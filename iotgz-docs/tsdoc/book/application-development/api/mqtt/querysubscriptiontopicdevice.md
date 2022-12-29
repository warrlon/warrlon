# Equipment for querying and subscribing to topic
Request mode: ** GET**

URL: http://api.heclouds.com/mqtt/topic_device

#### URL parameters
Parameter Name | Format | Whether Must | Explain
:- | :- | :- | :- 
Topic | string | is | to publish a message to a specified topic, which only supports publishing a message with QoS = 0
Page | int | is | specify page number
Per_page | int | is | specifies the number of output devices per page, default 30, up to 1000


#### Return parameters
Parameter name | format | description
:- | :- | :- 
Error no | int | Calls the error code, which is 0 to indicate that the call was successful
Error | string | Error description, which indicates that the call succeeded for "succ"
Data | JSON | Interface call success returns device-related information, as shown in the data description table

##### data description table
Parameter name | format | description
:- | :- | :- 
Tot_count | int | Number of devices in query results
Page | int | current page
Per_page | int | Number of devices per page
Device | array-int | Device ID array


#### Request Header Example
```text
GET http://api.heclouds.com//mqtt/topic_device?topic=topic/test/01&page=1&per_page=100 HTTP/1.1
```

#### Return an example
```json
{
    "errno": 0,
    "data": {
        "per_page": 100,
        "devices": [39587277,39587272],
        "total_count": 2,
        "page": 1
    },
    "error": "succ"
}
```