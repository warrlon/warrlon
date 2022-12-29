# 本地功能集成

### 离线合成

ttsres 目录是离线合成的引擎资源集合，common.jet 是基础资源，其他文件是发音人各自对应的资源。在实际使用时，common.jet 和发音人资源需要同时设置。发音人可以根据需要自行选择。
![pci](/images/svs/ios-11.png)

注意:添加离线资源时请使用引用方式，以使得程序编译时将资源编译到app中，如下图所示：
![pci](/images/svs/ios-12.png)

集成后在 Xcode 对应工程的 Build Phases下的copy bundle resources项目中可以看到已集成的资源。

下面代码是集成本地资源时需要添加的部分，其他代码与在线一致。

    //生成合成引擎的资源文件路径，以发音人小燕为例，请确保资源文件的存在 
    NSString *resPath = [[NSBundle mainBundle] resourcePath];
    NSString *newResPath = [[NSString alloc] initWithFormat:@"%@/tts64res/common.jet;%@/tts64res/xiaoyan.jet",resPath,resPath];
    //设置TTS的启动参数 
    [[IFlySpeechUtility getUtility] setParameter:@"tts" forKey:[IFlyResourceUtil ENGINE_START]]; 
    //生成TTS的实例
    _iFlySpeechSynthesizer = [IFlySpeechSynthesizer sharedInstance]; _iFlySpeechSynthesizer.delegate = self;
    //设置本地引擎类型 
    [_iFlySpeechSynthesizer setParameter:[IFlySpeechConstant TYPE_LOCAL] forKey:[IFlySpeechConstant ENGINE_TYPE]];
    //设置发音人为小燕
    [_iFlySpeechSynthesizer setParameter:@"xiaoyan" forKey:[IFlySpeechConstant VOICE_NAME]]; //设置TTS合成的引擎资源文件路径 
    [_iFlySpeechSynthesizer setParameter:newReth forKey:@"tts_res_path"];

### 离线命令词识别

    //1.设置本地识别参数，其他参数与在线方式一致 

    //设置引擎类型，cloud 或者 local
    [_iflySpeechRecognizer setParameter:@ "local" forKey:[IFlySpeechConstant ENGINE_TYPE]]; 
    //语法类型，本地是bnf，在线识别是abnf
    [_iflySpeechRecognizer setParameter:@ "bnf" forKey:[IFlyResourceUtil GRAMMARTYPE]]; 
    //启动asr 识别引擎
    [[IFlySpeechUtility getUtility] setParameter:@"asr" forKey:[IFlyResourceUtil ENGINE_START]]; 
    //设置引擎资源文件路径，如 demo 中的 aitalkResource 中的 common.mp3 
    [_iflySpeechRecognizer setParameter:_aitalkResourcePath forKey:[IFlyResourceUtil ASR_RES_PATH]]; 

    //2.编译语法文件(注意 grammarType 参数的区别) 

    //读取本地 bnf 语法文件内容
    grammarContent = [self readFile:_bnfFilePath];
    //调用语法编译接口
    [_iflySpeechRecognizer buildGrammarCompletionHandler:^(NSString * grammerID, 
    IFlySpeechError *error){ 

    //3.设置 grammerID 

    [_iFlySpeechRecognizer setParameter:_localgrammerId forKey:[IFlySpeechConstant
    LOCAL_GRAMMAR]];
    }grammarType:@”bnf” grammarContent:grammarContent]; 

    //4.启动识别 [_iFlySpeechRecognizer startListening];

    //5.识别代理 与在线完全一致 

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





