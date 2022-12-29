获取资源列表
---
请求方式：**GET**

URL: http(s)://openapi.heclouds.com/LwM2M-online?action=resources

[我只想看示例！！！](#1)

#### url参数

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="15%">是否必须</th><th>说明</th></tr>
<tr><td>imei</td><td>string</td><td>是</td><td>nbiot设备的身份码</td></tr>
<tr><td>obj_id</td><td>int</td><td>否</td><td>设备的objectid，根据终端设备sdk确定</td></tr>
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
<tr><td>total_count</td><td>int</td><td>返回的条目数</td></tr>
<tr><td>item </td><td>array-json</td><td>返回的条目详情，见item描述表</td></tr>
</table>

##### item描述表

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="70%">说明</th></tr>
<tr><td>obj_id</td><td>int</td><td>设备的object id，根据终端设备sdk确定</td></tr>
<tr><td>instances</td><td>array-json</td><td>obj_id对象下的实例条目，见instances描述表</td></tr>
</table>

##### instances描述表

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="70%">说明</th></tr>
<tr><td>inst_id</td><td>int</td><td>设备的instances id，根据终端设备sdk确定</td></tr>
<tr><td>resources</td><td>array-int</td><td>设备instances id下所有的资源列表</td></tr>
</table>

##### 说明

返回errno状态码所对应的含义，可以查看[API状态码](/book/api/LwM2M-IPSO/Error_codes.md)。

HTTP内容部分选填。

<h4 id="1">请求示例</h4>

```text
GET http://openapi.heclouds.com/LwM2M-online?action=resources?imei=***&obj_id=3200 HTTP/1.1
authorization: version=2020-05-29&res=userid%2F38055&et=1623982416&method=sha1&sign=S04GcvafYIjtAMHJthkGPevbNwE%3D

```

#### 返回示例

```json
{
	"errno": 0,
	"error": "succ",
	"data":{
    "total_count":123,
    "item":[
      	 {
         "obj_id":3200,
         "instances":[
            {
              "inst_id":0,
              "resources":[5500,5050]
            },
            {…},
            …
          ]
       },
       {……},
       ……
    ]
  }
} //响应消息中 errno 表示错误码， error 表示错误原因。
```

#### [< 新增设备](/book/application-develop/list/1create-device.md)
#### [<div style="text-align: right">更新设备信息 ></div>](/book/application-develop/list/28update-dev-info.md)