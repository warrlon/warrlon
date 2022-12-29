查询设备详情
---

请求方式：**GET**

URL: http(s)://api.heclouds.com/devices/{device_id}

说明：device_id的值需要替换为设备ID。

[我只想看示例！！！](#1)

#### 返回参数

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="70%">说明</th></tr>
<tr><td>errno</td><td>int</td><td>调用错误码，为0表示调用成功</td></tr>
<tr><td>error</td><td>string </td><td>错误描述，为"succ"表示调用成功</td></tr>
<tr><td>data</td><td> json</td><td>接口调用成功之后返回的设备相关信息，见data描述表</td></tr>
</table>

##### data描述表

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="70%">说明</th></tr>
<tr><td>id</td><td>string</td><td>平台分配的唯一ID</td></tr>
<tr><td>online</td><td>bool</td><td>表示LwM2M设备是否在线</td></tr>
<tr><td>protocol</td><td>string</td><td>设备接入协议（LwM2M)</td></tr>
<tr><td>title</td><td>string</td><td>设备名称</td></tr>
<tr><td>desc</td><td>string</td><td>设备描述</td></tr>
<tr><td>create_time</td><td>string</td><td>设备创建时间，北京时间</td></tr>
<tr><td>obsv</td><td>bool</td><td>是否自动订阅</td></tr>
<tr><td>private</td><td>bool</td><td>设备私密性</td></tr>
<tr><td>binary</td><td>json</td><td>设备关联的图像或者二进制数据，详情见binary描述表</td></tr>
<tr><td>tags</td><td>array-string</td><td>设备标签</td></tr>
<tr><td>obsv_st</td><td>bool</td><td>订阅状态，表示：设备上线后，平台下发自动订阅命令，设备资源是否全部成功</td></tr>
<tr><td>location</td><td>json</td><td>设备位置坐标信息，以经纬度键值对表示:{"lon":xx,"lat":xx}</td></tr>
<tr><td>auth_info</td><td>string</td><td>设备鉴权信息，对应设备注册接口中的"sn"或者"mac"参数</td></tr>
<tr><td>rg_id</td><td>string</td><td>Nbiot设备的endpoint name ( registration id)（目前对应于模组:  IMEI）</td></tr>
<tr><td>imsi</td><td>string</td><td>Nbiot设备当前IMSI</td></tr>
<tr><td>imsi_mt</td><td>datetime</td><td>Nbiot设备IMSI最新修改时间</td></tr>
<tr><td>ack</td><td>boolean</td><td>Nbiot设备IMSI更改通知状态（false：未通知用户，true：已经通知用户)</td></tr>
<tr><td>imsi_old</td><td>array[string]</td><td>Nbiot设备历史IMSI列表 （包括当前）</td></tr>
<tr><td>act_time</td><td>datetime</td><td>激活时间，即第一次在平台上线的时间</td></tr>
<tr><td>last_ct</td><td>datetime</td><td>最后连接服务器时间</td></tr>
<tr><td>manu_id</td><td>string</td><td>生产厂商名称，用户自定义，长度不超过32位</td></tr>
<tr><td>model</td><td>string</td><td> 型号名称，用户自定义，长度不超过32位</td></tr>
<tr><td>other</td><td>json</td><td>其他设备自定义信息，以键值对格式表示，见示例</td></tr>
<tr><td>datastreams</td><td>array-json</td><td>设备数据流信息的json数组，见datastreams描述表</td></tr>
</table>

##### binary描述表

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="70%">说明</th></tr>
<tr><td>index</td><td>string </td><td>二进制数据索引</td></tr>
<tr><td>at</td><td>string </td><td>上传时间</td></tr>
<tr><td>size</td><td>int </td><td>字节</td></tr>
<tr><td>desc</td><td>string </td><td>描述</td></tr>
</table>

##### datastreams描述表

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="70%">说明</th></tr>
<tr><td>id</td><td>string </td><td>数据流名称</td></tr>
<tr><td>create_time </td><td>string </td><td>数据流创建时间，北京时间</td></tr>
<tr><td>unit</td><td>string </td><td>单位</td></tr>
<tr><td>unit_symbol</td><td>string </td><td>单位符号</td></tr>
</table>

<h4 id="1">请求示例</h4>

```text
GET http://api.heclouds.com/devices/35****92 HTTP/1.1  //35****92为平台随机分配的设备ID
api-key: WhI*************v1c= //必须为 MasterKey， 由于涉及个人隐私，这里用“*******” 代替
```

#### 返回示例
```json
{
    "errno": 0,
    "data": { //设备信息
        "private": false, 
        "create_time": "2019-04-24 14:54:29", //设备创建时间
        "act_time": "Fri May 10 01:32:48 CST 2019",
        "obsv": true, //NB CoAP协议设备才有该字段值
        "ack": false,
        "auth_info": {
            "188xxxxxxxx": "1xxxxxx4"
        },
        "imsi": "188832xxxx234",
        "last_ct": "Fri Jun 21 17:06:32 CST 2019",
        "title": "11",
        "tags": [],
        "obsv_st": false,
        "protocol": "LwM2M",
        "rg_id": "188832963901234",
        "imsi_old": [
            "188832963901234"
        ],
        "imsi_mt": "Fri May 10 01:32:48 CST 2019",
        "online": false,
        "location": {
            "lat": 0,
            "lon": 0
        },
        "id": "524166559",
        "datastreams":  //数据流
         [   
            {
                "create_time": "2019-05-10 01:32:51",
                "uuid": "d2fd9428-45f3-45f9-bd17-7106432f22dd",
                "id": "9999_0_7"
            },
                   ],  //end data_streams
        "desc": ""
    }, //end data
    "error": "succ"
}	
```

#### [< 更新设备信息](/book/application-develop/list/28update-dev-info.md)
#### [<div style="text-align: right"> 批量查询设备信息 ></div>](/book/application-develop/list/29batch-query-dev-info.md) 