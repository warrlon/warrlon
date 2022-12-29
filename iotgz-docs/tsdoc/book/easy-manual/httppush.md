# HTTP Push

The platform provides HTTP push function, which can actively send device-related data and messages to application servers in the form of HTTP/HTTPS POST requests.

Follow these steps to enable HTTP push service:

**Step 1**

Enter the Developer Center, select ** Data Push ** - > ** HTTP Push **, click ** Add Global Push **, as shown below:

![Push Entrance](/images/数据推送/推送入口.png)


**Step 2**

Fill in the server URL address for receiving data and the custom token (token can be used to verify whether the request is from OneNET). By specifying the data stream, select the data stream that needs to push the new data point, and click ** to associate **, as shown in the following figure:

![push configuration](/images/数据推送/推送配置页面.png)

**Step 3**

In the pop-up menu bar, select the data stream that needs to push data. After selection, the push service will push the new data points in the selected data stream, as shown in the following figure:

![Associated Data Stream Template](/images/数据推送/关联数据流模板.png)

**Step 4**

Deploy push timing intervals and cumulative numbers as needed, as shown in the following figure:

- After configuring the push interval, data will be pushed periodically according to the time interval.
- After the number of configurations is accumulated, the number of messages is accumulated to a certain number before pushing the data.

![Interval](/images/数据推送/时间间隔与消息累计.png)


**Step 5**

Deploy the application server receiving service according to the application[development guide](/book/application-development/httppush/development-manual.md). Click ** to add ** and you can see that the service is ** enabled ** after success, as shown in the following figure:

![Configuration success](/images/数据推送/配置成功.png)