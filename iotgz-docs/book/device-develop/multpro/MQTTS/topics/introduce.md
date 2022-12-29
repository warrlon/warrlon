# Topic 簇

MQTTS物联网套件中设备相关服务（存储、命令等）的面向设备的接口，均以 topic 的形式提供，设备可以通过 publish 消息到系统 topic 调用服务接口，也可以订阅系统 topic 用于接收服务消息通知，服务提供的**系统 topic 的集合**形成了 topic 簇

MQTTS物联网套件目前包含：数据点topic簇、命令topic簇、子设备topic簇、设备影子topic簇，如下图所示：

![](/images/MQTTS/topics.jpg)


## 数据点topic簇

设备可以通过数据点 topic 簇上传数据存储并即时获取数据存储结果
- 簇中topic 以 $sys/{pid}/{device-name}/dp 开头
- 通过publish上传数据时，payload需要满足平台约定数据格式
- 支持一次上报多条数据，支持设备自带时间戳上报
- 即时通知数据处理结果（需订阅）


详情见[数据点topic簇](/book/device-develop/multpro/MQTTS/topics/dp-topics.md)

## 设备命令topic簇

设备可以通过设备命令 topic 簇获取应用即时命令，并上报执行结果
- 簇中topic 以 $sys/{pid}/{device-name}/cmd 开头
- 即时获取设备命令（需订阅）
- 平台通过 publish payload **透传**设备命令与设备应答
- 每条命令具有唯一的uuid，应用可根据其查询命令的创建与应答记录

详情见[设备命令topic簇](/book/device-develop/multpro/MQTTS/topics/cmd-topics.md)

（即将到来）

## 设备镜像topic簇

设备可以通过设备镜像 topic 簇与设备镜像服务交互，同步设备状态/配置信息
- 簇中topic 以 $sys/{pid}/{device-name}/image 开头
- 支持设备自定义状态/配置信息上传更新
- 即时获取设备状态更新消息（需订阅）
- 支持设备查询当前全量设备镜像信息


详情见[设备镜像topic簇](/book/device-develop/multpro/MQTTS/topics/image-topics.md)


## 子设备topic簇

（即将到来）