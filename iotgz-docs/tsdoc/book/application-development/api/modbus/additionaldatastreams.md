# Added data stream
Request mode: ** POST**

URL: http://api.heclouds.com/devices/device_id/datastreams

    Device_id: The device ID needs to be replaced

#### HTTP body parameter
Parameter Name | Format | Whether Must | Explain
:- | :- | :- | :- 
ID | string | is | data flow ID, that is, the name of the data flow
Tags | array-string | no | data stream tags can be one or more
Unit | string | no | data unit
Unit_symbol | string | no | data unit symbol
CMD | string | no | issue commands periodically, hexadecimal byte string < br > example: 010300002c40b
Interval | int | no | sampling period
Formula | string | no | register calculation formula < br > example: (A0 + A1) means that the value of register 0 is added to the value of register 1

#### Return parameters
Parameter name | format | description
:- | :- | :- 
Error no | int | Calls the error code, which is 0 to indicate that the call was successful
Error | string | Error description, which indicates that the call succeeded for "succ"
Data | JSON | Interface call success returns device-related information, as shown in the data description table

##### data description table
Parameter name | format | description
:- | :- | :- 
Ds_uuid | string | unique ID inside data stream platform

#### Request Header Example
```text
POST http://api.heclouds.com/devices/20474930/datastreams HTTP/1.1
```

#### Examples of request parameters
```json
{
    "id": "speed",
    "cmd": "010300000002c40b",
    "interval": 10
}
```

#### Return an example
```json
{
    "errno":0,
    "data": {
        "ds_uuid":"856f8622-64e7-5549-8e55-44931f07db6e"
    },
    "error":"succ"
}
```