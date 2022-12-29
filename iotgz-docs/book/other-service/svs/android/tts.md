#  语音合成

将文字信息转化为可听的声音信息，让机器像人一样开口说话。

使用示例如下所示：

    //1.创建SpeechSynthesizer对象
    SpeechSynthesizer mTts= SpeechSynthesizer.createSynthesizer(context, null);
    //2.合成参数设置，详见《MSC Reference Manual》SpeechSynthesizer 类
    mTts.setParameter(SpeechConstant.VOICE_NAME, "xiaoyan");//设置发音人
    mTts.setParameter(SpeechConstant.SPEED, "50");//设置语速
    mTts.setParameter(SpeechConstant.VOLUME, "50");//设置音量，范围0~100
    //设置合成音频保存位置（可自定义保存位置），保存在“./sdcard/cmcc.pcm”
    //保存在SD卡需要在AndroidManifest.xml添加写SD卡权限
    //如果不需要保存合成音频，注释该行代码
    mTts.setParameter(SpeechConstant.TTS_AUDIO_PATH, "./sdcard/tts.pcm");
    //3.开始合成
    mTts.startSpeaking("语音合成测试例子。", mSynListener);

    //合成监听器
    private SynthesizerListener mSynListener = new SynthesizerListener(){
	    //会话结束回调接口，没有错误时，error为null
	    public void onCompleted(SpeechError error) {}
	    //缓冲进度回调
	    //percent为缓冲进度0~100，beginPos为缓冲音频在文本中开始位置，endPos表示缓冲音频在文本中结束位置，info为附加信息。
	    public void onBufferProgress(int percent, int beginPos, int endPos, String info) {}
	    //开始播放
	    public void onSpeakBegin() {}
	    //暂停播放
	    public void onSpeakPaused() {}
	    //播放进度回调
	    //percent为播放进度0~100,beginPos为播放音频在文本中开始位置，endPos表示播放音频在文本中结束位置.
	    public void onSpeakProgress(int percent, int beginPos, int endPos) {}
	    //恢复播放回调接口
	    public void onSpeakResumed() {}
        //会话事件回调接口
	    public void onEvent(int arg0, int arg1, int arg2, Bundle arg3) {}
    };
