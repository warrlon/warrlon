# 添加/删除指定的快速唤醒词

如果您想通过代码来控制快速唤醒，可以调用下面的接口。

QuickStart词为类似“导航去”、“我想听”等，此类唤醒词只在oneshot模式下生效，作用为在未唤醒状态下语音输入“导航去天安门”，可直接进入对话流程。

    //添加多条QuickStart词
    
    WakeupWord quickStartWord = new WakeupWord()
            .setPinyin("dao hang qu")
            .setWord("导航去")
            .setThreshold("0.15");
    List<WakeupWord> quickStartWordList = new ArrayList<>();
    quickStartWordList.add(quickStartWord);
    DDS.getInstance().getAgent().getWakeupEngine().addQuickStartWords(quickStartWordList);
    
    
    //实时移除一条QuickStart词
    WakeupWord quickStartWord = new WakeupWord().setWord("导航去");
    DDS.getInstance().getAgent().getWakeupEngine().removeQuickStartWord(quickStartWord);
    
    
    //实时移除多条QuickStart词
    WakeupWord quickStartWord = new WakeupWord().setWord("导航去");
    List<WakeupWord> quickStartWordList = new ArrayList<>();
    quickStartWordList.add(quickStartWord);
    DDS.getInstance().getAgent().getWakeupEngine().removeQuickStartWords(quickStartWordList);
    
    //更新多条QuickStart词的接口，覆盖原有的QuickStart词
    WakeupWord quickStartWord = new WakeupWord()
            .setPinyin("dao hang qu")
            .setWord("导航去")
            .setThreshold("0.15");
    List<WakeupWord> quickStartWordList = new ArrayList<>();
    quickStartWordList.add(quickStartWord);
    DDS.getInstance().getAgent().getWakeupEngine().updateQuickStartWords(quickStartWordList);
    
    //清空QuickStart词
    DDS.getInstance().getAgent().getWakeupEngine().clearQuickStartWords();
