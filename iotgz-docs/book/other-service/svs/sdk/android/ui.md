# 语音输入UI


为了便于快速开发，SDK提供了一套默认的语音输入UI。如需使用，请务必先将SDK资源包assets路径下的资源文件拷贝至Android工程asstes目录下，如下图添加动画资源所示：

![pci](/images/svs/an-1.png)

语音输入UI控件RecognizerDialog可以用于语音听写、语法识别和语义理解，使用方法大致如下：

    //1.创建RecognizerDialog对象
    RecognizerDialog	mDialog = new RecognizerDialog(this, mInitListener);

    //2.设置accent、language等参数
    mDialog.setParameter(SpeechConstant.LANGUAGE, "zh_cn");
    mDialog.setParameter(SpeechConstant.ACCENT, "mandarin");
    //若要将UI控件用于语义理解，必须添加以下参数设置，设置之后onResult回调返回将是语义理解结果
    // mDialog.setParameter("asr_sch", "1");
    // mDialog.setParameter("nlp_version", "2.0");

    //3.设置回调接口
    mDialog.setListener(mRecognizerDialogListener);

    //4.显示dialog，接收语音输入
    mDialog.show();
