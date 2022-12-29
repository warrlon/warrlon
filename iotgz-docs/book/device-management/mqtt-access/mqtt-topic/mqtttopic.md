# **通信主题**

# **通信主题Topic**

#### Topic概念

物联平台中，服务端和设备端通过通信主题Topic实现消息通信，设备可以通过发布消息到系统 topic 调用服务接口，也可以订阅系统 topic 用于接收服务消息通知，服务提供的系统 topic 见Topic列表。

#### Topic列表

物联平台预定义物模型通信Topic，各物模型功能Topic消息的数据格式，见OneJSON数据格式。
Topic类以正斜线（/）进行分层，区分每个类目。其中，有两个类目为既定类目：${pid}表示产品的产品id；${device-name}表示设备名称；${identifier}表示服务标识符。

物模型通信Topic：

<table style="text-align: left">

<tr style="background-color:#363636; color:#F0FFF0;"><td width="15%">功能</th><td width="10%">类别</th><td width="10%">行为</th><td width="10%">描述</th><td>Topic类</th><td width="10%">操作权限</td></tr>

<tr><td rowspan="14">物模型通信Topic</td><td rowspan="10">属性</td><td rowspan="2">设备属性上报</td><td>请求</td><td>$sys/{pid}/{device-name}/thing/property/post</td><td>发布</td></tr>
<tr><td>响应</td><td>$sys/{pid}/{device-name}/thing/property/post/reply</td><td>订阅</td></tr>

<tr><td rowspan="2">设备属性设置（同步）</td><td>请求</td><td>$sys/{pid}/{device-name}/thing/property/set</td><td>订阅</td></tr>
<tr><td>响应</td><td>$sys/{pid}/{device-name}/thing/property/set_reply</td><td>发布</td></tr>

<tr><td rowspan="2">设备获取属性期望值</td><td>请求</td><td>$sys/{pid}/{device-name}/thing/property/desired/get</td><td>发布</td></tr>
<tr><td>响应</td><td>$sys/{pid}/{device-name}/thing/property/desired/get/reply</td><td>订阅</td></tr>

<tr><td rowspan="2">清除属性期望值</td><td>请求</td><td>$sys/{pid}/{device-name}/thing/property/desired/delete</td><td>发布</td></tr>
<tr><td>响应</td><td>$sys/{pid}/{device-name}/thing/property/desired/delete/reply</td><td>订阅</td></tr>

<tr><td rowspan="2">设备属性获取</td><td>请求</td><td>$sys/{pid}/{device-name}/thing/property/get</td><td>订阅</td></tr>
<tr><td>响应</td><td>$sys/{pid}/{device-name}/thing/property/get_reply</td><td>发布</td></tr>

<tr><td rowspan="2">事件</td><td rowspan="2">设备事件上报</td><td>请求</td><td>$sys/{pid}/{device-name}/thing/event/post</td><td>发布</td></tr>
<tr><td>响应</td><td>$sys/{pid}/{device-name}/thing/event/post/reply</td><td>订阅</td></tr>

<tr><td rowspan="2">服务</td><td rowspan="2">设备服务调用</td><td>请求</td><td>$sys/{pid}/{device-name}/thing/service/{identifier}/invoke</td><td>订阅</td></tr>
<tr><td>响应</td><td>$sys/{pid}/{device-name}/thing/service/{identifier}/invoke_reply</td><td>发布</td></tr>

</table>

网关与子设备通信Topic：

<table style="text-align: left">

<tr style="background-color:#363636; color:#F0FFF0;"><td width="15%">功能</th><td width="10%">类别</th><td width="10%">行为</th><td width="10%">描述</th><td>Topic类</th><td width="10%">操作权限</th></tr>

<tr><td rowspan="23">网关与子设备通信Topic</td><td rowspan="4">上下线</td><td rowspan="2">子设备上线</td><td>请求</td><td>$sys/{pid}/{device-name}/thing/sub/login</td><td>发布</td></tr>
<tr><td>响应</td><td>$sys/{pid}/{device-name}/thing/sub/login/reply</td><td>订阅</td></tr>

<tr><td rowspan="2">子设备下线</td><td>请求</td><td>$sys/{pid}/{device-name}/thing/sub/logout</td><td>发布</td></tr>
<tr><td>响应</td><td>$sys/{pid}/{device-name}/thing/sub/logout/reply</td><td>订阅</td></tr>

<tr><td rowspan="8">属性和事件</td><td rowspan="2">批量上报属性和事件（网关上报或代理子设备上报）</td><td>请求</td><td>$sys/{pid}/{device-name}/thing/pack/post</td><td>发布</td></tr>
<tr><td>响应</td><td>$sys/{pid}/{device-name}/thing/pack/post/reply</td><td>订阅</td></tr>

<tr><td rowspan="2">子设备属性获取</td><td>请求</td><td>$sys/{pid}/{device-name}/thing/sub/property/get</td><td>订阅</td></tr>
<tr><td>响应</td><td>$sys/{pid}/{device-name}/thing/sub/property/get_reply</td><td>发布</td></tr>

<tr><td rowspan="2">子设备属性设置</td><td>请求</td><td>$sys/{pid}/{device-name}/thing/sub/property/set</td><td>订阅</td></tr>
<tr><td>响应</td><td>$sys/{pid}/{device-name}/thing/sub/property/set_reply</td><td>发布</td></tr>

<tr><td rowspan="2">历史属性和事件上报（网关上报或代理子设备上报）</td><td>请求</td><td>$sys/{pid}/{device-name}/thing/history/post</td><td>发布</td></tr>
<tr><td>响应</td><td>$sys/{pid}/{device-name}/thing/history/post/reply</td><td>订阅</td></tr>

<tr><td rowspan="2">服务</td><td rowspan="2">子设备服务调用</td><td>请求</td><td>$sys/{pid}/{device-name}/thing/sub/service/invoke</td><td>订阅</td></tr>
<tr><td>响应</td><td>$sys/{pid}/{device-name}/thing/sub/service/invoke_reply</td><td>发布</td></tr>

<tr><td rowspan="9">拓扑关系</td><td rowspan="2">添加子设备</td><td>请求</td><td>$sys/{pid}/{device-name}/thing/sub/topo/add</td><td>发布</td></tr>
<tr><td>响应</td><td>$sys/{pid}/{device-name}/thing/sub/topo/add/reply</td><td>订阅</td></tr>

<tr><td rowspan="2">删除子设备</td><td>请求</td><td>$sys/{pid}/{device-name}/thing/sub/topo/delete</td><td>发布</td></tr>
<tr><td>响应</td><td>$sys/{pid}/{device-name}/thing/sub/topo/delete/reply</td><td>订阅</td></tr>

<tr><td rowspan="3">获取拓扑关系</td><td>请求</td><td>$sys/{pid}/{device-name}/thing/sub/topo/get</td><td>发布</td></tr>
<tr><td>响应</td><td>$sys/{pid}/{device-name}/thing/sub/topo/get/reply</td><td>订阅</td></tr>
<tr><td>网关同步结果响应</td><td>$sys/{pid}/{device-name}/thing/sub/topo/get/result</td><td>发布</td></tr>

<tr><td rowspan="2">通知网关拓扑关系变化</td><td>请求</td><td>$sys/{pid}/{device-name}/thing/sub/topo/change</td><td>订阅</td></tr>
<tr><td>响应</td><td>$sys/{pid}/{device-name}/thing/sub/topo/change_reply</td><td>发布</td></tr>


</table>
