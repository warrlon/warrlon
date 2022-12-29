# 设备命令

> 平台提供设备命令API，用于直接向设备下发单播指令  
> API为同步设计，即，当设备收到命令并进行应答时，API返回设备应答内容

## 请求语法
```
POST /v1/synccmds?device_id=524092364&timeout=30

<command-content>
```

#### URL参数说明
| 版本 | 类型 | 是否必须 | 说明|
|:- | :- | :- | :- |
|device_id | string |  是 | 设备ID |
|timeout | string |  是 | 同步API最长等待时间，取值范围 5-30， 单位秒 |


#### body说明

请求body部分为用户自定义命令数据内容


## 返回语法
```json
Content-type: application/json

{
    "errno": 0,
    "error": "success",
    "data": {
        "cmd_uuid": "f9115090-8ef1-4b0c-aaf4-0678754f575a",
        "cmd_resp": "dGhpcyUyMGlzJTIwY29tbWFuZC1yZXNwb25zZSUyMGNvbnRlbnQ="
    }
}
```

#### 返回参数说明
|参数名称 | 类型 | 说明|
|:- | :- | :- |
|errno | int | 错误码|
|error | string | 错误描述|
|cmd_uuid | string | 命令ID|
|cmd_resp | string | 设备应答内容，base64编码格式 |

#### 返回错误码

|错误码 | 错误描述 | 说明|
|:- | :- | :- |
|12 | device not found | 设备不存在|
|13 | device not online | 设备不在线|
|14 | cmd response timeout | 设备命令应答超时|

返回错误示例：
```json
{
    "errno": 14,
    "error": "cmd response timeout"
}
```
## 使用限制

- 命令请求body数据长度必须 **小于1k**
- 设备应答时 payload 长度必须 **小于1k**

## 更多帮助

- [了解命令topic簇的使用方式](//book/device-develop/topics/cmd-topics.md)
- [了解如何通过 topic 使用物联网套件中的服务](//book/device-develop/topics/introduce.md)
- [了解如何使用模拟工具快速体验接入过程](//book/example/cmd.md)
