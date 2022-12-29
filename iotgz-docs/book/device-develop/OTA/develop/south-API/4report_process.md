<h1>上报升级状态</h1>

请求方式：**POST**

URL: http(s)://ota.heclouds.com/ota/south/device/download/{token}/progress

[我只想看示例！！！](#1)

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

#### http 请求内容

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="15%">是否必须</th><th>说明</th></tr>
<tr><td>step</td><td>int</td><td>是</td><td>取值为[0,100]，下载进度比</td></tr>
</table>

#### 返回参数

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="70%">说明</th></tr>
<tr><td>errno</td><td>int</td><td>调用错误码，为0表示调用成功</td></tr>
<tr><td>error</td><td> string</td><td>错误描述，为"succ"表示调用成功</td></tr>
</table>

#### 说明

1、设备在下载升级包的过程中（分片下载），可以根据需要上报下载进度（设备处于“下载中”，才能上报step=[0,100]）；

2、如果设备上报的下载进度为100（即step:100），那么平台会将设备的升级状态从“正在下载”修改为“正在升级”状态；

3、只有当设备处于“正在下载”状态时，设备才能够使用该接口上报下载进度，其他状态将返回“invalid state”的错误；

4、step如果大于100，将作为上报状态使用（设备处于：待升级、下载中、升级中，这三个状态时，可以通过上报如下状态码完成升级流程。其他状态如：已取消，升级失败、升级成功、暂停时，不能上报如下状态）：

<table>
<tr><th width="20%">状态码</th><th>说明</th></tr>
<tr><td>101</td><td>升级包下载成功（设备状态变成：升级中）。</td></tr>
<tr><td>102</td><td>下载失败,空间不足（设备状态变成：升级失败）。</td></tr>
<tr><td>103</td><td>下载失败,内存溢出（设备状态变成：升级失败）。</td></tr>
<tr><td>104</td><td>下载失败,下载请求超时（设备状态变成：升级失败）。</td></tr>
<tr><td>105</td><td>下载失败,电量不足（设备状态变成：升级失败）。</td></tr>
<tr><td>106</td><td>下载失败,信号不良（设备状态变成：升级失败）。</td></tr>
<tr><td>107</td><td>下载失败,未知异常（设备状态变成：升级失败）。</td></tr>
<tr><td>201</td><td>升级成功，此时会把设备的版本号修改为任务的目标版本（设备状态变成：升级完成）。</td></tr>
<tr><td>202</td><td>升级失败,电量不足（设备状态变成：升级失败）。</td></tr>
<tr><td>203</td><td>升级失败,内存溢出（设备状态变成：升级失败）。</td></tr>
<tr><td>204</td><td>升级失败,升级包与当前任务目标版本不一致（设备状态变成：升级失败）。</td></tr>
<tr><td>205</td><td>升级失败,MD5校验失败（设备状态变成：升级失败）。</td></tr>
<tr><td>206</td><td>升级失败,未知异常（设备状态变成：升级失败）。</td></tr>
<tr><td>207</td><td>达到最大重试次数（设备状态变成：升级失败）。</td></tr>
<tr><td>208</td><td>设备升级过期（设备状态变成：升级失败）。</td></tr>
</table>

#### 特别说明

下载中状态可以上报下载中的状态码或者升级中的状态码；
升级中状态只能上报升级中的状态码。


<h4 id="1">请求示例</h4>

```text
POST http:///ota/south/device/download/ota_MP9qVOT0AtsHhUSNYMy7/progress?dev_id=32981907
Content-Type:application/json
Host: api.heclouds.com

```

#### http请求参数示例

```json
{

  "step":50 // [1, 100] 下载进度为50%

}
```

#### 返回示例

```json
{

    "errno": 0,

    "error":“succ”

}
```