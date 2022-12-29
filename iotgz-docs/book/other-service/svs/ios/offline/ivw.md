# 本地功能集成

### 唤醒功能集成

使用唤醒功能需要将开发包中\resource\ivw\路径下的唤醒资源文件引入，资源文件以.jet为后缀。

![pci](/images/svs/ios-13.png)

语音唤醒流程如下：

![pci](/images/svs/ios-14.png)

创建唤醒对象

    self.iflyVoiceWakeuper = [IFlyVoiceWakeuper sharedInstance];
    self.iflyVoiceWakeuper.delegate = self;

设置唤醒参数

    //The order of the keywords must be consistent with the resource file
    NSString *thresStr = [NSString stringWithFormat:@"0:%d",(int)self.thresSlider.value];
    [self.iflyVoiceWakeuper setParameter:thresStr forKey:[IFlySpeechConstant IVW_THRESHOLD]];
    
    //set session type
    [self.iflyVoiceWakeuper setParameter:@"wakeup" forKey:[IFlySpeechConstant IVW_SST]];

    //set the path of resource file
    NSString *resPath = [[NSBundle mainBundle] resourcePath];
    NSString *wordPath = [[NSString alloc] initWithFormat:@"%@/ivw/%@.jet",resPath,APPID_VALUE];
    NSString *ivwResourcePath = [IFlyResourceUtil generateResourcePath:wordPath];
    [self.iflyVoiceWakeuper setParameter:ivwResourcePath forKey:@"ivw_res_path"];

    //set session continuation state after the service is successful.
    //0: the session ends after one wakeup; 1: the session continues after wakeup
    [self.iflyVoiceWakeuper setParameter:@"1" forKey:[IFlySpeechConstant KEEP_ALIVE]];

    //set audio source
    [self.iflyVoiceWakeuper setParameter:IFLY_AUDIO_SOURCE_MIC forKey:@"audio_source"];

    //set the audio path saved by recorder
    [self.iflyVoiceWakeuper setParameter:@"ivw.pcm" forKey:@"ivw_audio_path"];

启动唤醒

    [self.iflyVoiceWakeuper startListening];





