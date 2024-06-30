# Development

This page describes the various methods for setting up the UWFITS-Server local development environment, the purpose of each script, and steps to further develop the api.

## Setting Up Environment

???+ warning "Node Version"

    Ensure you use an updated version of node, preferably node 20.2.0. You can utilize the python library ```nodeenv``` to easily change your node version

???+ note "ENV_NAME"

    Ensure this environment variable does not conflict with any other developers. It will be the name of your environment directory on the s3 bucket ```dev/environments/<ENV_NAME>```

1. Create the .env file and utilize .env_empty for template. Set all environment variables (_**Be extremely cautious with ENV_NAME and ensure it is kept**_)
    - The AWS Environment variables will be to the IAM dev user, and will be provided by the AWS Admin (Dr. Reicherzer). The AWS_USER_KEY is the IAM User's secret access key (_the names are swapped by the multer library_) 
2. Download AWS CLI V2 (_utilize preferred package manager_)
3. Utilize the ```setup_aws_profile.sh``` script to setup the AWS CLI V2 medusa User (_The access key names are not swapped, like previously_)
4. Utilize the ```setup_s3_env.sh``` script to setup the S3 environment
5. Utilize the ```download_dev_data.sh``` script to download the development data from the S3 bucket
6. Utilize the ```run_dev_db.sh``` script to run the mysql database
7. Run ```npm i``` to install node libraries
8. Run ```npm run dev``` to start node server


## Development Scripts

<pre><code>
scripts/
├── build_dev_api.sh     
├── download_dev_data.sh helpers.sh           
├── setup_aws_profile.sh 
├── stop_deploy_dev.sh
├── deploy_dev.sh        
├── export_dev_db.sh     
├── run_dev_db.sh        
└── setup_s3_env.sh
</code></pre>

| Script Name | Description | Prerequisites |
| ----------- | ----------- | ------------- |
| `build_dev_api.sh` | Builds API image used in `docker/docker-compose.yml` for pre-deployment check and by `UWFITS-Instructor` repo for development | - .env file must be created and populated properly |
| `download_dev_data.sh` | Downloads development data (`dump.sql`) from S3 bucket for MySQL database | - AWS CLI V2 must be installed<br>- Medusa user must be set up (use `setup_aws_profile.sh`) |
| `helpers.sh` | Helper functions for all script files | None specified |
| `setup_aws_profile.sh` | Sets up AWS profile for authentication with S3 bucket for development scripts | - Authentication credentials for IAM Development user (provided by AWS Admin) |
| `stop_deploy_dev.sh` | Stops and removes the docker stack created by `deploy_dev.sh` | None specified |
| `deploy_dev.sh` | Creates and deploys docker stack for pre-deployment check | - API development environment must be set up<br>- `medusa-api-dev` image must be built<br>- No process running on port 80<br>- Medusa instructor portal must be built |
| `export_dev_db.sh` | Exports database to `$HOME/medusa/mysql/backup/` | - `medusa-db-dev` container must be running |
| `run_dev_db.sh` | Runs development database with default configuration for `npm run dev` | - `$HOME/medusa/mysql/` directory must be created and populated |
| `setup_s3_env.sh` | Creates environment directory in S3 bucket and uploads default image and audio files | - AWS CLI V2 must be installed<br>- .env file must be created and populated<br>- Medusa user must be set up |

## Development Process

After setting up the development environment, and making code changes ensure the dev database container is running (```medusa-db-dev```) then run ```npm run dev```. With the server running use an application such as Postman to test routes.

## Testing

!!! note "Status"
    It isn't thorough (or entirely up to date) however its a good start.

Ensure the server is running, and from a seperate terminal run ```npm run test``` to run tests. 

## Saving db progress
After backing up the database to use the data in a new database image, simply move the backup from the ```$HOME/medusa/mysql/backups``` directory to the ```$HOME/medusa/mysql/entrypoint``` directory and remove other files.

1. Utilize the ```export_dev_db.sh``` to export a timestamped .sql file to the ```$HOME/medusa/mysql/backups``` directory

## Migrations

!!! danger "TODO"
    This section has not been written yet

## Documentation (MKDocs

!!! danger "TODO"
    This section has not been written yet
