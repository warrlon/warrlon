# Modbus Access Instructions

The test access process is divided into platform domain and device domain, which is used to help you have the first access experience, so as to have a general understanding of the platform's functions and access protocols.

The test flow chart is as follows:

![pic](/images/Modbus/测试流程.png)

** Access steps** are as follows:

** Step1 Create Products, Choose Access Protocol**

First, you need to create a product on the platform with ** access protocol MODBUS ** and see[product creation](/book/easy-manual/product&device/product-create.md)
If you don't have an OneNET account, you can[register users](/book/easy-manual/login.md)

** Step2 creates device creation device, records device ID and other information**

Click on ** Add device ** and enter ** device name ** and ** authentication information ** (i.e. device number). For details of the resource model of the specific platform, please see Chapter 1[resource model](/book/introduction/resource-model.md) and record the device number.

** Step3 Creates Data Stream**

Adding sampling data stream, a sampling data stream corresponds to a periodic acquisition command
![pic](/images/Modbus/添加采样数据流.png)

Configure relevant sampling information and click ** to save **
![pic](/images/Modbus/保存数据流配置.png)


** Step4 Establishing Equipment Connection**

With the product ID and the number and password input when setting up the device as parameters, the message is serialized in the following order and sent to the platform to establish the device connection.

| Field | Length / byte | Description|
|:---|---|---|---|---|
| Type | 11 | Device type, ending with'/0', currently retained|
| Name | 9 | device name, ending with'/0', currently retained|
| Phone | 12 | DTU phone number, ending with'/0', for device login authentication|
| svrpwd | 9 | DTU password, ending with'/0', for device login authentication|
| ID | 11 | Product ID, ending with'/0', the product ID allocated when the platform applies for the project|

After the device connection is established, you will see the online status of the device (as shown below), and the platform will issue the acquisition command according to the set ** data cycle **.
![pic](/images/MQTT/在线.png)

** Step6 Maintaining Equipment Online**

When the device is idle, in order to keep the connection with OneNET platform open, it is necessary to send ** heartbeat packet ** (** 0x0000 **) regularly to ensure the continuous opening of TCP connection. The interval should be less than 5 minutes, recommended for 1-3 minutes.