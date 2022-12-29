Query device information based on IMEI
---
Request mode: ** GET**

URL: http://api.heclouds.com/devices/getbyimei



#### URL parameter
Parameter Name | Format | Whether Must | Explain
:- | :- | :- | :- 
IMEI | string | is the identity code of | nbiot device

#### Return parameters
Parameter name | format | description
:- | :- | :- 
Error no | int | Calls the error code, which is 0 to indicate that the call was successful
Error | string | Error description, which indicates that the call succeeded for "succ"
Data | JSON | Interface call success returns device-related information, as shown in the data description table

##### data description table
Parameter name | format | description
:- | :- | :- 
ID | string | device ID
Online | bool | device online status
Title | string | device name
Desc | string | device description
Create_time | string | device creation time, Beijing time
Private | bool | Device privacy

#### Examples of requests

```text
GET http://api.heclouds.com/devices/getbyimei?imei=865***03 HTTP/1.1
api-key: WhI*************v1c=
Host: api.heclouds.com

```

#### Return an example
```json
{
    "errno": 0,
    "data": {
        "id": "35282992",
        "online": false,
        "title": "test_device",
        "desc": "test_desc",
        "create_time": "2018-07-04 17:43:11",
        "private":true,
    },
    "error": "succ"
}
```