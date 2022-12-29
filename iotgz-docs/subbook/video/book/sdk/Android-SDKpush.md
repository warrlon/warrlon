# Android SDK推流端使用说明

#### 1.简介

实现本地设备向OneNET视频平台推视频流的功能，包括设备连接加密，获取视频流通道，删除视频流通道和上传数据的功能。

#### 2.环境准备

Android Studio 3.1.2

Gradle 4.4

Platform API 17~27

NDK 16

CPU armv7,armv8,x86,x86_64

minSdkVersion 17

#### 3.特性
支持ODVP设备接入协议<br>支持直播流、历史流和Onvif流的推送<br>MP4文件录制（仅供参考）

#### 4.SDK

**4.1下载Demo**

地址：[https://github.com/cm-heclouds/AndroidODVPSDK](https://github.com/cm-heclouds/AndroidODVPSDK)

**4.2Android工程由Demo(sample)和SDK(odvpsdk)组成**


**4.3SDK由Android-SDK(video_sdk_wrapper)和C-SDK(video_sdk)组成**


#### 5.Demo示例

**5.1工作原理**

![pic1](/images/vedio-image/Android-SDK推流端使用说明01.png)


**5.2编译选项配置**

SDK中build.gradle开启-D_ONVIF=1选项打开Onvif模块编译

```
externalNativeBuild {
    cmake {
        arguments '-D_ONVIF=1'
        abiFilters "armeabi-v7a","arm64-v8a","x86","x86_64"
    }
}
```
**5.3设备接入**

[https://github.com/cm-heclouds/AndroidODVPSDK/odvpsdk/library/src/main/java/com/ont/media/odvp/OntOdvp.java](https://github.com/cm-heclouds/AndroidODVPSDK/odvpsdk/library/src/main/java/com/ont/media/odvp/OntOdvp.java)

**5.4数据推流接口(含本地视频流)**

https://github.com/cm-heclouds/AndroidODVPSDK/odvpsdk/library/src/main/java/com/ont/media/odvp/OntRtmp.[java](https://github.com/cm-heclouds/AndroidODVPSDK/odvpsdk/library/src/main/java/com/ont/media/odvp/OntRtmp.java)

**5.5onvif设备推流接口**

***5.5.1 接口介绍***

[https://github.com/cm-heclouds/AndroidODVPSDK/odvpsdk/library/src/main/java/com/ont/media/odvp/OntOnvif.java](https://github.com/cm-heclouds/AndroidODVPSDK/odvpsdk/library/src/main/java/com/ont/media/odvp/OntOnvif.java)

***5.5.2 配置文件***

文件格式自拟，内容须包含如下
```
{
    "onvif":[
        {
            "title":"xx",
            "channel_id":1,   
            "url": "xxxxxxxxxxxxxxxx",       // onvif摄像头访问地址
            "user": "xxxx",                // 摄像头用户名 
            "passwd": "xxxxx",             // 摄像头密码
            "desc":"xxxx",                
            "defaultlevel": 1
        }
    ]
}
```
