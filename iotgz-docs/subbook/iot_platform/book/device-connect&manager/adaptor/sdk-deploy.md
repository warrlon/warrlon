# 泛协议SDK部署
本节将以OneNET应用托管云为例，讲解将泛协议SDK服务部署到OneNET应用托管云服务上的详细步骤。
## 创建服务实例
参考**服务实例管理**部分的内容创建好服务实例，服务实例是平台上对用户具体的SDK应用服务的映射。

## 泛协议SDK开发
参考**SDK开发指南**部分的内容开发泛协议SDK，并打包好应用。

## 创建资源
### 创建云服务器
  点击 设备接入与管理-泛协议接入 菜单，进入 泛协议接入控制台，点击页面上的「 部署泛协议SDK 」按钮，弹出对话框，如果用户已经有OneNET云服务器，则可以直接点击「前往服务器管理」进行查看；如果还没有创建OneNET云服务器，则点击「没有云服务器」，在切出的Tab页面中选择 设备接入数量 和 服务内存占用后，页面会显示云服务器推荐配置，点击「前往创建云服务器」，进入云服务器创建页面（若未登录则会先跳转至登录页面，进行OneNET登录授权后会再跳回创建页面），
页面提示信息填写相应的云服务器信息并同意服务条款后，点击创建，提交云服务器创建信息（若用户未创建过vpc则需要先根据提示创建vpc专网）。
  ![sdk部署](/subbook/iot_platform/book/device-connect&manager/images/sdk-deploy.png)<br>
  ![sdk部署弹出页](/subbook/iot_platform/book/device-connect&manager/images/sdk-deploy-pop-win.png)<br>
  ![去创建云服务器](/subbook/iot_platform/book/device-connect&manager/images/goto-new-cloud-server.png)<br>
  ![服务协议](/subbook/iot_platform/book/device-connect&manager/images/iaas-service-aggrement.png)<br>
  创建后回到云服务器列表，服务器资源初始化完成后会自动开机，如下图所示：<br>
  ![云服务器列表](/subbook/iot_platform/book/device-connect&manager/images/cloud-server-list.png)<br>
  >云服务器具体收费标准请参考云服务器创建页面右侧的已选信息。
### 创建并绑定安全组
  点击 云服务器-网络安全-安全组 菜单，进入 安全组控制台，点击「创建安全组」按钮，在弹出的页面填写 安全组名称、安全组描述、专有网络，并添加
22端口和应用服务端口（泛协议SDK中的服务配置文件protocolhub-tcp.conf的port配置项所配置的端口）规则，将泛协议接入SDK中配置的对外端口在安全组中配置为开放，如下图所示：
![安全组列表](/subbook/iot_platform/book/device-connect&manager/images/sec-group.png)<br>
![创建安全组](/subbook/iot_platform/book/device-connect&manager/images/new-sec-group.png)<br>

### 创建并绑定弹性公网IP
  点击 弹性公网IP 菜单，进入 弹性公网IP控制台，点击「创建弹性公网」按钮，在弹出的页面填写相应创建信息（请勾选绑定资源，资源类型选择云服务器选项，云服务器选择之前创建的云服务器选项）后，点击创建，提交创建信息。
  ![弹性公网IP](/subbook/iot_platform/book/device-connect&manager/images/eip.png)<br>
  ![创建弹性公网IP](/subbook/iot_platform/book/device-connect&manager/images/new-eip.png)<br>
  >弹性公网IP具体收费标准请参考弹性公网创建页面右侧的已选信息和峰值带宽项中的流量单价。

## ssh远程登录云服务器
使用上一卡云服务器绑定的公网IP、端口22及创建云服务器时填写的账号/密码（或密钥），通过ssh工具远程登录到云服务器，如下图所示：
![ssh服务器](/subbook/iot_platform/book/device-connect&manager/images/ssh-host-setting.png)<br>
![ssh用户名](/subbook/iot_platform/book/device-connect&manager/images/ssh-user&pwd.png)<br>
![登录云服务器](/subbook/iot_platform/book/device-connect&manager/images/ssh-terminal.png)<br>

## 安装配置SDK运行环境
下载jdk1.8 linux 64位安装包（如：jdk-8u251-linux-x64.tar.gz），并上传至云服务器，进行jdk1.8安装；安装完成后需配置JAVA环境变量。
![云服务器安装JDK](/subbook/iot_platform/book/device-connect&manager/images/ssh-jdk-install.png)<br>
![JDK信息](/subbook/iot_platform/book/device-connect&manager/images/ssh-jdk-info.png)<br>
## 上传并运行SDK应用包
将打包好的应用包上传至云服务器，修改运行权限，执行启动应用命令nohup java –jar xxx，查看./logs目录下日志确认应用服务已成功启动。
![运行SDK服务](/subbook/iot_platform/book/device-connect&manager/images/ssh-run-sdk.png)<br>
## 设备接入
设备通过服务器的公网IP+服务端口与SDK应用服务进行通信。