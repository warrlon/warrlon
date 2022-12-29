# 更新设备信息

请求方式：**PUT**

URL: http(s)://api.heclouds.com/devices/{device_id}
 
说明：device_id需要替换为设备ID。

[我只想看示例！！！](#1)

#### http body参数

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="15%">是否必须</th><th>说明</th></tr>
<tr><td>title</td><td>string</td><td>否</td><td>设备名称</td></tr>
<tr><td>desc</td><td>string</td><td>否</td><td>设备描述</td></tr>
<tr><td>tags</td><td>array-string</td><td>否</td><td>设标签，可为一个或者多个，见示例</td></tr>
<tr><td>location</td><td>json</td><td>否</td><td>设备位置坐标信息，以经纬度键值对表示:{"lon":xx,"lat":xx}</td></tr>
<tr><td>private</td><td>bool</td><td>否</td><td>设备私密性，决定应用编辑器分享链接中设备信息的可见度，默认为true</td></tr>
<tr><td>auth_info</td><td>string</td><td>否</td><td>鉴权信息，建议携带，并设置为设备的产品序列号</td></tr>
<tr><td>other</td><td>json</td><td>否</td><td>其他设备自定义信息，以键值对格式表示，见示例</td></tr>
</table>

#### 返回参数

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="70%">说明</th></tr>
<tr><td>errno</td><td>int</td><td>调用错误码，为0表示调用成功</td></tr>
<tr><td>error</td><td> string</td><td>错误描述，为"succ"表示调用成功</td></tr>
</table>


<h4 id="1">请求参数示例</h4>

```json
{
	"title": "test_device",
	"desc": "test_desc",
	"tags": ["china", "mobile"],
	"location": {
		"lon": 109,
		"lat": 23.54
	},
	"auth_info": "tes01235n82105",
	"other": {
		"version": "1.0.0",
		"manufacturer": "china mobile"
	}
}
```

#### 返回示例
```json
{
	"errno": 0,
	"error": "succ"
}
```

#### [< 获取资源列表](/book/application-develop/list/7get-resource-list.md)
#### [<div style="text-align: right">查询设备详情 ></div>](/book/application-develop/list/2check-a-device.md)