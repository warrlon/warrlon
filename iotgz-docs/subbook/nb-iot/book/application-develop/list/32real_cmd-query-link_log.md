即时命令-全链路日志查询
---

请求方式：**GET**

http(s)://api.heclouds.com/nbiot/open/online/history/{uuid}/piecewise

说明：uuid为即时命令ID

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
| 参数名称 | 格式   | 说明                 |
| :------- | :----- | :------------------- |
| log      | String | 各个时间点相关日志   |
| time     | String | 日志对应的时间字符串 |

##### 说明
```text
1、received command，平台接收

2、send command，下发

3、received confirm message，设备响应

4、feedback message，反馈（即时命令为设备响应）
```
##### 参数说明：

| **参数名**     | **描述**                                           |
| -------------- | -------------------------------------------------- |
| imei           | nb设备imei号                                       |
| type           | 命令类型0：READ，1:WRITE：，2：EXECUTE，3：OBSERVE |
| args           | type类型接口http参数                               |
| content        | type类型接口http内容                               |
| confirm_status | 响应状态：0：SUCCESS（命令成功执行）               |
| result         | 平台返回内容                                       |

<h4 id="1">请求示例</h2>

```text
GET http://api.heclouds.com/nbiot/open/online/history/31688926-*****9a9c-32b1541b0b62/piecewise?imei=86076504****** HTTP/1.1

api-key: WhI*************v1c= //必须为 MasterKey， 由于涉及个人隐私， 这里用“*******” 代替;
```
#### 返回示例
```java
{
	"errno": 0,
	"error": "succ",
	"data": [{
			"log": "received command type: [0], args: [], content: []",
			"time": "Wed Feb 27 14:31:22 CST 2019"
		},
		{
			"log": "send command type: [0], args: [], content: []",
			"time": "Wed Feb 27 14:31:22 CST 2019"
		},
		{
			"log": "received confirm message, type: [0], command send status: [1], confirm status: [0]",
			"time": "Wed Feb 27 14:31:22 CST 2019"
		},
		[{
			"log": "feedback message, type: [0], confirm status: [0], result: []",
			"time": "Wed Feb 27 14:31:22 CST 2019"
		}]
	]
}
```