# 语音识别

主要指将连续语音快速识别为文字的过程，能识别通用常见的语句、词汇，不限制说法。

### 语音听写（带界面示例）

使用示例如下图所示：

    //头文件定义
    //需要实现IFlyRecognizerViewDelegate，为识别会话的服务代理

    @interface RecognizerViewController : UIViewController<IFlyRecognizerViewDelegate>
    {
        IFlyRecognizerView      *_iflyRecognizerView;
    }

    //初始化语音识别控件
    _iflyRecognizerView = [[IFlyRecognizerView alloc] initWithCenter:self.view.center];
    _iflyRecognizerView.delegate = self;
    [_iflyRecognizerView setParameter: @"iat" forKey: [IFlySpeechConstant IFLY_DOMAIN]];
    //asr_audio_path保存录音文件名，如不再需要，设置value为nil表示取消，默认目录是documents
    [_iflyRecognizerView setParameter:@"asrview.pcm " forKey:[IFlySpeechConstant ASR_AUDIO_PATH]];

    //启动识别服务
    [_iflyRecognizerView start];

    /*识别结果返回代理
    @param resultArray 识别结果
    @ param isLast 表示是否最后一次结果
    */
    - (void)onResult: (NSArray *)resultArray isLast:(BOOL) isLast
    {
    }

    /*识别会话错误返回代理
    @ param  error 错误码
    */
    - (void)onError: (IFlySpeechError *) error
    {
    }


使用sms-5s16引擎额外增加如下参数：

    //progressive 流式识别 accent=mandarin, domain=iat5s, rate 决定了sms-5s16引擎
    [_iFlySpeechRecognizer setParameter: @"http://lingxi.openspeech.cn/65.htm" forKey: @"server_url"];
    [_iFlySpeechRecognizer setParameter:@"wpgs" forKey:@"dwa"];
    [_iFlySpeechRecognizer setParameter:@"mandarin" forKey:@"accent"];
    [_iFlySpeechRecognizer setParameter:@"iat5s" forKey:@"domain"];
注：结果解析与普通听写解析有些区别，解析方式参考Demo中的听写回调onResults:中ISRDataHelper解析。


### 上传联系人
上传联系人可以提高联系人名称识别率，也可以提高语义理解的效果，每个用户终端设备对应一个联系人列表。

使用示例如下图所示：

    //创建上传对象
    _uploader = [[IFlyDataUploader alloc] init];

    //获取联系人集合
    IFlyContact *iFlyContact = [[IFlyContact alloc] init];
    NSString *contactList = [iFlyContact contact];

    //设置参数
    [_uploader setParameter:@"uup" forKey:@"subject"];
    [_uploader setParameter:@"contact" forKey:@"dtt"];

    //启动上传
    [_uploader uploadDataWithCompletionHandler:^(NSString * grammerID, IFlySpeechError *error)
    {
	//接受返回的grammerID和error
    [self onUploadFinished:grammerID error:error];

    }name:@"contact" data: contactList];

### 上传用户词表
上传用户词表可以提高词表内词汇的识别率，也可以提高语义的效果，每个用户终端设备对应一个词表。

使用示例如下图所示：

    //创建上传对象
    _uploader = [[IFlyDataUploader alloc] init];

    //用户词表  
    #define USERWORDS   @"{\"userword\":[{\"name\":\"cmcc\",\"words\":[\"德国盐猪手\",\"1912酒吧街\",\"清蒸鲈鱼\",\"挪威三文鱼\",\"黄埔军校\",\"横沙牌坊\",\"中国移动\",\”王小贰\”]}]}"

    #define NAME @"userwords"

    //生成用户词表对象
    IFlyUserWords *iFlyUserWords = [[IFlyUserWords alloc] initWithJson:USERWORDS ];

    //设置参数
    [_uploader setParameter:@"iat" forKey:@"sub"];
    [_uploader setParameter:@"userword" forKey:@"dtt"];

    [_uploader uploadDataWithCompletionHandler:^(NSString * grammerID, IFlySpeechError *error)
    {
	    //接受返回的grammerID和error
	    [self onUploadFinished:grammerID error:error];

    } name:NAME data:[iFlyUserWords toString]];
   