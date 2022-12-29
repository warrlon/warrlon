<h1>位置能力</h1>


OneNET LBS位置能力为用户提供高效、准确的定位服务，目前支持基站定位服务与WiFi定位服务，方便快捷的接入使用流程，超大的免费日配额，低成本的使用方式，让物联网企业可以更加灵活的对智能硬件进行位置管理，从而降低企业研发、运营和运维成本。

OneNET Studio位置能力和OneNET 4.0位置能力对比如下：

<table>
<tr><th width="20%">对比项</th><th width="40%">OneNET Studio位置能力</th><th>OneNET 4.0位置能力</th></tr>
<tr><td>数据上报</td><td>物模型系统功能点“基站定位”<br>物模型系统功能点“WiFi定位”</td><td>基站定位数据流$OneNET_LBS<br>WiFi定位数据流$OneNET_LBS_WIFI</td></tr>
<tr><td>上报记录</td><td>可在控制台页面【设备管理】-【设备详情】中查看历史上报基站信息或WiFi信息</td><td>无法在页面查看上报的数据记录</td></tr>
<tr><td>位置API鉴权</td><td>安全鉴权：<br>签名算法版本version：2020-05-29<br>访问资源res：userid或userid/roleid</td><td>masterKey</td></tr>
<tr><td>数据推送</td><td>支持设备经纬度推送</td><td>不支持设备经纬度推送</td></tr>
</table>

[进入OneNET 4.0位置能力开发文档](https://open.iot.10086.cn/doc/lbs/)