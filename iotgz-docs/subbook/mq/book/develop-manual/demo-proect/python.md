# demo 工程

本demo主要以 **python** 为例，面向初次接触OneNET消息队列的开发者，演示如何一步一步搭建测试工程

## 准备条件

- 请确认本地已经正确安装 python 环境，若未完成，请先下载安装
- 请确认已经正确开通消息队列MQ服务并创建服务资源，若未完成，请参考入门手册完成服务开通与资源创建

## 下载 demo 工程

[下载demo工程](/images/tools/OneNET-MQ-Demo-Python-20190830.zip)并解压，解压后可以看到本地新增了OneNET-MQ-Demo-Python文件夹

## 配置 demo 工程

1、在IDE(已JetBrains PyCharm为例)，选择File->Open,打开解压的OneNET-MQ-Demo-Python文件夹  

![](/images/mq/demoproj/py1.png)

2、修改demo中的变量，根据在平台创建的资源参数，修改mq_recv_client.py文件第102行-105行。

![](/images/mq/demoproj/py3.png)

```python
access_key = '您的MQ access_key'   
namespace = '您的MQ实例名称'   
topic_name1 = '您创建的topic名称'   
sub_name1 = '您创建的订阅名称' 
```

## 运行 demo 工程

**step1**：消息生产，见[消息生产指南](/book/develop-manual/msg-produce.md)，将设备消息转发至消息队列MQ的topic中

**step2**：消息消费，运行mq_recv_client.py中main函数，连接服务并消费队列中的消息，成功后，可以在 console 中观察到成功消费的消息
![](/images/mq/demoproj/py2.png)

