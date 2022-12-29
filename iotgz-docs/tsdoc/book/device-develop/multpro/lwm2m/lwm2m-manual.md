# LwM2M Access Description

The test access process is divided into platform domain and device domain, which is used to help you have the first access experience, so as to have a general understanding of the platform's functions and access protocols.

** Test flow chart**
Access process based on NB module/SDK mode:
![pic](/images/LwM2M/接入流程说明.jpg)

## Access steps

** Step1 Create Products, Choose Access Protocol**
First, you need to create a NB-IoT product on the platform, and select LwM2M protocol when choosing the device access protocol (because NB-IOT device needs to access the platform through NB base station, select "NB-IoT" when creating the product, and the specific creation steps can be seen[product creation](/book/easy-manual/product&device/product-create.md)

If you don't have an OneNET account, you can[register users](/book/easy-manual/login.md)

After creating the product, record the ** user ID ** of the product.


** Step2 Creates Devices, Records Device ID and Other Information**
There are two ways to create a device:
The first method is to add devices by clicking on the page and input device name and authentication information (i.e. IMEI and IMSI). For details of the resource model of the specific platform, please see[resource model](/book/introduction/resource-model.md) and record the device number.

The second way is to create devices by calling the Creation Device API. By inputting device name, access protocol, authentication information and MasterKey information, devices can be created on the platform.

** Step3 transplants SDK or carries NB module to establish UDP connection **

According to the actual access mode of NB-IOT equipment, there are two main ways at present:

First, the NB-IOT device carries the NB module which has been implemented to access the OneNET platform. The device connects with the OneNET platform through the NB module and the NB base station as well as the core network elements, realizes the interaction with the OneNET platform, and completes the UDP connection with the bootstrap server.

The specific way is to send AT instructions to the module and carry endpoint name parameters (i.e. authentication information ** IMEI, IMSI and other information **) to realize UDP connection between the device and the platform after the device is powered on. After the connection is established successfully, the bootstrap server will return the LwM2M access server address and port.

The NB module that has been implemented to access OneNET platform is shown in the following table:

For a list of all modules, see[List of Modules](/book/device-development/multpro/LwM2M/module-list.md)

| Terminal Manufacturer Full Name | Module Model | Standard Protocol Version | Chip Model|
|:-----|----|----|----|
| China Mobile Internet of Things Limited | M5311 | R14 | MT2625|
| China Mobile Internet of Things Limited | M5310-A | R14 | Hi2115|
| China Mobile Internet of Things Limited | M5330-GNSS | R14 | MT2625|
| China Mobile Internet of Things Limited | M5312 | R14 | RDA8908A|
| China Mobile Internet of Things Limited | M5330-A | R14 | RDA8908A|
| China Mobile Internet of Things Limited | M5310-SE | R14 | Hi2115|
| China Mobile Internet of Things Limited | M5313 | R14 | RDA8909B|
| China Mobile Internet of Things Limited | M5330 | R14 | MT2625|
| China Mobile Internet of Things Limited | S5601 | R14 | MT2625|
| China Mobile Internet of Things Limited | M5310-A-CM | R14 | Hi2115|
| China Mobile Internet of Things Limited | M5311-CM | R13 | MT2625|
| China Mobile Internet of Things Limited | M5313-CM | R13 | RDA8909B|
  [See more...](/book/device-development/multpro/LwM2M/module-list.md)






Second, NB modules on NB-IOT devices do not access OneNET platform. This situation suggests two ways: the first way is to adapt NB modules to OneNET (if you want to access OneNET platform, please click here). (https://open.iot.10086.cn/Partners/) The other way requires users to download ** SDK** of NB-IOT, and carry out corresponding development work by themselves. Plant in MCU of equipment.


If SDK has been successfully transplanted to MCU, the bootstrap server address, port number and endpoint name parameter (i.e. authentication information ** IMEI, IMSI and other information **) can be configured in MCU, and the bootstrap server UDP connection can be realized through SDK. After the connection is successfully established, the bootstrap server returns the LwM2M access server address and port.

The bootstrap server domain name is ** nbiotbt. heclouds. com ** port number is 5683.


** Step4 Establishes Protocol Connection between Equipment and Platform**

After the device acquires the address of the LwM2M access server in Step3, the device automatically completes the protocol connection with the platform.

If the connection is successful, you will see an online tag in the device information:
![pic](/images/LwM2M/设备在线.png)

** Step5 Device Resource List View**

After the device is online in Step4, you can access the device's resource list by clicking the "Resource List" button on the right for information viewing. After the device goes online, it uploads a list of resources to the platform, which can read, write, execute and subscribe to these resources.

In the resource list, you can see the object name, the number of instances and the number of attributes under the device.
![pic](/images/LwM2M/实例属性.png)

** Step6 Device Properties View, Resource Data Operation**

After you see the list of device resources in Step5, you can click on a specific object name to see the specific object instance and the attribute values under the object instance. On this page, we can read, write, execute and view the details of a specific property, and complete the actual operation of a specific property of the device.
![pic](/images/LwM2M/设备属性.png)

** Step7 Developing NB-IOT Applications in Combination with Practical Scenarios**
Through the above operation of Step1-6, we can realize the connection of specific NB-IOT devices, the view of resource list, the reading, writing and execution of object attributes, etc. to meet the development of the whole NB-IOT application under the NB environment.