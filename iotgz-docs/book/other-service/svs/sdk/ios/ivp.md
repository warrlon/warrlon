# 声纹识别

声纹识别，主要是提供基于用户声纹特征的注册、验证服务，语音云平台支持2种类型的声纹密码类型，即文本密码和数字密码，在注册时需要指定声纹类型。

#### 声纹注册

    //1.创建声纹对象
    isvRec=[IFlyISVRecognizer sharedInstance];
    isvRec.delegate=self;   

    //2.设置声纹工作参数
    //设置密码类型，pwdt的取值为1、3，分别表示文本密码和数字密码
    [isvRec setParameter:[NSString stringWithFormat:@"%d",pwdt] forKey:@"pwdt"];



pwdt的取值说明如下表所示：

<table>
<tr><th width="20%">pwdt取值</th><th>说明</th></tr>
<tr><td>1</td><td>文本密码<br>用户通过读出指定的文本内容来进行声纹注册和验证，现阶段支持的文本只有“芝麻开门”一种</td></tr>
<tr><td>3</td><td>数字密码<br>从云端拉取一组特定的数字串（共分5组，每组8位数字），用户依次读出这5组数字进行注册，在验证过程中会生成一串特定的数字，用户通过朗读这串数字进行验证</td></tr>
</table>

密码内容需调用接口从云端获取：

    //通过调用getPasswordList方法来获取密码。获取密码的时候需指定声纹密码类型，pwdt为1表示固定文本密码，pwdt为3表示数字密码，自由说不需从云端获取密码。
    // getPasswordList可以参照demo所示。
    NSArray *tmpArray=[isvRec getPasswordList:ivppwdt];

获取到密码后，接下来进行声纹注册，即要求用户朗读若干次指定的内容，这一过程也称为声纹模型的训练。

    // 设置业务类型为训练
    [isvRec setParameter:@"train"  forKey:@"sst"];
    // 设置密码类型
    [isvRec setParameter:[NSString stringWithFormat:@"%d",pwdt] forKey:@"pwdt"];
    // 对于文本密码和数字密码，必须设置密码的文本内容，ptxt的取值为“我的地盘我做主”、“移动改变生活”、“芝麻开门”或者是从云端拉取的数字密码(每8位用“-”隔开)。自由说略过此步
    [isvRec setParameter:ptxt forKey:@"ptxt"];
    // 设置声纹对应的auth_id，它用于标识声纹对应的用户
    [isvRec setParameter:auth_id forKey:@"auth_id"];
    // 设置有效录音时间
    [isvRec setParameter:@"3000" forKey:@"vad_timeout"];
    // 末端静音检测时间，用于检测到静音自动停止录音
    [isvRec setParameter:@"700" forKey:@"vad_speech_tail"];

    //3.启动训练服务
    // 开始注册，当得到注册结果时，SDK会将其封装成NSDictionary对象，回调onResult方法进行处理，处理方法详见Demo示例
    [isvRec startListening];

    //4.声纹实现delegate
    @protocol IFlyISVDelegate
    -(void) onResult:(NSDictionary *)dic;        //训练和验证正常结果返回
    -(void) onError:(IFlySpeechError *) errorCode; //会话结束，正常结束错误码为0，非0表示有错误，错误码见下面描述
    @optional
    -(void) onRecognition;                           //结果处理中
    -(void) onVolumeChanged: (int)volume;         //录音音量发生改变
    @end

推荐在注册声纹模型时每个用户都指定一个唯一的auth_id。auth_id的格式为：6-18个字符，为字母、数字和下划线的组合且必须以字母开头，不支持中文字符，不能包含空格。

开发者通过重写onResult方法来处理注册和验证结果。在结果result中携带错误码，用来判别注册是否成功以及出错原因，部分错误码的含义如下表所示：

<table>
<tr><th width="40%">错误码</th><th width="30%">错误值</th><th>说明</th></tr>
<tr><td>MSS_ERROR_IVP_GENERAL</td><td>11600</td><td>正常，请继续传音频</td></tr>
<tr><td>MSS_ERROR_IVP_EXTRA_RGN_SOPPORT</td><td>11601</td><td>rgn超过最大支持次数9</td></tr>
<tr><td>MSS_ERROR_IVP_TRUNCATED</td><td>11602</td><td>音频波形幅度太大，超出系统范围，发生截幅</td></tr>
<tr><td>MSS_ERROR_IVP_MUCH_NOISE</td><td>11603</td><td>太多噪音</td></tr>
<tr><td>MSS_ERROR_IVP_TOO_LOW</td><td>11604</td><td>声音太小</td></tr>
<tr><td>MSS_ERROR_IVP_ZERO_AUDIO</td><td>11605</td><td>没检测到音频</td></tr>
<tr><td>MSS_ERROR_IVP_UTTER_TOO_SHORT</td><td>11606</td><td>音频太短</td></tr>
<tr><td>MSS_ERROR_IVP_TEXT_NOT_MATCH</td><td>11607</td><td>音频内容与给定文本不一致</td></tr>
<tr><td>MSS_ERROR_IVP_NO_ENOUGH_AUDIO</td><td>11608</td><td>音频长达不到自由说的要求</td></tr>
</table>

#### 声纹验证

声纹验证过程与声纹注册类似，不同之处仅在于@“sst”参数需要设置为@“verify”，其他参数的设置、验证结果的处理过程可参考上一节。
另外，为了达到较好的效果，请在声纹注册与验证过程中尽量与麦克风保持同样的距离（建议的最佳距离是15厘米左右）。若距离较远，可能会对验证通过率产生较大影响。

#### 声纹模型操作

声纹注册成功后，在云端会生成一个对应的模型来存储声纹信息，声纹模型的操作即对模型进行查询和删除。

    // 开发者调用sendRequest方法查询或者删除模型，该函数的定义如下：
    -(BOOL) sendRequest:
        (NSString*)cmd                         
        authid:(NSString *)auth_id   
        pwdt:(int)pwdt 
        ptxt:(NSString *)ptxt 
        vid:(NSString *)vid 
        err:(int *)err;
    //cmd: @”query”表示查询，@”del”表示删除
    //auth_id表示用户名;
    //pwdt表示声纹类型；
    //ptxt表示查询或者删除的密码文本；
    //vid是用户注册成功后服务器返回的32位标识，查询和删除时，vid可以设置位nil;
    //err是查询的错误码。 通常查询或者删除成功，该函数会返回YES,否则返回NO;

