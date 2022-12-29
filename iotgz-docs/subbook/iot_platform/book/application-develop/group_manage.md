# 分组管理

<a href="#1">1. 创建分组</a> 

<a href="#2">2. 分组详情</a> 

<a href="#3">3. 分组查询</a> 

<a href="#4">4. 删除分组</a> 

<a href="#5">5. 规则引擎使用分组</a>

---

项目提供设备分组功能，用于在单个项目下实现自定义的设备资源组合及分组权限控制。例如某个市级智慧工地项目包含100个工地，每个工地可作为一个分组，通过分组的资源管理及权限控制，满足该项目的不同业务权限管理及区域监管功能。

<h3 id="1">1.创建分组</h3>

进入某个项目的管理页面，展开菜单栏中的「设备管理」，点击「分组管理」，进入分组列表页面。该列表展示当前项目下已经添加的分组，如图1所示。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/application/分组列表.png">
    <br>
    图1 分组列表
    <br>
</center>

点击列表右上角「添加分组」，输入分组名称及分组描述，完成分组创建，如图2所示。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/application/添加分组.png">
    <br>
    图2 添加分组
    <br>
</center>

<h3 id="2">2.编辑分组</h3>

分组创建完成后，点击列表「查看详情」，进入分组详情页面。分组详情页面提供分组基础信息、分组标签及分组设备的管理功能。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/application/分组管理_分组详情.png">
    <br>
    图3 分组详情
    <br>
</center>

 #### 分组基础信息
 
 基础信息包括分组名称、分组ID、分组key等描述信息，其中分组描述支持编辑功能，其他字段不可编辑。

#### 分组标签

分组标签用于描述分组场景、地域等特有信息及分组设备的一些共有特性。单个分组最多可添加20组标签，每组标签包括两个字段，标签key和标签value，标签key可看作标签的名称或类别，标签value则表示其类别的具体值。

#### 分组设备管理

分组设备管理支持设备的动态添加和移除，如果需要在项目下重新划分设备资源，只需将设备添加进自定义分组即可。目前每个设备只能被添加进一个分组，当设备从分组移除后，可重新加入其他分组。

- ##### 添加设备

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/application/分组管理_添加设备.png">
    <br>
    图4 分组添加设备
    <br>
</center>

- ##### 移除设备

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/application/分组管理_移除设备.png">
    <br>
    图5 分组移除设备
    <br>
</center>

<h3 id="3">3.查询分组</h3>

在分组列表页面，输入分组名称、标签key、标签value进行查询，这三个查询条件可以叠加筛选，如图5所示。如果只输入了标签value而未输入标签key不能进行查询操作，但标签key可以作为单独的搜索条件进行查询。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/application/分组管理_分组查询.png">
    <br>
    图6 分组列表
    <br>
</center>

<h3 id="4">4.删除分组</h3>

分组列表页面点击「删除分组」，如果该分组下没有设备，点击二次确认，即可删除当前分组；如果该分组下有设备，则需要将设备从当前分组移除后才能成功删除分组。

<h3 id="5">5.规则引擎使用分组</h3>

规则引擎可基于项目分组进行数据推送。配置推送规则时，筛选范围选择指定分组，从已创建的分组列表中选择需要推送的数据范围，完成规则配置后，应用服务器即可获取所选分组下的应用及设备数据。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/application/分组管理_规则引擎配置.png">
    <br>
    图7 规则引擎使用分组
    <br>
</center>

分组删除后，如果该分组被规则引擎所使用，则规则引擎自动更新推送规则，移除该分组数据，如果被删除的这个分组是规则引擎里的唯一一个分组，则规则引擎自动禁用，同时在页面提示禁用原因。