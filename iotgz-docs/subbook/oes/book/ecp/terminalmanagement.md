# 边缘终端管理

边缘终端是通过边缘节点接入平台的终端设备。边缘IoT管理原生支持MQTT、OPC-UA、Modbus协议的设备接入。

## 创建边缘终端设备

1.进入**边缘IoT管理**控制台，在左侧**设备管理**栏选择**边缘终端管理**，进入边缘终端管理页，如图：

![](/images\oes\ecp\边缘终端管理2.png)

2.和边缘节点一样，也是分产品，产品下面是设备，需要先建产品，然后在产品里面创建设备。点击**添加产品**，可以添加边缘终端产品，如图：

![](/images\oes\ecp\创建边缘终端产品.png)

![](/images\oes\ecp\完成终端设备创建.png)

​	**查看设备列表**：可以在边缘终端产品列表里面点击对应产品的**查看设备列表**来查看产品详情：

![](/images\oes\ecp\查看产品详情.png)

| 名称          | 说明                                   |
| ------------- | -------------------------------------- |
| 产品ID        | 终端设备登录时的身份信息之一           |
| MasterKey     | 终端设备登录时的鉴权信息               |
| 查看物模型TSL | 点击可以查看物模型TSL格式的描述        |
| 导入物模型    | 支持通过外部文件的方式导入产品的物模型 |
| 使用模板      | 通过选择已有的物模型模板来导入物模型   |
| 添加功能      | 对产品对物模型进行添加功能的操作       |
| 设备列表      | 可以查看此产品下的设备列表详情         |
| 群组管理      | 可以对此产品下的设备进行分组管理       |