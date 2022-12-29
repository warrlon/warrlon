# 语法识别

主要指基于命令词的识别，识别指定关键词组合的词汇，或者固定说法的短句。语法识别分云端识别和本地识别，云端和本地分别采用ABNF和BNF语法格式。

### 上传abnf语法

    云端语法识别如下，如需本地识别请参照[本地功能集成](/book/other-service/svs/android/offline/prepare.md)
    //1.创建SpeechRecognizer对象
    SpeechRecognizer mAsr = SpeechRecognizer.createRecognizer(context, null);
    // ABNF语法示例，可以说”北京到上海”
    String mCloudGrammar = "#ABNF 1.0 UTF-8;
                        languagezh-CN; 
                        mode voice;
                        root $main;
                        $main = $place1 到$place2 ;
                        $place1 = 北京 | 武汉 | 南京 | 天津 | 天京 | 东京;
                        $place2 = 上海 | 合肥; ";
    //2.构建语法文件
    mAsr.setParameter(SpeechConstant.TEXT_ENCODING, "utf-8");
    ret = mAsr.buildGrammar("abnf", mCloudGrammar ,	grammarListener);
    if (ret != ErrorCode.SUCCESS){
	      Log.d(TAG,"语法构建失败,错误码：" + ret);
    }else{
	      Log.d(TAG,"语法构建成功");
    }
    //3.开始识别,设置引擎类型为云端
    mAsr.setParameter(SpeechConstant.ENGINE_TYPE, "cloud");
    //设置grammarId
    mAsr.setParameter(SpeechConstant.CLOUD_GRAMMAR, grammarId);
    ret = mAsr.startListening(mRecognizerListener);
    if (ret != ErrorCode.SUCCESS) {
	      Log.d(TAG,"识别失败,错误码: " + ret);
    }
    //构建语法监听器
    private GrammarListener grammarListener = new GrammarListener() {
	     @Override
	     public void onBuildFinish(String grammarId, SpeechError error) {
		     if(error == null){
			      if(!TextUtils.isEmpty(grammarId)){
                     //构建语法成功，请保存grammarId用于识别
			      }else{
				     Log.d(TAG,"语法构建失败,错误码：" + error.getErrorCode());
			      }			
		     }};
