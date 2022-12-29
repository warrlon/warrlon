# 场景联动规则列表

<table>
<tr><th>方法</th><td colspan="4">GET</th></tr>
<tr><td>路径URI</td><td colspan="4">/application?action=QuerySceneRules&version=1&project_id=ocgzVU</td></tr>
<tr><td>URI</td><td colspan="4"></td></tr>
<tr><td>请求头</td><td colspan="4"></td></tr>

<tr><td rowspan="3">URL请求参数</td><td>project_id</td><td>string</td><td>必填</td><td>项目ID</td></td>
<tr><td>offset</td><td>string</td><td>可选</td><td>请求起始位置，默认0</td></tr>
<tr><td>limit</td><td>string</td><td>可选</td><td>每次请求记录数，默认10, 范围[1, 100]</td></tr>
<tr><td>请求体参数</td><td colspan="4">无</td></tr>

<tr><td rowspan="15">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>调用成功返回业务数据</td></tr>
<tr><td colspan="2">data.list</td><td>array</td><td>场景联动规则集合，如下的l表示 list 数组的单个对象标识</td></tr>
<tr><td colspan="2">l.name</td><td>string</td><td>规则名称</td></tr>
<tr><td colspan="2">l.scene_id</td><td>string</td><td>规则ID</td></tr>
<tr><td colspan="2">l.start</td><td>string</td><td>规则是否启用</td></tr>
<tr><td colspan="2">l.created_at</td><td>string</td><td>创建时间</td></tr>
<tr><td colspan="2">l.updated_at</td><td>string</td><td>更新时间</td></tr>
<tr><td colspan="2">data.meta</td><td>object</td><td>分页信息</td></tr>
<tr><td colspan="2">data.meta.limit</td><td>string</td><td>每次请求记录数</td></tr>
<tr><td colspan="2">data.meta.offset</td><td>string</td><td>请求记录起始位置</td></tr>
<tr><td colspan="2">data.meta.count</td><td>object</td><td>记录总数</td></tr>

<tr><th>请求示例</th><td colspan="4">GET /application?action=QuerySceneRules&version=1&project_id=ocgzVU</th></tr>
<tr><th>响应示例</th><td colspan="4">
{<br>
    "data": {<br>
        "list": [<br>
          {<br>
            "name": "联动测试",<br>
            "scene_id": "a25087f46df04b69b29e90ef0acfd115",<br>
            "start": true,<br>
            "created_at": "2020-05-20T01:37:45.187Z",<br>
            "updated_at": "2020-05-20T01:45:35.149Z"<br>
          }<br>
        ],<br>
        "meta": {<br>
          "count": 1,<br>
          "limit": 10,<br>
          "offset": 0<br>
        },<br>
    },<br>
    "requestId": "a25087f46df04b69b29e90ef0acfd115",<br> 
    "success": true<br>
}<br>
</th></tr>
</table>