# 查询设备命令

## 请求语法
```
GET /devices/{deviceName}/commands/{commandId}

```


## 返回语法
```
Content-type: application/json

{
    "isSuccessful": true,
    "errorCode": "enum-string",     //当isSuccessful=false时携带
    "data":{                        //当isSuccessful=true时携带
        "commandId": "string",
        "requestTime": 12312391274,
        "commandContent": "hex-string",
        "commandStatus": "enum-string"
        "commandResponse": "hex-string",
        "responseTime": 123123912726
    }
}

```

#### 返回参数说明
|参数名称 | 类型 | 说明|
|:- | :- | :- |
|commandId | string | 命令ID|
|requestTime | int | 命令请求时间 |
|commandContent | string | 命令内容（二进制数据的HEX编码）|
|commandStatus | string | 命令状态 |
|commandResponse | string | 设备应答内容 （二进制数据的HEX编码）|
|responseTime | int | 命令应答时间 |

#### 命令状态
|状态 | 含义 | 说明|
|:- | :- | :- |
|requested | 已经发送命令请求 | 异步 |
|responsed | 已经接收到命令响应 | 异步/同步 |
|responseOverTime | 响应超时 | 同步 |

