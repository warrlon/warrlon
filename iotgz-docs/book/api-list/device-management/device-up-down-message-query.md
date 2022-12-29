# **设备上下行消息查询**  

<table style="text-align: left">

<tr><td >方法</td><td colspan="4">GET</td></tr>
<tr><td>路径URI</td><td colspan="4">/common?action=DeviceMessage&version=1&message_id=fe8e158c5cab11ecbfd05180177bf746
</td></tr>
<tr><td>请求头</td><td colspan="4"></td></tr>

<tr><td>URL请求参数</td><td>message_id</td><td>string</td><td>必填</td><td>消息id 通过接口【设备链路日志查询】获取（只存在部分类型的日志信息中）</td></tr>

<tr><td>请求体参数</td><td colspan="4">无</td></tr>

<tr><td rowspan="5">响应参数</td><td>code</td><td>string</td><td colspan="2">调用失败时，返回的错误码</td></tr>
<tr><td>msg</td><td>string</td><td colspan="2">调用失败时，返回的错误信息</td></tr>
<tr><td>requestId</td><td>string</td><td colspan="2">调用API时生成的请求标识</td></tr>
<tr><td>success</td><td>boolean</td><td colspan="2">接口是否调用成功</td></tr>
<tr><td>data</td><td>-</td><td colspan="2">调用成功时，返回的业务数据，data为base64 字符串，可转义</td></tr>

<tr><td>请求示例</td><td colspan="4">GET /common?action=DeviceMessage&version=1&message_id=fe8e158c5cab11ecbfd05180177bf746
</td></tr>
<tr><td>响应示例</td>
<td colspan="4">
    {   <br>
        &nbsp;&nbsp;"data": "eyJpZCI6IjE2Mzk0NjU0MzIzOTMiLCJjb2RlIjoyMDAsIm1zZyI6InN1Y2Nlc3MifQ==",    <br>
        &nbsp;&nbsp;"requestId": "a25087f46df04b69b29e90ef0acfd115",    <br>
        &nbsp;&nbsp;"success": true <br>
    }

</td>
</tr>

</table>
