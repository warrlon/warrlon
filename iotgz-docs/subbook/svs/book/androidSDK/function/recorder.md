# 外部录音机拾音

您如果有自己的录音机，可以通过以下方法将录音数据传给DDS。

    // 注意：需要将DDSConfig.K_RECORDER_MODE设置为"external"，用来关闭DDS内置录音机，该接口才会生效
    // 音频长度：无限制。内置录音机是3200（单麦）
    // 调用间隔：无限制。内置录音机是100ms
    // 调用时机：无限制。DDS会根据对话状态将接受的音频送入识别或者丢弃。
    DDS.getInstance().getAgent().feedPcm(byte[] pcm);