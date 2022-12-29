# 设备状态查询

#### 接口名称

> QueryDeviceStatus

#### 请求方法

> GET

#### 请求参数
|参数名称 | 类型 | 是否必选 | 描述 |
|:- | :- | :- | :- |
|project_id | string | 是 | 项目ID |
|product_id | string | 是 | 产品ID |
|device_name | string | 是 | 设备名称 |

#### 返回数据
|参数名称 | 类型 | 描述 |
|:- | :- | :- |
| code | string | 调用失败时，返回的错误码 |
| msg  | string | 调用失败时，返回的错误信息 |
| requestId | string | 调用API时生成的请求标识  |
| success | boolean | 接口是否调用成功 |
| data | - | 调用成功时，返回的业务数据 |
| data.status | int | 设备状态 1-未激活 2-在线 3-离线 |

#### 示例

##### 请求示例

```
GET /application?action=QueryDeviceStatus&version=1&project_id=ocgzVU
&product_id=9MaNe52pNO&device_name=no001

```

##### 响应示例

```
{
    "data": {
        status: 1
    },
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
```