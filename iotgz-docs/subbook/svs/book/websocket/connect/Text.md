# 发送文本请求

<table style="text-align:center;">
<tr><th width="15%">参数名</th><th width="15%">类型</th><th width="30%">含义</th><th width="15%">是否必须</th><th>取值示例</th></tr>
<tr><td>topic</td><td>string</td><td>用于区分语音请求，文本请求、关闭连接请求</td><td>是</td><td>nlu.input.text</td></tr>
<tr><td>recordId</td><td>string</td><td>uuid，标识一次请求，32字符</td><td>否</td><td>DUIddeeeeeeeeeeee88888888260c8ab</td></tr>
<tr><td>sessionId</td><td>string</td><td>uuid，服务端通过相同的sessionId关联多轮请求的上下文；<br>首轮对话请求不需要携带；<br>非首轮对话请求取值是上一轮服务端返回结果中的sessionId</td><td>否</td><td>DUIddeeeeeeeeeeee88888888260c8ab</td></tr>
<tr><td>refText</td><td>string</td><td>用户发送的文本请求</td><td>是</td><td>topic为nlu.input.text时必须</td></tr>
<tr><td>aiType</td><td>string</td><td>指定云端服务的类型，asr表示识别结果，不设置该字段表示对话文本结果</td><td>否</td><td>dm</td></tr>
</table>