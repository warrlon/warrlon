# 分组详情

<table>
<tr><th>方法</th><td colspan="4">GET</th></tr>
<tr><td>路径URI</td><td colspan="4">/application?action=QueryGroupDetail&version=1</td></tr>
<tr><td>请求头</td><td colspan="4">无</td></tr>

<tr><td rowspan="2">URL参数</td><td>project_id</td><td>string</td><td>必填</td><td>项目id </td></td>
<tr><td>group_id</td><td>string</td><td>必填</td><td>分组ID</td></tr>

<tr><td>请求体</td><td colspan="4">无</td></tr>

<tr><td rowspan="15">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>调用成功时, 返回业务数据</td></tr>
<tr><td colspan="2">data.active_time</td><td>string</td><td>激活时间</td></tr>
<tr><td colspan="2">data.online_count</td><td>string</td><td>上线次数</td></tr>
<tr><td colspan="2">data.project_id</td><td>string</td><td>分组所属的项目ID</td></tr>
<tr><td colspan="2">data.name</td><td>string</td><td>分组名称</td></tr>
<tr><td colspan="2">data.group_id</td><td>string</td><td>分组ID</td></tr>
<tr><td colspan="2">data.key</td><td>string</td><td>分组key</td></tr>
<tr><td colspan="2">data.tag</td><td>object</td><td>分组标签</td></tr>
<tr><td colspan="2">data.desc</td><td>string</td><td>分组描述</td></tr>
<tr><td colspan="2">data.device_count</td><td>string</td><td>设备数量</td></tr>
<tr><td colspan="2">data.create_time</td><td>string</td><td>创建时间</td></tr>
<tr><th>请求示例</th><td colspan="4">GET  /application?action=QueryGroupDetail&version=1</th></tr>

<tr><th>响应示例</th><td colspan="4">
{<br>
    "data": { <br>
        "activate_count": 0,<br>
        "online_count": 0,<br>
        "project_id": "3C6Djy",<br>
        "name": "xq_group1",<br>
        "group_id": "qf6nAD",<br>
        "key": "ZDM0MzA4MTA3MjQ4NzdlYzZjOGJlYzU1YmUwZTNhMmY=",<br>
        "tag": {<br>
            "xq": "123"<br>
        },<br>
        "desc": "123",<br>	
        "created_time": "2020-08-13T01:49:17.694Z",<br>
        "device_count": 2<br>
    } <br>
    "requestId": "a25087f46df04b69b29e90ef0acfd115",<br> 
    "success": true<br>
}<br>
</th></tr>
</table>