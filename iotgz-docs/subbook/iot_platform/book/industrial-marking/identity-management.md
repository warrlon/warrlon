# 标识管理

标识是每一个物联网感知设备在工业互联网标识解析体系下的唯一身份，可通过手动完善和设备自动上报数据的方式实现注册/更新设备标识数据。

在注册标识前首先需要完成企业节点申请、服务托管申请、数据模板配置。

### 设备自动注册标识
标识和设备一一对应，一个设备有且仅有一个唯一的工业互联网标识，进入OneNET Studio设备管理创建设备时，您可以选择是否为设备开启自动注册标识。

开启自动注册标识后，当产品/设备基础属性数据、物模型功能点上报数据、自定义维护数据满足数据模板数据点要求时，将自动为设备注册标识。
<center>
    <img width="100%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/industrial-marking/添加设备注册标识.png">
    <br>
    图1 添加设备注册标识
    <br>
</center>

您也可以在批量导入添加设备时为所有导入设备开启标识自动注册。
<center>
    <img width="100%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/industrial-marking/批量添加设备注册标识.png">
    <br>
    图2 批量添加设备注册标识
    <br>
</center>

### 手动注册标识
对于未开启自动注册标识的设备，可进入到设备详情页“标识管理”Tab栏手动为设备注册标识。

<center>
    <img width="100%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/industrial-marking/手动注册标识.png">
    <br>
    图3 手动注册标识
    <br>
</center>

手动注册标识时，您需要按照设置的数据模板，手动维护必录的标识数据点内容，才可完成标识注册。

### 查看设备标识数据

已经注册了标识的设备，可在设备详情页“标识管理”Tab栏查看已经注册的标识数据。
<center>
    <img width="100%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/industrial-marking/查看设备标识数据.png">
    <br>
    图4 查看设备标识数据
    <br>
</center>
此外您也可以进入到工业标识服务的标识管理菜单页查看对应的标识数据。
<center>
    <img width="100%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/industrial-marking/查看设备标识数据2.png">
    <br>
    图5 查看设备标识数据
    <br>
</center>

### 手动更新设备标识数据

已经注册了标识的设备，若您有手动更新标识数据的需求，您可手动对设备标识数据进行更新。
<center>
    <img width="100%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/industrial-marking/手动更新标识数据.png">
    <br>
    图6 手动更新标识数据
    <br>
</center>

需要注意的是若您需要手动更新标识时，清先关闭标识自动注册功能，否则当设备有新的数据上报时可能会去更新您手动更新的标识数据。
