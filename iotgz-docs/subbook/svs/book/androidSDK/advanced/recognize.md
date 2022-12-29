# 识别配置项

|参数名|取值|说明|默认值|
|-|-|-|-|
| K_ASR_ROUTER | partner/dialog | 识别路由：<br>partner（将识别结果传递给partner，不会主动进入对话）<br>dialog（将识别结果传递给dui，会主动进入对话) | dialog 
| K_ASR_ENABLE_PUNCTUATION | true/false | 识别结果是否带标点符号 | false 
| K_ASR_ENABLE_TONE | true/false | 识别结果的拼音是否带音调 | false 
| K_VAD_TIMEOUT | 数值型字符串，毫秒 | VAD静音检测超时时间，默认8000毫秒 | 8000 
| K_VAD_BIN | VAD资源的磁盘绝对路径，比如/sdcard/vad.bin | 商务定制版VAD资源的路径。如果开发者对VAD有更高的要求，请联系商务申请定制VAD资源。 | 内置通用VAD资源 
| K_ASR_TIPS | true/false | 识别完成是否播报提示音 | false 
| K_ASR_ENABLE_NUMBER_CONVERT | true/false | 中文数据转阿拉伯数字 | false 
| K_ASR_NOT_DROP_WAKEUP | true/false | 识别时不要过滤唤醒词 | false 

注： DDSConfig.K_ASR_ENABLE_PUNCTUATION 开关同时控制识别和语义，开启后，语义解析结果也会带标点符号，且不建议在oneshot、中英文连用、轻音的情况下使用。