# 本地功能集成

### 导入资源文件

MSC支持本地听写、识别和合成等语音功能，使用时需要导入本地资源文件（.jet后缀），资源可以存放在以下三个位置：Assets、Resources、SD卡。下图以Assets方式为例：

![pci](/images/svs/an-2.png)

### 本地资源加载

加载本地资源的方式共有三种，可以选择性的在不同阶段加载，且资源只需加载一次。以听写为例：

1、createUtility初始化时

    StringBuffer param = new StringBuffer();
    //加载识别本地资源，resPath为本地识别资源路径
    param.append(”,”+ResourceUtil.ASR_RES_PATH+”=”+resPath);
    param.append(”,”+ResourceUtil.ENGINE_START+”=”+SpeechConstant.ENG_ASR); 
    param.append(”;”+ SpeechConstant.APPID+"=123456789012");
    SpeechUtility.createUtility(context, param);

 2、setParameter方式

    StringBuffer param =new StringBuffer();
    //加载识别本地资源，resPath为本地识别资源路径
    param.append(ResourceUtil.ASR_RES_PATH+”=”+resPath);
    param.append(”,”+ResourceUtil.ENGINE_START+”=”+SpeechConstant.ENG_ASR);
    SpeechUtility.getUtility().setParameter(ResourceUtil.ENGINE_START,param);

3、会话开始时

    //加载识别本地资源，mIat为听写对象，resPath为本地识别资源路径
    mIat.setParameter(ResourceUtil.ASR_RES_PATH, resPath);
    //设置引擎类型为本地
    mIat.setParameter(SpeechConstant.ENGINE_TYPE, SpeechConstant.TYPE_LOCAL);
    mIat.startListening(recognizerListener);

其中上述代码中resPath指本地资源路径，因资源存放路径不同，其导入方式也有三种：

1、Assets

    String resPath = ResourceUtil.generateResourcePath(mContext, RESOURCE_TYPE.assets, "asr/common.jet")+ ";" + ResourceUtil.generateResourcePath(mContext, RESOURCE_TYPE.assets, "asr/src_16k.jet");

2、Resources

    String resPath = ResourceUtil.generateResourcePath(mContext, RESOURCE_TYPE.res, String.valueOf(R.raw.asr_common)) + ";" + ResourceUtil.generateResourcePath(mContext, RESOURCE_TYPE.res, String.valueOf(R.raw.asr_src_16k));

3、SD卡

    String resPath = ResourceUtil.generateResourcePath(mContext, RESOURCE_TYPE.path,"/sdcard/msc/res/asr/common.jet")+ ";" + ResourceUtil.generateResourcePath(mContext,RESOURCE_TYPE.path,"/sdcard/msc/res/asr/src_16k.jet");

### 本地引擎销毁

本地引擎销毁方式有两种，一种是注销方式，所有的本地引擎都会被销毁；另一种是指定资源销毁方式，只会销毁指定的引擎。代码示例如下：

1、注销方式

    SpeechUtility.getUtility().destroy();

2、指定引擎销毁方式
    
    SpeechUtility.getUtility().setParameter("engine_destroy", "asr");


### 本地识别

利用本地引擎进行识别，需要将引擎类型设为本地。

    //1.创建SpeechRecognizer对象，需传入初始化监听器
    SpeechRecognizer mAsr = SpeechRecognizer.createRecognizer(context, null);
    //2.构建语法（本地识别引擎目前仅支持BNF语法），方法同在线语法识别，详见Demo
    //3.开始识别,设置引擎类型为本地
    mAsr.setParameter(SpeechConstant.ENGINE_TYPE, SpeechConstant.TYPE_LOCAL);
    //设置本地识别使用语法id(此id在语法文件中定义)、门限值
    mAsr.setParameter(SpeechConstant.LOCAL_GRAMMAR, "call");
    mAsr.setParameter(SpeechConstant.MIXED_THRESHOLD, "30");
    //设置语法构建生成路径，buildpath是生成路径，可以设置在sd卡内
    mAsr.setParameter(ResourceUtil.GRM_BUILD_PATH, buildpath);
    mAsr.setParameter(ResourceUtil.ASR_RES_PATH, resPath);
    ret = mAsr.startListening(mRecognizerListener);

### 本地合成

利用本地引擎合成语音，需要将引擎类型设为本地。

    //1.创建SpeechSynthesizer对象
    SpeechSynthesizer mTts= SpeechSynthesizer.createSynthesizer(context, null);
    //2.合成参数设置
    //设置引擎类型为本地
    mTts.setParameter(SpeechConstant.ENGINE_TYPE, SpeechConstant.TYPE_LOCAL); 
    //设置本地发音人
    mTts.setParameter(SpeechConstant.VOICE_NAME, "xiaoyan");
    加载本地合成资源，resPath为本地合成资源路径
    mTts.setParameter(ResourceUtil.TTS_RES_PATH, resPath);
    //设置合成音频保存位置（可自定义保存位置），保存在“./sdcard/cmcc.pcm”
    //保存在SD卡需要在AndroidManifest.xml添加写SD卡权限
    //如果不需要保存合成音频，注释该行代码
    mTts.setParameter(SpeechConstant.TTS_AUDIO_PATH, "./sdcard/cmcc.pcm");
    //3.开始合成
    mTts.startSpeaking("中国移动灵犀云", mSynListener);

### 混合模式

混合能力是MSC的功能亮点，能够在较差的网络环境下，选择最优的方式进行语音交互。使用混合模式时，只需将引擎设置为mixed。

混合模式包含两种，一种是实时模式，即同时向云端和本地发送音频，当云端返回结果超时时，返回本地结果；另一种是延时模式，先向云端发送音频，当云端返回结果超时后自动转为向本地发送音频的模式；其对应的参数设置分别为mixed_type：realtime（实时）、delay（延时）。其中，混合模式超时的时间设置参数为mixed_timeout，单位为ms。








