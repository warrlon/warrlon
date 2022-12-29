# Brief introduction

The Modbus protocol supported by OneNET is based on TCP connection, namely Modbus over TCP.
OneNET, as the host, encapsulates the data in TCP data for sending and receiving data. With the simple transmission capability of DTU, it can realize the communication between bus equipment and platform's Modbus protocol. It can be widely used in many industries using Modbus protocol.

## Functional characteristics

- Long Connection Protocol
- OneNET platform serves as Modbus host, periodically issuing host commands
- Determining the content and cycle of a single command through the attributes of a single data stream
- Automatically convert the data reported by the terminal into data points in the data stream
- Processing formulas can be set up in advance, and data can be processed preliminarily.

## Typical application scenarios

Modbus communication protocol is an industrial fieldbus communication protocol, which is widely used in industrial automation control. It can realize the functions of industrial data acquisition and control. It can be widely used in DTU + Modbus scenario (i.e. the bus protocol is Modbus, using DTU connection platform), as follows:

![pic](/images/Modbus/连接示意图.png)