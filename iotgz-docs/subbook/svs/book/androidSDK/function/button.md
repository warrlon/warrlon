# 按键事件

如果您有相关的软硬件按键，您需要关注以下接口，将用户的行为反馈给SDK。

    // 点击唤醒/停止识别/打断播报 操作接口
    DDS.getInstance().getAgent().avatarClick();
    
    
    // 点击唤醒/停止识别/打断播报 操作接口 , 并附带一则欢迎语，当此次是唤醒时，播报这则欢迎语
    DDS.getInstance().getAgent().avatarClick("有什么可以帮你");
    
    // 按下按键接口(调用此接口需关闭VAD,VAD在创建产品时可配置)
    DDS.getInstance().getAgent().avatarPress();
    
    // 释放按键接口(调用此接口需关闭VAD，VAD在创建产品时可配置)
    DDS.getInstance().getAgent().avatarRelease();