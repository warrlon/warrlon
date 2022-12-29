<h1>上报状态</h1>

请求方式：**POST**

URL: http//ota.heclouds.com/ota/south/report

> 用户使用该API时，需要调用两次，先上报下载相关状态码（Result=1xx），再上报升级相关状态码(Result=2xx)。

[我只想看示例！！！](#1)

#### http头部 
参数名称 | 格式 | 是否必须 | 说明
:- | :- | :- | :- 
Authorization | string | 是 | 安全鉴权信息


#### http请求参数
参数名称 | 格式 | 是否必须 | 说明
:- | :- | :- | :- 
dev_id | long | 是 | 设备id
token | string | 是 | 检测升级任务返回的token

#### http body 内容
参数名称 | 格式 | 是否必须 | 说明
:- | :- | :- | :- 
result | int | 是 | 详情见result说明

#### 返回参数
参数名称 | 格式 | 说明
:- | :- | :- 
errno | int | 调用错误码，详见错误码说明
error | string | 错误描述，为"succ"表示调用成功


#### result说明

<table>
<tr><th width="10%">result码</th><th width="40%">说明</th><th width="10%">result码</th><th width="40%">说明</th></tr>
<tr><td>101</td><td>升级包下载成功。</td><td>102</td><td>下载失败,空间不足</td></tr>
<tr><td>103</td><td>下载失败,内存溢出</td><td>104</td><td>下载失败,下载请求超时</td></tr>
<tr><td>105</td><td>下载失败,电量不足</td><td>106</td><td>下载失败,信号不良</td></tr>
<tr><td>107</td><td>下载失败,未知异常</td><td>-</td><td>-</td></tr>
<tr><td>201</td><td>升级成功</td><td>202</td><td>升级失败,电量不足</td></tr>
<tr><td>203</td><td>升级失败,内存溢出</td><td>204</td><td>升级失败,版本不一致</td></tr>
<tr><td>203</td><td>升级失败,内存溢出</td><td>204</td><td>升级失败,版本不一致</td></tr>
<tr><td>205</td><td>升级失败,MD5校验失败</td><td>206</td><td>升级失败,未知异常</td></tr>
<tr><td>207</td><td>达到最大重试次数</td><td>208</td><td>设备升级过期</td></tr>
</table>

#### 错误码说明

<table>
<tr><th width="10%">错误码</th><th>说明</th></tr>
<tr><td>0</td><td>上报信息成功。</td></tr>
<tr><td>1</td><td>上报信息失败，token鉴权失败。</td></tr>
<tr><td>2</td><td>上报失败，上报的状态码不能识别。</td></tr>
<tr><td>20</td><td>上报信息失败，升级任务已经完成。</td></tr>
<tr><td>21</td><td>无效的操作，sdk逻辑错误。</td></tr>
<tr><td>22</td><td>上报信息失败，升级任务已被取消。</td></tr>
<tr><td>24</td><td>请求内容result错误。</td></tr>
</table>

<h4 id="1">请求参数示例</h4>

```json
{
	"result": 101
	
}
```

#### 返回示例

```json
{
	"errno": 0,
	"error": "succ"

}
```

<div>
    <a href="/book/develop/south-API/7check_version.md">
        <span> &#171; 上一篇：7-查询设备版本号</span>
        </a>
		</div>
<div>
    <a href="/book/develop/south-API/8check_did.md">
        <span> &#187; 下一篇：9-查询设备ID</span>
    </a>
</div>