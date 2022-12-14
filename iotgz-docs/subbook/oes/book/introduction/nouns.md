# 名词解释

本章主要介绍边缘IoT管理中相关的产品名词。

| 名词         | 描述                                                         |
| ------------ | ------------------------------------------------------------ |
| 边缘节点     | 边缘节点是您自己的边缘计算设备，用于运行边缘应用，处理您的数据，并安全、便捷地和云端应用进行协同。 |
| 边缘终端产品 | 设备的集合，通常指一组具有相同功能的设备。边缘IoT管理为每个产品颁发全局唯一的MasterKey。每个产品下可以有多个设备。 |
| 边缘终端设备 | 归属于某个边缘终端产品下的具体设备。边缘IoT管理为设备颁发产品内唯一的标识符API-Key。设备可以小到传感器、控制器，大到智能摄像机或工控机床。边缘IoT管理支持以MQTT协议、modbus协议和OPC-UA协议等接入设备。 |
| 设备证书     | 设备证书指ProductId、MasterKey、DeviceId。ProductId：是边缘IoT管理为产品颁发的全局唯一标识；MasterKey：在注册设备时，自定义的或自动生成的设备名称，具备产品维度内的唯一性。该参数很重要，在设备认证以及通信中都会用到，因此需要您保管好；DeviceId：具备产品维度内的唯一性。该参数很重要，在设备认证以及通信中都会用到，因此需要您保管好。 |
| 属性         | 设备的功能模型，一般用于描述设备运行时的状态，如环境监测设备所读取的当前环境温度等。属性支持 GET 和 SET 请求方式。应用系统可发起对属性的读取和设置请求。 |
| 物模型       | 是对设备在云端的功能描述，包括设备信息和功能属性。边缘IoT管理通过定义一种物的描述语言来描述物模型，称之为 TSL（即 Thing Specification Language），采用JSON格式。 |
| 应用         | 应用是您需要在边缘节点上运行的功能模块，通过部署所需应用来构建您自己的边缘计算能力。 |
| 固件         | 固件是厂商用于维护、更新设备的安装包，边缘IoT管理支持厂商将固件分配给产品，并对产品对应的设备进行固件升级。 |
