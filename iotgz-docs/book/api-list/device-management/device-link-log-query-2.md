# **设备链路日志查询**  

<table style="text-align: left">

<tr><td >方法</td><td colspan="4">GET</td></tr>
<tr><td>路径URI</td><td colspan="4">/common?action=DeviceTraceLog&version=1start_time=1639050724393&end_time=1639381724393
</td></tr>
<tr><td>请求头</td><td colspan="4"></td></tr>

<tr><td rowspan="7">URL请求参数</td><td>product_id</td><td>string</td><td>可选</td><td>产品id</td></tr>
<tr><td>device_name</td><td>string</td><td>可选</td><td>设备名称</td></tr>
<tr><td>start_time</td><td>string</td><td>必填</td><td>查询起始时间，毫秒时间戳</td></tr>
<tr><td>end_time</td><td>string</td><td>必填</td><td>查询结束时间，毫秒时间戳</td></tr>
<tr><td>offset</td><td>string</td><td>可选</td><td>请求起始位置，默认0</td></tr>
<tr><td>limit</td><td>string</td><td>可选</td><td>每次请求记录数，默认10, 范围[1, 100]</td></tr>
<tr><td>log_type</td><td>string</td><td>可选</td><td>业务类型编码，参考备注</td></tr>

<tr><td>请求体参数</td><td colspan="4">无</td></tr>

<tr><td rowspan="17">响应参数</td><td>code</td><td>string</td><td colspan="2">调用失败时，返回的错误码</td></tr>
<tr><td>msg</td><td>string</td><td colspan="2">调用失败时，返回的错误信息</td></tr>
<tr><td>requestId</td><td>string</td><td colspan="2">调用API时生成的请求标识</td></tr>
<tr><td>success</td><td>boolean</td><td colspan="2">接口是否调用成功</td></tr>
<tr><td>data</td><td>-</td><td colspan="2">调用成功时，返回的业务数据</td></tr>

<tr><td>data.list</td><td>array</td><td colspan="2">设备链接日志记录数据集合</td></tr>
<tr><td>data.meta</td><td>object</td><td colspan="2">分页信息</td></tr>
<tr><td>data.meta.limit</td><td>int</td><td colspan="2">每次请求记录数</td></tr>
<tr><td>data.meta.offset</td><td>int</td><td colspan="2">请求记录起始位置</td></tr>

<tr><td>请求示例</td><td colspan="3">GET /common?action=DeviceTraceLog&version=1start_time=1639050724393&end_time=1639381724393
</td></tr>
<tr><td>响应示例</td>
<td colspan="3">
    {   <br>
        &nbsp;&nbsp;"data": {   <br>
            &nbsp;&nbsp;&nbsp;&nbsp;"list":[    <br>
                &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{   <br>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"_routing":"7ubgKi1vhm",    <br>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"@timestamp":"2021-12-10T10:19:33.325Z",    <br>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"type":"1.1",   <br>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"start_time":"2021-12-10T10:19:33.325Z",    <br>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"@version":"1", <br>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"pid":"7ubgKi1vhm", <br>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"status":"200", <br>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"trace_id":"ab2fc05759a211ecbfd023bbbfff50a4",  <br>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"end_time":"2021-12-10T10:19:33.325Z",  <br>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"env_type":"UNKNOWN",   <br>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"uid":"5",  <br>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"device_name":"400A002090011001",   <br>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"content":"{\"protocol\":\"MQTT\",\"offline_time\":\"2021-12-10 18:19:33.325\", \"offline_reason\":\"CloseByPeer\"}",   <br>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"create_time":"2021-12-10 18:19:33",    <br>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"message_status":"0",   <br>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"type_mean":"设备行为", <br>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"status_mean":"成功"    <br>
                &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}   <br>
            &nbsp;&nbsp;&nbsp;&nbsp;],  <br>
            &nbsp;&nbsp;&nbsp;&nbsp;"meta":{    <br>
                &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"total":26, <br>
                &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"limit":"11",   <br>
                &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"offset":"0"    <br>
            &nbsp;&nbsp;&nbsp;&nbsp;}   <br>
        &nbsp;&nbsp;}   <br>
        &nbsp;&nbsp;"requestId": "a25087f46df04b69b29e90ef0acfd115",    <br>
        &nbsp;&nbsp;"success": true <br>
    }   

</td>
</tr>

<tr><td>备注</td><td colspan="3">
    业务类型对照表：{ <br>
    &nbsp;&nbsp;&nbsp;&nbsp;'1.1': '设备行为', <br>
    &nbsp;&nbsp;&nbsp;&nbsp;'1.2': '上行消息', <br>
    &nbsp;&nbsp;&nbsp;&nbsp;'1.3': '下行消息', <br>
    &nbsp;&nbsp;&nbsp;&nbsp;'2.1': '物模型调用', <br>
    &nbsp;&nbsp;&nbsp;&nbsp;'3.1': '数据存储', <br>
    &nbsp;&nbsp;&nbsp;&nbsp;'4.1': '规则引擎', <br>
    &nbsp;&nbsp;&nbsp;&nbsp;'5.1': 'HTTP推送', <br>
    &nbsp;&nbsp;&nbsp;&nbsp;'6.1': 'Kafka推送', <br>
    &nbsp;&nbsp;&nbsp;&nbsp;'7.1': '开放API', <br>
    &nbsp;&nbsp;&nbsp;&nbsp;'8.1': 'RDS存储', <br>
    &nbsp;&nbsp;&nbsp;&nbsp;'9.1': '应用长连接' <br>
    }

</td></tr>

</table>
