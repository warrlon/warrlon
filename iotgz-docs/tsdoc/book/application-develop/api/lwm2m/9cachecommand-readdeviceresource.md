Cache command-read device resources
---
Request mode: ** GET**

URL: http://api.heclouds.com/nbiot/offline


#### URL parameter
Parameter Name | Format | Whether Must | Explain
:- | :- | :- | :- 
IMEI | string | is the identity code of | nbiot device
Obj_id | int | is the object ID of the | device, determined by the terminal device SDK
A specific instance ID under obj_inst_id | int | no | nbiot device object is determined according to terminal device SDK
Resource ID of res_id | int | no | nbiot device, determined by terminal device SDK
The valid_time | string | no | command takes effect at a time that must be greater than the current time of the OneNET server
Expired_time | string | is | command expiration time, must be greater than valid_time
Retry | int | no | [0 10], which indicates the number of failed retries (waiting for the next device update or online), defaults to 3
Timeout | int | no | expiration time, must be between [5,40]; default is 25
The type of uplink message triggered by trigger_msg | int | no | command must be between [1,7]; the default is 7.


#### Return parameters
Parameter name | format | description
:- | :- | :- 
Error no | int | Calls the error code, which is 0 to indicate that the call was successful
Error | string | Error description, which indicates that the call succeeded for "succ"
Data | JSON | Interface call success returns device-related information, as shown in the data description table

##### data description table
Parameter name | format | description
:- | :- | :- 
UUID | string | offline command UUID

##### Description

The corresponding meaning of returning errno status code can be found in "NB protocol northward API return status code description" in OneNET Document Center - > Device Development Guide - > Protocol Document - > LwM2M[download and view](/book/device-development/multpro/sdk-doc-tool/doc.md)

Valid_time and expired_time formats are: "2018-03-08T17:30:00"


```text
trigger_msg 触发类型：
1. REGISTER   
2. UPDATE   
3. REGISTER | UPDATE 组合  
4. NOTIFY
5. REGUSTER | NOTIFY 组合
6. UPDATE | NOTIFY 组合
7. NOTIFY | UPDATE | REGISTE 组合
```


#### Examples of requests

```text
GET http://api.heclouds.com/nbiot/offline HTTP/1.1
api-key: WhI*************v1c=
Host: api.heclouds.com

```
#### Return an example
```json
{
    "errno": 0,
    "data": {
        "uuid": "42742677-adc3-54ca-83a1-5aaaf71482f8"
    },
    "error": "succ"
}
```