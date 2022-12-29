# Brief Introduction to Video Capability

Based on the OneNET cloud platform of China Mobile Internet of Things, the access capability of video devices in the Internet of Things industry is introduced, which provides users with core capabilities such as open access, remote device control, video push, video distribution, video storage, video playback, etc. The secondary development kit is also provided to facilitate users to customize and develop their own industry applications.

** Equipment Access**

Provide Video Capability Private Access Protocol (ODVP) for Device Access, Support Channel Encryption

** Equipment push **

Support RTMP push-flow, and support rtmpe encryption push-flow, provide c-sdk, android-sdk, and open source code, can be transplanted platform.

** Player **

Provide Android/Ios playback sdk, and support three common players jwplayer, vlc, video.js, IJK Player, etc.

** Cloud Distribution**

Support rtmp, HLS distribution, and support rtmpe, https-hls encryption distribution protocol

** Cloud Video Storage**

Real-time video can be stored in the cloud, so that it can be viewed at any time, and provide circular recording, timing recording, manual recording, etc.

** Local History Video**

Provide remote playback of local video

** Directive Control**

Provide general instruction control and customized instruction issuance



** Service Model**

![pic1](/images/vedio-image/视频能力配图_01.jpg)

** Resource Management Model**

![pic1](/images/vedio-image/视频能力配图_02.jpg)

** Access process**

![pic1](/images/vedio-image/视频能力配图_03.jpg)

** Working Principles of Real-Time Video**

![pic1](/images/vedio-image/视频能力配图_04.jpg)

Steps:

- Device Connection Authentication Access to Device Cloud.

- Players initiate playback requests, and cloud receives requests to send push-stream instructions to devices.

- The device receives the audio and video data of the corresponding video source channel after correctly parsing the instructions.

- The device side uses RTMP interface to push streaming to OneNET video cloud.

- The video cloud distributes the stream to the requesting player.

** Local History Video Access Principles**

![pic1](/images/vedio-image/视频能力配图_05.jpg)

Steps:

- Device Connection Authentication Access to Device Cloud.

- Players initiate playback requests, and cloud receives requests to send push-stream instructions to devices.

- The device receives instructions and parses them correctly, then finds the corresponding historical video in the request and reads the audio and video data.

- The device side uses RTMP interface to push audio and video data to OneNET video cloud.

- The video cloud distributes the stream to the requesting player.