# 规则引擎

<a href="#1">1. 服务概述</a>

<a href="#2">2. 规则配置</a>

---
<h3 id="1">1. 服务概述</h3>

规则引擎是提供用户进行数据流转的核心服务，用户可自定义规则，对项目下应用及设备数据进行筛选过滤，并将数据转发至平台通信组件，进行应用开发。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/application/规则引擎流转示意.png">
    <br>
    图 1 规则引擎流转示意
    <br>
</center>

#### 消息源选择

规则引擎支持将项目下的设备数据和应用数据进行处理与转发，消息源包括：

* 设备生命周期事件：设备在线、离线事件消息
* 设备物模型数据：设备上报的属性、事件功能点数据、服务调用响应数据
* 场景联动触发日志：场景联动触发日志信息

#### 消息处理

系统消息源均以固定 基础消息格式 输入规则引擎，用户通过自定义SQL语句，对基础消息进行提取与重组。

#### 消息分发

规则引擎支持将处理过的消息转发至平台通信组件，目前支持的通信组件如下：

* 消息队列MQ
高性能、高可用的消息中间件，便于应用服务高效稳定地获取设备消息。
* HTTP推送
系统消息以HTTP/HTTPS POST请求的方式，发送给应用服务器。

<h3 id="2">2. 规则配置</h3>

规则描述了 数据从哪里来、如何筛选并处理数据、处理数据到哪里去三个参数信息，是规则引擎流转数据的基础配置。点击左侧导航栏的"规则引擎"，点击"添加消息推送规则"，配置规则名称、规则描述、消息源、筛选范围、查询字段、查询字段以及消息目的地。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/application/规则引擎.png">
    <br>
    图1 规则创建
    <br>
</center>

* 筛选范围指定设备数据的获取范围，项目下全部产品设备或指定产品设备。（注：场景联动触发日志不支持筛选范围）。
* 查询字段与匹配条件共同完成SQL语句的定义，见SQL语句说明。
