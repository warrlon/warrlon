# API调用说明

OneNET Studio提供项目、设备、服务等云端API，帮助快速开发应用，满足场景业务需求。

#### 公共请求说明

API接口请求参数包括公共参数和自定义业务参数两部分。公共请求参数是调用每个API时都需要携带的请求参数, 包括服务命名空间、接口名称、版本信息。自定义业务参数由各接口定义，根据调用方法不同，需要将参数携带至请求路径或者请求体中。API接口公共参数调用如下所示:

```
    https(http)://openapi.heclouds.com/{namespace}?action=xxxx&version=1
```
##### 参数说明

<table>
<tr><th>序号</th><th width="20%">参数</th><th>类型</th><th>是否必选</th><th width="30%">描述</th></tr>
<tr><td>1</td><td>namespace</td><td>string</td><td>是</td><td>API接口类别, 包括:<br/> 应用开发类-application<br>设备管理类-common<br>LwM2M IPSO开发类-LwM2M-online、LwM2M-offline</td><tr>
<tr><td>2</td><td>action</td><td>string</td><td>是</td><td>API接口名称</td></tr>
<tr><td>3</td><td>version</td><td>string</td><td>是</td><td>API版本号, 目前所有API接口版本均为1</td></tr>
</table>

#### 公共响应说明

成功响应：
```
{
    "requestId": "8906582E6722409AA6C40E7863B733A5", 
    "success": true,
    "data": {
        status: 1
    }
}
```

失败响应：
```
{
    "requestId": "8906582E6722409AA6C40E7863B733A5",
    "code":  "iot.application.deviceNotFound",
    "msg": "device does not exist", 
    "success": false
}
```
##### 参数说明

|序号 | 参数 | 类型 | 描述 |
|:- | :- | :- | :- |
|1 | requestId | string |请求ID，调用API时由平台生成唯一请求标识|
|2 | code | string |调用失败时，返回的错误码 |
|3 | msg  | string | 调用失败时，返回的错误信息 |
|4 | success | boolean |接口是否调用成功 |
|5 | data | object | 调用成功时，返回的业务数据（接口无业务数据返回，值为null） |