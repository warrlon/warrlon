# 账户下文件列表查询

<table>
<tr><th>方法</th><td colspan="4">GET</th></tr>
<tr><td>路径URI</td><td colspan="4">/application?action=GetDeviceFilesList&version=1</td></tr>
<tr><td>请求头</td><td colspan="4"></td></tr>
<tr><td>URL请求参数</td><td colspan="4">无</td></tr>
<tr><td>请求体参数</td><td colspan="4">无</td></tr>

<tr><td rowspan="15">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>调用成功时，返回的业务数据</td></tr>
<tr><td colspan="2">data.meta.total</td><td>number</td><td>文件数量</td></tr>
<tr><td colspan="2">data.meta.limit</td><td>number</td><td>每次请求的数据长度</td></tr>
<tr><td colspan="2">data.meta.offset</td><td>number</td><td>偏移量</td></tr>
<tr><td colspan="2">data.list.id<td>string</td><td>文件上传记录ID</td></tr>
<tr><td colspan="2">data.list.fid</td><td>string</td><td>文件ID</td></tr>
<tr><td colspan="2">data.list.name</td><td>string</td><td>文件名称</td></tr>
<tr><td colspan="2">data.list.file_size</td><td>number</td><td>文件大小</td></tr>
<tr><td colspan="2">data.list.created_time</td><td>string</td><td>文件创建时间</td></tr>
<tr><td colspan="2">data.list.device_name</td><td>string</td><td>文件所属设备名称</td></tr>
<tr><td colspan="2">data.list.product_id</td><td>string</td><td>文件所属设备的产品ID</td></tr>

<tr><th>请求示例</th><td colspan="4">GET /application?action=GetDeviceFilesList&version=1</th></tr>
</th></tr>
<tr><th>响应示例</th><td colspan="4">
{<br>
    "data": { <br>
        "meta": {<br>
            "limit": 10,<br>
            "offset": 0,<br>
            "total": 1<br>
        },<br>
        "list": [<br>
            {<br>
                "id": "574f7eab98eb7b5222911a",<br>
                "fid": "98cfa6be79574f7eab98eb7b5222911a",<br>
                "name": "28fpf.png",<br>
                "file_size": 138683,<br>
                "created_time": "2020-12-16T09:30:18.419Z",<br>
                "device_name": "ap-test-008",<br>
                "product_id": "Bs1f6s5bhKP7rmfO"<br>
            }<br>
        ]<br>
    } <br>
    "requestId": "a25087f46df04b69b29e90ef0acfd115", <br>
    "success": true<br>
}<br>
</th></tr>
</table>