# **调用服务**  

<table style="text-align: left">

<tr><td >方法</td><td colspan="4">POST</td></tr>
<tr><td>路径URI</td><td colspan="4">/application?action=CallService&version=1</td></tr>
<tr><td>请求头</td><td colspan="4">Content-Type : application/json</td></tr>

<tr><td>URL参数</td><td colspan="4">无</td></tr>

<tr><td rowspan="5">请求体参数</td><td>project_id</td><td>string</td><td>必填</td><td>项目id </td></tr>
<tr><td>device_name</td><td>string</td><td>必填</td><td>设备名称</td></tr>
<tr><td>product_id</td><td>string</td><td>必填</td><td>产品id</td></tr>
<tr><td>identifier</td><td>string</td><td>必填</td><td>服务型功能点标识</td></tr>
<tr><td>params</td><td>object</td><td>必填</td><td>输入参数的键值对，输入参数的唯一标识做键</td></tr>

<tr><td rowspan="5">响应参数</td><td>code</td><td>string</td><td colspan="2">调用失败时，返回的错误码</td></tr>
<tr><td>msg</td><td>string</td><td colspan="2">调用失败时，返回的错误信息</td></tr>
<tr><td>requestId</td><td>string</td><td colspan="2">调用API时生成的请求标识</td></tr>
<tr><td>success</td><td>boolean</td><td colspan="2">接口是否调用成功</td></tr>
<tr><td>data</td><td>-</td><td colspan="2">调用成功返回业务数据</td></tr>

<tr><td>请求示例</td><td colspan="4">
    {   <br>
        &nbsp;&nbsp;"project_id":"ocgzVU",  <br>
        &nbsp;&nbsp;"product_id":"B7EEW578EbRg5Y4K",    <br>
        &nbsp;&nbsp;"device_name":"device3",    <br>
        &nbsp;&nbsp;"identifier": "light",  <br>
        &nbsp;&nbsp;"params":{  <br>
            &nbsp;&nbsp;&nbsp;&nbsp;"Power1":"1",   <br>
            &nbsp;&nbsp;&nbsp;&nbsp;"WF1":"2"   <br>
        &nbsp;&nbsp;}   <br>
    }   

</td></tr>
<tr><td>响应示例</td>
<td colspan="4">
    {   <br>
        &nbsp;&nbsp;"requestId": "a25087f46df04b69b29e90ef0acfd115",    <br>
        &nbsp;&nbsp;"success": true,    <br>
        &nbsp;&nbsp;"data":{    <br>
            &nbsp;&nbsp;&nbsp;&nbsp;"result1":"1",  <br>
            &nbsp;&nbsp;&nbsp;&nbsp;"result2":"2"   <br>
        &nbsp;&nbsp;}   <br>
    }


</td>
</tr>

</table>
