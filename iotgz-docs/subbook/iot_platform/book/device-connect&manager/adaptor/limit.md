# 相关限制

<a href="#1">1. 控制连接限制</a>

<a href="#2">2. 代理连接限制</a>

<a href="#3">3. 代理设备限制</a>

---

<h3 id="1">1. 控制连接限制</font></h3>

1.通用限制：

控制连接只起gateway自身上下行通道及代理连接建立的先决条件的作用，限制如下：
- 不能用于代理设备的数据上传，否则断开连接；
- 不能订阅代理设备或不属于控制连接自身的topic，否则断开连接或订阅失败；
- 控制连接有且只能有一个，重复登录会踢掉前一个控制连接；
- 和设备一致，不支持qos2、不支持retain、will等特性；
- 和设备一致，订阅、取消订阅filter个数不能超过8。

2.频率限制：

<table>
<tr><th width="10%">限制类型</th><th width="10%">value</th><th width="45%">说明</th><th width="35%">超限后策略</th></tr>
<tr><td>CONNECT</td><td>5</td><td>5s内connect不能超过5次</td><td>集群禁用5min登录</td></tr>
<tr><td>publish qos0</td><td>10</td><td>5s内publish qos0报文数量不能超过10次</td><td>断开连接</td></tr>
<tr><td>publish qos1</td><td>5</td><td>5s内publish qos0报文数量不能超过5次</td><td>断开连接</td></tr>
<tr><td>subscribe</td><td>10</td><td>5s内订阅的topic数量不能超过10次</td><td>断开连接，集群禁用5min登录</td></tr>
<tr><td>unsubscribe</td><td>5</td><td>5s内取消订阅的报文数量不能超过5次</td><td>断开连接，集群禁用5min登录</td></tr>
<tr><td>ping</td><td>5</td><td>5s内ping报文数量不能超过10</td><td>断开连接，集群禁用5min登录</td></tr>
</table>


<h3 id="2">2. 代理连接限制</font></h3>

1.通用限制：

代理连接只起代理设备登录、上下行数据的作用，不能用于gateway自身的数据上下行，限制如下：

- 不能用户gateway自身数据上传；
- 不能订阅gateway自身数据上下行的topic，否则断开连接或订阅失败；
- 代理登录设备时不能订阅login响应，待收到login/accepted后才能订阅该代理设备的其他topic；
- 只能订阅代理设备的相关topic，订阅其他如$sys、$subdev开头的topic会订阅失败或断开连接；
- 新建代理连接时，控制连接必须存在；
- 控制连接断开时，不影响已有的代理连接；
- 代理连接断开时，会移除该连接下的所有代理设备session；
- 代理连接可以有多个(根据各instance的配置来限制)；
- 单个代理连接登录的设备数量有限(根据各instance的配置来限制)；
- 代理的connectionId不能重复，否则禁用后一个代理连接登录；
- 和设备一致，不支持qos2、不支持retain、will等特性；
- 和设备一致，订阅、取消订阅filter个数不能超过8。

2.频率限制：

<table>
<tr><th width="10%">限制类型</th><th width="10%">value</th><th width="35%">说明</th><th width="45%">超限后策略</th></tr>
<tr><td>CONNECT</td><td>5</td><td>5s内单个代理connect报文累计次数不超过 5 （相同connectionId）</td><td>断开该代理连接，（若因频率被断开连接次数累计到3次，则集群禁用代理5min，任何connectionId的代理连接均不能登录）</td></tr>
<tr><td>publish qos0</td><td>10</td><td>5s内所有代理qos0 级别的publish报文累计次数不超过10(代理发布无效topic的频率限制，若设备已登录，则subscribe限制接入到设备中)</td><td>断开该代理连接，（若因频率被断开连接次数累计到3次，则集群禁用代理5min，任何connectionId的代理连接均不能登录）</td></tr>
<tr><td>publish qos1</td><td>5</td><td>5s内所有代理qos1 级别的publish报文累计次数不超过5(代理发布无效topic的频率限制，若设备已登录，则subscribe限制接入到设备中)</td><td>断开该代理连接，（若因频率被断开连接次数累计到3次，则集群禁用代理5min，任何connectionId的代理连接均不能登录）</td></tr>
<tr><td>subscribe</td><td>10</td><td>5s内所有代理订阅的topic累计数量不超过10 (此处仅订阅失败的情况，若设备已登录，则subscribee限制接入到设备中)</td><td>断开该代理连接，（若因频率被断开连接次数累计到3次，则集群禁用代理5min，任何connectionId的代理连接均不能登录）</td></tr>
<tr><td>unsubscribe</td><td>5</td><td>5s内所有代理取消订阅的topic累计数量不超过5</td><td>断开该代理连接，（若因频率被断开连接次数累计到3次，则集群禁用代理5min，任何connectionId的代理连接均不能登录）</td></tr>
<tr><td>ping</td><td>5</td><td>5s内所有代理ping报文的累计数量不超过5</td><td>断开该代理连接，（若因频率被断开连接次数累计到3次，则集群禁用代理5min，任何connectionId的代理连接均不能登录）</td></tr>
<tr><td>CONNECT</td><td>5</td><td>5s内单个代理 connect报文累计次数不超过 5 （不同connectionId）</td><td>断开最后一次超过该限制的代理连接，（若因频率被断开连接次数累计到3次，则集群禁用代理5min，任何connectionId的代理连接均不能登录）</td></tr>
</table>



<h3 id="3">3. 代理设备限制</font></h3>

1.通用限制：

- 不允许代理设备登录成功后的重复登录(单机不同TCP连接及多机重复登录会移除前一个session，单机相同TCP连接重复登录会移除session)；
- 代理不能订阅代理设备的login/+、login/#等于login相关的topic，否则断开连接或订阅失败；
- 当代理设备因为协议错误需要移除session时会主动通知到代理该代理设备protocol-error。

>  注：代理设备超时时间与代理相同。

2.频率限制：

<table>
<tr><th width="10%">限制类型</th><th width="10%">value</th><th width="40%">说明</th><th width="40%">超限后策略</th></tr>
<tr><td>CONNECT</td><td>5</td><td>5s内connect不能超过10次</td><td>单机禁用该设备5min登录</td></tr>
<tr><td>publish qos0</td><td>10</td><td>5s内publish qos0报文数量不能超过10次</td><td>通知代理设备session被移除并单机禁用该设备5min登录</td></tr>
<tr><td>publish qos1</td><td>5</td><td>5s内publish qos1报文数量不能超过5次</td><td>通知代理设备session被移除并单机禁用该设备5min登录</td></tr>
<tr><td>subscribe</td><td>10</td><td>5s内订阅的topic数量不能超过10次</td><td>通知代理设备session被移除并单机禁用该设备5min登录</td></tr>
<tr><td>unsubscribe</td><td>5</td><td>5s内取消订阅的报文数量不能超过10次</td><td>通知代理设备session被移除并单机禁用该设备5min登录</td></tr>
</table>

>  注：该限制仅当代理设备登录后的操作行为，若代理设备未登录执行相关操作则计入到代理频率限制中。
