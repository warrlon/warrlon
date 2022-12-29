# 安连宝SDK集成说明 #

SDK（**MTK7628** 和**MTK7621**平台）下载地址：

https://github.com/tztmp/CMIOT-ALB

注：如需其他平台请联系中移物联网技术支持人员

## 概述： ##
本文档介绍了硬件平台为MTK7628或MTK7621，软件平台为OpenWRT方式下安连宝SDK的集成方法，如有其他平台请联系中移物联网技术支持人员。
### 1.	环境要求 ###
内核要求：Linux内核版本3.14及以上
硬件平台：mips架构
当前支持的CPU：MTK7628、MTK7621
外部包依赖：libnfnetlink、libnetfilter-queue、libmnl、libpthread、kmod-ipt-conntrack、libstdcpp。
推荐软件平台：OpenWRT
### 2.	获取设备信息接口 ###
需提供获取设备基本信息的接口：
1.	获取设备名称接口
2.	获取设备序列号（SN）接口
3.	获取设备软件版本接口
4.	获取设备硬件版本接口
推荐的接口格式（基于OpenWRT的UCI方式）：
设备名称（DEV_NAME）		uci get custom.info.module
设备SN（DEV_SN）				uci get custom.info.sn
设备软件版本（SW_VER）		uci get custom.info.software
设备硬件版本（HW_VER）		uci get custom.info.hardware

### 3.	SDK各组件简介 ###
1.	公共库
Libmifi
该模块为与设备相关的接口的适配模块
2.	连接平台&设备管理组件
Mifi
该模块与安全云平台对接，定时上报设备运行信息，负责设备管理和黑白名单管理等功能。
3.	HTTP域名和IP管理模块
该模块负责对黑白名单中的HTTP网址或IP进行拦截和上报。
mifi_udp_http
HttpAndDns(内核模块)
4.	HTTPS域名和IP管理模块
该模块负责对黑白名单中的HTTPS网址或IP进行拦截和上报。
mifi_udp_https
HTTPS(内核模块)
### 4.	安连宝SDK安装步骤 ###
安连宝SDK使用OpenWRT的OPKG包管理机制，安装包以IPK格式打包，可以采用配置页面上设备包管理进行安装，也可在shell下进行安装，本文介绍MTK7628平台设备shell下的安装方式。具体安装步骤如下：
①	解压ALBSDK_MTK7628_0520_V1.7z文件
解压完成后目录下有ALBSDK和ONENET两个文件夹，ALBSDK文件夹下是安连宝SDK的安装包，ONENET文件夹下是定制化的OneNet EDP组件，该组件支持快速连接到ONENET平台。
②	在设备上选择一个可读写目录，使用SCP或者其他方式将ALB文件夹下的安装包拷贝到该目录，具体要拷贝的文件如下：
kmod-HttpAndDns_3.10.14-3_ramips_24kec.ipk
kmod-HTTPS_3.10.14-3_ramips_24kec.ipk
libmifi_2.1.0-1_ramips_24kec.ipk
mifi_1.1.0_ramips_24kec.ipk
mifi_udp_http_1.2.0_ramips_24kec.ipk
mifi_udp_https_1.2.0_ramips_24kec.ipk
③	安装SDK的相关IPK包
执行以下命令进行安装：
opkg install kmod-HttpAndDns_3.10.14-3_ramips_24kec.ipk
opkg install kmod-HTTPS_3.10.14-3_ramips_24kec.ipk
opkg install libmifi_2.1.0-1_ramips_24kec.ipk
opkg install mifi_1.1.0_ramips_24kec.ipk
opkg install mifi_udp_http_1.2.0_ramips_24kec.ipk
opkg install mifi_udp_https_1.2.0_ramips_24kec.ipk
安装过程中有任何问题请联系中移物联网的技术支持人员。
④	检查安装情况
检查内核模块安装情况：

![](/images/safe-image/内核模块.jpg)
 
上图表示内核模块已正常加载。

检查用户进程安装情况

![](/images/safe-image/进程安装.jpg)
 
上图表示用户进程安装成功。
### 5.	安连宝SDK相关配置 ###
1.	mifi程序配置文件
配置文件mifi.conf用于安全云平台的tcp服务器地址和端口的配置。
该文件位于/etc/mifi目录。
文件内容如下图：

![](/images/safe-image/文件内容.jpg)
 
IP = 139.224.14.18设置的是云平台服务器的ip地址。
PORT = 8844设置的是云平台服务器的端口。
注意：修改该文件可能会使安连宝SDK功能失效，除非确实必要，请不要修改。如有修改需要，建议先与中移物联网技术支持人员联系。
2.	mifi_udp_http/mifi_udp_https恶意网址拦截上报程序配置文件
配置文件docom.conf用于udp网址拦截上报服务器地址和端口的配置。应用程序会把恶意网址拦截的记录上报到该文件配置的服务器上。此外，当应用程序不确定一个网址是否安全时，也会将该网址上报到云服务器上分析，云服务器将分析结果下发到应用程序。
该文件位于/etc/docom/目录。
文件内容如下：

![](/images/safe-image/文件内容2.jpg)
 
注意：修改该文件可能会使安连宝SDK功能失效，除非确实必要，请不要修改。如有修改需要，建议先与中移物联网技术支持人员联系。
3.	黑白名单配置文件urls
该文件用于保存SDK本地的黑白名单策略。内核模块根据该配置文件对特定的网址执行拦截或者放行动作。
该文件位于/etc/docom目录。
文件内容如下：

![](/images/safe-image/文件内容3.jpg)
 
0开头的网址表示白名单，1开头的网址表示黑名单。
具体策略是当白名单模式开启时，0开头的网址会被放行，除了这些网址之外的其他网址都会被拦截。黑名单模式开启时，1开头的网址会被拦截，除了这些网址外的其他网址都会被放行。
说明：黑白名单的配置可以通过云平台来维护，不建议在本地修改。

