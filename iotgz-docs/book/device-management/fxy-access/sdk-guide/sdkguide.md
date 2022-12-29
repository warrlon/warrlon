# **SDK开发指南**  

泛协议接入服务SDK使用Java语言开发，使用Netty 4搭建开发框架、Maven构建项目和管理依赖。

#### **1. 准备工作**  

- 在物联平台上创建并配置了产品（创建产品时接入协议请选择其它）和设备信息；
- 已创建泛协议服务实例，参见 [代理直连设备](/book/device-management/fxy-access/agent-direct-link-device/agentdirectlinkdevice.md)；  
- 本地已正确安装JDK（JDK版本要求最低为JDK 1.8）；  
- 安装IDE（推荐使用IntelliJ IDEA）和TCP测试工具  。

#### **2. 安装SDK（以Maven为例）**  

泛协议接入SDK与Apache Maven 3.2或更高版本兼容。如果尚未安装Maven，您可以参考 Maven 上的说明进行操作。泛协议接入SDK依赖关系使用的groupId为com.github.cm-heclouds，通常，您的Maven POM文件从protocol-adapter-parent项目中继承，目前SDK依赖最新版本号为1.0.4。  
以下清单显示了一个典型的pom.xml文件（不包含程序打包相关插件）：  

````xml
<?xml version="1.0" encoding="UTF-8"?>
<project xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xmlns="http://maven.apache.org/POM/4.0.0"
         xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 http://maven.apache.org/xsd/maven-4.0.0.xsd">
    <modelVersion>4.0.0</modelVersion>

    <artifactId>protocol-adapter-sdk-example-with-tcp-protocol-hub</artifactId>
    <version>1.0.0</version>
    <description>泛协议接入SDK使用示例</description>

    <parent>
        <groupId>com.github.cm-heclouds</groupId>
        <artifactId>protocol-adapter-parent</artifactId>
        <version>1.0.4</version>
    </parent>

    <dependencies>
        <dependency>
            <groupId>com.github.cm-heclouds</groupId>
            <artifactId>protocol-adapter-sdk</artifactId>
        </dependency>
        <dependency>
            <groupId>com.github.cm-heclouds</groupId>
            <artifactId>protocol-adapter-protocolhub-tcp</artifactId>
        </dependency>
        <dependency>
            <groupId>com.github.cm-heclouds</groupId>
            <artifactId>thing-model-code-generator</artifactId>
        </dependency>
    </dependencies>
</project>
````

#### **3. 配置服务及设备映射关系**  

按照以下步骤来进行配置，其中当您使用适配SDK时需要配置（1）、（2），当您使用TCP协议站时需要配置（3）。

（1）.配置泛协议服务相关信息：  

新建并将已开通的泛协议接入服务ID（serviceId）和实例相关信息填入src/main/resources/config路径下adapter.conf文件。本示例的配置如下，服务端口被设置为10086，使用非加密通道的方式接入平台。  

<div align=center><img src ="/images/device-management/fxy-sdk/project-structure1-1.0.4.png"/></div>

（2）.配置文件相关信息：  

新建并将已申请的物联平台设备信息按照提示填入src/main/resources/config路径下devices.conf文件。实例中"device"字符串为您真实设备的唯一标识（可以是设备SN、MAC等，您可以自行定义）。

<div align=center><img src ="/images/device-management/fxy-sdk/project-structure2-1.0.4.png"/></div>

（3）.配置TCP协议站相关信息：  

新建并将TCP协议站启动地址和启动端口按照提示填入src/main/resources/config路径下protocolhub-tcp.conf文件。  

<div align=center><img src ="/images/device-management/fxy-sdk/project-structure3.png"/></div>

> 说明：SDK支持泛协议接入服务配置和设备映射关系配置自定义实现，如数据库读取等，只需实现泛协议接入服务配置>信息读取接口或设备映射关系配置信息读取接口，接口文件位置：
````
src/main/java/com/github/cm/heclouds/adapter/config/IAdapterConfig.java以及src/main/java/com/github/cm/heclouds/adapter/config/IDeviceConfig.java
````
>同理，您也可以自定义实现TCP协议站配置。

#### **4. 生成功能点上报和接收方法 (可选)**  

除了提供通用API外，泛协议接入SDK还提供了自动生成功能点相关的上报和接收方法，同时会为功能点自动生成Java类。

使用方法：

（1）.您需要先引入物模型代码生成工具相关依赖：

````java
<dependency>
    <groupId>com.github.cm-heclouds</groupId>
    <artifactId>thing-model-code-generator</artifactId>
    <version>1.0.4</version>
</dependency>
````

（2）.您需要在产品详情页中导出物模型文件，将物模型文件保存在项目src/main/resources/中的任一位置，在示例代码中，物模型文件保存在项目src/main/resources/config文件夹下；

（3） .直连设备和网关设备：在任一类的类名上方增加@ThingModelConfiguration注解，填入物模型文件(文件名应为model-${pid}.json)相对于resources文件夹的路径，支持填入多个物模型文件，文件之间使用逗号隔开，如 @ThingModelConfiguration({"config/model-AAWCVR5JIx4hG9V3.json"})；

（4）.子设备：在任一类的类名上方增加@@ChildDevThingModelConfiguration注解，填入物模型文件(文件名应为model-${pid}.json)相对于resources文件夹的路径，支持填入多个物模型文件，文件之间使用逗号隔开，如 @@ChildDevThingModelConfiguration({"config/model-Lu4Qiz60x3.json"})；

（5）.使用Maven Compile编译项目(maven命令为mvn compile)或点击Build – Build Project，建议在每次compile之前先清除编译文件(maven命令为mvn clean)，建议使用mvn clean compile命令进行编译；

（6）.编译完成后会在target/generated-sources/annotations文件夹下类名为Thing+${pid}.java，类结构如下图所示：

<div align=center><img src ="/images/device-management/fxy-sdk/model-code-generation-1.0.4.png"/></div>

您可以直接使用其中的API及常量。

#### **5. 实现业务功能**  

当您使用TCP协议站时需实现com.github.cm.heclouds.adapter.protocolhub.tcp.custom包中的TcpDeviceUpLinkHandler.java接口用以支持处理自定义协议数据的上行业务处理以及自定义协议设备断开连接时的业务处理：

- 初始化设备信息：#initDevice(Object, Channel)；  
- 上行业务处理：#processUpLinkData(Device, Object, Channel) ； 
- 自定义协议设备连接断开：#processConnectionLost(Device, Channel)。

当您使用适配SDK时需实现com.github.cm.heclouds.adapter.handler包中DownLinkRequestHandler.java接口用以支持平台接入机下行数据的业务处理。

详细使用方法可参考Javadoc和示例代码。

#### **6. 配置并初始化**  

（1）.配置并初始化SDK：

首先，您需要对SDK进行配置，即需要先实例化Config类，如：

    Config config = new Config(logger);

Config配置参数说明如下，详细使用方法可参考示例代码：

- logger：日志系统，默认使用FileLogger，如使用自定义日志系统，应首先配置此项； 
- adapterConfig：泛协议接入服务和平台配置，默认使用AdapterFileConfig读取src/main/resources/config路径下adapter.conf文件中配置的相关参数。注意后配置此项会覆盖已配置的泛协议接入服务和平台相关配置； 
- name：SDK模块名称，用于默认日志打印，默认为”SDK”， 注意后配置此项会覆盖已配置的SDK模块名称； 
- connectionHost：平台接入机地址，支持ipv4和ipv6，默认为ipv4地址。注意后配置此项会覆盖已配置的平台接入机地址；
- serviceId：泛协议接入服务ID，后配置此项会覆盖已配置的泛协议接入服务ID ； 
- instanceName：泛协议接入服务实例名称，后配置此项会覆盖已配置的泛协议接入服务实例名称； 
- instanceKey：泛协议接入服务实例key，后配置此项会覆盖已配置的泛协议接入服务实例key；
- enableTls：是否开启和平台接入机之间加密传输功能，默认为false，后配置此项会覆盖此前的配置；
- enableMetrics：是否启用统计功能，默认为true，后配置此项会覆盖此前的配置；  
- enableCtrlReconnect：SDK和平台的控制连接断开后是否重连，默认为false，后配置此项会覆盖此前的配置； 
- ctrlReconnectInterval：SDK控制连接异常断开后的初始重连等待时间（默认值：30，单位：秒），重连失败后等待时间会呈指数级逐渐增加，若重连成功，则等待时间重置为初始重连等待时间，此参数仅当ctrReconnect为ture时生效，后配置此项会覆盖此前的配置； 
- deviceConfig：设备映射关系配置，默认为使用DeviceFileConfig读取src/main/resources/config路径下devices.conf文件中配置的相关参数；
- downLinkRequestHandler：下行数据业务处理，非必填，默认实现仅打印日志。

然后，您需要初始化实例化后的Config使相关配置生效，示例代码如下:  

    config.init();

（2）.配置并初始化TCP协议站

首先，您需要对TCP协议站进行配置，即需要先实例化TcpProtocolHubConfig类，以后续章节示例代码中的自定义协议编解码为例，如：

    TcpProtocolHubConfig protocolHubConfig = new TcpProtocolHubConfig(logger) {
        @Override
        public void addChannelHandlers(ChannelPipeline pipeline) {
            pipeline.addLast(new TvlDecoder())
                        .addLast(TvlEncoder.INSTANCE);
        }
    };

TcpProtocolHubConfig配置参数说明如下，详细使用方法可参考示例代码：

- logger：日志系统，默认使用FileLogger，如使用自定义日志系统，应首先配置此项，注意，SDK和协议站配置默认统一使用SDK和协议站配置中首先配置的日志系统；  
- addChannelHandler(ChannelPipeline)：抽象方法，您需要实现此方法配置数据编解码器，将“入站”数据和“出站”数据转换成特定的数据类型； 
- tcpProtocolHubConfig：TCP协议站配置，默认使用TcpFileConfig读取src/main/resources/config路径下protocolhub-tcp.conf文件中配置的相关参数。注意后配置此项会覆盖已配置的TCP协议站相关配置； 
- name：TCP协议站模块名称，用于默认日志打印，默认为”TCPHub”， 注意后配置此项会覆盖已配置的TCP协议站模块名称；  
- host：TCP协议站启动地址，非必填， 注意后配置此项会覆盖已配置的TCP协议站启动地址； 
- port：TCP协议站启动端口，非必填，默认为10086，注意后配置此项会覆盖已配置的TCP协议站启动端口； 
- tcpDeviceUpLinkHandler：上行数据业务处理，必填。

然后，您需要初始化实例化后的TcpProtocolHubConfig使相关配置生效，示例代码如下：

    protocolHubConfig.init();

#### **7. 打包部署**  

您可以使用IDE中集成Maven工具，或使用mvn package命令进行打包操作。您可以参考示例代码工程POM文件中提供的打包插件对工程项目进行打包，为便于您对SDK的配置进行修改，示例代码中将打包资源文件（resources）与jar包分离，打包后工程目录结构如下图所示：

<div align=center><img src ="/images/device-management/fxy-sdk/package.png"/></div>

#### **8. 其它说明**  

- 日志系统、SDK配置、设备映射关系配置、TCP协议站配置均提供默认的基于文件的实现，当您使用默认实现时可以手动填入这些配置的文件位置或使用其默认文件位置，值得注意的是，这些默认实现都使用了单例模式，这也表明了其被实例化后配置的文件位置不可更改；  
- 当您使用日志系统的默认实现，在使用日志默认配置即泛协议接入SDK内置的logback-default.xml配置时，日志文件位置为工程（使用IDE调试时）或jar包（使用java命令运行时）当前./logs/protocol-adapter文件夹下，您可以通过编写自己的logback配置来更改日志文件位置和其它设置；  
- 使用默认设备映射关系配置，即使用DeviceFileConfig读取config/device.conf文件时，支持device.conf文件的动态更新。注：当使用IDE调试时，读取的应是target/resources/config/device.conf ；  
- SDK配置文件和物模型文件不支持动态更新。



