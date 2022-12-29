批量查询设备状态
---
请求方式：**GET**

URL: http(s)://api.heclouds.com/devices/status

[我只想看示例！！！](#1)

#### url参数

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="15%">是否必须</th><th>说明</th></tr>
<tr><td>devIds</td><td>string</td><td>是</td><td>设备id，多个设备id用逗号隔开，限制1000个设备</td></tr>
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
<tr><td>total_count</td><td>int</td><td>总数</td></tr>
<tr><td>devices</td><td>array-json</td><td>设备状态的json数组，见devices描述表</td></tr>
</table>

#### devices描述表

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="70%">说明</th></tr>
<tr><td>id</td><td>string</td><td>设备id</td></tr>
<tr><td>title</td><td>string</td><td>设备名称</td></tr>
<tr><td>online</td><td>bool</td><td>在线状态</td></tr>
</table>

<h4 id="1">请求示例</h4>

```text
GET http://api.heclouds.com/devices/status?devIds=1221,12233,1123 HTTP/1.1
api-key: WhI*************v1c=
Content-Type: application/json
```

#### 返回示例
```json
{
	"errno": 0,
	"data": {
		"total_count":121,
		"devices":[
			{
				"id":1221,
				"title":"device1",
				"online":false
			},
			{
				"id":12333,
				"title":"device2",
				"online":true
			},
			...
		]
	},
	"error": "succ"
}
```

#### [< 批量查询设备信息](/book/application-develop/list/29batch-query-dev-info.md)
#### [<div style="text-align: right">根据IMEI查询设备信息 ></div>](/book/application-develop/list/22imei-query-dev-inf.md)