Batch inquiries about device status
---
Request mode: ** GET**

URL: http://api.heclouds.com/devices/status


#### URL parameter
Parameter Name | Format | Whether Must | Explain
:- | :- | :- | :- 
DevIds | string | is | device id, multiple device IDs are separated by commas, limiting 1000 devices

#### Return parameters
Parameter name | format | description
:- | :- | :- 
Error no | int | Calls the error code, which is 0 to indicate that the call was successful
Error | string | Error description, which indicates that the call succeeded for "succ"
Data | JSON | Interface call success returns device-related information, as shown in the data description table

##### data description table
Parameter name | format | description
:- | :- | :- 
Total_count | int | Total
Device | array - JSON | JSON array of device state, see device description table

##### Devices Description Table
Parameter name | format | description
:- | :- | :- 
ID | string | device ID
Title | string | device name
Online | bool | online status

#### Examples of requests

```text
GET http://api.heclouds.com/devices/status?devIds=1221,12233,1123 HTTP/1.1
api-key: WhI*************v1c=
Content-Type: application/json
Host: api.heclouds.com

```

#### Return an example
```json
{
    "errno": 0,
    "data": {
        "total_count":121,
        "devices":[
            {
                "id":1221,
                "title":"device1",
                "online":false
            },
            {
                "id":12333,
                "title":"device2",
                "online":true
            },
            ...
        ]
    },
    "error": "succ"
}
```