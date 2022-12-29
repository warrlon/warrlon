查看触发器
---
跳转到[批量查看](#2)

<h4 id="1">1.单个查看</h4>

请求方式：**GET**

URL: http(s)://api.heclouds.com/triggers/{trigger_id}

说明：trigger_id需要替换为设备ID。

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
<tr><td>id</td><td>string</td><td>触发器id</td></tr>
<tr><td>title</td><td>string</td><td>触发器名称</td></tr>
<tr><td>url</td><td>string</td><td>url</td></tr>
<tr><td>type</td><td>string</td><td>触发器类型</td></tr>
<tr><td>threshold</td><td>int</td><td>触发器值</td></tr>
<tr><td>invalid</td><td>bool</td><td>触发器是否已失效</td></tr>
<tr><td>create_time</td><td>string</td><td>设备触发器时间，北京时间</td></tr>
</table>

##### 说明

**触发器失效**是指触发器所依赖的数据流或者设备被删除了。此时触发器永远不会有效触发事件。

#### 请求示例
```text
GET http://api.heclouds.com/triggers/350092 HTTP/1.1
api-key: WhI*************v1c=
Content-Type: application/json
```

#### 返回示例
```json
{
	"errno": 0,
	"data": {
		"id":350092,
		"title":"we du jian kong",
		"url":"xx.bb.com",
		"type":">=",
		"threshold":45,
		"invalid":true,
		"create_time":"2018-04-24 10:22:22"
	},
	"error": "succ"
}
```

<h4 id="2">2.批量查看</h4>

请求方式：**GET**

URL: http(s)://api.heclouds.com/triggers

#### http头部

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="15%">是否必须</th><th>说明</th></tr>
<tr><td>api-key</td><td>string</td><td>是</td><td>必须为masterkey或者具备该设备访问权限的apikey</td></tr>
<tr><td>Content_Type</td><td>string</td><td>是</td><td>application/json</td></tr>
</table>

#### url参数

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="15%">是否必须</th><th>说明</th></tr>
<tr><td>title</td><td>string</td><td>否</td><td>指定触发器名称</td></tr>
<tr><td>page</td><td>int</td><td>否</td><td>指定页码</td></tr>
<tr><td>per_page</td><td>int</td><td>否</td><td>指定每页输出个数，默认为10个，最多100个</td></tr>
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
<tr><td>total_count</td><td>int</td><td>触发器总数</td></tr>
<tr><td>per_page</td><td>int</td><td>每页显示个数</td></tr>
<tr><td>page</td><td>int</td><td>页码</td></tr>
<tr><td>triggers</td><td>array-json</td><td>触发器的json数组，见triggers描述表</td></tr>
</table>

#### triggers描述表

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="70%">说明</th></tr>
<tr><td>id</td><td>string</td><td>触发器id</td></tr>
<tr><td>title</td><td>string</td><td>触发器名称</td></tr>
<tr><td>url</td><td>string</td><td>url</td></tr>
<tr><td>type</td><td>string</td><td>触发器类型</td></tr>
<tr><td>threshold</td><td>int</td><td>触发器值</td></tr>
<tr><td>invalid</td><td>bool</td><td>触发器是否已失效</td></tr>
<tr><td>create_time</td><td>string</td><td>设备触发器时间，北京时间</td></tr>
</table>

#### 说明

触发器失效是指触发器所依赖的数据流或者设备被删除了，此时触发器永远不会有效触发事件。

#### 请求示例

```text
GET http://api.heclouds.com/triggers?page=1&per_page=30 HTTP/1.1
api-key: WhI*************v1c=
Content-Type: application/json
```

#### 返回示例
```json
{
	"errno": 0,
	"data": {
		"total_count": 600,
		"per_page": 30,
		"page": 1,
		"triggers":[
			{
				"id":350092,
				"title":"we du jian kong",
				"url":"xx.bb.com",
				"type":">=",
				"threshold":45,
				"invalid":true,
				"create_time":"2018-04-24 10:22:22" 
			}
			{
				"id":350093,
				"title":"wen du jian kong",
				"url":"xx.bb.com",
				"type":">=",
				"threshold":45,
				"invalid":true,
				"create_time":"2018-04-24 10:22:22" 
			}
			...
		]
	},
	"error": "succ"
}
```

#### [< 更新触发器](/book/application-develop/list/16update-trigger.md)
#### [<div style="text-align: right">删除触发器 ></div>](/book/application-develop/list/18remove-trigger.md)