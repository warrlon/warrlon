# TTS相关设置

### TTS事件回调

如果您想在TTS播报的相关时间节点收到通知，如：开始播报，播报结束。可以使用如下的方式：

    DDS.getInstance().getAgent().getTTSEngine().setListener(new TTSEngine.Callback() {
        /**
         * 开始合成时的回调
         * @param ttsId 当前TTS的id， 对话过程中的播报ttsid默认为0，通过speak接口调用的播报，ttsid由speak接口指定。
         */
        @Override
        public void beginning(String ttsId) {
            Log.d(TAG, "TTS开始播报");
        }
        /**
         * 合成的音频数据的回调，可能会返回多次，data长度为0表示音频结束
         * @param data 音频数据属性：单声道 16bit, pcm
         */
        @Override
        public void received(byte[] data) {
            Log.d(TAG, "收到音频，此方法会回调多次，直至data为0，音频结束");
        }
        /**
         * TTS播报完成的回调
         * @param status 播报结束的状态。
         *               正常播报结束为0
         *               播报中途被打断结束为1
         */
        @Override
        public void end(String ttsId, int status) {
            Log.d(TAG, "TTS播报结束");
        }
        /**
         * 合成过程中出现错误的回调
         * @param error 错误信息
         */
        @Override
        public void error(String error) {
            Log.d(TAG, "出现错误，"+error);
        }
    });

### TTS参数设置

如果您想通过SDK定制不同的合成音类型，可以在需要的时候调用下面的接口。

    /* 设置TTS播报类型的接口
     * 调用此接口则云端配置的合成音类型失效，此后的合成音类型都将由此接口来托管
     * @param speaker 取值如：zhilingf, gdgm等，若取为null，则表示随机改为一个不同的类型
     */
    DDS.getInstance().getAgent().getTTSEngine().setSpeaker("zhilingf");
    
    
    /**
     * 设置TTS播报类型的接口
     * 调用此接口则云端配置的合成音类型失效，此后的合成音类型都将由此接口来托管
     * @param speaker 取值如：zhilingf, gdgm等
     * @param path 取值如："sdcard/tts/zhilingf.bin"，自定义合成间类型的全路径
     */
    DDS.getInstance().getAgent().getTTSEngine().setSpeaker("zhilingf","sdcard/tts/zhilingf.bin");
    
    
    /**
     * 设置TTS播报语速的接口
     * 调用此接口则云端配置的合成音语速失效，此后的合成音语速都将由此接口来托管
     *
     * @param speed 语速，取值0.5-2.0，0.5语速最快，2.0语速最慢，对应控制台上合成音倍率值
     */
    DDS.getInstance().getAgent().getTTSEngine().setSpeed(1.0f);
    
    
    /**
     * 设置TTS播报音量的接口
     * 调用此接口则云端配置的合成音音量失效，此后的合成音音量都将由此接口来托管
     *
     * @param volume 音量大小，取值1-100
     */
    DDS.getInstance().getAgent().getTTSEngine().setVolume(50);
    
    
    /**
     * 设置TTS引擎为本地或者云端
     *
     * @param mode 取值 TTSEngine.LOCAL(本地合成)，TTSEngine.CLOUD(云端合成)
     */
    DDS.getInstance().getAgent().getTTSEngine().setMode(TTSEngine.LOCAL);
    
    
    /**
     * 设置TTS播报的通道
     * @param streamType AudioManager.STREAM_*的取值
     * @throws DDSNotInitCompleteException
     */
    DDS.getInstance().getAgent().getTTSEngine().setStreamType(int streamType);
    
    
    /**
     * 设置TTS播报的通道(安卓7.0版本以上支持,并且需要配置K_AUDIO_USAGE和    K_CONTENT_TYPE)
     * @param usage 取值: AudioAttributes.USAGE_*
     * @param contentType 取值: AudioAttributes.CONTENT_TYPE_*
     * @throws DDSNotInitCompleteException
     */
    DDS.getInstance().getAgent().getTTSEngine().setUsage(int usage, int contentType);
    
    
    /**
     * 设置TTS播报自定义录音
     * @param customAudioList 自定义播报音频列表
     * @throws DDSNotInitCompleteException
     */
    DDS.getInstance().getAgent().getTTSEngine().setCustomAudio(List<CustomAudioBean> customAudioList);
    
    
    /**
     * 设备抢焦点,默认为抢焦点
     * @param enable true/false  true: 抢焦点  false: 不抢焦点
     */
    DDS.getInstance().getAgent().getTTSEngine().enableFocus(boolean enable);
    
    /**
     * 设置TTS人设
     * @param style 风格，humor:幽默;calm:沉稳;common:普通;简短:short;
     */
    DDS.getInstance().getAgent().getTTSEngine().setStyle(String style);
    
    
    /**
     * 清除TTS人设
     */
    DDS.getInstance().getAgent().getTTSEngine().removeStyle();
    
    /**
     * 设置TTS结束后延迟时间,单位ms
     * @param afterTime
     * @throws DDSNotInitCompleteException
     */
    public void setPlayAfterTime(int afterTime);

### TTS参数获取

如果您想获取当前TTS配置的接口，可以调用如下接口：

    //返回String 当前使用的合成音类型,如："zhilingf",获取失败返回null
    DDS.getInstance().getAgent().getTTSEngine().getSpeaker();
    
    //返回float 当前合成音语速，返回值0.5-2.0，0.5语速最快，2.0语速最慢，获取失败返回 0
    DDS.getInstance().getAgent().getTTSEngine().getSpeed();
    
    //返回int 当前合成音音量,返回值1-100,获取失败返回 0
    DDS.getInstance().getAgent().getTTSEngine().getVolume();
    
    //返回List<CustomAudioBean> 当前自定义播报音频的列表
    DDS.getInstance().getAgent().getTTSEngine().getCustomAudio();
    
    //获取当前TTS人设
    DDS.getInstance().getAgent().getTTSEngine().getStyle();
