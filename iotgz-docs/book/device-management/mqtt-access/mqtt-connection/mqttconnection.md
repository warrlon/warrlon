# **MQTT协议接入**

# **MQTT设备连接**

#### 1. 服务地址 

设备接入支持标准MQTTV3.1.1版本，接入服务地址如下：

<table>
<tr style="background-color:#363636; color:#F0FFF0;"><td width="10%">连接协议</td><td>证书</td><td>地址</td><td>端口</td><td>说明</td></tr>
<tr><td>MQTT</td><td><a href="https://open.iot.10086.cn/doc/iot_platform/images/iot_platform/mqtts/MQTTS-certificate.zip">证书下载</a></td><td>iotjr.tsinghua.edu.cn:1883</td><td>1883</td><td>非加密端口接入</td></tr>
</table>

#### 2. 产品与设备创建

按照[创建产品](/book/qinghua/Device-management/product-management/my-product.md)与[创建设备](/book/device-management/device-manager/device-list/devicelist.md)介绍，创建MQTT产品，并创建设备。

> 其中：  
> **产品名称**用户下具有**唯一性**  
> **设备名称**产品内具有**唯一性**，推荐采用设备sn、mac地址、IMEI等信息命名设备  

#### 3. 设备安全认证 

产品、设备创建时，平台为每类产品、每个设备均分配了唯一的 key，设备登录时需要使用通过key计算出的访问token 来进行访问安全认证，见[接入安全认证](/book/device-management/standard-access/security-auth/security.md)，设备可通过MQTT connnect报文进行登录。
connect报文中三要素填写方法如下：

<table>
<tr style="background-color:#363636; color:#F0FFF0;"><td width="25%">参数</td><td width="25%">是否必须</td><td> 参数说明</td></tr>
<tr><td>clientId</td><td>是</td><td>设备名称</td></tr>
<tr><td>username</td><td>是</td><td>平台分配的产品ID</td></tr>
<tr><td>3password</td><td>是</td><td>填写经过 key 计算的 token</td></tr>
</table>