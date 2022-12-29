# 应用开发
本页目录

<a href="#1">1. 应用鉴权</a> 

<a href="#2">2. 应用调试</a> 

<a href="#3">3. 应用服务</a> 

---
应用开发包括以下三项内容：

<h3 id="1"><font color="#66CDAA">1. 应用鉴权</font></h3>

**应用管理&#10142;应用鉴权**，包括了项目access_key和masterkey的信息，用于API的调用。点击查看或重置，需要填入向用户绑定的手机发送的验证码才能进行下一步操作，如图1所示。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/应用鉴权.png">
    <br>
    图 1 应用鉴权
    <br>
</center>

<h4>1.1 名词解释</h4>
masterkey：每个项目的主key，拥有最高权限，可对项目下所有设备进行下发命令等操作。

群组key：每个群组代表一批设备的集合，群组key仅拥有这一批设备的操作权限。

access_key：鉴权密钥，不具备操作设备的权限，仅在加密模式下使用API时作为对称加密密钥使用。

> 每个项目仅拥有一个masterkey，但是可以有多个群组key。

<h4>1.2 应用鉴权</h4>
当使用API进行应用开发时，平台根据用户传递的masterkey或者群组key返回一个token，该token根据用户所传递的key类型获取相应的权限即masterkey换取的token可操作项目下所有设备，群组key换取的token仅可操作该群组下的设备。

具体鉴权方式详见[API文档](/book/api/open_api.md)。


<h3 id="2"> <font color="#66CDAA">2. 应用调试</font></h3>

**应用管理&#10142;应用调试**，支持虚拟设备调试和真实设备调试，选择设备相关的信息，启动设备，设备显示连接成功后，可以选择设备功能点进行调试，如图2所示。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/应用调试.png">
    <br>
    图 2 应用调试
    <br>
</center>

<h4>2.1 调试目的</h4>
应用调试用于模拟真实硬件设备的数据交互，可模拟真实设备上报数据。同时，也可以模拟应用执行下发命令、查询功能点状态等操作。即使硬件设备未完成开发，或不在身边也可以进行调试。

<h4>2.2 调试准备</h4>
在进行应用调试前，请确保项目下已有至少一个设备。该设备可以是通过[生产管理](/book/equipment_manufacturer/device_manage.md#3)导入后[授权](/book/equipment_manufacturer/device_authorization.md)到项目中的设备，也可以是通过配网绑定到项目中的设备。

<h4>2.3 使用说明</h4>
如图2所示，应用调试分为两种，分别是：虚拟真实设备和调试真实设备。其中，虚拟真实设备区域模拟设备上报数据，调试真实设备区域模拟应用下发命令。用户选择产品和设备信息后，点击启动设备，设备显示连接成功后，可以选择设备功能点进行调试。

**模拟设备上报**：包括普通功能点上报和事件功能点上报，该区域可以在真实设备尚未开发完成时模拟设
备上报数据

**模拟应用下发**：包括普通功能点下发和查询功能点，该区域可以在应用尚未开发完成时模拟应用下发命令


<h3 id="3"> <font color="#66CDAA">3. 应用服务</font></h3>

**应用管理&#10142;应用服务**，目前支持消息队列、设备联动、应用托管加入项目的应用开发，如图3所示。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/应用服务.png">
    <br>
    图 3 应用服务
    <br>
</center>

#### &#10064; 消息队列

在本平台配置规则引擎，分发到用户的消息队列实例和topic上，若还没有创建可以跳转到MQ去创建。

用户在应用中订阅该topic即可接收设备上报的数据。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/应用服务_消息队列.png">
    <br>
    图 4 消息队列MQ
    <br>
</center>

#### &#9939; 设备联动

支持配置多设备或时间维度的触发及过滤条件，并可执行其他设备或API回调，实现设备联动的场景。

用户可以设置多条设备联动，并可以管理其联动规则和查看触发日志。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/应用服务_设备联动.png">
    <br>
    图 5 设备联动
    <br>
</center>


在**设备联动&#10142;管理**中，设置触发条件、执行动作、执行条件，其中触发条件和执行动作可以通过典型事件来进行快捷设置，如图14所示。

执行动作可以执行设备的下发以及调用API.

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/应用服务_联动管理.png">
    <br>
    图 6 联动管理
    <br>
</center>

#### &#9919; 应用托管服务

提供配套的IaaS资源，OneNET为用户免费提供1核1G的服务器。该服务器根目录下的/mqtt目录默认实现了一个MQ消息接收的客户端，用户配置MQ实例、topic等参数后即可接收消息队列推送的消息。具体使用方式请参见服务器/mqtt目录下的使用指南。

<div>
    <a href="/book/project_integrator/device_manage2.md">
        <span> &#171; 上一篇：项目集成商_设备管理</span>
    </a>
</div>
<div>
    <a href="/book/project_integrator/key_use.md">
        <span> &#187; 下一篇：项目集成商_Key管理</span>
    </a>
</div>