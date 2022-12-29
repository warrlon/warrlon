根据imei查询设备信息
---
请求方式：**GET**

URL: http://api.heclouds.com/devices/getbyimei



#### url参数
参数名称 | 格式 | 是否必须 | 说明
:- | :- | :- | :- 
imei | string | 是 | nbiot设备的身份码

#### 返回参数
参数名称 | 格式 | 说明
:- | :- | :- 
errno | int | 调用错误码，为0表示调用成功
error | string | 错误描述，为"succ"表示调用成功
data | json | 接口调用成功之后返回的设备相关信息，见data描述表

##### data描述表
参数名称 | 格式 | 说明
:- | :- | :- 
create_time | string | 设备创建时间，北京时间
id | string | 设备ID
online | bool | 设备在线状态
observ_status|bool|订阅状态，表示：设备上线后，平台下发订阅命令，设备资源是否全部成功
title | string | 设备名
desc | string | 描述，若有则返回



#### 请求示例
```text
GET http://api.heclouds.com/devices/getbyimei?imei=865***03 HTTP/1.1
api-key: WhI*************v1c=
Host: api.heclouds.com

```

#### 返回示例
```json
{
	"errno": 0,
	"error": "succ",
	"data": {
        "create_time": "2019-04-24 14:54:29",
        "online": false,
        "id": "5241665",
        "observe_status": false,
        "title": "xxxxxx"
	},
	"error": "succ"
}
```
