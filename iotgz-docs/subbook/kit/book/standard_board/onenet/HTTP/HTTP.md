##1.5.2 HTTP  
* 产品与设备的创建  
创建产品：[https://open.iot.10086.cn/doc/multiprotocol/book/get-start/product&device/product-create.html](https://open.iot.10086.cn/doc/multiprotocol/book/get-start/product&device/product-create.html "创建产品")  
创建设备：[https://open.iot.10086.cn/doc/multiprotocol/book/get-start/product&device/device-create/single-device.html](https://open.iot.10086.cn/doc/multiprotocol/book/get-start/product&device/device-create/single-device.html "创建设备")  
* 协议初识  
[https://open.iot.10086.cn/doc/multiprotocol/book/develop/http/api/api-usage.html](https://open.iot.10086.cn/doc/multiprotocol/book/develop/http/api/api-usage.html "HTTP简介")  
* 需要下载的资料  
程序代码\麒麟座开发板\麒麟座V3.2\2.kyLin-V3.2-OneNET-裸机-基础例程\4.ESP8266-HTTP_TYPE3-温湿度  
* 上传数据  
因HTTP协议属短连接，在OneNET平台上没有在线和离线标志，设备只需要在成功连接HTTP服务器IP、PORT之后，即可向对应设备上传数据  
1.打开工程stm32f103.uvprojx  

![工程目录](project_dir.jpg)  

2.打开工程目录下net_protocol->onenet.c文件，修改第40行、42行的设备登陆参数，分别对应设备ID、APIKEY  

![登陆信息](login_information.jpg)  

3.打开工程目录下的net_device->esp8266.c文件，修改第36行的AP连接参数  

![wifi信息](wifi.jpg)  

4.配置MDK下载方式  

![配置下载方式](download.jpg)  

5.编译、下载代码到目标板  
6.给目标板上电，然后在OneNET网页端观察设备数据  

![数据展示](datastream.jpg)  

![数据上传](data_upload.jpg)  

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