# 数据点 topic 簇

MQTT物联网套件支持用户以**数据流-数据点**模型（[模型详情](/book/get-start/datastream&point.md)）将数据上传至平台并进行存储，设备可以通过数据点 topic 簇调用数据点存储服务存储数据，可以通过订阅系统 topic 获取数据处理结果通知，如下图所示：

![](/images/MQTTS/数据点topic簇.png)

数据点 topic 簇 topic 列表如下：

<table>
<tr><th width="45%">系统topic</th><th>用途</th><th width="8%">QoS</th><th width="10%">可订阅</th><th width="10%">可发布</th></tr>
<tr><td>$sys/{pid}/{device-name}/dp/post/json</td><td>设备上传数据点</td><td>0/1</td><td> </td><td>√</td></tr>
<tr><td>$sys/{pid}/{device-name}/dp/post/json/accepted</td><td>系统通知"设备上传数据点成功"</td><td>0</td><td>√</td><td></td></tr>
<tr><td>$sys/{pid}/{device-name}/dp/post/json/rejected</td><td>系统通知"设备上传数据点失败"</td><td>0</td><td>√</td><td></td></tr>
</table>


### 设备数据点上传

设备可以通过向系统固定 topic：$sys/{pid}/{device-name}/dp/post/json 发送数据点存储消息，消息中payload字段数据内容仅支持json格式，示例如下：

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
其中，参数说明如下：
<table>
<tr><th width="10%">参数</th><th width="10%">类型</th><th>是否必填</th><th width="60%">说明</th></tr>
<tr><td>id</td><td>int</td><td>是</td><td>消息ID，大于0的整数，数值范围为，4字节有符号数取值范围</td></tr>
<tr><td>dp</td><td>object</td><td>是</td><td>数据点内容，key-value格式，key为数据流名称，value为list格式的一个或者多个数据点值<br>上例中向temperatrue、power、status三个数据流中上传带时间戳的数据</td></tr>
<tr><td>v</td><td>-</td><td>是</td><td>数据点值，可以为int/float/string/object多种格式</td></tr>
<tr><td>t</td><td>int</td><td>否</td><td>数据点时间戳，unix时间，单位为秒，若不携带，则系统将以数据到达平台时间作为其数据时间</td></tr>
</table>


设备数据点上传，**支持 QoS1**，若 publish QoS=1，则平台回复 publish ack

### 平台通知上传结果

消息处理完成后，平台通过系统 topic 向设备发送上传结果通知，若设备订阅了该 topic，则能收到该消息

当上传数据处理成功时

返回消息至：$sys/${pid}/${device-name}/dp/post/json/**accepted** 

数据格式为：
```json
{
    "id": 123              //对应数据上报时的消息ID
}
```

当上传数据处理失败时

返回消息至：$sys/${pid}/${device-name}/dp/post/json/**rejected** 

若不能成功解析合法id，错误时，返回数据格式为：
```json
{
    "id": -1,             
    "err_code": 98,
    "err_msg":"Illegal Data"
}
```

若能成功解析合法id，由其他格式问题导致的错误，返回数据格式为：
```json
{
    "id": 123,            
    "err_code": 98,
    "err_msg":"Illegal Data"
}
```
#### 错误码

上传数据处理失败时，错误码如下：

|错误码 err_code |错误消息 err_msg |说明|
|:-|:-|:-|
|98 |Illegal Data |payload格式有误，平台解析失败|

## 更多帮助

[了解设备上传数据点的最佳实例](/book/example/datapoints.md)