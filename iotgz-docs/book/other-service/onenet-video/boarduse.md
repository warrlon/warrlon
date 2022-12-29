# 开发板直播体验

*Usart/开发板启动*

打开超级终端。插上与串口连接的出口线(若笔记本电脑无串口，可使用串口-USB转换器)，开发板启动，超级终端输出界面。如无相关经验，可参考附录1的1.3.2章节

![pic](/images/vedio-image/开发板直播体验01.png)

可通过超级终端输入相关命令进行交互比如ls

![pic](/images/vedio-image/开发板直播体验02.png)

*按键*

输入命令./saradc_test 执行saradc_test程序，可测试按键。

![pic](/images/vedio-image/开发板直播体验03.png)

*以太网*

通过ifconfig设置IP地址，并通过ping命令测试网络

![pic](/images/vedio-image/开发板直播体验04.png)

![pic](/images/vedio-image/开发板直播体验05.png)

*Wifi*

接入wifi热点，其中Baiduiot为热点名称，LinuxIOT123为wifi密码，需替换为自己的wifi信息。

```
./wpa_passphrase Baiduiot "LinuxIOT123" >> /usr/wpa_supplicant.conf
./wpa_supplicant -Dwext -ira0 -c/usr/wpa_supplicant.conf -B
```

![pic](/images/vedio-image/开发板直播体验06.png)

获取IP

```
ifconfig ra0 `udhcpc -i  ra0 | grep 'Lease of'| awk '{print $3}'`
route add default gw `ifconfig|grep 'inet addr'|grep -v '127.0.0.1'|cut -d: -f2 |awk '{print $1}'|awk '{split($0,ip,"." ); printf "%s.%s.%s.1\n",ip[1],ip[2],ip[3] }'`
```

![pic](/images/vedio-image/开发板直播体验07.png)

测试

![pic](/images/vedio-image/开发板直播体验08.png)

*TF卡*

通过命令```mount -t vfat /dev/mmcblk0p1 /usr/tfcar```d挂载tf卡

![pic](/images/vedio-image/开发板直播体验09.png)

*音频*

通过执行audio_livesound测试音频的输入和输出

![pic](/images/vedio-image/开发板直播体验10.png)

*视频*

进入/mnt/mtd ,执行rtspd程序，可在PC端通过VLC等播放器播放实时视频。

![pic](/images/vedio-image/开发板直播体验11.png)

![pic](/images/vedio-image/开发板直播体验12.png)

**功能介绍**

功能演示需通过与开发板交互完成，若无嵌入式linux使用或开发经验，请先阅读附录1，并按照附录1.3.2完成超级终端的安装。

*设置网络*

开发板配置wifi和有线两种网络通信方式，开发者可自由选择任意一种。

有线网络

设置IP地址命令：ifconfig eth0 192.168.200.172

设置网络命令：route add default gw 192.168.200.1  

*WIFI*

进入/usr/onenet目录,并打开wifi.sh，将其中的wifi名称和wifi密码改成需设定的wifi名称和wifi密码，并保存。

![pic](/images/vedio-image/开发板直播体验13.png)

执行wifi.sh脚本，连接wifi。sh wifi.sh

*注：所有体验实验都需要网络，请务必先设置网络。*

**视频直播体验**

目的：让用户快速体验视频能力。

OneNET 视频体验实验功能:

以官方SDK为基础，实现视频直播功能。

体验流程：

请按照[https://open.iot.10086.cn/doc/art388.html#68](https://open.iot.10086.cn/doc/art388.html#68)中介绍的步骤，在onenet中创建视频产品和设备，并获取产品ID和注册码。产品管理页获取产品ID，注册码

![pic](/images/vedio-image/开发板直播体验14.png)

进入开发板目录 /usr/onenet

使用vi config.json命令修改config.json文件

![pic](/images/vedio-image/开发板直播体验15.png)

将productid、pass的值修改为上面所创建视频设备的产品ID，注册码，deviceid可设置为0，id可自主设置。

运行./sample_test

![pic](/images/vedio-image/开发板直播体验16.png)

通过onenet视频管理页面即可观看视频