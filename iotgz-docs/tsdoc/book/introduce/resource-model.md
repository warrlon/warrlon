# Resource Model

The OneNET resource model is as follows:

![Resource Model](/images/资源模型.png)

- Product

    The largest resource set of users is products. Resources under products include equipment, device data, device privileges, data trigger services and application based on device data. Users can create multiple products.

- Device

    Devices are the mapping of real terminals on the platform. When real terminals connect to the platform, they need to establish one-to-one correspondence with the platform equipment. The data uploaded by the terminal is stored in the data stream, and the device can have one or more data streams.

- Data Stream and Data Point

    Data stream is used to store some kind of attribute data of the device, such as temperature, humidity, coordinates and so on. When the platform requests the device to upload and store data, it must upload data in key-value format, in which key is the name of the data stream, value is the actual stored data point, and value format can be customized formats such as int, float, string, JSON and so on.

- APIkey

    APIkey is the key of API invocation for users. When users access product resources, they must use the corresponding APIkey under the product catalog.

- trigger

    Flip-flops serve messages in product catalogs. They can make simple logical judgments based on data flow and trigger HTTP requests or mails.

- Application

    The application editing service supports users to generate simple web page display applications by dragging and dropping controls and correlating device data streams.