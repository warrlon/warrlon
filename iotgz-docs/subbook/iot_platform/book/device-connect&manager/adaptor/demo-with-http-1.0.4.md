# 最佳实践-云云对接

<a href="#1">1. 修改配置文件</a>

<a href="#2">2. 开发业务代码，启动服务</a>

<a href="#3">3. 接入第三方云平台，实现设备登录</a>

<a href="#4">4. 上传设备数据</a>

<a href="#5">5. 登出设备</a>

---
示例代码工程源码(Java)：[点击下载](/images/iot_platform/CoAP&MQTT/protocol-adapter-sdk-examples-1.0.4.rar)

工程包括：
- protocol-adapter-sdk-example-gateway：使用SDK接入私有协议网关子设备；
- protocol-adapter-sdk-example-with-http：云云对接方案示例，示例使用HTTP作为接收数据的接口；
- protocol-adapter-sdk-example-with-tcp-protocol-hub：包含TCP协议站模块和适配SDK模块的示例，演示如何将私有协议设备接入到OneNET平台。

以下以protocol-adapter-sdk-example-with-http为例，示例模拟了第三方平台的一台风扇设备使用泛协议接入SDK接入OneNET上传数据的过程，示例代码开发使用IntelliJ IDEA 2020.1.3 (Ultimate Edition) ，示例中的配置仅供参考，运行时需要修改为您自己的泛协议接入服务的相关配置信息。<br>
示例项目使用SpringBoot作为开发框架，项目结构如下图所示：
```
|-- src 
   |-- main 
      |-- java 
         |-- com.github.cm.heclouds.adapter
            |-- controller
               |-- HttpController.java               控制层，接收HTTP接口数据
            |-- service
               |-- ProtocolAdapterService.java       处理设备数据，转换为OneNET物模型数据并上传到OneNET平台
            |-- ProtocolAdapterDemo.java             程序入口类
         |-- resources
            |-- config
               |-- adapter.conf                      SDK配置
               |-- devices.conf                      设备映射配置
            |-- logback.xml                          自定义日志配置
                
|-- pom.xml 

```
本示例定义了一种简单的仅供测试使用的自定义HTTP接口：

#### 请求地址

> http://localhost:8080/data

#### 请求方法

> Post

#### 请求头

| 参数名称   | 类型   | 是否必选 | 描述   |
| :--------- | :----- | :------- | :----- |
| Token | String | 是       | 鉴权用Token，示例中默认为cmiot|
| DeviceName | String | 是       | 设备名，示例中作为唯一标识|

#### 请求Body

> JSON格式

```json
{
    "type": 2,
    "data": {
        "status": 1,
        "gear": 3,
        "duration": 20000
    }
}
```

| 参数名称   | 类型   | 是否必选 | 描述   |
| :--------- | :----- | :------- | :----- |
| type      | Integer   | 是 | 操作类型，1-上线，2-上传数据，9-下线             |
| data      | JsonObject| 否 | 上传的具体数据，type=1或3时可为空，type=2时必填  |
| status    | Integer   | 否 | 电风扇状态：0-关，1-开                         |
| gear      | Integer   | 否 | 电风扇档位：1-低速，2-中速，3-高速               |
| duration  | Long      | 否 | 电风扇已开启持续时间：单位ms                     |

#### 返回数据

| 参数名称          | 类型    | 描述                       |
| :---------------- | :------ | :------------------------- |
| id                | String  | 消息id号   |
| code              | Integer  | 结果状态码   |
| msg               | String  | 错误信息 |


<h3 id="1">1. 修改配置文件</font></h3>

1).新建并修改src/main/resources/config文件夹下的adapter.conf和device.conf文件：

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/CoAP&MQTT/config-sample-http-1.0.4.png">
</center>

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/CoAP&MQTT/config-sample2-http-1.0.4.png">
</center>

2).新建程序入口类ProtocolAdapterDemo.java。

<h3 id="2">2. 开发业务代码，启动SDK服务</font></h3>

1).编写HttpController.java，开发HTTP接口，可参见[SpringBoot官网文档](https://spring.io/guides/gs/rest-service/) ；
2).编写ProtocolAdapterService.java，解析上述JSON数据，实现设备登录登出和数据上传。<br/>

第三方云平台设备数据上传到示例项目后，首先应建立与OneNET设备的映射，返回OneNET设备实体Device，这是进行后续业务上行操作的先决条件。

```java
// 设备映射关系的配置默认使用文件配置，同时也可参考protocol-adapter-sdk-example-config示例自主实现
Device device = deviceConfig.getDeviceEntity(deviceName);
```

3).在ProtocolAdapterDemo.java main方法中配置SDK，初始化配置并启动SpringBoot服务：

```java
// 初始化日志系统，默认提供文件日志
// 可指定logback日志配置文件相对于resources目录的路径
ILogger logger = FileLogger.getInstance("logback.xml");
// 配置SDK
Config sdkConfig = new Config(logger);
// 非必填，默认为文件配置，可选择手动填入泛协议接入服务和平台相关配置
// 如config.connectionHost("${connection_host}")
// .serviceId("${service_id}")
// .instanceName("${instance_name}")
// .instanceKey("${instance_key}")
// 也可通过填入IAdapterConfig接口实现类方式配置泛协议接入服务和平台相关配置，如
sdkConfig.adapterConfig(AdapterFileConfig.getInstance())
        // 配置设备映射关系配置，非必填，默认为文件配置
        .deviceConfig(DeviceFileConfig.getInstance());
// 初始化SDK配置
sdkConfig.init();

// 启动程序
SpringApplication.run(ProtocolAdapterDemo.class, args);

```

使用IDEA服务成功启动后可看到如下图所示的日志：

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/CoAP&MQTT/start-success-http-1.0.4.png">
</center>

同时，可在Studio上观察到泛协议接入服务在线状态：

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/CoAP&MQTT/studio-adaptor-http-1.0.4.png">
</center>

<h3 id="3">3. 接入第三方云平台，实现设备登录</font></h3>

使用HTTP客户端工具，接入SDK服务，发送type=1的数据，实现设备登陆，如下图所示：

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/CoAP&MQTT/login-success-http-1.0.4.png">
</center>

规定请求头的"DeviceName"字段对应设备映射文件中的"originalIdentity"，即"DeviceName"="fan1"表示OneNET设备
```
fan1 {
   # 产品ID
   productId = "AAWCVR5JIx4hG9V3"
   # 设备名称
   deviceName = "test_device"
   # 产品或设备key
   key = "xxxxxxxxxxxxxxx"
}
```
您可使用AdapterApi提供的通用API上线设备，以下示例代码在ProtocolAdapterService类中的#uploadProperties(Device, JsonObject)方法中：
```java
adapterApi.deviceOnline(device);
```

在Studio上可观察到接入设备详情及在线状态。

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/CoAP&MQTT/login-success2-http-1.0.4.png">
</center>

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/CoAP&MQTT/login-success3-http-1.0.4.png">
</center>


<h3 id="4">4. 上传设备数据</font></h3>

设备登陆后，上传type=2的JSON格式数据，如下图所示：

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/CoAP&MQTT/upload-prop-http-1.0.4.png">
</center>

您可使用AdapterApi提供的通用API上传设备属性，以下示例代码在ProtocolAdapterService类中的#uploadProperties(Device, JsonObject)方法中：

```java
JsonObject data = body.get("data").getAsJsonObject();
int status = data.get("status").getAsInt();
int gear = data.get("gear").getAsInt();
int duration = data.get("duration").getAsInt();
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
adapterApi.uploadProperty(device, new OneJSONRequest(properties));
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
您可参照物模型OneJSON格式和物模型功能点构造自己的OneJSON，也可参考protocol-adapter-sdk-example-code-generator使用[自动生成物模型相关代码](https://open.iot.10086.cn/doc/iot_platform/book/device-connect&manager/adaptor/sdk-usage.html#4) 生成的扩展API上传单个设备数据。

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/CoAP&MQTT/upload-prop-show-http-1.0.4.png">
</center>

从日志中可以看出，设备数据上传成功，同时，在Studio上可观察到设备最新上传的数据。

<h3 id="5">5. 设备登出</font></h3>

发送type=3的数据，表示设备登出，调用通用API通知平台接入机主动登出设备：
```java
adapter.deviceOffline(device);
```
接口返回登出成功响应。

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/CoAP&MQTT/logout-http-1.0.4.png">
</center>

此时在Studio页面中可观察到设备已经离线：

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/CoAP&MQTT/logout2-http-1.0.4.png">
</center>