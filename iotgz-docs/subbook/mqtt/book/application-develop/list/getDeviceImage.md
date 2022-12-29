# 查询设备镜像

> 用于查询某个设备的设备镜像json文档

## 请求语法
```
GET /mqtt/v1/devices/{device_id}/image
Authorization:xxxx

```


## 返回语法

```json
{
    "request_id": "b0a25c65-0299-4260-a849-5861adf07fd5",
    "code": "000000",
    "code_no": "onenet_common_success",
    "message": null,
    "data": {
        "deviceId": "536444692",
        "createTime": 1563929740,
        "status": "enabled",
        "statusReason": "created",
        "statusUpdateTime": 0,
        "connectionState": "offline",
        "lastActivityTime": 0,
        "tags": {},
        "properties": {
            "state": {
                "reported": {
                    "color": "red"
                },
                "desired": {
                    "color": "green"
                },
                "delta": {
                    "color": "green"
                }
            },
            "metadata": {
                "reported": {
                    "color": {
                        "timestamp": 1564685309
                    }
                },
                "desired": {
                    "color": {
                        "timestamp": 1564685309
                    }
                }
            },
            "version": 9,
            "timestamp": 1565007250
        }
    }
}
```
> 其中：data部分为设备镜像json数据


## 更多帮助

[查看api返回错误码](/book/application-develop/errorCode.md)