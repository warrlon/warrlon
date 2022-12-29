# NB-IoT物联网套件

NB-IoT物联网套件为用户提供“终端-平台-应用”整体解决方案，帮助企业快速实现NB-IoT能力升级。

**终端侧**通过移植SDK可以实现基于轻量化的CoAP+LwM2M协议进行传输，降低物联网终端功耗。同时目前已有80多款模组已经移植平台的SDK，终端设备可基于预集成的模组，使用AT指令快速实现接入平台和数据业务。

**平台侧**可实现与中国移动NB-IoT网络无缝对接，满足大量设备的快速入云，同时实现对设备的资源订阅、数据存储、数据转发、命令下发（即时|缓存）、远程升级（OTA）、安全传输等功能。

**应用侧**提供丰富的API接口，使物联网企业可以更加专注于自身应用的开发，而不用将工作重心放在设备接入层的环境搭建上，从而缩短物联网系统的形成周期，降低企业研发、运营和运维成本。


## 快速入门

通过阅读下列文档，快速了解NB-IoT物联网套件。

- [了解NB-IoT物联网套件整体功能介绍](/book/introduce/introduce.md)
- [了解NB-IoT物联网套件资源模型](/book/introduce/resource-model.md)
- [创建属于我的第一个产品](/book/get-start/product&device/createProduct.md)

## 设备开发

下列文档将能帮助您快速了解如何进行设备开发，更多详情请见“设备开发指南”中各协议介绍。

- [了解设备接入协议规范](https://open.iot.10086.cn/doc/easy-manual/book/product&device/protocal-introduce.html)
- [了解LwM2M+CoAP协议简介](/book/device-develop/LwM2M_protocol.md)
- [了解LwM2M协议接入流程](/book/device-develop/access.md)
- [查看OneNET平台目前支持的模组列表](/book/device-develop/module-list.md)
- [查看NB-IoT设备（M5310模组）的接入实例](/book/example/M5310_access_template.md)
- [我是模组厂商，要移植LwM2M协议的SDK](/book/device-develop/get_SDK.md)
 
## 应用开发

下列文档有助于快速了解如何基于NB-IoT物联网套件实现应用系统的开发。

- [了解API两种鉴权认证方式](/book/application-develop/api-usage.md)
- [查看NB-IoT物联网套件API列表](/book/application-develop/api-list.md)
- [了解如何使用规则引擎实现服务扩展](/book/manual/rule-engine/introduce.md)
- [了解OneNET平台提供的HTTP推送功能](/book/manual/httppush.md)
- [了解消息队列服务，以实现应用层快速、即时、可靠地获取设备消息](/book/manual/MQ.md)