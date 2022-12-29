# 产品开发
本页目录

<a href="#1">1. 功能定义</a> 

<a href="#2">2. 设备开发</a> 

<a href="#3">3. 设备调试</a> 

<a href="#4">4. 产品发布</a> 

---
根据预集成SDK和物模型，实现设备快速接入平台。

<h3 id="1"><font color=#CD6839> 1. 功能定义</font></h3>

用于定义该产品的功能点，每一个功能点对应一个设备的属性，功能点可以分为标准功能点和系统功能点。

例如：热水器设备

&#9786; 基础功能点可以包括设备开关、工作状态、模式、加热容量、当前温度、剩余水量等内容。

&#9787; 系统功能点可以包括故障数、信号强度、经度、纬度、上报成功率、电量、软件版本、固件版本等内容。

如图1所示，从产品列表进入产品详情页，点击**产品开发**，可以添加基础功能点、组合功能点、固定上报功能点，基础功能点包括设备功能和系统功能两种。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/产品开发.png">
    <br>
    图 1 产品开发
    <br>
</center>

**添加基础功能点**：点击右侧**添加标准功能**，如图2所示，标准功能表示平台已经定义好的设备功能，可以直接选择，如图2所示。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/添加标准功能.png">
    <br>
    图 2 添加标准功能
    <br>
</center>

**添加自定义功能**：如果系统提供的标准功能点无法满足产品开发需求，可以点击**添加自定义功能**为该产品配置自定义的功能点，如图3所示。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/添加自定义功能.png">
    <br>
    图 3 添加自定义功能
    <br>
</center>

**添加系统功能**：如图4所示，系统功能为提前制定的功能，如故障率，将用于设备故障统计，输出报表等。添加结果如图5所示。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/添加系统功能.png">
    <br>
    图 4 添加系统功能
    <br>
    <br>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/产品基础功能点列表.png">
    <br>
    图 5 产品基础功能点列表
    <br>
</center>

**添加组合功能点**：组合功能点表示将多个独立功能点组合，进行上报或者下发，点击**组合功能点 &#10142; 添加组合功能**进入**新建组合功能**配置页面，如图6、图7所示。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/新建组合功能.png">
    <br>
    图 6 新建组合功能
    <br>
    <br>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/组合功能点列表.png">
    <br>
    图 7 组合功能点配置结果
</center>

**设置固定上报**：该功能可以配置伴随着基础功能点一起上报的字段，即**全局功能点**，表示会伴随其他功能点一起上报的功能点，配置相关参数后，设备在上报基础功能点的同时，也会固定上报全局功能点。

目前系统提供了两个全局功能点以供使用，分别是“消息ID”和“上报时间”，点击**固定上报&#10142; 添加标准功能**可以进行配置，此外，点击**固定上报&#10142; 添加固定上报**可以自定义全局功能点，此处添加了消息长度作为自定义的全局功能点，如图8所示。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/自定义固定上报功能点.png">
    <br>
    图 8 组合功能点配置结果
    <br>
    <br>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/固定上报功能点列表.png">
    <br>
    图 9 固定上报功能点列表
</center>

<h3 id="2"><font color=#CD6839>2. 设备开发</font></h3>

完成功能定义后,点击页面底部**下一步**，进入**设备开发**环节。

首先需要下载编译环境和设备SDK，每次功能点变更时都需要重新下载设备SDK，设备开发完成，上电后可以在图10所示页面进行功能调试。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/设备测试.png">
    <br>
    图 10 设备开发测试
    <br>
</center>

用户下载sdk并进行设备开发可以参考[SDK使用说明](/book/equipment_manufacturer/sdk_introduce.md)进行设备功能开发。

<h3 id="3"><font color=#CD6839>3. 设备调试</font></h3>

平台提供调试设备工具，如图10所示。用户可以在界面上查看设备上行数据，也可以模拟下行数据。设备连接平台时，平台根据注册码和设备SN自动创建设备。也可以在**设备管理 &#129030; 生产管理**中提前创建好设备。

用户下载sdk并进行设备调试的过程请参考[设备接入平台](/book/equipment_manufacturer/device_connect_platform.md)页面流程的**接入调试**过程介绍。

<h3 id="4"><font color=#CD6839>4. 产品发布</font></h3>

设备调试结束后，用户确认产品信息，可以进行产品发布，表示该产品已经开发完成，发布后无法修改和删除。

<div>
    <a href="/book/equipment_manufacturer/create_produce&device.md">
        <span> &#171; 上一篇：设备生产商_创建产品和设备</span>
    </a>
</div>
<div>
    <a href="/book/equipment_manufacturer/device_connect_platform.md">
        <span> &#187; 下一篇：设备生产商_设备接入平台</span>
    </a>
</div>