# 添加/删除指定的主唤醒词

如果您想通过代码来控制主唤醒词，可以调用下面的接口。

注意：通过此接口添加的主唤醒词会屏蔽控制台添加的主唤醒词。

    //实时添加主唤醒词-添加一条主唤醒词(1.1.2.1版本及以上支持)
    WakeupWord mainWord = new WakeupWord()
            .setPinyin("ni hao xiao chi")
            .setWord("你好小迟")
            .addGreeting("我在")
            .setThreshold("0.15");
    DDS.getInstance().getAgent().getWakeupEngine().addMainWakeupWord(mainWord);
    
    //实时添加主唤醒词-添加多条主唤醒词(1.1.2.1版本及以上支持)
    WakeupWord mainWord = new WakeupWord()
            .setPinyin("ni hao xiao chi")
            .setWord("你好小迟")
            .addGreeting("我在")
            .setThreshold("0.15");
    WakeupWord mainWord2 = new WakeupWord()
            .setPinyin("ni hao xiao le")
            .setWord("你好小乐")
            .addGreeting("我在")
            .setThreshold("0.15");
    List<WakeupWord> mainWordList = new ArrayList<>();
    mainWordList.add(mainWord);
    mainWordList.add(mainWord2);
    DDS.getInstance().getAgent().getWakeupEngine().addMainWakeupWords(mainWordList);
    
    //实时移除主唤醒词-移除一条主唤醒词(1.1.2.1版本及以上支持)
    WakeupWord mainWord = new WakeupWord().setWord("你好小迟");
    DDS.getInstance().getAgent().getWakeupEngine().removeMainWakeupWord(mainWord);
    
    //实时移除主唤醒词-移除多条主唤醒词(1.1.2.1版本及以上支持)
    WakeupWord mainWord = new WakeupWord().setWord("你好小迟");
    WakeupWord mainWord2 = new WakeupWord().setWord("你好小乐");
    List<WakeupWord> mainWordList = new ArrayList<>();
    mainWordList.add(mainWord);
    mainWordList.add(mainWord2);
    DDS.getInstance().getAgent().getWakeupEngine().removeMainWakeupWords(mainWordList);
    
    //更新多条主唤醒词的接口，覆盖原有的主唤醒词 
    WakeupWord mainWord = new WakeupWord() .setPinyin("ni hao xiao le") .setWord("你好小乐") .setThreshold("0.15") .addGreeting("我在");
    WakeupWord mainWord2 = new WakeupWord() .setPinyin("ni hao xiao chi") .setWord("你好小迟") .setThreshold("0.15") .addGreeting("我在");
    List<WakeupWord> mainWordList = new ArrayList<>();
    mainWordList.add(mainWord);
    mainWordList.add(mainWord2);
    DDS.getInstance().getAgent().getWakeupEngine().updateMainWakeupWords(mainWordList);
