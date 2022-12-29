# OTA服务升级任务推送使用指导

<h3 id="1">1 应用场景</h3>

使用OTA增值服务时，如果在OneNET平台将设备添加到指定升级包中（即给设备新增升级任务），需要用户的终端设备主动到OneNET平台检查是否存在升级任务。这种情况下，用户的设备就需要开启一个定时任务，周期性到OneNET平台检查是否存在升级任务，这种工作模式对电能消耗敏感的设备极其不利。

<h3 id="2">2 使用流程</h3>

OneNET平台提供了OTA升级任务的推送功能，当用户在OneNET平台为终端设备新建升级任务后，将所涉及到的设备信息推送给用户侧的应用平台，由用户的应用平台下发命令给对应设备，再由设备到OneNET平台检查升级任务进行OTA升级。使用OneNET升级任务推送功能后，设备就不需要周期性到OneNET平台检查升级任务，节约能耗。

具体流程图如下所示。


<center>
    <img width="70%"  
    src="/images/OTA/升级任务推送流程.jpg">
    <br>
    升级任务推送使用流程
</center>

#### 第一步：完成用户侧应用平台部署

用户侧应用服务用于接收OneNET OTA推送过来的任务信息和校验信息。OneNET平台提供了简单的[DEMO](https://github.com/cm-heclouds/ota-receive)。

若跳转失败，请使用地址 https://github.com/cm-heclouds/ota-receive


#### 第二步：在OneNET OTA官网配置推送url和token

token用于校验。校验过程包括：用户在提交配置时，平台会将token+uid取md5值通过HTTP GET请求发送到用户配置的url，如果返回PASSED则配置成功，如果返回FAILED则配置失败。

#### 第三步：在OneNET OTA控制台开启推送功能，并关联升级包

配置推送URL和token后，将需要推送的升级包关联到该URL中，用户可以选择推送或者不推送升级信息（通过开启和取消关联等操作）。

#### 第四步：添加设备到对应升级包时

如果用户开启推送功能并关联了该升级包，则OneNET-OTA会将升级的设备信息通过HTTP POST方法推送给用户配置的url中。

<h3 id="3">3 服务校验接口</h3>

**HTTP方法**:	GET

**URL**:	http://&#60;API_ADDRESS&#62;/ota/receive

**HTTP参数**:	signature=dfadfdafda

**成功返回**:	PASSED | FAILED

> 说明: signature是用户在OneNET-OTA配置的token+uid的md5值。

<h3 id="4">4 接收任务信息接口</h3>

**HTTP方法**:	POST

**URL**:	http://&#60;API_ADDRESS&#62;/ota/receive

**HTTP请求内容**:

```json
	{
    "info":{
        "uid":1,
        "date":1573611869000
    },
    "signature":"3783bdc4ccdf08f1189d21871edd9df5",
    "msg":{
        "dids":[123,345],
        "startTime":1573611869000,
        "version":"11"
    }
}
```	

<div>
    <a href="/book/manual/ota_develop_document.md">
        <span> &#171; 上一篇：升级操作流程</span>
        </a>
		</div>
<div>
    <a href="/book/develop/auth.md">
        <span> &#187; 下一篇：API鉴权</span>
    </a>
</div>