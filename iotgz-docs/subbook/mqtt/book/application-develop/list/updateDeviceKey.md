# 更新设备key

> 为用户提供设备key的更新与自定义的方法

## 请求语法
```
PUT /mqtt/v1/devices/{device_id}/key?force_offline=true
Authorization:xxxx
Content-Type:application/json

{
    "key":"5h2QzmpEqD7IqaOYNoj2kuNNm1Q="
}

```

### url参数说明

<table>
<tr><th width="20%">参数名称</th><th width="15%">类型</th><th width="15%">是否必填</th><th>说明</th></tr>
<tr><td>force_offline</td><td>bool</td><td>否</td><td>是否强制设备离线，默认为true，即携带该参数时，更新成功则设备离线</td></tr>
</table>

### body说明

<table>
<tr><th width="20%">参数名称</th><th width="15%">类型</th><th width="15%">是否必填</th><th>说明</th></tr>
<tr><td>key</td><td>string</td><td>否</td><td>必须为base64编码格式，原始码长度不得超过32字节<br>缺省情况下，平台自动分配新的key</td></tr>
</table>

## 返回语法
```json
{
    "request_id":"855b2fe4-3f54-41f2-8cd5-3e34bcfa8356",
    "code_no":"000000",
    "code":"onenet_common_success",
    "message":null,
    "data":{
        "device_id":"12345",
        "name":"IMEI12345678901",
        "pid":1234,
        "key":"5h2QzmpEqD7IqaOYNoj2kuNNm1Q="
    }
}
```

### data参数说明
|参数名称 | 类型 | 说明|
|:- | :- | :- |
|device_id | string | 设备ID|
|name | string | 设备名称|
|pid | int | 产品ID|
|key | string | 设备新秘钥 |



## 更多帮助

[查看api返回错误码](/book/application-develop/errorCode.md)