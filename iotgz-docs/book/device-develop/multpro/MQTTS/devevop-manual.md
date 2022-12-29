# 开发指南

## 服务地址

MQTTS 接入套件支持标准 MQTT V3.1.1 版本，支持TLS加密，接入服务地址如下

|连接协议|证书|地址|端口|
|:-|:-|:-|:-|
|MQTTS|[证书下载](/cer/MQTTS-certificate.pem)| 183.230.40.16|8883 |

## 产品与设备创建

按照入门手册[创建产品](/book/easy-manual/product&device/product-create.md)与[创建设备](/book/easy-manual/product&device/device-create/single-device.md)介绍，创建MQTTS产品，并创建设备

> 其中：  
> **设备名称**产品内具有**唯一性**，推荐采用设备sn、mac地址、IMEI等信息命名设备

## 设备安全认证

设备创建时，平台为每个设备分配了唯一的 key，设备登录时需要使用 **通过 key 计算出的访问token** 来进行访问安全认证，token算法见[安全鉴权](/book/easy-manual/auth.md)

设备可通过MQTT connnect报文进行登录，connect报文中三要素填写方法如下：

<table>
<tr><th width="30%">参数</th><th width="20%">是否必须</th><th>参数说明</th></tr>
<tr><td>clientId</td><td>是</td><td>设备名称</td></tr>
<tr><td>username</td><td>是</td><td>平台分配的产品ID</td></tr>
<tr><td>password</td><td>是</td><td>填写经过 key 计算的 token</td></tr>
</table>


### 常见安全方案

#### 方案1
设备产线烧录时，为每一个设备烧写对应的 **设备名称、产品ID、设备key**，设备启动时通过 key计算token，并进行设备登录

#### 方案2 
设备首次启动时，从访问管理者处获取设备key，并进行本地存储，随后设备通过密钥生成token进行访问

![](/images/MQTTS/设备认证2.jpg)

#### 方案3
设备key由访问管理者统一管理，当设备需要访问时，首先通过访问管理者获取临时访问token，访问管理者可根据需要自定义该token的访问有效期（即 token 过期时间），设备获取该token后，通过该token访问OneNET

![](/images/MQTTS/设备认证1.jpg)

## 设备保活

MQTT connect 报文中，需要设置keepalive（即保活时间），keepalive支持范围为：**10~1800**，单位为秒

设备若需要保持长连接，则设备在连续的 设置的keepalive 时间内，必须要有上行数据报文（包括 publish、ping、subscribe 等）

平台若在连续的 **设置的keepalive的1.5倍** 的时间内没有收到设备上行数据，则会设备断开连接

## 更多帮助

- [了解更多 OneNET 关于 MQTT 的协议约定](/book/device-develop/multpro/MQTTS/protocol.md)
- [了解如何通过 topic 使用物联网套件中的服务](/book/device-develop/multpro/MQTTS/topics/introduce.md)
- [了解如何使用模拟工具快速体验接入过程](/book/device-develop/multpro/MQTTS/example/connect.md)
