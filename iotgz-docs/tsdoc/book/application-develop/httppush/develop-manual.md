# Development Guidelines

In the use of push services, OneNET serves as the client while the third-party application of users serves as the server. Third-party applications need to support ** URL authentication ** and ** data reception ** services.


## URL validation

The URL validation process is shown in the following figure:

![url validation process](/images/url验证.png)

When the user completes the configuration page and clicks "Submit", OneNET platform sends HTTP ** GET ** request to fill in the URL address for URL verification. Examples of the request form are as follows:

```
http://url?msg=xxx&nonce=xxx&signature=xxx
```

Where * URL * is the URL that the user fills in when configuring the page, and * nonce *, * MSG *, * signature * is used to validate the URL and token.

The token verification process is as follows:

1. Calculate MD5 with the values of * token * and * nonce *, * MSG * configured in the configuration page and encode them as Base64 string values

2. Compare the value of Base64 string value calculated by URL Decode in the previous step with the value of request parameter * signature * if equal, token validation is successful.

If token validation succeeds, the * MSG * parameter value is returned to indicate that the URL validation is successful.

    If the user does not want to verify token, he can choose to skip the MD5 calculation process and return the MSG parameter value directly.


## Data reception

The platform pushes data to the third-party platform URL address in the form of HTTP POST request. The third-party platform needs to return HTTP 200 after receiving the data, otherwise OneNET will consider the push invalid and try again.

Push data-related information in the body part of an HTTP request in the form of a JSON string, where each field has the following meaning

<table>
<tr><th width="15%">字段</th><th width="10%">类型</th><th>字段说明</th></tr>
<tr><td>type</td><td>int</td><td>标识消息类型<br> 1：设备上传数据点消息<br>2：设备上下线消息 <br>7：缓存命令下发后结果上报（仅支持NB设备）</td></tr>
<tr><td>dev_id</td><td>int</td><td>设备ID</td></tr>
<tr><td>ds_id</td><td>string</td><td>数据流名称</td></tr>
<tr><td>at</td><td>int</td><td>平台时间戳,单位ms</td></tr>
<tr><td>value</td><td> </td><td>具体数据部分，为设备上传至平台或触发的相关数据</td></tr>
<tr><td>status</td><td>int</td><td>设备上下线标识<br>0：设备下线<br>1：设备上线</td></tr>
<tr><td>login_type</td><td>int</td><td>设备登录协议类型<br>1-EDP, 6-MODBUS, 7-MQTT, 10-NB-IoT</td></tr>
<tr><td>cmd_type</td><td>int</td><td>命令响应的类型<br>1：设备收到cmd的ACK响应信息<br>2：设备收到cmd的Confirm响应信息</td></tr>
<tr><td>cmd_id</td><td>string</td><td>命令ID</td></tr>
<tr><td>msg_signature</td><td>string</td><td>消息摘要</td></tr>
<tr><td>nonce</td><td>string</td><td>用于计算消息摘要的随机串</td></tr>
<tr><td>enc_msg</td><td>string</td><td>加密密文消息体,对明文JSON串（msg字段）的加密</td></tr>
</table>


Example 1: Data Point Messages
```json
{
    "msg": {
        "type": 1,
        "dev_id": 2016617,
        "ds_id": "datastream_id",
        "at": 1466133706841,
        "value": 42
    },
    "msg_signature": "message signature",
    "nonce": "abcdefgh"
}
```

Example 2: Batch data point messages (data caching needs to be configured)
```json
{
    "msg": [{
            "type": 1,
            "dev_id": 2016617,
            "ds_id": "datastream_id",
            "at": 1466133706841,
            "value": 42
        },
        {
            "type": 1,
            "dev_id": 2016617,
            "ds_id": "datastream_id",
            "at": 1466133706842,
            "value": 43
        },
        ...
    ],
    "msg_signature": "message signature ",
    "nonce": "abcdefgh"
}
```

Example 3: Device offline message
```json
{
    "msg": {
        "type": 2,
        "dev_id": 2016617,
        "status": 0,
        "login_type": 1,
        "at": 1466133706841
    },
    "msg_signature": "message signature",
    "nonce": "abcdefgh"
}
```

Example 4: Cache command post-issuance result reporting (NB device only supported)
```json
{
    "msg": {
        "type": 7,
        "cmd_id": "3a351323-c4fe-5f21-9e9e-a9adc321182f",
        "imei": "865820060031939",
        "dev_id": 2016690,
        "cmd_type": 0,
        "send_time": 1466133706841,
        "send_status": 5,
        "confirm_time": 146613371921,
        "confirm_status": 0,
        "confirm_body": {
            "obj_id": 3,
            "obj_inst": [{
                "obj_inst_id": 0,
                "res": [{
                        "res_inst": [{
                            "val": 0,
                            "res_inst_id": 0
                        }],
                        "res_id": 11
                    },
                    {
                        "val": 1530496927000,
                        "res_id": 13
                    }
                ]
            }]
        }
    },
    "msg_signature": "message signature",
    "nonce": "abcdefgh"
}
```

Explain:

1. When the response result contains binary data, the array that converts binary data byte [] into ASCII code exists in JSON data, such as: [98, 105, 110, 97, 114, 121]
2. When the command type is READ, the confirm_body field carries the object ID and object instance ID when the command request is made, which facilitates the user to parse the data.

## Encrypted transmission
Users can configure data encryption transmission when configuring push service. OneNET supports AES symmetrical encryption. Users can configure keys through pages and decrypt operations through the keys on the application side.

Example: Ciphertext format
```json
{
    "enc_msg": "XXXXXXXXXXX",
    "msg_signature": "message signature",
    "nonce": "abcdefgh"
}
```



## Suggestions on Service Realization

- OneNET platform in order to ensure that data is not lost, there is a mechanism for retransmitting. If duplicate data has an impact on business, the data receiver needs to eliminate duplicate processing of duplicate data.
- After every POST data request in OneNET, there is a time limit for waiting for the client's response (currently 5 seconds). If the response is not received within the specified time limit, the sending failure will be considered. If the total failure is 2000 times, the third party service will be considered unavailable and the service will stop. Therefore, it is suggested that when the third party application receives the data, ** first do data caching, then do business logic processing **
- To ensure that you can experience continuous and stable services when using OneNET platform data push service, Please add the following export IP address of OneNET platform data push to your application's ** IP whitelist **.

|||||||
|:- | :- | :- | :-|:-|:-|
|183.230.102.83 | 183.230.102.84 |183.230.102.85  | 183.230.102.86 |183.230.40.120|183.230.40.121|
|218.201.45.1|218.201.45.2|218.201.45.3|218.201.45.4|218.201.45.5|218.201.45.6|