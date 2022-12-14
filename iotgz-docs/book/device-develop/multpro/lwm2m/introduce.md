# LwM2M简介

LwM2M协议OMA组织制定的轻量化的M2M协议，主要面向基于蜂窝的窄带物联网（Narrow Band Internet of Things, NB-IoT）场景下物联网应用，聚焦于低功耗广覆盖（LPWA）物联网（IoT）市场，是一种可在全球范围内广泛应用的新兴技术。具有覆盖广、连接多、速率低、成本低、功耗低、架构优等特点。

## 功能特点

NB-IoT具备四大特点：

- 广覆盖：在同样的频段下，NB-IoT比现有的网络增益20dB，相当于提升了100倍覆盖区域的能力；
- 大连接：轻松支持大量设备联网需求，具备支撑海量连接的能力，NB-IoT一个扇区能够支持10万个连接；
- 低功耗：聚焦小数据量、小速率应用特别对于一些不能经常更换电池的设备和场合，理论上NB-IoT终端模块的待机时间可长达10年；
- 低成本：预期的单个接连模块不超过5美元；

基于NB-IOT的LwM2M协议和CoAP协议实现UE与OneNET平台的通信，其中实现数据传输协议中传输层协议为CoAP，应用层协议LwM2M协议实现。

Coap协议有以下特点：

- 基于轻量级的UDP协议之上，具有重传机制
- 协议支持IP多播
- 协议包头小，仅为4个字节
- 功耗低，适用于低功耗物联网场景

LwM2M协议适用于轻量级的协议适用于各种物联网设备，LwM2M定义了三个逻辑实体:

- LwM2M Server 服务器；
- LwM2M Client 客户端，负责执行服务器的命令和上报执行结果；
- LwM2M 引导服务器 Bootstrap Server，负责配置LwM2M客户端。

## 典型应用场景

LwM2M协议（NB-IoT）是基于UDP协议之上具有重传机制的轻量级M2M协议，主要面向基于蜂窝的窄带物联网（Narrow Band Internet of Things, NB-IoT）场景下物联网应用，聚焦于低功耗广覆盖（LPWA）物联网（IoT）市场，是一种可在全球范围内广泛应用的新兴技术。

广泛适用于对电量需求低、覆盖深度高，终端设备海量连接以及设备成本敏感的环境。可以广泛应用于智能停车、智能抄表、智能井盖、智能路灯等应用场景。