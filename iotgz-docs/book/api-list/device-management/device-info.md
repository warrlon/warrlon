# **设备详情**  

<table style="text-align: left">

<tr><td >方法</td><td colspan="4">GET</td></tr>
<tr><td>路径URI</td><td colspan="4">/common?action=QueryDeviceDetail&version=1&product_id=lsibd9
&device_name=no001
</td></tr>
<tr><td>请求头</td><td colspan="4"></td></tr>

<tr><td rowspan="2">URL请求参数</td><td>product_id</td><td>string</td><td>必填</td><td>产品id</td></tr>
<tr><td>device_name</td><td>string</td><td>必填</td><td>设备名称</td></tr>

<tr><td>请求体参数</td><td colspan="4">无</td></tr>

<tr><td rowspan="17">响应参数</td><td>code</td><td>string</td><td colspan="2">调用失败时，返回的错误码</td></tr>
<tr><td>msg</td><td>string</td><td colspan="2">调用失败时，返回的错误信息</td></tr>
<tr><td>requestId</td><td>string</td><td colspan="2">调用API时生成的请求标识</td></tr>
<tr><td>success</td><td>boolean</td><td colspan="2">接口是否调用成功</td></tr>
<tr><td>data</td><td>-</td><td colspan="2">调用成功时，返回的业务数据</td></tr>

<tr><td>data.device_name</td><td>string</td><td colspan="2">设备名称</td></tr>
<tr><td>data.product_id</td><td>string</td><td colspan="2">产品ID</td></tr>
<tr><td>data.product_name</td><td>string</td><td colspan="2">产品名称</td></tr>
<tr><td>data.desc</td><td>string</td><td colspan="2">设备描述</td></tr>
<tr><td>data.status</td><td>int</td><td colspan="2">设备状态 1-未激活 2-在线 3-离线</td></tr>
<tr><td>data.node_type</td><td>int</td><td colspan="2">节点类型 1-直连设备</td></tr>
<tr><td>data.protocol</td><td>int</td><td colspan="2">协议类型 1-泛协议 2-MQTT 3-CoAP</td></tr>
<tr><td>data.ip</td><td>string</td><td colspan="2">设备连接ip</td></tr>
<tr><td>data.create_time</td><td>string</td><td colspan="2">创建时间</td></tr>
<tr><td>data.last_time</td><td>string</td><td colspan="2">最后一次在线时间</td></tr>
<tr><td>data.active_time</td><td>string</td><td colspan="2">激活时间</td></tr>
<tr><td>data.sec_key</td><td>string</td><td colspan="2">设备密钥</td></tr>

<tr><td>请求示例</td><td colspan="4">GET /common?action=QueryDeviceDetail&version=1&product_id=lsibd9
&device_name=no001
</td></tr>
<tr><td>响应示例</td>
<td colspan="4">
    {   <br>
        &nbsp;&nbsp;"data": {   <br>
            &nbsp;&nbsp;&nbsp;&nbsp;"device_name": "no001", <br>
            &nbsp;&nbsp;&nbsp;&nbsp;"product_id": "9MaNe52pNO", <br>
            &nbsp;&nbsp;&nbsp;&nbsp;"product_name": "空气净化器",   <br>
            &nbsp;&nbsp;&nbsp;&nbsp;"active_time": "2020-06-19T08:11:27.801Z",  <br>
            &nbsp;&nbsp;&nbsp;&nbsp;"created_time": "2020-06-19T06:09:22.550Z", <br>
            &nbsp;&nbsp;&nbsp;&nbsp;"desc": "设备1",        <br>    
            &nbsp;&nbsp;&nbsp;&nbsp;"ip": "192.168.200.139",    <br>
            &nbsp;&nbsp;&nbsp;&nbsp;"last_time": "2020-06-19T09:48:15.027Z",    <br>
            &nbsp;&nbsp;&nbsp;&nbsp;"node_type": 1,     <br>
            &nbsp;&nbsp;&nbsp;&nbsp;"protocol": 2,  <br>
            &nbsp;&nbsp;&nbsp;&nbsp;"sec_key": "UQd3K9lXR/EbLXeJc50lJfvvkTVdu5uFgbfz48/fI5k=",  <br>
            &nbsp;&nbsp;&nbsp;&nbsp;"status": 3 <br>
        &nbsp;&nbsp;},  <br>
        &nbsp;&nbsp;"requestId": "a25087f46df04b69b29e90ef0acfd115",    <br>
        &nbsp;&nbsp;"success": true <br>
    }

</td>
</tr>

</table>
