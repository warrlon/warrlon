# Equipment command

> Platform provides device command API for sending unicast instructions directly to devices
> The API is designed for synchronization, that is, when the device receives a command and responds, the API returns the device response content.

## Request grammar

```
POST /v1/synccmds?device_id=524092364&timeout=30

<command-content>
```

#### Description of URL parameters
| Version | Type | Must | Explain|
|:- | :- | :- | :- |
| device_id | string | is | device ID|
| timeout | string | is the longest waiting time for the | synchronous API, ranging from 5 to 30, per second|


#### Body description

Request body part to customize command data content for users


## Return grammar

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

#### Return parameter description
| parameter name | type | description|
|:- | :- | :- |
| errno | int | error code|
| error | string | error description|
| cmd_uuid | string | command ID|
| cmd_resp | string | device response content, Base64 encoding format|

#### Return error code

| Error Code | Error Description | Description|
|:- | :- | :- |
| 12 | device not found | device does not exist|
| 13 | device not online | device not online|
| 14 | CMD response timeout | device command response timeout|

Returns an error example:
```json
{
    "errno": 14,
    "error": "cmd response timeout"
}
```
## Use restrictions

- The command request body data length must be ** less than 1k**
- The payload length must be ** less than 1k** when the equipment responds.

## More help

-[Understanding how the command topic cluster is used](/book/device-development/multpro/MQTTS/topics/cmd-topics.md)
-[Learn how to use services in the Internet of Things suite through topic](/book/device-development/multpro/MQTTS/topics/introduction.md)
-[Learn how to use simulation tools to quickly experience access processes](/book/device-development/multpro/MQTTS/example/connect.md)