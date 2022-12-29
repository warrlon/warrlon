# 查询设备

> 为用户提供设备查询的方法，当**设备名称**不存在，返回错误；

## 请求语法

```http
GET /mqtt/v1/devices/{device_name}
Authorization:xxxx
```

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
        "key":"5h2QzmpEqD7IqaOYNoj2kuNNm1Q=",
        "desc":"some description"
    }
}
```

### data参数说明

| 参数名称  | 类型   | 说明     |
| :-------- | :----- | :------- |
| device_id | string | 设备ID   |
| name      | string | 设备名称 |
| pid       | int    | 产品ID   |
| key       | string | 设备秘钥 |
| desc      | string | 设备描述 |

## 更多帮助

[查看api返回错误码](/book/application-develop/errorCode.md)
