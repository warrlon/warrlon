# 最佳实践 - 消息产生与消费
## 消息生产

本例中通过模拟数据上传与规则引擎转发的方式产生消息

### Step 1 配置规则引擎
用户可以通过**规则引擎**将物联网套件中的消息转发至消息队列MQ中

进入**产品详情** -> **规则引擎** -> **添加规则**

![](/images/rule-engine/规则入口.png)

选择消息源为：**设备数据点消息**
![](/images/rule-engine/选择消息源.png)

选择消息目的地为：**消息队列MQ** -> 实例：**mq-for-test** -> topic：**topic-test**，点击**完成**
![](/images/rule-engine/选择消息目的地.png)

### Step 2 生产设备消息
用户可以使用平台的模拟工具产生设备消息，操作如下：

进入**设备列表** -> **数据流** -> **模拟数据**工具

![](/images/mq/example/数据流.png)
![](/images/mq/example/模拟数据.png)

点击**发送数据**，完成消息的模拟产生，规则引擎则会按照配置将该消息转发至对应的topic
![](/images/mq/example/发送数据.png)

## 客户端消费消息

在MQTT.fx客户端，可以查看到当前接收到的数据(/book/application-develop/mq/develop-manual.md)

![](/images/mq/example/客户端接收消息.png)
