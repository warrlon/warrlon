# Send commands
Request mode: ** POST**

URL:http://api.heclouds.com/cmds

#### URL parameters
Parameter Name | Format | Whether Must | Explain
:- | :- | :- | :- 
Device_id | string | is the device ID that receives the data


#### HTTP request content
Parameter Name | Format | Whether Must | Explain
:- | :- | :- | :- 
CMD | string | is hexadecimal data in the form of a string, as shown in an example

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


#### Request Header Example
```text
POST http://api.heclouds.com/cmds?device_id=8029377 HTTP/1.1
```

#### Examples of request parameters
```json
{
    "cmd":"07030001000295AD"
}
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