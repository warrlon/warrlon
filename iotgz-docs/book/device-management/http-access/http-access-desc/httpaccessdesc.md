# **HTTP协议接入**  

# **HTTP接入使用说明** 

### **HTTP 接入简介**  

#### **1. HTTP接入概述**  

支持设备使用HTTPS/HTTP协议上报数据，分为直连设备和代理子设备，直连设备不显示在线状态，网关子设备可显示设备的在线状态。

#### **2. HTTP 接入API格式**  

````
POST https://${Address}/${url}?${url参数}
````

Header参数：token，Content-Type

Body：OneJson

<table style="text-align: left">
    <tr style="background-color:#363636; color:#F0FFF0;">
        <td width="30%">参数类型</td>
        <td>说明</td>
    </tr>
    <tr>
        <td>Method</td>
        <td>请求方法，只支持POST方法,支持HTTPS,HTTP协议</td>
    </tr>
    <tr>
        <td>Address</td>
        <td>具体请求ip或域名地址</td>
    </tr>
    <tr>
        <td>Url</td>
        <td>请求路径，如：/device/thing/property/post</td>
    </tr>
    <tr>
        <td>Header参数</td>
        <td>1.token:鉴权参数的token值 2.Content-Type:application/json</td>
    </tr>
    <tr>
        <td>URL参数</td>
        <td>1.topic，请求参数topic，见2.1中的topic。 2.protocol 协议类型，(MQTT,COAP,OTHER)</td>
    </tr>
    <tr>
        <td>Body</td>
        <td>请求内容，内容格式同OneJson</td>
    </tr>
</table>

数据上报OneJson格式参照：[设备属性/事件](/book/qinghua/Device-management/object-model-cp/device-attribute.md)

子设备数据上下线OneJson格式参照：[子设备上下线](/book/qinghua/Device-management/object-model-cp/child-device-onoff.md)

#### **3. HTTP接入地址**  

<table style="text-align: left">
    <tr style="background-color:#363636; color:#F0FFF0;">
        <td width="30%">标识符</td>
        <td>地址</td>
    </tr>
    <tr>
        <td>Address</td>
        <td>iotjr.tsinghua.edu.cn:1667</td>
    </tr>
</table>

#### **4. HTTP接入数据规范**  

根据物模型规范，支持上报的数据如下表：

<table style="text-align: left">
    <tr style="background-color:#363636; color:#F0FFF0;">
        <td width="15%">功能类型</td>
        <td width="35%">topic</td>
        <td width="25%">直连设备是否支持</td>
        <td>网关子设备是否支持</td>
    </tr>
    <tr>
        <td>设备属性上报</td>
        <td>$sys/{pid}/{device-name}/thing/property/post</td>
        <td>是</td>
        <td>是（采用设备批量数据上报）</td>
    </tr>
    <tr>
        <td>设备事件上报</td>
        <td>$sys/{pid}/{device-name}/thing/event/post</td>
        <td>是</td>
        <td>是（采用设备批量数据上报）</td>
    </tr>
    <tr>
        <td>设备批量数据上报</td>
        <td>$sys/{pid}/{device-name}/thing/pack/post</td>
        <td>是</td>
        <td>是</td>
    </tr>
    <tr>
        <td>设备历史数据上报</td>
        <td>$sys/{pid}/{device-name}/thing/history/post</td>
        <td>是</td>
        <td>是</td>
    </tr>
    <tr>
        <td>子设备上线</td>
        <td>$sys/{pid}/{device-name}/thing/sub/login</td>
        <td>否</td>
        <td>是</td>
    </tr>
    <tr>
        <td>子设备下线</td>
        <td>$sys/{pid}/{device-name}/thing/sub/logout</td>
        <td>否</td>
        <td>是</td>
    </tr>
    <tr>
        <td>添加子设备</td>
        <td>$sys/{pid}/{device-name}/thing/sub/topo/add</td>
        <td>否</td>
        <td>是</td>
    </tr>
    <tr>
        <td>删除子设备</td>
        <td>$sys/{pid}/{device-name}/thing/sub/topo/delete</td>
        <td>否</td>
        <td>是</td>
    </tr>
    <tr>
        <td>获取拓扑关系</td>
        <td>$sys/{pid}/{device-name}/thing/sub/topo/get</td>
        <td>否</td>
        <td>是</td>
    </tr>
</table>

#### **5. HTTP接入鉴权设计**  

根据topic中的$sys/{pid}/{device-name}/*中的pid和device-name参照物联平台设备安全鉴权生成token作为鉴权参数，具体参照：[接入安全认证](/book/device-management/standard-access/security-auth/security.md)。

#### **6. HTTP接入返回码设计**  

<table style="text-align: left">
    <tr style="background-color:#363636; color:#F0FFF0;">
        <td width="20%">序号</td>
        <td>错误码</td>
        <td>描述</td>
    </tr>
    <tr>
        <td>0</td>
        <td>succ</td>
        <td>成功</td>
    </tr>
    <tr>
        <td>1</td>
        <td>internalServerError</td>
        <td>内部错误</td>
    </tr>
    <tr>
        <td>2</td>
        <td>authPermissionDeny</td>
        <td>鉴权失败</td>
    </tr>
    <tr>
        <td>4</td>
        <td>parameterRequired</td>
        <td>缺少请求参数</td>
    </tr>
    <tr>
        <td>6</td>
        <td>invalidParameter</td>
        <td>不合法的请求参数</td>
    </tr>
    <tr>
        <td>17</td>
        <td>setPropertyFailed</td>
        <td>设备属性设置失败</td>
    </tr>
    <tr>
        <td>21</td>
        <td>callTmServiceFailed</td>
        <td>物模型服务调用失败</td>
    </tr>
    <tr>
        <td>32</td>
        <td>subDeviceLoginFailed</td>
        <td>子设备登录失败</td>
    </tr>
    <tr>
        <td>33</td>
        <td>subDeviceLogoutFailed</td>
        <td>子设备登出失败</td>
    </tr>
    <tr>
        <td>34</td>
        <td>addTopoFailed</td>
        <td>添加子设备失败</td>
    </tr>
    <tr>
        <td>35</td>
        <td>deleteTopoFailed</td>
        <td>删除子设备失败</td>
    </tr>
    <tr>
        <td>36</td>
        <td>getTopoFailed</td>
        <td>查询拓扑关系失败</td>
    </tr>
    <tr>
        <td>37</td>
        <td>reachRateLimit</td>
        <td>达到请求限制</td>
    </tr>
</table>
