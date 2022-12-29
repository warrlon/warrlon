即时命令-写设备资源
---

请求方式：**POST**

URL: http(s)://openapi.heclouds.com/LwM2M-online?action=write

[我只想看示例！！！](#1)

#### url参数

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="15%">是否必须</th><th>说明</th></tr>
<tr><td>imei</td><td>string</td><td>是</td><td>nbiot设备的身份码</td></tr>
<tr><td>obj_id</td><td>int</td><td>是</td><td>设备的object id , 对应到平台模型中为数据流id，必填</td></tr>
<tr><td>obj_inst_id</td><td>int</td><td>是</td><td>nbiot设备object下具体一个instance的id ，对应到平台模型中数据点key值的一部分，必填</td></tr>
<tr><td>mode</td><td>int</td><td>是</td><td>write的模式，只能是1或者2</td></tr>
<tr><td>timeout</td><td>int</td><td>否</td><td>请求超时时间，默认25(单位：秒)，取值范围[5,40]</td></tr>
</table>


#### http请求参数

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="15%">是否必须</th><th>说明</th></tr>
<tr><td>data</td><td>array-json</td><td>是</td><td>写设备资源的json数组，大小限制2k，见data请求参数描述表</td></tr>
</table>

##### data描述表

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="15%">是否必须</th><th>说明</th></tr>
<tr><td>res_id</td><td>int</td><td>是</td><td>指定write操作的资源id</td></tr>
<tr><td>type</td><td>int</td><td>否</td><td>目前支持为1和2:<br>1代表该资源type为Opaque，此时val字段为该二进制对应的十六进制字符串；<br>2代表该资源type为Time，此时val字段为时间戳（单位为秒，数值）；不写代表该资源type为基础数据类型</td></tr>
<tr><td>val</td><td>object</td><td>是</td><td>根据指定资源的类型决定val的数值类型，可为boolean、string、long、double</td></tr>
</table>

#### 返回参数

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="70%">说明</th></tr>
<tr><td>errno</td><td>int</td><td>调用错误码，为0表示调用成功</td></tr>
<tr><td>error</td><td>string</td><td>错误描述，为"succ"表示调用成功</td></tr>
</table>

##### 说明

返回errno状态码所对应的含义，可以查看[API状态码](/book/api/LwM2M-IPSO/Error_codes.md)。

1、mode取值： 

（1）表示replace ，意为替换指定的instance或者resource的值 ; 

（2）表示partial update , 意为只更新给定的resource或者resource instace的值。

2、HTTP内容部分必须存在。

3、type字段可选，目前支持1和2，1代表该资源type为Opaque，此时val字段为该二进制对应的十六进制字符串；2代表该资源type为Time，此时val字段为时间戳（单位为秒，数值）

<h4 id="1">请求示例</h4>

```text
POST http://openapi.heclouds.com/LwM2M-online?action=write HTTP/1.1
authorization: version=2020-05-29&res=userid%2F38055&et=1623982416&method=sha1&sign=S04GcvafYIjtAMHJthkGPevbNwE%3D
Content-Type: application/json
```

#### 请求参数示例

```json
非opaque类型：
{
	"data":[
		{
			"res_id":12,
			"val":121
		}
	]
} //HTTP内容部分必须存在。

opaque类型：
{
    "data":[
        {
            "res_id":12,
			"type":1,
            "val":121
        }
    ]
} //HTTP内容部分必须存在。
```

#### 返回示例

```json
{
	"errno": 0,
	"error": "succ"
} //响应消息中 errno 表示错误码， error 表示错误原因。
```
#### [< 即时命令-读设备资源](/book/application-develop/list/4rt-read-device-resources.md)
#### [<div style="text-align: right">即时命令-命令下发 ></div>](/book/application-develop/list/6rt-comm-issue.md)