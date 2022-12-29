# 批量查询设备信息
请求方式：**GET**

URL: http(s)://api.heclouds.com/devices

[我只想看示例！！！](#1)

#### URL参数

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="15%">是否必须</th><th>说明</th></tr>
<tr><td>key_words</td><td>string</td><td>否</td><td>匹配关键字，从id和title字段中左匹配</td></tr>
<tr><td>auth_info</td><td>string</td><td>否</td><td>鉴权信息</td></tr>
<tr><td>tag</td><td>array-string</td><td>否</td><td>设备标签</td></tr>
<tr><td>online</td><td>bool</td><td>否</td><td>设备在线状态</td></tr>
<tr><td>private</td><td>bool</td><td>否</td><td>设备私密性</td></tr>
<tr><td>page</td><td>int</td><td>否</td><td>指定页码，最大页数为10000</td></tr>
<tr><td>per_page</td><td>int</td><td>否</td><td>指定每页输出设备个数，默认30，最多100</td></tr>
<tr><td>device_id</td><td>string</td><td>否</td><td>指定设备ID，多个用逗号分隔，最多100个</td></tr>
<tr><td>begin</td><td>string</td><td>否</td><td>起始时间，北京时间，示例：2019-10-01</td></tr>
<tr><td>end</td><td>string</td><td>否</td><td>结束时间，北京时间，示例：2019-10-01</td></tr>
</table>


#### 返回参数

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="70%">说明</th></tr>
<tr><td>errno</td><td>int</td><td>调用错误码，为0表示调用成功</td></tr>
<tr><td>error</td><td> string</td><td>错误描述，为"succ"表示调用成功</td></tr>
<tr><td>data</td><td>json</td><td>接口调用成功之后返回的设备相关信息，见data描述表</td></tr>
</table>

##### data描述表

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="70%">说明</th></tr>
<tr><td>total_count</td><td>int</td><td>查询结果中设备的数量</td></tr>
<tr><td>page</td><td>int</td><td>当前页码</td></tr>
<tr><td>per_page</td><td>int</td><td>每页设备数量</td></tr>
<tr><td>devices</td><td>array-json</td><td>设备信息的json数组，见devices描述表</td></tr>
</table>

#### devices描述表

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="70%">说明</th></tr>
<tr><td>protocol</td><td>string</td><td>设备接入协议</td></tr>
<tr><td>create_time</td><td>string</td><td>设备创建时间，北京时间</td></tr>
<tr><td>online</td><td>bool</td><td>设备在线状态</td></tr>
<tr><td>id</td><td>string</td><td>设备ID</td></tr>
<tr><td>auth_info</td><td>string</td><td>设备鉴权信息，对应设备注册接口中的"sn"或者"mac"参数</td></tr>
<tr><td>title</td><td>string</td><td>设备名</td></tr>
<tr><td>desc</td><td>string</td><td>设备描述</td></tr>
<tr><td>tags</td><td>array-string</td><td>设备标签</td></tr>
<tr><td>location</td><td>json</td><td>设备位置坐标信息，以经纬度键值对表示:{"lon":xx,"lat":xx}</td></tr>
<tr><td>other</td><td>json</td><td>其他设备自定义信息，以键值对格式表示，见示例</td></tr>
</table>

<h4 id="1">请求示例1</h4>

查询创建时间为2017-02-04至2017-06-04的标签为china的在线设备:

```text
GET http://api.heclouds.com/devices?begin=2017-02-04&end=2017-06-04&online=true&tag=china HTTP/1.1
```

#### 请求示例2

查询设备ID为35282992,35271941的两个设备:

```text
GET http://api.heclouds.com/devices?device_id=35282992,35271941 HTTP/1.1
```

#### 请求示例3

查询该产品下所有的设备:

```text
GET http://api.heclouds.com/devices HTTP/1.1
```

#### 返回示例
```json
{
	"errno": 0,
	"data": {
		"per_page": 30,
		"devices": [{
			"protocol": "EDP",
			"other": {
				"version": "1.0.0",
				"manufacturer": "china mobile"
			},
			"create_time": "2018-06-04 17:43:11",
			"online": true,
			"location": {
				"lat": 23.54,
				"lon": 109
			},
			"id": "35282992",
			"auth_info": "tes01235n82105",
			"title": "test_device",
			"desc": "test_desc",
			"tags": ["china", "mobile"]
		}, {
			"protocol": "EDP",
			"create_time": "2018-06-04 11:15:38",
			"online": true,
			"id": "35271941",
			"auth_info": "tes810372105",
			"title": "test_device",
			"tags": ["china"]
		}],
		"total_count": 2,
		"page": 1
	},
	"error": "succ"
}
```

#### [< 查询设备详情](/book/application-develop/list/2check-a-device.md)
#### [<div style="text-align: right">批量查询设备状态> </div>](/book/application-develop/list/19batch-query-dev-status.md)