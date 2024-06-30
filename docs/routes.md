# Routes

This page describes each route available through the api, it's method, permission level, url route, url parameters, body parameters, and description.

_Many routes support pagination, look for ```pagination supported``` tag_

## Courses /courses

| Sub-URL | Permission | Method | URL Params | Body Params | Description | Notes |
|---------|------------|--------|------------|-------------|-------------|-------|
| / | instructor, admin | GET | none | none | Gets all courses | Pagination supported |
| /unregistered | user, instructor, admin | GET | none | none | Gets user's unregistered courses | Mobile |
| /registered | user, instructor, admin | GET | none | none | Gets user's registered courses | Mobile |
| /published | instructor, admin | GET | none | none | Gets all published courses | |
| /unpublished | instructor, admin | GET | none | none | Gets all unpublished courses | |
| /:course_id | user, instructor, admin | GET | none | course_id | Gets course by course_id | |
| /create | instructor, admin | POST | none | name, description, is_published | Creates new course given parameters | |
| /edit | instructor, admin | PATCH | none | name, description, is_published, course_id | Updates course given parameters | |
| /add | user, instructor, admin | POST | none | course_id | Registers user for course | Mobile |
| /remove | user, instructor, admin | DELETE | none | course_id | Unregisters user from course | Mobile |
| /completed | user, instructor, admin | GET | none | none | Gets all courses that are flagged "is_completed" for a user in UserCourse_Join | Mobile |
| /publish | instructor, admin | PATCH | none | course_id | Sets is_published to true | |
| /unpublish | instructor, admin | PATCH | none | course_id | Unpublishes course | |
| /:course_id | instructor, admin | DELETE | course_id | none | Deletes course | |

## Parts /parts

| Sub-URL | Permission | Method | URL Params | Body Params | Description |
|---------|------------|--------|------------|-------------|-------------|
| /:part_id | user, instructor, admin | GET | part_id | none | Gets part by id |
| /scenario/:scenario_id | user, instructor, admin | GET | scenario_id | none | Gets scenario by id |
| /nextOrderVal/:scenario_id | instructor, admin | GET | scenario_id | none | Gets next "order" field for a new part |
| /create | instructor, admin | POST | none | order, time, description, scenario_id, image_id | Creates part using body params |
| /edit | instructor, admin | PATCH | none | order, time, description, scenario_id, image_id, part_id | Edits part using body params |
| /reorder | instructor, admin | PATCH | none | `{orders : [{order: number, part_id}]}` | Sets new orders for each part in a scenario |
| /:part_id | instructor, admin | DELETE | part_id | none | Deletes part given part_id |

## Scenarios /scenarios

| Sub-URL | Permission | Method | URL Params | Body Params | Description | Notes |
|---------|------------|--------|------------|-------------|-------------|-------|
| /load/:scenario_id | user, instructor, admin | GET | scenario_id | none | Loads scenario and everything associated with scenario | Mobile |
| / | instructor, admin | GET | none | none | Retrieves all scenarios | Pagination supported |
| /:scenario_id | user, instructor, admin | GET | scenario_id | none | Gets scenario by scenario_id | |
| /course/:course_id | user, instructor, admin | GET | course_id | none | Gets all scenarios by associated course_id | Mobile |
| /create | instructor, admin | POST | none | name, description, difficulty, course_id | Creates scenario given body params | |
| /edit | instructor, admin | PATCH | none | scenario_id, name, description, difficulty, course_id | Edits scenario given body params | |
| /:scenario_id | instructor, admin | DELETE | scenario_id | none | Deletes scenario given scenario_id | |

## Patients /patients

| Sub-URL | Permission | Method | URL Params | Body Params | Description |
|---------|------------|--------|------------|-------------|-------------|
| / | user, instructor, admin | GET | none | none | Gets all patients |
| /:patient_id | user, instructor, admin | GET | patient_id | none | Gets patient by patient_id |
| /create | instructor, admin | POST | none | name | Creates patient given name |
| /edit | instructor, admin | PATCH | none | patient_id, name | Edits patient given name and id |
| /:patient_id | instructor, admin | DELETE | patient_id | none | Deletes patient given id |

## Users /users

| Sub-URL | Permission | Method | URL Params | Body Params | Description | Notes |
|---------|------------|--------|------------|-------------|-------------|-------|
| / | admin | GET | none | none | Gets all users and user info | |
| /adminToken | admin | GET | none | none | Creates admin token (used to create admin accounts, valid for 10 days) | |
| /instructorToken | admin | GET | none | none | Creates instructor token (used to create instructor accounts, valid for 10 days) | |
| /register | none | POST | none | email, password, first_name, last_name, token | Creates user account, if valid token exists they will be given permissions associated with token | Mobile/web |
| /login | none | POST | none | email, password | Logs in user to existing account | Mobile/web |
| /logout | user, instructor, admin | POST | none | none | Logs user out and destroys session | Mobile/web |
| /delete | user, instructor, admin | DELETE | none | none | Deletes account of currently logged in user | Mobile/web |

## Images /images

| Sub-URL | Permission | Method | URL Params | Body Params | Description | Notes |
|---------|------------|--------|------------|-------------|-------------|-------|
| / | instructor, admin | GET | none | none | Gets all images (records, not images themselves) | Pagination supported |
| /:image_id | user, instructor, admin | GET | image_id | none | Gets image based on image_id (actual image, not record) | Mobile/web |
| /patient/:patient_id | user, instructor, admin | GET | patient_id | none | Gets all images based on patient ID (records, not images themselves) | |
| /upload | instructor, admin | POST | none | none | Takes image file from form-data and posts it to EC2 instance, and creates a record for that image (part 1/2 of request) | |
| /upload/metadata | instructor, admin | PATCH | none | image_id, patient_id | Adds metadata to a previously uploaded image (part 2/2 of request) | |
| /:image_id | instructor, admin | DELETE | image_id | none | Deletes the image record (will soon delete image from EC2 as well, still work in progress) | |

## Vitals /vitals

| Sub-URL | Permission | Method | URL Params | Body Params | Description |
|---------|------------|--------|------------|-------------|-------------|
| /scenario/:scenario_id | user, instructor, admin | GET | scenario_id | none | Gets all vitals associated with a scenario |
| /:vitals_id | user, instructor, admin | GET | vitals_id | none | Gets vitals by vitals_id |
| /create | instructor, admin | POST | none | scenario_id, type, value | Creates vitals based on body params |
| /create/multiple | instructor, admin | POST | none | Array of vitals objects (scenario_id, type, value) | Creates multiple vitals based on body params array |
| /edit | instructor, admin | PATCH | none | vitals_id, scenario_id, type, value | Creates new vitals based on body params |
| /:vitals_id | instructor, admin | DELETE | vitals_id | none | Deletes vitals based on vitals_id |

## Events /events

| Sub-URL | Permission | Method | URL Params | Body Params | Description |
|---------|------------|--------|------------|-------------|-------------|
| /types | user, instructor, admin | GET | none | none | Returns all event types |
| /:event_id | user, instructor, admin | GET | event_id | none | Returns event and associated event type of event_id |
| /type/:event_type_id | user, instructor, admin | GET | event_type_id | none | Returns event type object of event_type_id |
| /part/:part_id | user, instructor, admin | GET | part_id | none | Gets all events and associated event types for part_id |
| /create | instructor, admin | POST | none | part_id, event_type_id, value, time, descriptive_name | Creates an event based on body params |
| /edit | instructor, admin | PATCH | none | event_id, part_id, event_type_id, value, time, descriptive_name | Updates an event based on body params |
| /type/create | instructor, admin | POST | none | descriptive_name | Creates an event type based on body params |
| /type/edit | instructor, admin | PATCH | none | descriptive_name, event_type_id | Updates an event type based on body params |
| /:event_id | instructor, admin | DELETE | event_id | none | Deletes an event based on event_id |
| /type/:event_type_id | instructor, admin | DELETE | event_type_id | none | Deletes an event type and all associated events |

## Sagats /sagats

| Sub-URL | Permission | Method | URL Params | Body Params | Description |
|---------|------------|--------|------------|-------------|-------------|
| /types | user, instructor, admin | GET | none | none | Gets all sagat query types |
| /:sagat_id | user, instructor, admin | GET | sagat_id | none | Gets sagat query based on sagat_id |
| /part/:part_id | user, instructor, admin | GET | part_id | none | Gets all sagat queries and answers based on part_id |
| /answers/:sagat_id | user, instructor, admin | GET | sagat_id | none | Gets sagat answers based on sagat_id |
| /query/create | instructor, admin | POST | none | part_id, text, sagat_level, sagat_type_id | Creates sagat query based on body params |
| /query/edit | instructor, admin | POST | none | sagat_id, part_id, text, sagat_level, sagat_type_id | Updates sagat query based on body params |
| /answer/create | instructor, admin | POST | none | sagat_id, text, correct_answer | Creates sagat answer based on body params |
| /answer/edit | instructor, admin | PATCH | none | answer_id, sagat_id, text, correct_answer | Edits sagat answer based on body params |
| /type/create | instructor, admin | POST | none | descriptive_name | Creates sagat query type based on body params |
| /submit | user, instructor, admin | POST | none | sagat_id, user_answers | Creates a grade for the user based on answers |

## Prompts /prompts

| Sub-URL | Permission | Method | URL Params | Body Params | Description | Notes |
|---------|------------|--------|------------|-------------|-------------|-------|
| / | instructor, admin | GET | none | none | Gets all prompts | Pagination supported |
| /categories | user, instructor, admin | GET | none | none | Gets all prompt categories | |
| /:prompt_id | user, instructor, admin | GET | prompt_id | none | Returns prompt and prompt type based on prompt_id | |
| /categories/:category_id | user, instructor, admin | GET | category_id | none | Gets prompt category by category_id | |
| /part/:part_id | user, instructor, admin | GET | part_id | none | Gets all prompts and prompt categories for part_id | |
| /create | instructor, admin | POST | none | text, answer, part_id, category_id | Creates prompt based on body params | |
| /edit | instructor, admin | PATCH | none | prompt_id, text, answer, part_id, category_id | Edits prompt based on body params | |
| /category/create | instructor, admin | POST | none | descriptive_name | Creates prompt category based on body params | |
| /category/edit | instructor, admin | PATCH | none | descriptive_name, category_id | Edits category based on body params | |
| /:prompt_id | instructor, admin | DELETE | prompt_id | none | Deletes prompt based on prompt | |

## Sounds /sounds

| Sub-URL | Permission | Method | URL Params | Body Params | Description | Notes |
|---------|------------|--------|------------|-------------|-------------|-------|
| / | user, instructor, admin | GET | none | none | Gets all sounds and sound types (not the actual sound files) | Pagination supported |
| /:sound_id | user, instructor, admin | GET | sound_id | none | Gets the sound from the S3 instance based on the sound ID (actual sound, not the record) | Mobile/web |
| /types/:sound_type_id | user, instructor, admin | GET | sound_type_id | none | Gets the sound type based on the sound type ID | |
| /upload | instructor, admin | POST | none | none | Uploads the sound file to the S3 instance and creates a sound record | |
| /upload/metadata | instructor, admin | PATCH | none | sound_id, descriptive_name, sound_type_id | Adds metadata to the previously created sound record | |
| /types/edit/:sound_type_id | instructor, admin | PATCH | sound_type_id | none | Updates the record in the sound type table | In development |
| /edit/:sound_id | instructor, admin | PATCH | sound_id | none | Updates the sound file and/or sound description on the S3 instance and database | In development |
| /:sound_id | instructor, admin | DELETE | sound_id | none | Deletes the sound record and sound file | In development |

## Clipboard /Clipboard

| Sub-URL | Permission | Method | URL Params | Body Params | Description | Notes |
|---------|------------|--------|------------|-------------|-------------|-------|
| / | user, instructor, admin | POST | none | message, scenario_id | Creates a clipboard record based on the provided body parameters | Mobile |

## Treatment /Treatment

| Sub-URL | Permission | Method | URL Params | Body Params | Description | Notes |
|---------|------------|--------|------------|-------------|-------------|-------|
| / | user, instructor, admin | POST | none | treatment_type, treatment1, treatment2, scenario_id | Creates a treatment record based on the provided body parameters | Mobile |

## AppLogger /AppLog

| Sub-URL | Permission | Method | URL Params | Body Params | Description | Notes |
|---------|------------|--------|------------|-------------|-------------|-------|
| /log | user, instructor, admin | POST | none | level, message | Add user interaction event | Mobile |
