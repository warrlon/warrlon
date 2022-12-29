# **使用限制**

# **MQTT 相关限制**

**频率限制**  

<table>
<tr style="background-color:#363636; color:#F0FFF0;"><td width="25%">特性</td><td>是否支持</td><td width="50%"> 说明</td></tr>
<tr><td> 设备登录</td><td>3次/5s</td><td>单设备5s登录不能超过3次</td></tr>
<tr><td>设备上行</td><td>1/s</td><td>上行不能超过每秒1次，超限后延迟到下一秒处理</td></tr>
<tr><td>单设备订阅topic数量</td><td>10</td><td>单设备在session周期内订阅的topic数量不能超过10个，超限后订阅失败</td></tr>
<tr><td>订阅频率</td><td>10/s</td><td>订阅的topic数量不能超过10个每秒，超限后订阅失败，连接上的所有报文延迟到下一秒处理</td></tr>
<tr><td>取消订阅频率</td><td>10/s</td><td>取消订阅的topic数量不能超过10个每秒，超限后连接上的所有报文延迟到下一秒处理</td></tr>
<tr><td>ping报文</td><td>1/s</td><td>ping报文频率不能超过1个每秒，超限后连接上的所有报文延迟到下一秒处理</td></tr>
<tr><td>payload</td><td>256K</td><td>上行publish报文最大为256K，超限后断开连接</td></tr>
<tr><td>带宽</td><td>512K/s</td><td>单设备上连接，上行报文总流量不超过512K/s，超过后连接上所有报文延迟到下1s处理</td></tr>
<tr><td>设置属性</td><td>1/s </td><td>设置属性下发不能超过每秒1次，超限后下发设置属性失败（设备收不到超限后的设置命令）</td></tr>
</table>