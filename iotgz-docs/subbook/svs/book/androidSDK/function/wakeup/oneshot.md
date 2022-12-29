# oneshot开关

如果您想动态更改唤醒模式，可以在需要的时候调用下面的接口。

    //开启oneshot
    DDS.getInstance().getAgent().getWakeupEngine().enableOneShot();
    
    //关闭oneshot
    DDS.getInstance().getAgent().getWakeupEngine().disableOneShot();
