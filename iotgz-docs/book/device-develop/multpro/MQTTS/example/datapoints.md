# 接入实例-上传数据点

本文将通过实例介绍如何通过**MQTT.fx**进行设备数据点上传

[MQTT客户端下载](http://mqttfx.jensd.de/index.php/download)

## 准备条件
在上传数据点前，请完成产品与设备的创建，并进行设备连接，步骤参考[设备连接实例](/book/device-develop/multpro/MQTTS/example/connect.md)

本例中，设备接入相关参数如下：

<table>
<tr><th width="20%">产品ID</th><th width="30%">设备名称</th><th>设备key</th></tr>
<tr><td>238322</td><td>mqtts-test-device</td><td>EnW4T71eIE55xOIQMN6pFMKuqel5T5HTzsGJRPiDhlM=</td></tr>
</table>

## 上传数据点

### 订阅上传结果通知消息
为了确保设备上传消息确实被平台所接受处理，设备可以订阅系统 topic 获取上传数据点结果消息；

选择Subscribe项，输入订阅topic名称

> topic 命名规则如下：  
> $sys/**{pid}**/**{device-name}**/dp/post/json/+  
> 本例中，订阅topic为：  
> $sys/238322/mqtts-test-device/dp/post/json/+

点击 Subscribe，完成 topic 订阅
![](/images/MQTTS/订阅.png)

### 设备数据点上传

选择Publish项，输入发布 topic 
> topic 命名规则如下：    
> $sys/**{pid}**/**{device-name}**/dp/post/json  
> 本例中，发布 topic 名称为：  
> $sys/238322/mqtts-test-device/dp/post/json

payload示例如下：

```json
{
    "id": 123,        
    "dp": {             
        "temperatrue": [{     
            "v": 30,
        }],
        "power": [{     
            "v": 4.5,        
        }]
    }
}
```
![](/images/MQTTS/发布.png)

点击 **Publish**，上传数据点至平台

完成后，可以通过 **Subscribe**可以接收到平台下发的上传结果通知，若通过.../accepted topic接收到消息，则表明平台处理消息成功
![](/images/MQTTS/发布结果.png)

## 控制台查看数据

上传数据成功后，可以通过控制台 **设备列表** -> **数据流**，查看设备上传的数据点

![](/images/MQTTS/设备列表数据流.png)

![](/images/MQTTS/数据流.png)


## 更多帮助

[了解数据点topic簇的使用，见使用手册](/book/device-develop/multpro/MQTTS/topics/dp-topics.md)

