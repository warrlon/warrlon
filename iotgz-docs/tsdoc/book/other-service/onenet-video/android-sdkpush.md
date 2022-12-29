# Instructions for the use of Android SDK push end

#### 1. Introduction

The functions of pushing video streams from local devices to OneNET platform include device connection encryption, acquiring video streams, deleting video streams and uploading data. This project is implemented by OneNet Video SDK.

#### 2. Environmental preparation

Android Studio 3.1.2

Gradle 4.4

Platform API 17~27

NDK 16

CPU armv7,armv8,x86,x86_64

minSdkVersion 17

#### 3. Characteristics
Support ODVP device access protocol < br > support live stream, history stream and Onvif stream push < br > MP4 file recording (for reference only)

#### 4.SDK

** 4.1 Download Demo**

Address:[https://github.com/cm-heclouds/Android ODVPSDK](https://github.com/cm-heclouds/AndroidODVPSDK)

** 4.2Android Project consists of Demo (sample) and SDK (odvpsdk)**


** 4.3 SDK is composed of Android-SDK (video_sdk_wrapper) and C-SDK (video_sdk)**


#### 5. Demo example

** 5.1 Working Principle**

![pic1](/images/vedio-image/Android-SDK推流端使用说明01.png)


** 5.2 Compilation Options Configuration**

Build. gradle opens - D_ONVIF=1 option in SDK to open Onvif module compilation

```
externalNativeBuild {
    cmake {
        arguments '-D_ONVIF=1'
        abiFilters "armeabi-v7a","arm64-v8a","x86","x86_64"
    }
}
```
** 5.3 Equipment Access**

[https://github.com/cm-heclouds/AndroidODVPSDK/odvpsdk/library/src/main/java/com/ont/media/odvp/OntOdvp.java](https://github.com/cm-heclouds/AndroidODVPSDK/odvpsdk/library/src/main/java/com/ont/media/odvp/OntOdvp.java)

** 5.4 Data Push Interface (including Local Video Stream)**

https://github.com/cm-heclouds/AndroidODVPSDK/odvpsdk/library/src/main/java/com/ont/media/odvp/OntRtmp.[java](https://github.com/cm-heclouds/AndroidODVPSDK/odvpsdk/library/src/main/java/com/ont/media/odvp/OntRtmp.java)

** 5.5 onvif device push interface**

***5.5.1 Interface Introduction***

[https://github.com/cm-heclouds/AndroidODVPSDK/odvpsdk/library/src/main/java/com/ont/media/odvp/OntOnvif.java](https://github.com/cm-heclouds/AndroidODVPSDK/odvpsdk/library/src/main/java/com/ont/media/odvp/OntOnvif.java)

***5.5.2 Profile***

The format of the document is self-made and the contents should be as follows
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