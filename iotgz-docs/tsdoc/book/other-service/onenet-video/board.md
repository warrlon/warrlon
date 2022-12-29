# API Interface Document

* API_ADDRESS address: api.video.heclouds.com

### 1. Device Management

**1.1 Added**

|HTTP method|POST|
|:---|:---|
|URL|http://API_ADDRESS/devices|
|HTTP Header|Api-key: xxxx-ffff-zzz, must be master KeyContent-Type: application/json|
|HTTP content|{<br>"Title", "device 1", // device name, must be selected. Within 64 characters.<br>    "Desc": "some description", // device description, optional.<br>"Location": {ele": 370000, // height, double<br>"Lat": 17.609997, //longitude, double<br>"Lon": 177.03403//latitude, double<br>} The // device location is optional.<br>"Private": true, // private or not, optional. Public applications are listed on open.iot.10086.cn.<br>"Protocol": "RTMP", // Device Access Protocol, must RTMP.<br>"Auth_info": { } Authentication information is required. Only under the product. If not, default authentication information will be generated for the device.<br>"Area": "100", // Equipment Area Number, optional. It must be a legal area code.<br>"Other": { } The rest of the equipment information is optional.<br>"Interval": 60, //reservation, invalid choice<br>"Auth": "1233311", //reservation, invalid choice<br>"Route_to":"abcd", //reservation, invalid selection<br>"Url": "http://www.test.com", //device url". (The meaning is unknown)<br>"Idsn": "test", //reservation, invalid selection<br>"Activate_code":"test", //reserve, device activation code}
|HTTP response response message content| {"errno": 0,<br>"error":“succ”,<br>"data":<br>{<br>// Platform Assignment Unique ID<br>"device_id":"233444"<br>}<br>}
|Explain|The new device is used to add a device to the device cloud. The device is added through HTTP POST request. When the device is added successfully, the device ID of the device will be returned.|



**1.2 Registry Code Creation Device**

|HTTP method|POST|
|:---|:---|
|URL|http://API_ADDRESS/register_de|
|url parameter|Register_code = xxxxx // device registration code, optional|
|HTTP content|{"sn": "xxxx", //optional device uniquely identifies string type, up to 512 characters<br>"Mac": "xxxx", //optional device unique MAC identifier string type, up to 512 characters<br>Note that sn, MAC must fill in one of them, and can only pass one<br>"Title": "xxxx"//Optional device name up to 32 characters,<br>"Area": 100// area number, optional<br>}
|Request return| {"errno": 0,<br>"error":“succ”,<br>"data":<br>{<br>"Key": "XXAABBCCDD", //api-key can only operate this device<br>"device_id": 21442<br>}<br>}|


**1.3 Update**

|HTTP method|PUT|
|:---|:---|
|URL|http://API_ADDRESS/devices/<device_id>|
|HTTP Header|Api-key: xxxx-ffff-zzz, master key or device apikey. Content-Type: application/json|
|HTTP content|{"title":"my device1", <br>"desc":"some description",<br>"private":true,<br>"tags":[<br>"Tag1",<br>"Tag2"<br>],<br>“url”: “http://www.test.com”,<br>“idsn”:”test”,<br>"location":{<br>"ele":370000,<br>"lat":17.609991828964787,<br>"lon":177.03402996826173<br>},<br>"Route_to": "test", // EDP device is valid.<br>"auth_info":{…}“auth123”,<br>"Auth":"123123", //reservation, invalid<br>"interval":60,<br>“activate_code”:”test”,<br>"area":”100”, <br>"other":{}<br>}
|Request return| {<br>"errno": 0,<br>"error":“succ”,<br>}|
|Explain|When updating, updating that field only needs to include which field in the JSON string, not everything.<br>If any fields are not clear, please refer to the explanation of the new section of the equipment.|

**1.4 View individual device information**

|HTTP method|GET|
|:---|:---|
|URL|http://API_ADDRESS/devices/<device_id>|
|HTTP Header|Api-key: xxxx-ffff-zzz, master key or device apikey. Content-Type: application/json|
|Request return| {"errno": 0,<br>"error":“succ”,<br>"data":<br>{<br>"id":"device_id",<br>"Online": true / false, // whether the device is online.<br>"protocol":"rtmp"<br>"title":"my device1", <br>"desc":"some description,ex:url",<br>......<br>"keys":[<br>{"title":"device-auto-key","key":"2JO3B12O1"},<br>{"title":"key-name2","key":"DFWfsfw1wfDF233"},<br>]<br>}<br>}
|Explain|A single device view is to see the details of the device with the device ID of the device to be checked. It will return the basic information of the equipment to be checked, the apikey information related to the equipment, and so on.|


**1.5 Fuzzy Search for Equipment Information**

|HTTP method|GET|
|:---|:---|
|URL|http://API_ADDRESS/devices|
|HTTP Header|Api-key: xxxx-ffff-zzz, master key or device apikey. Content-Type: application/json|
|url parameter|Key_words = key, // optional, matches left from the device ID or title or the IMEI field of the Nb device.<br>Tag = xxx, // optional.<br>Online = true / false, // optional.<br>Private = true / false, // optional.<br>Page = 1, // Specified Page Number, optional, default 1, up to 10000<br>Per_page = 30// Specifies the number of output devices per page, optional, default 30, up to 100<br>Device_id = 235122// Specified device ID, optional, multiple commas separated, up to 100<br>Auh_info="{"auth":"auth123"}", //authentication information, optional.<br>Begin = 2016-06-10// Optional,<br>End = 2016-06-20// optional,<br>Title = test // device name keyword, string, left match, case insensitive, optional.<br>|
|Request return| {"errno": 0,<br>"error":“succ”,<br>"data":<br>{<br>"total_count":1,<br>"per_page":30,<br>"page":1,<br>"devices":<br>[<br>{<br>"id":"dev_id", <br>"title":"my device1",<br>“desc”:”device desc”,<br>"private":true,<br>"protocol":"RTMP”,<br>"online":ture/false,<br>"location":{"lon":106.55231191544001,"lat":29.535451246673},<br>"create_time":"2013-02-11 12:22:33",<br>"auth_info":{"SYS":"z=8QY3r7aTQ48UKfqPnB=PybYRo="},<br>"Channel_count": 2//number of device channels<br>"Last_login": "2018-11-20 15:34:09"// Last time of equipment on line<br>……<br>}<br>{……},<br>……<br>]<br>}<br>}|
|Explain|Batch checking refers to blurring the device and listing all eligible devices.<br>Batch lookup queries the device from the server side in the form of parameters attached to the URL.|


**1.6 Delete**

|HTTP method|DELETE|
|:---|:---|
|URL|http://API_ADDRESS/devices/{device_id}|
|HTTP Header|Api-key: xxxx-ffff-zzz, which can be a device-level Key or master Key<br>Content-Type:application/json|
|url parameter|nothing|
|HTTP content|nothing|
|Request return|{"errno": 0,<br>"error":“succ”<br>}|
|Explain|Deleting devices deletes all videos and images stored on the platform|



### 2. Channel Management

**2.1 Query the channel information under the device**

|HTTP method|GET|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/device/QryChannel|
|HTTP Header|Api-key required|
|url parameter|Device_id=// Device ID must be filled in|
|HTTP content|nothing|
| |{<br> "errno":0,<br>  "error":"succ",<br>  "result":<br>  [<br>      { <br>         "channel_id":20,<br>         "title":"test_qwer",  <br>         "desc":"1qwqwq/"  <br>    },   <br>    { <br>         "channel_id":100,   <br>         "title":"my_quto_test",   <br>        "desc":"123_test"   <br>     }  <br>  ]<br>}|

**2.2 Delete device DOWN-channel**

|HTTP method|DELETE|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/device/DelChannel|
|HTTP Header|Api-key required|
|url parameter|Device_id=// Device ID must be filled in <br> Channel_id=//Channel number, required|
|HTTP content|nothing|
|Successful return|{<br>    "errno":0,<br>    "error":"succ"<br>}|

**2.3 Increase Channel Information under Equipment**

|HTTP method|POST|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/device/AddChannel|
|HTTP Header|Api-key required|
|url parameter|Device_id=// Device ID must be filled in<br>Channel_id=//Channel ID, required<br>Title=// Title, mandatory (no longer than 64 and only numbers, letters or combinations of numbers and letters)<br>Desc=//channel description|
|HTTP content|nothing|
|Successful return|{<br>    "errno":0,<br>    "error":"succ"<br>}|
|Explain|If the channel already exists, the error returns the following information:<br>{<br>"errno": 16,<br> "error": "The channel already exists,cannot add again!"<br>}|

**2.4 Modifying Channel Information under Equipment**

|HTTP method|POST|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/device/ModifyChannel|
|HTTP Header|Api-key required|
|url parameter|Device_id=// Device ID must be filled in<br>Channel_id=//Channel ID, required<br>Title=// Title, mandatory (no longer than 64 and only numbers, letters or combinations of numbers and letters)<br>Desc=//channel description|
|HTTP content|nothing|
|Successful return|{<br>    "errno":0,<br>    "error":"succ"<br>}|
|Explain|If the modified channel does not exist, the error returns the following information:<br>{<br>"errno": 17,<br> "error": "This channel is not available under this device!"<br>}|


### 3. Order issuance

**3.1 Send commands**

|HTTP method|POST|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/cmds|
|HTTP Header|Api-key required|
|url parameter|Device_id=//Device ID<br>Qos=// Whether device response is required, 0 does not need, 1 needs a default value of 0<br>Type=// Command Type, 0, Platform Definition, 1 User Definition Default Value is 0|
|HTTP content|User-defined data: json, string, binary data (less than 64K)|
|Successful return|{<br>"errno": 0,<br>"error":”succ”,<br>"data":{<br> "Cmd_uuid": "2303-312-Fws", //instruction ID<br>"Cmd_status": 4, / / / status of device download (return of platform)<br>"dev_resp": {<br>   "Resp_code": 1, / / / the error code returned by the device, 0 indicates success  <br>"Resp_data": "xxxxxx"//base64 of the data returned by the device<br>}<br>|
|Explain|Resp_code is the execution state of the command on the device<br>Cmd_status is as follows:<br>0: The device is not online<br>1: The command has created send<br>2: The command has been sent to the device send OK<br>3: Send error failed to send command to device <br>4: normal device response OK<br>5: Command execution time out<br>6: Device response data error resp data error.<br>When the command does not require a device reply, return 2 indicates that the download was successful.<br>Return >= 4 when a device reply is required indicates that the process of requesting the device at http has returned. De_resp is the return of the device when equal to 4<br>Return 1,2 to call the command-issuing state interface to get the command-issuing situation|

**3.2 Command Status Query**

|HTTP method|GET|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/cmd_status|
|HTTP Header|Api-key required|
|url parameter|Device_id=//Device ID<br>Cmd_uuid=//command issuing interface returns instruction ID|
|HTTP content|nothing|
|Successful return|{<br>"errno": 0,<br>"error":”succ”,<br>"data":{<br>"Status": 1, / / / status of device download (platform return)<br>"desc":"sending" <br>}|
|Explain|Command status<br>0: The device is not online<br>1: The command has created send<br>2: The command has been sent to the device send OK<br>3: Send error failed to send command to device <br>4: normal device response OK<br>5: Command execution time out<br>6: Device response data error resp data error|


**3.3 Command Response to Queries**

|HTTP method|GET|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/cmd_resp|
|HTTP Header|Api-key required|
|url parameter|Device_id=//Device ID<br>Cmd_uuid=//command issuing interface returns instruction ID|
|HTTP content|nothing|
|Successful return|{<br>"errno": 0,<br>"error":”succ”,<br>"Resp":"XXXXXXX"// Response content of the device, Base64 encoding<br>}|
|Explain|After 60 seconds, the valid time of the device replying to the platform is 60 seconds. After 60 seconds, the platform will delete the cached data of the device replying content.|

**3.4 Specific Flow Chart of Command**

The flow charts of the above three APIs used when actually issuing a command are as follows:

When qos== 0, the commands that do not need to be answered by the device, such as cloud operation, resolution adjustment and so on, are not needed.

![pic1](/images/vedio-image/API说明01.png)

When qos==1, commands requiring device reply, such as getting a list of video files on the device

![pic2](/images/vedio-image/API说明02.png)

**3.5 Common Commands for Device Definition**

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

**4.1 Lab Address Acquisition**

|HTTP method|GET|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/play_address|
|HTTP Header|Api-key required|
|url parameter|Device_id=// Device ID that receives this data, must be filled in<br>Channelnum in channel_id=// corresponding data stream name <br>Protocol_type = playback protocol type 0:rtmp 1:hls 2:https-hls|
|HTTP content|nothing|
|Successful return|{<br>"errno": 0,<br>"error":”succ”,<br>“data”:{<br>"addr":"ip:port",<br>"AccessToken": "String".<br>"type":"rtmpe",<br>}<br>}|
|Explain|Pull-flow addresses need to be spliced according to the return interface:<br>Rtmp real-time pull-down address format: type://ip: port/live/${device_id} - ${channel_id}? AccessToken<br>Rtmp real-time pull-down address example: rtmp://183.230.40.39:1935/live/2162826-2?Access Token<br><br>Rtmp Historic Lab Address Format:<br> rtmp://ip:port/rvod/${device_id}-${channel_id}-${begintime}-${endtime}?accessToken<br>Rtmp Historic Lab Address Example:<br>rtmp://183.230.40.39:1935/rvod/2162826-2-201711131530-201711131540?accessToken<br><br>Hls real-time pull-down address format:<br>http://183.230.40.39:8080/live/live_${device_id}_${channel_id}/index.m3u8?accessToken<br>Hls real-time pull-down address example:<br>http://183.230.40.39:8080/live/live_2162826_2/index.m3u8?accessToken|

### 4.2 HLS stream preload request

|HTTP method|GET|
|:---|:---|
|URL|http://HLS_PLAY_ADDRESS/live/live_DEVICE_ID_CHANNEL_ID/preload|
|HTTP Header|Api-key required|
|url parameter|Token = xxxxx, // play token<br>Idle_time = 120, // idle cleaning time (s), maximum 120|
|HTTP content| |
|Successful return|{<br>"errno": 0,<br>"error":”succ”<br>}|
|Explain|HLS_PLAY_ADDRESS and token are returned by the HLS pull-down address interface. DEVICE_ID device ID, CHANNEL_ID channel ID<br>    The interface can achieve the purpose of HLS stream preloading.|

### 4.3 Getting Live Thumbnails

|HTTP method|GET|
|:---|:---|
|URL|http://coveraddr/live_preview/${device_id}-${channel_id}|
|HTTP Header| |
|url parameter|token = “”|
|HTTP content| |
|Successful return|Picture Binary Content|
|Explain|Address and Token are accessToken and playback addresses returned when the pull-down address is obtained. The URL address can be assembled directly by playback address and token.<br>http://coveraddr/live_preview/${device_id}_${channel_id}?token=accessToken|

### 5. Picture-related interface

**5.1 Picture Upload**

|HTTP method|PUT|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/picture/upload|
|HTTP Header|Api-key required|
|url parameter|device_id =1<br>channel_id=1<br>format=”jpg”/”png”<br>name="111"<br>Desc= "Picture Description"|
|HTTP content|Picture Binary Content|
|Successful return|{<br>"errno": 0,<br>"error":”succ”}|
|Explain|Can be uploaded on screenshots at the playback end, etc.<br>If the name of the image is the same as that of the uploaded image, an error is returned.|

**5.2 Getting Picture List Information**

|HTTP method|GET|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/picture/get_list|
|HTTP Header|Api-key required|
|url parameter|device_id ="1111"<br>channel_id=11<br>Start_time = 111, // UNIX timestamp, optional filtering conditions<br>End_time = 222, // UNIX timestamp, optional filtering conditions<br>Page_start= 1, // Paging Start<br>Page_size = 1 // Page size|
|HTTP content|nothing|
|Successful return|{<br>"errno": 0,<br>"error":”succ”<br>data:[<br>{<br>"Format": "jpg"// JPG or png<br>"Size": 1234, // units are bytes<br>"Date": 1234, // UNIX timestamp<br>"Name": "111", // image name (unique ID)<br>"Desc": "name", // picture description<br>"Url": "url"//image acquisition URL<br>}<br>],<br>"page_info":{<br>"total_num":50<br>"page_total":25,<br>"page_size":2,<br>"current_page":1<br>}<br>}|
|Explain|-|

**5.3 Getting Picture Information**

|HTTP method|GET|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/picture/get_info|
|HTTP Header|Api-key required|
|url parameter|device_id ="1111"<br>channel_id=11<br>Name = 1, // Picture Name|
|HTTP content|nothing|
|Successful return|{<br>"errno": 0,<br>"error":”succ”<br>data:<br>{<br>"Format": "jpg"// JPG or png<br>"Size": 1234, // units are bytes<br>"Date": 1234, // UNIX timestamp<br>"Name": "111", // image name (unique ID)<br>"Desc": "name", // picture description<br>"Url": "url"//image acquisition URL<br>}<br>|
|Explain|-|

**5.4 Delete pictures**

|HTTP method|DELETE|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/picture/delete_pictrue|
|HTTP Header|Api-key required|
|url parameter|device_id ="1111"<br>channel_id=11<br>Name = 1, // Picture Name|
|HTTP content|nothing|
|Successful return|{<br>"errno": 0,<br>"error":”succ”}|
|Explain|-|

**5.5 Get pictures**

|HTTP method|GET|
|:---|:---|
|URL|$url|
|HTTP Header|nothing|
|url parameter|nothing|
|HTTP content|nothing|
|Successful return|Return image data|
|Explain|The $url is returned from the interface in Getting Picture Information or Getting Picture List Information|

### 6. VOD-related interfaces

**6.1 Video Information Acquisition**

|HTTP method|GET|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/vod/get_video_info|
|HTTP Header|Api-key required|
|url parameter|device_id=12,<br>channel_id=12,<br>video_id=”1112341234”<br>Security = 1 // / Select secure playback links (https and rtmpe), otherwise default to normal links|
|HTTP content| |
|Successful return|{<br>"errno": 0,<br>"error":”succ”,<br>"data":{   <br> "videoid":dafdafd<br>"name":“dad”,<br>"start":"2017-01-12 12:01:12",<br>"end":"2017-01-12 15:01:12",<br>"Size": "1234", // in Kbytes<br>"Durtion": "12", // in seconds<br>"Hls_url", "url", // HTTP playback address<br>"Rtmp_url": "url"// RTMP playback address<br>}<br>}|
|Explain|Play address needs to carry token. See "Video on Demand Token Acquisition" for token acquisition<br>The assembly method is hls: url? Token= "token", rtmp: url? Token.<br>Hls adds a parameter token according to HTTP URL parameter, and the parameter value is the token content obtained.<br>The Rtmp protocol splices token content directly behind "?".<br>Security defaults to 0, returns normal playback links (http and rtmp), and 1 returns secure playback links (https and rtmpe)|

**6.2 Video List Acquisition**

|HTTP method|GET|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/vod/get_video_list|
|HTTP Header|Api-key required|
|url parameter|device_id=12,<br>channel_id=12,<br>Start_time= "2018-01-01:00:00", //formatted string optional filtering conditions<br>End_time= "2018-01-01:00:00", //formatted string optional filtering conditions<br>Name= "111", // Optional filtering conditions, filtered by name<br>Page_start= 1, // Paging Start<br>Page_size = 1 // Page size<br>Security = 1 // / Select secure playback links (https and rtmpe), otherwise default to normal links|
|HTTP content| |
|Successful return|{<br>"errno": 0,<br>"error":”succ”,<br>"data":{<br>    "videos":[<br>{<br> "videoid":"dafdafd",<br>      "name":"dad",<br>      "start":"2017-01-12 12:01:12",<br>      "end":"2017-01-12 15:01:12",<br>      "Size": 1234, // in KBytes<br>"Hls_url", "url", // HTTP playback address<br>      "Rtmp_url": "url"// RTMP playback address<br>},<br>     {….},<br>     …..<br>    ]<br>}<br>"page_info":<br>    {<br>        "total_num":50,<br>        "page_total":25,<br>        "page_size":2,<br>        "current_page":1<br>    }<br>}|
|Explain|Select the filter time to fill in either start_time or end_time, or together.<br>Play address needs to carry token. See "Video on Demand Token Acquisition" for token acquisition<br>The assembly method is hls: url? Token= "token", rtmp: url? Token.<br>Hls adds a parameter token according to HTTP URL parameter, and the parameter value is the token content obtained.<br>The Rtmp protocol splices token content directly behind "?".<br>Security defaults to 0, returns normal playback links (http and rtmp), and 1 returns secure playback links (https and rtmpe)|

**6.3 Video Delete**

|HTTP method|POST|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/vod/delete_video|
|HTTP Header|Api-key required<br>Content-Type:application/json|
|url parameter|deviceid=1,<br>channeled= 1|
|HTTP content|{<br>   "video": [{<br>     "videoId": 1<br>    },<br>  {<br>       "videoId": 2<br>    }]<br>}|
|Successful return|{<br>"errno": 0,<br>"error":”succ”,<br>"data":<br>[ <br>{"code":0}<br>{"code":1, "message":"not exist"}<br>]<br>}|
|Explain|The return message gives the result of each deletion ID in an array, and if the deletion fails, the error message videoId must be a string.|

**6.4 Video Renaming**

|HTTP method|PUT|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/vod/rename_video|
|HTTP Header|Api-key required<br>Content-Type:application/json|
|url parameter|device_id=12,<br>channel_id=12,<br>video_id=”1112341234”|
|HTTP content|{“name” : “11111”}|
|Successful return|{<br>"errno": 0,<br>"error":”succ”,<br>}|
|Explain|-|

**6.5 video on demand token acquisition**

|HTTP method|GET|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/vod/get_play_token|
|HTTP Header|Api-key required|
|url parameter|device_id=12,<br>channel_id=12,<br>video_id=”1112341234”|
|HTTP content| |
|Successful return|{<br>"errno": 0,<br>"error":”succ”,<br>"data":{<br>    "token": "sdafsa"<br>}<br>}|
|Explain|Token for VOD-related video capture|


### 7. Product Encryption

**7.1 Setting up Video Encryption Switch for Products**

|HTTP method|PUT|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/trans_encrypt|
|HTTP Header|Api-key required|
|url parameter|Product_id=7355//product ID|
|HTTP content|{"type":0}   0 is not encrypted, 1 is encrypted|
|Successful return|{<br>  "errno": 0,<br>  "error": "succ"<br>}|
|Explain| |

**7.2 Obtain product encryption status**

|HTTP method|GET|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/trans_encrypt|
|HTTP Header|Api-key required|
|url parameter|Product_id=7355//product ID|
|HTTP content|nothing|
|Successful return|{"errno":0,"trans_enc":1}|
|Explain|-|

### 8. Query device online status

|HTTP method|GET|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/device/QryDevStatus|
|HTTP Header|Api-key required|
|url parameter|DevIds = 123,456,789//device ID string, separated by commas, up to 30, no longer than 500 in length, required fields|
|HTTP content|nothing|
|Successful return|{"errno": 0,<br>"error": "succ",<br>"result": {<br>"total_count": 2,<br>"devices": [<br>{<br>"id": "2480461",<br> "online": false<br>},<br> {<br>"id": "2818370",<br>"online": false<br>}<br>]<br>}<br>}|
|Explain| |

### 9. Query equipment to transmit information

|HTTP method|GET|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/device/QryDevMsg|
|HTTP Header|Api-key required|
|url parameter|Device_id=// Device ID must be filled in<br>Start_time=//Query start time must be 2018-01-01 00:00:00:00<br>End_time=// Query End Time, 2018-01-02 00:00:00:00|
|HTTP content|nothing|
|Successful return|{"errno":0,<br>"error":"succ",<br>"page_info":<br>{<br>"total_num":7,<br>"page_total":1,<br>"page_size":50,<br>"current_page":1<br>},<br>"result":<br>[    <br>{<br>"create_time":"2018-01-04 16:27:40",<br>"msg_id":14,<br>"msg":"bXlfdGVzdF8xMjM0NQ=="<br>},<br>{<br>"create_time":"2018-01-04 16:31:53",<br>"msg_id":14,<br>"msg":"bXlfdGVzdF8xMjM0NQ=="<br>},<br>{<br>"create_time":"2018-01-08 09:27:00",<br>"msg_id":4398046511104,<br>"msg":"bXlfdGVzdF8xMjM0NQ=="<br>},<br>{<br>"create_time":"2018-01-08 10:06:16",<br>"msg_id":4398046511104,<br>"msg":"bXlfdGVzdF8xMjM0NQ=="<br>},<br>{<br>"create_time":"2018-01-08 10:07:19",<br>"msg_id":4398046511104,<br>"msg":"bXlfdGVzdF8xMjM0NQ=="<br>},<br>{<br>"create_time":"2018-01-08 10:09:49",<br>"msg_id":4398046511104,<br>"msg":"bXlfdGVzdF8xMjM0NQ=="<br>},<br>{<br>"create_time":"2018-01-08 14:10:35",<br>"msg_id":4398046511104,<br>"msg":"bXlfdGVzdF8xMjM0NQ=="<br>}<br>]<br>}<br>|
|Explain|The message content transmitted by the device (msg field) is encoded by Base64 and needs to be decoded by the client.|


### 10. Query boot machine address

|HTTP method|GET|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/boot_address|
|HTTP Header|nothing|
|url parameter|nothing|
|HTTP content|nothing|
|Successful return|{<br>  "errno": 0,<br>  "error": "succ",<br>  “data”:<br>  {<br>      "boot_address": "183.230.40.42",<br>      "boot_port": 9101<br>}<br>}|
|Explain|-|

### 11. Equipment data transmission

|HTTP method|POST|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/dev_active|
|HTTP Header|Api-key required|
|url parameter|Device_id=//Device ID|
|HTTP content|Customization, no more than 128 byte|
|Successful return|{<br>  Erno: 0, // 0 command sent successfully<br>  "error": "succ"<br>}|
|Explain|Scenarios for this interface: The device needs to receive a fixed string<br>The protocol will not encrypt the string and the serial number of the protocol header will be set to zero.<br>The header string received by the device will remain unchanged|



### 12. Video Recording Interface

|HTTP method|GET|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/record/record_video|
|HTTP Header|Api-key required|
|url parameter|product_id=12<br>device_id=123<br>channel_id=12345<br>Action = 0/1, // 0: Stop recording 1: Start recording, required|
|HTTP content||
|Successful return|{<br>  "errno": 0,<br>  "error": "succ"<br>}|
|Explain|Product_id: Product number, required parameter<br>Device_id: Device number, required parameter<br>Channel_id: Channel number, required parameter<br>Action: Operational Type, 0: Stop Recording, 1: Start Recording, Required Parameters|


### 13. Real-time query

**13.1 Play Real-time Query**

|HTTP method|GET|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/stat/getonlinelist|
|HTTP Header|Api-key required<br>Note: Master-key can only be used|
|url parameter|Product id=//Product number required<br> Deviceid =//device ID<br> Channelid=//channel number<br> Protocoltype =// protocol type RTMP HLS<br> Page_key=// Paging query usage<br> Page_size=// Data queried per page<br> Page = Paging query usage|
|HTTP content|nothing|
| |{<br>   "errno":0,<br>    "error":"succ",<br>    "result":<br>    [<br>        {<br>            "productid":7312,<br>            "deviceid":2479989,<br>            "channelid":1,<br>            "protocoltype":"RTMP",<br>            "clientip":"172.19.3.99",<br>            "videocodec":"H264",<br>            "resolution":"1280 * 720",<br>            "fps":25,<br>            "audiocodec":"",<br>            "bandwidth":91392,<br>            "onlinetime":"00:04:43"<br>        },<br>        {<br>            "productid":7312,<br>            "deviceid":2479989,<br>            "channelid":2,<br>            "protocoltype":"RTMP",<br>            "clientip":"172.19.3.99",<br>            "videocodec":"H264",<br>            "resolution":"1280 * 720",<br>            "fps":25,<br>            "audiocodec":"",<br>            "bandwidth":63066,<br>            "onlinetime":"00:07:00"<br>        }<br>    ],<br>    "page_info":<br>    {<br>        "total_num":3,<br>        "page_total":2,<br>        "page_size":2,<br>        "current_page":1,<br>        "page_key":"fc94c7c4-0760-4523-876c-5583260520c6"<br>    }<br>}|
|Explain|1) For real-time queries, data queries after the first page need to be passed in page_key<br>2) Paging data server caches for only 5 minutes and will fail after 5 minutes|

**13.2 Push Flow Real-time Query**

|HTTP method|GET|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/stat/getpushlist|
|HTTP Header|Api-key required<br>Note: Master-key can only be used|
|url parameter|Product id=//Product number required<br>Deviceid =//device ID<br>Channelid=//channel number<br>Page_key=// Paging query usage<br>Page_size=// Data queried per page<br>Page = Paging query usage|
|HTTP content|nothing|
|Successful return|{<br>    "errno":0,<br>    "error":"succ",<br>    "result":<br>    [<br>        {<br>            "productid":7312,<br>            "deviceid":2479989,<br>            "channelid":3,<br>            "protocoltype":"RTMP",<br>            "puship":"172.19.3.98",<br>            "videocodec":"H264",<br>            "resolution":"640 * 480",<br>            "fps":25,<br>            "audiocodec":"AAC",<br>            "bandwidth":95230,<br>            "pushtime":"00:06:37"<br>        },<br>        {<br>            "productid":7312,<br>            "deviceid":2479989,<br>            "channelid":1,<br>            "protocoltype":"RTMP",<br>            "puship":"172.19.3.98",<br>            "videocodec":"H264",<br>            "resolution":"1280 * 720",<br>            "fps":25,<br>            "audiocodec":"",<br>            "bandwidth":91020,<br>            "pushtime":"00:04:43"<br>        }<br>    ],<br>    "page_info":<br>    {<br>        "total_num":3,<br>        "page_total":2,<br>        "page_size":2,<br>        "current_page":1,<br>        "page_key":"5931b760-864a-44fb-9dd0-558e7caaace0"<br>    }<br>}|
|Explain|Paging queries are processed in the same way as playlists.|

### 14. Camera Disabled/Enabled Interface

|HTTP method|PUT|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/access_control/closecamera|
|HTTP Header|Api-key required|
|url parameter|Product_id = 12, // product ID<br>Device_id = 123, // device ID<br>Id= "1", //camera ID|
|HTTP content|{<br>  "Type": 1, //1 is off, 0 is on<br>}|
|Successful return|{<br>"errno": 0,<br>"error":”succ”<br>}|



### 15. Public Object Storage

|HTTP status code | Error code |  Meaning  |
|-|-|-|
|200 | 200 | Success |
|400 | 400 | Bad request |
|401 | 401 | Authentication Failure |
|403 | 403 | Access deny due to insufficient privileges |
|404 | 404 | Resource not found |
|405 | 405 | Method not allowed |



|HTTP status code | Error code |  Meaning  |
|-|-|-|
|413 | 413 | Request resource size is greater than the specified maximum (resource size is too big) |
|500 | 500 | System internal error |
|502 | 502 | Bad gateway |
|503 | 503 | Service unavailable |
|504 | 504 | Gateway timeout |
|1001 | 1001 | Invalid name, excluding special characters |
|1002 | 1002 | Invalid name, maximum limit is 256 (invalid name, maximum limit is 256)|
|1003 | 1003 | Invalid description, maximum limit is 1024 (invalid desc, maximum limit is 1024)|


**15.1 Upload**

|HTTP method|PUT|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/file/upload|
|HTTP Header|Api-key and authorization (required)|
|url parameter|product_id=1111,<br>name=test,<br>Desc= "1111", //optional|
|HTTP content|Uploaded file content|
|Successful return|{<br>"errno": 200,<br>"error":”succ”<br>}|
|Explain|Upload object size is limited to 8M|

**15.2 Download**

|HTTP method|GET|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/file/download|
|HTTP Header|Api-key and authorization (required)|
|url parameter|product_id=1111,<br>name=test|
|HTTP content|nothing|
|Successful return|Binary content of files|
|Explain|-|

**15.3 Delete**

|HTTP method|DELETE|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/file/delete|
|HTTP Header|Api-key and authorization (required)|
|url parameter|product_id=1111,<br>name=test|
|HTTP content|nothing|
|Successful return|{<br>"errno": 200,<br>"error":”succ”<br>}|
|Explain|-|

**15.4 Get List**

|HTTP method|GET|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/file/list|
|HTTP Header|Api-key and authorization (required)|
|url parameter|product_id=1111,<br>name=test|
|HTTP content|nothing|
|Successful return|{"data": [{<br>"product_id": 111,<br>"name": "test",<br>"size": 1024,<br>"date": 1548228623,<br>"desc": ""<br>}],<br>"errno": 0,<br>"error": "succ",<br>"page_info": {<br>"total_num": 0,<br>"page_total": 0,<br>"page_size": 50,<br>"current_page": 1<br>}<br>}|
|Explain|-|