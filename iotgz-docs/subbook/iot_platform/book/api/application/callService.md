# 调用服务

#### 接口名称

> CallService

#### 请求方法

> POST

#### 请求参数

| 参数名称   | 类型   | 是否必选 | 描述     |
| :--------- | :----- | :------- | :------- |
| project_id | string | 是        | 项目ID |
| product_id | string | 是        | 产品ID |
| device_name | string | 是        | 设备唯一标识 |
| identifier | string | 是        | 服务型功能点标识 |
| params | object | 是        | 输入参数的键值对，输入参数的唯一标识做键 |

#### 返回数据

| 参数名称      | 类型    | 描述                       |
| :------------ | :------ | :------------------------- |
| code          | string  | 调用失败时，返回的错误码   |
| msg           | string  | 调用失败时，返回的错误信息 |
| requestId     | string  | 调用API时生成的请求标识    |
| success       | boolean | 接口是否调用成功           |
| data          | -       | 调用成功时，返回的业务数据 |

#### 示例

##### 请求示例

```
POST /application?action=CallService&version=1
Content-type: application/json

{
  "project_id":"ocgzVU",
  "product_id":"B7EEW578EbRg5Y4K",
  "device_name":"device3",
  "identifier": "light",
  "params":{
    "Power1":"1",
    "WF1":"2"
  }
}
```

##### 响应示例

```
{
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true,
    "data":{
      "result1":"1",
      "result2":"2"
    }
}
```
