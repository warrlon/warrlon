# CoAP设备连接

---

### 设备登录

设备登录报文

<table>
<tr><td width="20%">POST</td><td>$sys/{pid}/{device-name}/login</td></tr>
<tr><td >HOST</td><td>{Acc-ip}</td></tr>
<tr><td >Port</td><td>5683</td></tr>
<tr><td >Code</td><td>POST</td></tr>
<tr><td >Type</td><td>Con</td></tr>
<tr><td >Content-Format</td><td>application/json</td></tr>
<tr><td >payload</td><td>{“lt”:86400, “st”:“xxxxxx”}</td></tr>
</table>

设备登录报文参数说明

<table>
<tr><th width="20%">参数</th><th>说明</th></tr>
<tr><td >pid</td><td>产品ID</td></tr>
<tr><td >device-name</td><td>产品名称</td></tr>
<tr><td >HOST</td><td>接入地址，取值：183.230.102.116</td></tr>
<tr><td >Port</td><td>端口，取值为：5683</td></tr>
<tr><td >Content-Format</td><td>设备发送给物联网平台的上行数据编码格式，支持application/json方式</td></tr>
<tr><td >payload</td><td>设备登录信息内容，JSON数据格式</td></tr>
</table>

返回结果

<table>
<tr><td width="20%">Resp-success</td><td>2.01Created<br> Payload:{token}
</td></tr>
<tr><td >Resp-failed</td><td>4.00 Bad Request/4.03 Forbidden</td></tr>
</table>

### 设备保活

设备保活报文：

<table>
<tr><td width="20%">POST</td><td>$sys/{pid}/{device-name}/keep_alive</td></tr>
<tr><td >HOST</td><td>{Acc-ip}</td></tr>
<tr><td >Port</td><td>5683</td></tr>
<tr><td >Code</td><td>POST</td></tr>
<tr><td >Type</td><td>Con</td></tr>
<tr><td >Content-Format</td><td>application/json</td></tr>
<tr><td >payload</td><td>{“lt”:86400, “st”:“xxxxxx”}</td></tr>
</table>


返回结果

<table>
<tr><td width="20%">Resp-success</td><td>2.04 Changed
</td></tr>
<tr><td >Resp-failed</td><td>4.00 Bad Request/4.04 Not Found</td></tr>
</table>

### 设备物模型上行

#### 属性类：

1、属性上报：$sys/{pid}/{device-name}/thing/property/post

2、属性期望获取：$sys/{pid}/{device-name}/thing/property/desired/get

3、属性期望删除：$sys/{pid}/{device-name}/thing/property/desired/delete

#### 事件类：

1、事件上报：$sys/{pid}/{device-name}/thing/event/post

<table>
<tr><td width="20%">POST</td><td>使用物模型定义的上行topic</td></tr>
<tr><td >HOST</td><td>{Acc-ip}</td></tr>
<tr><td >Port</td><td>5683</td></tr>
<tr><td >Code</td><td>POST</td></tr>
<tr><td >Type</td><td>Con/Non</td></tr>
<tr><td >Accept</td><td>application/json</td></tr>
<tr><td >Content-Format</td><td>application/json</td></tr>
<tr><td >payload</td><td>物模型数据</td></tr>
</table>


### 物模型下行命令

#### 属性类：

1、属性设置：$sys/{pid}/{device-name}/thing/property/set

2、属性获取：$sys/{pid}/{device-name}/thing/property/get

#### 服务类：

1、服务调用：$sys/{pid}/{device-name}/thing/service/{identifier}/invoke

<table>
<tr><td width="20%">POST</td><td>使用物模型定义的下行topic</td></tr>
<tr><td >HOST</td><td>设备ip</td></tr>
<tr><td >Port</td><td>设备连接端口</td></tr>
<tr><td >Code</td><td>POST</td></tr>
<tr><td >Type</td><td>Con</td></tr>
<tr><td >Accept</td><td>application/json</td></tr>
<tr><td >Content-Format</td><td>application/json</td></tr>
<tr><td >payload</td><td>设置属性的物模型数据</td></tr>
</table>

物模型下行命令响应报文：

<table>
<tr><td  width="20%">Code</td><td>2.05 content</td></tr>
<tr><td >HOST</td><td>{Acc-ip}</td></tr>
<tr><td >Port</td><td>5683</td></tr>
<tr><td >Type</td><td>Ack</td></tr>
<tr><td >Accept</td><td>application/json</td></tr>
<tr><td >Content-Format</td><td>application/json</td></tr>
<tr><td >payload</td><td>物模型响应数据</td></tr>
</table>


### 设备登出

设备登出报文：

<table>
<tr><td width="20%">POST</td><td>$sys/{pid}/{device-name}/logout</td></tr>
<tr><td >HOST</td><td>{Acc-ip}</td></tr>
<tr><td >Port</td><td>5683</td></tr>
<tr><td >Code</td><td>POST</td></tr>
<tr><td >Type</td><td>Con</td></tr>
<tr><td >Content-Format</td><td>application/json</td></tr>
<tr><td >payload</td><td>{ “st”:“xxxxxx”}</td></tr>
</table>
返回结果
<table>
<tr><td width="20%">Resp-success</td><td>2.02Deleted
</td></tr>
<tr><td >Resp-failed</td><td>4.00 Bad Request/4.03 Forbidden</td></tr>
</table>

## 平台接入地址

| **通信协议** | **地址**            | **端口** | **说明**       |
| -------- | --------------- | ---- | ---------- |
| CoAP    | studio-coap.heclouds.com | 5683  |非加密端口 |
