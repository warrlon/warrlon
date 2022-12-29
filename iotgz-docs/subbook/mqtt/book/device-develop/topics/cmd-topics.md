# 设备命令 topic 簇

MQTT物联网套件支持应用通过API直接向设备发送**单播命令**，设备可以通过设备命令 topic 簇获取消息并进行消息应答

设备命令交互流程见下图：

![](/images/MQTTS/设备命令topic簇.png)

设备命令 topic 簇 topic 列表如下：

<table>
<tr><th width="50%">系统topic</th><th>用途</th><th width="8%">QoS</th><th width="10%">可订阅</th><th width="10%">可发布</th></tr>
<tr><td>$sys/{pid}/{device-name}/cmd/request/{cmdid}</td><td>系统向设备下发命令</td><td>0</td><td>√</td><td></td></tr>
<tr><td>$sys/{pid}/{device-name}/cmd/response/{cmdid}</td><td>设备回复命令应答</td><td>0/1</td><td></td><td>√</td></tr>
<tr><td>$sys/{pid}/{device-name}/cmd/response/{cmdid}/accepted</td><td>系统回复"设备命令应答成功"</td><td>0</td><td>√</td><td></td></tr>
<tr><td>$sys/{pid}/{device-name}/cmd/response/{cmdid}/rejected</td><td>系统回复"设备命令应答失败"</td><td>0</td><td>√</td><td></td></tr>
</table>

- 当应用调用通过命令 API 创建设备命令时，**设备必须处于在线状态**
- 设备需提前订阅系统 topic 以获取该命令消息
- 设备可以通过发布消息至系统 topic 的方式，进行设备命令结果应答
- 设备进行命令应答之后，平台发送命令应答结果通知，设备需提前订阅系统 topic 以获取该消息
- API返回为**同步返回**，即，当设备进行命令应答之后，或者当应答超时后，系统返回API请求结果，见[命令API详情](/book/application-develop/list/synccmds.md)

## 设备命令下发

应用可通过 API 创建下发命令，平台会将该命令消息发布至系统 topic： $sys/{pid}/{device-name}/cmd/**request**/{cmdid}，若设备订阅了该 topic 则可获取该命令消息，用户可自定义消息内容

> 说明：
> - cmdid 为平台为该命令自动创建的唯一标识
> - 命令消息内容由应用与设备协商确定，平台将该消息存放于 publish payload 中进行**数据透传**
> - 推荐设备采用通配符方式进行命令请求消息订阅：如 $sys/{pid}/{device-name}/cmd/**request**/+

## 设备命令回复

设备接收该命令后，可通过发布消息至 topic：$sys/{pid}/{device-name}/cmd/**response**/{cmdid} 进行该命令结果的应答，用户可自定义应答数据内容

> 说明：
> - cmdid 为平台为命令下发时携带的唯一标识，设备应答某一条具体命令时，应将 cmdid 置于 topic 路径中
> - 命令应答内容由应用与设备协商确定，设备需将该消息存放于 publish payload 中进行上报
> - 应答报文 payload 中，数据长度必须 **小于1k**


设备命令回复时，支持 QoS1，若 publish QoS=1，则平台回复 publish ack

## 命令回复结果通知

平台接收该应答，会通过 cmdid 存储该应答数据，并通过系统 topic 进行处理结果通知

> - 命令应答成功时，系统通过topic $sys/{pid}/{device-name}/cmd/response/{cmdid}/accepted 发布**空消息**
> - 命令**不可重复应答**，重复应答的消息将会通过拒绝，通过系统 topic $sys/{pid}/{device-name}/cmd/response/{cmdid}/rejected 返回消息
> - 推荐设备采用通配符方式进行命令应答结果消息订阅：如：$sys/{pid}/{device-name}/cmd/response/+/+

## 应答错误码

当设备进行命令应答出错时，平台会通过 topic $sys/{pid}/{device-name}/cmd/response/{cmdid}/rejected 发布错误消息

其中，错误码列表如下：

|  错误码 | 错误说明 | 备注 |
| :- | :- | :- | :- |
| 99   | maximum payload size exceeded | 设备回复的命令响应长度超过限制（1k） |
| 100   | internal error                | 服务器内部错误             |
| 112   | cmd response timeout          | 设备在超时时间后回复命令   |
| 113   | cmd id not found              | 未找到对应的命令ID（命令ID错误或者命令重复应答） |

错误消息示例如下：

```json
{
    "err_code": 99,
    "err_msg":"maximum payload size exceeded"
}
```

## 更多帮助

[了解设备同步命令的最佳实例](/book/example/cmd.md)