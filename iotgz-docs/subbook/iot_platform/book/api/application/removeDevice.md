# 项目设备移除

#### 接口名称

> RemoveDevice

#### 请求方法

> POST

#### 请求参数
|参数名称 | 类型 | 是否必选 | 描述 |
|:- | :- | :- | :- |
|project_id | string | 是 | 项目ID |
|product_id | string | 是 | 产品ID |
|devices | array | 是 | 需要移除的设备名称集合 | 

#### 返回数据
|参数名称 | 类型 | 描述 |
|:- | :- | :- |
| code | string | 调用失败时，返回的错误码 |
| msg  | string | 调用失败时，返回的错误信息 |
| requestId | string | 调用API时生成的请求标识  |
| success | boolean | 接口是否调用成功 |
| data | - | 调用成功时，返回的业务数据 |
| data.error_data | array | 移除失败的错误信息集合 |

##### data.err_data 字段结构为
```
[
    {
        "device_name": string, # 移除失败设备名称 
        "cause": string, # 移除失败原因
    }
]
```
#### 示例

##### 请求示例

```
POST /application?action=RemoveDevice&version=1
Content-type: application/json

{
    "project_id": "ocgzVU",
    "product_id": "9MaNe52pNO", 
    "devices": ["no010"]
}

```

##### 响应示例

```
{
    "data": {
       "err_data":[
           {"name": "no010", "cause": "设备不存在"}
        ],
    }
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
```