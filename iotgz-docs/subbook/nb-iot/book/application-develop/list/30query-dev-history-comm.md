# 查询设备历史命令
请求方式：**GET**

URL:http(s)://api.heclouds.com/cmds/history/{device_id}

说明：device_id需要替换为设备ID。

[我只想看示例！！！](#1)

#### URL参数

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="15%">是否必须</th><th>说明</th></tr>
<tr><td>start</td><td>date</td><td>是</td><td>查询的开始时间，格式示例：2019-10-10T08:00:35</td></tr>
<tr><td>end</td><td>date</td><td>否</td><td>查询的结束时间，格式示例：2019-10-10T08:00:35</td></tr>
<tr><td>page</td><td>int</td><td>否</td><td>指定页码</td></tr>
<tr><td>per_page</td><td>int</td><td>否</td><td>指定每页输出设备个数，默认30，最多100</td></tr>
</table>

#### HTTP请求返回参数

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="70%">说明</th></tr>
<tr><td>errno</td><td>int</td><td>调用错误码，为0表示调用成功</td></tr>
<tr><td>error</td><td> string</td><td>错误描述，为"succ"表示调用成功</td></tr>
<tr><td>data</td><td>json</td><td>接口调用成功之后返回的设备相关信息，见data描述表</td></tr>
</table>

#### data描述表

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="70%">说明</th></tr>
<tr><td>page</td><td>int</td><td>当前页码</td></tr>
<tr><td>per_page</td><td>int</td><td>当前每页总数</td></tr>
<tr><td>total_count</td><td>int</td><td>总数</td></tr>
<tr><td>items</td><td>array-json</td><td>设备历史命令相关信息，见items描述表</td></tr>
</table>

#### items描述表

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="70%">说明</th></tr>
<tr><td>cmd_uuid</td><td>string</td><td>命令ID</td></tr>
<tr><td>device_id</td><td>string</td><td>设备ID</td></tr>
<tr><td>expire_time</td><td>date</td><td>过期时间</td></tr>
<tr><td>status</td><td>int</td><td>命令状态</td></tr>
<tr><td>send_time</td><td>date</td><td>发送时间</td></tr>
<tr><td>confirm_time</td><td>date</td><td>响应时间</td></tr>
<tr><td>confirm_body</td><td>string</td><td>响应内容，16进制字符</td></tr>
<tr><td>body</td><td>string</td><td>请求内容，16进制字符</td></tr>
</table>

<h4 id="1">请求示例</h4>

```text
GET http://api.heclouds.com/cmds/history/3****78?start=2015-01-10T08:00:35 HTTP/1.1
```

#### 返回示例
```json
{
	"errno": 0,
	"error": "succ",
	"data": {
		"page": 1,
		"per_page": 10,
		"total_count": 100,
		"items": [{
				"cmd_uuid": "2302-312-21dgaapbafddfs",
				"device_id": 223422,
				"expire_time": "2016-07-05 00:00:00",
				"send_time": "2016-07-05 00:00:00",
				"confirm_time": "2016-07-05 00:00:00",
				"confirm_body": "2463726571007b202274797022",
				"body": " 2463726571007b202274797022"
			},{
				"cmd_uuid": "rezcgt2-se12-F2323Wdadfadfs",
				"device_id": 223422,
				"expire_time": "2016-07-05 01:01:01",
				"send_time": "2016-07-05 03:01:02",
				"confirm_time": "2016-07-05 02:02:02",
				"confirm_body": "2463726571007b202274797022",
				"body": " 2463726571007b202274797022"
			},{...}
		]
	}
}
```

#### [< 取消缓存命令](/book/application-develop/list/14cancel-cache-comm.md)
#### [<div style="text-align: right">新增触发器 ></div>](/book/application-develop/list/15add-trigger.md)
