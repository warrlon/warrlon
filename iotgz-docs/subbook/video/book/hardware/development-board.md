# 视频开发板简介

OneNET视频全功能开发板是为具备开发能力的用户设计的功能验证性视频硬件设备，意在帮助用户和开发者熟悉OneNET的视频能力，让开发者了解和熟悉OneNET 视频SDK，以及如何应用OneNET视频SDK快速搭建基于OneNET的视频监控系统、安防系统以及直播系统。同时，开发板配备了外部数据采集监测、摄像头抓拍监测、内存监测等小实验，让开发者熟悉在嵌入式linux环境下如何快速开发OneNET物联网应用。

## 模块介绍

**核心控制模块--GM8136S**

开发板采用Grain Media公司的GM8136S作为核心处理器，以此提供OneNET视频能力应用于IPC领域的模板。<br>Grain Media的IP摄像机SoC GM8136S嵌入了使用ARM@CPU内核和集成多种外围控制器，可开发IP摄像机，车载DVR和家庭监控系统等多种应用。<br>GM8136S的视频编码器引擎提供H.264 HP/MP/BP编码器；可以提供高质量的视频性能和满足低宽带要求。广泛的系统外围元件，包括视频捕获，显示控制器，加密控制器，串行I/F控制器，USB2.0 OTG和10/100M以太网控制器，使GM8136S能够支持大多数具有成本效益的监控应用产品。

**接口介绍**

![pic1](/images/vedio-image/开发板介绍01.png)

|种类 | 规格 |  数量  |
|-|-|-|
|中央处理器 | GM8136S:32位RISC,Sip 1Gb DDR 720@60fps | x1 |
|指示灯 | 电源指示灯 | x1 |
|指示灯 | 状态指示灯 | x4 |
|操作按键 | 功能按键 | x8 |
|摄像头模组 | OV9712 100万像素 | x1 |
|电源电路 | 5V转3.3V | x1|
|调试接口 | DB9串口调试接口 | x1 |
|供电接口 | 5V电源输入接口 | x4 |
|输出接口 | 串口 | x1 |
|输出接口 | USB | x1 |
|扩展接口 | PWM | x1 |
|扩展接口 | I2C | x1|
|扩展接口 | ADC | x2 |
|扩展接口 | 红外 | x1|
|扩展接口 | 3.3V | x1|
|通信接口 | wifi | x1 |
|通信接口 | 网卡 | x1|
|FLASH芯片 | W25Q128F | x1 |
|存储接口 | TF卡接口 | x1|

## 开发板基本功能体验

**开发板上电**

接上5V电源适配器，按下开关，开发板上电。正常状态下：LED1灯亮。

![pic1](/images/vedio-image/开发板介绍25.png)

**Usart/开发板启动**

打开超级终端。插上与串口连接的出口线(若笔记本电脑无串口，可使用串口-USB转换器)，开发板启动，超级终端输出界面。

![pic1](/images/vedio-image/开发板介绍26.png)

可通过超级终端输入相关命令进行交互比如ls

![pic1](/images/vedio-image/开发板介绍27.png)

**按键**

输入命令./saradc_test 执行saradc_test程序，可测试按键。

![pic1](/images/vedio-image/开发板介绍28.png)

**以外网**

通过ifconfig设置IP地址，并通过ping命令测试网络

![pic1](/images/vedio-image/开发板介绍29.png)
![pic1](/images/vedio-image/开发板介绍30.png)

**WIFI**

接入wifi热点，其中Baiduiot为热点名称，LinuxIOT123为wifi密码，需替换为自己的wifi信息。
```
./wpa_passphrase Baiduiot "LinuxIOT123" >> /usr/wpa_supplicant.conf
./wpa_supplicant -Dwext -ira0 -c/usr/wpa_supplicant.conf -B
```

![pic1](/images/vedio-image/开发板介绍31.png)

获取IP

```
ifconfig ra0 udhcpc -i  ra0 | grep 'Lease of'| awk '{print $3}'<br>route add default gw ifconfig|grep 'inet addr'|grep -v '127.0.0.1'|cut -d: -f2 |awk '{print $1}'|awk '{split($0,ip,"." ); printf "%s.%s.%s.1\n",ip[1],ip[2],ip[3] }
```
![pic1](/images/vedio-image/开发板介绍32.png)

测试

![pic1](/images/vedio-image/开发板介绍33.png)


**TF卡**

通过命令mount -t vfat /dev/mmcblk0p1 /usr/tfcard挂载tf卡

![pic1](/images/vedio-image/开发板介绍34.png)

**音频**

通过执行audio_livesound测试音频的输入和输出

![pic1](/images/vedio-image/开发板介绍35.png)

**视频**

进入/mnt/mtd ,执行rtspd程序，可在PC端通过VLC等播放器播放实时视频。

![pic1](/images/vedio-image/开发板介绍36.png)
![pic1](/images/vedio-image/开发板介绍37.png)

## 开发板基本功能体验

体验演示需通过与开发板交互完成

**开发板交互**

可在超级终端输入相关命令进行开发板操作，例如设置系统时间
输入命令:date 2018.08.22-10:14:00,即可将系统设置为所需要时间。

**设置网络**

开发板配置wifi和有线两种网络通信方式，开发者可自由选择任意一种。
- 有线网络<br>设置IP地址命令：ifconfig eth0 192.168.200.172<br>设置网络命令：route add default gw 192.168.200.1  
- WIFI<br>进入/usr/onenet目录,并打开wifi.sh，将其中的wifi名称和wifi密码改成需设定的wifi名称和wifi密码，并保存。

![pic1](/images/vedio-image/开发板介绍38.png)

执行wifi.sh脚本，连接wifi。sh wifi.sh<br><b>注：所有体验实验都需要网络，请务必先设置网络。</b>

**视频直播体验**

目的：让用户快速体验视频能力。<br>OneNET 视频体验实验功能:<br>以官方SDK为基础，实现视频直播功能。<br>体验流程：<br>请按照OneNET创建产品的步骤，创建视频产品和设备，并获取产品ID和注册码。

![pic1](/images/vedio-image/开发板介绍39.png)

进入开发板目录 /usr/onenet<br>使用vi config.json命令修改config.json文件
 
![pic1](/images/vedio-image/开发板介绍40.png)

将productid、pass的值修改为上面所创建视频设备的产品ID，注册码，deviceid可设置为0，id可自主设置。<br>运行./sample_test

![pic1](/images/vedio-image/开发板介绍41.png)

通过onenet视频管理页面即可观看视频

![pic1](/images/vedio-image/开发板介绍42.png)