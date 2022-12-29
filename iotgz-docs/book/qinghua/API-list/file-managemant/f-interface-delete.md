# 文件删除接口

<table>
<tr><th>方法</th><td colspan="4">POST</th></tr>
<tr><td>路径URI</td><td colspan="4">/application?action=DeleteDeviceFile&version=1</td></tr>
<tr><td>请求头</td><td colspan="4"></td></tr>
<tr><td>URL参数</td><td colspan="4">无</td></tr>

<tr><td rowspan="1">请求体参数</td><td>id</td><td>string</td><td>必填</td><td>文件id </td></tr>

<tr><td rowspan="5">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>调用成功时，返回的业务数据</td></tr>

<tr><th>请求示例</th><td colspan="4">
{<br>
  id：43bb54ac673f48c88300fa6e6d3c9481<br>
}<br>
</th></tr>
<tr><th>响应示例</th><td colspan="4">
{<br>
    "requestId": "a25087f46df04b69b29e90ef0acfd115", <br>
    "success": true<br>
}<br>
</th></tr>
</table>
