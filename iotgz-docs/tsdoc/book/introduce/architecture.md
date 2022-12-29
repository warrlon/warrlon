# Platform architecture

![Platform Architecture](/images/平台架构new1.png)

### Equipment Access
OneNET provides secure and stable device access services and supports a variety of protocols including LwM2M (CoAP), MQTT, Modbus, HTTP, TCP, etc.
- Considering low power consumption and wide coverage scenarios, it is recommended to use CoAP protocol access
- In the industrial Modbus communication scenario, DTU + Modbus protocol is recommended for access
- In scenarios where real-time communication with devices is required, MQTT protocol is recommended for access.
- In the scenario where the device simply reports data, it can be accessed using HTTP/HTTPS protocol.
- In the scenario where users need to customize protocol access, TCP + script is recommended.

For more information, please refer to the section of ** Instructions for Equipment Development **

### Equipment management
OneNET platform provides rich equipment management functions including life cycle management, on-line status monitoring, on-line debugging, data management and other functions for different use scenarios.

For more information, please refer to the section of ** Introduction Manual **

### API
OneNET provides an open, rich API interface based on HTTP/HTTPS. Users can use API for device management, data query, device command interaction and other operations. On the basis of API, according to their own personalized needs, they can specify the upper application.

Refer to[API List](/book/application-development/api/api-list.md) for details.

### HTTP Push
For some scenarios with high real-time requirements, OneNET provides data push function, which can filter out the frequent periodic data reported by the device side, and push the real-time data that users care about to the user's application server through HTTP/HTTPS.

Refer to[HTTP push](/book/application-development/httppush/introduction.md) for details.

### Message Queue MQ

Message queue MQ is a message middleware service for application layer to obtain device messages quickly and reliably. Users can customize message types produced by message producers, such as device data points, device life cycle events, etc. User application layer can establish a long connection between message consumers and services for message consumption.

Refer to[Message Queue MQ](/book/application-development/mq/introduction.md) for details.

### Security Authentication

OneNET provides user resource access security authentication mechanism, provides product-level and device-level keys with different granularity, and supports user-defined key access privileges to maximize the security of user equipment and application-level access.

For more information, please refer to[Security Authentication](/book/easy-manual/auth.md)