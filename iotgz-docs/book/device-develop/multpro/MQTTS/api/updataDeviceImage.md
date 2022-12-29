# 更新设备镜像

## 请求语法
```
PUT /mqtt/v1/devices/{device_id}/image/properties
Authorization:xxxx
Content-Type:application/json

{
    "state":{
        "desired":{
            "color": "green"
        },
        "reported":{
            "color": "red"
        }
    }
}
```

### body说明

|参数名称 | 类型 | 说明|
|:- | :- | :- |
|state | object | 必须且仅携带该参数 |

**state说明**

|参数名称 | 类型 | 说明|
|:- | :- | :- |
|desired | object | 应用期望属性，与reported至少存在一项 |
|reported | object | 设备上报属性，与desired至少存在一项 |

## 返回语法

```json
{
    "request_id": "daa992aa-0080-47f4-810f-2aa5e3bb27fe",
    "code": "000000",
    "code_no": "onenet_common_success",
    "message": null,
    "data": {
        "state": {
            "desired": {
                "color": "green"
            },
            "reported": {
                "color": "red"
            }
        },
        "metadata": {
            "desired": {
                "color": {
                    "timestamp": 1565066884
                }
            },
            "reported": {
                "color": {
                    "timestamp": 1565066884
                }
            }
        },
        "version": 11,
        "timestamp": 1565066884
    }
}
```

> 其中：data 部分为设备镜像更新确认数据

## 更多帮助

[查看api返回错误码](/book/application-develop/errorCode.md)