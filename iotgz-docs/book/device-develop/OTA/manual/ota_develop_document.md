# OTA南向服务使用说明：

OneNET平台提供固件升级服务，首先需要确保设备端支持OTA服务，然后在OneNET平台上传新的固件包，设备检测到升级任务，即可完成在线升级。本文将为您讲解如果设置固件升级和管理固件。

### 前提条件

固件升级功能前，请确保设备端支持OTA升级服务。

1、	如果您使用设备端SDK，请参考OneNET提供的SDK；

2、	如果使用在线差分进行升级，需要继承相应的差分还原SDK，详情请咨询邓经理（18883296390）。

**整体升级流程如下：**

![升级流程](/images/OTA/升级流程.jpg)

### 操作步骤

<h4 id="1"><font color=#2B2B2B face="微软雅黑"> &triangleright; STEP 1 登录OneNET平台</font></h4> 

<h4 id="2"><font color=#2B2B2B face="微软雅黑"> &triangleright; STEP 2 远程升级OTA入口</font></h4> 

进入**开发者中心**，在导航栏选择**全部产品**->**远程升级OTA**板块。

![pic](/images/OTA/远程升级OTA入口.jpg)

> 说明：为提供更好的服务，OneNET平台OTA2.0版本改版了原固件升级，新增了产品管理升级包。首次进会将OTA1.0版本新增的升级包默认添加到某个产品下进行关联。

<h4 id="3"><font color=#2B2B2B face="微软雅黑"> &triangleright; STEP 3 选择升级模块</font></h4> 

进入**远程升级OTA**界面，选择需要升级的模块；然后点击右上角的**添加升级包**按钮。

![pic](/images/OTA/选择需要升级的模块.jpg)


> FOTA升级：对设备中的模组进行升级。

> SOTA升级：对设备中的应用程序进行升级，本部分内容选择“FOTA升级”作为示例。

<h4 id="4"><font color=#2B2B2B face="微软雅黑"> &triangleright; STEP 4 上传固件包</font></h4> 

在添加升级包对话框中，输入固件信息，上传固件包文件。

![pic](/images/OTA/上传固件包.jpg)

&ggg;

参数说明：

<table>
<tr><th width="30%">参数</th><th>描述</th></tr>
<tr><td>升级名称</td><td>1-20个中文、英文、数字、空格、或半角符号，升级名称不能重复</td></tr>
<tr><td>选择产品</td><td>下拉框选择需要升级的设备所属产品，若没有产品，先OneNET平台新增一个产品</td></tr>
<tr><td>厂商名称</td><td>根据设备所使用模组选择厂商名称，如果下拉框中没有所需的模组，选择其他</td></tr>
<tr><td>模组型号</td><td>根据设备所使用模组选择对应的型号，如果下拉框中没有所需的型号，选择其他</td></tr>
<tr><td>目标版本</td><td>1-20个英文、数字、点号、连接符和下划线</td></tr>
<tr><td>上传升级包</td><td>选择需要升级的完整包，并上传，这里升级包文件名不支持中文</td></tr>
</table>

<h4 id="5"><font color=#2B2B2B face="微软雅黑"> &triangleright; STEP 5 验证升级</font></h4> 

点击**验证升级**按钮，选择验证类型（完整包或者差分包），选择进行测试升级的设备，进行验证。

![pic](/images/OTA/验证升级.jpg)

&ggg;

参数说明：

<table>
<tr><th width="30%">参数</th><th>描述</th></tr>
<tr><td>升级包</td><td>完整包：进行完整包验证；<br>差分包:进行差分包验证，需要提前上传或者在线生成对应的差分包（详情见STEP 6）</td></tr>
<tr><td>选择设备</td><td>选择用于验证升级的设备（如果点击“选择设备”，提示没有设备，说明目前该产品下还不存在设备，或者存在设备但是并没有上报过版本号）</td></tr>
<tr><td>待升级版本</td><td>如果选择差分包验证，这里选择差分升级的起始版本（即设备的当前版本号）</td></tr>
</table>

> (1) 固件上传至OneNET平台后，需要使用少量设备对固件进行验证，确保测试设备升级成功后，才能批量升级。

> (2) 也可以单击“跳过验证”按钮跳过验证（不建议这样操作）。

<h4 id="6"><font color=#2B2B2B face="微软雅黑"> &triangleright; STEP 6 添加差分包</font></h4> 
	
如果需要进行差分升级，需在平台“上传”或者“在线生成”差分包，具体操作如下：

(1) 单击**添加差分包**按钮;

(2) 在**添加差分包**对话框中填写对应信息。
	
![pic](/images/OTA/添加差分包.jpg)	

&ggg;

参数说明：

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

<h4 id="7"><font color=#2B2B2B face="微软雅黑"> &triangleright; STEP 7 升级设备列表</font></h4> 

(1) 单击**升级设备列表**，进入升级队列模块，在右上角单击**添加升级设备**按钮，新增设备升级任务。

(2) 在**添加待升级设备**对话框中输入对应参数值。

![pic](/images/OTA/升级设备列表.jpg)	

&ggg;

参数说明：

<table>
<tr><th width="30%">参数</th><th>描述</th></tr>
<tr><td>初始版本</td><td>下拉框选择需要升级的设备版本范围，如果下拉框没有数据，可能是产品下没有设备，或者设备没有上报版本号</td></tr>
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

![pic](/images/OTA/待升级设备.jpg)

<h4 id="8"><font color=#2B2B2B face="微软雅黑"> &triangleright; STEP 8 设备端API的调用</font></h4> 

设备与平台采用HTTP协议RESTful标准格式进行数据交互，接口通过Authorization来鉴权。

（1）[上报版本](/book/device-develop/OTA/develop/south-API/0report_version.md)

设备上报当前固件版本号，设备在首次进行升级时需要执行此步骤。

**示例：**

```text
curl -XPOST 
-H "Content-Type:application/json" 
-H "Authorization:version=2018-10-31&res=products/33704&et=2529385073&method=sha1&sign=RccQWjT1n5OJ2khw3M4aPckkiFs=" 
-d '{"f_version": "4.0"}' 
"http://ota.heclouds.com/ota/device/version?dev_id=32981907"

```

（2）[检查设备升级任务](book/device-develop/OTA/develop/south-API/1task.md)

**示例：**

```text
curl -XGET 
-H "Content-Type:application/json" 
-H "Authorization:version=2018-10-31&res=products/33704&et=2529385073&method=sha1&sign=RccQWjT1n5OJ2khw3M4aPckkiFs=" 
"http://ota.heclouds.com/ota/south/check?dev_id=32981907&manuf=001&model=00108&type=1&version=4.0&cdn=false"
```

（3）[检测token有效](/book/device-develop/OTA/develop/south-API/2token.md)

该步骤可选。如果上一步成功检查到升级任务，得到任务和升级包相关信息，设备拉取升级包时，OneNET平台通过token进行校验，并且上一步返回的token只有48小时的有效期，所以这里客户在使用时最好提前校验一下token是否有效。

**示例：**

```text
curl -XGET 
-H "Authorization:version=2018-10-31&res=products/33704&et=2529385073&method=sha1&sign=RccQWjT1n5OJ2khw3M4aPckkiFs=" 
"http://ota.heclouds.com/ota/south/download/ota_MTuflbjJDBclqltMlXX6/check?dev_id=32981907"

```

（4）[下载资源](
/book/device-develop/OTA/develop/south-API/3port.md)

token检测成功后，设备即可从平台获取升级包，完成升级包下载，远程升级OTA支持分片下载。

**示例：**

```text

curl -XGET 
-H "host:ota.heclouds.com" 
-H "Range:50500-50999" 
"http://183.230.40.50:80/ota/south/download/ota_KUuCwrPAjYj4tCr6Bcdl"
```

（5）[上报升级状态](/book/device-develop/OTA/develop/south-API/4report_process.md)

设备上报当前资源下载进度和升级状态。

**示例：**

```text
curl -XPOST 
-H "Content-Type:application/json" 
-H "Authorization:version=2018-10-31&res=products/33704&et=2529385073&method=sha1&sign=RccQWjT1n5OJ2khw3M4aPckkiFs=" 
-d '{"step":100}' 
"http://ota.heclouds.com/ota/south/device/download/ota_MP9qVOT0AtsHhUSNYMy7/progress?dev_id=32981907"
```
