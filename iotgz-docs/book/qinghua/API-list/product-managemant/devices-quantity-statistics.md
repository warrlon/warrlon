# 产品中的设备数量统计

<table>
<tr><th>方法</th><td colspan="4">GET</th></tr>
<tr><td>路径URI</td><td colspan="4">/common?action=ProductDeviceStatistics&version=1</td></tr>
<tr><td>请求头</td><td colspan="4"></td></tr>
<tr><td rowspan="1">URL请求参数</td><td>product_id</td><td>string</td><td>必填</td><td>产品id </td></td>

<tr><td rowspan="9">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>调用成功返回业务数据</td></tr>
<tr><td colspan="2">data.unactive</td><td>number</td><td>未激活设备数</td></tr>
<tr><td colspan="2">data.online</td><td>number</td><td>在线设备数</td></tr>
<tr><td colspan="2">data.offline</td><td>number</td><td>离线设备数</td></tr>
<tr><td colspan="2">data.total</td><td>number</td><td>总的设备数</td></tr>

<tr><th>请求示例</th><td colspan="4">GET /common?action=ProductDeviceStatistics&version=1&product_id=7ubgKi1vhm</th></tr>
<tr><th>响应示例</th><td colspan="4">
{<br>
    "data": { <br>
         "unactive":6, // 未激活数<br>
        "online":0, // 在线数<br>
        "offline":8, // 离线数<br>
        "total":14 // 总数<br>
} <br>
    "requestId": "a25087f46df04b69b29e90ef0acfd115",<br> 
    "success": true<br>
}<br>
</th></tr>
</table>