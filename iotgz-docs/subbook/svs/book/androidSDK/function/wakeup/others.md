# 唤醒相关设置

### 设置环麦增强角度

如果您想动态指定环麦增强角度，可以在需要的时候调用下面的接口。

    DDS.getInstance().getAgent().getWakeupEngine().setWakeupDoa(int doa);


### 设置车载双麦模式

如果您想动态指定车载双麦的驾驶模式，可以在需要的时候调用下面的接口。

    // 0：全模式， 1：主驾模式
    
    DDS.getInstance().getAgent().getWakeupEngine().setWakeupMode(int mode);

### 获取当前唤醒内核的版本号

如果您想获取当前唤醒内核的版本号，可以在需要的时候调用下面的接口。

    DDS.getInstance().getAgent().getWakeupEngine().getWakeupVersion();

### 设置是否允许识别过程中响应唤醒

如果您想设置是否允许识别过程中响应唤醒，可以在需要的时候调用下面的接口。

    //enable: true. 允许识别过程中响应唤醒, false. 不允许识别过程中响应唤醒
    DDS.getInstance().getAgent().getWakeupEngine().enableWakeupWhenAsr(boolean enable);

### 设置自定义欢迎语回调

如果您想设置自定义欢迎语,可以在需要的时候调用下面的接口。

    DDS.getInstance().getAgent().getWakeupEngine().setWakeupCallback(WakeupCallback wakeupCallback);

###  获取主唤醒词列表

获取主唤醒词列表，默认返回WakeupEngine所设置的主唤醒词，如果没有设置过则返回产品配置的主唤醒词。

    DDS.getInstance().getAgent().getWakeupEngine().getMainWakeupWords();

### 设置Beamforming监听器

设置Beamforming监听器, 实时回调Beamforming音频

    DDS.getInstance().getAgent().getWakeupEngine().setBfListener(BfListener listener);

### 设置唤醒模块的模式

设置唤醒模块的模式(信号处理模块不变,环麦中暂不支持)

    DDS.getInstance().getAgent().getWakeupEngine().setWakeupSwitch(boolean mode);

### 就近唤醒

如果你有使用就近唤醒的需求, 可以参照下面的配置与设置(目前支持线性双麦的就近唤醒)

    1. 设置major参数为true
    config.addConfig("MAJOR", "true");
    2. 设置K_USE_NEAR_WAKEUP为true, 表示使用就近唤醒
    config.addConfig(DDSConfig.K_USE_NEAR_WAKEUP, "true");
    3. 在设置唤醒词的时候设置major字段
    WakeupWord minorWord = new WakeupWord()
            .setPinyin("ni hao xiao chi")
            .setWord("你好小驰")
            .setThreshold("0.25")
            .setMajor("1")
            .addGreeting("小驰回来了");
    DDS.getInstance().getAgent().getWakeupEngine().addMainWakeupWord(minorWord);
