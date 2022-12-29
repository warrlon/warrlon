# 常见问题

### 消息队列中的 topic 和 订阅（sub） 的关系是什么？
A：topic为队列实体，可以理解成一个缓存数据的仓库，只有数据超时或者仓库满之后，才会丢弃数据；而 sub 可以理解为是消息代理，sub 负责从仓库中复制数据的**副本**并发送给已经通过 MQTT 建立了订阅关系的客户端

### 客户端因为异常断开连接后，重连之后为何接收不到数据？
A：服务支持用户通过 MQTT 协议连接并消费数据，客户端订阅之后方才能接收到消息，目前由于不支持 session，所以客户端的订阅关系系统不会保存，当客户端断开后，订阅关系会被清除，重新连接之后，需要重新建立订阅关系才能消费到数据

### 系统支持的TLS是单向认证还是双向认证？
A：系统支持TLS**单向认证**，提供下载的.pem证书用于客户端验证服务器的合法性；而服务器验证客户端的合法性是通过MQTT连接时 username 与 password 来进行的


