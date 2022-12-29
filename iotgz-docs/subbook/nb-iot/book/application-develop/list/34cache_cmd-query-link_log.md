缓存命令-全链路日志查询
---

请求方式：**GET**

http(s)://api.heclouds.com/nbiot/offline/history/{uuid}/piecewise

说明：uuid为缓存命令ID

[我只想看示例！！！](#1)

#### url参数
| 参数名称 | 格式   | 是否必须 | 说明              |
| :------- | :----- | :------- | :---------------- |
| imei     | string | 是       | nbiot设备的身份码 |

#### 返回参数
| 参数名称 | 格式       | 说明                                             |
| :------- | :--------- | :----------------------------------------------- |
| errno    | int        | 调用错误码，为0表示调用成功                      |
| error    | string     | 错误描述，为"succ"表示调用成功                   |
| data     | array-json | 接口调用成功之后返回的设备相关信息，见data描述表 |

##### data描述表
| 参数名称 | 格式       | 说明                 |
| :------- | :--------- | :------------------- |
| log      | String | 各个时间点相关日志   |
| time     | String | 日志对应的时间字符串 |

##### 说明
```text
1、received command，平台接收

2、send command，下发

3、received confirm message，设备响应

4、feedback message，推送反馈
```
##### 参数说明：

| **参数名**     | **描述**                             |
| -------------- | ------------------------------------ |
| imei           | nb设备imei号                         |
| type           | 命令类型0：READ，1:WRITE，2：EXECUTE |
| args           | type类型接口http参数                 |
| content        | type类型接口http内容                 |
| retry          | 命令下发失败重试次数                 |
| remain         | 命令下发失败后剩余重试次数           |
| trigger        | 命令触发的上行消息类型，范围为1~7    |
| send_status    | 命令状态5：命令下发成功（success）   |
| confirm_status | 响应状态：0：SUCCESS（命令成功执行） |
| result         | 平台返回内容                         |

<h4 id="1">请求示例</h2>

```text
GET http://api.heclouds.com/nbiot/offline/history/bb824a24-*****b45d-a9b66cd2104e/piecewise?imei=8607650***** HTTP/1.1

api-key: WhI*************v1c= //必须为 MasterKey， 由于涉及个人隐私， 这里用“*******” 代替;
```
#### 返回示例
```java
	
{
    "errno": 0,
    "error": "succ",
    "data": [
        {
            "log": "received command type: [2], args: [{\"obj_id\":5,\"obj_inst_id\":0,\"res_id\":26600,\"imei\":\"00000***05\",\"expired_time\":\"2021-01-02 09:02:24:185\",\"valid_time\":\"2020-12-02 09:02:24:185\",\"retry\":3,\"timeout\":25}], content: []",
            "time": "Wed Dec 02 09:02:24 CST 2020"
        },
        {
            "log": "send command type: [2], args: [{\"obj_id\":5,\"obj_inst_id\":0,\"res_id\":26600,\"imei\":\"00000***05\",\"expired_time\":\"2021-01-02 09:02:24:185\",\"valid_time\":\"2020-12-02 09:02:24:185\",\"retry\":3,\"timeout\":25}], content: []",
            "time": "Wed Dec 02 09:02:33 CST 2020"
        },
        {
            "log": "received confirm message, type: [2], command send status: [5], confirm status: [0], result: [{\"errno\":0,\"error\":\"success\"}]",
            "time": "Wed Dec 02 09:02:33 CST 2020"
        }
    ]
}
```