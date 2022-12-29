# 设备工业标识注册

#### 接口名称

> RegistDeviceIdentity

#### 请求方法

> POST

#### 请求参数
|参数名称 | 类型 | 是否必选 | 描述 |
|:- | :- | :- | :- |
|product_id | string | 是  | 产品ID |
|devices | array | 是 | 设备信息集合, 一次最多创建500个设备。每个集合元素设备名称,例如["device01", "device02"]| 
|auto_mode | number | 是  | 是否开启自动更新,0：关闭，1：开启 |

#### 返回数据
|参数名称 | 类型  | 描述 |
|:- | :- | :- |
| code | string | 调用失败时，返回的错误码 |
| msg  | string  | 调用失败时，返回的错误信息 |
| requestId | string | 调用API时生成的请求标识  |
| success | boolean | 接口是否调用成功,当部分设备操作失败时，接口返回操作成功，并返回失败设备信息 |
| data | - | 调用成功时，返回的业务数据 |
| data.error_devices | array | 操作失败的设备信息集合 |

##### data.error_devices 字段结构为

```
["device01", "device02"]
```

#### 示例

##### 请求示例

```
POST /common?action=RegistDeviceIdentity&version=1
Content-type: application/json

{
	"product_id": "N57oL1l2fe",
	"devices":["ceshi-0003", "ceshi-0004"],
	"auto_mode": 1,
}

```

##### 响应示例

```
{
    "data": {
        "error_devices": ["ceshi-0003"]
     },
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
```
