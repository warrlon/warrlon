# 整体使用流程
本页目录

<a href="#1">1. 创建产品</a> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<a href="#4">4. SDK下载和嵌入式开发</a>  

<a href="#2">2. 功能定义</a> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<a href="#5">5. 设备调试</a>

<a href="#3">3. 生产管理和导入设备</a>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <a href="#6">6. 产品发布</a> 

使用行业开发平台进行设备生产的流程如下：

<center>
    <img src="/images/设备生产.png">
    <br>
    <br>
    图 1 设备生产流程图
</center>

<h3 id="1"> <font color=#CD6839> 1. 创建产品</font></h3>

若您是设备生产商或者设备方案商，为了更好的体验和使用行业开发平台，首先需要在平台上根据页面导引创建您的产品以及在产品下添加设备。

&#9863; 产品：表示具有相同数据模型的一类设备集合。例如，中国移动和目C71智能摄像机，小移智能插座P51，西门子A型开关等。

&#9862; 设备：表示具有唯一识别号（序列号SN，模组为IMEI）的硬件终端在行业开发平台上的设备映射。

[点击此处](/book/equipment_manufacturer/create_produce&device.md)了解产品创建和设备添加的详情以及注意事项。

<h3 id="2"><font color=#CD6839> 2. 产品功能定义</font></h3>

**产品开发的第一个环节**。产品功能定义是用于定义该产品的功能点，每一个功能点对应一个设备的属性，功能点可以分为标准功能点和系统功能点。

例如：热水器设备

&#9786; 基础功能点可以包括设备开关、工作状态、模式、加热容量、当前温度、剩余水量等内容。

&#9787; 系统功能点可以包括故障数、信号强度、经度、纬度、上报成功率、电量、软件版本、固件版本等内容。

行业开发平台支持添加**基础功能点、组合功能点、固定上报功能点**，基础功能点包括设备功能和系统功能两种。

[点击此处](/book/equipment_manufacturer/produce_develop.md)了解产品功能定义的详情以及注意事项。

<h3 id="3"><font color=#CD6839>3. 生产管理和导入设备</font></h3>

完成产品的功能点定义之后，行业开发平台提供产品下的设备管理功能，包括四个管理模块，分别是

**我的设备** 表示当前产品下未交付项目的设备，支持设备SN查询。

**交付设备** 表示产品下已经交付到项目中的设备，支持设备SN查询。

**生产管理** 预导入设备，支持产品白名单、导出产品码、导出设备码、导出产品码功能。

**档案管理** 可以管理设备的档案字段、支持导入档案信息。

[点击此处](/book/equipment_manufacturer/device_manage.md)了解设备管理的详情和特别说明。

<h3 id="4"><font color=#CD6839>4. SDK下载和嵌入式开发</font></h3>

**产品开发的第二个环节**。您需要下载编译环境和设备SDK，每次功能点变更时都需要重新下载设备SDK，然后进行设备开发并接入行业开发平台。

[点击此处](/book/equipment_manufacturer/produce_develop.md)了解设备嵌入式开发流程。

<h3 id="5"><font color=#CD6839>5. 设备调试</font></h3>

完成设备本地开发后可以在平台提供的产品开发环境中进行功能调试。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/设备测试.png">
    <br>
    图 2 设备调试
</center>

<h3 id="5"><font color=#CD6839>6. 产品发布</font></h3>

**产品开发第三个环节**。设备调试结束后，用户确认产品信息，可以进行产品发布，表示该产品已经开发完成，发布后无法修改和删除。

<div>
    <a href="/book/easy-manual/object_model.md">
        <span> &#171; 上一篇：物模型</span>
    </a>
</div>
<div>
    <a href="/book/equipment_manufacturer/create_produce&device.md">
        <span> &#187; 下一篇：设备生产商_创建产品和设备</span>
    </a>
</div>