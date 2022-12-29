# 最佳实例

本文将通过实例介绍如何通过**MQTT.fx**连接并消费MQ消息。

[MQTT客户端下载](http://mqttfx.jensd.de/index.php/download)

## MQ服务开启与配置

- 按照[入门手册](/book/easy-manual/MQ.md)介绍，开通MQ服务并创建topic，创建订阅
- [配置规则引擎](/book/easy-manual/rule-engine/config.md)，将设备消息转发至消息队列中

本例中，topic名为：test，订阅名为：sub123

## MQTT.fx客户端配置

### Step 1 客户端配置
打开MQTT.fx客户端，进入客户端配置页面，
![](/images/mq/example/客户端配置入口.png)

设置**Profile Name**，本例中为test-mq

设置接入地址与端口，并设置**username**与**password**，其中：

username设置为MQ_ID，password见[安全鉴权](/book/easy-manual/auth.md)，本例中：password示例如下：

    version=2018-10-31&res=mqs%2FA18F3248E9306BE160C6E95BFEE5B257F&et=1548643432&method=sha1&sign=S7uiBwW7Pv5%2FfbtGmQI%2F94hLyGw%3D

![](/images/mq/example/MQTT配置.png)

点击**SSL/TLS**进入加密设置

选择**CA certificate file**，导入证书

![](/images/mq/example/证书选择.png)

点击OK，完成配置

### Step 2 客户端连接
点击配置文件选择箭头，选择配置test-mq

![](/images/mq/example/选择配置文件.png)

点击**Connect**，连接MQ服务

### Step 3 订阅并消费数据

选择Subscribe配置，输入订阅名称，订阅命名规则如下：

$sys/pb/consume/**$MQ_ID**/**$TOPIC**/**$SUB**

本例中订阅名称为：
   
    $sys/pb/consume/A18F3248E9306BE160C6E95BFEE5B257F/test/sub123

选择 **QoS1**，点击**Subscribe**

![](/images/mq/example/订阅.png)


## 消息产生与消费

用户可以使用平台的模拟工具产生设备消息，操作如下：

进入**设备列表** -> **数据流** -> **模拟数据**工具

![](/images/mq/example/数据流.png)
![](/images/mq/example/模拟数据.png)

点击**发送数据**，完成消息的模拟产生
![](/images/mq/example/发送数据.png)

在MQTT.fx客户端，可以查看到当前接收到的数据，数据格式见[开发指南](/book/application-develop/mq/develop-manual.md)

![](/images/mq/example/客户端接收数据.png)

## 更多帮助

- [查看更多服务功能介绍](/book/application-develop/mq/introduce.md)
- [了解客户端开发帮助，详情请见开发手册](/book/application-develop/mq/develop-manual.md)
- [查看demo工程使用说明](/book/application-develop/mq/demo-project.md)
- [公测版服务资源使用限制](/book/application-develop/mq/limit.md)



