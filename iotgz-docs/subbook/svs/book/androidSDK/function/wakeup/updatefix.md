# 更新打断唤醒词

如果您期望在唤醒的时候能同时打断语音播报，可以在需要的时候调用下面的接口。打断唤醒词暂不支持在DUI控制台设置。（说明：打断需要设备开启回声消除）

**参数说明**

1）words 打断唤醒词，为string数组，不为null。

2）pinyins 打断唤醒词的拼音，形如：ni hao xiao chi，为string数组，不为null。

3）thresholds 打断唤醒词的阈值，形如：0.120（取值范围：0-1）为string数组，不为null。

    //实时更新打断唤醒词-更新一条打断唤醒词(1.1.2.1版本及以上支持)
    WakeupWord fixWord = new WakeupWord()
            .setPinyin("da duan")
            .setWord("打断")
            .setThreshold("0.18");
    DDS.getInstance().getAgent().getWakeupEngine().updateShortcutWakeupWord(fixWord);
    
    
    //实时更新打断唤醒词-更新多条打断唤醒词(1.1.2.1版本及以上支持)
    WakeupWord fixWord = new WakeupWord()
            .setPinyin("da duan")
            .setWord("打断")
            .setThreshold("0.18");
    WakeupWord fixWord1 = new WakeupWord()
            .setPinyin("da duan ba")
            .setWord("打断吧")
            .setThreshold("0.16");
    List<WakeupWord> fixList = new ArrayList<>();
    fixList.add(fixWord);
    fixList.add(fixWord1);
    DDS.getInstance().getAgent().getWakeupEngine().updateShortcutWakeupWords(fixList);
    
    //清空当前设置的打断唤醒词
    DDS.getInstance().getAgent().getWakeupEngine().clearShortCutWakeupWord();
