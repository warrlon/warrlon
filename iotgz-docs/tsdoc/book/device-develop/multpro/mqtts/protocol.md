# MQTT Protocol Specification

## Protocol Version

The platform supports the standard MQTT ** version 3.1.1 ** and refers to the protocol description for details (http://mqtt.org/?Spm=a2c4g.11186623.2.11.19083f86gxhJ7h)

## Protocol Implementation

#### Message support

- Platform supports connect, subscribe, publish, ping, unsubscribe, disconnect and other messages
- No support for pubrec, pubrel, pubcomp messages


#### Feature support

The platform supports the protocol features as follows:
<table>
<tr><th width="20%">特性</th><th width="20%">是否支持</th><th>说明</th></tr>
<tr><td>will</td><td>不支持</td><td>will、will retain 的flag必须为0，will qos必须为0</td></tr>
<tr><td>session</td><td>不支持</td><td>cleansession标记必须为1</td></tr>
<tr><td>retain</td><td>不支持</td><td>相关标记必须为0</td></tr>
<tr><td>QoS0</td><td>支持</td><td>设备由订阅成功而收到的系统 topic 的消息均为 QoS0<br>设备发布至平台系统 topic 的消息均支持 QoS0</td></tr>
<tr><td>QoS1</td><td>支持</td><td>设备发布至平台系统 topic 的消息均支持 QoS1</td></tr>
<tr><td>QoS2</td><td>不支持</td><td> </td></tr>
</table>


## Topic Convention

The platform agrees on topic as follows:
- User-defined topic is not supported for the time being, only system topic is used.
- System topics start with $
- Users can access storage, commands and other services in the access suite using the related system Topic, for details see[Topic Cluster](/book/device-development/multpro/MQTTS/topics/introduction.md)
- Subscribe to topics related to publishing messages for the time being, not across devices/products.
- illegal use of topic

    When a device subscribes to an illegal topic, the platform returns a subscription failure via MQTT publish ACK

    When a device publishes a message to an illegal topic, the platform ** disconnects the device **

- Wildcards: Platform supports wildcards + and#
    > ** Note **: Wildcards supported when using ** system topic ** only support starting from Topic Level 5 directory
    >- Supports subscriptions of $sys/{pid}/{device-name}/cmd/#, $sys/{pid}/{device-name}/cmd/request/+, etc.
    >- Subscriptions such as $sys/{pid}/{device-name}/#, $sys/{pid}/#, $sys/{pid}/#, $sys/#, # are not supported.

    Devices can subscribe to messages as follows:

| Subscribe topic | Subscribe effect|
|:-|:-|
| $sys/{pid}/{device-name}/dp/post/json/accepted| Subscribe device data points to report successful messages|
| $sys/{pid}/{device-name}/dp/post/json/rejected | Subscribe device data points to report failed messages|
| $sys/{pid}/{device-name}/dp/post/json/+| Subscribe device data points to report results|
| $sys/{pid}/{device-name}/cmd/request/+| Subscribe to all command messages for devices|
| $sys/{pid}/{device-name}/cmd/response/+/+| Subscribe to all command response result messages for devices|
| $sys/{pid}/{device-name}/ cmd/# | Subscribe to all command-related messages for devices|