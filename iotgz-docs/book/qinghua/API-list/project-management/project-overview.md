# 项目管理

# 项目概况

<table>
<tr><td>方法</td><td colspan="4">GET</td></tr>
<tr><td>路径URI</td><td colspan="4">/application?action=QueryStatistics&version=1&project_id=ocgzVU</td></tr>
<tr><td>请求头</td><td colspan="4">Content-Type : application/json</td></tr>
<tr><td>URL参数</td><td>project_id</td><td>string</td><td>必填</td><td>项目id </td></td>

<tr><td>请求体</td><td colspan="4">无</td></tr>

<tr><td rowspan="22">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>object</td><td>调用成功时，返回的请求数据</td></tr>
<tr><td colspan="2">data.project</td><td>object</td><td>项目基础信息</td></tr>
<tr><td colspan="2">data.project. project_id</td><td>string</td><td>项目ID</td></tr>
<tr><td colspan="2">data.project. create_time</td><td>string</td><td>项目创建时间</td></tr>
<tr><td colspan="2">data.project. tag</td><td>string</td><td>自定义标签名称集合</td></tr>
<tr><td colspan="2">data.project. name</td><td>string</td><td>项目名称</td></tr>
<tr><td colspan="2">data.project.</td><td>string</td><td>项目描述</td></tr>
<tr><td colspan="2">desc</td><td></td><td></td></tr>
<tr><td colspan="2">data.project. category_name</td><td>string</td><td>行业类别名称</td></tr>
<tr><td colspan="2">data.project. category</td><td>string</td><td>行业类别ID </td></tr>
<tr><td colspan="2">data.product_count</td><td>int</td><td>集成产品总数</td></tr>
<tr><td colspan="2">data.device_count</td><td>int</td><td>集成设备总数</td></tr>
<tr><td colspan="2">data.online_count</td><td>int</td><td>在线设备总数</td></tr>
<tr><td colspan="2">data.activate_count</td><td>int</td><td>激活设备总数</td></tr>
<tr><td colspan="2">data.active_count</td><td>int</td><td>活跃设备总数</td></tr>
<tr><td colspan="2">data.product_aggregate</td><td>array</td><td>设备分布集合，如下的p表示product_aggregate数组的单个对象标识</td></tr>
<tr><td colspan="2">p. name</td><td>string</td><td>产品名称</td></tr>
<tr><td colspan="2">p. count</td><td>int</td><td>项目下产品设备总数</td></tr>

<tr><td>请求示例</td><td colspan="4">GET /application?action=QueryStatistics&version=1&project_id=ocgzVU</td></tr>
<tr><td>响应示例</td><td colspan="4">
{<br>
   "data":{<br>
        "project": {<br>
            "project_id": "ocgzVU",<br>
            "name": "智慧城市",<br>
            "desc": "",<br>
            "category": "A003",<br>
            "category_name": "智慧城市",<br>
            "create_time": "2020-06-19T08:18:01.483Z",<br>
            "project_id": "ocgzVU",V
            "tag": [<br>
                "智慧城市"<br>
            ]<br>
        },<br>
        "product_count": 1,<br>
        "device_count": 2,<br>
        "activate_count": 2,<br>
        "active_count": 2,<br>
        "online_count": 2,<br>
        "product_aggregate": [<br>
            "name": "智能烟感",<br>
            "count": 2<br>
         ]<br>
    },<br>
    "requestId": "a25087f46df04b69b29e90ef0acfd115", <br>
    "success": true<br>
}</td></tr><br>
</table>