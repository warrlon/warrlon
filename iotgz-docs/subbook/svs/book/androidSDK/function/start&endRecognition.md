# 开启/终止识别

如果您期望仅开启识别并获取识别结果，可以在需要的时候调用下面的接口。

    //获取识别引擎
    ASREngine asrEngine = DDS.getInstance().getAgent().getASREngine();
    //开启识别
    asrEngine.startListening(new ASREngine.Callback() {
        @Override
        public void beginningOfSpeech() {
            AILog.i(TAG, "检测到用户开始说话");
        }
    
        /**
         * @buffer  音频数据属性：单声道 16bit
         */
        @Override
        public void bufferReceived(byte[] buffer) {
            AILog.i(TAG, "用户说话的音频数据");
        }
    
        @Override
        public void endOfSpeech() {
            AILog.i(TAG, "检测到用户结束说话");
        }
    
        /**
         * @results. eof 为 0 代表识别过程中的结果， 为 1 代表识别结束的最终结果
         *    {"var":"今","sessionId":"0b48c0d086efc42d55bbf1068137655d","recordId":"6b3ccb1ee745d42fa6ddb74330b1c059","eof":0}
         *    {"var":"今天 天气","sessionId":"0b48c0d086efc42d55bbf1068137655d","recordId":"6b3ccb1ee745d42fa6ddb74330b1c059","eof":0}
         *    {"sessionId":"0b48c0d086efc42d55bbf1068137655d","pinyin":"jin tian tian qi","recordId":"6b3ccb1ee745d42fa6ddb74330b1c059","eof":1,"text":"今天 天气"}
         */
        @Override
        public void partialResults(String results) {
            AILog.i(TAG, "实时识别结果反馈");
        }
    
        /**
         * @results. {"sessionId":"0b48c0d086efc42d55bbf1068137655d","recordId":"6b3ccb1ee745d42fa6ddb74330b1c059","eof":1,"text":"今天天气","pinyin":"jin tian tian qi"}
         */
        @Override
        public void finalResults(String results) {
            AILog.i(TAG, "最终识别结果反馈");
        }
    
        @Override
        public void error(String error) {
            AILog.i(TAG, "识别过程中发生的错误");
        }
    
        @Override
        public void rmsChanged(float rmsdB) {
            AILog.i(TAG, "用户说话的音量分贝");
        }
    });
    
    //主动结束此次识别
    asrEngine.stopListening();
    
    //取消此次识别
    asrEngine.cancel();
