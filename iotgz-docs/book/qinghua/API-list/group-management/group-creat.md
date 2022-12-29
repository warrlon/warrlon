# 分组管理

# 分组创建

<table>
<tr><th>方法</th><td colspan="4">POST</th></tr>
<tr><td>路径URI</td><td colspan="4">/application?action=CreateGroup&version=1</td></tr>
<tr><td>请求头</td><td colspan="4">Content-Type : application/json</td></tr>

<tr><td>URL参数</td><td colspan="4">无</td></tr>

<tr><td rowspan="3">请求体参数</td><td>project_id</td><td>string</td><td>必填</td><td>项目id </td></td>
<tr><td>name</td><td>string</td><td>必填</td><td>分组名称</td></tr>
<tr><td>desc</td><td>string</td><td>可选</td><td>分组描述</td></tr>

<tr><td rowspan="6">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>调用成功时, 返回业务数据</td></tr>
<tr><td colspan="2">data.group_id</td><td>string</td><td>分组ID</td></tr>

<tr><th>请求示例</th><td colspan="4">
{<br>
    "project_id": "3C6Djy",<br>
    "name": "黄河大道东",<br>
    "desc": "group 1"<br>
}<br>
</th></tr>
<tr><th>响应示例</th><td colspan="4">
{<br>
    "data": {<br>
        "group_id": "uwYqby"<br>
    },<br>
    "requestId": "a25087f46df04b69b29e90ef0acfd115",<br> 
    "success": true<br>
}<br>
</th></tr>
</table>