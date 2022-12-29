# **WIFI例程移植**

## **移植前准备**

### **硬件准备**

- 开发板（比如OneNET标准板、迷你板，或者其他具有一定RAM和串口通信能力的单片机的板子，推荐16位单片机以上）
- 下载器（比如说ST-link，J-link等）
- USB转串口模块（主要是为了方便对模组进行调试）


### **软件准备**

- keil MDK软件
- 下载器的驱动
- USB转串口模块的驱动
- 单片机的BSP

## **移植步骤**

### **1、打开工程文件**

本文档使用的例程路径是——>程序代码\麒麟座开发板\麒麟座V3.2\2.kyLin-V3.2-OneNET-裸机-基础例程\4.ESP8266-HTTP_TYPE3-温湿度


### **2、修改WIFI账号以及密码**

修改NET\device\src\esp8266.c下的WIFI账号及密码


```
#define ESP8266_WIFI_INFO		"AT+CWJAP=\"ONENET\",\"IOT@Chinamobile123\"\r\n"
```

### **3、修改devid和apikey**

修改NET\protocol\src\esp8266.c里面的devid和apikey


```
#define DEVID	"5616708"
#define APIKEY	"kPl=kf99QxL2acVvVCHssUPWZKs="
```









