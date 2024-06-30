# Homepage

This repository contains the code for the UWF Situation Awareness Medusa Application.  This code takes HTTP requests from the Instructor web portal and the
mobile application

## Features

- RESTful API with CRUD operations
- Connection to a relational database using Sequelize package
- Express as the web framework for easy route handling
- Logging Feature using Winston and Express-Winston package
- File downloading and uploading through S3
- File compression


## UWFITS-Server (API) Overview
Programming wise this uses ExpressJS that greatly simplifies the routing of HTTP requests. Each topic for routing is grouped in its `./api/routes` which specifies the kind of HTTP request and the route, and typically has the whole code but if it is a more complex request it may be factored out.

This uses a mysql database within a container as well as PhpMyAdmin as a dead simple way to work with the database using a GUI.

The database is connected through Sequelize, a very high level ORM. Models (tables) are defined under `./api/models` and to do joins **require** it to be done in javascript, under `./config/models.js`. Don't do stupid stuff like take the response of a query and then loop over an await. Lean on the ORM and mysql.

Audio and images may pass through this to and from the S3 bucket, ffmpeg is used to compress to mpeg and webp respectively to save space. Bewarned: older browsers may not support webp and who knows if that huffman table overflow exploit has gotten patched yet.

There is also a memoizer for storing the image and audio sound URLs which are signed so they can't be simply available to the public with a public URL.

Each user currently has one and only one session at a time, and for each request that needs authorization to do something, there is a small table in the database that keeps track of sessions and maps session cookies from the request to user information a the start of each request.

## Medusa Project Overview
This is an application meant to test situational awareness of medical staff using various scenarios.

There is a giant heirarchical tree at the center of the database. Each course has many scenarios which has many parts which has many sagat (questions) which has many answers. In this there are patients attached to each scenario, an image attached to each part, and events attached to each part.

There is a gradebook that records each response and upon scenario completion tablulates grades for a scenario.

## Project Structure

<pre><code>
.
├── Dockerfile - <i style="font-size: smaller;">Dockerfile for UWFITS-Server image</i>     
├── config/ - <i style="font-size: smaller;">Configuration files for server</i>
│   ├── auth.js      
│   ├── aws.js       
│   ├── database.js  
│   ├── envsetter.js 
│   ├── logger.js    
│   ├── models.js    
│   ├── paginator.js 
│   └── session.js     
├── docs/ - <i style="font-size: smaller;">Documentation files</i>
│   └── files...
├── server.js - <i style="font-size: smaller;">Entrypoint for server</i>
├── api/ - <i style="font-size: smaller;">Models, routes, and caching</i>
│   ├── memoizer.js 
│   ├── models/
│   │   └── files...
│   └── routes/
│       └── files...
├── docker/ - <i style="font-size: smaller;">Configuration files for deployment test</i>
│   ├── docker-compose.yml 
│   └── nginx 
├── scripts/ - <i style="font-size: smaller;">Scripts for development</i>
│   ├── build_dev_api.sh     
│   ├── download_dev_data.sh helpers.sh           
│   ├── setup_aws_profile.sh 
│   ├── stop_deploy_dev.sh
│   ├── deploy_dev.sh        
│   ├── export_dev_db.sh     
│   ├── run_dev_db.sh        
│   └── setup_s3_env.sh
├── test/ - <i style="font-size: smaller;">Test scripts for routes</i>
│   └── files...    
├── mkdocs.yml - <i style="font-size: smaller;">Mkdocs artifact</i>
├── package-lock.json - <i style="font-size: smaller;">Build artifact</i>
├── node_modules - <i style="font-size: smaller;">Build artifact</i>
└── package.json - <i style="font-size: smaller;">Build artifact</i>
</code></pre>

## Logging
1. The logging feature uses winston as the logger and express-winston as the middleware

2. All configurations are available in UWFITS-Server/api/logger/logger.js

3. Documentation on how to modify this code is available at https://www.npmjs.com/package/winston. There are many online resources on winston as well since it is very popular

4. All requests/responses are automatically logged in the ServerLogs table in development environment

5. By setting the environment variable LOGS to (info, warn, or error), confidential information will no longer be logged and only messages of "LOGS" importance will be logged. This is a custom feature built for production runs of UWFITS-Server, I recommend using LOGS=warn in docker-compose when running on production. 
