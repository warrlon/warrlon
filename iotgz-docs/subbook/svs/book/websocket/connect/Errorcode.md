# 错误码列表

<table style="text-align:center;">
<tr><th width="20%">errId</th><th width="40%">errMsg</th><th>含义</th></tr>
<tr><td>501</td><td>text read wait Time out</td><td>请求连接之后的文本参数获取超时</td></tr>
<tr><td>601</td><td>get asr service conf error</td><td>获取第三方asr调用配置失败</td></tr>
<tr><td>602</td><td>speech recognize error</td><td>asr识别错误</td></tr>
<tr><td>603</td><td>speech recognize empty</td><td>asr识别结果为空</td></tr>
<tr><td>604</td><td>audio read timeOut</td><td>用户音频读取超时</td></tr>
<tr><td>605</td><td>audio read error</td><td>用户音频读取错误</td></tr>
<tr><td>606</td><td>audio read none</td><td>未读取到用户音频</td></tr>
<tr><td>607</td><td>audio format not support</td><td>用户音频格式不支持</td></tr>
<tr><td>608</td><td>action lang not support</td><td>用户需求语言第三方asr不支持</td></tr>
<tr><td>609</td><td>asr timeOut</td><td>在规定时间内未等到足够音频数据来向第三方asr发起请求</td></tr>
<tr><td>610</td><td>asr internet error</td><td>第三方asr网络不通</td></tr>
<tr><td>611</td><td>asr result format error</td><td>第三方asr返回结果解析失败</td></tr>
<tr><td>700</td><td>ai with empty text</td><td>以空文本请求对话结果</td></tr>
<tr><td>701</td><td>get ai service conf error</td><td>第三方语义理解配置获取失败</td></tr>
<tr><td>702</td><td>ai internal error</td><td>语义理解网络异常</td></tr>
<tr><td>704</td><td>ai result error</td><td>语义理解返回结果格式错误</td></tr>
</table>