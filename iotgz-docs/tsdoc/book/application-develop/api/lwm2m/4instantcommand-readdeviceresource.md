Instant Command-Read Device Resources
---
Request mode: ** GET**

URL: http://api.heclouds.com/nbiot



#### URL parameter
Parameter Name | Format | Whether Must | Explain
:- | :- | :- | :- 
IMEI | string | is the identity code of | nbiot device
Obj_id | int | is the object ID of the | device, determined by the terminal device SDK
A specific instance ID under obj_inst_id | int | no | nbiot device object is determined according to terminal device SDK
Resource ID of res_id | int | no | nbiot device, determined by terminal device SDK
Timeout | int | no | request timeout, default 25 (in seconds), range of values [5, 40]

#### Return parameters
Parameter name | format | description
:- | :- | :- 
Error no | int | Calls the error code, which is 0 to indicate that the call was successful
Error | string | Error description, which indicates that the call succeeded for "succ"
Data | array - JSON | Information about device resources returned after successful interface invocation is shown in the data description table.

##### data description table
Parameter name | format | description
:- | :- | :- 
Obj_inst_id | int | object instance ID
Res | array - JSON | res list

##### res description table
Parameter name | format | description
:- | :- | :- 
Res_id | int | resource ID
Value | object | reads the value of the resource, which can be bool, string, long, double, etc.

##### Description

The corresponding meaning of returning errno status code can be found in "NB protocol northward API return status code description" in OneNET Document Center - > Device Development Guide - > Protocol Document - > LwM2M[download and view](/book/device-development/multpro/sdk-doc-tool/doc.md)

When obj_instance_id does not exist, resource_id does not exist.


#### Examples of requests

```text
GET http://api.heclouds.com/devices/nbiot?imei=**&obj_id=*** HTTP/1.1
api-key: WhI*************v1c=
Host: api.heclouds.com

```

#### Return an example
```json
{
    "errno": 0,
    "error":"succ",
    "data": [
        {
            "res":[
                {
                    "res_id": 3,
                    "val": "1.00"
                }
            ],
            "obj_inst_id": 0    
        }
    ]
}
```