# Instructions for the Use of OTA Services

The remote upgrade OTA function provides the capability of remote upgrade for terminals. It can upgrade module firmware and MCU application software. At present, the general OTA service of OneNET platform provides upgrade package version management and differential generation, equipment grouping management, upgrade package task strategy configuration, upgrade task status modification, equipment upgrade status viewing and other functions. After configuring the platform, terminals need to cooperate with other related tasks to complete the task of checking and upgrading, pulling upgrade files and reporting upgrade status.
![dmp home page](/images/OTA/升级流程.png)

If you have any questions, please apply for technical support first (https://open.iot.10086.cn/questionnaire/show/441f4a7819df17d0e101bb9c1b23ab75).


### Page operation steps:

Step 1. Register / log on to OneNET platform https://open.iot.10086.cn

Step 2. Click on the device management module and enter the MDP management module.
![dmp home page](/images/OTA/dmp.png)

Step 3. Select OTA upgrade in the left navigation bar and click FOTA upgrade.
![ota](/images/OTA/OTA.png)

Step 4. Select firmware management, click Add firmware version, enter firmware information, upload firmware information in the Add firmware dialog box.
![ota](/images/OTA/addpakge.png)

 > Description:

        (a) Choose the manufacturer's name and model according to the module used by the equipment (if you don't have one in the drop-down box, you can contact 18883296390 or choose another)
        B) Target version, firmware version number, support only English letters, numbers, dots, connectors and underscores, length is 1-50 characters.
        C) Version package: optional, full package name can not contain Chinese characters.

 ![ota](/images/OTA/managepakge.png)

Step 5. Add differential packages, select "Add differential packages" under a firmware package, add differential packages dialog box, select the initial version number, and upload upgrade packages.
![ota](/images/OTA/adddf.png)

> Description: (in case of differential packet upgrade)

        (a) Initial version: the current version number of the device to be upgraded;
        B) Target version: version number after successful upgrade of equipment;
        C) Upload upgrade packages: If users have differential packages in their hands, they can choose to upload them directly (at this time, the device side gets differential packages, reverting to full packages requires users to implement themselves);
        If users do not have differential packages, they can choose online differential. In this case, after downloading upgrade packages, devices need to use OneNET platform to provide SDK for differential restore.

![ota](/images/OTA/managedfpakge.png)

Step 6. Add Upgrade Task: Select Upgrade Task Management, click Add Upgrade Task, and in the Add Upgrade Task Dialog Box, select the equipment, upgrade package and upgrade strategy that need to be upgraded.
![ota](/images/OTA/addtask.png)

> Description:

        A) Upgrade Name: Support Chinese, Numbers, Letters, Spaces already-! @#%... &* Equivalent symbols;
        B) Choose upgrade packages: here you can choose the complete package (the initial version is "Before Version") or the differential package (the initial version is not "Before Version");
        C) Drop-down selection of upgraded products;
        D) Select the device, you can select the designated device or group;
        (e) Pull-down selection of signal strength: This value will be returned to the device successfully in the inspection task, with the device to determine whether the current device signal meets the upgrade requirements;
        F) Drop-down percentage of residual power: This value will be returned to the equipment successfully in the inspection task, with the equipment to determine whether the current equipment capacity meets the upgrade requirements;
        G) Retry strategy: This value will be returned to the device successfully in the check task, and the device will determine whether the current device is retried or not.
        H) Execution strategy: There are two options: start execution and custom time, start execution needs to manually click start task; custom time is the specified time, then it is automatic start task.
        I) Deadline: Task termination time, when the task deadline arrives, will terminate all equipment upgrade.

Step 7. Click Start Task: If you add an upgrade task, the selected execution strategy is "Start Execution", you need to click Start Task on the page.
![ota](/images/OTA/sarttask.png)
Up to now, the upgrade task has been completed. The next step is to detect the upgrade task and pull the upgrade package for upgrade.

### Equipment-side operation
The following operations are performed on the device side (south)

Devices and platforms interact with each other in HTTP RESTful standard format. Interfaces are authenticated through Authorization. Authorization is provided in Section[Security Authentication](/book/easy-manual/auth.md).

Step 8. Detection and Upgrade Tasks

    [Detection and Upgrade Task Interface](/book/device-development/OTA/southboundAPIInterface/1DetectionandUpgradeTask.md)

Step 9. token check

    If the upgrade task is checked successfully in the previous step, and the information about the task and the upgrade package is obtained, when the device pulls the upgrade package, OneNET platform checks through token, and the token returned in the previous step is only valid for 48 hours, so it is better for customers here to check whether token is valid in advance. The following interfaces are validation interfaces:
    [token check interface](/book/device-development/OTA/southboundAPIinterface/2tokencheck.md)

Step 10. Pull Upgrade Pack

    If token detection is successful, the next step is to get the upgrade package from the platform. The following interface completes the download of the upgrade package and supports the fragmented download.
[Access Resource Interface](/book/device-development/OTA/southboundAPIinterface/3AccessResourceInterface.md)

Step 11. Upgrade status reported

    During the upgrade process, the device needs to report the upgrade status actively, using the following interface
    [Update Upgrade Status Interface](/book/device-development/OTA/SouthwardAPIInterface/4UpdateStatus.md)