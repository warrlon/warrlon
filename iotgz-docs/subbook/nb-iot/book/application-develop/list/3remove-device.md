删除设备
---
请求方式：**DELETE**

URL: http(s)://api.heclouds.com/devices/**_device_id_**

说明：device_id的值需要替换为设备ID。

[我只想看示例！！！](#1)

#### 返回参数

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="70%">说明</th></tr>
<tr><td>errno</td><td>int</td><td>调用错误码，为0表示调用成功</td></tr>
<tr><td>error</td><td>string </td><td>错误描述，为"succ"表示调用成功</td></tr>
</table>

<h4 id="1">请求示例</h4>

```text
DELETE http://api.heclouds.com/devices/35****92 HTTP/1.1
api-key: WhI*************v1c=  //MasterKey或者设备级别的Key，由于涉及个人隐私，这里用“*******” 代替
```

#### 返回示例
```json
{
	"errno": 0,
	"error": "succ"
} //响应消息中 errno 表示错误码， error 表示错误原因。
```

#### [< 根据IMEI查询设备信息](/book/application-develop/list/22imei-query-dev-inf.md)
#### [<div style="text-align: right">批量查询设备最新数据 ></div>](/book/application-develop/list/20batch-query-dev-latest-data.md)