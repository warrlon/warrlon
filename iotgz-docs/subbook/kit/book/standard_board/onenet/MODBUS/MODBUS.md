##1.5.4 MODBUS  
* 产品与设备的创建  
创建产品：[https://open.iot.10086.cn/doc/multiprotocol/book/get-start/product&device/product-create.html](https://open.iot.10086.cn/doc/multiprotocol/book/get-start/product&device/product-create.html "创建产品")  
创建设备：[https://open.iot.10086.cn/doc/multiprotocol/book/get-start/product&device/device-create/single-device.html](https://open.iot.10086.cn/doc/multiprotocol/book/get-start/product&device/device-create/single-device.html "创建设备")  
* 协议初识  
[https://open.iot.10086.cn/doc/multiprotocol/book/develop/modbus/device/introduce.html](https://open.iot.10086.cn/doc/multiprotocol/book/develop/modbus/device/introduce.html "MODBUS简介")  
* 需要下载的资料  
程序代码\麒麟座开发板\麒麟座V3.2\2.kyLin-V3.2-OneNET-裸机-基础例程\10.ESP8266-MODBUS-LED  
程序代码\麒麟座开发板\麒麟座V3.2\2.kyLin-V3.2-OneNET-裸机-基础例程\11.ESP8266-MODBUS-温湿度  
* 设备登陆  
1.打开工程stm32f103.uvprojx  

![工程目录](project_dir.jpg)  

2.打开工程目录下OneNET->onenet.c文件，修改第41行、43行和45行的设备登陆参数，分别对应产品ID、DTU序列号、DTU密码  

![登陆信息](login_information.jpg)  

3.打开工程目录下的net_device->esp8266.c文件，修改第37行的AP连接参数 

![wifi信息](wifi.jpg)  

4.配置MDK下载方式  

![配置下载方式](download.jpg)  

5.编译、下载代码到目标板  
6.给目标板上电，观察该设备在OneNET上的在线情况  
MODBUS协议登陆成功后平台不返回任何数据，相反，如果登陆失败平台会断开TCP连接，所以判断登陆是否成功，就检查设备TCP连接是否断开  

![设备在线](dev_online.jpg)  

![连接成功-串口打印](connect_print.jpg)  

* 数据上传  
使用例程 11.ESP8266-MODBUS-温湿度 来演示数据上传  
然后在设备里 数据流展示->添加采样数据数据流  

![数据公式配置1](config_data1.jpg)  

![数据公式配置2](config_data2.jpg)  

MODBUS协议的设备是被动设备，设备不主动上传数据，需要等待平台周期性的查询设备数据 

![查询数据1](inquire_data1.jpg)  

![查询数据2](inquire_data2.jpg)  

![上传数据](data_upload.jpg)  

* 命令下发  
使用例程 10.ESP8266-MODBUS-LED 来演示命令下发  
在main.c的170行~198行有相关控制命令，需要按照MODBUS协议规定来发送命令  
比如打开红色LED，发送命令：010400010001600A 即可  

![命令列表](cmd_list.jpg)    

* 例程移植  
以FreeRTOS例程为例  

![工程目录1](project_dir1.jpg)  

core：硬件平台相关启动代码，不同平台需替换  
FreeRTOS：RTOS相关代码，需移植到对应硬件平台使用  
fwlib：硬件平台相关底层驱动，不同平台需替换  
mcu_fun：硬件平台驱动中间件，其他平台下可自行实现或不用该中间件  
driver：属于硬件平台驱动，不同平台需要自行实现  
hardware：外设硬件驱动，根据实际硬件编写相应驱动程序  
user：主逻辑代码，主要实现用户应用  
net_task：网络相关任务，不需要修改，但可以调整数据上传间隔、心跳维持时间间隔  
OneNET：与OneNET数据交互应用层，无需修改  
net_protocol：协议层，只需修改H文件里边内存分配规则即可  
net_device：网络模组驱动层，需根据实际硬件来编写对应的驱动代码  