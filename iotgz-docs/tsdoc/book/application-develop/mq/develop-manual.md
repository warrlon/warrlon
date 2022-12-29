# Message Queue MQ Consumer Development Guide

## Consumption agreement

Message queue MQ currently supports clients to connect and consume data using ** MQTT ** protocol, and only supports TLS encryption.

    MQTT v3.1.1, which supports the standard by default

| Connection Protocol | Certificate | Address | Port|
|:-|:-|:-|:-|
| MQTT |[Certificate Download](/cer/certificate.pem) | 183.230.40.96 | 8883|

#### SDK Download

Recommended third-party SDK, visit[https://github.com/mqtt/mqtt.github.io/wiki/libraries](https://github.com/mqtt/mqtt.github.io/wiki/libraries)


## Development process
The development process of the consumer side is as follows:
![](/images/mq/开发流程.png)

### 1 Client Connection

Once the message queue MQ service is enabled, OneNET assigns it a unique Id, as shown below, for one of the client connection authentication parameters.

![MQ_ID](/images/mq/MQ_ID.png)

Client can establish connection with server by sending MQTT Connnect message. The three elements of connection message are as follows:

| Parameter | Must | Parameter Description|
|:-|:-|:-|
| ClientId | No | User-defined valid UTF-8 string, null|
| username | is | Fill in ** MQ_ID **|
| password | is | Fill in token. For the algorithm, see[security authentication](/book/easy-manual/auth.md)<br> where res = mqs/$MQ_ID|


In addition, in Connnect messages, the use of keep alive, will, session fields is limited as follows:

<table>
<tr><th width="20%">功能</th><th width="20%">是否支持</th><th>说明</th></tr>
<tr><td>keepalive</td><td>支持</td><td>支持范围为：30~4800s</td></tr>
<tr><td>will</td><td>不支持</td><td>will、will retain 的flag必须为0，will qos必须为0</td></tr>
<tr><td>session</td><td>不支持</td><td>cleansession标记必须为1</td></tr>
</table>

### 2 Subscribe Themes

- Subscribe to messages

    The top format of subscription messages is as follows: ** Wildcard characters are not supported **

    $sys/pb/consume/**$MQ_ID**/**$TOPIC**/**$SUB**

    Request QoS** must be greater than 0** at subscription time, otherwise subscription fails

- Subscription confirmation message

    The platform uses MQTT SubAck message for subscription confirmation, and the return code is fixed to 0x01 when the return is successful.

<table>
<tr><th width="25%">Request QoS</th><th width="25%">SubAck返回码</th><th>说明</th></tr>
<tr><td>0</td><td>0x80</td><td>订阅失败</td></tr>
<tr><td>1</td><td>0x01</td><td>订阅成功，最大QoS为1</td></tr>
<tr><td>2</td><td>0x01</td><td>订阅成功，最大QoS为1</td></tr>
</table>

- Cancel Subscription Message

    Client uses MQTT Unsubscribe message to cancel subscription

- unsubscribed confirmation message

    The server uses MQTT UnsubAck message for subscription cancellation confirmation

### 3 News Consumption

- After successful subscription, MQ will actively push to the client through ** publish message ** according to the situation of production message.
- When consuming, MQ pushes only ** QoS1 **
- Client needs to use ** puback message ** to reply after consuming data according to the order of data acquired.

### 4 Data parsing

After receiving the publish message, the client parses the ** payload ** data segment according to the MQTT protocol, and then parses the payload data content according to the following steps

#### Step 1 Installs Protobuf

#### Step 2 Download the following. proto file
The onenet-mq.proto interface file is as follows:



```c++
syntax = "proto3";

package mq;

message Msg{
    uint64 msgid          = 1; //MQ中该消息的真实id
    bytes data            = 2; //具体的数据
}
```

Save[onenet-mq.proto](/book/doc/onenet-mq.proto) file to local

#### Step 3 Compiles Proto Files

Compile the file according to the language, taking Java as an example
```bash
protoc --java_out=$DST_DIR $SRC_DIR/onenet-mq.proto
```

#### Step 4 adds compiled source files to the project

Take Java as an example, the OnenetMq. java file is generated after compilation, and the source file is added to the project. At the same time, the dependency of Java grpc needs to be added. Take Maven management as an example, the following contents need to be added to the pom. XML file:
```xml
        <dependency>
            <groupId>io.grpc</groupId>
            <artifactId>grpc-protobuf</artifactId>
            <version>1.18.0</version>
        </dependency>
```

#### Step 5 reads data
- Call the parseFrom () method to create the Msg object obj
- Call obj. getMsgid () to get the message ID
- Call obj. getData () to get message data (view ** data format **)


The Java example is as follows:
```java
OnenetMq.Msg obj;
obj = OnenetMq.Msg.parseFrom(mqttPayload);
System.out.println(obj.getMsgid());
System.out.println(new String(obj.getData().toByteArray()));
```


## Data format

Users can distribute different types of data in a unified data format (json) to subsequent services by configuring the data source of message queue MQ. Currently, the following messages are supported:

- Data stream message

    Supporting ** New Data Point Messages Occurring in User Configuration Forwarding Data Stream **

- Equipment Life Cycle Event Messages

    Support for User Configuration Forwarding Device Life Cycle Event Messages in Products (Currently only ** Device Up and Down Messages **)

The message data format is as follows:

### Data stream message

The data flow message data format is as follows:


<table>
<tr><th width="15%">参数</th><th width="15%">属性</th><th width="15%">类型</th><th width="40%">说明</th><th>示例</th></tr>
<tr>
    <td rowspan="2"> sysProperty
    <td>messageType</td><td>string</td><td>消息类型：固定为deviceDatapoint</td><td> </td>
</tr>
<tr>    
    <td>productId</td><td>string</td><td>产品ID</td><td>90273</td>
</tr>
<tr>
    <td rowspan="3"> appProperty
    <td>deviceId</td><td>string</td><td>设备ID</td><td>102839</td>
</tr>
<tr>
    <td>dataTimestamp</td><td>int</td><td>设备数据点生产时间戳，单位毫秒，设备上传时可自定义携带</td><td>15980987429000</td>
</tr>
<tr>    
    <td>datastream</td><td>string</td><td>数据流名称</td><td>weather</td>
</tr>

<tr>
    <td rowspan="1"> body
    <td> </td><td>object/string/...</td><td>详细的数据点消息内容</td><td>见如下示例</td>
</tr>
</table>



Data JSON Example 1, JSON data
```json
{
    "sysProperty": {
        "messageType": "deviceDatapoint",
        "productId": "90273",
    },
    "appProperty":{
        "deviceId": "102839",
        "dataTimestamp": 15980987429000,
        "datastream":"weather"
    },
    "body":{
        "temperature": 30,
        "humidity": "47%"
    }
}
```
Data JSON example 2, numerical data
```json
{
    "sysProperty": {
        "messageType": "deviceDatapoint",
        "productId": "90273",
    },
    "appProperty":{
        "deviceId": "102839",
        "dataTimestamp": 15980987429000,
        "datastream":"temperature"
    },
    "body": 10
}
```

Data JSON example 3, string data
```json
{
    "sysProperty": {
        "messageType": "deviceDatapoint",
        "productId": "90273",
    },
    "appProperty":{
        "deviceId": "102839",
        "dataTimestamp": 15980987429000,
        "datastream":"weather"
    },
    "body":"sunny with wind"
}
```

Data JSON example 4, binary data

> ** Note **
>- When the data format is binary data, the data in body is the index number * index *. The example is as follows. Users can get the data through API through the index number. See[API details](/book/application-development/api/MQTT/17.Getthefile.md)

```json
{
    "sysProperty": {
        "messageType": "deviceDatapoint",
        "productId": "90273",
    },
    "appProperty":{
        "deviceId": "102839",
        "dataTimestamp": 15980987429000,
        "datastream":"weather"
    },
    "body":{
        "index": "3491506_1475204886914_bin"
    }
}
```


### Equipment Life Cycle Event Messages

The device life cycle event message data format is as follows:


<table>
<tr><th width="15%">参数</th><th width="15%">属性</th><th width="15%">类型</th><th width="40%">说明</th><th>示例</th></tr>
<tr>
    <td rowspan="2"> sysProperty
    <td>messageType</td><td>string</td><td>消息类型：固定为deviceLifeCycle</td><td> </td>
</tr>
<tr>    
    <td>productId</td><td>string</td><td>产品ID</td><td>90273</td>
</tr>
<tr>
    <td rowspan="2"> appProperty
    <td>deviceId</td><td>string</td><td>设备ID</td><td>102839</td>
</tr>
<tr>
    <td>dataTimestamp</td><td>int</td><td>设备消息生产时间戳，单位毫秒</td><td>15980987429000</td>
</tr>

<tr>
    <td rowspan="1"> body
    <td> </td><td>object</td><td>创建、删除、启用、应用、上线、下线
created/deleted/enabled/disabled/online/offline</td><td>目前仅支持<br>online/offline</td>
</tr>
</table>

Data JSON example
```json
{
    "sysProperty": {
        "messageType": "deviceLifeCycle",
        "productId": "90273",
    },
    "appProperty":{
        "deviceId": "102839",
        "dataTimestamp": 15980987429000,
    },
    "body":{
        "event": "online"
    }
}
```




## More help

-[View the Console Use Guide](/book/easy-manual/MQ.md)
-[See more introduction to service functions](/book/application-development/mq/introduction.md)
-[View demo engineering instructions](/book/application-development/mq/demo-project.md)
-[View the best examples of service usage](/book/application-development/mq/example.md)
-[Restrictions on the use of public beta service resources](/book/application-development/mq/limit.md)