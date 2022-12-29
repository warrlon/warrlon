<h1>上报版本</h1>

请求方式：**POST**

URL: http://ota.heclouds.com/ota/device/version

>设备首次升级时需要调用该接口向平台上报版本号。

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
<tr><td>dev_id</td><td>long</td><td>是</td><td>设备id</td></tr>
</table>

#### http 请求内容

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="15%">是否必须</th><th>说明</th></tr>
<tr><td>f_version</td><td>string</td><td>否</td><td>模组版本号</td></tr>
<tr><td>s_version</td><td>string</td><td>否</td><td>应用服务版本号</td></tr>
</table>

#### 返回参数

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="70%">说明</th></tr>
<tr><td>errno</td><td>int</td><td>调用错误码，为0表示调用成功</td></tr>
<tr><td>error</td><td> string</td><td>错误描述，为"succ"表示调用成功</td></tr>
</table>

#### 说明

1、如果设备需要使用OTA对设备进行升级，需要调用该接口上报设备的当前版本；

2、平台会将对应版本号和设备绑定存储；

3、如果该设备存在升级任务，并且任务的目标版本是此时上报的版本号，那么平台会将该升级任务设定为“已完成”状态。

4、版本号长度限制小于等于20个字符，并且限制为数字、字母、短横线、点、下划线中的一种或多种的组合。

<h4 id="1">请求示例</h4>

```text
POST http://ota/device/version?dev_id=32981907
Authorization:version=2018-10-31&res=products/33704&et=2529385073&method=sha1&sign=RccQWjT1n5OJ2khw3M4aPckkiFs=
Content-Type:application/json
Host: api.heclouds.com

```

#### http请求参数示例

```json
{

  "f_version":"1.0", //模组版本号
  "s_version":"2.0" //应用软件版本号

}
```

#### 返回示例

```json
{

    "errno": 0,

    "error":“succ”

}
```

<div>
    <a href="/book/develop/south-API/api-list.md">
        <span> &#171; 上一篇：API列表</span>
        </a>
		</div>
<div>
    <a href="/book/develop/south-API/1task.md">
        <span> &#187; 下一篇：2-检查设备升级任务</span>
    </a>
</div>
