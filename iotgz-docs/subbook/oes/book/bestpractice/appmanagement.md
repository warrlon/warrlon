## 应用管理最佳实践

应用管理支持下发两类容器应用到边缘节点，一是从边缘市场中的获取边缘应用。另外一个是自定义边缘应用。本节主要介绍如何创建使用自定义边缘应用。

### 上传并使用自定义容器应用。

以模拟一个MQTT协议设备的应用为例子，定时上报数据到边缘平台，并在边缘平台查看数据。

1. 登录**边缘IoT管理**控制台。

2. 选择容器镜像，我的镜像，客户端上传镜像。按提示操作进行操作，把本地制作的镜像上传到边缘计算套件的镜像仓库。

   ![添加镜像](/images\oes\bestpractice\APPManagement\添加镜像.png)

   ![镜像列表](/images\oes\bestpractice\APPManagement\镜像列表.png)

3. 选择应用管理，应用模版，创建应用模版。进入应用模版的创建页面。填写模版基本信息，选择容器镜像中已经上传的镜像。

   ![添加应用模版](/images\oes\bestpractice\APPManagement\添加应用模版.png)

   然后根据上传的镜像实际情况，进行模版配置。

   ![模版配置](/images\oes\bestpractice\APPManagement\模版配置.png)

   ![应用模版添加成功](/images\oes\bestpractice\APPManagement\应用模版添加成功.png)

4. 在模版创建成功后，选择应用管理，容器应用，创建容器应用，选择应用模板。

   ![选择应用模版](/images\oes\bestpractice\APPManagement\选择应用模版.png)

   填写基本信息，并选择要关联的边缘节点（需要边缘节点处于在线状态），以及填写唯一的容器的名称。因为选择模版后，已经继承了模版的相关信息，所以在关联模版内容中，只是根据具体环境进行相关数据调整（本例中不需要调整）。

   ![应用基本信息](/images\oes\bestpractice\APPManagement\应用基本信息.png)

   点击部署，部署成功，返回容器应用列表。

   ![容器应用列表](/images\oes\bestpractice\APPManagement\容器应用列表.png)

5. 在设备管理，边缘终端管理中，查看设备列表，选择设备列表标签页，找到通过容器应用模拟的MQTT客户端。

   ![设备列表](/images\oes\bestpractice\APPManagement\设备列表.png)

   点击详情，点击操作中写入数据，让模拟的终端设备定时上报数据。

   ![写入数据](/images\oes\bestpractice\APPManagement\写入数据.png)
