# Introduction to LwM2M

The lightweight M2M protocol developed by OMA organization of LwM2M is mainly for the application of the Internet of Things (NB-IoT) in the context of cellular-based Narrow Band Internet of Things, focusing on the low-power and wide-coverage (LPWA) Internet of Things (IoT) market. It is a new technology that can be widely used worldwide. It has the characteristics of wide coverage, multiple connections, low speed, low cost, low power consumption and excellent architecture.

## Functional characteristics

NB-IoT has four characteristics:

- Broad coverage: In the same frequency band, NB-IoT gains 20 dB compared with the existing network, equivalent to 100 times the coverage area capacity;
- Dalian Connection: Easily support a large number of equipment networking needs, with the ability to support massive connections, NB-IoT can support 100,000 connections in a sector;
- Low power consumption: focusing on small data volume and small rate applications, especially for equipment and occasions where batteries cannot be replaced frequently, theoretically the standby time of NB-IoT terminal module can be up to 10 years.
- Low cost: Expected single connection module does not exceed $5;

Based on NB-IOT LwM2M protocol and CoAP protocol, the communication between UE and OneNET platform is realized. The transmission layer protocol in data transmission protocol is CoAP, and the application layer protocol is LwM2M protocol.

Coap protocol has the following characteristics:

- Based on lightweight UDP protocol, it has a retransmit mechanism
- IP Multicast Supported by Protocol
- The protocol header is small, only 4 bytes.
- Low power, suitable for low power Internet of Things scenarios

LwM2M protocol is applicable to lightweight protocols for various Internet of Things devices. LwM2M defines three logical entities:

- LwM2M Server server;
- The LwM2M Client client is responsible for executing the server's commands and reporting the execution results.
- LwM2M boot server Bootstrap Server is responsible for configuring LwM2M client.

## Typical application scenarios

LwM2M protocol (NB-IoT) is a lightweight M2M protocol with retransmit mechanism based on UDP protocol. It is mainly aimed at the application of Internet of Things (IOT) in the Narrow Band Internet of Things (NB-IoT) scenario. It focuses on the low power and wide coverage (LPWA) market of the Internet of Things (IoT), and is a new technology that can be widely used worldwide.

It is widely used in environments with low demand for electricity, high coverage depth, mass connection of terminal equipment and cost-sensitive equipment. It can be widely used in intelligent parking, intelligent meter reading, intelligent well cover, intelligent street lamp and other application scenarios.