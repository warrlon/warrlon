编辑acc_psk
---

请求方式：**PUT**

URL:http://api.heclouds.com/nbiot/device/accpsk?imei=865820034287669



#### URL请求参数
参数名称 | 格式 | 是否必须 | 说明
:- | :- | :- | :- 
imei | string | 是 | URL中请求参数，值为设备的IMEI号

#### http body 请求参数
参数名称 | 格式 | 是否必须 | 说明
:- | :- | :- | :- 
key | string | 是 | 编辑连接接入机的PSK，长度8-16个字节，字母或数字组成

#### 返回参数

参数名称 | 格式 | 说明
:- | :- | :- 
errno | int | 调用错误码，为0表示调用成功
error | string | 错误描述，为"succ"表示调用成功

#### 请求示例
```text
POST http://api.heclouds.com/devices HTTP/1.1
api-key: WhI*************v1c=
Content-Type: application/json
Host: api.heclouds.com

```

#### http请求参数示例

```json
{
	"key":"dafdfdsafd" 
}
```

#### 返回示例

```json
{
	"errno": 0,
	"error": "succ"
}
```

