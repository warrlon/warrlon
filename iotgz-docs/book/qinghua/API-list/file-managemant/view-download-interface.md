# 查看下载设备文件接口

<table>
<tr><th>方法</th><td colspan="4">GET</th></tr>
<tr><td>路径URI</td><td colspan="4">/application?action=GetDeviceFile&version=1&id=43bb54ac673f48c88300fa6e6d3c9481</td></tr>
<tr><td>请求头</td><td colspan="4"></td></tr>

<tr><td rowspan="1">URL参数</td><td>id</td><td>string</td><td>必填</td><td>文件id </td></tr>

<tr><td>请求体</td><td colspan="4">无</td></tr>

<tr><td rowspan="1">响应参数</td><td colspan="2">file</td><td>file</td><td>需要下载的文件</td></tr>
<tr><th>请求示例</th><td colspan="4">GET /application?action=GetDeviceFile&version=1&id=43bb54ac673f48c88300fa6e6d3c9481
</th></tr>
<tr><th>响应示例</th><td colspan="4">file
</th></tr>
</table>