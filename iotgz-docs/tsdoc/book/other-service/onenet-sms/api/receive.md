# Uplink message reception

### Short Message Up Push

First, you need an upstream code. If you don't have an upstream code, please contact the customer service application. If you have an up-link code, you can view it on the Account Overview page of the console.

After obtaining the upstream code, you need to configure a URL address in the Console-Communication Message Receiving Settings interface to receive platform-pushed HTTP post requests.

When users reply to messages, they need to reply to "Uplink + Content". For example, the Uplink Code is UX, and the content they want to reply to is 1. Then the user should reply: UX1.

After receiving the upstream message, the platform identifies the user according to the upstream code and pushes the upstream message to each user's configured address.

### Return field


<table>
<tr><th width="20%">参数名称</th><th width="15%">类型<th>说明</th></tr>

<tr><td><center>phone</center></td><td><center>String</center></td><td><center>发送手机号码</center></td></tr>
<tr><td><center>exo</center></td><td><center>String</center></td><td><center>接收端口号</center></td><tr>
<tr><td><center>msg</center></td><td><center>String</center></td><td><center>消息内容</center></td></tr>
<tr><td><center>pushda</center></td><td><center>String</center></td><td><center>推送时间推送的时间，格式为YYYYMMDD24MISS
例如20120501110000
</center></td></tr>
</table>