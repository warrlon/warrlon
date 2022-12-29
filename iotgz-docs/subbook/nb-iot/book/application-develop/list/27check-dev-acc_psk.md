查看设备acc_psk
---

请求方式：**GET**

URL: http(s)://api.heclouds.com/nbiot/device/accpsk

#### URL请求参数

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="15%">是否必须</th><th>说明</th></tr>
<tr><td>imei</td><td>string</td><td>是</td><td>URL中的请求参数，值为设备IMEI号</td></tr>
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
<tr><td>device_id</td><td>string</td><td>平台分配唯一ID</td></tr>
<tr><td>psk</td><td>string</td><td>设备连接接入机的psk，在NB协议开启DTLS加密功能时返回该字段，其他情况没有该字段</td></tr>
</table>

#### 请求示例

```text
POST http://api.heclouds.com/devices HTTP/1.1
api-key: WhI*************v1c=
Content-Type: application/json
```

#### 返回示例

```json
{
	"errno": 0,
	"error": "succ",
	"data": {
		"psk":"23ddafd3444"
	}
}
```

#### [< 编辑acc_psk](/book/application-develop/list/26edit-acc_psk.md)
