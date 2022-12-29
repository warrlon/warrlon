# 语音识别

### 上传用户词表
上传用户词表可以提高词表内词汇的识别率，也可以提高语义的效果，每个用户终端设备对应一个词表。

使用示例如下所示：

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
   