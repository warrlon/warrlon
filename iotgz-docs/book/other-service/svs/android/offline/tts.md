# 本地功能集成

### 本地合成

利用本地引擎合成语音，需要将引擎类型设为本地。

    //1.创建SpeechSynthesizer对象
    SpeechSynthesizer mTts= SpeechSynthesizer.createSynthesizer(context, null);
    //2.合成参数设置
    //设置引擎类型为本地
    mTts.setParameter(SpeechConstant.ENGINE_TYPE, SpeechConstant.TYPE_LOCAL); 
    //设置本地发音人
    mTts.setParameter(SpeechConstant.VOICE_NAME, "xiaoyan");
    加载本地合成资源，resPath为本地合成资源路径
    mTts.setParameter(ResourceUtil.TTS_RES_PATH, resPath);
    //设置合成音频保存位置（可自定义保存位置），保存在“./sdcard/cmcc.pcm”
    //保存在SD卡需要在AndroidManifest.xml添加写SD卡权限
    //如果不需要保存合成音频，注释该行代码
    mTts.setParameter(SpeechConstant.TTS_AUDIO_PATH, "./sdcard/cmcc.pcm");
    //3.开始合成
    mTts.startSpeaking("中国移动灵犀云", mSynListener);

### 混合模式

混合能力是MSC的功能亮点，能够在较差的网络环境下，选择最优的方式进行语音交互。使用混合模式时，只需将引擎设置为mixed。

混合模式包含两种，一种是实时模式，即同时向云端和本地发送音频，当云端返回结果超时时，返回本地结果；另一种是延时模式，先向云端发送音频，当云端返回结果超时后自动转为向本地发送音频的模式；其对应的参数设置分别为mixed_type：realtime（实时）、delay（延时）。其中，混合模式超时的时间设置参数为mixed_timeout，单位为ms。


