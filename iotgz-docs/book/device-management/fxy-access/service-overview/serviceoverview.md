# **泛协议接入**

# **服务概述**  

#### **1. 什么是泛协议接入服务**  

物联平台目前支持MQTT和CoAP协议，对于其他协议类型，如消防协议GB/T 26875.3-2011则暂未提供接入支持。在智能家居场景中，存在基于ZIGBEE或蓝牙的近距离通信设备，这些设备当前是无法直接接入清华大学物联平台的。此时，通过泛协议接入服务则能快速实现(无法直接接入平台)设备的接入工作，搭建设备与物联平台的双向数据通道。泛协议接入服务提供了用户自定义协议设备接入平台的能力，提供设备与平台的双向通信能力。

#### **2. 适用场景**  

+ 设备只支持特定协议，而这种协议不被物联平台支持
+ 由于设备硬件资源限制，设备无法直接接入物联平台
+ 设备已接入用户私有服务，用户希望在不修改设备固件情况下，将设备接入物联平台

#### **3. 服务架构说明**  

泛协议接入服务架构如下图所示：

![architecture](/images\device-management\fxy-service-overview\architecture.png)

图中主要名词解释：  

<table style="text-align: left">
    <tr style="background-color:#363636; color:#F0FFF0;">
        <td width="20%">名词</td>
        <td>描述</td>
    </tr>
    <tr>
        <td>Device</td>
        <td>用户(自定义私有协议)设备</td>
    </tr>
    <tr>
        <td>Protocol Hub</td>
        <td>泛协议接入SDK - 协议站模块，负责建立设备与协议网关的连接及数据通信，支持多种通信协议（目前仅支持TCP协议）</td>
    </tr>
    <tr>
        <td>Adapter SDK</td>
        <td>泛协议接入SDK - 适配SDK模块，提供一系列API供开发者连接用户设备与物联平台</td>
    </tr>
</table>

泛协议接入SDK为协议站和适配SDK两个模块：  

+ 适配SDK模块单独使用  
+ 协议站和适配SDK模块组合使用，可以用于泛协议设备接入网关适配物联平台的改造 
  

#### **4. 主要功能**  

**基础功能：**  

- 提供泛协议接入服务实例配置接口(默认实现基于静态文件的配置)  
- 提供设备上行通信的能力  
- 提供平台至设备的下行通信能力  
- 提供SDK自身至物联平台的上行通信能力  
- 提供物联平台至SDK自身的下行通信能力  
- 提供SDK与物联平台的TLS连接  

**高级功能：**  

- 提供设备在SDK侧鉴权及访问策略控制接口  
- 提供设备上行数据缓存的能力  
- 提供设备下行命令缓存的能力  
- 提供基础运行指标统计的能力  

#### **5. 开发与部署**  

（1）在控制台创建泛协议接入实例，代理产品，代理设备。

- 代理直连设备具体操作，请参见[代理直连设备](/book/device-management/fxy-access/agent-direct-link-device/agentdirectlinkdevice.md)  
- 代理网关设备具体操作，请参见[代理网关设备](/book/device-management/fxy-access/agent-gateway-device/agentgatewaydevice.md)

>备注：泛协议接入在代理「直连设备」类型或「网关设备」类型时，只能代理其「其它」类型设备，「MQTT & CoAP」类型设备不能被代理，**创建产品类型时需注意**。

（2）配置开发泛协议接入SDK。

- 具体操作参见[SDK开发指南](/book/device-management/fxy-access/sdk-guide/sdkguide.md)

（3）部署已开发完成的泛协议接入服务。

- 可以使用任意云服务器来部署  
- 也可以直接部署在网络环境通畅的本地环境中