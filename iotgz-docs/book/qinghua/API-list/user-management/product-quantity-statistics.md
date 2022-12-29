# 用户管理

# 用户下产品数量统计

<table>
<tr><th>方法</th><td colspan="4">GET</th></tr>
<tr><td>路径URI</td><td colspan="4">/common?action=ProductStatistics&version=1</td></tr>
<tr><td>请求头</td><td colspan="4"></td></tr>
<tr><td>URL请求参数</td><td colspan="4">无</td></tr>
<tr><td>请求体参数</td><td colspan="4">无</td></tr>

<tr><td rowspan="21">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>调用成功时，返回的业务数据</td></tr>
<tr><td colspan="2">data.product_aggregate.product_count</td><td>number</td><td>产品数量</td></tr>
<tr><td colspan="2">data.product_aggregate.ind_agg</td><td>array</td><td>数组对象，行业类型统计，如下的ind表示ind_agg数组的单个对象标识</td></tr>
<tr><td colspan="2">ind._id</td><td>string</td><td>行业ID（自动生成）</td></tr>
<tr><td colspan="2">ind.count/td><td>string</td><td>行业类别下产品数量</td></tr>
<tr><td colspan="2">ind.name</td><td>string</td><td>行业名称</td></tr>
<tr><td colspan="2">data.product_aggregate.pt_agg</td><td>array</td><td>数组对象，协议类型统计，如下的pt表示pt_agg数组的单个对象标识</td></tr>
<tr><td colspan="2">pt._id</td><td>string</td><td>协议ID（自动生成）</td></tr>
<tr><td colspan="2">pt.count</td><td>string</td><td>同一协议下产品数量</td></tr>
<tr><td colspan="2">pt.name</td><td>string</td><td>协议名称</td></tr>
<tr><td colspan="2">data.product_aggregate.net_agg</td><td>array</td><td>数组对象，联网类型统计，如下的net表示net_agg数组的单个对象标识</td></tr>
<tr><td colspan="2">net._id</td><td>string</td><td>联网类型ID（自动生成）</td></tr>
<tr><td colspan="2">net.name</td><td>string</td><td>联网类型名称</td></tr>
<tr><td colspan="2">data.product_aggregate.model_agg</td><td>array</td><td>数组对象，物模型类型统计，如下的model表示model_agg数组的单个对象标识</td></tr>
<tr><td colspan="2">model._id</td><td>string</td><td>物模型类型ID（自动生成)</td></tr>
<tr><td colspan="2">model.count</td><td>string</td><td>物模型类型下产品数量</td></tr>
<tr><td colspan="2">model.name</td><td>string</td><td>物模型类型名称</td></tr>

<tr><th>请求示例</th><td colspan="4">GET /common?action=ProductStatistics&version=1</th></tr>
</th></tr>
<tr><th>响应示例</th><td colspan="4">
{<br>
    "data": { <br>
          "product_aggregate":{<br>
            "ind_agg":[ // 行业类别<br>
                {<br>
                    "_id":"1",<br>
                    "count":7,<br>
                    "name":"智慧城市"<br>
                }<br>
            ],<br>
            "pt_agg":[ // 协议类型<br>
                {<br>
                    "_id":'sub',<br>
                    "count":1,<br>
                    "name":‘网关子设备’<br>
                },<br>
                {<br>
                    "_id":4,<br>
                    "count":2,<br>
                    "name":'LwM2M'<br>
                },<br>
                {<br>
                    "_id":2,<br>
                    "count":4,<br>
                    "name":"MQTT"<br>
                }<br>
            ],<br>
            "net_agg":[ // 联网型类型<br>
                {<br>
                    "_id":"1",<br>
                    "count":0,<br>
                    "name":"其他"<br>
                },<br>
                {<br>
                    "_id":"2",<br>
                    "count":0,<br>
                    "name":"蜂窝"<br>
                },<br>
                {<br>
                    "_id":"3",<br>
                    "count":5,<br>
                    "name":"wifi"<br>
                },<br>
                {<br>
                    "_id":"4",<br>
                    "count":0,<br>
                    "name":"以太网"<br>
                },<br>
                {<br>
                    "_id":"5",<br>
                    "count":1,<br>
                    "name":"NB"<br>
                }<br>
            ],<br>
            "model_agg":[ // 物模型类型<br>
                {<br>
                    "_id":"1",<br>
                    "count":2,<br>
                    "name":"标准"<br>
                },<br>
                {<br>
                    "_id":"2",<br>
                    "count":5,<br>
                    "name":"自定义"<br>
                }<br>
            ]<br>
        },<br>
        "product_count":7 // 总数<br>
}<br>
}<br>
    "requestId": "a25087f46df04b69b29e90ef0acfd115", <br>
    "success": true<br>
}<br>
</th></tr>
</table>