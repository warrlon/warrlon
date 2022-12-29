# 短信下发

#### 对原短信平台用户的特别说明
OneNET SMS短信平台于2019年5月17日凌晨上线。备份了原短信平台的模板数据和用户数据。并复制拆分原模板表到了新的签名表、模板表中。原系统已关闭，原短信平台用户可以使用新的OneNET SMS短信平台。

原模板短信下发接口调用原模板ID仍可以正常发送。新平台中对拆分后的模板进行修改不会变更老模板，也不会影响老接口的调用和短信下发。同时，新申请的模板无法被老接口调用。

在此，特别建议老用户采用新的“模板签名发送接口”进行短信发送，对此造成的不便敬请谅解。

### 模板签名短信下发（新接口）

#### 接口地址

http://api.sms.heclouds.com/tempSignSmsSend

#### 请求示例
POST:http://api.sms.heclouds.com/tempSignSmsSend?sicode=5b9a3fd4-817b-409f-a4db-85e751b31a62&tempid=xxx&signId=xxx&mobiles=13812341234,13856785678&code=2623

##### 编码：

统一使用UTF-8编码，请确保您的文件编码及传入参数的格式。

#### 请求参数：
<table>
<tr><th width="20%">名称</th><th width="15%">类型<th width="12%">必填</th><th>说明</th></tr>
<tr><td><center>sicode</center></td><td><center>String</center></td><td><center>是</center></td><td>si唯一标识</td></tr>
<tr><td><center>mobiles</center></td><td><center>String</center></td><td><center>是</center></td><td>短信接收号码,最大99条,逗号分割</td></tr>
<tr><td><center>tempid</center></td><td><center>String</center></td><td><center>是</center></td><td>模板ID,创建模板时生成的ID,需要审核通过</td></tr>
<tr><td><center>signId</center></td><td><center>String</center></td><td><center>是</center></td><td>签名ID,创建签名时生成的ID,需要审核通过</td></tr>
<tr><td><center>自定义参数1(code)</center></td><td><center>String</center></td><td><center>否</center></td><td>自定义字段，在模板短信中定义，#code#,即为参数名,可扩展,由短信模板中设置</td><tr>
<tr><td><center>……</center></td><td></td><td></td><td>自定义参数可扩展</td><tr>
</table>

#### 返回字段：
<table>
<tr><th width="10%">名称</th><th width="50%">类型</th><th>说明</th></tr>
<tr><td><center>result</center></td><td><center>String</center></td><td><center>处理结果码</center></td></tr>
<tr><td><center>resultInfo</center></td><td><center>String</center></td><td><center>处理结果信息描述</center></td></tr>
<tr><td><center>errorInfo</center></td><td><center>String</center></td><td><center>处理结果错误信息</center></td><tr>
</table>

#### 返回示例
{"result":"11101","resultInfo":"201408250920530265531100","errorInfo":""}

#### 结果码

<table>
<tr><th width="20%">结果码</th><th>说明</th></tr>
<tr><td><center>11101</center></td><td>	下发处理成功,resultInfo会返回下发流水号</td></tr>
<tr><td><center>11102</center></td><td>下发处理失败,resultInfo会描述具体失败原因,此次下发请求被放弃</td></tr>
<tr><td><center>11103</center></td><td>发送内容有敏感词,errorInfo中会返回具体的敏感词,此次下发请求被放弃</td></tr>
<tr><td><center>11104</center></td><td>下发号码包含黑名单,errorInfo会返回处于主叫黑名单的下发号码,此次下发请求被放弃</td></tr>
<tr><td><center>11105</center></td><td>接收号码包含黑名单,errorInfo会返回处于被叫黑名单的接收号码,此次下发请求被放弃</td></tr>
<tr><td><center>11106</center></td><td>接收号码中包含非法号码,errorInfo会返回非法的接收号码,此次下发请求被放弃</td></tr>
<tr><td><center>11108</center></td><td>SI鉴权失败,resultInfo中返回具体SI鉴权失败原因,如:SI不存在,此次下发请求被放弃</td></tr>
<tr><td><center>11109</center></td><td>余额不足</td></tr>
<tr><td><center>11112</center></td><td>参数异常,resultInfo返回出现异常的参数,此次下发请求被放弃</td></tr>
</table>

### 模板短信下发（老接口）

#### 接口地址：

http://api.sms.heclouds.com/tempsmsSend

#### 请求示例：

POST：http://api.sms.heclouds.com/tempsmsSend?sicode=5b9a3fd4-817b-409f-a4db-85e751b31a62&mobiles=13812341234,13856785678&tempid=10003&code=2623

##### 编码：

统一使用UTF-8编码，请确保您的文件编码及传入参数的格式。

#### 请求参数：
<table>
<tr><th width="20%">名称</th><th width="15%">类型<th width="12%">必填</th><th>说明</th></tr>
<tr><td><center>sicode</center></td><td><center>String</center></td><td><center>是</center></td><td>si编码</td></tr>
<tr><td><center>mobiles</center></td><td><center>String</center></td><td><center>是</center></td><td>短信接收号码,最大99条,逗号分割</td></tr>
<tr><td><center>tempid</center></td><td><center>String</center></td><td><center>是</center></td><td>模板ID,创建模板时生成的ID,需要审核通过</td></tr>
<tr><td><center>自定义参数1(code)</center></td><td><center>String</center></td><td><center>否</center></td><td>自定义字段，在模板短信中定义，#code#,即为参数名,可扩展,由短信模板中设置</td><tr>
<tr><td><center>……</center></td><td></td><td></td><td>自定义参数可扩展</td><tr>
</table>

#### 返回字段：
<table>
<tr><th width="10%">名称</th><th width="50%">类型</th><th>说明</th></tr>
<tr><td><center>result</center></td><td><center>String</center></td><td><center>处理结果码</center></td></tr>
<tr><td><center>resultInfo</center></td><td><center>String</center></td><td><center>处理结果信息描述</center></td></tr>
<tr><td><center>errorInfo</center></td><td><center>String</center></td><td><center>处理结果错误信息</center></td><tr>
</table>

#### 返回示例
{"result":"10701","resultInfo":"201408250920530265531100","errorInfo":""}

#### 结果码

<table>
<tr><th width="20%">结果码</th><th>说明</th></tr>
<tr><td><center>10701</center></td><td>	下发处理成功,resultInfo会返回下发流水号</td></tr>
<tr><td><center>10702</center></td><td>下发处理失败,resultInfo会描述具体失败原因,此次下发请求被放弃</td></tr>
<tr><td><center>10703</center></td><td>发送内容有敏感词,errorInfo中会返回具体的敏感词,此次下发请求被放弃</td></tr>
<tr><td><center>10704</center></td><td>下发号码包含黑名单,errorInfo会返回处于主叫黑名单的下发号码,此次下发请求被放弃</td></tr>
<tr><td><center>10705</center></td><td>接收号码包含黑名单,errorInfo会返回处于被叫黑名单的接收号码,此次下发请求被放弃</td></tr>
<tr><td><center>10706</center></td><td>接收号码中包含非法号码,errorInfo会返回非法的接收号码,此次下发请求被放弃</td></tr>
<tr><td><center>10708</center></td><td>SI鉴权失败,resultInfo中返回具体SI鉴权失败原因,如:SI不存在,此次下发请求被放弃</td></tr>
<tr><td><center>10709</center></td><td>余额不足</td></tr>
<tr><td><center>10712</center></td><td>参数异常,resultInfo返回出现异常的参数,此次下发请求被放弃</td></tr>
<tr><td><center>10713</center></td><td>模板不存在或未审核通过</td></tr>
<tr><td><center>10714</center></td><td>缺少模板参数</td></tr>
</table>


