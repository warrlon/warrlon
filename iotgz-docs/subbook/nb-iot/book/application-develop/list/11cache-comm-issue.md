缓存命令-命令下发/Execute
---
请求方式：**POST**

URL: http(s)://api.heclouds.com/nbiot/execute/offline

[我只想看示例！！！](#1)

#### url参数

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="15%">是否必须</th><th>说明</th></tr>
<tr><td>imei</td><td>string</td><td>是</td><td>设备模组IMEI，必填</td></tr>
<tr><td>obj_id</td><td>int</td><td>是</td><td>nbiot设备的object id , 对应到平台模型中为数据流id，必填</td></tr>
<tr><td>obj_inst_id</td><td>int</td><td>是</td><td>设备object下具体一个instance的id ，对应到平台模型中数据点key值的一部分，必填</td></tr>
<tr><td>res_id</td><td>int</td><td>是</td><td>nbiot设备的资源id，必填</td></tr>
<tr><td>valid_time</td><td>string</td><td>否</td><td>命令开始生效时间戳，可选（不填时默认为OneNET当前时间），填写必须大于OneNET服务器的当前时间</td></tr>
<tr><td>expired_time</td><td>string</td><td>是</td><td>命令过期时间戳，必填且大于valid_time</td></tr>
<tr><td>retry</td><td>int</td><td>否</td><td>[0-10]之间，表示失败重试次数（等待下一次设备update或者上线），可选（不填时默认为3），填写时必须在[0, 10]之间</td></tr>
<tr><td>timeout</td><td>int</td><td>否</td><td>过期时间，填写时必须在[5,40]s之间；不填写默认为25s</td></tr>
<tr><td>trigger_msg</td><td>int</td><td>否</td><td>命令触发的上行消息类型，填写时必须在[1,7]之间；不填写默认为7</td></tr>
</table>

#### http请求参数

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="15%">是否必须</th><th>说明</th></tr>
<tr><td>args</td><td>string</td><td>否</td><td>命令字符串，大小限制2k</td></tr>
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
<tr><td>uuid</td><td>string </td><td>缓存命令uuid</td></tr>
</table>

#### 说明
1、返回errno状态码所对应的含义，可以查看[API状态码](/book/application-develop/Error_codes.md)。

2、HTTP内容部分选填。
```
trigger_msg 触发类型：
1. REGISTER   
2. UPDATE   
3. REGISTER | UPDATE 组合  
4. NOTIFY
5. REGISTER | NOTIFY 组合
6. UPDATE | NOTIFY 组合
7. NOTIFY | UPDATE | REGISTER 组合
```

<h4 id="1">请求示例</h4>

```text
POST http://api.heclouds.com/nbiot/execute/offline?imei=86582003***&valid_time=2016-08-05T08:00:00&expired_time=2016-08-06T08:00:00&obj_id=1212&obj_inst_id=1212&res_id=123 HTTP/1.1
api-key: WhI*************v1c=  //必须为 MasterKey， 由于涉及个人隐私， 这里用“*******” 代替

```

#### 请求参数示例

```json
POST data
{
	"args":"ping" //字符串
} //HTTP 内容部分选填
```

#### 返回示例
```json
{
	"errno": 0,
	"data": {
		"uuid":"42742677-adc3-54ca-83a1-5aaaf71482f8" ////缓存命令uuid
	},
	"error": "succ"
} //响应消息中 errno表示错误码， error表示错误原因。
```

#### [< 缓存命令-写设备资源](/book/application-develop/list/10cache-write-dev-res.md)
#### [<div style="text-align: right">查看指定设备缓存命令列表 ></div>](/book/application-develop/list/12check-spe-dev-cache-comm-list.md)