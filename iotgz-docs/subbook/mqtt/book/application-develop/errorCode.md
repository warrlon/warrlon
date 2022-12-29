# 错误码

## 通用错误码

<table>
<tr><th width="20%">错误码</th><th>错误码说明</th><th>错误描述</th></tr>
<tr><td>000000</td><td>onenet_common_success</td><td>请求成功</td></tr>
<tr><td>000001</td><td>onenet_common_unauthorized</td><td>缺少鉴权参数</td></tr>
<tr><td>000002</td><td>onenet_common_authFailed</td><td>鉴权失败</td></tr>
<tr><td>000003</td><td>onenet_common_apiRateLimit</td><td>用户调用频次达到上限</td></tr>
<tr><td>000004</td><td>onenet_common_notFound</td><td>服务中无此资源路径</td></tr>
<tr><td>000005</td><td>onenet_common_methodNotAllowed</td><td>HTTP方法不支持</td></tr>
<tr><td>000006</td><td>onenet_common_paramRequired</td><td>缺少必要参数</td></tr>
<tr><td>000007</td><td>onenet_common_invalidParam</td><td>无效的参数</td></tr>
<tr><td>000008</td><td>onenet_common_invalidJson</td><td>无效的json格式</td></tr>
<tr><td>000009</td><td>onenet_common_quotaUsedUp</td><td>调用次数用尽</td></tr>
<tr><td>000010</td><td>onenet_common_badRequest</td><td>客户端请求错误</td></tr>
<tr><td>000020</td><td>onenet_common_internalServerError</td><td>系统异常，请稍后重试</td></tr>
<tr><td>000021</td><td>onenet_common_serviceUnavailable</td><td>服务不可用</td></tr>
</table>

## 鉴权相关错误码
<table>
<tr><th width="20%">错误码</th><th>错误码说明</th><th>错误K描述</th></tr>
<tr><td>001000</td><td>onenet_auth_prodNotFound</td><td>产品未找到</td></tr>
<tr><td>001001</td><td>onenet_auth_devNotFound</td><td>设备未找到</td></tr>
<tr><td>001002</td><td>onenet_auth_devKeyFormatError</td><td>mqtts设备鉴权key格式有误</td></tr>
<tr><td>001010</td><td>onenet_auth_serviceUnavailable</td><td>鉴权服务暂不可用</td></tr>
<tr><td>001011</td><td>onenet_auth_serviceInternalError</td><td>鉴权服务内部错误</td></tr>
</table>

## 设备镜像相关错误码
<table>
<tr><th width="20%">错误码</th><th>错误码说明</th><th>错误描述</th></tr>
<tr><td>002001</td><td>onenet_image_illegalJson</td><td>非法json</td></tr>
<tr><td>002002</td><td>onenet_image_jsonOutOfBound</td><td>json体数据量超限</td></tr>
<tr><td>002003</td><td>onenet_image_jsonOutOfDepth</td><td>json体层次超限</td></tr>
<tr><td>002004</td><td>onenet_image_noStateKey</td><td>json中未包含key:state</td></tr>
<tr><td>002005</td><td>onenet_image_noDesiredOrReportedKey</td><td>json中未包含key:desired或repored</td></tr>
<tr><td>002010</td><td>onenet_image_serviceInternalError</td><td>设备镜像服务内部错误</td></tr>
<tr><td>002011</td><td>onenet_image_serviceUnavailable</td><td>设备镜像服务暂不可用</td></tr>
</table>

