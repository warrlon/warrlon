# 设备调试

[1.设备模拟器](#1设备模拟器)

[2.应用模拟器](#2应用模拟器)

---

平台提供设备调试功能，解耦设备及应用开发工作。设备调试包括设备模拟器与应用模拟器两种类型，设备模拟器由平台在云端创建虚拟设备，按照真实设备接入流程进行上下行数据模拟，让应用在未获取真实设备的情况下即可进行开发，提升开发效率。应用模拟器则通过模拟应用调用云端API，完成对真实设备的下行功能测试。整体交互流程如图所示：

<center>
    <img width="90%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/设备调试.png">
    <br>
    图1 设备调试流程示意
    </br>
</center>

<table>
  <tr>
    <th>调试类型</th>
    <th>设备类型</th>
    <th>功能说明</th>
  </tr>
  <tr>
    <td rowspan="3">设备模拟器</td>
    <td>直连设备</td>
    <td>支持使用MQTT、CoAP、泛协议的设备模拟，提供属性上报、属性期望获取、属性期望清除、事件上报</td>
  </tr> 
  <tr>
    <td>网关设备</td>
    <td>支持属性上报、属性期望获取、属性期望清除、事件上报、子设备拓扑管理（绑定/解绑）</td>
  </tr>
  <tr>
    <td>子设备</td>
    <td>不支持对子设备单独调试，须绑定网关进行数据模拟，提供属性上报、事件上报、设备上下线</td>
  </tr>
  <tr>
    <td rowspan="3">应用模拟器</td>
    <td>直连设备</td>
    <td>支持使用MQTT、CoAP、泛协议接入设备的下行命令调试，提供属性设置、属性获取、属性期望值设置、服务调用</td>
  </tr>
  <tr>
    <td>网关设备</td>
    <td>支持属性设置、属性获取、属性期望值设置、服务调用</td>
  </tr>
  <tr>
     <td>子设备</td>
     <td>不支持对子设备单独调试，须绑定网关进行下行命令调试，提供属性设置、属性获取、服务调用</td>
  </tr>
</table>

<h3 id="1">1. 设备模拟器</h3>

设备模拟器模拟设备进行属性上报、事件上报等上行操作。只有处于离线或未激活状态的设备可以正常启用设备模拟器，如果已有真实设备和平台建立连接，为避免连接冲突（同一设备只允许一个连接），须先断开真实设备，才能正常使用该功能。

##### 直连设备调试步骤

    (1) 登录物联网平台控制台。
    (2) 左侧导航栏，选择「监控运维」>「设备调试」。
    (3) 选择要调试的产品和设备。
    (4) 点击「设备模拟器」Tab，切换到设备模拟器操作页面。
    (5) 选择要调试的功能，填写参数信息，单击启动设备。
    (6) 填写参数信息，点击提交，在「调试日志」查看日志详情。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/设备模拟器.png">
    <br>
    图2 直连设备模拟
    </br>
</center>

- 调试说明

<div style="display: flex; aling-items: center; border-bottom: 1px solid #dfdfdf; background: #f2f2f2;">
  <div style="width: 20%; padding: 10px 20px; border-right: 1px solid #dfdfdf;">
    功能类别
  </div>
  <div style="width: 80%; padding: 10px 20px;">
    功能说明
  </div>
</div>
<div style="display: flex; aling-items: center; border-bottom: 1px solid #dfdfdf;">
  <div style="width: 20%;padding: 10px 20px; border-right: 1px solid #dfdfdf;">
    属性上报
  </div>
  <div style="width: 80%; padding: 10px 20px;">
     <ul>
        <li style="list-style: decimal;">页面展示属性功能点列表</li>
        <li style="list-style: decimal;">支持单个和批量功能点上报</li>
        <li style="list-style: decimal;">功能点输入值为必填（字符串可以允许为空值）</li>
    </ul>
  </div>
</div>
<div style="display: flex; aling-items: center; border-bottom: 1px solid #dfdfdf;">
<div style="width: 20%;padding: 10px 20px; border-right: 1px solid #dfdfdf;">
    属性期望获取
  </div>
  <div style="width: 80%; padding: 10px 20px;">
    <ul>
       <li style="list-style: decimal;">页面只展示读写类型属性功能点列表</li>
       <li style="list-style: decimal;">支持单个和批量功能点上报</li>
      <li style="list-style: decimal;">功能点输入值为必填（字符串可以允许为空值）</li>
    </ul>
  </div>
</div>
<div style="display: flex; aling-items: center; border-bottom: 1px solid #dfdfdf;">
  <div style="width: 20%;padding: 10px 20px; border-right: 1px solid #dfdfdf;">
    属性期望清除
  </div>
  <div style="width: 80%; padding: 10px 20px;">
    <ul>
      <li style="list-style: decimal;">页面只展示读写类型属性功能点列表</li>
      <li style="list-style: decimal;">支持单个和批量功能点期望清除</li>
    </ul>
  </div>
</div>
<div style="display: flex; aling-items: center; border-bottom: 1px solid #dfdfdf;">
  <div style="width: 20%;padding: 10px 20px; border-right: 1px solid #dfdfdf;">
    事件上报
  </div>
  <div style="width: 80%; padding: 10px 20px;">
    <ul>
      <li style="list-style: decimal;">页面展示事件功能点列表</li>
      <li style="list-style: decimal;">事件功能点所有元素为必填项</li>
    </ul>
  </div>
</div>

##### 网关/子设备调试步骤

网关调试包括对自身功能及其子设备的调试，网关功能调试与直连设备操作步骤一致，下面只对网关子设备调试步骤进行说明。
  
    (1) 在左侧导航栏，选择「监控运维」>「设备调试」。
    (2) 选择要调试的网关产品和设备。
    (3) 选择「子设备」调试类别。
    (4) 选择调试子设备，如果还未绑定，选择点框点击「添加子设备」，输入子设备信息，完成子设备绑定。
    (5) 点击「设备模拟器」Tab，切换到子设备模拟器操作页面。
    (6) 选择要调试的功能，填写参数信息，点击「提交」。
    (7) 调试日志查看日志详情。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/子设备调试.png">
    <br>
    图3 子设备模拟
    </br>
</center>

- 调试说明

<div style="display: flex; aling-items: center; border-bottom: 1px solid #dfdfdf; background: #f2f2f2;">
  <div style="width: 20%; padding: 10px 20px; border-right: 1px solid #dfdfdf;">
    功能类别
  </div>
  <div style="width: 80%; padding: 10px 20px;">
    功能说明
  </div>
</div>
<div style="display: flex; aling-items: center; border-bottom: 1px solid #dfdfdf;">
  <div style="width: 20%;padding: 10px 20px; border-right: 1px solid #dfdfdf;">
    子设备添加
  </div>
  <div style="width: 80%; padding: 10px 20px;">
     <ul>
      <li style="list-style: decimal;">页面展示账号下未绑定子设备</li>
    </ul>
  </div>
</div>
<div style="display: flex; aling-items: center; border-bottom: 1px solid #dfdfdf;">
<div style="width: 20%;padding: 10px 20px; border-right: 1px solid #dfdfdf;">
    子设备拓扑关系管理
  </div>
  <div style="width: 80%; padding: 10px 20px;">
    <ul>
      <li style="list-style: decimal;">支持上线、下线及解绑功能</li>
      <li style="list-style: decimal;">支持列表手动刷行</li>
    </ul>
  </div>
</div>

<h3 id="2">2. 应用模拟器</h3>

应用模拟器调用云端API向设备下发属性设置、属性期望设置、属性获取及服务调用操作。

##### 操作步骤

    (1) 登录物联网平台控制台。
    (2) 在左侧导航栏，选择「监控运维」>「设备调试」。
    (3) 选择要调试的产品和设备。
    (3) 点击「应用模拟器」Tab，切换到应用模拟器操作页面。
    (4) 选择要调试的功能。
    (5) 填写参数信息，点击提交，在「调试日志」查看日志详情。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/应用模拟器.png">
    <br>
    图4 应用模拟器
    </br>
</center>

- 调试说明

<div style="display: flex; aling-items: center; border-bottom: 1px solid #dfdfdf; background: #f2f2f2;">
  <div style="width: 20%; padding: 10px 20px; border-right: 1px solid #dfdfdf;">
    功能类别
  </div>
  <div style="width: 80%; padding: 10px 20px;">
    功能说明
  </div>
</div>
<div style="display: flex; aling-items: center; border-bottom: 1px solid #dfdfdf;">
  <div style="width: 20%;padding: 10px 20px; border-right: 1px solid #dfdfdf;">
    属性设置
  </div>
  <div style="width: 80%; padding: 10px 20px;">
     <ul>
        <li style="list-style: decimal;">页面只展示读写类型属性功能点列表</li>
        <li style="list-style: decimal;">支持单个和批量功能点设置</li>
        <li style="list-style: decimal;">功能点输入值为必填（字符串可以允许为空值）</li>
    </ul>
  </div>
</div>
<div style="display: flex; aling-items: center; border-bottom: 1px solid #dfdfdf;">
<div style="width: 20%;padding: 10px 20px; border-right: 1px solid #dfdfdf;">
    属性获取
  </div>
  <div style="width: 80%; padding: 10px 20px;">
    <ul>
       <li style="list-style: decimal;">页面展示属性功能点列表</li>
       <li style="list-style: decimal;">支持单个和批量功能点上报</li>
    </ul>
  </div>
</div>
<div style="display: flex; aling-items: center; border-bottom: 1px solid #dfdfdf;">
  <div style="width: 20%;padding: 10px 20px; border-right: 1px solid #dfdfdf;">
    属性期望值设置
  </div>
  <div style="width: 80%; padding: 10px 20px;">
    <ul>
      <li style="list-style: decimal;">页面只展示读写类型属性功能点列表</li>
      <li style="list-style: decimal;">支持单个和批量功能点期望清除</li>
    </ul>
  </div>
</div>
<div style="display: flex; aling-items: center; border-bottom: 1px solid #dfdfdf;">
  <div style="width: 20%;padding: 10px 20px; border-right: 1px solid #dfdfdf;">
    服务调用
  </div>
  <div style="width: 80%; padding: 10px 20px;">
    <ul>
      <li style="list-style: decimal;">页面展示服务功能点列表</li>
      <li style="list-style: decimal;">服务功能点输入参数为必填项（字符串可以允许为空值）</li>
    </ul>
  </div>
</div>