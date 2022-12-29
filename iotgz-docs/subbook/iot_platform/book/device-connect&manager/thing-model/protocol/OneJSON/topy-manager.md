# 管理拓扑关系

[1. 绑定子设备](#1-绑定子设备)

[2. 解绑子设备](#2-解绑子设备)

[3. 获取拓扑关系](#3-获取拓扑关系)

[4. 网关拓扑关系变化通知](#4-网关拓扑关系变化通知)

---

### 1. 绑定子设备

网关类型的设备，可以通过Topic上行请求添加它和子设备之间的拓扑关系，单个网关设备最多支持添加1500个子设备

- 请求topic:$sys/{pid}/{device-name}/thing/sub/topo/add

OneJSON数据格式:

```json
{
    "id":"123",
    "version":"1.0",
    "params":{
        "deviceName":"device1",
        "productID":"product1",
        "sasToken":"version=2018-10-31&res=products/product1/devices/device1&et=1537255523&method=sha1&sign=ZjA1NzZlMmMxYzIOTg3MjBzNjYTI2MjA4Yw%3D"
    }
}
```

表：请求参数说明

| 参数       | 类型       | 说明                                                         |
| ---------- | ---------- | ------------------------------------------------------------ |
| id         | String     | 消息id号，用户自定义，String类型的数字，长度限制不超过13位。 |
| version    | String     | 物模型版本号，可选字段，不填默认为1.0                        |
| params     | JsonObject | 请求入参，包含要要绑定的子设备的信息                      |
| deviceName | String     | 子设备的设备名称                                      |
| productID  | String     | 子设备所属产品的productID                                 |
| sasToken   | String      | 鉴权token，具体可参考[设备安全认证](/book/device-connect&manager/device-auth.md) |

- 响应topic:$sys/{pid}/{device-name}/thing/sub/topo/add/reply

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
| id   | String  | 消息id号，String类型的数字，长度限制不超过13位 |
| code | Integer | 结果状态码，成功返回200                                      |
| msg  | String  | 错误信息                                                     |

### 2. 解绑子设备

网关类型的设备，可以通过Topic上行请求解绑它和子设备之间的拓扑关系

- 请求topic:$sys/{pid}/{device-name}/thing/sub/topo/delete

OneJSON数据格式:

```json
{
    "id":"123",
    "version":"1.0",
    "params":{
        "deviceName":"device1",
        "productID":"product1",
        "sasToken":"version=2018-10-31&res=products/product1/devices/device1&et=1537255523&method=sha1&sign=ZjA1NzZlMmMxYzIOTg3MjBzNjYTI2MjA4Yw%3D"
    }
}
```

表：请求参数说明

| 参数       | 类型       | 说明                                                         |
| ---------- | ---------- | ------------------------------------------------------------ |
| id         | String     | 消息id号，用户自定义，String类型的数字，长度限制不超过13位。 |
| version    | String     | 物模型版本号，可选字段，不填默认为1.0                        |
| params     | JsonObject | 请求入参，包含要要绑定的子设备的信息。                       |
| deviceName | String     | 子设备的设备名称。                                           |
| productID  | String     | 子设备所属产品的productID。                                  |
| sasToken   | String      | 鉴权token，具体可参考[设备安全认证](/book/device-connect&manager/device-auth.md) |

- 响应topic:$sys/{pid}/{device-name}/thing/sub/topo/delete/reply

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
| id   | String  | 消息id号，String类型的数字，长度限制不超过13位 |
| code | Integer | 结果状态码，成功返回200                                       |
| msg  | String  | 错误信息                                                     |

### 3. 获取拓扑关系

网关类型的设备，可以获取该网关设备拓扑关系，平台返回该网关设备的拓扑，网关本地同步成功后，回复平台同步状态（控制台可查看同步状态）

- 请求topic:$sys/{pid}/{device-name}/thing/sub/topo/get

OneJSON数据格式:

```json
{
    "id":"123",
    "version":"1.0",
}
```

表：请求参数说明

| 参数    | 类型   | 说明                                                         |
| ------- | ------ | ------------------------------------------------------------ |
| id      | String | 消息id号，用户自定义，String类型的数字，长度限制不超过13位 |
| version | String | 物模型版本号，可选字段，不填默认为1.0                        |

- 响应topic:$sys/{pid}/{device-name}/thing/sub/topo/get/reply

OneJSON数据格式:

```json
{
    "id":"123",
    "code":200,
    "msg":"xxxx",
    "data":[
        {
            "deviceName":"device1",
            "productID":"product1"
        },
        {
            "deviceName":"device2",
            "productID":"product2"
        }
    ]
}
```

表:响应参数描述

| 参数       | 类型    | 说明                                                       |
| ---------- | ------- | ---------------------------------------------------------- |
| id         | String  | 消息id号，String类型的数字，长度限制不超过13位 |
| code       | Integer | 结果状态码，成功返回200                                     |
| msg        | String  | 错误信息                                                   |
| data       | array   | 请求成功时，返回的所有子设备信息                           |
| deviceName | String  | 子设备的设备名称                                           |
| productID  | String  | 子设备所属产品的productID                                  |

- 网关同步结果响应topic: $sys/{pid}/{device-name}/thing/sub/topo/get/result

OneJSON数据格式:

```json
{
    "id":"123",
    "code":200,
    "msg":"xxxx"
}
```

表 . 响应参数说明

| 参数 | 类型    | 说明                                                         |
| :--- | :------ | :----------------------------------------------------------- |
| id   | String  | 消息id号，String类型的数字，长度限制不超过13位 |
| code | Integer | 返回结果，200代表成功                                    |
| msg  | String  | 结果信息，可选项                                        |

### 4. 网关拓扑关系变化通知

用户通过控制台或者API修改了网关的拓扑关系，平台需通知网关拓扑发生变化

- 通知topic:$sys/{pid}/{device-name}/thing/sub/topo/change

OneJSON数据格式:

```json
{
    "id":"123",
    "version":"1.0",
    "params":{
        "subList":[
            {
                "deviceName":"device1",
                "productID":"product1"
            },
            {
                "deviceName":"device2",
                "productID":"product2"
            }
        ]
    }
}
```

表：请求参数说明

| 参数       | 类型       | 说明                                                         |
| ---------- | ---------- | ------------------------------------------------------------ |
| id         | String     | 消息id号，String类型的数字，长度限制不超过13位 |
| version    | String     | 物模型版本号，可选字段，不填默认为1.0                        |
| params     | JsonObject | 下发数据信息                                                 |
| subList    | array      | 子设备全量列表                                               |
| deviceName | String     | 子设备的设备名称                                             |
| productID  | String     | 子设备所属产品的productID                                    |

- 响应topic:$sys/{pid}/{device-name}/thing/sub/topo/change_reply

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
| id   | String  | 消息id号，String类型的数字，长度限制不超过13位|
| code | Integer | 结果状态码，成功返回200                                       |
| msg  | String  | 错误信息                                                     |
