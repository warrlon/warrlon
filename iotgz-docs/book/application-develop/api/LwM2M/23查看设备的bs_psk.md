查看设备的bs_psk
---

请求方式：**GET**

URL: http://api.heclouds.com/nbiot/device/psk?imei=865820034287669&did=86582



#### URL请求参数
参数名称 | 格式 | 说明
:- | :- | :- 
imei | string | URL中的请求参数，值为设备IMEI号
did | long | URL中的请求参数，值为设备ID

#### 说明
```text
1、请求参数中imei和did仅且只能选择其一
2、兼容历史NB设备，查看历史设备的PSK后端默认生成存库并返回
```



#### 返回参数

参数名称 | 格式 | 说明
:- | :- | :- 
errno | int | 调用错误码，为0表示调用成功
error | string | 错误描述，为"succ"表示调用成功
data | json | 接口调用成功之后返回的设备相关信息，见data描述表

##### data描述表

参数名称 | 格式 | 说明
:- | :- | :- 
psk | string | 设备连接引导机的psk，在NB协议开启DTLS加密功能时返回该字段，其他情况没有该字段


#### 返回示例

```json
{
"errno": 0,
"error":"succ",
"data":
{
"psk":"23ddafd3444"
    }
}
```

