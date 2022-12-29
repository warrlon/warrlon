# demo 工程

本文主要以 **Java** 为例，面向初次接触OneNET消息队列MQ的开发者，演示如何搭建测试工程

## 准备条件

- 请确认本地已经正确安装 JDK 与 IDE 环境，若未完成，请先下载安装
- 请确认已经正确开通消息队列MQ服务并创建服务资源，若未完成，请参考快速入门完成服务开通与资源创建

## 下载 demo 工程

[下载demo工程](/images/tools/OneNET-MQ-demo-20200119.zip) 并解压，解压后可以看到本地新增了OneNET-MQ-demo文件夹


## 配置 demo 工程

1. 在 IDE（以 Eclipse 为例）中，选择 File -> Import，选择 Import 类型为 _Existing Maven Projects_

    ![](/images/mq/demoproj/import.png)

2. 点击 Next，点击 Browse，选择解压后的OneNET-MQ-demo文件夹

    ![](/images/mq/demoproj/rootdirectory.png)

3. 点击 Finish，完成工程导入

    demo 工程导入时需要加载依赖的jar包，整个导入过程需要等待约1分钟


## 配置 demo 变量

请按照如下说明，根据在平台创建的资源参数，修改 MqClient.java 中的 MqClient 类

demo中45 - 47行：
```java
String userName = "您的MQ实例名称";
String mqTopic = "您创建的topic名称";
String mqSub = "您创建的订阅名称";
```
81 - 83行：
```java
String userName = "您的MQ实例名称";
String accessKey = "您的MQ access_key";
String expirationTime = "您自定义的鉴权参数过期时间";
```

 注：如需手动回复puback，请将 MqClient.java 中 第25行 manualAcks 设置为 true，并在PushCallback类中的messageArrived的接口中手动回复

```java
 private boolean manualAcks = false; 
```

## 运行 demo

配置规则引擎并生产消息，运行 MqClient 类，连接服务并消费队列中的消息，成功后，可以在 console 中观察到成功消费的消息

![](/images/mq/demoproj/消费消息.png)

