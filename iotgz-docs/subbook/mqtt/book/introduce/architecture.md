# 产品架构

MQTT物联网套件产品架构如下图所示：

![平台架构](/images/MQTTS/MQTTS架构.png)

### 设备接入
提供高安全性、高稳定性的MQTT协议接入服务，保障设备连接可靠

### 设备管理
针对不同的使用场景，提供关于设备的包括生命周期管理、在线状态监测、在线调试、数据管理等功能在内的丰富的设备管理功能；支持设备同步命令、设备镜像等功能，便于用户可以自由实现设备通信与设备状态同步


### API
套件提供开放的、丰富的、基于HTTP/HTTPS的API接口，用户可以使用API进行设备管理，数据查询，设备命令交互等操作，在API的基础上，根据自己的个性化需求指定搭建上层应用

### 规则引擎
支持基于SQL的消息处理与分发能力，便于用户进行套件中消息的自定义处理与后续服务扩展


### 安全认证

提供用户资源访问安全认证机制，提供产品级以及设备级的不同粒度的密钥，并支持用户自定义密钥访问权限，最大限度保证用户设备以及应用层接入的安全性
