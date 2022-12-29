# 使用限制

使用物联网平台常见限制如下：
## 通用限制

<table>
<tr><th width="15%">限制项</th><th width="70%">详细描述</th><th>限制指标</th></tr>
<tr><td>产品数量</td><td>未认证用户最多创建3个产品，个人认证用户最多创建10个产品，企业认证用户产品数量无限制</td><td>3/10/无限制</td></tr>
<tr><td>设备数量</td><td>未认证用户每个产品最多创建10个设备，个人认证用户每个产品最多创建1000个设备，企业认证用户每个产品下的设备数量无限制</td><td>单产品下10/1000/无限制 </td></tr>
<tr><td>API调用频率</td><td>单IP每秒限制100次接口调用</td><td>100次/s </td></tr>
<tr><td>body大小限制</td><td>POST方式限制body大小为4M</td><td>4M </td></tr>
<tr><td>API超时时间</td><td>超时时间10s</td><td>10s </td></tr>
</table>



## MQTT接入限制

<table>
<tr><th width="15%">限制项</th><th width="70%">详细描述</th><th>限制指标</th></tr>
<tr><td>设备登陆频率</td><td>5s内不超过10次，超过后踢设备下线，并回复rst，拉黑设备5分钟</td><td>10次/5s</td></tr>
</table>


## CoAP接入限制

<table>
<tr><th width="15%">限制项</th><th width="70%">详细描述</th><th>限制指标</th></tr>
<tr><td>设备登陆频率</td><td>每分钟不超过20次</td><td>20次/min</td></tr>
<tr><td>设备保活</td><td>每分钟不超过10次</td><td>10次/min </td></tr>

<tr><td>设备登出</td><td>每分钟不超过10次</td><td>10次/min </td></tr>
<tr><td>物模型上报数据</td><td>每分钟不超过200次</td><td>200次/min </td></tr>
<tr><td>物模型属性设置</td><td>每分钟不超过60次</td><td>60次/min </td></tr>
</table>