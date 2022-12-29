# 设备属性期望删除

#### 接口名称

> DeleteDeviceDesiredProperty

#### 请求方法

> POST

#### 请求参数
|参数名称 | 类型 | 是否必选 | 描述 |
|:- | :- | :- | :- | :- |
|project_id | string | 是 | 项目ID |
|product_id | string | 是  | 产品ID |
|device_name | string | 是 | 设备名称 |
|params | object | 是 | 删除的属性期望, 数据格式为json对象, 形式为key:value, key为属性功能点标识, value为空对象{} 或者 { "version": 1 }, 如果携带版本号信息，则只有版本号信息等于当前属性期望值版本，才能删除成功 |

#### 返回数据
|参数名称 | 类型  | 描述 |
|:- | :- | :- |
| code | string  | 调用失败时，返回的错误码 |
| msg  | string  | 调用失败时，返回的错误信息 |
| requestId | string | 调用API时生成的请求标识  |
| success | boolean | 接口是否调用成功 |

#### 示例

##### 请求示例

```
POST /application?action=DeleteDeviceDesiredProperty&version=1
Content-type: application/json

{
    "product_id": "12909",
    "device_name": "no001",
    "params": {
        "switch":  { version: 1 },  //删除期望值（版本校验）
        "temperature": {},  // 删除期望值
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