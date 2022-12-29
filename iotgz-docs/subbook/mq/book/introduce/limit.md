# 使用限制

消息队列MQ使用限制如下： 

## 服务限制

<table>
<tr><th width="25%">限制内容</th><th width="10%">限制值</th><th>说明</th></tr>
<tr><td>单MQ服务中用户可以创建的topic总数</td><td>5</td><td> </td></tr>
<tr><td>单topic中用户可以创建的订阅总数</td><td>5</td><td> </td></tr>
<tr><td>消息体大小</td><td>256KB</td><td>超限消息将会被丢弃</td></tr>
<tr><td>topic中的消息过期时间</td><td>30s-7天</td><td>系统将回收进入队列超过过期时间的消息</td></tr>
<tr><td>topic的缓存空间大小</td><td>1G</td><td>	默认为1G，暂不支持配置，队列数据量超限时，服务会从头部开始回收未过期消息所占用的空间</td></tr>
<tr><td>单topic消费消息速率</td><td>5000 条/秒</td><td>消息条数计算方式：以1KB为单位，向上取整<br>示例1：入队列1.5KB，被1个客户端消费消费，消息计算为2条<br>示例2：入队列1KB，被3个客户端消费，计为3条</td></tr>
<tr><td>订阅消息锁定时间</td><td>10-60s</td><td>默认为0，即不锁定消息，若设置为>0，则表示启用消息锁定<br>例：若设置为10s，客户端消费数据之后，若未返回ack，则会在10s后再次消费到未进行确认的消息</td></tr>
<tr><td>订阅消费位置</td><td>无</td><td>默认为0，即从队列头部开始消费</td></tr>
<tr><td>单客户端非业务报文频率限制</td><td>60/s</td><td>对于Ping、Subscribe、Unsubscribe报文发送频率限制，超限则会断开连接</td></tr>
</table>

## MQTT 协议限制
<table>
<tr><th width="20%">功能</th><th width="20%">是否支持</th><th>说明</th></tr>
<tr><td>Connect</td><td>支持</td><td>客户端发送到MQ的连接报文，connect flag必须为0xC2，否则会被断开连接</td></tr>
<tr><td>ConnAck</td><td>支持</td><td>MQ回复给客户端的连接响应，反向会断开连接</td></tr>
<tr><td>Publish</td><td>支持</td><td>MQ向客户端推送消息</td></tr>
<tr><td>PubAck</td><td>支持</td><td>客户端收到MQ推送消息后的回复</td></tr>
<tr><td>Subscribe</td><td>支持</td><td>客户端发送到MQ订阅topic的消息<br>当实例处于欠费状态时，订阅会失败同时服务器会断开连接</td></tr>
<tr><td>SubAck</td><td>支持</td><td>Q发送给客户端的订阅回复，反向会断开连接</td></tr>
<tr><td>Unsubscribe</td><td>支持</td><td>客户端发到MQ取消订阅topic的消息</td></tr>
<tr><td>UnsubAck</td><td>支持</td><td>MQ发送给客户端取消订阅的回复，反向会断开连接</td></tr>
<tr><td>Ping</td><td>支持</td><td>客户端发往MQ的Ping报文</td></tr>
<tr><td>PingResp</td><td>支持</td><td>MQ发给客户端的Ping报文的回复</td></tr>
<tr><td>Disconn</td><td>支持</td><td>客户端发往MQ的离线报文</td></tr>
<tr><td>PubRec</td><td>不支持</td><td>客户端发送此类型报文会断开连接</td></tr>
<tr><td>PubRel</td><td>不支持</td><td>客户端发送此类型报文会断开连接</td></tr>
<tr><td>PubComp</td><td>不支持</td><td>客户端发送此类型报文会断开连接</td></tr>
</table>

