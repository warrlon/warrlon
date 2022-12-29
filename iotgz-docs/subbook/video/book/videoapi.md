# API接口文档

*生产环境API_ADDRESS地址：https://api-video.heclouds.com:8443/

*测试环境API_ADDRESS地址：http://v-test.cmcconenet.com:8000/，https://v-test.cmcconenet.com:8443/

### 1.设备（device）管理

**1.1 新增**

|HTTP方法|POST|
|:---|:---|
|URL|http://API_ADDRESS/devices|
|HTTP头部|api-key:xxxx-ffff-zzzzz，必须为masterKeyContent-Type:application/json|
|HTTP内容|{<br>"title":"device1",  // 设备名称，必选。64个字符以内。<br>    "desc":"some description",  // 设备描述，可选。<br>"location":{"ele":370000,  // 高度，double<br>"lat":17.609997,  // 经度，double<br>"lon":177.03403  // 纬度，double<br>},  // 设备位置，可选。<br>"private":true,  // 是否私有，可选。公开的应用在open.iot.10086.cn上会列出来。<br>"protocol":"RTMP", // 设备接入协议，必须RTMP。<br>"auth_info":{…} auth123”,  // 设备鉴权信息，必选。产品下唯一。如不填写，将为该设备生成默认鉴权信息。<br>"area":”100”,  // 设备区域号，可选。必须是合法的区域号。<br>“other":{…},  // 设备其余信息，可选。<br>"interval":60,  // 保留，选择无效<br>"auth":"1233311", // 保留，选择无效<br>“route_to”:”abcd”, //保留，选择无效<br>“url”:“http://www.test.com”, // 设备url。（含义未知）<br>“idsn”：“test”,  // 保留，选择无效<br>“activate_code”:”test”,  // 保留，设备激活码}
|HTTP响应响应消息内容| {"errno": 0,<br>"error":“succ”,<br>"data":<br>{<br>//平台分配唯一ID<br>"device_id":"233444"<br>}<br>}
|说明|新增设备用于向设备云增加一个设备，通过HTTP POST请求增加设备，增加成功后，会返回该设备的设备ID。|



**1.2	注册码创建设备**

|HTTP方法|POST|
|:---|:---|
|URL|http://API_ADDRESS/register_de|
|URL参数|register_code=xxxxx //设备注册码，必选|
|HTTP内容|{"sn": "xxxx", //可选 设备唯一标识string类型， 最长512字符<br>"mac": "xxxx",//可选设备唯一mac标识string类型 ， 最长512字符<br>注意sn,mac一定要必填其中一个，而且只可以传一个<br>"title": "xxxx"//可选设备名  最长32个字符，<br>"area":100 //区域号，可选<br>}
|请求返回| {"errno": 0,<br>"error":“succ”,<br>"data":<br>{<br>"key":"XXAABBCCDD",//api-key只可以操作这个设备<br>"device_id": 21442<br>}<br>}|


**1.3	更新**

|HTTP方法|PUT|
|:---|:---|
|URL|http://API_ADDRESS/devices/{device_id}|
|HTTP头部|api-key:xxxx-ffff-zzzzz，masterKey或设备apikey。Content-Type:application/json|
|HTTP内容|{"title":"my device1", <br>"desc":"some description",<br>"private":true,<br>"tags":[<br>"Tag1",<br>"Tag2"<br>],<br>“url”: “http://www.test.com”,<br>“idsn”:”test”,<br>"location":{<br>"ele":370000,<br>"lat":17.609991828964787,<br>"lon":177.03402996826173<br>},<br>“route_to”:”test”, // edp设备有效。<br>"auth_info":{…}“auth123”,<br>“auth”:”123123”, // 保留，填写无效<br>"interval":60,<br>“activate_code”:”test”,<br>"area":”100”, <br>"other":{}<br>}
|请求返回| {<br>"errno": 0,<br>"error":“succ”,<br>}|
|说明|更新时，更新那个字段就只需要在json字符串中包括哪个字段，不需要包含所有内容。<br>如有字段不明确，请参见设备新增章节的解释。|

**1.4	查看单个设备信息**

|HTTP方法|GET|
|:---|:---|
|URL|http://API_ADDRESS/devices/{device_id}|
|HTTP头部|api-key:xxxx-ffff-zzzzz，masterKey或设备apikey。Content-Type:application/json|
|请求返回| {"errno": 0,<br>"error":“succ”,<br>"data":<br>{<br>"id":"device_id",<br>"online":true/false,  // 设备是否在线。<br>"protocol":"rtmp"<br>"title":"my device1", <br>"desc":"some description,ex:url",<br>......<br>"keys":[<br>{"title":"device-auto-key","key":"2JO3B12O1"},<br>{"title":"key-name2","key":"DFWfsfw1wfDF233"},<br>]<br>}<br>}
|说明|单个设备查看是在知道待查设备的设备ID的情况下查看设备的明细。会返回待查设备的基本信息、设备相关apikey信息等等。|


**1.5	模糊查找设备信息**

|HTTP方法|GET|
|:---|:---|
|URL|http://API_ADDRESS/devices|
|HTTP头部|api-key:xxxx-ffff-zzzzz，masterKey或设备apikey。Content-Type:application/json|
|URL参数|key_words = key, //可选,会从设备id或title或nb设备的imei字段中左匹配。<br>tag = xxx , //可选。<br>online = true/false , //可选。<br>private = true/false , //可选。<br>page = 1 , //指定页码, 可选, 默认1，最多10000<br>per_page = 30 // 指定每页输出设备个数,可选,默认30，最多100<br>device_id = 235122 //指定设备ID,可选,多个用逗号分隔，最多100个<br>auth_info = “{“auth”:”auth123”}”, //鉴权信息，可选。<br>begin=2016-06-10//可选，<br>end=2016-06-20//可选，<br>title=test//设备名称关键字，字符串，左匹配，大小写不敏感，可选。<br>|
|请求返回| {"errno": 0,<br>"error":“succ”,<br>"data":<br>{<br>"total_count":1,<br>"per_page":30,<br>"page":1,<br>"devices":<br>[<br>{<br>"id":"dev_id", <br>"title":"my device1",<br>“desc”:”device desc”,<br>"private":true,<br>"protocol":"RTMP”,<br>"online":ture/false,<br>"location":{"lon":106.55231191544001,"lat":29.535451246673},<br>"create_time":"2013-02-11 12:22:33",<br>"auth_info":{"SYS":"z=8QY3r7aTQ48UKfqPnB=PybYRo="},<br>“channel_count”:2  //设备通道数量<br>“last_login”: “2018-11-20 15:34:09” //设备最后上线时间<br>……<br>}<br>{……},<br>……<br>]<br>}<br>}|
|说明|批量查看是指模糊查找设备，会把所有符合条件的设备都列出来。<br>批量查找通过在URL中附带参数的形式向服务器端查询设备。|


**1.6	删除**

|HTTP方法|DELETE|
|:---|:---|
|URL|http://API_ADDRESS/devices/{device_id}|
|HTTP头部|api-key:xxxx-ffff-zzzzz，可为设备级别的Key或masterKey<br>Content-Type:application/json|
|URL参数|无|
|HTTP内容|无|
|请求返回|{"errno": 0,<br>"error":“succ”<br>}|
|说明|删除设备会删除所有在平台存储的视频和图片|



### 2.通道管理

**2.1查询设备下通道信息**

|HTTP方法|GET|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/device/QryChannel|
|HTTP头部|api-key 必填|
|URL参数|device_id=//设备ID  必填|
|HTTP内容|无|
| |{<br> "errno":0,<br>  "error":"succ",<br>  "result":<br>  [<br>      { <br>         "channel_id":20,<br>         "title":"test_qwer",  <br>         "desc":"1qwqwq/"  <br>    },   <br>    { <br>         "channel_id":100,   <br>         "title":"my_quto_test",   <br>        "desc":"123_test"   <br>     }  <br>  ]<br>}|

**2.2删除设备下通道**

|HTTP方法|DELETE|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/device/DelChannel|
|HTTP头部|api-key 必填|
|URL参数|device_id=//设备ID  必填 <br> channel_id=//通道编号，必填|
|HTTP内容|无|
|成功返回|{<br>    "errno":0,<br>    "error":"succ"<br>}|

**2.3增加设备下通道信息**

|HTTP方法|POST|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/device/AddChannel|
|HTTP头部|api-key 必填|
|URL参数|device_id=//设备ID 必填<br>channel_id=//通道ID，必填<br>title=//标题，必填（长度不超过64且只能是数字、字母或者是数字字母组合）<br>desc=//通道描述<br>product_id=//产品ID，内部不用api-key鉴权时需要填写<br>channel_num=//添加多个通道数量，通道号1到channel_num，可选|
|HTTP内容|无|
|成功返回|{<br>    "errno":0,<br>    "error":"succ"<br>}|
|说明|如果通道已经存在则报错返回如下信息:<br>{<br>"errno": 16,<br> "error": "The channel already exists,cannot add again!"<br>}|

**2.4修改设备下通道信息**

|HTTP方法|POST|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/device/ModifyChannel|
|HTTP头部|api-key 必填|
|URL参数|device_id=//设备ID 必填<br>channel_id=//通道ID，必填<br>title=//标题，必填（长度不超过64且只能是数字、字母或者是数字字母组合）<br>desc=//通道描述|
|HTTP内容|无|
|成功返回|{<br>    "errno":0,<br>    "error":"succ"<br>}|
|说明|如果修改的通道不存在则报错返回如下信息:<br>{<br>"errno": 17,<br> "error": "This channel is not available under this device!"<br>}|


### 3.命令下发

**3.1发送命令**

|HTTP方法|POST|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/cmds|
|HTTP头部|api-key 必填|
|URL参数|device_id =//设备ID<br>qos=//是否需要设备回应，0 不需要，1需要 默认值为0<br>type=//命令类型，0，平台定义，1用户定义 默认值为0|
|HTTP内容|用户自定义数据：json、string、二进制数据（小于64K）|
|成功返回|{<br>"errno": 0,<br>"error":”succ”,<br>"data":{<br> "cmd_uuid":”2303-312-Fws”,  //指令ID<br>"cmd_status": 4,//设备下发的状态（平台的返回）<br>"dev_resp": {<br>   “resp_code”:1,//设备返回的错误码,0表示成功	<br>"resp_data": "xxxxxxx"  //设备返回的数据的base64<br>}<br>|
|说明|resp_code  为命令在设备的执行状态<br>cmd_status 如下：<br>0：设备不在线 device not online<br>1：命令已创建  sending<br>2：命令已发往设备  send ok<br>3：命令发往设备失败  Send error <br>4：设备正常响应  ok<br>5：命令执行超时  time out<br>6：设备响应数据错误   resp data error。<br>当命令为不需要设备回复时，返回2表示下发成功。<br>当需要设备回复时,返回 4 时表示成功|


**3.2 OneNET视频设备支持的通用命令**

1.通知通道生成关键帧<br>
设备根据情况实现，命令格式如下：

```
{
    "cmdId": 5,      //产生视频关键帧
    "channel_id ": 1 //数字，对应视频源通道号

}
```

2.云台控制指令

```
{
    "cmdId": 7,      //指令id，7为云台控制指令
    "channel_id": 1, //数字, 对应视频源通道号
    "cmd":
    {
        "stop": 0, // 0 表示开始控制，1 停止控制, 2 单步控制
        "cmd": 1,  // 见cmd值
        "speed":   //速度1-7
    }
}

cmd值: 1: 焦距变大(倍率变大)  2:焦距变小(倍率变小)  3: 焦点前调 4: 焦点后调 5: 光圈扩大 6: 光圈缩小 11: 方向向上 12: 方向向下  13: 方向左转 14: 方向右转 15: 方向左上 16: 方向右上 17: 方向左下 18: 方向右下 22:自动扫描

}
```

3.本地视频查询<br>请求格式：

```
{
   "cmdId": 10, 
    "channel_id":1,
    "cmd":{
        "warn_type":100,//告警类型，参考告警类型表，0或无此字段表示查询所有文件
        "page":1,
        "start_time": "2017-09-29 12:00:31", // 可选
        "end_time": "2017-09-29 13:00:30"    //可选
        "per_page":20
    }

} 
```

设备返回格式

``` {
  "all_count": 25, //查询的所有视频总数
    "cur_count":20,  //当前页视频数
    "channel_id":1
    "rvods":[{
        "warn_type":100, // 告警类型，参考告警类型表，0表示非告警视频
        "video_desc": "test123",
        "size": 222,  // 字节数
        "start_time":"2017-09-29 12:00:31",
        "end_time":"2017-09-29 13:00:30"
    }]

}
```

4.通知设备升级
```
{
    "cmdId": 11, //指令id
    "cmd":
    {
        "url": "文件名称"    //升级包下载链接网址，升级包采用.tar.gz 格式
        "ver": "xxx.xxx.xxx" // 文件版本号
        "md5": "xxxx"        //文件的32bit md5码
    }
}

```
5.OSD获取<br>平台请求：
```
{
    "cmdId": 20, //指令id
    "channel_id":1
}

```
设备响应：
```
{
    "cmdId": 20, //指令id
    "channel_id":1,
    "cmd":[
    {
        "type": 1,    //1 自定义字符
        "enable": 0,  //0 禁止OSD功能，1 启用OSD功能 若禁用，无后面两字段
        "text":"xxxx" //OSD内容： 
        "pos":"xxx"   //left-top right-top left-bottom right-bottom
    },
    {
        "type": 2,    //2 时间
        "enable": 0,  //0 禁止OSD功能，1 启用OSD功能 若禁用，没有后续字段
        "pos":"xxx"   //left-top right-top left-bottom right-bottom  
        "date":"YMD", // 日期格式 年月日的顺序YMD DMY…
        "time": 12    // 时间格式，12小时或者24小时制
    }]
}
```
6.OSD设置<br>平台请求：
```
{
    "cmdId": 21, //指令id
    "channel_id":1,
    "cmd":[
    {
        "type": 1,  //1 自定义字符
        "enable": 0,//0 禁止OSD功能，1 启用OSD功能 如果为禁用，没有后面两个字段
        "text":"xxxx" //OSD内容： 如果为空，则直接显示当前时间
        "pos":"xxx"   //left-top right-top left-bottom right-bottom  
    },
    {
        "type": 2,   //type 2表示时间
        "enable": 0, //0 禁止OSD功能，1 启用OSD功能 如果禁用，没有后面两个字段
        "text":"xxxx"  //OSD内容： 如果为空，则直接显示当前时间
        "pos":"xxx"    //left-top right-top left-bottom right-bottom  
        "date": "YMD", // 日期格式 年月日的顺序
        "time": 12     //12 小时或者24小时
    }]
}

```
设备响应设置结果：
```
{
    "cmdId": 21,    //指令id
    "channel_id":1,
    "result":0     //操作结果：0 失败，1 成功
}

```

7.设备录像状态获取<br>设备录像状态获取
```
{
    "cmdId": 26, //指令id
    "channel_id":1
}

```

设备录像状态返回：
```
{
    "cmdId": 26,   //指令id
    "channel_id":1,
    "cmd":
    {     
        "mode": 0,    //0 未启用，1 启用指定时间段录制，
        "recycle": 0, // 0 不覆盖， 1 当满时覆盖旧的录像
        "time":[      //当状态为mode为1 时，有此字段
        {
            "weekday":0,            // 见weekday值
            "start_time": "HH:MM:SS", //每天录制开始时间 
            "end_time": "HH:MM:SS"  //每天录制结束时间, 24小时制
        },
        {
            "weekday":1, 
            "start_time": "HH:MM:SS", //每天录制开始时间 
            "end_time": "HH:MM:SS"    //每天录制结束时间 
        }]
    }
}
weekday值: 0,1,2,3,4,5,6 分别对应星期日，星期一，星期二，星期三，星期四，星期五，星期六。

```
8.设备录像设置<br>设置请求
```
{
    "cmdId": 27, //指令id
    "channel_id":1,
    "cmd":{
        "mode": 0,    //0 未启用，1 启用指定时间段录制，
        "recycle": 0, // 0 不覆盖， 1 当满时覆盖旧的录像
        "time":[ //当mode为1时，有此字段
        {
            "weekday":0, // 见weekday值
            "start_time": "HH:MM:SS",//每天录制开始时间 
            "end_time": "HH:MM:SS"   //每天录制结束时间, 24小时制
        },
        {
            "weekday":1, 
            "start_time": "HH:MM:SS",//每天录制开始时间 
            "end_time": "HH:MM:SS"   //每天录制结束时间 
        }]
}
weekday值: 0,1,2,3,4,5,6 分别对应星期日，星期一，星期二，星期三，星期四，星期五，星期六。

```
录像设置返回
```
{
    "cmdId": 27,  //指令id
    "channel_id":1,
    "result":0    //操作结果：0 失败，1 成功
}

```

9.当前时间配置获取<br>获取请求
```
{
    "cmdId": 28,  //指令id
    "channel_id":1
}

```
设备返回
```
{
    "cmdId": 28,  //指令id
    "channel_id":1,
    "cmd":
    {
        
        "mode": 1 , // 1 手动方式， 2 NTP 方式
        "time": "YYYY-MM-DD HH-MM-SS", //年月日 时分秒 当mode 为1 时有此字段
        "timezone": "+/-N", //时区+N代表东N区，-N代表西N区，当mode为2时有此字段
        "syncserver":"www.xxxx", //同步服务器，当mode为2时有此字段
        "port": 111 //NTP 服务端口号, 当mode为2时有此字段
    }
}

```

10.时间同步设置
```
{
    "cmdId": 29,  //指令id
    "channel_id":1,
    "cmd":
    {
        
        "mode": 1 , // 1 手动方式， 2 NTP 方式
        "time": "YYYY-MM-DD HH-MM-SS", //年月日 时分秒 当mode 为1 时有此字段
        "timezone": "+/-N", //时区+N代表东N区，-N代表西N区，当mode为2时有此字段
        "syncserver":"www.xxxx", //同步服务器，当mode为2时有此字段
        "port": 111 //NTP 服务端口号, 当mode为2时有此字段
    }
}

```
时间设置返回
```
{
    "cmdId": 29, //指令id
    "channel_id":1,
    "result":0 //操作结果：0 失败，1 成功
}

```
11.TF卡状态获取<br>获取请求
```
{
    "cmdId": 30  //指令id
}

```
设备返回
```
{
    "cmdId": 30,  //指令id
    "cmd":
    {
        "state":0,     //TF卡状态:0 不存在，1正常，2 异常，3 容量满
        "blocks": 0 ,  //总容量（单位：K）
        "available": 0 //可用容量（单位：K）
        "mode":0       //0 不可操作，1 仅可读，2 可读写
    }
}

```

12.TF卡操作<br>操作请求：
```
{
    "cmdId": 31,   //指令id
    "cmd":
    {
        "opt":"format" //操作 format 格式化，mount 挂载，umount 卸载
    }
}

```
TF卡设置返回：
```
{
    "cmdId": 31,  //指令id
    "result":0    //操作结果：0 失败，1 成功
}

```

13.设备快照<br>快照请求：
```
{
    "cmdId": 32,   //指令id
    "channel_id":1,
    "cmd":
    {
        "width":xx,   //快照分辨率，宽度，默认是终端最大分辨率
        "height":xx,  //快照分辨率，高度，默认是终端最大分辨率
        "quality":xx, //快照质量，取值1-100，默认是100
    }
}

```
快照结果：
```
{
    "cmdId": 32,    //指令id
    "channel_id":1,
    "result":0,    //操作结果：0 失败，1 成功
    "cmd": //当结果为成功时，有此字段
    {
        "name":"xxxx" //上传的文件名称 
    }
}

```
14.获取音视频配置信息<br>获取请求：
```
{
    "cmdId": 33,  //指令id
    "channel_id":1
}

```
设备返回：
```
{
    "cmdId": 33,  //指令id
    "channel_id":1,
    "cmd":
    {
        "codec": "h264", //h264或者h265
        "bitRate": 512 , //码率 kbps
        "frameRate": "25", //帧率
        "resolution": "1280*720", //分辨率（宽*高）
        "display_mode": 1, //图像模式，0 自动，1 彩色，2 黑白，3 日夜全彩
        "display_direction":0,// 见display_direction值
        "display_flip":0, //见display_flip值
        "led_white":0,    //0 关闭LED白光，1 打开LED白光，2 自动设置
        "led_red":0,      //0 关闭LED红灯，1 打开LED红光，2 自动设置   
        "audio": "on",    //audio 开关 on或者off
    }
}
display_direction值: 画面方向，0正常，1左转90度，2右转90度，3旋转180度。
display_flip值: 画面翻转，0 正常，1 水平翻转，2 垂直翻转，3 垂直及水平翻转。

```
15.设置音视频配置信息
```
{
    "cmdId": 34,  //指令id
    "channel_id":1,
    "cmd":
    {
        "codec": "h264", //h264或者h265
        "bitRate": 512 , //码率 kbps
        "frameRate": "25", //帧率
        "resolution":"1280*720", //分辨率（宽*高）
        "display_mode": 1,   //图像模式，0 自动，1 彩色， 2 黑白， 3 日夜全彩
        "display_direction":0,   //见display_direction值。
        "display_flip":0, //见display_flip值。
        "led_white":0,    //0 关闭LED白光，1 打开LED白光，2 自动设置
        "led_red":0,      //0 关闭LED红灯，1 打开LED红光，2 自动设置   
        "audio": "on",    // audio 开关 on或者off
    }
}
display_direction值: 画面方向，0正常，1左转90度，2右转90度，3旋转180度。
display_flip值: 画面翻转，0正常，1 水平翻转，2 垂直翻转，3 垂直及水平翻转。

```
设备返回：
```
{
    "cmdId": 34,   //指令i
    "channel_id":1,
    "result":0     //操作结果：0 失败，1 成功
}

```
16. 获取摄像机状态
```
{
    "cmdId": 39,  //指令id
    "channel_id":1
}

```
设备返回：
```
{
    "cmdId": 39, //指令id
    "channel_id":1,
    "cmd":
    {
        "status": "on" //on 镜头开启，off 镜头关闭
    }
}

```

17. 设置摄像机状态
```
{
    "cmdId": 40, //指令id
    "channel_id":1,
    "cmd":
    {
        "status": "on"  //on 镜头开启，off 镜头关闭 
    }
}

```
设备返回：
```
{
    "cmdId": 40, //指令id
    "channel_id":1,
    "result":0   //操作结果：0 失败，1 成功
}

```

18.  获取摄像机的WiFi列表
```
{
   "cmdId": 41  //指令id
}
```
设备返回
```
{
   "cmdId": 41,  //指令id
   "cmd": { "list":["ap1", "ap2", "ap3"] }
}

```

19.设置摄像机WiFi 密码
```
{
    "cmdId": 42,  //指令id
    "cmd":
    {
        "wifi_id": "ap1", 
        "wifi_pw": "pwd" 
    }
}

```
设备返回：

```
{
    "cmdId": 42, //指令id
    "result":0   //操作结果：0 失败，1 成功
}

```
20. 本地视频封面图获取<br>请求格式：
```
{
    "cmdId": 43,
    "channel_id":1,
    "cmd": //标识文件的索引信息
    {
        "start_time": "2017-09-29 12:00:31",
        "end_time": "2017-09-29 13:00:30"
    }
}

```
设备返回格式：
```
{
    "cmdId": 43,
    "channel_id":1,
    "result": 0,  //操作结果：0 失败，1 成功
    "cmd":
    { 
        "type":"jpg",        //jpg 或者 png
        "data":"base64data"  //图片文件的base64码
    }
}

```
21. 运动侦测状态获取<br>获取状态：
```
{
    "cmdId": 80, //指令id
    "channel_id":1
}

```
获取状态返回：
```
{
    "cmdId": 80, //指令id
    "channel_id":1,
    "cmd":
    {
        "state":0,   //0 已禁止功能， 1 已允许启动功能 
        "event":1,   //0 无配置，1 触发抓拍，2触发设备录像，3触发云端录像
        "sensitivity":0, //灵敏度（1-100）
        "resolution": "640*480", //设备当前分辨率,x分辨率*y分辨率
        "max_region":1          //允许设置的区域数量
        "region": [  //区域布防,左上角为原点
        {
            "x": 0    //x起始处的像素点数
            "y": 0    //y起始处的像素点数
            "w": 300  //宽度，区域x方向所包含的像素点数
            "h": 100  //高度，区域y方向所包含的像素点数
        }],
        "time":[ //布防时间
        {
            "weekday":0, //见weekday值。 
            "start_time": "HH:MM:SS", //布放开始时间 
            "end_time": "HH:MM:SS"    //布放结束时间, 24小时制
        },
        {
            "weekday":1, 
            "start_time": "HH:MM:SS",  
            "end_time": "HH:MM:SS"  
        }]
    }
}
weekday值: 0,1,2,3,4,5,6 分别对应星期日，星期一，星期二，星期三，星期四，星期五，星期六。
```
22. 运动侦测状态设置<br>设置运动侦测：
```
{
    "cmdId": 81, //指令id
    "channel_id":1,
    "cmd":
    {
        "enable": 0, //0 禁止功能，1 启用功能，当启用时，有后面3个字段
        "event":1,   //0 无配置 1 触发抓拍，2触发设备录像，3触发云端录像
        "sensitivity":0, //灵敏度（1-100）
        "region": [  //区域布防,左上角为原点
        {
            "x": 0    //x起始处的像素点数
            "y": 0    //y起始处的像素点数
            "w": 300  //宽度，区域x方向所包含的像素点数
            "h": 100  //高度，区域y方向所包含的像素点数
        }],
        "time":[ //布防时间
        {
            "weekday":0, //见weekday值
            "start_time": "HH:MM:SS",  //布放开始时间 
            "end_time": "HH:MM:SS"    //布放结束时间, 24小时制
        },
        {
            "weekday":1, 
            "start_time": "HH:MM:SS",
            "end_time": "HH:MM:SS"
        }]
    }
}
weekday值: 0,1,2,3,4,5,6 分别对应星期日，星期一，星期二，星期三，星期四，星期五，星期六。

```
设备返回设置结果：
```
{
    "cmdId": 81, //指令id
    "channel_id":1,
    "result":0   //操作结果：0 失败，1 成功
}

```
23.视频遮挡状态获取<br>获取状态：
```
{
    "cmdId": 82, //指令id
    "channel_id":1
}

```
获取状态返回：
```
{
    "cmdId": 82, //指令id
    "channel_id":1,
    "cmd":
    {
        "state":0,       //0 已禁止功能， 1 已允许启动功能
        "event":1,       //0 无配置，1 触发抓拍，2触发设备录像，3触发云端录像
        "sensitivity":0, //灵敏度（1-100）
        "resolution": "640*480", //设备当前分辨率,x分辨率*y分辨率
        "max_region":1          //允许设置的区域数量
        "region": [  //区域布防,左上角为原点
        {
            "x": 0    //x起始处的像素点数
            "y": 0    //y起始处的像素点数
            "w": 300  //宽度，区域x方向所包含的像素点数
            "h": 100  //高度，区域y方向所包含的像素点数
        }],
        "time":[ //布防时间
        {
            "weekday":0, //见weekday值
            "start_time": "HH:MM:SS", //布放开始时间 
            "end_time": "HH:MM:SS"    //布放结束时间, 24小时制
        },
        {
            "weekday":1, 
            "start_time": "HH:MM:SS",
            "end_time": "HH:MM:SS"
        }]
    }
}
weekday值: 0,1,2,3,4,5,6 分别对应星期日，星期一，星期二，星期三，星期四，星期五，星期六。

```
24.视频遮挡状态设置<br>设置视频遮挡状态：
```
{
    "cmdId": 83, //指令id
    "channel_id":1,
    "cmd":
    {
        "enable": 0, //0 禁止功能，1 启用功能，当启用时，有后面3个字段
        "event":1,   //0 无配置，1 触发抓拍，2触发设备录像，3触发云端录像
        "sensitivity":0, //灵敏度（1-100）
        "region": [  //区域布防,左上角为原点
        {
            "x": 0    //x起始处的像素点数
            "y": 0    //y起始处的像素点数
            "w": 300  //宽度，区域x方向所包含的像素点数
            "h": 100  //高度，区域y方向所包含的像素点数
        }],
        "time":[ //布防时间
        {
            "weekday":0, //见weekday值。
            "start_time": "HH:MM:SS", //布放开始时间 
            "end_time": "HH:MM:SS"    //布放结束时间, 24小时制
        },
        {
            "weekday":1, 
            "start_time": "HH:MM:SS",
            "end_time": "HH:MM:SS"
        }]
    }
}
weekday值: 0,1,2,3,4,5,6 分别对应星期日，星期一，星期二，星期三，星期四，星期五，星期六。

```
设备返回设置结果：
```
{
    "cmdId": 83, //指令id
    "channel_id":1,
    "result":0   //操作结果：0 失败，1 成功
}

```
25.声音告警状态获取<br>获取状态
```
{
    "cmdId": 84, //指令id
    "channel_id":1
}

```
获取状态返回：
```
{
    "cmdId": 84, //指令id
    "channel_id":1,
    "cmd":
    {           
        "state":0, //0 已禁止功能， 1 已允许启动功能 
        "event":1,   //0 无配置，1 触发抓拍，2触发设备录像，3触发云端录像
        "sensitivity":0, //灵敏度（1-100）
        "time":[ //布防时间
        {
            "weekday":0, //见weekday值
            "start_time": "HH:MM:SS", //布放开始时间 
            "end_time": "HH:MM:SS"    //布放结束时间, 24小时制
        },
        {
            "weekday":1, 
            "start_time": "HH:MM:SS",
            "end_time": "HH:MM:SS"
        }]
    }
}
weekday值: 0,1,2,3,4,5,6 分别对应星期日，星期一，星期二，星期三，星期四，星期五，星期六。

```

26.声音告警设置<br>设置声音告警：
```
{
    "cmdId": 85, //指令id
    "channel_id":1,
    "cmd":
    {
        "enable": 0, //0 禁止功能，1 启用功能，当启用时，有后面3个字段
        "event":1,   //0 无配置，1 触发抓拍，2触发设备录像，3触发云端录像
        "sensitivity":0, //灵敏度（1-100）
        "time":[ //布防时间
        {
            "weekday":0,  //见weekday值
            "start_time": "HH:MM:SS", //布放开始时间 
            "end_time": "HH:MM:SS"    //布放结束时间, 24小时制
        },
        {
            "weekday":1, 
            "start_time": "HH:MM:SS",
            "end_time": "HH:MM:SS"
        }]
    }
}
weekday值: 0,1,2,3,4,5,6 分别对应星期日，星期一，星期二，星期三，星期四，星期五，星期六。

```
设备返回设置结果
```
{
    "cmdId": 85, //指令id
    "channel_id":1,
    "result":0   //操作结果：0 失败，1 成功
}

```

27.其他告警状态获取<br>获取状态：
```
{
    "cmdId": 91, //指令id
    "channel_id":1
}

```
获取状态返回：
```
{
    "cmdId": 91, //指令id
    "channel_id":1,
    "cmd":
    {
        "state":0,  //0 已禁止功能， 1 已允许启动功能 
        "event":1,  // 触发事件类型 0 无配置 1 触发抓拍，2触发设备录像，3触发云端录像
        "time":[ //布防时间
        {
            "weekday":0, //见weekday值           "start_time": "HH:MM:SS", //布放开始时间
            "end_time": "HH:MM:SS"    //布放结束时间, 24小时制
        },
        {
            "weekday":1, 
            "start_time": "HH:MM:SS",
            "end_time": "HH:MM:SS"
        }]
    }
}
weekday值: 0,1,2,3,4,5,6 分别对应星期日，星期一，星期二，星期三，星期四，星期五，星期六。

```

28.其他告警设置<br>告警设置请求：
```
{
    "cmdId": 92, //指令id
    "channel_id":1,
    "cmd":
    {
        "state":0,  //0 已禁止功能， 1 已允许启动功能 
        "event":1,  // 触发事件类型 0 无配置 1 触发抓拍，2触发设备录像，3触发云端录像
        "time":[  //布防时间
        {
            "weekday":0,   //见weekday值
            "start_time": "HH:MM:SS", //布放开始时间 
            "end_time": "HH:MM:SS"    //布放结束时间, 24小时制
        },
        {
            "weekday":1, 
            "start_time": "HH:MM:SS",  
            "end_time": "HH:MM:SS"  
        }]
    }
}
weekday值: 0,1,2,3,4,5,6 分别对应星期日，星期一，星期二，星期三，星期四，星期五，星期六。

```
告警设置返回：
```
{
    "cmdId": 92, //指令id
    "channel_id":1,
    "result":0   //操作结果：0 失败，1 成功
}

```
### 4.实时播放接口

**4.1 拉流地址获取**

|HTTP方法|GET|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/play_address|
|HTTP头部|api-key 必填|
|URL参数|device_id=//接收该数据的设备ID，必填<br>channel_id=//对应数据流名称中的channelnum <br>protocol_type=播放协议类型  0:rtmp  1:hls  2:https-hls 3:flv 4:https-flv timeout=//token超时时间，单位为毫秒，-1表示永不过期| 
|HTTP内容|无|
|成功返回|{<br>"errno": 0,<br>"error":”succ”,<br>“data”:{<br>"addr":"ip:port",<br>"accessToken":“字符串”,<br>"type":"rtmpe",<br>"coveraddr":"ip:port" <br>}<br>}|
|说明|拉流地址需要根据返回接口进行拼接：<br>Rtmp实时拉流地址格式：type://ip:port/live/${device_id}-${channel_id}?accessToken<br>Rtmp 实时拉流地址示例：rtmp://183.230.40.39:1935/live/2162826-2?accessToken<br><br>Rtmp历史拉流地址格式:<br> rtmp://ip:port/rvod/${device_id}-${channel_id}-${begintime}-${endtime}?accessToken<br>Rtmp历史拉流地址示例:<br>rtmp://183.230.40.39:1935/rvod/2162826-2-201711131530-201711131540?accessToken<br><br>Hls实时拉流地址格式:<brhttp://183.230.40.39:8080/live/live_2162826_2/index.m3u8?accessToken<br>错误码说明：<br>1 参数错误 <br>2服务器内部错误 <br>3 通道不存在 <br>4 设备不在线<br>5 设备数据错误 

### 4.2 HLS流预加载请求

|HTTP方法|GET|
|:---|:---|
|URL|http://HLS_PLAY_ADDRESS/live/live_{DEVICE_ID}_{CHANNEL_ID}/preload|
|HTTP头部|api-key 必填|
|URL参数|token=xxxxx, //播放token<br>idle_time=120, //空闲清理时间(s),最大值120|
|HTTP内容| |
|成功返回|{<br>"errno": 0,<br>"error":”succ”<br>}|
|说明|HLS_PLAY_ADDRESS 及 token 是由HLS拉流地址接口返回。<br>DEVICE_ID 设备ID，CHANNEL_ID 通道ID<br>该接口可以达到HLS流预加载的目的|

### 4.3 获取直播缩略图

|HTTP方法|GET|
|:---|:---|
|URL|http://coveraddr/live_preview/${device_id}-${channel_id}|
|HTTP头部| |
|URL参数|token = “”|
|HTTP内容| |
|成功返回|图片二进制内容|
|说明|地址和Token是获取拉流地址时返回的accessToken和coveraddr, 直接通过coveraddr和token可以拼装url地址<br>http://coveraddr/live_preview/${device_id}_${channel_id}?token=accessToken|

### 4.4 获取设备主动推流地址

|HTTP方法|GET|
|:---|:---|
|URL|http:// <API_ADDRESS>/ipc/video/get_push_address|
|HTTP头部|api-key  (必填项) |
|URL参数|device_id=  //设备ID<br>channel=  //通道ID<br>isp=     //cm cu ct  other //设备所在的网络，移动，联通，电信或者其他未知网络|
|HTTP内容| |
|成功返回| {<br>"errno":   0,<br>"error":"succ",<br>"data":<br>{<br>"url": "rtmp push address" <br>}<br>}|
|说明|此地址没有时间使用限制，用户自行保密<br>支持RTMP推流的设备可以直接推流，也可以使用第三方软件推流，如ffmpeg等，不需要使用ODVP协议接入设备。

### 5.图片相关接口

**5.1 图片上传**

|HTTP方法|PUT|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/picture/upload|
|HTTP头部|api-key 必填|
|URL参数|device_id =1<br>channel_id=1<br>format=”jpg”/”png”<br>name="111"<br>desc="图片描述"|
|HTTP内容|图片二进制内容|
|成功返回|{<br>"errno": 0,<br>"error":”succ”}|
|说明|可用在播放端截图上传等<br>如果与已经上传的图片名字相同，则返回错误|

**5.2 获取图片列表信息**

|HTTP方法|GET|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/picture/get_list|
|HTTP头部|api-key 必填|
|URL参数|device_id ="1111"<br>channel_id=11<br>start_time=111, // UNIX时间戳，可选过滤条件<br>end_time=222, // UNIX时间戳， 可选过滤条件<br>page_start= 1, //分页起始<br>page_size=1 //分页大小|
|HTTP内容|无|
|成功返回|{<br>"errno": 0,<br>"error":”succ”<br>data:[<br>{<br>"format":”jpg” // jpg或png<br>"size": 1234,// 单位是字节<br>"date": 1234, // UNIX 时间戳<br>"name":"111",// 图片名(唯一ID)<br>"desc" : "name", // 图片描述<br>"url" : "url"  //图片获取url<br>}<br>],<br>"page_info":{<br>"total_num":50<br>"page_total":25,<br>"page_size":2,<br>"current_page":1<br>}<br>}|
|说明|-|

**5.3 获取图片信息**

|HTTP方法|GET|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/picture/get_info|
|HTTP头部|api-key 必填|
|URL参数|device_id ="1111"<br>channel_id=11<br>name=1, //图片名字|
|HTTP内容|无|
|成功返回|{<br>"errno": 0,<br>"error":”succ”<br>data:<br>{<br>"format":”jpg” // jpg或png<br>"size": 1234,// 单位是字节<br>"date": 1234, // UNIX 时间戳<br>"name":"111",// 图片名(唯一ID)<br>"desc" : "name", // 图片描述<br>"url" : "url"  //图片获取url<br>}<br>|
|说明|-|
 
**5.4 删除图片**

|HTTP方法|DELETE|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/picture/delete_pictrue|
|HTTP头部|api-key 必填|
|URL参数|device_id ="1111"<br>channel_id=11<br>name=1, //图片名字|
|HTTP内容|无|
|成功返回|{<br>"errno": 0,<br>"error":”succ”}|
|说明|-|

**5.5 获取图片**

|HTTP方法|GET|
|:---|:---|
|URL|$url|
|HTTP头部|无|
|URL参数|无|
|HTTP内容|无|
|成功返回|返回图片数据|
|说明|$url 从《获取图片信息》或者《获取图片列表信息》中的接口返回<br>http:// <API_ADDRESS>/ipc/video/picture/|

### 6.点播相关接口

**6.1 视频信息获取**

|HTTP方法|GET|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/vod/get_video_info|
|HTTP头部|api-key 必填|
|URL参数|device_id=12,<br>channel_id=12,<br>video_id=”1112341234”<br>security=1 //选择安全播放链接（https和rtmpe），没有则默认为普通链接|
|HTTP内容| |
|成功返回|{<br>"errno": 0,<br>"error":”succ”,<br>"data":{	<br> "videoid":dafdafd<br>"name":“dad”,<br>"start":"2017-01-12 12:01:12",<br>"end":"2017-01-12 15:01:12",<br>"size":"1234",// 单位是Kbytes<br>"durtion":"12", // 单位是秒<br>"hls_url":"url",// http播放地址<br>"rtmp_url":"url" // RTMP播放地址<br>}<br>}|
|说明|播放地址需要携带token。token获取见《视频点播token获取》<br>组装方式为hls: url?token=”token”, rtmp: url?token。<br>Hls按照http url参数方式增加一个参数token，参数值为获取的token内容。<br>Rtmp协议直接将token内容拼接在“?”后面。<br>Security 默认为0，返回普通播放链接（http和rtmp），1表示返回安全播放链接（https和rtmpe）|

**6.2 视频列表获取**

|HTTP方法|GET|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/vod/get_video_list|
|HTTP头部|api-key 必填|
|URL参数|device_id=12,<br>channel_id=12,<br>start_time=“2018-01-01 01:00:00”, // 格式化字符串  可选过滤条件<br>end_time=“2018-01-01 01:00:00”, // 格式化字符串  可选过滤条件<br>name=”111”, //可选过滤条件,根据名称过滤<br>page_start= 1, //分页起始<br>page_size=1 //分页大小<br>security=1 //选择安全播放链接（https和rtmpe），没有则默认为普通链接|
|HTTP内容| |
|成功返回|{<br>"errno": 0,<br>"error":”succ”,<br>"data":{<br>    "videos":[<br>{<br> "videoid":"dafdafd",<br>      "name":"dad",<br>      "start":"2017-01-12 12:01:12",<br>      "end":"2017-01-12 15:01:12",<br>      "size":1234,// 单位是KBytes<br>"hls_url":"url",// http播放地址<br>      "rtmp_url":"url" // RTMP播放地址<br>},<br>     {….},<br>     …..<br>    ]<br>}<br>"page_info":<br>    {<br>        "total_num":50,<br>        "page_total":25,<br>        "page_size":2,<br>        "current_page":1<br>    }<br>}|
|说明|选择过滤时间可以只填start_time或者end_time，也可以一起填<br>播放地址需要携带token。token获取见《视频点播token获取》<br>组装方式为hls: url?token=”token”, rtmp: url?token。<br>Hls按照http url参数方式增加一个参数token，参数值为获取的token内容。<br>Rtmp协议直接将token内容拼接在“?”后面。<br>Security 默认为0，返回普通播放链接（http和rtmp），1表示返回安全播放链接（https和rtmpe）|

**6.3 视频删除**

|HTTP方法|POST|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/vod/delete_video|
|HTTP头部|api-key 必填<br>Content-Type:application/json|
|URL参数|deviceid=12,<br>channeled= 12|
|HTTP内容|{<br>	"video": [{<br>		"videoId": 1<br>	},<br>	{<br>		"videoId": 2<br>	}]<br>}|
|成功返回|{<br>"errno": 0,<br>"error":”succ”,<br>"data":<br>[ <br>{"code":0}<br>{"code":1, "message":"not exist"}<br>]<br>}|
|说明|返回消息会以数组的形式给出每个删除ID的结果，如果删除失败会给出错误信息<br>videoId必须是字符串|

**6.4 视频重命名**

|HTTP方法|PUT|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/vod/rename_video|
|HTTP头部|api-key 必填<br>Content-Type:application/json|
|URL参数|device_id=12,<br>channel_id=12,<br>video_id=”1112341234”|
|HTTP内容|{“name” : “11111”}|
|成功返回|{<br>"errno": 0,<br>"error":”succ”,<br>}|
|说明|-|

**6.5 视频点播token获取**

|HTTP方法|GET|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/vod/get_play_token|
|HTTP头部|api-key 必填|
|URL参数|device_id=12,<br>channel_id=12,<br>video_id=”1112341234”|
|HTTP内容| |
|成功返回|{<br>"errno": 0,<br>"error":”succ”,<br>"data":{<br>    "token": "sdafsa"<br>}<br>}|
|说明|Token用于点播相关的视频获取|


### 7.产品加密

**7.1 设置产品的视频加密开关**

|HTTP方法|PUT|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/trans_encrypt|
|HTTP头部|api-key 必填|
|URL参数|product_id=7355 //产品id|
|HTTP内容|{"type":0}   0为不加密，1加密|
|成功返回|{<br>  "errno": 0,<br>  "error": "succ"<br>}|
|说明| |

**7.2 获取产品加密状态**

|HTTP方法|GET|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/trans_encrypt|
|HTTP头部|api-key 必填|
|URL参数|product_id=7355 //产品id|
|HTTP内容|无|
|成功返回|{"errno":0,"trans_enc":1}|
|说明|-|

### 8.查询设备在线状态

|HTTP方法|GET|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/device/QryDevStatus|
|HTTP头部|api-key 必填|
|URL参数|devIds=123,456,789//设备ID串，以逗号隔开，最多30个，长度不超过500，必填字段|
|HTTP内容|无|
|成功返回|{"errno": 0,<br>"error": "succ",<br>"result": {<br>"total_count": 2,<br>"devices": [<br>{<br>"id": "2480461",<br> "online": false<br>},<br> {<br>"id": "2818370",<br>"online": false<br>}<br>]<br>}<br>}|
|说明| |

### 9.查询设备透传信息

|HTTP方法|GET|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/device/QryDevMsg|
|HTTP头部|api-key 必填|
|URL参数|device_id=//设备ID 必填<br>begin_time=//查询开始时间 必填 2018-01-01 00:00:00<br>end_time=//查询结束时间，必填  2018-01-02 00:00:00|
|HTTP内容|无|
|成功返回|{"errno":0,<br>"error":"succ",<br>"page_info":<br>{<br>"total_num":7,<br>"page_total":1,<br>"page_size":50,<br>"current_page":1<br>},<br>"result":<br>[    <br>{<br>"create_time":"2018-01-04 16:27:40",<br>"msg_id":14,<br>"msg":"bXlfdGVzdF8xMjM0NQ=="<br>},<br>{<br>"create_time":"2018-01-04 16:31:53",<br>"msg_id":14,<br>"msg":"bXlfdGVzdF8xMjM0NQ=="<br>},<br>{<br>"create_time":"2018-01-08 09:27:00",<br>"msg_id":4398046511104,<br>"msg":"bXlfdGVzdF8xMjM0NQ=="<br>},<br>{<br>"create_time":"2018-01-08 10:06:16",<br>"msg_id":4398046511104,<br>"msg":"bXlfdGVzdF8xMjM0NQ=="<br>},<br>{<br>"create_time":"2018-01-08 10:07:19",<br>"msg_id":4398046511104,<br>"msg":"bXlfdGVzdF8xMjM0NQ=="<br>},<br>{<br>"create_time":"2018-01-08 10:09:49",<br>"msg_id":4398046511104,<br>"msg":"bXlfdGVzdF8xMjM0NQ=="<br>},<br>{<br>"create_time":"2018-01-08 14:10:35",<br>"msg_id":4398046511104,<br>"msg":"bXlfdGVzdF8xMjM0NQ=="<br>}<br>]<br>}<br>|
|说明|设备透传的消息内容（msg字段）经过了base64编码，需要客户端解码。|


### 10.查询引导机地址

|HTTP方法|GET|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/boot_address|
|HTTP头部|无|
|URL参数|无|
|HTTP内容|无|
|成功返回|{<br>  "errno": 0,<br>  "error": "succ",<br>  “data”:<br>  {<br>      "boot_address": "xxx.xxx.xxx.xxx",<br>      "boot_port": 9101<br>}<br>}|
|说明|-|

### 11.获取设备接入地址

|HTTP方法|GET|
|:---|:---|
|URL|http:// <API_ADDRESS>/ipc/video/device/acc_service|
|HTTP头部|api-key 必填|
|URL参数|product_id=//产品号，必填<br>device_id=//接收该数据的设备ID，必填<br>net = <br>device_addr=<br>domain=1//为1时返回值中addr为域名|
|HTTP内容|无|
|成功返回|{<br>"errno": 0<br>"error": "succ"<br>"data":{<br>"addr":"ip:port",<br>"token":"字符串",<br>"access":"字符串"<br>}<br>}|
|说明|net填写网络标识（移动:CM，联通:CU, 电信:CT）<br>device_addr填写设备ip地址，字符串形式，如192.168.1.1。可选填，填写地址之后，net参数可能会被忽略，将会根据实际地址返回<br>合适的接入点，不一定会按照net参数来分配。<br>net和device_addr必须选填一个<br> <br>Addr返回接入机连接地址<br>Token返回设备接入鉴权字符串<br>Access返回设备access鉴权字符串|

### 12.设备数据透传

|HTTP方法|POST|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/dev_active|
|HTTP头部|api-key 必填|
|URL参数|device_id =//设备ID|
|HTTP内容|自定义，不超过128 byte|
|成功返回|{<br>  "errno": 0, // 0 命令发送成功<br>  "error": "succ"<br>}|
|说明|该接口适用的场景：设备需要收到固定字符串<br>协议将不对该串加密，协议头部的序列号将置零<br>设备收到的头部字符串将固定不变|



### 13.视频录制接口

**13.1 手动录制**

|HTTP方法|GET|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/record/record_video|
|HTTP头部|api-key 必填|
|URL参数|product_id=12<br>device_id=123<br>channel_id=12345<br>action=0/1, // 0:停止录制 1:开始录制， 必选<br>expired=nday //当开始录制时，设置这个参数|
|HTTP内容|无|
|成功返回|{<br>  "errno": 0,<br>  "error": "succ"<br>}|
|说明|product_id : 产品号，必选参数<br>device_id : 设备号，必选参数<br>channel_id : 通道号，必选参数<br>action: 操作类型，0:停止录制 1:开始录制，必选参数<br>如果平台正在录制，返回错误<br>如果平台是通过API启动的录制，则需要通过API 停止录制|

**13.2 添加录制配置**

|HTTP方法|PUT|
|:---|:---|
|URL|http:// <API_ADDRESS>/api/record/record_config|
|HTTP头部|api-key:xxxx|
|URL参数|product_id=12<br>device_id=123<br>channel_id=12345<br>action=0/1, // 0:停止录制 1:实时录制，2:事件录制 必选<br>cycle =1, //单位天<br>start_time=””,<br>end_time=””|
|HTTP内容|无|
|成功返回|{<br>  "errno": 0,<br>  "error": "succ"<br>}|
|说明|product_id : 产品号，必选参数<br>device_id : 设备号，必选参数<br>channel_id : 通道号，必选参数<br>type: 录制类型，0:定时录制，1:实时录制，2:事件录制，必选参数<br> <br>以下为非必选参数<br>cycle: 单位天, 录制周期，当type为1和2时有效|

**13.3 删除录制配置**

|HTTP方法|DELETE|
|:---|:---|
|URL|http:// <API_ADDRESS>/ipc/video/record/delete_config|
|HTTP头部|api-key:xxxx|
|URL参数|product_id=12<br>device_id=123<br>channel_id=12345|
|HTTP内容|无|
|成功返回|{<br>  "errno": 0,<br>  "error": "succ"<br>}|
|说明|product_id : 产品号，必选参数<br>device_id : 设备号，必选参数<br>channel_id : 通道号，必选参数|

**13.4 更新录制配置**

|HTTP方法|PUT|
|:---|:---|
|URL|http:// <API_ADDRESS>/ipc/video/record/update_config|
|HTTP头部|api-key:xxxx|
|URL参数|product_id=12<br>device_id=123<br>channel_id=12345<br>type=0/1, //1:实时录制，2:事件录制<br>cycle =1, //单位天|
|HTTP内容|无|
|成功返回|{<br>  "errno": 0,<br>  "error": "succ"<br>}|
|说明|此API用于更新设备录制配置，调用此API，将会强制刷新设备原有配置，有短暂的生效时间（即设备停止旧配置后<br>重新录制新配置），原配置不存在则新增。type参数若为空，表示清空设备配置|

### 14.实时查询

**14.1 播放实时查询**

|HTTP方法|GET|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/stat/getonlinelist|
|HTTP头部|api-key 必填<br>注:只能用master-key|
|URL参数|productid=//产品号  必填<br> deviceid =//设备ID<br> channelid=//通道号<br> protocoltype =//协议类型 rtmp hls<br> page_key=//分页查询使用<br> page_size=//每页查询的数据<br> page=分页查询使用|
|HTTP内容|无|
| |{<br>   "errno":0,<br>    "error":"succ",<br>    "result":<br>    [<br>        {<br>            "productid":7312,<br>            "deviceid":2479989,<br>            "channelid":1,<br>            "protocoltype":"RTMP",<br>            "clientip":"172.19.3.99",<br>            "videocodec":"H264",<br>            "resolution":"1280 * 720",<br>            "fps":25,<br>            "audiocodec":"",<br>            "bandwidth":91392,<br>            "onlinetime":"00:04:43"<br>        },<br>        {<br>            "productid":7312,<br>            "deviceid":2479989,<br>            "channelid":2,<br>            "protocoltype":"RTMP",<br>            "clientip":"172.19.3.99",<br>            "videocodec":"H264",<br>            "resolution":"1280 * 720",<br>            "fps":25,<br>            "audiocodec":"",<br>            "bandwidth":63066,<br>            "onlinetime":"00:07:00"<br>        }<br>    ],<br>    "page_info":<br>    {<br>        "total_num":3,<br>        "page_total":2,<br>        "page_size":2,<br>        "current_page":1,<br>        "page_key":"fc94c7c4-0760-4523-876c-5583260520c6"<br>    }<br>}|
|说明|1)对于实时查询，第一页之后的数据查询,需要传入page_key<br>2)分页数据服务器只缓存5分钟,5分钟之后将失效|

**14.2 推流实时查询**

|HTTP方法|GET|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/stat/getpushlist|
|HTTP头部|api-key 必填<br>注:只能用master-key|
|URL参数|productid=//产品号  必填<br>deviceid =//设备ID<br>channelid=//通道号<br>page_key=//分页查询使用<br>page_size=//每页查询的数据<br>page=分页查询使用|
|HTTP内容|无|
|成功返回|{<br>    "errno":0,<br>    "error":"succ",<br>    "result":<br>    [<br>        {<br>            "productid":7312,<br>            "deviceid":2479989,<br>            "channelid":3,<br>            "protocoltype":"RTMP",<br>            "puship":"172.19.3.98",<br>            "videocodec":"H264",<br>            "resolution":"640 * 480",<br>            "fps":25,<br>            "audiocodec":"AAC",<br>            "bandwidth":95230,<br>            "pushtime":"00:06:37"<br>        },<br>        {<br>            "productid":7312,<br>            "deviceid":2479989,<br>            "channelid":1,<br>            "protocoltype":"RTMP",<br>            "puship":"172.19.3.98",<br>            "videocodec":"H264",<br>            "resolution":"1280 * 720",<br>            "fps":25,<br>            "audiocodec":"",<br>            "bandwidth":91020,<br>            "pushtime":"00:04:43"<br>        }<br>    ],<br>    "page_info":<br>    {<br>        "total_num":3,<br>        "page_total":2,<br>        "page_size":2,<br>        "current_page":1,<br>        "page_key":"5931b760-864a-44fb-9dd0-558e7caaace0"<br>    }<br>}|
|说明|分页查询的处理方式与播放记录列表的处理方式一致|

### 15.摄像头禁用/启用接口

|HTTP方法|PUT|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/access_control/closecamera|
|HTTP头部|api-key 必填|
|URL参数|product_id=12, //产品id<br>device_id=123, //设备id<br>id="1", //摄像头ID|
|HTTP内容|{<br>  "type":1,   //1为关，0为开<br>}|
|成功返回|{<br>"errno": 0,<br>"error":”succ”<br>}|



### 16.公共对象存储

|HTTP状态码 | 错误码 |  含义  |
|-|-|-|
|200 | 200 | 成功(success) |
|400 | 400 | 请求报文格式错误(bad request) |
|401 | 401 | 认证授权失败(auth failed) |
|403 | 403 | 权限不足，拒绝访问(access deny) |
|404 | 404 | 资源不存在(resource not found) |
|405 | 405 | 请求方式错误(method not allow) |



|HTTP状态码 | 错误码 |  含义  |
|-|-|-|
|413 | 413 | 请求资源大小大于指定的最大值(resource size is too big) |
|500 | 500 | 系统内部错误(system internal error) |
|502 | 502 | 错误网关(bad gateway) |
|503 | 503 | 服务端不可用(service unavailable) |
|504 | 504 | 服务端操作超时(gateway timeout) |
|400 | 1001 | 无效名字，排除特殊字符（invalid name, excluding special characters） |
|400 | 1002 | 无效名，最大长度限制为256（invalid name, maximum limit is 256）|
|400 | 1003 | 无效描述，最大长度限制为1024（invalid desc, maximum limit is 1024）|


**16.1 上传**

|HTTP方法|PUT|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/file/upload|
|HTTP头部|api-key 与 authorization 二选一(必填项)|
|URL参数|product_id=1111,<br>name=test,<br>desc="1111", //可选|
|HTTP内容|上传的文件内容|
|成功返回|{<br>"errno": 200,<br>"error":”succ”<br>}|
|说明|上传对象大小限制在8M以内|

**16.2 下载**

|HTTP方法|GET|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/file/download|
|HTTP头部|api-key 与 authorization 二选一(必填项)|
|URL参数|product_id=1111,<br>name=test|
|HTTP内容|无|
|成功返回|文件的二进制内容|
|说明|-|

**16.3 删除**

|HTTP方法|DELETE|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/file/delete|
|HTTP头部|api-key 与 authorization 二选一(必填项)|
|URL参数|product_id=1111,<br>name=test|
|HTTP内容|无|
|成功返回|{<br>"errno": 200,<br>"error":”succ”<br>}|
|说明|-|

**16.4 获取列表**

|HTTP方法|GET|
|:---|:---|
|URL|http://API_ADDRESS/ipc/video/file/list|
|HTTP头部|api-key 与 authorization 二选一(必填项)|
|URL参数|product_id=1111,<br>name=test|
|HTTP内容|无|
|成功返回|{"data": [{<br>"product_id": 111,<br>"name": "test",<br>"size": 1024,<br>"date": 1548228623,<br>"desc": ""<br>}],<br>"errno": 0,<br>"error": "succ",<br>"page_info": {<br>"total_num": 0,<br>"page_total": 0,<br>"page_size": 50,<br>"current_page": 1<br>}<br>}|
|说明|-|

### 17.云告警信息

**17.1 告警（视频，图片）列表查询**

|HTTP方法|GET|
|:---|:---|
|URL|http://<API_ADDRESS>/ipc/video/alarm/list|
|HTTP头部|api-key|
|URL参数|product_id= //产品ID(必填) <br>device_id =  //设备ID (默认0)<br>channel_id = //通道ID(默认 0)<br>alarm_type = //告警类型 (默认0)   参考《事件告警类型表》<br>alarm_way =  //告警方式 (默认 0)  1 视频告警  2 图片告警<br>start_time = //开始时间(必填)<br>end_time =   //结束时间(必填)<br>支持两种查询方式（时间跨度最大不超过31天）:<br>例如:查询2019年12月31日告警信息<br>1)按照日期查询，格式:YYYY-MM-DD<br>start_time:2019-12-31<br>end_time:2019-12-31<br>start_time 取当日最开始的时间，end_time 取下一日最开始时间<br>2)按照时间查询，格式:YYYY-MM-DD HH:MM:SS<br>start_time:2019-12-31 00:00:00<br>end_time:2020-01-01 00:00:00<br>alarm_status = //1 未读 2 已读(默认0)<br>protocol =  //告警事件播放地址协议类型 1 https  0 http(默认)<br>page =  //指定页码, 可选, 默认1，最多10000<br>per_page = //指定每页输出设备个数,可选,默认30，最多100|
|HTTP内容|无|
|成功返回|{<br>"errno": 0,<br>"error": "succ",<br>"data": {<br>"total_count": 1,<br>"per_page":30,<br>"page": 1,<br>"item": [{<br>"device_id": 25045682,<br>"create_time": "2019-04-29   12:00:01",<br>"alarm_id":"5cff0d073", //告警记录ID唯一标识<br>"alarm_type": 199,<br>"alarm_way": 2,<br>"alarm_status": 1, // 1 未读 2 已读 <br>"comment": "告警描述", <br>"picture": "图片url",<br>"thumbnail": "缩略图",<br>"play_address": "告警视频播放地址"<br>}]<br>}<br>}|
|备注|查询产品或者设备或者通道下的告警信息|

**17.2 告警消息查询**

|HTTP方法|GET|
|:---|:---|
|URL|http://<API_ADDRESS>/ipc/video/alarm/info|
|HTTP头部|api-key|
|URL参数|product_id= //产品ID(必填) <br>device_id =  //设备ID (默认0)<br>channel_id = //通道ID(默认 0)<br>start_time = //开始时间(必填)<br>end_time =   //结束时间(必填)<br>支持两种查询方式（时间跨度最大不超过31天）:<br>例如:查询2019年12月31日告警信息<br>1)按照日期查询，格式:YYYY-MM-DD<br>start_time:2019-12-31<br>end_time:2019-12-31<br>start_time 取当日最开始的时间，end_time 取下一日最开始时间<br>2)按照时间查询，格式:YYYY-MM-DD HH:MM:SS<br>start_time:2019-12-31 00:00:00<br>end_time:2020-01-01 00:00:00<br>alarm_status = //1 未读 2 已读(默认0)<br>protocol =  //告警事件播放地址协议类型 1 https  0 http(默认)<br>page =  //指定页码, 可选, 默认1，最多10000<br>per_page = //指定每页输出设备个数,可选,默认30，最多100|
|HTTP内容|无|
|成功返回|{<br>"errno": 0,<br>"error": "succ",<br>"data": {<br>"total_count": 1,<br>"per_page":30,<br>"page": 1,<br>"item": [{<br>"device_id": 25045682,<br>"create_time": "2019-04-29   12:00:01",<br>"alarm_id":     "5cff0d0e9dc6d6c65305e573", //告警消息ID唯一标识一条告警消息<br>"alarm_status": 1, // 1 未读 2 已读<br>"comment": "告警描述"<br>}]<br>}<br>}|
|备注|1)  查询设备的告警消息(非视频告警以及图片告警)<br>2)  查询后消息自动更新为已读

**17.3 告警信息状态更新**

|HTTP方法|POST|
|:---|:---|
|URL|https://<API_ADDRESS>/ipc/video/alarm/update_status|
|HTTP头部|api-key|
|URL参数|product_id= //产品ID(必填)|
|HTTP内容|{<br>"alarm_id":["dkjfkdjf",   "dkjfkdjf", "121313ssf"]<br>}|
|成功返回|{<br>"errno": 0,<br>"error": "succ"<br>}|

**17.4 未读告警数量查询**

|HTTP方法|GET|
|:---|:---|
|URL|http:// <API_ADDRESS>/ipc/video/alarm/count|
|HTTP头部|api-key|
|URL参数|product_id= //产品ID(必填) <br>device_id =  //设备ID (默认0)<br>channel_id = //通道ID(默认 0)|
|HTTP内容|无|
|成功返回|{<br>"errno": 0,<br>"error": "succ",<br>"data": {<br>"item": [{<br>"prodcut_id": 33020,<br>"device_id": 29023064,<br>"alarm_way": 1, //1 视频告警  2 图片告警 3设备信息<br>"channel_id": 1,<br>"count":   15<br>},<br>{<br>"prodcut_id": 33020,<br>"device_id": 27566869,<br>"channel_id": 1,<br>"alarm_way": 1, //1 视频告警  2 图片告警 3设备信息<br>"count":   15<br>}<br>]<br>}<br>}|
|备注|查询产品或者设备或者通道下的未读告警数量|

**17.5 告警信息删除**

|HTTP方法|POST|
|:---|:---|
|URL|https://<API_ADDRESS>/ipc/video/alarm/delete|
|HTTP头部|api-key|
|URL参数|product_id = //产品ID(必填)|
|HTTP内容|{<br>"alarm_id":["dkjfkdjf", "dkjfkdjf",   "121313ssf"]<br>}|
|成功返回|{<br>"errno": 0,<br>"error": "succ"|

**17.6 未读告警事件(图片告警，视频告警)按天统计**

|HTTP方法|GET|
|:---|:---|
|URL|http:// <API_ADDRESS>/ipc/video/alarm/day|
|HTTP头部|api-key|
|URL参数|product_id= //产品ID(必填) <br>device_id =  //设备ID (默认0)<br>start_time = //开始时间(必填)<br>end_time =   //结束时间(必填)<br>支持两种查询方式（时间跨度最大不超过31天）:<br>例如:查询2019年12月31日告警信息<br>1)按照日期查询，格式:YYYY-MM-DD<br>start_time:2019-12-31<br>end_time:2019-12-31<br>start_time 取当日最开始的时间，end_time 取下一日最开始时间<br>2)按照时间查询，格式:YYYY-MM-DD HH:MM:SS<br>start_time:2019-12-31 00:00:00<br>end_time:2020-01-01 00:00:00|
|HTTP内容|无|
|成功返回|{<br>"errno": 0,<br>"error": "succ",<br>"data": {<br>"item": [{<br>"day": "2019-12-31",<br>"number": 6<br>},<br> {<br>"day": "2019-12-30",<br>"number": 122<br>},<br>{<br>"day": "2019-12-27",<br>"number": 679<br>}<br>]<br>}<br>}|
|备注|

**17.7 告警事件(图片告警，视频告警)按天统计**

|HTTP方法|GET|
|:---|:---|
|URL|http:// <API_ADDRESS>/ipc/video/alarm/day_count|
|HTTP头部|api-key|
|URL参数|product_id= //产品ID(必填) <br>device_id =  //设备ID (默认0)<br>start_time = //开始时间(必填)<br>end_time =   //结束时间(必填)<br>支持两种查询方式（时间跨度最大不超过31天）:<br>例如:查询2019年12月31日告警信息<br>1)按照日期查询，格式:YYYY-MM-DD<br>start_time:2019-12-31<br>end_time:2019-12-31<br>start_time 取当日最开始的时间，end_time 取下一日最开始时间<br>2)按照时间查询，格式:YYYY-MM-DD HH:MM:SS<br>start_time:2019-12-31 00:00:00<br>end_time:2020-01-01 00:00:00|
|HTTP内容|无|
|成功返回|{<br>"errno": 0,<br>"error": "succ",<br>"data": {<br>"item": [{<br>"day": "2019-12-31",<br>"number": 6<br>},<br> {<br>"day": "2019-12-30",<br>"number": 122<br>},<br>{<br>"day": "2019-12-27",<br>"number": 679<br>}<br>]<br>}<br>}|
|备注|

### 18.存储用量查询

**18.1 产品存储用量查询**

|HTTP方法|GET|
|:---|:---|
|URL|https://<API_ADDRESS>/ipc/video/storage/capacity|
|HTTP头部|api-key|
|URL参数|product_id= //产品ID(必填) |
|HTTP内容|无|
|成功返回|{<br>"errno": 0,<br>"error": "succ",<br>"total": 123356955545,<br>"used": 123568956<br>}|
|备注|

**18.2 设备存储用量列表查询**

|HTTP方法|GET|
|:---|:---|
|URL|https://<API_ADDRESS>/ipc/video/storage/qry_dev_list|
|HTTP头部|Authorization:|
|URL参数|product_id= //产品ID(必填) <br>device_id =  //设备ID (默认0)<br>dev_name = //设备名称(默认空)<br>page = 指定页码, 可选, 默认1，最多10000 <br>per_page = 指定每页输出设备个数,可选,默认30，最多100 |
|HTTP内容|无|
|成功返回|{<br>"errno": 0,<br>"error": "succ",<br> "result":<br> {<br>"total_count": 1,<br>"per_page": 30,<br>"page":1,<br>"data":[{<br>"device_id":   1,<br>"dev_name": "设备名称",<br>"sn":   "设备序列号",<br> "used": 123565,<br>}]<br>}<br>}|

### 19.设备软件版本查询

|HTTP方法|GET|
|:---|:---|
|URL|https://<API_ADDRESS>/ipc/video/device/version|
|HTTP头部|api-key|
|URL参数|product_id= //产品ID(必填) |
|HTTP内容|无|
|成功返回|{<br>"errno": 0,<br>"error": "succ",<br>"data": {<br>"ver":"1.3.4"<br>}<br>}|
|备注|
