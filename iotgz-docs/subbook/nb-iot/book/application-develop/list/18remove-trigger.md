删除触发器
---
请求方式：**DELETE**

URL: http(s)://api.heclouds.com/triggers/{trigger_id}

说明：trigger_id为触发器ID。

#### 返回参数

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="70%">说明</th></tr>
<tr><td>errno</td><td>int</td><td>调用错误码，为0表示调用成功</td></tr>
<tr><td>error</td><td> string</td><td>错误描述，为"succ"表示调用成功</td></tr>
</table>

#### 请求示例

```text
DELETE http://api.heclouds.com/triggers/12***1 HTTP/1.1
api-key: WhI*************v1c=
Content-Type: application/json

```

#### 返回示例
```json
{
	"errno": 0,
	"error": "succ"
}
```

#### [< 查看触发器](/book/application-develop/list/17check-trigger.md)
#### [<div style="text-align: right">查看设备的bs_psk ></div>](/book/application-develop/list/23check-dev-bs_psk.md)