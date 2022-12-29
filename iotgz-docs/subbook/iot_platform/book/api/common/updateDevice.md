# 设备编辑

#### 接口名称

> UpdateDevice

#### 请求方法

> POST

#### 请求参数
|参数名称 | 类型 | 是否必选  | 描述 |
|:- | :- | :- | :- |
|product_id | string | 是  | 产品ID |
|device_name | string | 是  | 设备名称 | 
|desc | string | 否 | 设备描述 | 
|imsi | string | 否 | NB设备imsi，不超过15个的数字，设备所属产品为LwM2M时，为必填 |
|psk | string | 否 | NB设备所需属性，若创建未填则平台随机生成，8-16位数字字母组合 |
|auth_code | string | 否 | NB设备鉴权码，1-16位数字字母组合 |
#### 返回数据
|参数名称 | 类型 值 | 描述 |
|:- | :-  | :- |
| code | string | 调用失败时，返回的错误码 |
| msg  | string  | 调用失败时，返回的错误信息 |
| requestId | string | 调用API时生成的请求标识  |
| success | boolean | 接口是否调用成功 |
| data  | - | 调用成功返回业务数据 |
| data.device_name | string | 设备名称 |
| data.desc | string | 设备描述 |

#### 示例

##### 请求示例

```
POST /common?action=UpdateDevice&version=1
Content-type: application/json

{
    "product_id":  "9MaNe52pNO",
    "device_name": "no003",
    "desc": "iot application"
}

```

##### 响应示例

```
{
    "data": {
        "device_name": "no003",
        "desc": "iot application"
    },
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
```