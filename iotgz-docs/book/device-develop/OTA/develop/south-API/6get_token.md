<h1>获取设备正在升级（下载中/升级中）的token</h1>

请求方式：**GET**

URL: http(s)//ota.heclouds.com/ota/south/tasking

> 目前可以使用“检测设备升级任务”API进行替代。

[我只想看示例！！！](#1)

#### http头部 

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="15%">是否必须</th><th>说明</th></tr>
<tr><td>Content-Type</td><td>string</td><td>是</td><td>必须为application/json</td></tr>
<tr><td>Authorization</td><td>string</td><td>是</td><td>安全鉴权信息</td></tr>
</table>

#### http请求参数

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="15%">是否必须</th><th>说明</th></tr>
<tr><td>dev_id</td><td>string</td><td>是</td><td>设备id</td></tr>
<tr><td>type</td><td>int</td><td>是</td><td>1:fota任务,2:sota任务</td></tr>
<tr><td>cdn</td><td>boolean</td><td>否</td><td>是否返回拉取升级包ip</td></tr>
</table>

#### 返回参数

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="70%">说明</th></tr>
<tr><td>errno</td><td>int</td><td>调用错误码，为0表示调用成功</td></tr>
<tr><td>error</td><td> string</td><td>错误描述，为"succ"表示调用成功</td></tr>
<tr><td>data</td><td> json</td><td>接口调用成功之后返回的设备相关信息，见data描述表</td></tr>
</table>

#### data描述表
<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="70%">说明</th></tr>
<tr><td>target</td><td>string</td><td>升级任务的目标版本</td></tr>
<tr><td>token</td><td>string</td><td>文件地址 ip:port/ota/download/{token}</td></tr>
<tr><td>size</td><td>int</td><td>文件大小</td></tr>
<tr><td>signal</td><td>int</td><td>任务在大于该信号下进行</td></tr>
<tr><td>power</td><td>int</td><td>任务在大于该电量下进行</td></tr>
<tr><td>retry</td><td>int</td><td>重试次数</td></tr>
<tr><td>interval</td><td>int</td><td>重试间隔</td></tr>
<tr><td>md5</td><td>string</td><td>升级文件的md5码</td></tr>
<tr><td>ipPort </td><td>string</td><td>拉取升级包的ip地址</td></tr>
<tr><td>type</td><td>int</td><td>1:完整包，2：差分包</td></tr>
</table>
 
#### 错误码说明

<table>
<tr><th width="10%">错误码</th><th>说明</th></tr>
<tr><td>0</td><td>有效。</td></tr>
<tr><td>2</td><td>type参数错误。</td></tr>
<tr><td>4</td><td>not found 没有找到有效的token，可能是由于没有升级任务，或者升级任务的token过期。</td></tr>
<tr><td>7</td><td>OneNET内部错误。</td></tr>
<tr><td>12</td><td>token过期，设备升级流程结束。</td></tr>
</table>

<h4 id="1">请求参数示例</h4>

```json
{
	"dev_id":6523,  //设备id
	"type":1,       //1:fota任务,2:sota任务
	"cdn": true     //是否返回拉取升级包ip，选填
}
```

#### 返回示例

```json
{
	"errno": 0,
	"error":"succ",
	"data":
	{
		"target":"1.2", // 升级任务的目标版本
		"token":"ota_5hc95SFeo5xJEnaNrste",//文件地址ip:port/ota/download/{token}
   		"size":123,//文件大小
   		"signal":12,//任务在大于该信号下进行
   		"power":90,//任务在大于该电量下进行
   		"retry":10,//重试次数
   		"interval":90,//重试间隔
   		"md5":"dfkdajkfd",//升级文件的md5
   		"ipPort":"172.19.3.3:8002", //拉取升级包的ip地址
   		"type":1 // 1:完整包，2：差分包
	}
}
```