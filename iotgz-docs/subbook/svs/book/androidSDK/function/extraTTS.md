# 外部TTS引擎

您如果使用第三方的TTS引擎，可以通过以下方法来将第三方TTS引擎注册到DDS中。
    
    // 注意：需要将DDSConfig.K_TTS_MODE设置为"external"，用来声明使用第三方TTS引擎，该接口才会生效。
    
    
    // 注册
    DDS.getInstance().getAgent().setTTSRequestListener(listener)
    
    // 播报结束通知
    DDS.getInstance().getAgent().notifyTTSEnd();
    
    private TTSRequestListener listener = new TTSRequestListener() {
        @Override
        public void onStart(String type, String content) {
            Log.d(TAG, "tts start," + type + ":" + content);
            int code = mExternelTts.startSpeaking(content, mTtsListener);
    
            if (code != ErrorCode.SUCCESS) {
                Log.d(TAG, "语音合成失败,错误码: " + code);
            }
        }
    
        @Override
        public void onStop() {
            Log.d(TAG, "tts stop");
            mExternelTts.stopSpeaking();
        }
    };
