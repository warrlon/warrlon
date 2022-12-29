# 项目概况

#### 接口名称

> QueryStatistics

#### 请求方式 

> GET

#### 请求参数

|参数名称 | 类型 | 是否必选  | 描述 |
|:- | :- | :- | :- |
|project_id | string | 是 | 项目ID |

#### 返回数据

|参数名称 | 类型  | 描述 |
|:- | :- | :- |
| code | string | 调用失败时，返回的错误码 |
| msg  | string |  调用失败时，返回的错误信息 |
| requestId | string | 调用API时生成的请求标识  |
| success | boolean | 接口是否调用成功 |
| data | object | 调用成功时，返回的请求数据 |
| data.project | object | 项目基础信息 |
| data.product_count | int | 集成产品总数 |
| data.device_count | int | 集成设备总数 |
| data.online_count | int | 在线设备总数 |
| data.activate_count | int | 激活设备总数 |
| data.active_count | int | 活跃设备总数 |
| data.product_aggregate | array | 设备分布集合 |

##### data.project 字段结构为

```
{
    "project_id": string, # 项目ID
    "create_time": string, # 项目创建时间
    "tag": array, # 自定义标签名称集合
    "name": string, # 项目名称
    "desc": string, # 项目描述
    "category_name": string, # 行业类别名称
    "category": string, # 行业类别ID 
    "province": string, # 省 
    "city": string, # 市 
    "district": string, # 区、县 
    "street": string, # 街道、路 
    "street_num": string, # 号牌 
    "address": string, # 详细地址
    "lon": string, # 经度 
    "lat": string, # 纬度 
}
```

##### data.product_aggregate 字段结构

```
[
    { 
        "name": string, # 产品名称
        "count": int, # 项目下产品设备总数
    }
]
```

#### 示例

##### 请求示例

```
GET /application?action=QueryStatistics&version=1&project_id=ocgzVU

```

##### 响应示例

```
{
    "data": {
        "project": {
            "project_id": "ocgzVU",
            "name": "智慧城市",
            "desc": "",
            "category": "A003",
            "category_name": "智慧城市",
            "create_time": "2020-06-19T08:18:01.483Z", 
            "project_id": "ocgzVU",
            "province": "重庆市",
            "city": "重庆市",
            "district": "渝北区",
            "street": "",
            "street_num": "",
            "address": "address",
            "lon": "106.644328",
            "lat": "29.726856",
            "tag": [
                "智慧城市"
            ]
        },
        "product_count": 1,
        "device_count": 2,
        "activate_count": 2,
        "active_count": 2,
        "online_count": 2,
        "product_aggregate": [
            "name": "智能烟感",
            "count": 2
         ]
    },
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
```