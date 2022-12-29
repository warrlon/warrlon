# 创建产品

<a href="#1">1. 登录</a>

<a href="#2">2. 创建产品</a>

<a href="#3">3. 产品管理</a>

---

产品是一组具有相同功能定义的设备集合，创建产品是使用平台的第一步，快速创建产品后可定义产品物模型、添加对应设备。产品列表用于自建产品及第三方授权产品的管理。

<h3 id="1"> 1. 登录</h3>

使用OneNET账号登录开发者中心，如图1所示。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/application/登录页.jpeg">
    <br>
    图1 登录
    <br>
</center>

通过页面左上角的入口进入OneNET Studio平台，如图2所示。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/application/进入OneNET Studio平台.png">
    <br>
    图2 进入Studio平台
    <br>
</center>

<h3 id="2"> 2. 创建产品</h3>

进入Studio平台后，展开菜单栏中的「设备接入与管理」，点击「产品管理」，进入产品列表页面。
点击「添加产品」，在弹出页面中，按照提示填写产品的基本信息，进行产品创建，如图3所示。
请您按照提示尽可能完整、全面地填写相应内容，这样更方便您后期对产品进行管理。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/application/添加产品.png">
    <br>
    图3 添加产品
    <br>
</center>

<h3 id="3"> 3. 产品管理</h3>

 ##### 产品列表
 
产品列表用于自建产品及第三方授权产品的管理。「我的产品」展示由用户主动创建的产品信息，具有详情查看、删除、编辑、物模型及生产档案管理等权限;「授权产品」则是用户获取他人转移设备时，由平台自动生成的授权产品信息，当前用户只具有产品基础信息及物模型查看权限，产品列表如图所示。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/我的产品.png">
    <br>
    图 4 产品列表
    <br>
</center>

##### 物模型管理

物模型是对设备的数字化抽象描述，是在云端构建实体的一种规范化数据描述，以产品为单位进行定义。进入单个产品的详情页面，可对产品的物模型功能点进行新增、编辑、查看及导出等操作，详细使用说明见[开发产品物模型](https://open.iot.10086.cn/doc/iot_platform/book/device-connect&manager/thing-model/introduce.html)。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/物模型管理.png">
    <br>
    图 5 物模型管理
    <br>
</center>

##### 设备生产档案管理

设备生产档案用于产品设备的生产信息管理（由当前用户创建，包括自有和已转移设备），该功能提供灵活的查询及导出操作，用户可根据实际业务系统的生产管理需求，将单个产品下的设备按照转移状态、添加日期等条件导出后进行维护与管理。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/设备生产档案管理.png">
    <br>
    图 6 设备生产档案管理
    <br>
</center>

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/设备生产档案下载.png">
    <br>
    图 7 设备生产档案下载
    <br>
</center>

设备导出说明：

- 设备导出采用异步任务方式，首先需要在「创建任务」页面设置筛选条件，点击「创建导出任务」按钮，平台创建任务后在「任务列表」页面查看任务执行情况。

- 设备导出任务同一时间只能执行一个（即状态为"导出中"），如需进行后续操作，必须等当前任务执行完成后才可进行，连续操作之间的时间间隔不得少于1分钟。

- 平台会保存用户最近5次的导出任务信息，用户可在任务列表进行查看，并直接下载导出文件。
