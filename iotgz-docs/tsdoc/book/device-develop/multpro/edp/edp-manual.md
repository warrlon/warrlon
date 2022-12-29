# Introduction to EDP
The test access process is divided into platform domain and device domain, which is used to help you have the first access experience, so as to have a general understanding of the platform's functions and access protocols.

** Test flow chart**

![pic](/images/EDP/测试流程图.jpg)

** Access steps** are as follows:

** Step1 Create Products, Choose Access Protocol**
First, you need to create an access protocol for EDP products on the platform and see[product creation](/book/easy-manual/product&device/product-create.md)

If you don't have an OneNET account, you can[register users](/book/easy-manual/login.md)

After creating the product, record the product ID of the product

** Step2 Creates Devices, Records Device ID and Other Information**

There are two ways to create a device:

The first is to add devices by clicking on the page and enter device name and authentication information (i.e. device number). For details of the resource model of the specific platform, please see the[resource model](/book/introduction/resource-model.md) and record the device number.

The second way is to create devices by calling the Creation Device API. By inputting device name, access protocol, authentication information and MasterKey information, devices can be created on the platform.


** Step3 Establishes Protocol Connection between Equipment and Platform**

The parameters of Step1 and Step2 are used as login parameters, and the corresponding interfaces in SDK are used to organize EDP connection messages, send them to the platform, and establish EDP connection with the platform.

Take the C language SDK as an example:


```c
/* 利用sdk 中EdpKit.h 中PacketConnect2 方法封包连接协议 */
EdpPacket* send_pkg = PacketConnect2(PID, AUTHINFO);

/* 发送连接协议包数据 */
int ret = DoSend (sockfd, send_pkg->_data, send_pkg->_write_pos);

/* 使用完后必须删除send_pkg ， 否则会造成内存泄漏 */
DeleteBuffer(&send_pkg);
```

If the connection is successful, you will see an online tag in the device information:

![pic](/images/MQTT/在线.png)

** Step4 data stream creation, data point upload **

Using the interface function provided in SDK, write code to upload data to the platform

Take C language SDK as an example, upload a set of data points with temperature of 18 C and humidity of 80% RH.





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

** Step5 Data Stream Display, View Data Points**

On OneNET ** Device Management ** click ** Data Display ** to enter the data display page, click the drop-down menu to view the recently uploaded data points, or choose the time interval to view the historical time.

In the above test flow chart, users need to manually add devices to the platform, and then proceed to the access process of the device domain. When a large number of devices access, it will bring a lot of unnecessary operations.

Therefore, when you need batch access of equipment, the ** batch access ** scheme is recommended.


## Common Questions
----

** Q1: How to upload integer/floating-point data points numerically? * *

A: It is recommended that type = 3 or type = 1 be used for uploading (refer to the Equipment Terminal Access Protocol-EDP for details). Example:
```
type=3  整型： {"temperature":22}                     
        浮点型： {"pi":3.14159}
type=1  整型： {"datastreams":[{"id":"temperature","datapoints":[{"value":22}]}]}
        浮点型： {"datastreams":[{"id":"pi","datapoints":[{"value":3.14159}]}]} 
```
** Q2: How to upload location information? * *

A: Geographic location information in JSON format can be displayed in data stream. It is suggested to upload it by type=3 or type=1 (refer to EDP for details). For example:
```
type=3：{"loc":{"lon": 117.48,"lat": 39.96}}
type=1：{"datastreams":[{"id":"loc","datapoints":[{"value":{"lon":117.48,"lat":39.96}}]}]}
```
** Q3: EDP implements the issuance of control commands. What's the use of cmd_id? * *

A: cmd_id is generated randomly by the server. Each EDP-cmd corresponds to a unique cmd_id, according to which the user can get the command response of the device and the execution status of the command through RESTFUL API (see API document for details).

** Q4: Does the device need to respond to an EDP command when it receives an EDP command request? * *

A: EDP command requests are generally used to send command control devices. When the server sends the command, it generates a unique cmd_id and a corresponding execution state of the command. When the device receives the command, if it sends an EDP command response, the execution state of the server will become successful. If the device does not respond, the execution state of the server will be set as execution overrun. The device can query the execution status of commands through RESTFUL API and cmd_id. If the device does not send a reply, it will only affect the execution status of the command saved on the server side, but will not affect the process of command issuance.