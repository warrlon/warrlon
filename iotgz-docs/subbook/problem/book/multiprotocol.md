# 多协议接入

#### 1.MQTT协议的设备保活时间keepalive是否有限制？

新版MQTT（MQTT套件）为 10-1800S，旧版MQTT（多协议-MQTT）为 1-1200S。

#### 2.MQTT(旧)协议的设备发送ping服务器无响应，是什么原因？

应该是组包有问题。官网有模拟器，可以发ping包，有应答的，对比下。

#### 3.MQTT(旧)协议的下发命令能一次对多个设备下发命令吗？

不能，但你可以让你的所有设备订阅一个topic，然后往这个topic发数据，需要自行开发，进行群发操作。

#### 4.HTTP协议的设备显示离线是什么问题？

HTTP协议就显示离线，数据正常上报没问题，因为HTTP短连接。要显示在线状态请换TCP或者MQTT协议。

#### 5.HTTP协议的设备掉线后再重启，可以不用再与平台配置吗？

可以不用。

#### 6.数据能发送到OneNET但是平台上显示离线，是什么原因？

这种情况应该是HTTP协议连接的平台，因为HTTP是短连接的，设备不会显示在线，但是能往OneNET平台POST数据。

#### 7.使用EDP协议会掉线吗？有没有防掉线的一些步骤的？

EDP协议基于TCP的，想要不断开掉线，是需要发报文维持连接的，可以发数据，可以发心跳。

#### 8.EDP协议是不是只能向OneNET传数字，字符能传吗？

都可以。字符和数字都是最后传输的二进制码流。

#### 9.EDP协议连接OneNET发点儿数据就掉线了，是什么原因？

数据格式有问题，被服务器关闭了链接，也可能你没响应服务器的回复要求。

#### 10.TCP透传如何查询设备历史数据？

通过查询设备历史数据的API接口获得设备历史数据。

#### 11.TCP透传发送数据超时时间一般设置多少合适呢？

2秒足够。2g网络的话，信号不好可能会比较长时间，搞不清楚设置个3到5秒，再超时就当错误处理。

#### 12.TCP透传需要发怎样的指令设备才能立即离线？

断开socket就离线了。

#### 13.配置是TCP透传，数据都是lua解析。当接收到服务器的下发命令后，怎么把数据上传到这个响应里面？

TCP透传命令不支持响应，只能单方面下发。

#### 14.TCP透传怎样接收到字符类型的数据？

改lua脚本。

#### 15.TCP透传有没办法确切知道DTU是否执行命令成功，现在OneNET只知道命令有没发送到DTU？

只能通过你执行过后上报一个执行状态的数据流，来完成反馈，因为透传的命令本身不支持反馈。

#### 16.使用TCP透传，如何使终端发送一条数据给服务器，服务器将这条数据解析成中文，并在数据流中显示？

上传utf8编码的中文字符串即可。

#### 17.添加完设备后如何关联脚本呢？

TCP设备上传第一包报文含有关联的脚本名称，进行关联，*$PID#$AUTH_INFO#$PARSER_NAME*。
