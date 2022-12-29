View the list of cache commands for the specified device
---
Request mode: ** GET**

URL: http://api.heclouds.com/nbiot/offline/history


#### URL parameter
Parameter Name | Format | Whether Must | Explain
:- | :- | :- | :- 
IMEI | string | is the identity code of | nbiot device
ID of UUID | string | no | command
Start | string | is | specifies the start time
End | string | no | specify the end time
Page | int | no | current page number
Per_page | int | No | Number of bars per page
Sort | string | no | time sort (ASC/DESC), default DESC

#### Return parameters
Parameter name | format | description
:- | :- | :- 
Error no | int | Calls the error code, which is 0 to indicate that the call was successful
Error | string | Error description, which indicates that the call succeeded for "succ"
Data | JSON | Information returned after successful interface invocation is shown in the data description table


##### data description table
Parameter name | format | description
:- | :- | :- 
Tot_count | int | Number of caching commands
JSON array of items | array-json | caching commands, see item description table

##### item description table
Parameter name | format | description
:- | :- | :- 
Cmd_uuid | string | cache command ID
Type | string | command type
Create_time | string | command creation time
Valid_time | string | command effective time
Expired_time | string | command expiration time
Send_time | string | command delivery time
The type of upstream message triggered by trigger_msg | int | command, ranging from 1 to 7 valid
Send_status | int | down status
Confirm_time | string | response time
Confirm_status | string | response state
Feedback_time | string | Feedback time
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

> confirm_status status status:
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

> trigger_msg trigger type:
    1. REGISTER
    2. UPDATE
    3. REGISTER | UPDATE combination
    4. NOTIFY
    5. REGUSTER | NOTIFY combination
    6. UPDATE | NOTIFY combination
    7. NOTIFY | UPDATE | REGISTE combination


#### Examples of requests

```text
GET http://api.heclouds.com/nbiot/offline/history?imei=86582003***&start=2016-08-05T08:00:00&end=2016-08-06T08:00:00&page=2&per_page=10 HTTP/1.1
api-key: WhI*************v1c=
Host: api.heclouds.com
Content-Length: 196

```

#### Return an example

```json
{
"errno": 0,
"error": "succ"
"data":
{
"total_count": 100,
"items":
[
{
"cmd_uuid":"f6869ecb-3dc1-5374-9be0-4fb961f8af3c ",
"type":"READ", 
"create_time":"2017-08-28 11:34:58",
"valid_time":"2017-08-28 11:34:58",
"expired_time":"2017-08-28 11:34:58",
"send_time":"2017-08-28 11:34:58",
"trigger_msg": 1,
// 命令下发成功
"send_status": 5,
"confirm_time": "2017-08-28 11:34:58",
"confirm_status": "SUCCESS"
"feedback_time": "2019-02-28 13:50:43"
"imei":"869975031234561"
"remain":"3"//剩余重试次数
{…}
]
}
}

```