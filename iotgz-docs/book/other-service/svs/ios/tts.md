# 语音合成

将文字信息转化为可听的声音信息，让机器像人一样开口说话。

### 语音合成（不带界面示例）

使用示例如下所示：

    //头文件定义
    //需要实现IFlySpeechSynthesizerDelegate，为合成会话的服务代理
    @interface TTSViewController : UIViewController<IFlySpeechSynthesizerDelegate>
    { 
        IFlySpeechSynthesizer       * _iFlySpeechSynthesizer;
    }
    // 创建合成对象，为单例模式
    _iFlySpeechSynthesizer = [IFlySpeechSynthesizer sharedInstance]; _iFlySpeechSynthesizer.delegate = self;

    //设置语音合成的参数
    //语速,取值范围 0~100
    [_iFlySpeechSynthesizer setParameter:@"50" forKey:[IFlySpeechConstant SPEED]];
    //音量;取值范围 0~100
    [_iFlySpeechSynthesizer setParameter:@"50" forKey: [IFlySpeechConstant VOLUME]];
    //发音人,默认为”xiaoyan”;可以设置的参数列表可参考个 性化发音人列表
    [_iFlySpeechSynthesizer setParameter:@" xiaoyan " forKey: [IFlySpeechConstant VOICE_NAME]];   
    //音频采样率,目前支持的采样率有 16000 和 8000
    [_iFlySpeechSynthesizer setParameter:@"8000" forKey: [IFlySpeechConstant SAMPLE_RATE]];
    //asr_audio_path保存录音文件路径，如不再需要，设置value为nil表示取消，默认目录是documents
    [_iFlySpeechSynthesizer setParameter:@" tts.pcm" forKey: [IFlySpeechConstant TTS_AUDIO_PATH]];

    //启动合成会话
    [_iFlySpeechSynthesizer startSpeaking: @”你好，我是中国移动的小燕”];

    //合成结束，此代理必须要实现
    - (void) onCompleted:(IFlySpeechError *) error{}
    //可选接口
    - (void) onSpeakBegin{
    //合成开始}
    - (void) onBufferProgress:(int) progress message:(NSString *)msg{
    //合成缓冲进度}
    - (void) onSpeakProgress:(int) progress{
    //合成播放进度}