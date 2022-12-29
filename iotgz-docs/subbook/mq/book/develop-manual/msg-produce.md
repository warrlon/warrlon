# 消息队列MQ 消息生产指南

消息队列MQ目前仅支持通过物联网套件中的 **规则引擎** 作为消息的生产者生产消息

用户可用过进入**物联网套件** -> **产品详情** -> **规则引擎**，通过添加规则，将产品下的设备数据点、设备生命周期事件等消息转发至某实例的topic中，流转全过程如下图所示：

![](/images/mq/消息流转MQ示意图.png)

流转过程包括：

- 设备终端接入OneNET平台不同的产品套件，上传设备消息至OneNET平台
- 开通消息队列MQ服务，创建消息队列MQ实例，添加topic和sub
- 选择不同的 [**数据源**](https://open.iot.10086.cn/doc/mqtt/book/manual/rule-engine/dataFormat.html) 配置规则引擎和消息目的地，自定义 [**SQL规则**](https://open.iot.10086.cn/doc/mqtt/book/manual/rule-engine/SQL.html) 对消息数据进行过滤，将消息转发到消息队列MQ。更多内容请参考 [**规则引擎**](https://open.iot.10086.cn/doc/mqtt/book/manual/rule-engine/introduce.html)
![](/images/rule-engine/规则入口.jpg)

- 应用服务端订阅MQ进行消费，实现业务处理

