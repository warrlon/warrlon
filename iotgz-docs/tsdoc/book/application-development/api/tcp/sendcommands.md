# Send commands
Request mode: ** POST**

URL:http://api.heclouds.com/cmds

#### URL parameters
Parameter Name | Format | Whether Must | Explain
:- | :- | :- | :- 
Device_id | string | is the device ID that receives the data
Timeout | int | no | command validity time, default 0. <br> 0:On-line command, if the equipment is on-line, send it to the equipment, if the equipment is off-line, discard <br> 0:Off-line command directly. If the equipment is on-line, send it to the equipment. If the equipment is off-line, it will be valid in the current time plus timeout time. During the validity period, if the equipment is on-line, send it to the equipment <br> unit: seconds < br> valid range: 0-2678400.


#### HTTP body content
    User-defined data: json, string, binary data (less than 64K)

#### HTTP request returns parameters
Parameter name | format | description
:- | :- | :- | :- 
Error no | int | Calls the error code, which is 0 to indicate that the call was successful
Error | string | Error description, which indicates that the call succeeded for "succ"
Data | JSON | Interface call success returns device-related information, as shown in the data description table

##### data description table
Parameter name | format | description
:- | :- | :- | :- 
Cmd_uuid | string | command id, unique in platform scope


#### Request Example 1


```text
POST http://api.heclouds.com/cmds?device_id=8029377 HTTP/1.1
api-key: l2aH*************BRtAo=

<this is a command>
```

#### Return to Example 1: Successful creation of commands
```json
{
    "errno": 0,
    "error": "succ",
    "data": {
        "cmd_uuid": "81572aae-fc34-5deb-8f06-ab45d73cb12b"
    }
}
```
#### Return to Example 2: The device is not online
```json
{
    "errno": 10,
    "error": "device not online: 8029377"
}
```


#### Request Example 2: Sending Offline Commands


```text
POST http://api.heclouds.com/cmds?device_id=8029377&timeout=3600 HTTP/1.1
api-key: l2aH*************BRtAo=

<this is a command>
```

#### Return an example
```json
{
    "errno": 0,
    "error": "succ",
    "data": {
        "cmd_uuid": "81572aae-fc34-5deb-8f06-ab45d73cb12b"
    }
}
```