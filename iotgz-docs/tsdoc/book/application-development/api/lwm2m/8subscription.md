Subscription
---
Request mode: ** POST**

URL: http://api.heclouds.com/nbiot/observe


#### URL parameter
Parameter Name | Format | Whether Must | Explain
:- | :- | :- | :- 
IMEI | string | is the identity code of | nbiot device
Cancel | bool | is | true for cancellation of subscription, false for subscription
Obj_id | int | is the object ID of the | device, determined by the terminal device SDK
A specific instance ID under obj_inst_id | int | no | nbiot device object is determined according to terminal device SDK
Resource ID of res_id | int | no | nbiot device, determined by terminal device SDK
Pmin | int | no | minimum time interval for uploading data, default to 0, when data is uploaded
Maximum time interval for Pmax | int | no | uploading data
GT | double | no | upload when the data value is greater than that value
Lt | double | no | upload when the data value is less than that value
St | double | no | when the difference between the last two data points is greater or equal to the value
Timeout | int | no | request timeout, default 25 (in seconds), range of values [5, 40]

#### Return parameters
Parameter name | format | description
:- | :- | :- 
Error no | int | Calls the error code, which is 0 to indicate that the call was successful
Error | string | Error description, which indicates that the call succeeded for "succ"

##### Description

The corresponding meaning of returning errno status code can be found in "NB protocol northward API return status code description" in OneNET Document Center - > Device Development Guide - > Protocol Document - > LwM2M[download and view](/book/device-development/multpro/sdk-doc-tool/doc.md)

When both Pmin and Pmax exist, Pmax >= Pmin and both need to be greater than 0
LT < gt, and lt + 2*st < Gt
If there are gt, lt, st, res_id must be filled in
Cancel is not true | false will default to false


#### Examples of requests

```text
POST http://api.heclouds.com/nbiot/observe HTTP/1.1
api-key: WhI*************v1c=
Content-Type:application/json
Host: api.heclouds.com

```
#### Return an example
```json
{
    "errno": 0,
    "error": "succ"
}
```