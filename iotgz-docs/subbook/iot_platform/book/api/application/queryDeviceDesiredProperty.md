# 设备属性期望查询

#### 接口名称

> QueryDeviceDesiredProperty

#### 请求方法

> POST

#### 请求参数
|参数名称 | 类型 | 是否必选 | 描述 |
|:- | :- | :- | :- |
|project_id | string | 是 | 项目ID |
|product_id | string | 是 | 产品ID |
|device_name | string | 是 | 设备名称 |
|params | array | 否 | 查询期望值的功能点标识集合，参数不传默认查询所有属性期望，例如["switch", "temperature"]|

#### 返回数据
|参数名称 | 类型  | 描述 |
|:- | :- | :- |
| code | string  | 调用失败时，返回的错误码 |
| msg  | string  | 调用失败时，返回的错误信息 |
| requestId | string | 调用API时生成的请求标识  |
| success | boolean | 接口是否调用成功 |
| data | - | 调用成功返回业务数据 |
| data.params | object | 属性功能点期望值 |

##### data.params 字段结构为

```
{
    "identify": {  // 功能点标识为对象key
        "value": string, # 期望值值
        "version": int, # 期望值版本号
    }
}
```
#### 示例

##### 请求示例

```
POST /application?action=QueryDeviceDesiredProperty&version=1
Content-type: application/json

{
    "project_id": "ocgzVU",
    "product_id": "9MaNe52pNO",
    "device_name": "no001",
    "params": [
        "switch",
        "temperature",
    ]
}
```

##### 响应示例

```
{
    "data": {
       "params": { 
            "switch": {
                "value": "on",
                "version": "2"
            },
            "temperature": {
                "value": 23,
                "version": 1    
            }
        } 
    },
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
```