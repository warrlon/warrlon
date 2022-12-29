# Query topic for device subscription
Request mode: ** GET**

URL: http://api.heclouds.com/mqtt/device_topic/device_id

    Device_id: The device ID needs to be replaced

#### Return parameters
Parameter name | format | description
:- | :- | :- 
Error no | int | Calls the error code, which is 0 to indicate that the call was successful
Error | string | Error description, which indicates that the call succeeded for "succ"
Data | array - string | topic list

#### Request Header Example
```text
GET http://api.heclouds.com/mqtt/device_topic/39587277 HTTP/1.1
```

#### Return an example
```json
{
    "errno": 0,
    "data": ["topic/test/01", "topic/test/02"],
    "error": "succ"
}
```