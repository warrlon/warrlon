# 预备工作

### 创建iOS工程

在XCode中建立您的工程，或者打开已经建立的工程。

### 添加静态库

将开发工具包中lib目录下的iflyMSC.framework添加到新建工程中，如下图所示：

![pci](/images/svs/ios-1.png)

![pci](/images/svs/ios-2.png)

![pci](/images/svs/ios-3.png)

![pci](/images/svs/ios-4.png)

### 添加framework

按下图添加SDK所需要的iOS库

![pci](/images/svs/ios-5.png)

### 确认SDK的路径

![pci](/images/svs/ios-6.png)

请确认上图红色部分的路径能够找到iflyMSC.framework。为了支持多人开发，建议双击红色部分，把路径改为相对路径，例如像下图所示:

![pci](/images/svs/ios-7.png)

注意：请把不必要的路径删除。例如更新了SDK后，新的SDK与旧的SDK不在同一路径，请把旧的路径删除，避免引用到旧的库。对应集成SDK后发现编译失败，提示找不到头文件，请先检查这个路径是否正确。

### 导入头文件

在您需要使用MSC服务的文件中导入相应的头文件；例如：


    //带界面的语音识别控件
    #import “iflyMSC/IFlyRecognizerViewDelegate.h”
    #import “iflyMSC/IFlyRecognizerView.h”

    //不带界面的语音识别控件
    #import “iflyMSC/IFlySpeechRecognizerDelegate.h”
    #import “iflyMSC/IFlySpeechRecognizer.h”
    
    //不带界面的语音合成控件
    #import “iflyMSC/IFlySpeechSynthesizerDelegate.h”
    #import “iflyMSC/IFlySpeechSynthesizer.h”

 ### 集成帮助文档到Xcode

打开终端（termainl或iterm），cd到压缩包的doc目录，执行以下命令：

    cp -R -f -a com.iflytek.documentation.IFlyMSC.docset ~/Library/Developer/Shared/Documentation/DocSets/
然后执行命令：

    open ~/Library/Developer/Shared/Documentation/DocSets/

请核对文档的版本为最新下载的版本：

![pci](/images/svs/ios-8.png)

打开Xcode的帮助文档就可以看到已经集成的文档：

![pci](/images/svs/ios-9.png)

### 初始化

创建用户语音配置对象后才可以使用语音服务，建议在程序入口处调用：

    //初始化MSC
    [[OneNetSpeechUtility shareInstance] initializeWithOneNetAppId:APPID_VALUE logFile:LVL_ALL showLogcat:YES]