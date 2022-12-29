# 文件管理

<a href="#1">1. 文件限制</a> 

<a href="#2">2. 控制台操作</a> 

<a href="#3">3. 设备文件管理接口</a>

<a href="#4">4. 应用文件管理接口</a> 

---

平台提供文件管理功能，支持设备或应用通过HTTP方式，将文件上传至平台服务器存储。用户可对上传文件进行查看、下载等管理操作，同时也可基于存储的图片、文档等信息，进行灵活的业务开发。文件管理两种使用场景:
- 本地文件存储。设备端通过南向API接口将本地文件上传至平台，平台进行存储，应用对设备上传文件进行管理。

- 远程文件获取。

  ​	（1）第三发应用通过控制台页面或云端API将文件上传至平台

  ​	（2）第三方应用通过云端API调用物模型服务（结合系统功能点-文件管理类，可用同步或者异步方式，推荐大文件采用异步方式，文件下载结果可通过服务调用记录API查询执行情况），将文件基础信息下发给设备

  ​	（3）设备根据平台下发数据，向平台发起http请求，下载文件。

  ​	（4）文件下载完成之后，向平台回复第二步调用物模型服务的执行状况（命令响应）

<h3 id="1">1. 文件限制</h3>

| 序号 | 限制         | 描述                                                         |
| :--- | :----------- | :----------------------------------------------------------- |
| 1    | 文件大小     | 单个文件不超过20M，一个账号用户文件不超过1G，滚动式覆盖 |
| 2    | 文件格式     | 目前仅支持图片和文本。格式：jpg、jpeg、png、bmp、gif、webp、tiff、txt。 |
| 3    | 文件保存时间 | 单个文件保存最长时间为3个月                                  |
| 4    | 文件数量     | 单个设备最多保存1000个文件，滚动式覆盖               |

<h3 id="2">2. 控制台操作</h3>

进入Studio平台后，展开菜单栏中的「设备接入与管理」，点击「设备管理」，进入设备列表页面。点击「详情」-「文件管理」，如图所示。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/文件管理.png">
    <br/>
    图 1 添加设备
    <br/>
</center>

操作功能说明：

| 操作 | 描述                         |
| ---- | ---------------------------- |
| 上传 | 上传文件到对应设备的文件管理 |
| 下载 | 下载该文件到本地             |
| 删除 | 删除该文件                   |
| 查看 | 预览文件                     |

<h3 id="3">3. 设备文件管理接口</h3>

#### API地址

  域名方式：
> studio-file.heclouds.com
  
  ip端口方式：
> 183.230.102.116:27001

#### 鉴权方式

> 参见[设备接入安全鉴权](https://open.iot.10086.cn/doc/iot_platform/book/device-connect&manager/device-auth.html)

#### 接口列表

设备端文件管理接口包括文件上传和文件下载。

##### 文件上传

| HTTP方法     | POST                                                         |
| ------------ | ------------------------------------------------------------ |
| URL          | http://{API_ADDRESS}/studio/{pro_id}/{dev_name}/outupload    |
| HTTP头部     | Content-Type: multipart/form-data; boundary=----WebKitFormBoundary7MA4YWxkTrZu0gW     Authorization:"version=2018-10-31&res=products/23104&et=1554398783&method=sha1&sign=fsBwuj0udOpU3BLoHmpbFwyIo30=" |
| 请求内容     | file:file //必填，文件二进制内容  <br/>md5=adfadfdafdafdafda //必填，文件的md5，文件完整性校验，确保文件在传输过程中不出错 <br/> filename=test.jpa  //必填，文件名，下载会时会将该文件名携带在下载报文头部<br/> size=1223 //必填，文件大小，单位：byte |
| HTTP响应内容 | { <br/>"errno": 0,   <br/> "error":"succ",  <br/>"data": {  <br/>“uuid”:”f93fecfedabb47e48631e50d29c89e99”;  } <br/> } |
| 备注         | errno(Studio-SysFile-Errno):  <br/> 0: 成功；   <br/>1：鉴权失败；   <br/>2：请求参数错误；   <br/>3：请求参数缺失；   <br/>4：文件已存在；<br/> 5：文件不存在；<br/> 6：请求格式错误；<br/> 7：后端服务异常；<br/> 8：内部rpc调用异常；<br/> 9：存储空间不足；<br/> 10：文件大小不一致；<br/> 11：文件md5不一致；<br/> 12：设备不存在 |

##### 文件下载

| HTTP方法 | GET                                                          |
| -------- | ------------------------------------------------------------ |
| URL      | http://{API_ADDRESS}/studio/{productId}/{deviceName}/{uuid}/outdownload |
| HTTP头部 | Content-Type:application/json  <br/>Authorization:"version=2018-10-31&res=products/23104&et=1554398783&method=sha1&sign=fsBwuj0udOpU3BLoHmpbFwyIo30=" |
| HTTP响应 | 二进制文件                                                   |
| 备注     | Content-Length:当前请求获取的数据大小  <br/> Studio-SysFile-Errno:0, //请求的状态 |

<h3 id="4">4. 应用文件管理接口</h3>

应用端可通过调用云端API进行文件上传，请参见[createDeviceFile](https://open.iot.10086.cn/doc/iot_platform/book/api/application/createDeviceFile.html)、[deleteDeviceFile(暂不支持)](https://open.iot.10086.cn/doc/iot_platform/book/api/application/deleteDeviceFile.html)、[getDeviceFile(暂不支持)](https://open.iot.10086.cn/doc/iot_platform/book/api/application/getDeviceFile.html)

物模型服务调用相关接口，请参见[CallService](https://open.iot.10086.cn/doc/iot_platform/book/api/application/callService.html)

物模型服务执行记录相关接口，请参考[QueryServiceRecord](https://open.iot.10086.cn/doc/iot_platform/book/api/application/queryServiceRecord.html)
