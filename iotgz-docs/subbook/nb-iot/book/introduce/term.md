# 名词解释

产品中常用的名词解释如下：

<table>
<tr><th width="15%">术语</th><th width="70%">解释</th><th>说明</th></tr>
<tr><td>产品</td><td>OneNET平台资源（包括设备，规则等）的集合，一个产品对应唯一的accessKey、产品ID，一个产品下包含多个具备同一特征的设备</td><td></td></tr>
<tr><td>产品ID</td><td>pid，创建产品时由平台分配的唯一产品识别码，用于标识唯一个产品，作为设备登录鉴权参数之一</td><td></td></tr>
<tr><td>accessKey</td><td>安全性更高的访问密钥，用于访问平台时的隐性鉴权参数（非直接传输），通过参与计算并传输token的方式进行访问鉴权</td><td> </td></tr>
<tr><td>token</td><td>安全性更高的鉴权参数，由多个参数组成，在通道中直接传输</td><td> </td></tr>
<tr><td>设备</td><td>归属于某一个产品下，是真实设备在平台的映射，用于和真实设备通过连接报文建立连接关系，平台资源分配的最小单位，设备之间的通过设备名称来区分</td><td> </td></tr>
<tr><td>设备ID</td><td>由平台分配的，在平台范围内设备唯一的识别号</td><td> </td></tr>
<tr><td>IMEI</td><td>模组的IMEI号，用于创建设备和接入平台的鉴权</td><td> </td></tr>
<tr><td>IMSI</td><td>NB物联卡的IMSI号，用于创建设备和接入平台的鉴权</td><td> </td></tr>
<tr><td>FOTA</td><td>主要是指模组固件的远程升级</td><td> </td></tr>
<tr><td>SOTA</td><td>主要是指MCU应用软件的远程升级</td><td> </td></tr>
<tr><td>object ID</td><td>IPSO规范里面的对象，例如温度 ：3303，详细请参考IPSO规范</td><td></td></tr>
<tr><td>resource ID</td><td>IPSO规范里面的属性，例如传感器值 ：5700，详细请参考IPSO规范</td><td> </td></tr>
</table>
