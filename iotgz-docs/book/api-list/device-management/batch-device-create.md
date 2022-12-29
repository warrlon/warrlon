# **批量创建设备**  

<table style="text-align: left">

<tr><td >方法</td><td colspan="4">POST</td></tr>
<tr><td>路径URI</td><td colspan="4">/common?action=BatchCreateDevices&version=1</td></tr>
<tr><td>请求头</td><td colspan="4">Content-Type : application/json</td></tr>

<tr><td>URL参数</td><td colspan="4">无</td></tr>

<tr><td rowspan="2">请求体参数</td><td>product_id</td><td>string</td><td>必填</td><td>产品ID</td></tr>
<tr><td>devices</td><td>array</td><td>必填</td><td>批量创建的设备信息集合, 一次最多创建500个设备。每个集合元素为json对象，包括name和desc属性值,例如[{ "name": "no001" , "desc": "iot application" }], 设备为LwM2M协议时，增加imei、imsi、auth_code、psk属性，校验规则请参考设备创建接口</td></tr>

<tr><td rowspan="16">响应参数</td><td>code</td><td>string</td><td colspan="2">调用失败时，返回的错误码</td></tr>
<tr><td>msg</td><td>string</td><td colspan="2">调用失败时，返回的错误信息</td></tr>
<tr><td>requestId</td><td>string</td><td colspan="2">调用API时生成的请求标识</td></tr>
<tr><td>success</td><td>boolean</td><td colspan="2">接口是否调用成功</td></tr>
<tr><td>data</td><td>-</td><td colspan="2">调用成功返回业务数据</td></tr>

<tr><td>data.list</td><td>array</td><td colspan="2">创建成功设备信息集合，如下的l表示 list 数组的单个对象标识</td></tr>
<tr><td>l.name</td><td>string</td><td colspan="2">设备名称</td></tr>
<tr><td>l.node_type</td><td>Int</td><td colspan="2">设备类型  1-直连设备</td></tr>
<tr><td>l.desc</td><td>string</td><td colspan="2">设备描述</td></tr>
<tr><td>l.sec_key</td><td>string</td><td colspan="2">设备密钥</td></tr>
<tr><td>l.protocol</td><td>int</td><td colspan="2">协议类型  1-泛协议  2-MQTT  3-CoAP</td></tr>
<tr><td>l.imei</td><td>string</td><td colspan="2">imei</td></tr>
<tr><td>l.imsi</td><td>string</td><td colspan="2">imsi</td></tr>
<tr><td>l.auth_code</td><td>string</td><td colspan="2">auth_code</td></tr>
<tr><td>l.psk</td><td>string</td><td colspan="2">psk</td></tr>
<tr><td>l.created_time</td><td>string</td><td colspan="2">创建时间</td></tr>

<tr><td>请求示例</td><td colspan="4">
    {   <br>
        &nbsp;&nbsp;"product_id": "9MaNe52pNO", <br>
        &nbsp;&nbsp;&nbsp;&nbsp;"devices": [    <br>
            &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{   <br>
                &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"name": "no001",    <br>
                &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"desc": "iot application"   <br>      
            &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}   <br>
        &nbsp;&nbsp;&nbsp;&nbsp;]   <br>
    }

</td></tr>
<tr><td>响应示例</td>
<td colspan="4">
    {   <br>
        &nbsp;&nbsp;"data": {   <br>
            &nbsp;&nbsp;&nbsp;&nbsp;list: [{    <br>
                &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"name": "no001",    <br>
                &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"node_type": 1,     <br>
                &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"desc": "iot application",  <br>
                &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"sec_key": "imQE5CGsIiT9ZMBMD/bSbqMnPIBwXXsYynQQsi/fimk=",  <br>
                &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"created_time": "2020-06-08T10:33:30.442Z",     <br>
                &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"protocol": 1   <br>
            &nbsp;&nbsp;&nbsp;&nbsp;}]  <br>
        &nbsp;&nbsp;},  <br>
        &nbsp;&nbsp;"requestId": "a25087f46df04b69b29e90ef0acfd115",    <br>
        &nbsp;&nbsp;"success": true <br>
    }

</td>
</tr>

</table>
