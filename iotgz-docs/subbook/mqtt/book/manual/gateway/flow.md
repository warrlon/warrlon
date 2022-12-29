# 使用流程

用户设备通过自定义私有协议将设备与gateway服务连接，当设备需要登录或上传数据至OneNET平台时，gateway服务使用用户提供的Custom Protocol Decoder将该设备数据经过转换为内部数据格式，之后转换为标准MQTT协议数据，然后与平台进行交互。

当用户通过OneNET平台下发数据给指定设备时，gateway接收到下行数据后，将MQTT数据转换为内部数据格式，之后使用用户提供的Custom Protocol Encoder将内部数据转换为用户设备能识别的数，然后发送给设备。

## 登录

![](/images/MQTTS/gateway/gw2.png)

## 上行数据

![](/images/MQTTS/gateway/gw3.png)


## 下行数据

![](/images/MQTTS/gateway/gw4.png)

