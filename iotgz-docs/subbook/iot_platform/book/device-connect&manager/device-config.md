# 远程配置

<a href="#1">1. 使用流程</a> 

<a href="#2">2. 配置文件管理接口</a>

---

平台具备远程配置功能，远程配置功能支持开发者在云端设置全局系统参数、网络参数等配置信息，设备端通过定时拉取或命令触发方式下载平台配置文件信息，完成本地配置文件更新。

<h3 id="1">1. 使用流程</h3>

菜单栏点击「产品管理」，进入产品列表页面。产品列表页面选择单个产品进入详情操作页面，点击「远程配置」功能标签，切换到配置页面，如图所示。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/远程配置操作页面.png">
    <br/>
    图 1 远程配置操作页面
    <br/>
</center>

点击「编辑配置文件」按钮，进入文件编辑模式。开发者在编辑框中输入JSON格式的配置信息。编辑完成后，点击「编辑完成」按钮，即可发布配置文件，此时该配置文件将对产品下所有设备生效。 

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/配置文件编辑页面.png">
    <br/>
    图 2 配置文件编辑页面
    <br/>
</center>

配置文件编辑模式下，开发者可使用平台提供的额外操作功能来简化配置文件编辑过程，如下为平台提供的操作功能说明：

| 操作 | 功能描述                         |
| ---- | ---------------------------- |
| 导入物模型 | 操作可将物模型功能点配置信息快速添加至编辑区中， 新添加信息将会覆盖编辑区已有信息 |
| 还原历史版本 | 系统默认保存最近5次的配置文件修改记录，操作可查看版本更新时间和配置内容，并且可选择将目标版本内容恢复至编辑区中，恢复信息将会覆盖编辑区已有信息 |

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/配置文件历史版本管理.png">
    <br/>
    图 3 配置文件历史版本管理页面
    <br/>
</center>

<h3 id="2">2. 配置文件管理接口</h3>

> 设备通过定时拉取或命令触发方式调用云端API下载配置文件信息，API鉴权参数Authorization计算方式参见[设备接入安全鉴权](https://open.iot.10086.cn/doc/iot_platform/book/device-connect&manager/device-auth.html)

配置文件下载API

| HTTP方法 | GET                                                          |
| -------- | ------------------------------------------------------------ |
| URL      | http://studio-file.heclouds.com/studio/config/{productId}/{deviceName}/outdownload |
| HTTP头部 | Content-Type:application/json  <br/>Authorization: xxx，示例-"version=2018-10-31&res=products/23104&et=1554398783&method=sha1&sign=fsBwuj0udOpU3BLoHmpbFwyIo30=" |
| HTTP响应 | 二进制文件                                                   |
| 备注     | Content-Length:当前请求获取的数据大小  <br/> Studio-SysFile-Errno:0, // 请求的状态 0-成功、3-文件已删除、6-鉴权失败、7-不存在远在配置文件 |
