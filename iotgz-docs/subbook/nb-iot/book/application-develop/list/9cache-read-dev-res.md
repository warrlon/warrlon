缓存命令-读设备资源/Read
---
请求方式：**GET**

URL: http(s)://api.heclouds.com/nbiot/offline

[我只想看示例！！！](#1)

#### url参数

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="15%">是否必须</th><th>说明</th></tr>
<tr><td>imei</td><td>string</td><td>是</td><td>nbiot设备的身份码，必填</td></tr>
<tr><td>obj_id</td><td>int</td><td>是</td><td>设备的object id , 对应到平台模型中为数据流id，必填</td></tr>
<tr><td>obj_inst_id</td><td>int</td><td>否</td><td>nbiot设备object下具体一个instance的id ，对应到平台模型中数据点key值的一部分，选填</td></tr>
<tr><td>res_id</td><td>int</td><td>否</td><td>nbiot设备的资源id，选填</td></tr>
<tr><td>valid_time</td><td>string</td><td>否</td><td>命令开始生效时间，可选（不填时默认为OneNET当前时间），填写必须大于OneNET服务器的当前时间</td></tr>
<tr><td>expired_time</td><td>string</td><td>是</td><td>命令过期时间，必须大于valid_time</td></tr>
<tr><td>retry</td><td>int</td><td>否</td><td>表示失败重试次数（等待下一次设备update或者上线），可选（不填时默认为3），填写时必须在[0, 10]之间</td></tr>
<tr><td>timeout</td><td>int</td><td>否</td><td>过期时间，填写时必须在[5,40]s之间；不填写默认为25s</td></tr>
<tr><td>trigger_msg</td><td>int</td><td>否</td><td>命令触发的上行消息类型，填写时必须在[1,7]之间；不填写默认为7</td></tr>
<tr><td>bin2hex</td><td>boolean</td><td>否</td><td>true|false，默认false，如果bin2hex为true，资源类型为Opaque的值将被转换成十六进制字符串返回</td></tr>
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
<tr><td>uuid</td><td>string </td><td>缓存命令uuid</td></tr>
</table>

##### 说明

1、返回errno状态码所对应的含义，可以查看[API状态码](/book/application-develop/Error_codes.md)。

2、valid_time和expired_time格式为："2018-03-08T17:30:00"

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
GET http://api.heclouds.com/nbiot/offline HTTP/1.1
api-key:xxxx-ffff-zzzzz //必须为 MasterKey， 由于涉及个人隐私， 这里用“*******” 代替

```

#### 请求参数示例

```json
{
"imei":121,      // nbiot设备的身份码，必填
"obj_id":1212,         // 设备的object id , 对应到平台模型中为数据流id，必填
"obj_inst_id": 1212,    // nbiot设备object下具体一个instance的id ，对应到平台模型中数据点key值的一部分，选填
"res_id": 2122,        // nbiot设备的资源id，选填
"valid_time":"2018-03-08T17:30:00",// 命令开始生效时间，可选（不填时默认为OneNET当前时间），填写必须大于OneNET服务器的当前时间
"expired_time": "2018-03-09T17:30:00",// 命令过期时间，必填且大于valid_time
"retry":3,            // 表示失败重试次数（等待下一次设备update或者上线），可选（不填时默认为3），填写时必须在[3, 10]之间
"bin2hex": true// 可选，取值为true|false,默认false，如果bin2hex为true，资源类型为Opaque的值将被转换成十六进制字符串返回
}
```

#### 返回示例
```json
{
	"errno": 0,
	"error":"succ",
	"data":
		  {
		    "uuid":"42742677-adc3-54ca-83a1-5aaaf71482f8"//缓存命令uuid
		  }
} //响应消息中 errno 表示错误码，error 表示错误原因。
```

#### [< 即时命令-命令下发](/book/application-develop/list/6rt-comm-issue.md)
#### [<div style="text-align: right">缓存命令-写设备资源 ></div>](/book/application-develop/list/10cache-write-dev-res.md)