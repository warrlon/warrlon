# 使用示例

## 将代理设备映射OneNET设备
在接收到代理设备上线请求后，用户可对代理设备进行鉴权和权限认证（可选，详情见下一小节），认证通过后，在自定义协议数据解码器解码相关方法中构造并返回MessageType为LOGIN的ProtocolMessage，并填充OneNET设备Id、设备名称、设备Key、设备所属的产品Id等信息。网关项目默认提供了代理设备配置信息读取接口（接口默认位置为/src/main/java/com/cmiot/gateway/config）及其默认实现，用于配置和读取代理设备信息到OneNET设备信息的映射。

代理设备配置默认使用配置文件方式。默认从Java工程默认资源文件路径（默认位置为/src/main/resources/config）下的devices.conf中读取代理设备配置文件。同时，网关项目支持代理设备配置自定义，只需实现代理设备配置信息读取接口（接口默认位置为/src/main/java/com/cmiot/gateway/config），并将其注解为Spring Bean，然后可通过 

    IDeviceConfig deviceConfig = ExtensionUtils.getDeviceConfig();

获取代理设备配置。

网关配置文件参数说明如下表

<table>
<tr><th width="30%">参数</th><th width="15%">是否必须</th><th >说明</th></tr>
<tr><td>originalIdentity</td><td>是</td><td>设备原始身份标识符，用户可通过此标识符建立代理设备到OneNET的映射关系。</td></tr>
<tr><td>productId</td><td>是</td><td>代理设备所属的OneNET产品Id</td></tr>
<tr><td>deviceName</td><td>是</td><td>OneNET设备名称。</td></tr>
<tr><td>deviceId</td><td>是</td><td>OneNET设备Id。</td></tr>
<tr><td>deviceKey</td><td>是</td><td>OneNET设备Key，用于设备在平台侧的鉴权。</td></tr>
</table>

## 设备鉴权和权限认证
网关项目以可选的扩展工具的形式提供了设备鉴权和权限认证能力，相关接口和默认实现在Java工程中的目录路径为/src/main/java/com/cmiot/gateway/security。用户可根据自己的业务实现鉴权和权限策略接口，并将其注解为Spring Bean，然后可通过扩展工具类ExtensionUtil获取并使用。


## 处理设备登陆响应
网关解析MessageType为LOGIN后，会发送代理设备的主动上线请求，OneNET平台MQTT接入服务收到主动上线请求后对上线请求进行处理并返回设备登陆成功/失败响应，用户可以实现下行数据处理接口DownLinkHandler（默认位置为/src/main/java/com/cmiot/gateway/custom）。

## 主动推送数据给设备
用户可通过DownLinkChannelHandler中pushToDevice方法主动推送数据给设备。需要注意的是，推送方法传入的网关内部数据（ProtocolMessage）并不是最终推送给设备的数据，仍需要用户自主编写自定义协议编码器将内部数据转换为最终推送给设备的数据。

用户可通过内部数据中MessageType的不同实现相应的业务逻辑。

> 注：DownLinkChannelHandler同时提供了主动断开设备连接的方法。
