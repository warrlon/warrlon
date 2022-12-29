# Development Guidelines

## Service Address

MQTTS Access Suite supports standard MQTT V3.1.1 version and TLS encryption. The access service address is as follows

| Connection Protocol | Certificate | Address | Port|
|:-|:-|:-|:-|
| MQTTS |[Certificate Download](/cer/serverCert.pem) | 183.230.40.16 | 8883|

## Product and Equipment Creation

Create MQTTS products and devices according to the introduction manual (/ book/easy-manual/product&device/product-create.md) and (/ book/easy-manual/product&device/device-create/single-device.md)

> Among them:
> ** Equipment Name ** Uniqueness ** in the product. It is recommended to use equipment sn, MAC address, IMEI and other information naming devices.

## Equipment Safety Authentication

When the device is created, the platform assigns a unique key to each device. When the device logs in, it needs to use ** to access token ** calculated by key to authenticate the access security. For the token algorithm, see[security authentication](/book/easy-manual/auth.md).

The device can be logged in by MQTT Connnect message. The three elements of connect message are as follows:

<table>
<tr><th width="30%">参数</th><th width="20%">是否必须</th><th>参数说明</th></tr>
<tr><td>clientId</td><td>是</td><td>设备名称</td></tr>
<tr><td>username</td><td>是</td><td>平台分配的产品ID</td></tr>
<tr><td>password</td><td>是</td><td>填写经过 key 计算的 token</td></tr>
</table>


### Common security solutions

1. When the equipment production line is burned, the corresponding ** device name, product ID and key ** are written for each device. When the device is started, token is calculated by key, and the device is logged in.

2. When the device is first started, the device key is obtained from the access manager and stored locally. Then the device is accessed by token generated by the key.

    ![](/images/MQTTS/设备认证2.jpg)

3. The device key is managed by the access manager. When the device needs access, the temporary access token is obtained by the access manager. The access manager can customize the token's access validity period (i.e. token expiration time) according to the need. After the device acquires the token, it accesses OneNET through the token.

    ![](/images/MQTTS/设备认证1.jpg)

## Equipment maintenance

In MQTT connect message, keep alive (i.e. live time) needs to be set, and keep alive support ranges from ** 10 to 1800 ** in seconds.

If a device needs to maintain a long connection, the device must have an upstream data message (including publish, ping, subscribe, etc.) in a continuous set of keep-alive time.

If the platform does not receive the device upstream data within 1.5 times the time of continuous ** keeping, the device will be disconnected.

## More help

-[Learn more about OneNET protocols for MQTT](/book/device-development/multpro/MQTTS/protocol.md)
-[Learn how to use services in the Internet of Things suite through topic](/book/device-development/multpro/MQTTS/topics/introduction.md)
-[Learn how to use simulation tools to quickly experience access processes](/book/device-development/multpro/MQTTS/example/connect.md)