# **设备转移**  

<table style="text-align: left">

<tr><td >方法</td><td colspan="4">POST</td></tr>
<tr><td>路径URI</td><td colspan="4">/common?action=MoveProductDevice&version=1</td></tr>
<tr><td>请求头</td><td colspan="4">Content-Type : application/json</td></tr>

<tr><td>URL参数</td><td colspan="4">无</td></tr>

<tr><td rowspan="3">请求体参数</td><td>device_name</td><td>array</td><td>必填</td><td>被转移设备的名称数组，如["name_1", "name_2"]</td></tr>
<tr><td>product_id</td><td>string</td><td>必填</td><td>产品ID</td></tr>
<tr><td>target_user_tel</td><td>string</td><td>必填</td><td>接收人电话</td></tr>

<tr><td rowspan="5">响应参数</td><td>code</td><td>string</td><td colspan="2">调用失败时，返回的错误码</td></tr>
<tr><td>msg</td><td>string</td><td colspan="2">调用失败时，返回的错误信息</td></tr>
<tr><td>requestId</td><td>string</td><td colspan="2">调用API时生成的请求标识</td></tr>
<tr><td>success</td><td>boolean</td><td colspan="2">接口是否调用成功</td></tr>
<tr><td>data</td><td>-</td><td colspan="2">调用成功时，返回的业务数据</td></tr>

<tr><td>请求示例</td><td colspan="4">
    {   <br>
        &nbsp;&nbsp;"product_id": "IOoSyVbY8q", <br>
        &nbsp;&nbsp;"device_name": ["SB00009"], <br>
        &nbsp;&nbsp;"target_user_tel": "17830021227"    <br>
    }

</td></tr>
<tr><td>响应示例</td>
<td colspan="4">
    {   <br>
        &nbsp;&nbsp;"requestId": "a25087f46df04b69b29e90ef0acfd115",    <br>
        &nbsp;&nbsp;"success": true,    <br>
        &nbsp;&nbsp;"data": {   <br>
        &nbsp;&nbsp;&nbsp;&nbsp;"move_id": "1317465"    <br>
        &nbsp;&nbsp;}   <br>
    }

</td>
</tr>

</table>
