# **设备创建**  

<table style="text-align: left">

<tr><td >方法</td><td colspan="4">POST</td></tr>
<tr><td>路径URI</td><td colspan="4">/common?action=CreateDevice&version=1</td></tr>
<tr><td>请求头</td><td colspan="4">Content-Type : application/json</td></tr>

<tr><td>URL参数</td><td colspan="4">无</td></tr>

<tr><td rowspan="7">请求体参数</td><td>device_name</td><td>string</td><td>必填</td><td>设备名称</td></tr>
<tr><td>product_id</td><td>string</td><td>必填</td><td>产品ID</td></tr>
<tr><td>imei</td><td>string</td><td>可选(LwM2M协议时必填)</td><td>NB设备imei，15个数字组成的电子串号，设备所属产品为LwM2M时，为必填</td></tr>
<tr><td>imsi</td><td>string</td><td>可选</td><td>NB设备imsi，不超过15个的数字，设备所属产品为LwM2M时，为必填</td></tr>
<tr><td>psk</td><td>string</td><td>可选</td><td>NB设备所需属性，若创建未填则平台随机生成，8-16位数字字母组合</td></tr>
<tr><td>auth_code</td><td>string</td><td>可选</td><td>NB设备鉴权码，1-16位数字字母组合</td></tr>
<tr><td>desc</td><td>string</td><td>可选</td><td>设备描述</td></tr>

<tr><td rowspan="15">响应参数</td><td>code</td><td>string</td><td colspan="2">调用失败时，返回的错误码</td></tr>
<tr><td>msg</td><td>string</td><td colspan="2">调用失败时，返回的错误信息</td></tr>
<tr><td>requestId</td><td>string</td><td colspan="2">调用API时生成的请求标识</td></tr>
<tr><td>success</td><td>boolean</td><td colspan="2">接口是否调用成功</td></tr>
<tr><td>data</td><td>-</td><td colspan="2">调用成功返回业务数据</td></tr>

<tr><td>data.name</td><td>string</td><td colspan="2">设备名称</td></tr>
<tr><td>data.node_type</td><td>string</td><td colspan="2">节点类型 1-直连设备</td></tr>
<tr><td>data.desc</td><td>string</td><td colspan="2">设备描述</td></tr>
<tr><td>data.sec_key</td><td>string</td><td colspan="2">设备密钥</td></tr>
<tr><td>data.protocol</td><td>int</td><td colspan="2">协议 1-泛协议 2-MQTT 3-CoAP</td></tr>
<tr><td>data.created_time</td><td>string</td><td colspan="2">创建时间</td></tr>
<tr><td>data.imei</td><td>string</td><td colspan="2">NB设备imei，15个数字组成的电子串号</td></tr>
<tr><td>data.imsi</td><td>string</td><td colspan="2">NB设备imsi，不超过15个的数字</td></tr>
<tr><td>data.auth_code</td><td>string</td><td colspan="2">NB设备鉴权码</td></tr>
<tr><td>data.psk</td><td>string</td><td colspan="2">NB设备所需属性</td></tr>

<tr><td>请求示例</td><td colspan="4">
    {   <br>
        &nbsp;&nbsp;"product_id":  "9MaNe52pNO",    <br>
        &nbsp;&nbsp;"device_name": "no003", <br>
        &nbsp;&nbsp;"imei": "366322456556584",  <br>
        &nbsp;&nbsp;"imsi": "366322456556584",  <br>
        &nbsp;&nbsp;"auth_code": "authcode",    <br>
        &nbsp;&nbsp;"psk": "authcode",      <br>
        &nbsp;&nbsp;"desc": "iot application"   <br>
    }


</td></tr>
<tr><td>响应示例</td>
<td colspan="4">
    {   <br>
        &nbsp;&nbsp;"data": {   <br>
            &nbsp;&nbsp;&nbsp;&nbsp;"name": "no003",    <br>
            &nbsp;&nbsp;&nbsp;&nbsp;"node_type": 1,     <br>
            &nbsp;&nbsp;&nbsp;&nbsp;"desc": "iot application",  <br>
            &nbsp;&nbsp;&nbsp;&nbsp;"sec_key": "imQE5CGsIiT9ZMBMD/bSbqMnPIBwXXsYynQQsi/fimk=",  <br>
            &nbsp;&nbsp;&nbsp;&nbsp;"created_time": "2020-06-08T10:33:30.442Z",     <br>
            &nbsp;&nbsp;&nbsp;&nbsp;"protocol": 1   <br>
        &nbsp;&nbsp;},  <br>
        &nbsp;&nbsp;"requestId": "a25087f46df04b69b29e90ef0acfd115",    <br>
        &nbsp;&nbsp;"success": true <br>
    }

</td>
</tr>

</table>
