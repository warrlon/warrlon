# 语义理解

使用示例如下图所示：

    _iFlySpeechUnderstander = [IFlySpeechUnderstander sharedInstance];
    _iFlySpeechUnderstander.delegate = self; 

    [_iFlySpeechUnderstander startListening]; //启动识别服务

    /*语义识别结果返回代理
    @param resultArray 识别结果
    @ param isLast 表示是否最后一次结果
    */
    - (void) onResults:(NSArray *) results isLast:(BOOL) isLast
    {
    }
    -(void) onError:(IFlySpeechError*) error
    {
    }
    /*
    其他代理为非必要，具体请看头文件的定义
    */