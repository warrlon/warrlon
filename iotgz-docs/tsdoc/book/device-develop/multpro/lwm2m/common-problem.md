# NB-IoT Common Problems

## Revised Records


| Document Version Number | Revision Date | Revision Content | Description|
|:--|:--|:--|:--|
| V 1.1 | 2019.5.24 | New Construction | Li Chun, He Long|



## 1 Registration-related
### 1.1 Module correlation
#### 1. Can't the terminal connect to OneNET?

Answer: Please confirm whether the terminal is normally attached to the NB network. If the network is normally attached, then check whether the terminal connection message and authentication code are normal. If both are working properly, technicians can transfer from 4001-100-868 to 3 consulting platform.

#### 2. SDK Initialization Module Failed?

Answer: SDK will configure the working mode of the current module to attach to the NB network when it is started. The configuration is based on a series of AT instructions. It should be noted that each AT instruction needs a certain time to be processed by the module. Therefore, it is suggested that AT instructions can be delayed for several seconds, otherwise the initialization process will fail.

### 1.2 Authentication Failure
#### 1. The device can't connect to the platform. Return to 4.03?

Answer: 4.03 Forbidden means that the access machine fails to authenticate, and the access machine side-to-device authentication rules are as follows:
1) Authcode is used to authenticate according to EP if the device is not set up, and the incorrect EP results in the failure of authentication.
2) Authodcode is authenticated by EP + Authcode if the device is equipped with Authodcode. If EP and Authcode are incorrect or without Authcode parameters, authentication will fail.
3) Platform setting IP blacklist users will also lead to authentication failure.

> Note: Endpoint-Name (in the form of imei; semicolon in the middle of imsi), abbreviated as EP

### 1.3 Discover and Observer

#### 1. About the use of platform automatic subscription and manual subscription? (Equipment level)

Answer: Automatic subscription, when the device is online, the platform will actively issue subscription commands to the device. Manual subscription. After the device goes online, it is necessary to issue the subscription manually. The validity of this command is during one go-online period, and the next go-online need to re-subscribe.
Note: Equipment can only report data after subscribing.

#### 2. How does the device determine the success of the subscription?

Answer: The platform will send read 3/0 operation after all subscriptions have been completed. If the device receives the read command, it will be regarded as the success of all subscriptions.

#### 3. About the use of platform automatic discovery and manual discovery?

Answer: Discovered resources can be viewed in a specific resource list. Because the terminal resource list is not likely to change in general, due to low power considerations, the platform defaults to cancel the automatic discovery function for new products, making it unnecessary to issue the Discover command every registration. If users want to see a real-time resource list on the platform, they can send it manually.

> Note: Open/close automatic discovery can be set at the product level, while manually issuing discovery is a specific Instance under the corresponding Object.

#### 4. In which cases will the platform delete subscriptions?

Answer: Registration and offline will be deleted. If resources are deleted from the Update message, the platform will also remove subscriptions and delete them to Instance. If users subscribe to a resource through the platform, device registration and offline will be deleted separately to the corresponding resource.
Data reporting

## Update, Notify

#### 1. Understanding of Update Report on Platform Update Resources

Answer: When the access machine receives the device's Update message, it updates the device's Lifetime, then compares the object instance content contained in Linkobject in Update with the previous resource, clears the old object instance contained in the original resource but not included in Update, cancels the corresponding subscription, adds the new object instance in Update and sends the device registration to the new object instance. Operations (Observer, Discover)

#### 2. After the platform deletes the device, the device can still send data to the platform?

Answer: No. Because the platform retains the cache information of device registration, it may appear that after the online device is deleted, it can still receive the data sent to the platform and receive the correct response. If the device's Lifetime is very long, the device can report the data during the Lifetime period. When the next update information is sent, the platform will delete the device in time.

#### 3. Notify about the platform display receiving device, but the display device does not exist?

Answer: Maybe the equipment is not up date in time, and the platform has eliminated the equipment.

#### 4. Can the device report data when it is offline?

Answer: After receiving the data reported by the offline device, the platform will send Rst to prevent the device from going up again.

#### 5. The device did not report any information during the Lifetime cycle. Why does the platform display the device online?

Answer: According to the mechanism of judging equipment off-line by platform, the online status display of equipment may be delayed to a certain extent, about one point.

#### 6. How much can the maximum Lifetime be set and how long is the general setting reasonable?

Answer: The maximum value of 32-bit module Lifetime is 2 ^ 32-1 (S). How long the life cycle is set depends on the use of the equipment. If you don't use online commands, you can set any settings. If you want to use online commands and Notify frequency is very low, it is recommended that within 5 minutes.

#### 7. Why is the device offline on the OneNET portal page?

Answer: The online status of the device is only related to the expiration of Lifetime. A parameter of Lifetime device connection (Register) is in seconds. If it is not specified, it defaults to 86400. When Lifetime expires, the platform kicks the device off the line. At this time, the device can not report data and can only reconnect (Register). The device can extend Lifetime by sending Register Update messages when Lifetime is not expired.

#### 8. Upload data continuously, and only one data is saved to the platform every 5 minutes?

Answer: The CoAP protocol filters duplicate messages through Message ID and Token. For packets that report (Notify), if the subscription paths are the same, Token will be the same. If Message ID remains unchanged, it will be filtered as duplicate messages. Duplicate message filtering time window is 247 seconds, that is, the first message is processed, within 247 seconds duplicate messages will be filtered.

#### 9. The uploaded Integer / Float / string data is displayed in [10, 100, 123] format?

Answer: There is no standard resource model defined by IPSO. For Object ID and Resource ID of non-IPSO model, if the platform can not judge the data type of resources, it will be processed according to binary system.

## 3 Data downlink
### 3.1 Read, Write and Execute

#### 1. Read to Resource and Read to Instance, the format of data reporting?

Answer: Plain / Text is used to report to Resource, and Tlv format is used to report to Instance.

#### 2. The device sends commands. Before the device does not have Notify, the device receives Acsii code. After reporting, it can receive data correctly.

Answer: This is because the module does not know the type of resource. When the device reports Notify, the module declares the type of resource. After receiving the write command of the corresponding platform for the corresponding resource, it can correctly translate and change the type of resource and receive the data correctly. When you don't know the resource type, you treat it as an Opaque type, so you see the Ascii code.

#### 3. The problem of timeout often occurs when data is sent next, but it does not occur when data is interacted with each other.

Answer: If there is no upstream data for a long time, the core network will kick off the previously cached connection information. The routing can not find the device, so it will lead to timeout.

#### 4. Will the device receive a reply when it sends Con messages to the platform?

Answer: After receiving any Con message, the access machine will reply to Ack. The normal message goes through the normal process. The abnormal Con message, the access opportunity discards the message, but it will also send Ack or Rst.

### 3.2 Use of downlink data Api

#### 1. About the time_out of the API and the number of retries?

Answer: The default setting is 25s, which can be set by api, ranging from 5 to 40s.
Taking the default time out of 25s as an example, the platform will retry when the first download timeout (no reply is received within 5-7.5s). The next timeout is twice as long as the first one, so the second retry time is 10s (assuming the first retry is 5s) and the third is 20s. Therefore, within the default 25s, the platform will try twice at most and issue three times altogether.
The time-out applied to equipment is actually the time-out from platform to equipment, because the normal communication time applied to platform is negligible.
Use a flow chart to describe the above process:
 ![Downstream process](/images/LwM2M/downdata.png)


#### 2. The difference between the parameter mode = 1 or 2 in write?

Answer: If mode is 1, it is equivalent to overwriting operation. It will delete all the previous resources and values, and only retain the current written resources and values. 2 is equivalent to updating, resetting or adding resources, which will retain the previous resources and values.

#### 3. When the device is online, call the resource list interface and return empty?

Answer: When discover is issued under the platform, the cached resource list will be emptied and the normal call can continue after the device replies.

#### 4. What is the maximum length of command content issued under the platform?

Answer: The current limit is 2Kb.

## 4 caching commands

#### 1. Is there a limit on the number of downlink instructions cached by OneNet, and how many downlink instructions can be cached at most?

A: At present, there are 10 restrictions.

#### 2. Does OneNet provide an API to clear all caching instructions accumulated on OneNet by an IMEI device?

Answer: At present, it can only be deleted through uuid.

#### 3. How do caching commands trigger?

Answer: Cache commands are triggered when an upstream message arrives, such as registration, update, notify. Now the cache commands can also set the type of upstream commands triggered.

## 5FOTA correlation

#### 1. What is the time-out for pushing firmware packages?

Answer: The total overtime time time of packages is 20 minutes, and that of single packages is about 2 minutes.

#### 2. In fota, why do devices receive multiple discoveries from the platform?

Answer: This is a common problem, not only in fota, but also in updates when devices update resource categories, and the platform rediscovers discoveries.

#### 3. Was the cancellation unsuccessful?

Answer: When cancelled, the platform will issue erase instructions, but the instructions will be issued when the upstream data is received. If the heartbeat is set too long, it may take some time.

#### 4. What are the requirements for a module to use platform FOTA capabilities?

Answer: First of all, the module itself has the capability of firmware upgrade. Secondly, we recommend using the SDK we provide.

## 6SOTA correlation

#### 1. The difference between platform FOTA and SOTA?

Answer: FOTA is used to upgrade module firmware remotely, while SOTA is used to upgrade software in MCU remotely.

## 7 Data push

#### 1. Will the platform push all notify to third-party applications?

Answer: Yes, nbiot has no data stream template and will push it all.

#### 2. When there are multiple resources under the obj of data reporting, is the platform pushed to the third-party application platform at one time?

Answer: Three resources are equivalent to three data streams. Data push will still be pushed by bar, which is equivalent to pushing three data points over. Of course, you can also set the number of single pushes, perhaps including these three values.

#### 3. What does it mean to stop pushing when data pushing fails more than 2000 times?

Answer: The 2000 times here are not just retransmitted, but the cumulative number of failed Onnet push (including retransmitted) is 2000 times.

#### 4. If the push address is not reachable, will OneNET cache the data?

Answer: If the number of push failures does not exceed 2000, the platform will retry the data that has not been successfully pushed, which is equivalent to caching. If more than 2,000 times, OneNET will stop pushing and discard the data points between the stop pushing and the recovery pushing (where discarding means not pushing to the application platform, data will still be stored on the platform and can be obtained through the api). When the push address is available, OneNET will push out the latest data points of the device.

## 8 Other issues

#### 1. Does the platform support DTLS encryption transmission?

Answer: Current platform only supports DTLS encryption based on PSK (using Coaps and 5684 ports to connect), and will support DTLS encryption based on public key and X.509 Certificate in the future.

#### 2. Use of custom data?

Answer: The platform data model follows the IPSO specification, and developers can create resources by themselves. The data type of the custom resource will be changed to Opaque type. At present, the page can display the value of the resource, but it can not read, write and execute the operation of the custom resource on the page. It needs to call the corresponding Api interface to complete.

#### 3. Does Light Map Support NB-IoT Location? How to use it?

A: Support. When the device notify, you can use the following two obj resources to report longitude and latitude: object ID is 6, resource id: 0 (latitude), 1 (longitude)
Objectid 3336, resource id: 5513 (latitude), 5514 (longitude)
Select the data stream named "location" in the corresponding device in the map.
Note: Both resources need to be reported at the same time, under an instance