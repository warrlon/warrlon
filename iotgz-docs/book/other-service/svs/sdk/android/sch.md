# 语义理解

### 语音语义理解

    //1.创建文本语义理解对象
    SpeechUnderstander understander = SpeechUnderstander.createUnderstander(context, null);
    //2.设置参数
    understander.setParameter(SpeechConstant.LANGUAGE, "zh_cn");
    //3.开始语义理解
    understander.startUnderstanding(mUnderstanderListener);
    //语义理解监听接口
    private SpeechUnderstanderListener mUnderstanderListener = new SpeechUnderstanderListener(){
        public void onResult(UnderstanderResult result) { 
			    String text = result.getResultString();	
        }
	    public void onError(SpeechError error) {}//会话发生错误回调接口
	    public void onBeginOfSpeech() {}//开始录音
	    public void onVolumeChanged(int volume, byte[] data){} //音量值0~30
	    public void onEndOfSpeech() {}//结束录音
	    public void onEvent(int eventType, int arg1, int arg2, Bundle obj) {}//扩展用接口
    };


### 文本语义理解

用户通过输入文本获取语义结果，文本语义结果和上述语音的方式相同。

    //创建文本语义理解对象
    TextUnderstander mTextUnderstander = TextUnderstander.createTextUnderstander(this, null); 
    //开始语义理解
    mTextUnderstander.understandText("今天的天气", searchListener);
    //初始化监听器
    TextUnderstanderListener searchListener = new TextUnderstanderListener(){
        //语义结果回调
	    public void onResult(UnderstanderResult result){}
	    //语义错误回调
	    public void onError(SpeechError error) {}
    }; 

