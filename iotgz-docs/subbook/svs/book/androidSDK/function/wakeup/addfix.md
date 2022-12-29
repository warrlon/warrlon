# 添加/删除指定的打断唤醒词

如果您期望添加或者移除一些打断唤醒词而保留之前的打断唤醒词，可以在需要的时候调用下面的接口。

    //实时添加打断唤醒词-添加一条打断唤醒词(1.1.2.1版本及以上支持)
    WakeupWord fixWord = new WakeupWord()
            .setPinyin("da duan")
            .setWord("打断")
            .setThreshold("0.18");
    DDS.getInstance().getAgent().getWakeupEngine().addShortcutWakeupWord(fixWord);
    
    
    //实时添加打断唤醒词-添加多条打断唤醒词(1.1.2.1版本及以上支持)
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
    DDS.getInstance().getAgent().getWakeupEngine().addShortcutWakeupWords(fixList);
    
    
    //实时移除打断唤醒词-移除一条打断唤醒词(1.1.2.1版本及以上支持)
    WakeupWord fixWord = new WakeupWord().setWord("打断");
    
    DDS.getInstance().getAgent().getWakeupEngine().removeShortcutWakeupWord(fixWord);
    
    
    //实时移除打断唤醒词-移除多条打断唤醒词(1.1.2.1版本及以上支持)
    WakeupWord fixWord = new WakeupWord().setWord("打断");
    WakeupWord fixWord1 = new WakeupWord().setWord("打断吧");
    List<WakeupWord> fixList = new ArrayList<>();
    fixList.add(fixWord);
    fixList.add(fixWord1);
    DDS.getInstance().getAgent().getWakeupEngine().removeShortcutWakeupWords(fixList);
