# API列表

API | 请求方式 | 说明
:- | :- | :- 
[上报版本](/book/device-develop/OTA/develop/south-API/0report_version.md) | POST| 上报设备的当前版本
[检查设备升级任务](/book/device-develop/OTA/develop/south-API/1task.md) |GET| 检查设备是否存在升级任务
[检查token有效](/book/device-develop/OTA/develop/south-API/2token.md)  |GET| 通过token检测接口进行token检查（因为token存在2天有效期）
[下载资源](/book/device-develop/OTA/develop/south-API/3port.md) |	GET | 设备下载资源接口
[上报升级状态](/book/device-develop/OTA/develop/south-API/4report_process.md) | POST | 设备在下载升级包的过程中（分片下载），可以根据需要上报下载进度或升级状态
[获取设备token](/book/device-develop/OTA/develop/south-API/6get_token.md) |	GET | 获取设备正在升级（下载中/升级中）的token
[查询设备版本号](/book/device-develop/OTA/develop/south-API/7check_version.md)|GET |查询设备版本号接口
[上报状态](/book/device-develop/OTA/develop/south-API/5state.md) | POST | 上报升级包下载状态。与“上报升级状态”API的区别在于，用户使用该API时，需要调用两次，先上报下载相关状态码（Result=1xx），再上报升级相关状态码(Result=2xx)