View triggers
---

#### ** A Single View**

Request mode: ** GET**

URL: http://api.heclouds.com/triggers/trigger_id

    Trigger_id: The device ID needs to be replaced


#### Return parameters
Parameter name | format | description
:- | :- | :- 
Error no | int | Calls the error code, which is 0 to indicate that the call was successful
Error | string | Error description, which indicates that the call succeeded for "succ"
Data | JSON | trigger information returned after successful interface call is shown in the data description table

##### data description table
Parameter name | format | description
:- | :- | :- 
ID | string | trigger ID
Title | string | trigger name
url | string | url
Type | string | trigger type
Threshold | int | trigger value
Is invalid | bool | trigger invalid
Create_time | string | device trigger time, Beijing time

##### Description
```
触发器失效是指触发器所依赖的数据流或者设备被删除了。此时触发器永远不会有效触发事件
```
#### Examples of requests
```text
GET http://api.heclouds.com/triggers/350092 HTTP/1.1
api-key: WhI*************v1c=
Content-Type: application/json
Host: api.heclouds.com
```

#### Return an example
```json
{
    "errno": 0,
    "data": {
        "id":350092,
        "title":"we du jian kong",
        "url":"xx.bb.com",
        "type":">=",
        "threshold":45
        "invalid":true,
        "create_time":"2018-04-24 10:22:22"
    },
    "error": "succ"
}
```

#### ** B Batch View**

Request mode: ** GET**

URL: http(s)://api.heclouds.com/triggers

#### HTTP head
Parameter Name | Format | Whether Must | Explain
:- | :- | :- | :- 
Api-key | string | is | must be master key or apikey with access to the device
Content_Type | string | is | application / JSON

#### URL parameter
Parameter Name | Format | Whether Must | Explain
:- | :- | :- | :- 
Title | string | no | specify trigger name
Page | int | no | specify page number
Per_page | int | no | specifies the number of output per page, defaulting to 10, up to 100

#### Return parameters
Parameter name | format | description
:- | :- | :- 
Error no | int | Calls the error code, which is 0 to indicate that the call was successful
Error | string | Error description, which indicates that the call succeeded for "succ"
Data | JSON | trigger information returned after successful interface call is shown in the data description table

##### data description table
Parameter name | format | description
:- | :- | :- 
Total_count | int | total number of triggers
Per_page | int | Number of displays per page
Page | int | page number
JSON array of triggers | array-json | triggers, see triggers description table

##### triggers description table
Parameter name | format | description
:- | :- | :- 
ID | string | trigger ID
Title | string | trigger name
url | string | url
Type | string | trigger type
Threshold | int | trigger value
Is invalid | bool | trigger invalid
Create_time | string | device trigger time, Beijing time

##### Description
1. Trigger failure means that the data stream or device on which the trigger relies has been deleted. At this point the trigger will never trigger the event effectively

#### Examples of requests

```text
GET http://api.heclouds.com/triggers?page=1&per_page=30 HTTP/1.1
api-key: WhI*************v1c=
Content-Type: application/json
Host: api.heclouds.com
Content-Length: 196

```

#### Return an example
```json
{
    "errno": 0,
    "data": {
        "total_count": 600,
        "per_page": 30,
        "page": 1,
        "triggers":[
            {
                "id":350092,
                "title":"we du jian kong",
                "url":"xx.bb.com",
                "type":">=",
                "threshold":45,
                "invalid":true,
                "create_time":"2018-04-24 10:22:22" 
            }
            {
                "id":350093,
                "title":"wen du jian kong",
                "url":"xx.bb.com",
                "type":">=",
                "threshold":45,
                "invalid":true,
                "create_time":"2018-04-24 10:22:22" 
            }
            ...
        ]
    },
    "error": "succ"
}
```