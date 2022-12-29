# 设备创建

#### 接口名称

> CreateDevice

#### 请求方法 

> POST

#### 请求参数
|参数名称 | 类型 | 是否必选  | 描述 |
|:- | :- | :- | :- |
|product_id | string | 是  | 产品ID |
|device_name | string | 是  | 设备名称 | 
| imei | string |  否(LwM2M协议时必填)  |NB设备imei，15个数字组成的电子串号，设备所属产品为LwM2M时，为必填 |
| imsi | string | 否 | NB设备imsi，不超过15个的数字，设备所属产品为LwM2M时，为必填 |
| psk | string | 否 | NB设备所需属性，若创建未填则平台随机生成，8-16位数字字母组合 |
| auth_code | string | 否 | NB设备鉴权码，1-16位数字字母组合 |
|desc | string | 否 | 设备描述 | 

#### 返回数据
|参数名称 | 类型  | 描述 |
|:- | :-  | :- |
| code | string | 调用失败时，返回的错误码 |
| msg  | string | 调用失败时，返回的错误信息 |
| requestId | string  | 调用API时生成的请求标识  |
| success | boolean  | 接口是否调用成功 |
| data | - | 调用成功时，返回的业务数据 |
| data.name | string | 设备名称 |
| data.node_type | string | 节点类型 1-直连设备 |
| data.desc | string | 设备描述 |
| data.sec_key | string | 设备密钥 |
| data.protocol | int | 协议 1-泛协议 2-MQTT 3-CoAP |
| data.created_time | string | 创建时间 |
| data.imei | string | NB设备imei，15个数字组成的电子串号 |
| data.imsi | string | NB设备imsi，不超过15个的数字 |
| data.auth_code | string | NB设备鉴权码 |
| data.psk | string | NB设备所需属性 |

#### 示例

##### 请求示例

```
POST /common?action=CreateDevice&version=1
Content-type: application/json

{
    "product_id":  "9MaNe52pNO",
    "device_name": "no003",
    "imei": "366322456556584",
    "imsi": "366322456556584",
    "auth_code": "authcode",   
    "psk": "authcode",   
    "desc": "iot application"
}

```

##### 响应示例

```
{
    "data": {
        "name": "no003",
        "node_type": 1, 
        "desc": "iot application", 
        "sec_key": "imQE5CGsIiT9ZMBMD/bSbqMnPIBwXXsYynQQsi/fimk=",
        "created_time": "2020-06-08T10:33:30.442Z", 
        "protocol": 1
    },
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
```
