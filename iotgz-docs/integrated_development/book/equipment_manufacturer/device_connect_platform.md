# 设备接入平台

本页目录

<a href="#1">1. 下载SDK和编译环境</a> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <a href="#5">5. 程序编译</a> 

<a href="#2">2. 替换SDK中相关文件</a> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <a href="#6">6. 程序烧录</a> 

<a href="#3">3. 设备的逻辑功能开发</a> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <a href="#7">7. 接入调试</a> 

<a href="#4">4. 安装OpenCPU编译环境</a> 

---

本部分内容主要提供下载SDK进行嵌入式开发，实现产品功能，接入平台联调等参考内容。并着重描述嵌入式开发SDK的使用方法，具体嵌入式功能开发，需要用户在SDK里根据自己功能进行开发，待功能开发完成后就可以进行接入测试。

接入流程用例：中移物联网M5311模组

> 接入前用户需参考[《M5311 OpenCPU 开发指导手册》](/doc/M5311_OpenCPU开发指导手册.pdf)。


<h3 id="1"><font color=#CD6839>1. 下载SDK和编译环境</font></h3>

用户通过**控制台**进入产品列表，在**产品开发** &#10142; **产品功能定义**中完成功能点定义之后，点击页面底部**下一步**按钮进入**设备开发测试**页面，如图1所示，点击**SOC-SDK下载**和**下载编译环境**链接。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/下载SDK.png">
    <br>
    图 1 下载SDK
</center>

<h3 id="2"><font color=#CD6839>2. SDK文件复制</font></h3>

**&#9758; SOC-SDK**是根据用户所定义的功能点以及产品信息平台自动生成特有SDK文件。

**&#9758; SDK-BASE**文件是基于M5311模组的OPENCPU SDK开发环境。

用户需将SOC-SDK中cmiot_user.c和cmiot_user.h复制到SDK-BASE文件夹中的user文件夹下替换即可。如图2和图3所示。

> 注意如果功能点发生改变，需要重新下载SOC_SDK重新编译。

<center>
    <img width="70%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/SOC_SDK.png">
    <br>
    图 2 SOC-SDK中cmiot_user.c和cmiot_user.h文件
    <br>
    <br>
    <img width="70%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/SDK_BASE.png">
    <br>
    图 3 SDK-BASE文件夹
</center>

文件目录说明：

<table>
<tr><th width="15%">文件名称</th><th>文件说明</th></tr>
<tr><td>app</td><td>业务逻辑层包含DM认证</td><tr>
<tr><td>docs</td><td>编译文档说明</td><tr>
<tr><td>sdk</td><td>M5311模组的SDK</td><tr>
<tr><td>user</td><td>用户功能开发</td><tr>
<tr><td>bin</td><td>可执行文件</td><tr>
</table>

<h3 id="3"><font color=#CD6839>3. 设备逻辑功能开发</font></h3>

文件复制完成后，用户可在**cmiot_user.c**里进行设备逻辑功能开发，具体开发细节请参考[SDK说明](/book/equipment_manufacturer/sdk_introduce.md)。

<h3 id="4"><font color=#CD6839>4. 安装OpenCPU编译环境</font></h3>

完成逻辑功能开发后，需要使用build.bat编译。

Windows环境安装gcc编译环境后可编译软件版本。用户首次进行OpenCPU开发，需要准备好编译环境。下面为gcc编译环境的安装过程：

(1) 在[下载专区](/book/download/download_list.md)中找到“GNU Tools ARM Embedded”安装包并将解压至：“C：progarm files（X86）”目录下。

(2) 将“C：progarm files（X86）\GNU Tools ARM Embedded\4.9 2015q3\bin”路径添加至环境变量。如图4、图5、图6所示。

> 添加环境变量路径为：我的电脑 > 属性 > 高级系统设置

(3) 添加完成变量后，重启电脑完成安装。

至此，OpenCPU编译环境安装完成，可以使用编译工具来完成编译。

<center>
    <img width="70%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/系统属性位置.png">
    <br>
    图 4 高级系统设置—系统属性
    <br>
    <br>
    <img width="70%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/环境变量位置.png">
    <br>
    图 5 系统属性-环境变量
    <br>
    <br>
    <img width="70%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/编辑环境变量.png">
    <br>
    图 6 编辑环境变量   
</center>

<h3 id="5"><font color=#CD6839>5. 程序编译</font></h3>

首先确定使用的模组硬件版本，-LV表示多频版本，频段支持band3/5/8,-CM表示单频版本，频段只支持band 8，以多频版本为例，编译命令为：

<h3><font color=#20B2AA><center>build.bat LV</center></font></h3>

在命令行中进入SDK主目录，输入build.bat LV 命令后回车，即可执行编译。如图7所示。

<center>
    <img width="70%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/程序编译.png">
    <br>
    <img width="70%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/编译结果.png">
    <br>
    图 7 程序编译
    <br>
</center>

如图8所示，编译成功后会在fimware/LV目录下生成固件：

<h3><font color=#20B2AA><center>noiot_m2m_demo.bin</center></font></h3>

<center>
    <img width="70%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/编译成功.png">
    <br>
    图 8 编译成功
    <br>
</center>

> 在命令行中输入build.bat CLEAN命令可以删除编译结果。

<h3 id="6"><font color=#CD6839>6. 程序烧录</font></h3>

编译完成，生产BIN文件后，将版本文件烧录至开发板过程如下所示：

&#10148; 1. 如图9所示，将开发板UART0口通过micro-USB线连接至PC，板子左上方两个切换开关分别切至U0和ON，板子通电指示灯亮起。

<center>
    <img width="70%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/程序烧录1.png">
    <br>
    图 9 程序烧录
    <br>
</center>

&#10148; 2. 安装CH340串口驱动程序（如已安装则跳过此步骤）

**CH340驱动程序**安装成功后，计算机的**设备管理器**中会出现相关COM口，如图10和图11所示。

<center>
    <img width="50%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/驱动安装.png">
    <br>
    图 10 驱动安装
    <br>
    <img width="50%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/COM口.png">
    <br>
    图 11 设备管理器
    <br>
</center>

&#10148; 3.	打开flashtool.exe下载工具，选择好COM口之后，在**Config file**栏下选择**firmware**目录下的**flash_download.cfg**文件，工具会自动加载目录下BootLoader文件和ROM文件。

&#10148; 4.	点击**start**键，然后长按开发板右下角PWKey键2秒开机，直至出现烧录进度条。

<center>
    <img width="70%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/程序烧录.png">
    <br>
    图 12 程序烧录
    <br>
    <br>
    <img width="70%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/烧录完成.png">
    <br>
    图 13 程序烧录完成
    <br>
</center>

<h3 id="7"><font color=#CD6839>7. 接入调试</font></h3>

#### 1） 设备上电

烧录完成后，打开串口调试工具，设备上电打印信息如下：

<center>
    <img width="70%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/设备上电打印信息.png">~
    <br>
    图 14 设备上电
    <br>
</center>

#### 2） 录入IMEI

设备首次上电时打印信息显示没有IMEI和SN信息，使用M5311模组接入行业开发平台的设备只需录入IMEI号即可。使用串口工具发送下面的命令进行录入。

<h3><font color=#20B2AA><center>AT+SETDEVID={“imei_dev”:“imei”}</center></font></h3>

**参数说明：**
- “imei”：设备imei号，模组上面可查询到，有效的15位数字。

> 注意：录入IMEI号时，必须使用英文字符输入，命令区分大小写，并且必须勾选发送新行。

**示例：**
AT+SETDEVID={"imei_dev":"86997xxxx827879"}

<center>
    <img width="70%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/录入IMEI号.png">
    <br>
    图 15 设备信息录入
    <br>
    <br>
    <img width="70%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/设备登录成功.png">
    <br>
    图 16 设备登录成功
    <br>
</center>

#### 3） 平台侧调试设备

录入完IMEI号后，模组自动连接平台，在平台**产品开发 > 设备开发测试 > 调试设备**下拉栏里可以查看到已连接平台的设备。用户选择需要调试的设备，点击开始测试后应用和设备会进行连接。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/选择调试的设备.png">
    <br>
    图 17 选择调试的设备
    <br>
    <br>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/调试设备.png">
    <br>
    图 18 调试设备
    <br>
</center>

在消息日志里可以查看设备和平台应用交互的信息。待收到设备在线信息后，用户可以在应用界面进行交互，选择消息类型和功能点后可以将命令下发到设备，如图18所示，设备可以上传数据到平台。用户可以根据自己需求进行功能点的开发，开发完成后就可以进入产品发布阶段。

> 示例：如图18所示，在平台侧，通过调试工具向设备的功能点“开关（功能点ID12289）”发送“写命令”，值为true，接收到设备返回的操作成功响应消息。如图19所示，在设备侧，通过串口调试工具，可以看到设备针对功能点“开关”上报的响应信息。

<center>
    <br>
    <img width="70%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/设备上报资源成功.png">
    <br>
    图 19 设备上报资源成功
    <br>
</center>

#### 4） 设备管理

设备登录行业开发平台后，通过**设备生产 > 设备管理 > 我的设备**可以查看登录到平台的设备信息，如图20所示。

<center>
    <br>
    <img width="70%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/设备管理_我的设备.png">
    <br>
    图 20 我的设备_设备列表
    <br>
</center>

点击**操作 > 历史数据**可以查看到先前登录行业开发平台的设备详细信息，如图21所示。

<center>
    <br>
    <img width="70%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/我的设备_历史数据.png">
    <br>
    图 21 设备列表_历史数据
    <br>
</center>

点击**历史数据**列表中的**操作 > 详情**，可以查看到之前调试设备时，命令下发和资源上报的数据记录，如图22、图23所示。

<center>
    <br>
    <img width="70%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/历史数据_详情.png">
    <br>
    图 22 历史数据_详情
    <br>
    <br>
    <img width="70%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/历史数据记录.png">
    <br>
    图 23 历史数据
    <br>
</center>

<div>
    <a href="/book/equipment_manufacturer/produce_develop.md">
        <span> &#171; 上一篇：设备生产商_产品开发</span>
    </a>
</div>
<div>
    <a href="/book/equipment_manufacturer/sdk_introduce.md">
        <span> &#187; 下一篇：设备生产商_SDK使用说明</span>
    </a>
</div>