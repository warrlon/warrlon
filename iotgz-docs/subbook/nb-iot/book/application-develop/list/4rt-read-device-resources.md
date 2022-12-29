即时命令-读设备资源
---
请求方式：**GET**

URL: http(s)://api.heclouds.com/nbiot

[我只想看示例！！！](#1)

#### url参数

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="15%">是否必须</th><th>说明</th></tr>
<tr><td>imei</td><td>string</td><td>是</td><td>nbiot设备的身份码</td></tr>
<tr><td>obj_id</td><td>int</td><td>是</td><td>设备的objectid，对应到平台模型中为数据流id</td></tr>
<tr><td>obj_inst_id</td><td>int</td><td>否</td><td>nbiot设备object下具体一个instance的id ，对应到平台模型中数据点key值的一部分，选填</td></tr>
<tr><td>res_id</td><td>int</td><td>否</td><td> nbiot设备的资源id，选填</td></tr>
<tr><td>timeout</td><td>int</td><td>否</td><td>超时时间,可选,默认25秒，取值范围[5,40]</td></tr>
</table>

#### 返回参数

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="70%">说明</th></tr>
<tr><td>errno</td><td>int</td><td>调用错误码，为0表示调用成功</td></tr>
<tr><td>error</td><td>string </td><td>错误描述，为"succ"表示调用成功</td></tr>
<tr><td>data</td><td>array-json </td><td>接口调用成功之后返回的设备资源相关信息，见data描述表</td></tr>
</table>

##### data描述表

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="70%">说明</th></tr>
<tr><td>obj_inst_id</td><td>int</td><td>对象实例id</td></tr>
<tr><td>res</td><td>array-json </td><td>res列表</td></tr>
</table>

##### res描述表

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="70%">说明</th></tr>
<tr><td>res_id</td><td>int</td><td>资源id</td></tr>
<tr><td>val</td><td>object</td><td>读取资源的值，可以是bool,string,long,double等类型</td></tr>
</table>

##### 说明

返回errno状态码所对应的含义，可以查看[API状态码](/book/application-develop/Error_codes.md)。

obj_instance_id不存在的时候，resource_id必不存在。

<h4 id="1">请求示例</h4>

```text
GET http://api.heclouds.com/devices/nbiot?imei=**&obj_id=*** HTTP/1.1
api-key: WhI*************v1c=  //必须为 MasterKey， 由于涉及个人隐私， 这里用“*******” 代替
Authorization: version=2018-10-31&res=products/23104&et=1554398783&method=sha1&sign=fsBwuj0udOpU3BLoHmpbFwyIo30=

```

#### 返回示例
```json
{
	"errno": 0,
	"error": "succ",
	"data": [{
			"obj_inst_id":123,
			"res":[
					{
					"res_id":1234,
					"val": Object    //可为boolean、string、long、double类型数据
					},
					………
				]
			},
			………
			]
} //响应消息中 errno 表示错误码， error 表示错误原因。
```

#### [< 查看数据点](/book/application-develop/list/21check-datapoint.md)
#### [<div style="text-align: right">即时命令-写设备资源 ></div>](/book/application-develop/list/5rt-write-device-resources.md)