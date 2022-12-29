数据推送

<a href="#1">1. 实例创建</a> 

<a href="#2">2. 实例验证</a> 

<a href="#3">3. 消息推送</a> 

---

KAFKA推送服务通过消息中间件方式，将项目下设备及应用数据推送给指定的KAFKA消息中间件。服务使用流程为：实例创建、实例验证、规则配置、消息推送。

<h3 id="1">1. 实例创建</h3>

展开菜单栏中的「应用开发」，点击「消息推送」，切换至Kafka推送标签页，进入Kafka推送实例列表页面。列表展示已创建的实例信息，每个实例对应一个Kafka的推送配置。点击「添加实例」，填写实例名称、推送地址等信息，完成实例新增，如图1所示。目前每个用户最多创建10个实例。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/application/数据推送_添加编辑KAFKA推送实例.png">
    <br>
    图 1 添加Kafka推送实例
    <br>
</center>

##### 参数说明：


<table>
<tr><th width="20%">参数</th><th>说明</th></tr>
<tr><td>Kafka地址</td><td>kafka集群地址。</td></tr>
<tr><td>Topic</td><td>填写集群中已存在的Topic。</td></tr>
</table>

实例创建成功，列表显示实例名称、Kafka地址、创建时间和验证状态等信息，如图2所示。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/application/数据推送_KAFKA实例列表.png">
    <br>
    图 2 Kafka推送实例列表
    <br>
</center>

其中实例状态代表当前实例的验证状态，包括待验证、验证成功、验证失败三种。

- 待验证：创建成功的实例状态默认为待验证，用户未对实例进行过验证操作。

- 验证成功：当前实例已通过平台验证，可以正常使用。

- 验证失败：当前实例进行过验证操作，但验证失败。失败的原因包括：1）网络请求错误，Kafka地址访问异常。2）Topic在当前Kafka地址中不存在。

<h3 id="2">2. 实例验证</h3>

实例创建成功后，下一步进行实例验证。实例列表页面，选择某一实例，点击「验证」，如图3所示。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/application/数据推送_验证KAFKA推送实例.png">
    <br>
    图 3 验证KAFKA推送实例
    <br>
</center>

点击验证时，平台服务器回想配置的服务器地址发送连接请求，并获取对应的topic信息，进行实例有效性验证。
实例验证通过后，下一步进行消息源（需要推送的数据）的配置。

<h3 id="3">3. 消息推送</h3>

消息源以单个项目进行配置，使用前需完成项目创建。推送实例列表页面点击「配置消息推送规则」按钮，弹出消息规则配置指引页面，如图3所示。选择某一具体项目，进入该项目「规则引擎」管理页面，配置推送的数据源及过滤规则。选择消息目的地为Kafka推送，页面展示当前已验证的推送实例列表，选择某一实例保存后，推送即可生效，该项目下设备及业务数据将会推送至Kafka集群，详细操作见[规则引擎使用说明](/book/application-develop/push/rule_engine/rule_introduce.md)。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/application/kafka数据推送_配置消息推送规则.png">
    <br>
    图 4 配置消息推送规则
    <br>
</center>

目前平台支持设备生命周期、设备物模型、场景联动触发日志等数据推送。推送数据将拼装成JSON字符串，以BYTE形式推送到对应的topic上。