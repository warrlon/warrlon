# 项目移除设备

<table>
<tr><td>方法</td><td colspan="4">POST</td></tr>
<tr><td>路径URI</td><td colspan="4">/application?action=RemoveDevice&version=1</td></tr>
<tr><td>请求头</td><td colspan="4">Content-Type : application/json</td></tr>

<tr><td>URL参数</td><td colspan="4">无</td></tr>

<tr><td rowspan="3">请求体参数</td><td>project_id</td><td>string</td><td>必填</td><td>项目id </td></td>
<tr><td>product_id</td><td>string</td><td>必填</td><td>产品ID</td></tr>
<tr><td>devices</td><td>array</td><td>必填</td><td>移除设备名称集合</td></tr>

<tr><td rowspan="8">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>调用成功时, 返回业务数据</td></tr>
<tr><td colspan="2">data.error_data</td><td>array</td><td>移除失败的错误信息集合，如下的e表示 error_data数组的单个对象标识</td></tr>
<tr><td colspan="2">e. device_name</td><td>string</td><td>移除失败设备名称</td></tr>
<tr><td colspan="2">e. cause</td><td>string</td><td>移除失败原因</td></tr>

<tr><td>请求示例</td><td colspan="4">
{<br>
    "project_id": "ocgzVU",<br>
    "product_id": "9MaNe52pNO", <br>
    "devices": ["no010"]<br>
}<br>
</td></tr>
<tr><td>响应示例</td><td colspan="4">
{<br>
    "data": {<br>
       "error_data":[
           {"name": "no010", "cause": "设备不存在"}<br>
        ],<br>
    }<br>
    "requestId": "a25087f46df04b69b29e90ef0acfd115",<br> 
    "success": true<br>
}<br>
</td></tr>
</table>