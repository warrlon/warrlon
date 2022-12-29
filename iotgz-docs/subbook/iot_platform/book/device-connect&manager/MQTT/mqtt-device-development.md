
# MQTT设备连接

<a href="#1">1. 服务地址</a>

<a href="#2">2. 产品与设备创建</a>

<a href="#3">3. 设备安全认证</a>

---

<h3 id="1">1. 服务地址</h3>

设备接入支持标准MQTTV3.1.1版本，支持TLS加密，接入服务地址如下：

| 连接协议 | 证书                                                         | 地址            | 端口 |说明       |
| ------- | ---------------------------------------------------------- | ------------- | --- | ------------------------ | --------- |
| MQTT     | [证书下载](/images/iot_platform/mqtts/MQTTS-certificate.zip) | studio-mqtt.heclouds.com | 1883 | 非加密端口接入 |
| MQTTS     | [证书下载](/images/iot_platform/mqtts/MQTTS-certificate.zip) | studio-mqtts.heclouds.com    | 8883 |   加密端口接入 |

<h3 id="2">2. 产品与设备创建</h3>

按照[创建产品](/book/device-connect&manager/product-create.md)与[创建设备](/book/device-connect&manager/device-create.md)介绍，创建MQTT产品，并创建设备

> 其中：
>
> **产品名称**用户下具有**唯一性**
>
> **设备名称**产品内具有**唯一性**，推荐采用设备sn、mac地址、IMEI等信息命名设备

<h3 id="3">3. 设备安全认证</h3>


产品、设备创建时，平台为每类产品、每个设备均分配了唯一的 key，设备登录时需要使用通过key计算出的访问token 来进行访问安全认证，见[接入安全认证](/book/device-connect&manager/device-auth.md)


设备可通过MQTT connnect报文进行登录，connect报文中三要素填写方法如下：

| 参数     | 是否必须 | 参数说明                  |
| -------- | -------- | ------------------------- |
| clientId | 是       | 设备名称                  |
| username | 是       | 平台分配的产品ID          |
| password | 是       | 填写经过 key 计算的 token |
