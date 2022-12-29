# 容器镜像

## 介绍

边缘IoT管理支持下发容器应用到边缘节点，您可以下发如下两类容器应用。

- 边缘市场中的边缘应用。具体方法请参见**边缘市场**。
- 自定义边缘应用。本节主要介绍如何上传自己的容器镜像。

您可以从左侧**容器镜像**>**我的镜像**进入。

## 客户端上传镜像

点击右上角**客户端上传镜像**可按照步骤提示上传镜像：

![](/images\oes\ecp\ECP-容器镜像-我的镜像-客户端上传镜像.png)

```
Step 1. 以root用户登录Docker所在的虚拟机 
Step 2. 输入 docker login swr-cn.heclouds.com
根据提示输入：用户名和密码，完成Docker访问权限登录
用户名：XXXXXXXX
密码：XXXXXXXX
Step 3. 上传镜像
$ sudo docker tag [{镜像名称}:{版本名称}] swr-cn.heclouds.com//{镜像名称}:{版本名称}
$ sudo docker push swr-cn.heclouds.com//{镜像名称}:{版本名称}

*注意：单个用户支持上传2个镜像，镜像大小共不超过256.00MB
```

上传完成之后可在页面看到：
![](/images\oes\ecp\容器镜像-完成镜像上传.png)

