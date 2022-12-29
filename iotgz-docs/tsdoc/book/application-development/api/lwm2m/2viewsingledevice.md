View individual devices
---

Request mode: ** GET**
URL: http://api.heclouds.com/devices/device_id

    Device_id: The device ID needs to be replaced


#### Return parameters
Parameter name | format | description
:- | :- | :- 
Error no | int | Calls the error code, which is 0 to indicate that the call was successful
Error | string | Error description, which indicates that the call succeeded for "succ"
Data | JSON | Interface call success returns device-related information, as shown in the data description table


##### data description table

Parameter name | format | description
:- | :- | :- 
ID | string | unique ID allocated by the platform
Online | bool | indicates whether the LwM2M device is online
Protocol | string | Device Access Protocol (LwM2M)
Title | string | device name
Desc | string | device description
Create_time | string | device creation time, Beijing time
Obsv | bool | Subscribe or not
Private | bool | Device privacy
Binary | JSON | device-related images or binary data, as detailed in the binary description table
Tags | array-string | device Tags
Location | JSON | device location coordinate information, expressed in longitude and latitude key pairs: {"lon": xx, "lat": xx}
Auth_info | string | device authentication information, corresponding to the "sn" or "mac" parameters in the device registration interface
Other | JSON | Custom information for other devices, expressed in key-to-value format, see Example
Datastreams | array - JSON | JSON array of device data flow information, see datastreams description table


##### binary description table
Parameter name | format | description
:- | :- | :-
Index | string | binary data index
At | string | upload time
Size | int | bytes
Desc | string | description

##### datastreams description table

Parameter name | format | description
:- | :- | :- 
ID | string | data stream name
Create_time | string | data stream creation time, Beijing time
Unit | string | unit
Unit_symbol | string | unit symbol

#### Examples of requests

```text
GET http://api.heclouds.com/devices/35****92 HTTP/1.1
api-key: WhI*************v1c=
Host: api.heclouds.com

```


#### Return an example
```json
{
    "errno": 0,
    "data": {
        "protocol": "LwM2M",
        "other": {
            "version": "1.0.0",
            "manufacturer": "china mobile"
        },
        "create_time": "2018-07-04 17:43:11",
        "online": false,
        "location": {
            "lat": 23.54,
            "lon": 109
        },
        "id": "35282992",
        "auth_info": "tes01235n82105",
        "datastreams": [{
            "unit": "",
            "id": "1",
            "unit_symbol": "",
            "create_time": "2018-07-04 17:43:11"
        }],
        "title": "test_device",
        "desc": "test_desc",
        "tags": ["china", "mobile"]
    },
    "error": "succ"
}
```