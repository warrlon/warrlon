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


