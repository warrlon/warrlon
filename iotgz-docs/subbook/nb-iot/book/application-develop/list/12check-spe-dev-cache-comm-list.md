查看指定设备缓存命令列表
---
请求方式：**GET**

URL: http(s)://api.heclouds.com/nbiot/offline/history

[我只想看示例！！！](#1)

#### url参数

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="15%">是否必须</th><th>说明</th></tr>
<tr><td>imei</td><td>string</td><td>是</td><td>设备的imei号</td></tr>
<tr><td>start</td><td>string</td><td>是</td><td>指定开始时间，必填</td></tr>
<tr><td>end</td><td>string</td><td>否</td><td>指定结束时间，可选</td></tr>
<tr><td>page</td><td>int</td><td>否</td><td>当前页数</td></tr>
<tr><td>per_page</td><td>int</td><td>否</td><td>每页显示条数</td></tr>
<tr><td>sort</td><td>string</td><td>否</td><td>时间排序方式，DESC:降序，ASC升序，默认降序</td></tr>
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
<tr><td>total_count</td><td>int</td><td>缓存命令数</td></tr>
<tr><td>items</td><td>array-json</td><td>缓存命令的json数组，见item描述表</td></tr>
</table>

#### item描述表

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="70%">说明</th></tr>
<tr><td>cmd_uuid</td><td>string</td><td>缓存命令id</td></tr>
<tr><td>type</td><td>string</td><td>命令类型</td></tr>
<tr><td>create_time</td><td>string</td><td>命令创建时间</td></tr>
<tr><td>valid_time</td><td>string</td><td>命令生效时间</td></tr>
<tr><td>expired_time</td><td>string</td><td>命令过期时间</td></tr>
<tr><td>send_time</td><td>string</td><td>命令下发时间</td></tr>
<tr><td>send_status</td><td>int</td><td>下发状态</td></tr>
<tr><td>confirm_time</td><td>string</td><td>响应时间</td></tr>
<tr><td>confirm_status</td><td>string</td><td>响应状态</td></tr>
<tr><td>feedback_time</td><td>string</td><td>反馈时间</td></tr>
<tr><td>imei</td><td>string</td><td>nbiot设备的身份码</td></tr>
<tr><td>remain</td><td>int</td><td>剩余重试次数</td></tr>
</table>

##### 说明

send_time/confirm_time可能不存在。

> send_status状态：
	1. 命令等待（wait）
	2. 命令取消（cancle）
	3. 命令已发往设备（send）
	4. 命令过期（expired）
	5. 命令下发成功（success）
	6. 命令下发失败（failed）
	8. 其他未知错误（undefined）
	
> confirm_status状态：
	0. SUCCESS(命令执行成功)
	1. METHOD_NOT_ALLOWED（对象或资源不允许该操作） 
	2. FORBIDDEN（终端未注册）
	3. NOT_FOUND（未发现该对象或资源）
	4. INTERNAL_SERVER_ERROR（设备响应码错误等）
	5. TIME_OUT（设备响应超时）
	6. REQ_PARAM_ERROR（请求参数错误）
	7. RESP_ERROR（设备响应报文错误）
	8. UNAUTHORIZED（访问权限不允许）
	9. BAD_REQUEST（请求格式错误，如少参数或编码等）
	10. NOT_ACCEPTABLE（无任何首选的报文格式可以返回）
	11. UNSUPPORTED_CONTENT_FORMAT（指定的报文格式不支持）
	12. OFFLINE（设备未注册）
	13. ADDR_OCCUPIED（设备的地址被其他设备占用）

>trigger_msg 触发类型：
    1. REGISTER
	2. UPDATE
	3. REGISTER | UPDATE 组合
	4. NOTIFY
	5. REGISTER | NOTIFY 组合
	6. UPDATE | NOTIFY 组合
	7. NOTIFY | UPDATE | REGISTER 组合


<h4 id="1">请求示例</h4>

```text
GET http://api.heclouds.com/nbiot/offline/history?imei=86582003***&start=2016-08-05T08:00:00&end=2016-08-06T08:00:00&page=2&per_page=10 HTTP/1.1
api-key: WhI*************v1c= //必须为 MasterKey， 由于涉及个人隐私， 这里用“*******” 代替;
```

#### 返回示例

```json
{
	"errno": 0,
	"error": "succ",
	"data":
		{
		"total_count": 100,
		"items":
			[
			{
			"cmd_uuid":"f6869ecb-3dc1-5374-9be0-4fb961f8af3c ",
			"type":"READ", 
			"create_time":"2017-08-28 11:34:58",
			"valid_time":"2017-08-28 11:34:58",
			"expired_time":"2017-08-28 11:34:58",
			"send_time":"2017-08-28 11:34:58",
			"trigger_msg": 1,
			"send_status": 5,// 命令下发成功
			"confirm_time": "2017-08-28 11:34:58",
			"confirm_status": "SUCCESS",
			"feedback_time": "2019-02-28 13:50:43",
			"imei":"869975031234561",
			"remain":"3"//剩余重试次数
			}
			{…}
			]
		}
}

```

#### [< 查看指定设备缓存命令列表](/book/application-develop/list/12check-spe-dev-cache-comm-list.md)
#### [<div style="text-align: right">取消缓存命令 ></div>](/book/application-develop/list/14cancel-cache-comm.md)