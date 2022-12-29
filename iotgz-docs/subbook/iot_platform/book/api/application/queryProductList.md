# 项目集成产品列表

#### 接口名称

> QueryProductList

#### 请求方法

> GET

#### 请求参数
|参数名称 | 类型 | 是否必选  | 描述 |
|:- | :- | :- | :- |
|project_id | string | 是 | 项目ID |
|offset | string | 否 | 请求起始位置，默认0 |
|limit | string | 否 | 每次请求记录数，默认10 |

#### 返回数据
|参数名称 | 类型 | 描述 |
|:- | :- | :- |
| code | string  | 调用失败时，返回的错误码 |
| msg  | string | 调用失败时，返回的错误信息 |
| requestId | string | 调用API时生成的请求标识  |
| success | boolean | 接口是否调用成功 |
| data | - | 调用成功时, 返回业务数据 |
| data.list | array | 产品信息集合 |
| data.meta | object | 分页信息 |

##### data.list 字段结构为

```
[
    {
        "product_id": string, # 产品ID
        "name": string, # 产品名称
        "type": string, # 类型
        "desc": string, # 描述
        "protocol": int, # 协议 1-泛协议 2-MQTT 3-CoAP
        "node_type": int, # 节点类型 1-直连设备
        "data_type": int, # 数据类型 1-OneJson
        "network": int, # 联网模式 1-其他 2-蜂窝 3-wifi 4-以太网
        "device_number": string, # 设备总数
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
GET /application?action=QueryProductList&version=1&project_id=ocgzVU

```

##### 响应示例

```
{
    "data": {
        "list": [
            {
                "product_id": "9MaNe52pNO",
                "name": "空气净化器",
                "desc":  "智能家居空气净化器",
                "type": 1,
                "protocol":  2, 
                "node_type":  1,
                "data_type":  1,
                "network": 4, 
                "device_number": 2
            }
        ],
        "meta": {
            "limit": 10,
            "offset": 0,
            "total": 1
        }
    },
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
```