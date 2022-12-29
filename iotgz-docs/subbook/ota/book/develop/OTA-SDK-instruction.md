 # OTA SDK使用说明
[本页目录]()

[1. 用户例程](#1)

[2. 逻辑控制](#2)

[3. 适配接口](#3)

[4. 事件说明](#4)

[5. 其它说明](#5)

如需获取SDK，或技术支持请[填写企业及项目信息](https://open.iot.10086.cn/questionnaire/show/441f4a7819df17d0e101bb9c1b23ab75)申请，填写完成后发送邮件至chenkeyu@cmiot.chinamobile.com

<h3 id="1">1. 用户例程</h3>

OTA的用户例程为sample文件夹，在VS工程中对应为OtaSample项目。所涉及的函数有：

<table>
<tr><th width="20%">函数名</th><th width="20%">功能说明</th><th>参数与备注</th></tr>
<tr><td>ota_init</td><td>ota上下文初始化函数</td><td>check_time：检查升级任务的时间间隔，单位：秒</td></tr>
<tr><td>ota_loop</td><td>ota逻辑控制函数</td><td>check_now：是否立即检查升级任务<br>备注：需要周期性调用</td></tr>
<tr><td>ota_deinit</td><td>ota上下文销毁函数</td><td>备注：在结束ota流程后应当调用该函数清除相关内存空间</td></tr>
</table>

<h3 id="2">2. 逻辑控制</h3>

OTA的逻辑控制函数及相关功能文件为core文件夹，在VS工程中对应为CMIOT-OTA项目。core文件夹中的文件及二级文件夹有：

<table>
<tr><th width="20%">文件或文件夹名</th><th>说明</th></tr>
<tr><td>ota_core.c</td><td>包含ota逻辑控制函数、功能函数</td></tr>
<tr><td>ota_parse.c</td><td>包含解析报文控制函数</td></tr>
<tr><td>ota_api.h</td><td>ota外部使用头文件</td></tr>
<tr><td>ota_internal.h</td><td>ota内部使用头文件</td></tr>
<tr><td>cjson/</td><td>json解析组件</td></tr>
<tr><td>http/</td><td>http报文解析组件</td></tr>
<tr><td>mbedtls/</td><td>HMAC签名加密组件</td></tr>
</table>

在ota_core.c文件中，包含了ota的逻辑控制函数及相关的解析功能函数，所涉及的函数有：

<table>
<tr><th width="20%">函数名</th><th width="35%">功能说明</th><th>参数与备注</th></tr>
<tr><td>OTA_Pack_Check_Task</td><td>查询任务API组包</td><td>无</td></tr>
<tr><td>OTA_Pack_Check_Token</td><td>Token检验API组包</td><td>无</td></tr>
<tr><td>OTA_Pack_Get_Package</td><td>获取文件API组包</td><td>无</td></tr>
<tr><td>OTA_Pack_Report</td><td>上报状态API组包</td><td>无</td></tr>
<tr><td>OTA_Pack_Authorization_Info</td><td>Authorization参数计算及组包</td><td>无</td></tr>
<tr><td>OTA_CHECK_DEVICE</td><td>检查设备是否具备升级条件</td><td>备注：每次下载升级包前都应该检查电量及信号强度是否符合预设条件</td></tr>
</table>

<h3 id="3">3. 适配接口</h3>

OTA的适配接口位于adapter文件夹，在VS工程中对应为OtaAdapter项目。接口共分为系统接口和网络接口两部分，其中系统接口涉及的函数有：

<table>
<tr><th width="20%">函数名</th><th width="35%">功能说明</th><th>参数与备注</th></tr>
<tr><td>OTA_Event_Handle</td><td>ota事件触发函数</td><td>无</td></tr>
<tr><td>ota_log_printf</td><td>日志打印</td><td>无</td></tr>
<tr><td>ota_atoi</td><td>字符串转整形</td><td>无</td></tr>
<tr><td>ota_itoa_decimal</td><td>十进制整数转字符串</td><td>无</td></tr>
<tr><td>ota_hex2str</td><td>十六进制转字符串</td><td>备注：将md5计算结果转成字符串用于比较</td></tr>
<tr><td>ota_malloc</td><td>内存申请</td><td>无</td></tr>
<tr><td>ota_free</td><td>内存释放</td><td>无</td></tr>
<tr><td>ota_get_tick</td><td>获取系统运行时间</td><td>备注：用于计时</td></tr>
<tr><td>ota_get_deviceID</td><td>获取设备ID</td><td>无</td></tr>
<tr><td>ota_get_manuf</td><td>获取厂商编号</td><td>无</td></tr>
<tr><td>ota_get_model</td><td>获取模组编号</td><td>无</td></tr>
<tr><td>ota_get_type</td><td>获取升级type</td><td>备注：1为fota任务，2为sota任务</td></tr>
<tr><td>ota_get_version</td><td>获取当前版本</td><td>无</td></tr>
<tr><td>ota_get_signals</td><td>获取信号强度</td><td>无</td></tr>
<tr><td>ota_get_powers</td><td>获取电池电量</td><td>无</td></tr>
<tr><td>ota_get_auth_version</td><td>获取鉴权版本</td><td>备注：当前鉴权版本固定为”2018-10-31”</td></tr>
<tr><td>ota_get_auth_res</td><td>获取res</td><td>备注：在当前SDK中，既为获取产品ID</td></tr>
<tr><td>ota_get_auth_et</td><td>获取鉴权过期时间</td><td>备注：UNIX时间</td></tr>
<tr><td>ota_get_auth_method</td><td>获取签名计算方式</td><td>备注：当前支持sha1/sha256/md5（全为小写）</td></tr>
<tr><td>ota_get_auth_accesskey</td><td>获取accesskey</td><td>无</td></tr>
<tr><td>ota_read_flash</td><td>从flash中恢复ota状态</td><td>无</td></tr>
<tr><td>ota_save_flash</td><td>将ota状态保存至flash</td><td>无</td></tr>
<tr><td>ota_calculate_range</td><td>计算下次获取升级包的范围（range）</td><td>无</td></tr>
</table>

其中网络接口涉及的函数有：

<table>
<tr><th width="20%">函数名</th><th width="35%">功能说明</th><th>参数与备注</th></tr>
<tr><td>ota_net_init</td><td>网络连接初始化</td><td>无</td></tr>
<tr><td>ota_net_send</td><td>发送函数</td><td>无</td></tr>
<tr><td>ota_get_host_by_name</td><td>域名解析</td><td>备注：若不支持域名解析可以直接返回固定IP</td></tr>
</table>

<h3 id="4">4. 事件说明</h3>

SDK的逻辑控制和用户数据交互是通过事件触发实现的，包含在函数OTA_Event_Handle()中。其中所涉及的事件有：

<table>
<tr><th width="35%">事件名</th><th width="30%">功能说明</th><th>参数与备注</th></tr>
<tr><td>OTA_EVENT_TASK_ManufOrModel_ERROR</td><td>检测任务失败，厂商编号或模组编号不一致</td><td>无</td></tr>
<tr><td>OTA_EVENT_TASK_Ver_ERROR</td><td>检测任务失败，差分包的初始版本号不一致</td><td>无</td></tr>
<tr><td>OTA_EVENT_TASK_STATE_ERROR</td><td>检测任务失败，任务状态失效</td><td>无</td></tr>
<tr><td>OTA_EVENT_TASK_NO_TASK</td><td>检测任务失败，没有对应的任务存在</td><td>无</td></tr>
<tr><td>OTA_EVENT_TASK_OTHER_ERROR</td><td>检测任务失败，由于其它原因失败</td><td>备注：其它原因包括OneNET内部错误、任务暂停等原因</td></tr>
<tr><td>OTA_EVENT_TASK_SUCCESS</td><td>检测任务成功</td><td>备注：检测任务成功后应当将上下文的state参数更新为下载状态</td></tr>
<tr><td>OTA_EVENT_TOKEN_OK</td><td>校验token成功</td><td>备注：token校验完毕后可以进行文件的获取</td></tr>
<tr><td>OTA_EVENT_TOKEN_INTERNAL_ERROR</td><td>校验token失败，OneNET内部错误</td><td>无</td></tr>
<tr><td>OTA_EVENT_TOKEN_EXPIRED_ERROR</td><td>校验token失败，token过期</td><td>备注：应当结束OTA本次流程，并销毁上下文</td></tr>
<tr><td>OTA_EVENT_TOKEN_RETRIEVE_ERROR</td><td>校验token失败，token过期</td><td>备注：可以重新检测一次任务，更新到最新的token</td></tr>
<tr><td>OTA_EVENT_TOKEN_CHECK_ERROR</td><td>校验token失败，token错误</td><td>备注：应当结束OTA本次流程，并销毁上下文</td></tr>
<tr><td>OTA_EVENT_TOKEN_PAUSED_ERROR</td><td>校验token失败，任务已暂停</td><td>备注：根据重试时间进行重试，但是不消耗重试次数</td></tr>
<tr><td>OTA_EVENT_TOKEN_TASK_EXPIRED_ERROR</td><td>校验token失败，任务已结束</td><td>备注：应当结束OTA本次流程，并销毁上下文</td></tr>
<tr><td>OTA_EVENT_TOKEN_TERMINATE_ERROR</td><td>校验token失败，任务已取消</td><td>备注：应当结束OTA本次流程，并销毁上下文</td></tr>
<tr><td>OTA_EVENT_TOKEN_OTHER_ERROR</td><td>校验token失败，由于其它原因失败</td><td>无</td></tr>
<tr><td>OTA_EVENT_REPORT_DOWNLOAD_SUCCESS</td><td>开始上报下载成功状态</td><td>无</td></tr>
<tr><td>OTA_EVENT_REPORT_LOW_POWER</td><td>开始上报下载失败状态，原因为电量低</td><td>无</td></tr>
<tr><td>OTA_EVENT_REPORT_BAD_SIGNAL</td><td>开始上报下载失败状态，原因为信号不良</td><td>无</td></tr>
<tr><td>OTA_EVENT_REPORT_UNKNOWN_ERROR</td><td>开始上报下载失败状态，其它原因</td><td>备注：其它原因包括重试次数消耗完毕、服务器未找到资源、文件大小不一致、token无效等原因</td></tr>
<tr><td>OTA_EVENT_REPORT_UPDATE_SUCCESS</td><td>开始上报升级成功状态</td><td>无</td></tr>
<tr><td>OTA_EVENT_REPORT_MD5_ERROR</td><td>开始上报升级失败状态，原因为md5校验失败</td><td>无</td></tr>
<tr><td>OTA_EVENT_REPORT_SUCCESS</td><td>上报状态成功</td><td>备注：上报状态成功后，若是上报的下载成功，则可以开始进行升级，<br>若为其它上报状态，则应当结束OTA本次流程，并销毁上下文</td></tr>
<tr><td>OTA_EVENT_REPORT_FAILED</td><td>上报状态失败，由其它原因造成</td><td>备注：其它原因包括token失效、上传错误的状态码、升级任务已取消、升级任务已完成、无效操作等原因，<br>其中若升级任务已取消或者已完成，建议结束OTA本次流程，并销毁上下文</td></tr>
<tr><td>OTA_EVENT_custom_retry_download</td><td>开始下载重试</td><td>备注：由于收到的字节数与contentlength不相等，故开始重试计时</td></tr>
<tr><td>OTA_EVENT_custom_save_packet</td><td></td><td>
<tr><td>OTA_EVENT_custom_ready_update</td><td>开始升级</td><td>无</td></tr>
<tr><td>OTA_EVENT_custom_save_task_info</td><td>保存任务信息至flash</td><td>备注：将接收到的文件保存成文件</td></tr>
<tr><td>OTA_EVENT_custom_report_error_clear</td><td>由于上报失败结束OTA流程</td><td>备注：当由于升级任务已取消、升级任务已完成导致上报状态失败时，建议结束OTA本次流程，并销毁上下文</td></tr>
<tr><td>OTA_EVENT_custom_delete_package</td><td>销毁上下文时清空已经保存的升级包数据</td><td>无</td></tr>
</table>

<h3 id="5">5. 其它说明</h3>

（1）在win平台运行该工程时，只需要将default_device_id、default_manuf、default_model、default_type、default_version、default_res和default_access_key修改即可运行；

（2）在事件OTA_EVENT_custom_ready_update中，应当增加其它方式判断升级成功与否（例如通过比对升级前后的version等），再上报升级状态；

（3）在函数OTA_Pack_Authorization_Info()中会将签名加密的计算结果保存至上下文中的encrypt_result变量中。在OTA_EVENT_custom_save_task_info事件中可以将其保存至flash中或者下次恢复状态时重新计算；

---

（4）若超过一定时间未收到数据应当标记为重试（ctx_net_state重置为NET_STATE_NULL , isRetry置为DownLoadRetry_True）；

（5）检测任务API中，如果设置了cdn为true可以返回升级包的下载IP；

（6）在函数ota_save_flash中，若需要将某些数据存入flash用作恢复时，应当保存检测任务成功时返回的token、信号要求、电量要求、重试次数、重试时间间隔、升级包大小、已下载升级包大小、升级包md5信息等，且当每次获取分片包成功并据存储完毕后，应当将已下载升级包大小更新到flash中；

---

（7）每次拉取文件的分片范围在函数ota_calculate_range()中计算，可以根据实际需要自由设计计算方式；

（8）下载升级包时若因为电量低或者信号差，可以选择在回调事件中将isRetry置为重试状态；

（9）如果需要升级包的文件名，可以在Content-Disposition中获取；

---

（10）每次获取分片包的最小范围限制为2个字节；

（11）上报状态时，若OneNET收到了状态码但是因某些原因（例如网络原因）导致sdk没收到回应，可以在OTA_EVENT_REPORT_FAILED事件中根据实际需求选择直接销毁上下文。

<div>
    <a href="/book/develop/south-API/8check_did.md">
        <span> &#171; 上一篇：9-查询设备ID</span>
        </a>
		</div>
<div>
    <a href="/book/develop/OTA-SDK-instruction.md">
        <span> &#187; 下一篇：API调试-Postman</span>
    </a>
</div>