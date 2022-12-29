# 项目集成设备列表

<table>
<tr><td>方法</td><td colspan="4">GET</td></tr>
<tr><td>路径URI</td><td colspan="4">/application?action=QueryDeviceList&version=1&project_id=ocgzVU</td></tr>
<tr><td>请求头</td><td colspan="4">Content-Type : application/json</td></tr>

<tr><td rowspan="7">URL参数</td><td>project_id</td><td>string</td><td>必填</td><td>项目id </td></td>
<tr><td>product_id</td><td>string</td><td>可选</td><td>产品ID</td></tr>
<tr><td>group_id</td><td>string</td><td>可选</td><td>分组ID</td></tr>
<tr><td>device_name</td><td>string</td><td>可选</td><td>设备名称</td></tr>
<tr><td>from</td><td>string</td><td>可选</td><td>设备来源 1-自主创建 2-他人转移</td></tr>
<tr><td>offset</td><td>string</td><td>可选</td><td>请求起始位置，默认0</td></tr>
<tr><td>limit</td><td>string</td><td>可选</td><td>每次请求记录数，默认10, 范围[1, 100]</td></tr>

<tr><td>请求体</td><td colspan="4">无</td></tr>

<tr><td rowspan="18">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>调用成功时, 返回业务数据</td></tr>
<tr><td colspan="2">data.list</td><td>array</td><td>产品信息集合，如下的l表示 list 数组的单个对象标识</td></tr>
<tr><td colspan="2">l. product_id</td><td>string</td><td>产品ID</td></tr>
<tr><td colspan="2">l.product_name</td><td>string</td><td>产品名称</td></tr>
<tr><td colspan="2">l.device_name</td><td>string</td><td>设备名称</td></tr>
<tr><td colspan="2">l.status</td><td>string</td><td>设备状态 1-未激活 2-在线 3-离线</td></tr>
<tr><td colspan="2">l.from</td><td>string</td><td>设备来源 1-自主创建 2-他人转移</td></tr>
<tr><td colspan="2">l. node_type</td><td>int</td><td>节点类型 1-直连设备</td></tr>
<tr><td colspan="2">l.created_time</td><td>string</td><td>创建时间</td></tr>
<tr><td colspan="2">l.last_time</td><td>string</td><td>最后一次在线时间</td></tr>
<tr><td colspan="2">data.meta</td><td>object</td><td>分页信息</td></tr>
<tr><td colspan="2">data.meta. limit</td><td>int</td><td>每次请求记录数</td></tr>
<tr><td colspan="2">data.meta.offset</td><td>int</td><td>请求记录起始位置</td></tr>
<tr><td colspan="2">data.meta.total</td><td>int</td><td>记录总数</td></tr>

<tr><td>请求示例</td><td colspan="4">GET  /application?action=QueryDeviceList&version=1&project_id=ocgzVU</td></tr>
<tr><td>响应示例</td><td colspan="4">
{<br>
    "data": {<br>
        "list": [<br>
             {<br>
                "product_id": "9MaNe52pNO",<br>
                "product_name": "空气净化器",<br>
                "node_type": 1,<br>
                "status": 1,<br>
                "device_name": "no001",<br>
                "from": 1,<br>
                "created_time": "2020-06-19T06:09:42.300Z",<br>
                "last_time": "0001-01-01T00:00:00.000Z"<br>
            },<br>
            {<br>
                "product_id": "9MaNe52pNO",<br>
                "product_name": "空气净化器",<br>
                "node_type": 1,<br>
                "status": 3,<br>
                "device_name": "no002",<br>
                "from": 1,<br>
                "created_time": "2020-06-19T06:09:22.550Z",<br>
                "last_time": "2020-06-19T09:48:15.027Z"<br>
            }<br>
        ],<br>
        "meta": {<br>
            "limit": 10,<br>
            "offset": 0,<br>
            "total": 2<br>
        }<br>
    },<br>
    "requestId": "a25087f46df04b69b29e90ef0acfd115", <br>
    "success": true<br>
}<br>
</td></tr>
</table>