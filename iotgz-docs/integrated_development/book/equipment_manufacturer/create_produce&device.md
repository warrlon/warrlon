# 创建产品和设备
本页目录

<a href="#1">1. 创建产品</a> 

<a href="#2">2. 功能定义</a> 

<a href="#3">3. 设备开发</a> 

---

<h3 id="1"><font color=#CD6839> 1. 创建产品</font></h3>

点击首页右上角“**控制台**”，如图1所示。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/控制台入口.png">
    <br>
    图 1 控制台的入口
</center>

进入控制台后，点击页面的“**创建产品**”按钮，如图2所示，进入创建产品的详情页面，如图3所示，输入信息后点击“确定”，产品创建成功，如图4所示。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/创建产品入口.png">
    <br>
    图 2 创建产品入口
    <br>
    <br>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/创建产品详情.png">
    <br>
    图 3 创建产品详情
    <br>
    <br> 
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/创建产品成功.png">
    <br>
    图 4 创建产品结果
</center>

#### &#9755; 参数说明

<table>
<tr><th width="20%">参数</th><th>说明</th></tr>
<tr><td>产品名称</td><td>用户自定义的产品名称，1-20个字符，只支持英文字母、汉字、数字、下划线或组合。</td></tr>
<tr><td>产品类别</td><td>选择所创建产品所属的行业以及产品类别。</td></tr>
<tr><td>联网模式</td><td>目前支持NB设备，其它协议类型将陆续更新。</td></tr>
<tr><td>数据类型</td><td>TLV为平台自定义的TLV二进制流，平台提供SDK可根据功能生成二进制流。</td></tr>
</table>

<h3 id="2"><font color=#CD6839> 2. 功能定义</font></h3> 


从产品列表进入产品详情页，点击产品开发，可以添加基础功能点、组合功能点、固定上报功能点，基础功能点包括设备功能和系统功能两种。如图5所示。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/产品开发.png">
    <br>
    图 5 产品开发
</center>

在基础功能点页面，点击右侧“添加标准功能”，如图6所示，标准功能是平台已经定义好的设备功能。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/添加标准功能.png">
    <br>
    图 6 添加标准功能
</center>

此外，可以点击“添加自定义功能”向该产品添加自定义的功能点，如图7所示。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/添加自定义功能.png">
    <br>
    图 7 添加自定义功能
    <br>
</center>

点击“添加系统功能”，如图8所示，系统功能为提前制定的功能，如故障率，将用于设备故障统计，输出报表等。添加结果如图9所示

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/添加系统功能.png">
    <br>
    图 8 添加系统功能
    <br>
    <br>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/产品基础功能点列表.png">
    <br>
    图 9 产品基础功能点列表
    <br>
</center>

<h3 id="3"><font color=#CD6839> 3. 设备开发</font></h3>

功能定义完成后，即可下载SDK和编译环境。

> 每次功能定义更新后都需要重新下载SDK。

利用平台提供的SDK可以进行功能开发，最后写入设备，完成设备侧的开发，同时平台提供调试设备工具，可以在界面上查看设备上行数据，也可以模拟下行数据。如图10所示。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/设备测试.png">
    <br>
    图 10 设备调试
    <br>
</center>

设备连接平台时，平台根据注册码和设备SN自动创建设备。也可以在**设备管理&#10142;生产管理**中预导入设备信息，如图11所示。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/设备导入.png">
    <br>
    图 11 设备导入
    <br>
</center>

> 白名单：未开启白名单功能，用户设备接入平台后可直接注册激活；开启白名单功能后，仅预导入设备列表种的设备可以注册激活。若用户开启了白名单，并进行设备接入时，请先在**设备管理**&#10132;**生产管理**中导入设备SN或设备IMEI。

<div>
    <a href="/book/equipment_manufacturer/total_use_process.md">
        <span> &#171; 上一篇：设备生产商_流程概览</span>
    </a>
</div>
<div>
    <a href="/book/equipment_manufacturer/produce_develop.md">
        <span> &#187; 下一篇：设备生产商_产品开发</span>
    </a>
</div>

