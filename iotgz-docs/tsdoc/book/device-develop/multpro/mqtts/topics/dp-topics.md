# Topic cluster of data points

OneNET supports users to upload data to the platform with ** data stream-data point** model ([model details](/book/easy-manual/datastream&point.md). Devices can call data point storage service through data point topic cluster to store data. Subscriber system Topic can get notifications of data processing results, as shown in the following figure:

![](/images/MQTTS/数据点topic簇.png)

The data point topic cluster topic list is as follows:

<table>
<tr><th width="45%">系统topic</th><th>用途</th><th width="8%">QoS</th><th width="10%">可订阅</th><th width="10%">可发布</th></tr>
<tr><td>$sys/{pid}/{device-name}/dp/post/json</td><td>设备上传数据点</td><td>0/1</td><td> </td><td>√</td></tr>
<tr><td>$sys/{pid}/{device-name}/dp/post/json/accepted</td><td>系统通知"设备上传数据点成功"</td><td>0</td><td>√</td><td></td></tr>
<tr><td>$sys/{pid}/{device-name}/dp/post/json/rejected</td><td>系统通知"设备上传数据点失败"</td><td>0</td><td>√</td><td></td></tr>
</table>


### Device Data Point Upload

The device can store messages by sending data points to the system by fixing the topic: $sys/{pid}/{device-name}/dp/post/json. The payload field data content in the message only supports JSON format. The example is as follows:

```json
{
    "id": 123,        
    "dp": {             
        "temperatrue": [{     
            "v": 30,       
            "t": 1552289676
        }],
        "power": [{     
            "v": 4.5,        
            "t": 1552289676 
        }],
        "status": [{
                "v": {
                    "color": "blue"
                },
                "t": 1552289677
            },
            {
                "v": {
                    "color": "red"
                },
                "t": 1552289678
            }
        ]
    }
}
```
Among them, the parameters are as follows:
<table>
<tr><th width="10%">参数</th><th width="10%">类型</th><th>是否必填</th><th width="60%">说明</th></tr>
<tr><td>id</td><td>int</td><td>是</td><td>消息ID，大于0的整数，数值范围为，4字节有符号数取值范围</td></tr>
<tr><td>dp</td><td>object</td><td>是</td><td>数据点内容，key-value格式，key为数据流名称，value为list格式的一个或者多个数据点值<br>上例中向temperatrue、power、status三个数据流中上传带时间戳的数据</td></tr>
<tr><td>v</td><td>-</td><td>是</td><td>数据点值，可以为int/float/string/object多种格式</td></tr>
<tr><td>t</td><td>int</td><td>否</td><td>数据点时间戳，unix时间，单位为秒，若不携带，则系统将以数据到达平台时间作为其数据时间</td></tr>
</table>


Device data point upload, ** supports QoS1**, if publish QoS = 1, the platform replies publish ack.

### Platform notification upload results

After the message processing is completed, the platform sends the upload result notification to the device through the system topic. If the device subscribes to the topic, it can receive the message.

When uploading data is successful

Return the message to: $sys/${pid}/${device-name}/dp/post/json/** accepted**

The data format is:
```json
{
    "id": 123              //对应数据上报时的消息ID
}
```

When upload data processing fails

Return the message to: $sys/${pid}/${device-name}/dp/post/json/** rejected**

If the valid ID ID ID cannot be parsed successfully, the return data format is:
```json
{
    "id": -1,             
    "err_code": 98,
    "err_msg":"Illegal Data"
}
```

If the valid ID ID ID can be parsed successfully, errors caused by other format problems will be returned in the following format:
```json
{
    "id": 123,            
    "err_code": 98,
    "err_msg":"Illegal Data"
}
```
#### Error code

When uploading data fails, the error codes are as follows:

| Error Code Er_code | Error Message Er_msg | Description|
|:-|:-|:-|
| 98 | Illegal Data | payload format error, platform parsing failed|