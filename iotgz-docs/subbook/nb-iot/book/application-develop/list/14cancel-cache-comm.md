取消缓存命令
---
请求方式：**PUT**

URL: http(s)://api.heclouds.com/nbiot/offline/cancel/{uuid}

说明：uuid为缓存命令ID。

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
</table>

##### 说明
```
只有当命令处于wait状态才能取消，即命令valid_time没到期之前。
```

<h4 id="1">请求示例</h4>

```text
PUT http://api.heclouds.com/nbiot/offline/cancel/10018?imei=86582003*** HTTP/1.1
api-key: WhI*************v1c=

```

#### 返回示例
```json
{
	"errno": 0,
	"error": "succ"
}
```

#### [< 查看指定缓存命令详情](/book/application-develop/list/13check-spe-cache-comm-detail.md)
#### [<div style="text-align: right">查询设备历史命令 ></div>](/book/application-develop/list/30query-dev-history-comm.md)