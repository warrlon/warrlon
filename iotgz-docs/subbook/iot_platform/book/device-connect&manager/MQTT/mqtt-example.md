
# MQTT 最佳实践

<a href="#1">1. 产品与设备创建</a>

<a href="#2">2. MQTT.fx客户端配置</a>

<a href="#3">3. 设备连接</a>

---

<h3 id="1">1. 产品与设备创建</h3>

创建产品，接入协议选择MQTT，并创建设备。

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/CoAP&MQTT/product-manager.png">
   
</center>

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/CoAP&MQTT/product-create.png">
</center>


在设备管理-设备详情里，查询设备相关参数，本例中，设备接入相关参数如下：

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/CoAP&MQTT/device-info.png">
</center>

<h3 id="2">2. MQTT.fx客户端配置</h3>
打开MQTT.fx客户端，进入客户端配置页面

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/CoAP&MQTT/mqttfx-connect.png">
</center>

设置Profile Name,设置接入地址与端口
（mqtt tls： 183.230.102.116:8883;  mqtt-notls：218.201.45.7:1883），并设置Client ID、User Name与Password，其中参数设置方式如下：
Client ID:设备名称
User Name：产品id 
Password：token

算法参见[接入安全认证](/book/device-connect&manager/device-auth.md)

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/CoAP&MQTT/mqttfx-set.png">
</center>

<h3 id="2">3. 设备连接</h3>

点击配置文件选择箭头，选择配置MQTT相应项目，点击conncent，此时，设备在页面处于在线状态。

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/CoAP&MQTT/mqttfx-online.png">
</center>

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/CoAP&MQTT/device-online.png">
</center>


#### 属性上报
##### 订阅属性上报结果通知消息
为了确保设备上传消息确实被平台所接受处理，设备可以订阅系统 topic 获取属性上报结果消息，属性上报回复topic为：$sys/{pid}/{device-name}/thing/property/post/reply

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/CoAP&MQTT/sub-property.png">
</center>


我们进入产品管理-详情页面，创建两个属性，分别为Power、temp，添加完成后保存物模型。

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/CoAP&MQTT/sub-property2.png">
</center>

属性上报的topic为：$sys/{pid}/{device-name}/thing/property/post
上报数据成功后，订阅的属性上报会返回success
OneJSON请求数据格式:
```json
{
    "id": "123",
    "version": "1.0",
    "params": {
        "Power": {
            "value": "12345",
            "time": 1599534283111
        },
        "temp": {
            "value": 23.6,
            "time": 1599534283111
        }   
    }
}
```
请求参数说明

| 参数 | 类型                 | 说明            |
| :------- | :----------      | :-------------- |
| id     | String | 消息id号，用户自定义，String类型的数字，长度限制13位。 |
| version     | String     | 物模型版本号，可选字段，不填默认为1.0   |
| params     | JsonObject    | 请求参数，用户自定义，标准json格式。如以上示例中，设备上报了的两个属性Power和WF。具体属性信息，包含属性上报时间（time）和上报的属性值（value）。  |
| time   | Long    | 属性值生成时间。该参数为可选字段，到豪秒级。根据您的业务场景决定消息中是否带时间戳。如果消息频繁，需根据时间戳判断消息顺序，建议消息中带有时间戳。   |
| value     | Object     | 上报的属性值   |

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/CoAP&MQTT/sub-property3.png">
</center>

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/CoAP&MQTT/sub-property4.png">
</center>

页面设备管理-设备详情，查看设备上报的属性数据。

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/CoAP&MQTT/sub-property5.png">
</center>


#### 设备属性设置
设备侧需要收到平台下发的数据，需要订阅：
$sys/{pid}/{device-name}/thing/property/set 

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/CoAP&MQTT/property-set.png">
</center>

在页面运维监控-设备调试中-下行数据调试，可进行设置设备属性。

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/CoAP&MQTT/property-set2.png">
</center>

topic: $sys/{pid}/{device-name}/thing/property/set_reply 
```json
{
"id": "2",
"code":200,
"msg":"success"
}
```
其中id为下行数据的id，需要匹配，code为200代表成功，msg可以自定义。

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/CoAP&MQTT/property-set3.png">
</center>

#### 事件上报
##### 订阅事件上报结果通知消息
为了确保事件上传消息确实被平台所接受处理，设备可以订阅系统 topic 获取事件上报结果消息，属性上报回复topic为：$sys/{pid}/{device-name}/thing/event/post/reply。
上报数据成功后，订阅的事件上报会返回success。

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/CoAP&MQTT/event.png">
</center>


我们进入产品管理-详情页面，创建1个事件（switch），包含两个参数（led1，led2，参数类型为整型）。

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/CoAP&MQTT/event2.png">
</center>

上报事件topic为：$sys/{pid}/{device-name}/thing/event/post
OneJSON请求数据格式:
```json
{
	"id": "123",
	"version": "1.0",
	"params": {
		"switch": {
			"value": {
				"led1": 22,
				"led2":23
			},
			"time": 1599534283111
		}
		
	}
}

```
请求参数说明

| 参数 | 类型                 | 说明            |
| :------- | :----------      | :-------------- |
| id     | String | 消息id号，用户自定义，String类型的数字，长度限制13位。 |
| version     | String     | 物模型版本号，可选字段，不填默认为1.0   |
| params     | JsonObject    | 上报事件的参数。  |
| time   | Long    | 属性值生成时间。该参数为可选字段，到豪秒级。根据您的业务场景决定消息中是否带时间戳。如果消息频繁，需根据时间戳判断消息顺序，建议消息中带有时间戳。   |
| value     | Object     | 具体的事件信息。|

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/CoAP&MQTT/event3.png">
</center>

页面设备管理-设备详情，查看设备上报的事件数据。

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/CoAP&MQTT/event4.png">
</center>


#### 订阅获取设备期望值topic

$sys/{pid}/{device-name}/thing/property/desired/get/reply
设备获取期望值：
$sys/{pid}/{device-name}/thing/property/desired/get
OneJSON数据格式:
```json
{
    "id" : "123",
    "version":"1.0",
    "params" : [
        "Power"
    ]
}
```
请求参数说明

| 参数 | 类型                 | 说明            |
| :------- | :----------      | :-------------- |
| id     | String | 消息id号，用户自定义，String类型的数字，长度限制13位。 |
| version     | String     | 物模型版本号，可选字段，不填默认为1.0   |
| params     | JsonObject    | 获取属性期望的标识符列表。  |

页面设置期望值：

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/CoAP&MQTT/desire-property.png">
</center>

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/CoAP&MQTT/desire-property2.png">
</center>

<center>
    <img style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);"
    src="/images/iot_platform/CoAP&MQTT/desire-property3.png">
</center>


