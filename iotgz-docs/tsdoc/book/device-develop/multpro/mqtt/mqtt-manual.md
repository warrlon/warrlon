# MQTT Access Description

The test access process is divided into platform domain and device domain, which is used to help you have the first access experience, so as to have a general understanding of the platform's functions and access protocols.

** Test flow chart**

![PIC](/images/MQTT/测试流程图1.jpg)

** Access steps** are as follows:

** Step1 Create Products, Choose Access Protocol**

First, you need to create a product with ** access protocol for MQTT** on the platform and see[product creation](/book/easy-manual/product&device/product-create.md)

After creating the product, record the product ID of the product

** Step2 Creates Devices, Records Device ID and Other Information**

There are two ways to create a device:

The first one can click on ** to add device ** and enter ** device name ** and ** authentication information ** (i.e. device number). For details of the resource model of a specific platform, please see Chapter 1[resource model](/book/introduction/resource-model.md) and record the ** device number **.

The second way is to create devices by calling the Creation Device API. By inputting device name, access protocol, authentication information and MasterKey information, devices can be created on the platform.

** Step3 Establishes Protocol Connection between Equipment and Platform**

MQTT server address domain name: ** mqtt. heclouds. com**

Using the parameters of Step1 and Step2 as login parameters, the corresponding interfaces in SDK are used to organize MQTT connection messages, send them to the platform, and establish MQTT connection with the platform.

If the connection is successful, you will see an online tag in the device information:

![pic](/images/MQTT/在线.png)

** Step4 data stream creation, data point upload **

Using the interface function provided in SDK, write code to upload data to the platform

** Step5 Data Stream Display, View Data Points**

Click on data display under device management on OneNET, enter data display page, click on drop-down menu to view recently uploaded data points, or choose time interval to view historical time.


## Common Questions
----------

** Q1: When MQTT connection authentication, what are the ClientIdentifier, UserName and UserPassword in Payload? * *

** A **:** ClientIdentifier **: The device ID obtained when the device was created is a digital string;

   UserName**: When registering a product, the product ID assigned by the platform is a digital string.

  ** UserPassword**: Authentication information for the device (i.e. unique device number, SN), or apiKey, as a string.

** Q2: Does MQTT need connection authentication before it can send other messages? * *

** A **: Yes, the MQTT protocol must be authenticated (after receiving ConnAck) before it can send subsequent messages for interaction, otherwise the server will discard the messages directly.

** Q3: What are the restrictions on MQTT subscribing to Topic? * *

** A **: OneNET does not support the system Topic that subscribes to the $start.

** Q4: How to upload data to cloud platform using MQTT protocol? * *

** A **: After the device completes the connection authentication, it packages the data in a certain format (see the protocol document description) and publishes the data to the Topic of the $dp system.

** Q5: Do you need to create Topic before subscribing? * *

** A **: When a device performs a subscription, OneNET automatically determines whether the Topic exists or not, and automatically creates the Topic if it does not exist.

** Q6: Can devices get data stream information from other devices by subscribing? * *

** A **: Yes, you can get the latest data point information of a device in time by subscribing to **/device_id/data stream name **.

** Q7: What are the limitations of Publish? * *

** A **: Publish messages can only be published under the same product ID, not across products.