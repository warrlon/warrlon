# 唤醒功能集成

### 导入资源文件

使用唤醒功能需要将开发包中\res\ivw\路径下的唤醒资源文件引入，引入方式有三种：Assets、Resources、SD卡；资源文件以.jet为后缀（下图以Assets方式为例）。

![pci](/images/svs/an-3.png)


### 初始化

创建用户语音配置对象后才可以使用语音服务，建议在程序入口处调用。

    //将“123456789012”替换成您在OneNET上创建应用所获取到的APPID
    SpeechUtility.createUtility(context, SpeechConstant.APPID +"=123456789012");


### 代码添加


    //1.加载唤醒词资源，resPath为唤醒资源路径
    StringBuffer param =new StringBuffer();
    String resPath = ResourceUtil.generateResourcePath(WakeDemo.this, RESOURCE_TYPE.assets, "ivw/ivModel_zhimakaimen.jet");
    param.append(ResourceUtil.IVW_RES_PATH+"="+resPath);
    param.append(","+ResourceUtil.ENGINE_START+"="+SpeechConstant.ENG_IVW);
    SpeechUtility.getUtility().setParameter(ResourceUtil.ENGINE_START,param.toString());
    //2.创建VoiceWakeuper对象
    VoiceWakeuper mIvw = VoiceWakeuper.createWakeuper(context, null);
    //3.设置唤醒参数，详见《MSC Reference Manual》SpeechConstant类
    //唤醒门限值，根据资源携带的唤醒词个数按照“id:门限;id:门限”的格式传入
    mIvw.setParameter(SpeechConstant.IVW_THRESHOLD,"0:"+curThresh);
    //设置当前业务类型为唤醒
    mIvw.setParameter(SpeechConstant.IVW_SST,"wakeup");
    //设置唤醒一直保持，直到调用stopListening，传入0则完成一次唤醒后，会话立即结束（默认0）
    mIvw.setParameter(SpeechConstant.KEEP_ALIVE,"1");
    //4.开始唤醒
    mIvw.startListening(mWakeuperListener);
    //听写监听器
    private WakeuperListener mWakeuperListener = new WakeuperListener() {
		  public void onResult(WakeuperResult result) {
			   try {
				   String text = result.getResultString();
			   } catch (JSONException e) {
				   e.printStackTrace();
			   }}
		  public void onError(SpeechError error) {}
		  public void onBeginOfSpeech() {}
		  public void onEvent(int eventType, int arg1, int arg2, Bundle obj) {
               if (SpeechEvent.EVENT_IVW_RESULT == eventType) {
               //当使用唤醒+识别功能时获取识别结果
               //arg1:是否最后一个结果，1:是，0:否。
               RecognizerResult reslut = ((RecognizerResult)obj.get(SpeechEvent.KEY_EVENT_IVW_RESULT));
    }
    }};


### 唤醒+识别

    //使用唤醒+识别功能需要设置如下参数
    //唤醒门限值，根据资源携带的唤醒词个数按照“id:门限;id:门限”的格式传入
    mIvw.setParameter(SpeechConstant.IVW_THRESHOLD,"0:"+curThresh);
    //设置/当前业务类型为唤醒+识别
    mIvw.setParameter(SpeechConstant.IVW_SST,"oneshot");
    //设置识别引擎
    mIvw.setParameter(SpeechConstant.ENGINE_TYPE, "cloud");
    //设置云端识别使用的语法id
    mIvw.setParameter(SpeechConstant.CLOUD_GRAMMAR, grammarID);


