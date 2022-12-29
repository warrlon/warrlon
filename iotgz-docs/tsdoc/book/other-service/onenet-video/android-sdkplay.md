# Instructions for Android SDK Player

#### 1. Introduction

The SDK is used with the push end of OneNet platform device to realize video playback functions, including live streaming, historical streaming, local video viewing, voice push, screenshots, etc. This project is based on ijkplayer and dkplayer.

#### 2. Environment

Android Studio 3.1.2

Gradle 4.4

Platform API 21~27

NDK 16 

CPU armv5、armv7、arm64、X86、X86-64

#### 3. Characteristics


Support Live and On Demand

Support RTMP, RTMPE, HLS, HTTPS playback

Support RTMP, RMPE live voice push

Support for playback screenshots (excluding surfaceview hard-coded scenarios)

Optimizing RTMP First Screen Opening Time

Optimize the flow of variable frame rate soft decoding and dynamically adjust the number of decoding threads according to the frame rate

#### 4. Acquisition

Source address:[https://github.com/cm-heclouds/Android Player SDK](https://github.com/cm-heclouds/AndroidPlayerSDK)
Or add the following code to build. gradle
```
repositories {
    jcenter()
}
dependencies {
    implementation "com.ont.media:ontplayer-native:1.0.0"
implementation "com.ont.media:ontplayer-java:1.0.0"
implementation "com.ont.media:ontplayer-ui:1.0.0"
}
```

#### 5. DEMO example

** 5.1 Encryption Settings**

OneNET Video Services > Product Profile can set whether the video stream is encrypted or not, and after setting, it corresponds to different playback protocols.

** 5.2 Playback Function**

Home page input device ID, camera channel ID and API Key enter player interface.

![pic1](/images/vedio-image/Android-SDK播放端使用说明01.png)

***5.2.1 Video Live ****

In the upper left corner of the player interface, live and on-demand video playback can be switched. In the video live interface, the protocol type and definition can be selected, and the live address can be obtained (corresponding to the device at the push-stream terminal must be online) or the live address can be directly input for playback.

![pic1](/images/vedio-image/Android-SDK播放端使用说明02.png)

***5.2.2 VOD Playback***

Device Video - Get History Video on Push-Flow Device

Server Video - Get Video Recorded by Server

Local Video - Play Local Video Files

![pic1](/images/vedio-image/Android-SDK播放端使用说明03.png)

The use of each API in the function is described in "Introduction to the Http API Interface of OneNET Video Service".

** 5.3. Voice push**

Implementing the following interface in BaseVideoController*








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

***5.3.2. Call the following interface in IjkVideoView***

```
public int startPushAudio() 
public int stopPushAudio() 
```

** 5.4. Screenshot function**

Support TextureView screenshots, support SurfaceView soft decoding screenshots, generated pictures are saved locally.

***5.4.1. Call the following interface in IjkVideoView***

```
public void doScreenshot()
```

***5.4.2. Implement the following interface in BaseVideoController*


```
@Override
public void onScreenshotComplete(int ret, String path) {

// 截图完成
// ......
}
```

*** 5.4.3. The following options should be enabled for soft-decoding screenshots of Surface View ***


```
mMediaPlayer.setOption(IjkMediaPlayer.OPT_CATEGORY_PLAYER, "ffplaycodec-screenshot-path", "/sdcard/OntRoot");

mMediaPlayer.setOption(IjkMediaPlayer.OPT_CATEGORY_PLAYER, "ffplaycodec-screenshot", 1);
```

### 6.Licence

Copyright (c) 2018 cmiot

Licensed under LGPLv2.1 or later