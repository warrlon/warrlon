# **设备属性期望值删除**  

<table style="text-align: left">

<tr><td >方法</td><td colspan="4">POST</td></tr>
<tr><td>路径URI</td><td colspan="4">/application?action=DeleteDeviceDesiredProperty&version=1
</td></tr>
<tr><td>请求头</td><td colspan="4">Content-Type : application/json</td></tr>

<tr><td>URL请求参数</td><td colspan="4">无</td></tr>

<tr><td rowspan="4">请求体参数</td><td>project_id</td><td>string</td><td>必填</td><td>项目id</td></tr>
<tr><td>device_name</td><td>string</td><td>必填</td><td>设备名称</td></tr>
<tr><td>product_id</td><td>string</td><td>必填</td><td>产品ID</td></tr>
<tr><td>params</td><td>object</td><td>必填</td><td>删除的属性期望, 数据格式为json对象, 形式为key:value, key为属性功能点标识, value为空对象{} 或者 { "version": 1 }, 如果携带版本号信息，则只有版本号信息等于当前属性期望值版本，才能删除成功</td></tr>

<tr><td rowspan="4">响应参数</td><td>code</td><td>string</td><td colspan="2">调用失败时，返回的错误码</td></tr>
<tr><td>msg</td><td>string</td><td colspan="2">调用失败时，返回的错误信息</td></tr>
<tr><td>requestId</td><td>string</td><td colspan="2">调用API时生成的请求标识</td></tr>
<tr><td>success</td><td>boolean</td><td colspan="2">接口是否调用成功</td></tr>

<tr><td>请求示例</td><td colspan="4">
    {   <br>
         &nbsp;&nbsp;"product_id": "12909",  <br>
         &nbsp;&nbsp;"device_name": "no001", <br>
         &nbsp;&nbsp;"params": { <br>
             &nbsp;&nbsp; &nbsp;&nbsp;"switch":  { version: 1 },  //删除期望值（版本校验）    <br>
             &nbsp;&nbsp; &nbsp;&nbsp;"temperature": {},  // 删除期望值   <br>
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
