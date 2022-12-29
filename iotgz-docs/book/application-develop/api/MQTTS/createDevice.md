# 创建设备

## 请求语法
```
POST /devices
Content-type: application/json

{
    "name": "my_device",
    "desc": "string",
}
```
#### query参数说明
| 版本 | 类型 | 是否必须 | 说明|
|:- | :- | :- | :- |
|apiVersion | string | 是 | 当前API版本号，目前仅支持2019-03-04 |


#### body参数说明
|参数名称 | 类型 | 是否必须 | 说明|
|:- | :- | :- | :- |
|name | string | 是 | 设备名称（长度1-64，支持英文、数字、- 与 _ ）|
|desc | string | 否 | 设备描述|



## 返回语法
```
Content-type: application/json

{
    "isSuccessful": true,
    "errorCode": "enum-string",     //当isSuccessful=false时返回
    "data":{                        //当isSuccessful=true时返回
        "name": "string",
        "deviceId": "string",
        "key": "string"
    }
}
```

#### 返回参数说明
|参数名称 | 类型 | 说明|
|:- | :- | :- |
|name | string | 设备名称|
|deviceId | string | 设备ID |
|key | string | 设备key，用于设备接入 |

