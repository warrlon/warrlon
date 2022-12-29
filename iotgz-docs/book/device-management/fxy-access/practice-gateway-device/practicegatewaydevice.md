# **最佳实践-代理网关设备**   

示例代码工程源码(Java)：[点击下载](https://open.iot.10086.cn/doc/iot_platform/images/iot_platform/CoAP&MQTT/protocol-adapter-sdk-examples-1.0.4.rar)

工程包括：

- protocol-adapter-sdk-example-gateway：使用SDK接入私有协议网关子设备；
- protocol-adapter-sdk-example-with-http：使用HTTP作为接收数据的接口；
- protocol-adapter-sdk-example-with-tcp-protocol-hub：包含TCP协议站模块和适配SDK模块的示例，演示如何将私有协议设备接入到物联平台。  
  
以下以protocol-adapter-sdk-example-gateway为例，示例模拟了一台连接风扇子设备的私有协议的网关使用泛协议接入SDK接入物联平台上传子设备数据和下发子设备命令的过程，使用IntelliJ IDEA 2020.1.3 (Ultimate Edition) ，示例中的配置仅供参考，运行时需要修改为您自己的泛协议接入服务的相关配置信息。泛协议接入适配SDK提供AdapterApi进行网关设备相关操作及网关设备、子设备的批量数据和历史数据上传，提供SubAdapterApi进行子设备相关操作。

示例项目结构如下图所示：

````java
|-- src 
   |-- main 
      |-- java 
         |-- com.github.cm.heclouds.adapter
            |-- adapter
               |-- SampleGatewayDeviceDownLinkHandler.java  网关设备平台下行数据处理
               |-- SampleSubDeviceDownLinkHandler.java      子设备平台下行数据处理
               |-- SampleUpLinkHandler.java                 设备上行数据处理
            |-- tlv
               |-- Tlv.java                                 示例使用的私有协议格式
               |-- TlvDecoder.java                          私有协议解码
               |-- TlvEncoder.java                          私有协议编码
            |-- ProtocolAdapterSDKDemo.java                 程序入口类
         |-- resources
            |-- config
               |-- adapter.conf                             SDK配置
               |-- devices.conf                             设备映射配置
               |-- protocolhub-tcp.conf                     TCP协议站配置
            |-- logback.xml                                 自定义日志配置
                
|-- pom.xml
````

本示例定义了一种简单的仅供测试使用的自定义协议格式，为便于测试，协议忽略了SDK对于设备上行数据的响应：  
数据格式：TLV，大端模式编码

<table style="text-align: left">
    <tr style="background-color:#363636; color:#F0FFF0;">
        <td width="15%"></td>
        <td width="15%">含义</td>
        <td width="15%">数据长度</td>
        <td>说明</td>
    </tr>
    <tr>
        <td>Type</td>
        <td>操作类型</td>
        <td>2字节(16bit)</td>
        <td>1-网关设备上线，9-网关设备下线，101-子设备上线，102-子设备上传数据，103-给子设备下发命令，109-子设备下线，111-子设备响应下发命令</td>
    </tr>
    <tr>
        <td>Length</td>
        <td>数据长度</td>
        <td>2字节(16bit)</td>
        <td>指定数据payload长度</td>
    </tr>
    <tr>
        <td>Value</td>
        <td>数据</td>
        <td>长度由Length指定</td>
        <td>数据payload，JSON类型，详情如下：</td>
    </tr>
</table>

- 网关设备上线(type=1)：

````json
{
  "device_name": "wangguan"
}
````

- 网关设备下线(type=9)：

````json
{}
````

- 子设备上线(type=101)：

````json
{
  "sub_device_name": "zishebei"
}
````

<table style="text-align: left">
    <tr style="background-color:#363636; color:#F0FFF0;">
        <td width="30%">字段</td>
        <td>含义</td>
    </tr>
    <tr>
        <td>sub_deivce_name</td>
        <td>子设备名称</td>
    </tr>
</table>

- 子设备上传数据(type=102)：

````json
{
    "sub_device_name": "zishebei",
    "data": {
        "status": 1,
        "gear": 2,
        "duration": 10000
    }
}
````

<table style="text-align: left">
    <tr style="background-color:#363636; color:#F0FFF0;">
        <td width="30%">字段</td>
        <td>含义</td>
    </tr>
    <tr>
        <td>status</td>
        <td>电风扇状态: 0-关，1-开</td>
    </tr>
    <tr>
        <td>gear</td>
        <td>电风扇档位：1-低速，2-中速，3-高速</td>
    </tr>
    <tr>
        <td>duration</td>
        <td>电风扇已开启持续时间: 单位ms</td>
    </tr>
</table>

- 给子设备下发命令(type=111)：

````json
{
    "id": "1609916964",
    "sub_device_name": "zishebei",
    "data": {
        "status": 1,
        "gear": 1
    }
}
````

- 子设备响应下发命令(type=103)：

````json
{
    "id": "1609916964",
    "sub_device_name": "zishebei",
    "code": 200,
    "msg": "success"
}
````

<table style="text-align: left">
    <tr style="background-color:#363636; color:#F0FFF0;">
        <td width="30%">字段</td>
        <td>含义</td>
    </tr>
    <tr>
        <td>id</td>
        <td>命令id</td>
    </tr>
    <tr>
        <td>code</td>
        <td>响应状态：200-成功</td>
    </tr>
    <tr>
        <td>msg</td>
        <td>响应信息</td>
    </tr>
</table>

- 子设备下线(type=109)：

````json
{
    "sub_device_name": "zishebei"
}
````

#### **1. 修改配置文件**  

（1）.新建并修改src/main/resources/config文件夹下的adapter.conf和device.conf文件；

（2）.新建并修改项目src/main/resources/config文件夹下的protocolhub-tcp.conf文件：可参考[最佳实践-代理直连设备](/book/device-management/fxy-access/practice-link-device/practicelinkdevice.md)；

（3）.新建程序入口类ProtocolAdapterSdkDemo.java。

#### **2. 开发业务代码，启动SDK服务**  

（1）.编写TlvDecoder.java和TlvEncoder.java，实现自定义协议的编解码；

（2）.编写SampleDeviceUpLinkHandler.java和SampleDeviceDownLinkHandler，实现自定义协议设备上下行数据处理接口；

（3）.在ProtocolAdapterSdkDemo.java main方法中配置SDK和TCP协议站，初始化配置并启动服务。

以上可参考[最佳实践-代理直连设备](/book/device-management/fxy-access/practice-link-device/practicelinkdevice.md)。  

子设备接收下发命令需要实现并配置SubDeviceDownLinkRequestHandler接口：  

````java
sdkConfig.adapterConfig(AdapterFileConfig.getInstance())
        // 配置设备映射关系配置，非必填，默认为文件配置
        .deviceConfig(DeviceFileConfig.getInstance())
        // 配置平台设备的响应及命令下发接口的实现，非必填，默认实现仅打印日志
        .deviceDownLinkHandler(new SampleDeviceDownLinkHandler())
        // 配置平台子设备的响应及命令下发接口的实现，非必填，默认实现仅打印日志
        .subDeviceDownLinkRequestHandler(new SampleSubDeviceDownLinkHandler()); 
````

#### **3. 接入网关设备并登录**  

网关设备同直连设备，可参考[最佳实践-代理直连设备](/book/device-management/fxy-access/practice-link-device/practicelinkdevice.md)。

#### **4. 登录子设备，上传子设备数据**  

网关设备登陆后，使用TCP工具发送00 65 00 1E 7B 22 73 75 62 5F 64 65 76 69 63 65 5F 6E 61 6D 65 22 3A 22 7A 69 73 68 65 62 65 69 22 7D，此报文为编码后的TLV数据，type=101，表示登录子设备，相应的处理代码为：  

````java
subDeviceAdapterApi.subDeviceOnline(device, subDevice);
````

在物联平台上可观察到子设备在线状态。

![dev-line-list](/images/device-management/fxy-gateway-device/dev-line-list.png)

子设备登陆后，使用TCP工具继续发送00 66 00 4C 7B 22 73 75 62 5F 64 65 76 69 63 65 5F 6E 61 6D 65 22 3A 22 7A 69 73 68 65 62 65 69 22 2C 22 64 61 74 61 22 3A 7B 22 73 74 61 74 75 73 22 3A 31 2C 22 67 65 61 72 22 3A 33 2C 22 64 75 72 61 74 69 6F 6E 22 3A 32 30 30 30 30 7D 7D报文，此报文为编码后的TLV数据，type=102，表示子设备上传数据：

````json
{
  "status": 1,		
  "gear": 3,  		
  "duration": 20000	
}
````

您可使用Adapter提供的批量上传数据API上传子设备属性，以下示例代码在SampleDeviceUpLinkHandler类中的#processUpLinkData(Device, Object, Channel)方法中：

````java
JsonObject data1 = tlvValue.get("data").getAsJsonObject();
int status = data1.get("status").getAsInt();
int gear = data1.get("gear").getAsInt();
int duration = data1.get("duration").getAsInt();

// 使用通用API上传所有数据，根据物模型规定，需要使用批量上报数据API
// 构造identity
JsonObject identity = new JsonObject();
identity.addProperty("productID", subDevice.getProductId());
identity.addProperty("deviceName", subDevice.getDeviceName());
// 构造properties
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

// 构造request
UploadPackRequest.Param param = new UploadPackRequest.Param(identity, properties, null);
List<UploadPackRequest.Param> params = new ArrayList<>();
params.add(param);
UploadPackRequest uploadPackRequest = new UploadPackRequest(params);
// 上传数据
adapterApi.uploadPackData(device, uploadPackRequest);
````

以上代码最终对应上传到平台的物模型OneJSON格式为：

````json
{
  "id": "1609923196784",
  "version": "1.0",
  "params": [
    {
      "identity": {
        "productID": "productID",
        "deviceName": "deviceName"
      },
      "properties": {
        "status": {
          "value": 1
         },
        "gear": {
          "value": 2
         },
        "duration": {
          "value": 10000
         }
      }
    }
  ]
}
````

您可参照物模型OneJSON格式和物模型功能点构造自己的OneJSON。

![](/images/device-management/fxy-cloud-dock/device-info.png)

同时，在物联平台上可观察到子设备最新上传的数据。

#### **5. 下发命令及回复响应**  

SubDeviceDownLinkRequestHandler中onSetSubDevicePropertyRequest(Device, String, String, String, JsonObject)方法提供了处理平台下发子设备属性设置业务的接口，SampleSubDeviceDownLinkHandler中实现了此接口。 

（1）.实现监听接口：

````java
private final DevicePropertySetListener listener = (device, id, version, params) -> {
    logger.logDevInfo(ConfigUtils.getName(), PLATFORM_DOWN_LINK, device.getProductId(), device.getDeviceName(), "property set command received: " +
            "id=" + id + ", version=" + version + ", value=" + params);
    // 获取子设备原始id
    String subDeviceName = params.get("deviceName").getAsString();
    String subDevicePid = params.get("productId").getAsString();
    String originalId = ConfigUtils.getDeviceConfig().getOriginalIdentity(subDevicePid, subDeviceName);
    // 获取数据
    JsonObject dataParams = params.get("params").getAsJsonObject();
    JsonElement status = dataParams.get("status");
    JsonElement gear = dataParams.get("gear");
    // 构造给子设备下发的命令
    // value格式为
    //{
    //    "id": "1609916964",
    //    "sub_device_name": "subDevice",
    //    "data": {
    //      "status": 1,
    //      "gear": 1
    //    }
    //}
    JsonObject jsonObject = new JsonObject();
    jsonObject.addProperty("id", id);
    jsonObject.addProperty("sub_device_name", originalId);
    JsonObject data = new JsonObject();
    if (status != null) {
        data.add("status", status);
    }
    if (gear != null) {
        data.add("gear", gear);
    }
    jsonObject.add("data", data);
    // type=111表示向子设备下发命令
    Tlv tlv = new Tlv((short) 111, jsonObject);
    // 推送给设备
    deviceDownLinkApi.pushToDevice(device, tlv);
};
````

（2）.实现SubDeviceDownLinkRequestHandler，编写收到平台下发子设备属性设置的业务逻辑：

````java
@Override
public void onSetSubDevicePropertyRequest(Device device, String id, String version, JsonObject params) { 
    listener.onCommandReceived(device, id, version, params);     
}
````

（3）.调试设备  
使用物联平台设备调试工具设置子设备属性，填入合法属性值，点击发送。

![fxy-ts](/images/device-management/fxy-cloud-dock/fxy-ts.png)

SDK接收到平台下发的子设备属性设置请求，会按照代码编写的业务逻辑，将请求发送给网关设备，网关设备会收到如下图所示经TLV编码后的消息：

<div align=center><img src ="/images/device-management/fxy-gateway-device/receive-msg-1.0.4.png"/></div>

使用TCP工具模拟子设备响应命令下发，发送00 67 00 43 7B 22 69 64 22 3A 22 31 30 22 2C 22 73 75 62 5F 64 65 76 69 63 65 5F 6E 61 6D 65 22 3A 22 7A 69 73 68 65 62 65 69 22 2C 22 63 6F 64 65 22 3A 32 30 30 2C 22 6D 73 67 22 3A 22 73 75 63 63 65 73 73 22 7D报文，此报文为编码后的TLV数据，type=103，表示子设备响应回复：  

````json
{
    "id": 10,		
    "code": 200,  		
    "msg": "success"	
}
````

您可使用SubDeviceAdapterApi提供的方法响应命令，如：

````java
String id = tlvValue.get("id").getAsString();
int code = tlvValue.get("code").getAsInt();
String msg = tlvValue.get("msg").getAsString();
// 构造响应回复
Response response = new Response(id, code, msg);
// 注意device是网关设备，并不是子设备
subDeviceAdapterApi.replySubDevicePropertySetRequest(device, response);
````

此时，可在页面上看到平台已成功接收到子设备的命令响应。

#### **6. 登出子设备**  

网关设备发送00 6D 00 1E 7B 22 73 75 62 5F 64 65 76 69 63 65 5F 6E 61 6D 65 22 3A 22 7A 69 73 68 65 62 65 69 22 7D报文，此报文为编码后的TLV数据，type=109，表示子设备主动下线。调用子设备API通知平台接入机主动登出子设备：

````java
subDeviceAdapterApi.deviceOffline(device, subDevice)
````

接入机返回登出成功响应。

此时在物联平台页面中可观察到子设备已经离线：

![](/images\device-management\fxy-cloud-dock\device-offline.png)

