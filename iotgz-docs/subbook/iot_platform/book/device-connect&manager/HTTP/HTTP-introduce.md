# HTTP 接入简介

[1. HTTP接入概述](#1-HTTP接入概述)

[2. HTTP 接入API格式](#2-HTTP接入API格式)

[3. HTTP接入地址](#3-HTTP接入地址)

[4. HTTP接入数据规范](#4-HTTP接入数据规范)

[5. HTTP接入鉴权设计](#5-HTTP接入鉴权设计)

[6. HTTP接入返回码设计](#6-HTTP接入返回码设计)

---

## 1. HTTP接入概述

支持设备使用HTTPS/HTTP2协议上报数据，分为直连设备和代理子设备，直连设备不显示在线状态，网关子设备可显示设备的在线状态。

## 2. HTTP 接入API格式

POST https://${Address}/${url}?${url参数}

Header参数:token，Content-Type

Body:OneJson

| **参数类型** | **说明**   | 
| -------- | ---------- |
| Method   | 请求方法，只支持POST方法,支持HTTPS,HTTP2协议|
| Address  | 具体请求ip或域名地址  |
| Url   | 请求路径，如：/device/thing/property/post |
| Header参数   | 1.token:鉴权参数的token值     2.Content-Type:application/json |
| URL参数   | 1.topic，请求参数topic，见2.1中的topic。   2.protocol 协议类型，(MQTT,COAP,OTHER) |
| Body   | 请求内容，内容格式同OneJson |

数据上报OneJson格式参照：
https://open.iot.10086.cn/doc/iot_platform/book/device-connect&manager/thing-model/protocol/OneJSON/property&event.html

子设备数据上下线OneJson格式参照：
https://open.iot.10086.cn/doc/iot_platform/book/device-connect&manager/thing-model/protocol/OneJSON/subdevice-loginout.html?h=%E5%AD%90%E8%AE%BE%E5%A4%87%E4%B8%8A%E7%BA%BF#2-%E5%AD%90%E8%AE%BE%E5%A4%87%E4%B8%8B%E7%BA%BF

## 3. HTTP接入地址

| **标识符** | **地址**   | 
| -------- | ---------- |
| Address   | https://open.iot.10086.cn/studio/http |

## 4. HTTP接入数据规范

根据Studio物模型规范，支持上报的数据如下表：

| **功能类型** | **topic**   | **直连设备是否支持**   |**网关子设备是否支持**   |
| -------- | ---------- | ---------- |---------- |
| 设备属性上报   | $sys/{pid}/{device-name}/thing/property/post | 是 | 是（采用设备批量数据上报） |
| 设备事件上报  | $sys/{pid}/{device-name}/thing/event/post  | 是 | 是（采用设备批量数据上报） |
| 设备批量数据上报   | $sys/{pid}/{device-name}/thing/pack/post | 是 | 是 |
| 设备历史数据上报   | $sys/{pid}/{device-name}/thing/history/post | 是 | 是 |
| 子设备上线   | $sys/{pid}/{device-name}/thing/sub/login | 否 | 是 |
| 子设备下线   | $sys/{pid}/{device-name}/thing/sub/logout | 否 | 是 |
| 添加子设备   | $sys/{pid}/{device-name}/thing/sub/topo/add | 否 | 是 |
| 删除子设备   | $sys/{pid}/{device-name}/thing/sub/topo/delete | 否 | 是 |
| 获取拓扑关系   | $sys/{pid}/{device-name}/thing/sub/topo/get | 否 | 是 |


## 5. HTTP接入鉴权设计

根据topic中的$sys/{pid}/{device-name}/*中的pid和device-name参照studio设备安全鉴权生成token作为鉴权参数。具体参照：
https://open.iot.10086.cn/doc/iot_platform/book/device-connect&manager/device-auth.html


## 6. HTTP接入返回码设计

|**序号**| **错误码** | **描述**   | 
| -------- | ---------- | ---------- |
|0| succ   | 成功 |
|1| internalServerError  | 内部错误  |
|2| authPermissionDeny   | 鉴权失败 |
|4| parameterRequired   | 缺少请求参数 |
|6| invalidParameter   | 不合法的请求参数 |
|17| setPropertyFailed   | 设备属性设置失败 |
|21| callTmServiceFailed   | 物模型服务调用失败 |
|32| subDeviceLoginFailed   | 子设备登录失败 |
|33| subDeviceLogoutFailed   | 子设备登出失败 |
|34| addTopoFailed   | 添加子设备失败 |
|35| deleteTopoFailed   | 删除子设备失败 |
|36| getTopoFailed   | 查询拓扑关系失败 |
|37| reachRateLimit   | 达到请求限制 |
