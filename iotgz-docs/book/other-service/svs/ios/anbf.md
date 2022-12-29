# 语法识别

主要指基于命令词的识别，识别指定关键词组合的词汇，或者固定说法的短句。语法识别分云端识别和本地识别，云端和本地分别采用ABNF和BNF语法格式。

使用示例如下所示：

    // ABNF语法示例，可以说”北京到上海”；如需本地识别请参照[本地功能集成](/book/other-service/svs/ios/offline/tts.md)
    #define ABNFPARAM @”sub=asr,dtt=abnf”
    #define ABNFDATA = “#ABNF 1.0 gb2312;
                        language zh-CN; 
                        mode voice;
                        root $main;
                        $main = $place1 到$place2 ;
                        $place1 = 北京 | 武汉 | 南京 | 天津 | 天京 | 东京;
                        $place2 = 上海 | 合肥;”
    //创建上传对象
    _uploader = [[IFlyDataUploader alloc] init];

    //设置参数
    [_uploader setParameter:@"asr" forKey:@"sub"];
    [_uploader setParameter:@"abnf" forKey:@"dtt"];

    //上传abnf语法
    [_uploader uploadDataWithCompletionHandler:^(NSString * grammerID, IFlySpeechError *error)
    {
	    //接受返回的grammerID和error
        [self setGrammerId:grammerID];

    }name:ABNFNAME data:ABNFDATA];