# 接口服务能力说明

用户可通过上传数据点的方式，向\$OneNET_LBS_WIFI这个数据流上传规定格式的WiFi信息数据点，平台收到数据点后，会将数据点转化为对应的经纬度信息，方便用户通过API接口查询。

## 数据点上传

**数据流名称   $OneNET_LBS_WIFI**

<table>
<tr><th width="20%">字段名称</th><th width="20%">数据类型</th><th width="20%">字段</th><th>是否必填</th></tr>
<tr><td>移动用户识别码</td><td>String</td><td>imsi</td><td>选填，移动用户识别码，可以提高精度</td></tr>
<tr><td>设备接入基站时对应的网关ip</td><td>String</td><td>serverip</td><td>选填，可以提高精度，无法定位时，可根据该参数排查问题</td></tr>
<tr><td>可以接收到的热点mac信息</td><td>String</td><td>macs</td><td>必填，单mac信息同 mmac，mac之间使用“|”分隔。必须填写2个及2个以上</td></tr>
<tr><td>已连热点mac信息</td><td>String</td><td>mmac</td><td>选填，格式mac,signal,ssid。如：f0:7d:68:9e:7d:18,-41,TPLink,可以提高精度</td></tr>
<tr><td>手机mac码</td><td>String</td><td>smac</td><td>选填，可以提高精度，无法定位时，可根据该参数排查问题</td></tr>
<tr><td>IOS手机的idfa</td><td>String</td><td>idfa</td><td>选填，可以提高精度,无法定位时，可根据该参数排查问题</td></tr>
</table>

-------------
注：在使用数据点上报时,TYPE类型必须为3

**WiFi定位数据上报格式**
```json
{
	"$OneNET_LBS_WIFI": {
		"macs":"FC:D7:33:55:92:6A,-77|B8:F8:83:E6:24:DF,-60",
        "serverip":"10.2.166.4",
        "imsi":"352315052834187",
        "mmac":"FC:D7:33:55:92:6A,-80",
        "smac":"E0:DB:55:E4:C7:49",
        "idfa":"583D2BB0-B19C- 4A9A-A600-2A1EB2FB7E39"
	}
}
```


## API说明

<table>
<tr><th width="30%">类别</th><th width="30%">功能</th><th>详细内容</th></tr>
<tr><td>API</td><td>最新位置查询</td><td>可返回最后一次WiFi定位结果</td></tr>
<tr><td>API</td><td>历史轨迹查询</td><td>根据输入的时间区间范围实现时间区间内轨迹查询</td></tr>
</table>

## API接口

{API_ADDRESS}为：api.heclouds.com

### 最新位置查询

| HTTP方法 | GET|
|----------|-|
| URL      | http://API_ADDRESS/devices/device_id/lbs/latestWifiLocation    |
| HTTP头部 | api-key:xxxx-ffff-zzzzz
| url参数  | 无|
| 请求返回 | {  "errno": 0, <br/> "error":“succ”,  <br/>"data": <br/> { "at": "2018-06-13 15:15:22", //时间 <br/>"lon": 106.48881, //经度 <br/> "lat": 29.62518 //纬度 } } |

### 历史轨迹查询

| HTTP方法 | GET                                                    |
|----------|--|
| URL  | http://API_ADDRESS/devices/device_id/lbs/getWifiTrail         
| URL参数  | start= 2018-01-10T08:00:35.012 //表示查询轨迹的开始时间, 默认起始时间为本周一零点，可选，精确到毫秒级别 <br/>end= 2018-01-10T08:00:35.230 //表示查询轨迹的结束时间，默认结束时间为当前时间，可选，精确到毫秒级别  <br/>page = 1 //指定页码，可选  <br/>per_page = 30 //指定每页输出设备个数，可选，默认10 <br/>maxLon=130.308 //最大经度, 可选  <br/>minLon=100.308 //最小经度, 可选 <br/> maxLat=30.0944 //最大纬度, 可选  <br/>minLat=10.0944 //最小纬度, 可选  <br/>sort = DESC\ASC //可选，默认为ASC（升序）  <br/>备注：最大、最小经纬度如果不传，查询所有轨迹。 如果四个参数都传入，则查询范围内轨迹。 |
| HTTP头部 | api-key:xxxx-ffff-zzzzz                              |
| 请求返回 | { "errno": 0,  <br/>"error":“succ”,  <br/>"data": { "page": 1, <br/> "per_page": 10,  <br/>"total_count": 39,  <br/>"trail": [ <br/> { "at": "2018-06-13 15:15:22.012", //时间  <br/> "lon": 106.48881, //经度  <br/>"lat": 29.62518 //纬度 }, <br/> { "at": "2018-06-13 18:22:58.234", //时间 <br/> "lon": 106.48886999999999, //经度  <br/>"lat": 29.62514 //纬度 }, <br/> { "at": "2018-06-13 18:25:19.210", //时间   <br/>"lon": 106.48885, //经度 <br/> "lat": 29.62516 //纬度 } ] }|

    注：
    1.最大、最小经纬度如果不传，查询所有轨迹。 如果四个参数都传入，则查询范围内轨迹。
    2.WiFi定位的坐标系为WGS-84坐标系。


