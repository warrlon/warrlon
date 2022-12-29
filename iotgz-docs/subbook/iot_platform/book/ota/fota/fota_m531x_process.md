[本页目录]()
* [1.准备工作](#1)
* [2.操作步骤](#2)
    * [STEP 1 模组烧写固件](#21)
    * [STEP 2 进入FOTA升级页面](#22)
    * [STEP 3 添加FOTA群组](#23)
    * [STEP 4 FOTA群组配置](#24)
    * [STEP 5 关联设备入口](#25)
    * [STEP 6 关联设备操作](#26)
    * [STEP 7 添加升级固件并创建升级任务](#27)

<h1>NB模组实现FOTA升级操作流程（M5310-A为例）</h1>
<h2 id="1">1.准备工作</h2>

#### （1）升级方式： 

差分包升级。

#### （2）模组侧准备工作

- NB 模组型号： M5310-A（仅以此模组举例， 其他具有 FOTA 功
能的模组也支持）。
- 模组初始固件， 需先烧录到模组：
M5310-A-MBRH0S00_1.0.0.1806250952_rel.fwpkg。
- 差分包：需通过 OneNET 对模组升级的目标版本。
- 模组固件烧写工具： UEUpdaterUI（建议使用较新的版本）。

#### （3）平台侧准备工作

- 在OneNET平台上创建即将升级的NB-IoT设备；
- 设备接入平台，平台读取模组固件当前的版本号。

<h2 id="2">2.操作步骤</h2>

<h4 id="21"><font color=#2B2B2B face="微软雅黑"> &triangleright; STEP 1 模组烧写固件</font></h4> 

模组通电，完成初始化，如图 1 所示。

![1](/images/LwM2M/模组上电初始化.jpg)

<center>图 1 模组上电初始化 </center>

打开 UEUpdaterUI，选择正确的端口和初始固件，点击“**update**”按钮开始下载初始固件至模组。出现如图2中的“**update complete**”表示固件下载完成。
![2](/images/LwM2M/模组初始固件下载界面.jpg)

<center>图 2 模组初始固件下载界面 </center>

#### 平台 FOTA 升级配置步骤

<h4 id="22"><font color=#2B2B2B face="微软雅黑"> &triangleright; STEP 2 进入FOTA升级页面</font></h4> 

打开 OneNET 平台产品页面， 进入 FOTA 升级页面， 如图 3 所示。

![3](/images/LwM2M/FOTA页面入口.jpg)

<center>图 3 产品功能选项</center>

<h4 id="23"><font color=#2B2B2B face="微软雅黑"> &triangleright; STEP 3 添加FOTA群组</font></h4> 

选择 FOTA 升级页面的“**正式群组**”， 点击“**添加 FOTA 群组**”按钮，如图 4 所示。
> 正式群组： 所有终端厂家对模组升级都应选择该选项；测试群组： 适用于NB芯片厂家测试用。

![4](/images/LwM2M/FOTA升级主页面.jpg)

<center>图 4 FOTA 升级主页面</center>

<h4 id="24"><font color=#2B2B2B face="微软雅黑"> &triangleright; STEP 4 FOTA群组配置</font></h4> 

进入FOTA群组， 对相应选项进行设置并点击“**添加**”按钮，如图5所示。

![5](/images/LwM2M/FOTA群组配置.jpg)

<center>图 5 FOTA群组配置</center>

#### 参数说明：
<table>
<tr><th width="20%">参数名称</th><th>说明</th></tr>
<tr><td>群组类型</td><td>正式群组：所有终端厂家对模组升级都应选择该选项；</br>测试群组： 适用于NB芯片厂家测试用。</td></tr>
<tr><td>群组名称</td><td>用户自定义。</td></tr>
<tr><td>厂商名称</td><td>选择模组厂商。</td></tr>
<tr><td>模组型号</td><td>选择升级模组的型号。</td></tr>
<tr><td>群组名称</td><td>用户自定义。</td></tr>
<tr><td>群组描述</td><td>可选，用户自定义描述。</td></tr>
</table>

<h4 id="25"><font color=#2B2B2B face="微软雅黑"> &triangleright; STEP 5 关联设备入口</font></h4> 

进入”FOTA_TEST”群组， 点击“**关联设备**”为该群组添加待升级的模组， 如图 6 所示。

![6](/images/LwM2M/关联设备.jpg)

<center>图 6 关联设备入口</center>

<h4 id="26"><font color=#2B2B2B face="微软雅黑"> &triangleright; STEP 6 关联设备操作</font></h4> 

进入“**关联设备**”页面，在未关联选项的搜索框里输入该产品下已创建设备的IMEI；或者在未关联列表里面选择欲升级设备， 点击方框选中该设备， 最后点击“**提交修改**”按钮完成选中设备的关联，如图7所示。

图8为关联后的设备及该设备对应的初始固件版本号。

![7](/images/LwM2M/关联设备操作.jpg)

<center>图 7 关联设备操作</center>

![8](/images/LwM2M/已关联设备信息.jpg)

<center>图 8 已关联设备信息</center>

> 注意：后面的步骤中添加固件版本的初始版号时，必须与此处的已关联设备的版本号保持一致。

<h4 id="27"><font color=#2B2B2B face="微软雅黑"> &triangleright; STEP 7 添加升级固件并创建升级任务</font></h4> 

（1）点击“**FOTA 升级**”按钮，进入“**固件管理**”和“**升级任务**”， 如图 9所示。添加升级固件并创建升级任务。

![9](/images/LwM2M/FOTA升级配置入口.jpg)

<center>图 9 FOTA升级配置入口</center>

（2）选中“**固件管理**”选项， 点击“**添加固件版本**”按钮， 如图 10 所示。

![10](/images/LwM2M/添加固件版本入口.jpg)

<center>图 10 添加固件版本入口</center>

（3）厂商名称和模组型号为 FOTA 群组里面的参数， 此处不可修改，只需填写目标版本号，用户需要执行两次“添加固件版本”操作，第一次在“目标版本号”处填写模组初始版本号，如图11所示，第二次填写将要升级到的目标版本号，如图12所示。添加固件版本后的列表如图13所示。

> 注意：此处必须创建两个固件版本，一个为初始版本，一个为升级后的目标版本。若用户只创建了升级后的目标版本，在后续的“添加升级包”操作中将无法选择初始版本。

![11](/images/LwM2M/填写初始版本号.jpg)

<center>图 11 填写初始版本号</center>

![12](/images/LwM2M/填写目标版本号.jpg)

<center>图 12 填写目标版本号</center>

![13](/images/LwM2M/固件版本列表.jpg)

<center>图 13 固件版本列表</center>

（4）在“V2.0”固件管理列表里添加升级包，点击“**添加升级包**”按钮，如图 14 所示。

![14](/images/LwM2M/添加升级包入口.jpg)

<center>图 14 添加升级包入口</center>

（5）对升级包相关参数进行配置，如图15所示，完成参数配置以后点击“**添加**”
按钮。

![15](/images/LwM2M/升级包配置.jpg)

<center>图 15 升级包配置</center>

#### 参数说明：
<table>
<tr><th width="20%">参数名称</th><th>说明</th></tr>
<tr><td>类型</td><td>选择差分包或完整包</td></tr>
<tr><td>初始版本</td><td>上一步创建的固件版本，本示例中为1.00。</td></tr>
<tr><td>目标版本</td><td>上一步创建的目标版本，本示例中为V2.0。</td></tr>
<tr><td>上传升级包</td><td>为待升级的差分包bin文件。</td></tr>
<tr><td>MD5 码</td><td> MD5校验工具对差分包校验所得。</td></tr>
</table>

（6）点击“**升级任务管理**”， 进入“**添加升级任务**”界面， 如图16所示。

![16](/images/LwM2M/升级任务管理入口.jpg)

<center>图 16 升级任务管理入口</center>

（7）升级包选择为第（5）步添加的升级包， 其它选项根据设备实际应用场景选择， 配置完成后点击“**添加**”按钮， 配置选项如图17。
![17](/images/LwM2M/升级任务配置.jpg)

<center>图 17  升级任务配置</center>

（8）升级任务创建成功之后， 进入详情查看当前升级任务相关状态，如图18和图19所示。

![18](/images/LwM2M/创建完成的升级任务.jpg)

<center>图 18  创建完成的升级任务</center>

![19](/images/LwM2M/升级任务相关状态.jpg)

<center>图 19  升级任务相关状态</center>

（9）升级完成后，模组打印信息以及平台升级列表显示的状态，如图20和图21所示。

![20](/images/LwM2M/模组升级完成.jpg)

<center>图 20  模组升级完成</center>

![21](/images/LwM2M/平台升级后显示的状态.jpg)

<center>图 21  平台升级后显示的状态</center>