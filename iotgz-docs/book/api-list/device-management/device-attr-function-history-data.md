# **设备属性一个功能点历史数据**  

<table style="text-align: left">

<tr><td >方法</td><td colspan="4">GET</td></tr>
<tr><td>路径URI</td><td colspan="4">/common?action=DevicePropertyHistory&version=1&product_id=9MaNe52pNO&device_name=no001&identifier=fan&start_time=1615342778414&end_time=1615342898096
</td></tr>
<tr><td>请求头</td><td colspan="4"></td></tr>

<tr><td rowspan="7">URL请求参数</td><td>product_id</td><td>string</td><td>必填</td><td>产品id</td></tr>
<tr><td>device_name</td><td>string</td><td>必填</td><td>设备名称</td></tr>
<tr><td>identifier</td><td>string</td><td>必填</td><td>属性功能点标识</td></tr>
<tr><td>start_time</td><td>string</td><td>必填</td><td>查询起始时间，毫秒时间戳</td></tr>
<tr><td>end_time</td><td>string</td><td>必填</td><td>查询结束时间，毫秒时间戳</td></tr>
<tr><td>offset</td><td>string</td><td>可选</td><td>请求起始位置，默认0</td></tr>
<tr><td>limit</td><td>string</td><td>可选</td><td>每次请求记录数，默认10, 范围[1, 100]</td></tr>

<tr><td>请求体参数</td><td colspan="4">无</td></tr>

<tr><td rowspan="11">响应参数</td><td>code</td><td>string</td><td colspan="2">错误码，code为“0”代表请求成功</td></tr>
<tr><td>msg</td><td>string</td><td colspan="2">错误消息</td></tr>
<tr><td>requestId</td><td>string</td><td colspan="2">调用API时生成的请求标识</td></tr>
<tr><td>success</td><td>boolean</td><td colspan="2">接口是否调用成功</td></tr>
<tr><td>data</td><td>-</td><td colspan="2">调用成功时，返回的业务数据</td></tr>

<tr><td>data.list</td><td>array</td><td colspan="2">设备属性记录集合，如下的l表示 list 数组的单个对象标识</td></tr>
<tr><td>l.value</td><td>string</td><td colspan="2">属性功能点上报值</td></tr>
<tr><td>l.time</td><td>string</td><td colspan="2">属性功能点上报时间</td></tr>
<tr><td>data.meta</td><td>object</td><td colspan="2">分页信息</td></tr>
<tr><td>data.meta.limit</td><td>int</td><td colspan="2">每次请求记录数</td></tr>
<tr><td>data.meta.offset</td><td>int</td><td colspan="2">请求记录起始位置</td></tr>


<tr><td>请求示例</td><td colspan="4">GET /common?action=DevicePropertyHistory&version=1&product_id=9MaNe52pNO&device_name=no001&identifier=fan&start_time=1615342778414&end_time=1615342898096
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
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"time":"1639380798206", <br>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"value":"qweasd"    <br>
                &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;},  <br>
                &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{   <br>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"time":"1639380795091", <br>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"value":"qweasd"    <br>
                &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}   <br>
            &nbsp;&nbsp;&nbsp;&nbsp;]       <br>
        &nbsp;&nbsp;},  <br>
        &nbsp;&nbsp;"requestId": "a25087f46df04b69b29e90ef0acfd115",    <br>
        &nbsp;&nbsp;"success": true <br>
    }

</td>
</tr>

</table>
