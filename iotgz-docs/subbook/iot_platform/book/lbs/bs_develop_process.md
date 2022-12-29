<h1>基站定位开发指南</h1>

[本页目录]()
* [1.开通基站定位服务](#1)
* [2.添加基站定位功能点](#2)
* [3.数据上报（MQTT设备模拟器）](#3)
* [4.经纬度数据推送](#4)
---

本部分内容将以MQTT协议接入的设备为例，介绍设备通过定义物模型“基站定位”系统功能点实现设备定位和经纬度数据推送的操作过程。


<h2 id="1">1.开通基站定位服务</h2>

用户首次使用基站定位服务时，需要登录开发者中心，选择**增值服务 > 基站定位**，开通基站定位服务。

> 若您直接在产品开发阶段添加了系统功能点“基站定位”，但没有开通基站定位服务，将无法正常调用位置定位提供的开放API或者进行经纬度数据推送。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/lbs/开通基站定位服务.png">
    <br>
    图 1 开通基站定位服务
    <br>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/lbs/基站定位首页.png">
    <br>
    图 2 基站定位控制台
    <br>
</center>

<h2 id="2">2.添加基站定位系统功能点</h2>

选择**设备接入 > 产品管理 > 产品详情**，为产品添加系统功能点“基站定位”。

该功能点为数组类型，最大支持基于3个基站的数据进行定位，每一个元素对应一个基站信息，元素结构如下：

<table>
<tr><th width="40%">字段</th><th>说明</th></tr>
<tr><td>mnc</td><td>移动网号</td></tr>
<tr><td>mcc</td><td>移动国家号码</td></tr>
<tr><td>lac</td><td>地区区域码</td></tr>
<tr><td>cid</td><td>基站码</td></tr>
<tr><td>networkType</td><td>网络制式<br>1 GSM<br>2 CDMA<br>3 WCDMA<br>4 TD_CDMA<br>5 LTE</td></tr>
<tr><td>ss</td><td>信号强度</td></tr>
<tr><td>signalLength</td><td>当前基站广播信号强度</td></tr>
<tr><td>ta</td><td>移动台距以确定其发往基站的定时超前量</td></tr>
<tr><td>flag</td><td>基站信息数字进制<br>基站信息是10进制flag写10，不填则默认为10进制；<br>基站信息是16进制，flag必须写入16</td></tr>
</table>

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/lbs/基站-添加系统功能点.png">
    <br>
    图 3 添加系统功能点“基站定位”入口
    <br>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/lbs/基站-选择系统功能点基站定位.png">
    <br>
    图 4 选择系统功能点“基站定位”
    <br>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/lbs/基站-功能列表.png">
    <br>
    图 5 功能点列表
    <br>
</center>

<h2 id="3">3. 数据上报（MQTT设备模拟器）</h2>

此处采用MQTT.fx模拟设备接入物联网平台。请前往[mqtt.fx官网](http://mqttfx.jensd.de/index.php/download)进行下载，本文档使用的是MQTT.fx Version 1.7.1客户端软件。

您也可以使用平台提供的[设备调试](/book/devops&monitor/device-debugger/introduce.md)进行上下行数据调试。

`优化提示：采用多基站定位并上报数据时，基站的排列顺序不同，会产生不同精度的定位结果，建议按照设备从每个基站接收到的信号强弱（ss）排序后再上报，可提高设备定位精准度。`

### 1）操作前提

您已经通过**设备接入**服务在产品下添加了相应的MQTT设备。

### 2）设备激活（MQTT.fx配置）

打开MQTT.fx客户端，进入客户端配置页面。
<i class="far fa-address-card"></i>

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/lbs/mqtt模拟器首页.png">
    <br>
    图 6 打开MQTT.fx客户端
    <br>
</center>

设置Profile Name、接入地址与端口、Client ID、User Name与Password，其中参数设置方式如下：
> 本例为测试环境ip端口，请修改为线上环境对应的ip端口<br>
1、加密：183.230.102.116:8883<br>2、不加密：218.201.45.7:1883<br>
如果采用加密方式，需要设置SSL/TLS，选择CA certificate file，导入证书

- Client ID: 设备名称（本例为：device1）
- User Name：产品id （本例为：0miYdTzp2i）
- Password：token（本例为：version=2018-10-31&res=products%2F0miYdTzp2i%2Fdevices%2Fdevice1&et=1598229625&method=md5&sign=mS2KenTgQwo%2BlOD6a3whFA%3D%3D）
- [前往token算法](https://open.iot.10086.cn/doc/iot_platform/book/device-connect&manager/device-auth.html)

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/lbs/MQTT模拟器配置.png">
    <br>
    图 7 MQTT.fx客户端配置
    <br>
</center>

配置完成后，在配置文件下拉列表中选择配置MQTT相应项目，点击conncent，切换到开发者中心，设备在页面处于在线状态。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/lbs/MQTT模拟器连接.png">
    <br>
    图 8 选择配置MQTT相应项目
    <br>
    <br>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/lbs/MQTT模拟器已连接.png">
    <br>
    图 9 设备已接入平台
    <br>
    <br>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/lbs/M基站定位设备在线.png">
    <br>
    图 10 设备在线
    <br>
</center>

### 3）数据上报（MQTT.fx模拟）

#### 订阅属性上报结果通知消息

为了确保设备上传消息确实被平台所接受处理，设备可以订阅系统topic获取属性上报结果消息，属性上报回复topic为：

**$sys/{pid}/{device-name}/thing/property/post/reply**

本例中topic为：$sys/0miYdTzp2i/device1/thing/property/post/reply

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/lbs/MQTT模拟器订阅回复.png">
    <br>
    图 11 订阅属性上报结果通知消息
    <br>
</center>

#### 基站信息数据上报

“基站定位”系统功能点为“属性”类型，属性上报的topic为：

**$sys/{pid}/{device-name}/thing/property/post**

本例中topic为：$sys/0miYdTzp2i/device1/thing/property/post

上报数据成功后，订阅的属性上报会返回success。

OneJSON请求数据格式如下：

（1）单基站定位
```json
 {
  "id": "1",
  "version": "1.0",
  "params": {
    "$OneNET_LBS": {
	    "value":[{
		    "cid":21089,
		    "lac":6334,
		    "mcc":460,
		    "mnc":0,
		    "networkType":5,
		    "ss":-12,
		    "ta":1,
		    "flag":10
			}
		]
    }
  }
}
```

（2）多基站定位：
```json
 {
  "id": "1",
  "version": "1.0",
  "params": {
   "$OneNET_LBS": {
        "value": [
            {
                "cid": 21089,
                "lac": 6334,
                "mcc": 460,
                "mnc": 0,
                "networkType": 5,
                "ss": -12,
                "ta": 1,
                "flag": 10
            },
            {
                "cid": 21089,
                "lac": 6334,
                "mcc": 460,
                "mnc": 0,
                "networkType": 5,
                "ss": -12,
                "ta": 1,
                "flag": 10
            }
        ]
    }
  }
}
```

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/lbs/MQTT模拟器发布.png">
    <br>
    图 12 多基站信息上报
    <br>
    <br>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/lbs/MQTT模拟器订阅回复成功.png">
    <br>
    图 13 MQTT.FX订阅数据发送成功
    <br>
</center>

### 4）上报记录

设备上报数据后，可在**设备接入 > 设备管理 > 设备详情**中查看该功能点数据上报记录。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/lbs/基站定位上报记录.png">
    <br>
    图 14 设备上报基站信息记录
    <br>
</center>

<h2 id="4">4. 经纬度数据推送</h2>

平台支持通过HTTP推送、消息队列MQ推送服务向企业服务器推送设备经纬度数据。
> 您需要在HTTP数据推送和消息队列MQ中创建相应的实例才可以添加推送规则。
 
[查看HTTP数据推送详情](https://open.iot.10086.cn/doc/iot_platform/book/application-develop/push/http_push.html)

[查看消息队列MQ详情](https://open.iot.10086.cn/doc/iot_platform/book/transfer/mq_introduce.html)

此处以HTTP数据推送为例。

1）创建项目

使用规则引擎对数据定义推送规则时，需要先创建项目，并将设备添加到项目中。（设备已绑定到项目可跳过此步骤）

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/lbs/添加项目.png">
    <br>
    图 15 添加项目
    <br>
</center>

2）添加推送规则

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/lbs/添加消息推送规则.png">
    <br>
    图 16 添加推送规则入口
    <br>
    <br>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/lbs/添加消息推送规则2.png">
    <br>
    图 17 选中设备位置数据消息源
    <br>
    <br>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/lbs/添加消息推送规则3.png">
    <br>
    图 18 选择消息目的地
    <br>
</center>

3）接收推送消息

配置推送规则后，当设备上报基站信息时，平台将会向企业服务器根据自定义规则推送消息源数据。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/lbs/数据推送结果.png">
    <br>
    图 19 接收推送数据
    <br>
</center>

<h2 id="5">5. 位置信息查询</h2>

1）设备上报基站信息后，您可以在开发者中心**基站定位**控制台页面查询设备的位置。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/lbs/查询设备位置.png">
    <br>
    图 20 查询设备位置
    <br>
</center>

2）或者通过平台提供的开放API进行位置查询。

[查看API详情](/book/lbs/lbs_bs_openAPI.md)