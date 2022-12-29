
# MQTT 协议规范

<a href="#1">1. 协议版本</a>

<a href="#2">2. 协议实现</a>

---

<h3 id="1">协议版本</h3>

平台支持标准 MQTT **3.1.1**版本，协议详情请参考[协议说明](http://mqtt.org/?spm=a2c4g.11186623.2.11.19083f86gxhJ7h)

<h3 id="2">协议实现</h3>

#### 报文支持

- 平台支持connect、subscribe、publish、ping、unsubscribe、disconnect等报文
- 不支持pubrec、pubrel、pubcomp报文


#### 特性支持

平台对协议特性支持如下：
<table>
<tr><th width="20%">特性</th><th width="20%">是否支持</th><th>说明</th></tr>
<tr><td>will</td><td>不支持</td><td>will、will retain 的flag必须为0，will qos必须为0</td></tr>
<tr><td>session</td><td>不支持</td><td>cleansession标记必须为1</td></tr>
<tr><td>retain</td><td>不支持</td><td>相关标记必须为0</td></tr>
<tr><td>QoS0</td><td>支持</td><td>设备由订阅成功而收到的系统 topic 的消息均为 QoS0<br>设备发布至平台系统 topic 的消息均支持 QoS0</td></tr>
<tr><td>QoS1</td><td>支持</td><td>设备发布至平台系统 topic 的消息均支持 QoS1</td></tr>
<tr><td>QoS2</td><td>不支持</td><td> </td></tr>
</table>


