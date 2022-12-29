# 产品管理

# 产品详情

<table>
<tr><th>方法</th><td colspan="4">GET</th></tr>
<tr><td>路径URI</td><td colspan="4">/common?action=ProductDetail&version=1&product_id=10132</td></tr>
<tr><td>请求头</td><td colspan="4"></td></tr>
<tr><td rowspan="1">URL请求参数</td><td>product_id</td><td>string</td><td>必填</td><td>产品ID</td></td>
<tr><td>请求体参数</td><td colspan="4">无</td></tr>

<tr><td rowspan="18">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>调用成功返回业务数据</td></tr>
<tr><td colspan="2">data.device_number</td><td>number</td><td>设备数量</td></tr>
<tr><td colspan="2">data.product_id</td><td>string</td><td>产品ID</td></tr>
<tr><td colspan="2">data.name</td><td>string</td><td>产品名称</td></tr>
<tr><td colspan="2">data.desc</td><td>string</td><td>产品描述</td></tr>
<tr><td colspan="2">data.network</td><td>string</td><td>联网方式</td></tr>
<tr><td colspan="2">data.category</td><td>string</td><td>产品所属分类ID</td></tr>
<tr><td colspan="2">data.protocol</td><td>number</td><td>协议类型 1-泛协议 2-MQTT 3-CoAP</td></tr>
<tr><td colspan="2">data.scene</td><td>string</td><td>产品所属场景ID</td></tr>
<tr><td colspan="2">data.create_time</td><td>string</td><td>创建时间</td></tr>
<tr><td colspan="2">data.ind_title</td><td>string</td><td>产品行业名称</td></tr>
<tr><td colspan="2">data.prod_ind</td><td>string</td><td>产品行业编码</td></tr>
<tr><td colspan="2">data.uid</td><td>string</td><td>产品用户ID</td></tr>
<tr><td colspan="2">data.sec_key</td><td>string</td><td>产品权限key</td></tr>

<tr><th>请求示例</th><td colspan="4">GET /common?action=ProductDetail&version=1&product_id=10132</th></tr>
<tr><th>响应示例</th><td colspan="4">
{<br>
    "data": {<br>
        "device_number":0,<br>
        "protocol":2,<br>
        "created_time":"2021-12-06T08:28:56.762Z",<br>
        "product_id":"wjrJjSRtsG",<br>
        "network":"1",<br>
        "category":"138",<br>
        "scene":"82",<br>
        "ind_title":"智慧城市",<br>
        "prod_ind":"1",<br>
        "uid":37782,<br>
        "sec_key":"vC3eX2gr8mapsNZ1zYVmtsFRMYaX953GbJiKlcAQTp4=",<br>
        "desc":"",<br>
        "name":"物模型"<br>   
 },<br>
    "requestId": "a25087f46df04b69b29e90ef0acfd115",<br> 
    "success": true<br>
}<br>
</th></tr>
</table>
