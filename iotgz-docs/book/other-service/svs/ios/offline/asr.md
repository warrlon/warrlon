# 本地功能集成

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


