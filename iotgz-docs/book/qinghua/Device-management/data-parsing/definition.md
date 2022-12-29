# 数据解析

# 什么是数据解析

#### 1. 服务概述

平台与设备通过OneJSON数据协议进行通信，OneJSON是一套基于JSON的用户层协议，具有可读性高的特点，能够直观展示数据交互细节。但在物联网场景中，存在低配置且资源受限的设备，往往不适合直接使用JSON数据格式，而是采用二进制数据格式与平台进行通信。针对该应用场景，平台提供数据解析功能，支持通过编写数据解析脚本实现自定义数据格式（二进制）与标准物模型数据格式之间的转换。如下为数据解析整体流程：

![服务概述](/images\qinghua\device-management\data-parsing-process.png)

数据解析脚本定义设备与平台间数据处理规则。设备上报数据时，平台将接收数据先运行解析脚本，将自定义数据转换成标准物模型数据，再进行后续业务处理。平台下发命令给设备时，也会先通过数据解析脚本将物模型数据转换为设备侧自定义数据，再下发给设备。  
使用流程：数据解析功能包括产品创建、产品物模型定义、数据脚本开发及设备端逻辑开发四个步骤。

- **产品创建**

数据解析功能只支持产品节点类型为直连设备，且接入协议为MQTT或LwM2M。产品创建时，需要选择数据协议为透传/自定义，具体操作参见[我的产品](/book/qinghua/Device-management/product-management/my-product.md)中**添加产品**章节。

- **产品物模型定义**

产品定义物模型，将设备侧功能按照属性、服务和事件三种类型功能点进行抽象及描述，具体操作参见[开发产品物模型](/book/qinghua/Device-management/dproduct-object-models/introduce.md)。

- **数据脚本开发**

数据解析脚本定义了设备自定义二进制数据与平台物模型Json数据间解析、转换规则。按照平台规范完成上下行解析函数编写、调试及发布后，平台即可对设备数据进行处理，脚本具体操作见[脚本开发](/book/qinghua/Device-management/data-parsing/script-development.md)。

- **设备逻辑开发**

平台定义了MQTT协议、LwM2M协议使用自定义数据通信的专属资源信息，用户按照规范完成设备业务逻辑开发，即可使用自定义数据格式与平台进行上下行通信，具体操作见：[MQTT设备开发](/book/qinghua/Device-management/data-parsing/mqtt-device-development.md)、[LmM2M设备开发](/book\qinghua\Device-management\data-parsing\LWM2M-device-development.md)。
