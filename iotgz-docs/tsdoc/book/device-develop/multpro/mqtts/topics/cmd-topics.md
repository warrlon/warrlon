# Topic cluster of device commands

The MQTT Internet of Things suite supports applications sending ** unicast commands ** directly to devices through APIs. Devices can get messages and respond to messages through the device command topic cluster.

The device command interaction process is shown in the following figure:

![](/images/MQTTS/设备命令topic簇.png)

The device command topic cluster topic list is as follows:

<table>
<tr><th width="50%">系统topic</th><th>用途</th><th width="8%">QoS</th><th width="10%">可订阅</th><th width="10%">可发布</th></tr>
<tr><td>$sys/{pid}/{device-name}/cmd/request/{cmdid}</td><td>系统向设备下发命令</td><td>0</td><td>√</td><td></td></tr>
<tr><td>$sys/{pid}/{device-name}/cmd/response/{cmdid}</td><td>设备回复命令应答</td><td>0/1</td><td></td><td>√</td></tr>
<tr><td>$sys/{pid}/{device-name}/cmd/response/{cmdid}/accepted</td><td>系统回复"设备命令应答成功"</td><td>0</td><td>√</td><td></td></tr>
<tr><td>$sys/{pid}/{device-name}/cmd/response/{cmdid}/rejected</td><td>系统回复"设备命令应答失败"</td><td>0</td><td>√</td><td></td></tr>
</table>

- When an application calls to create device commands through the command API,** the device must be online**
- The device needs to subscribe to the system topic in advance to get the command message
- Devices can respond to device command results by publishing messages to system top
- After the device responds to the command, the platform sends a notification of the result of the command response. The device needs to subscribe to the system topic in advance to get the message.
- API return is ** synchronous return **, that is, when the device responds to a command, or when the response times out, the system returns the result of the API request, as shown in[command API details](/book/device-development/multpro/MQTTS/api/synccmds.md)

## Equipment command issuance

The application can create and issue commands through API, and the platform will publish the command message to the system topic: $sys/{pid}/{device-name}/cmd/**request**/{cmdid}. If the device subscribes to the topic, the command message can be obtained, and the user can customize the message content.

> Description:
>- cmdid is the unique identifier automatically created for this command by the platform
>- The content of command message is determined by negotiation between application and device. The platform stores the message in publish payload for ** data transmission **
>- Recommended devices subscribe to command request messages in a wildcard manner: for example, $sys/{pid}/{device-name}/ cmd/** request**/+

## Equipment command reply

When the device receives the command, it can respond to the result of the command by publishing a message to topic: $sys/{pid}/{device-name}/cmd/**response**/{cmdid}, and users can customize the content of the response data.

> Description:
>- cmdid is the only identification carried by the platform when the command is issued. When the device responds to a specific command, cmdid should be placed in the top path.
>- The content of the command response is determined by the application in consultation with the device, which needs to store the message in the publish payload for reporting.
>- In payload of reply message, the length of data must be ** less than 1k**


When the device command replies, it supports QoS1. If publish QoS = 1, the platform replies to publish ack.

## Command Respond Result Notification

The platform receives the reply, stores the reply data through cmdid, and processes the result notification through system top

>- When the command response succeeds, the system publishes ** empty message ** through topic $sys/{pid}/{device-name}/ cmd/response/{cmdid}/ accepted
>- Command ** Non-repeatable Response **, message of repeatable response will be returned by rejection through system topic $sys/{pid}/{device-name}/cmd/response/{cmdid}/rejected
>- Recommended devices subscribe to command response result messages by wildcard: e.g. $sys/{pid}/{device-name}/ cmd/response/+/+

## Answer Error Code

When the device makes a command response error, the platform publishes the error message through topic $sys/{pid}/{device-name}/cmd/response/{cmdid}/rejected.

The list of error codes is as follows:

| Error Code | Error Description | Remarks|
| :- | :- | :- | :- |
| 99 | maximum payload size exceeded | device response length exceeded limit (1k)|
| 100 | internal error | server internal error|
| 112 | CMD response timeout | The device responds to commands after a timeout|
| 113 | CMD id not found | No corresponding command ID was found (command ID error or command reply repeated)|

An example of an error message is as follows:

```json
{
    "err_code": 99,
    "err_msg":"maximum payload size exceeded"
}
```



## More help

-[Understand the device synchronization command API](/book/device-development/multpro/MQTTS/api/synccmds.md)
-[Learn how to use services in the Internet of Things suite through topic](/book/device-development/multpro/MQTTS/topics/introduction.md)
-[Learn how to use simulation tools to quickly experience access processes](/book/device-development/multpro/MQTTS/example/connect.md)