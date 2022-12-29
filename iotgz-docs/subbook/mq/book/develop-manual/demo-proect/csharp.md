# demo 工程

本文主要以 **C#** 为例，面向初次接触OneNET消息队列MQ的开发者，演示如何搭建测试工程

## 准备条件

- 请确认本地已经安装Visual Studio 2017以上版本，若未完成，请先安装
- 请确认已经正确开通消息队列MQ服务并创建服务资源，若未完成，请参考入门手册完成服务开通与资源创建

## 下载 demo 工程

[下载demo工程](/images/tools/MQDemo-CSharp-src-20190805.zip)并解压，解压后可以看到本地新增了MQDemo-CSharp-src文件夹


## 打开 demo 工程

打开 MQDemo-CSharp-src 文件夹，使用 Visual Studio 打开 MQDemo-CSharp.sln

![](/images/mq/demoproj/csharp1.png)


编译该工程（Ctrl+Shift+B）

![](/images/mq/demoproj/csharp2.png)


运行该工程（Ctrl+F5）

![](/images/mq/demoproj/csharp3.png)

## demo 使用示例

**step1**：消息生产，见[消息生产指南](/book/develop-manual/msg-produce.md)，将设备消息转发至消息队列MQ的topic中

**step2**：客户端消息消费，填写 **实例名称**、**topic**、**订阅**、**access-key**（需注意与消息生产进入的topic相关参数保持一致），点击**连接**，提示框显示连接成功

![](/images/mq/demoproj/csharp4.png)

![](/images/mq/demoproj/csharp5.png)

若已经有消息被生产进入消息队列MQ对应topic，Demo客户端将显示已经消费到的消息

 ![](/images/mq/demoproj/csharp6.png)

