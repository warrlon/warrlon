# **接入概述**

# **标准协议接入**

#### 1. 接入协议概述 

物联平台支持标准MQTT协议和CoAP协议接入，是物联网的重要组成部分。MQTT是一种基于TCP构建的轻量级发布、订阅传输协议，适用于网络带宽有限的场景，同时其可以保持长连接，具有一定的实效性。CoAP是一个满足受限环境下M2M需求的应用层协议，运行在UDP之上，适合数据采集等场景，广泛应用于对电量需求低、覆盖深度广、终端设备海量连接以及设备成本敏感的环境。典型应用场景为：智能停车、智能抄表、智能井盖、智能路灯等应用场景。

#### 2. MQTT协议规范  

平台支持标准 MQTT 3.1.1版本，协议详情请参考[协议说明](https://mqtt.org/?spm=a2c4g.11186623.2.11.19083f86gxhJ7h)。

**报文支持**

- 平台支持connect、subscribe、publish、ping、unsubscribe、disconnect等报文
- 不支持pubrec、pubrel、pubcomp报文

**特性支持**  

平台对协议特性支持如下：  

<table style="text-align: left">
<tr style="background-color:#363636; color:#F0FFF0;"><td width="15%">特性</td><td width="20%">是否支持</td><td>说明</td></tr>
<tr><td>will</td><td>不支持</td><td>will、will retain 的flag必须为0，will qos必须为0</td></tr>
<tr><td>session</td><td>不支持</td><td>cleansession标记必须为1</td></tr>
<tr><td>retain</td><td>不支持</td><td>相关标记必须为0</td></tr>
<tr><td>QoS0</td><td>支持</td><td>设备由订阅成功而收到的系统 topic 的消息均为 QoS0<br>设备发布至平台系统 topic 的消息均支持 QoS0</td></tr>
<tr><td>QoS1</td><td>支持</td><td>设备发布至平台系统 topic 的消息均支持 QoS1</td></tr>
<tr><td>QoS2</td><td>不支持</td><td> </td></tr>
</table>

#### 3. CoAP协议规范 

平台支持 RFC 7252 Constrained Application Protocol协议。