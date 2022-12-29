# TCP

Users supported by OneNET upload data through TCP, which provides the feasibility for any protocol device to access OneNET. The device accesses OneNET through TCP connection, and after authentication, it can interact with OneNET. OneNET can parse the uploaded data and send data to the device through user-uploaded custom scripts.

![pic](/images/TCP/脚本工作方式.png)

## Functional characteristics

- Long connection
- User-defined scripts, only support Lua
- High flexibility
- Supporting one connection to transmit multiple device data

## Use restrictions

| Limited Item | Limited Content | Over-limit Description|
|:-|:-|:-|
| Number of scripts in product | up to 10||
| script file size | less than 2M||
| Single script runs memory | less than 100kB | discards data when it exceeds|
| script single execution time | less than 2ms | time-out discards data|
| Traffic Limitation | Device Data Up/Down Data Message Length Not More than 1K | Abandon Data|

## Typical application scenarios

The high flexibility of TCP transmission determines that it is not constrained. It is mainly applicable to user-defined protocols. It can interact with any protocol according to scripts defined by itself, and can support scripts to be modified and uploaded at any time. The protocol supports one connection to transmit data from multiple devices, and can centralize downloads from multiple devices for data upload and download. It is widely used in intelligent meters such as smart meters and water meters.