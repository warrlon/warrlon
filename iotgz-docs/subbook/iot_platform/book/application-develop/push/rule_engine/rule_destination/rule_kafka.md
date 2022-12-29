# 消息目的地—Kafka推送

<a href="#1">1. 应用场景</a> 

<a href="#2">2. 使用说明</a> 

<a href="#3">3. 操作步骤</a> 

---

<h3 id="1">1. 应用场景</h3>

Kafka推送用于将数据源中的数据发送至客户指定的Kafka集群中，Kafka是一种高吞吐量的分布式发布订阅消息系统，具有消息持久化、高吞吐量、高扩展性等优势，规则引擎中使用Kafka推送需用户提前准备好Kafka集群以及对应Topic。

<h3 id="2">2. 使用说明</h3>

规则引擎配置推送规则前，需要先创建Kafka实例，Kafka推送服务使用流程包括：实例创建、实例验证、规则配置、消息推送，创建实例操作参见[Kafka数据推送](/book/application-develop/push/kafka_push.md)。

<h3 id="3">3. 操作步骤</h3>

- 选择消息目的地为Kafka推送，页面显示当前用户已创建的Kafka实例列表；如果当前用户账号下没有Kafka实例，需要点击链接前往"数据推送“进行配置。

- 当前用户已创建Kafka实例时，选择消息数据需要推送的Kafka实例（实例服务器地址及Topic已通过验证），点击"添加“按钮，规则引擎列表增加一行规则，为启用状态。


<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/application/消息目的地KAFKA-无实例.png">
    <br>
    图1 消息目的地KAFKA-无实例
    <br>
</center>

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/application/消息目的地KAFKA-有实例.png">
    <br>
    图2 消息目的地KAFKA-有实例
    <br>
</center>