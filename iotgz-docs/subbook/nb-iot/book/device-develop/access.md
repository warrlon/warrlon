# NB-IoT设备接入开发指南
[本页目录]()

[STEP 1 创建产品，选择接入协议](#1)

[STEP 2 创建设备，记录设备ID等信息](#2)

[STEP 3 移植SDK或搭载NB模组，建立UDP连接](#3)

[STEP 4 建立设备与平台间的协议连接](#4)

[STEP 5 查看设备资源列表](#5)

[STEP 6 查看设备属性列表，操作资源数据](#6)

[STEP 7 结合实际场景开展NB-IOT应用](#7)

测试接入流程分为平台域和设备域，用于帮助您进行首次接入体验，以便对平台的功能以及接入协议有大致的了解。

**测试流程图**：
基于NB模组/SDK方式接入流程：
![pic](/images/LwM2M/接入流程说明.jpg)



<h3 id="1"><font color=#2B2B2B face="微软雅黑"> &triangleright; STEP 1 创建产品，选择接入协议</font></h3> 

首先您需要在平台创建一个NB-IoT的产品，在设备接入协议选择时选择LwM2M协议(因NB-IOT设备需通过NB基站接入平台，创建产品时联网方式请选择“NB-IoT”)，具体创建步骤可查看[产品创建](/book/get-start/product&device/createProduct.md)。

创建产品后，记录该产品的**用户ID**。

<h3 id="2"><font color=#2B2B2B face="微软雅黑"> &triangleright; STEP 2 创建设备，记录设备ID等信息</font></h3>

创建设备有两种方式：

&bigodot; 第一种: 

可以通过页面点击添加设备，输入设备名称和鉴权信息（即IMEI、IMSI），具体平台的资源模型可详情请查看[资源模型](/book/introduce/resource-model.md)，并记录下该设备编号。

&bigodot; 第二种：

可以通过调用创建设备API 实现设备的创建，输入设备的设备名、接入协议、鉴权信息以及MasterKey等信息，即可在平台上创建设备。

<h3 id="3"><font color=#2B2B2B face="微软雅黑"> &triangleright; STEP 3 移植SDK或搭载NB模组，建立UDP连接</font></h3>

结合NB-IOT设备的实际接入方式，目前来看主要有两种：

&bigodot; 第一种：

NB-IOT设备搭载了已经实现接入OneNET平台的NB模组，设备通过NB模组和NB基站以及核心网等网元连接，实现和OneNET平台进行交互，完成同bootstrap服务器建立UDP连接。

**具体方式**为：设备上电后通过发送AT指令给模组，同时携带鉴权参数，包括：**Endpoint-Name（IMEI；IMSI）、Authcode(默认为NULL)**，实现设备和平台之间的UDP连接。连接建立成功后，bootstrap服务器会返回的LwM2M接入服务器地址和端口；

已经实现接入OneNET平台的NB模组部分展示见下表：

全部模组列表见[已支持模组的列表](/book/device-develop/module-list.md)。

|	终端厂商全称	|	模组型号	|	制式协议版本	|	芯片型号	|
|:-----|----|----|----|
|	中移物联网有限公司	|	M5311	|	R14	|	MT2625	|
|	中移物联网有限公司	|	M5310-A	|	R14	|	Hi2115	|
|	中移物联网有限公司	|	M5330-GNSS	|	R14	|	MT2625	|
|	中移物联网有限公司	|	M5312	|	R14	|	RDA8908A	|
|	中移物联网有限公司	|	M5330-A	|	R14	|	RDA8908A	|
|	中移物联网有限公司	|	M5310-SE	|	R14	|	Hi2115	|
|	中移物联网有限公司	|	M5313	|	R14	|	RDA8909B	|
|	中移物联网有限公司	|	M5330	|	R14	|	MT2625	|
|	中移物联网有限公司	|	S5601	|	R14	|	MT2625	|
|	中移物联网有限公司	|	M5310-A-CM	|	R14	|	Hi2115	|
|	中移物联网有限公司	|	M5311-CM	|	R13	|	MT2625	|
|	中移物联网有限公司	|	M5313-CM	|	R13	|	RDA8909B	|
  [查看更多...](/book/device-develop/module-list.md)


&bigodot; 第二种：

NB-IOT设备搭载的NB模组未实现接入OneNET平台，该情况建议有两种方式：

- (1) 开展NB模组接入OneNET的适配工作（若有意向接入OneNET平台，请[点击此处](/book/device-develop/get_SDK.md)）。
- (2) 需要用户下载NB-IOT的**SDK**，开展相应的开发工作自行移植至设备的MCU中。

若SDK已成功移植至MCU后，可在MCU中配置好bootstrap服务器地址、端口号，以及endpoint name参数（也即鉴权信息**IMEI、IMSI等信息**）信息后，通过SDK实现和bootstrap服务器的UDP连接。

连接建立成功后，bootstrap服务器会返回的LwM2M接入服务器地址和端口。

bootstrap服务器域名为：

**coap://nbiotbt.heclouds.com**端口号为：5683 

**coaps://nbiotbt.heclouds.com**端口号为：5684 

支持IPV6协议方式接入，IPV6接入暂不支持引导机方式，请配置连接ACC地址：

**2409:8060:8ea:601::1864**端口号为：5683 

**2409:8060:8ea:601::1864**端口号为：5684 

<h3 id="4"><font color=#2B2B2B face="微软雅黑"> &triangleright; STEP 4 建立设备与平台间的协议连接</font></h3>

在STEP 3中完成设备获取LwM2M接入服务器的地址后，设备会自动完成和平台间的协议连接。

若已经连接成功，在设备信息中会看到一个在线标记：

![pic](/images/LwM2M/设备在线.jpg)

<h3 id="5"><font color=#2B2B2B face="微软雅黑"> &triangleright; STEP 5 查看设备资源列表</font></h3>

在STEP 4中完成设备上线后，通过点击最右边的“资源列表”按钮可以进入该设备的资源列表中进行信息查看。

设备上线后会上传一个资源列表到平台中，平台可以对这些资源做读、写、执行、订阅等操作。

在资源列表中可以看到设备下的对象名称、实例个数和属性个数。
![pic](/images/LwM2M/资源列表.jpg)

<h3 id="6"><font color=#2B2B2B face="微软雅黑"> &triangleright; STEP 6 查看设备属性列表，操作资源数据</font></h3>

在STEP 5中看到设备资源列表后，点击某个具体的对象名称后可以看到具体的对象实例以及该对象实例下的属性值等信息。
![pic](/images/LwM2M/对象的属性.jpg)

在该页面上可以实现对具体某个属性的读、写、执行以及查看详情等权限，完成对设备某个具体属性的实际操作。
![pic](/images/LwM2M/属性值.jpg)

<h3 id="7"><font color=#2B2B2B face="微软雅黑"> &triangleright; STEP 7 结合实际场景开展NB-IOT应用</font></h3>

通过STEP 1至STEP 6上述操作，可以实现对具体NB-IOT设备的连接、资源列表查看、对象属性的读、写、执行等实际操作等，满足在NB环境下整个NB-IOT应用的开展。
