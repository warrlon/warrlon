# LwM2M 协议规范

[1. CoAP协议](#1-coap协议)

[2. LwM2M协议](#2-LwM2M协议)

---

## 1. CoAP协议

CoAP协议是IETF提出的一种面向网络的协议，采用了与HTTP类似的特征，核心内容为资源抽象、REST式交互以及可扩展的头选项等。CoAP协议基于REST构架，REST是指表述性状态转换架构，是互联网资源访问协议的一般性设计风格。为了克服HTTP对于受限环境的劣势，CoAP既考虑到数据报长度的最优化，又考虑到提供可靠通信。一方面，CoAP提供URI，REST式的方法如GET、POST、PUT和DELETE，以及可以独立定义的头选项提供的可扩展性。另一方面，CoAP基于轻量级的UDP协议，并且允许IP多播。为了弥补UDP传输的不可靠性，CoAP定义了带有重传机制的事务处理机制。并且提供资源发现机制，并带有资源描述。

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/LwM2M/image-20210401232104060.png">
</center>

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/LwM2M/image-20210401232410953.png">
</center>

传输层为CoAP协议报文格式，CoAP由UDP作为承载，遵循UDP基本的协议报文格式，UDP数据内容部分按照CoAP协议报文格式进行写入传输。

CoAP协议格式说明如下：

- 【Ver】版本编号，指示CoAP协议的版本号。类似于HTTP 1.0 HTTP 1.1。版本编号占2位，取值为01B。
- 【T】报文类型，CoAP协议定义了4种不同形式的报文：CON报文，NON报文，ACK报文和RST报文。
- 【TKL】CoAP标识符长度。CoAP协议中具有两种功能相似的标识符，一种为Message ID（报文编号），一种为Token（标识符）。其中每个报文均包含消息编号，但是标识符对于报文来说是非必须的。
- 【Code】功能码/响应码。Code在CoAP请求报文和响应报文中具有不同的表现形式，Code占一个字节，它被分成了两部分，前3位一部分，后5位一部分，为了方便描述它被写成了c.dd结构。其中0.XX表示CoAP请求的某种方法，而2.XX、4.XX或5.XX则表示CoAP响应的某种具体表现。
- 【Message ID】报文编号。
- 【Token】标识符具体内容，通过TKL指定Token长度。
- 【Option】报文选项，通过报文选项可设定CoAP主机、CoAP URI、CoAP请求参数和负载媒体类型等等。
- 【1111 1111B】CoAP报文和具体负载之间的分隔符。
CoAP支持多个Option，CoAP的Option的表示方法比较特殊，采用增量的方式描述。一般情况下Option部分包含Option Delta、Option Length和Option Val三部分：
- 【Option Delta】表示Option的增量，当前的Option的具体编号等于之前所有Option Delta的总和。
- 【Option Length】表示Option Val终端设备的具体长度。
- 【Option Val终端设备】表示Option具体内容。
CoAP协议报文中具体数值的意义参考CoAP协议：IETF RFC7252。

## 2. LwM2M协议

LwM2M是OMA组织制定的轻量化的M2M协议。LwM2M定义了三个逻辑实体:

- LwM2M Server 服务器；
- LwM2M Client 客户端，负责执行服务器的命令和上报执行结果；
- LwM2M 引导服务器 Bootstrap Server，负责配置LwM2M客户端。

在这三个逻辑实体之间有4个逻辑接口：

- Device Discovery and Registration：客户端注册到服务器并通知服务器客户端所支持的能力；
- Bootstrap：Bootstrap Server配置Client；
- Device Management and Service Enablement：指令发送和接收；
- Information Reporting：上报其资源信息。

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/LwM2M/image-20210401232720698.png">
</center>

LwM2M Objects：每个对象对应客户端的某个特定功能实体。LwM2M 规范定义了以下标准Objects，比如

    urn:oma:LwM2M:oma:2; (LwM2M Server Object)；
    urn:oma:LwM2M:oma:3; (LwM2M Access Control Object)；
    每个object下可以有很多resource，比如Firmware object可以有Firmware版本号，size等resource；
    Vendor可以自己定义object。

LwM2M Protocol：定义了一些逻辑操作，比如Read, Write, Execute, Create or Delete。

CoAP：是IETF定义的Constrained Application Protocol，用来做LwM2M的传输层，下层是UDP。CoAP有自己的消息头，重传机制等。

DTLS 是指 Datagram Transport Level Security，即数据报安全传输协议，其提供了UDP 传输场景下的安全解决方案，能防止消息被窃听、篡改、身份冒充等问题。
LwM2M协议具体参见[OMA Lightweight M2M v1.0](http://www.openmobilealliance.org/release/LightweightM2M/V1_0_1-20170704-A/OMA-TS-LightweightM2M-V1_0_1-20170704-A.pdf)。
