Batch inquiry of equipment latest data
---
Request mode: ** GET**

URL: http://api.heclouds.com/devices/datapoints



#### URL parameter
Parameter Name | Format | Whether Must | Explain
:- | :- | :- | :- 
DevIds | string | is | device ids, separated by commas, limiting up to 500 devices

#### Return parameters
Parameter name | format | description
:- | :- | :- 
Error no | int | Calls the error code, which is 0 to indicate that the call was successful
Error | string | Error description, which indicates that the call succeeded for "succ"
Data | JSON | Interface call succeeds in returning device data related information, see Data Description Table

##### data description table
Parameter name | format | description
:- | :- | :- 
Device | array - JSON | JSON array of the latest device data, see Devices Description Table

##### Devices Description Table
Parameter name | format | description
:- | :- | :- 
ID | string | device ID
Title | string | device name
JSON array of the latest data for datastreams | array-json | data stream, see datastreams description table

##### datastreams description table
Parameter name | format | description
:- | :- | :- 
ID | string | data stream name
At | string | time
Value | string | latest data values

#### Examples of requests

```text
GET http://api.heclouds.com/devices/datapoints?devIds=12323,12324 HTTP/1.1
api-key: WhI*************v1c=
Content-Type: application/json
Host: api.heclouds.com

```

#### Return an example
```json
{
    "errno": 0,
    "data": {
        "devices":[
            {
                "id":12323,
                "title":"daf",
                "datastreams":[
                    {
                        "id":"temperature",
                        "at":"2017-02-12 10:22:22",
                        "value":"12"
                    },
                    ...
                ]
            },
            {
                "id":12324,
                "title":"daf",
                "datastreams":[
                    {
                        "id":"temperature",
                        "at":"2017-02-12 10:22:22",
                        "value":"15"
                    },
                    ...
                ]
            },
            ...
        ]
    },
    "error": "succ"
}
```