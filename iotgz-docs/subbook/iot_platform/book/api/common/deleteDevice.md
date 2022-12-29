# 设备删除

#### 接口名称

> DeleteDevice

#### 请求方法

> POST

#### 请求参数
|参数名称 | 类型 | 是否必选  | 描述 |
|:- | :- | :- | :- |
|product_id | string | 是  | 产品ID |
|device_name | string | 是  | 设备名称 | 

#### 返回数据
|参数名称 | 类型  | 描述 |
|:- | :- | :- | 
| code | string  | 调用失败时，返回的错误码 |
| msg  | string | 调用失败时，返回的错误信息 |
| requestId | string  | 调用API时生成的请求标识  |
| success | boolean | 接口是否调用成功 |

#### 示例

##### 请求示例

```
POST /common?action=DeleteDevice&version=1
Content-type: application/json

{
    "product_id":  "9MaNe52pNO",
    "device_name": "no003"
}

```

##### 响应示例

```
{
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
```