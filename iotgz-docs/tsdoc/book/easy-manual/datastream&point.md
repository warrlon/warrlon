# Data Stream and Data Point

The platform organizes device upstream data through data streams and data points, as shown in the following figure:

![Data streams and data points](/images/数据流与数据点1.png)

When a device uploads and stores data, it must upload data in key-value format, in which key is the name of data stream, value is the actual stored data point, and value format can be used for int, float, string, JSON and other customized formats.

In practical applications, data streams can be used to classify and describe some kind of attribute data of equipment, such as temperature, humidity, coordinates and so on. Users can customize the data range of data streams and classify the data with high correlation as a data stream.

The data in the data stream can flow to the follow-up service while it is stored. The data stream is the service object of the platform's follow-up data service (rules, triggers, message queues, etc.). The follow-up data service supports users to select the data source of the service by choosing the data stream.

Data platforms in data streams store ** in time series by default. Users can query the values of data points in data streams at different times, as follows:

![Data streams and data points](/images/数据流与数据点2.png)