# 项目集成设备列表

#### 接口名称

> QueryDeviceList

#### 请求方法 

> GET

#### 请求参数
|参数名称 | 类型 | 是否必选  | 描述 |
|:- | :- | :- | :- |
|project_id | string | 是 | 项目ID |
|product_id | string | 否 | 产品ID |
|group_id | string | 否 | 分组ID |
|device_name | string | 否 | 设备名称 |
|from | string | 否 | 设备来源 1-自主创建 2-他人转移 |
|offset | string | 否 | 请求记录起始位置，默认 0 |
|limit | string | 否 | 每次请求记录数，默认10, 范围[1, 100] |

#### 返回数据
|参数名称 | 类型 | 描述 |
|:- | :- | :- | :- |
| code | string | 调用失败时，返回的错误码 |
| msg  | string  | 调用失败时，返回的错误信息 |
| requestId | string | 调用API时生成的请求标识  |
| success | boolean | 接口是否调用成功 |
| data | - | 调用成功时，返回的业务数据 |
| data.list | array | 设备信息集合 |
| data.meta | object | 分页信息 |

##### data.list 字段结构为

```
[
    {
        "product_id": string, # 产品ID
        "product_name": string, # 产品名称
        "device_name": string, # 设备名称
        "status": string, # 设备状态 1-未激活 2-在线 3-离线
        "from": string, # 设备来源 1-自主创建 2-他人转移
        "node_type": int, # 节点类型 1-直连设备
        "created_time": string, # 创建时间
        "last_time": string, # 最后一次在线时间
    }
]
```

##### data.meta 字段结构为

```
{
    "limit": int, # 每次请求记录数
    "offset": int, # 请求记录起始位置
    "total": int, # 记录总数
}
```

#### 示例

##### 请求示例

```
GET /application?action=QueryDeviceList&version=1&project_id=ocgzVU

```

##### 响应示例

```
{
    "data": {
        "list": [
             {
                "product_id": "9MaNe52pNO",
                "product_name": "空气净化器",
                "node_type": 1,
                "status": 1,
                "device_name": "no001",
                "from": 1,
                "created_time": "2020-06-19T06:09:42.300Z",
                "last_time": "0001-01-01T00:00:00.000Z"
            },
            {
                "product_id": "9MaNe52pNO",
                "product_name": "空气净化器",
                "node_type": 1,
                "status": 3,
                "device_name": "no002",
                "from": 1,
                "created_time": "2020-06-19T06:09:22.550Z",
                "last_time": "2020-06-19T09:48:15.027Z"
            }
        ],
        "meta": {
            "limit": 10,
            "offset": 0,
            "total": 2
        }
    },
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
```