# 代理直连设备

<a href="#1">1. 泛协议实例创建</a>

<a href="#2">2. 代理产品创建</a>

<a href="#3">3. 代理设备创建</a>

---

<h3 id="1">1. 泛协议实例创建</font></h3>

在Studio菜单中找到 「设备接入与管理-泛协议接入」菜单，点击进入实例列表页，在列表页可查看到用户的服务ID、实例数量、在线实例数量及实例列表信息，如下图所示：

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/CoAP&MQTT/instance-list.png">
</center>

实例列表中包含每条实例数据的实例名称、实例描述、在线状态、当前接入设备数、创建时间及一些操作按钮。
选择一条实例数据，点击操作中的查看KEY，可以看到实例对应的KEY，该KEY可用于SDK的服务实例鉴权配置。
点击更新KEY，按照页面提示输入短信验证码后，可以对实例KEY进行更新。


点击「添加服务实例」按钮，在弹出页面填写实例名称和实例描述，再点击确定，提交后即可创建一个实例。如下图所示：

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/CoAP&MQTT/new-instance.png">
</center>

<h3 id="2">2. 代理产品创建</font></h3>

在Studio菜单中找到 「设备接入与管理-产品管理」菜单，点击「添加产品」按钮，在弹出页面填写产品名称，选择产品类别，节点类型选择**直连设备**，接入协议选择**其他**,再点击确定，提交后即可创建一个代理产品。如下图所示：

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/CoAP&MQTT/proxy-product.png">
</center>

<h3 id="3">3. 代理设备创建</font></h3>

在Studio菜单中找到 「设备接入与管理-设备管理」菜单，点击「添加设备」按钮，在弹出页面填写设备名称，选择刚才创建的代理产品，再点击确定，提交后即可一个代理设备。如下图所示：

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/CoAP&MQTT/proxy-device.png">
</center>

