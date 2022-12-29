<h1>API返回状态码说明</h1>

<table>
<tr><th width="20%">状态码(errno)</th><th width="25%">错误提示</th><th>说明参数</th></tr>
<tr><td>0</td><td>succ</td><td>请求成功</td></tr>
<tr><td>1</td><td>auth failed</td><td>鉴权失败，请核实自己的api-key和imei是否对应匹配。</td></tr>
<tr><td>3</td><td>parameter required</td><td>没有请求的body数据或者请求body数据格式错误。</td></tr>
<tr><td>7</td><td>service internal error</td><td>内部服务处理堆积，这时建议间隔重试或者将请求的timeout设置大一点。</td></tr>
<tr><td>2001</td><td>device not online</td><td>设备不在线，排查终端是否正常注册到平台。</td></tr>
<tr><td>5006</td><td>system logic limit</td><td>OneNET平台限制，请认真看文档参数的限制条件。</td></tr>
<tr><td>5106</td><td>UNSUCESS</td><td>1：METHOD_NOT_ALLOWED（对象或资源不允许该操作）<br>2：FORBIDDEN（终端设备未注册）<br>3：NOT_FOUND（未发现该对象或资源）<br>4：INTERNAL_SERVER_ERROR（设备响应码错误等）<br>5：TIME_OUT（设备响应超时）<br>6：REQ_PARAM_ERROR（请求参数错误）<br>7：RESP_ERROR（设备响应报文错误）<br>8：UNAUTHORIZED（访问权限不允许）<br>9：BAD_REQUEST（请求格式错误，如少参数或编码等）<br>10：NOT_ACCEPTABLE（无任何首选的报文格式可以返回）<br>11：UNSUPPORTED_CONTENT_FORMAT（指定的报文格式不支持）<br>12：OFFLINE（设备未注册）<br>13：ADDR_OCCUPIED（设备的地址被其他设备占用）</td></tr>
<tr><td>5108</td><td>invalid parameter/rpc response error</td><td>无效的参数/重试。</td></tr>
<tr><td>5117</td><td>rpc error</td><td>内部服务异常，重试。</td></tr>
</table>
