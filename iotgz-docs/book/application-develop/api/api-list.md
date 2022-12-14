# API列表

平台提供的API列表如下：

    注：用户可以使用的API集根据选择的产品接入协议不同会有差异，详情请见各协议产品支持的API详情

## 设备管理相关
API | 请求方式 | 说明
:- | :- | :- 
新增设备 | POST| 供应用层使用
注册设备 | POST | 用于设备自行注册场景
更新设备信息 |	PUT | 用于更新设备属性
查询设备详情 | GET | 用于查询设备属性，包括设备在线状态
批量查询设备信息 | GET | 
批量查询设备状态 | GET | 
删除设备 | DELETE | 

## 数据流管理相关
API | 请求方式 | 说明
:- | :- | :- 
新增数据流 | POST | 建立某设备独有的数据属性，产品内建议使用数据流模板替代
更新数据流属性 | PUT | 
查询数据流状态 | GET | 可用于查询数据流配置以及最新数据点
删除数据流 | DELETE | 

## 数据管理相关
API | 请求方式 | 说明
:- | :- | :- 
查询设备历史数据 | GET |
批量查询设备最新数据 | GET | 
上传数据点 | POST | 设备/应用服务器均可通过HTTP/HTTPS方式上传数据
上传文件 | POST |可用于设备上传原始数据、图片、文件等
获取文件 | GET | 

## 设备命令相关
API | 请求方式 | 说明
:- | :- | :- 
下发命令 | POST | 平台主动发送数据至设备
查询命令状态 | GET | 用于查询某条命令的执行情况
查询命令响应 | GET | 设备收到命令时需要设备发送命令响应
查询设备历史命令 | GET | 

## 触发器相关
API | 请求方式 | 说明
:- | :- | :- 
新增触发器 | POST | 
更新触发器 | PUT | 
查询触发器详情 | GET | 
删除触发器 | DELETE |

## apikey相关
API | 请求方式 | 说明
:- | :- | :- 
新增apikey | POST | 新增的apikey只具有设备级的权限
更新apikey | PUT | 
查询apikey | GET | 
删除apikey | DELETE |

## topic相关（限MQTT设备使用）
API | 请求方式 | 说明
:- | :- | :- 
发布消息 | POST | 发布消息到topic
查询订阅设备列表 | GET | 查询订阅某个topic的设备列表
查询设备订阅详情 | GET | 查询设备的topic订阅列表
查询topic列表 | GET |
