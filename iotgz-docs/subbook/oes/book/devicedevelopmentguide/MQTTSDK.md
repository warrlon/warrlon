# 使用OneNET-MQTT-SDK接入边缘计算网关

本文档介绍如何使用MQTT-SDK接入边缘计算网关，可以快速验证设备接入，数据上传和命令等相关功能。

## SDK简介

如下是SDK目录结构，主要分为PahoMQTTSDK、 OneNETMqttClient、Sample3个大块，通过Cmake工具编译代码，最终生成可执行文件。

PahoMQTTSDK为精简和移植Paho MQTT的官方开源库paho.mqtt.embedded-c ，保留了其不同驱动以及对应的示例代码，方便客户移植，其github地址为：https://github.com/eclipse/paho.mqtt.embedded-c ，官网地址为：https://www.eclipse.org/paho/downloads.php

OneNETMqttClient为边缘计算网关的应用SDK，基于PahoMQTTSDK实现设备与平台的连接，数据上报，命令接收以及回复等业务处理。

Sample为各种案例，皆基于linux操作系统，pahoapp基于PahoMQTTSDK原案例简单改造，实现平台部分功能。onenestandardapp为OneNETMqttClient标准设备完整案例，实现平台所有功能。onenecustomizedapp为OneNETMqttClient透传设备代码框架，需要用户自己实现MQTT Payload数据组包以及命令处理函数。

SDK下载：[OneNET-MQTT-SDK](/images\oes\devicedevelopmentguide\OneNET-MQTT-SDK.zip)

## 创建产品和设备

1.用户登录边缘IoT管理平台。

2.创建产品。

i.左侧导航栏选择通用**边缘终端管理>添加产品**，根据提示创建好产品。

![](/images\oes\devicedevelopmentguide\平台创建产品.png)

ii.查看**产品详情**，获取**产品ID**和**产品MasterKey**。

![](/images\oes\devicedevelopmentguide\平台产品详情.png)

iii.**产品详情>功能定义>新增功能**,定义物模型。

![](/images\oes\devicedevelopmentguide\平台新增功能.png)

3.创建设备

   i.**产品详情>设备列表>新增设备**，创建好设备。

![](/images\oes\devicedevelopmentguide\平台添加设备.png)

   ii.查看**设备详情**，获取**设备ID**

![](/images\oes\devicedevelopmentguide\平台设备详情.png)

## OneNET-MQTT-SDK接入

​       本案例只介绍标准MQTT设备接入，自定义设备接入方法请自行阅读代码示例，接入协议详情见[OneNET Edge MQTT能力接入说明书](/images\oes\devicedevelopmentguide\OneNET MQTT能力接入说明书.docx)。

1.打开项目工程OneNETMqttClient目录下面OneNETMqttClient.h文件。

如下图所示，设置好设备模式MODEL：standard，接入机地址：实际接入服务器地址，设备ID、产品ID、产品MASTER_KEY由创建产品设备后其详情获得，见上述产品设备创建流程，分别作为MQTT设备的ClientID、Username、Password，BUFFER_SIZE、TIME_OUT、MQTTQOS根据实际硬件配置、业务、网络环境等自行配置。

此处，用户还可以重新定义ONENETLOG(format,...)自定义自己的打印函数以及打印开关。

```c

/*-----------------------------------用户配置区上分界线-------------------------------*/
#define MODEL  "standard"           //standard:标准模式，customized:自定义模式
#define ServerHost	"10.12.4.25"   //mqtt接入机IP
//#define ServerPort	8899           //mqtt接入机端口
#define ServerPort	4433           //mqtt 网关接入机端口
#define DEVICE_ID	 "10144260"	// 设备ID   -  MQTT协议 ClientID，平台设备详情获取
#define PRODUCT_ID	 "101808"	// 产品ID   -  MQTT协议 Username，平台产品详情获取
#define MASTER_KEY	 "MmU3YWM5MGQ5NjAzYWYzMDk2YWM="  //  产品masterKey  -  MQTT协议 Password，平台产品详情获取
#define BUFFER_SIZE  2048   //读写缓存大小
#define TIME_OUT  1000   //读写超时时间
#define MQTTQOS  QOS0    //MQTT QOS，目前只支持QOS0和QOS1


/* 日志打印，用户可自定义日志输出 */
#define __ONENETLOG__   //调试总开关

#ifdef __ONENETLOG__
#define filename(x) strrchr(x,'/')?strrchr(x,'/')+1:x
#define ONENETLOG(format,...) printf("******File: %s, Line: %05d******: "format"",filename(__FILE__), __LINE__, ##__VA_ARGS__)
#else
#define ONENETLOG(format,...)
#endif
/*-----------------------------------用户配置区下分界线-------------------------------*/

```

备注：SDK默认用开启tls连接。

2.打开Sample目录下onenestandardapp.c.

include OneNETMqttClient.h头文件，定义全局唯一设备变量和缓存大小，以及接收数据处理进程。

```c
#include "../OneNETMqttClient/OneNETMqttClient.h"
#include <pthread.h>

OneNetMqttDevice dev;   //定义设备
char mqttpayload[2048];   //payload缓存大小
pthread_t 	mqtt_RecvData_id;    //接收数据处理进程

```



定义数据以及数据初始函数，数据流名称和格式需和平台产品功能定义属性名保持一致对应。

```c
float temperature = 11.11;
DataStream testdata[1];

//标准类型数据初始化
void DataInit(){
	testdata[0].dataPoint=&temperature;
	testdata[0].name="temperature";
	testdata[0].dataType=TYPE_FLOAT;
	testdata[0].flag=true;
}

```

DataStream数据结构说明

```c

typedef struct
{

	char *name;           //数据流名称，和平台产品功能定义中属性名对应
	void *dataPoint;      //数据
	DATA_TYPE dataType;   //数据类型
	int   datalen;        //二进制数据有效，string可用可不用。
	_Bool flag;           //上报使能，false数据被过滤不上报。

} DataStream;


```

3.主函数流程

如下是函数的主流程，实现了设备数据定时上报，命令接收处理以及回复等功能。其中，多线程时需单开线程调用OneNETMQTTReceiveDataMultiThread()函数接收处理平台数据，单线程需循环调用OneNETMQTTReceiveDataSingleThread()函数接收处理平台数据。

```c

void main(void){
    
	int rc = 0;
	//初始化设备
    OneNETMQTTDeviceInit(&dev);

    //连接平台
	if(!OneNETMQTTConnect())  goto exit;
	//订阅平台命令
	if(!OneNETMQTTSubscribeCmd(OneNETStandardCmdHandler))  goto exit;
    //创建线程，定时循环接受数据
	pthread_create(&mqtt_RecvData_id, NULL, OneNETMQTTReceiveDataMultiThread, NULL);
    //标准类型数据初始化
	DataInit();

	while(1){
	    int lenth=0;
        temperature++;
        sleep(10);
        
		//标准数据上报
        lenth=OneNETMQTTStandardDataPacket(FORMAT_TYPE3,testdata,1,mqttpayload,2048);
        if(!OneNETMQTTPublishData(mqttpayload, lenth)) goto exit;		
	}
exit:
    //断开设备连接和网络
	MQTTDisconnect(&dev.client);
	NetworkDisconnect(&dev.network);
}

```

1.编译执行

   linux系统下，需要客户安装cmake 、make 、gcc等c编译工具，camke版本为3及其以上。

   项目根目录下依次执行如下命令：

   ​	a. mkdir build                         -------创建编译目录

   ​	b. cd build/                              -------进入编译目录

   ​	c.  cmake ..                              -------生成makefile文件

   ​	d.  make                                  -------生成可执行文件

   ​	e.  cd Sample/                        -------进入执行文件所在目录

   ​	f.   ./onenestandardapp       -------执行编译生成的可执行文件


如下图所示，可以看到设备正常连接到平台，并定时上报数据，设备正常运行。

![](/images\oes\devicedevelopmentguide\设备数据上报.png)

## 平台验证

1.设备上线

![](/images\oes\devicedevelopmentguide\平台设备上线.png)

2.上报数据查看 

平台**设备详情>资源列表**，点击对应属性，下拉查看上传数据。

number数据

![](/images\oes\devicedevelopmentguide\平台设备数据查看.png)

str_test数据

![](/images\oes\devicedevelopmentguide\平台数据查看2V3.png)

3.命令下发

​      i.平台下发写命令

![](/images\oes\devicedevelopmentguide\平台下发写命令.png)

​      ii.平台下发读命令以及返回结果

![](/images\oes\devicedevelopmentguide\平台读命令结果.png)

​    可以看到读取值为刚才设置值。

​      iii.设备运行日志

![](/images\oes\devicedevelopmentguide\设备读写命令日志.png)

可以看到写成功后，设备数据被改变，成功上报新数据，返回读命令结果。
