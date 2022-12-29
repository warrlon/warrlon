# Overview of Services

The platform provides data push function. It can take the platform as a client and send relevant information to the application server in the way of HTTP/HTTPS request.

Among them, relevant information includes:
- New Data Point Messages for Devices
- Device Up and Down Message
- Response information of the device to downlink commands (NB device only)


HTTP requests initiated by the platform mainly include:
- GET: User-configured URL validation
- POST: Used to push new data point messages, device up and down messages, and device response information to downlink commands


Push service provides data filtering function. Users can use ** data stream template ** as filtering condition, filter out a large number of ** time insensitive ** data such as frequent periodic reports of devices, and only push data with high real-time requirements that users care about.

![Data filtering](/images/数据过滤.png)


Push function provides data compression function. Users can set data volume and time compression mode, merge a certain amount of multi-package single message in a certain time into a package of JSON data containing multiple information, which can greatly reduce the processing pressure of application server.

![Data](/images/数据压缩.png)