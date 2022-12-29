- [OneNET Internet of Things Platform](README.MD)
- [Platform Introduction](readme.md)
    - [Platform Profile](/book/introduce/introduce.md)
    - [Platform Architecture](/book/introduce/architecture.md)
    - [Resource Model](/book/introduce/resource-model.md)
    - [Terminological Interpretation](/book/introduce/term.md)
- [Introduction manual](readme.md)
    - [Account and login](/book/easy-manual/login.md)
    - [Products and Equipment](readme.md)
        - [Create a product](/book/easy-manual/product&device/product-create.md)
        - [Introduction to Access Protocol](/book/easy-manual/product&device/protocal-introduce.md)
        - [Create device](readme.md)
            - [Create a single device](/book/easy-manual/product&device/device-create/single-device.md)
            - [Batch creation device](/book/easy-manual/product&device/device-create/batch-devcie.md)
        - [Export device](/book/easy-manual/product&device/batch-export.md)
    - [Data Stream and Data Point](/book/easy-manual/datastream&point.md)
    - [Application Management](readme.md)
        - [Introduction to Services](/book/easy-manual/application-manage/1.md)
        - [Introduction to Controls](/book/easy-manual/application-manage/2.md)
        - [Instructions for operation](/book/easy-manual/application-manage/3.md)
    - [Message queue (public beta)](/book/easy-manual/mq.md)
    - [HTTP push](/book/easy-manual/httppush.md)
    - [Security Authentication](/book/easy-manual/auth.md)
- [Instruction for Equipment Development](readme.md)
    - [Protocol Document](/book/device-develop/multpro/sdk-doc-tool/doc.md)
    - [SDK](/book/device-develop/multpro/sdk-doc-tool/sdk.md)
    - [Debugging Tool](/book/device-develop/multpro/sdk-doc-tool/tool.md)
    - [Device Cloud APP Download](/book/device-develop/multpro/sdk-doc-tool/app.md)
    - [Multiprotocol Access](readme.md)
        - [LwM2M](readme.md)
            - [Introduction to Protocol](/book/device-develop/multpro/LwM2M/introduce.md)
            - [Access instructions](/book/device-develop/multpro/LwM2M/LwM2M-manual.md)
            - [List of supported modules](/book/device-develop/multpro/LwM2M/module-list.md)
            - [NB Frequent Questions](book/device-develop/multpro/LwM2M/common-problem.md)
            - [Access instance (M5310)](book/device-development/multpro/LwM2M/nbdeviceaccessinstance_LwM2M_basedonm5310_module.md)
            - [Access instance (MCU)](book/device-development/multpro/LwM2M/nbdeviceaccessinstance_LwM2M_basedonmcu.md)
        - [MQTTS（Beta）](readme.md)
            - [Protocol Specification](/book/device-develop/multpro/mqtts/protocol.md)
            - [Equipment Development Guide](/book/device-develop/multpro/mqtts/devevop-manual.md)
            - [Topic Cluster](readme.md)
                - [Overview](/book/device-develop/multpro/mqtts/topics/introduce.md)
                - [Topic cluster of data points](/book/device-develop/multpro/mqtts/topics/dp-topics.md)
                - [Topic cluster of device commands](/book/device-develop/multpro/mqtts/topics/cmd-topics.md)
                - [Device Mirror Topic Cluster](/book/device-develop/multpro/mqtts/topics/image-topics.md)
            - [Access instance](readme.md)
                - [Device Connection](/book/device-develop/multpro/mqtts/example/connect.md)
                - [Upload data points](/book/device-develop/multpro/mqtts/example/datapoints.md)
            - [API](readme.md)
                - [Device command](/book/device-develop/multpro/mqtts/api/synccmds.md)
        - [MQTT](readme.md)
            - [Introduction to protocols](/book/device-develop/multpro/mqtt/introduce.md)
            - [Access note](/book/device-develop/multpro/mqtt/mqtt-manual.md)
        - [EDP](readme.md)
            - [Introduction to Protocol](/book/device-develop/multpro/edp/introduce.md)
            - [Access note](/book/device-develop/multpro/edp/edp-manual.md)
        - [Modbus](readme.md)
            - [Introduction to protocols](/book/device-develop/multpro/modbus/introduce.md)
            - [Access instructions](/book/device-develop/multpro/modbus/modbus-manual.md)
        - [TCP](readme.md)
            - [Introduction to Protocol](/book/device-develop/multpro/tcp/introduce.md)
            - [Access Description](/book/device-develop/multpro/tcp/tcp-manual.md)
    - [OTA upgrade](readme.md)
        - [OTA instructions](/book/device-develop/ota/otainstructions.md)
        - [OTA-API usage example](/book/device-develop/ota/ota-api-instruction.md)
        - [South-to-South API](readme.md)
            - [Detection and Upgrade Task](/book/device-development/ota/southboundapiinterface/1detectionandupgradetask.md)
            - [chek interface](/book/device-development/ota/southboundapiinterface/2tokencheck.md)
            - [Access Resource Interface](/book/device-development/ota/southboundapiinterface/3accessresourceinterface.md)
            - [Update Upgrade Status](/book/device-development/ota/southwardapiinterface/4updatestatus.md)
        - [OTA-SDK instructions](/book/device-develop/ota/ota-sdk-instruction.md)
- [Application Development Guide](readme.md)
    - [API](readme.md)
        - [API usage](/book/application-develop/api/api-usage.md)
        - [API list](/book/application-develop/api/api-list.md)
        - [SDK](/book/application-develop/api/sdk.md)
        - [MQTT](readme.md)
            - [Additional equipment](/book/application-development/api/mqtt/1.additionalequipment.md)
            - [Registration device](/book/application-development/api/mqtt/2.registrationdevice.md)
            - [Update device](/book/application-development/api/mqtt/3.updatedeviceinformation.md)
            - [Query device details](/book/application-development/api/mqtt/4.querydevicedetails.md)
            - [Batch query device details](/book/application-development/api/mqtt/5.batchquerydeviceinformation.md)
            - [batch query device status](/book/application-development/api/mqtt/6.batchquerydevicestatus.md)
            - [Delete devices](/book/application-development/api/mqtt/7.deletedevices.md)
            - [New Data Flow](/book/application-development/api/mqtt/8.newdataflow.md)
            - [Update Data Flow](/book/application-development/api/mqtt/9.updatedataflowproperties.md)
            - [Query Data Flow](/book/application-development/api/mqtt/10.querydataflowdetails.md)
            - [Batch Query Data Flow](/book/application-development/api/mqtt/11.batchquerydataflowinformation.md)
            - [Delete data streams](/book/application-development/api/mqtt/12.deletedatastreams.md)
            - [Query device history data](/book/application-development/api/mqtt/13.querydevicehistorydata.md)
            - [batch query device data](/book/application-development/api/mqtt/14.batchquerydevicelatestdata.md)
            - [Upload Data Points](/book/application-development/api/mqtt/15.uploaddatapoints.md)
            - [Upload file](/book/application-development/api/mqtt/16.uploadfile.md)
            - [Get files](/book/application-development/api/mqtt/17.getfiles.md)
            - [Send commands](/book/application-development/api/mqtt/sendcommands.md)
            - [Query command status](/book/application-development/api/mqtt/19.querycommandstatus.md)
            - [Query command response](/book/application-development/api/mqtt/20.querycommandresponse.md)
            - [Query device history command](/book/application-development/api/mqtt/21.querydevicehistorycommand.md)
            - [New triggers](/book/application-development/api/mqtt/26.newtriggers.md)
            - [Update trigger](/book/application-development/api/mqtt/27.updatetrigger.md)
            - [Query trigger](/book/application-development/api/mqtt/28.querytrigger.md)
            - [Delete triggers](/book/application-development/api/mqtt/29.deletetriggers.md)
            - [New apikey](/book/application-development/api/mqtt/22.newapikey.md)
            - [Update apikey](/book/application-development/api/mqtt/23.updateapikey.md)
            - [Query apikey](/book/application-development/api/mqtt/24.queryapikey.md)
            - [Delete apikey](/book/application-development/api/mqtt/25.deleteapikey.md)
            - [Publish message](/book/application-development/api/mqtt/publishmessage.md)
            - [Query Subscription Topic Device](/book/application-development/api/mqtt/querysubscriptiontopicdevice.md)
            - [Query device subscription topic](/book/application-development/api/mqtt/querydevicesubscriptiontopic.md)
            - [Query product topic](/book/application-development/api/mqtt/queryproducttopic.md)
        - [LwM2M](readme.md)
            - [Create Devices](/book/application-development/api/LwM2M/1createdevices.md)
            - [Query device](/book/application-development/api/LwM2M/2viewsingledevice.md)
            - [Delete device](/book/application-development/api/LwM2M/3deletedevice.md)
            - [Get a list of resources](/book/application-development/api/LwM2M/7getalistofresources.md)
            - [Subscription](/book/application-development/api/LwM2M/8subscription.md)
            - [Instant command-read device resource](/book/application-develop/api/LwM2M/4instantcommand-readdeviceresource.md)
            - [Cache command-read device resource](/book/application-develop/api/LwM2M/9cachecommand-readdeviceresource.md)
            - [Instant command-write device resource](/book/application-development/api/LwM2M/5instantcommand-writedeviceresource.md)
            - [Cache command-write device resource](/book/application-develop/api/LwM2M/10cachecommand-writedeviceresource.md)
            - [Instant command-command issuance](/book/application-development/api/LwM2M/6instantcommand-commandissuance.md)
            - [Cache command-command issuance](/book/application-development/api/LwM2M/11cachecommand-commandissuance.md)
            - [View the list of device cache commands](/book/application-development/api/LwM2M/12viewthelistofspecifieddevicecachecommands.md)
            - [See the details of the specified cache command](/book/application-development/api/LwM2M/13toseethedetailsofthespecifiedcachecommand.md)
            - [Cancel Caching Command](/book/application-development/api/LwM2M/14cancelcachingcommand.md)
            - [New triggers](/book/application-development/api/LwM2M/15newtriggers.md)
            - [Update trigger](/book/application-development/api/LwM2M/16updatetrigger.md)
            - [View triggers](/book/application-development/api/LwM2M/17viewtriggers.md)
            - [Delete triggers](/book/application-development/api/LwM2M/18deletetriggers.md)
            - [batch query device status](/book/application-development/api/LwM2M/19batchquerydevicestatus.md)
            - [batch query device data](/book/application-development/api/LwM2M/20batchquerydevicelatestdata.md)
            - [View Data Points](/book/application-development/api/LwM2M/21viewdatapoints.md)
            - [Query device information](/book/application-development/api/LwM2M/22querydeviceinformationaccordingtoimei.md)
            - [View device bs_psk](/book/application-development/api/LwM2M/23viewdevicebs_psk.md)
            - [Update bs_psk](/book/application-development/api/LwM2M/24updatebs_psk.md)
            - [Added acc_psk](/book/application-development/api/LwM2M/25addedacc_psk.md)
            - [Edit acc_psk](/book/application-development/api/LwM2M/26editacc_psk.md)
            - [View device acc_psk](/book/application-development/api/LwM2M/27viewdeviceacc_psk.md)
        - [EDP](readme.md)
            - [Additional equipment](/book/application-development/api/edp/1.additionalequipment.md)
            - [Registered Equipment](/book/application-development/api/edp/2.registeredequipment.md)
            - [Update device](/book/application-development/api/edp/3.updatedeviceinformation.md)
            - [Query device details](/book/application-development/api/edp/4.querydevicedetails.md)
            - [Batch inquiry device details](/book/application-development/api/edp/5.batchinquirydeviceinformation.md)
            - [batch query device status](/book/application-development/api/edp/6.batchquerydevicestatus.md)
            - [Delete device](/book/application-development/api/edp/7.deletedevice.md)
            - [Additional data streams](/book/application-development/api/edp/8.additionaldatastreams.md)
            - [Update Data Stream](/book/application-development/api/edp/9.updatedatastreamproperties.md)
            - [Query Data Flow](/book/application-development/api/edp/10.querydataflowdetails.md)
            - [Batch Query Data Flow](/book/application-development/api/edp/11.batchquerydataflowinformation.md)
            - [Delete data streams](/book/application-development/api/edp/12.deletedatastreams.md)
            - [Query device history data](/book/application-development/api/edp/13.querydevicehistorydata.md)
            - [batch query device data](/book/application-development/api/edp/14.batchquerydevicelatestdata.md)
            - [Upload Data Points](/book/application-development/api/edp/15.uploaddatapoints.md)
            - [Upload file](/book/application-development/api/edp/16.uploadfile.md)
            - [Get files](/book/application-development/api/edp/17.getfiles.md)
            - [Send commands](/book/application-development/api/edp/sendcommands.md)
            - [Query command status](/book/application-development/api/edp/19.querycommandstatus.md)
            - [Query command response](/book/application-development/api/edp/20.querycommandresponse.md)
            - [Query device history command](/book/application-development/api/edp/21.querydevicehistorycommand.md)
            - [New trigger](/book/application-development/api/edp/26.newtrigger.md)
            - [Update trigger](/book/application-development/api/edp/27.updatetrigger.md)
            - [Query trigger](/book/application-development/api/edp/28.querytrigger.md)
            - [Delete triggers](/book/application-development/api/edp/29.deletetriggers.md)
            - [Added apikey](/book/application-development/api/edp/22.addedapikey.md)
            - [Update apikey](/book/application-development/api/edp/23.updateapikey.md)
            - [Query apikey](/book/application-development/api/edp/24.queryapikey.md)
            - [Delete apikey](/book/application-development/api/edp/25.deleteapikey.md)
        - [Modbus](readme.md)
            - [Additional equipment](/book/application-development/api/modbus/1.additionalequipment.md)
            - [Update device](/book/application-development/api/modbus/3.updatedeviceinformation.md)
            - [Query device details](/book/application-development/api/modbus/4.querydevicedetails.md)
            - [Batch query device details](/book/application-development/api/modbus/5.batchquerydeviceinformation.md)
            - [batch query device status](/book/application-development/api/modbus/6.batchquerydevicestatus.md)
            - [Delete device](/book/application-development/api/modbus/7.deletedevice.md)
            - [Additional data streams](/book/application-development/api/modbus/additionaldatastreams.md)
            - [Update Data Stream](/book/application-development/api/modbus/updatedatastreamproperties.md)
            - [Query Data Flow](/book/application-development/api/modbus/querydataflowdetails.md)
            - [batch query data flow](/book/application-development/api/modbus/11.batchquerydataflowinformation.md)
            - [Delete data streams](/book/application-development/api/modbus/12.deletedatastreams.md)
            - [Query device history data](/book/application-development/api/modbus/13.querydevicehistorydata.md)
            - [batch query device data](/book/application-development/api/modbus/14.batchquerydevicelatestdata.md)
            - [Upload Data Points](/book/application-development/api/modbus/15.uploaddatapoints.md)
            - [Send commands](/book/application-development/api/modbus/sendcommands.md)
            - [Query command status](/book/application-development/api/modbus/19.querycommandstatus.md)
            - [Query command response](/book/application-development/api/modbus/20.querycommandresponse.md)
            - [Query device history command](/book/application-development/api/modbus/21.querydevicehistorycommand.md)
            - [New trigger](/book/application-development/api/modbus/26.newtrigger.md)
            - [Update trigger](/book/application-development/api/modbus/27.updatetrigger.md)
            - [Query trigger](/book/application-development/api/modbus/28.querytrigger.md)
            - [Delete triggers](/book/application-development/api/modbus/29.deletetriggers.md)
            - [New apikey](/book/application-development/api/modbus/22.newapikey.md)
            - [Update apikey](/book/application-development/api/modbus/23.updateapikey.md)
            - [Query apikey](/book/application-development/api/modbus/24.queryapikey.md)
            - [Delete apikey](/book/application-development/api/modbus/25.deleteapikey.md)
        - [TCP](readme.md)
            - [Additional devices](/book/application-development/api/tcp/1.additionaldevices.md)
            - [Registered Device](/book/application-development/api/tcp/2.registereddevice.md)
            - [Update device](/book/application-development/api/tcp/3.updatedeviceinformation.md)
            - [Query device details](/book/application-development/api/tcp/4.querydevicedetails.md)
            - [Batch Query Device Details](/book/application-development/api/tcp/5.batchquerydeviceinformation.md)
            - [batch query device status](/book/application-development/api/tcp/6.batchquerydevicestatus.md)
            - [Delete device](/book/application-development/api/tcp/7.deletedevice.md)
            - [Additional data streams](/book/application-development/api/tcp/8.additionaldatastreams.md)
            - [Update Data Stream](/book/application-development/api/tcp/9.updatedatastreamproperties.md)
            - [Query Data Flow](/book/application-development/api/tcp/10.querydataflowdetails.md)
            - [Batch Query Data Flow](/book/application-development/api/tcp/11.batchquerydataflowinformation.md)
            - [Delete data streams](/book/application-development/api/tcp/12.deletedatastreams.md)
            - [Query device history data](/book/application-development/api/tcp/13.querydevicehistorydata.md)
            - [batch query device data](/book/application-development/api/tcp/14.batchquerydevicelatestdata.md)
            - [Upload Data Points](/book/application-development/api/tcp/15.uploaddatapoints.md)
            - [Upload file](/book/application-development/api/tcp/16.uploadfile.md)
            - [Get files](/book/application-development/api/tcp/17.getfiles.md)
            - [Send commands](/book/application-development/api/tcp/sendcommands.md)
            - [Query device history command](/book/application-development/api/tcp/21.querydevicehistorycommand.md)
            - [Additional triggers](/book/application-development/api/tcp/26.additionaltriggers.md)
            - [Update trigger](/book/application-development/api/tcp/27.updatetrigger.md)
            - [Query Trigger](/book/application-development/api/tcp/28.querytrigger.md)
            - [Delete triggers](/book/application-development/api/tcp/29.deletetriggers.md)
            - [New apikey](/book/application-development/api/tcp/22.newapikey.md)
            - [Update apikey](/book/application-development/api/tcp/23.updateapikey.md)
            - [Query apikey](/book/application-development/api/tcp/24.queryapikey.md)
            - [Delete apikey](/book/application-development/api/tcp/25.deleteapikey.md)
    - [Message queue MQ (public beta)](readme.md)
        - [Overview of Services](/book/application-develop/mq/introduce.md)
        - [Development Guide](/book/application-develop/mq/develop-manual.md)
        - [Regular expression filtering rules](/book/application-develop/mq/rule.md)
        - [demo project](/book/application-develop/mq/demo-project.md)
        - [Best case](/book/application-develop/mq/example.md)
        - [Use restrictions](/book/application-develop/mq/limit.md)
    - [HTTP push](readme.md)
        - [Overview of Services](/book/application-develop/httppush/introduce.md)
        - [Development Guide](/book/application-develop/httppush/develop-manual.md)
        - [SDK](/book/application-develop/httppush/sdk.md)
- [Service pricing](readme.md)
    - [Location capability](/book/price-service/lbs.md)
    - [Message Queue MQ](book/price-service/mq.md)
- [Extended Services](readme.md)
    - [Video Service](readme.md)
        - [Introduction to Services](/book/other-service/onenet-video/introduce.md)
        - [Main Functions](/book/other-service/onenet-video/function.md)
        - [Manual for the Use of the Management Console](/book/other-service/onenet-video/control.md)
        - [API](/book/other-service/onenet-video/API.md)
        - [Device SDK](/book/other-service/onenet-video/device-sdk.md)
        - [SDK usage example](/book/other-service/onenet-video/sdkdemo.md)
        - [Introduction to Development Board](/book/other-service/onenet-video/board.md)
        - [Development Board Live Experience](/book/other-service/onenet-video/boarduse.md)
        - [Android-SDK Push End Description](/book/other-service/onenet-video/android-sdkpush.md)
        - [Android-SDK Player Description](/book/other-service/onenet-video/android-sdkplay.md)
    - [Location Services](readme.md)
        - [Introduction to Services](/book/other-service/onenet-lbs/introduce.md)
        - [API](/book/other-service/onenet-lbs/API.md)
    - [Device Management Service (DMP)](readme.md)
        - [Service introduction](/book/other-service/device-manage-service/introduce.md)
        - [Log query](/book/other-service/device-manage-service/logquery.md)
        - [API](readme.md)
            - [Card Relation Binding](/book/other-service/device-management-service/api/1cardrelationbinding.md)
            - [Machine Card Relational Query](/book/other-service/device-management-service/api/2machinecardrelationalquery.md)
            - [Card relationship deletion](/book/other-service/device-management-service/api/3cardrelationshipdeletion.md)
            - [Machine Card Relation Modification](/book/other-service/device-management-service/api/4machinecardrelationmodification.md)
            - [Union of Things Card Business Data Query](/book/other-service/device-management-service/api/5unionofthingscardbusinessdataquery.md)
    - [Short Message Service](readme.md)
        - [Development process](/book/other-service/onenet-sms/develop.md)
        - [Call description](/book/other-service/onenet-sms/request.md)
        - [API](readme.md)
            - [Special note](/book/other-service/onenet-sms/api/notice.md)
            - [Text messaging](/book/other-service/onenet-sms/api/smssend.md)
            - [Status report acquisition](/book/other-service/onenet-sms/api/getstatus.md)
            - [Uplink message reception](/book/other-service/onenet-sms/api/receive.md)
        - [Code Example](readme.md)
            - [C#](/book/other-service/onenet-sms/demo/csharp.md)
            - [HTML](/book/other-service/onenet-sms/demo/HTML.md)
            - [Java](/book/other-service/onenet-sms/demo/JAVA.md)
- [Frequent Questions](readme.md)
    - [Platform address list](/book/problem/platformaddress.md)
    - [Technical class](/book/problem/faq.md)
    - [Business class](/book/problem/business.md)
    - [OCP class](/book/problem/ocp.md)
    - [Development Board Application Class](/book/problem/boardapply.md)
    - [Development Board Technology Class](/book/problem/board.md)
- [Announcement](readme.md)
    - [2019-01](/book/release/201901.md)
    - [2019-02](/book/release/201902.md)
    - [2019-03](/book/release/201903.md)