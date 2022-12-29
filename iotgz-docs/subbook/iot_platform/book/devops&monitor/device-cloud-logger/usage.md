# 功能使用

使用说明：
- 使用设备日志功能请先开通OneNET Studio物联网平台；
- 在Sutdio菜单中找到「运维监控-设备日志」菜单，点击菜单，即可进入「设备日志」功能页面
## 设备日志条件查询
使用「设备日志」条件查询功能，需要先选择需要要查询的产品范围，选定产品范围后，根据需要填写设备名称（模糊匹配）、链路ID（精确匹配）、消息ID（精确匹配）、日志状态（成功、失败，默认全部）、业务类型（设备行为、上行消息、下行消息、物模型调用、数据存储、规则引擎、MQ推送、HTTP推送、开放API等）和日志时段（近15分钟、近1小时、近4小时、近24小时、近7天、自定义，默认近15分钟）条件，来点击「查询」按钮来执行查询，日志数据按照日志时间倒序排序；「重置」按钮可将查询条件恢复至初始查询条件；还可以点击分页列表下方的页码来跳到指定页，点开「每页显示」下拉列表选择一个分页量来控制分页大小。

设备日志列表数据项字段一览：

|  字段名称 |  类型 |  说明 |
|---|---|---|
|  日志时间 |时间|  业务开始时间，格式yyyy-MM-dd HH:mm:ss.SSS，精确到毫秒 |
|  设备名称 |字符串|  |
|  链路ID |字符串| 32位，一条消息在系统内部各个服务模块流转以及相关触发消息的唯一标识ID|
|  消息ID |字符串| 设备与平台上下行消息的消息唯一标识，用户可根据消息ID，查询消息通信数据内容，消息查询时效性为一天（自然天，当天可查当天，跨天则不可查询），目前仅上行消息、下行消息有消息ID，具体消息可在操作栏点击详情进入日志详情页面查看。|
|  业务类型 |枚举| 日志的业务类型，由各个服务定义，参见**日志业务类型**|
|  日志状态 |枚举| 200代表成功，其它状态定义码参见**日志业务状态码**|
|  日志内容 |枚举| 详细的日志输出内容|

## 异常日志定位分析
当在日志列表中查看到有失败的日志（日志状态非200）时，可以根据该数据项的链路ID来进行全链路查询，利用查询出来的全链路日志可以很快速地进行问题朔源和故障定位，每种出口业务的完整日志链路说明见**出口业务日志链路说明**。