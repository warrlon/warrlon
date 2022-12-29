# HTTP推送

在左侧边导航栏中选择【应用开发】，点击选择【HTTP推送】，该页面以列表形式展示数据推送内容，具体包括实例名称、消息加密方式、创建时间信息。

![http推送](/images\qinghua\device-management\http-push.png)

该页面支持以下功能：

- 支持用户基于【添加HTTP推送实例】内容进行相关操作
- 支持用户基于【配置消息推送规则】内容进行相关操作
- 支持用户对实例进行验证功能
- 支持用户查看实例详情功能
- 支持用户编辑实例内容功能
- 支持用户删除实例功能

### 添加HTTP推送实例

用户点击【添加HTTP推送实例】按钮，页面如下所示。用户通过填写实例名称、推送地址、Token、消息加密方式、AesKey完成实例添加，添加实例可在前端列表中显示。

![添加http推送](/images\qinghua\device-management\http-push-add.png)

### 验证

新添加的实例，验证状态为待验证，用户点击【验证】按钮，即可实现在线验证。当验证通过时，系统验证状态显示为验证成功，反之显示为验证失败。其中，验证失败的原因包括：  
（1）网络请求错误，应用服务器地址访问异常；  
（2）url参数验证失败，应用服务器返回验证响应数据格式错误或平台请求未通过应用服务器校验。

<div align=center><img src ="/images\qinghua\device-management\http-push-validation.png"/></div>

### 配置消息推送规则

用户进入【HTTP推送】页面，点击【配置消息推送规则】，可跳转至【规则引擎界面】，支持用户直接添加规则或可视化添加规则。

![配置规则](/images\qinghua\device-management\configure-push-rule.png)