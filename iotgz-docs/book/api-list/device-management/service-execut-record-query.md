# **服务执行记录查询**  

<table style="text-align: left">

<tr><td >方法</td><td colspan="4">GET</td></tr>
<tr><td>路径URI</td><td colspan="4">/application?action=QueryServiceRecord&version=1&project_id=ocgzVU&trace_id=b7be91a1306211eb99afa3eef70771ea
</td></tr>
<tr><td>请求头</td><td colspan="4"></td></tr>

<tr><td rowspan="2">URL请求参数</td><td>project_id</td><td>string</td><td>必填</td><td>项目id </td></tr>
<tr><td>trace_id</td><td>string</td><td>必填</td><td>调用服务后的requestId</td></tr>

<tr><td>请求体参数</td><td colspan="4">无</td></tr>

<tr><td rowspan="14">响应参数</td><td>code</td><td>string</td><td colspan="2">调用失败时，返回的错误码</td></tr>
<tr><td>msg</td><td>string</td><td colspan="2">调用失败时，返回的错误信息</td></tr>
<tr><td>requestId</td><td>string</td><td colspan="2">调用API时生成的请求标识</td></tr>
<tr><td>success</td><td>boolean</td><td colspan="2">接口是否调用成功</td></tr>
<tr><td>data</td><td>-</td><td colspan="2">调用成功时，返回的业务数据</td></tr>

<tr><td>data.request_time</td><td>string</td><td colspan="2">调用服务的时间</td></tr>
<tr><td>data.function_name</td><td>string</td><td colspan="2">功能名称</td></tr>
<tr><td>data.identifier</td><td>string</td><td colspan="2">标识符</td></tr>
<tr><td>data.type</td><td>string</td><td colspan="2">服务调用类型，0为同步，1为异步</td></tr>
<tr><td>data.request_body</td><td>string</td><td colspan="2">服务调用时的请求参数</td></tr>
<tr><td>data.response_time</td><td>string</td><td colspan="2">返回时间</td></tr>
<tr><td>data.response_body</td><td>string</td><td colspan="2">输出参数，json string</td></tr>
<tr><td>data.code</td><td>string</td><td colspan="2">执行结果code，200：执行成功，0：未执行，其他：执行异常</td></tr>
<tr><td>data.msg</td><td>string</td><td colspan="2">返回消息</td></tr>


<tr><td>请求示例</td><td colspan="4">GET /application?action=QueryServiceRecord&version=1&project_id=ocgzVU&trace_id=b7be91a1306211eb99afa3eef70771ea
</td></tr>
<tr><td>响应示例</td>
<td colspan="4">
    {   <br>
        &nbsp;&nbsp;"data": {   <br>
            &nbsp;&nbsp;&nbsp;&nbsp;"request_time": "1606448611264",    <br>
            &nbsp;&nbsp;&nbsp;&nbsp;"function_name": "df",  <br>
            &nbsp;&nbsp;&nbsp;&nbsp;"identifier": "df", <br>
            &nbsp;&nbsp;&nbsp;&nbsp;"type": 1,  <br>
            &nbsp;&nbsp;&nbsp;&nbsp;"request_body": "{\"id\":\"1\",\"version\":\"1.0\",\"params\":{\"identifier\":\"df\",\"input\":{\"fd\":1}}}",   <br>
            &nbsp;&nbsp;&nbsp;&nbsp;"response_time": "0",   <br>
            &nbsp;&nbsp;&nbsp;&nbsp;"response_body": "",    <br>
            &nbsp;&nbsp;&nbsp;&nbsp;"code": 0,  <br>
            &nbsp;&nbsp;&nbsp;&nbsp;"msg": ""   <br>
        &nbsp;&nbsp;}   <br>
        &nbsp;&nbsp;"requestId": "a25087f46df04b69b29e90ef0acfd115",    <br>
        &nbsp;&nbsp;"success": true <br>
    }

</td>
</tr>

</table>
