Instant command-write device resources
---

Request mode: ** POST**

URL: http://api.heclouds.com/nbiot


#### URL parameter
Parameter Name | Format | Whether Must | Explain
:- | :- | :- | :- 
IMEI | string | is the identity code of | nbiot device
Obj_id | int | is the object ID of the | device, determined by the terminal device SDK
Obj_inst_id | int | is a specific instance ID under | nbiot device object, determined according to terminal device SDK
Mode | int | is the mode of | write, only 1 or 2
Timeout | int | no | request timeout, default 25 (in seconds), range of values [5, 40]

#### HTTP request parameters
Parameter Name | Format | Whether Must | Explain
:- | :- | :- | :- 
Data | array - JSON | is a JSON array of | write device resources, size limit 2k, see data request parameter description table

##### data description table
Parameter Name | Format | Whether Must | Explain
:- | :- | :- | :-
Res_id | int | is the resource ID of | specifying the write operation
Type | int | no | currently supports 1 and 2, 1 represents the resource type as Opaque, where the Val field is the hexadecimal string corresponding to the binary; 2 represents the resource type as Time, when the Val field is a timestamp (in seconds, numerical value); does not write represents the resource type as the base data type.
Val | object | is | determines the value type of Val based on the type of specified resource, which can be boolean, string, long, double

#### Return parameters
Parameter name | format | description
:- | :- | :- 
Error no | int | Calls the error code, which is 0 to indicate that the call was successful
Error | string | Error description, which indicates that the call succeeded for "succ"

##### Description

The corresponding meaning of returning errno status code can be found in "NB protocol northward API return status code description" in OneNET Document Center - > Device Development Guide - > Protocol Document - > LwM2M[download and view](/book/device-development/multpro/sdk-doc-tool/doc.md)

Model value: 1, which means replace, means replace the specified instance or resource value; 2, partial update, which means only update the value of a given resource or resource instace


#### Examples of requests
```text
POST http://api.heclouds.com/nbiot HTTP/1.1
api-key: WhI*************v1c=
Content-Type: application/json
Host: api.heclouds.com
```
#### Examples of request parameters

```json
非opaque类型：
{
    "data":[
        {
            "res_id":12,
            "val":121
        }
    ]
}

opaque类型：
{
    "data":[
        {
            "res_id":12,
            "type":1,
            "val":121
        }
    ]
}
```
#### Return an example
```json
{
    "errno": 0,
    "error": "succ"
}
```