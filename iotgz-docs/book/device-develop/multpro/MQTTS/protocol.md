# MQTT 协议规范

## 协议版本

平台支持标准 MQTT **3.1.1**版本，协议详情请参考[协议说明](http://mqtt.org/?spm=a2c4g.11186623.2.11.19083f86gxhJ7h)

## 协议实现

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


## Topic约定

平台对 topic 约定如下：
- 暂不支持用户自定义 topic，仅限使用系统 topic
- 系统topic均为 $ 开头
- 用户可以使用相关系统 topic 访问接入套件中的存储、命令等服务，详情请见 [Topic簇](/book/device-develop/multpro/MQTTS/topics/introduce.md)
- 设备使用 **系统 topic** 时暂仅限订阅与发布消息至自己相关的 topic，不能跨设备/产品订阅与发布
- topic非法使用

    设备订阅非法 topic 时，平台通过MQTT publish ack返回订阅失败
    
    设备发布消息到非法topic时，平台会**断开设备连接**

- 通配符：平台支持通配符 + 与 # 
    > **说明**：使用 **系统topic** 时支持的通配符仅支持从 topic 第五级目录开始
    > - 支持 $sys/{pid}/{device-name}/cmd/#、$sys/{pid}/{device-name}/cmd/request/+等订阅方式
    > - 不支持 $sys/{pid}/{device-name}/#、$sys/{pid}/#、$sys/#、# 等订阅方式
    
    设备可以按照如下方式进行消息订阅：

|订阅 topic |订阅效果 |
|:-|:-|
|$sys/{pid}/{device-name}/dp/post/json/accepted|订阅设备数据点上报成功的消息|
|$sys/{pid}/{device-name}/dp/post/json/rejected|订阅设备数据点上报失败的消息|
|$sys/{pid}/{device-name}/dp/post/json/+|订阅设备数据点上报结果|
|$sys/{pid}/{device-name}/cmd/request/+|订阅设备所有命令消息|
|$sys/{pid}/{device-name}/cmd/response/+/+|订阅设备所有命令应答结果消息|
|$sys/{pid}/{device-name}/cmd/#|订阅设备所有命令相关消息|

