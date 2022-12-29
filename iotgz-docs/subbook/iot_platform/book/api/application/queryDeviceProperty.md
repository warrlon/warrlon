# 设备属性最新数据查询

#### 接口名称

> QueryDeviceProperty

#### 请求方法

> GET

#### 请求参数
|参数名称 | 类型 | 是否必选 | 描述 |
|:- | :- | :- | :- |
|project_id | string | 是 | 项目ID |
|product_id | string | 是 | 产品ID |
|device_name | string | 是 | 设备名称 |

#### 返回数据
|参数名称 | 类型  | 描述 |
|:- | :- | :- | :- |
| code | string  | 调用失败时，返回的错误码 |
| msg  | string | 调用失败时，返回的错误信息 |
| requestId | string | 调用API时生成的请求标识  |
| success | boolean | 接口是否调用成功 |
| data | - | 调用成功时，返回的业务数据 |
| data.list | array | 设备状态历史数据集合 |

##### data.list 字段结构为

```
[
    {
        "identifier": string, # 功能点标识
        "time": string, # 上报时间，毫秒时间戳
        "value": string, # 功能点上报值，json字符串
        "data_type": string, # 数据类型 int32、int64、float、double、enum、bool、string、struct、bitMap
        "access_mode": string, # 读写类型
        "expect_value": string, # 期望值, json字符串，属性功能点具有该字段 
        "name": string, # 功能点名称
        "description": string, # 功能描述
    }
]
```

#### 示例

##### 请求示例

```
GET /application?action=QueryDeviceProperty&version=1&project_id=ocgzVU
&product_id=9MaNe52pNO&device_name=no001

```

##### 响应示例

```
{
    "data": {
        "list": [{
           {
                "access_mode": "读写",
                "data_type": "int32",
                "description": "二氧化碳",
                "expect_value": "800",
                "identifier": "CO2",
                "name": "二氧化碳",
                "time": "1592797444539",
                "value": "600"
            },
            {
                "access_mode": "读写",
                "data_type": "bool",
                "description": "关",
                "expect_value": "true",
                "identifier": "fan",
                "name": "风扇",
                "time": "1592797444539",
                "value": "false"
            }
        }]
    },
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
```