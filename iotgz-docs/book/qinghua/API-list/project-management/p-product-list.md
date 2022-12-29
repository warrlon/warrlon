# 项目集成产品列表

<table>
<tr><td>方法</td><td colspan="4">GET</td></tr>
<tr><td>路径URI</td><td colspan="4">/application?action=QueryProductList&version=1&project_id=ocgzVU</td></tr>
<tr><td>请求头</td><td colspan="4">Content-Type : application/json</td></tr>

<tr><td rowspan="3">URL参数</td><td>project_id</td><td>string</td><td>必填</td><td>项目id </td></td>
<tr><td>offset</td><td>string</td><td>可选</td><td>请求起始位置，默认0</td></tr>
<tr><td>limit</td><td>string</td><td>可选</td><td>每次请求记录数，默认10</td></tr>

<tr><td>请求体</td><td colspan="4">无</td></tr>

<tr><td rowspan="19">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>调用成功时, 返回业务数据</td></tr>
<tr><td colspan="2">data.list</td><td>array</td><td>产品信息集合，如下的l表示 list 数组的单个对象标识</td></tr>
<tr><td colspan="2">l. product_id</td><td>string</td><td>产品ID</td></tr>
<tr><td colspan="2">l. name</td><td>string</td><td>产品名称</td></tr>
<tr><td colspan="2">l. type</td><td>string</td><td>描述</td></tr>
<tr><td colspan="2">l. desc</td><td>string</td><td>项目名称</td></tr>
<tr><td colspan="2">l. protocol</td><td>int</td><td>协议 1-泛协议 2-MQTT 3-CoAP</td></tr>
<tr><td colspan="2">l. node_type</td><td>int</td><td>节点类型 1-直连设备</td></tr>
<tr><td colspan="2">l. data_type</td><td>int</td><td>数据类型 1-OneJson</td></tr>
<tr><td colspan="2">l. network</td><td>int</td><td>联网模式 1-其他 2-蜂窝 3-wifi 4-以太网</td></tr>
<tr><td colspan="2">l. device_number</td><td>string</td><td>设备总数</td></tr>
<tr><td colspan="2">data.meta</td><td>object</td><td>分页信息</td></tr>
<tr><td colspan="2">data.online_count</td><td>int</td><td>每次请求记录数</td></tr>
<tr><td colspan="2">data.meta.offset</td><td>int</td><td>请求记录起始位置</td></tr>
<tr><td colspan="2">data.meta.total</td><td>int</td><td>记录总数</td></tr>

<tr><td>请求示例</td><td colspan="4">GET /application?action=QueryProductList&version=1&project_id=ocgzVU</td></tr>
<tr><td>响应示例</td><td colspan="4">
{<br>
    "data": {<br>
        "list": [<br>
            {<br>
                "product_id": "9MaNe52pNO",<br>
                "name": "空气净化器",<br>
                "desc":  "智能家居空气净化器",<br>
                "type": 1,<br>
                "protocol":  2, <br>
                "node_type":  1,<br>
                "data_type":  1,<br>
                "network": 4, <br>
                "device_number": 2<br>
            }<br>
        ],<br>
        "meta": {<br>
            "limit": 10,<br>
            "offset": 0,<br>
            "total": 1<br>
        }<br>
    },<br>
    "requestId": "a25087f46df04b69b29e90ef0acfd115",<br> 
    "success": true<br>

}<br>
</td></tr>
</table>