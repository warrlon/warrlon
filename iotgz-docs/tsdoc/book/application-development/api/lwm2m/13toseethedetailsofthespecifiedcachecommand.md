See the details of the specified cache command
---
Request mode: ** GET**

URL: http://api.heclouds.com/nbiot/offline/history/uuid

    Uuid: Cache command ID

#### URL parameter
Parameter Name | Format | Whether Must | Explain
:- | :- | :- | :- 
IMEI | string | is the identity code of | nbiot device

#### Return parameters
Parameter name | format | description
:- | :- | :- 
Error no | int | Calls the error code, which is 0 to indicate that the call was successful
Error | string | Error description, which indicates that the call succeeded for "succ"
Data | JSON | interface call success after the return of caching commands related information, see the data description table

##### data description table
Parameter name | format | description
:- | :- | :- 
Type | string | command type
Args | JSON | type interface HTTP parameters
Content | JSON | type interface HTTP content
Create_time | string | command creation time
Valid_time | string | command effective time
Expired_time | string | command expiration time
Send_time | string | command delivery time
The type of upstream message triggered by trigger_msg | int | command, ranging from 1 to 7 valid
Send_status | int | down status
Confirm_time | string | response time
Confirm_status | string | response state
JSON result successfully returned by cmd_result | JSON | type type interface
Details of feedback_msg | array | data push may be multiple
Identity code for IMEI | string | nbiot device
Remaining | int | Number of Remaining Retries

##### Description
> send_status status status:
    1. Order Waiting (wait)
    2. Cancle
    3. The command has been sent to the device.
    4. Order expired
    5. Command success
    6. Failed command issuance
    7. Other Unknown Errors

> confirm_status status status description:
    0. SUCCESS (successful command execution)
    1. METHOD_NOT_ALLOWED (object or resource does not allow this operation)
    2. FORBIDDEN (Terminal not registered)
    3. NOT_FOUND (No object or resource found)
    4. INTERNAL_SERVER_ERROR (device response code error, etc.)
    5. TIME_OUT (device response timeout)
    6. REQ_PARAM_ERROR (request parameter error)
    7. RESP_ERROR (device response message error)
    8. UNAUTHORIZED (Access permissions are not allowed)
    9. BAD_REQUEST (request format error, such as fewer parameters or encoding, etc.)
    10. NOT_ACCEPTABLE (no preferred message format can be returned)
    11. UNSUPPORTED_CONTENT_FORMAT (specified message format is not supported)


#### Examples of requests

```text
GET http://api.heclouds.com/nbiot/offline/history/10018?imei=86582003*** HTTP/1.1
api-key: WhI*************v1c=
Host: api.heclouds.com

```

#### Return an example

```json
{
"errno": 0,
"error": "succ"
"data":
{
"type":"READ",
"args": {
      // type类型接口http参数
}
"content": {
// type类型接口http内容
},
"create_time":"2017-08-28 11:34:58",
"valid_time":"2017-08-28 11:34:58",
"expired_time":"2017-08-28 11:34:58",
"send_time":"2017-08-28 11:34:58",
"trigger_msg": 1,
// 命令下发成功
"send_status": 5,
"confirm_time": "2017-08-28 11:34:58",
// 命令响应结果，如果不是success，则没有cmd_result
"confirm_status": "SUCCESS",
//响应内容
"cmd_result": {
           // type类型接口成功返回的json结果
} 
"feedback_msg": [//数据推送详情
            {
                "feedback_time": "2019-02-28 13:50:43",
                "feedback_status": 0
            },
            {
                "feedback_time": "2019-02-28 13:50:43",
                "feedback_status": 0
            }
        ]
"imei":"869975031234561"
"remain":"3"//剩余重试次数

}
}
```