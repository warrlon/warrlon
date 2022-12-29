# 子设备数据交互

[1. 子设备数据上传](#1-子设备数据上传)

[2. 子设备属性获取](#2-子设备属性获取)

[3. 子设备属性设置](#3-子设备属性设置)

[4. 子设备服务调用](#4-子设备服务调用)

---

### 1. 子设备数据上传

子设备数据上传采用批量上送数据通道，具体参考「设备属性/事件」的[「批量数据上报」](/book/device-connect&manager/thing-model/protocol/OneJSON/property&event.md#5-批量上报数据)或[「历史数据上报」](/book/device-connect&manager/thing-model/protocol/OneJSON/property&event.md#5-历史数据上报)

### 2. 子设备属性获取

支持应用通过网关获取子设备属性，目前仅支持一次获取单个子设备多个属性，每次获取属性个数不超过50个，超时时间为5s

- 请求topic:$sys/{pid}/{device-name}/thing/sub/property/get

OneJSON数据格式:

```json
{
    "id":"123",
    "version":"1.0",
    "params":{
        "deviceName":"device1",
        "productID":"product1",
        "params":[
            "temperature",
            "humidity"
        ]
    }
}
```

表：请求参数说明

| 参数           | 类型       | 说明                                                         |
| -------------- | ---------- | ------------------------------------------------------------ |
| id             | String     | 消息id号，用户自定义，String类型的数字，长度限制不超过13位。 |
| version        | String     | 物模型版本号，可选字段，不填默认为1.0                        |
| params（外层） | JsonObject | 获取属性最新值的相关信息                                     |
| deviceName     | String     | 子设备的设备名称。                                           |
| productID      | String     | 子设备所属产品的productID。                                  |
| params（内层） | array      | 请求属性标识符列表                                           |

- 响应topic:$sys/{pid}/{device-name}/thing/sub/property/get_reply

OneJSON数据格式:

```json
{
    "id":"123",
    "code":200,
    "msg":"xxx",
    "data":{
        "temperature":39.5,
        "humidity":20
    }
}
```

表:响应参数描述

| 参数 | 类型       | 说明                                                         |
| ---- | ---------- | ------------------------------------------------------------ |
| id   | String     | 消息id号，用户自定义，String类型的数字，长度限制不超过13位。 |
| code | Integer    | 结果状态码，用户自定义                                       |
| msg  | String     | 错误信息                                                     |
| data | JsonObject | 获取属性最新值列表                                           |

### 3. 子设备属性设置

支持应用通过网关设置子设备属性，目前仅支持一次设置单个子设备多个属性，每次设置属性个数不超过50个，超时时间为5s

- 请求topic:$sys/{pid}/{device-name}/thing/sub/property/set

OneJSON数据格式:

```json
{
    "id":"123",
    "version":"1.0",
    "params":{
        "deviceName":"device1",
        "productID":"product1",
        "params":{
            "temperature":"30.5",
            "humidity":"20.5"
        }
    }
}
```

表：请求参数说明

| 参数           | 类型       | 说明                                                         |
| -------------- | ---------- | ------------------------------------------------------------ |
| id             | String     | 消息id号，用户自定义，String类型的数字，长度限制不超过13位。 |
| version        | String     | 物模型版本号，可选字段，不填默认为1.0                        |
| params（外层） | JsonObject | 设置属性值的相关信息                                         |
| deviceName     | String     | 子设备的设备名称。                                           |
| productID      | String     | 子设备所属产品的productID。                                  |
| params（内层） | array      | 设置属性的值列表                                             |

- 响应topic:$sys/{pid}/{device-name}/thing/sub/property/set_reply

OneJSON数据格式:

```json
{
    "id":"123",
    "code":200,
    "msg":"xxxx"
}
```

表:响应参数描述

| 参数 | 类型    | 说明                                                         |
| ---- | ------- | ------------------------------------------------------------ |
| id   | String  | 消息id号，用户自定义，String类型的数字，长度限制不超过13位。 |
| code | Integer | 结果状态码，用户自定义                                       |
| msg  | String  | 错误信息                                                     |

### 4. 子设备服务调用

网关可代替子设备获取平台下发的服务调用，并返回设备执行结果。

- 请求topic:$sys/{pid}/{device-name}/thing/sub/service/invoke

OneJSON数据格式:

```json
{
    "id":"123",
    "version":"1.0",
    "params":{
        "deviceName":"device1",
        "productID":"product1",
        "identifier":"xxxx",
        "input":{
            "Power1":"on",
            "WF1":"2"
        }
    }
}
```

表：请求参数说明

| 参数       | 类型   | 说明                                                         |
| :--------- | :----- | :----------------------------------------------------------- |
| id         | String | 消息id号，用户自定义，String类型的数字，长度限制不超过13位。 |
| version    | String | 物模型版本号，可选字段，不填默认为1.0                        |
| params     | Object | 请求入参，详情见表params。                                   |
| deviceName | String | 子设备的设备名称。                                           |
| productID  | String | 子设备所属产品的productID。                                  |
| identifier | String | 服务标识符                                                   |
| input      | Object | 服务的请求参数，参数类型具体见物模型对应的“”服务“”定义       |

- 响应topic:$sys/{pid}/{device-name}/thing/sub/service/invoke_reply

OneJSON数据格式:

```json
{
    "id":"123",
    "code":200,
    "msg":"xxxx",
    "data":{
        "deviceName":"device1",
        "productID":"product1",
        "identifier":"xxxx",
        "output":{
            "result1":"on",
            "result2":"2"
        }
    }
}
```

    消息体中，参数productID和deviceName的值是子设备的对应信息

表:响应参数描述

| 参数       | 类型       | 说明                                                         |
| ---------- | ---------- | ------------------------------------------------------------ |
| id         | String     | 消息id号，用户自定义，String类型的数字，长度限制不超过13位。 |
| code       | Integer    | 结果状态码，用户自定义                                       |
| msg        | String     | 错误信息                                                     |
| data       | JsonObject | 请求成功是，返回的服务调用结果，具体见表.data                |
| deviceName | String     | 子设备的设备名称。                                           |
| productID  | String     | 子设备所属产品的productID。                                  |
| identifier | String     | 服务标识符                                                   |
| output     | Object     | 服务的响应参数，参数类型具体见物模型对应的“”服务“”定义       |
