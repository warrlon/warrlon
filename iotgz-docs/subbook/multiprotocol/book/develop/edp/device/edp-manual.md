# 开发流程

测试接入流程分为平台域和设备域，用于帮助您进行首次接入体验，以便对平台的功能以及接入协议有大致的了解。

**测试流程图**

![pic](/images/EDP/测试流程图.jpg)

**接入步骤**如下：

**Step1 创建产品，选择接入协议**

首先您需要在平台创建一个接入协议为EDP的产品，创建产品后，记录该产品的产品ID

**Step2 创建设备，记录设备ID等信息**

创建设备有两种方式：

第一种 可以通过页面点击添加设备，输入设备名称和鉴权信息（即设备编号），并记录下该设备编号。

第二种 可以通过调用创建设备API 实现设备的创建，输入设备的设备名、接入协议、鉴权信息以及MasterKey等信息，即可在平台上创建设备。


**Step3 建立设备与平台间的协议连接**

使用Step1和step2中的参数作为登录参数，使用SDK中的对应接口组织EDP连接报文，发送到平台，与平台建立EDP连接.

以C语言SDK为例:
```c
/* 利用sdk 中EdpKit.h 中PacketConnect2 方法封包连接协议 */
EdpPacket* send_pkg = PacketConnect2(PID, AUTHINFO);

/* 发送连接协议包数据 */
int ret = DoSend (sockfd, send_pkg->_data, send_pkg->_write_pos);

/* 使用完后必须删除send_pkg ， 否则会造成内存泄漏 */
DeleteBuffer(&send_pkg);
```

若已经连接成功，在设备信息中会看到一个在线标记：

![pic](/images/MQTT/在线.png)

**Step4 数据流创建，数据点上传**

利用SDK中提供的接口函数，编写代码将数据上传到平台

以C语言SDK为例，上传一组温度为18℃，湿度为80%RH的数据点
```c
cJSON *json_data = cJSON_CreateObject();

cJSON_AddNumberToObject(json_data, "temperature", 18);
cJSON_AddNumberToObject(json_data, "humidity", 80);
		  
EdpPacket* send_pkg = PacketSavedataJson(NULL, json_data, kTypeSimpleJsonWithoutTime, 0);

/*发送存储包数据,上传数据点*/
int ret = DoSend (sockfd, send_pkg->_data, send_pkg->_write_pos);

/*使用完后必须删除send_pkg ， 否则会造成内存泄漏*/
DeleteBuffer(&send_pkg);

/*删除构造的json对象*/
cJSON_Delete(json_data);
```

**Step5 数据流展示，查看数据点**

在OneNET上的**设备管理**下点击**数据展示**，进入数据展示页面，点击下拉菜单，查看近期上传的数据点；也可以选择时间区间来查看历史时间

在上述测试流程图中，用户需要手动在平台添加设备，之后再进行设备域的接入流程，在大量设备接入时，会带来很多不必要的操作。

因此，您需要进行设备批量接入时，推荐采用**批量接入**方案

