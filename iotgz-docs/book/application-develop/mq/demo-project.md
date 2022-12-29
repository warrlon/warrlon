# demo工程

本demo主要以 **Java** 为例，面向初次接触OneNET消息队列MQ的开发者，演示如何一步一步搭建测试工程

## 准备条件

- 请确认本地已经正确安装 JDK 与 IDE 环境，若未完成，请先下载安装
- 请确认已经正确开通消息队列MQ服务并创建服务资源，若未完成，请参考[入门手册](/book/easy-manual/MQ.md)完成服务开通与资源创建

## 下载 demo 工程

[下载demo工程](/images/tools/OneNET-MQ-Reconn-demo-20190711.zip)并解压，解压后可以看到本地新增了OneNET-MQ-Reconn-demo文件夹


## 配置 demo 工程

1. 在 IDE（以 Eclipse 为例）中，选择 File -> Import，选择 Import 类型为 _Existing Maven Projects_

    ![](/images/mq/demoproj/import.png)

2. 点击 Next，点击 Browse，选择解压后的OneNET-MQ-demo文件夹

    ![](/images/mq/demoproj/rootdirectory.png)

3. 点击 Finish，完成工程导入

    demo 工程导入时需要加载依赖的jar包，整个导入过程需要等待约1分钟


## 配置 demo 变量

请按照如下说明，根据在平台创建的资源参数，修改 **MqClient.java** 中的 **MqClient** 类

demo中30 - 32行：
```java
String userName = "您的MQ实例名称";
String mqTopic = "您创建的topic名称";
String mqSub = "您创建的订阅名称"; 
```

64 - 66行：
```java
String userName = "您的MQ实例名称";
String accessKey = "您的MQ access_key";
String expirationTime = "您自定义的鉴权参数过期时间";
```

## 运行 demo

运行 MqClient 类，连接服务并消费队列中的消息，成功后，可以在 console 中观察到成功消费的消息

![](/images/mq/demoproj/消费消息.png)


用户可以使用平台的模拟工具产生设备消息，操作如下：

进入**设备列表** -> **数据流** -> **模拟数据**工具

![](/images/mq/example/数据流.png)
![](/images/mq/example/模拟数据.png)

点击**发送数据**，完成消息的模拟产生
![](/images/mq/example/发送数据.png)


## 更多帮助

- [查看控制台使用入门手册](/book/easy-manual/MQ.md)
- [查看更多服务功能介绍](/book/application-develop/mq/introduce.md)
- [了解客户端开发帮助，详情请见开发手册](/book/application-develop/mq/develop-manual.md)
- [查看demo工程使用说明](/book/application-develop/mq/demo-project.md)
- [查看服务使用最佳实例](/book/application-develop/mq/example.md)
- [公测版服务资源使用限制](/book/application-develop/mq/limit.md)