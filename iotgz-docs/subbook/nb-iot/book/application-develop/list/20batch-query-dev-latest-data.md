批量查询设备最新数据
---
请求方式：**GET**

URL: http(s)://api.heclouds.com/devices/datapoints

[我只想看示例！！！](#1)

#### url参数

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="15%">是否必须</th><th>说明</th></tr>
<tr><td>devIds</td><td>string</td><td>是</td><td>设备ids，用逗号隔开，最多限制500个设备</td></tr>
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
<tr><td>devices</td><td>array-json</td><td>设备最新数据的json数组，见devices描述表</td></tr>
</table>

#### devices描述表

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="70%">说明</th></tr>
<tr><td>id</td><td>string</td><td>设备id</td></tr>
<tr><td>title</td><td>string</td><td>设备名称</td></tr>
<tr><td>datastreams</td><td>array-json</td><td>数据流的最新数据的json数组，见datastreams描述表</td></tr>
</table>

#### datastreams描述表

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="70%">说明</th></tr>
<tr><td>id</td><td>string</td><td>数据流名称</td></tr>
<tr><td>at</td><td>string</td><td>时间</td></tr>
<tr><td>value</td><td>string</td><td>最新数据值</td></tr>
</table>

<h4 id="1">请求示例</h4>

```text
GET http://api.heclouds.com/devices/datapoints?devIds=12323,12324 HTTP/1.1
api-key: WhI*************v1c=
Content-Type: application/json

```

#### 返回示例
```json
{
	"errno": 0,
	"data": {
		"devices":[
			{
				"id":12323,
				"title":"daf",
				"datastreams":[
					{
						"id":"temperature",
						"at":"2017-02-12 10:22:22",
						"value":"12"
					},
					...
				]
			},
			{
				"id":12324,
				"title":"daf",
				"datastreams":[
					{
						"id":"temperature",
						"at":"2017-02-12 10:22:22",
						"value":"15"
					},
					...
				]
			},
			...
		]
	},
	"error": "succ"
}
```

#### [< 删除设备](/book/application-develop/list/3remove-device.md)
#### [<div style="text-align: right">查看数据点 ></div>](/book/application-develop/list/21check-datapoint.md)