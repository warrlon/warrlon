# 注册设备

> 为用户提供设备注册的方法，当 **设备名称** 已存在时，接口返回当前设备信息

## 请求语法
```
POST /mqtt/v1/devices/reg
Authorization:xxxx
Content-Type:application/json

{
    "name":"IMEI12345678901",
    "desc":"some description",
    "key":"5h2QzmpEqD7IqaOYNoj2kuNNm1Q="
}
```

### body说明

<table>
<tr><th width="20%">参数名称</th><th width="15%">类型</th><th width="15%">是否必填</th><th>说明</th></tr>
<tr><td>name</td><td>string</td><td>是</td><td>设备名称，产品下唯一标识，建议使用设备SN、IMEI、MAC作为设备名称，仅支持英文、数字、"_"、"-"，长度1-64</td></tr>
<tr><td>desc</td><td>string</td><td>否</td><td>设备描述，长度0-100</td></tr>
<tr><td>key</td><td>string</td><td>否</td><td>必须为base64编码格式，原始码长度不得超过32字节<br>缺省情况下，平台自动分配设备key</td></tr>
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
|key | string | 设备秘钥 |



## 更多帮助

[查看api返回错误码](/book/application-develop/errorCode.md)