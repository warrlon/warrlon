# 开关唤醒

默认SDK加载后不会启动语音唤醒，您可以通过以下接口对需对语音唤醒进行控制。

    // 开启语音唤醒
    DDS.getInstance().getAgent().getWakeupEngine().enableWakeup();
    
    // 关闭语音唤醒
    DDS.getInstance().getAgent().getWakeupEngine().disableWakeup();
    
    // 获取主唤醒词列表
    DDS.getInstance().getAgent().getWakeupEngine().getWakeupWords();
