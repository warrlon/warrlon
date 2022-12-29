# 语音识别

### 上传联系人
上传联系人可以提高联系人名称识别率，也可以提高语义理解的效果，每个用户终端设备对应一个联系人列表。

使用示例如下所示：

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

