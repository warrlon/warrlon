# 语音识别

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

