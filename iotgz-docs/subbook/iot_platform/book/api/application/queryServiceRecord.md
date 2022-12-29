# 服务执行记录查询

#### 接口名称

> QueryServiceRecord

#### 请求方法

> GET

#### 请求参数

| 参数名称   | 类型   | 是否必选 | 描述   |
| :--------- | :----- | :------- | :----- |
| project_id | string | 是       | 项目id |
| trace_id | string | 是       | 调用服务后的requestId |

#### 返回数据

| 参数名称          | 类型    | 描述                       |
| :---------------- | :------ | :------------------------- |
| code              | string  | 调用失败时，返回的错误码   |
| msg               | string  | 调用失败时，返回的错误信息 |
| requestId         | string  | 调用API时生成的请求标识   |
| success           | boolean | 接口是否调用成功  |
| data              | -       | 调用成功时，返回的业务数据 |
| data.request_time  | string  | 调用服务的时间 |
| data.function_name | string  | 功能名称 |
| data.identifier    | string  | 标识符 |
| data.type          | string  | 服务调用类型，0为同步，1为异步 |
| data.request_body  | string  | 服务调用时的请求参数 |
| data.response_time | string  | 返回时间 |
| data.response_body | string  | 输出参数，json string |
| data.code          | string  | 执行结果code，200：执行成功，0：未执行，其他：执行异常 |
| data.msg           | string  | 返回消息 |

#### 示例

##### 请求示例

```
GET /application?action=QueryServiceRecord&version=1&project_id=ocgzVU&trace_id=b7be91a1306211eb99afa3eef70771ea
```

##### 响应示例

```
{
    "data": { 
        "request_time": "1606448611264",
        "function_name": "df",
        "identifier": "df",
        "type": 1,
        "request_body": "{\"id\":\"1\",\"version\":\"1.0\",\"params\":{\"identifier\":\"df\",\"input\":{\"fd\":1}}}",
        "response_time": "0",
        "response_body": "",
        "code": 0,
        "msg": ""
    } 
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
```
