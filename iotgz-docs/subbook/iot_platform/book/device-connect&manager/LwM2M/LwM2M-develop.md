# 设备开发

[1. 设备注册](#1-设备注册)

[2. 设备注册更新](#2-设备注册更新)

[3. 设备注销](#3-设备注销)

[4. notify](#4-notify)
  
[5. 命令下行](#5-命令下行)

---

## 1. 设备注册

### 1.1. 设备注册报文

表1：设备注册报文

<table class="tableizer-table">
<thead><tr class="tableizer-firstrow"><th>CoAP请求消息</th><th>参数</th><th>示例说明</th></tr></thead><tbody>
 <tr><td>Message-Mode</td><td>CON</td><td>&nbsp;</td></tr>
 <tr><td>CoAP-Method</td><td>POST</td><td>&nbsp;</td></tr>
 <tr><td>CoAP-Options</td><td>Uri-Path(11): {path}</td><td>/rd</td></tr>
 <tr><td>&nbsp;</td><td>Content-Format(12):application/link-format</td><td>&nbsp;</td></tr>
 <tr><td>&nbsp;</td><td>Uri-Query(15): ep={endpoint name}</td><td>imei;imsi</td></tr>
 <tr><td>&nbsp;</td><td>Uri-Query(15): LwM2M={LwM2M version}</td><td>可选，1.0</td></tr>
 <tr><td>&nbsp;</td><td>Uri-Query(15): lt={lifetime}</td><td>可选，5-86400</td></tr>
 <tr><td>&nbsp;</td><td>Uri-Query(15): b={binding}</td><td>可选，默认为U</td></tr>
 <tr><td>&nbsp;</td><td>authcode (63): {authcode}</td><td>可选</td></tr>
 <tr><td>CoAP-payload</td><td>{ObjectLinks}</td><td>LwM2M相关参数加上{ObjectLinks}，例如</>:rt="oma.LwM2M",</1/0></td></tr>
 <tr><td>&nbsp;</td><td>&nbsp;</td><td>OneJson数据模型：需要携带<19/0>，<19/1></td></tr>
</tbody></table> 

<table class="tableizer-table">
<thead><tr class="tableizer-firstrow"><th>CoAP响应消息</th><th>参数</th><th>示例说明</th></tr></thead><tbody>
 <tr><td>Success Code</td><td>2.01 Created</td><td>&nbsp;</td></tr>
 <tr><td>Failure Code</td><td>4.00 Bad Request</td><td>&nbsp;</td></tr>
 <tr><td>&nbsp;</td><td>4.03 Forbidden</td><td>&nbsp;</td></tr>
 <tr><td>CoAP-Option</td><td>Location-path(8):{location-path1}</td><td>rd</td></tr>
 <tr><td>&nbsp;</td><td>Location-path(8):{location-path2}</td><td>imei</td></tr>
</tbody></table>

### 1.2. 设备注册流程

![img](/images/iot_platform/LwM2M/clip_image002.gif)

设备注册流程详细描述：

   用户在平台web端进行注册 –> 设备注册并携带鉴权信息 -> 接入机鉴权 -> 设备订阅/discover -> 设备读3/0 -> 注册成功。

1)   设备携带鉴权信息向接入机发起接入请求，接入机鉴权（目前支持imei/imei+authCode两种鉴权方式）。

2)   若鉴权通过，回复设备响应码201.

3)   设备是否为IPSO设备，若是进行步骤4-6；若不是进行步骤6；

4)   检查设备是否开启自动订阅，若开启，则下发订阅。订阅成功，记录订阅信息至session。

5)   检查设备是否允许discover，若允许，则下发discover。Discover成功，记录资源列表信息至redis

6)   若设备数据模型为OneJson，则对设备19-0、19-1进行订阅操作。若订阅成功，记录订阅信息至session服务；若失败，则设备注册失败；

7)   若前面操作都未失败，则下发read 3/0至设备。

8)   注册流程完成。

## 2. 设备注册更新

### 2.1. 设备注册更新报文

表2：设备注册更新报文

<table class="tableizer-table">
<thead><tr class="tableizer-firstrow"><th>CoAP请求消息</th><th>参数</th><th>示例说明</th></tr></thead><tbody>
 <tr><td>Message-Mode</td><td>CON</td><td>&nbsp;</td></tr>
 <tr><td>CoAP-Method</td><td>POST</td><td>&nbsp;</td></tr>
 <tr><td>CoAP-Options</td><td>Uri-Path(11): {location-path1}</td><td>Location</td></tr>
 <tr><td>&nbsp;</td><td>Uri-Query(15): lt={lifetime}</td><td>可选，5-86400</td></tr>
 <tr><td>&nbsp;</td><td>Uri-Query(15): b={binding}</td><td>可选，默认为U</td></tr>
 <tr><td>&nbsp;</td><td>authcode (63): {authcode}</td><td>可选</td></tr>
 <tr><td>CoAP-payload</td><td>{ObjectLinks}</td><td>LwM2M相关参数加上{ObjectLinks}，例如</>:rt="oma.LwM2M",</1/0></td></tr>
</tbody></table>

<table class="tableizer-table">
<thead><tr class="tableizer-firstrow"><th>CoAP响应消息</th><th>参数</th><th>示例说明</th></tr></thead><tbody>
 <tr><td>Success Code</td><td>2.04 Changed</td><td>&nbsp;</td></tr>
 <tr><td>Failure Code</td><td>4.00 Bad Request</td><td>非法参数</td></tr>
 <tr><td>&nbsp;</td><td>4.03 Forbidden</td><td>鉴权失败</td></tr>
 <tr><td>&nbsp;</td><td>4.04 Not Found</td><td></td></tr>
</tbody></table>

### 2.2. 设备注册更新流程

![img](/images/iot_platform/LwM2M/clip_image004.gif)

设备保活流程详细描述：

   设备发送保活报文并携带鉴权信息 -> 接入机鉴权 -> 心跳时间更新 -> 设备更新成功或者失败。

1)   设备携带鉴权信息向接入机发起保活请求，接入机鉴权（使用imei/imei+auth）

2)   检查注册更新报文中objectlinks列表是否有变化

3)   若有变化，接入机需要对新增资源进行订阅/Discover操作，对减少资源进行清理操作

4)   返回保活报文成功/失败响应

5)   若成功，更新上行链路信息和心跳周期

## 3. 设备注销

### 3.1. 设备注销报文

表3：设备注销报文

<table class="tableizer-table">
<thead><tr class="tableizer-firstrow"><th>CoAP请求消息</th><th>参数</th><th>示例说明</th></tr></thead><tbody>
 <tr><td>Message-Mode</td><td>CON</td><td>&nbsp;</td></tr>
 <tr><td>CoAP-Method</td><td>DELETE</td><td>&nbsp;</td></tr>
 <tr><td>CoAP-Options</td><td>Uri-Path(11): {location-path1}</td><td>Rd/{imei}</td></tr>
 <tr><td>&nbsp;</td><td>authcode (63): {authcode}</td><td>可选</td></tr>
</tbody></table> 

 <table class="tableizer-table">
<thead><tr class="tableizer-firstrow"><th>CoAP响应消息</th><th>参数</th><th>示例说明</th></tr></thead><tbody>
 <tr><td>Success Code</td><td>2.02 Deleted</td><td>&nbsp;</td></tr>
 <tr><td>Failure Code</td><td>4.00 Bad Request</td><td>非法参数</td></tr>
 <tr><td>&nbsp;</td><td>4.03 Forbidden</td><td>鉴权失败</td></tr>
 <tr><td>&nbsp;</td><td>4.04 Not Found</td><td>URI不存在</td></tr>
</tbody></table>

### 3.2. 设备注销流程

![img](/images/iot_platform/LwM2M/clip_image006.gif)

设备注销流程详细描述：

  设备发送注销报文并携带鉴权信息 -> 接入机鉴权 -> 清理设备信息-> 设备注销成功或者失败。

1)   设备携带鉴权信息向接入机发起注销请求，接入机鉴权（使用imei/imei+auth）

2)   返回注销报文成功/失败响应

3)   若成功，删除设备注册信息，以及订阅的设备信息。 

## 4. notify

上报数据模型分为IPSO模型，OneJson模型

### 4.1. IPSO模型

#### 4.1.1. IPSO模型notify报文请求

表4：notify报文请求格式

CoAP请求消息 | 参数 | 示例说明
---------|----|-----
Message-Mode | NON | 
CoAP-Method | Asynchronous Response | 
CoAP-Options | Observe(6):  | 2
 | Content-Format(12) | Observe Accept Option中设置的数据格式
CoAP-Option | {newValue}: | 上报数据值

| CoAP响应消息 | 参数 | 示例说明 |
| ------------ | ---- | -------- |
| 无           |      |          |


#### 4.1.2. IPSO模型notify流程图

![img](/images/iot_platform/LwM2M/clip_image008.gif)

设备上报数据流程详细描述：

  设备发送上报数据报文并携带token信息 -> 接入机鉴权 -> 将物模型数据上报至物模型平台 -> 更新链路信息 -> 推送触发消息。

1)    设备携带token向接入机发起上报数据请求，接入机鉴权（匹配token）。

2)    鉴权成功，判断notify数据类型是否为IPSO。

3)    若为IPSO，则发送报文数据至kafka待存储服务、规则引擎消费。

4)    更新链路信息和重新设置过期时间至session服务，lifetime仍以登陆和保活时携带的lifetime为基准。

5)    若上报消息类型为Con，则返回空响应；

6)    推送相关触发消息至kafka。

### 4.2. OneJson模型

#### 4.2.1. OneJson模型notify报文请求

| CoAP请求消息       | 参数                                   | 示例说明   |
| ------------------ | -------------------------------------- | ---------- |
| Message-Mode       | CON                                    |            |
| CoAP-Method        | Asynchronous  Response                 |            |
| CoAP-Options       | Observe(6):                            | 2          |
| Content-Format(12) | Observe  Accept Option中设置的数据格式 |            |
| CoAP-Option        | {newValue}:                            | 上报数据值 |

| CoAP响应消息  | 参数 | 示例说明 |
| ------------- | ---- | -------- |
| Success  Code |      |          |

#### 4.2.2. OneJson模型notify流程

![img](/images/iot_platform/LwM2M/clip_image010.gif)

设备上报OneJson数据流程详细描述：

设备发送上报数据报文并携带token信息 -> 接入机鉴权 -> 将物模型数据上报至物模型平台 -> 更新链路信息 -> 推送触发消息。

1)设备携带token向接入机发起上报数据请求，接入机鉴权（匹配token）。

2)鉴权成功，判断notify数据类型是否为OneJson。

3) 若为OneJson且为Con消息，则调用rpc发送至物模型校验服务。

4)更新设备链路信息，lifetime仍以登陆和 保活时携带的lifetime为基准。

5)返回相应结果响应；若物模型行为为获取期望，则返回相应期望值。若物 模型行为为删除期望，则返回删除结果。

## 5. 命令下行

### 5.1. 通用命令下行

#### 5.1.1. Observer

1. 订阅报文

表5：订阅报文

<table class="tableizer-table">
<thead><tr class="tableizer-firstrow"><th>CoAP请求消息</th><th>参数</th><th>示例说明</th></tr></thead><tbody>
 <tr><td>Message-Mode</td><td>CON</td><td>&nbsp;</td></tr>
 <tr><td>CoAP-Method</td><td>GET</td><td>&nbsp;</td></tr>
 <tr><td>CoAP-Options</td><td>Observe（6）：0（订阅）</td><td>&nbsp;</td></tr>
 <tr><td>&nbsp;</td><td>Uri-Path（11）：{Object ID}</td><td>传感器类型</td></tr>
 <tr><td>&nbsp;</td><td>Uri-Path（11）：{Object Instance ID}</td><td>该类型传感器编号</td></tr>
 <tr><td>&nbsp;</td><td>Uri-Path（11）：{Resource ID}</td><td>该类型传感器的数据</td></tr>
 <tr><td>&nbsp;</td><td>Option 5：Accept（17）：Content Format表中的类型</td><td>application/vnd.oma.LwM2M+tlv</td></tr>
 <tr><td>CoAP-payload</td><td>&nbsp;</td><td></td></tr>
</tbody></table>

<table class="tableizer-table">
<thead><tr class="tableizer-firstrow"><th>CoAP响应消息</th><th>参数</th><th>示例说明</th></tr></thead><tbody>
 <tr><td>Success Code</td><td>2.05 Content with Observe option</td><td>&nbsp;</td></tr>
 <tr><td>Failure Code</td><td>4.00 Bad Request</td><td>&nbsp;</td></tr>
 <tr><td>&nbsp;</td><td>4.01 Unauthorized</td><td>&nbsp;</td></tr>
 <tr><td>&nbsp;</td><td>4.03 Forbidden</td><td>&nbsp;</td></tr>
 <tr><td>&nbsp;</td><td>4.04 Not Found</td><td>&nbsp;</td></tr>
 <tr><td>&nbsp;</td><td>4.05 Method Not Allowed</td><td></td></tr>
</tbody></table>

2. 订阅流程图

![img](/images/iot_platform/LwM2M/clip_image012.gif)

1)   接入机服务接收到北向服务发起的订阅请求。

2)   接入机判断设备是否在线

3)   若在线，接入机向设备发起订阅请求并制定上报策略

4)   若订阅成功，设备将订阅信息缓存。

#### 5.1.2. Discover

1. Discover报文

表6：Discover报文

<table class="tableizer-table">
<thead><tr class="tableizer-firstrow"><th>CoAP请求消息</th><th>参数</th><th>示例说明</th></tr></thead><tbody>
 <tr><td>Message-Mode</td><td>CON</td><td>&nbsp;</td></tr>
 <tr><td>CoAP-Method</td><td>POST</td><td>&nbsp;</td></tr>
 <tr><td>&nbsp;</td><td>Uri-Path（11）：{Object ID}</td><td>传感器类型</td></tr>
 <tr><td>&nbsp;</td><td>Uri-Path（11）：{Object Instance ID}</td><td>该类型传感器编号</td></tr>
 <tr><td>&nbsp;</td><td>Uri-Path（11）：{Resource ID}</td><td>该类型传感器的数据</td></tr>
 <tr><td>CoAP-payload</td><td>&nbsp;</td><td></td></tr>
</tbody></table> 

<table class="tableizer-table">
<thead><tr class="tableizer-firstrow"><th>CoAP响应消息</th><th>参数</th><th>示例说明</th></tr></thead><tbody>
 <tr><td>Success Code</td><td>2.05 Content with objectlinks</td><td>&nbsp;</td></tr>
 <tr><td>Failure Code</td><td>4.00 Bad Request</td><td>&nbsp;</td></tr>
 <tr><td>&nbsp;</td><td>4.01 Unauthorized</td><td>&nbsp;</td></tr>
 <tr><td>&nbsp;</td><td>4.03 Forbidden</td><td>&nbsp;</td></tr>
 <tr><td>&nbsp;</td><td>4.04 Not Found</td><td>&nbsp;</td></tr>
 <tr><td>&nbsp;</td><td>4.05 Method Not Allowed</td><td></td></tr>
</tbody></table>
2. Discover流程

![img](/images/iot_platform/LwM2M/clip_image014.gif)

1)   接入机服务接收到北向服务发起的Discover请求。

2)   接入机判断设备是否在线

3)   若在线，接入机向设备发起Discover请求

4)   若Discover成功，设备将设备资源列表信息缓存

### 5.2. IPSO下行通道

#### 5.2.1. Read

##### 5.2.1.1. Read请求报文

表7：Read报文

<table class="tableizer-table">
<thead><tr class="tableizer-firstrow"><th>CoAP请求消息</th><th>参数</th><th>示例说明</th></tr></thead><tbody>
 <tr><td>Message-Mode</td><td>CON</td><td>&nbsp;</td></tr>
 <tr><td>CoAP-Method</td><td>GET</td><td>&nbsp;</td></tr>
 <tr><td>&nbsp;</td><td>Uri-Path（11）：{Object ID}</td><td>传感器类型</td></tr>
 <tr><td>&nbsp;</td><td>Uri-Path（11）：{Object Instance ID}</td><td>该类型传感器编号</td></tr>
 <tr><td>&nbsp;</td><td>Uri-Path（11）：{Resource ID}</td><td>该类型传感器的数据</td></tr>
 <tr><td>&nbsp;</td><td>Option 5：Accept（17）：Content Format表中的类型</td><td>application/vnd.oma.LwM2M+tlv</td></tr>
 <tr><td>CoAP-payload</td><td>&nbsp;</td><td></td></tr>
</tbody></table> 

<table class="tableizer-table">
<thead><tr class="tableizer-firstrow"><th>CoAP响应消息</th><th>参数</th><th>示例说明</th></tr></thead><tbody>
 <tr><td>Success Code</td><td>2.05 Content</td><td>&nbsp;</td></tr>
 <tr><td>Failure Code</td><td>4.00 Bad Request</td><td>&nbsp;</td></tr>
 <tr><td>&nbsp;</td><td>4.01 Unauthorized</td><td>&nbsp;</td></tr>
 <tr><td>&nbsp;</td><td>4.04 Not Found</td><td>&nbsp;</td></tr>
 <tr><td>&nbsp;</td><td>4.05 Method Not Allowed</td><td></td></tr>
</tbody></table>

##### 5.2.1.2. Read 流程

![img](/images/iot_platform/LwM2M/clip_image016.jpg)

1)   服务器端向设备client发送Read消息，例如Read /6/0/5;

2)   设备client收到Read消息后，SDK通过读取设备上相应的资源属性值，资源值支持单个及批量形式，具体根据Read消息的格式，然后返回给server，并携带返码Success。

#### 5.2.2. Write

##### 5.2.2.1. Write请求报文

表8：Write请求报文

<table class="tableizer-table">
<thead><tr class="tableizer-firstrow"><th>CoAP请求消息</th><th>参数</th><th>示例说明</th></tr></thead><tbody>
 <tr><td>Message-Mode</td><td>CON</td><td>&nbsp;</td></tr>
 <tr><td>CoAP-Method</td><td>PUT/POST</td><td>&nbsp;</td></tr>
 <tr><td>&nbsp;</td><td>Uri-Path（11）：{Object ID}</td><td>传感器类型</td></tr>
 <tr><td>&nbsp;</td><td>Uri-Path（11）：{Object Instance ID}</td><td>该类型传感器编号</td></tr>
 <tr><td>&nbsp;</td><td>Uri-Path（11）：{Resource ID}</td><td>该类型传感器的数据</td></tr>
 <tr><td>&nbsp;</td><td>Option 5：Accept（17）：Content Format表中的类型</td><td>application/vnd.oma.LwM2M+tlv</td></tr>
 <tr><td>CoAP-payload</td><td>&nbsp;</td><td>资源属性值</td></tr>
</tbody></table> 

<table class="tableizer-table">
<thead><tr class="tableizer-firstrow"><th>CoAP响应消息</th><th>参数</th><th>示例说明</th></tr></thead><tbody>
 <tr><td>Success Code</td><td>2.04 Changed</td><td>&nbsp;</td></tr>
 <tr><td>Failure Code</td><td>4.00 Bad Request</td><td>&nbsp;</td></tr>
 <tr><td>&nbsp;</td><td>4.01 Unauthorized</td><td>&nbsp;</td></tr>
 <tr><td>&nbsp;</td><td>4.04 Not Found</td><td>&nbsp;</td></tr>
 <tr><td>&nbsp;</td><td>4.05 Method Not Allowed</td><td></td></tr>
</tbody></table>

##### 5.2.2.2. Write流程

与Read流程基本一致

#### 5.2.3. Execute

##### 5.2.3.1. Execute报文

表9：Write请求报文

| 操作         | Observe（资源执行）                                          |
| ------------ | ------------------------------------------------------------ |
| LwM2M参数    | address /{Object ID}/{Object Instance ID}/{Resource  ID}/{Arguments} |
| 参数说明     | {Object ID}：必选，如UE上的传感器类型  </br>{Object Instance ID}：必选，该类型传感器的编号 </br> {Resource ID}：必选，该传感器的某种类型的数据，如温度的当前值，最大值等  </br>{Arguments}：可选，待执行的命令，如重启，关机等 |
| CoAP-Method  | POST                                                         |
| CoAP-Option  | Option 1：Uri-Path（11）：{Object  ID}  Option 2：Uri-Path（11）：{Object  Instance ID}  Option 3：Uri-Path（11）：{Resource  ID} |
| CoAP-payload | {Arguments}，格式为Content Format表中的text/plain格式        |
| Success      | 2.04 Changed                                                 |
| Failure      | 4.00 Bad Request, 4.01 Unauthorized, 4.04 Not Found, 4.05 Method  Not Allowed |

### 5.3. OneJson下行通道

#### 5.3.1. OneJson下行命令请求报文

表10：OneJson下行命令请求报文

<table class="tableizer-table">
<thead><tr class="tableizer-firstrow"><th>CoAP请求消息</th><th>参数</th><th>示例说明</th></tr></thead><tbody>
 <tr><td>Message-Mode</td><td>CON</td><td>&nbsp;</td></tr>
 <tr><td>CoAP-Method</td><td>PUT/POST</td><td>&nbsp;</td></tr>
 <tr><td>&nbsp;</td><td>Uri-Path（11）：{Object ID}</td><td>固定19</td></tr>
 <tr><td>&nbsp;</td><td>Uri-Path（11）：{Object Instance ID}</td><td>固定1</td></tr>
 <tr><td>&nbsp;</td><td>Uri-Path（11）：{Resource ID}</td><td>固定0</td></tr>
 <tr><td>&nbsp;</td><td>Option 5：Accept（17）：Content Format表中的类型</td><td>application/vnd.oma.LwM2M+tlv</td></tr>
 <tr><td>CoAP-payload</td><td>&nbsp;</td><td>资源属性值</td></tr>
</tbody></table> 

<table class="tableizer-table">
<thead><tr class="tableizer-firstrow"><th>CoAP响应消息</th><th>参数</th><th>示例说明</th></tr></thead><tbody>
 <tr><td>Success Code</td><td>2.04 Changed</td><td>&nbsp;</td></tr>
 <tr><td>Failure Code</td><td>4.00 Bad Request</td><td>&nbsp;</td></tr>
 <tr><td>&nbsp;</td><td>4.01 Unauthorized</td><td>&nbsp;</td></tr>
 <tr><td>&nbsp;</td><td>4.04 Not Found</td><td>&nbsp;</td></tr>
 <tr><td>&nbsp;</td><td>4.05 Method Not Allowed</td><td></td></tr>
</tbody></table>

#### 5.3.2. OneJson下行命令响应报文

| Code           | 2.05  content    |
| -------------- | ---------------- |
| Host           | Acc-ip           |
| Port           | 5683             |
| Type           | Ack              |
| Accept         | application/json |
| Content-Format | application/json |
| payload        | 物模型响应数据   |

#### 5.3.3. 物模型下行命令流程

![img](/images/iot_platform/LwM2M/clip_image018.gif) 

用户设置物模型属性流程详细描述：

   用户调用下发命令接口并携带鉴权信息 -> 物模型服务调用接入机下发命令接口-> 接入机发送请求到设备侧-> 捕获请求响应。

1)    根据设备信息查询session服务中的信息，判断设备是否在线

2)    若在线，下发命令至设备

3)    设备返回命令LwM2M响应码至接入机

4)    设备解析OneJson请求，并将对应OneJson响应通过Notify上报至接入机。