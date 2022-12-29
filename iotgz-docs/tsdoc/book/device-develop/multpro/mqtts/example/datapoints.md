# Access Instance - Upload Data Point

This article will introduce how to upload device data point by ** MQTT. fx** through an example.

[MQTT client download](http://mqttfx.jensd.de/index.php/download)

## Preparatory conditions
Before uploading data points, complete the creation of products and devices, and connect devices. Step by step refer to[device connection instance](/book/device-development/multpro/MQTTS/example/connect.md)

In this example, the device access parameters are as follows:

<table>
<tr><th width="20%">产品ID</th><th width="30%">设备名称</th><th>设备key</th></tr>
<tr><td>238322</td><td>mqtts-test-device</td><td>EnW4T71eIE55xOIQMN6pFMKuqel5T5HTzsGJRPiDhlM=</td></tr>
</table>

## Upload data points

### Subscribe to Upload Result Notification Message
In order to ensure that the uploaded message is accepted and processed by the platform, the device can subscribe to the system top to get the uploaded data point result message.

Select the Subscribe entry and enter the name of the subscription topic

> Topic naming rules are as follows:
> $sys/**{pid}**/**{device-name}**/dp/post/json/+  
> In this case, the subscription topic is:
> $sys/238322/mqtts-test-device/dp/post/json/+

Click Subscribe to complete the topic subscription
![](/images/MQTTS/订阅.png)

### Device Data Point Upload

Select the Publish item and enter the publish topic
> Topic naming rules are as follows:
> $sys/**{pid}**/**{device-name}**/dp/post/json  
> In this case, the publish topic name is:
> $sys/238322/mqtts-test-device/dp/post/json

The payload example is as follows:

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

Click ** Publish ** to upload data points to the platform

Upload result notifications can be received through ** Subscribe ** and messages can be received through... / accepted topic, indicating that the platform has successfully processed the messages.
![](/images/MQTTS/发布结果.png)

## Console View Data

After uploading data successfully, you can view the data points uploaded by the device through the console ** device list ** - > ** data stream **.

![](/images/MQTTS/设备列表数据流.png)

![](/images/MQTTS/数据流.png)


## More help

[See the Manual for the Use of Topic Clusters for Data Points](/book/device-development/multpro/MQTTS/topics/dp-topics.md)