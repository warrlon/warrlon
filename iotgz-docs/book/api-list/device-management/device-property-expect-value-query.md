# **设备属性期望值查询**  

<table style="text-align: left">

<tr><td >方法</td><td colspan="4">POST</td></tr>
<tr><td>路径URI</td><td colspan="4">/application?action=QueryDeviceDesiredProperty&version=1
</td></tr>
<tr><td>请求头</td><td colspan="4">Content-Type : application/json</td></tr>

<tr><td>URL请求参数</td><td colspan="4">无</td></tr>

<tr><td rowspan="4">请求体参数</td><td>project_id</td><td>string</td><td>必填</td><td>项目id</td></tr>
<tr><td>device_name</td><td>string</td><td>必填</td><td>设备名称</td></tr>
<tr><td>product_id</td><td>string</td><td>必填</td><td>产品ID</td></tr>
<tr><td>params</td><td>array</td><td>必填</td><td>查询期望值的功能点标识集合，参数不传默认查询所有属性期望，例如["switch", "temperature"]</td></tr>

<tr><td rowspan="9">响应参数</td><td>code</td><td>string</td><td colspan="2">调用失败时，返回的错误码</td></tr>
<tr><td>msg</td><td>string</td><td colspan="2">调用失败时，返回的错误信息</td></tr>
<tr><td>requestId</td><td>string</td><td colspan="2">调用API时生成的请求标识</td></tr>
<tr><td>success</td><td>boolean</td><td colspan="2">接口是否调用成功</td></tr>
<tr><td>data</td><td>-</td><td colspan="2">调用成功返回业务数据</td></tr>
<tr><td>data.params</td><td>object</td><td colspan="2">属性功能点期望值</td></tr>
<tr><td>data.params.identify</td><td>object</td><td colspan="2">功能点标识为对象key</td></tr>
<tr><td>data.params.identify.value</td><td>string</td><td colspan="2">期望值值</td></tr>
<tr><td>data.params.identify.version</td><td>int</td><td colspan="2">期望值版本号</td></tr>

<tr><td>请求示例</td><td colspan="4">
    {   <br>
         &nbsp;&nbsp;"project_id": "ocgzVU", <br>
         &nbsp;&nbsp;"product_id": "9MaNe52pNO", <br>
         &nbsp;&nbsp;"device_name": "no001", <br>
         &nbsp;&nbsp;"params": [ <br>
             &nbsp;&nbsp; &nbsp;&nbsp;"switch",   <br>
             &nbsp;&nbsp; &nbsp;&nbsp;"temperature",  <br>
         &nbsp;&nbsp;]   <br>
    }

</td></tr>
<tr><td>响应示例</td>
<td colspan="4">
    {   <br>
         &nbsp;&nbsp;"data": {   <br>
         &nbsp;&nbsp; &nbsp;&nbsp;"params": {     <br>
                 &nbsp;&nbsp; &nbsp;&nbsp; &nbsp;&nbsp;"switch": { <br>
                     &nbsp;&nbsp; &nbsp;&nbsp; &nbsp;&nbsp; &nbsp;&nbsp;"value": "on",  <br>
                     &nbsp;&nbsp; &nbsp;&nbsp; &nbsp;&nbsp; &nbsp;&nbsp;"version": "2"  <br>
                &nbsp;&nbsp; &nbsp;&nbsp; &nbsp;&nbsp;},      <br>    
                 &nbsp;&nbsp; &nbsp;&nbsp; &nbsp;&nbsp;"temperature": {    <br>
                     &nbsp;&nbsp; &nbsp;&nbsp; &nbsp;&nbsp; &nbsp;&nbsp;"value": 23,    <br>
                     &nbsp;&nbsp; &nbsp;&nbsp; &nbsp;&nbsp; &nbsp;&nbsp;"version": 1    <br> 
                 &nbsp;&nbsp; &nbsp;&nbsp; &nbsp;&nbsp;}   <br>
         &nbsp;&nbsp; &nbsp;&nbsp;}   <br>
         &nbsp;&nbsp;},  <br>
         &nbsp;&nbsp;"requestId": "a25087f46df04b69b29e90ef0acfd115",    <br>
         &nbsp;&nbsp;"success": true <br>
    }

</td>
</tr>

</table>
