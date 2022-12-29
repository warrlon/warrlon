# 更新副唤醒词

如果您期望为设备增加一个副唤醒词，可以在需要的时候调用下面的接口。

**参数说明**

1）word 副唤醒词，若设置null，则清空当前的副唤醒词。

2）pinyin 副唤醒词的拼音，形如：ni hao xiao chi。

3）threshold 副唤醒词的阈值，形如：0.120（取值范围：0-1）。若设置null，则自动估算。

4）greetings 副唤醒词的欢迎语，若设置null，则与主唤醒词保持一致。

    // 实时更新副唤醒词(1.1.2.1版本及以上支持)
    WakeupWord minorWord = new WakeupWord()
            .setPinyin("ni hao xiao chi")
            .setWord("你好小迟")
            .setThreshold("0.15")
            .addGreeting("我在");
    DDS.getInstance().getAgent().getWakeupEngine().updateMinorWakeupWord(minorWord);
    
    //获取当前的副唤醒词
    DDS.getInstance().getAgent().getWakeupEngine().getMinorWakeupWord();

