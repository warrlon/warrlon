# 应用开发流程概述

<a href="#1">1. 新建项目</a> 

<a href="#2">2. 添加设备</a> 

<a href="#3">3. 应用开发</a> 

---

项目是应用开发的基础，可实现跨产品的资源整合及协同管理。其开发流程如图所示

<h3 id="1">1.新建项目</h3>

对于项目集成商，可通过创建项目，并为项目添加设备，实现对设备资源的集中管理及应用开发。

点击导航栏“应用开发”，进入项目列表页面，点击右上角“添加项目”按钮，填写项目基本信息，完成项目创建，如图1所示。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    <!-- src="/images/iot_platform/application/新建项目.png">
    <br>
    图 1 新建项目
    <br>
</center>

<h3 id="2">2.添加设备</h3>

项目列表页面，点击列表“进入项目管理”按钮，进入单项目管理页面。点击左侧导航栏“设备管理”->“设备列表”，页面显示当前项目集成的设备信息，用户可通过“添加设备”按钮，将账户下未关联项目的设备添加至项目中。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/application/添加设备.png">
    <br>
    图 2 设备添加
    <br>
</center>

<h3 id="3">3.应用开发</h3>

设备关联项目后，可进行后续应用开发。平台提供应用API、规则引擎、数据推送、消息队列、场景联动等应用功能。

- [应用API](/book/api/introduce.md)

提供项目、设备、服务等云端API，帮助快速开发应用，满足场景业务需求。

- [规则引擎](/book/application-develop/project_manage/rule_introduce.md)

支持灵活规则，对项目下设备、应用数据进行筛选过滤，并将数据转发至后续通信组件。

- [数据推送](/book/application-develop/push/http_push.md)

通过HTTP/HTTPS请求方式，将项目下设备数据、应用数据推送给应用服务器。

- [消息队列](/book/transfer/mq_introduce.md)

低时延、高并发、高可用的通信组件，可将设备消息高效可靠传递到应用服务器。

- [场景联动](/book/application-develop/scene/scene.md)

支持设备、时间、第三方数据等维度触发条件，并可执行设备或API动作，实现场景联动。
