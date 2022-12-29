# 调用说明

## 调用方式

语音通话API接口实现采用JSON + HTTP(HTTPS)的协议，您可以使用几乎任何客户端和任何编程语言与REST API进行交互，通过发送简单的HTTP POST请求就可以轻松接入使用。

## 请求格式

BASE URL：
https://voice.heclouds.com:8002

URL格式：
BASE URL/{接口名称} body参数详见各个接口的API说明 HTTP头部:Accept:application/json;charset=utf-8;Content-Type:application/json;charset=utf-8

## 应用参数

接口调用的appid和accessKey由OneNET平台在您开通服务时分配。

## 通知模板

语音通知需提前向OneNET平台投递通知模板，模板审核通过后方能使用。模板一旦审核通过，将无法修改模板内容，若有变动需另行申请新的模板。

## 编码说明

请求和返回数据均统一使用UTF-8编码，请确保您的文件编码及传入参数的格式。
