[本页目录]()
* [1.准备工作](#1)
* [2.平台侧操作步骤](#2)
    * [STEP 1 SOTA任务入口](#21)
    * [STEP 2 添加SOTA群组](#22)
    * [STEP 3 关联设备](#23)
    * [STEP 4 SOTA升级](#24)
    * [STEP 5 添加软件版本](#25)
    * [STEP 6 添加升级包](#26)
    * [STEP 7 添加升级任务](#27)
* [3. MCU端AT指令操作流程](#3)
    * [STEP 8 创建设备实例](#38)
    * [STEP 9 注册请求/查询是否注册](#39)
    * [STEP 10 进入MCU升级流程](#310)
    * [STEP 11 读取资源值](#311)
    * [STEP 12 下载MCU固件包](#312)
    * [STEP 13 MCU开始升级](#313)
    * [STEP 14 更新状态请求](#314)
    * [STEP 15 读取资源值](#315)
    * [STEP 16 升级完成](#316)

<h1>NB模组实现SOTA升级操作流程（中国移动M531x为例）</h1>
<h2 id="1">1.前提条件</h2>

模组固件版本为S04版本且支持SOTA的AT指令。

<h2 id="2">2.平台侧操作步骤</h2>

<h4 id="21"><font color=#2B2B2B face="微软雅黑"> &triangleright; STEP 1 SOTA任务入口</font></h4> 

点击页面左侧“**SOTA升级**”，进入SOTA任务，如图1所示。

![1](/images/LwM2M/SOTA任务入口.jpg)

<center>图 1 SOTA任务入口 </center>

<h4 id="22"><font color=#2B2B2B face="微软雅黑"> &triangleright; STEP 2 添加SOTA群组</font></h4> 

点击页面右侧“**添加SOTA群组**”，如图2所示。若选择“正式设备”，填写群组名称根据实际情况填写！

![2](/images/LwM2M/添加SOTA群组.jpg)

<center>图 2 添加SOTA群组 </center>

<h4 id="23"><font color=#2B2B2B face="微软雅黑"> &triangleright; STEP 3 关联设备</font></h4> 

点击群组列表中目标群组右侧的“**关联设备**”，进入关联设备操作界面，点击“**未关联**”，在下方选择之前创建的相关设备，再点击“**提交修改**”，完成添加设备。如图3和图4所示。

![3](/images/LwM2M/SOTA关联设备入口.jpg)

<center>图 3 关联设备入口 </center>

![4](/images/LwM2M/SOTA关联设备操作.jpg)

<center>图 4 关联设备操作 </center>

<h4 id="24"><font color=#2B2B2B face="微软雅黑"> &triangleright; STEP 4 SOTA升级</font></h4> 

点击群组列表中目标群组右侧的“**SOTA升级**”，进入升级界面，如图5所示。

![5](/images/LwM2M/SOTA升级入口.jpg)

<center>图 5 SOTA升级入口 </center>

<h4 id="25"><font color=#2B2B2B face="微软雅黑"> &triangleright; STEP 5 添加软件版本</font></h4> 

在“**软件管理**”页面点击“**添加软件版本**”，进入配置页面，创建自定义的“**软件名称**”以及“**目标版本**”，软件名称和目标版本名称应与实际情况对应。如图6和图7所示。

> 注：“目标版本”为MCU将要升级的版本号，在下载完数据后，与后面MCU上传的版本号核对，若相同则升级成功，不相同则继续升级流程。


![6](/images/LwM2M/SOTA添加软件版本入口.jpg)

<center>图 6 添加软件版本入口 </center>

![7](/images/LwM2M/SOTA添加软件版本操作.jpg)

<center>图 7 添加软件版本操作 </center>

<h4 id="26"><font color=#2B2B2B face="微软雅黑"> &triangleright; STEP 6 添加升级包</font></h4> 

在“**软件管理**”页面点击“**添加升级包**”，进入配置页面，类型选择“**完整包**”，接着上传升级包,填写升级包的MD5码，点击“**添加**”，如图8和图9所示。然后在软件版本列表中点击左侧箭头，查看所添加的版本信息，如图10所示。

![8](/images/LwM2M/SOTA添加升级包入口.jpg)

<center>图 8 添加升级包入口 </center>

![9](/images/LwM2M/SOTA添加升级包操作.jpg)

<center>图 9 添加升级包操作 </center>

![10](/images/LwM2M/SOTA软件版本详情.jpg)

<center>图 10 软件版本详情 </center>

<h4 id="27"><font color=#2B2B2B face="微软雅黑"> &triangleright; STEP 7 添加升级任务</font></h4> 

在SOTA升级页面选择“**升级任务管理**”进入升级界面，点击右侧“**添加升级任务**”开始创建SOTA升级任务，如图11所示。在“**添加升级任务**”配置界面填写任务信息，最后点击“**添加**”，至此升级任务创建完成，如图12所示。

> 注：若添加升级任务失败，显示“**没有实体**”，应该在发送“AT+MIPLOPEN”之前，向模组发送：AT+MIPLSOTAVER="test0"(test0为当前版本即老版本，ps：我们要升级到test000版本)，待模组回复“OK”之后，便可创建任务。

![11](/images/LwM2M/SOTA添加升级任务入口.jpg)

<center>图 11 添加升级任务入口 </center>

![12](/images/LwM2M/SOTA添加升级任务操作.jpg)

<center>图 12 添加升级任务操作 </center>

<h2 id="3">3. MCU端AT指令操作流程</h2>

<h4 id="38"><font color=#2B2B2B face="微软雅黑"> &triangleright; STEP 8 创建设备实例</font></h4> 

AT+MIPLCREATE

OK

AT+MIPLSOTAVER="test0"		//向平台上报当前版本号“test0”

OK

<h4 id="39"><font color=#2B2B2B face="微软雅黑"> &triangleright; STEP 9 注册请求/查询是否注册</font></h4> 

AT+MIPLOPEN=0,600,60

OK

+MIPLEVENT:0,6            // 注册成功

> 注：返回+MIPLEVENT:0,6说明注册成功，其它情况请查询注网情况或者信号质量。

<h4 id="310"><font color=#2B2B2B face="微软雅黑"> &triangleright; STEP 10 进入MCU升级流程</font></h4> 

+MIPLEXECUTE:0,54077,5,0,26550,0,"" // 该指令是一个下发命令操作请求消息

AT+MIPLEXECUTERSP=0,54077,2

OK

<h4 id="311"><font color=#2B2B2B face="微软雅黑"> &triangleright; STEP 11 读取资源值</font></h4> 

（1）读取MCU可用空间

+MIPLREAD:0,54078,3,0,26261	 //该指令是一个读取请求消息

AT+MIPLREADRSP=0,54078,1,3,0,26261,3,3,"256",0,0 // 256为MCU可用存储空间，单位KB

OK

（2）读取MCU当前版本号

+MIPLREAD:0,54079,3,0,19

AT+MIPLREADRSP=0,54079,1,3,0,19,1,7,"test0",0,0 // test0为MCU版本号

OK

> 注：3,0,19分别对应objid、insid、resid，此语句告诉MCU需要上传当前版本号，“test000”与目标版本号比较，如不同继续升级流程，若相同则标志升级完成。

（3）读取MCU升级状态

+MIPLREAD:0,54080,5,0,-1// 此处需连回以下3条

AT+MIPLREADRSP=0,54080,1,5,0,3,3,1,"0",2,1  // 0为MCU当前升级状态

OK

AT+MIPLREADRSP=0,54080,1,5,0,5,3,1,"0",1,2  				// 0为MCU当前升级结果

OK

AT+MIPLREADRSP=0,54080,1,5,0,26500,3,1,"0",0,0  			// 0为MCU已接收字节数

OK

（4）读取MCU当前电量

+MIPLREAD:0,54081,3,0,9

AT+MIPLREADRSP=0,54081,1,3,0,9,3,3,"100",0,0			   // 100为MCU当前电量

OK

> 注：该电量需要超过STEP 13中创建升级任务时的最低电量。

<h4 id="312"><font color=#2B2B2B face="微软雅黑"> &triangleright; STEP 12 下载MCU固件包</font></h4> 

+MIPLEXECUTE:0,27495,5,0,26501,0,""  // 切换系统状态，准备下载MCU固件包

AT+MIPLSOTA=3  		//擦除flash成功
 
OK

#### 下载固件包

> 注：以上流程均正确，平台下发该消息，开始下载固件包

+MIPLWRITE:0,27496,5,0,0,2,1024,

C7AC******F8,1 //*表示省略的报文信息，最后一个字节是flag标志位

AT+MIPLSOTA=1  //把接收到的升级报文写入flash中，成功，result为1

OK

> 注：此处flag为“1”，表示第一条消息。


+MIPLWRITE:0,27497,5,0,0,2,1024,

D3A6******EB,2//*表示省略的报文信息，最后一个字节flag标志位

AT+MIPLSOTA=1 //把接收到的升级报文写入flash中，成功，result为1
    
OK

> 注：此处flag为“2”，表示中间消息。


+MIPLWRITE:0,27508,5,0,0,2,1024,

AEC9******C9,2//*表示省略的报文信息，最后一个字节flag标志位

AT+MIPLSOTA=1   //把接收到的升级报文写入flash中，成功，result为1
     
OK

> 注：此处flag为“2”，表示中间消息。

+MIPLWRITE:0,27509,5,0,0,2,346,

CFA3******0A,0//*表示省略的报文信息，最后一个字节flag标志位

AT+MIPLSOTA=1   //把接收到的升级报文写入flash中，成功，result为1
     
OK

注：此处flag为“0”，表示最后一条消息,只有最后以为flag为“0”，才表示所有固件包下载完成。

<h4 id="313"><font color=#2B2B2B face="微软雅黑"> &triangleright; STEP 13 MCU开始升级</font></h4>

+MIPLREAD:0,27510,3,0,9

AT+MIPLREADRSP=0,27510,1,3,0,9,3,3,"100",0,0 				// 再次获取电量准备升级

OK

+MIPLEXECUTE:0,27511,5,0,2,0,""             				// MCU开始升级标志

AT+MIPLEXECUTERSP=0,27495,2

OK	  //开始升级

<h4 id="314"><font color=#2B2B2B face="微软雅黑"> &triangleright; STEP 14 更新状态请求</font></h4>

AT+MIPLUPDATE=0,0,0

OK

+MIPLEVENT:0,11

> 注：该指令为MCU主动上传指令，需等待MCU升级完成后，再上传该指令（等待时间与MCU下载固件包大小有关）

<h4 id="315"><font color=#2B2B2B face="微软雅黑"> &triangleright; STEP 15 读取资源值</font></h4>

（1）读取MCU可用空间

+MIPLEXECUTE:0,54077,5,0,26550,0,""     

AT+MIPLEXECUTERSP=0,54077,2

OK

+MIPLREAD:0,17502,3,0,26261

AT+MIPLREADRSP=0,17502,1,3,0,26261,3,3,"128",0,0	 // 128为MCU可用存储空间，单位KB

OK

（2）读取MCU当前版本号

+MIPLREAD:0,17503,3,0,19

AT+MIPLREADRSP=0,17503,1,3,0,19,1,7,"test000",0,0 	// test000为MCU版本号

OK

<h4 id="316"><font color=#2B2B2B face="微软雅黑"> &triangleright; STEP 16 升级完成</font></h4>

+MIPLWRITE:0,17507,5,0,0,2,0,,0  //本次升级流程完结

AT+MIPLWRITERSP=0,17507,2    

OK

以上流程均完成后，登录OneNET平台查看升级任务状态，如图13所示。

![13](/images/LwM2M/平台查看SOTA升级状态.jpg)

<center>图 13 OneNET平台查看SOTA升级状态</center>








