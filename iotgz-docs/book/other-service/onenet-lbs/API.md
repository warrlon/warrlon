# 接口服务能力说明

用户可通过上传数据点的方式，向\$OneNET_LBS这个数据流上传规定格式的基站信息数据点。平台收到数据点后，可将数据点信息转化为对应的经纬度信息保存在平台，以方便用户调用接口查询经纬度信息。

## 数据点上传

**数据流名称   $OneNET_LBS**

**单基站定位**

| 字段名称   | 数据类型   |  字段  |是否必填|
| --------| -----|----|----|
| 获取基站信息时间|date|bstime|选填|
| 移动网号|int|mnc|选填、目前仅支持0|
| 移动国家号码|int|mcc|选填、中国默认460|
| 地区区域码|int|lac|必填|
| 基站码|int|cid|必填|
| 网络制式|int|networkType|选填 <br/>0 GSM<br/>1 GSM Compact<br/>2 UTRAN <br/>3 GSM w/EGPRS <br/>4 UTRAN w/HSDPA <br/>5 UTRAN w/HSUPA <br/>6 UTRAN w/HSDPA and HSUPA <br/>7 E-UTRAN<br/>8 EC-GSM-IoT <br/>9 E-UTRAN <br/>10 E-UTRA connected to a 5G CN <br/>11 NR connected to a 5G CN <br/>12 NR connected to an EPS core <br/>13 NG-RAN <br/>14 E-UTRA-NR dual connectivity|


**数据流名称        $OneNET_LBS**<br/>**多基站定位**

| 字段名称 | 数据类型   |  字段  |是否必填|
| --------| -----|----|----|
| 获取基站信息时间|date|bstime|选填|
| 移动网号|int|mnc|选填、目前仅支持0|
| 移动国家号码|int|mcc|选填、中国默认460|
| 地区区域码|int|lac|必填|
| 基站码|int|cid|必填|
| 网络制式|int|networkType|必填 <br/>0 GSM<br/>1 GSM Compact<br/>2 UTRAN <br/>3 GSM w/EGPRS <br/>4 UTRAN w/HSDPA <br/>5 UTRAN w/HSUPA <br/>6 UTRAN w/HSDPA and HSUPA <br/>7 E-UTRAN<br/>8 EC-GSM-IoT <br/>9 E-UTRAN <br/>10 E-UTRA connected to a 5G CN <br/>11 NR connected to a 5G CN <br/>12 NR connected to an EPS core <br/>13 NG-RAN <br/>14 E-UTRA-NR dual connectivity|
|信号强度|int|ss|选填|
|当前基站广播信号强度|int|signalLength|选填|
|移动台距以确定其发往基站的定时超前量|int|ta|选填|
|基站信息数字进制|int|flag|选/必填<br/>基站信息是10进制flag写10，默认不填为10进制，基站信息是16进制，flag必须填写16|

-------------
注：当flag为10时，所有上报的数据均为10进制，当flag为16时，所有上报的数据均为16进制，且按照JSON规定，十六进制数当成字符串传。

**单基站定位数据上报格式**
```json
{
	"$OneNET_LBS": {
		"cid": 30183,
		"lac": 13112,
		"mcc": 460,
		"mnc": 0,
		"networktype": 5,
		"ss": -12,
		"ta": 1
	}
}
```


**多基站定位数据上报格式**
```json
{
	"$OneNET_LBS": [{
		"cid": 21089,
		"lac": 6334,
		"mcc": 460,
		"mnc": 0,
		"networktype": 5,
		"ss": -12,
		"ta": 1
	}, {
		"cid": 40673,
		"lac": 6334,
		"mcc": 460,
		"mnc": 0,
		"networktype": 5,
		"ss": -11,
		"ta": 1
	}]
}
```


## API说明

| 类别 | 功能         | 详细内容                                     |
|------|--------------|----------------------------------------------|
| API  | 最近位置查询 | 可返回最后一次定位结果的经纬度               |
|      | 历史轨迹查询 | 根据输入的时间区间范围实现时间区间内轨迹查询 |

## API接口

<API_ADDRESS>为：api.heclouds.com

### 查询轨迹

| HTTP方法 | GET                                                    |
|----------|--|
| URL  | http://API_ADDRESS/devices/device_id/lbs/getTrail         
| URL参数  | start= 2018-01-10T08:00:35.012 //表示查询轨迹的开始时间, 默认起始时间为本周一零点，可选，精确到毫秒级别 <br/>end= 2018-01-10T08:00:35.230 //表示查询轨迹的结束时间，默认结束时间为当前时间，可选 ，精确到毫秒级别  <br/>page = 1 //指定页码, 可选  <br/>per_page = 30 //指定每页输出设备个数,可选,默认10, 可选  <br/>maxLon=130.308 //最大经度, 可选  <br/>minLon=100.308 //最小经度, 可选 <br/> maxLat=30.0944 //最大纬度, 可选  <br/>minLat=10.0944 //最小纬度, 可选  <br/>sort = DESC\ASC //可选，默认为ASC（升序）  <br/>备注：最大、最小经纬度如果不传，查询所有轨迹。 如果四个参数都传入，则查询范围内轨迹。 |
| HTTP头部 | api-key:xxxx-ffff-zzzzz                              |
| 请求返回 | { "errno": 0,  <br/>"error":“succ”,  <br/>"data": { "page": 1,, <br/> "per_page": 10,  <br/>"total_count": 39,  <br/>"trail": [ <br/> { "at": "2018-06-13 15:15:22.012", //时间  <br/>"accuracy": 20, //精确度 <br/> "lon": 106.48881, //经度  <br/>"lat": 29.62518 //纬度 }, <br/> { "at": "2018-06-13 18:22:58.234", //时间 <br/> "accuracy": 20, //精确度 <br/> "lon": 106.48886999999999, //经度  <br/>"lat": 29.62514 //纬度 }, <br/> { "at": "2018-06-13 18:25:19.210", //时间 <br/> "accuracy": 20, //精确度  <br/>"lon": 106.48885, //经度 <br/> "lat": 29.62516 //纬度 } ] }|

    注：最大、最小经纬度如果不传，查询所有轨迹。 如果四个参数都传入，则查询范围内轨迹。

### 查询最新位置

| HTTP方法 | GET|
|----------|-|
| URL      | http://API_ADDRESS/devices/device_id/lbs/latestLocation    |
| HTTP头部 | api-key:xxxx-ffff-zzzzz
| url参数  | 无|
| 请求返回 | { "errno": 0, <br/> "error":“succ”,  <br/>"data": <br/> { "at": "2018-06-13 15:15:22", //时间 <br/> "accuracy": 20, //准确度 <br/>"lon": 106.48881, //经度 <br/> "lat": 29.62518 //纬度 } } |
