Update trigger
---
Request mode: ** PUT**

URL: http://api.heclouds.com/triggers/trigger_id

    Trigger_id: trigger ID



#### HTTP request parameters
Parameter Name | Format | Whether Must | Explain
:- | :- | :- | :- 
Title | string | no | trigger name
Ds_id | string | no | optional, data stream name, data stream name, consisting of {obj_id} {obj_inst_id} {res_id}
Dev_ids | array-string | no | optional, device ID
Ds_uuids | array-string | no | optional, data stream UUID
URL | string | no | URL
Type | string | no | trigger type
Threshold | int | no | trigger value


##### Description of parameters

```text
1、触发器的含义是：当指定范围内的数据点满足触发条件的要求时，会向url参数指定的地址发送post请求；

2、触发器有三种工作触发模式
  1) 在请求参数中单独指定了ds_id，不包括其他参数，那么当前项目下所有设备的数据流中数据流名称符合ds_id
的数据都会进入触发判断逻辑；
  2) 在请求参数中单独指定了ds_uuids数组，那么只有这些指定的数据流会进入触发判断逻辑；
  3) 在请求参数中指定了ds_id和dev_ids，那么只有这些指定的设备的数据流会进入触发判断逻辑。
```

#### Return parameters
Parameter name | format | description
:- | :- | :- 
Error no | int | Calls the error code, which is 0 to indicate that the call was successful
Error | string | Error description, which indicates that the call succeeded for "succ"

##### Description
```
若要修改触发条件，必须同时设置type和threshold
```
#### Examples of requests

```text
PUT http://api.heclouds.com/triggers/350092 HTTP/1.1
api-key: WhI*************v1c=
Content-Type: application/json
Host: api.heclouds.com

```
#### Examples of request parameters
```json
POST data
{
    "title":"wen du jian kong ",
    "ds_id": "gps",
    "url":"http://xx.wd.com",
    "type":"<=",
    "threshold":60
}
```

#### Return an example
```json
{
    "errno": 0,
    "error": "succ"
}
```