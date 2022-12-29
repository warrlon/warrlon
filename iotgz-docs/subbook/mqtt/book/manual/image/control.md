# 控制台操作

MQTT物联网套件开发者中心提供了设备镜像查看与编辑的页面工具

进入设备列表 -> 设备详情
![](/images/MQTTS/设备详情入口.png)

点击上方**设备镜像**标签页，页面展示如下：
![](/images/MQTTS/设备镜像初始页.png)

设备镜像 json文档初始状态为：
```json
{
    "deviceId": "536444692",
    "createTime": 1563929740,
    "connectionState": "online",
    "properties": {
        "state": {
            "reported": {},
            "desired": {}
        },
        "metadata": {
            "reported": {},
            "desired": {}
        },
        "version": 0,
        "timestamp": 0
    }
}
```

点击页面右上方编辑，进行镜像属性编辑与更新

![](/images/MQTTS/编辑镜像入口.png)

![](/images/MQTTS/编辑镜像.png)

点击**完成**，保存该编辑内容，可以看到镜像json已经发生了更新，如下图：

![](/images/MQTTS/完成镜像编辑.png)


## 更多帮助

- [了解设备镜像服务介绍](/book/manual/image/introduce.md)    
- [了解设备开发指南，见设备镜像topic簇的使用手册](/book/device-develop/topics/image-topics.md)
