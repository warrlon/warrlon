# An Example of NB Device Access Based on MCU
---
```
基于MCU的方式实现NB设备接入，即通过移植SDK至设备MCU中，通过MCU和模组进行交互实现连接到OneNET平台。
该情况适用于实验阶段或是终端设备对接入OneNET平台有较紧急意愿，但设备所用模组暂未支持接入OneNET的情况下。 
``` 
Specific access examples and steps are as follows:

```
（1）首先需要完成对SDK的移植操作，实现把SDK植入所需连接到OneNET的MCU芯片中；

（2）网络配置。在连接OneNET平台之前需要对设备侧进行网络配置：
 ```
![](/images/LwM2M/网络配置.png)

Including access machine address and ** authentication information and other parameters ** (that is ** IMEI, IMSI **).

```
同时还需要对设备和平台所交互的资源进行资源配置，在设备端的SDK中，设备上所有与onenet进行交互的数据变量都需要表示为资源，
比如温湿度传感器的温度和湿度分别可以表示为2个资源，配置好资源属性后，设备在向服务器注册的过程中会携带相应的资源列表,
服务器端会主动向设备订阅（Observe）资源列表中所有资源。
```
| Attribute | Description|
|:---|---|
| objid | describes the sensor type on the device|
| instid | describes the number of this type of sensor|
| resid | describes some type of data of the sensor, such as the current, maximum and minimum values of temperature|
| Flag | Operability of the resource, supported by types that are readable/writable/executable|
| Type | Data type of the resource, supported by bool/int/float/string/bin|
| write | User writes hook functions for this resource|
| execute | User executes the hook function of the resource|
```
注意：objid和resid是不能够随意定义的，必须遵守《IPSO-Smart-Objects-Expansion-Pack》文档中的规定
```
Configuration example:

![](/images/LwM2M/配置示例.png)


```
（3）心跳设置。设备端的SDK在初始化的时候会设置lifetime的值，并在向服务器注册的时候上传该值，
SDK在到期后会主动向服务器发送Update消息，如服务器端未收到Update消息，服务器端将抛弃所有上报
的Notify消息并向该设备发送RST消息。

（4）数据发送。如果有资源的值被更新了，需要调用nbiot_device_notify通知SDK该资源的值发生了变化，
由SDK择机上传至onenet。

（5）下行处理。  命令由第三方应用发送至onenet，并由云平台转发至终端设备，读写命令和执行命令均
直接发送至终端，SDK会自动调用该命令对应的资源中的write钩子函数或者execute钩子函数，用户只需要
编写该两个函数即可以完成下行命令的处理。
```