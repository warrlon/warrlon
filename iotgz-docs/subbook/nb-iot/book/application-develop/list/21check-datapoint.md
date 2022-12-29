查看数据点
---
请求方式：**GET**

URL: http(s)://api.heclouds.com/devices/{device_id}/datapoints

说明：device_id需要替换为设备ID

[我只想看示例！！！](#1)

#### url参数

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="15%">是否必须</th><th>说明</th></tr>
<tr><td>datastream_id</td><td>string</td><td>否</td><td>数据流，多个数据流之间用逗号分隔</td></tr>
<tr><td>start</td><td>string</td><td>否</td><td>提取数据点的开始时间，格式：2015-01-10T08:00:35</td></tr>
<tr><td>end</td><td>string</td><td>否</td><td>提取数据点的结束时间，格式：2015-01-10T08:00:35</td></tr>
<tr><td>limit</td><td>int</td><td>否</td><td>限定本次请求最多返回的数据点的数量，取值>0,<=6000</td></tr>
<tr><td>cursor</td><td>string</td><td>否</td><td>指定本次请求继续从cursor位置开始提取数据</td></tr>
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
<tr><td>cursor</td><td>string</td><td>下一个数据点的位置</td></tr>
<tr><td>datastreams</td><td>array-json</td><td>设备数据流信息的json数组，见datastreams描述表</td></tr>
<tr><td>count</td><td>int</td><td>返回的数据流个数</td></tr>
</table>

#### datastreams描述表

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="70%">说明</th></tr>
<tr><td>id</td><td>string</td><td>数据流名称</td></tr>
<tr><td>datapoints</td><td>array-json</td><td>数据点的json数组，见datapoints描述表</td></tr>
<tr><td>statistic </td><td>json</td><td>数据流统计信息的json ，见statistic描述表</td></tr>
</table>

#### datapoints描述表

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="70%">说明</th></tr>
<tr><td>at</td><td>string</td><td>时间</td></tr>
<tr><td>value</td><td>string/array</td><td>数据点的值</td></tr>
</table>

##### statistic描述表

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="70%">说明</th></tr>
<tr><td>at</td><td>string</td><td>求最值时返回的一个最值时间点</td></tr>
<tr><td>value</td><td>string</td><td>数据点的值</td></tr>
</table>

#### 说明 

1. 不携带任何参数，直接调用，则返回本设备所存在的所有数据流中最新的数据。如果这个设备有三个数据流，则返回这三个数据流中每个数据流中最后一条数据。
2. 不携带数据流id参数，携带limit参数时，会返回该设备每个数据流最多limit条数据。
其中datastream_id等于obj_id_obj_inst_id_ res_id，如obj_id:3200，obj_inst_id:0，res_id:5501，那么这个datastream_id就为3200_0_5501。
3. 要查看某一条数据流在某个时间范围内的数据，可以在增加start和end参数。注意如果start参数存在，end参数不存在，表示取start后的所有数据；如果start不存在，end存在，设备云会忽略end参数。start和end之间的时间间隔最大为1年，超过一年会忽略。
4. 如果指定了start参数，则可能返回的数据点的数目会很多，此时默认会返回最多100个数据点。可以使用limit参数，设定返回多少个数据点，最大为6000个数据点。当实际的数据点数目多于limit限定的数目时，返回的json串中会有一个cursor字段，下一次请求的命令行中可以携带此cursor字段表示接着遍历本数据流。此cursor字段标识上次取出数据点后下一个数据点的位置。
 
<h4 id="1">请求示例</h4>

```text
GET http://api.heclouds.com/devices/564280/datapoints? datastream_id=3200_0_5501&start=2015-11-30T17:12:33&end=2015-12-01T17:22:33&limit=5&cursor=25971_564280_1448961024981 HTTP/1.1
api-key: WhI*************v1c=

```

#### 返回示例
```json
{
	"errno":0,
	"data":{
		"cursor":"25971_564280_1448961152173",
		"count":5,
		"datastreams":[
			{
				"datapoints":[
					{
						"at":"2015-12-01 17:10:24.981",
						"value":"35"
					},
					{
						"at":"2015-12-01 17:10:53.406",
						"value":"38"
					},
					...
				],
				"id":"3200_0_5501"
			},
			...
		]
	},
	"error":"succ"}
```

#### [< 批量查询设备最新数据](/book/application-develop/list/20batch-query-dev-latest-data.md)
#### [<div style="text-align: right">即时命令-读设备资源 ></div>](/book/application-develop/list/4rt-read-device-resources.md)