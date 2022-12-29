即时命令-资源发现
---
请求方式：**GET**

URL:http(s)://api.heclouds.com/nbiot/discover

[我只想看示例！！！](#1)

#### url参数

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="15%">是否必须</th><th>说明</th></tr>
<tr><td>imei</td><td>string</td><td>是</td><td>nbiot设备的身份码，必填</td></tr>
<tr><td>obj_id</td><td>int</td><td>是</td><td>nbiot设备的object id , 对应到平台模型中为数据流id，必填</td></tr>
<tr><td>obj_inst_id</td><td>int</td><td>否</td><td>设备object下具体一个instance的id ，对应到平台模型中数据点key值的一部分，选填</td></tr>
<tr><td>timeout</td><td>int</td><td>否</td><td>超时时间,可选,默认25秒，取值范围[5,40]</td></tr>
</table>


#### HTTP请求返回参数

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="70%">说明</th></tr>
<tr><td>errno</td><td>int</td><td>调用错误码，为0表示调用成功</td></tr>
<tr><td>error</td><td>string </td><td>错误描述，为"succ"表示调用成功</td></tr>
</table>

##### 说明
返回errno状态码所对应的含义，可以查看[API状态码](/book/application-develop/Error_codes.md)。

如果返回data是空数组，说明没有资源。

<h4 id="1">请求示例</h4>

```text
GET http://api.heclouds.com/nbiot/discover HTTP/1.1
api-key:xxxx-ffff-zzzzz，必须为masterKey
Authorization: version=2018-10-31&res=products/23104&et=1554398783&method=sha1&sign=fsBwuj0udOpU3BLoHmpbFwyIo30=
```

#### 返回示例
```json
{
	"errno": 0,
	"error": "succ",
	"data":[
		  {
		    "obj_inst_id":3,
			"res_id":[3, 2, 4]
		  },
		  {},
		  ……
		]
}
```

#### [< 查看数据点](/book/application-develop/list/21check-datapoint.md)
#### [<div style="text-align: right">即时命令-资源订阅 ></div>](/book/application-develop/list/8subscribe.md)
