# 基于M5310模组实现NB设备接入实例

## 1、上电初始化

注意：每个AT命令之间应该留有一定时间间隔

|M5310|                                          |
|---|---|
|OK|							//开机启动信息|
|AT|							//开机之后循环发送AT直到返回OK，证明模块初始化正常|
|OK|                                             |
|AT+COPS=1,2,"46000"|				//设置手动注册移动运营MNC|
|OK|
|AT+NEARFCN=0,3555|//锁定频点为3555，锁频可以有效减小搜网时间，但是频点设置错误会导<br>			//致搜网失败，建议通常情况下不要设置锁频|
|OK|                                             |
|AT+CSCON=1|					//打开信号提示自动上报|
|OK|                                             |
|AT+CEREG=1|					//打开注册信息自动上报|
|OK|                                             |
|+CSCON:1|						//自动上报的网络信号提示——已连接|
|+CEREG:1,19E6,94,7|				    //自动上报的网络注册信息——1-本地网络已注册入网，5-漫游已<br>							    //注册，其它情况为注册异常，详细请参考AT命令手册							//如果未使能自动上报，则用户需要使用AT+CEREG?查询注册状态
|AT+CGDCONT？|                                             |
|+CGDCONT:0,"IP",<br>"nbiot.MNC002.MCC460.GPRS",,0,0|//查询当前APN，此步骤可省略|
|OK|-|

```text
注：需要确认入网状态为已注册才能进行后续数据收发操作，如果不使用自动上报功能，
可使用AT+CEREG? 命令主动查询当前注册状态直到变为已注册，目前测试开机注册时间范围为20s-120s  
```


## 2、UDP数据收发

### 2.1、创建UDP Socket
```text
AT+NSOCR=`<type>`,`<protocol>`,`<listen prt>`[,`<receive control>`]
```

例如：

|AT+NSOCR="DGRAM",17,2334,1|//创建本地UDP监听端口，开启数据到达自动上报|
|:---|---|
|0|					//创建成功返回socket编号，数值0-6，最多监听7个端口|
|OK|						//创建UDP成功|

### 2.2、发送UDP数据

```text
向目的UDP地址发送数据可使用AT+NSOST或AT+NSOSTF命令，如下，
AT+NSOST=`<socket>`,`<remote_addr>`,`<remote_port>`,`<length>`,`<data>`
AT+NSOSTF=`<socket>`,`<remote_addr>`,`<remote_port>`,`<flag>`,`<length>`,`<data>`
```
例如：

|AT+NSOST=0,183.230.40.150,<br>36000,10,30313233343536373839|---|
|:---|---|
|0,10|                            //第0号Socket成功发送10 Byte UDP数据|
|OK|                                                        |
|+NSONMI:0,30  |                 //第0号Socket接收到30 Bytes数据|

 ### 2.3、接收UDP数据

```text
当接收到UDP数据时，可以使用AT+NSORF读取，当读取长度大于实际接收长度时，返回缓冲区实际接收数据长度
```

|AT+NSORF=`<socket>`,`<req_length>`|---| 
|:---|---|
|+NSONMI:0,30|				//提示第0号Socket接收到30 Bytes数据|
|AT+NSORF=0,30|				//读取接收到的30Bytes数据，|
|0,183.230.40.150,36000,30,<br>5B3131372E3136392E33362E<br>31353A323137395D30313233343536373839,0|//读取到183.230.40.150:36000发过来的30Bytes数据

```text
注：本示例的测试服务器为中移物联网公司内部测试服务器，会自动回复”[远程IP:端口]接收数据”，只做测试用途，不保证服务器功能。
```

### 2.4、关闭UDP 

|AT+NSOCL=`<socket>`|//`<socket>`为2.1创建时系统分配的id|
|:---|---|---|
|OK| - |  


## 3、OneNET数据收发

### 3.1、OneNET 平台端创建设备

```text
访问OneNET门户网站：http://open.iot.10086.cn/ ，创建NB-IOT产品及设备。
创建设备所使用的鉴权信息imei及imsi需要记录并在终端登录时使用，返回的device_id为平台端创建的设备接入标识，
如果需要查询设备信息，需要提供设备id
```

### 3.2、设备注册流程
  
#### （1）版本统一与创建基础通信套件

|AT+MIPLVER?|
|:---|
|+MIPLVER: 版本号|
|OK|
|该指令验证终端基础通信套件版本是否符合送测声明，直接在客户端读取通信套件版本信息，并将读取的版本信息与送测时声明的版本对比。|
|AT+MIPLCREATE|
|+MIPLCREATE:ref值(通常为0)|
|OK|
|为基础通信套件添加对象和实例，并从终端侧向OneNet平台侧发起注册过程，注册成功则判定创建通信套件成功。|  

#### （2）向通信套件添加object组

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
具体的编码规范可参照IPSO规范或OMA模型规范http://www.openmobilealliance.org/wp/OMNA/LwM2M/LwM2MRegistry.html。
```
```text
终端侧向OneNet平台侧注册，检查OneNet平台侧下发的discover请求，discover请求中包含3303、3306则判定添加成功。
```
#### （3）发起注册请求

#### A、注册操作

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

 #### 控制平台下判断注册操作的API报文示例
```text
GET http://api.heclouds.com/devices/status?imei=$IMEI&devIds=$DEVICE_ID HTTP/1.1   
Host: api.heclouds.com/  
api-key: OneNet分配的api-key  
Content-Length: 0  
终端侧预期回复：online : true
```

 ### B、无参数更新注册
```text
AT+MIPLUPDATE=0,0,0
OK
+MIPLEVENT:0,11
终端侧在本次lifetime周期之内发送不携带参数的更新注册信息到平台侧,
平台侧对该更新注册信息回应,确认检查终端侧是否收到平台侧的回应。
```
### C、参数变动更新注册
```text
AT+MIPLUPDATE=0,3600,1
OK
+MIPLEVENT:0,11
终端侧在本次lifetime周期之内发送携带参数的更新注册信息到平台侧，
平台侧对该更新注册信息回应确认，检查终端侧是否收到平台侧的回应。
```

### 3.3、数据上报流程
![](/images/LwM2M/数据上报流程.jpg)
### 用户上报数据
```text
AT+MIPLNOTIFY=0,msgid1,3303,0,5700,4,4,98,0,0

OK

AT+MIPLNOTIFY=0,msgid2,3303,0,5601,4,4,88,0,0

OK

在OneNet平台侧查看终端上报最新数据和历史数据，数据完整且正确则判定成功。
```
### 控制平台下判断注销操作的API报文示例
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

### 3.4、设备Bootstrap流程
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
### 控制平台下判断Bootstrap操作的API报文示例
```
GET http://api.heclouds.com/devices/status?imei=$IMEI&devIds=$DEVICE_ID HTTP/1.1

Host: api.heclouds.com/

api-key: OneNet分配的api-key

Content-Length: 0
```
```
终端侧预期回复：online : true
```

### 3.5、设备管理流程
 
![](/images/LwM2M/设备管理流程.jpg)

```
设备管理目前版本提供6操作：discover、read、write、execute、write-attributes、observe、

MCU应在执行平台下发的规定操作后数秒内（建议3s）上报对应操作结果，否则传输信息可能丢失。
```
**（1）	discover操作**

设备发送注册请求到平台侧，检查设备接收到的平台侧信息中的Discover请求信息，并回应Discover请求，在平台侧检查设备资源情况。
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
#### 控制平台下获取discover状态的API报文示例:
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
### （2）read操作

#### A、读取resource请求

平台侧向设备发送指定资源的Read操作请求，设备收到消息后，终端通信套件获取设备的资源值信息返回给平台侧，在平台侧检查读取结果。

```
AT+MIPLREADRSP=0,msgid,1,3303,0,5700,4,4,20.123,0,0

OK
```
```
OneNet平台侧预期结果：

{"errno":0,"data":[{"res":[{"val":20.123,"res_id":5700}],"obj_inst_id":0}],"error":"succ"}
```
#### 控制平台下读操作的API报文示例:
```
GET http://api.heclouds.com/nbiot?imei=$IMEI&obj_id=3303&obj_inst_id=0&res_id=5700 HTTP/1.1

Host: api.heclouds.com/

api-key: OneNet分配的api-key

Content-Length: 0
```

终端侧预期回复：
```
+MIPLREAD:0,msgid,3303,0,5700 
```

#### B、读取instance请求

平台侧向设备发送指定实例的Read操作请求，设备收到消息后，终端通信套件获取设备的实例资源信息返回给平台侧，在平台侧检查读取结果。
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

OneNet平台侧预期结果：
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
#### 控制平台下读操作的API报文示例:
```
GET http://api.heclouds.com/nbiot?imei=$IMEI&obj_id=3303&obj_inst_id=0 HTTP/1.1

Host: api.heclouds.com/

api-key: OneNet分配的api-key

Content-Length: 0
```
终端侧预期回复：
```
+MIPLREAD:0,msgid,3303,0,-1
```

#### C、读取object请求

平台侧向设备发送指定对象的Read操作请求,设备收到消息后，终端通信套件获取设备的对象实例资源信息返回给平台侧,在平台侧检查读取结果。
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
OneNET平台侧预期结果：
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
#### 控制平台下读操作的API报文示例:
```
GET http://api.heclouds.com/nbiot?imei=$IMEI&obj_id=3303 HTTP/1.1

Host: api.heclouds.com/

api-key: OneNet分配的api-key

Content-Length: 0
```
终端侧预期回复：
```
+MIPLREAD:0,msgid,3303,-1,-1
```
#### 资源读取API报文协议如下：

|操作|	Read（资源读取）|
|:---|---|---|
|LwM2M-URI|	address /{Object ID}/{Object Instance ID}/{Resource ID}
|参数说明|	{ Object ID }：必选，如设备上的传感器类型；<br>{ Object Instance ID }：可选，该类型传感器的编号；<br>{Resource ID}：可选，该传感器的某种类型的数据，如温度的当前值，最大值等|
|CoAP-Method|	GET|
|CoAP-Option	Option| 1：Uri-Path（11）：{Object ID}<br>Option 2：Uri-Path（11）：{Object Instance ID}<br>Option 3：Uri-Path（11）：{Resource ID}<br>Option 4：Accept（17）： 第1节中的Content Format表中的类型，如application/vnd.oma.LwM2M+tlv这个参数是指明读取数据的格式。|
|CoAP-payload|-|
|Success|	2.05 Content|
|Failure|	4.00 Bad Request,  4.01 Unauthorized, 4.04 Not Found, 4.05 Method Not Allowed|
```
注：每次read操作后模块响应上报COAP报文长度应小于512Bytes。
```
### （3）	write操作

#### A、写入source请求

平台侧向设备发送指定资源的Write操作请求，设备收到消息后，终端通信套件将指定值写入指定资源，在终端侧检查写入结果。
```
AT+MIPLWRITERSP=0,msgid,2

OK
```
OneNet平台侧预期结果：
```
{"errno":0,"error":"succ"}
```

#### 控制平台下写操作的API报文示例：
```
POST http://api.heclouds.com/nbiot?imei=$IMEI&obj_id=3306&obj_inst_id=0&mode=2 HTTP/1.1  

Host: api.heclouds.com/  

api-key: OneNet分配的api-key  

Content-Length: 47       //数值根据HTTP报文实际body大小修改  

Content-Type:application/json  

HTTP内容：{"data":[{"res_id":5850,"val":1}]}  
```
终端侧预期回复：
```
+MIPLWRITE:0,msgid,3306,0,5850,2,1,01,0,0
```
#### B、写入instance请求

平台侧向设备发送指定实例的Write操作请求，设备收到消息后，终端通信套件将指定值写入指定实例下的资源，在终端侧检查写入结果。
```
AT+MIPLWRITERSP=0,msgid,2

OK
```
OneNet平台侧预期结果：
```
{"errno":0,"error":"succ"}
```

#### 控制平台下写操作的API报文示例：
```
POST http://api.heclouds.com/nbiot?imei=$IMEI&obj_id=3306&obj_inst_id=0&mode=2 HTTP/1.1

Host: api.heclouds.com/

api-key: OneNet分配的api-key

Content-Length: 47       //数值根据HTTP报文实际body大小修改

Content-Type:application/json

HTTP内容：{"data":[{"res_id":5850,"val":1},{"res_id":5851,"val":22}]}
```
终端侧预期回复：
```
+MIPLWRITE:0,msgid,3306,0,5850,2,1,01,0,1

+MIPLWRITE:0,msgid,3306,0,5851,2,1,16,0,0
```

**资源写入API报文协议如下：**

|操作|	Write（资源写入）|
|:---|---|---|
|LwM2M-URI|	address /{Object ID}/{Object Instance ID}/{Resource ID}/{NewValue}|
|参数说明	{ Object ID }：必选，如设备上的传感器类型；|{ Object Instance ID }：必选，该类型传感器的编号；<br>{Resource ID}：必选，该传感器的某种类型的数据，如温度的当前值，最大值等；<br>{NewValue}：必选，写入的资源属性值。|
|CoAP-Method	PUT/POST|CoAP-Option	Option 1：Uri-Path（11）：{Object ID}<br>Option 2：Uri-Path（11）：{Object Instance ID}<br>Option 3：Uri-Path（11）：{Resource ID}<br>Option 4：Content-Format（12）：格式为Content Format表中的几种格式，<br>如application/vnd.oma.LwM2M+tlv|
|CoAP-payload|	{NewValue}，数据格式为Option4中指定的数据格式|
|Success|	2.04 Changed|
|Failure|	4.00 Bad Request,  4.01 Unauthorized, 4.04 Not Found, 4.05 Method Not Allowed|

注：每次write操作下发COAP报文长度应小于512Bytes，故下发数据段长度最大480Bytes。
 
#### （4）	execute操作

平台侧向设备发送指定资源的Exec操作请求，设备收到消息后，终端通信套件将操作值写入指定资源，在终端侧检查执行结果。
```
AT+MIPLEXECUTERSP=0,msgid,2

OK
```
OneNet平台侧预期结果：
```
{"errno":0,"error":"succ"}
```

#### 控制平台下发execute消息的API报文示例：
```
POST http://api.heclouds.com/nbiot/execute?imei=$IMEI&obj_id=3303&obj_inst_id=0&res_id=5605 HTTP/1.1

api-key:OneNet分配的api-key

Host: api.heclouds.com

Content-Length: 21       //数值根据HTTP报文实际body大小修改

Content-Type:application/json

HTTP内容：{"args":"reset"}
```
终端侧预期回复：
```
+MIPLEXECUTE:0,msgid,3303,0,5605,5, "reset"
```

#### 资源执行API报文协议如下：


|操作|	Execute（资源执行）|
|:---|---|---|
|LwM2M-URI|	address /{Object ID}/{Object Instance ID}/{Resource ID}/{Arguments}|
|参数说明|	{ Object ID }：必选，如设备上的传感器类型；<br>{ Object Instance ID }：必选，该类型传感器的编号；<br>{Resource ID}：必选，该传感器的某种类型的数据，如温度的当前值，最大值等；<br>{Arguments}：可选，待执行的命令，如重启，关机等。|
|CoAP-Method|	POST|
|CoAP-Option|	Option 1：Uri-Path（11）：{Object ID}<br>Option 2：Uri-Path（11）：{Object Instance ID}<br>Option 3：Uri-Path（11）：{Resource ID}|
|CoAP-payload|	{Arguments}，格式为Content Format表中的text/plain格式|
|Success|	2.05 Changed|
|Failure|	4.00 Bad Request,  4.01 Unauthorized, 4.04 Not Found, 4.05 Method Not Allowed|

```
注:每次execute操作下发COAP报文长度应小于512Bytes，故下发数据段长度最大480Bytes。
```
#### （5）	Write-Attributes操作

平台侧向设备发送指定资源的Write-Attributes操作请求，设备收到消息后，终端通信套件将属性值写入指定资源，在终端侧检查执行结果。
```
AT+MIPLPARAMETERRSP=0,msgid1,2

AT+MIPLPARAMETERRSP=0,msgid2,2

OK

OK
```
OneNet平台侧预期结果：
```
{"errno":0,"error":"succ"} {"errno":0,"error":"succ"}
```
#### 控制平台下发Write-Attributes消息的API报文示例：
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
终端侧预期回复：
```
+MIPLPARAMETER:0,msgid1,3303,0,5700,37,"pmin=15;pmax=60;lt=0.0;gt=50.0;st=2.0"

+MIPLPARAMETER:0,msgid2,3303,0,5601,37,"pmin=18;pmax=90;lt=0.0;gt=60.0;st=2.0"
```

#### （6）	Observe操作

#### A、观察resource请求

平台侧向设备发送指定资源的Observe操作请求，设备收到消息后，终端通信套件订阅指定资源，在终端侧检查执行结果。
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
OneNet平台侧预期结果：
```
{"errno":0,"error":"succ"}

{"errno":0,"error":"succ"}
```

#### 控制平台下观察操作的API报文示例:
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
终端侧预期回复：
```
+MIPLPARAMETER:0,msgid1,3303,0,5700,37,"pmin=15;pmax=60;lt=0.0;gt=50.0;st=2.0"

+MIPLPARAMETER:0,msgid2,3303,0,5601,37,"pmin=18;pmax=90;lt=0.0;gt=60.0;st=2.0"
```

#### B、观察instance请求

平台侧向设备发送指定实例的Observe操作请求，设备收到消息后，终端通信套件订阅指定实例，在终端侧检查执行结果。
```
AT+MIPLOBSERVERSP=0,msgid,1

OK
```
OneNet平台侧预期结果：
```
{"errno":0,"error":"succ"}
```

控制平台下观察操作的API报文示例:
```
GET http://api.heclouds.com/nbiot/observe?imei=$IMEI&cancel=false&obj_id=3303&obj_inst_id=0 HTTP/1.1

api-key:OneNet分配的api-key

Host: api.heclouds.com

Content-Length: 21       //数值根据HTTP报文实际body大小修改

Content-Type:application/json
```
终端侧预期回复：
```
+MIPLOBSERVE:0,msgid,1,3303,0,-1
```

#### C、观察object请求

平台侧向设备发送指定对象的Observe操作请求，设备收到消息后，终端通信套件订阅指定对象，在终端侧检查执行结果。
```
AT+MIPLOBSERVERSP=0,msgid,1

OK
```
OneNet平台侧预期结果：
```
{"errno":0,"error":"succ"}
```

#### 控制平台下观察操作的API报文示例:
```
GET http://api.heclouds.com/nbiot/observe?imei=$IMEI&cancel=false&obj_id=3303 HTTP/1.1

api-key:OneNet分配的api-key

Host: api.heclouds.com

Content-Length: 21       //数值根据HTTP报文实际body大小修改

Content-Type:application/json
```
终端侧预期回复：
```
+MIPLOBSERVE:0,msgid,1,3303,-1,-1
```

#### D、取消观察resource请求

平台侧向设备发送指定资源的取消观察的操作请求，设备收到消息后，终端通信套件取消订阅指定资源，在终端侧检查执行结果。
```
AT+MIPLOBSERVERSP=0,msgid,1

OK
```
OneNet平台侧预期结果：
```
{"errno":0,"error":"succ"}
```

#### 控制平台下取消观察操作的API报文示例:
```
GET http://api.heclouds.com/nbiot/observe?imei=$IMEI&cancel=true&obj_id=3303&obj_inst_id=0&res_id=5700 HTTP/1.1

api-key:OneNet分配的api-key

Host: api.heclouds.com

Content-Length: 21       //数值根据HTTP报文实际body大小修改

Content-Type:application/json
```
终端侧预期回复：
```
+MIPLOBSERVE:0,msgid,0,3303,0,5700
```
#### E、取消观察instance请求

平台侧向设备发送指定实例的取消观察的操作请求，设备收到消息后，终端通信套件取消订阅指定实例，在终端侧检查执行结果。
```
AT+MIPLOBSERVERSP=0,msgid,1

OK
```
OneNet平台侧预期结果：
```
{"errno":0,"error":"succ"}
```

#### 控制平台下取消观察操作的API报文示例:
```
GET http://api.heclouds.com/nbiot/observe?imei=$IMEI&cancel=true&obj_id=3303&obj_inst_id=0 HTTP/1.1

api-key:OneNet分配的api-key

Host: api.heclouds.com

Content-Length: 21       //数值根据HTTP报文实际body大小修改

Content-Type:application/json
```
终端侧预期回复：
```
+MIPLOBSERVE:0,msgid,0,3303,0,-1
```

#### F、取消观察odject请求

平台侧向设备发送指定对象的取消观察的操作请求，设备收到消息后，终端通信套件取消订阅指定对象，在终端侧检查执行结果。
```
AT+MIPLOBSERVERSP=0,msgid,1

OK
```
OneNet平台侧预期结果：
```
{"errno":0,"error":"succ"}
```

#### 控制平台下取消观察操作的API报文示例:
```
GET http://api.heclouds.com/nbiot/observe?imei=$IMEI&cancel=true&obj_id=3303 HTTP/1.1

api-key:OneNet分配的api-key

Host: api.heclouds.com

Content-Length: 21       //数值根据HTTP报文实际body大小修改

Content-Type:application/json
```
终端侧预期回复：
```
+MIPLOBSERVE:0,msgid,0,3303,-1,-1
```

#### 3.6、设备注销流程
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
#### 控制平台下判断注销操作的API报文示例
```
GET http://api.heclouds.com/devices/status?imei=$IMEI&devIds=DEVICE_ID HTTP/1.1

Host: api.heclouds.com/

api-key: OneNet分配的api-key

Content-Length: 0
```
终端侧预期回复：
```
online : false
```
```
注：用户亦可在向平台发送注销请求后执行销毁实例，此时模组会自动删除所有object。

用户亦可直接执行销毁实例，模组将会在向平台提出注销请求后删除object再销毁Object以及通信实例。
```