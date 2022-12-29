# 分组设备添加

<table>
<tr><th>方法</th><td colspan="4">POST</th></tr>
<tr><td>路径URI</td><td colspan="4">/application?action=AddGroupDevice&version=1</td></tr>
<tr><td>请求头</td><td colspan="4">Content-Type : application/json</td></tr>
<tr><td>URL参数</td><td colspan="4">无</td></tr>

<tr><td rowspan="4">请求体参数</td><td>project_id</td><td>string</td><td>必填</td><td>项目id </td></td>
<tr><td>group_id</td><td>string</td><td>必填</td><td>分组ID</td></tr>
<tr><td>product_id</td><td>string</td><td>必填</td><td>产品ID</td></tr>
<tr><td>devices</td><td>array</td><td>必填</td><td>需要添加的设备集合</td></tr>

<tr><td rowspan="8">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>调用成功时, 返回的业务数据</td></tr>
<tr><td colspan="2">data.error_data</td><td>array</td><td>添加失败的错误信息集合，如下的e表示 error_data 数组的单个对象标识</td></tr>
<tr><td colspan="2">e. device_name</td><td>string</td><td>添加失败的设备集合</td></tr>
<tr><td colspan="2">e. cause</td><td>string</td><td>添加失败原因</td></tr>

<tr><th>请求示例</th><td colspan="4">
{<br>
    "project_id": "3C6Djy",<br>
    "group_id": "Z1Pdei",<br>
    "product_id": "XVlg5CCSSj",<br>
    "devices": ["dev1", "dev2"]<br>
}<br>
</th></tr>
<tr><th>响应示例</th><td colspan="4">
{<br>
    "data": <br>{
        "group_id": "qf6nAD",<br>
        "devices": ["dev1", "dev2"]<br>
    },<br>
    "requestId": "a25087f46df04b69b29e90ef0acfd115",<br> 
    "success": true<br>
}<br>
</th></tr>
</table>