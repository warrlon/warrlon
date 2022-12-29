# 语音识别

主要指将连续语音快速识别为文字的过程，能识别通用常见的语句、词汇，不限制说法。

### 语音听写

    //1.创建SpeechRecognizer对象
    SpeechRecognizer mIat= SpeechRecognizer.createRecognizer(context, null);

    //2.设置听写参数，详见《MSC Reference Manual)》SpeechConstant类
    mIat.setParameter(SpeechConstant.DOMAIN, "iat");
    mIat.setParameter(SpeechConstant.LANGUAGE, "zh_cn");
    mIat.setParameter(SpeechConstant.ACCENT, "mandarin ");

    //3.开始听写
    mIat.startListening(mRecoListener);
    //听写监听器
    private RecognizerListener mRecoListener = new RecognizerListener(){
        //听写结果回调接口(返回Json格式结果，用户可参见附录)；
        //一般情况下会通过onResults接口多次返回结果，完整的识别内容是多次结果的累加；
        //关于解析Json的代码可参见Demo中JsonParser类；
        //isLast等于true时会话结束。
        public void onResult(RecognizerResult results, boolean isLast) {
			Log.d("Result:",results.getResultString ());
	    }
        //会话发生错误回调接口
    	public void onError(SpeechError error) {error.getPlainDescription(true) //获取错误码描述}
	    //开始录音
	    public void onBeginOfSpeech() {}
	    //音量值0~30
	    public void onVolumeChanged(int volume, byte[] data){}
	    //结束录音
	    public void onEndOfSpeech() {}
	    //扩展用接口
	    public void onEvent(int eventType,int arg1,int arg2, Bundle obj) {}
    };



### 上传联系人

上传联系人可以提高联系人名称识别率，也可以提高语义理解的效果，每个用户终端设备对应一个联系人列表，联系人格式详见《MSC Reference Manual》ContactManager类。

    //获取ContactManager实例化对象
    ContactManager mgr = ContactManager.createManager(context, mContactListener);	
    //异步查询联系人接口，通过onContactQueryFinish接口回调
    mgr.asyncQueryAllContactsName();

    //获取联系人监听器。
    private ContactListener mContactListener = new ContactListener() {
	     @Override
	     public void onContactQueryFinish(String contactInfos, boolean changeFlag) {
		     //指定引擎类型
             mIat.setParameter(SpeechConstant.ENGINE_TYPE, SpeechConstant.TYPE_CLOUD);
		     mIat.setParameter(SpeechConstant.TEXT_ENCODING,"utf-8");	
		     ret = mIat.updateLexicon("contact", contactInfos, lexiconListener);
		     if(ret != ErrorCode.SUCCESS){
                    Log.d(TAG,"上传联系人失败：" + ret);
             } 
	    }
    };
    //上传联系人监听器。
    private LexiconListener lexiconListener = new LexiconListener() {
	     @Override
	     public void onLexiconUpdated(String lexiconId, SpeechError error) {
		    if(error != null){
			     Log.d(TAG,error.toString());
		    }else{
			     Log.d(TAG,"上传成功！");
		    }
	    }
    };


### 上传用户词表

上传用户词表可以提高词表内词汇的识别率，也可以提高语义的效果，每个用户终端设备对应一个词表，用户词表的格式及构造方法详见《MSC Reference Manual》UserWords类。

    //上传用户词表，userwords为用户词表文件。
    String contents = "您所定义的用户词表内容";
    mIat.setParameter(SpeechConstant.TEXT_ENCODING,"utf-8");	
    //指定引擎类型
    mIat.setParameter(SpeechConstant.ENGINE_TYPE, SpeechConstant.TYPE_CLOUD);
    ret = mIat.updateLexicon("userword", contents, lexiconListener);
    if(ret != ErrorCode.SUCCESS){
	    Log.d(TAG,"上传用户词表失败：" + ret);
    }
    //上传用户词表监听器。
    private LexiconListener lexiconListener = new LexiconListener() {
	    @Override
	    public void onLexiconUpdated(String lexiconId, SpeechError error) {
		    if(error != null){
			     Log.d(TAG,error.toString());
		    }else{
			     Log.d(TAG,"上传成功！");
		    }
	    }
    };
