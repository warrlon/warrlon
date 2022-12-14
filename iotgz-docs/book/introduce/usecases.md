# 适用场景

消息队列MQ作为OneNET推出的消息中间件服务，具备设备消息高效可靠传递到应用服务的机制，广泛用于智能家居、共享经济、智慧园区、智慧城市等行业，帮助用户解决消息推送、消息分发等需求，保障用户应用平台与OneNET数据交互即时可靠。


### 实时数据推送

在烟感告警、共享经济等多种涉及到设备消息及时通知与回复的场景中，用户应用系统需要及时获取设备消息。消息队列MQ为应用层获取设备消息提供高效数据通道，实现毫秒级端到端实时数据同步。

![](/images/mq/实时数据推送.png)

以共享经济行业为例，共享充电宝方案商可以通过OneNET实现设备长连接与设备实时命令控制，该方案商的业务系统在获取设备消息时，可以选用 **HTTP推送** 和 **消息队列** 两种方案，而消息队列具有时延低特性，能够杜绝消息丢失现象的发生，可以极大程度地确保数据一致性与完整性。

与OneNET 同为数据推送场景服务的HTTP数据推送服务相比，消息队列MQ具有如下优势：

<table>
<tr><th width="20%"></th><th>HTTP数据推送</th><th>消息队列MQ</th></tr>
<tr><td>消息缓存</td><td>不支持</td><td>支持</td></tr>
<tr><td>集群消费</td><td>需要在应用侧做负载</td><td>支持</td></tr>
<tr><td>消息回溯</td><td>不支持</td><td>支持</td></tr>
<tr><td>多方消费</td><td>不支持</td><td>支持一对多消费模式</td></tr>
<tr><td>时延</td><td>较高</td><td>较低</td></tr>
</table>

### 消息分发

在智慧城市、智慧表计行业中，会有多个应用系统对设备数据有对接需求，这样就需要将同样设备消息分发至不同的应用系统。 消息队列MQ支持一对多消费模式，消息可以被灵活的分发至一个或者多个消费者。

![](/images/mq/消息分发.png)

智慧表计供应商的设备连接至OneNET平台后，设备消息需要对接多个子应用服务系统。当设备上传消息后，关联的应用服务系统可能发生以下动作：
- 表厂应用系统：对设备上传消息建设数据模型，完成数据管理、分析及运维等
- 水务应用系统： 通过设备上传消息获取实时水情等
- 监管应用系统：对设备状态行为进行监控和告警，推送告警消息等

以上的应用服务系统都是各自独立的，不需要等待其他模块的处理结果。由于消息队列支持多方独立消费的特性，可以完全满足该业务场景需求。如果新增业务也对此类消息存在对接需求，只需要订阅消息进行处理即可，对已有的业务没有任何影响。

### 削峰去谷

在智能家居、共享经济、智慧园区等应用场景中，在设备集中使用时会出现短暂的流量波峰，对应用系统产生巨大的冲击压力。消息队列MQ可以缓冲业务波峰，确保消费端业务平稳运行，减少成本投入。

以共享经济方案商为例，其在重大节日期间可能会推出秒杀促销活动，主要业务流程如下：

![](/images/mq/秒杀流程.png)

如果大量的秒杀请求直接发送至应用系统，可能会对系统造成冲击。

![](/images/mq/削峰去谷.png)

在引入消息队列MQ之后，将短时间内产生的秒杀请求消息存储在消息队列中，等到应用系统有能力处理消息时再进行处理，降低了应用系统的处理压力，达到削峰去谷的目的。




