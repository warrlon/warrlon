# API返回说明

## 多协议API返回说明

多协议EDP,LwM2M,Modbus,MQTT,HTTP,TCP透传接入相关API返回说明。

| errno   | error   | 说明 | 
| :--------- | :----- | :------- |
|0 | succ | 成功 |
|1 | internal server error | 内部错误 |
|2 | api-key required | 缺少api-key |
|3 | auth failed | 鉴权失败 |
|4 | invalid JSON |json格式错误 |
|5 | request entity too large | 请求内容过大 |
|6 | invalid parameter | 不合法的请求参数 |
|7 | parameter required | 缺少请求参数 |
|8 | not found | 未找到 |
|9 | entity data required | 缺少请求内容 |
|10 | device not online | 设备不在线 |
|11 | datastream already exists | 数据流已经存在 |
|12 | already exists | 已存在 |
|13 | system limit | 系统限制 |
|14 | network latency | 网络延迟 |
|15 | api freq out of limit | 请求频率超过限制 |
|16 | unsuccess | 失败 |
|17 | nbiot server error | nb服务异常 |
|18 | hs server error | 红石服务异常 |
|19 | device count limit by account policy | 设备数量限制 |
|20 | max device count limit is 1000 for one time | 设备数量超过1000 |
|21 | device field constraint violation | 导入字段违反约束 |
|22 | invalid protocol | 不合法的协议 |
|23 | contain sensitive words | 存在非法词语 |
