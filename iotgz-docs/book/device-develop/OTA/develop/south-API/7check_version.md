<h1>查询设备版本号</h1>

请求方式：**GET**

URL: http(s)//ota.heclouds.com/ota/device/version

[我只想看示例！！！](#1)

> 用户根据实际需求使用，属于可选操作。

#### http头部

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="15%">是否必须</th><th>说明</th></tr>
<tr><td>Content-Type</td><td>string</td><td>是</td><td>必须为application/json</td></tr>
<tr><td>Authorization</td><td>string</td><td>是</td><td>安全鉴权信息</td></tr>
</table>

#### http 请求参数

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="15%">是否必须</th><th>说明</th></tr>
<tr><td>dev_id</td><td>string</td><td>是</td><td>设备id</td></tr>
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
<tr><td>f_version</td><td>string</td><td>模组版本号</td></tr>
<tr><td>s_version</td><td>string</td><td>应用服务版本号</td></tr>
</table>

#### 说明

1、如果返回的data为空，说明设备没有上报过版本信息；

2、f_version和s_version根据平台存的信息返回（即如果设备没有上报过f_version信息，将不会返回该字段）；


<h4 id="1">返回示例</h4>

```json
{
   {
   "errno": 0,
   "error":"succ",
   "data":
      {
      "target":"1.2", // 升级任务的目标版本
      "token":"ota_5hc95SFeo5xJEnaNrste", //文件地址ip:port/ota/download/{token}
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
}
```