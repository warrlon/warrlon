# Best examples

This article will show you how to connect and consume MQ messages through ** MQTT. FX **.

[MQTT client download](http://mqttfx.jensd.de/index.php/download)

## MQ Service Opening and Configuration
### Step 1 Service Opening and Resource Creation
Open MQ services, create topics, and create subscriptions as described in the Introduction Manual (/book/easy-manual/MQ.md)

In this case, topic is named: test and subscription is named: sub123
![topic](/images/mq/example/topicname.png)
![sub](/images/mq/example/subname.png)

### Step 2 Opens Data Source

Click on ** to configure data sources **, in this case select ** All data streams **
![](/images/mq/example/配置数据源.png)
![](/images/mq/example/全部数据流.png)


## MQTT.fx Client Configuration

### Step 1 Client Configuration
Open the MQTT.fx client and enter the client configuration page.
![](/images/mq/example/客户端配置入口.png)

Set ** Profile Name **, in this case test-mq

Set the access address and port, and set ** username ** and ** password **, where:

Username is set to MQ_ID and password is shown in[security authentication](/book/easy-manual/auth.md). In this case, the password example is as follows:

    version=2018-10-31&res=mqs%2FA18F3248E9306BE160C6E95BFEE5B257F&et=1548643432&method=sha1&sign=S7uiBwW7Pv5%2FfbtGmQI%2F94hLyGw%3D

![](/images/mq/example/MQTT配置.png)

Click ** SSL / TLS ** to enter the encryption settings

Select ** CA certificate file ** to import certificates

![](/images/mq/example/证书选择.png)

Click OK to complete the configuration

### Step 2 Client Connection
Click on the configuration file to select the arrow and select the configuration test-mq

![](/images/mq/example/选择配置文件.png)

Click ** Connect ** to connect to MQ service

### Step 3 Subscribes to and consumes data

Select the Subscribe configuration and enter the subscription name. The subscription naming rules are as follows:

$sys/pb/consume/**$MQ_ID**/**$TOPIC**/**$SUB**

In this case, the subscription name is:

    $sys/pb/consume/A18F3248E9306BE160C6E95BFEE5B257F/test/sub123

Select ** QoS1 ** and click ** Subscribe **

![](/images/mq/example/订阅.png)


## News Generation and Consumption

Users can use the platform's simulation tools to generate device messages, as follows:

Enter ** Device List ** - > ** Data Stream ** - > ** Analog Data ** Tool

![](/images/mq/example/数据流.png)
![](/images/mq/example/模拟数据.png)

Click ** to send data ** to complete the simulation of message generation
![](/images/mq/example/发送数据.png)

On the MQTT.fx client, you can view the currently received data in the format of[Development Guide](/book/application-development/mq/development-manual.md)

![](/images/mq/example/客户端接收数据.png)

## More help

-[See more introduction to service functions](/book/application-development/mq/introduction.md)
-[For more information on client development assistance, see the Development Manual](/book/application-development/mq/development-manual.md)
-[View demo engineering instructions](/book/application-development/mq/demo-project.md)
-[Restrictions on the use of public beta service resources](/book/application-development/mq/limit.md)