# 添加/删除指定的命令唤醒词（快捷唤醒词）

如果您期望添加或者移除一些命令唤醒词而保留之前的命令唤醒词（即控制台上的快捷唤醒词），可以调用下面的接口。

    // 实时添加命令唤醒词-添加一条命令唤醒词(1.1.2.1版本及以上支持)
    WakeupWord commandWord = new WakeupWord()
            .setPinyin("xia yi shou")
            .setWord("下一首")
            .setThreshold("0.18")
            .addGreeting("我在")
            .setAction("sys.next");
    DDS.getInstance().getAgent().getWakeupEngine().addCommandWakeupWord(commandWord);
    
    // 实时添加命令唤醒词-添加多条命令唤醒词(1.1.2.1版本及以上支持)
    WakeupWord commandWord = new WakeupWord()
            .setPinyin("xia yi shou")
            .setWord("下一首")
            .setThreshold("0.18")
            .addGreeting("我在")
            .setAction("sys.next");
    WakeupWord commandWord1 = new WakeupWord()
            .setPinyin("shang yi shou")
            .setWord("上一首")
            .addGreeting("我在")
            .setThreshold("0.20")
            .setAction("sys.play");
    List<WakeupWord> commandList = new ArrayList<>();
    commandList.add(commandWord);
    commandList.add(commandWord1);
    DDS.getInstance().getAgent().getWakeupEngine().addCommandWakeupWords(commandList);
    
    
    // 实时移除命令唤醒词-移除一条命令唤醒词(1.1.2.1版本及以上支持)
    WakeupWord commandWord = new WakeupWord().setWord("下一首");
    
    DDS.getInstance().getAgent().getWakeupEngine().removeCommandWakeupWord(commandWord);
    
    
    // 实时移除命令唤醒词-移除多条命令唤醒词(1.1.2.1版本及以上支持)
    WakeupWord commandWord = new WakeupWord().setWord("下一首");
    WakeupWord commandWord1 = new WakeupWord().setWord("上一首");
    List<WakeupWord> commandList = new ArrayList<>();
    commandList.add(commandWord);
    commandList.add(commandWord1);
    DDS.getInstance().getAgent().getWakeupEngine().removeCommandWakeupWords(commandList);
