# 常见问题

物联平台接入过程中常见以下问题，接入方可参考解决。

### 1.物联平台账号获取

账号由物联平台管理人员分配。厂家需提供企业名称、手机号，物联平台管理人员分配账号后反馈给厂家。

### 2.物联平台登录地址

物联平台登录地址如下：
> https://iot.tsinghua.edu.cn:8443/account/login

### 3.物联平台接入地址

一般来说，设备连接物联平台，南向为设备侧，北向为基于物联平台搭建自己的业务应用。物联平台北向对接支持API，南向接入支持MQTT、HTTP、LwM2M、CoAP协议，分别对应的地址如下：

<table>
<tr style="background-color:#363636; color:#F0FFF0;"><td width="10%">地址</th><td width="20%">协议</td></tr>
<tr><td>iotjr.tsinghua.edu.cn:1667</td><td>HTTP标准协议接入</td></tr>
<tr><td>iotjr.tsinghua.edu.cn:1883</td><td>MQTT标准协议接入</td></tr>
<tr><td>iotjr.tsinghua.edu.cn:6683</td><td>CoAP标准协议接入</td></tr>
<tr><td>iotjr.tsinghua.edu.cn:5683</td><td>LwM2M标准协议接入</td></tr>
<tr><td>iotjr.tsinghua.edu.cn:51234</td><td>应用API主域名。不同的操作后面跟的uri不一样，详见开发文档。应用api是基于设备接入后再调用，和以上4个设备接入协议不是并列关系。</td></tr>
</table>

### 4.旁路接入和串联接入

物联平台定位是为业务应用提供平台，本身不是业务应用。旁路接入模式，数据备份到物联平台，原有的业务逻辑不改变。串联接入模式，基于物联平台开发整个业务应用，设备不仅要把数据传到物联平台，还要使用平台能力做命令下发和数据推送到业务平台。

### 5.四个标准接入协议的区别

HTTP标准协议接入，是单向的传输。因为HTTP是短链接协议，所以这种协议接入的设备不能使用下发命令的应用接口，而其他协议是可以的。LwM2M，CoAP是常用在NB-IoT蜂窝网络的低功耗场景协议。MQTT协议是长连接协议，需要隔一段时间（mqtt协议有个keepalive周期）就发数据，不然会断开TCP链接。