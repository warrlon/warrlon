# 更新日志

###v4.0.0.20201203

#### Features:
* redis哨兵迁移至集群
* 去除redis中hgetall等命令使用


###v4.0.0.20201119

#### Bug Fix:
* 修复LRUC算法get方法无法驱逐过期内容
* 修复IO异常导致thrift服务终止，增加重启机制
* 修复设备在线数统计线程被异常中断
* 优化底层配置参数


###v4.0.0.20201015
####Features:
* kafka版本升级 0.9.0.1 -> 2.3.1


###v4.0.0.20200326

####Features:
*register/update/deregister 需要判断设备是否在移动云的冻结名单中。若在，禁止设备上行行为。若不在，按原有流程进行
*移动云设备冻结后，下线服务会从session中把设备信息剔除，设备notify会失败。



###v4.0.0.20191212

####Features:
* 设备imsi发生变更后，将变更信息发送到新topic
* 新增kafka新建producer成功日志
* 新建kafka producer时，使用单独线程执行producer.close(), 防止close不成功导致新建失败

###v4.0.0.20191128

#### Bug Fix
* kafka发送异常优化（出现异常新建producer重发送）


### v4.0.0.20191111

#### Features:
* 使用额外的 kafka producer 和本地文件避免 kafka 丢失数据
* 设备 register 或者 update 时，根据 payload 中的 object 列表更新资源列表，新增的 object instance 属性个数为0，但有实例数量，已有的 object instance 资源列表不变，删除的 object instance 从设备资源列表中删除实例；该步骤在自动下发 discover 之前，即无论是否打开自动发现资源，都会更新
* 增加接入机外网 ip 默认配置，用于配置非 172 和 192 网段接入机的外网 ip
* IP 黑名单功能中，定时获取 ip 列表从 redis keys 命令改为 scan

## v1.9.3 20190815
## 优化内容

1、修复已知问题

2、新增NB-IoT设备上线后，将固件版本和MCU软件版本主动更新到设备版本表中。	
## V1.9.2 20190808

### 优化内容：

1、缓存命令新增读取命令时，可以指定二进制数据的返回格式为16进制字符串形式。

2、NB即时命令修改从session中获取设备接入机地址。


