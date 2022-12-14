<h1 id="1">规则引擎服务概述</h1>

[本页目录]()

[消息源选择](#2)

[消息处理](#3)

[消息转发](#4)

规则引擎是OneNET提供给用户进行数据流转的核心服务。

- 功能：用户可以物联网套件中的设备消息进行筛选与分发。
- 特点：用户可以自定义数据筛选规则，转换数据格式，并将数据转发至后续产品中，从而获得更多的服务.

![](/images/rule-engine/示意图.jpg)

<h2 id="2">消息源选择</h2>

规则引擎支持将物联网套件某产品中的消息进行处理与转发，支持处理的消息源如下：

- 设备数据点消息：设备上传的 **新增数据点消息**；
- 设备生命周期事件：设备生命周期中发生的 **创建**、**删除**、**在线**、**离线** 的事件消息；
- 设备镜像属性更新事件：设备镜像中properties属性更新的事件消息（即将到来）。

<h2 id="3">消息处理</h2>

规则引擎支持通过SQL语句对选择的消息源的json数据内容自定义处理规则。

目前系统消息源均以系统固定 [基础消息格式](/book/manual/rule-engine/dataFormat.md) 输入规则引擎，用户可基于基础消息格式进行自定义SQL编辑，将 json 数据进行提取与重组，自定义[SQL语句](/book/manual/rule-engine/SQL.md)进行消息处理，如下图所示：

![](/images/rule-engine/数据处理示意图.jpg)


<h2 id="4">消息转发</h2>

规则引擎支持将自定义处理过的消息转发至后端服务，目前支持的后端服务如下：

- 消息队列 MQ
    
    高性能、高可用的消息中间件，便于应用服务稳定高效获取设备消息。

- 短信服务 SMS

    触发包含自定义参数的固定模板短信。

- 存储服务（即将到来）

    基于MySQL数据库的数据存储服务。


