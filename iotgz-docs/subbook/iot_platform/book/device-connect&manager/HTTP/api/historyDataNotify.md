# 历史数据上报接口

#### 接口名称

> historyDataNotify

#### 请求方法

> POST

#### 请求参数

| 参数名称   | 类型   | 是否必选 | 描述   |
| :--------- | :----- | :------- | :----- |
| topic | string | 是       | $sys/{pid}/{device-name}/thing/history/post |
| protocol | string | 是       | 协议名称，包含MQTT,COAP,OTHER,HTTP|

#### 返回数据

| 参数名称          | 类型    | 描述                       |
| :---------------- | :------ | :------------------------- |
| code              | string  | 调用失败时，返回的错误码   |
| msg               | string  | 调用失败时，返回的错误信息 |
| requestId         | string  | 调用API时生成的请求标识   |
| success           | boolean | 接口是否调用成功  |
| data              | -       | 调用成功时，返回的业务数据 |

#### 示例

##### 请求示例

```
POST /device/thing/history/post?topic=$sys/W6O8v7Ce7d/device1/thing/history/post&protocol=http
{
    "id":"123",
    "version":"1.0",
    "params":[{
           "properties":{
                "status":[{
                    "value":1,
                    "time":1619332210357
                }],
                "gear":[{
                    "value":1,
                    "time":1619332210357
                }]
            },
            "events":{
                "RolloverEvent":[{
                    "value":{
                        "RolloverAccP":31,
                        "RolloverAccE":32
                     },
                    "time":1619332210357
                }]
            }
    }]
}
```


##### 响应示例

```
{
    "errno": 0,
    "error": "succ"
}
```
