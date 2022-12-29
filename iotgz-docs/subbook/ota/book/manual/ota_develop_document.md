# 升级流程概览
[本页目录]()

<a href='#1'><span>1 登录并进入开发者中心</span></a>&nbsp;&nbsp;&nbsp;
<a href='#5'><span>5 验证升级</span></a><br>
<a href='#2'><span>2 远程升级OTA入口</span></a>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
<a href='#6'><span>6 添加差分包</span></a><br>
<a href='#3'><span>3 选择远程升级类型</span></a>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
<a href='#7'><span>7 添加升级设备</span></a><br>
<a href='#4'><span>4 上传固件包到平台</span></a>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
<a href='#8'><span>8 设备端API的调用</span></a>


OneNET平台提供固件升级服务，首先需要确保设备端支持OTA服务，然后在OneNET平台上传新的固件包，设备检测到升级任务，即可完成在线升级。本部分内容将为您介绍如何设置固件升级和管理固件。

<h3 id="0">前提条件</h3>

固件升级功能前，请确保设备端支持OTA升级服务。

1、	如果您使用设备端SDK，请参考OneNET提供的SDK；

2、	如果使用在线差分进行升级，需要继承相应的差分还原SDK，详情请咨询陈经理（13983745042）。

**升级流程图：**

<center>
    <img src="/images/OTA/升级流程.jpg">
    <br>
    升级流程
</center>


<h3 id="00">操作步骤</h3>

<h4 id="1">STEP 1 登录并进入开发者中心</h4> 

您需要[登录](https://open.iot.10086.cn/)OneNET平台，方可使用OneNET OTA服务。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/OTA/进入开发者中心.png">
    <br>
    图 1 开发者中心入口
    <br>
</center>

<h4 id="2">STEP 2 进入远程升级OTA</h4> 

进入**开发者中心**，在导航栏选择**全部产品**->**远程升级OTA**板块。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/OTA\远程升级OTA入口.png">
    <br>
    图 2 远程升级OTA入口
    <br>
</center>

> 说明：为提供更好的服务，OneNET平台OTA2.0版本改版了原固件升级，新增了产品管理升级包。首次进会将OTA1.0版本新增的升级包默认添加到某个产品下进行关联。

<h4 id="3">STEP 3 选择远程升级类型</h4> 

进入**远程升级OTA**界面，选择需要升级的模块；然后点击右上角的**添加升级包**按钮。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/OTA/选择升级类型.png">
    <br>
    图 3 选择升级模块
    <br>
</center>

1. FOTA升级：对设备中的模组进行升级。
2. SOTA升级：对设备中的应用程序进行升级，本部分内容选择“FOTA升级”作为示例。

<h4 id="4">STEP 4 上传固件包到平台</h4> 

在添加升级包对话框中，输入固件信息，上传固件包文件。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/OTA/添加升级包.png">
    <br>
    图 4 上传固件包
    <br>
</center>

- 参数说明：
<table>
<tr><th width="30%">参数</th><th>描述</th></tr>
<tr><td>升级名称</td><td>1-20个中文、英文、数字、空格、或半角符号，升级名称不能重复</td></tr>
<tr><td>选择产品</td><td>下拉框选择需要升级的设备所属产品，若没有产品，请在OneNET平台<a href="https://open.iot.10086.cn/develop/global/product/#/console"><span>基础服务</span></a>中新增一个产品，如图2所示</td></tr>
<tr><td>厂商名称</td><td>根据设备所使用模组选择厂商名称，如果下拉框中没有所需的模组，选择其他</td></tr>
<tr><td>模组型号</td><td>根据设备所使用模组选择对应的型号，如果下拉框中没有所需的型号，选择其他</td></tr>
<tr><td>目标版本</td><td>1-20个英文、数字、点号、连接符和下划线</td></tr>
<tr><td>上传升级包</td><td>选择需要升级的完整包，并上传，这里升级包文件名不支持中文</td></tr>
</table>

<h4 id="5">STEP 5 验证升级</h4> 

如图5，图6所示，点击**验证升级**按钮，选择验证类型（完整包或者差分包），选择进行测试升级的设备，进行验证。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/OTA/验证升级.png">
    <br>
    图 5 验证升级入口1
    <br>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/OTA/验证升级2.png">
    <br>
    图 6 验证升级入口2
    <br>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/OTA/验证升级3.png">
    <br>
    图 7 验证升级
    <br>
</center>

- 参数说明：

<table>
<tr><th width="30%">参数</th><th>描述</th></tr>
<tr><td>升级包</td><td>完整包：进行完整包验证；<br>差分包：进行差分包验证，需要提前上传或者在线生成对应的差分包（详情见STEP 6）</td></tr>
<tr><td>选择设备</td><td>选择用于验证升级的设备（如果点击“选择设备”，提示没有设备，说明目前该产品下还不存在设备，或者存在设备但是并没有上报过版本号）</td></tr>
<tr><td>待升级版本</td><td>如果选择差分包验证，这里选择差分升级的起始版本（即设备的当前版本号）</td></tr>
</table>

1. 固件上传至OneNET平台后，需要使用少量设备对固件进行验证，确保测试设备升级成功后，才能批量升级。

2. 也可以单击“跳过验证”按钮跳过验证（不建议这样操作）。

<h4 id="6">STEP 6 添加差分包</h4> 
	
如果需要进行差分升级，需在平台“上传”或者“在线生成”差分包。使用差分升级时：

1）首先需要确认该差分包的初始版本和目标版本已存在，如图8所示的列表中的“目标版本”字段。

2）若该差分包的初始版本或目标版本不存在，可通过图8右上角**添加升级包**按钮添加版本（一次只能添加一个版本，若要创建初始版本和目标版本，请添加两次）。

3）若差分包的初始版本和目标版本均已存在，具体操作如下：

1. 单击**添加差分包**按钮;

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/OTA/添加差分包1.png">
    <br>
    图 8 添加差分包入口
    <br>
</center>

2. 在**添加差分包**对话框中填写对应信息。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/OTA/添加差分包2.png">
    <br>
    图 9 添加差分包
    <br>
</center>

- 参数说明：

<table>
<tr><th width="30%">参数</th><th>描述</th></tr>
<tr><td>升级名称</td><td>升级任务名称，自动填充</td></tr>
<tr><td>对应产品</td><td>自动填充</td></tr>
<tr><td>目标版本</td><td>自动填充</td></tr>
<tr><td>制作差分包</td><td>线上自动差分：如果需要使用OneNET平台的差分能力，需要在设备端继承平台提供的差分还原SDK；<br>
手动上传差分包：用户如果使用自己的差分能力，可以选择手动上传差分包。
</td></tr>
<tr><td>初始版本</td><td>差分升级的起始版本，也就是当前设备的版本号</td></tr>
</table>

<h4 id="7">STEP 7 添加升级设备</h4> 

(1) 单击**升级设备列表**，进入升级队列模块，在右上角单击**添加升级设备**按钮，新增设备升级任务。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/OTA/添加升级设备.png">
    <br>
    图 10 添加升级设备入口
    <br>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/OTA/添加升级设备2.png">
    <br>
    图 11 添加升级设备入口
    <br>
</center>

(2) 在**添加待升级设备**对话框中输入对应参数值。

<center>
    <img width="45%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/OTA/添加待升级设备.png">
    <br>
    图 12 添加待升级设备详情
    <br>
</center>

- 参数说明：

<table>
<tr><th width="30%">参数</th><th>描述</th></tr>
<tr><td>初始版本</td><td>下拉框选择需要升级的设备版本范围</td></tr>
<tr><td>升级范围</td><td>在选择了初始版本后，是对版本号下所有设备进行升级，还是选择部分设备进行升级</td></tr>
<tr><td>升级方式</td><td>整包，差分</td></tr>
<tr><td>升级时机</td><td>立即升级：升级任务立即生效；<br>定时升级：升级任务在到达指定时间后生效
</td></tr>
<tr><td>重试策略</td><td>不重试；<br>重试：选择对应的重试次数和重试时间就间隔;这里只是将策略通知到终端，由终端设备控制
</td></tr>
<tr><td>信号强度</td><td>通知到终端，由终端控制</td></tr>
<tr><td>剩余电量</td><td>通知到终端，由终端控制</td></tr>
</table>

(3) 新建的待升级设备，如下图所示：

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/OTA/升级设备列表.png">
    <br>
    图 13 查看待升级设备列表
    <br>
</center>

<h4 id="8">STEP 8 设备端API的调用</h4> 

设备与平台采用HTTP协议RESTful标准格式进行数据交互，接口通过Authorization来鉴权。

（1）[上报版本](/book/develop/south-API/0report_version.md)

设备上报当前固件版本号，设备在首次进行升级时需要执行此步骤。

**示例：**

```text
curl -XPOST 
-H "Content-Type:application/json" 
-H "Authorization:version=2018-10-31&res=products/33704&et=2529385073&method=sha1&sign=RccQWjT1n5OJ2khw3M4aPckkiFs=" 
-d '{"f_version": "4.0"}' 
"http://ota.heclouds.com/ota/device/version?dev_id=32981907"

```

（2）[检查设备升级任务](/book/develop/south-API/1task.md)

**示例：**

```text
curl -XGET 
-H "Content-Type:application/json" 
-H "Authorization:version=2018-10-31&res=products/33704&et=2529385073&method=sha1&sign=RccQWjT1n5OJ2khw3M4aPckkiFs=" 
"http://ota.heclouds.com/ota/south/check?dev_id=32981907&manuf=001&model=00108&type=1&version=4.0&cdn=false"
```

（3）[检测token有效](/book/develop/south-API/2token.md)

该步骤可选。如果上一步成功检查到升级任务，得到任务和升级包相关信息，设备拉取升级包时，OneNET平台通过token进行校验，并且上一步返回的token只有48小时的有效期，所以这里客户在使用时最好提前校验一下token是否有效。

**示例：**

```text
curl -XGET 
-H "Authorization:version=2018-10-31&res=products/33704&et=2529385073&method=sha1&sign=RccQWjT1n5OJ2khw3M4aPckkiFs=" 
"http://ota.heclouds.com/ota/south/download/ota_MTuflbjJDBclqltMlXX6/check?dev_id=32981907"

```

（4）[下载资源](/book/develop/south-API/3port.md)

token检测成功后，设备即可从平台获取升级包，完成升级包下载，远程升级OTA支持分片下载。

**示例：**

```text

curl -XGET 
-H "host:ota.heclouds.com" 
-H "Range:50500-50999" 
"http://183.230.40.50:80/ota/south/download/ota_KUuCwrPAjYj4tCr6Bcdl"
```

（5）[上报升级状态](/book/develop/south-API/4report_process.md)

设备上报当前资源下载进度和升级状态。

**示例：**

```text
curl -XPOST 
-H "Content-Type:application/json" 
-H "Authorization:version=2018-10-31&res=products/33704&et=2529385073&method=sha1&sign=RccQWjT1n5OJ2khw3M4aPckkiFs=" 
-d '{"step":100}' 
"http://ota.heclouds.com/ota/south/device/download/ota_MP9qVOT0AtsHhUSNYMy7/progress?dev_id=32981907"
```

<div>
    <a href="/book/manual/createProduct-device.md">
        <span> &#171; 上一篇：产品与设备</span>
        </a>
		</div>
<div>
    <a href="/book/develop/service_push.md">
        <span> &#187; 下一篇：升级任务推送</span>
    </a>
</div>