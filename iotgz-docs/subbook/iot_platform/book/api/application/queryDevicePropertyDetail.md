# 设备属性获取

#### 接口名称

> QueryDevicePropertyDetail

#### 请求方法

> POST

#### 请求参数

| 参数名称    | 类型   | 是否必选 | 描述           |
| :---------- | :----- | :------- | :------------- |
| project_id  | string | 是       | 设备所属项目id         |
| product_id  | string | 是       | 产品id         |
| device_name | string | 是       | 设备唯一标识   |
| params      | array | 是       | 功能点标识数组，expample: ["light","model"] |

#### 返回数据

| 参数名称  | 类型    | 描述                       |
| :-------- | :------ | :------------------------- |
| code      | string  | 调用失败时，返回的错误码   |
| msg       | string  | 调用失败时，返回的错误信息 |
| requestId | string  | 调用API时生成的请求标识    |
| success   | boolean | 接口是否调用成功           |
| data      | -       | 调用成功时，返回的业务数据 |

#### 示例

##### 请求示例

```text
POST /application?action=QueryDevicePropertyDetail&version=1
Content-type: application/json

{
  "project_id":"ocgzVU",
  "product_id":"B7EEW578EbRg5Y4K",
  "device_name":"device3",
  "params":["light","model"]
}
```

##### 响应示例

```
{
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true,
    "data":{
        "light":1,
        "model":1
    }
}
```
