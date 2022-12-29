Get a list of resources
---
Request mode: ** GET**

URL: http://api.heclouds.com/nbiot/resources


#### URL parameter
Parameter Name | Format | Whether Must | Explain
:- | :- | :- | :- 
IMEI | string | is the identity code of | nbiot device
Object ID of obj_id | int | no | device, determined by terminal device SDK

#### Return parameters
Parameter name | format | description
:- | :- | :- 
Error no | int | Calls the error code, which is 0 to indicate that the call was successful
Error | string | Error description, which indicates that the call succeeded for "succ"
Data | JSON | Interface call success after the return of resource-related information, see the data description table

##### data description table
Parameter name | format | description
:- | :- | :- 
Tot_count | int | Number of entries returned
Details of the entry returned by item | array - JSON | are shown in the item description table

##### item description table
Parameter name | format | description
:- | :- | :- 
Object ID of obj_id | int | device, determined by terminal device SDK
Instance entries under instances | array-json | obj_id objects are shown in the instances description table

##### instances description table
Parameter name | format | description
:- | :- | :- 
Ins_id | int | device instances id, determined by terminal device SDK
List of all resources under resources | array-int | device instances ID

##### Description

The corresponding meaning of returning errno status code can be found in "NB protocol northward API return status code description" in OneNET Document Center - > Device Development Guide - > Protocol Document - > LwM2M[download and view](/book/device-development/multpro/sdk-doc-tool/doc.md)


#### Examples of requests

```text
GET http://api.heclouds.com/nbiot/resources HTTP/1.1
api-key: WhI*************v1c=
Host: api.heclouds.com

```
#### Return an example
```json
{
    "errno": 0,
    "data": {
        "total_count": 12,
        "item": [
            {
                "obj_id": 3200,
                "instances": [
                    {
                        "inst_id": 0,
                        "resources": [5505, 5050]
                    }
                ]
            }
        ]
    },
    "error": "succ"
}
```