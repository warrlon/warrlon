即时命令-资源订阅
---
请求方式：**POST**

URL: http(s)://api.heclouds.com/nbiot/observe

[我只想看示例！！！](#1)

#### url参数

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="15%">是否必须</th><th>说明</th></tr>
<tr><td>imei</td><td>string</td><td>是</td><td>nbiot设备的身份码，必填</td></tr>
<tr><td>cancel</td><td>bool</td><td>是</td><td>true为取消订阅，false为订阅，必填</td></tr>
<tr><td>obj_id</td><td>int</td><td>是</td><td>nbiot设备的object id , 对应到平台模型中为数据流id，必填</td></tr>
<tr><td>obj_inst_id</td><td>int</td><td>否</td><td>设备object下具体一个instance的id ，对应到平台模型中数据点key值的一部分，选填</td></tr>
<tr><td>res_id</td><td>int</td><td>否</td><td>nbiot设备的资源id，选填</td></tr>
<tr><td>pmin</td><td>int</td><td>否</td><td>上传数据的最小时间间隔，默认为0，此时有数据就上传</td></tr>
<tr><td>pmax</td><td>int</td><td>否</td><td>上传数据的最大时间间隔</td></tr>
<tr><td>gt</td><td>double</td><td>否</td><td>当数据值大于该值时上传</td></tr>
<tr><td>lt</td><td>double</td><td>否</td><td>当数据值小于该值时上传</td></tr>
<tr><td>st</td><td>double</td><td>否</td><td>当前后两个数据点值相差大于或者等于该值时</td></tr>
<tr><td>timeout</td><td>int</td><td>否</td><td>请求超时时间，默认25(单位：秒)，取值范围[5,40]</td></tr>
</table>

#### 返回参数

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="70%">说明</th></tr>
<tr><td>errno</td><td>int</td><td>调用错误码，为0表示调用成功</td></tr>
<tr><td>error</td><td> string</td><td>错误描述，为"succ"表示调用成功</td></tr>
</table>

##### 说明

1、返回errno状态码所对应的含义，可以查看[API状态码](/book/application-develop/Error_codes.md)。

2、pmin和pmax都存在时，pmax >= pmin且都需要大于0;

3、lt < gt, 并且lt + 2*st < gt；

4、如果有gt、lt、st，则res_id必填；

5、cancel为非 true|false将默认为false。

<h4 id="1">请求示例</h4>

```text
POST http://api.heclouds.com/nbiot/observe HTTP/1.1
api-key: WhI*************v1c=  //必须为 MasterKey， 由于涉及个人隐私， 这里用“*******” 代替
Content-Type:application/json
Authorization: version=2018-10-31&res=products/23104&et=1554398783&method=sha1&sign=fsBwuj0udOpU3BLoHmpbFwyIo30=
```

#### 请求参数示例

```json
{
	"imei":xxxx, // nbiot 设备的身份码， 由 15 位数字组成；
	"cancel":true|false, //true 为取消订阅， false 为订阅， 必填
	"obj_id":xxxx, // nbiot 设备的 object id , 对应到平台模型中为数据流 id， 必填
	"obj_inst_id": xxxx, //设备object下具体一个instance的 id ，对应到平台模型中数据点 key 值的一部分，选填
	"res_id": 123, // nbiot 设备的资源 id，选填
	"pmin":11, //上传数据的最小时间间隔 int 类型，默认为 0，此时有数据就上传
	"pmax":123,//上传数据的最大时间间隔，int 类型，可选
	"gt":12, //当数据大于该值上传，double 类型，可选
	"lt":233, // 当数据小于该值上传，double 类型，可选
	"st":12 //当两个数据点相差大于或者等于该值上传，double 类型，可选
}
```

#### 返回示例

```json
{
	"errno": 0,
	"error": "succ"
} //响应消息中 errno 表示错误码， error表示错误原因。
```

#### [< 即时命令-资源发现](/book/application-develop/list/31resource_discover.md)
#### [<div style="text-align: right">即时命令-读设备资源 ></div>](/book/application-develop/list/4rt-read-device-resources.md)