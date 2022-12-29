# 用户文件存储空间查询

<table>
<tr><th>方法</th><td colspan="4">GET</th></tr>
<tr><td>路径URI</td><td colspan="4">/application?action=GetDeviceFileSpace&version=1</td></tr>
<tr><td>请求头</td><td colspan="4"></td></tr>
<tr><td>URL请求参数</td><td colspan="4">无</td></tr>
<tr><td>请求体参数</td><td colspan="4">无</td></tr>

<tr><td rowspan="8">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>调用成功时，返回的业务数据</td></tr>
<tr><td colspan="2">data.useSize</td><td>number</td><td>用户已使用的空间</td></tr>
<tr><td colspan="2">data.hasSize</td><td>number</td><td>用户剩余空间</td></tr>
<tr><td colspan="2">data.totalSize</td><td>number</td><td>用户分配的总空间</td></tr>

<tr><th>请求示例</th><td colspan="4">GET /application?action=GetDeviceFileSpace&version=1</th></tr>
</th></tr>
<tr><th>响应示例</th><td colspan="4">
{<br>
    "data": { <br>
        "useSize": 138683,<br>
        "hasSize": 1073603141,<br>
        "totalSize": 1073741824<br>
    } <br>
    "requestId": "a25087f46df04b69b29e90ef0acfd115",<br> 
    "success": true<br>
}<br>
</th></tr>
</table>
