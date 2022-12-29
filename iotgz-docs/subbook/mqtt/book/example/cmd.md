# 接入实例 - 同步命令

本文将通过 **MQTT.fx** 实例，介绍如何通过设备同步命令下发命令与获取设备应答

[MQTT客户端1.7.1下载](http://www.jensd.de/apps/mqttfx/1.7.1/)

## 准备条件
在上传数据点前，请完成产品与设备的创建，并进行设备连接，步骤参考[设备连接实例](/book/example/connect.md)


## 订阅设备命令topic

建立设备连接之后，获取设备命令前，必须先订阅系统命令topic：$sys/{pid}/{device-name}/cmd/request/{cmdid}

> topic中{cmdid}为变量，为每条命令的唯一id，可通过通配符的方式进行订阅，比如：$sys/{pid}/{device-name}/cmd/request/+，或者$sys/{pid}/{device-name}/cmd/#

![](/images/MQTTS/订阅命令topic.png)

## 控制台下发命令

通过**设备列表** -> **更多操作** -> **下发命令**，打开命令调试工具

![](/images/MQTTS/下发命令入口.png)

![](/images/MQTTS/下发命令工具.png)


配置下发命令内容与超时时间，点击 **发送** 

MQTT模拟工具会接收到一条topic消息，如下图所示
> 本例中的topic为：$sys/238322/mqtts-test-device/cmd/request/33ffea0a-e5f1-49d6-a626-ffee1bbd93ef


![](/images/MQTTS/接收命令.png)

使用MQTT.fx发布消息至对应topic，模拟设备应答（应答内容为*abcd*），如下图所示：
> 本例中，应答对应的topic为：
$sys/238322/mqtts-test-device/cmd/response/33ffea0a-e5f1-49d6-a626-ffee1bbd93ef

![](/images/MQTTS/命令应答.png)

使用MQTT.fx模拟设备应答后，会从系统topic接收消息表明，设备应答成功，如下图所示：
> 本例中，该topic为：
$sys/238322/mqtts-test-device/cmd/response/33ffea0a-e5f1-49d6-a626-ffee1bbd93ef/accepted

![](/images/MQTTS/命令应答确认.png)

使用MQTT.fx模拟设备应答后，页面的命令工具会显示命令的应答结果，如下图所示：
> 其中 cmd_resp": "YWJjZA==" 为设备应答消息 *abcd* 的base64编码形式
 
![](/images/MQTTS/页面工具反馈.png)
