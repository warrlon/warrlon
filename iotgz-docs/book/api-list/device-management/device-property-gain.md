# **设备属性获取**  

<table style="text-align: left">

<tr><td >方法</td><td colspan="4">POST</td></tr>
<tr><td>路径URI</td><td colspan="4">/application?action=QueryDevicePropertyDetail&version=1
</td></tr>
<tr><td>请求头</td><td colspan="4">Content-Type : application/json</td></tr>

<tr><td>URL请求参数</td><td colspan="4">无</td></tr>

<tr><td rowspan="4">请求体参数</td><td>project_id</td><td>string</td><td>必填</td><td>项目id</td></tr>
<tr><td>device_name</td><td>string</td><td>必填</td><td>设备名称</td></tr>
<tr><td>product_id</td><td>string</td><td>必填</td><td>产品ID</td></tr>
<tr><td>params</td><td>array</td><td>必填</td><td>功能点标识数组，expample: ["light","model"]</td></tr>

<tr><td rowspan="5">响应参数</td><td>code</td><td>string</td><td colspan="2">调用失败时，返回的错误码</td></tr>
<tr><td>msg</td><td>string</td><td colspan="2">调用失败时，返回的错误信息</td></tr>
<tr><td>requestId</td><td>string</td><td colspan="2">调用API时生成的请求标识</td></tr>
<tr><td>success</td><td>boolean</td><td colspan="2">接口是否调用成功</td></tr>
<tr><td>data</td><td>-</td><td colspan="2">调用成功时，返回的业务数据</td></tr>

<tr><td>请求示例</td><td colspan="4">
    {   <br>
        &nbsp;&nbsp;"project_id":"ocgzVU",  <br>
        &nbsp;&nbsp;"product_id":"B7EEW578EbRg5Y4K",    <br>
        &nbsp;&nbsp;"device_name":"device3",    <br>
        &nbsp;&nbsp;"params":["light","model"]  <br>
    }

</td></tr>
<tr><td>响应示例</td>
<td colspan="4">
    {   <br>
        &nbsp;&nbsp;"requestId": "a25087f46df04b69b29e90ef0acfd115",    <br>
        &nbsp;&nbsp;"success": true,    <br>
        &nbsp;&nbsp;"data":{    <br>
            &nbsp;&nbsp;&nbsp;&nbsp;"light":1,  <br>
            &nbsp;&nbsp;&nbsp;&nbsp;"model":1   <br>
        &nbsp;&nbsp;}   <br>
    }

</td>
</tr>

</table>
