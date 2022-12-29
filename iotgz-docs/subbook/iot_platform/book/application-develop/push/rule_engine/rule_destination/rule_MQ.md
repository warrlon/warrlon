# 消息目的地—消息队列MQ

<a href="#1">1. 应用场景</a> 

<a href="#2">2. 使用说明</a> 

<a href="#3">3. 操作步骤</a> 

---

<h3 id="1">1. 应用场景</font></h3>

消息队列MQ为平台推出的消息中间件服务，具有低时延、高并发、高可用的特点，支持实时消息推送、消息路由与离线存储，适用于智能家居、共享单车、共享设备等多种行业应用中，满足实时控制及高性能服务需求。

<h3 id="2">2. 使用说明</font></h3>

规则引擎配置推送规则前，需要先购买消息队列MQ实例，并创建实例、主题和订阅实体，创建实例操作参见[消息队列](/book/transfer/mq_introduce.md)。

<h3 id="3">3. 操作步骤</font></h3>

- 选择消息目的地为MQ实例，页面显示当前用户已创建的MQ实例列表；如果当前用户账号下没有MQ实例，需要点击链接前往"消息队列MQ"进行配置。

- 当前用户已创建MQ实例时，选择消息数据需要存入的MQ实例和Topic，点击"添加“按钮，规则引擎列表增加一行规则，为启用状态。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/application/消息目的地MQ-无实例.png">
    <br>
    图1 消息目的地MQ-无实例
    <br>
</center>

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/application/消息目的地MQ-有实例.png">
    <br>
    图2 消息目的地MQ-有实例
    <br>
</center>



