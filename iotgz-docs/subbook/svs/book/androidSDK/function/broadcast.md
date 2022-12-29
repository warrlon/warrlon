# 语音播报

参数说明：

1）text 播报文本，支持SSML。

2）priority 优先级

提供4个优先级播报。

- ①优先级0：保留，与DDS语音交互同级，仅限内部使用；
- ②优先级1：正常，默认选项，同级按序播放；
- ③优先级2：重要，可以插话<优先级1>，同级按序播放，播报完毕后继续播报刚才被插话的<优先级1>；
- ④优先级3：紧急，可以打断当前正在播放的<优先级1|优先级2>，同级按序播放，播报完毕后播报剩余的<优先级2|优先级1>。

3）ttsId 用于追踪该次播报的id，建议使用UUID。

4）audioFocus 该次播报的音频焦点，默认值:

①优先级0：

android.media.AudioManager#AUDIOFOCUS_GAIN_TRANSIENT_EXCLUSIVE

②优先级非0：

android.media.AudioManager#AUDIOFOCUS_GAIN_TRANSIENT_MAY_DUCK

    // 请求语音播报
    
    DDS.getInstance().getAgent().getTTSEngine().speak("这是一段测试文本", 1, "100", AudioManager.AUDIOFOCUS_GAIN_TRANSIENT_MAY_DUCK);

停止播报接口如下:

1）ttsId与speak接口的ttsId一致，则停止或者移除该播报；

2）ttsId为空， 停止所有播报；

3）ttsId为"0"，停止当前播报。

    // 停止播报
    
    DDS.getInstance().getAgent().getTTSEngine().shutup("100");