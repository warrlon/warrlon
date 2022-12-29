# 设备属性上报接口

#### 接口名称

> devicePropertyNotify

#### 请求方法

>POST

#### 请求参数

| 参数名称   | 类型   | 是否必选 | 描述   |
| :--------- | :----- | :------- | :----- |
| topic | string | 是       | $sys/{pid}/{device-name}/thing/property/post |
| protocol | string | 是       | 协议名称，包含MQTT,COAP,OTHER,HTTP|

#### 返回数据

| 参数名称          | 类型    | 描述                       |
| :---------------- | :------ | :------------------------- |
| errno              | int  | 调用失败时，返回的错误码序号   |
| error               | string  | 调用失败时，返回的错误码 |

#### 示例

##### 请求示例

```
POST /device/thing/property/post?topic=$sys/W6O8v7Ce7d/device1/thing/property/post&protocol=http
{
    "id":"123",
    "version":"1.0",
    "params":{
        "status":{"value":0,
                  "time":1619142962931
        },
         "gear":{"value":3,
                 "time":1619142962931
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
