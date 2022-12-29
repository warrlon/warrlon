# API使用说明

### 公共请求说明

API接口请求参数包括公共参数和自定义业务参数两部分。公共请求参数是调用每个API时都需要携带的请求参数, 包括服务命名空间、接口名称、版本信息。自定义业务参数由各接口定义，根据调用方法不同，需要将参数携带至请求路径或者请求体中。API接口公共参数调用如下所示:

https(http)://openapi.heclouds.com/{namespace}?action=xxxx&version=2

### 参数说明

<table>
<tr><th width="10%">序号</th><th width="15%">参数</th><th width="10%">类型</th><th width="15%">是否必选</th><th>描述</th></tr>
<tr><td>1</td><td>namespace</td><td>string</td><td>是</td><td>vcs 语音通话</td></tr>
<tr><td>2</td><td>action</td><td>string</td><td>是</td><td>API接口名称</td></tr>
<tr><td>3</td><td>version</td><td>string</td><td>是</td><td>API版本号, 目前语音通话所有API接口版本均为2</td></tr>
</table>

### 公共响应说明

成功响应：

    {
        "requestId": "a25087f46df04b69b29e90ef0acfd115", 
        "success": true,
        "data": {
            "call_id": "150104227912386807"
        }
    }

失败响应：

    {
        "requestId": "a25087f46df04b69b29e90ef0acfd115",
        "code":  "iot.vcs.notApplyTestAccount",
        "msg": "request ip not equals test account ip", 
        "success": false
    }

### 参数说明

<table>
<tr><th width="10%">序号</th><th width="15%">参数</th><th width="15%">类型</th><th>描述</th></tr>
<tr><td>1</td><td>requestId</td><td>string</td><td>请求ID，调用API时由平台生成唯一请求标识</td></tr>
<tr><td>2</td><td>code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td>3</td><td>msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td>4</td><td>success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td>5</td><td>data</td><td>object</td><td>调用成功时，返回的业务数据（接口无业务数据返回，值为null）</td></tr>
</table>