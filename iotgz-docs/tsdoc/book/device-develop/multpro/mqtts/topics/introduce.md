# Topic cluster

Device-oriented interfaces of device-related services (storage, commands, etc.) in MQTTS Internet of Things suite are provided in the form of topic. Devices can call service interfaces through publish messages to system topic, or subscribe to system topic for receiving service message notifications. The set of ** system topic provided by services ** forms a topic cluster.

MQTTS Internet of Things suite currently includes: data point topic cluster, command topic cluster, sub-device topic cluster, device shadow topic cluster, as shown in the following figure:

![](/images/MQTTS/topics.jpg)


## Topic cluster of data points

Devices can upload data storage through data point top cluster and obtain data storage results instantly.
- Topic in the cluster begins with $sys/{pid}/{device-name}/ DP
- When uploading data through publish, payload needs to meet the platform's agreed data format
- Supporting multiple data reporting at one time, supporting device with timestamp reporting
- Instant notification of data processing results (subscription required)


See[Data Point Topic Cluster](/book/device-development/multpro/MQTTS/topics/dp-topics.md)

## Topic cluster of device commands

The device can obtain the application instant command through the device command topic cluster and report the execution result.
- Topic in the cluster begins with $sys/{pid}/{device-name}/ CMD
- Instant access to device commands (subscription required)
- The platform transmits ** device commands and device responses through publish payload **
- Each command has a unique uuid, and the application can record the creation and response of its query commands.

See[device command topic cluster](/book/device-development/multpro/MQTTS/topics/cmd-topics.md)

(forthcoming)

## Device Mirror Topic Cluster

Devices can interact with device mirroring services through the device mirror top cluster to synchronize device status/configuration information
- Topic in the cluster begins with $sys/{pid}/{device-name}/ image
- Supporting Upload Update of Device Custom Status/Configuration Information
- Real-time access to device status updates (subscription required)
- Supporting devices to query current full device image information


For details see[Topic cluster of device commands](/book/device-develop/multpro/MQTTS/topics/image-topics.md)


## Subdevice Topic Cluster

(forthcoming)