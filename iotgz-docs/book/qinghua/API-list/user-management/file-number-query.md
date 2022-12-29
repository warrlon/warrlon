# 用户设备文件数量查询

<table>
<tr><th>方法</th><td colspan="4">GET</th></tr>
<tr><td>路径URI</td><td colspan="4">/application?action=GetDeviceFileCount&version=1&device_name=ap-test-008&product_id=Bs1f6s5bhKP7rmfO</td></tr>
<tr><td>请求头</td><td colspan="4"></td></tr>

<tr><td rowspan="2">URL请求参数</td><td>product_id</td><td>string</td><td>必填</td><td>产品id </td></td>
<tr><td>device_name</td><td>string</td><td>必填</td><td>设备名称</td></tr>
<tr><td>请求体参数</td><td colspan="4">无</td></tr>

<tr><td rowspan="7">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>调用成功时，返回的业务数据</td></tr>
<tr><td colspan="2">data.upperLimit</td><td>number</td><td>设备允许的最大文件数量</td></tr>
<tr><td colspan="2">data.filesTotal</td><td>number</td><td>设备已存在的文件数量</td></tr>

<tr><th>请求示例</th><td colspan="4">GET /application?action=GetDeviceFileCount&version=1&device_name=ap-test-008&product_id=Bs1f6s5bhKP7rmfO </th></tr>
</th></tr>
<tr><th>响应示例</th><td colspan="4">
{<br>
    "data": { <br>
        "upperLimit": 1000,<br>
        "filesTotal": 1<br>
    } <br>
    "requestId": "a25087f46df04b69b29e90ef0acfd115",<br> 
    "success": true<br>
}<br>
</th></tr>
</table>