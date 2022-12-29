# 视频平台使用介绍

**接入流程**

![pic1](/images/vedio-image/视频能力配图_03.jpg)

**一、创建产品**

在OneNET开发者中心创建RTMP产品

![pic1](/images\vedio-image\管理控制台01.png)

**二、添加/创建设备，以视频私有协议为例**

1.自动创建

可以使用sdk接口(```ont_device_connect```)通过产品注册码进行连接鉴权时自动创建设备.

![pic1](/images\vedio-image\管理控制台02.png)

2.手动创建

可以在管理页面创建设备

![pic1](/images\vedio-image\管理控制台03.png)


**三、添加/创建视频通道**

1.通过sdk-c来进行创建

具体参见sdk接口```ont_video_dev_add_channel```

2.手动创建

可以在管理页面进行通道创建

![pic1](/images\vedio-image\管理控制台04.png)


**四、设备接入**

使用sdk接口(```ont_device_connect```)进行设备接入,连接鉴权成功后，可以在页面看见设备在线

![pic1](/images\vedio-image\管理控制台05.png)


**五、实时视频播放**

![pic1](/images\vedio-image\管理控制台06.png)


**六、远程本地历史视频播放**

点击通道列表上的历史视频按钮

![pic1](/images\vedio-image\管理控制台07.png)


页面会远程查询并显示本地视频列表:

![pic1](/images\vedio-image\管理控制台08.png)


这里的列表是通过指令下发到设备，设备上报的列表.可以参考sdk回调接口(```t_ont_video_dev_query_files```)

**七、Apikey权限管理**

Apikey用于视频通道播放权限的分组管理

添加apikey

![pic1](/images\vedio-image\管理控制台09.png)


关联视频通道

![pic1](/images\vedio-image\管理控制台10.png)


取消关联

![pic1](/images\vedio-image\管理控制台11.png)


**八、实时查询**

实时推流查询

![pic1](/images\vedio-image\管理控制台12.png)


实时播放查询

![pic1](/images\vedio-image\管理控制台13.png)
