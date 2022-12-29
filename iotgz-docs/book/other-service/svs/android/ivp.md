# 声纹识别

与指纹一样，声纹也是一种独一无二的生理特征，可以用来鉴别用户的身份。声纹密码的使用包括注册、验证和模型操作。

#### 声纹注册

现阶段仅支持数字密码，文本密码、自由说还在开发阶段。在注册之前要选择声纹的类型。

    // 首先创建SpeakerVerifier对象
    mVerify = SpeakerVerifier.createVerifier(this, null);
    // 通过setParameter设置密码类型，pwdType的取值为1、2、3，分别表示文本密码、自由说和数字密码
    mVerify.setParameter(SpeechConstant.ISV_PWDT, "" + pwdType);


pwdType的取值说明如下表所示：

<table>
<tr><th width="20%">pwdType取值</th><th>说明</th></tr>
<tr><td>1</td><td>文本密码<br>用户通过读出指定的文本内容来进行声纹注册和验证，现阶段支持的文本只有“芝麻开门”</td></tr>
<tr><td>2</td><td>自由说密码<br>用户通过读一段文字来进行声纹注册和验证，注册时要求声音长度为20秒左右，验证时要求15秒左右，内容不限</td></tr>
<tr><td>3</td><td>数字密码<br>从云端拉取一组特定的数字串（共分5组，每组8位数字），用户依次读出这5组数字进行注册，在验证过程中会生成一串特定的数字，用户通过朗读这串数字进行验证</td></tr>
</table>

除自由说外，其他两种密码需调用接口从云端获取：

    //通过调用getPasswordList方法来获取密码。mPwdListener是一个回调接口，当获取到密码后，SDK会调用其中的onBufferReceived方法对云端返回的JSON格式（具体格式见附录的密码进行处理，处理方法详见声纹Demo示例。
    mVerify.getPasswordList(SpeechListener mPwdListener);
    SpeechListener mPwdListenter = new SpeechListener() {
		   public void onEvent(int eventType, Bundle params) {}
		   public void onBufferReceived(byte[] buffer) {}
		   public void onCompleted(SpeechError error) {}
    };


获取到密码后，接下来进行声纹注册，即要求用户朗读若干次指定的内容，这一过程也称为声纹模型的训练。

    // 设置业务类型为训练
    mVerify.setParameter(SpeechConstant.ISV_SST, "train");
    // 设置密码类型
    mVerify.setParameter(SpeechConstant.ISV_PWDT, "" + pwdType);
    // 对于文本密码和数字密码，必须设置密码的文本内容，pwdTex的取值为“芝麻开门”或者是从云端拉取的数字密码(每8位用“-”隔开，如“62389704-45937680-32758406-29530846-58206497”)。自由说略过此步
    mVerify.setParameter(SpeechConstant.ISV_PWD, pwdText);
    // 对于自由说，必须设置采样频率为8000，并设置ISV_RGN为1。其他密码可略过此步
    mVerify.setParameter(SpeechConstant.SAMPLE_RATE, "8000");
    mVerify.setParameter(SpeechConstant.ISV_RGN, "1");
    // 设置声纹对应的auth_id，它用于标识声纹对应的用户，不能为空
    mVerify.setParameter(SpeechConstant.ISV_AUTHID, auth_id);
    // 开始注册，当得到注册结果时，SDK会将其封装成VerifierResult对象，回调VerifierListener对象listener的onResult方法进行处理，处理方法详见Demo示例
    mVerify.startListening(mRegisterListener);
    VerifierListener mRegisterListener =new VerifierListener() {
		    public void onVolumeChanged(int volume, byte [] data) {}
		    public void onResult(VerifierResult result) {
		    public void onEvent(int eventType, int arg1, int arg2, Bundle obj) {}
		    public void onError(SpeechError error) {}
		    public void onEndOfSpeech() {}
		    public void onBeginOfSpeech() {}
    };


注意：当auth_id不能为空，格式为：6-18个字符，为字母、数字和下划线的组合且必须以字母开头，不支持中文字符，不能包含空格。
开发者通过声明一个VerifierListener对象并重写onResult方法来处理注册结果。在结果result中携带了一个返回码（0表示成功，-1为失败）和错误码，用来判别注册是否成功以及出错原因，错误码的含义如下：

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

声纹验证过程与声纹注册类似，不同之处仅在于ISV_SST需要设置为”verify”，且不用设置ISV_RGN参数，其他参数的设置、验证结果的处理过程完全可参考上一节。

另外，为了达到较好的效果，请在声纹注册与验证过程中尽量与麦克风保持同样的距离（建议的最佳距离是15厘米左右）。如果距离差距较大的话，可能会对验证通过率产生较大影响。


#### 声纹模型操作

声纹注册成功后，在云端会生成一个对应的模型来存储声纹信息，声纹模型的操作即对模型进行查询和删除。

    // 首先设置声纹密码类型
    mVerify.setParameter(SpeechConstant.ISV_PWDT, "" + pwdType);
    // 对于文本和数字密码，必须设置声纹注册时用的密码文本，pwdText的取值为“芝麻开门”或者是从云平台拉取的数字密码。自由说略过此步
    mVerify.setParameter(SpeechConstant.ISV_PWD, pwdText);
    // 特别地，自由说一定要设置采样频率为8000，其他密码则不需要
    mVerify.setParameter(SpeechConstant.SAMPLE_RATE, “8000”);
    // 设置待操作的声纹模型的vid
    mVerify.setParameter(SpeechConstant.ISV_VID, vid);
    // 调用sendRequest方法查询或者删除模型，cmd的取值为“que”或“del”，表示查询或者删除，auth_id是声纹对应的用户标识，操作结果以异步方式回调SpeechListener类型对象listener的onBufferReceived方法进行处理，处理方法详见Demo示例
    mVerify.sendRequest(cmd, auth_id, listener);


