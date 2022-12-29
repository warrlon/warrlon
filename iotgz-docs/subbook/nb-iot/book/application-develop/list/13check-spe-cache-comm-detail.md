查看指定缓存命令详情
---
请求方式：**GET**

URL: http(s)://api.heclouds.com/nbiot/offline/history/{uuid}

说明：uuid为缓存命令ID

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
<tr><td>type</td><td>string</td><td>命令类型</td></tr>
<tr><td>args</td><td>json</td><td>type类型的接口http参数</td></tr>
<tr><td>content</td><td>json</td><td>type类型接口http内容</td></tr>
<tr><td>create_time</td><td>string</td><td>命令创建时间</td></tr>
<tr><td>valid_time</td><td>string</td><td>命令生效时间</td></tr>
<tr><td>expired_time</td><td>string</td><td>命令过期时间</td></tr>
<tr><td>send_time</td><td>string</td><td>命令下发时间</td></tr>
<tr><td>trigger_msg</td><td>int</td><td>命令触发的上行消息类型，范围为1~7有效</td></tr>
<tr><td>send_status</td><td>int</td><td>下发状态</td></tr>
<tr><td>confirm_time</td><td>string</td><td>响应时间</td></tr>
<tr><td>confirm_status</td><td>string</td><td>响应状态</td></tr>
<tr><td>cmd_result</td><td>json</td><td>type类型接口成功返回的json结果</td></tr>
<tr><td>feedback_msg</td><td>array</td><td>数据推送的详情，可能多个</td></tr>
<tr><td>imei</td><td>string</td><td>nbiot设备的身份码</td></tr>
<tr><td>remain</td><td>int</td><td>剩余重试次数</td></tr>
</table>

##### 说明
> send_status状态：
	1. 命令等待（wait）
	2. 命令取消（cancle）
	3. 命令已发往设备（send）
	4. 命令过期（expired）
	5. 命令下发成功（success）
	6. 命令下发失败（failed）
	8. 其他未知错误（undefined）
	
> confirm_status状态说明：
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

<h4 id="1">请求示例</h4>

```text
GET http://api.heclouds.com/nbiot/offline/history/10018?imei=86582003*** HTTP/1.1
api-key: WhI*************v1c=

```

#### 返回示例
```json
{
	"errno": 0,
	"error": "succ",
	"data":
		{
		"type":"READ",
		"args": {
      	// type类型接口http参数
		},
		"content": {
		// type类型接口http内容
		},
		"create_time":"2017-08-28 11:34:58",
		"valid_time":"2017-08-28 11:34:58",
		"expired_time":"2017-08-28 11:34:58",
		"send_time":"2017-08-28 11:34:58",
		"trigger_msg": 1,
		"send_status": 5,// 命令下发成功
		"confirm_time": "2017-08-28 11:34:58",
		// 命令响应结果，如果不是success，则没有cmd_result
		"confirm_status": "SUCCESS",
		//响应内容
		"cmd_result": {
           // type类型接口成功返回的json结果
		} ,
		"feedback_msg": [//数据推送详情
            {
                "feedback_time": "2019-02-28 13:50:43",
                "feedback_status": 0
            },
            {
                "feedback_time": "2019-02-28 13:50:43",
                "feedback_status": 0
            }
        ],
		"imei":"869975031234561",
		"remain":"3"//剩余重试次数
	}
}
```

#### [< 缓存命令-命令下发](/book/application-develop/list/11cache-comm-issue.md)
#### [<div style="text-align: right">查看指定缓存命令详情 ></div>](/book/application-develop/list/13check-spe-cache-comm-detail.md)