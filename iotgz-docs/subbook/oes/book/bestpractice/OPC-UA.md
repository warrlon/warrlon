# OPC UA设备接入实践

本文介绍将基于OPC UA协议的设备（以下统称设备）接入OneNET智能边缘计算套件的边缘节点，及其与OES边缘计算平台ECP交互的过程。

## 搭建OPC UA服务器

这里使用以python语言实现的[opcua开源库](https://github.com/FreeOpcUa/python-opcua)搭建OPC UA模拟服务器，因此对操作系统没有限制，只须能安装上**python 3.5.2**及以上版本，python安装过程略。下面以linux系统为例，根据如下步骤，完成OPC UA Server的搭建。

1.使用 pip(Python 3.4+ 版本都自带 pip) 工具安装依赖包**opcua 0.98.3及以上版本**，此处为0.98.7:

```shell
pip install opcua==0.98.7
```

2.下载OPC UA服务器源文件[simulated_opcua_server.py](/images\oes\bestpractice\OPCUA\simulated_opcua_server.py)，此源代码模拟了一个灯设备，有温度和开关状态两个属性，属性值每5秒随机改变。

```shell
wget --no--check-certificate simulated_opcua_server.py
```

3.后台运行OPC UA服务器：

```shell
python3 simulated_opcua_server.py 2>&1 1>/dev/null
```

## 安装OPC UA客户端

使用OPC UA边缘应用接入OPC UA设备时需要先配置设备的产品物模型，该过程需要借助OPC UA客户端作为辅助工具来浏览OPC UA服务器模拟的所有设备节点信息。这里使用**windows系统**上的OPC UA客户端工具**UaExpert**，过程如下：

1.下载并安装[UaExpert](https://www.unified-automation.com/downloads/opc-ua-clients.html)。

2.打开UaExpert,点击工具栏上的![opcua_02.png](/images\oes\bestpractice\OPCUA\opcua_02.png)工具添加OPC UA Server：

![opcua_01.png](/images\oes\bestpractice\OPCUA\opcua_01.png)

3.在弹出框中的Endpoint Url输入框中按下图所示输入OPC UA服务器Url，端口默认是4840，因此按下图只需修改其中的ip地址即可。

![opcua_03.png](/images\oes\bestpractice\OPCUA\opcua_03.png)

4.点击OK按钮连接OPC UA服务器成功后，可以看到设备信息如下图所示。

   ![opcua_04.png](/images\oes\bestpractice\OPCUA\opcua_04.png)

5.在左边点击各节点，可以在右上角节点信息中查看所选节点的对应信息。在配置OPC UA产品物模型时，就需要查看设备各属性的类型和值。

## 接入OPC UA设备

登录**边缘IoT管理**控制台，进行设备接入。

前提条件：已搭建部署OneNET边缘节点并连接上OneNET边缘计算平台，具体步骤参考**边缘节点环境搭建最佳实践**。

### 创建OPC UA产品

产品是对具有相同属性的一类终端设备的抽象，它定义了该类设备共同的一组功能属性也叫物模型。

1.在**边缘资源**>**边缘终端管理**界面，点击右边的**添加产品**按钮：

![opcua_11.png](/images\oes\bestpractice\OPCUA\opcua_11.png)

2.在弹出界面中输入自定义产品名称，但必须选择协议类型为**OPC UA**。

![opcua_12.png](/images\oes\bestpractice\OPCUA\opcua_12.png)

3.输入完成后，点击添加按钮，回到产品界面。

![opcua_13.png](/images\oes\bestpractice\OPCUA\opcua_13.png)



### 创建OPC UA产品物模型

1.在OPC UA产品下点击**查看设备列表**，进入产品详情界面。

![opcua_14.png](/images\oes\bestpractice\OPCUA\opcua_14.png)

2.在**产品详情**选项卡界面中，点击右边的**添加功能**按钮。

![opcua_15.png](/images\oes\bestpractice\OPCUA\opcua_15.png)

3.在弹出框输入界面中按下图输入功能信息，属性类型和节点名称需要参考OPC UA服务上实际设备属性填写，可对照UaExpert上显示的信息。

![opcua_18.png](/images\oes\bestpractice\OPCUA\opcua_18.png)

4.填写完后点击**添加**按钮,回到产品功能定义列表。

![opcua_20.png](/images\oes\bestpractice\OPCUA\opcua_20.png)

5.以相同步骤添加其它属性。

![opcua_19.png](/images\oes\bestpractice\OPCUA\opcua_19.png)



### 创建OPC UA设备

这里的设备对应一个实际终端设备，是抽象模型。

1.切换到**设备列表**选项卡界面，点击**添加设备**按钮。

![opcua_21.png](/images\oes\bestpractice\OPCUA\opcua_21.png)

2.在弹出框输入界面，自定义输入设备名称。

![opcua_22.png](/images\oes\bestpractice\OPCUA\opcua_22.png)

3.点击添加，回到设备列表界面。至此一个设备添加完成。

![opcua_23.png](/images\oes\bestpractice\OPCUA\opcua_23.png)



### 部署OPC UA应用

OPC UA应用须为OneNET边缘市场官方提供的镜像应用，内部集成了OPC UA客户端驱动，本为OneNET边缘节点的可选模块，这里需要将它部署到将要接入OPC UA设备的边缘节点。

1.找到**已部署好的边缘节点**，记住节点产品名称，后面部署应用需要用到，然后点击**查看**按钮。

![opcua_24.png](/images\oes\bestpractice\OPCUA\opcua_24.png)

2.进入边缘节点列表，找到要接入OPC UA设备的节点，确保显示为**在线**，记住**节点名称**，后面部署应用需要用到。

![opcua_25.png](/images\oes\bestpractice\OPCUA\opcua_25.png)

3.进入**边缘市场**，找到与边缘节点CPU架构一致的**OPC UA应用**，点击**部署应用**。

![opcua_26.png](/images\oes\bestpractice\OPCUA\opcua_26.png)

4.在进入部署设置界面，如下图修改关联边缘节点为已部署好的边缘节点的产品名称和节点名称，输入首字符时会自动联想选择。其它输入项可默认，也可根据实际需要修改。最后点击**创建**按钮部署到边缘节点中，如果成功则会跳转到容器应用界面。

![opcua_27.png](/images\oes\bestpractice\OPCUA\opcua_27.png)

![opcua_28.png](/images\oes\bestpractice\OPCUA\opcua_28.png)

### 添加子设备通信通道

通信通道，也即通信方式。OPC UA协议是基于TCP的协议。在边缘节点下添加OPC UA通信通道，可以提供给本边缘节点下的OPC UA设备使用。

1.回到边缘节点列表，找到边缘节点，点击**详情**按钮进入节点详情界面。

![opcua_29.png](/images\oes\bestpractice\OPCUA\opcua_29.png)

2.按如下图切换选项卡：**边缘节点配置**>**子设备通信通道**>**OPC UA协议**，点击**新增通道**按钮。

![opcua_32.png](/images\oes\bestpractice\OPCUA\opcua_32.png)

3.在弹出框输入界面中按下图配置，通道协议选OPC-UA，通道地址填实际的OPC UA服务器的地址。点击**分配**按钮添加通道信息。

![opcua_33.png](/images\oes\bestpractice\OPCUA\opcua_33.png)

4.添加完成后回到OPC UA协议通道列表，多了一条记录。

![opcua_34.png](/images\oes\bestpractice\OPCUA\opcua_34.png)

### 关联OPC UA设备

即将哪些设备接入到当前边缘节点。

1.按如下图切换选项卡：**边缘节点配置**>**子设备管理**>**OPC UA协议**，点击**关联**按钮。

![opcua_30.png](/images\oes\bestpractice\OPCUA\opcua_30.png)

2.在弹出框输入界面中先勾选要关联的OPC UA设备，再点击**添加**按钮。

![opcua_31.png](/images\oes\bestpractice\OPCUA\opcua_31.png)

3.添加完成后回到OPC UA子设备列表，多了一条记录。

![opcua_35.png](/images\oes\bestpractice\OPCUA\opcua_35.png)


### 配置OPC UA设备通道

指定OPC UA设备驱动去哪里读写该设备的数据，即连接OPC UA服务器，读取服务器里对应设备的属性数据。

1.仍然在**边缘节点配置**>**子设备管理**>**OPC UA协议**的OPC UA子设备列表，点击每个设备行右边的**通道配置**。

![opcua_36.png](/images\oes\bestpractice\OPCUA\opcua_36.png)

2.在弹出框输入界面上选择之前添加的OPC UA设备通道，节点路径为OPC UA服务上的节点路径，以Objects开头且以/间隔，如下图。填完后点击**分配**按钮。完成。

![opcua_37.png](/images\oes\bestpractice\OPCUA\opcua_37.png)

### 添加云边消息【平台转发】

如果已配置，可跳过。

边缘网关收到设备上传的数据，默认是不上报给边缘云平台的。如果需要上报给边缘云平台，则要添加一个对应的消息路由。

1.进入**云边消息**>**客户端配置**界面，点击**添加客户端**按钮。

![opcua_40.png](/images\oes\bestpractice\OPCUA\opcua_40.png)

2.在弹出框输入界面中，如下图配置好后，点击**完成**按钮。

![opcua_41.png](/images\oes\bestpractice\OPCUA\opcua_41.png)

3.成功后回到云边消息客户端列表界面，新增了一条记录。

![opcua_42.png](/images\oes\bestpractice\OPCUA\opcua_42.png)

4.回到边缘节点详情界面，如下图切换到**边缘节点配置**>**云边消息**列表，点击**分配客户端**按钮。

![opcua_43.png](/images\oes\bestpractice\OPCUA\opcua_43.png)

5.在弹出框输入界面中勾选刚才创建的客户端，点击**分配**按钮。

![opcua_44.png](/images\oes\bestpractice\OPCUA\opcua_44.png)

6.完成之后回到云边消息列表。

![opcua_45.png](/images\oes\bestpractice\OPCUA\opcua_45.png)

### 部署配置方案

上述所有配置包括子设备、通信通道、云边消息等配置操作完成后，还只是保存在平台侧，需要下发到边缘节点。下发之后，如果一切无误，边缘节点就会采集设备数据并上报到边缘云平台。

1.回到边缘节点详情界面，点击右上角的**部署配置**按钮部署到边缘节点中。

![opcua_38.png](/images\oes\bestpractice\OPCUA\opcua_38.png)

### 查看数据上报

1.在OPC UA设备列表里点击OPC UA设备行右边的**详情**，查看设备数据。

![opcua_39.png](/images\oes\bestpractice\OPCUA\opcua_39.png)

2.可以点击每行属性前的**箭头**按钮展开数据视图。比如点击温度属性。

![opcua_46.png](/images\oes\bestpractice\OPCUA\opcua_46.png)

3.温度属性数据视图如下：

![opcua_47.png](/images\oes\bestpractice\OPCUA\opcua_47.png)
