# API Interface Document

* API_ADDRESS address: api.video.heclouds.com

### 1. Device Management

** 1.1 Added**

| HTTP Method | POST|
|:---|:---|
|URL|http://API_ADDRESS/devices|
| HTTP header | api-key: xxxx-ffff-zzz, must be master KeyContent-Type: application/json|
| HTTP content |{<br> "title": "device1", // device name, must be selected. Within 64 characters. <br> "desc", "some description", // device description, optional. <br> "location": {"ele": 370000, //height, double < br > "lat": 17.609997, //longitude, double < br > "lon": 177.03403//latitude, double < br >}, //device location, optional. <br> "Private": true, // private or not, optional. Public applications are listed on open.iot.10086.cn. <br> "Protocol": "RTMP", // Device Access Protocol, must RTMP. <br> "auth_info": { } Authentication information is required. Only under the product. If not, default authentication information will be generated for the device. <br> "Area": "100", // Equipment Area Number, optional. It must be a legal area code. <br> "Other": { } The rest of the equipment information is optional. <br> "interval": 60, // reservation, invalid selection < br > "auth": "1233311", // reservation, invalid selection < br > "route_to", "abcd", // reservation, invalid selection < br > "url": "http://www.test.com", //device url". (meaning unknown) < br > "idsn": "test", //reserve, invalid selection < br > "activate_code": "test", //reserve, device activation code}
| HTTP Response Message Content | {"Erno": 0, <br> "error": "succ", <br> "data": <br> {<br>// Platform Assignment Unique ID <br> "device_id": "233444"<br>} < br> < data}
| Description | Additional device is used to add a device to the device cloud, and the device ID of the device will be returned after the addition is successful by HTTP POST request. A kind of



** 1.2 Registration Code Creation Device**

| HTTP Method | POST|
|:---|:---|
|URL|http://API_ADDRESS/register_de|
| URL parameter | register_code = xxxxx // device registration code, optional|
| HTTP Content |{"sn": "xxxx", //optional device unique identifier string type, up to 512 characters < br > "mac": "xxxx", //optional device unique MAC identifier string type, up to 512 characters < br > note that sn, MAC must fill in one of them, and only one <br> "title": "xxxx"//optional device name up to 32 characters, <br> "100//area number, optional < br> can be passed.
| Request return | {"errno": 0, <br> "error": "succ", <br> "data": <br> {<br> "key": <XXAABBCCDD, //api-key can only operate this device <br> "device_id": 21442 < br>} < br>} <br>}|


** 1.3 Update**

| HTTP Method | PUT|
|:---|:---|
|URL|http://API_ADDRESS/devices/{device_id}|
| HTTP header | api-key: xxxx-ffff-zzz, master key or device apikey. Content-Type: application/json|
|HTTP内容|{"title":"my device1", <br>"desc":"some description",<br>"private":true,<br>"tags":[<br>"Tag1",<br>"Tag2"<br>],<br>“url”: “http://www.test.com”,<br>“idsn”:”test”,<br>"location":{<br>"ele":370000,<br>"lat":17.609991828964787,<br>"lon":177.03402996826173<br>},<br>“route_to”:”test”, // edp设备有效。 <br> "auth_info": { } "auth123", < br > "auth":"123123", //reservation, invalid < br > "interval": 60, < br > "activate_code":"test", < br > "area":"100", < br > "other": {} < br > < br >}
| Request return | {br > "errno": 0, < br > "error": "succ", < br >}|
| Explain | When updating, updating that field only needs to include which field in the JSON string, not everything. <br> If any fields are not clear, please refer to the explanation of the new section of the equipment. A kind of

** 1.4 View individual device information**

| HTTP Method | GET|
|:---|:---|
|URL|http://API_ADDRESS/devices/{device_id}|
| HTTP header | api-key: xxxx-ffff-zzz, master key or device apikey. Content-Type: application/json|
| Request return | {errno": 0, <br>"error":"succ", <br>"data": <br> {br>"id":"device_id", <br>"online": true/false, //whether the device is online. <br> "protocol": "rtmp"< br > "title": "my device1", < br > "desc", "some description, ex: url", < br > (< br > < br > keys": [<br > {"title":"device-auto-key","key":"2JO3B12O1"}, <br > {"title-2","key":"DFWfsfw1wfDF233"}, < br > < br > < br > < br > keys.
| Description | Individual device view is to see the details of the device when the device ID of the device to be checked is known. It will return the basic information of the equipment to be checked, the apikey information related to the equipment, and so on. A kind of


** 1.5 Fuzzy Search Device Information**

| HTTP Method | GET|
|:---|:---|
|URL|http://API_ADDRESS/devices|
| HTTP header | api-key: xxxx-ffff-zzz, master key or device apikey. Content-Type: application/json|
| The URL parameter | key_words = key, // optional, matches left from the IMEI field of the device ID or title or Nb device. <br> tag = xxx, // optional. <br> online = true / false, // optional. <br> private = true / false, // optional. <br> Page = 1, // specify page number, optional, default 1, up to 10000 < br > per_page = 30 // / specify the number of output devices per page, optional, default 30, up to 100 < br > device_id = 235122 // specify device ID, optional, separated by commas, up to 100 < br > h_info ="{"auth":" auth 123",//authentication information, optional. <br> start = 2016-06-10// optional, < br > end = 2016-06-20// optional, < br > title = test// device name keyword, string, left match, case insensitive, optional. <br>|
|请求返回| {"errno": 0,<br>"error":“succ”,<br>"data":<br>{<br>"total_count":1,<br>"per_page":30,<br>"page":1,<br>"devices":<br>[<br>{<br>"id":"dev_id", <br>"title":"my device1",<br>“desc”:”device desc”,<br>"private":true,<br>"protocol":"RTMP”,<br>"online":ture/false,<br>"location":{"lon":106.55231191544001,"lat":29.535451246673}, <br> "create_time": "2013-02-11:12:22:33", <br> "auth_info": {"SYS": "z=8QY3r7aTQ48UKfqPnB=PybYRo=",<br> "channel_count": 2//device channel number < br> "last_login": "2018-11-20:34:09"//device last-on-line time < br>... <br>}<br> { } <br>... <br>]<br>}<br>}|
| Explanation | Batch view is a blurred lookup device that lists all eligible devices. <br> Batch lookup queries the device from the server side in the form of parameters attached to the URL. A kind of


** 1.6 Delete**

| HTTP Method | DELETE|
|:---|:---|
|URL|http://API_ADDRESS/devices/{device_id}|
| HTTP header | api-key: xxxx-ffff-zzz, which can be device-level Key or master Key < br > Content-Type: application/json|
| URL parameter | No|
| HTTP Content | No|
| Request return |{errno": 0, <br>"error":"succ"<br>}|
| Description | Deleting devices deletes all videos and pictures stored on the platform|



### 2. Channel Management

** 2.1 Query the channel information under the device**

| HTTP Method | GET|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/device/QryChannel|
| HTTP Header | api-key required|
| URL parameter | device_id=// device ID must be filled in|
| HTTP Content | No|
| |{<br> "errno":0,<br>  "error":"succ",<br>  "result":<br>  [<br>      { <br>         "channel_id":20,<br>         "title":"test_qwer",  <br>         "desc":"1qwqwq/"  <br>    },   <br>    { <br>         "channel_id":100,   <br>         "title":"my_quto_test",   <br>        "desc":"123_test"   <br>     }  <br>  ]<br>}|

** 2.2 Delete device downstream **

| HTTP Method | DELETE|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/device/DelChannel|
| HTTP Header | api-key required|
| URL parameter | device_id=// device ID must be filled in <br> channel_id=// channel number, must be filled in|
| HTTP Content | No|
| Successful return |{br > "errno": 0, <br > "error": "succ" < br >}|

** 2.3 Increase channel information under equipment**

| HTTP Method | POST|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/device/AddChannel|
| HTTP Header | api-key required|
| URL parameter | device_id=// device ID must be < br > channel_id=// channel ID, must be < br > title=// title, must be filled (length not more than 64 and can only be a combination of numbers, letters or numerals)< br > desc=// channel description|
| HTTP Content | No|
| Successful return |{br > "errno": 0, <br > "error": "succ" < br >}|
| Note | If the channel already exists, the error returns the following information: <br> {br> "errno": 16, <br> "error": "The channel already exists, cannot add again!" < br>}|

** 2.4 Modification of Channel Information under Equipment**

| HTTP Method | POST|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/device/ModifyChannel|
| HTTP Header | api-key required|
| URL parameter | device_id=// device ID must be < br > channel_id=// channel ID, must be < br > title=// title, must be filled (length not more than 64 and can only be a combination of numbers, letters or numerals)< br > desc=// channel description|
| HTTP Content | No|
| Successful return |{br > "errno": 0, <br > "error": "succ" < br >}|
| Note | If the modified channel does not exist, the error returns the following information: <br> {<br> "errno": 17, <br> "error": "This channel is not available under this device!" <br>}|


### 3. Order issuance

** 3.1 Send Order**

| HTTP Method | POST|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/cmds|
| HTTP Header | api-key required|
| URL parameter | device_id=// device ID < br > qos=// Whether device response is required, 0 does not need, 1 needs default value of 0 < br > type=// command type, 0, platform definition, 1 user definition default value of 0|
| HTTP Content | User-defined Data: json, string, binary data (less than 64K)|
| Successful return |{<br> <br> "errno": 0,<br> "error":succ,<br> "error":succ,<br> "data"{<br> <br> {<br> <br> "cmd_uuid":"2303-312-Fws",//instruction ID //instruction ID <br> "2303-312-Fws",//instruction ID <br> "cmd_status":4,///device download status (return of platform)<br> <br> <dev_resp> <br> {<br> "resp_code": 1,///device returned error code, 0 means the// Base64 < br >} < br > of the data returned by the device|
| Description | resp_code is command in device execution status < br > cmd_status as follows: < br > 0: device not online < br > 1: command has been created send < br > 2: command sent to device send OK < br > 3: command sent to device failed Send error < br > 4: device normal response OK < br > 5: command execution time out < br > 6: device response data error resp error . <br> When the command does not require a device reply, return 2 indicates that the download was successful. <br> Return >= 4 when a device reply is required indicates that the process of requesting the device at http has returned. When dev_resp is equal to 4, dev_resp returns <br> to 1 for the return of the device, and 2 needs to call the command-issuing state interface to get the command-issuing situation.|


**3.2 Common commands for device definition**

A. Setting the bit stream level

```
{
    “type”: ”video”,
    ”cmdId”: 6,
    ”cmd”:{
           “channel_id”: 1, //通道ID, 数字
           “level”: 1 //数字1-4(1:流畅 2:标清 3:高清 4:超清)
          }
}
```

B. Yuntai Control Instruction

```
{
  ”type”: ”video”,
  ”cmdId”: 7,
”cmd”:{
”channel_id”: number, //对应通道的ID(映射到数据流名称)
”stop”:number,  // 2 单步控制
”cmdV:number,  // 1: 焦距变大(倍率变大)  2:焦距变小(倍率变小)  3: 焦点前调 4: 焦点后调 5: 光圈扩大 6: 光圈缩小 11: 方向向上 12: 方向向下 13: 方向左转 14: 方向右转 22:自动扫描
”speed”: number //速度1-7
    }
}
```

C. Local Video List Query

```
{
   ”type”: ”video”,             //指令类型(设备SDK识别)
   ”cmdId”: 10,                //查询视频列表指令(设备SDK识别)
   ”cmd”:{
         ”channel_id”:1,
         ”page”:1,
         ”start_time”: ”2017-09-29 12:00:31”, // 可选
         ”end_time”: ”2017-09-29 13:00:30” //可选
         ”per_page”:20
}
} 
```

Local Video List Response

``` {
”all_count”: 25,    //查询的所有视频总数
”cur_count”:20,   //当前页视频数
”rvods”:[
{
   ”channel_id”:1
   ”video_desc”: ”test123”,
   ”size”: 222,   // 字节数
   ”beginTime”： ”2017-09-29 12:00:31”,
   ”endTime”: ”2017-09-29 13:00:30”
  }
]
}
```

### 4. Real-time Playback Interface

** 4.1 Lab Address Access**

| HTTP Method | GET|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/play_address|
| HTTP Header | api-key required|
| The URL parameter | device_id=// device ID that receives the data must be filled in < br > channel_id=// channelnum < br > protocol_type = playback protocol type 0:rtmp 1:hls 2:https-hls in the corresponding data stream name|
| HTTP Content | No|
| Successfully returned |{br > "errno": 0, < br > "error":"succ, < br >"data": {br >"addr": {ip: port", < br > "access Token", "string", < br > "type": "rtmpe", < br >} < br > < br >} < br >}|
| Explanation | Lab address needs to be spliced according to the return interface: <br>Rtmp real-time Lab address format: <br>Rtmp real-time Lab address format: <br>Rtmp real-time Lab address format: type:///ip:port/live/${device_id}-${device_id}-{channel_id}?AccessToken<br>Rtmp real-time Lab address example accessToken <br>accessToken<br>Rtmp real-time Lab address example: rtmp:///183.230.230.40.39.39:1935/live/2162826-2?1935/2162826-2?Token<br><Token<br><id} - ${begintime} - ${endti AccessToken < br > Rtmp history pull address example: <br > rtmp:///183.230.40.39:1935/rvod/2162826-2-201711131530-201711131530-201711131131131131511540? AccessToken <br ><br> Hls real-time pull address format: <br>http:///183.230.230.40.40.40.39:8080/live/live live ${udevice {_id}${${channel_id}/channel_id}/index.3m3index.3m3Token <hthththththththththththththththththththththththththththt<br>http://183.230.40.39:8080/live/live_2162826_2/index.m3u8?A CcessToken|

### 4.2 HLS stream preload request

| HTTP Method | GET|
|:---|:---|
|URL|http://HLS_PLAY_ADDRESS/live/live_{DEVICE_ID}_{CHANNEL_ID}/preload|
| HTTP Header | api-key required|
| URL parameter | token = xxxx, // playback token < br > idle_time = 120, // idle cleaning time (s), maximum 120|
| HTTP content||
| Successfully returned |{br > "errno": 0, <br > "error":"succ"< br >}|
| Explanation | HLS_PLAY_ADDRESS and token are returned by the HLS pull-down address interface. DEVICE_ID device ID, CHANNEL_ID channel ID < br> This interface can achieve the purpose of HLS stream preloading.|

### 4.3 Getting Live Thumbnails

| HTTP Method | GET|
|:---|:---|
|URL|http://coveraddr/live_preview/${device_id}-${channel_id}|
| HTTP Header||
| URL parameter | token = ""|
| HTTP content||
| Successful return of | image binary content|
| Description | Address and Token are accessToken and playback addresses returned when the pull-down address is obtained. The URL address <br>http://coveraddr/live_preview/${device_id}${channel_id} token=accessToken can be assembled directly by playback address and token.|

### 5. Picture-related interface

** 5.1 Picture Upload**

| HTTP Method | PUT|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/picture/upload|
| HTTP Header | api-key required|
| URL parameter | device_id = 1 < br > channel_id = 1 < br > format = "jpg"/"png"< br > name = "111"< br > desc = "picture description"|
| HTTP Content | Picture Binary Content|
| Successful return |{br > "errno": 0, <br > "error": "succ"}|
| Description | Can be uploaded on playback screenshots, etc < br > If the name of the uploaded image is the same, an error is returned.|

** 5.2 Get Picture List Information**

| HTTP Method | GET|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/picture/get_list|
| HTTP Header | api-key required|
| URL parameter | device_id = 1111 < br > channel_id = 11 < br > start_time = 111, / / / UNIX timestamp, optional filtering conditions < br > end_time = 222, / / / UNIX timestamp, optional filtering conditions < br > page_start= 1, //page start < br > page_size = 1 //page size|
| HTTP Content | No|
|成功返回|{<br>"errno": 0,<br>"error":”succ”<br>data:[<br>{<br>"format":”jpg” // jpg或png<br>"size": 1234,// 单位是字节<br>"date": 1234, // UNIX 时间戳<br>"name":"111",// 图片名(唯一ID)<br>"desc" : "name", // 图片描述<br>"url" : "url"  //图片获取url<br>}<br>],<br>"page_info":{<br>"total_num":50<br>"page_total":25, <br> "page_size": 2, < br > "current_page": 1 < br >} < br >|
| Description|-|

** 5.3 Access to Picture Information**

| HTTP Method | GET|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/picture/get_info|
| HTTP Header | api-key required|
| URL parameter | device_id = 1111 < br > channel_id = 11 < br > name = 1, // image name|
| HTTP Content | No|
| Succccessfreturns |{<br> "errno":0,<br> "error":succ succ"<br><data:<br><br>{<br>{<br> <format"<br> <format"<br> <br> <format"<jpg"//jpg or png<br> br>"size":1234,//unit byte <br> br>"date":1234,///UNIX timestamp <br>"date":1234,///UNIX timestamp <br>"name":"111", //image name (unique ID)<br><unique ID)<br><descr>"// Picture acquisition URL < br >} < br >|
| Description|-|

** 5.4 Delete pictures**

| HTTP Method | DELETE|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/picture/delete_pictrue|
| HTTP Header | api-key required|
| URL parameter | device_id = 1111 < br > channel_id = 11 < br > name = 1, // image name|
| HTTP Content | No|
| Successful return |{br > "errno": 0, <br > "error": "succ"}|
| Description|-|

** 5.5 Get pictures**

| HTTP Method | GET|
|:---|:---|
|URL|$url|
| HTTP Header | No|
| URL parameter | No|
| HTTP Content | No|
| Successful Return | Return Picture Data|
| Description | $url returns from the interface in Getting Picture Information or Getting Picture List Information|

### 6. VOD-related interfaces

** 6.1 Video Information Acquisition**

| HTTP Method | GET|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/vod/get_video_info|
| HTTP Header | api-key required|
| URL parameter | device_id = 12, < br > channel_id = 12, < br > video_id = "1112341234", < br > Security = 1 // select secure playback link (https and rtmpe), otherwise default to normal link|
| HTTP content||
|成功返回|{<br>"errno": 0,<br>"error":”succ”,<br>"data":{   <br> "videoid":dafdafd<br>"name":“dad”,<br>"start":"2017-01-12 12:01:12",<br>"end":"2017-01-12 15:01:12",<br>"size":"1234",// 单位是Kbytes<br>"durtion":"12", // 单位是秒<br>"hls_url":"url",// http播放地址<br>"rtmp_url":"url" // RTMP播放地址<br>}<br>}|
| Note | Play address needs to carry token. For token acquisition, see "Video on Demand token acquisition" <br> assembled in hls: url? Token= "token", rtmp: url? Token. <br> Hls adds a parameter token according to HTTP URL parameter, and the parameter value is the token content obtained. <br> The Rtmp protocol splices token content directly behind "?". <br> Security defaults to 0, returns normal playback links (http and rtmp), and 1 returns secure playback links (https and rtmpe)|

** 6.2 Video List Access**

| HTTP Method | GET|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/vod/get_video_list|
| HTTP Header | api-key required|
| URL parameter |device_id=12, <br>channel_id=12, <br>channel_id=12, <br>channel_id=12, <br>start_time= "2018-01-01:01:00:00"//formatted string optional filtering conditions <br>end_time= "2018-01-01-01:01:00:00"//formatted string optional filtering conditions <br>name="name=" 111"////optional filtering conditions, according to name filter <br>page_start_page= 1,///page start <br>page start_page=1//page start_page=1//page size <br>page>page size=1//page size=1//security/security/security/security Selection Choose secure playback links (https and rtmpe), otherwise default to normal links|
| HTTP content||
|成功返回|{<br>"errno": 0,<br>"error":”succ”,<br>"data":{<br>    "videos":[<br>{<br> "videoid":"dafdafd",<br>      "name":"dad",<br>      "start":"2017-01-12 12:01:12",<br>      "end":"2017-01-12 15:01:12",<br>      "size":1234,// 单位是KBytes<br>"hls_url":"url",// http播放地址<br>      "rtmp_url":"url" // RTMP播放地址<br>},<br> { }, <br>... <br>] <br>} <br> "page_info": <br> {<br> "total_num": 50, <br> "page_total": 25, <br> "page_size": 2, <br> "current_page": 1 < br>} < br> current_page < 1 < br > < br > < br >} < br > current_page|
| Note | Select the filter time to fill in only start_time or end_time, or fill in <br> playback address with token. For token acquisition, see "Video on Demand token acquisition" <br> assembled in hls: url? Token= "token", rtmp: url? Token. <br> Hls adds a parameter token according to HTTP URL parameter, and the parameter value is the token content obtained. <br> The Rtmp protocol splices token content directly behind "?". <br> Security defaults to 0, returns normal playback links (http and rtmp), and 1 returns secure playback links (https and rtmpe)|

** 6.3 Video Delete**

| HTTP Method | POST|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/vod/delete_video|
| HTTP header | api-key required < br > Content-Type: application/json|
| URL parameter | deviceid = 1, < br > channeled = 1|
| HTTP Content | {br > "video": [{br > "videoId": 1 < br >}, < br > {br > "videoId": 2 < br >} < br > < br > and < br >} < br >} <|
| Successfully returned | {br > "errno": 0, < br > "error":"succ, < br >"data": < br > [< br > {code": 0} < br > {code ": 1," message ":"not exist"} < br >] < br >} <|
| Description | The return message gives the result of each deletion ID in an array, and if the deletion fails, the error message videoId must be a string.|

** 6.4 Video Renaming**

| HTTP Method | PUT|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/vod/rename_video|
| HTTP header | api-key required < br > Content-Type: application/json|
| URL parameter | device_id = 12, < br > channel_id = 12, < br > video_id="1112341234".|
| HTTP Content | {"name": "11111"}|
| Successful return |{br > "errno": 0, < br > "error":"succ, < br >}|
| Description|-|

** 6.5 Video On Demand Token Access**

| HTTP Method | GET|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/vod/get_play_token|
| HTTP Header | api-key required|
| URL parameter | device_id = 12, < br > channel_id = 12, < br > video_id="1112341234".|
| HTTP content||
| Successfully returned |{br > "errno": 0, < br > "error":"succ, < br >"data": {br >"token":"sdafsa"< br >} < br >} < br >}|
| Description | Token for VOD-related video capture|


### 7. Product Encryption

** 7.1 Setting up Video Encryption Switch for Products**

| HTTP Method | PUT|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/trans_encrypt|
| HTTP Header | api-key required|
| URL parameter | product_id = 7355 // product id|
| HTTP content |{type": 0} 0 is not encrypted, 1 is encrypted|
| Successful return |{br > "errno": 0, <br > "error": "succ" < br >}|
| Description||

** 7.2 Access to Product Encryption Status**

| HTTP Method | GET|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/trans_encrypt|
| HTTP Header | api-key required|
| URL parameter | product_id = 7355 // product id|
| HTTP Content | No|
| Successful return |{errno": 0,"trans_enc": 1}|
| Description|-|

### 8. Query device online status

| HTTP Method | GET|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/device/QryDevStatus|
| HTTP Header | api-key required|
| URL parameter | devIds = 123,456,789// device ID string, separated by commas, up to 30, no longer than 500, required fields|
| HTTP Content | No|
| Successfully returned | {"errno": 0,<br> "error": "succ", <br> "result": {<br> "total_count": 2,<br> "devices": [<br> {<br> "id": [<2480461,<br> "online": false < br>}, <br> {id":<2818370,<br>"online"<false < br> < online"<br> < br> < br> < br > < br >} < br > < br > < br >} <br > devices <br > <br >|
| Description||

### 9. Query equipment to transmit information

| HTTP Method | GET|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/device/QryDevMsg|
| HTTP Header | api-key required|
| URL parameter | device_id=// device ID must be filled in < br > begin_time=// query start time must be filled in 2018-01-01 00:00 < br > end_time=// query end time must be filled in 2018-01-02 00:00:00|
| HTTP Content | No|
|成功返回|{"errno":0,<br>"error":"succ",<br>"page_info":<br>{<br>"total_num":7,<br>"page_total":1,<br>"page_size":50,<br>"current_page":1<br>},<br>"result":<br>[    <br>{<br>"create_time":"2018-01-04 16:27:40",<br>"msg_id":14,<br>"msg":"bXlfdGVzdF8xMjM0NQ=="<br>},<br>{<br>"create_time":"2018-01-04 16:31:53",<br>"msg_id":14,<br>"msg":"bXlfdGVzd F8xMjM0NQ=="<br>},<br>{<br>"create_time":"2018-01-08 09:27:00",<br>"msg_id":4398046511104,<br>"msg":"bXlfdGVzdF8xMjM0NQ=="<br>},<br>{<br>"create_time":"2018-01-08 10:06:16",<br>"msg_id":4398046511104,<br>"msg":"bXlfdGVzdF8xMjM0NQ=="<br>},<br>{<br>"create_time":"2018-01-08 10:07:19",<br>"msg_id":4398046511104,<br>"msg":"bXlfdGVzdF8xMjM0NQ=="<br>},< Br >{<br>{<br> <br>"create_time": "2018-01-08 10:09:49",<br>"msg_id":4398046511104,<br>"msg":<br>"msg":bXlfdGVzdFzdF8xMjM8xMjM0NQ=="<br>>"<br>{<br>{<br>{<br>{<br><br> <br>{<br><br>{<br>"create_time"<br>14:10:35"<br><br>"msg_id":439804046511104,<br><br jM0NQ="<br>}<br>]<br>}<br>>|
| Description | The message content transmitted by the device (msg field) is encoded by Base64 and needs to be decoded by the client. A kind of


### 10. Query boot machine address

| HTTP Method | GET|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/boot_address|
| HTTP Header | No|
| URL parameter | No|
| HTTP Content | No|
| Successfully returned |{br > "errno": 0, < br > "error": "succ", < br > "data": <br > {br > "boot_address": "183.230.40.42", < br > "boot_port": 9101 < br >} < br >} <|
| Description|-|

### 11. Equipment data transmission

| HTTP Method | POST|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/dev_active|
| HTTP Header | api-key required|
| URL parameter | device_id=// device ID|
| HTTP content | custom, no more than 128 byte|
| Successful return |{br > "errno": 0, // 0 command sent successfully < br > "error": "succ" < br >}|
| Description | Scenario applicable to this interface: The device needs to receive a fixed string <br> protocol and will not encrypt the string. The serial number of the protocol header will be set to zero <br> and the header string received by the device will be fixed.|



### 12. Video Recording Interface

| HTTP Method | GET|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/record/record_video|
| HTTP Header | api-key required|
| URL parameter | product_id = 12 < br > device_id = 123 < br > channel_id = 12345 < br > action = 0/1, // 0: stop recording 1: start recording, must be selected|
| HTTP content||
| Successful return |{br > "errno": 0, <br > "error": "succ" < br >}|
| Description | product_id: Product number, required parameter < br > device_id: device number, required parameter < br > channel_id: channel number, required parameter < br > action: operation type, 0: stop recording 1: start recording, required parameter|


### 13. Real-time query

** 13.1 Play Real-time Query**

| HTTP Method | GET|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/stat/getonlinelist|
| HTTP Header | api-key must be filled in < br > Note: Master-key only|
| URL parameter | productid=// product number must be filled in < br > deviceid =// device ID < br > channelid =// channel number < br > protocoltype =// protocol type RTMP HLS < br > page_key=// paging query using < br > page_size=// data per page query < br > page = paging query using < br > page = paging query|
| HTTP Content | No|
| |{<br>   "errno":0,<br>    "error":"succ",<br>    "result":<br>    [<br>        {<br>            "productid":7312,<br>            "deviceid":2479989,<br>            "channelid":1,<br>            "protocoltype":"RTMP",<br>            "clientip":"172.19.3.99",<br>            "videocodec":"H264",<br>            "resolution":"1280 * 720",<br>            "fps":25,<br>            "audiocodec":"",<br>            "bandwidth":91392,<br>            "onlinetime":"00:04:43"<br>        },<br>        {<br>            "productid":7312,<br>            "deviceid":2479989,<br>            "channelid":2,<br>            "protocoltype":"RTMP",<br>            "clientip":"172.19.3.99",<br>            "videocodec":"H264",<br>            "resolution":"1280 * 720",<br>            "fps":25,<br>            "audiocodec":"",<br>            "bandwidth":63066,<br>            "onlinetime":"00:07:00"<br>        }<br>    ],<br>    "page_info":<br>    {<br>        "total_num":3,<br>        "page_total":2,<br>        "page_size":2,<br>        "current_page":1,<br>        "page_key":"fc94c7c4-0760-4523-876c-5583260520c6"<br>    }<br>}|
| Note | 1) For real-time queries, data queries after the first page need to be passed in page_key < br > 2) Paging data server caches for only 5 minutes, and will fail after 5 minutes.|

** 13.2 Push Flow Real-time Query**

| HTTP Method | GET|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/stat/getpushlist|
| HTTP Header | api-key must be filled in < br > Note: Master-key only|
| URL parameter | productid=// product number must be filled in < br > deviceid =// device ID < br > channelid =// channel number < br > page_key =// paging query using < br > page_size =// data per page query < br > page = paging query using < br > page = paging query|
| HTTP Content | No|
| Successfreturns |{<br> <br> "errno":0,<br> "error": "succ"<br> "result": <br> <br> <br> <br> "result": <br> <br> <br> "product id":7312,<br> <7312,<br> <br> <deviceid"<2479989,<br> <br>"channelid":3,<br><br>"channel id"<3,<br><br>"protocoltype"<RTMP,<br> <br>"protocoltype":RTMP"<br"<br> <br>"<b" R > "fps": 25, < br > "audiocodec": "AAC", < br > "bandwidth": 95230, < br > "pushtime", "00:06:37" < br > "pushtime", < br > {productid": 7312, < br >"deviceid": 2479 989, < br >"nelid": 1, < br >"prototype","RTMP,< br > "channel width", "172.19.3" < bv > "pushtime". Ideocodec "::" H264",<br>"resolution ":::" 1280*720",<br>"resolution "::" 1280*720",<br>"fps": 25,<br><br>"<br>"fps": 25,<br>"audiocodec""""",<br>"",,<br>"""""<br>"pushtime""""""""""""""""""""""""""<br>"""pushtime""""""""""""""""""""""""""""00:04:43"<br> < br>}}"page_size": 2, <br> and "current_page": 1,.< Br > "page_key": "5931b760-864a-44fb-9dd0-558e7caaace0" < br >} < br >|
| Note | Paging queries are processed in the same way as playlists|

### 14. Camera Disabled/Enabled Interface

| HTTP Method | PUT|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/access_control/closecamera|
| HTTP Header | api-key required|
| URL parameter | product_id = 12, // product ID < br > device_id = 123, / / device ID < br > id = "1" and // camera ID|
| HTTP Content |{br > "type": 1, //1 is off, 0 is on < br >|
| Successfully returned |{br > "errno": 0, <br > "error":"succ"< br >}|



### 15. Public Object Storage

| HTTP status code | error code | meaning|
|-|-|-|
| 200 | 200 | success|
| 400 | 400 | bad request|
| 401 | 401 | Authentication Failure|
| 403 | 403 | Insufficient privileges, access deny|
| 404 | 404 | Resource not found|
| 405 | 405 | method not allowed|



| HTTP status code | error code | meaning|
|-|-|-|
| 413 | 413 | Request resource size greater than the specified maximum (resource size is too big)|
| 500 | 500 | System internal error|
| 502 | 502 | bad gateway|
| 503 | 503 | Service unavailable|
| 504 | 504 | gateway timeout|
| 1001 | 1001 | invalid name, excluding special characters|
| 1002 | 1002 | invalid name, maximum limit is 256 (invalid name, maximum limit is 256)|
| 1003 | 1003 | invalid description, maximum limit is 1024 (invalid desc, maximum limit is 1024)|


** 15.1 Upload**

| HTTP Method | PUT|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/file/upload|
| HTTP Header | api-key and authorization|
| URL parameter | product_id = 1111, < br > name = test, < br > desc = 1111, // optional|
| HTTP Content | Uploaded File Content|
| Successfully returned |{br > "errno": 200, <br > "error":"succ"< br >}|
| Description | Upload object size is limited to 8M|

** 15.2 Download**

| HTTP Method | GET|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/file/download|
| HTTP Header | api-key and authorization|
| URL parameter | product_id = 1111, < br > name = test|
| HTTP Content | No|
| Successfully returning the binary content of the | file|
| Description|-|

** 15.3 Delete **

| HTTP Method | DELETE|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/file/delete|
| HTTP Header | api-key and authorization|
| URL parameter | product_id = 1111, < br > name = test|
| HTTP Content | No|
| Successfully returned |{br > "errno": 200, <br > "error":"succ"< br >}|
| Description|-|

** 15.4 Access List**

| HTTP Method | GET|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/file/list|
| HTTP Header | api-key and authorization|
| URL parameter | product_id = 1111, < br > name = test|
| HTTP Content | No|
| Successfreturned |{"data": [{<br>"product_id":111,<br>"name":: <test",<br>"name"<test",<br><br>>"size":1024,<br><date":154822228623,<br>"date"15484822228623,<br><desc"""""<br>>}],<br>"errno":0,<br><error,<br><br>>>>>>"error"<succ succ succ,<br><br>"page_info"::{<page_info"{<br> <br> <total_info> <size": 50, < br > "current_page": 1 < br >} < br >}|
| Description|-|