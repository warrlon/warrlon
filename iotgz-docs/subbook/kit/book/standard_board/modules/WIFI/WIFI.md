# **WIFI模组**


## **WIFI模组简介**

OneNET开发板搭配了汇思锐的ESP8266-S2模组。

ESP8266-S2模组是汇思锐（hysiry）推出的小体积、低功耗、低成本嵌入式串口Wi-Fi模块，内置高性能低功耗32位微控制器，具有多种模拟、数字接口外设，3.3V单电源供电，贴片封装，外接天线连接器。

## **概述**

ESP8266-S2 WiFi模块是由深圳市汇思锐科技有限公司开发的、低功耗高性价比的嵌入式无线网络控制模块。可满足智能电网、楼宇自动化、安防、智能家居、远程医疗等物联网应用的需求。

### **主要特点：**

- 集成了Tensilica L106 超低功耗 32 位微型 MCU，带有 16位精简模式，主频支持 80 MHz 和160 MHz，支持 RTOS系统
- 集成Wi-Fi MAC/ BB/RF/PA/LNA，板载天线
- 支持标准的IEEE802.11b/g/n 协议，完整的TCP/IP 协议栈。用户可以使用该模块为现有的设备添加联网功能，也可以构建独立的网络控制器。
- 模组支持固件二次开发，用户可根据自己的需要实现各种嵌入式Wi-Fi应用。
- 提供一系列独立的固件来满足不同的应用场景，如UART——Wi-Fi透明传输、一键智能配网、各种云接入服务等


### **硬件参数**

条目|参数
---|:--:|---:
工作电压            |3.3V （3.0 ~3.6V）
工作环境温度        |-40 ~ 85°C
CPU                |TensilicaL106（超低功耗 32 位微型 MCU，带有 16 位精简模式，主频支持 80 MHz 和160 MHz，支持 RTOS）
RAM                |50KB（可用）
Flash              |16Mbit
WIFI               |@2.4 GHz，支持WPA/WPA2 安全模式
WIFI协议            |802.11 b/g/n
频率范围            |2.4 GHz ~2.5 GHz（2400 M ~ 2483.5 M）
ADC                |内置 10 bit 高精度ADC
网络协议            |支持TCP、UDP、HTTP、FTP
电流                |平均工作电流80mA，深度睡眠保持电流为 20uA，关断电流小于 5uA
待机功率            |待机状态消耗功率小于1.0mW(DTIM3)
天线                |外置I-PEX连接器
尺寸                |18.6mm *15.0mm * 3.05mm

### **其他功能**

- 支持UART、I2C、GPIO、PWM、SDIO、SPI、ADC、PWM、IR

- 内置 TR 开关、 balun、LNA、功率放大器和匹配网络

- 内置PLL、稳压器和电源管理组件 802.11b 模式下+ 20 dBm 的输出功率

- 可以兼作应用处理器 SDIO2.0、 SPI、 UART

- 2ms之内唤醒、连接并传递数据包

- 支持本地串口烧录、云端升级、主机下载烧录

- 支持Station /SoftAP / SoftAP + Station无线网络模式



**模组硬件引脚图，以及典型电路图可以参考安信可ESP8266模组硬件开发相关手册。** [安信可ESP8266模组文档](http://wiki.ai-thinker.com/esp8266)


### **功能描述**

* #### MCU

    ESP8266EX内置Tensilica L106 超低功耗32位微型MCU，带有16位精简模式，主频支持80MHz 和160MHz，支持RTOS。目前WiFi协议栈只用了20%的处理能力，其余可以用来做应用开发。MCU可通过以下接口和芯片其他部分协同工作：

  - 连接存储控制器、也可以用来访问外界Flash的编码RAM/ROM接口（iBus）；

  - 连接存储控制器的数据RAM接口（dBus）;

  - 访问控制器的AHB接口；

* #### 存储

  - 内置SRAM与ROM

      基于DemoSDK的使用SRAM情况，用户可用剩余SRAM空间为：

      - RAM < 50kB（Station模式下，连上路由后，Heap + Data区大致可有50kB左右）。

      - 目前ESP8266EX片上没有可编程ROM，用户程序存放在SPI Flash中。

  - SPI Flash

      - ESP8266EX芯片支持使用SPI接口的外置FLASH，理论**支持16MB的SPI Flash。

      - ESP8266-S2模块配置了16Mbit的SPI Flash，可满足一般客户的使用需求。

### **软件参数**

AT指令部分可以参考安信可ESP8266 WIFI模组AT指令文档


## **下载**

- [AT指令使用示例](doc/AT_demo.pdf)
- [WIFI模组 AT 指令手册](doc/AT_instruction_set.pdf)

## **注意事项**

- OneNET开发板上的TX，RX跳线帽一定要接到WIFI部分





