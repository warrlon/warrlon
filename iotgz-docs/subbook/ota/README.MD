# 远程升级OTA

远程升级OTA功能面向终端提供远程升级的能力，可对终端的模组固件升级和MCU应用软件升级，目前OneNET平台的通用OTA服务提供升级包版本管理和差分生成、设备分组管理、升级包任务策略配置、升级任务状态修改、设备升级状态查看等功能


## 适用场景
- 海量同步升级
    
    提供多线程、高并发的升级包分发能力，能够轻松完成百万设备升级，保证版本升级快速完成，安全漏洞极速修复

- 流程化快速升级

    设备能发起HTTP请求即可使用OTA，并提供详尽的SDK接入文档、操作说明文档，升级流程简单快捷

- 全面保护设备

    在设备远程升级过程中，提供断点续传、低电量保护、防降级等升级防护机制，可查看每台设备升级详情


## 快速入门

通过阅读下列文档，您将能快速了解远程升级OTA

- [产品与设备](/book/manual/createProduct-device.md)
- [升级操作流程](/book/manual/ota_develop_document.md)
- [鉴权参数](/book/develop/auth.md)

## 开发指南

下列文档将能帮助您快速了解如何运用远程升级OTA服务完成设备升级

- [OTA-API使用实例](/book/example/simulate.md)
- [OTA-SDK使用说明](/book/develop/OTA-SDK-instruction.md)
