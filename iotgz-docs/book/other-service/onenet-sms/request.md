# 调用说明

### 调用方式

短彩信能力平台API是使用HTTP并遵循REST原则设计的Web服务接口，您可以使用几乎任何客户端和任何编程语言与REST API进行交互。通过发送简单的HTTP GET/POST请求就可以轻松接入使用。

注：短彩信能力平台为确保您的账户和信息安全，建议注册后在账户设置页面添加您要使用的IP地址到IP白名单列表中。

### 统一请求格式

BASE URL：
http://api.sms.heclouds.com

URL格式：
/{接口名称}?{参数}
参数详见各个接口的API说明
HTTP头信息:
Accept:text/plain;charset=utf-8;
Content-Type:application/x-www-form-urlencoded;charset=utf-8;

### 编码

统一使用UTF-8编码，请确保您的文件编码及传入参数的格式。

