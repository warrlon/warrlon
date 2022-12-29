# 语音评测

提供汉语、英语两种语言的评测，支持单字（汉语专有）、词语和句子朗读三种题型，通过简单地接口调用就可以集成到您的应用中。语音评测的使用主要有以下三个步骤：

#### 创建对象和设置参数

    // 创建评测对象
    SpeechEvaluator mSpeechEvaluator = SpeechEvaluator.createEvaluator(
    IseDemoActivity.this, null);
    // 设置评测语种
    mSpeechEvaluator.setParameter(SpeechConstant.LANGUAGE, "en_us");
    // 设置评测题型
    mSpeechEvaluator.setParameter(SpeechConstant.ISE_CATEGORY, "read_word");
    // 设置试题编码类型
    mSpeechEvaluator.setParameter(SpeechConstant.TEXT_ENCODING, "utf-8");
    // 设置前、后端点超时
    mSpeechEvaluator.setParameter(SpeechConstant.VAD_BOS, vad_bos);
    mSpeechEvaluator.setParameter(SpeechConstant.VAD_EOS, vad_eos);
    // 设置录音超时，设置成-1则无超时限制
    mSpeechEvaluator.setParameter(SpeechConstant.KEY_SPEECH_TIMEOUT, "-1");
    // 设置结果等级，不同等级对应不同的详细程度
    mSpeechEvaluator.setParameter(SpeechConstant.RESULT_LEVEL, "complete");

可通过setParameter设置的评测相关参数说明如下：

<table>
<tr><th width="25%">参数名称</th><th width="20%">是否必填</th><th>说明</th></tr>
<tr><td>language</td><td>是</td><td>评测语种，可选值：en_us（英语）、zh_cn（汉语）</td></tr>
<tr><td>category</td><td>是</td><td>评测题型，可选值：read_syllable（单字，汉语专有）、read_word（词语）、read_sentence（句子）</td></tr>
<tr><td>text_encoding</td><td>是</td><td>上传的试题编码格式，可选值：gb2312、utf-8。当进行汉语评测时，必须设置成utf-8，建议所有试题都使用utf-8编码</td></tr>
<tr><td>vad_bos</td><td>否</td><td>前端点超时，默认5000ms</td></tr>
<tr><td>vad_eos</td><td>否</td><td>后端点超时，默认1800ms</td></tr>
<tr><td>speech_timeout</td><td>否</td><td>录音超时，当录音达到时限将自动触发vad停止录音，默认-1（无超时）</td></tr>
<tr><td>result_level</td><td>否</td><td>评测结果等级，可选值：plain（仅英文）、complete，默认为complete</td></tr>
</table>


#### 上传评测试题和录音

    // 首先创建一个评测监听接口
    private EvaluatorListener mEvaluatorListener = new EvaluatorListener() {
	    // 结果回调，评测过程中可能会多次调用该方法，isLast为true则为最后结果
	    public void onResult(EvaluatorResult result, boolean isLast) {}
	    // 出错回调
	    public void onError(SpeechError error) {}
	    // 开始说话回调
	    public void onBeginOfSpeech() {}
	    // 说话结束回调
	    public void onEndOfSpeech() {}
	    // 音量回调
	    public void onVolumeChanged(int volume, byte[] data) {}
	    // 扩展接口，暂时没有回调
	    public void onEvent(int eventType, int arg1, int arg2, Bundle obj) {}
    };

    // 然后设置评测试题、传入监听器，开始评测录音。evaText为试题内容，试题格式详见《语音
    // 评测参数、结果说明文档》，第二个参数为扩展参数，请设置为null
    mSpeechEvaluator.startEvaluating(evaText, null, mEvaluatorListener);


调用startListening即开始评测录音，读完试题内容后可以调用stopListening停止录音，也可以在一段时间后由SDK自动检测vad并停止录音。当评测出错时，SDK会回调onError方法抛出IFlySpeechError 
错误，通过IFlySpeechError的getErrorCode()方法可获得错误码，常见的错误码详见[附录错误码列表](/book/other-service/svs/appendix/errorcode.md)和下表：

<table>
<tr><th width="40%">错误码</th><th width="20%">错误值</th><th>说明</th></tr>
<tr><td>MSP_ERROR_ASE_EXCEP_SILENCE</td><td>11401</td><td>无语音或音量太小</td></tr>
<tr><td>MSP_ERROR_ASE_EXCEP_SNRATIO</td><td>11402</td><td>信噪比低或有效语音过短</td></tr>
<tr><td>MSP_ERROR_ASE_EXCEP_PAPERDATA</td><td>11403</td><td>非试卷数据</td></tr>
<tr><td>MSP_ERROR_ASE_EXCEP_PAPERCONTENTS</td><td>11404</td><td>试卷内容有误</td></tr>
<tr><td>MSP_ERROR_ASE_EXCEP_NOTMONO</td><td>11405</td><td>录音格式有误</td></tr>
<tr><td>MSP_ERROR_ASE_EXCEP_OTHERS</td><td>11406</td><td>其他评测数据异常，包括错读、漏读、恶意录入、试卷内容等错误</td></tr>
<tr><td>MSP_ERROR_ASE_EXCEP_PAPERFMT</td><td>11407</td><td>试卷格式有误</td></tr>
<tr><td>MSP_ERROR_ASE_EXCEP_ULISTWORD</td><td>11408</td><td>存在未登录词，即引擎中没有该词语的信息</td></tr>
</table>
		
#### 解析评测结果

SDK通过onResult回调抛出xml格式的评测结果，结果格式及字段含义详见[《语音评测参数、结果说明文档》](https://www.xfyun.cn/doc/voiceservice/ise/ise_protocol.html)，具体的解析过程可参考demo工程com.iflytek.ise.result包中的源代码。
