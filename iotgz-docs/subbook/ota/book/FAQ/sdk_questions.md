# OTA常见问题-SDK相关
[本页目录]()

[1. 在VS中运行该工程时，需要修改哪些参数？](#1)

[2. 是否可以自定义上报下载进度的方式？](#2)

[3. 签名加密的计算结果存在哪个变量中？](#3)

[4. 如果需要保存任务信息，应当怎么做？](#4)

[5. 每次拉取文件的分片方式能自定义么？](#5)

[6. 升级时若设备电量和信号不满足条件怎么办？](#6)

[7. 如何获取升级包的文件名？](#7)

[8. 分片包最小的长度为多少？](#8)

[9. 为什么在持续下载升级包的过程中TCP连接会被断开？](#9)

[10. 在win平台运行SDK时升级包保存在哪里？](#10)

[11. SDK中如何重新下载升级包？](#11)

<h4 id="1">1.在VS中运行该工程时，需要修改哪些参数？</h4>

答：在VS中运行该工程时，需要修改下列参数，

default_device_id（设备ID）

default_manuf（设备模组厂商编号）

default_model（设备模组编号）

default_type（升级类型）

default_fota_version（设备固件版本号）

default_sota_version（设备应用程序版本号）

default_res（资源及资源实体ID）和

default_access_key（产品access_key）。

<h4 id="2">2.是否可以自定义上报下载进度的方式？</h4>

答：在事件OTA_EVENT_REPORT_DOWNLOAD_PROGRESS中，可以自由定义上报下载进度的方式，
> 注意：一定要保证下载完最后一个分片包后去上报下载进度，以触发升级。

<h4 id="3">3. 签名加密的计算结果存在哪个变量中？</h4>

答：在函数OTA_Pack_Authorization_Info中会将签名加密的计算结果保存至上下文中的encrypt_result变量中。

在OTA_EVENT_custom_save_task_info事件中可以将其保存至flash中或者重启恢复状态时重新计算。

<h4 id="4">4. 如果需要保存任务信息，应当怎么做？</h4>

答：在函数ota_save_flash中，若需要将某些数据存入flash用作恢复工作状态使用时，推荐保存检测任务成功时返回的token、信号要求、电量要求、重试次数、重试时间间隔、升级包大小、已下载升级包大小、升级包md5信息等，且当每次获取分片包成功存储完毕后，应当将已下载的升级包大小更新到flash中。

<h4 id="5">5. 每次拉取文件的分片方式能自定义么？</h4>

答：每次拉取文件的分片范围在函数ota_calculate_range()中计算。

默认采用分多次、每次固定大小的方式下载，可以根据实际需要自行设计分片逻辑。

<h4 id="6">6. 升级时若设备电量和信号不满足条件怎么办？</h4>

答：下载升级包时若因为电量低或者信号差，可以选择在回调事件中将isRetry置为重试状态。

<h4 id="7">7.如何获取升级包的文件名？</h4>

答：如果需要升级包的文件名，在下载升级包的API的返回报文中的Content-Disposition中获取。

<h4 id="8">8.分片包最小的长度为多少？</h4>

答：每次获取分片包的最小范围限制为2个字节。

<h4 id="9">9.为什么在持续下载升级包的过程中TCP连接会被断开？</h4>

答：在一次TCP连接中的请求数上限为1000，超过这个上限会断开TCP连接，只需重新建立TCP连接即可。

<h4 id="10">10.在win平台运行SDK时升级包保存在哪里？</h4>

答：SDK默认将下载的升级包保存至\build\OtaSample下，在结束流程后会在OTA_EVENT_custom_delete_package事件中将升级包删除，若需要查看升级包完整性，修改该事件即可。

<h4 id="11">11.SDK中如何重新下载升级包？</h4>

答：在下载升级包过程中若超过一定时间未收到数据应当标记为重试（ctx_net_state重置为NET_STATE_NULL , isRetry置为DownLoadRetry_True）。

<div>
    <a href="/book/FAQ/product_function_questions.md">
        <span> &#171; 上一篇：功能相关问题</span>
        </a>
		</div>
<div>
    <a href="/book/FAQ/other_questions.md">
        <span> &#187; 下一篇：其它问题</span>
    </a>
</div>