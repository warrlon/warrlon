# **最佳实践**

# **MQTT 最佳实践**

#### 1. 产品与设备创建

创建产品，接入协议选择MQTT，并创建设备。

![产品列表](/images/device-management/mqtt-bestpractice/product_list.png)

<div align=center><img src ="/images/device-management/mqtt-bestpractice/product_add.png"/></div>

在设备管理-设备详情里，查询设备相关参数，本例中，设备接入相关参数如下：

![设备详情](/images/device-management/mqtt-bestpractice/device_info.png)

#### 2. MQTT.fx客户端配置 

打开MQTT.fx客户端，进入客户端配置页面。

![mqttfx-connect](/images/device-management/mqtt-bestpractice/mqttfx-connect.png)

设置Profile Name,设置接入地址与端口  。
````
（
    mqtt tls：iotjr.tsinghua.edu.cn:8883; 
    mqtt-notls：iotjr.tsinghua.edu.cn:1883
）
````

并设置Client ID、User Name与Password，其中参数设置方式如下：
  
<table>
<tr><td>Client ID</td><td width="70%">设备名称</td></tr>
<tr><td>User Name</td><td>产品id</td>
<tr><td>Password</td><td>token</td></tr>
</table>
 
算法参见[接入安全认证](/book/device-management/standard-access/security-auth/security.md)。

<div align=center><img src ="/images/device-management/mqtt-bestpractice/mqttfx-set.png"/></div>

#### 3. 设备连接 

点击配置文件选择箭头，选择配置MQTT相应项目，点击conncent，此时，设备在页面处于在线状态。

![mqttfx-online](/images/device-management/mqtt-bestpractice/mqttfx-online.png)

![device-online](/images/device-management/mqtt-bestpractice/device-online.png)

**属性上报**  

**订阅属性上报结果通知消息**  

为了确保设备上传消息确实被平台所接受处理，设备可以订阅系统 topic 获取属性上报结果消息。

>- 属性上报回复topic为：$sys/{pid}/{device-name}/thing/property/post/reply

![sub-property](/images/device-management/mqtt-bestpractice/sub-property.png)

我们进入产品管理-详情页面，创建两个属性，分别为Power、temp，添加完成后保存物模型。

![product-info](/images/device-management/mqtt-bestpractice/product-info.png)

>- 属性上报的topic为：$sys/{pid}/{device-name}/thing/property/post 

上报数据成功后，订阅的属性上报会返回success。

OneJSON请求数据格式:  

````json
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
````

表：请求参数说明

<table style="text-align: left">
    <tr style="background-color:#363636; color:#F0FFF0;">
        <td width="20%">参数</td>
        <td width="20%">类型</td>
        <td>说明</td>
    </tr>
    <tr>
        <td>id</td>
        <td>String</td>
        <td>消息id号，用户自定义，String类型的数字，长度限制13位</td>
    </tr>
    <tr>
        <td>version</td>
        <td>String</td>
        <td>物模型版本号，可选字段，不填默认为1.0</td>
    </tr>
    <tr>
        <td>params</td>
        <td>JsonObject</td>
        <td>请求参数，用户自定义，标准json格式。如以上示例中，设备上报了的两个属性Power和WF。具体属性信息，包含属性上报时间（time）和上报的属性值（value）</td>
    </tr>
    <tr>
        <td>time</td>
        <td>Long</td>
        <td>属性值生成时间。该参数为可选字段，到豪秒级。根据您的业务场景决定消息中是否带时间戳。如果消息频繁，需根据时间戳判断消息顺序，建议消息中带有时间戳</td>
    </tr>
    <tr>
        <td>value</td>
        <td>Object</td>
        <td>上报的属性值</td>
    </tr>
</table>

![sub-property3](/images/device-management/mqtt-bestpractice/sub-property3.png)

![sub-property4](/images/device-management/mqtt-bestpractice/sub-property4.png)

页面设备管理-设备详情，查看设备上报的属性数据。

![device-info](/images/device-management/mqtt-bestpractice/device-info.png)

**设备属性设置** 
 
>- 设备侧需要收到平台下发的数据，需要订阅：$sys/{pid}/{device-name}/thing/property/set  

![property-set](/images/device-management/mqtt-bestpractice/property-set.png)

在页面运维监控-设备调试中-设备模拟器调试，可进行设置设备属性。

![property-sb.png](/images/device-management/mqtt-bestpractice/property-sb.png)

>- topic: $sys/{pid}/{device-name}/thing/property/set_reply  

````json
{
    "id": "2",
    "code":200,
    "msg":"success"
}
````

其中id为下行数据的id，需要匹配，code为200代表成功，msg可以自定义。

![property-set3](/images/device-management/mqtt-bestpractice/property-set3.png)

**事件上报** 

**订阅事件上报结果通知消息** 

为了确保事件上传消息确实被平台所接受处理，设备可以订阅系统 topic 获取事件上报结果消息。
>- 属性上报回复topic为：$sys/{pid}/{device-name}/thing/event/post/reply

上报数据成功后，订阅的事件上报会返回success。  

![event](/images/device-management/mqtt-bestpractice/event.png)

我们进入产品管理-详情页面，创建1个事件（switch），包含两个参数（led1，led2，参数类型为整型）。

<div align=center><img src ="/images/device-management/mqtt-bestpractice/event2.png"/></div>

>- 上报事件topic为：$sys/{pid}/{device-name}/thing/event/post

OneJSON请求数据格式:  

````json
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
````

表：请求参数说明

<table style="text-align: left">
    <tr style="background-color:#363636; color:#F0FFF0;">
        <td width="20%">参数</td>
        <td width="20%">类型</td>
        <td>说明</td>
    </tr>
    <tr>
        <td>id</td>
        <td>String</td>
        <td>消息id号，用户自定义，String类型的数字，长度限制13位</td>
    </tr>
    <tr>
        <td>version</td>
        <td>String</td>
        <td>物模型版本号，可选字段，不填默认为1.0</td>
    </tr>
    <tr>
        <td>params</td>
        <td>JsonObject</td>
        <td>上报事件的参数</td>
    </tr>
    <tr>
        <td>time</td>
        <td>Long</td>
        <td>属性值生成时间。该参数为可选字段，到豪秒级。根据您的业务场景决定消息中是否带时间戳。如果消息频繁，需根据时间戳判断消息顺序，建议消息中带有时间戳</td>
    </tr>
    <tr>
        <td>value</td>
        <td>Object</td>
        <td>具体的事件信息</td>
    </tr>
</table>

![event3](/images/device-management/mqtt-bestpractice/event3.png)

页面设备管理-设备详情，查看设备上报的事件数据。

![event4](/images/device-management/mqtt-bestpractice/event4.png)

**订阅获取设备期望值topic** 

>- 订阅获取设备期望值topic：$sys/{pid}/{device-name}/thing/property/desired/get/reply  
>- 设备获取期望值：$sys/{pid}/{device-name}/thing/property/desired/get

OneJSON数据格式:  

````json
{
    "id" : "123",
    "version":"1.0",
    "params" : [
        "Power"
    ]
}
````

表：请求参数说明

<table style="text-align: left">
    <tr style="background-color:#363636; color:#F0FFF0;">
        <td width="20%">参数</td>
        <td width="20%">类型</td>
        <td>说明</td>
    </tr>
    <tr>
        <td>id</td>
        <td>String</td>
        <td>消息id号，用户自定义，String类型的数字，长度限制13位。</td>
    </tr>
    <tr>
        <td>version</td>
        <td>String</td>
        <td>物模型版本号，可选字段，不填默认为1.0</td>
    </tr>
    <tr>
        <td>params</td>
        <td>JsonObject</td>
        <td>获取属性期望的标识符列表。</td>
    </tr>
</table>

页面设置期望值：

![desire-property](/images/device-management/mqtt-bestpractice/desire-property.png)

![desire-property2](/images/device-management/mqtt-bestpractice/desire-property2.png)

![desire-property3](/images/device-management/mqtt-bestpractice/desire-property3.png)