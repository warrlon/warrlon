# 设备列表

<table>
<tr><th>方法</th><td colspan="4">GET</th></tr>
<tr><td>路径URI</td><td colspan="4">/common?action=DeviceList&version=1</td></tr>
<tr><td>请求头</td><td colspan="4"></td></tr>

<tr><td rowspan="5">URL请求参数</td><td>name</td><td>string</td><td>可选</td><td>设备名称</td></td>
<tr><td>product_id</td><td>string</td><td>可选</td><td>产品ID</td></tr>
<tr><td>status</td><td>string</td><td>可选</td><td>设备状态，可选['1'未激活, '2'在线, '3'离线]</td></tr>
<tr><td>offset</td><td>string</td><td>可选</td><td>请求起始位置，默认0</td></tr>
<tr><td>limit</td><td>string</td><td>可选</td><td>每次请求记录数，默认10</td></tr>

<tr><td>请求体参数</td><td colspan="4">无</td></tr>

<tr><td rowspan="21">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>调用成功返回业务数据</td></tr>
<tr><td colspan="2">data.list</td><td>array</td><td>产品信息集合，如下的l表示 list 数组的单个对象标识</td></tr>
<tr><td colspan="2">l. product_id</td><td>string</td><td>产品ID</td></tr>
<tr><td colspan="2">l. name</td><td>string</td><td>设备名称</td></tr>
<tr><td colspan="2">l. node_type</td><td>number</td><td>节点类型1：直连设备，2：网关设备，3：网关子设备</td></tr>
<tr><td colspan="2">l. status</td><td>number</td><td>设备状态1：未激活，2：在线，3：离线 【默认为未激活】</td></tr>
<tr><td colspan="2">l. last_time</td><td>string</td><td>设备最后一次在线时间</td></tr>
<tr><td colspan="2">l. created_time</td><td>string</td><td>创建时间</td></tr>
<tr><td colspan="2">l. from</td><td>string</td><td>设备来源(1:自主创建，2:他人转移)</td></tr>
<tr><td colspan="2">l. lon</td><td>string</td><td>经度</td></tr>
<tr><td colspan="2">l. lat</td><td>string</td><td>纬度</td></tr>
<tr><td colspan="2">l. idid</td><td>string</td><td>设备ID</td></tr>
<tr><td colspan="2">l. product_name</td><td>string</td><td>产品名称</td></tr>
<tr><td colspan="2">data.meta</td><td>object</td><td>分页信息</td></tr>
<tr><td colspan="2">data.meta.limit</td><td>number</td><td>每次请求记录数</td></tr>
<tr><td colspan="2">data.meta.offset</td><td>number</td><td>请求记录起始位置</td></tr>
<tr><td colspan="2">data.meta.total</td><td>number</td><td>条数</td></tr>

<tr><th>请求示例</th><td colspan="4">GET /common?action=DeviceList&version=1</th></tr>
<tr><th>响应示例</th><td colspan="4">
{<br>
    "data": {<br>
          "list":[<br>
            {<br>
                "pid":"7ubgKi1vhm",<br>
                "name":"400A002090011001",<br>
                "ct":"2021-11-30T08:22:53.519Z",<br>
                "node_type":1,<br>
                "status":3,<br>
                "last_time":"2021-12-10T10:19:33.327Z",<br>
                "from":1,<br>
                "lon":"",<br>
                "lat":"",<br>
                "idid":"10015446",<br>
                "product_id":"7ubgKi1vhm",<br>
                "created_time":"2021-11-30T08:22:53.519Z",<br>
                "id":10015446,<br>
                "product_name":"水电费"<br>
            }<br>
        ],<br>        
"meta":{<br>
            "total":1,<br>
            "limit":10,<br>
            "offset":0<br>
        }<br>
 },<br>
    "requestId": "a25087f46df04b69b29e90ef0acfd115", <br>
    "success": true<br>
}<br>
</th></tr>
</table>