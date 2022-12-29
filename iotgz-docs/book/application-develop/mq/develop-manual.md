# 消息队列MQ消费端开发指南

## 消费协议

消息队列MQ目前支持客户端使用**MQTT**协议连接并消费数据，仅支持TLS加密

    默认支持标准的 MQTT v3.1.1版本

|连接协议|证书|地址|端口|
|:-|:-|:-|:-|
|MQTT|[证书下载](/cer/MQ-certificate-release-0711.pem)|183.230.40.96|8883|

#### SDK 下载

推荐使用第三方SDK，请访问[https://github.com/mqtt/mqtt.github.io/wiki/libraries](https://github.com/mqtt/mqtt.github.io/wiki/libraries)


## 开发流程
消费端开发流程如下：
![](/images/mq/开发流程.png)

### 1 客户端连接

进入消息队列MQ服务
![MQ](/images/mq/1.png)

开通消息队列MQ服务实例，输入实例名称（实例名称平台唯一），如下图，实例名称用于客户端连接鉴权参数之一。


![MQ](/images/mq/2.png)
客户端可通过发送MQTT connnect报文与服务器建立连接，connect报文中三要素填写方法如下：

|参数|是否必须|参数说明|
|:-|:-|:-|
|clientId|否|用户自定义合法的UTF-8字符串，可为空|
|username|是|填写**MQ实例名称**|
|password|是|填写token，算法见[安全鉴权](/book/easy-manual/auth.md)<br>其中：res=mqs/$MQ_NAME|


另外，connnect报文中，keepalive、will、session字段的使用限制如下：

<table>
<tr><th width="20%">功能</th><th width="20%">是否支持</th><th>说明</th></tr>
<tr><td>keepalive</td><td>支持</td><td>支持范围为：30~4800s</td></tr>
<tr><td>will</td><td>不支持</td><td>will、will retain 的flag必须为0，will qos必须为0</td></tr>
<tr><td>session</td><td>不支持</td><td>cleansession标记必须为1</td></tr>
</table>

### 2 订阅主题

- 订阅报文

    订阅报文中topic格式如下，**不支持通配符**
	
    $sys/pb/consume/**$MQ_NAME**/**$TOPIC**/**$SUB**

    订阅时request QoS**必须大于0**，否则订阅失败

- 订阅确认报文
    
	平台采用MQTT SubAck报文进行订阅确认，返回成功时返回码固定为0x01

<table>
<tr><th width="25%">Request QoS</th><th width="25%">SubAck返回码</th><th>说明</th></tr>
<tr><td>0</td><td>0x80</td><td>订阅失败</td></tr>
<tr><td>1</td><td>0x01</td><td>订阅成功，最大QoS为1</td></tr>
<tr><td>2</td><td>0x01</td><td>订阅成功，最大QoS为1</td></tr>
</table>

- 取消订阅报文
    
    客户端使用MQTT Unsubscribe报文进行订阅取消  

- 取消订阅确认报文

    服务端使用MQTT UnsubAck报文进行订阅取消确认

### 3 消息消费

- 订阅成功后MQ会根据生产消息的情况，通过**publish报文**的主动推送给客户端
- 消费时MQ推送的消息只会是**QoS1**
- 客户端消费到数据后需要按照获取到的数据先后顺序使用**puback报文**回复

### 4 数据解析

客户端接收到publish报文后，按照MQTT协议解析其**payload**数据段，然后按照如下步骤解析payload数据内容

#### Step 1 安装protobuf

#### Step 2 下载下述.proto文件
onenet-mq.proto接口文件如下：

```c++
syntax = "proto3";

package mq;

message Msg{
    uint64 msgid          = 1; //MQ中该消息的真实id
    bytes data            = 2; //具体的数据
    uint64 timestamp      = 3; //精确到ms
}

```

保存[onenet-mq.proto](/book/doc/onenet-mq.proto)文件至本地

#### Step 3 编译proto文件

根据语言编译该文件，以Java为例
```bash
protoc --java_out=$DST_DIR $SRC_DIR/onenet-mq.proto
```

#### Step 4 将编译生成的源文件添加到项目

以Java为例，编译后生成OnenetMq.java文件，将该源文件添加到项目，同时需添加java grpc的依赖，这里以maven管理为例，需要在pom.xml文件中添加如下内容：
```xml
        <dependency>
            <groupId>io.grpc</groupId>
            <artifactId>grpc-protobuf</artifactId>
            <version>1.18.0</version>
        </dependency>
```

#### Step 5 读取数据
- 调用 parseFrom() 方法，创建Msg对象obj
- 调用 obj.getMsgid() 获取消息id
- 调用 obj.getData() 获取消息数据（查看**数据格式**）
- 调用 obj.getTimestamp() 获取消息毫秒级时间戳


Java示例如下：
```java
OnenetMq.Msg obj;
obj = OnenetMq.Msg.parseFrom(mqttPayload);
System.out.println(obj.getMsgid());
System.out.println(new String(obj.getData().toByteArray()));
System.out.println(obj.getTimestamp());
```



## 更多帮助

- [前往规则引擎介绍，了解MQ消息格式](/book/easy-manual/rule-engine/base-data.md)
- [查看控制台使用入门手册](/book/easy-manual/MQ.md)
- [查看更多服务功能介绍](/book/application-develop/mq/introduce.md)
- [查看demo工程使用说明](/book/application-develop/mq/demo-project.md)
- [查看服务使用最佳实例](/book/application-develop/mq/example.md)
- [公测版服务资源使用限制](/book/application-develop/mq/limit.md)