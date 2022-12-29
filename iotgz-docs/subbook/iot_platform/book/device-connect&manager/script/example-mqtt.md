# MQTT设备开发

<a href="#1">1. Topic定义</a>

<a href="#2">2. 接入流程说明</a>

---

<h3 id="1">1. Topic定义</h3>

MQTT设备使用自定义数据格式与平台通信时，订阅和发布Topic如下所示：

<table>
<tr><th>Topic类型</th><th>Topic</th><th width="35%">说明</th></tr>
<tr><td>数据上报</td><td>$sys/{pid}/{device-name}/custome/up</td><td/></tr>
<tr><td>数据上报响应</td><td>$sys/{pid}/{device-name}/custome/up_reply</td><td/></tr>
<tr><td>命令下发</td><td>$sys/{pid}/{device-name}/custome/down/{id}</td><td> topic中的消息{id}需采用通配符+号订阅 </td></tr>
<tr><td>命令回复响应</td><td>$sys/{pid}/{devicename}/custome/down_reply/{id}</td><td>topic中的消息id，应与收到命令请求中的id保持对应关系</td></tr>
</table>

<h3 id="2">2. 接入流程说明</h3>

##### 数据上报流程

<center>
    <img width="80%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/script/mqtt数据上报.png">
</center>

<br/>


    说明：数据上报流程中，有两处需要用到脚本解析：
    (1) 数据上报时，平台按照上行解析函数定义将自定义数据转换成平台规范的物模型数据，并发送只后续云服务处理。。
    (2) 平台响应时，平台按照下行解析函数定义将响应物模型数据转换成自定义数据格式下发给设备。
    （如果未对平台响应结果进行处理，则平台不会下发响应给设备）。

##### 命令下发流程

属性设置、属性获取等命令下发时会在Topic中携带消息id，设备收到命令执行后，回复响应数据，应在发送的Topic中携带命令请求的消息id。

+ 同步命令下发

<center>
    <img width="80%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/script/mqtt同步命令下发.png">
</center>

+ 异步命令下发

<center>
    <img width="80%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/script/mqtt异步命令下发.png">
</center>

<br/>

    说明：命令下发流程中，有两处需要用到脚本解析：
    (1) 命令下发时，平台按照下行解析函数定义将物模型数据转换成自定义数据格式，发送给设备。
    (2) 设备回复命令时，平台按照上行解析函数定义将设备响应自定义数据解析成物模型数据。
    