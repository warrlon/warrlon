# Android SDK播放端使用说明

#### 1.简介

该SDK配合OneNet视频平台设备推流端使用，实现视频播放功能，包括直播流、历史流、本地视频的观看，语音推送，截图等。本项目基于ijkplayer，dkplayer实现。

#### 2.环境

Android Studio 3.1.2

Gradle 4.4

Platform API 21~27

NDK 16 

CPU armv5、armv7、arm64、X86、X86-64

#### 3.特性


支持直播和点播

支持RTMP，RTMPE，HLS，HTTPS播放

支持RTMP，RMPE直播的语音推送

支持播放截屏（surfaceview硬解码场景除外）

优化RTMP首屏打开时间

优化可变帧率软解码流程，根据帧率动态调整解码线程数

提供时间轴的回放功能

累计延迟追帧

#### 4.获取

源码地址：https://github.com/cm-heclouds/AndroidPlayerSDK，或者build.gradle中添加如下代码
```
repositories {
    jcenter()
maven {
        url 'https://dl.bintray.com/video-onenet/maven'
    }
}
dependencies {
    implementation "com.ont.media:ontplayer-native:1.0.1"
implementation "com.ont.media:ontplayer-java:1.0.1"
implementation "com.ont.media:ontplayer-ui:1.0.1"
}
```

#### 5.DEMO示例

**5.1 加密设置**

OneNET视频服务>产品概况处可以设置视频流是否加密接收，设置后对应不同的播放协议。

**5.2 播放功能**

首页输入设备ID，摄像头通道ID和APIKey进入播放器界面。

![pic1](/images/vedio-image/Android-SDK播放端使用说明01.png)

***5.2.1 视频直播***

播放器界面左上角可切换视频直播和点播回放。在视频直播界面可选择协议类型、清晰度，获取直播地址（对应推流端设备必须在线）播放，也可直接输入直播地址播放。

![pic1](/images/vedio-image/Android-SDK播放端使用说明02.png)

***5.2.2点播回放***

设备视频——获取推流端设备上的历史视频

服务器视频——获取服务器录制的视频

本地视频——播放本地视频文件

![pic1](/images/vedio-image/Android-SDK播放端使用说明03.png)

功能中的各API使用详见《OneNET视频服务Http API接口介绍》。

**5.3.语音推送**

***5.3.1.实现BaseVideoController中的如下接口***

```
@Override
public void onSupportPushAudio(boolean support) {

    if (support) {
        // 协议支持语音推送
// ......
// 如audioButton.setVisibility(VISIBLE);
    } else {
// 协议不支持语音推送
// ......
}
}

@Override
public void onEnablePushAudio(boolean enable) {

// 语音功能当前是否可用
// ......
    // 如audioButton.setEnabled(enable);
}



@Override
public void onStoppedPushAudio() {

// 语音功能已被动停止
// ......
    // 如audioButton.setText("录音");
}
```

***5.3.2.调用IjkVideoView中的如下接口***

```
public int startPushAudio() 
public int stopPushAudio() 
```

**5.4.截图功能**

支持TextureView截图，支持SurfaceView软解码截图，生成的图片保存至本地。

***5.4.1.调用IjkVideoView中的如下接口***

```
public void doScreenshot()
```

***5.4.2.实现BaseVideoController中的如下接口***

```
@Override
public void onScreenshotComplete(int ret, String path) {

// 截图完成
// ......
}
```

***5.4.3.SurfaceView软解码截图时需开启如下选项***

```
mMediaPlayer.setOption(IjkMediaPlayer.OPT_CATEGORY_PLAYER, "ffplaycodec-screenshot-path", "/sdcard/OntRoot");

mMediaPlayer.setOption(IjkMediaPlayer.OPT_CATEGORY_PLAYER, "ffplaycodec-screenshot", 1);
```

### 6.Licence

Copyright (c) 2018 cmiot

Licensed under LGPLv2.1 or later




