# OneJSON LwM2M拓展

[1. 设备上行数据](#1-设备上行数据)

[2. 异步服务响应数据](#2-异步服务响应数据)

[3. 设备下行数据](#3-设备下行数据)

---

### 1. 设备上行数据

OneJSON数据格式:

```json
{
  "id": "123",
  "version": "1.0",
  "params": {
    "Power": {
      "value": "on",
      "time": 1524448722123
    },
    "WF": {
      "value": 23.6,
      "time": 1524448722123
    }
  },
  "method":"thing.{功能类型}.{方法}"
}
```

表：请求参数描述

| 参数    | 类型       | 描述                                                                                                                 |
| :------ | :--------- | :------------------------------------------------------------------------------------------------------------------- |
| id      | String     | 消息id号，用户自定义，String类型的数字，长度限制不超过13位。                                                         |
| version | String     | 物模型版本号，可选字段，不填默认为1.0                                                                                |
| params  | JsonObject | 请求参数，标准json格式，内容同基础的OneJSON格式                                                                      |
| method  | string     | 上行数据业务类型，目前仅支持以下四种方法：thing.property.post、thing.event.post、thing.pack.post、thing.history.post |

### 2. 异步服务响应数据

OneJSON数据格式:

```json
{
    "id":"123",
    "code":200,
    "msg":"xxxx",
    "data":{
        "result1":"on",
        "result2":"2"
    },
    "method":"thing.{功能类型}.{identifier}.reply"
}
```

表:响应参数描述

| 参数   | 类型    | 描述                                                                   |
| :----- | :------ | :--------------------------------------------------------------------- |
| id     | String  | 消息id号，用户自定义，String类型的数字，长度限制不超过13位。           |
| code   | Integer | 结果状态码                                                             |
| msg    | String  | 错误消息                                                               |
| data   | Object  | 请求参数，标准json格式，内容同基础的OneJSON格式                        |
| method | String  | 下行数据响应业务类型，目前仅支持服务异步响应：<br/>thing.service.{identifier}.reply |

### 3. 设备下行数据

OneJSON数据格式:

```json
{
  "id": "123",
  "version": "1.0",
  "params": {},
  "method":"thing.{功能类型}.{方法/服务标识符}"
}
```

表：请求参数描述

| 参数    | 类型       | 描述                                                                                                                             |
| :------ | :--------- | :------------------------------------------------------------------------------------------------------------------------------- |
| id      | String     | 消息id号，用户自定义，String类型的数字，长度限制不超过13位。                                                                     |
| version | String     | 物模型版本号，可选字段，不填默认为1.0                                                                                            |
| params  | JsonObject | 请求参数，标准json格式，内容同基础的OneJSON格式                                                                                  |
| method  | string     | 上行数据业务类型，目前仅支持以下3种方法：<br/>thing.property.set、<br/>thing.property.get、<br/>thing.service.{identifier} |
