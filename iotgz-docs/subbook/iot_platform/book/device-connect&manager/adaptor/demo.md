# 最佳实践-代理直连设备

<a href="#1">1. 修改配置文件</a>

<a href="#2">2. 开发业务代码，启动服务</a>

<a href="#3">3. 接入设备并登陆</a>

<a href="#4">4. 上传设备数据</a>

<a href="#5">5. 下发命令及回复响应</a>

<a href="#6">6. 登出设备</a>

---
示例代码工程源码(Java)：[点击下载](/images/iot_platform/CoAP&MQTT/protocol-adapter-sdk-examples.rar)

工程包括：
- protocol-adapter-sdk-example-standalone：仅使用泛协议接入SDK-适配SDK模块的示例代码，不包含TCP协议站模块；
- protocol-adapter-sdk-example-with-tcp-protocol-hub：包含泛协议接入SDK-TCP协议站模块和适配SDK模块的示例代码。

以下以protocol-adapter-sdk-example-with-tcp-protocol-hub为例，示例模拟了一台非标准协议的风扇设备使用泛协议接入SDK接入OneNET上传数据和下发命令的过程，使用IntelliJ IDEA 2020.1.3 (Ultimate Edition) ，示例中的配置仅供参考，运行时需要修改为您自己的泛协议接入服务的相关配置信息。


本示例定义了一种简单的仅供测试使用的自定义协议格式：
数据格式：TLV，大端模式编码

|        | 含义     | 数据长度         | 说明                                                    |
| ------ | -------- | ---------------- | ------------------------------------------------------- |
| Tag    | 操作类型 | 2字节(16bit)     | 1-上线，2-上传数据，3-响应下发命令，9-下线，11-下发命令 |
| Length | 数据长度 | 2字节(16bit)     | 指定数据payload长度                                     |
| Value  | 数据     | 长度由Length指定 | 数据payload，JSON类型，详情如下：                       |

- 设备上线(tag=1)：

```json
{
  "device_name": "a"
}
```

- 设备上传数据(tag=2)：

```json
{
  "status": 1,		
  "gear": 3,  		
  "duration": 20000	
}
```

| 字段     | 含义                               |
| -------- | ---------------------------------- |
| status   | 电风扇状态: 0-关，1-开             |
| gear     | 电风扇档位：1-低速，2-中速，3-高速 |
| duration | 电风扇已开启持续时间: 单位ms       |

- 给设备下发命令(tag=11)：

```json
{
  "id": "1609916964",
  "status": 0,		
  "gear": 1	
}
```

- 设备响应下发命令(tag=3)：

```json
{
  "id": "1609916964",
  "code": 200,
  "msg": "success"
}
```

| 字段 | 含义               |
| ---- | ------------------ |
| id   | 命令id             |
| code | 响应状态：200-成功 |
| msg  | 响应信息           |

- 设备下线(tag=9)：

```json
{}
```

<h3 id="1">1. 修改配置文件</font></h3>

1).新建并修改src/main/resources/config文件夹下的adapter.conf和device.conf文件：

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/CoAP&MQTT/config-sample.png">
</center>

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/CoAP&MQTT/config-sample2.png">
</center>

2).新建并修改项目src/main/resources/config文件夹下的protocolhub-tcp.conf文件：

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/CoAP&MQTT/config-sample3.png">
</center>

3).将物模型文件model-AAWCVR5JIx4hG9V3.json放入项目src/main/resources/config目录下，新建程序入口类ProtocolAdapterSdkDemo.java，并添加注解@ThingModelConfiguration({"config/model- AAWCVR5JIx4hG9V3.json"})，使用maven编译，生成物模型相关代码。

<h3 id="2">2. 开发业务代码，启动SDK服务</font></h3>

1).编写TlvDecoder.java和TlvEncoder.java，实现自定义协议的编解码，详见示例源码。此外，也可以在步骤2中实现对自定义协议的编解码。<br/>
2).编写SampleDeviceUpLinkHandler.java和SampleDeviceDownLinkHandler，实现自定义协议设备上下行数据处理接口。<br/>
- SampleDeviceUpLinkHandler.java：
按照自定义协议进行业务操作，业务操作主要使用如下所示的SDK提供的通用API与自动生成的物模型扩展API，其它业务代码可参考示例源码。<br/>
自定义协议设备连接到TCP协议站后，首先应建立与OneNET设备的映射，即在#init(Object, Channel)方法中生成并返回OneNET设备实体Device，这是进行后续业务上行操作的先决条件。


```
/**
  * 数据上行OpenApi
  */ 
private OpenApi openApi = new OpenApi(); 
/**
  * 数据上行扩展OpenApi
  */
private OpenApiExtensionAAWCVR5JIx4hG9V3 apiExtension = new OpenApiExtensionAAWCVR5JIx4hG9V3(openApi);
```
- SampleDeviceDownLinkHandler.java：
对平台下发的响应或者命令进行业务操作，业务操作主要使用如下所示的SDK提供的通用API、自动生成的物模型扩展API、下行消息推送API，其它业务代码可参考示例源码。

```
/**  
  * 用于推送消息和主动断开连接至TCP协议站的自定义设备连接  
  */ 
private final TcpDeviceDownLinkApi deviceDownLinkApi = new TcpDeviceDownLinkApi();  
/**
  * 物模型设置设备属性监听示例
  * 详见{@link com.github.cm.heclouds.adapter.api.DeviceCommandListener}
  */ 
private final DeviceCommandListener listener = (device, id, version, params) -> {     
    logger.logDevInfo(ConfigUtils.getName(), PLATFORM_DOWN_LINK, device.getProductId(), device.getDeviceName(), "property set command received: " + "id=" + id + ", version=" + version + ", value=" + params);     
    JsonElement status = params.get("status");     
    JsonElement gear = params.get("gear");     
    // 构造给设备下发的命令
    JsonObject jsonObject = new JsonObject();
    jsonObject.addProperty("id", id);
    if (status != null) {
        jsonObject.add("status", status);     
    }     
    if (gear != null) {         
        jsonObject.add("gear", gear);     
    }     
    // tag=11表示向设备下发命令     
    Tlv tlv = new Tlv((short) 11, jsonObject);     
    // 推送给设备     
    deviceDownLinkApi.pushToDevice(device, tlv); 
};
```
2).在ProtocolAdapterSdkDemo.java main方法中配置SDK和TCP协议站，初始化配置并启动服务：

```
// 初始化日志系统，默认提供文件日志
// 可指定logback日志配置文件相对于resources目录的路径
// 注意，SDK和协议站配置默认统一使用SDK和协议站配置中首先配置的日志系统
// 如以下示例，即使TCP协议站在配置了日志系统，TCP协议站也会使用SDK配置的日志系统
ILogger logger = FileLogger.getInstance("logback.xml");

// 配置SDK
Config sdkConfig = new Config(logger);
// 可选择手动填入泛协议接入服务和平台相关配置
// 如config.connectionHost("${connection_host}")
// .serviceId("${service_id}")
// .instanceName("${instance_name}")
// .instanceKey("${instance_key}")
// 也可通过填入IAdapterConfig接口实现类方式配置泛协议接入服务和平台相关配置，如
sdkConfig.adapterConfig(AdapterFileConfig.getInstance())
        // 配置设备映射关系配置，默认为DeviceFileConfig
        .deviceConfig(DeviceFileConfig.getInstance())
        // 配置平台设备的响应及命令下发接口的实现
        .deviceDownLinkHandler(new SampleDeviceDownLinkHandler());
// 初始化SDK配置
sdkConfig.init();


// 配置TCP协议站
TcpProtocolHubConfig protocolHubConfig = new TcpProtocolHubConfig(logger) {
    @Override
    public void addChannelHandlers(ChannelPipeline pipeline) {
        pipeline.addLast(new TlvDecoder())
                    .addLast(TvlEncoder.INSTANCE);
    }
};
// 配置TCP协议站的配置
protocolHubConfig
        // 同SDK配置，也可使用代码形式配置
        .tcpProtocolHubConfig(TcpFileConfig.getInstance())
        // 配置自定义设备的协议解码及上行业务开发
        .tcpDeviceUpLinkHandler(new SampleDeviceUpLinkHandler());
// 初始化TCP协议站配置
protocolHubConfig.init();

```

使用IDEA服务成功启动后可看到如下图所示的日志：

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/CoAP&MQTT/start-success.png">
</center>

或在项目./logs/protocol-adapter-sdk-example-with-tcp-protocol-hub文件夹下可看到日志

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/CoAP&MQTT/logs.png">
</center>

同时，可在Studio上观察到泛协议接入服务在线状态：

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/CoAP&MQTT/studio-adaptor.png">
</center>

<h3 id="3">3. 接入设备并登录</font></h3>

使用TCP工具模拟设备，接入SDK服务，发送16进制字符串00 01 00 13 7B 22 64 65 76 69 63 65 5F 6E 61 6D 65 22 3A 22 61 22 7D报文，此报文为编码后的TLV数据，tag=1，表示"device_name"为"a"的设备上线。<br/>
规定自定义协议中的"device_name"字段对应设备映射文件中的"originalIdentity"，即"device_name"="a"表示OneNET设备
```
a {
   # 产品ID
   productId = "AAWCVR5JIx4hG9V3"
   # 设备名称
   deviceName = "test_device"
   # 设备key
   deviceKey = "xxxxxxxxxxxxxxx"
}
```
您可使用OpenApi提供的通用API上线设备，以下示例代码在SampleDeviceUpLinkHandler类中的#init(Object, Channel)方法中：
```
Tlv tlv = (Tlv) data;
String deviceName = tlv.getValue().get("device_name").getAsString();
// 获取设备对应的平台设备信息，用户可自主开发工具用于获取和缓存设备信息的映射
// 平台设备信息实体
Device device = deviceConfig.getDeviceEntity(deviceName);
String productId = device.getProductId();
String devName = device.getDeviceName();
// 鉴权及权限校验
if (!authenticator.checkValid(productId, devName)||!authorizatorPolicy.canWrite(productId, devName)) {
    logger.logDevWarn(ConfigUtils.getName(), DEV_UP_LINK, productId, devName, "device auth failed");
    return null;
}
// 调用OpenApi进行设备上线操作
openApi.deviceOnline(device);
```
SampleDeviceDownLinkHandler提供了收到设备登陆成功的响应后的业务处理。

```
@Override
public void onDeviceLoginResponse(Device device, Response response) {
    logger.logDevInfo(ConfigUtils.getName(), LOGIN, device.getProductId(), device.getDeviceName(), "response: " + response);
}
```
如下图，表示设备成功登录：

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/CoAP&MQTT/login-success.png">
</center>

同时，在Studio上可观察到接入设备详情及在线状态。

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/CoAP&MQTT/login-success2.png">
</center>

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/CoAP&MQTT/login-success3.png">
</center>


<h3 id="4">4. 上传设备数据</font></h3>

设备登陆后，使用TCP工具模拟设备，继续发送00 02 00 26 7B 22 73 74 61 74 75 73 22 3A 31 2C 22 67 65 61 72 22 3A 33 2C 22 64 75 72 61 74 69 6F 6E 22 3A 32 30 30 30 30 7D报文，此报文为编码后的TLV数据，tag=2，表示设备上传数据：
```json
{
  "status": 1,		
  "gear": 3,  		
  "duration": 20000	
}
```
您可使用OpenApi提供的通用API上传设备属性，以下示例代码在SampleDeviceUpLinkHandler类中的#processUpLinkData(Device, Object, Channel)方法中：

```
int status = tlvValue.get("status").getAsInt();
int gear = tlvValue.get("gear").getAsInt();
int duration = tlvValue.get("duration").getAsInt();
JsonObject statusValue = new JsonObject();
statusValue.addProperty("value", status);
JsonObject gearValue = new JsonObject();
gearValue.addProperty("value", gear);
JsonObject durationValue = new JsonObject();
durationValue.addProperty("value", duration);

JsonObject properties = new JsonObject();
properties.add("status", statusValue);
properties.add("gear", gearValue);
properties.add("duration", durationValue);

openApi.uploadProperty(device, new OneJSONRequest(properties));
```

以上代码最终对应上传到平台的物模型OneJSON格式为：

```json
{
  "id": "1609923196784",
  "version": "1.0",
  "params": {
    "status": {
      "value": 1
    },
    "gear": {
      "value": 3
    },
    "duration": {
      "value": 20000
    }
  }
}
```
您可参照物模型OneJSON格式和物模型功能点构造自己的OneJSON，也可使用 [自动生成物模型相关代码](https://open.iot.10086.cn/doc/iot_platform/book/device-connect&manager/adaptor/sdk-usage.html#4) 生成的扩展API上传单个设备数据，如：

```
apiExtension.uploadStatusProperty(device, OpenApiUtils.getDefaultId(), OpenApiUtils.getDefaultVersion(), status, System.currentTimeMillis());
```

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/CoAP&MQTT/upload-prop.png">
</center>

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/CoAP&MQTT/upload-prop-show.png">
</center>

从日志中可以看出，设备数据上传成功，同时，在Studio上可观察到设备最新上传的数据。

<h3 id="5">5. 下发命令及回复响应</font></h3>

DeviceDownLinkHandler中onPropertySetRequest(Device, String, String, String, JsonObject)方法提供了处理平台下发设备属性设置业务的接口，SampleDeviceDownLinkHandler中实现了此接口。<br/>
SDK提供了DeviceCommandListener接口用于处理平台下发设备属性设置业务，开发者可选用自己实现此接口，或者实现使用 [自动生成物模型相关代码](https://open.iot.10086.cn/doc/iot_platform/book/device-connect&manager/adaptor/sdk-usage.html#4) 中生成的设置设备属性监听抽象类。<br/>
值得注意的是， [自动生成物模型相关代码](https://open.iot.10086.cn/doc/iot_platform/book/device-connect&manager/adaptor/sdk-usage.html#4) 中生成的设置设备属性监听抽象类拆分了下发的设备属性设置命令，如果下发的属性设置同时含有status和gear，则会拆分成两个方法来分别接收两个属性设置，开发者如果想要同时处理status和gear，建议不要使用 [自动生成物模型相关代码](https://open.iot.10086.cn/doc/iot_platform/book/device-connect&manager/adaptor/sdk-usage.html#4) 中生成的设置设备属性监听抽象类。<br/>
1).实现监听接口：
```
private final DeviceCommandListener listener = (device, id, version, params) -> {
    logger.logDevInfo(ConfigUtils.getName(), PLATFORM_DOWN_LINK, device.getProductId(), device.getDeviceName(), "identifier1 property set command received: " +
            "id=" + id + ", version=" + version + ", value=" + params);
    JsonElement status = params.get("status");
    JsonElement gear = params.get("gear");
    // 构造给设备下发的命令
    // value格式为
    //{
    //  "id": "1609916964",
    //  "status": 0,
    //  "gear": 1,
    //}
    JsonObject jsonObject = new JsonObject();
    jsonObject.addProperty("id", id);
    if (status != null) {
        jsonObject.add("status", status);
    }
    if (gear != null) {
        jsonObject.add("gear", gear);
    }
    // tag=11表示向设备下发命令
    Tlv tlv = new Tlv((short) 11, jsonObject);
    // 推送给设备
    deviceDownLinkApi.pushToDevice(device, tlv);
};
```
2).实现DeviceDownLinkHandler，编写收到平台下发设备属性设置的业务逻辑。
```
@Override
public void onPropertySetRequest(Device device, String id, String version, JsonObject params) { 
    listener.onCommandReceived(device, id, version, params);     
}
```
3).调试设备<br/>
使用Studio设备调试工具设置设备属性，填入合法属性值，点击发送。

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/CoAP&MQTT/device-debug.png">
</center>

SDK接收到平台下发的设备属性设置请求，会按照代码编写的业务逻辑，将请求发送给设备，设备会收到如下图所示经TLV编码后的消息：

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/CoAP&MQTT/receive-msg.png">
</center>

使用TCP工具模拟设备相应命令下发，发送00 03 00 26 7B 22 69 64 22 3A 22 31 37 22 2C 22 63 6F 64 65 22 3A 32 30 30 2C 22 6D 73 67 22 3A 22 73 75 63 63 65 73 73 22 7D报文，此报文为编码后的TLV数据，tag=3，表示设备响应回复：

```json
{
    "id": 17,		
    "code": 200,  		
    "msg": "success"	
}
```
您可使用OpenApi提供的方法响应命令，如：
```
String id = tlvValue.get("id").getAsString();
int code = tlvValue.get("code").getAsInt();
String msg = tlvValue.get("msg").getAsString();
// 构造响应回复
Response response = new Response(id, code, msg);
openApi.replyPropertySetRequest(device, response);
```
此时，可在页面上看到平台已成功接收到设备的命令响应。

<h3 id="6">6. 设备登出</font></h3>

设备发送00 09 00 02 7B 7D报文，此报文为编码后的TLV数据，tag=9，表示设备主动下线。调用通用API通知平台接入机主动登出设备：
```
openApi.deviceOffline(device)
```
接入机返回登出成功响应。

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/CoAP&MQTT/logout.png">
</center>

此时在Studio页面中可观察到设备已经离线：

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/CoAP&MQTT/logout2.png">
</center>