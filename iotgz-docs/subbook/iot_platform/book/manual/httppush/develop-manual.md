# 开发指南

在使用推送服务时，OneNET作为客户端，而用户的第三方应用是作为服务器，第三方应用需要支持**URL验证**以及**数据接收**两部分服务。


## URL验证

URL验证流程如下图所示：

![url验证流程](/images/url验证.png)

用户在配置页面完成配置并点击“提交”时，OneNET平台会向填写URL地址发送HTTP **GET**请求进行URL验证，请求形式示例如下：

```
http://url?msg=xxx&nonce=xxx&signature=xxx
```

其中，*url*为用户在页面配置时填写的URL，*nonce*、*msg*、*signature*用于URL及token的验证

token验证过程如下：

1. 将配置页面中配置的*token*与*nonce*、*msg*的值计算MD5，并且编码为Base64字符串值

2. 将上一步中Base64字符串值通过URL Decode计算后的值与请求参数*signature*的值进行对比，如果相等则表示token验证成功

如果token验证成功，返回*msg*参数值，表示URL验证通过。

    如果用户不想验证token，可以选择跳过MD5计算过程，直接返回msg参数值


## 数据接收

平台以HTTP POST请求形式向第三方平台URL地址推送数据，第三方平台接收到数据后需要返回 HTTP 200，否则OneNET会认为此次推送无效并重试

推送数据相关信息以JSON串的形式置于HTTP请求中的body部分，其中各个字段的含义如下

<table>
<tr><th width="15%">字段</th><th width="10%">类型</th><th>字段说明</th></tr>
<tr><td>type</td><td>int</td><td>标识消息类型<br> 1：设备上传数据点消息<br>2：设备上下线消息 <br>7：缓存命令下发后结果上报（仅支持NB设备）</td></tr>
<tr><td>dev_id</td><td>int</td><td>设备ID</td></tr>
<tr><td>ds_id</td><td>string</td><td>数据流名称</td></tr>
<tr><td>at</td><td>int</td><td>平台时间戳,单位ms</td></tr>
<tr><td>value</td><td> </td><td>具体数据部分，为设备上传至平台或触发的相关数据</td></tr>
<tr><td>status</td><td>int</td><td>设备上下线标识<br>0：设备下线<br>1：设备上线</td></tr>
<tr><td>login_type</td><td>int</td><td>设备登录协议类型<br>1-EDP, 6-MODBUS, 7-MQTT, 10-NB-IoT</td></tr>
<tr><td>cmd_type</td><td>int</td><td>命令响应的类型<br>1：设备收到cmd的ACK响应信息<br>2：设备收到cmd的Confirm响应信息</td></tr>
<tr><td>cmd_id</td><td>string</td><td>命令ID</td></tr>
<tr><td>msg_signature</td><td>string</td><td>消息摘要</td></tr>
<tr><td>nonce</td><td>string</td><td>用于计算消息摘要的随机串</td></tr>
<tr><td>enc_msg</td><td>string</td><td>加密密文消息体,对明文JSON串（msg字段）的加密</td></tr>
</table>


示例1：数据点消息
```json
{
	"msg": {
		"type": 1,
		"dev_id": 2016617,
		"ds_id": "datastream_id",
		"at": 1466133706841,
		"value": 42
	},
	"msg_signature": "message signature",
	"nonce": "abcdefgh"
}
```

示例2：批量数据点消息（需要配置数据缓存）
```json
{
	"msg": [{
			"type": 1,
			"dev_id": 2016617,
			"ds_id": "datastream_id",
			"at": 1466133706841,
			"value": 42
		},
		{
			"type": 1,
			"dev_id": 2016617,
			"ds_id": "datastream_id",
			"at": 1466133706842,
			"value": 43
		},
        ...
	],
	"msg_signature": "message signature ",
	"nonce": "abcdefgh"
}
```

示例3：设备上下线消息
```json
{
	"msg": {
		"type": 2,
		"dev_id": 2016617,
		"status": 0,
		"login_type": 1,
		"at": 1466133706841
	},
	"msg_signature": "message signature",
	"nonce": "abcdefgh"
}
```

示例4：缓存命令下发后结果上报（仅支持NB设备）
```json
{
	"msg": {
		"type": 7,
		"cmd_id": "3a351323-c4fe-5f21-9e9e-a9adc321182f",
		"imei": "865820060031939",
		"dev_id": 2016690,
		"cmd_type": 0,
		"send_time": 1466133706841,
		"send_status": 5,
		"confirm_time": 146613371921,
		"confirm_status": 0,
		"confirm_body": {
			"obj_id": 3,
			"obj_inst": [{
				"obj_inst_id": 0,
				"res": [{
						"res_inst": [{
							"val": 0,
							"res_inst_id": 0
						}],
						"res_id": 11
					},
					{
						"val": 1530496927000,
						"res_id": 13
					}
				]
			}]
		}
	},
	"msg_signature": "message signature",
	"nonce": "abcdefgh"
}
```

说明：

1. 当响应结果包含二进制数据时，是将二进制数据byte[] 转换成 ASCII 码的数组存在JSON数据中，如: [98, 105, 110, 97, 114, 121]
2. 当命令类型为READ时，confirm_body字段会携带上命令请求时候的object id以及object instance id，方便用户解析数据。

## 加密传输
用户在配置推送服务时，可配置为数据加密传输，OneNET支持AES对称加密，用户可通过页面配置密钥，并在应用端通过该密钥进行解密操作

示例：密文格式
```json
{
	"enc_msg": "XXXXXXXXXXX",
	"msg_signature": "message signature",
	"nonce": "abcdefgh"
}
```



## 服务实现建议

- OneNET平台为了保证数据不丢失，有重发机制，如果重复数据对业务有影响，数据接收端需要对重复数据进行排除重复处理
- OneNET每一次POST数据请求后，等待客户端的响应都设有时限（目前是5秒），在规定时限内没有收到响应会认为发送失败，累计失败2000次则会认为第三方服务不可用，服务将停止，所以建议第三方应用接收程序接收到数据时，**先做数据缓存，再做业务逻辑处理**
- 为保证您在使用OneNET平台的数据推送服务时，能够体验连续、稳定的服务，请将下述OneNET平台数据推送的出口IP地址添加至您应用的**IP白名单**中.

|||||||
|:- | :- | :- | :-|:-|:-|
|183.230.102.83 | 183.230.102.84 |183.230.102.85  | 183.230.102.86 |183.230.40.120|183.230.40.121|
|218.201.45.1|218.201.45.2|218.201.45.3|218.201.45.4|218.201.45.5|218.201.45.6|
