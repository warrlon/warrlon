新增触发器
---
请求方式：**POST**

URL: http(s)://api.heclouds.com/triggers

[我只想看示例！！！](#1)

#### http请求参数
<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="15%">是否必须</th><th>说明</th></tr>
<tr><td>title</td><td>string</td><td>是</td><td>触发器名称</td></tr>
<tr><td>ds_id</td><td>string</td><td>否</td><td>可选，数据流名称，数据流名称,由{obj_id}_{obj_inst_id}_{res_id}组成</td></tr>
<tr><td>dev_ids</td><td>array-string</td><td>否</td><td>可选，设备ID</td></tr>
<tr><td>ds_uuids</td><td>array-string</td><td>否</td><td>可选，数据流uuid</td></tr>
<tr><td>url</td><td>string</td><td>是</td><td>告警通知地址</td></tr>
<tr><td>type</td><td>string</td><td>是</td><td>触发条件，见type说明列表</td></tr>
<tr><td>threshold</td><td></td><td>是</td><td>触发条件门限值，与type配合使用，见type说明列表</td></tr>
</table>

##### 参数说明

```text
1、触发器的含义是：当指定范围内的数据点满足触发条件的要求时，会向url参数指定的地址发送post请求；
2、触发器有三种工作触发模式
   1) 在请求参数中单独指定了ds_id，不包括其他参数，那么当前项目下所有设备的数据流中数据流名称符合ds_id的
数据都会进入触发判断逻辑；
   2) 在请求参数中单独指定了ds_uuids数组，那么只有这些指定的数据流会进入触发判断逻辑；
   3) 在请求参数中指定了ds_id和dev_ids，那么只有这些指定的设备的数据流会进入触发判断逻辑。
```

##### type说明列表 

<table>
<tr><th width="15%">type</th><th>说明</th></tr>
<tr><td>></td><td>threshold必须为数值</td></tr>
<tr><td><</td><td>threshold必须为数值</td></tr>
<tr><td>>=</td><td>threshold必须为数值</td></tr>
<tr><td><=</td><td>threshold必须为数值</td></tr>
<tr><td>inout</td><td>threshold设置为{"lolmt":40,"uplmt":52}，表示数据值进入或离开闭区间[40,52]时触发</td></tr>
<tr><td>change</td><td>threshold参数不用传递；当上传的值有改变时触发告警</td></tr>
<tr><td>frozen</td><td>threshold为数值，指定多少秒内未上报数据触发告警，同时被监控对象进入frozen状态</td></tr>
<tr><td>live</td><td>threshold为数值，指定多少秒后上报数据触发告警</td></tr>
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
<tr><td>trigger_id</td><td>int</td><td>触发器ID</td></tr>
</table>

<h4 id="1">请求头部示例</h4>

```text
POST http://api.heclouds.com/triggers HTTP/1.1
api-key: YHC**************VqKA=
```

#### 请求参数示例
```json
{
	"title": "trigger",
	"ds_id": "gps",
	"url": "http://aoic.choqf.com",
	"type": ">",
	"threshold": 100
}
```

#### 返回示例
```json
{
    "errno":0,
    "data": {
        "trigger_id":123809
    },
    "error":"succ"
}
```

#### 触发数据示例
```json
{
	"trigger": {
		"id": 123809,
		"threshold": 9.0,
		"type": ">"
	},
	"current_data": [{
			"dev_id": "2656",
			"ds_id": "gps",
			"ds_uuid": "FWEF-ZFW-ZFW-ZFWW",
			"at": "2009-09-07T12:16:02.001403Z",
			"value": 100
		}
	]
}
```

#### [< 查询设备历史命令](/book/application-develop/list/30query-dev-history-comm.md)
#### [<div style="text-align: right">更新触发器 ></div>](/book/application-develop/list/16update-trigger.md)