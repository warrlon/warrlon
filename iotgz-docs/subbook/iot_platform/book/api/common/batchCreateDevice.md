# 设备创建

#### 接口名称

> BatchCreateDevices

#### 请求方法

> POST

#### 请求参数
|参数名称 | 类型 | 是否必选 | 描述 |
|:- | :- | :- | :- |
|product_id | string | 是  | 产品ID |
|devices | array | 是 | 批量创建的设备信息集合, 一次最多创建500个设备。每个集合元素为json对象，包括name和desc属性值,例如[{ "name": "no001" , "desc": "iot application" }], 设备为LwM2M协议时，增加imei、imsi、auth_code、psk属性，校验规则请参考设备创建接口 | 

#### 返回数据
|参数名称 | 类型  | 描述 |
|:- | :- | :- |
| code | string | 调用失败时，返回的错误码 |
| msg  | string  | 调用失败时，返回的错误信息 |
| requestId | string | 调用API时生成的请求标识  |
| success | boolean | 接口是否调用成功 |
| data | - | 调用成功时，返回的业务数据 |
| data.list | array | 创建成功设备信息集合 |

##### data.list 字段结构为

```
[
    {
        "name": string, # 设备名称
        "node_type": int, # 设备类型  1-直连设备
        "desc": string, # 设备描述
        "sec_key": string, # 设备密钥
        "protocol": int,  # 协议类型  1-泛协议  2-MQTT  3-CoAP
        "imei": "366322456556584",
        "imsi": "366322456556584",
        "auth_code": "authcode",   
        "psk": "authcode",          
        "created_time": string, # 创建时间      
    }
]
```

#### 示例

##### 请求示例

```
POST /common?action=BatchCreateDevices&version=1
Content-type: application/json

{

    "product_id": "9MaNe52pNO",
    "devices": [
        {
            "name": "no001", 
            "desc": "iot application"      
        }
    ]
}

```

##### 响应示例

```
{
    "data": {
        list: [{
            "name": "no001",
            "node_type": 1,  
            "desc": "iot application",
            "sec_key": "imQE5CGsIiT9ZMBMD/bSbqMnPIBwXXsYynQQsi/fimk=", 
            "created_time": "2020-06-08T10:33:30.442Z", 
            "protocol": 1
        }]
     },
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
```
