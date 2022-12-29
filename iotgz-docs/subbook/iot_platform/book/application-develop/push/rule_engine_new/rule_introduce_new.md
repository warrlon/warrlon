# 规则引擎

<a href="#1">1. 服务概述</a>

<a href="#2">2. 规则配置</a>

---
<h3 id="1">1. 服务概述</h3>

规则引擎是提供用户进行数据流转的核心服务，用户可自定义规则，对平台设备所有相关数据进行筛选过滤，并将数据转发至平台通信组件，方便上层应用开发。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/application/规则引擎流转示意-新.png">
    <br>
    图 1 规则引擎流转示意
    <br>
</center>

#### 消息源选择

规则引擎支持将平台的设备相关数据进行处理与转发，消息源包括：

* 设备生命周期事件：设备在线、离线事件消息
* 设备物模型数据：设备上报的属性、事件功能点数据
* 设备物模型数据：服务调用响应数据
* 场景联动触发日志：场景联动触发日志信息
* 设备位置数据：设备具体位置信息

#### 消息处理

系统消息源均以固定基础消息格式输入规则引擎，用户通过自定义SQL语句，对基础消息进行提取与重组。

#### 消息分发

规则引擎支持将处理过的消息转发至平台通信组件，目前支持的通信组件如下：

* 消息队列MQ
高性能、高可用的消息中间件，便于应用服务高效稳定地获取设备消息。
* HTTP推送
系统消息以HTTP/HTTPS POST请求的方式，发送给应用服务器。

<h3 id="2">2. 规则配置</h3>

规则引擎流转需要配置消息源（推送消息类型）、条件过滤规则及消息目的地（推送方式）。支持规则直接创建与可视化创建两种方式。

（1）直接添加规则

点击左侧导航栏应用开发下的"规则引擎"，点击"直接添加规则"，配置规则名称、规则描述、消息源、产品筛选、设备范围、查询字段、查询字段、匹配条件以及消息目的地。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/application/规则引擎-直接创建.png">
    <br>
    图 2 规则引擎-直接创建
    <br>
</center>

* 支持选择某一产品下的一个、多个或全部设备。
* 查询字段与匹配条件共同完成SQL语句的定义，见SQL语句说明。

（2）可视化创建规则

点击左侧导航栏应用开发下的"规则引擎"，点击"可视化添加规则"，配置规则名称与规则描述后点击新增按钮，进入可视化规则编排页面。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/application/规则引擎-可视化创建.png">
    <br>
    图 3 规则引擎-可视化创建
    <br>
</center>

支持拖拽的方式将左侧控件添加至画布中，左键点击控件能够对控件详情进行编辑。

消息源控件：需配置消息类型，产品删选，选择字段，选择设备，其中，选择字段中可以对原有字段名进行自定义转换。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/application/消息源控件.png">
    <br>
    图 4 消息源控件
    <br>
</center>

条件过滤控件：配置好消息源控件后，可自定义设置过滤条件，支持AND/OR对各条规则进行组合，同时支持添加自定义条件，在输入框中可以选择内置函数对数据进行处理，具体内置函数支持列表见SQL语句说明文档。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/application/条件过滤控件.png">
    <br>
    图 5 条件过滤控件
    <br>
</center>

* 消息源为场景联动触发日志时，不支持条件过滤。

MQ输出控件：消息队列MQ为平台推出的消息中间件服务，具有低时延、高并发、高可用的特点，支持实时消息推送、消息路由与离线存储，适用于智能家居、共享单车、共享设备等多种行业应用中，满足实时控制及高性能服务需求。

规则引擎配置推送规则前，需要先购买消息队列MQ实例，并创建实例、主题和订阅实体，在控件设置时直接选择用户下的MQ实例和Topic即可。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/application/MQ输出控件.png">
    <br>
    图 6 MQ输出控件
    <br>
</center>

HTTP输出控件：HTTP推送用于实现平台与应用服务器之间的单向数据通信。平台作为客户端，通过HTTP/HTTPS请求方式，将设备数据推送给用户指定服务器。由于HTTP推送对应用服务器的性能及网络有较高要求，因此更适用于中等数据流量及允许一定延时的应用开发场景。

规则引擎配置推送规则前，需要先创建HTTP实例，HTTP推送服务使用流程包括：实例创建、实例验证、规则配置、消息推送。在控件设置时直接选择用户下的HTTP实例即可。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/application/HTTP输出控件.png">
    <br>
    图 7 HTTP输出控件
    <br>
</center>

配置完所有控件后，点击SQL检测按钮，进入SQL预览，以及输出数据模拟检测弹窗，点击测试按钮可以验证配置的规则是否生效。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/application/SQL检测.png">
    <br>
    图 8 SQL检测
    <br>
</center>