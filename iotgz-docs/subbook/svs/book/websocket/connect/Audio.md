# 发送语音请求

websocket连接建立成功之后，调用端首先向服务端发送一个opcode为text的报文；这个报文的payload是一个json字符串。

<table style="text-align:center;">
<tr><th width="15%">参数名</th><th width="15%">类型</th><th width="30%">含义</th><th width="15%">是否必须</th><th>取值示例</th></tr>
<tr><td>topic</td><td>string</td><td>用于区分语音请求，文本请求、关闭连接请求</td><td>是</td><td>recorder.stream.start</td></tr>
<tr><td>recordId</td><td>string</td><td>uuid，标识一次请求，32字符</td><td>否</td><td>DUIddeeeeeeeeeeee88888888260c8ab</td></tr>
<tr><td>sessionId</td><td>string</td><td>uuid，服务端通过相同的sessionId关联多轮请求的上下文；<br>首轮对话请求不需要携带；<br>非首轮对话请求取值是上一轮服务端返回结果中的sessionId</td><td>否</td><td>DUIddeeeeeeeeeeee88888888260c8ab</td></tr>
<tr><td>audio</td><td>object</td><td>用户发送音频格式</td><td>是</td><td>topic为recorder.stream.start时必须</td></tr>
<tr><td>audio.audioType</td><td>string</td><td>音频类型，推荐使用压缩过的音频格式，以节省带宽，推荐ogg，不支持ogg vorbis，只支持ogg speex</td><td>是</td><td>ogg, wav,mp3,flv,amr,opus</td></tr>
<tr><td>audio.sampleRate</td><td>int</td><td>音频数据采样率，推荐使用16000; （ogg支持8000、16000；wav支持8000、16000；mp3支持16000、22050、44100；amr支持8000）</td><td>是</td><td>16000</td></tr>
<tr><td>audio.channel</td><td>int</td><td>声道</td><td>是</td><td>1</td></tr>
<tr><td>audio.sampleBytes</td><td>int</td><td>音频数据每采样点大小</td><td>是</td><td>2</td></tr>
<tr><td>wakeupWord</td><td>string</td><td>触发当次请求的唤醒词，用于oneshot使用场景</td><td>否</td><td>你好小目</td></tr>
<tr><td>asrParams</td><td>object</td><td>asr配置参数</td><td>否</td><td></td></tr>
<tr><td>asrParams.enableVAD</td><td>bool</td><td>是否使用云端vad，默认true</td><td>否</td><td>true,false</td></tr>
<tr><td>asrParams.enablePunctuation</td><td>bool</td><td>识别结果是否开启标点符号，默认false</td><td>否</td><td>true,false</td></tr>
<tr><td>asrParams.enableTone</td><td>bool</td><td>是否使用拼音带声调，默认false</td><td>否</td><td>true,false</td></tr>
<tr><td>asrParams.enableConfidence</td><td>bool</td><td>识别结果是否返回置信度，默认false</td><td>否</td><td>true,false</td></tr>
<tr><td>asrParams.enableNumberConvert</td><td>bool</td><td>识别结果中文数字转成阿拉伯数字，默认false</td><td>否</td><td>true,false</td></tr>
<tr><td>asrParams.phraseHints</td><td>object</td><td>使用热词识别（pattern要在第二路，或者第三路lm中存在）</td><td>否</td><td>[{"type": "vocab", "name": "行政区", "data":["黄浦区"]}]</td></tr>
<tr><td>aiType</td><td>string</td><td>指定云端服务的类型，asr表示识别结果，tts表示对话音频结果、不设置该字段表示对话文本结果</td><td>否</td><td>asr</td></tr>
</table>

调用端发送完opcode为text的报文之后，接着发送语音数据，opcode为binary，payload是语音数据；

语音数据建议分帧发送，每帧包含的语音时长是100毫秒；

语音数据发送完毕之后，再发送一个opcode为binary，payload是空，表示语音数据发送完毕。
