新增设备
---

请求方式：**POST**

URL: http(s)://api.heclouds.com/devices

[我只想看示例！！！](#1)

#### http body 请求参数

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="15%">是否必须</th><th>说明</th></tr>
<tr><td>title</td><td>string</td><td>是</td><td>设备名称</td></tr>
<tr><td>desc</td><td>string</td><td>否</td><td>设备描述</td></tr>
<tr><td>tags</td><td>array-string</td><td>否</td><td>设备标签，字符串数组</td></tr>
<tr><td>protocol</td><td>string</td><td>是</td><td>接入协议，这里只能是LwM2M</td></tr>
<tr><td>location</td><td>json</td><td>否</td><td>设备位置（“纬度”，“经度”，“高度”）</td></tr>
<tr><td>private</td><td>bool</td><td>否</td><td>设备私密性（默认true)</td></tr>
<tr><td>auth_info</td><td>json</td><td>是</td><td>NBIOT设备：{“imei码”：“imsi码”}，imei、imsi规则见说明</td></tr>
<tr><td>auth</td><td>string</td><td>否</td><td>Auth_Code，由数字或字母组成，不超过16位</td></tr>
<tr><td>obsv</td><td>bool</td><td>否</td><td>是否订阅设备资源（默认为true）</td></tr>
<tr><td>other</td><td>json</td><td>否</td><td>其他信息（JSON格式，可自定义）</td></tr>
<tr><td>chip</td><td>int</td><td>否</td><td>测试设备与芯片类型对应关系（取值1-6），详情见说明</td></tr>
<tr><td>psk</td><td>string</td><td>否</td><td>DTLS加密所使用的PSK，长度8-16个字节，字母或数字组成</td></tr>
</table>

#### 返回参数

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="70%">说明</th></tr>
<tr><td>errno</td><td>int</td><td>调用错误码，为0表示调用成功</td></tr>
<tr><td>error</td><td> string</td><td>错误描述，为"succ"表示调用成功</td></tr>
<tr><td>data</td><td>json</td><td>接口调用成功之后返回的设备相关信息，见data描述表</td></tr>
</table>

##### data描述表

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="70%">说明</th></tr>
<tr><td>device_id</td><td>string</td><td>平台分配唯一ID</td></tr>
<tr><td>psk</td><td> string</td><td>在NB协议开启DTLS加密功能时返回该字段，其他情况没有该字段</td></tr>
</table>

#### 说明

<table>
<tr><th width="15%">分类</th><th width="15%">IMEI</th><th width="30%">IMSI</th><th width="10%">chip</th><th width="30%">备注</th></tr>
<tr><td>正式设备</td><td>15位数字</td><td>不超过15位数字，不为空</td><td>无 </td><td>正式设备无需chip值</td></tr>
<tr><td>测试设备</td><td>4位数字</td><td>不超过15位数字，不为空</td><td>取值1-6  </td><td>测试设备必须填写chip值</td></tr>
</table>

##### chip值对应表

chip取值 | 1 | 2  | 3 | 4 | 5 | 6 
:- | :- | :- | :- | :- | :- | :-
芯片名称 | MTK | 华为120 | 华为150 | 高通 | 中兴微 | RDA 

<h4 id="1">请求示例</h4>

```text
POST http://api.heclouds.com/devices HTTP/1.1
api-key: WhI*************v1c=   //必须为 MasterKey,由于涉及个人隐私,这里用“*******” 代替
Content-Type: application/json
```

#### http请求参数示例

```json
{
	"title": "mydevice", //设备名称
	"desc": "some description", //设备描述（可选）
	"tags": ["china", "mobile"], //设备标签（可选， 可为一个或多个）
	"protocol": "LwM2M", //接入协议
	"location": {"lon": 106, "lat": 29, "ele": 370}, //设备位置{"纬度", "精度", "高度"}（可选）
	"private": true, //设备私密性（可选， 默认为 ture）
	"auth_info": {"xxxxxxxxxxxx": "xxxxxxxxxxx"}, //NBIOT设备:{"imei" ："imsi"},imei（必须为15位）和imsi（不超过15位）都由数字组成，且首位不能为0
	"auth":"1233311",
	"obsv": true, //是否订阅设备资源,默认为true
	"other": {"version": "1.0.0", "manu": "china mobile"}, //其他信息（可选，JSON格式，可自定义）
	"chip":1, //参考chip值对应表
	"psk":"dafdfdsafd" 
}
```

#### 返回示例

```json
{
	"errno": 0, //无错误
	"data": {
		"device_id": "23444", //平台分配唯一ID
		"psk":"23ddafd3444"
	},
	"error": "succ"
}
```
&ggg;&ggg;&ggg;&ggg;&ggg;

说明：

(1) 响应消息中errno表示错误码，error表示错误原因，如果创建设备失败，则没有device_id字段；

(2) NB CoAP设备auth_info中imei（15位数字）和imsi（不超过15位数字，不为空）均由数字组成。

#### [<div style="text-align: right"> 获取资源列表 ></div>](/book/application-develop/list/7get-resource-list.md) 
