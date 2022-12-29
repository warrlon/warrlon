# 服务简介

## 概述

OneNET平台目前支持MQTT、EDP、NBIOT、MODBUS、HTTP等协议，但其他协议类型，如消防协议GB/T 26875.3-2011则暂未提供接入支持。在智能家居场景中，存在基于ZIGBEE或蓝牙的近距离通信设备，这些设备当前是无法直接接入OneNET平台的。此时，通过OneNET协议网关服务则能快速实现(无法直接接入OneNET平台)设备的接入工作，搭建设备与OneNET平台的双向数据通道。

## 适用场景
- 设备只支持特定协议，而这种协议不被OneNET平台支持；
- 由于设备硬件资源限制，设备无法直接接入OneNET平台；
- 设备搭载非TCP或UDP协议，无法直接接入OneNET平台；
- 设备已接入用户私有服务，用户希望在不修改设备固件情况下，将设备接入OneNET平台。




## Iot Protocol Gateway注解
OneNET协议网关服务提供了用户自定义协议设备接入OneNET平台的能力，提供设备与平台的双向通信能力。协议网关服务架构如下图所示：

![](/images/MQTTS/gateway/gw1.png)

图中名词解释如下：

<table>
<tr><th width="35%">名词</th><th >描述</th></tr>
<tr><td>Device</td><td>用户(自定义私有协议)设备</td></tr>
<tr><td>IoT Protocol Gateway</td><td>简称为gateway(网关)，连接用户设备与OneNET平台的应用程序</td></tr>
<tr><td>ACC Service</td><td>OneNET平台MQTT接入服务</td></tr>
<tr><td>Custom Service</td><td>用于gateway与用户私有服务连接</td></tr>
</table>

### 图例
- 图中蓝色矩形为协议网关内部模块，其中蓝色实线矩形协议网关内部提供，无需二次开发；蓝色虚线矩形协议网关提供模块接口并提供默认实现，开发者可选择按需实现接口功能。
- 图中灰色矩形为协议转换及用户扩展模块，其中灰色实线矩形开发者必须实现，灰色虚线矩形可选择按需添加。

### 核心模块

- Protocol Hub：负责建立设备与协议网关的连接及数据通信，支持多种通信协议（目前仅支持TCP协议）。
- Custom Protocol Encoder/Decoder：用户自定义协议编解码模块，负责设备自定义协议格式的数据与网关数据之间的转换。
- Gateway Manager：网关管理模块，其中：
   - Config：网关参数与设备配置模块，负责读取网关实例的相关配置和OneNET设备相关信息，提供的默认实现为通过配置文件读取。
   - Session Manager：设备和连接Session管理模块，负责设备与网关的关系管理、设备与Channel的关系管理，等等。
   - Gateway Data Transformer & Handler：网关数据转换和处理模块，负责网关内部数据与MQTT协议格式的数据之间的转换和处理。
- MQTT Adaptor：负责MQTT协议格式的编解码和协议网关与OneNET平台MQTT接入服务的连接及数据通信。

### 扩展模块
- Security & Policy：安全和策略模块，用于设备的鉴权和权限管理；
- Logging：日志模块，用于打印网关服务运行日志；
- Metric：性能统计模块，用于输出网关服务运行状态及性能统计；
- Custom Channel Handlers：自定义Channel Handler，可添加以实现自定义功能；
- Data Cache & Distributuion：数据缓存及分发模块，提供如数据的缓存、读取等扩展功能；
- CMD Data Processor：命令数据处理，提供如离线命令缓存处理等扩展功能；
- API：API模块，默认提供OneNET API SDK，便于扩展更多自定义功能。

