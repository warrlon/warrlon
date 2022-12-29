# 设备属性/事件

[1. 设备属性上报](#1-设备属性上报)

[2. 设备属性设置](#2-设备属性设置)

[3. 设备属性获取](#3-设备属性获取)

[4. 设备事件上报](#4-设备事件上报)

[5. 批量数据上报](#5-批量数据上报)

[6. 历史数据上报](#6-历史数据上报)

---

### 1. 设备属性上报

上行(OneJSON）

- 请求topic: $sys/{pid}/{device-name}/thing/property/post

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
  }
}
```

表：请求参数描述

| 参数    | 类型       | 描述                                                                                                                                               |
| ------- | ---------- | -------------------------------------------------------------------------------------------------------------------------------------------------- |
| id      | String     | 消息id号，用户自定义，String类型的数字，长度限制不超过13位。                                                                                       |
| version | String     | 物模型版本号，可选字段，不填默认为1.0                                                                                                              |
| params  | JsonObject | 请求参数，用户自定义，标准json格式。如以上示例中，设备上报了的两个属性Power和WF。具体属性信息，包含属性上报时间（time）和上报的属性值（value）。   |
| time    | Long       | 属性值生成时间。该参数为可选字段，到豪秒级。根据您的业务场景决定消息中是否带时间戳。如果消息频繁，需根据时间戳判断消息顺序，建议消息中带有时间戳。 |
| value   | Object     | 上报的属性值                                                                                                                                       |

- 响应topic: $sys/{pid}/{device-name}/thing/property/post/reply

OneJSON数据格式:

```json
{
  "id": "123",
  "code":200,
  "msg":"xxxx"
}
```

表:响应参数描述

| 参数 | 类型    | 描述                                                         |
| ---- | ------- | ------------------------------------------------------------ |
| Id   | String  | 消息id号，用户自定义，String类型的数字，长度限制不超过13位。 |
| code | Integer | 结果状态码                                                   |
| msg  | String  | 错误信息                                                     |

### 2. 设备属性设置

下行(OneJSON):

- 请求topic: $sys/{pid}/{device-name}/thing/property/set

OneJSON数据格式：

```json
{
  "id": "123",
  "version": "1.0",
  "params": {
    "temperature":"30.5"
  }
}
```

表：请求参数描述

| 参数    | 类型       | 描述                                                          |
| ------- | ---------- | ------------------------------------------------------------- |
| id      | String     | 消息id号，平台定义，String类型的数字，长度限制13              |
| version | String     | 物模型版本号，可选字段，不填默认为1.0                         |
| params  | JsonObject | 属性设置参数。如以上示例中，设置属性：{"temperature":"30.5" } |

- 响应topic: $sys/{pid}/{device-name}/thing/property/set_reply
  

OneJSON数据格式：

```json
{
    "id":"123",
    "code":200,
    "msg":"xxxx"
}
```

表:响应参数描述

| 参数 | 类型    | 描述                                                       |
| ---- | ------- | ---------------------------------------------------------- |
| Id   | String  | 消息id号，平台定义，String类型的数字，长度限制不超过13位。 |
| code | Integer | 结果状态码                                                 |
| msg  | String  | 错误信息                                                   |

### 3. 设备属性获取

下行(OneJSON):

- 请求topic: $sys/{pid}/{device-name}/thing/property/get

OneJSON数据格式：

```json
{
    "id":"123",
    "version":"1.0",
    "params":[
        "temperature",
        "humidity"
    ]
}
```

表：请求参数描述

| 参数    | 类型       | 描述                                                         |
| ------- | ---------- | ------------------------------------------------------------ |
| id      | String     | 消息id号，用户自定义，String类型的数字，长度限制不超过13位。 |
| version | String     | 物模型版本号，可选字段，不填默认为1.0                        |
| params  | JsonObject | 获取属性最新值的标识符列表                                   |

- 响应topic: $sys/{pid}/{device-name}/thing/property/get_reply
  

OneJSON数据格式：

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

表：响应参数描述

| 参数 | 类型       | 描述                                                         |
| ---- | ---------- | ------------------------------------------------------------ |
| id   | String     | 消息id号，用户自定义，String类型的数字，长度限制不超过13位。 |
| code | Integer    | 结果状态码，用户自定义                                       |
| msg  | String     | 错误信息                                                     |
| data | JsonObject | 获取属性最新值列表                                           |

### 4. 设备事件上报

上行(OneJSON)

- 请求topic: $sys/{pid}/{device-name}/thing/event/post

OneJSON数据格式:

```json
{
    "id":"123",
    "version":"1.0",
    "params":{
        "identifier1":{
            "value":{
                "Power":"on",
                "WF":"2"
            },
            "time":1524448722123
        },
        "identifier2":{
            "value":{
                "Power":"on",
                "WF":"2"
            },
            "time":1524448722123
        }
    }
}
```

表：请求参数描述

| 参数    | 类型       | 描述                                                                                                                                               |
| ------- | ---------- | -------------------------------------------------------------------------------------------------------------------------------------------------- |
| id      | String     | 消息id号，用户自定义，String类型的数字，长度限制不超过13位。                                                                                       |
| version | String     | 物模型版本号，可选字段，不填默认为1.0                                                                                                              |
| params  | JsonObject | 上报事件的参数。                                                                                                                                   |
| time    | Long       | 属性值生成时间。该参数为可选字段，到豪秒级。根据您的业务场景决定消息中是否带时间戳。如果消息频繁，需根据时间戳判断消息顺序，建议消息中带有时间戳。 |
| value   | Object     | 具体的事件信息。如以上示例中{      "Power": "on",      "WF": "2"}                                                                                  |

- 响应topic: $sys/{pid}/{device-name}/thing/event/post/reply

OneJSON数据格式:

```json
{
  "id": "123",
  "code":200,
  "msg":"xxxx"
}
```

表:响应参数描述

| 参数 | 类型    | 描述                                                         |
| ---- | ------- | ------------------------------------------------------------ |
| Id   | String  | 消息id号，用户自定义，String类型的数字，长度限制不超过13位。 |
| code | Integer | 结果状态码                                                   |
| msg  | String  | 错误信息                                                     |

### 5. 批量数据上报

上行(OneJSON)

- 请求topic: $sys/{pid}/{device-name}/thing/pack/post

  说明：
  每次批量上送不超过10个子设备，每个设备上送数据点数量不超过100个

OneJSON数据格式:

```json
{
    "id":"123",
    "version":"1.0",
    "params":[
        {
            "identity":{
                "productID":"",
                "deviceName":""
            },
            "properties":{
                "Power":{
                    "value":"on",
                    "time":1524448722000
                },
                "WF":{
                    "value":"3",
                    "time":1524448723000
                }
            },
            "events":
                {
                    "alarmEvent1":{
                        "value":{
                            "Power":"on",
                            "WF":"2"
                        },
                        "time":1524448722000
                    },
                    "alarmEvent2":{
                        "value":{
                            "Power":"on",
                            "WF":"2"
                        },
                        "time":1524448722000
                    }
                }
        },
        {
            "identity":{
                "productID":"",
                "deviceName":""
            },
            "properties":{
                "Power":{
                    "value":"on",
                    "time":1524448722000
                },
                "WF":{
                    "value":"3",
                    "time":1524448723000
                }
            },
            "events":
                {
                    "alarmEvent1":{
                        "value":{
                            "Power":"on",
                            "WF":"2"
                        },
                        "time":1524448722000
                    },
                    "alarmEvent2":{
                        "value":{
                            "Power":"on",
                            "WF":"2"
                        },
                        "time":1524448722000
                    }
                }
        }
    ]
}
```

表.请求参数说明

| 参数       | 类型   | 说明                                                                                                                                                                                          |
| :--------- | :----- | :-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| id         | String | 消息id号，用户自定义，String类型的数字，长度限制不超过13位。                                                                                                                                  |
| version    | String | 物模型版本号，可选字段，不填默认为1.0                                                                                                                                                         |
| params     | Object | 请求参数。                                                                                                                                                                                    |
| properties | Object | 属性，包含属性标识符、属性值value 和属性生成的时间time。其中，time参数为可选字段。根据您的业务场景决定消息中是否带时间戳。如果消息频繁，需根据时间戳判断消息顺序，建议消息中带有时间戳。      |
| events     | Object | 事件，包含事件标识符、事件输出参数value和事件生成的时间time。其中，time参数为可选字段。根据您的业务场景决定消息中是否带时间戳。如果消息频繁，需根据时间戳判断消息顺序，建议消息中带有时间戳。 |
| identity   | Object | 设备信息，**可选字段**，如果有此字段，内容为子设备信息                                                                                                                             |
| productID  | String | 子设备产品key。                                                                                                                                                                               |
| deviceName | String | 子设备名称。                                                                                                                                                                                  |

- 响应topic: $sys/{pid}/{device-name}/thing/pack/post/reply

OneJSON数据格式:

```json
{
  "id": "123",
  "code": 200,
  "msg":"xxxx"
}
```

表.响应参数说明

| 参数 | 类型    | 说明                                                         |
| :--- | :------ | :----------------------------------------------------------- |
| id   | String  | 消息id号，用户自定义，String类型的数字，长度限制不超过13位。 |
| code | Integer | 结果状态码                                                   |
| msg  | String  | 错误消息                                                     |

### 6. 历史数据上报

上行(OneJSON)

- 请求topic: $sys/{pid}/{device-name}/thing/history/post

  说明：
  每次批量上送不超过10个子设备，每个设备上送数据点数量不超过100个，每个功能点历史数据不超过100个

OneJSON数据格式:

```json
{
    "id":"123",
    "version":"1.0",
    "params":[
        {
            "identity":{
                "productID":"",
                "deviceName":""
            },
            "properties":{
                "Power":[
                    {
                        "value":"on",
                        "time":1524448722000
                    },
                    {
                        "value":"off",
                        "time":1524448723000
                    }
                ],
                "WF":[
                    {
                        "value":"3",
                        "time":1524448723000
                    },
                    {
                        "value":"3",
                        "time":1524448724000
                    }
                ]
            },
            "events":{
                "alarmEvent1":[
                    {
                        "value":{
                            "Power":"on",
                            "WF":"2"
                        },
                        "time":1524448722000
                    },
                    {
                        "value":{
                            "Power":"off",
                            "WF":"3"
                        },
                        "time":1524448723000
                    }
                ],
                "alarmEvent2":[
                    {
                        "value":{
                            "Power":"on",
                            "WF":"2"
                        },
                        "time":1524448722000
                    },
                    {
                        "value":{
                            "Power":"off",
                            "WF":"3"
                        },
                        "time":1524448723000
                    }
                ]
            }
        },
        {
            "identity":{
                "productID":"",
                "deviceName":""
            },
            "properties":{
                "Power":[
                    {
                        "value":"on",
                        "time":1524448722000
                    },
                    {
                        "value":"off",
                        "time":1524448723000
                    }
                ],
                "WF":[
                    {
                        "value":"3",
                        "time":1524448723000
                    },
                    {
                        "value":"3",
                        "time":1524448724000
                    }
                ]
            },
            "events":{
                "alarmEvent1":[
                    {
                        "value":{
                            "Power":"on",
                            "WF":"2"
                        },
                        "time":1524448723000
                    },
                    {
                        "value":{
                            "Power":"off",
                            "WF":"3"
                        },
                        "time":1524448724000
                    }
                ],
                "alarmEvent2":[
                    {
                        "value":{
                            "Power":"on",
                            "WF":"2"
                        },
                        "time":1524448723000
                    },
                    {
                        "value":{
                            "Power":"off",
                            "WF":"3"
                        },
                        "time":1524448724000
                    }
                ]
            }
        }
    ]
}
```

表 . 请求参数说明

| 参数       | 类型   | 说明                                                         |
| :--------- | :----- | :----------------------------------------------------------- |
| id         | String | 消息id号，用户自定义，String类型的数字，长度限制不超过13位。 |
| version    | String | 物模型版本号，可选字段，不填默认为1.0                        |
| params     | Object | 请求参数。                                                   |
| identity   | String | 数据所属设备的身份证书信息，包含参数productID和deviceName。**可选字段，**默认为topic信息中对应的设备数据；说明 直连设备仅能上报自己的物模型数据。网关设备可以上报其子设备的物模型数据。网关上报子设备历史数据时，identity为子设备的信息。 |
| properties | Object | 属性，包含属性标识符、属性值value 和属性生成的时间time。     |
| events     | Object | 事件，包含事件标识符、事件输出参数value和事件生成的时间time。 |
| productID  | String | 子设备产品key。                                              |
| deviceName | String | 子设备名称。                                                 |

- 响应topic: $sys/{pid}/{device-name}/thing/history/post/reply

OneJSON数据格式:

```json
{
  "id": "123",
  "code": 200,
  "msg":"xxxx"
}
```

表.响应参数说明

| 参数 | 类型    | 说明                                                         |
| :--- | :------ | :----------------------------------------------------------- |
| id   | String  | 消息id号，用户自定义，String类型的数字，长度限制不超过13位。 |
| code | Integer | 结果状态码                                                   |
| msg  | String  | 错误消息                                                     |
