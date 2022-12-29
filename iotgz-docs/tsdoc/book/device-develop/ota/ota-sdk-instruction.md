# Instructions for the use of OTA SDK

## 1 user routine
OTA's user routine is the sample folder, which corresponds to the OtaSample project in the VS project. The functions involved are:

| Function Name | Function Description | Parameters and Remarks|
|:-|:-|:-|
| ota_init | OTA context initialization function | check_time: Check the interval between upgrade tasks in seconds|
| ota_loop | OTA logic control function | check_now: Check for upgrade task < br > Note: Periodic calls are required|
| ota_deinit | OTA Context Destruction Function | Note: This function should be called to clear the associated memory space after the completion of the OTA process|

## 2 logical control

The logical control function and related function files of OTA are core folders, which correspond to CMIOT-OTA project in VS project. The files and secondary folders in the core folder are:

| File or Folder Name | Description|
|:-|:-|
| ota_core.c | contains OTA logic control function and function function|
| ota_parse.c | contains parsing message control function|
| ota_api.h | OTA external header file|
| ota_internal.h | OTA internal header file|
| cjson / JSON parsing component|
| http/| HTTP message parsing component|
| mbedtls/| HMAC Signature Encryption Component|

In the ota_core.c file, the logic control function of Ota and its related analytical function are included.

| Function Name | Function Description | Parameters and Remarks|
|:-|:-|:-|
| OTA_Pack_Check_Task | Query Task API Group Package | None|
| OTA_Pack_Check_Token | Token Test API Group Package | None|
| OTA_Pack_Get_Package | Get File API Group Package | None|
| OTA_Pack_Report | Report Status API Group Package | No|
| OTA_Pack_Authorization_Info | Authorization parameter calculation and package grouping | None|
| OTA_CHECK_DEVICE | Check whether the equipment is upgraded or not | Note: Before downloading the upgrade package, check whether the power and signal strength < br> meet the preset conditions.

## 3 adapter interface

The adapter interface of OTA is located in the adapter folder, which corresponds to the OtaAdapter project in the VS project. The interface is divided into two parts: the system interface and the network interface. The functions involved in the system interface are as follows:

| Function Name | Function Description | Parameters and Remarks|
|:-|:-|:-|
| OTA_Event_Handle | OTA event trigger function | None|
| ota_log_printf | log printing | no|
| ota_atoi | String Conversion Shaping | None|
| ota_itoa_decimal | decimal integer to string | none|
| ota_hex 2str | hexadecimal string | Note: Convert the MD5 calculation results into strings for comparison|
| ota_malloc | Memory application | No|
| ota_free | memory release | no|
| ota_get_tick | Get system run time | Note: Used for timing|
| ota_get_device ID | Get device ID | No|
| ota_get_manuf | Get the manufacturer number | No|
| ota_get_model | Get module number | None|
| ota_get_type | Get upgrade type | Note: 1 for FOTA task, 2 for SOTA task|
| ota_get_version | Get the current version | None|
| ota_get_signals | Get signal strength | No|
| ota_get_powers | Get battery power | No|
| ota_get_auth_version | Get Authentication Version | Note: The current Authentication Version is fixed to "2018-10-31"|
| ota_get_auth_res | Get res | Note: In the current SDK, both get product ID|
| ota_get_auth_et | Acquisition authentication expiration time | Note: UNIX time|
| ota_get_auth_method | Get Signature Computing Method | Note: Sha1/sha256/md5 is currently supported (all lowercase)|
| ota_get_auth_access key | get access key | no|
| ota_read_flash | Restore OTA status from flash | No|
| ota_save_flash | Save the OTA state to flash | No|
| ota_calculate_range | Calculates the range of the next upgrade package | No|

The functions involved in the network interface are:

| Function Name | Function Description | Parameters and Remarks|
|:-|:-|:-|
| ota_net_init | Network Connection Initialization | None|
| ota_net_send | Sender function | None|
| ota_get_host_by_name | domain name resolution | Note: If domain name resolution is not supported, you can directly return to fixed IP.|

## 4 Event Description
SDK's logical control and user data interaction are implemented by event triggering and are included in the function OTA_Event_Handle(). The incidents involved are:

| Event Name | Action Description | Parameters and Remarks|
|:-|:-|:-|
| OTA_EVENT_TASK_ManufOrModel_ERROR | Detection task failed, vendor or module number inconsistent | No|
| OTA_EVENT_TASK_Ver_ERROR | Detection task failed, initial version number of differential package inconsistent | No|
| OTA_EVENT_TASK_STATE_ERROR | Detecting Mission Failure, Mission State Failure | No|
| OTA_EVENT_TASK_NO_TASK | Detection task failed, no corresponding task exists | No|
| OTA_EVENT_TASK_OTHER_ERROR | Detect Mission Failure, Failure for Other Reasons | Note: Other Reasons include OneNET Internal Error, Task Suspension, etc.|
| OTA_EVENT_TASK_SUCCESS | Detection Task Success | Note: When the detection task succeeds, the context state parameter should be updated to the download state.|
| OTA_EVENT_TOKEN_OK | Check token Success | Note: After token check is completed, you can obtain files.|
| OTA_EVENT_TOKEN_INTERNAL_ERROR | Check token failed, OneNET internal error | No|
| OTA_EVENT_TOKEN_EXPIRED_ERROR | Check token failed, token expired | Note: This OTA process should be terminated and context destroyed|
| OTA_EVENT_TOKEN_RETRIEVE_ERROR | Check token failed, token expired | Note: You can re-detect a task and update it to the latest token|
| OTA_EVENT_TOKEN_CHECK_ERROR | Check token failed, token error | Note: This OTA process should be terminated and context destroyed|
| OTA_EVENT_TOKEN_PAUSED_ERROR | Check token failed, task suspended | Note: Retry according to retry time, but do not consume retry times|
| OTA_EVENT_TOKEN_TASK_EXPIRED_ERROR | Check token failed, task ended | Note: OTA process should be terminated and context destroyed|
| OTA_EVENT_TOKEN_TERMINATE_ERROR | Check token failed, task cancelled | Note: This OTA process should be terminated and context destroyed|
| OTA_EVENT_TOKEN_OTHER_ERROR | Check token failed because of other reasons | No|
| OTA_EVENT_REPORT_DOWNLOAD_SUCCESS | Start reporting download success status | No|
| OTA_EVENT_REPORT_LOW_POWER | Begins to report Download failure due to low power | No|
| OTA_EVENT_REPORT_BAD_SIGNAL | Begins to report Download failure due to bad signal | No|
| OTA_EVENT_REPORT_UNKNOWN_ERROR | Begins to report Download failure status, other reasons | Note: Other reasons include the number of retries consumed, the server did not find resources, file size inconsistency, token invalid and so on.|
| OTA_EVENT_REPORT_UPDATE_SUCCESS | Start reporting successful status of upgrade | No|
| OTA_EVENT_REPORT_MD5_ERROR | Begins to report upgrade failure due to MD5 check failure | No|
| OTA_EVENT_REPORT_SUCCESS | Report status success | Note: After report status success, if Report Download success, you can start upgrading, <br> If other report status, you should end the process of OTA and destroy the context.|
| OTA_EVENT_REPORT_FAILED | Failure to report status, caused by other reasons | Note: Other reasons include token failure, wrong status code upload, cancellation of upgrade task, completion of upgrade task, invalid operation, etc. <br> If the upgrade task has been cancelled or completed, it is recommended that the process of OTA be terminated and the context be destroyed.|
| OTA_EVENT_custom_retry_download | Start downloading retry | Note: Since the number of bytes received is not equal to content length, start retrying timing|
| OTA_EVENT_custom_save_packet | Start saving downloaded files Note: Save the received files as files|
| OTA_EVENT_custom_ready_update | Start upgrading | No|
| OTA_EVENT_custom_save_task_info | Save task information to flash | Note: Save received files as files|
| OTA_EVENT_custom_report_error_clear | End OTA process due to reporting failure | Note: When reporting status fails due to cancellation of upgrade task and completion of upgrade task, it is recommended that the process of OTA be terminated and the context be destroyed.|
| OTA_EVENT_custom_delete_package | Clear the saved upgrade package data when context is destroyed | No|

## Other notes

1. When running the project on win platform, it only needs to modify default_device_id, default_manuf, default_model, default_type, default_version, default_res and default_access_key to run.

2. In the event OTA_EVENT_custom_ready_update, other ways should be added to judge whether the upgrade is successful or not (e.g. by comparing versions before and after the upgrade), and then report the upgrade status.

3. In the function OTA_Pack_Authorization_Info(), the calculation result of signature encryption is saved to the encrypt_result variable in the context. In the OTA_EVENT_custom_save_task_info event, it can be saved to flash or recalculated at the next recovery state.

4. If no data is received over a certain period of time, it should be marked as retry (ctx_net_state is reset to NET_STATE_NULL, isRetry is set to DownLoadRetry_True).

5. In the detection task API, if the CDN is true, the download IP of the upgrade package can be returned.

6. In the function ota_save_flash, if some data need to be stored in flash for recovery, the token, signal requirement, power requirement, retry times, retry interval, upgrade package size, downloaded upgrade package size, upgrade package MD5 information returned when the detection task is successful should be saved, and the downloaded upgrade package should be uploaded after each successful acquisition and data storage. Class package size is updated to flash.

7. The fragmentation range of each pull-out file is calculated in the function ota_calculate_range(), and the calculation method can be freely designed according to the actual needs.

8. When downloading the upgrade package, if the power is low or the signal is poor, you can choose to reset isRetry in the callback event.

9. If you need to upgrade the file name of the package, you can get it in Content-Disposition.

10. The minimum range for each acquisition of fragmented packets is limited to 2 bytes.

11. When reporting status, if OneNET receives the status code but SDK is not responded due to some reasons (e.g. network reasons), the context can be destroyed directly according to actual needs in OTA_EVENT_REPORT_FAILED events.