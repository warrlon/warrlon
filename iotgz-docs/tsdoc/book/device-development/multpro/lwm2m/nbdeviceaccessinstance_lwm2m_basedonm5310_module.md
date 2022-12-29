# An Example of NB Device Access Based on M5310 Module

## 1. Initialization of power on

Note: There should be a certain time interval between each AT command

|M5310|                                          |
|---|---|
| OK | // Boot Up Information|
| AT | // After booting up, the AT is sent circularly until OK is returned, proving that the module initialization is normal.|
|OK|                                             |
| AT+COPS=1,2,'46000'|// Set up Manual Registration for Mobile Operations MNC|
|OK|
| AT+NEARFCN=0,3555 |// Lock-in Frequency Point is 3555. Lock-in Frequency can effectively reduce the search time, but the wrong set-up of frequency point will lead to <br>// search failure. It is recommended not to set lock-in Frequency under normal circumstances.|
|OK|                                             |
| AT+CSCON=1 |// Open Signal Tip Automatically Reporting|
|OK|                                             |
| AT+CEREG=1 |// Open automatic reporting of registration information|
|OK|                                             |
|+ CSCON: 1 |// Automatically Reported Network Signal Tips - Connected|
|+ CEREG: 1,19E6,94,7 |// Automatically reported network registration information - 1 - Local network has been registered, 5 - roaming has been <br>// registered, and other cases are registered exceptions. Please refer to the AT command manual for details // / / If auto reporting is not enabled, users need to use AT+CEREG?
|AT+CGDCONT？|                                             |
|+ CGDCONT:0, "IP", <br> "nbiot.MNC002.MCC460.GPRS",,0,0 |// Query the current APN, this step can be omitted|
|OK|-|

```text
注：需要确认入网状态为已注册才能进行后续数据收发操作，如果不使用自动上报功能，
可使用AT+CEREG? 命令主动查询当前注册状态直到变为已注册，目前测试开机注册时间范围为20s-120s  
```


## 2. UDP Data Transmitting and Sending

### 2.1. Create UDP Socket
```text
AT+NSOCR=`<type>`,`<protocol>`,`<listen prt>`[,`<receive control>`]
```

For example:

| AT+NSOCR= "DGRAM", 17,2334,1 |// Create a local UDP listening port, open data to automatic reporting|
|:---|---|
| 0 | // Create a successful return socket number, value 0-6, listen on up to seven ports|
| OK | // Create UDP Successfully|

### 2.2. Sending UDP Data

```text
向目的UDP地址发送数据可使用AT+NSOST或AT+NSOSTF命令，如下，
AT+NSOST=`<socket>`,`<remote_addr>`,`<remote_port>`,`<length>`,`<data>`
AT+NSOSTF=`<socket>`,`<remote_addr>`,`<remote_port>`,`<flag>`,`<length>`,`<data>`
```
For example:

|AT+NSOST=0,183.230.40.150,<br>36000,10,30313233343536373839|---|
|:---|---|
| 0,10 |// Socket No. 0 successfully sends 10 Byte UDP data|
|OK|                                                        |
|+ NSONMI: 0,30 |// Socket No. 0 receives 30 Bytes data|

 ### 2.3. Receiving UDP data

```text
当接收到UDP数据时，可以使用AT+NSORF读取，当读取长度大于实际接收长度时，返回缓冲区实际接收数据长度
```

|AT+NSORF=`<socket>`,`<req_length>`|---| 
|:---|---|
|+ NSONMI: 0,30 |// Hint No. 0 Socket receives 30 Bytes data|
| AT + NSORF = 0,30 |// Read the received 30Bytes data.|
| 0,183.230.40.150,36000,30, <br>5B31372E3136392E33362E<br>31353A3237395D3033333333333839,0 |// read to 183.230.40.150:36000 sent 30Bytes data

```text
注：本示例的测试服务器为中移物联网公司内部测试服务器，会自动回复”[远程IP:端口]接收数据”，只做测试用途，不保证服务器功能。
```

### 2.4. Turn off UDP

| AT+NSOCL= `socket> `|//`socket> `id allocated by the system at the time of creation of 2.1|
|:---|---|---|
|OK| - |  


## 3. OneNET Data Transmitting and Sending

### 3.1. OneNET Platform End Creation Device

```text
访问OneNET门户网站：http://open.iot.10086.cn/ ，创建NB-IOT产品及设备。
创建设备所使用的鉴权信息imei及imsi需要记录并在终端登录时使用，返回的device_id为平台端创建的设备接入标识，
如果需要查询设备信息，需要提供设备id
```

### 3.2. Equipment registration process

#### (1) Version Unification and Creation of Basic Communication Suite

|AT+MIPLVER?|
|:---|
|+ MIPLVER: Version number|
|OK|
| This instruction verifies whether the version of the terminal basic communication suite conforms to the test declaration, reads the version information of the communication suite directly in the client, and compares the version information read with the version of the test declaration. A kind of
|AT+MIPLCREATE|
|+ MIPLC REATE: ref value (usually 0)|
|OK|
| Objects and examples are added to the basic communication suite, and the registration process is initiated from the terminal side to the OneNet platform side. The success of registration determines the success of the creation of the communication suite. A kind of

#### (2) Adding object groups to communication Suites

|AT+MIPLADDOBJ=0,3303,2,"11",6,1|
|:---|
|OK|
|AT+MIPLADDOBJ=0,3306,1,"1",5,0|
|OK|
```text
LwM2M规范定义了每个对象对应客户端的某个特定功能实体object，instance代表着这个object的不同实例。
通过objectid和instanceid可以确认到一个指定的object实例；而每个object下可以有多个resource属性数据。
例如一个设备有芯片温度传感器与外界温度传感器的值须上报，温度传感器便是一种object对象，
而具体到某个温度传感器则需要instanceid来区分；某个温度传感器所对应的单位、温度等数值可视为其resource属性，
具体的编码规范可参照IPSO规范或OMA模型规范http://www.openmobilealliance.org/wp/OMNA/LwM2M/LwM2MRegistry.html 。
```
```text
终端侧向OneNet平台侧注册，检查OneNet平台侧下发的discover请求，discover请求中包含3303、3306则判定添加成功。
```
#### (3) Initiation of registration requests

#### A. Registration Operation









```text
设备发送注册请求到平台侧，平台侧接收到设备发送的注册信息，在平台侧检查设备注册情况。

AT+MIPLOPEN=0,3600,30

OK

+MIPLEVENT: 0,6

+MIPLDISCOVER:0,msgid,3303

+MIPLDISCOVER:0,msgid,3306

+MIPLOBSERVE:0,msgid,1,3303,0,-1

+MIPLOBSERVE:0,msgid,1,3303,1,-1

+MIPLOBSERVE:0,msgid,1,3306,0,-1
```
```
在OneNet平台侧(http://api.heclouds.com) 查看终端在线状态(图标为绿色)，终端在线则判定设备注册成功。
```

 #### Examples of API messages judging registration operations under control platform
```text
GET http://api.heclouds.com/devices/status?imei=$IMEI&devIds=$DEVICE_ID HTTP/1.1   
Host: api.heclouds.com/  
api-key: OneNet分配的api-key  
Content-Length: 0  
终端侧预期回复：online : true
```

 ### B. Update registration without parameters
```text
AT+MIPLUPDATE=0,0,0
OK
+MIPLEVENT:0,11
终端侧在本次lifetime周期之内发送不携带参数的更新注册信息到平台侧,
平台侧对该更新注册信息回应,确认检查终端侧是否收到平台侧的回应。
```
### C. Update Registration of Parameter Change
```text
AT+MIPLUPDATE=0,3600,1
OK
+MIPLEVENT:0,11
终端侧在本次lifetime周期之内发送携带参数的更新注册信息到平台侧，
平台侧对该更新注册信息回应确认，检查终端侧是否收到平台侧的回应。
```

### 3.3. Data reporting process
![](/images/LwM2M/数据上报流程.jpg)
### User Reporting Data




```text
AT+MIPLNOTIFY=0,msgid1,3303,0,5700,4,4,98,0,0

OK

AT+MIPLNOTIFY=0,msgid2,3303,0,5601,4,4,88,0,0

OK

在OneNet平台侧查看终端上报最新数据和历史数据，数据完整且正确则判定成功。
```
### Examples of API Messages Judging Log-off Operations under Control Platform




```text
GET http://api.heclouds.com/devices/$DEVICE_ID/datapoints?imei=$IMEI

HTTP/1.1

Host: api.heclouds.com/

api-key: OneNet分配的api-key

Content-Length: 0
```

```
终端侧预期回复：

{"errno":0,"data":{5700和5601最新数据},"error":"succ"} 
```

### 3.4. Equipment Bootstrap Process
```
在设备已初始化且基础通信套件（配置信息包含Bootstrap服务器地址coap://183.230.40.39:5683）
已创建成功且基础通信套件已添加对象和实例（3303、3306）且Bootstrap服务器就绪条件下，
客户端向平台侧发起注册以触发Bootstrap过程并检查Bootstrap过程是否成功。
```










```
AT+MIPLOPEN=0,3600,30

OK

+MIPLEVENT: 0,1

+MIPLEVENT: 0,2

+MIPLEVENT: 0,6

+MIPLDISCOVER:0,msgid,3303

+MIPLDISCOVER:0,msgid,3306

+MIPLOBSERVE:0,msgid,1,3303,0,-1

+MIPLOBSERVE:0,msgid,1,3303,1,-1

+MIPLOBSERVE:0,msgid,1,3306,0,-1

在OneNet平台侧 (http://api.heclouds.com) 查看终端在线状态(图标为绿色)，终端在线则判定Bootstrap过程成功。
```
### An API Message Example for Judging Bootstrap Operation under Control Platform



```
GET http://api.heclouds.com/devices/status?imei=$IMEI&devIds=$DEVICE_ID HTTP/1.1

Host: api.heclouds.com/

api-key: OneNet分配的api-key

Content-Length: 0
```
```
终端侧预期回复：online : true
```

### 3.5. Equipment management process

![](/images/LwM2M/设备管理流程.jpg)


```
设备管理目前版本提供6操作：discover、read、write、execute、write-attributes、observe、

MCU应在执行平台下发的规定操作后数秒内（建议3s）上报对应操作结果，否则传输信息可能丢失。
```
**(1) discover operation**

The device sends the registration request to the platform side, checks the Discover request information in the platform side information received by the device, responds to the Discover request, and checks the equipment resources on the platform side.










```
AT+MIPLOPEN=0,3600,30

OK

+MIPLEVENT: 0,6

+MIPLDISCOVER:0,msgid1,3303

+MIPLDISCOVER:0,msgid2,3306

+MIPLOBSERVE:0,msgid3,1,3303,0,-1

+MIPLOBSERVE:0,msgid4,1,3303,1,-1

+MIPLOBSERVE:0,msgid5,1,3306,0,-1

AT+MIPLDISCOVERRSP=0,msgid1,1,34,"5700;5701;5601;5602;5603;5604;5605"

AT+MIPLDISCOVERRSP=0,msgid2,1,24,"5850;5851;5852;5853;5750"

OK
```
```
在OneNet平台侧查看终端资源列表，完整显示终端设备的实例和资源信息则判定成功。
```
#### An API message example for obtaining discover status under the control platform:



```
GET http://api.heclouds.com/nbiot/resources?imei=$IMEI&obj_id=3303&obj_inst_id=0 HTTP/1.1

Host: api.heclouds.com/

api-key: OneNet分配的api-key

Content-Length: 0
```

```
预期结果：

终端设备的完整对象、实例、资源列表信息。
```
### (2) read operation

#### A. Reading resource requests

The platform side sends Read operation requests for specified resources to the device. After the device receives the message, the terminal communication suite retrieves the resource value information of the device and returns it to the platform side to check the reading results on the platform side.


```
AT+MIPLREADRSP=0,msgid,1,3303,0,5700,4,4,20.123,0,0

OK
```

```
OneNet平台侧预期结果：

{"errno":0,"data":[{"res":[{"val":20.123,"res_id":5700}],"obj_inst_id":0}],"error":"succ"}
```
#### Examples of API messages for read-down operations on the control platform:



```
GET http://api.heclouds.com/nbiot?imei=$IMEI&obj_id=3303&obj_inst_id=0&res_id=5700 HTTP/1.1

Host: api.heclouds.com/

api-key: OneNet分配的api-key

Content-Length: 0
```

Expected response from terminal side:
```
+MIPLREAD:0,msgid,3303,0,5700 
```

#### B. Read instance requests

The platform side sends the read operation request of the specified instance to the device. After the device receives the message, the terminal communication suite obtains the instance resource information of the device and returns it to the platform side to check the reading result on the platform side.







```
AT+MIPLREADRSP=0,msgid,1,3303,0,5700,4,4,20.123,5,0

AT+MIPLREADRSP=0,msgid,1,3303,0,5701,1,3, "Cel",4,0

AT+MIPLREADRSP=0,msgid,1,3303,0,5601,4,4,10.123,3,0

AT+MIPLREADRSP=0,msgid,1,3303,0,5602,4,4,60.2,2,0

AT+MIPLREADRSP=0,msgid,1,3303,0,5603,4,4,0.0,1,0

AT+MIPLREADRSP=0,msgid,1,3303,0,5604,4,4,99.0,0,0

OK

OK
```

Expected results on OneNet platform side:
```
{   "errno":0,
    "data":[
      {
          "res":[
                 {"val":20.123,"res_id":5700},
                 {"val":"Cel","res_id":5701},
                 {"val":10.123,"res_id":5601},
                 {"val":60.2,"res_id":5602},
                 {"val":0.0,"res_id":5603},
                 {"val":99.0,"res_id":5604}
                ],
          "obj_inst_id":0}
          ],
    "error":"succ"
    }
```
#### Examples of API messages for read-down operations on the control platform:



```
GET http://api.heclouds.com/nbiot?imei=$IMEI&obj_id=3303&obj_inst_id=0 HTTP/1.1

Host: api.heclouds.com/

api-key: OneNet分配的api-key

Content-Length: 0
```
Expected response from terminal side:
```
+MIPLREAD:0,msgid,3303,0,-1
```

#### C. Read object requests

The platform side sends Read operation requests for specified objects to the device. After the device receives the message, the terminal communication suite retrieves the object instance resource information of the device and returns it to the platform side to check the reading results on the platform side.







```
AT+MIPLREADRSP=0,msgid,1,3303,0,5701,1,3, "Cel",3,0

AT+MIPLREADRSP=0,msgid,1,3303,0,5602,4,4,50.123,2,0

AT+MIPLREADRSP=0,msgid,1,3303,1,5701,1,3, "Cel",1,0

AT+MIPLREADRSP=0,msgid,1,3303,1,5602,4,4,55.123,0,0

OK

OK

OK

OK
```
Expected results on OneNET platform side:
```
{
    "errno":0,
    "data":[
        {
            "res":[
                    {"val":"Cel","res_id":5701},
                    {"val":50.123,"res_id":5602}],
             "obj_inst_id":0
            },
             {"res":[
                 {"val":"Cel","res_id":5701},
                 {"val":55.123,"res_id":5602}
                 ],
                 "obj_inst_id":1}
        ],
    "error":"succ"
    }
```
#### Examples of API messages for read-down operations on the control platform:



```
GET http://api.heclouds.com/nbiot?imei=$IMEI&obj_id=3303 HTTP/1.1

Host: api.heclouds.com/

api-key: OneNet分配的api-key

Content-Length: 0
```
Expected response from terminal side:
```
+MIPLREAD:0,msgid,3303,-1,-1
```
#### The resource read API message protocol is as follows:

| Operation | Read|
|:---|---|---|
|LwM2M-URI| address /{Object ID}/{Object Instance ID}/{Resource ID}
| Parameter Description | {Object ID}: Required selection, such as sensor type on the device; <br> {Object Instance ID}: optional, sensor number of this type; <br> {Resource ID}: optional, some type of data of the sensor, such as current temperature, maximum value, etc.|
|CoAP-Method|   GET|
| CoAP-Option Option | 1: Uri-Path (11): {Object ID} < br > Option 2: Uri-Path (11): {Object Instance ID} < br > Option 3: Uri-Path (11): {Resource ID} < br > Option 4: Accept (17): The type in the Format table in Section 1, such as application/vnd.oma.LwM2M+tlv, indicates the format of the read data. A kind of
|CoAP-payload|-|
|Success|   2.05 Content|
|Failure|   4.00 Bad Request,  4.01 Unauthorized, 4.04 Not Found, 4.05 Method Not Allowed|
```
注：每次read操作后模块响应上报COAP报文长度应小于512Bytes。
```
### (3) write operation

#### A. Write a source request

The platform side sends Write operation requests for specified resources to the device. After the device receives the message, the terminal communication suite writes the specified values to the specified resources and checks the written results on the terminal side.

```
AT+MIPLWRITERSP=0,msgid,2

OK
```
Expected results on OneNet platform side:
```
{"errno":0,"error":"succ"}
```

#### Examples of API messages for write operations under the control platform:





```
POST http://api.heclouds.com/nbiot?imei=$IMEI&obj_id=3306&obj_inst_id=0&mode=2 HTTP/1.1  

Host: api.heclouds.com/  

api-key: OneNet分配的api-key  

Content-Length: 47       //数值根据HTTP报文实际body大小修改  

Content-Type:application/json  

HTTP内容：{"data":[{"res_id":5850,"val":1}]}  
```
Expected response from terminal side:
```
+MIPLWRITE:0,msgid,3306,0,5850,2,1,01,0,0
```
#### B. Write instance request

The platform sends Write operation requests for specified instances to the device side. After the device receives the message, the terminal communication suite writes the specified values to the resources under the specified instances and checks the written results on the terminal side.

```
AT+MIPLWRITERSP=0,msgid,2

OK
```
Expected results on OneNet platform side:
```
{"errno":0,"error":"succ"}
```

#### Examples of API messages for write operations under the control platform:





```
POST http://api.heclouds.com/nbiot?imei=$IMEI&obj_id=3306&obj_inst_id=0&mode=2 HTTP/1.1

Host: api.heclouds.com/

api-key: OneNet分配的api-key

Content-Length: 47       //数值根据HTTP报文实际body大小修改

Content-Type:application/json

HTTP内容：{"data":[{"res_id":5850,"val":1},{"res_id":5851,"val":22}]}
```
Expected response from terminal side:

```
+MIPLWRITE:0,msgid,3306,0,5850,2,1,01,0,1

+MIPLWRITE:0,msgid,3306,0,5851,2,1,16,0,0
```

** Resource Writing Protocol for API Messages is as follows: **

| Operation | Write (resource writing)|
|:---|---|---|
|LwM2M-URI| address /{Object ID}/{Object Instance ID}/{Resource ID}/{NewValue}|
| Parameter Description {Object ID}: Required selection, such as sensor type on device; |{Object Instance ID}: Required selection, sensor number of this type; <br> {Resource ID}: Required selection, some type of data of the sensor, such as current value of temperature, maximum value, etc.; <br> {NewValue}: Required selection, resource attribute value written. A kind of
| CoAP-Method PUT/POST | CoAP-Option Option 1: Uri-Path (11): {Object ID} < br > Option 2: Uri-Path (11): {Object Instance ID} < br > Option 3: Uri-Path (11): {Resource ID} < br > Option 4: Content-Format (12): Several formats in the Content Format table, <br> such as <br> oma.lvm2m+tlvnd|
| CoAP-payload | {NewValue}, data format specified in Option 4|
|Success|   2.04 Changed|
|Failure|   4.00 Bad Request,  4.01 Unauthorized, 4.04 Not Found, 4.05 Method Not Allowed|

Note: The length of COAP messages sent under each write operation should be less than 512 Bytes, so the maximum length of downward data segment is 480 Bytes.

#### (4) execute operation

The platform sends Exec operation requests for specified resources to the device side. After the device receives the message, the terminal communication suite writes the operation values to the specified resources and checks the execution results on the terminal side.

```
AT+MIPLEXECUTERSP=0,msgid,2

OK
```
Expected results on OneNet platform side:
```
{"errno":0,"error":"succ"}
```

#### Examples of API messages that send execute messages under the control platform:





```
POST http://api.heclouds.com/nbiot/execute?imei=$IMEI&obj_id=3303&obj_inst_id=0&res_id=5605 HTTP/1.1

api-key:OneNet分配的api-key

Host: api.heclouds.com

Content-Length: 21       //数值根据HTTP报文实际body大小修改

Content-Type:application/json

HTTP内容：{"args":"reset"}
```
Expected response from terminal side:
```
+MIPLEXECUTE:0,msgid,3303,0,5605,5, "reset"
```

#### The resource execution API message protocol is as follows:


| Operation | Execute (resource execution)|
|:---|---|---|
|LwM2M-URI| address /{Object ID}/{Object Instance ID}/{Resource ID}/{Arguments}|
| Parameter Description | {Object ID}: Required selection, such as sensor type on device; <br> {Object Instance ID}: Required selection, sensor number of this type; <br> {Resource ID}: Required selection, some type of data of the sensor, such as current temperature, maximum value, etc.;<br> {Arguments}: optional, commands to be executed, such as restart, shutdown, etc. A kind of
|CoAP-Method|   POST|
|CoAP-Option|   Option 1：Uri-Path（11）：{Object ID}<br>Option 2：Uri-Path（11）：{Object Instance ID}<br>Option 3：Uri-Path（11）：{Resource ID}|
| CoAP-payload | {Arguments}, in text/plain format in the Content Format table|
|Success|   2.05 Changed|
|Failure|   4.00 Bad Request,  4.01 Unauthorized, 4.04 Not Found, 4.05 Method Not Allowed|

```
注:每次execute操作下发COAP报文长度应小于512Bytes，故下发数据段长度最大480Bytes。
```
#### (5) Write-Attributes operation

The platform sends Write-Attributes operation requests for specified resources to the device. After the device receives the message, the terminal communication suite writes the attribute values to the specified resources and checks the execution results on the terminal side.



```
AT+MIPLPARAMETERRSP=0,msgid1,2

AT+MIPLPARAMETERRSP=0,msgid2,2

OK

OK
```
Expected results on OneNet platform side:
```
{"errno":0,"error":"succ"} {"errno":0,"error":"succ"}
```
#### An example of API message sending Write-Attributes message under control platform:






```
POST http://api.heclouds.com/nbiot/observe?imei=$IMEI&cancel=false&obj_id=3303&obj_inst_id=0
&res_id=5700&pmin=15&pmax=60&gt=50&lt=0&st=2 HTTP/1.1

POST http://api.heclouds.com/nbiot/observe?imei=$IMEI&cancel=false&obj_id=3303&obj_inst_id=0
&res_id=5601&pmin=18&pmax=90&gt=60&lt=0&st=2 HTTP/1.1

api-key:OneNet分配的api-key

Host: api.heclouds.com

Content-Length: 21       //数值根据HTTP报文实际body大小修改

Content-Type:application/json

{"args": " reset "}
```
Expected response from terminal side:

```
+MIPLPARAMETER:0,msgid1,3303,0,5700,37,"pmin=15;pmax=60;lt=0.0;gt=50.0;st=2.0"

+MIPLPARAMETER:0,msgid2,3303,0,5601,37,"pmin=18;pmax=90;lt=0.0;gt=60.0;st=2.0"
```

#### (6) Observer operation

#### A. Observing resource requests

The platform sends Observer operation requests for specified resources to the device. After the device receives the message, the terminal communication suite subscribes to the specified resources and checks the execution results on the terminal side.









```
AT+MIPLPARAMETERRSP=0,msgid1,2

AT+MIPLPARAMETERRSP=0,msgid2,2

OK

OK

+MIPLOBSERVE:0,msgid3,1,3303,0,5700

+MIPLOBSERVE:0,msgid4,1,3303,0,5601

AT+MIPLOBSERVERSP=0,msgid3,1

AT+MIPLOBSERVERSP=0,msgid4,1

OK

OK
```
Expected results on OneNet platform side:

```
{"errno":0,"error":"succ"}

{"errno":0,"error":"succ"}
```

#### Examples of API messages for observing operations under the control platform:





```
GET http://api.heclouds.com/nbiot/observe?imei=$IMEI&cancel=false&obj_id=3303&obj_inst_id=0
&res_id=5700&pmin=15&pmax=60&gt=50&lt=0&st=2 HTTP/1.1

GET http://api.heclouds.com/nbiot/observe?imei=$IMEI&cancel=false&obj_id=3303&obj_inst_id=0
&res_id=5601&pmin=18&pmax=90&gt=60&lt=0&st=2 HTTP/1.1

api-key:OneNet分配的api-key

Host: api.heclouds.com

Content-Length: 21       //数值根据HTTP报文实际body大小修改

Content-Type:application/json
```
Expected response from terminal side:

```
+MIPLPARAMETER:0,msgid1,3303,0,5700,37,"pmin=15;pmax=60;lt=0.0;gt=50.0;st=2.0"

+MIPLPARAMETER:0,msgid2,3303,0,5601,37,"pmin=18;pmax=90;lt=0.0;gt=60.0;st=2.0"
```

#### B. Observing instance requests

The platform sends the Observer operation request of the specified instance to the device side. After the device receives the message, the terminal communication suite subscribes to the specified instance and checks the execution result on the terminal side.

```
AT+MIPLOBSERVERSP=0,msgid,1

OK
```
Expected results on OneNet platform side:
```
{"errno":0,"error":"succ"}
```

Examples of API messages for observing operations under the control platform:




```
GET http://api.heclouds.com/nbiot/observe?imei=$IMEI&cancel=false&obj_id=3303&obj_inst_id=0 HTTP/1.1

api-key:OneNet分配的api-key

Host: api.heclouds.com

Content-Length: 21       //数值根据HTTP报文实际body大小修改

Content-Type:application/json
```
Expected response from terminal side:
```
+MIPLOBSERVE:0,msgid,1,3303,0,-1
```

#### C. Observing object requests

The platform sends the Observer operation request of the specified object to the device. After the device receives the message, the terminal communication suite subscribes to the specified object and checks the execution result on the terminal side.

```
AT+MIPLOBSERVERSP=0,msgid,1

OK
```
Expected results on OneNet platform side:
```
{"errno":0,"error":"succ"}
```

#### Examples of API messages for observing operations under the control platform:




```
GET http://api.heclouds.com/nbiot/observe?imei=$IMEI&cancel=false&obj_id=3303 HTTP/1.1

api-key:OneNet分配的api-key

Host: api.heclouds.com

Content-Length: 21       //数值根据HTTP报文实际body大小修改

Content-Type:application/json
```
Expected response from terminal side:
```
+MIPLOBSERVE:0,msgid,1,3303,-1,-1
```

#### D. Cancel Observing Resource Request

The platform side sends the operation request of canceling the observation of the specified resource to the device. After the device receives the message, the terminal communication suite cancels subscribing to the specified resource and checks the execution result on the terminal side.

```
AT+MIPLOBSERVERSP=0,msgid,1

OK
```
Expected results on OneNet platform side:
```
{"errno":0,"error":"succ"}
```

#### Examples of API messages that cancel observation operations under the control platform:




```
GET http://api.heclouds.com/nbiot/observe?imei=$IMEI&cancel=true&obj_id=3303&obj_inst_id=0&res_id=5700 HTTP/1.1

api-key:OneNet分配的api-key

Host: api.heclouds.com

Content-Length: 21       //数值根据HTTP报文实际body大小修改

Content-Type:application/json
```
Expected response from terminal side:
```
+MIPLOBSERVE:0,msgid,0,3303,0,5700
```
#### E. Canceling Observation instance request

The platform side sends the operation request of canceling the observation of the specified instance to the device. After the device receives the message, the terminal communication suite cancels subscribing to the specified instance and checks the execution result on the terminal side.

```
AT+MIPLOBSERVERSP=0,msgid,1

OK
```
Expected results on OneNet platform side:
```
{"errno":0,"error":"succ"}
```

#### Examples of API messages that cancel observation operations under the control platform:




```
GET http://api.heclouds.com/nbiot/observe?imei=$IMEI&cancel=true&obj_id=3303&obj_inst_id=0 HTTP/1.1

api-key:OneNet分配的api-key

Host: api.heclouds.com

Content-Length: 21       //数值根据HTTP报文实际body大小修改

Content-Type:application/json
```
Expected response from terminal side:
```
+MIPLOBSERVE:0,msgid,0,3303,0,-1
```

#### F. Cancel Observing odject Request

The platform side sends the operation request of canceling the observation of the specified object to the device. After the device receives the message, the terminal communication suite cancels subscribing to the specified object and checks the execution result on the terminal side.

```
AT+MIPLOBSERVERSP=0,msgid,1

OK
```
Expected results on OneNet platform side:
```
{"errno":0,"error":"succ"}
```

#### Examples of API messages that cancel observation operations under the control platform:




```
GET http://api.heclouds.com/nbiot/observe?imei=$IMEI&cancel=true&obj_id=3303 HTTP/1.1

api-key:OneNet分配的api-key

Host: api.heclouds.com

Content-Length: 21       //数值根据HTTP报文实际body大小修改

Content-Type:application/json
```
Expected response from terminal side:
```
+MIPLOBSERVE:0,msgid,0,3303,-1,-1
```

#### 3.6. Equipment cancellation process








```
AT+MIPLCLOSE=0

OK

在OneNet平台侧查看终端离线状态(图标为灰色)，终端离线则判定注销成功。

AT+MIPLDELETE=0（ref值通常为0）

OK

终端侧向OneNet平台侧发起注册过程，注册失败则判定删除通信套件成功。

AT+MIPLDELOBJ=0,3306

OK

终端侧向OneNet平台侧注销后再次注册，检查OneNet平台侧下发的discover请求，discover请求中不包含3306则判定对象3306删除成功
```
#### Examples of API Messages Judging Log-off Operations under Control Platform



```
GET http://api.heclouds.com/devices/status?imei=$IMEI&devIds=DEVICE_ID HTTP/1.1

Host: api.heclouds.com/

api-key: OneNet分配的api-key

Content-Length: 0
```
Expected response from terminal side:
```
online : false
```

```
注：用户亦可在向平台发送注销请求后执行销毁实例，此时模组会自动删除所有object。

用户亦可直接执行销毁实例，模组将会在向平台提出注销请求后删除object再销毁Object以及通信实例。
```