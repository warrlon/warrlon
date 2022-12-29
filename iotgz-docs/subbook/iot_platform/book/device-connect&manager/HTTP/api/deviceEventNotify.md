# 设备事件上报接口

#### 接口名称

> deviceEventNotify

#### 请求方法

> POST

#### 请求参数

| 参数名称   | 类型   | 是否必选 | 描述   |
| :--------- | :----- | :------- | :----- |
| topic | string | 是       | $sys/{pid}/{device-name}/thing/event/post |
| protocol | string | 是       | 协议名称，包含MQTT,COAP,OTHER,HTTP|

#### 返回数据

| 参数名称          | 类型    | 描述                       |
| :---------------- | :------ | :------------------------- |
| errno              | int  | 调用失败时，返回的错误码序号   |
| error               | string  | 调用失败时，返回的错误码 |

#### 示例

##### 请求示例

```
POST /device/thing/event/post?topic=$sys/W6O8v7Ce7d/device1/thing/event/post&protocol=http
{
    "id":"123",
    "version":"1.0",
    "params":{
        "RolloverEvent":{
            "time":1619161479300,
            "value":{
                "RolloverAccP":99,
                "RolloverAccE":99
             }
        }
    }
}
```


##### 响应示例

```
{
    "errno": 0,
    "error": "succ"
}
```
