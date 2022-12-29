# **设备属性期望值设置**  

<table style="text-align: left">

<tr><td >方法</td><td colspan="4">POST</td></tr>
<tr><td>路径URI</td><td colspan="4">/application?action=QueryDevicePropertyDetail&version=1
</td></tr>
<tr><td>请求头</td><td colspan="4">Content-Type : application/json</td></tr>

<tr><td>URL请求参数</td><td colspan="4">无</td></tr>

<tr><td rowspan="4">请求体参数</td><td>project_id</td><td>string</td><td>必填</td><td>项目id</td></tr>
<tr><td>device_name</td><td>string</td><td>必填</td><td>设备名称</td></tr>
<tr><td>product_id</td><td>string</td><td>必填</td><td>产品ID</td></tr>
<tr><td>params</td><td>object</td><td>必填</td><td>设置的属性期望值, 数据格式为json对象, 形式为key:value, key为属性功能点标识, value为属性值, 取值符合物模型定义的数据类型和取值范围, 例如{ "switch": true }</td></tr>

<tr><td rowspan="4">响应参数</td><td>code</td><td>string</td><td colspan="2">调用失败时，返回的错误码</td></tr>
<tr><td>msg</td><td>string</td><td colspan="2">调用失败时，返回的错误信息</td></tr>
<tr><td>requestId</td><td>string</td><td colspan="2">调用API时生成的请求标识</td></tr>
<tr><td>success</td><td>boolean</td><td colspan="2">接口是否调用成功</td></tr>

<tr><td>请求示例</td><td colspan="4">
    {   <br>
         &nbsp;&nbsp;"project_id": "ocgzVU", <br>
         &nbsp;&nbsp;"product_id": "9MaNe52pNO", <br>
         &nbsp;&nbsp;"device_name": "no001", <br>
         &nbsp;&nbsp;"params": { <br>
             &nbsp;&nbsp; &nbsp;&nbsp;"switch": true,             // bool <br>
             &nbsp;&nbsp; &nbsp;&nbsp;"text": "hello",            // string   <br>
             &nbsp;&nbsp; &nbsp;&nbsp;"humidity": 12 ,            // int32    <br>
             &nbsp;&nbsp; &nbsp;&nbsp;"number": 1564448722123,      // int64  <br>
             &nbsp;&nbsp; &nbsp;&nbsp;"temperature": 30.2             // float    <br>
             &nbsp;&nbsp; &nbsp;&nbsp;"lng": 3.1234567890123456789,   // double   <br>
             &nbsp;&nbsp; &nbsp;&nbsp;"type": 1,                      // enum <br>
            &nbsp;&nbsp; &nbsp;&nbsp; "error": 256,                   // bitmap   <br>
             &nbsp;&nbsp; &nbsp;&nbsp;"event":  {                    // struct    <br>
                 &nbsp;&nbsp; &nbsp;&nbsp; &nbsp;&nbsp;"a": 1, <br>
                 &nbsp;&nbsp; &nbsp;&nbsp; &nbsp;&nbsp;"b": true   <br>
             &nbsp;&nbsp; &nbsp;&nbsp;}   <br>
         &nbsp;&nbsp;}   <br>
    }

</td></tr>
<tr><td>响应示例</td>
<td colspan="4">
    {   <br>
         &nbsp;&nbsp;"requestId": "a25087f46df04b69b29e90ef0acfd115",    <br>
         &nbsp;&nbsp;"success": true <br>
    }

</td>
</tr>

</table>
