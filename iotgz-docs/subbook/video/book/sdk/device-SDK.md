# 设备接入SDK

**一，SDK下载地址**

[https://github.com/cm-heclouds/video_sdk](https://github.com/cm-heclouds/video_sdk)

**二，SDK说明**

头文件路径: 

```C
#inlcude/device.h
#inlcude/platform_cmd.h
#inlcude/rtmp_if.h
#inlcude/rvod.h
```

编译工具: cmake

**三，接口列表**

1.设备相关接口

|接口名称|说明|备注|
|:---|:---|:---|
|ont_device_create|创建OneNET接入设备|参考device.h|
|ont_device_get_acc|获取接入机地址和接入机token|参考device.h|
|ont_device_connect|设备连接鉴权接口|参考device.h|
|ont_device_verify|验证从接入机获取得到的token|参考device.h|
|ont_device_request_rsa_publickey|请求平台的RSA 公钥<br>同时平台会下发请求设备公钥|参考device.h|
|ont_device_replay_rsa_publickey|设备向OneNET发送加密公钥|参考device.h|
|ont_device_register|设备注册|参考device.h|
|ont_device_auth|设备鉴权，设备可以只注册一次，再以后的连接中使用鉴权码鉴权，从而提高效率|参考device.h|
|ont_device_data_upload|设备数据上传|参考device.h|
|ont_device_get_channels|获取设备下的通道|参考device.h|
|ont_device_del_channel|删除设备下的通道|参考device.h|
|ont_device_add_channel|增加通道|参考device.h|
|ont_device_keepalive|设备保活接口|参考device.h|
|ont_device_check_receive|检查是否有平台下发的数据需要处理|参考device.h|
|ont_device_reply_ont_cmd|设备向OneNET发送命令响应结果|参考device.h|
|ont_device_reply_user_defined_cmd|设备向OneNET发送命令响应结果|参考device.h|
|ont_device_deal_api_defined_msg|设备处理API下发的自定义消息|参考device.h|
|ont_device_deal_plat_resp_push_stream_msg|设备处理平台回复的设备推流请求|参考device.h|
|ont_device_set_platformcmd_handle|设置平台命令处理函数|参考device.h|
|ont_device_get_systime|同步平台的系统时间到设备|参考device.h|
|ont_device_keep_connect|设备与OneNET连接保持|参考device.|
|ont_device_disconnect|断开连接接口|参考device.h|
|ont_device_destroy|销毁实例接口|参考device.h|
|ont_device_req_push_stream|设备请求推流并调用回调函数处理平台回复|参考device.h|

2.指令回调接口(平台移植接口)

|接口名称|说明|备注|
|:---|:---|:---|
|t_ont_cmd_live_stream_ctrl|直播流级别切换|参考platform_cmd.h|
|t_ont_cmd_dev_ptz_ctrl|云台控制|参考platform_cmd.h|
|t_ont_cmd_dev_query_files|设备历史流文件查询|参考platform_cmd.h|
|t_ont_keepalive_resp_callback|心跳保活回复|参考device.h|
|t_ont_live_stream_start|通知直播流开始|参考device.h|
|t_ont_vod_start_notify|通知历史流回放开始|参考device.h|
|t_user_defind_cmd|用户自定义指令|参考device.h|
|t_api_defind_msg|处理API自定义消息|参考device.h|
|t_plt_resp_dev_req_stream_msg|处理平台回复推流请求的信息|参考device.h|

3.rtmp实时视频相关接口

|接口名称|说明|备注|
|:---|:---|:---|
|rtmp_create_publishstream|创建rtmp推流实例接口|参考rtmp_if.h|
|rtmp_stop_publishstream|关闭rtmp推流实例接口|参考rtmp_if.h|
|rtmp_send_metadata|发送metadata接口|参考rtmp_if.h|
|rtmp_send_spspps|发送sps数据接口|参考rtmp_if.h|
|rtmp_send_videodata|发送视频帧接口|参考rtmp_if.h|
|rtmp_send_audiodata|发送音频帧接口|参考rtmp_if.h|
|rtmp_check_rcv_handler|rtmp接收处理接口|参考rtmp_if.h|
|rtmp_make_audio_headerTag|创建flvaudio headerflag接口|参考rtmp_if.h|
|rtmp_send_h264data|发送H264视频帧|参考rtmp_if.h|

4.本地历史视频相关接口

|接口名称|说明|备注|
|:---|:---|:---|
|rtmp_rvod_createctx|创建历史视频实例接口|参考rvod.h|
|rtmp_rvod_destoryctx|销毁历史视频实例接口|参考rvod.h|
|rtmp_rvod_start|开始历史视频推流接口|参考rvod.h|
|rtmp_rvod_stop|结束历史视频推流接口|参考rvod.h|
|rtmp_rvod_send_videoeof|文件发送结束通知接口|参考rvod.h|

