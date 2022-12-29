# 分组列表

<table>
<tr><th>方法</th><td colspan="4">GET</th></tr>
<tr><td>路径URI</td><td colspan="4">/application?action=QueryGroupList&version=1&project_id=3C6Djy</td></tr>
<tr><td>请求头</td><td colspan="4">无</td></tr>

<tr><td rowspan="6">URL参数</td><td>project_id</td><td>string</td><td>必填</td><td>项目id </td></td>
<tr><td>name</td><td>string</td><td>可选</td><td>分组名称</td></tr>
<tr><td>key</td><td>string</td><td>可选</td><td>标签key（key、value需成对出现，否则没有效果）</td></tr>
<tr><td>value</td><td>string</td><td>可选</td><td>标签value（key、value 需成对出现，否则没有效果）</td></tr>
<tr><td>offset</td><td>string</td><td>可选</td><td>请求起始位置，默认0</td></tr>
<tr><td>limit</td><td>string</td><td>可选</td><td>每次请求记录数，默认10, </td></tr>
<tr><td>请求体</td><td colspan="4">无</td></tr>

<tr><td rowspan="17">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>调用成功时, 返回业务数据</td></tr>
<tr><td colspan="2">data.list</td><td>array</td><td>分组信息集合，如下的l表示 list 数组的单个对象标识</td></tr>
<tr><td colspan="2">l.project_id</td><td>string</td><td>项目id</td></tr>
<tr><td colspan="2">l.name</td><td>string</td><td>分组名称</td></tr>
<tr><td colspan="2">l.group_id</td><td>string</td><td>分组id</td></tr>
<tr><td colspan="2">l.key</td><td>string</td><td>分组key</td></tr>
<tr><td colspan="2">l.tag</td><td>object</td><td>标签信息,健值对</td></tr>
<tr><td colspan="2">l.created_time</td><td>string</td><td>创建时间</td></tr>
<tr><td colspan="2">l.device_count</td><td>int</td><td>设备数</td></tr>
<tr><td colspan="2">data.meta</td><td>object</td><td>分页信息</td></tr>
<tr><td colspan="2">data.meta. limit</td><td>int</td><td>每次请求记录数</td></tr>
<tr><td colspan="2">data.meta.offset</td><td>int</td><td>请求记录起始位置</td></tr>
<tr><td colspan="2">data.meta.total</td><td>int</td><td>记录总数</td></tr>

<tr><th>请求示例</th><td colspan="4">GET   /application?action=QueryGroupList&version=1&project_id=3C6Djy</th></tr>
<tr><th>响应示例</th><td colspan="4">
{<br>
    "data": {<br>
        "list": [<br>
            {<br>
                "project_id": "3C6Djy",<br>
                "name": "xq_group1",<br>
                "group_id": "qf6nAD",<br>
                "key": "ZDM0MzA4MTA3MjQ4NzdlYzZjOGJlYzU1YmUwZTNhMmY=",<br>
                "tag": {<br>
                    "xq": "123"<br>
                },<br>
                "created_time":"2020-08-13T01:49:17694,<br>
                "device_count": 2<br>
            }<br>
        ],<br>
        "meta": {<br>
            "limit": 10,<br>
            "offset": 0,<br>
            "total": 1<br>
        }<br>
    },<br>
    "requestId": "a25087f46df04b69b29e90ef0acfd115", <br>
    "success": true<br>
}<br>
</th></tr>
</table>
