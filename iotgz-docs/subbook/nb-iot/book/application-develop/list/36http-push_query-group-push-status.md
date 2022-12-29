HTTP推送-查询群组推送状态
---

请求方式：**GET**

http(s)://api.heclouds.com/msg_group/{msg_group_id}/status

说明：msg_group_id群组ID

[我只想看示例！！！](#1)

#### 返回参数
| 参数名称 | 格式   | 说明                                             |
| :------- | :----- | :----------------------------------------------- |
| errno    | int    | 调用错误码，为0表示调用成功                      |
| error    | string | 错误描述，为"succ"表示调用成功                   |
| data     | json   | 接口调用成功之后返回的状态信息，见data描述表 |

##### data描述表
| 参数名称 | 格式   | 说明         |
| :------- | :----- | :----------- |
| status     | boolean | true-开启/false-关闭 |


<h4 id="1">请求示例</h2>

```text
GET http://api.heclouds.com/msg_group/1111/status HTTP/1.1

api-key: WhI*************v1c= //必须为 MasterKey， 由于涉及个人隐私， 这里用“*******” 代替;
```
#### 返回示例
```java
{
    "errno": 0,
    "error": "succ",
    "data": {
        "status": true
       
    }
}
```