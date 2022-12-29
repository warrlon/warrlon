# 开发板介绍

OneNET视频全功能开发板意在帮助用户和开发者熟悉OneNET的视频能力，让开发者了解和熟悉OneNET 视频SDK，以及如何应用OneNET视频SDK快速搭建基于OneNET的视频监控系统、安防系统以及直播系统。同时，开发板配备了外部数据采集监测、摄像头抓拍监测、内存监测等小实验，让开发者熟悉在嵌入式linux环境下如何快速开发OneNET物联网应用。

![PIC](/images/vedio-image/开发板介绍01.png)

**MCU介绍--GM8136S**

开发板采用GM8136S作为核心处理器，GM8136S是一款为IP-CAM领域设计的高性价比SoC芯片，具有集成度高、易开发等特点。

*电源接口*

输入电源为5V，接口如下图所示，请使用官方配置适配器接入电源。

![PIC](/images/vedio-image/开发板介绍02.png)
电源接口原理图

![PIC](/images/vedio-image/开发板介绍03.png)
电源接口实物图

*以太网接口*

开发板提供100M以太网，请根据需求配置IP地址使用

![PIC](/images/vedio-image/开发板介绍04.png)
以太网接口原理图

![PIC](/images/vedio-image/开发板介绍05.png)
以太网接口实物图

*串口*

串口主要用于用户开发者与开发板交互，搭配官方所配的USB转串口线使用

![PIC](/images/vedio-image/开发板介绍06.png)
串口原理图

![PIC](/images/vedio-image/开发板介绍07.png)
串口实物图

*USB/WIFI*

USB可外插USB 设备。

USB接口与WIFI共用一个USB通道，因此二者不可同时使用，需通过SW15拨码开关进行配置，当拨码开关1、2处于连通状态(开关靠近ON)，可用USB接口；当拨码开关3、4处于连通状态(开关靠近ON)，可用WIFI；

![PIC](/images/vedio-image/开发板介绍08.png)
USB/WIFI实物图

*按键*

配置8个按键，通过AD采样实现按键区分。

![PIC](/images/vedio-image/开发板介绍09.png)
按键原理图

![PIC](/images/vedio-image/开发板介绍10.png)
按键实物图

*摄像头接口*

请配合官方配置摄像头使用

![PIC](/images/vedio-image/开发板介绍11.png)
摄像头接口原理图

![PIC](/images/vedio-image/开发板介绍12.png)
摄像头实物图

*MIC接口*

配置咪头MIC，供开发者进行语音应用开发。

![PIC](/images/vedio-image/开发板介绍13.png)
MIC接口原理图

![PIC](/images/vedio-image/开发板介绍14.png)
MIC接口实物图

*耳机接口*

配置耳机接口，供开发者进行语音应用开发。

![PIC](/images/vedio-image/开发板介绍15.png)
耳机接口原理图

![PIC](/images/vedio-image/开发板介绍16.png)
耳机接口实物图

*TF卡*

开发板可使用TF卡作为外部存储

![PIC](/images/vedio-image/开发板介绍17.png)
TF卡原理图

![PIC](/images/vedio-image/开发板介绍18.png)
TF卡实物图

*LED*

配置4路LED

![PIC](/images/vedio-image/开发板介绍19.png)
LED原理图

![PIC](/images/vedio-image/开发板介绍20.png)
LED 实物图

*综合接口*

扩展接口提供一路USART、一路PWM、一路I2C、一路红外、两路ADC供开发者使用。

![PIC](/images/vedio-image/开发板介绍21.png)
综合接口原理图

![PIC](/images/vedio-image/开发板介绍22.png)
综合接口实物图
 
*配置开关*
 
配置开关与系统启动相关，请保持SW14 1,2处于断开状态，否则系统无法启动。
 
![PIC](/images/vedio-image/开发板介绍23.png)
配置开关原理图
  
![PIC](/images/vedio-image/开发板介绍24.png)
配置开关实物图
