<h1>根据设备唯一标识查询设备ID</h1>

请求方式：**GET**

URL: http://ota.heclouds.com/ota/devInfo

[我只想看示例！！！](#1)

> 设备ID是平台为每个设备分配的、具有唯一性的ID号，若您的设备暂未获取到设备ID，并且在首次接入平台时需要进行升级，可通过该接口使用设备唯一标识获取到设备ID。

#### http头部

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="15%">是否必须</th><th>说明</th></tr>
<tr><td>Content-Type</td><td>string</td><td>是</td><td>必须为application/json</td></tr>
<tr><td>Authorization</td><td>string</td><td>是</td><td>安全鉴权信息</td></tr>
</table>

#### http 请求body

<table>
<tr><th width="15%">参数名称</th><th width="15%">格式</th><th width="15%">是否必须</th><th>说明</th></tr>
<tr><td>pid</td><td>long</td><td>是</td><td>产品id</td></tr>
<tr><td>authInfo</td><td>string</td><td>是</td><td> 设备唯一标识，详情请查看下文说明</td></tr>
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
<tr><td>dev_id</td><td>string</td><td>设备ID</td></tr>
</table>

#### 说明

请求参数authInfo根据产品协议不同，对应含义不同，详情如下：

1. 如果产品是**NB协议**，那么设备唯一标识就是在平台创建设备时的“IMEI”字段；

2. 如果产品是**MQTTS（新版MQTT）协议**，那么设备唯一标识就是在平台创建设备时的“设备名称”字段；

3. 如果产品是**MQTT/EDP/TCP透传协议**，那么设备唯一标识就是在平台创建设备时的“鉴权信息”字段；

4. 如果产品是**HTTP协议**，那么设备唯一标识就在平台创建设备时的“设备编号”字段；

5. 如果产品是**Modbus协议**，那么设备唯一标识是在平台创建设备时的“DTU序列号”和“DTU密码”字段组成的json字符串；

6. 如果产品是**JT/T808协议**，那么设备唯一标识是在平台创建设备时的“终端型号”和“终端ID”字段组成的json字符串。

<h4 id="1">请求示例</h4>

```json	
{

    "pid":123,

    "authInfo":"869975036903162"//NB设备的唯一标识为IMEI号，其他协议请参考上文“说明”

}
```

#### 返回示例

```json
{

"errno": 0,
"error":"succ",
"data":
      {
      "dev_id":"233444"
      }

}
```

<div>
    <a href="/book/develop/south-API/7check_version.md">
        <span> &#171; 上一篇：8-上报状态</span>
        </a>
		</div>
<div>
    <a href="/book/develop/OTA-SDK-instruction.md">
        <span> &#187; 下一篇：OTA-SDK使用说明</span>
    </a>
</div>