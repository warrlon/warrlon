# 查询设备镜像

graffiti    涂鸦

feature     特征  

tags        标签

## 请求语法
```
GET /devices/{deviceName}/mirror

```


## 返回语法
```
Content-type: application/json

{
    "isSuccessful": true,
    "errorCode": "enum-string",     //当isSuccessful=false时携带
    "data":{                        //当isSuccessful=true时携带
        "deviceName": "mydevice"
        "deviceId": "1234321",
        "createTime ": 1469564492, 
        "status": "enabled",
        "statusReason": "provisioned",
        "statusUpdateTime": 1469564492,
        "connectionState": "online",
        "lastActivityTime": 1469564492,

        "graffiti": {
            "deploymentLocation": {
                "building": "43",
                "floor": "1"
            }
        },

        "properties": {
            "state": {
                "desired": {
                    "lights": {
                        "color": "RED"
                    },
                    "engine": "ON"
                },
                "reported": {
                    "lights": {
                        "color": "GREEN"
                    },
                    "engine": "ON"
                },
            },
            "metadata": {
                "desired": {
                    "lights": {
                        "color": {
                            "timestamp": 1469564492,
                        },
                    }
                    "engine": {
                        "timestamp": 1469564492,
                    }
                },
                "reported": {
                    "lights": {
                        "color": {
                            "timestamp": 1469564492,
                        }
                    },
                    "engine": {
                        "timestamp": 1469564492,
                    }
                },
            },
            "version": 10,
            "timestamp": 1469564492,
        }
    }
}


```