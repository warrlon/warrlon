# 视频能力Video

#### 1.OneNET平台，能不能支持萤石摄像头，有没有配置的教程？

可以用网关转，或者移植sdk到硬件里，说明详见：[https://open.iot.10086.cn/doc/video/book/hardware/gateway.html](https://open.iot.10086.cn/doc/video/book/hardware/gateway.html)。

#### 2.视频开发板的IC是什么？

是GM8136S。

#### 3.OneNET用HTTP不可以传输视频么？

目前不支持。

#### 4.OneNET允许网络摄像头的接入吗？

可以使用我们的视频网关直接接入，也可以自己根据sdk开发接入。

#### 5.OneNET视频接入支持什么协议啊？

RTMP推流、RTMPE加密推流。

#### 6.OneNET视频平台支持G711格式的音频接入吗？

不支持，音频流转化为aac，G711先解码，再AAC编码。

#### 7.OneNET视频支持加密吗？如何开启加密视频？

支持的，具体可以参考官网视频服务版块。