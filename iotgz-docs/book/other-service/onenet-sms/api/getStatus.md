# 状态报告获取

#### 接口地址

http://api.sms.heclouds.com/getStatusReport

#### 请求示例

GET：http://api.sms.heclouds.com/getStatusReport?sicode=5b9a3fd4-817b-409f-a4db-85e751b31a62&seriNum=201408250920530265531100&receivePhone=15912312333

#### 编码
统一使用UTF-8编码，请确保您的文件编码及传入参数的格式

#### 请求参数：
<table>
<tr><th width="20%">名称</th><th width="15%">类型<th width="12%">必填</th><th>说明</th></tr>
<tr><td><center>sicode</center></td><td><center>String</center></td><td><center>是</center></td><td><center>si编码</center></td></tr>
<tr><td><center>seriNum</center></td><td><center>String</center></td><td><center>是</center></td><td><center>下发流水号</center></td></tr>
<tr><td><center>receivePhone</center></td><td><center>String</center></td><td><center>是</center></td><td><center>接收手机号</center></td><tr>
</table>

#### 返回字段：
<table>
<tr><th width="20%">名称</th><th width="15%">类型</th><th>说明</th></tr>
<tr><td><center>result</center></td><td><center>String</center></td><td><center>处理结果码</center></td></tr>
<tr><td><center>resultInfo</center></td><td><center>String</center></td><td><center>处理结果描述信息</center></td></tr>
<tr><td><center>errorInfo</center></td><td><center>String</center></td><td><center>处理结果错误信息</center></td><tr>
<tr><td><center>data</center></td><td><center>—</center></td><td><center>返回结果集</center></td></tr>
<tr><td><center>seriNum</center></td><td><center>String</center></td><td><center>下发流水号</center></td></tr>
<tr><td><center>receivePhone</center></td><td><center>String</center></td><td><center>接收号码</center></td><tr>
<tr><td><center>state</center></td><td><center>String</center></td><td><center>状态报告</center></td></tr>
<tr><td><center>reportTime</center></td><td><center>String</center></td><td><center>用户收到短信时间 格式:YYYYMMDD24MISS</center></td><tr>
</table>

#### 返回示例
{"result":"10510","resultInfo":"success","errorInfo":"","data":{"seriNum":"201408250920530265531100","receivePhone":"15912312333","state":"DELIVRD","reportTime":"20140825141330"}}

#### 错误码
<table>
<tr><th width="20%">结果码</th><th width="80%">说明</th></tr>
<tr><td><center>10508</center></td><td>	SI鉴权失败</td></tr>
<tr><td><center>10510</center></td><td>	获取状态执行成功,resultInfo中返回具体状态报告信息,success代表下发成功,data中包含详细信息;failed代表下发失败,data为null</td></tr>
<tr><td><center>10511</center></td><td>	获取状态报告失败,resultInfo中返回具体失败原因</td></tr>
</table>

#### 推送状态报告
在控制台，配置状态报告接收地址，我们将为您实时推送最新的状态报告，您需要提供一个url地址，接受http post请求

#### 返回字段
<table>
<tr><th width="20%">名称</th><th width="15%">类型<th>说明</th></tr>

<tr><td><center>seriNum</center></td><td><center>String</center></td><td><center>下发流水号</center></td></tr>
<tr><td><center>receivePhone</center></td><td><center>String</center></td><td><center>接收手机号</center></td><tr>
<tr><td><center>state</center></td><td><center>String</center></td><td><center>状态报告</center></td></tr>
<tr><td><center>reportTime</center></td><td><center>String</center></td><td><center>用户收到短信时间 格式:YYYYMMDD24MISS</center></td></tr>
</table>

#### 返回示例
{"seriNum":"201408250920530265531100","receivePhone":"15912312333","state":"DELIVRD","reportTime":"20140825141330"}

#### 状态报告state字段定义
##### 移动手机
<table>
<tr><th width="20%">结果码</th><th>说明</th></tr>
<tr><td><center>DELIVRD</center></td><td>用户收到短信</td></tr>
<tr><td><center>EXPIRED</center></td><td>短信过期（用户长时间关机，不在服务区）</td></tr>
<tr><td><center>DELETED</center></td><td>短信被删除</td></tr>
<tr><td><center>UNDELIV</center></td><td>短信无法送达（用户状态不正确，无法享受服务）</td></tr>
<tr><td><center>ACCEPTD</center></td><td>短信处于接收状态</td></tr>
<tr><td><center>UNKNOWN</center></td><td>未知错误</td></tr>
<tr><td><center>REJECTD</center></td><td>短信被拒绝</td></tr>
<tr><td><center>MA:xxxx</center></td><td>短信中心不返回响应消息时的状态报告（xxxx为4位错误码）</td></tr>
<tr><td><center>MB:xxxx</center></td><td>短信中心返回错误响应消息时的状态报告（xxxx为4位错误码）</td></tr>
<tr><td><center>CA:xxxx</center></td><td>业务控制点不返回响应消息时的状态报告（xxxx为4位错误码）</td></tr>
<tr><td><center>CA:xxxx</center></td><td>业务控制点返回错误响应消息时的状态报告（xxxx为4位错误码）</td></tr>
</table>

##### 联通、电信手机
参数值	说明
state	0为成功，其他失败
<table>
<tr><th width="20%">参数值</th><th width="20%">说明</th></tr>
<tr><td><center>state</center></td><td><center>0为成功，其他失败</center></td></tr>
</table>




