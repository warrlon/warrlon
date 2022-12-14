# 名词解释

<table>
<tr><th width="20%">名词</th><th>说明</th></tr>
<tr><td>设备生产商</td><td>指生产各类单品设备的厂商，不太关注整体应用/项目，主要以单品硬件设备销售获取利润。</td></tr>
<tr><td>项目集成商</td><td>指承接项目集成的厂商，需要将多品类设备同时集成到一个应用系统里面，典型如智能楼宇，智慧城市等。</td></tr>
<tr><td>产品</td><td>具有相同数据模型的一类设备集合。如海尔01冰箱，西门子A型开关。</td></tr>
<tr><td>项目</td><td>包含一种或多种产品的设备、包含上层应用，旨在为用户提供物联网直接服务的单位，比如智慧停车项目。</td></tr>
<tr><td>设备</td><td>指具体的个体设备，设备带有一些唯一属性，如设备SN（NB设备为IMEI）。</td></tr>
<tr><td>设备类型</td><td>创建产品时需要选择设备类型，平台对不同类型设定不同的行业标准物模型，同时可在该物模型的基础上继续自定义字段。</td></tr>
<tr><td>物模型</td><td>主要是指设备的功能定义，设备上下行的数据格式等约束条件，例如定义设备温度的功能点：数值类型、步长0.1、范围为0-100。</td></tr>
<tr><td>TLV数据格式</td><td>TLV指平台自定义的二进制流，平台提供SDK可根据功能生成二进制流，与标准TLV不完全一致。</td></tr>
<tr><td>设备生产</td><td>指在行业开发平台创建产品、添加设备，并对该产品进行功能定义、完成设备测试、进行产品发布的过程。</td></tr>
<tr><td>功能点</td><td>表示终端的各类型的属性，包括设备功能和系统功能，例如冰箱，功能点中设备功能可以包括开关、速冻模式、速冷模式、温度设定、童锁、电量统计、故障告警等参数；系统功能可以包括信号强度、经纬度、版本等参数。用户可以选择平台已经定义好的功能点，也可以自定义功能点。</td></tr>
<tr><td>白名单</td><td>未开启白名单时，设备接入平台后，可以注册和激活；开启白名单功能后，需要预导入设备SN或设备IMEI，才能进行设备注册和激活。</td></tr>
</table>

<div>
    <a href="/book/introduce/introduce.md">
        <span> &#171; 上一篇：平台简介</span>
    </a>
</div>
<div>
    <a href="/book/introduce/use_limit.md">
        <span> &#187; 下一篇：使用限制</span>
    </a>
</div>