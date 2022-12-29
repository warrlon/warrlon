# **设备状态查询**  

<table style="text-align: left">

<tr><td >方法</td><td colspan="4">GET</td></tr>
<tr><td>路径URI</td><td colspan="4">/application?action=QueryDeviceStatus&version=1&project_id=ocgzVU
&product_id=9MaNe52pNO&device_name=no001
</td></tr>
<tr><td>请求头</td><td colspan="4"> </td></tr>

<tr><td rowspan="3">URL请求参数</td><td>project_id</td><td>string</td><td>必填</td><td>项目id</td></tr>
<tr><td>product_id</td><td>string</td><td>必填</td><td>产品ID</td></tr>
<tr><td>device_name</td><td>string</td><td>必填</td><td>设备名称</td></tr>

<tr><td>请求体</td><td colspan="4">无</td></tr>

<tr><td rowspan="6">响应参数</td><td>code</td><td>string</td><td colspan="2">调用失败时，返回的错误码</td></tr>
<tr><td>msg</td><td>string</td><td colspan="2">调用失败时，返回的错误信息</td></tr>
<tr><td>requestId</td><td>string</td><td colspan="2">调用API时生成的请求标识</td></tr>
<tr><td>success</td><td>boolean</td><td colspan="2">接口是否调用成功</td></tr>
<tr><td>data</td><td>-</td><td colspan="2">调用成功时，返回的业务数据</td></tr>
<tr><td>data.status</td><td>int</td><td colspan="2">设备状态 1-未激活 2-在线 3-离线</td></tr>

<tr><td>请求示例</td><td colspan="4">GET  /application?action=QueryDeviceStatus&version=1&project_id=ocgzVU
&product_id=9MaNe52pNO&device_name=no001
</td></tr>
<tr><td>响应示例</td>
<td colspan="4">
    {   <br>
        &nbsp;&nbsp;"data": {   <br>
            &nbsp;&nbsp;&nbsp;&nbsp;status: 1   <br>
        &nbsp;&nbsp;},  <br>
        &nbsp;&nbsp;"requestId": "a25087f46df04b69b29e90ef0acfd115",    <br>
        &nbsp;&nbsp;"success": true <br>
    }

</td>
</tr>

</table>
