# HTTP推送

平台提供HTTP推送功能，可以主动将设备相关数据与消息以HTTP/HTTPS POST请求的方式，发送给应用服务器。

按照如下步骤启用HTTP推送服务：

**Step 1**

进入开发者中心，选择**数据推送**->**HTTP推送**，点击**添加全局推送**，如下图所示：

![推送入口](/images/数据推送/推送入口.png)


**Step 2**

填写用于接收数据的服务器URL地址与自定义token（token可用于验证请求是否来自OneNET），通过指定数据流，选择需要推送新增数据点的数据流，点击**关联**，如下图所示：

![推送配置](/images/数据推送/推送配置页面.png)

**Step 3**

在弹出菜单栏中，选择需要推送数据的数据流，选择之后，推送服务将推送已选择数据流中的新增数据点，如下图所示：

![关联数据流模板](/images/数据推送/关联数据流模板.png)

**Step 4**

根据需要配置推送时机间隔与数量累计，如下图所示：

- 配置推送时间间隔后，将会按照时间间隔定期推送数据
- 配置数量累计后，将会消息数累计到一定数量再推送数据

![时间间隔](/images/数据推送/时间间隔与消息累计.png)


**Step 5**

请按照应用[开发指南](/book/application-develop/httppush/develop-manual.md)部署应用服务器接收服务，点击**添加**，成功后可以看到该服务处于**已启用**状态，如下图所示：

![配置成功](/images/数据推送/配置成功.png)

