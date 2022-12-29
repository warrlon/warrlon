# **最佳实践-云云对接**  

示例代码工程源码(Java)：[点击下载](https://open.iot.10086.cn/doc/iot_platform/images/iot_platform/CoAP&MQTT/protocol-adapter-sdk-examples-1.0.4.rar)

工程包括：  

- protocol-adapter-sdk-example-gateway：使用SDK接入私有协议网关子设备；  
- protocol-adapter-sdk-example-with-http：云云对接方案示例，示例使用HTTP作为接收数据的接口；  
- protocol-adapter-sdk-example-with-tcp-protocol-hub：包含TCP协议站模块和适配SDK模块的示例，演示如何将私有协议设备接入到物联平台。  

以下以protocol-adapter-sdk-example-with-http为例，示例模拟了第三方平台的一台风扇设备使用泛协议接入SDK接入物联平台上传数据的过程，示例代码开发使用IntelliJ IDEA 2020.1.3 (Ultimate Edition) ，示例中的配置仅供参考，运行时需要修改为您自己的泛协议接入服务的相关配置信息。  
示例项目使用SpringBoot作为开发框架，项目结构如下图所示：

````java
|-- src
   |-- main 
      |-- java 
         |-- com.github.cm.heclouds.adapter
            |-- controller
               |-- HttpController.java               控制层，接收HTTP接口数据
            |-- service
               |-- ProtocolAdapterService.java       处理设备数据，转换为物联平台物模型数据并上传到平台
            |-- ProtocolAdapterDemo.java             程序入口类
         |-- resources
            |-- config
               |-- adapter.conf                      SDK配置
               |-- devices.conf                      设备映射配置
            |-- logback.xml                          自定义日志配置
                
|-- pom.xml
````

本示例定义了一种简单的仅供测试使用的自定义HTTP接口：

**请求地址**

> iotjr.tsinghua.edu.cn:1667

**请求方法**  

> Post

**请求头**  

<table style="text-align: left">
    <tr>
        <td width="20%">参数名称</td>
        <td width="20%">类型</td>
        <td width="20%">是否必选</td>
        <td>描述</td>
    </tr>
    <tr>
        <td>Token</td>
        <td>String</td>
        <td>是</td>
        <td>鉴权用Token，示例中默认为cmiot</td>
    </tr>
    <tr>
        <td>DeviceName</td>
        <td>String</td>
        <td>是</td>
        <td>设备名，示例中作为唯一标识</td>
    </tr>
</table>

**请求Body**  

> JSON格式

````json
{
    "type": 2,
    "data": {
        "status": 1,
        "gear": 3,
        "duration": 20000
    }
}
````

<table style="text-align: left">
    <tr>
        <td width="20%">参数名称</td>
        <td width="20%">类型</td>
        <td width="20%">是否必选</td>
        <td>描述</td>
    </tr>
    <tr>
        <td>type</td>
        <td>Integer</td>
        <td>是</td>
        <td>操作类型，1-上线，2-上传数据，9-下线</td>
    </tr>
    <tr>
        <td>data</td>
        <td>JsonObject</td>
        <td>否</td>
        <td>上传的具体数据，type=1或3时可为空，type=2时必填</td>
    </tr>
    <tr>
        <td>status</td>
        <td>Integer</td>
        <td>否</td>
        <td>电风扇状态：0-关，1-开</td>
    </tr>
    <tr>
        <td>gear</td>
        <td>Integer</td>
        <td>否</td>
        <td>电风扇档位：1-低速，2-中速，3-高速</td>
    </tr>
    <tr>
        <td>duration</td>
        <td>Long</td>
        <td>否</td>
        <td>电风扇已开启持续时间：单位ms</td>
    </tr>
</table>

**返回数据**  

<table style="text-align: left">
    <tr>
        <td width="20%">参数名称</td>
        <td width="20%">类型</td>
        <td>描述</td>
    </tr>
    <tr>
        <td>id</td>
        <td>String</td>
        <td>消息id号</td>
    </tr>
    <tr>
        <td>code</td>
        <td>Integer</td>
        <td>结果状态码</td>
    </tr>
    <tr>
        <td>msg</td>
        <td>String</td>
        <td>错误信息</td>
    </tr>
</table>

**1. 修改配置文件**  

1).新建并修改src/main/resources/config文件夹下的adapter.conf和device.conf文件：

![config-sample-http-1.0.4](/images/device-management/fxy-cloud-dock/config-sample-http-1.0.4.png)

![config-sample2-http-1.0.4](/images/device-management/fxy-cloud-dock/config-sample2-http-1.0.4.png)

2).新建程序入口类ProtocolAdapterDemo.java。

**2. 开发业务代码，启动SDK服务**  

1).编写HttpController.java，开发HTTP接口，可参见[SpringBoot官网文档](https://spring.io/guides/gs/rest-service/) ；  
2).编写ProtocolAdapterService.java，解析上述JSON数据，实现设备登录登出和数据上传。

第三方云平台设备数据上传到示例项目后，首先应建立与设备的映射，返回物联平台设备实体Device，这是进行后续业务上行操作的先决条件。  

````java
// 设备映射关系的配置默认使用文件配置，同时也可参考protocol-adapter-sdk-example-config示例自主实现
Device device = deviceConfig.getDeviceEntity(deviceName);
````

3).在ProtocolAdapterDemo.java main方法中配置SDK，初始化配置并启动SpringBoot服务：  

````java
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
````

使用IDEA服务成功启动后可看到如下图所示的日志：  

![start-success-http-1.0.4](/images/device-management/fxy-cloud-dock/start-success-http-1.0.4.png)

同时，可在物联平台上观察到泛协议接入服务在线状态：

![s-adaptor-http-1.0.4](/images\device-management\fxy-cloud-dock\studio-adaptor-http-1.0.4.jpg)

**3. 接入第三方云平台，实现设备登录**  

使用HTTP客户端工具，接入SDK服务，发送type=1的数据，实现设备登陆，如下图所示：

![login-success-http-1.0.4](/images/device-management/fxy-cloud-dock/login-success-http-1.0.4.png)

规定请求头的"DeviceName"字段对应设备映射文件中的"originalIdentity"，即"DeviceName"="fan1"表示物联平台设备

    fan1 {
        # 产品ID
        productId = "AAWCVR5JIx4hG9V3"
        # 设备名称
        deviceName = "test_device"
        # 产品或设备key
        key = "xxxxxxxxxxxxxxx"
    }

您可使用AdapterApi提供的通用API上线设备，以下示例代码在ProtocolAdapterService类中的#uploadProperties(Device, JsonObject)方法中：

    adapterApi.deviceOnline(device);

在物联平台上可观察到接入设备详情及在线状态。

![login-success2-http-1.0.4](/images\device-management\fxy-cloud-dock\login-success2-http-1.0.4.jpg)

**4. 上传设备数据**  

设备登陆后，上传type=2的JSON格式数据，如下图所示：

![upload-prop-http-1.0.4](/images/device-management/fxy-cloud-dock/upload-prop-http-1.0.4.png)

您可使用AdapterApi提供的通用API上传设备属性，以下示例代码在ProtocolAdapterService类中的#uploadProperties(Device, JsonObject)方法中：

````java
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
````

以上代码最终对应上传到平台的物模型OneJSON格式为：

````json
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
````

您可参照物模型OneJSON格式和物模型功能点构造自己的OneJSON，也可参考protocol-adapter-sdk-example-code-generator使用[自动生成物模型相关代码](/book/device-management/fxy-access/sdk-guide/sdkguide.md) 生成的扩展API上传单个设备数据。

![device-info](/images/device-management/fxy-cloud-dock/device-info.png)

从日志中可以看出，设备数据上传成功，同时，在物联平台上可观察到设备最新上传的数据。

**5. 设备登出**  

发送type=3的数据，表示设备登出，调用通用API通知平台接入机主动登出设备：

    adapter.deviceOffline(device);

接口返回登出成功响应。

![logout-http-1.0.4](/images/device-management/fxy-cloud-dock/logout-http-1.0.4.png)

此时在物联平台页面中可观察到设备已经离线：

![device-offline](/images/device-management/fxy-cloud-dock/device-offline.png)

