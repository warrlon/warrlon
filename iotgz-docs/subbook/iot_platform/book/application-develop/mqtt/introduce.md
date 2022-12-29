# 应用长连接

<a href="#1">1. 服务概述</a>

<a href="#2">2. 服务地址</a>

<a href="#3">3. 客户端鉴权</a>

<a href="#4">4. 消息通信主题</a>

---
<h3 id="1">1. 服务概述</h3>

应用长连接是提供点对点通信的服务，可实现应用设备数据的实时获取和控制命令下发，适用于设备操作频繁，对交互性、时效性要求比较高的应用场景，如智能家居APP、大屏应用等，可以减少网络请求次数和流量开销。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/application/长连接服务.png">
    <br>
    图 1 应用长连接通信流程
    <br>
</center>

应用长连接采用MQTT协议进行通信，每个应用客户端作为一个MQTT Client，平台作为MQTT Server，通信流程可概括为建立连接、订阅主题、接收消息并处理、发布消息四个步骤。
- 建立连接：
   - 应用客户端创建MQTT Client，设置clineid、username、password鉴权参数。
   - 应用客户端设置keepalive、协议版本、tls等连接会话参数。 
- 订阅主题
   - 根据应用场景需求，客户端订阅系统主题，目前提供设备生命周期状态变更、设备属性功能点、设备事件功能点及属性设置响应4种类型主题。
   - 系统通信主题以单设备作为发布和订阅的层级。
- 接收消息并处理
   - 设备发生状态更改或者上报数据后，平台将消息推送给订阅该通道的客户端，客户端对数据进行处理。
   - 应用长连接不提供消息缓存功能，对于需要获取项目设备全量数据，支持消息缓存的应用场景，建议使用HTTP推送或消息队列MQ。
- 发布消息
   - 用户可通过向指定主题发布消息，实现对设备的属性设置及属性期望值设置。


<h3 id="2">2. 服务地址</h3>

应用长连接支持标准 MQTT V3.1.1 版本，接入服务地址如下：

<table>
<tr><th>地址</th><th>端口</th><th>证书</th><th>说明</th></tr>
<tr><td>183.230.102.116</td><td>25002</td><td>-</td><td>tcp非加密端口</td></tr>
</table>

<h3 id="3">3. 客户端鉴权说明</h3>

应用客户端与平台建立连接时，平台会对MQTT Client设置的clienid，username，password参数信息进行鉴权，目前平台支持用户维度和项目分组维度两种鉴权方式。鉴权参数如下表所示：

<table>
<tr><th>参数</th><th>说明</th></tr>
<tr><td>clientid</td><td>应用客户端自定义，每个clientid在平台保持唯一，避免信息重复可不设置，由系统自动生成</td></tr>
<tr><td>username</td><td>目前支持两种类型：
<br/>基于用户权限订阅 userid/{userId} <br/>基于项目分组订阅 projectid/{projectId}/groupid/{groupId} 项目ID、分组ID作为变量参数</td></tr>
<tr><td>password</td><td><a href="/book/api/auth.md">安全鉴权参数</a>，username参数值作为安全鉴权计算中的res策略值参与运算 </td></tr>
</table>

<h3 id="4">4. 消息通信主题</h3>

客户端只能订阅当前账号权限下的设备主题，服务提供主题列表如下所示：

<table>
<tr><th width="65%">TOPIC</th><th>说明</th><th>可订阅</th><th>可发布</th></tr>
<tr><td>$sys/{productId}/{deviceName}/thing/lifecycle</td><td>设备生命周期状态更改</td><td>&radic;</td><td></td></tr>
<tr><td>$sys/{productId}/{deviceName}/thing/property</td><td>设备属性上报</td><td>&radic;</td><td></td></tr>
<tr><td>$sys/{productId}/{deviceName}/thing/event</td><td>设备事件上报</td><td>&radic;</td><td></td></tr>
<tr><td>$sys/{productId}/{deviceName}/thing/property/set</td><td>设备属性设置</td><td></td><td>&radic;</td></tr>
<tr><td>$sys/{productId}/{deviceName}/thing/property/desired/set</td><td>设备属性期望值设置</td><td></td><td>&radic;</td></tr>
<tr><td>$sys/{productId}/{deviceName}/thing/property/set/reply</td><td>设备属性设置响应</td><td>&radic;</td><td></td></tr>
</table>

##### 设备生命周期数据

```
Topic：$sys/{productId}/{deviceName}/thing/lifecycle

Message：{    
    "productId": "00001",                    
    "deviceName": "iot-0001",      
    "messageType": "lifecycle", 
    "data":  {
        "status": "online",
        "time": 1524448722123
    }
}
```

##### 设备属性功能点上报：

```
Topic：$sys/{product_id}/{device_name}/thing/property

Message: {  
    "productId": "00001",                   
    "deviceName": "iot-0001",     
    "messageType": "notify",
    "notifyType": "property",
    "data": {                         
        "id":  "12345",                
        "params": {
            "Power": {
                "value": "on",
                "time": 1524448722123
            },
            "WF": {
                "value": 23.6,
                "time": 1524448722123
            ｝
        ｝
    } 
}
```

##### 设备事件功能点上报：

```
Topic：$sys/{product_id}/{device_name}/thing/event

Message: {
    "productId": "00001",                        
    "deviceName": "iot-0001",    
    "messageType": "notify",
    "notifyType": "event",
    "data": {
        "id": "123",
        "version": "1.0",
        "params": {
            "identifier1":{
                "value": {
                    "Power": "on",
                    "WF": "2"
                },
                "time": 1524448722123
            },
            "identifier2": {
                "value": {
                    "Power": "on",
                    "WF": "2"
                },
                "time": 1524448722123
            }
        }
    }
}
```

##### 设备属性设置

```
Topic：$sys/{product_id}/{device_name}/thing/property/set

Message： {
    "requestId": "8906582E6722409AA6C40E7863B733A5",
    "data": {
        "version": "1.0",  // 可选，不填默认为1.0
        "params": {        // 属性设置，必须为对
            "temperature":"30.5"
        }
    }  
}
```

##### 设备属性期望值设置

```
Topic：$sys/{product_id}/{device_name}/thing/property/desired/set

Message： {
    "requestId": "8906582E6722409AA6C40E7863B733A5",
    "data": {
        "version": "1.0",  // 可选，不填默认为1.0
        "params": {        // 属性设置，必须为对
            "temperature":"30.5"
        }
    }  
}
```

##### 设备属性设置响应

```
Topic：$sys/{product_id}/{device_name}/thing/property/set/reply

成功响应：
{
    "requestId": "8906582E6722409AA6C40E7863B733A5", //用户自定义id 
    "success": true,
}

失败响应：
{
    "requestId": "8906582E6722409AA6C40E7863B733A5",
    "code":  "deviceNotFound",
    "msg": "device does not exist", 
    "success": false
}

```
