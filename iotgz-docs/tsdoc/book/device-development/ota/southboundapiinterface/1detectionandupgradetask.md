# Detection and Upgrade Tasks

Request mode: ** GET**

URL: http://ota.heclouds.com/ota/check

#### HTTP head
Parameter Name | Format | Whether Must | Explain
:- | :- | :- | :- 
Content-Type | string | is | must be application/json
Authorization | string | is | security authentication information


#### HTTP request parameters
Parameter Name | Format | Whether Must | Explain
:- | :- | :- | :- 
Dev_id | string | is | device ID
Manuf | string | is the name of the manufacturer
Model | string | is | module model
Type | int | is | task type, 1 represents FOTA task, 2 represents SOTA task.
Version | string | is | version information
Signals | int | No | Signal strength
Pows | int | No | Percentage of Residual Electricity
CDN | Boolean | is | device supports domain name resolution please select true, if device does not support domain name resolution please select false

#### Return parameters
Parameter name | format | description
:- | :- | :- 
Error no | int | Call error code, see error code description for details
Error | string | Error description, which indicates that the call succeeded for "succ"
Data | JSON | Interface call success returns device-related information, as shown in the data description table

#### data description table
Parameter name | format | description
:- | :- | :- 
Target | string | upgrade the target version of the task
Token | string | file address ip: port/ota/download/{token}
Size | int | file size
Signal | int | Task is performed under a larger signal
The power | int | task is performed at a greater power level than that.
Retry | int | retry times
Interval | int | retry interval
MD5 | string | upgrade file MD5 code
IP | string | pull the IP address of the upgrade package

#### Error Code Description
Error code | description
:- | :-
0 | Successful detection
7 | OneNET internal error
8 | Detection failure, device upgrade task, manuf or model inconsistency
9 | Detection failure, equipment upgrade task, version inconsistency
10 | Check failed, device upgrade task, signal or power inconsistency
11 | Check failed, device does not have type (fota / sota) corresponding upgrade tasks
13 | Check failed, device has upgrade task, but task status is invalid
19 | Detection failed, device task suspended

#### Examples of HTTP request parameters

```json
{
    "dev_id": 6523,
    "manuf": "中国移动",
    "model": "M5310",
    "type": 1,
    "version":"1.2" ,
    "signals": 10,
    "powers":30,
    "cdn": true

}
```

#### Return an example

```json
{
    "errno": 0,
    "error": "succ",
    "data": {
        "target":"1.2",
        "token":"dafddad",
        "size":123,
        "signal":12,
        "power":90,
        "retry":10,
        "interval":90,
        "md5":"dfkdajkfd",
         "ip":"172.19.3.3"
    }
}
```