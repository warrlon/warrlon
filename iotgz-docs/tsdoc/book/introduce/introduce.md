# Introduction to Platform

OneNET is positioned as PaaS service, which is to build an efficient, stable and secure application platform between Internet of Things applications and real devices: facing devices, adapting to various network environments and common transmission protocols, providing fast access schemes and equipment management services for various hardware terminals; facing enterprise applications, providing rich APIs and data distribution capabilities to meet the needs of application systems in various industries. With the development of demand, Internet of Things enterprises can focus more on the development of their own applications, instead of focusing on the environment construction of equipment access layer, so as to shorten the formation cycle of the Internet of Things system and reduce the cost of enterprise research and development, operation and maintenance.

The main functions of OneNET are as follows:

#### Equipment Access

- Support equipment access of various industries and mainstream standard protocols, such as CoAP (LwM2M), MQTT, Modbus, HTTP, etc., to meet the needs of a variety of application scenarios.
- Provide multiple languages to develop SDK to help developers quickly access devices
- Support user protocol customization and complete protocol parsing by uploading parsing script

#### Equipment management
- Provide equipment life cycle management functions to support users to register, update, query and delete equipment
- Provide on-line status management function of equipment, provide information notification of equipment on-line and off-line, and facilitate users to manage equipment on-line status.
- Provide device data storage capability to facilitate users to store large amounts of equipment data in queries
- Provide equipment debugging tools and equipment logs for users to quickly debug equipment and locate equipment problems.


#### Data and Access Security
- Provide TLS and DTLS (suitable for CoAP protocol) encryption channels to ensure the security of user data transmission
- Support users to adopt private protocols and private encryption for data transmission to ensure data security
- Distributed structure, remote dual-activity and other multiple data guarantee mechanisms to provide secure data storage services
- Support secure access authentication mechanism, effectively reduce the risk of key and access token being counterfeited

#### Enriching API support
- Open API interface, through simple calls to quickly achieve the generation of applications
- Increasingly rich API categories, including device addition, deletion and modification, data stream creation, data point upload, command issuance, etc., help users to easily build the upper application.

#### Application Integration Tool
- Provide message queue MQ for user application system to quickly obtain device data/events
- Provide HTTP push service, which can actively push data to application system in the form of HTTP request
- Supporting simple rule configuration, user can customize data processing logic

#### Simple application of hatching tools
- Provide a simple application generation tool for start-up users and a quick implementation of simple applications
- Provide rich graphical presentation components to meet multi-scenario usage requirements