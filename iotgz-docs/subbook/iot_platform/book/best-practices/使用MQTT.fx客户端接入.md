<a id="markdown-使用mqttfx做为客户端接入" name="使用mqttfx做为客户端接入"></a>
# 使用MQTT.fx做为客户端接入
<!-- TOC -->

- [使用MQTT.fx做为客户端接入](#使用mqttfx做为客户端接入)
  - [产品与设备创建](#产品与设备创建)
  - [MQTT.fx客户端配置](#mqttfx客户端配置)
  - [设备连接](#设备连接)
    - [属性上报](#属性上报)
      - [订阅属性上报结果通知消息](#订阅属性上报结果通知消息)
    - [设备属性设置](#设备属性设置)
    - [事件上报](#事件上报)
      - [订阅事件上报结果通知消息](#订阅事件上报结果通知消息)
    - [订阅获取设备期望值topic](#订阅获取设备期望值topic)

<!-- /TOC -->
<a id="markdown-产品与设备创建" name="产品与设备创建"></a>
## 产品与设备创建

创建产品，接入协议选择MQTT，并创建设备。

![img](/images/iot_platform/clip_image002.jpg)

![img](/images/iot_platform/clip_image004.jpg)

在设备管理-设备详情里，查询设备相关参数，本例中，设备接入相关参数如下：

![img](/images/iot_platform/clip_image006.jpg)

| 产品ID     | 设备名称 | 设备key                                      |
| ---------- | -------- | -------------------------------------------- |
| EJyXIoGn8p | test     | l3Vdt0EVyzPFR3kZs2XpQzn5v3Ht2VlvATmXxV0zdak= |

<a id="markdown-mqttfx客户端配置" name="mqttfx客户端配置"></a>
## MQTT.fx客户端配置

打开MQTT.fx客户端，进入客户端配置页面

![img](/images\iot_platform\clip_image008.jpg)

设置**Profile Name**,设置接入地址与端口，并设置**Client ID**、**User Name**与**Password**，其中参数设置方式如下：

**Client ID:设备名称(本例为：test)
User Name：产品id (本例为：**_EJyXIoGn8p_**)
Password：token（本例为：version=2018-10-31&res=products%2FEJyXIoGn8p%2Fdevices%2Ftest&et=1596067735&method=md5&sign=KjQ3tFpNOHv6Cm2rLjDV%2FA%3D%3D)**

**算法链接为：**[https://open.iot.10086.cn/doc/mqtt/book/manual/auth/introduce.html](https://open.iot.10086.cn/doc/mqtt/book/manual/auth/introduce.html)

![image-2020070114432images\iot_platform\image-20200701144320387.png)

<a id="markdown-设备连接" name="设备连接"></a>
## 设备连接

点击配置文件选择箭头，选择配置*MQTT**相应项目，点击**conncent**，此时，设备在页面处于在线状态。*

![img](/images/iot_platform/clip_image012.jpg)

![img](/images/iot_platform/clip_image014.jpg)

<a id="markdown-属性上报" name="属性上报"></a>
### 属性上报

<a id="markdown-订阅属性上报结果通知消息" name="订阅属性上报结果通知消息"></a>
#### 订阅属性上报结果通知消息

为了确保设备上传消息确实被平台所接受处理，设备可以订阅系统 topic 获取属性上报结果消息，属性上报回复topic为：$sys/{pid}/{device-name}/thing/property/post/reply

本例中topic为：$sys/EJyXIoGn8p/test/thing/property/post/reply

![img](/images/iot_platform/clip_image016.jpg)

我们进入产品管理-详情页面，创建两个属性，分别为Power、temp。

![img](/images/iot_platform/clip_image018.jpg)

属性上报的topic为：$sys/{pid}/{device-name}/thing/property/post

本例中为：$sys/EJyXIoGn8p/test/thing/property/post

上报数据成功后，订阅的属性上报会返回success

OneJSON请求数据格式:

```json
{
    "id":"123",
    "version":"1.0",
    "params":{
        "Power":{
            "value":"12345",
            "time":1524448722123
        },
        "temp":{
            "value":23.6,
            "time":1524448722123
        }
    }
}
```

表：请求参数说明

| 参数    | 类型       | 说明                                                                                                                                               |
| ------- | ---------- | -------------------------------------------------------------------------------------------------------------------------------------------------- |
| id      | String     | 消息id号，用户自定义，String类型的数字，长度限制13位。                                                                                             |
| version | String     | 物模型版本号，可选字段，不填默认为1.0                                                                                                              |
| params  | JsonObject | 请求参数，用户自定义，标准json格式。如以上示例中，设备上报了的两个属性Power和WF。具体属性信息，包含属性上报时间（time）和上报的属性值（value）。   |
| time    | Long       | 属性值生成时间。该参数为可选字段，到豪秒级。根据您的业务场景决定消息中是否带时间戳。如果消息频繁，需根据时间戳判断消息顺序，建议消息中带有时间戳。 |
| value   | Object     | 上报的属性值                                                                                                                                       |

![img](/images/iot_platform/clip_image020.jpg)

![img](/images/iot_platform/clip_image022.jpg)

页面设备管理-设备详情，查看设备上报的属性数据。

![img](/images/iot_platform/clip_image024.jpg)

<a id="markdown-设备属性设置" name="设备属性设置"></a>
### 设备属性设置

设备侧需要收到平台下发的数据，需要订阅：

$sys/{pid}/{device-name}/thing/property/set

本例为：$sys/EJyXIoGn8p/test/thing/property/set

![img](/images/iot_platform/clip_image026.jpg)

在页面运维监控-设备调试中-下行数据调试，可进行设置设备属性。

![img](/images/iot_platform/clip_image028.jpg)

topic: $sys/{pid}/{device-name}/thing/property/set_reply

本例中为：$sys/EJyXIoGn8p/test/thing/property/set_reply

```json
{
    "id":"128",
    "code":200,
    "msg":"success"
}
```

其中id为下行数据的id，需要匹配，code为200代表成功，msg可以自定义。

![img](/images/iot_platform/clip_image030.jpg)

<a id="markdown-事件上报" name="事件上报"></a>
### 事件上报

<a id="markdown-订阅事件上报结果通知消息" name="订阅事件上报结果通知消息"></a>
#### 订阅事件上报结果通知消息

为了确保事件上传消息确实被平台所接受处理，设备可以订阅系统 topic 获取事件上报结果消息，属性上报回复topic为：$sys/{pid}/{device-name}/thing/event/post/reply。

本例中topic为：$sys/EJyXIoGn8p/test/thing/event/post/reply。

上报数据成功后，订阅的事件上报会返回success。

![img](/images/iot_platform/clip_image032.jpg)

我们进入产品管理-详情页面，创建1个事件（switch），包含两个参数（led1，led2，参数类型为整型）。

![img](/images/iot_platform/clip_image034.jpg)

![img](/images/iot_platform/clip_image036.jpg)

上报事件topic为：$sys/{pid}/{device-name}/thing/event/post

本例中为：$sys/EJyXIoGn8p/test/thing/event/post

OneJSON请求数据格式:

```json
{
    "id":"123",
    "version":"1.0",
    "params":{
        "switch":{
            "value":{
                "led1":22,
                "led2":23
            },
            "time":1592530745328
        }
    }
}
```

表：请求参数说明

| 参数    | 类型       | 说明                                                                                                                                               |
| ------- | ---------- | -------------------------------------------------------------------------------------------------------------------------------------------------- |
| id      | String     | 消息id号，用户自定义，String类型的数字，长度限制13位。                                                                                             |
| version | String     | 物模型版本号，可选字段，不填默认为1.0                                                                                                              |
| params  | JsonObject | 上报事件的参数。                                                                                                                                   |
| time    | Long       | 属性值生成时间。该参数为可选字段，到豪秒级。根据您的业务场景决定消息中是否带时间戳。如果消息频繁，需根据时间戳判断消息顺序，建议消息中带有时间戳。 |
| value   | Object     | 具体的事件信息。如以上示例中  {       "Power": "on",       "WF": "2"  }                                                                            |

![img](/images/iot_platform/clip_image038.jpg)

页面设备管理-设备详情，查看设备上报的事件数据。

![img](/images/iot_platform/clip_image040.jpg)

<a id="markdown-订阅获取设备期望值topic" name="订阅获取设备期望值topic"></a>
### 订阅获取设备期望值topic

$sys/{pid}/{device-name}/thing/property/desired/get/reply

本例中为：$sys/EJyXIoGn8p/test/thing/property/desired/get/reply

设备获取期望值：

$sys/{pid}/{device-name}/thing/property/desired/get

$sys/EJyXIoGn8p/test/thing/property/desired/get

OneJSON数据格式:

```json
{
    "id":"123",
    "version":"1.0",
    "params":[
        "Power"
    ]
}
```

表：请求参数说明

| 参数    | 类型       | 说明                                                   |
| ------- | ---------- | ------------------------------------------------------ |
| id      | String     | 消息id号，用户自定义，String类型的数字，长度限制13位。 |
| version | String     | 物模型版本号，可选字段，不填默认为1.0                  |
| params  | JsonObject | 获取属性期望的标识符列表                               |

![img](/images/iot_platform/clip_image042.jpg)

![img](/images/iot_platform/clip_image044.jpg)
