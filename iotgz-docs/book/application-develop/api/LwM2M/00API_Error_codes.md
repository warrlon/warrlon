<h1>API返回状态码说明</h1>

状态码(errno)|错误提示|说明参数 
:-: | :- | :- 
0|succ|请求成功
1|auth failed|鉴权失败，请核实自己的api-key和imei是否对应匹配
3|parameter required|没有请求的body数据或者请求body数据格式错误
7|service internal error|内部服务处理堆积，这时建议间隔重试或者将请求的timeout设置大一点
2001|device not online|设备不在线，排查终端是否正常注册到平台
5006|system logic limit.|物联平台限制，请认真看文档参数的限制条件
5106|UNSUCESS|1：METHOD_NOT_ALLOWED（对象或资源不允许该操作）<br>2：FORBIDDEN（终端设备未注册）<br>3：NOT_FOUND（未发现该对象或资源）<br>4：INTERNAL_SERVER_ERROR（设备响应码错误等）<br>5：TIME_OUT（设备响应超时）<br>6：REQ_PARAM_ERROR（请求参数错误）<br>7：RESP_ERROR（设备响应报文错误）<br>8：UNAUTHORIZED（访问权限不允许）<br>9：BAD_REQUEST（请求格式错误，如少参数或编码等）<br>10：NOT_ACCEPTABLE（无任何首选的报文格式可以返回）<br>11：UNSUPPORTED_CONTENT_FORMAT（指定的报文格式不支持）<br>12：OFFLINE（设备未注册）<br>13：ADDR_OCCUPIED（设备的地址被其他设备占用）
5108|invalid parameter/rpc response error|无效的参数/重试
5117|rpc error|内部服务异常，重试

