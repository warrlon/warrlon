# 语音识别

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
