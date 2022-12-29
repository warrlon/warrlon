# API列表

# 使用说明

API接口请求参数包括公共参数和自定义业务参数两部分。公共请求参数是调用每个API时都需要携带的请求参数, 包括服务命名空间、接口名称、版本信息。自定义业务参数由各接口定义，根据调用方法不同，需要将参数携带至请求路径或者请求体中。


#### **参数说明**

<table>
<tr style="background-color:#363636; color:#F0FFF0;"><td width="12%">序号</td><td>参数</td><td>类型</td><td>是否必选</td><td width="52%">描述</td></tr>
<tr><td>1</td><td>namespace</td><td>string</td><td>是</td><td>API接口类别, 目前支持两类:
application 应用开发类
common 设备管理类</td></tr>
<tr><td>2</td><td>action</td><td>string</td><td>是</td><td>API接口名称</td></tr>
<tr><td>3</td><td>version</td><td>string</td><td>是</td><td>API版本号, 目前所有API接口版本均为1</td></tr>
</table>

#### **公共响应说明**

**成功响应：**

````java
{
    "requestId": "8906582E6722409AA6C40E7863B733A5",
    "success": true,
    "data": {
        status: 1
    }
}
````

**失败响应：**

````java
{
    "requestId": "8906582E6722409AA6C40E7863B733A5",
    "code":  "iot.application.deviceNotFound",
    "msg": "device does not exist",
    "success": false
}
````

**参数说明**

<table>
<tr style="background-color:#363636; color:#F0FFF0;"><td width="15%">序号</td><td>参数</td><td>类型</td><td width="55%">描述</td></tr>
<tr><td>1</td><td>requestId</td><td>string</td><td>请求ID，调用API时由平台生成唯一请求标识</td></tr>
<tr><td>2</td><td>code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td>3</td><td>msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td>4</td><td>success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td>5</td><td>data</td><td>object</td><td>调用成功时，返回的业务数据（接口无业务数据返回，值为null）</td></tr>
</table>