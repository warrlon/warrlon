# VAD相关设置

### 设置VAD后端停顿时间

如果您期望修改VAD后端检测的时间，可以在需要的时候调用下面的接口。

- 参数说明

millis 后端检测时间，单位毫秒，默认500毫秒。即若VAD在用户说话时停顿超过一定的时间，则认为用户已经说完，发出sys.vad.end消息，结束录音。

    //设置VAD后端停顿时间
    DDS.getInstance().getAgent().getASREngine().setVadPauseTime(1000);
    //获取VAD后端停顿时间
    DDS.getInstance().getAgent().getASREngine().getVadPauseTime();

### 设置VAD前端静音检测超时时间

如果您期望修改VAD前端静音检测超时时间，可以在需要的时候调用下面的接口。设置成功后，vad再次启动生效。

- 参数说明：

millis 前端静音检测超时时间，单位毫秒，默认8000毫秒。若VAD启动，一直未检测到用户说话，超过一定时间，发出sys.vad.timeout消息，结束录音。

    //设置VAD前端静音检测超时时间
    DDS.getInstance().getAgent().getASREngine().setVadTimeout(1000);
    
    //获取VAD前端静音检测超时时间
    DDS.getInstance().getAgent().getASREngine().getVadTimeout();

