缓存命令-取消设备所有待下发命令
---

请求方式：**PUT**

http(s)://api.heclouds.com/nbiot/offline/cancel/all

[我只想看示例！！！](#1)

#### url参数
| 参数名称 | 格式   | 是否必须 | 说明              |
| :------- | :----- | :------- | :---------------- |
| imei     | string | 是       | nbiot设备的身份码 |

#### 返回参数
| 参数名称 | 格式   | 说明                                             |
| :------- | :----- | :----------------------------------------------- |
| errno    | int    | 调用错误码，为0表示调用成功                      |
| error    | string | 错误描述，为"succ"表示调用成功                   |
| data     | json   | 接口调用成功之后返回的设备相关信息，见data描述表 |

##### data描述表
| 参数名称 | 格式   | 说明         |
| :------- | :----- | :----------- |
| succ     | array-json | 取消成功的uuid列表 |
| failed     | array-json |取消失败的uuid列表 |
| total     | int | 待下发的缓存命令总数 |

##### 说明
```text
只包含waiting状态的命令
```

<h4 id="1">请求示例</h2>

```text
PUT http://api.heclouds.com/nbiot/offline/cancel/all?imei=86076504******* HTTP/1.1

api-key: WhI*************v1c= //必须为 MasterKey， 由于涉及个人隐私， 这里用“*******” 代替;
```
#### 返回示例
```java
{
    "errno": 0,
    "error": "succ",
    "data": {
        "succ": [
            "cd050408-fe36-5f90-****-e831df8bc374",
			"3e62d080-2571-5456-****-5ff14bde5b25"
        ],
        "failed": [],
        "total": 2
    }
}
```