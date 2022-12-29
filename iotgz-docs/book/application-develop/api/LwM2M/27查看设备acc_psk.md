查看设备acc_psk
---

请求方式：**GET**

URL: http://api.heclouds.com/nbiot/device/accpsk?imei=865820034287669


#### URL请求参数
参数名称 | 格式 | 是否必须 | 说明
:- | :- | :- | :- 
imei | string | 是 | URL中请求参数，值为设备的IMEI号

#### 返回参数

参数名称 | 格式 | 说明
:- | :- | :- 
errno | int | 调用错误码，为0表示调用成功
error | string | 错误描述，为"succ"表示调用成功
data | json | 接口调用成功之后返回的设备相关信息，见data描述表

##### data描述表

参数名称 | 格式 | 说明
:- | :- | :- 
device_id | string | 平台分配唯一ID
psk | string | 设备连接接入机的psk，在NB协议开启DTLS加密功能时返回该字段，其他情况没有该字段


#### 请求示例
```text
POST http://api.heclouds.com/devices HTTP/1.1
api-key: WhI*************v1c=
Content-Type: application/json
Host: api.heclouds.com

```

#### 返回示例

```json
{
	"errno": 0,
	"error": "succ",
	"data": {
		"psk":"23ddafd3444"
	}
}
```

