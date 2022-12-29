# 设备接入

本文将通过实例介绍如何通过**MQTT.fx**进行设备接入

[MQTT客户端1.7.1下载](http://www.jensd.de/apps/mqttfx/1.7.1/)

## 产品与设备创建

按照快速入门 **创建产品** 与 **创建设备** 介绍，创建MQTTS产品，并创建设备

本例中，设备接入相关参数如下：

<table>
<tr><th width="20%">产品ID</th><th width="30%">设备名称</th><th>设备key</th></tr>
<tr><td>238322</td><td>mqtts-test-device</td><td>EnW4T71eIE55xOIQMN6pFMKuqel5T5HTzsGJRPiDhlM=</td></tr>
</table>

![](/images/MQTTS/设备列表.png)

## MQTT.fx客户端配置

打开MQTT.fx客户端，进入客户端配置页面，
![](/images/mq/example/客户端配置入口.png)

设置**Profile Name**，本例中为 *MQTTS设备接入*

设置接入地址与端口，并设置**username**与**password**，其中参数设置方式如下：

|Client ID|User Name|Password|
|:-|:-|:-|
|设备名称：mqtts-test-device|产品ID：238322|见[token算法](/book/manual/auth/token.md)|

本例中，Password 示例如下：

> version=2018-10-31&res=products%2F238322%2Fdevices%2Fmqtts-test-device&et=7557387130&method=sha1&sign=Rs0u%2FKnyoK5%2FMuKo5xKa0tW%2BWqY%3D

如下图所示：
![](/images/MQTTS/.fx配置.png)

点击**SSL/TLS**进入加密设置

选择**CA certificate file**，导入证书

![](/images/MQTTS/证书选择.png)

点击OK，完成配置

## 设备连接
点击配置文件选择箭头，选择配置*MQTTS设备接入*

![](/images/MQTTS/选择配置.png)

点击**Connect**，进行设备接入，此时，平台控制台中设备处于 **“在线”** 状态

![](/images/MQTTS/设备在线.png)


