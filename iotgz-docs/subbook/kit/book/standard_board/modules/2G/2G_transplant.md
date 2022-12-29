# **2G例程移植**

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

本文档使用的例程路径是——>G程序代码\麒麟座开发板\麒麟座V3.2\2.kyLin-V3.2-OneNET-裸机-基础例程\5.M6312-HTTP_TYPE1-三轴加速计


### **2、修改devid和apikey**

修改NET\protocol\src\m6312.c里面的devid和apikey


```
#define DEVID	"5616708"
#define APIKEY	"kPl=kf99QxL2acVvVCHssUPWZKs="
```




