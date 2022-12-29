# Access instance-device connection

This article will introduce how to access devices through ** MQTT. FX ** through examples.

[MQTT client download](http://mqttfx.jensd.de/index.php/download)

## Product and Equipment Creation

Create MQTTS products and devices according to the introduction manual (/ book/easy-manual/product&device/product-create.md) and (/ book/easy-manual/product&device/device-create/single-device.md)

In this example, the device access parameters are as follows:

<table>
<tr><th width="20%">产品ID</th><th width="30%">设备名称</th><th>设备key</th></tr>
<tr><td>238322</td><td>mqtts-test-device</td><td>EnW4T71eIE55xOIQMN6pFMKuqel5T5HTzsGJRPiDhlM=</td></tr>
</table>

![](/images/MQTTS/设备列表.png)

## MQTT.fx Client Configuration

Open the MQTT.fx client and enter the client configuration page.
![](/images/mq/example/客户端配置入口.png)

Set ** Profile Name **, in this case * MQTTS device access*

Set the access address and port, and set ** username ** and ** password **, where the parameters are set as follows:

|Client ID|User Name|Password|
|:-|:-|:-|
| Device Name: mqtts-test-device | Product ID: 238322 | See[Security Authentication](/book/easy-manual/auth.md)|

In this case, the Password example is as follows:

> version=2018-10-31&res=products%2F238322%2Fdevices%2Fmqtts-test-device&et=7557387130&method=sha1&sign=Rs0u%2FKnyoK5%2FMuKo5xKa0tW%2BWqY%3D

As shown in the following figure:
![](/images/MQTTS/.fx配置.png)

Click ** SSL / TLS ** to enter the encryption settings

Select ** CA certificate file ** to import certificates

![](/images/mq/example/证书选择.png)

Click OK to complete the configuration

## Device Connection
Click on the configuration file and select the arrow to configure * MQTTS device access*

![](/images/MQTTS/选择配置.png)

Click ** Connect ** to access the device. At this time, the device in the platform console is in ** online ** state.

![](/images/MQTTS/设备在线.png)