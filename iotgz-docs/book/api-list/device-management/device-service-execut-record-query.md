# **设备服务执行记录查询**  

<table style="text-align: left">

<tr><td >方法</td><td colspan="4">GET</td></tr>
<tr><td>路径URI</td><td colspan="4">/common?action=DeviceServiceHistory&version=1&product_id=7ubgKi1vhm&device_name=sb0011&start_time=1639050724393&end_time=1639381724393
</td></tr>
<tr><td>请求头</td><td colspan="4"></td></tr>

<tr><td rowspan="6">URL请求参数</td><td>product_id</td><td>string</td><td>必填</td><td>产品id</td></tr>
<tr><td>device_name</td><td>string</td><td>必填</td><td>设备名称</td></tr>
<tr><td>start_time</td><td>string</td><td>必填</td><td>查询起始时间，毫秒时间戳</td></tr>
<tr><td>end_time</td><td>string</td><td>必填</td><td>查询结束时间，毫秒时间戳</td></tr>
<tr><td>offset</td><td>string</td><td>可选</td><td>请求起始位置，默认0</td></tr>
<tr><td>limit</td><td>string</td><td>可选</td><td>每次请求记录数，默认10, 范围[1, 100]</td></tr>

<tr><td>请求体参数</td><td colspan="4">无</td></tr>

<tr><td rowspan="18">响应参数</td><td>code</td><td>string</td><td colspan="2">调用失败时，返回的错误码</td></tr>
<tr><td>msg</td><td>string</td><td colspan="2">调用失败时，返回的错误信息</td></tr>
<tr><td>requestId</td><td>string</td><td colspan="2">调用API时生成的请求标识</td></tr>
<tr><td>success</td><td>boolean</td><td colspan="2">接口是否调用成功</td></tr>
<tr><td>data</td><td>-</td><td colspan="2">调用成功时，返回的业务数据</td></tr>

<tr><td>data.list</td><td>array</td><td colspan="2">设备服务执行记录数据集合，如下的l表示 list 数组的单个对象标识</td></tr>
<tr><td>list.request_time</td><td>string</td><td colspan="2">调用服务的时间</td></tr>
<tr><td>list.function_name</td><td>string</td><td colspan="2">功能名称</td></tr>
<tr><td>list.identifier</td><td>string</td><td colspan="2">标识符</td></tr>
<tr><td>list.type</td><td>string</td><td colspan="2">服务调用类型，0为同步，1为异步</td></tr>
<tr><td>list.request_body</td><td>string</td><td colspan="2">服务调用时的请求参数</td></tr>
<tr><td>list.response_time</td><td>string</td><td colspan="2">返回时间</td></tr>
<tr><td>list.response_body</td><td>string</td><td colspan="2">输出参数，json string</td></tr>
<tr><td>list.code</td><td>string</td><td colspan="2">执行结果code，200：执行成功，0：未执行，其他：执行异常</td></tr>
<tr><td>list.msg</td><td>string</td><td colspan="2">返回消息</td></tr>
<tr><td>data.meta</td><td>object</td><td colspan="2">分页信息</td></tr>
<tr><td>data.meta.limit</td><td>int</td><td colspan="2">每次请求记录数</td></tr>
<tr><td>data.meta.offset</td><td>int</td><td colspan="2">请求记录起始位置</td></tr>


<tr><td>请求示例</td><td colspan="4">GET /common?action=DeviceServiceHistory&version=1&product_id=7ubgKi1vhm&device_name=sb0011&start_time=1639050724393&end_time=1639381724393
</td></tr>
<tr><td>响应示例</td>
<td colspan="4">
    {   <br>
        &nbsp;&nbsp;"data": {   <br>
            &nbsp;&nbsp;&nbsp;&nbsp;"meta":{    <br>
                &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"offset":0, <br>
                &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"limit":10  <br>
            &nbsp;&nbsp;&nbsp;&nbsp;},  <br>
            &nbsp;&nbsp;&nbsp;&nbsp;"list":[    <br>
                &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{   <br>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"request_time":"1639383257642", <br>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"function_name":"s1",   <br>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"identifier":"s1",  <br>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"type":1,   <br>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"request_body":"{\"id\":\"2\",\"params\":{\"identifier\":\"s1\",\"input\":{\"b\":2}},   \"version\":\"1.0\"}",  <br>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"response_time":"0",    <br>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"response_body":"", <br>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"code":0,   <br>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"msg":""    <br>
                &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}   <br>
            &nbsp;&nbsp;&nbsp;&nbsp;]   <br>
        &nbsp;&nbsp;}   <br>
        &nbsp;&nbsp;"requestId": "a25087f46df04b69b29e90ef0acfd115",    <br> 
        &nbsp;&nbsp;"success": true <br>
    }

</td>
</tr>

</table>
