# 上行消息接收

### 短信上行推送

首先，您需要在“控制台-通用设置”界面配置一个URL地址来接收平台推送的http post请求。
![pci](/images/sms/11.png)

1、使用OneNET账户登录并使用SMS服务的用户，以及使用模板签名短信下发接口的原系统用户，可以直接回复上行内容。系统将自动推送上行内容至您配置的地址。

2、使用原系统登录并使用模板接口下发短信的用户。需要使用上行码进行上行消息回复。您可在控制台“账户概览”页面中查看上行码。若您没有上行码，请联系客服进行申请。
![pci](/images/sms/10.png)
获取上行码后，用户在回复消息时，需回复“上行码+内容”，比如上行码为UX，用户要回复的内容是1。那么用户应该回复：UX1。

平台接收到上行消息后，会根据上行码识别用户，分别将上行消息推送到各用户配置的地址。

### 返回字段

<table>
<tr><th width="20%">参数名称</th><th width="15%">类型<th>说明</th></tr>

<tr><td><center>phone</center></td><td><center>String</center></td><td><center>发送手机号码</center></td></tr>
<tr><td><center>exo</center></td><td><center>String</center></td><td><center>接收端口号</center></td><tr>
<tr><td><center>msg</center></td><td><center>String</center></td><td><center>消息内容</center></td></tr>
<tr><td><center>pushda</center></td><td><center>String</center></td><td><center>推送时间推送的时间，格式为YYYYMMDD24MISS
例如20120501110000
</center></td></tr>
</table>

