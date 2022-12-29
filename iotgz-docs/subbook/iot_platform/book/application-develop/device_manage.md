# 设备管理

<a href="#1">1. 添加设备</a> 

<a href="#2">2. 移除设备</a> 

<a href="#3">3. 查询设备</a> 

---

项目实现跨用户跨产品的设备资源整合，用户可将当前账号下的不同类型设备（自主创建和他人转移）添加至项目中，进行统一管理及应用开发。目前每个设备只能归属于一个项目。

<h3 id="1">1.添加设备</h3>

展开菜单栏中的「设备管理」，点击「设备管理」，进入设备列表页面。点击列表右上方「添加设备」，选择设备添加方式，如果选择指定设备，勾选需要添加进项目的设备信息；如果选择按导入的设备列表添加，可以下载标准模版录入设备信息或者使用设备接入导出的设备文件进行添加；如果选择产品下全部设备，则当前用户该产品下的全部设备将自动添加进项目。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/application/设备管理_添加设备.png">
    <br>
    图 1 添加设备
    <br>
</center>

项目完成设备添加后，设备所属的产品信息也将自动关联到该项目下。展开菜单栏中的「设备管理」，点击「产品列表」，可快速获取项目集成的产品档案信息及物模型功能定义。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/application/设备管理_产品列表.png">
    <br>
    图 2 集成产品列表
    <br>
</center>

<h3 id="2">2.移除设备</h3>

如果当前项目下的设备需要关联至其他项目，需要先进行移除操作。点击设备列表「移除项目」，确认移除操作后，当前项目与设备解除绑定关系，设备即可重新添加至其他项目。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/application/设备管理_移除设备.png">
    <br>
    图 2 移除设备
    <br>
</center>

<h3 id="3">3.查询设备</h3>

设备列表页面展示当前项目下已集成的设备信息，包括设备名称、所属状态、节点类型等基础信息，点击列表「详情页面」，可跳转设备详情页面，查看设备属性功能实时状态、事件及操作记录等数据，快速掌握设备的运行状况。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/application/设备管理_设备列表.png">
    <br>
    图 3 设备列表
    <br>
</center>

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/application/设备管理_设备详情.png">
    <br>
    图 4 设备详情
    <br>
</center>