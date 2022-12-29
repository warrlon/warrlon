# TTS配置项

|参数名|取值|说明|默认值|
|-|-|-|-|
| K_TTS_MODE | external/internal| TTS模式：<br>external（使用外置TTS引擎，需主动注册TTS请求监听器）<br>internal（使用内置DUI TTS引擎） |internal |
| K_STREAM_TYPE | AudioManager.STREAM_*的取值 | 内置播放器的STREAM类型 | AudioManager.STREAM_ALARM |
| K_AUDIO_USAGE | AudioAttributes.USAGE_*的取值 | 内置播放器的USAGE类型,兼容7.0以后的新版本参数 | 无 |
| K_CONTENT_TYPE | AudioAttributes.CONTENT_TYPE_*的取值 | 内置播放器的contenttype类型,兼容7.0以后的新版本参数 | 无 |
| K_CUSTOM_TIPS | json字符串 | 指定对话错误码的TTS播报。若未指定，则使用产品配置。<br>{<br>"71304":"这是识别结果为空的自定义播报",<br>"71305":"这是语义结果为空的自定义播报",<br>"71308":"这是进入闲聊技能的自定义播报",<br>"713**":"*****"<br>} | 产品配置 |
| K_CUSTOM_AUDIO | JSONArray字符串 | \[<br>{<br>"name":"我在",<br>"type":"wav",<br>"path":"/sdcard/x.pcm"<br>}<br>{<br>"name":"好的，再见",<br>"type":"mp3",<br>"path":"/sdcard/y.mp3"<br>}<br>\] | 无 |
| K_TTS_OPTIMIZATION | true/false | 是否TTS开启内存优化 | false |
