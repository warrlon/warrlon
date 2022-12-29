# 设备状态记录查询

#### 接口名称

> QueryDeviceStatusHistory

#### 请求方法

> GET

#### 请求参数
|参数名称 | 类型 | 是否必选 | 描述 |
|:- | :- | :- | :- |
|project_id | string | 是 | 项目ID |
|product_id | string | 是 | 产品ID |
|device_name | string | 是 | 设备名称 |
|start_time | string | 是 | 查询起始时间，毫秒时间戳 |
|end_time | string | 是 | 查询结束时间，毫秒时间戳 |
|offset | string | 否 | 请求起始位置，默认0 |
|limit | string | 否 | 每次请求记录数，默认10, 范围[1, 100] |

#### 返回数据
|参数名称 | 类型 | 描述 |
|:- | :- | :- | :- |
| code | string  | 调用失败时，返回的错误码 |
| msg  | string  | 调用失败时，返回的错误信息 |
| requestId | string | 调用API时生成的请求标识  |
| success | boolean | 接口是否调用成功 |
| data | - | 调用成功返回业务数据 |
| data.list | array | 设备状态历史数据集合 |
| data.meta | object | 分页信息 |

##### data.list 字段结构为

```
[
    {
        "status": int, # 设备状态 0-离线 1-在线
        "time": 1592795961766
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
GET url/application?action=QueryDeviceStatusHistory&version=1&project_id=ocgzVU&product_id=9MaNe52pNO&device_name=no001&start_time=1592795951065&end_time=1592795971065

```

##### 响应示例

```
{
    "data": {
        "list": [{
            "status": 0,
            "time": 1592398421297,
        }],
        "meta": {
            "limit": 10,
            "offset": 0
        }
    },
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
```