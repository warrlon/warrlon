# **设备编辑**  

<table style="text-align: left">

<tr><td >方法</td><td colspan="4">POST</td></tr>
<tr><td>路径URI</td><td colspan="4">/common?action=UpdateDevice&version=1</td></tr>
<tr><td>请求头</td><td colspan="4">Content-Type : application/json</td></tr>

<tr><td>URL参数</td><td colspan="4">无</td></tr>

<tr><td rowspan="6">请求体参数</td><td>device_name</td><td>string</td><td>必填</td><td>设备名称</td></tr>
<tr><td>product_id</td><td>string</td><td>必填</td><td>产品ID</td></tr>
<tr><td>imsi</td><td>string</td><td>可选</td><td>NB设备imsi，不超过15个的数字，设备所属产品为LwM2M时，为必填</td></tr>
<tr><td>psk</td><td>string</td><td>可选</td><td>NB设备所需属性，若创建未填则平台随机生成，8-16位数字字母组合</td></tr>
<tr><td>auth_code</td><td>string</td><td>可选</td><td>NB设备鉴权码，1-16位数字字母组合</td></tr>
<tr><td>desc</td><td>string</td><td>可选</td><td>设备描述</td></tr>

<tr><td rowspan="7">响应参数</td><td>code</td><td>string</td><td colspan="2">调用失败时，返回的错误码</td></tr>
<tr><td>msg</td><td>string</td><td colspan="2">调用失败时，返回的错误信息</td></tr>
<tr><td>requestId</td><td>string</td><td colspan="2">调用API时生成的请求标识</td></tr>
<tr><td>success</td><td>boolean</td><td colspan="2">接口是否调用成功</td></tr>
<tr><td>data</td><td>-</td><td colspan="2">调用成功返回业务数据</td></tr>

<tr><td>data.device_name</td><td>string</td><td colspan="2">设备名称</td></tr>
<tr><td>data.desc</td><td>string</td><td colspan="2">设备描述</td></tr>

<tr><td>请求示例</td><td colspan="4">
    {   <br>
        &nbsp;&nbsp;"product_id":  "9MaNe52pNO",    <br>
        &nbsp;&nbsp;"device_name": "no003", <br>
        &nbsp;&nbsp;"desc": "iot application"   <br>
    }

</td></tr>
<tr><td>响应示例</td>
<td colspan="4">
    {   <br>
        &nbsp;&nbsp;"data": {   <br>
            &nbsp;&nbsp;&nbsp;&nbsp;"device_name": "no003", <br>
            &nbsp;&nbsp;&nbsp;&nbsp;"desc": "iot application"   <br>
        &nbsp;&nbsp;},  <br>
        &nbsp;&nbsp;"requestId": "a25087f46df04b69b29e90ef0acfd115",    <br>
        &nbsp;&nbsp;"success": true <br>
    }

</td>
</tr>

</table>
