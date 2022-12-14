# 清华大学校园物联应用综合管理服务平台

# 平台简介

清华大学物联平台（文档中简称“物联平台”）围绕信息建设“统一谋划、统一部署、统一推进、统一实施”的建设方针，通过制定统一的物模型、场景建设、数据、安全、泛协议接入和开放集成的标准，降低校园各板块数字化信息互通联动壁垒，加速实现校园终端统一接入、集中管理、多板块协同、开放共享，通过数据一致性推动校园业务发展，支撑业务快速创新。

物联平台面向设备，适配多种网络环境和常见传输协议，提供各类硬件终端的快速接入方案和设备管理服务；面向应用，提供丰富的API和数据分发能力以满足学校应用系统的开发需求，使学校及二级单位可以更加专注于自身应用的开发，而不用将工作重心放在设备接入层的环境搭建上，从而缩短物联网系统的形成周期，降低研发、运营和运维成本。

### 设备接入

- 支持多种行业及主流标准协议的设备接入，如CoAP、LwM2M、MQTT、HTTP等，满足多种应用场景的使用需求
- 提供多种语言开发SDK，帮助开发者快速实现设备接入
- 支持用户协议自定义，通过上传解析脚本来完成协议的解析

### 设备管理

- 提供设备生命周期管理功能，支持用户进行设备注册、设备更新、设备查询、设备删除
- 提供设备在线状态管理功能，提供设备上下线的消息通知，方便用户管理设备的在线状态
- 提供设备数据存储能力，便于用户进行设备海量数据存储与查询
- 提供设备调试工具以及设备日志，便于用户快速调试设备以及定位设备问题

### 应用开发

- 提供项目管理服务，可实现跨产品的资源整合及协同管理，实现应用的快速落地
- 提供HTTP推送服务，可以将数据以HTTP请求的方式主动推送至应用系统
- 提供Kafka推送服务，支持应用服务器通过订阅消费模式，稳定高效获取平台设备、项目等资源实时数据
- 支持通过直接创建与可视化创建两种方式创建

### 数据可视化

- 提供简易大屏生成工具，快速实现数据可视化
- 提供丰富的图表展示组件，满足多场景使用需求
