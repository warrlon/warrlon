# OneNET视频开发板接口

![step0文件](step0.png)

a) 电源接口
输入电源为5V，接口如下图所示，请使用官方配置适配器接入电源。

![step1文件](step1.png)
![step2文件](step2.png)

b) 以太网接口
开发板提供100M以太网，请根据需求配置IP地址使用

![step3文件](step3.png)
![step4文件](step4.png)

c) 串口
串口主要用于用户开发者与开发板交互，搭配官方所配的USB转串口线使用

![step5文件](step5.png)
![step6文件](step6.png)

d) USB/WIFI
USB可外插USB 设备

![step7文件](step7.png)

USB接口与WIFI共用一个USB通道，因此二者不可同时使用，需通过SW15拨码开关进行配置，当拨码开关1、2处于连通状态(开关靠近ON)，可用USB接口；当拨码开关3、4处于连通状态(开关靠近ON)，可用WIFI；

e) 按键
配置8个按键，通过AD采样实现按键区分。

![step9文件](step9.png)
![step10文件](step10.png)

f) 摄像头接口
请配合官方配置摄像头使用

![step11文件](step11.png)
![step12文件](step12.png)
![step13文件](step13.png)

g) MIC接口
配置咪头MIC，供开发者进行语音应用开发。

![step14文件](step14.png)
![step15文件](step15.png)

h) 耳机接口
配置耳机接口，供开发者进行语音应用开发。

![step16文件](step16.png)
![step17文件](step17.png)

i) TF卡
开发板可使用TF卡作为外部存储

![step18文件](step18.png)
![step19文件](step19.png)

j) LED
配置4路LED

![step20文件](step20.png)
![step21文件](step21.png)

k) 综合接口
扩展接口提供一路USART、一路PWM、一路I2C、一路红外、两路ADC供开发者使用。

![step22文件](step22.png)
![step23文件](step23.png)

l) 配置开关
配置开关与系统启动相关，请保持SW14 1,2处于断开状态，否则系统无法启动。

![step24文件](step24.png)





