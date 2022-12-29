# Device Access SDK

** 1, SDK Download Address**

[https://github.com/cm-heclouds/video_sdk](https://github.com/cm-heclouds/video_sdk)

** II, SDK Note**

Header file path:

```C
#inlcude/device.h
#inlcude/platform_cmd.h
#inlcude/rtmp_if.h
#inlcude/rvod.h
```

Compiler tool: cmake

** III, Interface List**

1. Device-related interfaces

| Interface Name | Description | Note|
|:---|:---|:---|
| ont_device_create | Create an OneNET access device | Refer to device.h|
| ont_device_get_acc| Get the address of the access machine and the token of the access machine | Reference device.h|
| ont_device_connect | Device Connection Authentication Interface | Reference device.h|
| ont_device_verify | Verify the token | reference device.h obtained from the access machine|
| ont_device_request_rsa_publickey | RSA public key of the request platform < br > and the platform will issue the request device public key | Reference device.h|
| ont_device_replay_rsa_publickey | Device sends encrypted public key to OneNET | Reference device.h|
| ont_device_register | device registration | refer to device.h|
| ont_device_auth | device authentication, the device can be registered only once, and then use authentication code authentication in subsequent connections, thereby improving efficiency | Reference device.h|
| ont_device_data_upload | device data upload | reference device.h|
| ont_device_get_channels | Get the channel under the device | Refer to device.h|
| ont_device_del_channel | Delete the channel under the device | Refer to device.h|
| ont_device_add_channel | Add channel | Refer to device.h|
| ont_device_keepalive | device lifesaving interface | refer to device.h|
| ont_device_check_receive | Check whether there is data from the platform that needs to be processed | Refer to device.h|
| ont_device_reply_ont_cmd | Device sends command response result to OneNET | Refer to device.h|
| ont_device_reply_user_defined_cmd | Device sends command response result to OneNET | Reference device.h|
| ont_device_deal_api_defined_msg | Device Processing API send custom messages | Refer to device.h|
| ont_device_deal_plat_resp_push_stream_msg | device push-flow request answered by device processing platform | refer to device.h|
| ont_device_set_platformcmd_handle | Set up the platform command processing function | Refer to device.h|
| ont_device_get_systime | Synchronization platform system time to device | Reference device.h|
| ont_device_keep_connect | Device and OneNET Connection Hold | Reference Device.|
| ont_device_disconnect | disconnect interface | refer to device.h|
| ont_device_destroy | Destroy instance interface | Refer to device.h|
| ont_device_req_push_stream | Device requests push-flow and callbacks to process platform response | Reference device.h|

2. Instruction Callback Interface (Platform Porting Interface)

| Interface Name | Description | Note|
|:---|:---|:---|
| t_ont_cmd_live_stream_ctrl | Live stream level switching | Reference platform_cmd.h|
| t_ont_cmd_dev_ptz_ctrl | platform control | reference platform_cmd.h|
| t_ont_cmd_dev_query_files | Device history stream file query | Reference platform_cmd.h|
| t_ont_keepalive_resp_callback | Heart-beat survival response | Reference device.h|
| t_ont_live_stream_start | Notify the start of live streaming | Refer to device.h|
| t_ont_vod_start_notify | Notify the playback start of the historical stream | Refer to device.h|
| t_user_defind_cmd | User-defined instruction | Refer to device.h|
| t_api_definition_msg | Processing API custom message | Reference device.h|
| t_plt_resp_dev_req_stream_msg | Processing platform reply to push flow request information | Refer to device.h|

3. RTMP real-time video correlation interface

| Interface Name | Description | Note|
|:---|:---|:---|
| rtmp_create_publishstream | Create RTMP push instance interface | Refer to rtmp_if.h|
| rtmp_stop_publishstream | Close the RTMP push instance interface | Refer to rtmp_if.h|
| rtmp_send_metadata | Send metadata interface | Refer to rtmp_if.h|
| rtmp_send_spspps | Send SPS data interface | Refer to rtmp_if.h|
| rtmp_send_videodata | Send Video Frame Interface | Refer to rtmp_if.h|
| rtmp_send_audiodata | Send Audio Frame Interface | Refer to rtmp_if.h|
| rtmp_check_rcv_handler | RTMP receiving and processing interface | refer to rtmp_if.h|
| rtmp_make_audio_headerTag | Create flvaudio headerflag interface | Refer to rtmp_if.h|
| rtmp_send_h264 data | Send H264 video frames | Refer to rtmp_if.h|

4. Local History Video Interface

| Interface Name | Description | Note|
|:---|:---|:---|
| rtmp_rvod_createctx | Create historical video instance interface | Refer to rvod.h|
| rtmp_rvod_destoryctx | Destroy Historical Video Instance Interface | Refer to rvod.h|
| rtmp_rvod_start | Start Historical Video Push Interface | Refer to rvod.h|
| rtmp_rvod_stop | End History Video Push Interface | Refer to rvod.h|
| rtmp_rvod_send_videof | File Send End Notification Interface | Refer to rvod.h|