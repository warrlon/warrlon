# 对话结果返回

<table style="text-align:center;">
<tr><th width="20%">参数名</th><th width="20%">类型</th><th width="35%">含义</th><th>取值示例</th></tr>
<tr><td>dm.intentName</td><td>string</td><td>意图名称</td><td>查天气</td></tr>
<tr><td>dm.input</td><td>string</td><td>识别结果或者客户端发送的文本</td><td></td></tr>
<tr><td>dm.intentId</td><td>int</td><td>意图id</td><td>0000000000000000</td></tr>
<tr><td>dm.nlg</td><td>string</td><td>系统生成的对话回复</td><td>今天的天气是晴</td></tr>
<tr><td>dm.speak</td><td>object</td><td></td><td></td></tr>
<tr><td>dm.speak.text</td><td>string</td><td>系统生成的对话回复文本</td><td></td></tr>
<tr><td>dm.speak.type</td><td>string</td><td>系统生成的对话回复类型</td><td></td></tr>
<tr><td>dm.task</td><td>string</td><td>任务名称</td><td>查天气</td></tr>
<tr><td>dm.taskId</td><td>string</td><td>任务Id</td><td></td></tr>
<tr><td>dm.shouldEndSession</td><td>bool</td><td>表示对话是否结束</td><td>true,false</td></tr>
<tr><td>dm.widget</td><td>map</td><td>控件结构化信息</td><td></td></tr>
<tr><td>skillId</td><td>string</td><td>技能id</td><td>0000000000000000</td></tr>
<tr><td>skill</td><td>string</td><td>技能名</td><td>天气</td></tr>
<tr><td>error.errId</td><td>string</td><td>错误id</td><td>010400</td></tr>
<tr><td>error.errMsg</td><td>string</td><td>错误信息</td><td>It's time to do qa.</td></tr>
<tr><td>recordId</td><td>string</td><td>uuid，标识一次请求，32字符</td><td>DUIddeeeeeeeeeeee88888888260c8ab</td></tr>
<tr><td>sessionId</td><td>string</td><td>uid，服务端通过相同的sessionId关联多轮请求的上下文；<br>首轮对话请求不需要携带；<br>非首轮对话请求取值是上一轮服务端返回结果中的sessionId</td><td>DUIddeeeeeeeeeeee88888888260c8ab</td></tr>
<tr><td>speakUrl</td><td>string</td><td>系统生成的对话回复音频文件地址（不是一定存在）</td><td></td></tr>
</table>