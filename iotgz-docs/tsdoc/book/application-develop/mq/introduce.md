# Overview of Message Queue MQ Service

Message queue MQ is positioned as the ** Internet of Things Service Component ** used by OneNET Device Access Service to achieve fast, immediate and reliable access to device messages at the application layer. The service model is as follows:

![Overview of MQ](/images/mq/MQ概述new.png)


Among them:
- ** topic** is a queue entity, and multiple queue entities can be created in an MQ service
- Subsubscription is a real consumer agent. The consumer agent sends data to client after consuming. A queue can support multiple consumer agents. Consumer agents are independent of each other and can consume data in queues with different modes.


## Service characteristics
- Message caching

    MQ services support message caching, which can effectively cache messages that can not be consumed in real time due to network or application server anomalies.

    Queue caching has a certain capacity cap. When the queue capacity reaches the cap, the service will recover the data from the queue head.

- Peak Cutting and Valley Cutting

    MQ service can effectively buffer large and concurrent device messages that burst forward, and push them to the consumer client at a lower average rate, thus reducing the pressure on the consumer side.

- ** Up to once ** and ** at least once **

    Users can configure the ** message locking time ** to achieve the message mode of ** consuming at most one time ** and ** consuming at least one time **. If the message locking time is enabled, during that time, if the client fails to acknowledge the response, the consumption is considered to fail. After the locking time period, the client can consume the unacknowledged message again.

- Message expiration time

    Users can customize message expiration time, and messages up to message expiration time when entering the queue will be deleted, that is, the service will delete messages entering the queue for more than a certain period of time.

- Customize Consumption Location

    Supporting user-defined consumption locations, such as from the head, from the tail, or from a location in the queue. After setting up, the client will consume the messages from the customized location in the queue.

    As long as the message is not deleted because the timeout or the buffer is full, the user can re-consume the message by specifying the consumption location.

- Multi-party independent consumption

    Services support users to create multiple consumer agents (sub) for a queue. Consumer agents are independent of each other and can consume data in the same queue with different configurations.

- ** Single Point Consumption** and Cluster Consumption**

    MQ services support one or more clients to establish a subscription relationship with the same sub at the same time

    When multiple clients establish a subscription relationship with the same sub in the same topic at the same time, MQ services assume that the client is in the cluster consumption mode, and messages will be sent to each client equally, and each message can only be consumed by one client, as shown in the following figure:

    [Cluster Consumption](/images/mq/单点消费与集群消费.png)


## More help

-[View the Console Use Guide](/book/easy-manual/MQ.md)
-[For more information on client development assistance, see the Development Manual](/book/application-development/mq/development-manual.md)
-[View demo engineering instructions](/book/application-development/mq/demo-project.md)
-[View the best examples of service usage](/book/application-development/mq/example.md)
-[Restrictions on the use of public beta service resources](/book/application-development/mq/limit.md)