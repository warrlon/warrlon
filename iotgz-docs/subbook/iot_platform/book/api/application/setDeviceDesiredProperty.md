# 设备属性期望设置

#### 接口名称

> SetDeviceDesiredProperty

#### 请求方法

> POST

#### 请求参数
|参数名称 | 类型 | 是否必选  | 描述 |
|:- | :- | :- | :- |
|project_id | string | 是  | 项目ID |
|product_id | string | 是  | 产品ID |
|device_name | string | 是 | 设备名称 |
|params | object | 是 | 设置的属性期望值, 数据格式为json对象, 形式为key:value, key为属性功能点标识, value为属性值, 取值符合物模型定义的数据类型和取值范围, 例如{ "switch": true }|

#### 返回数据
|参数名称 | 类型 | 描述 |
|:- | :-  | :- |
| code | string | 调用失败时，返回的错误码 |
| msg  | string | 调用失败时，返回的错误信息 |
| requestId | string | 调用API时生成的请求标识  |
| success | boolean | 接口是否调用成功 |

#### 示例

##### 请求示例

```
POST /application?action=SetDeviceDesiredProperty&version=1
Content-type: application/json

{
    "project_id": "ocgzVU",
    "product_id": "9MaNe52pNO",
    "device_name": "no001",
    "params": {
        "switch": true,             // bool
        "text": "hello",            // string
        "humidity": 12 ,            // int32
        "number": 1564448722123,      // int64
        "temperature": 30.2             // float
        "lng": 3.1234567890123456789,   // double
        "type": 1,                      // enum
        "error": 256,                   // bitmap
        "event":  {                    // struct
            "a": 1,
            "b": true 
        }
    }
}

```

##### 响应示例

```
{
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
```