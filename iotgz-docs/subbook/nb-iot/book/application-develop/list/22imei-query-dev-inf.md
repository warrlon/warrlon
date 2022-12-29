根据imei查询设备信息
---
请求方式：**GET**

URL: http(s)://api.heclouds.com/devices/getbyimei

[我只想看示例！！！](#1)

#### url参数

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="15%">是否必须</th><th>说明</th></tr>
<tr><td>imei</td><td>string</td><td>是</td><td>nbiot设备的身份码</td></tr>
</table>

#### 返回参数

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="70%">说明</th></tr>
<tr><td>errno</td><td>int</td><td>调用错误码，为0表示调用成功</td></tr>
<tr><td>error</td><td> string</td><td>错误描述，为"succ"表示调用成功</td></tr>
<tr><td>data</td><td>json</td><td>接口调用成功之后返回的设备相关信息，见data描述表</td></tr>
</table>

#### data描述表
<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="70%">说明</th></tr>
<tr><td>create_time</td><td>string</td><td>设备创建时间，北京时间</td></tr>
<tr><td>id</td><td>string</td><td>设备ID</td></tr>
<tr><td>online</td><td>bool</td><td>设备在线状态</td></tr>
<tr><td>observ_status</td><td>bool</td><td>订阅状态，表示：设备上线后，平台下发订阅命令，设备资源是否全部成功</td></tr>
<tr><td>title</td><td>string</td><td>设备名</td></tr>
<tr><td>desc</td><td>string</td><td>描述，若有则返回</td></tr>
</table>

<h4 id="1">请求示例</h4>

```text
GET http://api.heclouds.com/devices/getbyimei?imei=865***03 HTTP/1.1
api-key: WhI*************v1c=

```

#### 返回示例
```json
{
	"errno": 0,
	"error": "succ",
	"data": {
        "create_time": "2019-04-24 14:54:29",
        "online": false,
        "id": "5241665",
        "observe_status": false,
        "title": "xxxxxx"
	},
	"error": "succ"
}
```

#### [< 批量查询设备状态](/book/application-develop/list/19batch-query-dev-status.md)
#### [<div style="text-align: right">删除设备 ></div>](/book/application-develop/list/3remove-device.md)