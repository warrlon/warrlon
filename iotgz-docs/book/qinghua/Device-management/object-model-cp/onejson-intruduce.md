# 物模型通信协议

# OneJSON简介  

**1. 协议简介**

OneJSON协议是针对物联网开发领域设计的一种数据交换规范，数据格式是JSON，用于设备端和物联平台的双向通信，更便捷地实现和规范了设备端和物联平台之间的业务数据交互。  

**2. 设备接入**

设备接入流程，可以按照设备类型，分为直连设备和子设备接入。主要包括：设备注册、上线、绑定拓扑和数据上报三个流程。

![设备接入流程](/images\qinghua\device-management\advice-access-process.png)

**3. 设备上报属性或事件**

![设备上报属性或事件](/images\qinghua\device-management\advice-report.png)

(1) 设备使用OneJSON指定主题，上报数据；  
(2) 平台对数据进行业务处理，包含格式验证、数据存储等，如果配置了规则引擎，数据将流转到用户配置的消息目的地，推送方式支持HTTP、Kafka等；  
(3) 平台返回数据上报结果；  
(4) 开发者也可以通过控制台或公开API查询上报的数据。

**4. 设备属性获取**

![设备属性获取](/images\qinghua\device-management\advice-property-get.png)

(1) 开发者通过公开API或控制台发起获取属性请求；  
(2) 平台将根据物模型定义验证请求参数；  
(3) 平台将数据请求发给设备；  
(4) 平台等待设备响应，如果等待超时，将返回超时错误信息；  
(5) 设备处理完请求之后，把需要的设备属性返回给平台；  
(6) 平台收到设备最新属性后，对设备属性进行校验，将结果返回给开发者。

**5. 设备服务调用及属性设置**

- 同步服务调用及属性设置

![设备服务同步调用](/images\qinghua\device-management\device-synchronous-calls.png)

(1) 通过调用对应API接口来调用同步服务（定义服务时，调用方式选择为同步的服务即为同步调用）；  
(2) 平台将根据物模型定义验证输入参数；  
(3) 平台将数据下发给设备；  
(4) 平台等待设备响应，如果等待超时，将返回相应错误信息；  
(5) 设备处理完数据之后，把处理结果返回给平台；  
(6) 平台收到设备处理结果后，对设备输出参数进行校验，将结果返回给开发者。

- 异步服务调用及属性设置

![设备服务异步调用](/images\qinghua\device-management\device-asynchronous-calls.png)

(1) 通过调用对应API接口来调用同步服务（定义服务时，调用方式选择为异步的服务即为异步调用）；  
(2) 平台对输出参数进行校验，并返回处理结果给开发者；  
(3) 平台采用异步方式将数据下发；  
(4) 设备收到数据后，进行业务处理；  
(5) 设备完成业务处理后，返回处理结果给平台；  
(6) 平台对设备返回的输出参数进行验证；  
(7) 如果配置了规则引擎，数据将流转到用户配置的消息目的地，推送方式支持HTTP、Kafka等。

**6. 拓扑关系**

![拓扑关系](/images\qinghua\device-management\topology-relationships.png)

网关和子设备绑定拓扑关系后，子设备可借助网关通道进行上下线、数据上传、指令接收等操作
网关和子设备拓扑关系可以通过两种方式变更：

- 北向修改    
(1) 开发者在控制台绑定或解绑子设备；  
(2) 开发者点击同步操作，将拓扑关系变更通知到网关；  
(3) 网关收到拓扑关系后，进行网关本地拓扑关系同步；  
(4) 同步结果返返回平台；  
(5) 平台处理后，将最终结果返回给开发者。

- 南向修改  
(1) 网关侧发起关联或解绑子设备操作；  
(2) 平台处理完网关请求后，将处理结果返回给网关设备。

- 拓扑关系获取  
(1) 网关可主动向平台获取拓扑关系；  
(2) 平台下发拓扑关系到网关；  
(3) 网关本地同步云平台存储的拓扑关系到本地；  
(4) 网关回复本地同步结果。