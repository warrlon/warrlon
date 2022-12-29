# 设备日志

[1.功能概述](#1功能概述)

[2.查询设备日志](#2查询设备日志)

[3.日志业务类型及状态码](#3日志业务类型及状态码)

---

### 1.功能概述

设备日志是在设备行为（设备上下线）、上行消息(设备通过Topic上报数据(属性、事件)到云端、设备侧属性期望操作)、下行消息 (通过开放API、控制台给设备下发消息、更新期望等)以及各云后业务处理（物模型调用、存储、规则引擎、HTTP推送、MQ推送）等业务过程中的全链路业务处理记录，通过设备日志功能，用户可以非常方便、迅速地监控业务运行状态和排查运行时问题。

OneNET Studio 面向用全量开放内部服务全链路日志，用户可通过每条链路唯一的链路ID追踪每条访问请求以及该请求的相应触发消息的处理情况，便于用户实时消息追踪与定位问题。 设备日志功能具有以下特点：

    (1) 内存级索引查询，多条件查询优化
    (2) 24小时不间断监控，实时展示用户业务运行状态
    (3) 更加直观地向用户展示系统业务架构和用户的每个业务流程
    (4) 更加快速的问题朔源和故障定位系统，对用户友好，降低用户使用成本
    (5) 提供上下行原始消息缓存，助力用户精准地分析问题
    (6) 集中的标准化日志管理、查询，高可拓展性，其它业务模块可以进行快速接入
    (7) 用户级业务日志暴露，用户可自主查询绝大多数的设备侧操作日志，无需通过工单排查问题

### 2.查询设备日志

    (1) 登录物联网平台控制台。
    (2) 在左侧导航栏，单击监控运维 > 设备日志，进入设备日志页签。
    (3) 选择产品，输入搜索条件，然后单击搜索图标。

支持的搜索条件如下表。

|  搜索条件   | 说明  |
|  :----:  | :----:  |
|DeviceName	|输入设备名称。根据设备名称，搜索该设备的相关日志。|
|TraceId |输入追踪ID，搜索串联模块日志。|
|消息ID|消息ID|
|日志状态|执行日志的状态，可选择：日志状态（全部）、成功、失败|
|业务类型|选择要查询的业务类型，可选择：业务类型（全部）、设备行为、上行消息、下行消息、物模型调用、数据存储、规则引擎、MQ推送、HTTP推送、开放API、应用长连接|
|时间范围|选择要查询日志的时间范围，可选择：近15分钟、近1小时、近4小时、近24小时、近7天、自定义|

#### 日志字段说明

设备日志列表中包含的字段说明如下表。

|  参数   | 含义  | 备注 |
|  :----:  | :----:  |:----: |
|日志时间	|日志打印时间。| 业务开始时间，格式yyyy-MM-dd HH:mm:ss.SSS，精确到毫秒|
|设备名称 |设备名称。| 无|
|链路ID|追踪ID，可用于搜索串联模块。| 32位，一条消息在系统内部各个服务模块流转以及相关触发消息的唯一标识ID|
|消息ID|该条日志的消息ID| 设备与平台上下行消息的消息唯一标识，用户可根据消息ID，查询消息通信数据内容，消息查询时效性为一天（自然天，当天可查当天，跨天则不可查询），目前仅上行消息、下行消息有消息ID，具体消息可在操作栏点击详情进入日志详情页面查看。|
|业务类型|默认显示所有业务类型的日志，您可以仅查询某一业务类型的日志。-设备行为-上行消息-下行消息-物模型调用-数据存储-规则引擎-MQ推送-HTTP推送-开放API-应用长连接|日志的业务类型，由各个服务定义|
|日志状态|日志执行的结果状态| 200代表成功，其它状态定义码参见日志业务状态码|
|日志内容|日志执行的内容| 详细的日志输出内容|

### 3.日志业务类型及状态码

#### 日志业务类型

<table>
 <tr>
  <th>服务模块</th>
  <th>日志类型</th>
  <th>日志触发时机</th>
 </tr>
 <tr>
  <td rowspan=3>CoAP/MQTT接入服务</td>
  <td>设备行为类</td>
  <td>设备上/下线、设备心跳（目前仅CoAP协议支持）</td>
 </tr>
 <tr>
  <td >上行消息</td>
  <td >设备侧上报（设备上报属性、事件），设备侧期望操作（设备获取、删除属性期望值），平台侧属性设置操作设备回复</td>
 </tr>
 <tr>
  <td>下行消息</td>
  <td>设备上报属性、事件平台回复，设备获取、删除属性期望值平台回复，平台侧属性设置操作</td>
 </tr>
 <tr>
  <td>物模型服务</td>
  <td>物模型调用</td>
  <td>见下表业务日志状态码中的物模型服务模块说明 </td>
 </tr>
 <tr>
  <td>数据存储服务</td>
  <td>数据存储</td>
  <td>暂未接入</td>
 </tr>
 <tr>
  <td>规则引擎服务</td>
  <td>规则引擎</td>
  <td>当配置了相应产品、设备的消费规则时，见下表业务日志状态码中的规则引擎服务模块说明 </td>
 </tr>
 <tr>
  <td>MQ推送服务</td>
  <td>MQ推送</td>
  <td>暂未接入</td>
 </tr>
 <tr>
  <td>HTTP推送服务</td>
  <td>HTTP推送</td>
  <td>当推送数据被消费时，见下表业务日志状态码中的HTTP推送服务模块说明 </td>
 </tr>
 <tr>
  <td>开放API服务</td>
  <td>开放API</td>
  <td>使用API进行属性设备、属性期望值查询、更新、删除等操作时，见下表业务日志状态码中的开放API服务模块说明 </td>
 </tr>
</table>

#### 业务日志状态码

<table>
 <tr>
  <th>服务模块</th>
  <th>状态码</th>
  <th>消息</th>
  <th>原因</th>
  <th>排查步骤</th>
 </tr>
 <tr>
  <td>通用</td>
  <td>200</td>
  <td>-</td>
  <td>成功</td>
  <td></td>
 </tr>
 <tr>
  <td rowspan=28>MQTT接入服务</td>
  <td>1001</td>
  <td>rpc failed</td>
  <td>rpc调用失败（上行）</td>
  <td>请通过提交工单进行排查</td>
 </tr>
 <tr>
  <td>1002</td>
  <td>thing error</td>
  <td>物模型服务错误</td>
  <td>根据返回的desc信息排查设备数据</td>
 </tr>
 <tr>
  <td>1021</td>
  <td>channel not writable</td>
  <td>设备socket不可写（下行）</td>
  <td>设备正在断开连接或设备接收的tcp缓冲区已满，排查设备状态</td>
 </tr>
 <tr>
  <td>1022</td>
  <td>subscription not exist</td>
  <td>订阅不存在,设备未订阅主题(无法推送下行消息)</td>
  <td>排查设备是否订阅了接收下行消息的topic</td>
 </tr>
 <tr>
  <td>1023</td>
  <td>device replied but timeout</td>
  <td>设备在超时时间后才回复设备设置属性</td>
  <td>请排查设备是否在超时时间后才回复设备设置属性</td>
 </tr>
 <tr>
  <td>1024</td>
  <td>session not exist</td>
  <td>设备session不存在（下行）</td>
  <td>请通过提交工单进行排查</td>
 </tr>
 <tr>
  <td>1025</td>
  <td>duplicate id</td>
  <td>重复的下行id（下行）</td>
  <td>请通过提交工单进行排查</td>
 </tr>
 <tr>
  <td>1026</td>
  <td>internal error</td>
  <td>接入机内部错误</td>
  <td>请通过提交工单进行排查</td>
 </tr>
 <tr>
  <td>1027</td>
  <td>invalid id field or json format error</td>
  <td>set_reply响应中id字段错误(不存在或类型错误)或json格式错误</td>
  <td>排查是否为合法json格式，及id字段是否存在或是字符串类型</td>
 </tr>
 <tr>
  <td>1028</td>
  <td>id not found</td>
  <td>id未找到</td>
  <td>排查设备是否在超时时间到期后回复了设置属性</td>
 </tr>
 <tr>
  <td>1101</td>
  <td>invalid argument</td>
  <td>无效的参数</td>
  <td>无效的鉴权参数，排查填写的clientId、userName、password字段是否为空</td>
 </tr>
 <tr>
  <td>1102</td>
  <td>internal error</td>
  <td>内部错误</td>
  <td>请通过提交工单进行排查</td>
 </tr>
 <tr>
  <td>1103</td>
  <td>invalid token</td>
  <td>无效的token</td>
  <td>排查设备token字段是否填写正确(有且仅包括et、version、method、res、sign等)</td>
 </tr>
 <tr>
  <td>1104</td>
  <td>token expired</td>
  <td>token已过期</td>
  <td>检查token的过期时间</td>
 </tr>
 <tr>
  <td>1105</td>
  <td>seckey not found</td>
  <td>设备/产品sec_key未找到</td>
  <td>请通过提交工单进行排查</td>
 </tr>
 <tr>
  <td>1106</td>
  <td>sign not match</td>
  <td>签名不匹配</td>
  <td>检查设备token中sign签名是否计算正确</td>
 </tr>
 <tr>
  <td>1107</td>
  <td>device not found</td>
  <td>根据pid + dev_name未找到设备</td>
  <td>排查设备是否真实(产品id + 设备名称)存在</td>
 </tr>
 <tr>
  <td>1108</td>
  <td>internal pid not found</td>
  <td>未找到对应的内部产品id</td>
  <td>请通过提交工单进行排查</td>
 </tr>
 <tr>
  <td>1109</td>
  <td>internal device id not found</td>
  <td>未找到对应的内部设备id</td>
  <td>请通过提交工单进行排查</td>
 </tr>
 <tr>
  <td>1110</td>
  <td>sign method not supported</td>
  <td>不支持的签名算法</td>
  <td>检查token中的method是否被平台支持</td>
 </tr>
 <tr>
  <td>1111</td>
  <td>invalid version</td>
  <td>非法的版本号</td>
  <td>检查token中的version字段是否正确</td>
 </tr>
 <tr>
  <td>1112</td>
  <td>protocol not match</td>
  <td>协议不匹配</td>
  <td>检查设备协议类型是否与连接的接入服务匹配</td>
 </tr>
 <tr>
  <td>1114</td>
  <td>argument not match with token</td>
  <td>输入的参数与token不匹配</td>
  <td>检查填写的clientId、userName字段是否与token中res字段中的一致(clientId填写设备名称、userName为产品id)</td>
 </tr>
 <tr>
  <td>1201</td>
  <td>invalid argument</td>
  <td>无效的参数</td>
  <td>请通过提交工单进行排查</td>
 </tr>
 <tr>
  <td>1202</td>
  <td>internal error</td>
  <td>内部错误</td>
  <td>请通过提交工单进行排查</td>
 </tr>
 <tr>
  <td>1204</td>
  <td>session not exist</td>
  <td>设备session未找到</td>
  <td>请通过提交工单进行排查</td>
 </tr>
 <tr>
  <td>1210</td>
  <td>login on other acceptor</td>
  <td>该设备/协议适配服务实例已登录到其他接入机</td>
  <td>请通过提交工单进行排查</td>
 </tr>
 <tr>
  <td>1401</td>
  <td>abnormal offline</td>
  <td>设备异常离线</td>
  <td>请查看日志中的offline_reason以便获取具体原因</td>
 </tr>
 <tr>
  <td rowspan=14 >CoAP接入服务</td>
  <td>400</td>
  <td>coap_bad-request</td>
  <td>错误请求</td>
  <td>CoAP请求报文格式错误，（请检查参数、编码等是否正确）</td>
 </tr>
 <tr>
  <td>401</td>
  <td>coap_unauthorized</td>
  <td>鉴权失败</td>
  <td>设备鉴权信息不匹配</td>
 </tr>
 <tr>
  <td>403</td>
  <td>coap_forbidden</td>
  <td>禁止上行</td>
  <td>设备上行消息速率超过平台限制</td>
 </tr>
 <tr>
  <td>404</td>
  <td>coap_not-found</td>
  <td>找不到对应设备资源</td>
  <td>设备可能已在平台离线</td>
 </tr>
 <tr>
  <td>405</td>
  <td>coap_method-not-allowed</td>
  <td>该资源不允许当前请求方式（GET/PUT/POST/DELETE）</td>
  <td>请根据平台使用规范使用CoAP请求方式</td>
 </tr>
 <tr>
  <td>406</td>
  <td>coap_not-acceptable</td>
  <td>无可返回的消息格式</td>
  <td>平台暂无法返回该种消息格式</td>
 </tr>
 <tr>
  <td>415</td>
  <td>coap_unsupported-content-format</td>
  <td>不支持的特殊消息格式</td>
  <td>平台暂不支持该种消息格式</td>
 </tr>
 <tr >
  <td >500</td>
  <td >internal_server_error</td>
  <td >内部错误</td>
  <td >请通过提交工单进行排查</td>
 </tr>
 <tr >
  <td>601</td>
  <td>time_out</td>
  <td>下行命令请求超时</td>
  <td>检查设备是否回复响应，若回复，请通过提交工单进行排查</td>
 </tr>
 <tr>
  <td>602</td>
  <td>req_param_error</td>
  <td>请求格式错误</td>
  <td>请通过提交工单进行排查</td>
 </tr>
 <tr>
  <td>603</td>
  <td>resp_error</td>
  <td>回复格式错误</td>
  <td>检查设备回复格式，若仍有问题，请通过提交工单进行排查</td>
 </tr>
 <tr>
  <td>604</td>
  <td>offline</td>
  <td>设备已离线</td>
  <td>请重新上线设备</td>
 </tr>
 <tr>
  <td>605</td>
  <td>addr_occupied</td>
  <td>地址被占用</td>
  <td>该设备地址已被其他设备占用</td>
 </tr>
 <tr>
  <td>606</td>
  <td>limit</td>
  <td>CoAP接入服务策略限制</td>
  <td>请根据平台限流规则使用</td>
 </tr>
 <tr>
  <td rowspan=13 >物模型服务</td>
  <td>301</td>
  <td>json format error</td>
  <td>json格式错误</td>
  <td>请确认数据格式重试</td>
 </tr>
 <tr>
  <td>302</td>
  <td>data type error</td>
  <td>数据类型错误</td>
  <td>请确认数据格式重试</td>
 </tr>
 <tr>
  <td>303</td>
  <td>internal error</td>
  <td>内部错误</td>
  <td>请通过提交工单进行排查。</td>
 </tr>
 <tr>
  <td>304</td>
  <td>resp error</td>
  <td>返回错误</td>
  <td>请确认属性设置响应数据格式后重试</td>
 </tr>
 <tr>
  <td>305</td>
  <td>no thing-model</td>
  <td>物模型定义不存在</td>
  <td>请确认产品下有物模型的定义后重试</td>
 </tr>
 <tr>
  <td>306</td>
  <td>timeout</td>
  <td>属性设置响应超时</td>
  <td>请确认设备有无响应属性设置消息</td>
 </tr>
 <tr>
  <td>307</td>
  <td>invalid pid or devName</td>
  <td>请求中pid或devicename不合法</td>
  <td>请确认pid和devName是有效数据后重试</td>
 </tr>
 <tr>
  <td>308</td>
  <td>device not online</td>
  <td>设备不在线</td>
  <td>请检查设备是否在线</td>
 </tr>
 <tr>
  <td>309</td>
  <td>identifier not exist</td>
  <td>标识符不存在</td>
  <td>请检查标识符是否存在</td>
 </tr>
 <tr>
  <td>310</td>
  <td>mqtt acc error</td>
  <td>MQTT接入服务调用失败</td>
  <td>请通过链路ID查询链路上对应的MQTT接入服务日志进行排查</td>
 </tr>
 <tr>
  <td>311</td>
  <td>coap acc error</td>
  <td>CoAP接入服务调用失败</td>
  <td>请通过链路ID查询链路上对应的CoAP接入服务日志进行排查</td>
 </tr>
 <tr>
  <td>312</td>
  <td>invalid msg id</td>
  <td>消息id不符合规范</td>
  <td>请检查消息id是否是不超过13位的字符串类型的数字</td>
 </tr>
 <tr>
  <td>313</td>
  <td>bad request</td>
  <td>请求不合法</td>
  <td>请确认请求正确后重试</td>
 </tr>
 <tr>
  <td rowspan=2 >规则引擎服务</td>
  <td>900</td>
  <td>internal error</td>
  <td>内部错误</td>
  <td>请通过提交工单进行排查。</td>
 </tr>
 <tr>
  <td>901</td>
  <td>format error</td>
  <td>数据格式错误</td>
  <td>请确认数据格式后重试</td>
 </tr>
 <tr>
  <td rowspan=5 >HTTP推送服务</td>
  <td>2001</td>
  <td>code error</td>
  <td>状态码错误</td>
  <td>HTTP响应未正常返回200状态码</td>
 </tr>
<tr>
  <td>3001</td>
  <td>parameter error</td>
  <td>参数错误</td>
  <td>请确认数据格式后重试</td>
 </tr>
 <tr>
  <td>3002</td>
  <td>service degradation</td>
  <td>推送超时服务降级</td>
  <td>请确认网络是否正常</td>
 </tr>
 <tr>
  <td>3003</td>
  <td>failures reached the maximum number</td>
  <td>重推次数达到上限</td>
  <td>请确认服务是否正常</td>
 </tr>
 <tr>
  <td>4001</td>
  <td>send failed</td>
  <td>推送失败</td>
  <td>请通过提交工单进行排查</td>
 </tr>
 <tr>
  <td rowspan=3 >开放API服务</td>
  <td>800</td>
  <td>internal error</td>
  <td>内部服务错误</td>
  <td>请通过提交工单进行排查</td>
 </tr>
 <tr>
  <td>801</td>
  <td>rpc failed</td>
  <td>rpc调用失败</td>
  <td>请通过提交工单进行排查</td>
 </tr>
 <tr>
  <td>802</td>
  <td>thing sevice error</td>
  <td>物模型命令服务调用失败</td>
  <td>请通过链路ID查询链路上对应的物模型日志进行排查</td>
 </tr>
</table>