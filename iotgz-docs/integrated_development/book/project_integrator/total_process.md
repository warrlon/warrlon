# 整体使用流程
本页目录

<a href="#1">1. 创建项目</a> 

<a href="#2">2. 获取产品</a> 

<a href="#3">3. 设备管理</a> 

<a href="#4">4. 服务端订阅设备消息</a> 

<a href="#5">5. 下发命令到设备</a> 

---

使用行业开发平台实现跨账户跨产品的集成，流程如下：


<h3 id="1"><font color="#66CDAA">1. 创建项目</font></h3>

对于项目集成商，可通过行业开发平台创建项目，并为指定项目导入平台上他人的产品，若你同时是设备生产商，创建项目后可以为指定项目导入自己的产品和他人的产品。

[点击此处](/book/project_integrator/create_project.md)了解项目创建和产品获取的流程以及注意事项。

点击导航栏的“项目集成”，进入项目列表页面，点击右上角“新建项目”按钮，填写项目基本信息，完成项目创建，如图1所示。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/新建项目.png">
    <br>
    图 1 新建项目
    <br>
</center>

<h3 id="2"><font color="#66CDAA">2. 获取产品</font></h3>

左侧导航栏中点击**设备管理&#10142;产品获取**，进入项目的产品集成页面，支持导入我的产品、获取他人产品功能，并且支持通过产品来源、审批状态进行筛选，如图2所示。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/产品获取.png">
    <br>
    图 2 获取产品
    <br>
</center>

<h3 id="3"><font color="#66CDAA">3. 设备管理</font></h3>

“设备列表”是当前项目下的设备列表，支持设备状态、激活时间、产品ID、设备SN的搜索，如图3所示。

[点击此处](/book/project_integrator/device_manage2.md)了解设备管理详情。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/项目集成_设备列表.png">
    <br>
    图 3 设备列表
    <br>
</center>

<h3 id="4"><font color="#66CDAA">4. 服务端订阅设备消息</font></h3>

对于项目集成商，将产品关联到项目后，可以进行相应的应用开发。

[点击此处](/book/project_integrator/application_develop.md)了解应用开发过程。

进入项目详情，点击**应用管理&#10142;应用服务**，目前平台支持消息队列、设备联动、应用托管加入项目的应用开发，如图4所示。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/应用服务.png">
    <br>
    图 4 应用服务
    <br>
</center>

在本平台配置规则引擎，分发到用户在的消息队列实例和topic上，若还没有创建可以跳转到MQ去创建。具体MQ使用见：
https://open.iot.10086.cn/doc/book/application-develop/mq/introduce.html

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/应用服务_消息队列.png">
    <br>
    图 5 消息队列MQ
    <br>
</center>

<h3 id="5"><font color="#66CDAA">5. 下发命令到设备</font></h3>

对于项目集成商，可以使用平台提供的调试工具进行命令下发，如图6所示。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/应用调试.png">
    <br>
    图 6 应用调试
    <br>
</center>

<div>
    <a href="/book/equipment_manufacturer/device_authorization.md">
        <span> &#171; 上一篇：设备生产商_授权管理</span>
    </a>
</div>
<div>
    <a href="/book/project_integrator/create_project.md">
        <span> &#187; 下一篇：项目集成商_创建项目和集成产品</span>
    </a>
</div>