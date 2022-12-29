# demo project

This demo mainly takes ** Java ** as an example to demonstrate how to build a test project step by step for developers who first come into contact with OneNET message queue MQ.

## Preparatory conditions

- Make sure that the JDK and IDE environments are installed correctly locally. If not, please download and install them first.
- Make sure that the message queue MQ service has been opened correctly and the service resources have been created. If not, please refer to the introduction manual (/book/easy-manual/MQ.md) to complete the service opening and resource creation.

## Download demo project

[Download demo project](/images/tools/OneNET-MQ-demo-20190529.zip) and decompress it. After decompression, you can see that the local new OneNET-MQ-demo folder has been added.


## Configuration demo project

1. In IDE (take Eclipse for example), select File - > Import, and select Import type _Existing Maven Projects._

    ![](/images/mq/demoproj/import.png)

2. Click Next, click Browse, and select the unzipped OneNET-MQ-demo folder

    ![](/images/mq/demoproj/rootdirectory.png)

3. Click Finish to complete the project import

    Dependent jar packages need to be loaded when demo project is imported, and the whole import process needs to wait about 1 minute.


## Configure demo variables

Follow the instructions below to modify the MqClient class in _MqClient. java_based on the resource parameters created on the platform
```java
String userName = "您的MQ ID，作为MQTT连接时的username";
String accessKey = "您的MQ access_key";
String mqTopic = "您创建的topic名称";
String mqSub = "您创建的订阅名称"; 
String expirationTime = "您自定义的鉴权参数过期时间";
```

## Run demo

Running the MqClient class, connecting services and consuming messages in the queue, after success, you can observe successful consumption messages in console

![](/images/mq/demoproj/消费消息.png)


Users can use the platform's simulation tools to generate device messages, as follows:

Enter ** Device List ** - > ** Data Stream ** - > ** Analog Data ** Tool

![](/images/mq/example/数据流.png)
![](/images/mq/example/模拟数据.png)

Click ** to send data ** to complete the simulation of message generation
![](/images/mq/example/发送数据.png)


## More help

-[View the Console Use Guide](/book/easy-manual/MQ.md)
-[See more introduction to service functions](/book/application-development/mq/introduction.md)
-[For more information on client development assistance, see the Development Manual](/book/application-development/mq/development-manual.md)
-[View demo engineering instructions](/book/application-development/mq/demo-project.md)
-[View the best examples of service usage](/book/application-development/mq/example.md)
-[Restrictions on the use of public beta service resources](/book/application-development/mq/limit.md)