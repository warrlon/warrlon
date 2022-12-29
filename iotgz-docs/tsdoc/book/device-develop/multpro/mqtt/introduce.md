# Introduction to MQTT

MQTT protocol is an instant messaging protocol for Internet of Things applications. Using TCP/IP to provide network connection, it can shield messages from load content and reduce network traffic effectively.

## Characteristics and functions

- Long Connection Protocol
- Terminal data point reporting, supported data point types include
    - Integer (int)
    - Floating Points
    - String
    - JSON format
    - Binary data
- Platform message delivery
- Subscription, publication and message push based on Topic can realize message unicast and multicast between devices.


## Typical application scenarios

MQTT protocol is suitable for use scenarios where devices and platforms need to maintain long connections. MQTT is characterized by unicast and multicast of messages between devices. It can manage and control real devices in the way of application servers without relying on other services (issuing command services, pushing services, etc.).