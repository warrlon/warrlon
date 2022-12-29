# 接入实例 - 设备镜像

本文将通过实例介绍如何通过**MQTT.fx**模拟设备与**设备镜像**进行交互

[MQTT客户端1.7.1下载](http://www.jensd.de/apps/mqttfx/1.7.1/)

## 准备条件
- 在上传数据点前，请完成产品与设备的创建，并进行设备连接，步骤参考[设备连接实例](/book/example/connect.md)
- 为了获取设备镜像触发的消息通知，设备需要订阅相关系统topic，本例中通过通配符订阅设备镜像相关的所有topic： *$sys/238322/mqtts-test-device/image/#*，如下图：

![](/images/MQTTS/订阅imagetopic.png)

## 上报设备属性

选择Publish项，输入发布 topic 
> 本例中，发布 topic 名称为：$sys/238322/mqtts-test-device/image/update

payload示例如下：

```json
{
    "state": {
        "reported": {
            "color": "red"
        }
    }
}
```

点击 **Publish**，上传数据点至平台，如下图：

![](/images/MQTTS/更新镜像.png)


完成后，可以通过 **Subscribe**可以接收到平台下发的更新通知，若通过.../accepted topic接收到消息，则表明平台处理消息成功，如下图：

![](/images/MQTTS/更新镜像通知.png)

更新后，可通过页面**刷新**按键，查询更新后的设备镜像json内容，如下图：

![](/images/MQTTS/更新镜像成功.png)

## 属性差异消息

> 当 desired 内容与 reported 内容存在差异时，平台会通过topic .../delta 下发该消息至设备

通过控制台页面编辑更新属性中 desired 属性为 "color": "**green**"，如下图：

![](/images/MQTTS/更新desired.png)

点击**完成**，保存镜像编辑内容，由于desired 与 reported 存在差异，属性中会自动生成delta属性，如下图：

![](/images/MQTTS/更新desired成功.png)

完成保存的同时，模拟设备端会接收到到一条来自topic *$sys/238322/mqtts-test-device/image/update/delta* 的消息，用于通知设备 **当前的报告状态与应用期望状态存在差异**，如下图所示：

![](/images/MQTTS/接收delta消息.png)

