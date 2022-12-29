即时命令-命令下发
---
请求方式：**POST**

URL: http(s)://openapi.heclouds.com/LwM2M-online?action=execute

[我只想看示例！！！](#1)

#### url参数

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="15%">是否必须</th><th>说明</th></tr>
<tr><td>imei</td><td>string</td><td>是</td><td>nbiot设备的身份码</td></tr>
<tr><td>obj_id</td><td>int</td><td>是</td><td>nbiot设备的object id , 对应到平台模型中为数据流id，必填</td></tr>
<tr><td>obj_inst_id</td><td>int</td><td>是</td><td>设备object下具体一个instance的id ，对应到平台模型中数据点key值的一部分，必填</td></tr>
<tr><td>res_id</td><td>int</td><td>是</td><td>nbiot设备的资源id，必填</td></tr>
<tr><td>timeout</td><td>int</td><td>否</td><td>请求超时时间，默认25(单位：秒)，取值范围[5,40]</td></tr>
</table>

#### http请求参数

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="15%">是否必须</th><th>说明</th></tr>
<tr><td>args</td><td>string</td><td>是</td><td>命令字符串，大小限制2k</td></tr>
</table>

#### 返回参数
<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="70%">说明</th></tr>
<tr><td>errno</td><td>int</td><td>调用错误码，为0表示调用成功</td></tr>
<tr><td>error</td><td> string</td><td>错误描述，为"succ"表示调用成功</td></tr>
</table>

##### 说明

返回errno状态码所对应的含义，可以查看[API状态码](/book/api/LwM2M-IPSO/Error_codes.md)。

HTTP内容部分选填。

<h4 id="1">请求示例</h4>

```text
POST http://openapi.heclouds.com/LwM2M-online?action=execute HTTP/1.1
authorization: version=2020-05-29&res=userid%2F38055&et=1623982416&method=sha1&sign=S04GcvafYIjtAMHJthkGPevbNwE%3D
Content-Type:application/json

```

#### 请求参数示例
```json
{
	"args": "ping"  // 字符串
}// HTTP 内容部分选填。
```
#### 返回示例
```json
{
	"errno": 0,
	"error": "succ"
} //响应消息中 errno 表示错误码， error 表示错误原因。
```

#### [< 即时命令-写设备资源](/book/application-develop/list/5rt-write-device-resources.md)
#### [<div style="text-align: right">缓存命令-读设备资源 ></div>](/book/application-develop/list/9cache-read-dev-res.md)