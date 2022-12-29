Cache command-command issuance/Execute
---
Request mode: ** POST**

URL: http://api.heclouds.com/nbiot/execute/offline


#### URL parameter
Parameter Name | Format | Whether Must | Explain
:- | :- | :- | :- 
IMEI | string | is the identity code of | nbiot device
Obj_id | int | is the object ID of | nbiot device, corresponding to the data stream ID in the platform model
Obj_inst_id | int | is the ID of a specific instance under | device object, which corresponds to part of the key value of the data point in the platform model.
Res_id | int | is the resource ID of | nbiot device
Valid_time | string | no | command start time stamp, optional (default is OneNET current time when not filled in)
Expired_time | string | is the | command expiration timestamp, which must be greater than valid_time
Retry | int | no | [0 10], which indicates the number of failed retries (waiting for the next device update or online), defaults to 3
Timeout | int | no | expiration time, must be between [5,40]; default is 25
The type of uplink message triggered by trigger_msg | int | no | command must be between [1,7]; the default is 7.


#### HTTP request parameters
Parameter Name | Format | Whether Must | Explain
:- | :- | :- | :- 
Args | string | no | command string, size limit 2K

#### Return parameters
Parameter name | format | description
:- | :- | :- 
Error no | int | Calls the error code, which is 0 to indicate that the call was successful
Error | string | Error description, which indicates that the call succeeded for "succ"
Data | JSON | Information returned after successful interface invocation is shown in the data description table

##### data description table
Parameter name | format | description
:- | :- | :- 
UUID | string | offline command UUID

##### Description
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
POST http://api.heclouds.com/nbiot/execute/offline?imei=86582003***&valid_time=2016-08-05T08:00:00&expired_time=2016-08-06T08:00:00&obj_id=1212&obj_inst_id=1212&res_id=123 HTTP/1.1
api-key: WhI*************v1c=
Content-Type: application/json
Host: api.heclouds.com

```
#### Examples of request parameters
```json
POST data
{
    "args":"ping"
}
```

#### Return an example
```json
{
    "errno": 0,
    "data": {
        "uuid":"42742677-adc3-54ca-83a1-5aaaf71482f8"
    },
    "error": "succ"
}
```