# 创建设备命令

## 请求语法
```
POST /devices/{deviceName}/commands
Content-type: application/json

{
    "commandContent": "hex-string"
}
```

#### query参数说明
| 版本 | 类型 | 是否必须 | 说明|
|:- | :- | :- | :- |
|synchronize | string |  是 | 若设置为true，则为同步调用方式，必须设置timeout<br>在设备进行命令应答或者应答超时之后，API返回结果 |
|timeout | string |  否 | 当synchronize设置为true时生效，同步API最长等待时间（1-10 单位秒） |


#### body参数说明
|参数名称 | 类型 | 是否必须 | 说明 |
|:- | :- | :- | :- |
|commandContent | string | 是 | 命令内容（二进制数据的HEX编码）|


## 返回语法（异步）
```
Content-type: application/json

{
    "isSuccessful": true,
    "errorCode": "enum-string",     //当isSuccessful=false时携带
    "data":{                        //当isSuccessful=true时携带
        "commandId": "string",
    }
}

```

## 返回语法（同步）
```
Content-type: application/json

{
    "isSuccessful": true,
    "errorCode": "enum-string",     //当isSuccessful=false时携带
    "data":{                        //当isSuccessful=true时携带
        "commandId": "string",
        "commandResponse": "hex-string",    //当synchronize=true时，且设备成功应答时携带
    }
}

```

#### 返回参数说明
|参数名称 | 类型 | 说明|
|:- | :- | :- |
|commandId | string | 命令ID|
|commandResponse | string | 设备响应结果 |
