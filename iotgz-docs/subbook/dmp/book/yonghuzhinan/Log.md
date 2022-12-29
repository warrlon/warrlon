# 日志查询
日志查询主要是为您提供日志查询自服务工具，可以根据时间段、日志级别、设备ID来筛选查询日志，提升用户自服务能力。

## 操作步骤
1. 登录OneNET的[设备管理平台](https://open.iot.10086.cn/develop/device/#/device/list);
2. 左侧导航栏选择**设备日志查询**；您可以在页面顶栏通过日期范围、日志类别、设备ID来快速搜索定位目标设备日志内容，同时支持导出记录功能。
![日志查询](/images\DMP\日志查询1.png)
>搜索条件说明<br>
日期选择：默认选择最近一小时，最大选择范围为一个月，平台仅存储近3个月的日志；<br>
日志级别：日志级别分为INFO、ERRO、WARN；<br>
设备ID：通过设备ID精准搜索，目前为必填；<br>

### 日志查询示例：

|定义|描述|
|--|--:|
|业务类型|register|
|日志记录|new registered client<br>IMEI:1111<br>IMSI: 2222 300|
|日志含义|连接平台成功<br>IMEI: 1111,<br>IMSI: 2222<br>Lifetime: 300 秒|

### NB-IoT接入套件详细的日志说明如下：
#### 1. NBBS（NB接入机引导）
##### 1.1 Bootstrap start
关键词 | 关键信息 | 示例的含义
:- | :- | :- |
requested bootstrap | imei: 86xxxxxxxxx，imsi: 2222 | 请求bootstrap，imei: 86xxxxxxxxx, imsi: 2222

##### 1.2 Bootstrap delete
关键词 | 关键信息 | 示例的含义
:- | :- | :- 
bootstrap delete | CHANGED | Delete / 响应 CHANGED
bootstrap delete error |  | Delete / 错误

##### 1.3 Bootstrap discover
关键词 | 关键信息 | 示例的含义    
:- | :- | :- 
bootstrap discover | CONTENT | Discover / 响应 CONTENT      
bootstrap discover error |  | Discover / 错误   

##### 1.4 Bootstrap write /0/1
关键词 | 关键信息 | 示例的含义    
:- | :- | :- 
bootstrap wrote server address | /0/1 （信息1），CHANGED （信息2） | bootstrap 写/0/1 响应 CHANGED      
bootstrap write security instance xxx error | /0/1 | bootstrap 写/0/1 错误 

##### 1.5 Bootstrap write /0/1
关键词 | 关键信息 | 示例的含义    
:- | :- | :- 
bootstrap wrote server address | /0/1 （信息1），CHANGED （信息2） | bootstrap 写/0/1 响应 CHANGED      
bootstrap write security instance xxx error | /0/1 | bootstrap 写/0/1 错误

##### 1.6 Bootstrap finish
关键词 | 关键信息 | 示例的含义    
:- | :- | :- 
bootstrap finished | CHANGED | bootstrap finish 响应 CHANGED      
bootstrap finish error |  | bootstrap finish 错误  

#### 2 注册及上报数据
##### 2.1 Register
关键词 | 关键信息 | 示例的含义    
:- | :- | :- 
new registered client | imei: 86xxxxxxxxx, imsi: 2222，300 | 连接平台成功，imei: 86xxxxxxxxx, imsi: 2222，lifetime: 300 秒

##### 2.2 Observe
关键词 | 关键信息 | 示例的含义    
:- | :- | :- 
auto observe | /3/0，CONTENT | 平台订阅 /3/0 响应 CONTENT
auto observe error | /3/0 | 平台订阅 /3/0 超时，不再下发后续请求

##### 2.3 Read /3/0 or read /4/0
关键词 | 关键信息 | 示例的含义    
:- | :- | :- 
auto read | /3/0，CONTENT | 平台读取 /3/0 响应 CONTENT
auto read error | /3/0 | 平台读取 /3/0 超时，不再下发后续请求

##### 2.4 Update
关键词 | 关键信息 | 示例的含义    
:- | :- | :- 
update success | imei: 86xxxxxxxxx，300 | update 成功, imei: 86xxxxxxxxx，lifetime: 300 秒

##### 2.5 Deregister
关键词 | 关键信息 | 示例的含义    
:- | :- | :- 
deregister success | imei: 86xxxxxxxxx | 注销成功,设备离线， imei: 86xxxxxxxxx

##### 2.6 Notify
关键词 | 关键信息 | 示例的含义    
:- | :- | :- 
notify success | /3/0 | 设备notify，imei: 86xxxxxxxxx，资源路径：/3/0

#### 3 下行业务
##### 3.1 Read
关键词 | 关键信息 | 示例的含义    
:- | :- | :- 
read client | /3/0，12345 | 下发Read请求，资源路径：/3/0，序列号: 12345
read return | CONTENT，/3/0，12345 | 收到Read响应 CONTENT，资源路径: /3/0，序列号: 12345
read error |  | Read 响应超时/错误，资源路径：/3/0，序列号: 12345

##### 3.2 Write
关键词 | 关键信息 | 示例的含义    
:- | :- | :- 
write client | /3/0，12345 | 下发Write请求，资源路径：/3/0，序列号: 12345
write return | CHANGED，/3/0，12345 | 收到Write响应 CHANGED，资源路径: /3/0，序列号: 12345
write error | TIMEOUT/RESP_ERROR，/3/0，12345 | Write响应超时/错误，资源路径：/3/0，序列号: 12345

##### 3.3 Execute
关键词 | 关键信息 | 示例的含义    
:- | :- | :- 
execute client | /3/0，12345 | 下发Execute请求，资源路径：/3/0，序列号: 12345
execute return | CHANGED，/3/0，12345 | 收到Execute响应 CHANGED，资源路径: /3/0，序列号: 12345
execute error | TIMEOUT/RESP_ERROR，/3/0，12345 | Execute响应超时/错误，资源路径：/3/0，序列号: 12345

##### 3.4 Write attribute
关键词 | 关键信息 | 示例的含义    
:- | :- | :- 
writeAttribute client | /3/0，12345 | 下发WriteAttribute请求，资源路径：/3/0，序列号: 12345
writeAttribute return | CHANGED，/3/0，12345 | 收到WriteAttribute响应 CHANGED，资源路径: /3/0，序列号: 12345
writeAttribute error | TIMEOUT/RESP_ERROR，/3/0，12345 | WriteAttribute响应超时/错误，资源路径：/3/0，序列号: 12345

##### 3.5 Write package
关键词 | 关键信息 | 示例的含义    
:- | :- | :- 
writePackage client | 12345 | 下发写固件包请求，序列号: 12345
writePackage return | CHANGED，12345 | 收到写固件包响应 CHANGED，序列号: 12345
writePackage error | TIMEOUT/RESP_ERROR，12345 | 写固件包响应超时/错误，序列号: 12345

##### 3.6 Observe
关键词 | 关键信息 | 示例的含义    
:- | :- | :- 
observe client | /3/0，12345 | 下发Observe请求，资源路径：/3/0，序列号: 12345
observe return | CHANGED，/3/0，12345 | 收到Observe响应 CONTENT，资源路径: /3/0，序列号: 12345
observe error | TIMEOUT/RESP_ERROR，/3/0，12345 | Observe响应超时/错误，资源路径：/3/0，序列号: 12345

##### 3.7 Cancel observe
关键词 | 关键信息 | 示例的含义    
:- | :- | :- 
cancel observe client | /3/0，12345 | 下发取消Observe请求，资源路径：/3/0，序列号: 12345
cancel observe return | CHANGED，/3/0，12345 | 收到取消Observe响应 CONTENT，资源路径: /3/0，序列号: 12345
cancel observe error | TIMEOUT/RESP_ERROR，/3/0，12345 | 取消Observe响应超时/错误，资源路径：/3/0，序列号: 12345

#### 4 设备超时离线
关键词 | 关键信息 | 示例的含义    
:- | :- | :- 
offline | imei: 86xxxxxxxxx | lifetime到期，设备离线, imei: 86xxxxxxxxx