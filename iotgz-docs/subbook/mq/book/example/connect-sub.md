# 最佳实践 - 客户端连接与订阅

本文将通过实例介绍如何通过**MQTT.fx**连接并消费MQ消息。

[MQTT客户端下载](http://www.jensd.de/apps/mqttfx/1.7.0/)

## MQ服务开启与配置
### Step 1 服务开通与资源创建
添加MQ服务实例并创建topic，创建订阅

本例中：

实例名称为：**mq-for-test**，topic名为：**topic-test**
，订阅名为：**test-sub**

## MQTT.fx客户端配置

### Step 1 客户端配置
打开MQTT.fx客户端，进入客户端配置页面，
![](/images/mq/example/客户端配置入口.png)

设置**Profile Name**，本例中为MQ

设置接入地址与端口，并设置**username**与**password**，其中：

username设置为 **实例名称**，password见[访问鉴权](/book/develop-manual/auth.md)，本例中：password示例如下：

    version=2018-10-31&method=sha1&sign=%2FRdtyYy4l27DUwFKl74sqZelmV0%3D&res=mqs/mq-for-test&et=1564718131

![](/images/mq/example/MQTT配置.png)

点击**SSL/TLS**进入加密设置

选择**CA certificate file**，导入证书

![](/images/mq/example/证书选择.png)

点击OK，完成配置

### Step 2 客户端连接
点击配置文件选择箭头，选择配置文件 **MQ**

![](/images/mq/example/选择配置文件.png)

点击**Connect**，连接MQ服务

### Step 3 订阅并消费数据

选择Subscribe配置，输入订阅名称，订阅命名规则如下：

$sys/pb/consume/**$实例名称**/**$TOPIC**/**$SUB**

本例中订阅名称为：
   
    $sys/pb/consume/mq-for-test/topic-test/test-sub

选择 **QoS1**，点击**Subscribe**，完成MQTT订阅

![](/images/mq/example/订阅.png)

![](/images/mq/example/订阅成功.png)

