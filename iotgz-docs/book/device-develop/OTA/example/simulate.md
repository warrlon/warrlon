# OTA-API模拟调试

OneNET平台通用OTA设备侧使用说明
通用远程升级功能，包括模组升级和MCU应用升级两类，待升级的设备通过HTTP协议RESTful标准格式与OneNET平台进行数据交互以完成升级。<br/>
南向设备目前所需的RESTful API一共有三类：检测任务、拉取文件、上报状态，其中拉取文件包括校验TOKEN和获取文件两个API。<br>
这里讲解关于API的大概使用和用postman模拟器测试拉取固件的过程。
本文档适用于使用OneNET平台进行通用OTA功能操作的设备侧操作相关人员。


### 1 鉴权参数

这里采用的python来计算产品token,更改产品id和accesskey即可,参考[安全鉴权](/book/manual/auth.md)章节，Python代码如图一所示：

![SDK说明](/images/OTA/ota-api/ota-api1.png)

![SDK说明](/images/OTA/ota-api/ota-api2.png)

计算出来的产品token：
```
version=2018-10-31&res=products%2F245528&et=7559008892&method=sha1&sign=TPllhakDDnUV90epLnOqpj6aWqI%3D
```
### 2 检测任务
检测任务API使用说明和响应信息请参考OTA-SDK说明文档：
Headers的参数Authorization：value为上面计算出来的产品token。

>manuf=102&model=10201这两个参数参考下面的表格。dev_id=527776559修改为需要升级的设备id。其他参数不改变。

|芯片平台|	芯片型号|	厂商编号|	芯片编号|
|:-|:-|:-|:-|
|乐鑫|	ESP32	|101|	10101|
|nordic	|nrf52832|	102	|10201|
|兆易|	GD32|	103|	10301|
|其他	|其他	|100|	10001|

```
http://ota.heclouds.com/ota/south/check?dev_id=527776559&manuf=102&model=10201&type=2&version=V1&cdn=false
```

![SDK说明](/images/OTA/ota-api/ota-api3.png)

![SDK说明](/images/OTA/ota-api/ota-api4.png)


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
### 3 校验TOKEN
校验TOKEN使用说明和响应信息请参考OTA-SDK说明文档：
Headers的参数Authorization：value为上面计算出来的产品token。
> dev_id=527776559修改为需要升级的设备id。ota_iF0hnXrq2CxLrP8vZ39l为鉴权参数步骤获取到的任务token，其他参数不改变。

```
http://ota.heclouds.com/ota/south/download/ota_iF0hnXrq2CxLrP8vZ39l/check?dev_id=527776559
```
![SDK说明](/images/OTA/ota-api/ota-api5.png)

### 4 拉取文件
拉取文件使用说明和响应信息请参考OTA-SDK说明文档：
```
http://ota.heclouds.com/ota/south/download/ota_iF0hnXrq2CxLrP8vZ39l
```
ota_iF0hnXrq2CxLrP8vZ39l为鉴权参数步骤获取到的任务token，其他参数不改变。
可以拉取整个文件：

![SDK说明](/images/OTA/ota-api/ota-api6.png)

也可以拉取部分文件

![SDK说明](/images/OTA/ota-api/ota-api7.png)

头部Range字段解释：Range: bytes={start}-{end}，目前只支持如下几种模式
> 	1、Range: bytes={start}-，获取第{start}+1个字节到最后的数据
	例如：Range: bytes=0-，获取所有数据
	Range: bytes=2-，获取第3个数据到最后1个数据
	注意：如果{start}>=文件总长度，则默认{start}=0 
	2、Range: bytes={start}-{end}，获取第{start}+1个字节到第{end}+1个字节
	例如：Range: bytes=0-99，获取前100个字节
	注意：若{end}>=文件总长度len，则默认end=len-1
    若{start}>{end}，start被设置为0
	3、Range: bytes=-{end}，获取最后end个字节数据
	例如：Range: bytes=-100，获取最后100个字节数据
	注意：如果{end}>文件总长度len，则默认end=len（获取所有文件）

分片状态码
> 分片返回的状态码：206<br>
  不分片返回的状态码：200

### 5 上报状态
上报状态使用说明和响应信息请参考OTA-SDK说明文档：
Headers的参数Authorization：value为上面计算出来的产品token。
Body内容为
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
>dev_id=527776559修改为需要升级的设备id。ota_iF0hnXrq2CxLrP8vZ39l为鉴权参数步骤获取到的任务token，其他参数不改变。

```
http://ota.heclouds.com/ota/south/report?dev_id=527776559&token=ota_iF0hnXrq2CxLrP8vZ39l
```

![SDK说明](/images/OTA/ota-api/ota-api8.png)

![SDK说明](/images/OTA/ota-api/ota-api9.png)


上报升级成功状态后，平台会显示任务状态为完成。
