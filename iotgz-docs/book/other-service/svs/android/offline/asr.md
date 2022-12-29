# 本地功能集成

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


### 混合模式

混合能力是MSC的功能亮点，能够在较差的网络环境下，选择最优的方式进行语音交互。使用混合模式时，只需将引擎设置为mixed。

混合模式包含两种，一种是实时模式，即同时向云端和本地发送音频，当云端返回结果超时时，返回本地结果；另一种是延时模式，先向云端发送音频，当云端返回结果超时后自动转为向本地发送音频的模式；其对应的参数设置分别为mixed_type：realtime（实时）、delay（延时）。其中，混合模式超时的时间设置参数为mixed_timeout，单位为ms。








