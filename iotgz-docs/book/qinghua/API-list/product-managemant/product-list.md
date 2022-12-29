# 产品列表

<table>
<tr><th>方法</th><td colspan="4">GET</th></tr>
<tr><td>路径URI</td><td colspan="4">/common?action=ProductList&version=1</td></tr>
<tr><td>请求头</td><td colspan="4"></td></tr>

<tr><td rowspan="6">URL请求参数</td><td>name</td><td>string</td><td>可选</td><td>产品名称</td></td>
<tr><td>manufacturer</td><td>string</td><td>可选</td><td>厂商名称</td></tr>
<tr><td>protocol</td><td>string</td><td>可选</td><td>接入协议，可选['1', '2', '3', '4', '5', '6', '7', '8', '9', '0']</td></tr>
<tr><td>industry</td><td>string</td><td>可选</td><td>行业类型编码</td></tr>
<tr><td>offset</td><td>string</td><td>可选</td><td>请求起始位置，默认0</td></tr>
<tr><td>limit</td><td>string</td><td>可选</td><td>每次请求记录数，默认10</td></tr>
<tr><td>请求体参数</td><td colspan="4">无</td></tr>

<tr><td rowspan="26">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>调用成功返回业务数据</td></tr>
<tr><td colspan="2">data.list</td><td>array</td><td>产品信息集合，如下的l表示 list 数组的单个对象标识</td></tr>
<tr><td colspan="2">l. total</td><td>number</td><td>设备数量</td></tr>
<tr><td colspan="2">l. category_name</td><td>string</td><td>分类名称</td></tr>
<tr><td colspan="2">l. scene_name</td><td>string</td><td>场景名称</td></tr>
<tr><td colspan="2">l. desc</td><td>string</td><td>描述</td></tr>
<tr><td colspan="2">l. protocol</td><td>number</td><td>协议 1-泛协议 2-MQTT 3-CoAP</td></tr>
<tr><td colspan="2">l. created_time</td><td>string</td><td>创建时间</td></tr>
<tr><td colspan="2">l. product_id</td><td>string</td><td>产品ID</td></tr>
<tr><td colspan="2">l. network</td><td>string</td><td>联网模式 1-其他 2-蜂窝 3-wifi 4-以太网</td></tr>
<tr><td colspan="2">l. category</td><td>string</td><td>分类ID</td></tr>
<tr><td colspan="2">l. scene</td><td>string</td><td>场景ID</td></tr>
<tr><td colspan="2">l. ind_title</td><td>string</td><td>产品行业名称</td></tr>
<tr><td colspan="2">l. prod_ind</td><td>string</td><td>产品行业编码</td></tr>
<tr><td colspan="2">l. l. uid</td><td>string</td><td>产品用户ID</td></tr>
<tr><td colspan="2">l. sec_key</td><td>string</td><td>产品权限KEY</td></tr>
<tr><td colspan="2">l. name</td><td>string</td><td>产品名称</td></tr>
<tr><td colspan="2">l. manufacturer</td><td>string</td><td>厂商名称</td></tr>
<tr><td colspan="2">data.meta</td><td>object</td><td>分页信息</td></tr>
<tr><td colspan="2">data.meta.limit</td><td>number</td><td>每次请求记录数</td></tr>
<tr><td colspan="2">data.meta.offset</td><td>number</td><td>请求记录起始位置</td></tr>
<tr><td colspan="2">data.meta.total</td><td>number</td><td>条数</td></tr>

<tr><th>请求示例</th><td colspan="4">GET /common?action=ProductList&version=1&product_id=wA10WBynvt</th></tr>
<tr><th>响应示例</th><td colspan="4">
{<br>
    "data": {<br>
         "list":[<br>
            {<br>
                "total":2,<br>
                "category_name":"智能后视镜",<br>
                "scene_name":"公共服务",<br>
                "protocol":4,<br>
                "created_time":"2021-08-31T08:00:12.846Z",<br>
                "product_id":"wA10WBynvt",<br>
                "network":"3",<br>
                "category":"326",<br>
                "scene":"14",<br>
                "ind_title":"智慧城市",<br>
                "prod_ind":"1",<br>
                "uid":5,<br>
                "sec_key":"RJKrcCGT22DYGSQ4KVXslu/Jnh3bezHzvhqCTFMk05Q=",<br>
                "desc":"",<br>
                "name":"qwe123",<br>
                "manufacturer":"S1234567890"<br>
            }<br>
        ],<br>
        "meta":{<br>
            "total":1,<br>
            "limit":10,<br>
            "offset":0<br>
        }<br>
 },<br>
    "requestId": "a25087f46df04b69b29e90ef0acfd115",<br> 
    "success": true<br>
}<br>
</th></tr>
</table>