# 语音评测

提供汉语、英语两种语言的评测，支持单字（汉语专有）、词语和句子朗读三种题型，通过简单地接口调用就可以集成到您的应用中。

语音评测的使用主要有三个步骤：
- 创建评测对象
- 上传试题和录音
- 解析评测结果

    //1.创建评测对象
    _iFlySpeechEvaluator = [IFlySpeechEvaluator sharedInstance];
    _iFlySpeechEvaluator.delegate = self;
    //2.设置训练参数
    // 清空参数
    [_iFlySpeechEvaluator setParameter:@"" forKey:[IFlySpeechConstant PARAMS]];
    // 设置评测采样率
    [self.iFlySpeechEvaluator setParameter:@"16000" forKey:[IFlySpeechConstant SAMPLE_RATE]];
    // 设置评测题目编码，如果是utf-8格式，请添加bom头，添加方式可参考demo。
    [self.iFlySpeechEvaluator setParameter:@"utf-8" forKey:[IFlySpeechConstant TEXT_ENCODING]];
    // 设置评测题目结果格式，目前仅支持xml
    [self.iFlySpeechEvaluator setParameter:@"xml" forKey:[IFlySpeechConstant ISE_RESULT_TYPE]];
    // 设置评测前端点超时
    [self.iFlySpeechEvaluator setParameter:self.iseParams.bos forKey:[IFlySpeechConstant VAD_BOS]];
    // 设置评测后端点超时
    [self.iFlySpeechEvaluator setParameter:self.iseParams.eos forKey:[IFlySpeechConstant VAD_EOS]]; 
    // 设置评测前端点设置评测题型
    [self.iFlySpeechEvaluator setParameter:self.iseParams.category forKey:[IFlySpeechConstant ISE_CATEGORY]];
    // 设置评测语言
    [self.iFlySpeechEvaluator setParameter:self.iseParams.language forKey:[IFlySpeechConstant LANGUAGE]];
    // 设置评测结果级别
    [self.iFlySpeechEvaluator setParameter:self.iseParams.rstLevel forKey:[IFlySpeechConstant ISE_RESULT_LEVEL]];
    // 设置评测超时
    [self.iFlySpeechEvaluator setParameter:self.iseParams.timeout forKey:[IFlySpeechConstant SPEECH_TIMEOUT]];

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

    //3.语音评测实现Delegate
    /*!
     *  音量和数据回调
     *
     *  @param volume 音量
     *  @param buffer 音频数据
     */
    - (void)onVolumeChanged:(int)volume buffer:(NSData *)buffer{
    }

    /*!
     *  开始录音回调
     *  当调用了`startListening`函数之后，如果没有发生错误则会回调此函数。如果发生错误则回调onError:函数
     */
    - (void)onBeginOfSpeech{
    }

    /*!
     *  停止录音回调
     *    当调用了`stopListening`函数或者引擎内部自动检测到断点，如果没有发生错误则回调此函数。
     *  如果发生错误则回调onError:函数
     */
    - (void)onEndOfSpeech{
    }

    /*!
     *  正在取消
     */
    - (void)onCancel{
    }

    /*!
     *  评测错误回调
     *  在进行语音评测过程中的任何时刻都有可能回调此函数，你可以根据errorCode进行相应的处理。
     *  当errorCode没有错误时，表示此次会话正常结束，否则，表示此次会话有错误发生。
     *  特别的当调用`cancel`函数时，引擎不会自动结束，需要等到回调此函数，才表示此次会话结束。
     *  在没有回调此函数之前如果重新调用了`startListenging`函数则会报错误。
     *
     *  @param errorCode 错误描述类
     */
    - (void)onError:(IFlySpeechError *)errorCode{
    }

    /*!
     *  评测结果回调
     *   在评测过程中可能会多次回调此函数，你最好不要在此回调函数中进行界面的更改等操作，只需要将回调的结果保存起来。
     *
     *  @param results -[out] 评测结果。
     *  @param isLast  -[out] 是否最后一条结果
     */
    - (void)onResults:(NSData *)results isLast:(BOOL)isLast{
    }

调用startListening即开始评测录音，读完试题内容后可以调用 stopListening停止录音，也可以在一段时间后由SDK自动检测vad并停止录音。当评测出错时，SDK会回调onError方法抛出IFlySpeechError 
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

SDK通过onResult回调抛出xml格式的评测结果，结果格式及字段含义详见[《语音评测参数、结果说明文档》]（https://www.xfyun.cn/doc/voiceservice/ise/ise_protocol.html） ，具体的解析过程可参考demo工程IFlyMscDemo中ISE 目录下Result目录中的源代码。

