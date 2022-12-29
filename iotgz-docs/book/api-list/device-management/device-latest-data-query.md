# **设备最新数据查询**  

<table style="text-align: left">

<tr><td >方法</td><td colspan="4">GET</td></tr>
<tr><td>路径URI</td><td colspan="4">/application?action=QueryDeviceProperty&version=1&project_id=ocgzVU
&product_id=9MaNe52pNO&device_name=no001
</td></tr>
<tr><td>请求头</td><td colspan="4">Content-Type : application/json</td></tr>

<tr><td rowspan="3">URL请求参数</td><td>project_id</td><td>string</td><td>必填</td><td>项目id</td></tr>
<tr><td>product_id</td><td>string</td><td>必填</td><td>产品ID</td></tr>
<tr><td>device_name</td><td>string</td><td>必填</td><td>设备名称</td></tr>

<tr><td>请求体参数</td><td colspan="4">无</td></tr>


<tr><td rowspan="14">响应参数</td><td>code</td><td>string</td><td colspan="2">错误码，code为“0”代表请求成功</td></tr>
<tr><td>msg</td><td>string</td><td colspan="2">错误消息</td></tr>
<tr><td>requestId</td><td>string</td><td colspan="2">调用API时生成的请求标识</td></tr>
<tr><td>success</td><td>boolean</td><td colspan="2">接口是否调用成功</td></tr>
<tr><td>data</td><td>-</td><td colspan="2">调用成功时，返回的业务数据</td></tr>
<tr><td>data.list</td><td>array</td><td colspan="2">设备最新数据集合，如下的l表示 list 数组的单个对象标识</td></tr>
<tr><td>l.identifier</td><td>string</td><td colspan="2">功能点标识</td></tr>
<tr><td>l.time</td><td>string</td><td colspan="2">上报时间，毫秒时间戳</td></tr>
<tr><td>l.value</td><td>string</td><td colspan="2">功能点上报值，json字符串</td></tr>
<tr><td>l.data_type</td><td>string</td><td colspan="2">数据类型 int32、int64、float、double、enum、bool、string、struct、bitMap</td></tr>
<tr><td>l.access_mode</td><td>string</td><td colspan="2">读写类型</td></tr>
<tr><td>l.expect_value</td><td>string</td><td colspan="2">期望值, json字符串，属性功能点具有该字段</td></tr>
<tr><td>l.name</td><td>string</td><td colspan="2">功能点名称</td></tr>
<tr><td>l.description</td><td>string</td><td colspan="2">功能描述</td></tr>

<tr><td>请求示例</td><td colspan="4">
    GET /application?action=QueryDeviceProperty&version=1&project_id=ocgzVU
&product_id=9MaNe52pNO&device_name=no001
</td></tr>
<tr><td>响应示例</td>
<td colspan="4">
    {   <br>
        &nbsp;&nbsp;"data": {   <br>
            &nbsp;&nbsp;&nbsp;&nbsp;"list": [{  <br>
                &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{   <br>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"access_mode": "读写",  <br>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"data_type": "int32",   <br>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"description": "二氧化碳",  <br>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"expect_value": "800",  <br>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"identifier": "CO2",    <br>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"name": "二氧化碳", <br>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"time": "1592797444539",    <br>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"value": "600"  <br>
                &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;},  <br>
                &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{   <br>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"access_mode": "读写",  <br>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"data_type": "bool",    <br>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"description": "关",    <br>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"expect_value": "true", <br>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"identifier": "fan",    <br>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"name": "风扇", <br>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"time": "1592797444539",    <br>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"value": "false"    <br>
                &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}   <br>
            &nbsp;&nbsp;&nbsp;&nbsp;}]  <br>
        &nbsp;&nbsp;},      <br>
        &nbsp;&nbsp;"requestId": "a25087f46df04b69b29e90ef0acfd115",    <br>
        &nbsp;&nbsp;"success": true <br>
    }

</td>
</tr>

</table>
