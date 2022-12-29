# 消息目的地—HTTP推送

<a href="#1">1. 应用场景</a> 

<a href="#2">2. 使用说明</a> 

<a href="#3">3. 操作步骤</a> 

---

<h3 id="1">1. 应用场景</h3>

HTTP推送用于实现平台与应用服务器之间的单向数据通信。平台作为客户端，通过HTTP/HTTPS请求方式，将项目下应用数据、设备数据推送给用户指定服务器。由于HTTP推送对应用服务器的性能及网络有较高要求，因此更适用于中等数据流量及允许一定延时的应用开发场景。

<h3 id="2">2. 使用说明</h3>

规则引擎配置推送规则前，需要先创建HTTP实例，HTTP推送服务使用流程包括：实例创建、实例验证、规则配置、消息推送，创建实例操作参见[HTTP数据推送](/book/application-develop/push/http_push.md)。

<h3 id="3">3. 操作步骤</h3>

- 选择消息目的地为HTTP推送，页面显示当前用户已创建的HTTP实例列表；如果当前用户账号下没有HTTP实例，需要点击链接前往"数据推送“进行配置。

- 当前用户已创建HTTP实例时，选择消息数据需要推送的HTTP实例（实例服务器地址已通过验证），点击"添加“按钮，规则引擎列表增加一行规则，为启用状态。


<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/application/消息目的地HTTP-无实例.png">
    <br>
    图1 消息目的地HTTP-无实例
    <br>
</center>

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/application/消息目的地HTTP-有实例.png">
    <br>
    图2 消息目的地HTTP-有实例
    <br>
</center>