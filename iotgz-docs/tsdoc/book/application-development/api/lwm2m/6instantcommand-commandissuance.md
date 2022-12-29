Immediate order-order issuance
---
Request mode: ** POST**

URL: http://api.heclouds.com/nbiot/execute


#### URL parameter
Parameter Name | Format | Whether Must | Explain
:- | :- | :- | :- 
IMEI | string | is the identity code of | nbiot device
Obj_id | int | is the object ID of the | device, determined by the terminal device SDK
Obj_inst_id | int | is a specific instance ID under | nbiot device object, determined according to terminal device SDK
Res_id | int | is the resource ID of | nbiot device, determined by the terminal device SDK
Timeout | int | no | request timeout, default 25 (in seconds), range of values [5, 40]

#### HTTP request parameters
Parameter Name | Format | Whether Must | Explain
:- | :- | :- | :- 
Args | string | no | command string, size limit 2K

#### Return parameters
Parameter name | format | description
:- | :- | :- 
Error no | int | Calls the error code, which is 0 to indicate that the call was successful
Error | string | Error description, which indicates that the call succeeded for "succ"

##### Description

The corresponding meaning of returning errno status code can be found in "NB protocol northward API return status code description" in OneNET Document Center - > Device Development Guide - > Protocol Document - > LwM2M[download and view](/book/device-development/multpro/sdk-doc-tool/doc.md)


#### Examples of requests

```text
POST http://api.heclouds.com/nbiot/execute HTTP/1.1
api-key: WhI*************v1c=
Content-Type:application/json
Host: api.heclouds.com

```

#### Examples of request parameters
```json
{
    "args": "ping"
}
```
#### Return an example
```json
{
    "errno": 0,
    "error": "succ"
}
```