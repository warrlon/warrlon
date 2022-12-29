# 服务概述

<a href="#1">1. 什么是泛协议接入服务</a>

<a href="#2">2. 适用场景</a>

<a href="#3">3. 服务架构说明</a>

<a href="#4">4. 主要功能</a>

<a href="#5">5. 开发与部署</a>

---

<h3 id="1">1. 什么是泛协议接入服务</font></h3>

OneNET Studio目前支持MQTT和CoAP协议，对于其他协议类型，如消防协议GB/T 26875.3-2011则暂未提供接入支持。在智能家居场景中，存在基于ZIGBEE或蓝牙的近距离通信设备，这些设备当前是无法直接接入OneNET平台的。此时，通过泛协议接入服务则能快速实现(无法直接接入平台)设备的接入工作，搭建设备与OneNET平台的双向数据通道。
泛协议接入服务提供了用户自定义协议设备接入平台的能力，提供设备与平台的双向通信能力。

<h3 id="2">2. 适用场景</font></h3>

- 设备只支持特定协议，而这种协议不被OneNET平台支持
- 由于设备硬件资源限制，设备无法直接接入OneNET平台
- 设备已接入用户私有服务，用户希望在不修改设备固件情况下，将设备接入OneNET平台

<h3 id="3">3. 服务架构说明</font></h3>
泛协议接入服务架构如下图所示：
<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/CoAP&MQTT/architecture.png">
</center>


图中主要名词解释：


<table>
<tr><th>名词</th><th>描述</th></tr>
<tr><td>Device</td><td>用户(自定义私有协议)设备</td></tr>
<tr><td>Protocol Hub</td><td>泛协议接入SDK - 协议站模块，负责建立设备与协议网关的连接及数据通信，支持多种通信协议（目前仅支持TCP协议）</td></tr>
<tr><td>Adapter SDK</td><td>泛协议接入SDK - 适配SDK模块，提供一系列API供开发者连接用户设备与OneNET平台</td></tr>
<tr><td>OneNET</td><td>中国移动物联网开放平台</td></tr>
</table>

泛协议接入SDK为协议站和适配SDK两个模块：


- 适配SDK模块单独使用，用于云云对接；
- 协议站和适配SDK模块组合使用，可以用于泛协议设备接入网关适配OneNET的改造；


详细介绍及使用方法见下文。



<h3 id="4">4. 主要功能</font></h3>

#### 基础功能：

- 提供泛协议接入服务实例配置接口(默认实现基于静态文件的配置)
- 提供设备上行通信的能力
- 提供平台至设备的下行通信能力
- 提供SDK自身至OneNET平台的上行通信能力
- 提供OneNET平台至SDK自身的下行通信能力
- 提供SDK与OneNET平台的TLS连接

#### 高级功能：

- 提供设备在SDK侧鉴权及访问策略控制接口
- 提供设备上行数据缓存的能力
- 提供设备下行命令缓存的能力
- 提供基础运行指标统计的能力

<h3 id="5">5. 开发与部署</font></h3>

1).在控制台创建泛协议接入实例，代理产品，代理设备：

代理直连设备具体操作，请参见[代理直连设备](https://open.iot.10086.cn/doc/iot_platform/book/device-connect&manager/adaptor/device-proxy.html)

代理网关设备具体操作，请参见[代理网关设备](https://open.iot.10086.cn/doc/iot_platform/book/device-connect&manager/adaptor/gateway-proxy.html)

备注：

- 泛协议接入在代理「直连设备」类型或「网关设备」类型时，只能代理其「其它」类型设备，「MQTT & CoAP」类型设备不能被代理，**创建产品类型时需注意**。

2).配置开发泛协议接入SDK。

具体操作，请参见[SDK开发指南](https://open.iot.10086.cn/doc/iot_platform/book/device-connect&manager/adaptor/sdk-usage-1.0.4.html)


3).部署已开发完成的泛协议接入服务。
- 可以使用任意云服务器来部署。
- 也可以直接部署在网络环境通畅的本地环境中。