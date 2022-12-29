# Update data stream properties
Request mode: ** PUT**

URL: http://api.heclouds.com/devices/device_id/datastreams/datastream_id

    Device_id: The device ID needs to be replaced
    Datastream_id: The device data stream ID needs to be replaced

#### HTTP body parameter
Parameter Name | Format | Whether Must | Explain
:- | :- | :- | :- 
Tags | array-string | no | data stream tags can be one or more
Unit | string | no | data unit
Unit_symbol | string | no | data unit symbol
CMD | string | no | issue commands periodically, hexadecimal byte string < br > example: 010300002c40b
Interval | int | no | sampling period
Formula | string | no | register calculation formula. Multiple expressions are separated by commas (,) from < br > examples: (A0 + A1), A0*A1

#### Return parameters
Parameter name | format | description
:- | :- | :- 
Error no | int | Calls the error code, which is 0 to indicate that the call was successful
Error | string | Error description, which indicates that the call succeeded for "succ"


#### Request Header Example
```text
PUT http://api.heclouds.com/devices/20474930/datastreams/speed HTTP/1.1
```

#### Examples of request parameters
```json
{
    "cmd": "010300000002c40b",
    "interval": 10
}
```

#### Return an example
```json
{
    "errno":0,
    "error":"succ"
}
```