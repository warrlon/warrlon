# API调试-Postman模拟器

[本页目录]()

[1. 鉴权参数](#1)

[2. 检测任务](#2)

[3. 校验TOKEN](#3)

[4. 拉取文件](#4)

[5. 上报状态](#5)

#### OneNET平台通用OTA设备侧使用说明

通用远程升级功能，包括模组升级和MCU应用升级两类，待升级的设备通过HTTP协议RESTful标准格式与OneNET平台进行数据交互以完成升级。

南向设备目前所需的RESTful API一共有三类：**检测任务、拉取文件、上报状态**，其中拉取文件包括校验TOKEN和获取文件两个API。

本页内容介绍的是API的使用以及通过postman模拟器测试拉取固件的过程。

本文档适用于使用OneNET平台进行通用OTA功能操作的设备侧操作相关人员。


<h3 id="1">1. 鉴权参数</h3>

此处采用Python来计算产品Authorization,实际操作时更改产品id和accesskey即可,具体过程参考[API鉴权](/book/develop/auth.md)，Python代码如图2所示：

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/OTA/ota-api/ota-api1.png">
    <br>
    图 1 产品id和accesskey
    <br>
    <br>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/OTA/ota-api/ota-api2.png">
    <br>
    图 2 Phthon代码
    <br>
</center>


如图2所示，计算出来的鉴权参数为：

```
version=2018-10-31&res=products%2F245528&et=7559008892&method=sha1&sign=TPllhakDDnUV90epLnOqpj6aWqI%3D
```

<h3 id="2">2. 检测任务</h3>

```
http://ota.heclouds.com/ota/south/check?dev_id=527776559&manuf=102&model=10201&type=2&version=V1&cdn=false
```

Headers的参数Authorization：value为图2计算出来的产品token。

> manuf=102&model=10201这两个参数参考下面的表格。<br>dev_id=527776559修改为需要升级的设备id。<br>其他参数不改变。

|芯片平台|	芯片型号|	厂商编号|	芯片编号|
|:-|:-|:-|:-|
|乐鑫|	ESP32	|101|	10101|
|nordic	|nrf52832|	102	|10201|
|兆易|	GD32|	103|	10301|
|其他	|其他	|100|	10001|

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/OTA/ota-api/ota-api3.png">
    <br>
    图 3 postman模拟器测试示例-URL参数
    <br>
    <br>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/OTA/ota-api/ota-api4.png">
    <br>
    图 4 postman模拟器测试示例-Header
    <br>
</center>

如图4所示，示例的请求响应的代码如下:

 ```json
{
    "errno": 0,
    "error": "succ",
    "data": {
        "target": "V1",
        "token": "ota_iF0hnXrq2CxLrP8vZ39l",
        "size": 22,
        "md5": "ad2f4e4ea2a27eace7e4913139f8f01a",
        "signal": 10,
        "power": 50,
        "retry": 0,
        "interval": 0,
        "type": 1
    }
}
```
<h3 id="3">3. 校验TOKEN</h3> 

校验TOKEN使用说明和响应信息请参考[OTA-SDK说明文档](/book/develop/OTA-SDK-instruction.md)。

```
http://ota.heclouds.com/ota/south/download/ota_iF0hnXrq2CxLrP8vZ39l/check?dev_id=527776559
```

Headers的参数Authorization：value为上面计算出来的产品token。

> dev_id=527776559修改为需要升级的设备id。<br>ota_iF0hnXrq2CxLrP8vZ39l为鉴权参数步骤获取到的任务token。<br>其他参数不改变。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/OTA/ota-api/ota-api5.png">
    <br>
    图 5 postman模拟器测试示例-URL参数
    <br>
</center>


<h3 id="4">4. 拉取文件</h3> 

拉取文件使用说明和响应信息请参考[OTA-SDK说明文档](/book/develop/OTA-SDK-instruction.md)。

```
http://ota.heclouds.com/ota/south/download/ota_iF0hnXrq2CxLrP8vZ39l
```
ota_iF0hnXrq2CxLrP8vZ39l为鉴权参数步骤获取到的任务token，其他参数不改变。

可以拉取整个文件，如图6所示,也可以拉取部分文件，如图7所示：

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/OTA/ota-api/ota-api6.png">
    <br>
    图 6 postman-拉取整个文件
    <br>
    <br>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/OTA/ota-api/ota-api7.png">
    <br>
    图 7 postman-拉取部分文件
    <br>
</center>


头部Range字段解释：

<h4><center>Range: bytes={start}-{end}</center></h4>

目前只支持如下几种模式

> 	(1) Range: bytes={start}-，获取第{start}+1个字节到最后的数据
	例如：Range: bytes=0-，获取所有数据;
	Range: bytes=2-，获取第3个数据到最后1个数据;
	注意：如果{start}>=文件总长度，则默认{start}=0 。

>   (2) Range: bytes={start}-{end}，获取第{start}+1个字节到第{end}+1个字节
	例如：Range: bytes=0-99，获取前100个字节;
	注意：若{end}>=文件总长度len，则默认end=len-1;
    若{start}>{end}，start被设置为0。

>   (3) Range: bytes=-{end}，获取最后end个字节数据
	例如：Range: bytes=-100，获取最后100个字节数据；
	注意：如果{end}>文件总长度len，则默认end=len（获取所有文件）。

分片状态码

> 分片返回的状态码：206<br>
  不分片返回的状态码：200

<h3 id="5">5. 上报状态</h3> 

上报状态使用说明和响应信息请参考[OTA-SDK说明文档](/book/develop/OTA-SDK-instruction.md)。

```
http://ota.heclouds.com/ota/south/report?dev_id=527776559&token=ota_iF0hnXrq2CxLrP8vZ39l
```

Headers的参数Authorization：value为上面计算出来的产品token。

Body内容为：

```
{
    "result": 201

}
```

result:

>101:升级包下载成功<br>
 102:下载失败,空间不足<br>
 103:下载失败,内存溢出<br>
 104:下载失败,下载请求超时<br>
 105:下载失败,电量不足<br>
 106:下载失败,信号不良<br>
 107:下载失败,未知异常<br>
 201:升级成功<br>
 202:升级失败,电量不足<br>
 203:升级失败,内存溢出<br>
 204:升级失败,版本不一致<br>
 205:升级失败,md5校验失败<br>
 206:升级失败,未知异常<br>

error:

>0:上报状态成功<br>
1:上报状态失败，token鉴权失败<br>
2:上报状态失败，状态码有误<br>
20:上报状态失败，升级任务已经完成<br>
21:无效的操作<br>
22:上报状态失败，升级任务已被取消<br>
24:请求内容result错误<br>

说明
>dev_id=527776559修改为需要升级的设备id。<br>ota_iF0hnXrq2CxLrP8vZ39l为鉴权参数步骤获取到的任务token。<br>其他参数不改变。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/OTA/ota-api/ota-api8.png">
    <br>
    图 8 postman-上报状态
    <br>
    <br>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/OTA/ota-api/ota-api9.png">
    <br>
    图 9 postman-上报升级成功状态
    <br>
</center>

上报升级成功状态后，平台会显示任务状态为完成。

<div>
    <a href="/book/develop/OTA-SDK-instruction.md">
        <span> &#171; 上一篇：OTA-SDK使用说明</span>
        </a>
		</div>
<div>
    <a href="/book/example/api_debugging_assistant.md">
        <span> &#187; 下一篇：API调试-网络调试助手</span>
    </a>
</div>