新增acc_psk
---

请求方式：**POST**

URL:http(s)://api.heclouds.com/nbiot/device/accpsk


#### URL请求参数

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="15%">是否必须</th><th>说明</th></tr>
<tr><td>imei</td><td>string</td><td>是</td><td>URL中的请求参数，值为设备IMEI号</td></tr>
</table> 

#### http body 请求参数

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="15%">是否必须</th><th>说明</th></tr>
<tr><td>key</td><td>string</td><td>是</td><td>新增连接接入机的PSK，长度8-16个字节，字母或数字组成</td></tr>
</table> 

#### 返回参数

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="70%">说明</th></tr>
<tr><td>errno</td><td>int</td><td>调用错误码，为0表示调用成功</td></tr>
<tr><td>error</td><td> string</td><td>错误描述，为"succ"表示调用成功</td></tr>
</table>

#### 请求示例

```text
POST http://api.heclouds.com/devices HTTP/1.1
api-key: WhI*************v1c=
Content-Type: application/json
```

#### http请求参数示例

```json
{
	"key":"dafdfdsafd" 
}
```

#### 返回示例

```json
{
	"errno": 0,
	"error": "succ"
}
```

#### [< 更新bs_psk](/book/application-develop/list/24update-bs_psk.md)
#### [<div style="text-align: right">编辑acc_psk ></div>](/book/application-develop/list/26edit-acc_psk.md)
