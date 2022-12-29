New triggers
---
Request mode: ** POST**

URL: http://api.heclouds.com/triggers

#### HTTP request parameters
Parameter Name | Format | Whether Must | Explain
:- | :- | :- | :- 
Title | string | is the name of | trigger
Ds_id | string | no | optional, data stream name, data stream name, consisting of {obj_id} {obj_inst_id} {res_id}
Dev_ids | array-string | no | optional, device ID
Ds_uuids | array-string | no | optional, data stream UUID
URL | string | is | alarm notification address
Type | string | is the trigger condition for |, see the list of type instructions
Threshold | | is | trigger condition threshold value, used in conjunction with type, see the list of type instructions

##### Description of parameters
```text
1、触发器的含义是：当指定范围内的数据点满足触发条件的要求时，会向url参数指定的地址发送post请求；
2、触发器有三种工作触发模式
   1) 在请求参数中单独指定了ds_id，不包括其他参数，那么当前项目下所有设备的数据流中数据流名称符合ds_id的
数据都会进入触发判断逻辑；
   2) 在请求参数中单独指定了ds_uuids数组，那么只有这些指定的数据流会进入触发判断逻辑；
   3) 在请求参数中指定了ds_id和dev_ids，那么只有这些指定的设备的数据流会进入触发判断逻辑。
```

##### Type description list
Type | description
:- | :- 
>| Threshold must be numeric
< | threshold must be a number
>=| Threshold must be numeric
<= | threshold must be a value
Inout | threshold is set to {"lolmt": 40, "uplmt": 52}, indicating that the data value is triggered when it enters or leaves the closed interval [40, 52].
In | threshold is set to {"lolmt": 40, "uplmt": 52}, indicating that the data value is triggered when it enters the closed interval [40, 52].
Out | threshold is set to {"lolmt": 40, "uplmt": 52}, indicating that the data value is triggered when it leaves the closed interval [40, 52].
Change | threshold parameter does not need to be passed; alarms are triggered when uploaded values change
Frozen | threshold is a value that specifies how many seconds no data is reported to trigger an alarm, while the monitored object enters the frozen state
Live | threshold is a value that specifies how many seconds after reporting data to trigger an alarm

#### Return parameters
Parameter name | format | description
:- | :- | :- 
Error no | int | Calls the error code, which is 0 to indicate that the call was successful
Error | string | Error description, which indicates that the call succeeded for "succ"
Data | JSON | Interface call success returns device-related information, as shown in the data description table

##### data description table
Parameter name | format | description
:- | :- | :- 
Trigger_id | int | trigger ID

#### Request Header Example
```text
POST http://api.heclouds.com/triggers HTTP/1.1
api-key: YHC**************VqKA=
Host: api.heclouds.com
```

#### Examples of request parameters
```json
{
    "title": "trigger",
    "ds_id": "gps",
    "url": "http://aoic.choqf.com",
    "type": ">",
    "threshold": 100
}
```

#### Return an example
```json
{
    "errno":0,
    "data": {
        "trigger_id":123809
    },
    "error":"succ"
}
```

#### Trigger data example
```json
{
    "trigger": {
        "id": 123809,
        "threshold": 9.0,
        "type": ">"
    },
    "current_data": [{
            "dev_id": "2656",
            "ds_id": "gps",
            "ds_uuid": "FWEF-ZFW-ZFW-ZFWW",
            "at": "2009-09-07T12:16:02.001403Z",
            "value": 100
        }
    ]
}
```