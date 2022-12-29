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

