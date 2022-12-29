
# 创建产品与设备

[本页目录]()

[1 登录](#1)

[2 创建产品](#2)

[3 创建设备](#3)

为了使用OneNET的OTA,需要在平台上创建对应的产品、设备，本文档以MQTT为例，其他接入协议基本相同。

- 产品用于管理设备和获取鉴权所需的参数**access_key**
- 设备为升级的对象，获取**设备id**

<h4 id="1">STEP 1 登录</font></h4> 

使用OneNET账号，登录开发者中心，如图1所示。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/MQTTS/开发者中心首页.png">
    <br>
    图 1 开发者中心首页
    <br>
</center>

通过左边栏产品导航进入 **MQTT物联网套件**，如图2所示。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/MQTTS/MQTT物联网套件产品入口.png">
    <br>
    图 2 MQTT物联网套件产品入口
    <br>
</center>

<h4 id="2">STEP 2 创建产品</font></h4> 

如图3所示，点击右上角的 **添加产品**，在弹出页面（图4）中按照提示填写产品的基本信息，进行产品创建；请您按照提示尽可能完整、全面地填写相应内容，这样更方便您后期对产品进行管理。 

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/MQTTS/添加产品.png">
    <br>
    图 3 添加产品入口
    <br>
    <br>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/MQTTS/产品配置.png">
    <br>
    图 4 产品配置
    <br>
</center>

点击 **确定**，完成产品创建，产品列表如图5所示。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/MQTTS/产品列表.png">
    <br>
    图 5 产品列表
    <br>
</center>

点击产品列表中的产品，进入产品详情，如图6所示。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/MQTTS/产品详情.png">
    <br>
    图 6 查看产品详情
    <br>
</center>

产品详情页右上角为access_key，通过输入短信验证码后可以查看，该参数将用于后续的鉴权参数计算详见[API鉴权](/book/develop/auth.md)。

<h4 id="3">STEP 3 创建设备</font></h4> 

点击左侧导航栏 **设备列表**，进入设备列表页面，如图7所示，点击右侧 **添加设备**

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/MQTTS/添加设备.png">
    <br>
    图 7 添加设备入口
    <br>
</center>

进入添加设备的配置页面，如图8所示，编辑设备名称与设备描述，点击 **添加**，完成添加设备，如图9所示。

> 其中，在MQTTS协议中，**设备名称**为用户自定义设备唯一识别码，该产品下唯一。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/MQTTS/配置设备.png">
    <br>
    图 8 配置设备
    <br>
    <br>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/MQTTS/完成添加设备.png">
    <br>
    图 9 完成添加设备
    <br>
</center>

<div>
    <a href="/book/price/rule.md">
        <span> &#171; 上一篇：产品定价</span>
        </a>
		</div>
<div>
    <a href="/book/manual/ota_develop_document.md">
        <span> &#187; 下一篇：升级操作流程</span>
    </a>
</div>


