# LwM2M设备开发

<a href="#1">1. 资源定义</a>

<a href="#2">2. 接入流程说明</a>

---

<h3 id="1">1. 资源定义</h3>

LwM2M设备使用自定义数据格式与平台通信时，订阅和发送资源信息如下所示：

<table>
<tr><th>资源类型</th><th>资源（object/instance/resource）</th><th>说明</th></tr>
<tr><td>数据上报</td><td>20/0/0</td><td/></tr>
<tr><td>命令下发</td><td>20/1/0</td><td/></tr>
<tr><td>命令数据回复</td><td>20/1/0</td><td>命令执行需要携带响应数据时，需要向该资源主动notify数据。</td></tr>
</table>

<h3 id="2">2. 接入流程说明</h3>

##### 数据上报流程

<center>
    <img width="80%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/script/LwM2M数据上报.png">
</center>

<br/>

    数据上报流程中，有一处需要用到脚本解析：
    (1) 数据上报时，平台按照上行解析函数定义将自定义数据转换成平台规范物模型数据，并发送至后续云服务。
    
#####  命令下发流程

属性设置、属性获取及服务调用等命令，会通过LwM2M协议的Write操作下发至设备，设备回复响应状态码，如需额外携带响应数据，则需要通过Notify操作将响应数据上报至平台。

+ 同步命令下发

<center>
    <img width="80%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/script/LwM2M同步命令下发.png">
</center>

+ 异步命令下发

<center>
    <img width="80%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/script/LwM2M异步命令下发.png">
</center>

<br/>

    命令下发流程中，有两处需要用到脚本解析：
    (1) 命令下发时，平台按照下行解析函数定义将物模型数据转换成自定义数据格式，发送给设备。
    (2) 设备回复命令时，平台按照上行解析函数定义将设备响应自定义数据解析成物模型数据。
    