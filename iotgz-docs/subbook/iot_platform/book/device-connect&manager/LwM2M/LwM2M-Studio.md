# LwM2M-Studio

[1. 支持功能概览](#1-支持功能概览)

[2. 数据模型](#2-数据模型)

[3. 平台接入地址](#3-平台接入地址)

---

## 1. 支持功能概览

- 支持IMEI、IMEI+AuthCode等设备认证方式
- 支持DTLS加密传输
- 支持OMA-IPSO和OneNET-OneJson数据模型
- 支持FOTA/SOTA远程升级，以及通用OTA升级

## 2. 数据模型

LwM2M-studio支持标准OMA-IPSO和OneNET-OneJson两种数据模型，设备只能选择一种数据模型进行接入。

### 2.1. OMA-IPSO数据模型

支持除了object19外的标准Object交互

### 2.2. OneNET-OneJson数据模型

OneNET平台占用object19，并基于object19进行物模型OneJson数据交互。

- 平台物模型通道上行-数据上报：19/0/0
- 平台物模型通道-命令下发：19/1/0
- 平台物模型通道-命令异步回复上报数据：19/1/0

#### 2.2.1. 设备数据上行OneJson数据格式

##### 2.2.1.1. OneJson设备请求数据格式(设备 -> 平台)：

1） 设备请求OneJson数据格式
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

2） 表：请求参数描述

| **参数** | **类型**   | **描述**                                                                                                                                 |
| -------- | ---------- | ---------------------------------------------------------------------------------------------------------------------------------------- |
| id       | String     | 消息id号，用户自定义，String类型的数字，长度限制不超过13位                                                                           |
| version  | String     | 物模型版本号，可选字段，不填默认为1.0                                                                                                    |
| params   | JsonObject | 请求参数，标准json格式，内容同基础的OneJSON格式                                                                                          |
| method   | string     | 上行数据业务类型，目前仅支持以下四种方法：</br>thing.property.post、</br>thing.event.post、</br>thing.pack.post、</br>thing.history.post |


##### 2.2.1.2. OneJson平台响应数据格式(平台 -> 设备)：

1） OneJSON数据格式:

```json
{
  "id": "123",
  "code":200,
  "msg":"xxxx"
}
```

2） 表:响应参数描述

| 参数 | 类型    | 描述                                                         |
| ---- | ------- | ------------------------------------------------------------ |
| id   | String  | 消息id号，String类型的数字，长度限制不超过13位 |
| code | Integer | 结果状态码                                                   |
| msg  | String  | 错误信息         

#### 2.2.2. 平台命令下行 

##### 2.2.2.1. 平台请求OneJson数据格式 （平台 -> 设备）

1） OneJSON数据格式:

```json
{
  "id": "123",
  "version": "1.0",
  "params": {},
  "method":"thing.{功能类型}.{方法}"
}
```

2） 表：请求参数描述

| **参数** | **类型**   | **描述**                                                                                                                        |
| -------- | ---------- | ------------------------------------------------------------------------------------------------------------------------------- |
| id       | String     | 消息id号，由平台生成，String类型的数字，长度限制不超过13位                                                                   |
| version  | String     | 物模型版本号，可选字段，不填默认为1.0                                                                                           |
| params   | JsonObject | 请求参数，标准json格式，内容同基础的OneJSON格式                                                                                 |
| method   | string     | 上行数据业务类型，目前仅支持以下4种方法：thing.property.set、thing.property.get、thing.service.{identifier} |

##### 2.2.2.2. 设备回复OneJson数据格式 （设备 -> 平台） 

- 同步服务设备响应

1） OneJSON数据格式：

```json
{
    "id":"123",
    "code":200,
    "msg":"xxxx"
}
```

2） 表:响应参数描述

| 参数 | 类型    | 描述                                                       |
| ---- | ------- | ---------------------------------------------------------- |
| id   | String  | 消息id号，String类型的数字，长度限制不超过13位 |
| code | Integer | 结果状态码                                                 |
| msg  | String  | 错误信息                                                   |


- 异步服务设备响应

1） OneJSON数据格式:

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

2） 表:响应参数描述

| **参数** | **类型** | **描述**                                                                            |
| -------- | -------- | ----------------------------------------------------------------------------------- |
| id       | String   | 消息id号，String类型的数字，长度限制不超过13位                      |
| code     | Integer  | 结果状态码                                                                          |
| msg      | String   | 错误消息                                                                            |
| data     | Object   | 请求参数，标准json格式，内容同基础的OneJSON格式                                     |
| method   | String   | 下行数据响应业务类型，目前仅支持服务异步响应：thing.service.{identifier}.reply |


## 3. 平台接入地址

| **通信协议** | **地址**            | **端口** | **说明**       |
| -------- | --------------- | ---- |  ---------- |
| LwM2M    | studio-LwM2M.heclouds.com | 5683  |非加密端口 |

