# 设备事件记录查询

#### 接口名称

> QueryDeviceEventHistory

#### 请求方法

> GET

#### 请求参数
|参数名称 | 类型 | 是否必选 | 描述 |
|:- | :- | :- | :- |
|project_id | string | 是 | 项目ID |
|product_id | string | 是| 产品ID |
|device_name | string | 是 | 设备名称 |
|start_time | string | 是 | 查询起始时间，毫秒时间戳 |
|end_time | string | 是 | 查询结束时间，毫秒时间戳 |
|identifier | string | 否 | 事件功能点标识 |
|event_type | string | 否 | 事件类型 1-信息 2-告警 3-故障 |
|offset | string | 否 | 请求起始位置，默认0 |
|limit | string | 否 | 每次请求记录数，默认10, 范围[1, 100] |

#### 返回数据
|参数名称 | 类型 | 描述 |
|:- | :- | :- |
| code | string | 调用失败时，返回的错误码 |
| msg  | string | 调用失败时，返回的错误信息 |
| requestId | string | 调用API时生成的请求标识  |
| success | boolean | 接口是否调用成功 |
| data | - | 调用成功时，返回的业务数据 |
| data.list | array | 设备事件历史数据集合 |
| data.meta | object | 分页信息 |

##### data.list字段结构
```
[
    {
        "event_type": int, # 事件类型 1-信息 2-告警 3-故障
        "identifier": "lock_event", # 事件功能点标识
        "name": "lock_event", # 事件功能点名称
        "time": "1592814341051",  # 事件功能点上报时间
        "value": "{\"type\":1, \"user\"=27010}"  # 事件功能点上报值，json字符串
    }
]
```
##### data.meta 字段结构为

```
{
    "limit": int, # 每次请求记录数
    "offset": int, # 请求记录起始位置
}
```
#### 示例

##### 请求示例

```
GET /application?version=1&action=QueryDeviceEventHistory&project_id=ocgzVU
&product_id=9MaNe52pNO&device_name=no001&start_time=1592811019119&end_time=1592811198213

```

##### 响应示例

```
{
    "data": {
        "list": [ 
            {
                "event_type": 1,
                "identifier": "lock_event",
                "name": "lock_event",
                "time": "1592814341051",
                "value": "{\"type\":1, \"user\":27010}"
            },
            {
                "event_type": 1,
                "identifier": "lock_event",
                "name": "lock_event",
                "time": "1592814336050",
                "value": "{\"type\":2, \"user\":27010}"
            }
        ]
    },
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
```