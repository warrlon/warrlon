更新触发器
---
请求方式：**PUT**

URL: http(s)://api.heclouds.com/triggers/{trigger_id}

说明：trigger_id为触发器ID

[我只想看示例！！！](#1)

#### http请求参数

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="15%">是否必须</th><th>说明</th></tr>
<tr><td>title</td><td>string</td><td>否</td><td>触发器名称</td></tr>
<tr><td>ds_id</td><td>string</td><td>否</td><td>可选，数据流名称，数据流名称,由{obj_id}_{obj_inst_id}_{res_id}组成</td></tr>
<tr><td>dev_ids</td><td>array-string</td><td>否</td><td>可选，设备ID</td></tr>
<tr><td>ds_uuids</td><td>array-string</td><td>否</td><td>可选，数据流uuid</td></tr>
<tr><td>url</td><td>string</td><td>否</td><td>url</td></tr>
<tr><td>type</td><td>string</td><td>否</td><td>触发类型</td></tr>
<tr><td>threshold</td><td>int</td><td>否</td><td>触发值</td></tr>
</table>


##### 参数说明
```text
1、触发器的含义是：当指定范围内的数据点满足触发条件的要求时，会向url参数指定的地址发送post请求；

2、触发器有三种工作触发模式
  1) 在请求参数中单独指定了ds_id，不包括其他参数，那么当前项目下所有设备的数据流中数据流名称符合ds_id
的数据都会进入触发判断逻辑；
  2) 在请求参数中单独指定了ds_uuids数组，那么只有这些指定的数据流会进入触发判断逻辑；
  3) 在请求参数中指定了ds_id和dev_ids，那么只有这些指定的设备的数据流会进入触发判断逻辑。
```

#### 返回参数

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="70%">说明</th></tr>
<tr><td>errno</td><td>int</td><td>调用错误码，为0表示调用成功</td></tr>
<tr><td>error</td><td> string</td><td>错误描述，为"succ"表示调用成功</td></tr>
</table>

##### 说明 

若要修改触发条件，必须同时设置type和threshold

<h4 id="1">请求头部示例</h4>

```text
PUT http://api.heclouds.com/triggers/350092 HTTP/1.1
api-key: WhI*************v1c=
Content-Type: application/json

```
#### 请求参数示例
```json
POST data
{
	"title":"wen du jian kong ",
	"ds_id": "gps",
	"url":"http://xx.wd.com",
	"type":"<=",
	"threshold":60
}
```

#### 返回示例
```json
{
	"errno": 0,
	"error": "succ"
}
```

#### [< 新增触发器](/book/application-develop/list/15add-trigger.md)
#### [<div style="text-align: right">查看触发器 ></div>](/book/application-develop/list/17check-trigger.md)