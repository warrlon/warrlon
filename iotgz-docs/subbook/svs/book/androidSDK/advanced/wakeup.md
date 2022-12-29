# 唤醒配置项

|参数名|取值|说明|默认值|
|-|-|-|-|
| K_WAKEUP_ROUTER | partner/dialog | 唤醒路由：<br>partner（唤醒后不会主动进入对话，开发者可以通过注册sys.wakeup.result来接收唤醒消息）<br>dialog（唤醒后主动进入对话） | dialog 
| K_WAKEUP_BIN | 唤醒资源的磁盘绝对路径，比如/sdcard/wakeup.bin | 商务定制版唤醒资源的路径。如果开发者对唤醒率有更高的要求，请联系商务申请定制唤醒资源。 | 内置通用唤醒资源 
| K_ONESHOT_MIDTIME<br>K_ONESHOT_ENDTIME | 数值型字符串，毫秒 | OneShot配置：<br>1.若MIDTIME=0&ENDTIME=0，唤醒后进入识别；若VAD检测超时，则直接退出对话<br>2.若MIDTIME=0&ENDTIME!=0，唤醒后进入识别；若ENDTIME超时，则直接退出对话<br>3.若MIDTIME!=0&ENDTIME=0，唤醒后进入识别；若MIDTIME超时，则播放欢迎语，继续识别<br>4.若MIDTIME!=0&ENDTIME!=0，唤醒后进入识别；若MIDTIME超时，则播放欢迎语，继续识别；若ENDTIME超时，则直接退出对话<br>5.若MIDTIME=-1&ENDTIME=-1, 唤醒后进入识别; 若第一次识别结果为空, 则再次进入识别 | 500，2000 
| K_NR_ENABLE | true/false | 是否开启降噪功能 | false 
| K_NR_BIN | 降噪库的磁盘绝对路径，比如/sdcard/nr.bin | 商务定制版降噪资源的路径 | 内置能用降噪资源 
| K_HIGH_VOLUME_CHECK | true/false | 是否开启大音量检测<br>如果配置为true，则调用：WakeupWord.setThreshold(String threshold, String threshold2) 设置唤醒词阈值 | false 
| K_USE_AGE | true/false | 是否开启使用年龄识别 | false 
| K_USE_GENDER | true/false | 是否开启使用性别识别 | false 
| K_USE_NEAR_WAKEUP | true/false | 是否开启就近唤醒 | false 
| K_WAKEUP_DISABLE_CUSTOM_GREETING | true/false | 是否禁止自定义欢迎语功能 | false 