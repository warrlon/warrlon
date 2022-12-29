# 更新命令唤醒词（快捷唤醒词）

如果您期望在唤醒的时候执行一条指令，可以在需要的时候调用下面的接口。命令唤醒词和DUI控制台所设置的快捷唤醒词是相同的功能，且互不影响，可同时存在，根据需求来选择设置方式。

**参数说明**

1）actions 命令唤醒词指令，为string数组，不为null。

2）words 命令唤醒词，为string数组，不为null。

3）pinyins 命令唤醒词的拼音，形如：ni hao xiao chi，为string数组, 不为null。

4）thresholds 命令唤醒词的阈值，形如：0.120（取值范围：0-1），为string数组，不为null。

5）greetings 命令唤醒词的欢迎语，为string二维数组，不为null，每维对应一个唤醒词的欢迎语。

    // 实时更新命令唤醒词-更新一条命令唤醒词(1.1.2.1版本及以上支持)
    WakeupWord commandWord = new WakeupWord()
            .setPinyin("xia yi shou")
            .setWord("下一首")
            .setThreshold("0.18")
            .addGreeting("我在")
            .setAction("sys.next");
    DDS.getInstance().getAgent().getWakeupEngine().updateCommandWakeupWord(commandWord);
    
    
    // 实时更新命令唤醒词-更新多条命令唤醒词(1.1.2.1版本及以上支持)
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
    DDS.getInstance().getAgent().getWakeupEngine().updateCommandWakeupWords(commandList);
    
    
    //清空当前设置的命令唤醒词
    DDS.getInstance().getAgent().getWakeupEngine().clearCommandWakeupWord();
