# API列表


## 设备管理相关
API | 请求方式 | 说明
:- | :- | :- 
[新增设备](/book/application-develop/list/1create-device.md) | POST| 供应用层使用
[获取资源列表](/book/application-develop/list/7get-resource-list.md) |GET| 用于获取设备资源的相关信息
[更新设备信息](/book/application-develop/list/28update-dev-info.md) |	PUT | 用于更新设备属性
[查询设备详情](/book/application-develop/list/2check-a-device.md) | GET | 用于查询设备属性，包括设备在线状态
[批量查询设备信息](/book/application-develop/list/29batch-query-dev-info.md) | GET | 
[批量查询设备状态](/book/application-develop/list/19batch-query-dev-status.md) | GET | 
[根据imei查询设备信息](/book/application-develop/list/22imei-query-dev-inf.md)| GET | 
[删除设备](/book/application-develop/list/3remove-device.md) | DELETE | 

## 查询数据点
API | 请求方式 | 说明
:- | :- | :- 
[批量查询设备最新数据](/book/application-develop/list/20batch-query-dev-latest-data.md)|GET|
[查看数据点](/book/application-develop/list/21check-datapoint.md)|GET|
    

## 即时命令
API | 请求方式 | 说明
:- | :- | :- 
[资源发现](/book/application-develop/list/31resource_discover.md) |GET| 用于发现设备上的资源
[订阅](/book/application-develop/list/8subscribe.md)  |POST| 订阅设备对象或设备实例或设备资源
[读设备资源](/book/application-develop/list/4rt-read-device-resources.md) | POST | 平台主动发送数据至设备
[写设备资源](/book/application-develop/list/5rt-write-device-resources.md) | POST | 平台主动发送数据至设备
[命令下发](/book/application-develop/list/6rt-comm-issue.md) | POST | 平台主动发送数据至设备
[全链路日志查询(new)](/book/application-develop/list/32real_cmd-query-link_log.md) | GET | 即时命令全链路日志

## 缓存命令
API | 请求方式 | 说明
:- | :- | :- 
[读设备资源](/book/application-develop/list/9cache-read-dev-res.md) | POST | 平台主动发送数据至设备
[写设备资源](/book/application-develop/list/10cache-write-dev-res.md) | POST | 平台主动发送数据至设备
[命令下发](/book/application-develop/list/11cache-comm-issue.md) | POST | 平台主动发送数据至设备
[查看指定设备缓存命令列表](/book/application-develop/list/12check-spe-dev-cache-comm-list.md) | GET | 用于查询缓存命令列表
[查看指定缓存命令详情](/book/application-develop/list/13check-spe-cache-comm-detail.md) | GET | 用于查询某条命令的执行情况
[取消缓存命令](/book/application-develop/list/14cancel-cache-comm.md) | PUT | 设备收到命令时需要设备发送命令响应
[取消所有待下发命令(new)](/book/application-develop/list/33cache_cmd-cancel-all-wait_cmd.md) | PUT | 取消设备所有待下发命令
[全链路日志查询(new)](/book/application-develop/list/34cache_cmd-query-link_log.md) | GET | 缓存命令全链路日志


## 触发器相关
API | 请求方式 | 说明
:- | :- | :- 
[新增触发器](/book/application-develop/list/15add-trigger.md) | POST | 
[更新触发器](/book/application-develop/list/16update-trigger.md) | PUT | 
[查询触发器](/book/application-develop/list/17check-trigger.md) | GET | 
[删除触发器](/book/application-develop/list/18remove-trigger.md) | DELETE |

## DTLS相关
API | 请求方式 | 说明
:- | :- | :- 
[查看设备bs_psk](/book/application-develop/list/23check-dev-bs_psk.md)| GET | 
[更新bs_psk](/book/application-develop/list/24update-bs_psk.md)| PUT |
[新增acc_psk](/book/application-develop/list/25add-acc_psk.md)| POST | 新增
[编辑acc_psk](/book/application-develop/list/26edit-acc_psk.md)| PUT | 
[查看设备acc_psk](/book/application-develop/list/27check-dev-acc_psk.md)| GET |

## HTTP推送相关 （new）
API | 请求方式 | 说明
:- | :- | :- 
[查看全局推送状态](/book/application-develop/list/35http-push_query-global-push-status.md)| GET | 新增
[查看群组推送状态](/book/application-develop/list/36http-push_query-group-push-status.md)| GET | 新增

