# 设备属性记录查询

#### 接口名称

> QueryDevicePropertyHistory

#### 请求方法

> GET

#### 请求参数
|参数名称 | 类型 | 是否必选  | 描述 |
|:- | :- | :- | :- |
|project_id | string | 是 | 项目ID |
|product_id | string | 是  | 产品ID |
|device_name | string | 是 | 设备名称 |
|identifier | string | 是 | 属性功能点标识 |
|start_time | string | 是  | 查询起始时间，毫秒时间戳 |
|end_time | string | 是 | 查询结束时间，毫秒时间戳 |
|sort| string | 否 | 排序参数 1-正序  2-倒序|
|offset | string | 否 | 请求起始位置，默认0 |
|limit | string | 否 | 每次请求记录数，默认10, 范围[1, 100] |

#### 返回数据
|参数名称 | 类型  | 描述 |
|:- | :- | :- |
| code | string | 调用失败时，返回的错误码 |
| msg  | string | 调用失败时，返回的错误信息 |
| requestId | string | 调用API时生成的请求标识  |
| success | boolean | 接口是否调用成功 |
| data | - | 调用成功时，返回的业务数据 |
| data.list | array | 设备属性历史数据集合 |
| data.meta | object | 分页信息 |

##### data.list字段结构
```
[
    {
        "value": string, # 属性功能点上报值
        "time": string,  # 属性功能点上报时间
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
GET /application?action=QueryDevicePropertyHistory&version=1&project_id=ocgzVU
&product_id=9MaNe52pNO&device_name=no001&identifier=fan&start_time=1615342778414&end_time=1615342898096

```

##### 响应示例

```
{
    "data": {
        "list": [
            {
                "time": "1592810751988",
                "value": "false"
            },
            {
                "time": "1592810746988",
                "value": "true"
            }
        ]
    },
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
```