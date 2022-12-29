# 技术类

**1.电信联通的物联网卡可以连接OneNET平台么？**

答：可以，除电信的NB卡只能连接OC平台，其余物联网卡都可以的。

**2.触发器的邮箱可以修改么？**

答：触发器邮箱只能是注册时绑定的邮箱，如若想更换邮箱可点击安全设置>邮箱换绑

![pic1](/images/faq/1技术类/1.png)

**3.平台的数据流可以删除么？如何删除？**

答：数据流现在可以删除，开发者中心>数据流模板>操作>删除按钮

![pic2](/images/faq/1技术类/2.png)

**4.平台的数据可以导出、删除、修改和分析处理么？如何实现？**

答：目前平台提供API供用户进行数据/设备管理

**5.如何查看在平台发送的命令是否成功？**

答：如果在应用调用的API指令成功后，OneNET平台会返回执行结果。

**6.能否将多个设备的数据流放在同一应用中？**

答：独立应用可以，一个独立应用中可以有多个应用元件，不同元件可以对应不同的设备数据流

![pic3](/images/faq/1技术类/3.jpg)

**7.平台上设备删除后可以恢复么？怎么恢复？**

答：平台设备删除后，不能恢复 

**8.设备ID可以用户自己设置么？还是OneNET自动生成？**

答：设备ID 都是由平台自动生成的

**9.OneNET向第三方平台推送消息，一直出现您设置的数据推送已连续多次失败，即将达到平台上限，然后就会中断链接，这是什么情况？**

答：这种情况可能是应用与OneNET平台已断开连接，OneNET在没有收到应用确认的情况下，会一直推送数据，直到2000条才停止推送。

**10.创建产品是不是只能指定一种接入协议？**

答：用户根据应用场景选择一种协议，一个设备只能按照一种协议与平台交互

**11.一个产品下面可以创建多少设备？**

答：一个产品下可以创建多个设备，根据实名认证的不同类型，有不同的限制，详见[账户认证](//book/get-start/account.md)

**12.一个设备下面可以添加多少数据流？**

答：一个设备下可以创建多个数据流，目前平台不限制数量

**13.OneNET的数据能保存多长时间？容量是多大？**

答：OneNET平台数据保存时间为一年，容量不限

**14.请问一个数据流可以传送两种及两种以上的不同数据么？**

答：不可以，建议创建两个不同的数据流

**15.为什么上传到OneNET的数据一会儿是图一会儿是点？**

答：上传到平台的数据都是以数据点的形式上传，平台不支持图片展示功能

**16.独立应用和模板应用的区别，如何使用模板应用？**

答：

独立应用：独立应用中包含的数据信息可以同时取自多个设备。应用是唯一的，无法复用在其他设备上。

模板应用：模板应用中包含的数据信息仅能来自单一设备，每个设备都能够套用该模板。通过设备来启用模板应用时，模板应用里显示的数据均来自该设备。而要套用该模板的设备必须拥有模板中所要求的所有数据流

**17.如何将模板应用转化成独立应用？**

答：模板应用不能转化成独立应用

**18.OneNET可以批量添加/删除设备吗？**

答：平台提供批量添加删除设备的API，正确调用API可以实现批量添加和删除

**19.OneNET怎么下发数据给设备？**

答：平台向设备发送数据使用不同协议有不同的发送方式，详细方式见使用协议接入文档

**20.OneNET用http不可以传输视频么？**

答：目前不支持

**21.OneNET怎么实现判断设备是否在线吗？**

答：产品页面设备名称前指示灯显示绿色为设备在线，当显示灰色时为设备离线

**22.NB产品下IMEI号删除之后显示已重复，不能添加设备？**

答：模组上带的IMEI号只能绑定在唯一的平台设备上，平台不支持重复添加。遇到此问题，建议用户先删除已有设备，若非自己添加，请联系模组提供方删除设备或者更换模组。

**23.第三方平台认证成功后，服务器推送的数据，在哪接收呢？**

答：配置第三方应用时配置的url，服务器向该url推送数据

**24.第三方平台的数据推送失败后，OneNET可以实现手工触发推送吗？**

答：可以

**25.OneNET对接第三方平台只能http么？**

答：支持http或者https

**26.前手机号码丢失如何完成改绑？**

答：可以在安全设置中改绑手机号码，如果前手机号码已注销或丢失，那么不能完成改绑

**27.OneNET_config_v1.2.exe 如何使用？**

答：OneNET_config_v1.2.exe是注册码生成工具，在cmd中输入工具所在路径，并按要求填写各个参数运行即可

**28.触发器如果达到设定值的时候会给邮箱发信息，但是会一直发送，怎么才让它只发一次？**

答：在创建触发器时触发条件选择为inout方式时，数据流首次进出区间触发器响应一次，保持在区间不会持续响应，不同触发方式的不同点可参考应用接入文档中触发器api章节

**29.OneNET平台的个人账号和企业账号都是什么功能，有什么区别？**

答：目前用户认证功能已上线，个人账号与企业账号在功能上有部分差异，企业账号享有更多权限，如果通过了个人认证，可再次升级进行企业认证。具体内容详见[账户认证](/book/get-start/account.md)

**30.企业账户申请流程（企业认证流程）？**

答：认证功能上线之后，已经取消了企业账户的注册入口，如想完成企业注册，即可先进行平台用户注册>登录>个人资料>企业认证

**31.在应用编辑器里如何能够根据数据流改变显示的图片？**

答：将图片进行上传后，在图片下方填入相应数据流的值，当有对应数据值进行上传，就会切换到对应的图片。

**32.产品创建完成之后，可以修改通信协议么？**

答：不可以修改的，如果能修改了，那么产品下面的设备鉴权信息和方式会发生变化，会造成混乱。

**33.在OneNET平台创建添加设备以后，设备能够上线，但是平台显示设备“该设备不支持发现资源”，这个是怎么回事？**

答：LwM2M协议设备登录OneNET平台，首先需要在订阅Object组和订阅Resource参数，参考使用模组的AT指令先后步骤来完成登录前的配置。

**34.OneNET 离线设备如何重新登录？**

答：设备离线后，重新登录和初次登录步骤相同。如果为保证设备不出现掉线，及时发送心跳包。LwM2M协议的设备及时发送AT+MIPLUPDAT指令。

**35.服务器配置自动停用是什么原因？**

答：第三方服务器推送停用主要有两种原因：一是24小时之内出现连续推送失败的记录，二是某一条消息因为推送不过去导致连续失败2000次。

**36.FOTA设备列表里没有设备，如何添加？**

答：FOTA新建群组选择模组型号的时候，必须与你的设备的模组型号对应，这样FOTA设备列表里就会有设备。需要模组型号支持才会显示设备，然后进行添加。

**37.设备注册和设备添加有什么区别？**

答：设备添加通过产品的Api-key进行新增，设备注册通过产品的正式环境注册码Register-code进行新增。两者取得的效果都是新增设备。

**38.在应用里，一个地图可以显示多个设备位置么？**

答：不可以，不支持多个坐标显示，地图控件只能选择一个数据流，也就是一个点坐标。

**39.订阅主题数量有限制么？一个产品下面可发多少topic?一个设备最多能订阅多少个主题?**

答：有限制的，一个MQTT产品下面最多能支持100个自定义topic，一个设备最多能订阅50个主题。

**40.离线命令的超时时间如何设置？**

答：设置timeout参数，命令有效时间，默认0。0：在线命令，若设备在线，下发给设备，若设备离线，直接丢弃。>0： 离线命令，若设备在线，下发给设备；若设备离线，在当前时间加timeout时间内为有效期，有效期内，若设备上线，则下发给设备。单位：秒。有效范围：0~2678400。

**41.OneNET可以在应用管理里面滑动查看历史的数据曲线吗？**

答：不可以，数据曲线目前只能展示最新的数据点的值。

**42.设备管理中的正式环境注册码是怎么用的?**

答：在调用注册设备的api会使用到注册码进行设备注册。

**43.TCP透传如何查询设备历史数据？**

答：通过查询设备历史数据的API接口获得设备历史数据。

**44.OneNET的地图如何使用？**

答：从基站获取参数，往平台特殊指定数据流上报信息见位置服务

**45.接收到平台推送的数据，需要返回什么？**

答：需要在5秒内给OneNET响应http请求的成功状态码。

**46.推送的服务总是被停掉是怎么回事？**

答：首先会重复推送，但是累积重推条数达到2000次或者连续出现24小时都有重推消息，两者中出现一种会停掉推送功能。

**47.创建的产品或者设备不小心删除了，还能恢复么？**

答：不能。

**48.如果设备断网，OneNET多久才发现设备掉线？**

答：会等到保活时间lifetime到期后，OneNET才发现设备掉线。

**49.透传模式下，Ａ设备怎样传数据到Ｂ设备？**

答：设备之前的通信建议使用mqtt协议来实现。A设备发布主题，B设备订阅该主题。

**50.下发命令时没有提示参数错误，为什么读缓存命令执行情况时提示，执行状态是：请求参数错误?**

答：这个错误一般是资源类型和参数中的类型不一致导致的，这个只能在执行中才会判断。

**51.如果推送没收到应用的回复，会一直推送吗？**

答：首先会重复推送，但是累积重复条数达到2000次或者连续24小时会停掉推送功能。

**52.自定义resid有什么要求吗？**

答：流程跟正常一样，差别就是自定义object,instance和resource的ID，只要不与OMA定义的重合就可以。

**53.在第三方开发平台配置URL的时候总是校验token失败怎么办？**

答：在提交验证时采用get方法传三个参数nonce、msg、signature，返回结果没有正确返回msg的值，比如在msg值中多返回其他符号，都会验证失败。

**54.OneNET平台下发的命令该如何切割？**

答：分块传输。API下发命令最大2kb，然后分块最大是512字节。

**55.API里有根据MasterKey获取产品ID的方法吗？**

答：产品ID目前没有相关API可以使用，其他API详见开发文档应用开发。

**56.OneNET上每个设备的缓存命令可以有多少条？**

答：NB的设备目前最多缓存10条，其他设备没有限制。

**57.超过注册的存活时间会怎么样？**

答：设备会从OneNET平台离线。

**58.写设备资源和命令下发，有什么区别吗？**

答：写和执行均可对设备进行命令操作，执行只支持字符串下发，写的类型支持更多。

**59.即时命令和缓存命令有什么区别？**

答：下发即时命令需要设备在线且下行端口没有老化的时候才能抵达设备，缓存命令可以在设备离线的时候下发，等待有上行数据的时候抵达设备。

**60.数据能发送到OneNET但是平台上显示离线，是什么原因？**

答：这种情况应该是http协议连接的平台，因为http是短连接的，设备不会显示在线，但是能往OneNET平台POST数据。

**61.目前NB的模组有支持GPS定位的吗？**

答：模组本身是不支持的，可以外接GPS传感器实现。

**62.和网可以直接通过2G物联网卡连接自己的DTU-modbus吗？**

答：可以

**63.5106  OneNET返回给服务器这个是什么错误？**

答：TIME_OUT 是因为平台没有在超时时间内（25秒）收到设备的响应，有几种可能：

1）网络连接session被核心网回收，NB-IOT 设备通过核心网连接到平台，如果设备在一段时间内（各地情况不一，通常为几分钟）没有上行和下行的活动，核心网会回收连接，此时平台下发的消息无法到达设备

2）网络问题，NB-IOT 的网络不稳定，尽管CoAP 有重传机制，仍然有可能在25秒内无法完成平台到设备的请求响应的全过程。

**64.Fixed header里，Remaing length是什么？**

答：后面总长度字节。

**65.解压后的代码文件中文乱码，怎么解决？**

答：改字体，UTF-8最好。

**66.创建设备，说 auth_info 参数有误 
<br/>OneNET 请求错误：
url = https://api.heclouds.com/devices
params = {protocol=LwM2M, psk=P123123123123123123, auth_info={123123123123123123=123123123123123123}, title=测试-pan}
error = invalid parameter: auth_info</br>**

答：header需要apikey。

**67.在官方例程程序的哪个部分可以改我配置的wifi和密码？**

答：WIFI_info。

**68.设备上报数据到平台的地址是什么?**

答：每个协议接入的IP加端口不一样，详情参考[平台地址](/book/problem/platformaddress.md)。

**69.有线网络走mqtt数据协议格式可以吗，用lwip？**

答：可以的，那就用lwipIP里面的socket接口去对接OneNET就可以了。

**70.每个NB设备的离线缓存命令最大只能是10条吗？**

答：是的。

**71.OneNET上是不是没有建立数据库的权限？只能与第三方服务器进行对接？**

答：是的。

**72.一个群组里面关联的设备有限制吗？一个账户可以设置群数有限制吗？**

答：都没有。

**73.WiFi设置AP模式，可以往里面写指定WiFi账号密码让它连接吗？**

答：应该是不能直接串口写入的，请参考8266AT指令集。

**74.移动平台设备保活时间lifetime是多久？这个决定哪些参数？**

答：平台最大支持2的31次方减1秒。这个参数一般可以通过AT+MIPLOPEN或者AT+MIPLUPDATE改变他的值。

**75.应用侧有群发命令给所有设备的API吗？**

答：目前MQTT协议可以变相去实现这个功能，一个产品下MQTT的设备可以订阅相同的topic，达到发布一个topic，订阅了该topic的设备都能收到。

**76.AT+MIPLNOTIFY怎么一次传输多个整数？**

答：目前MQTT协议可以变相去实现这个功能，一个产品下MQTT的设备可以订阅相同的topic，达到发布一个topic，订阅了该topic的设备都能收到。

**77.我在服务端下发一下close命令，客户端收命令后关机，但重启后还是收到了 CLOSE命令。这是什么问题?<br>mqtt svrpublish $creq/c457c6f7-7c14-5314-9148-3294abe48687 nil close**

答：和qos有关，0：最多发送一次，不关心设备是否响应
1：至少发送一次，如果设备收到命令后没有应答，则会在下一次设备登录时若命令在有效期内（有效期定义参见timeout参数）则会重发该命令。

**78.OneNET开发文档中注册与新增的区别是什么？**

答：新增设备是通过masterkey作为验证；而masterkey的权限很高。如果不想把masterkey给出去，就用注册的方式，只给注册码即可验证，注册码只能用于注册，权限较低。 该功能针对于一个产品下有多个设备供应商的情况，给设备供应商注册码即可，不用给masterkey。

**79.请问OneNET平台测试的时间最快多长时间，1s一次可能吗？**

答：每秒一次，可以。但NB通讯协议不支持那么高频率，一般要求5秒以上间隔。

**80.AUTH_INFO 填什么？**

答：鉴权信息，创建设备时自定义的。现在一般不填，模组还没有适配这个字段。

**81.利用js或者ajax可以接入OneNET吗？**

答：两个都行，有个后端的nodejs的sdk 也有适用ajax的c#。

**82.给设备下发即时命令，平台反馈timeout是怎么回事？**

答：这个需要你设备回复，设备没回复就是timeout。

**83.我需要一个上传数据和云端控制的功能，应该选择什么协议？**

答：MQTT、EDP。

**84. 设备在线要用哪个协议？**

答：MQTT、EDP、LwM2M、TCP。

**85.OneNET平台支不支持私网通道？**

答：不支持。

**86.用EDP协议，数据可以正常上传，但设备不显示在线。**

答：用debugger登录即可。

**87.用Onenet平台的LwM2M协议要不要定期给平台发送心跳包？**

答：不用，lifetime里面可以随时发notify上报数据。

**88.用MQTT协议上传数据在平台上不显示，提示是上传成功的。**

答：只能往topic为$dp的数据流发，OneNET才以数据流的形式展示出来，详见MQTT协议文档。

**89.请问http推送的URL是怎么配置验证的？**

答：官网开发文档里有详细说明，第三方服务端要返回msg。
用户在配置页面完成配置并点击“提交”时，OneNET平台会向填写URL地址发送HTTP GET请求进行URL验证，请求形式示例如下：
http://url?msg=xxx&nonce=xxx&signature=xxx
其中，url为用户在页面配置时填写的URL，nonce、msg、signature用于URL及token的验证
token验证过程如下：
将配置页面中配置的token与nonce、msg的值计算MD5，并且编码为Base64字符串值
将上一步中Base64字符串值通过URL Decode计算后的值与请求参数signature的值进行对比，如果相等则表示token验证成功。
如果token验证成功，返回msg参数值，表示URL验证通过。
如果用户不想验证token，可以选择跳过MD5计算过程，直接返回msg参数值。

**90.NB-IoT怎么上报GPS数据？**

答：NB支持上报gps的资源
NB轻应用地图使用如下两个资源（任选一个）上传经纬度：
1.object id为6，resource id：0（纬度），1（经度）。
2.object id为3336，resource id：5513（纬度），5514（经度）。
在地图中选择对应设备中名为“location”的数据流即可。
使用模组M5310-A，资源3336上传经纬度举例：
AT+MIPLADDOBJ=0,3336,1,"1",0,1
AT+MIPLDISCOVERRSP=0,3336,1,9,"5513;5514"
AT+MIPLNOTIFY=0,0,3336,0,5513,1,13,"100.6474940698",0,1,21
AT+MIPLNOTIFY=0,0,3336,0,5514,1,14,"20.5371754772",0,0,22。

**91.开发板存在wifi连接不上的问题，代码上传成功，但就是连接不上？**

答：设备端调用检查检测任务的api接口就可以了。

**92.SOTA升级有没有设备类型限制？**

答：没有。能和OneNET通讯，就可以做SOTA升级。

**93.NB-IoT连接OneNET后，是一直保持连接呢？还是说过一段时间发送一个心跳包？每次都要进行设备鉴权？**

答：NB设备有生命周期的设置。生命周期内设备在线。设备需要更新生命周期。生命周期可以设置的很长，大于一天。
不需要每次都鉴权。

**94.MQTT有没有遗嘱消息？**

答：有的。

**95.有人用过应用里的轨迹控件么？怎么在应用中显示GPS轨迹？**

答：暂不支持经纬度数据流，该组件只能使用基站定位，需要设备上有基站定位信息才行。

**96.触发条件如果是inout需要两个阈值怎么传参数呢？**

答：type 为 inout 时，threshold 设置为{"lolmt":40, "uplmt":52}， 表示
数据流的值首次进入或离开闭区间[40,52]时触发。

**97.OneNET是否支持websocket方式的MQTT协议接入？**

答：可以。

**98.MQTT的一个客户端可以同时订阅多个topic吗？**

答：可以。

**99.NB模组收到缓存消息后,OneNET会回复应用服务器什么消息吗？**

答：设备回什么，是你用的模组决定的，看模组at指令手册，或者问模组产商技术支持。

**100.M5310只是一个通道，还是集成了LwM2M协议？M5310模组和OneNET平台是coap协议还是LwM2MoverCoap？**

答：5310是集成协议的LwM2MoverCoap的。

**101.OneNET平台MQTT第一包数据是publish，不会主动断开套接字吗？**

答：MQTT长连接的，只要你发的数据合法都不会断。

**102. OneNET好多对象的属性(尤其是string类型)的，不识别，显示出都是opaque类型，仅有5750,5751可识别为"string"类型。**

答：按ipso文档来的就有，如果不按文档，OneNET会把数据当成opaque方式存储和展示。

**103.OneNET平台现在支持文件下发吗？**

答：可以的，得根据设备端接入协议来看，有下发文件的接口。

**104.请问什么是保活时间？**

答：不用发心跳也不会断开连接的一个时间。

**105.请问在线调试出现这种情况是什么问题？"msg":"内部服务器数据解析失败，请稍后再试"**

答：建议使用postman，可能是在线调试工具的问题。

**106.平台显示设备在线，但是设备列表里的对象数量是0，正常吗？**

答：没有发现资源，重新走一下订阅和发现俩步骤。

**107.tcp透传怎样接收到字符类型的数据？**

答：改lua脚本。

**108.IMEI和IMSI怎么获取？**

答：获取imsi:at+cimi，获取imei:at+cgsn=1

**109.NB-IoT支持服务器主动控制指令吗？**

答：支持的，api接口下行读写执行都是服务器主动控制设备的命令。

**110.设备显示离线是什么问题？（http协议）**

答：http协议就显示离线，数据正常上报没问题，因为http短连接。要显示在线状态请换tcp或者mqtt协议。

**111.即时命令和缓存命令有啥区别？**

答：即时命令：三方平台下发命令到OneNET，OneNET立即将命令下发给设备。
缓存命令：三方平台下发命令到OneNET，设置好触发下行的条件，OneNET先把命令保存起来，等满足了条件再下发给设备。两种命令设备都需要回复到平台，平台拿到结果会立即转发给三方平台。

**112.平台上的新增APIKEY功能有什么用？**

答：是一个全新分发。如果你只想某个客户访问特定设备的数据或者进行控制的时候，就给他设备级别的apikey防止对你其他设备进行越权控制。

**113.MQTT标准的数据流格式是什么？**

答：MQTT有7种数据流格式，详见mqtt开发文档。

**114.OneNET里如何删除数据点？**

答：数据点已经上传了，就在OneNET的数据库里面，是不能随意删除的。

**115.请问M5310A可以改变波特率吗？**

答：可以改波特率，重启后会保持一段9600的波特率，然后才切换到设置的波特率。

**116.遇到HardFault_Handler怎么办？**

答：在HardFault_Handler加入while(1);并打个断点，看是从哪进去的。

**117.怎么在APP上显示上传到OneNET的图片？**

答：图片是二进制的文件格式，api拉取文件后，做格式转换。

**118.调用API老是返回auth failed，为什么？**

答：设备的编号（LwM2M协议的imei和apikey不对应，其他协议是devid和apikey不对应造成的）。

**119.应用开发环境用的是什么语言？**

答：typescript。

**120.怎么批量添加设备呢？这个是有后台来做还是开发设备的人来添加？**

答：NB的设备可以批量模组导入imei。EDP或者MQTT可以设备侧调用注册设备的API来完成。

**121.fota可以串口指令升级吗？**

答：可以。

**122.没有进入封包程序里面，直接到了else是什么问题呢？**

答：内存分配失败。

**123.请问订阅失败是什么原因？怎么解决？**

答：1.少发了ADDOBJ那条指令；2.对应平台下发的+MIPLOBSERVE没有响应。

**124.使用EDP协议会掉线吗？有没有防掉线的一些步骤的？**

答：EDP协议基于TCP的，想要不断开掉线，是需要发报文维持连接的，可以发数据，可以发心跳。

**125.OneNET的lifetime的生存周期，超过了这个时间，被平台踢下线了，我要上报数据，是要重新发起注册还是怎么来？**

答：重新发起。一般在生命周期过期之前去updata更新下。

**126.OneNET平台NB下发指令是字符串类型吗？**

答：可以，用执行execute的接口，下发字符串。

**127.OneNET的HTTP推送有免费数量限制吗？**

答：HTTP推送免费，没有数量限制。

**128.在设备列表里，显示设备状态为离线，激活状态为—未激活。这个未激活，该怎么理解呢？**

答：创建了实际从未登录过就是未激活，实际设备连接一次之后就激活了。

**129.OneNET最大一帧支持多少数据？**

答：二进制文件上传最大800K。

**130.OneNET api调用次数有限制吗？**

答：总次数没限制，但每秒调用频次限制在300次/秒。

**131.触发器中的邮箱提醒一天有次数限制吗？**

答：有，20次。

**132.HeartBeat TimeOut: 0 请问一下 串口输出这个这个是什么意思？**

答：发送的心跳没有被检测到。

**133.平台显示设备在线，串口发送AT+MIPLNOTIFY=0,3303,0,5700,"29.2",1也成功了，但是设备列表里的对象数量是0，看不到自己发送的数据，是怎么回事？**

答：没有发现资源，重新走一下订阅和发现俩步骤。