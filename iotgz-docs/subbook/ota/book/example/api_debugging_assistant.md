<h1>API调试-网络调试助手</h1>

[本页目录]()

[1. 鉴权参数](#1)

[2. 上报版本](#2)

[3. 检测任务](#3)

[4. 下载固件](#4)

[5. 上报状态](#5)

OTA包括模组升级和MCU应用升级两类，待升级设备通过HTTP协议RESTful标准格式与OneNET平台进行数据交互以完成升级。南向设备目前所需的RESTful API一共有三类：检测任务、拉取文件、上报状态。

本部分内容主要介绍网络调试助手使用API测试拉取固件的过程，为研发人员组包测试提供参考。

<h3 id="1">1. 鉴权参数</h3>

鉴权参数说明请参考[API鉴权](/book/develop/auth.md)。

这里采用Python来计算Authorization，实际使用时，更改产品id和accesskey即可。Python代码如图1所示。

代码下载地址：

&#9672; [JAVA代码、Python代码下载](/book/develop/auth.md)   &#9672; [C代码下载](https://open.iot.10086.cn/bbs/thread-36828-1-1.html)

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/OTA/python生成鉴权参数.png">
    <br>
    图 1 Python代码示例
    <br>
</center>

计算出来的鉴权参数：

version=2018-10-31&res=products%2F198290&et=7555917657&method=sha1&sign=ZUXNMUqvAbuH0uHs0S1pd%2BgflNE%3D

<h3 id="2">2. 上报版本</h3>

网络调试助手作为客户端，连接IP：183.230.40.50，端口：50,如图2所示。

```
POST http://ota.heclouds.com/ota/device/version?dev_id=522747162 HTTP/1.1
Content-Type: application/json
Authorization:version=2018-10-31&res=products%2F198290&et=7555917657&method=sha1&sign=ZUXNMUqvAbuH0uHs0S1pd%2BgflNE%3D
host:ota.heclouds.com
Content-Length:20

{"s_version":"V1.3"}
```

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/OTA/调试助手_上报版本.png">
    <br>
    图 2 上报版本
    <br>
</center>

<h3 id="3">3. 检测任务</h3> 

manuf=102&model=10201这两个参数的取值如下表所示。

dev_id=522747162需要修改为升级的设备id。其他参数不改变。

<table>
<tr><th>芯片平台</th><th>芯片型号</th><th>厂商编号</th><th>芯片编号</th></tr>
<tr><td>nordic</td><td>ESP32</td><td>101</td><td>10101</td></tr>
<tr><td>乐鑫</td><td>nrf52832</td><td>102</td><td>10201</td></tr>
<tr><td>兆易</td><td>GD32</td><td>103</td><td>10301</td></tr>
<tr><td>其他</td><td>其他</td><td>100</td><td>10001</td></tr>
</table>
		
```		
GET /ota/south/check?dev_id=522747162&manuf=102&model=10201&type=2&version=V11&cdn=false HTTP/1.1
Authorization:version=2018-10-31&res=products%2F198290&et=7555917657&method=sha1&sign=ZUXNMUqvAbuH0uHs0S1pd%2BgflNE%3D
host:  ota.heclouds.com
//此处有个换行，使用时请删除此行内容，保留换行符
//此处有个换行，使用时请删除此行内容，保留换行符
```

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/OTA/调试助手_检测任务.png">
    <br>
    图 3 检测任务
    <br>
</center>

<h3 id="4">4. 下载固件</h3> 

如图4所示。

```
GET /ota/south/download/ota_JcWgqjwXigKAfRayjjUW HTTP/1.1
Range:bytes=0-5
host:  ota.heclouds.com
//此处有个换行，使用时请删除此行内容，保留换行符
//此处有个换行，使用时请删除此行内容，保留换行符
```

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/OTA/调试助手_下载固件.png">
    <br>
    图 4 下载固件
    <br>
</center>

拉取部分文件时，修改头部Range字段。

Range: bytes={start}-{end}，目前只支持如下几种模式：

```
1、Range: bytes={start}-，获取第{start}+1个字节到最后的数据
  例如：Range: bytes=0-，获取所有数据
  Range: bytes=2-，获取第3个数据到最后1个数据
  注意：如果{start}>=文件总长度，则默认{start}=0

2、Range: bytes={start}-{end}，获取第{start}+1个字节到第{end}+1个字节
  例如：Range: bytes=0-99，获取前100个字节
  注意：若{end}>=文件总长度len，则默认end=len-1
  若{start}>{end}，start被设置为0

3、Range: bytes=-{end}，获取最后end个字节数据
  例如：Range: bytes=-100，获取最后100个字节数据
```
如果{end}大于文件总长度len，则默认end=len（获取所有文件）。

#### 状态码

分片返回的状态码：206

不分片返回的状态码：200

<h3 id="5">5. 上报状态</h3> 

```
POST /ota/south/device/download/ota_3lI1NIMLB6E4u260cLRd/progress?dev_id=522747162 HTTP/1.1
Authorization:version=2018-10-31&res=products%2F198290&et=7555917657&method=sha1&sign=ZUXNMUqvAbuH0uHs0S1pd%2BgflNE%3D
host:ota.heclouds.com
Content-Type: application/json
Content-Length:11

{"step":54}//上报下载进度为54%
```

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/OTA/调试助手_上报下载进度.png">
    <br>
    图 5 上报下载进度
    <br>
</center>

```
POST /ota/south/device/download/ota_3lI1NIMLB6E4u260cLRd/progress?dev_id=522747162 HTTP/1.1
Authorization:version=2018-10-31&res=products%2F198290&et=7555917657&method=sha1&sign=ZUXNMUqvAbuH0uHs0S1pd%2BgflNE%3D
host:ota.heclouds.com
Content-Type: application/json
Content-Length:12

{"step":201}//表示升级完成
```

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/OTA/调试助手_升级完成.png">
    <br>
    图 6 上报状态-升级完成
    <br>
</center>

#### 说明

1、设备在下载升级包的过程中（分片下载），可以根据需要上报下载进度（设备处于“下载中”，才能上报step=[0,100]）

2、如果设备上报的下载进度为100（即step:100），那么平台会将设备的升级状态从“正在下载”修改为“正在升级”状态

3、只有当设备处于“正在下载”状态时，设备才能够使用该接口上报下载进度，其他状态将返回“invalid state”的错误

4、step如果大于100，将作为上报状态使用（设备处于：待升级、下载中、升级中，这三个状态时，可以通过上报如下状态码完成升级流程。其他状态如：已取消，升级失败、升级成功、暂停时，不能上报如下状态）：

<table>
<tr><th width="10%">result码</th><th width="40%">说明</th><th width="10%">result码</th><th width="40%">说明</th></tr>
<tr><td>101</td><td>升级包下载成功。</td><td>102</td><td>下载失败,空间不足</td></tr>
<tr><td>103</td><td>下载失败,内存溢出</td><td>104</td><td>下载失败,下载请求超时</td></tr>
<tr><td>105</td><td>下载失败,电量不足</td><td>106</td><td>下载失败,信号不良</td></tr>
<tr><td>107</td><td>下载失败,未知异常</td><td>-</td><td>-</td></tr>
<tr><td>201</td><td>升级成功</td><td>202</td><td>升级失败,电量不足</td></tr>
<tr><td>203</td><td>升级失败,内存溢出</td><td>204</td><td>升级失败,版本不一致</td></tr>
<tr><td>203</td><td>升级失败,内存溢出</td><td>204</td><td>升级失败,版本不一致</td></tr>
<tr><td>205</td><td>升级失败,MD5校验失败</td><td>206</td><td>升级失败,未知异常</td></tr>
<tr><td>207</td><td>达到最大重试次数</td><td>208</td><td>设备升级过期</td></tr>
</table>

**上报升级成功状态后，平台会显示任务状态为完成。**

<div>
    <a href="/book/example/simulate.md">
        <span> &#171; 上一篇：API调试-Postman</span>
        </a>
		</div>
<div>
    <a href="/book/FAQ/product_function_questions.md">
        <span> &#187; 下一篇：功能相关问题</span>
    </a>
</div>