# MQTTs一期需求设计文档

## 1、MQTTs鉴权

### 1.1 Connect报文格式

| 序号 | 字段名称                | 参数名称         | 说明                                                         |
| ---- | ----------------------- | ---------------- | ------------------------------------------------------------ |
| 1    | ClientId                | 客户端Id         | 设备的名称(authinfo，产品下唯一，不为空)                     |
| 2    | UserName                | 用户名           | 设备所属产品id，不为空                                       |
| 3    | Password                | 密码             | 根据AccessKey计算出的sas token，不为空                       |
| 4    | Connect Flag            | 连接标志位       | 必须为0xC2(即username、password、cleansession为1，其余字段必须全部为0) |
| 5    | Protocol Name           | 协议名称         | Connect报文中协议名称必须为MQTT                              |
| 6    | Protocol Version        | 协议版本         | Connect报文中协议版本必须为4                                 |
| 7    | FixHeader Reserved bits | 固定头中保留字段 | Connect固定头必须为0x10(即FixHeader第一字节的保留的低4位必须全部为0) |
| 8    | Will                    | 遗嘱消息         | 不允许带有will topic及will msg字段                           |
| 9    | KeepAlive               | 保活字段         | 范围为：[10,1800]                                            |

### 1.2 Sas Token

####  token构成

| 参数名称      | 类型   |  含义  |  示例 | 是否必填 |
| --------     | :-----:  | :----  | :----  | :---- |
| version | string |   当前token参数组的版本号(日期格式)   |  2018-10-10  |  是 |
|  res  | string  | resourceName资源名称<br>products/<product_id>/devices/<authinfo> |  products/123123/devices/authinfo | 是 |
| et | string |   expirationTime过期时间，unix时间<br>注：距离1970年1月1日 00:00:00(UTC)的秒数   |  1537255523<br>表示:2018-09-18 15:25:23 |  是 |
| method | string |   signatureMethod   |  sha1  |  是 |
| sign | string |   signature签名结果字符串   |    |  是 |

####  sign(签名结果字符串)

- 仅参数内容参与计算，且参与计算的参数顺序按照参数名称字符串排序，当前版本中按照如下顺序进行排序：et、method、res、version

- 生成方式为base64(hmac_\<method\>(AccessKey,(et + "\n" + method + "\n" + res+ "\n" + version)))

- 示例: et=1537255523,method=sha1,res=products/123123/devices/authinfo,version=2018-10-31

- 签名生成算法为base64(hmac_sha1("1537255523" + "\n" + "sha1"+ "\n" + "products/123123/devices/authinfo"+ "\n" + "2018-10-31"))
- 参与hmac计算的key为新增的产品级的key，使用产品级access key时，resourceName资源名称必须包含products/<product_id>

####  参数编码

​	token中key=value的形式的value部分需要经过**URL编码**，需要进行编码的特殊符号如下：

| 序号 | 符号 | 编码 |
| ---- | ---- | ---- |
| 1    | +    | %2B  |
| 2    | 空格 | %20  |
| 3    | /    | %2F  |
| 4    | ?    | %3F  |
| 5    | %    | %25  |
| 6    | #    | %23  |
| 7    | &    | %26  |
| 8    | =    | %3D  |



### 1.3 鉴权流程

- 解析Connect报文，若报文不符合MQTT协议规范或不符合平台要求则回复响应ConnAck或直接断开连接
- 调用鉴权服务鉴权
- 若鉴权失败则回复ret_code=4，sp_flag=0的ConnAck
- 若鉴权成功，根据设备id查找本地session是否已存在，若不存在则调用设备在线状态服务上线该设备
- 若已存在本地session，则断开前一个session，再调用设备在线状态服务上线该设备
- 判断设备在线状态服务返回的svrtoken与本地不一致则为重复登录，发送重复登录消息到router以便通知到其他acc断开前一个设备的连接
- 创建设备关联session，回复设备ret_code=0，sp_flag=0的ConnAck并开始KeepAlive计时

### 1.4 其他说明

- 同一设备同一时刻只允许有一个TCP连接登录
- 若有多个使用相同鉴权信息的设备登录，只保留最后一个(踢掉前一个TCP连接)
- 只允许MQTTS协议设备接入MQTTS服务

## 2、通用限制

### 2.1 频率限制

| 所属MQTT报文 | 字段名称 | value | 描述                      | 动作                   |
| ------------ | :------- | :---- | :------------------------ | :--------------------- |
| connect      | -        | 10    | 5s内登录超过10次          | 断开连接并设备禁用5min |
| publish      | qos0     | 300   | 5s内发布qos0消息超过300次 | 断开连接并设备禁用5min |
| publish      | qos1     | 100   | 5s内发布qos1消息超过100次 | 断开连接并设备禁用5min |
| unsubscribe  | -        | 10    | 5s内取消订阅超过10次      | 断开连接并设备禁用5min |
| ping         | -        | 10    | 5s内发送ping报文超过10次  | 断开连接并设备禁用5min |

subscribe报文特殊限制

- 普通(父)设备订阅自身(以$sys)的topic及所有订阅失败的topic(用户自定义、非法子设备相关topic)频率限制为15 topics/5s

- 订阅子设备topic成功的计入子设备订阅频率限制中(15 topics/5s)

- 父设备订阅的业务topic不超过15个(可重复订阅已订阅过的topic)

- 订阅子设备的业务topic不超过15个(除子设备login、logout这一类topic，$subdev/{pid}/{device-name}/#计入业务topic)

- 父设备最多允许登录50个子设备(包括未订阅login响应直接登录子设备)

- 父设备最多允许订阅50 - 未订阅login直接登录的子设备数量的login、#

​	常见案例：

​			1.如父设备订阅了50个子设备的login或#，则不能再订阅其余子设备的login或者#

​			2.如父设备在未订阅子设备login直接登录子设备的个数为10，那么后续最多再订阅其余40（50 -10）个子设备的login或者#

​			3.若父设备未订阅子设备login直接登录50个子设备，则不允许订阅其余任何子设备的login或#

- 父设备最多允许登录50个子设备

- 父设备最多允许订阅子设备login、logout这一类topic的4个，例：

  ​	1.login 的topic可以为：

  - $subdev/{pid}/{device-name}/login/+

  - $subdev/{pid}/{device-name}/login/#


  - $subdev/{pid}/{device-name}/login/accepted


  - $subdev/{pid}/{device-name}/login/rejected，共计4个

    

  ​	2.logout 的topic可以为：

  - $subdev/{pid}/{device-name}/logout/+

  - $subdev/{pid}/{device-name}/logout/#


  - $subdev/{pid}/{device-name}/logout/accepted


  - $subdev/{pid}/{device-name}/logout/notify，共计4个


  注：

  ​		1.超过最大topic订阅数后会订阅失败

  ​		2.超过频率限制后会被踢下线并禁止登录5min

### 2.2 MQTT协议限制

| 所属MQTT报文 | 字段名称                          | value                        | 描述                                                         | 动作     |
| ------------ | :-------------------------------- | :--------------------------- | :----------------------------------------------------------- | :------- |
| connect      | keepalive                         | [10,1800]                    | 设备设置的keepalive必须在该范围内                            | 断开连接 |
| connect      | will相关字段                      | 必须全部为0                  | will相关的qos、retain、topic、msg都必须为0或空               | 断开连接 |
| connect      | cleansession                      | 1                            | 设备设置的cleansession必须为1                                | 断开连接 |
| connect      | all                               | null                         | 不允许设备重复发送connect报文                                | 断开连接 |
| connect      | clientid、username、protocol name | 必须为UTF8编码的string       | 必须为UTF8编码的string                                       | 断开连接 |
| connect      | clientid、username、password      | not null                     | 这3个字段必须都填写，username、password flag必须为1          | 断开连接 |
| connect      | username                          | 必须为数值                   | 该字段为产品id，必须为数值的字符串表示                       | 断开连接 |
| connect      | fixheader                         | 0x10                         | connect报文第一字节必须为0x10                                | 断开连接 |
| publish      | payload                           | 256KB                        | payload长度不超过256KB                                       | 断开连接 |
| publish      | qos                               | 只能为0,1                    | publish报文不支持Qos2                                        | 断开连接 |
| publish      | topic                             | 8                            | topic层级最大支持8级,即最多允许7个/                          | 断开连接 |
| publish      | topic                             | UTF-8字符串                  | topic只能为UTF-8编码的字符串                                 | 断开连接 |
| publish      | topic                             | ^[a-zA-Z0-9\/\_-]+$          | topic只能为字母、数字、短横线、下划线、反斜杠（不允许为空）  | 断开连接 |
| publish      | retain flag                       | 0                            | retain标记只允许为0                                          | 断开连接 |
| publish      | dup flag                          | Qos=0时，Dup不能为1          | Qos=0时，Dup不能为1                                          | 断开连接 |
| puback       | all                               | null                         | 1.不允许设备不按照服务器推送的顺序回复PubAck<br>2.不允许设备随意回复不存在的PubAck packetid | 断开连接 |
| pubrec       | all                               | null                         | 不支持该报文                                                 | 断开连接 |
| pubrel       | all                               | null                         | 不支持该报文                                                 | 断开连接 |
| pubcomp      | all                               | null                         | 不支持该报文                                                 | 断开连接 |
| subscribe    | topic                             | 512Bytes                     | topic长度不能超过512字节                                     | 断开连接 |
| subscribe    | topic                             | 8                            | topic层级最大支持8级,即最多允许7个/                          | 断开连接 |
| subscribe    | topic                             | UTF-8字符串                  | topic只能为UTF-8编码的字符串                                 | 断开连接 |
| subscribe    | topic                             | ^[a-zA-Z0-9\/\+\#\_-]+$      | topic只能为字母、数字、短横线、下划线、反斜杠、+、#          | 断开连接 |
| subscribe    | topic                             | 8                            | 一个subscribe报文最多允许订阅8个topic                        | 断开连接 |
| subscribe    | request_qos                       | 可以为0,1,2                  | 允许客户端的request_qos=2，但服务端授予的granted_qos最大为0  | 正常     |
| unsubscribe  | topic                             | 512Bytes                     | topic长度不能超过512字节                                     | 断开连接 |
| unsubscribe  | topic                             | 8                            | topic层级最大支持5级,即最多允许7个/                          | 断开连接 |
| unsubscribe  | topic                             | UTF-8字符串                  | topic只能为UTF-8编码的字符串                                 | 断开连接 |
| unsubscribe  | topic                             | ^[a-zA-Z0-9\/\+\#\_]+$       | topic只能为字母、数字、短横线、下划线、反斜杠、+、#          | 断开连接 |
| unsubscribe  | topic                             | 8                            | 一个unsubscribe报文最多允许取消订阅8个topic                  | 断开连接 |
| connAck      | all                               | 不允许客户端发送connAck报文  | 不允许客户端发送connAck报文                                  | 断开连接 |
| subAck       | all                               | 不允许客户端发送subAck报文   | 不允许客户端发送subAck报文                                   | 断开连接 |
| unsubAck     | all                               | 不允许客户端发送unsubAck报文 | 不允许客户端发送unsubAck报文                                 | 断开连接 |
| pingrsp      | all                               | 不允许客户端发送pingrsp报文  | 不允许客户端发送pingrsp报文                                  | 断开连接 |

### 2.3 全局Topic簇定义

#### 2.3.1 普通设备

|系统topic|方向|QoS|用途|可订阅|可发布|
|:-|:-|:-|:-|:-|--|
|$sys/{pid}/{device-name}/dp/post/json|client->server|0/1|设备上传数据||√|
|$sys/{pid}/{device-name}/dp/post/json/accepted|server->client|0|系统回复"上传数据成功"|√||
|$sys/{pid}/{device-name}/dp/post/json/rejected|server->client|0|系统回复"上传数据失败"|√||
|$sys/{pid}/{device-name}/cmd/request/{cmdId}|server->client|0|系统下发命令到设备|√||
|$sys/{pid}/{device-name}/cmd/response/{cmdId}|client->server|0/1|设备回复命令响应||√|
|$sys/{pid}/{device-name}/cmd/response/{cmdId}/accepted|server->client|0|系统回复"命令回复成功"|√||
|$sys/{pid}/{device-name}/cmd/response/{cmdId}/rejected|server->client|0|系统回复"命令回复失败"|√||
|$sys/{pid}/{device-name}/image/update|client->server|0/1|更新设备镜像||√|
|$sys/{pid}/{device-name}/image/update/accepted|server->client|0|系统回复“更新设备镜像成功”|√||
|$sys/{pid}/{device-name}/image/update/rejected|server->client|0|系统回复“更新设备镜像失败”|√||
|$sys/{pid}/{device-name}/image/get|client->server|0/1|获取设备镜像||√|
|$sys/{pid}/{device-name}/image/get/accepted|server->client|0|系统回复“获取设备镜像成功”|√||
|$sys/{pid}/{device-name}/image/get/rejected|server->client|0|系统回复“获取设备镜像失败”|√||
|$sys/{pid}/{device-name}/image/delta|server->client|0|推送delta消息给设备|√||
|$sys/{pid}/{device-name}/thing/tlv/up|client->server|0/1|上传tlv格式的物模型数据||√|
|$sys/{pid}/{device-name}/thing/tlv/up/accepted|server->client|0|系统回复"tlv格式数据上传成功"|√||
|$sys/{pid}/{device-name}/thing/tlv/up/rejected|server->client|0|系统回复"tlv格式数据上传失败"|√||
|$sys/{pid}/{device-name}/thing/tlv/down/{cmdId}|server->client|0|系统发送tlv格式的物模型数据到设备|√||
|$sys/{pid}/{device-name}/thing/tlv/down_reply/{cmdId}|client->server|0/1|设备回复tlv格式的物模型的下行数据||√|
|$sys/{pid}/{device-name}/thing/tlv/down_reply/{cmdId}/accepted|server->client|0|系统回复"设备回复tlv格式的物模型的下行数据"成功|√||
|$sys/{pid}/{device-name}/thing/tlv/down_reply/{cmdId}/rejected|server->client|0|系统回复"设备回复tlv格式的物模型的下行数据"失败|√||
|$sys/{pid}/{device-name}/thing/json/up|client->server|0/1|上传json格式的物模型数据||√|
|$sys/{pid}/{device-name}/thing/json/up/accepted|server->client|0|系统回复"json格式数据上传成功"|√||
|$sys/{pid}/{device-name}/thing/json/up/rejected|server->client|0|系统回复"json格式数据上传失败"|√||
|$sys/{pid}/{device-name}/thing/json/down/{cmdId}|server->client|0|系统发送json格式的物模型数据到设备|√||
|$sys/{pid}/{device-name}/thing/json/down_reply/{cmdId}|client->server|0/1|设备回复json格式的物模型的下行数据||√|
|$sys/{pid}/{device-name}/thing/json/down_reply/{cmdId}/accepted|server->client|0|系统回复"设备回复tlv格式的物模型的下行数据"成功|√||
|$sys/{pid}/{device-name}/thing/json/down_reply/{cmdId}/rejected|server->client|0|系统回复"设备回复tlv格式的物模型的下行数据"失败|√||

#### 2.3.1 子设备

|系统topic|方向|QoS|用途|可订阅|可发布|备注|
|:-|:-|:-|:-|:-|--|--|
|$subdev/{pid}/{device-name}/dp/post/json|client->server|0/1|设备上传数据||√||
|$subdev/{pid}/{device-name}/dp/post/json/accepted|server->client|0|系统回复"上传数据成功"|√|||
|$subdev/{pid}/{device-name}/dp/post/json/rejected|server->client|0|系统回复"上传数据失败"|√|||
|$subdev/{pid}/{device-name}/cmd/request/{cmdId}|server->client|0|系统下发命令到设备|√|||
|$subdev/{pid}/{device-name}/cmd/response/{cmdId}|client->server|0/1|设备回复命令响应||√||
|$subdev/{pid}/{device-name}/cmd/response/{cmdId}/accepted|server->client|0|系统回复"命令回复成功"|√|||
|$subdev/{pid}/{device-name}/cmd/response/{cmdId}/rejected|server->client|0|系统回复"命令回复失败"|√|||
|$subdev/{pid}/{device-name}/login|client->server|0/1|子设备登录||√|payload须为空|
|$subdev/{pid}/{device-name}/login/accepted|client->server|0|子设备登录成功响应|√|||
|$subdev/{pid}/{device-name}/login/rejected|server->client|0|子设备登录失败响应|√|||
|$subdev/{pid}/{device-name}/logout|server->client|0/1|子设备登出||√|payload须为空|
|$subdev/{pid}/{device-name}/logout/accepted|server->client|0|子设备登出成功响应|√|||
|$subdev/{pid}/{device-name}/logout/rejected|server->client|0|子设备登出失败响应|√|||
|$subdev/{pid}/{device-name}/logout/notify|server->client|0|服务端主动登出子设备|√|||
注：目前子设备不支持image、thing相关的topic簇

## 3 业务处理

### 3.1 数据点上传 

#### 3.1.1 topic：

​		普通(父)设备：$sys/{pid}/{device-name}/dp/post/json

​		子设备：           $subdev/{pid}/{device-name}/dp/post/json

#### 3.1.2 payload

目前版本中数据点上传payload只能为json格式，格式示例如下：

```json
{
	"id": 123, //必填项，用户自定义的id,用于消息区分，不小于0的int类型
	"dp": {	   //必填项类容只能为json
		"color": [{					//具体的数据流名称，值只能为jsonArry
				"t": 1231230821,	//可选
				"v": "blue"			//必填，数据点的值，可以是int float和String和json
			},
			{
				"v": "red"
			}
		],

		"temp": [{
				"t": 1231230821,
				"v": 31
			},
			{
				"v": 32
			},
			{
				"v": 34
			}
		]
	}
}
```

​	注：

- 目前dsId长度限制为不超过30字节，dsId只能由字母、数字、下划线、.号及$符号组成，其中$符号若存在则$只能位于dsId的首字节且只允许出现一次
- 若上传数据点v字段对应的value为json数据时，json层级不能超过5级且该json中的key长度限制不超过30字节，且只能由字母、数字、下划线、.号组成

#### 3.1.3 响应

1、数据点上传成功的payload为json。  

```json
{
      "id":123 	//用户上传数据点是自定义的id。
}
```
2、数据点上传失败的payload为json格式如下：

```json
{
      "id":123， //用户上传数据点是自定义的id，-1表示用户未上传id。
      "err_code": 98,
      "err_msg":"illegal data"
}
```

错误码及错误信息定义如下表所示：

| 序号 | 错误码 | 错误说明     | 备注     |
| ---- | ------ | ------------ | -------- |
| 1    | 0x62   | illegal data | 非法数据 |

#### 3.1.4 数据点上传流程

- 收到设备Publish报文
- 校验该设备是否已登录且校验topic中的pid+authinfo是否与session中的数据一致，否则断开连接
- 解析该Publish报文，若不符合平台规范(不支持的$sys开头的系统topic或为用户自定义topic等)或不符合MQTT协议规范，则断开连接
- 解析Publish报文Payload内容，若解析成功则发送至kafka
- 匹配该设备的订阅，若订阅存在则回复该设备$sys/{pid}/{device-name}/dp/post/json/accepted该数据点已接收，否则忽略
- 若解析Payload失败则匹配该设备的订阅，若订阅存在则回复该设备$sys/{pid}/{device-name}/dp/post/json/rejected该数据点被拒绝，错误码及错误Msg以json形式存入Payload中,否则忽略。

说明：设备只能上传数据到自身相关的topic。

### 3.2 命令

#### 3.2.1 命令下发

​	topic:

​	普通(父)设备：$sys/{pid}/{device-name}/cmd/request/{cmdId}

​		   子设备：$subdev/{pid}/{device-name}/cmd/request/{cmdId}

​	payload:

​		用户自定义数据(目前设备命令下发内容长度不能超过20KB)

#### 3.2.2 命令回复

​	topic:

​	普通(父)设备：$sys/{pid}/{device-name}/cmd/response/{cmdId}

​		   子设备：$subdev/{pid}/{device-name}/cmd/response/{cmdId}

​	payload:

​		用户自定义数据(目前设备命令回复内容长度不能超过1KB)

#### 3.2.3 平台回复 “设备命令响应”

- 设备命令回复成功的payload为空。  

- 设备命令回复失败的payload为json格式如下：

```json
{
      "err_code": 99,
      "err_msg":"maximum payload size exceeded"
}
```

错误码及错误信息定义如下表所示：

| 序号 | 错误码 | 错误说明                      | 备注                                                     |
| ---- | ------ | ----------------------------- | -------------------------------------------------------- |
| 1    | 0x63   | maximum payload size exceeded | 设备回复的命令响应超过限制                               |
| 2    | 0x64   | internal error                | 服务器内部错误                                           |
| 3    | 0x70   | cmd response timeout          | 设备在超时时间后回复命令                                 |
| 4    | 0x71   | cmd id not found              | 未找到对应的cmdId(cmdId错误或者是因为超时已移除该命令)||


### 3.3 Image

#### 3.3.1 更新镜像

​	topic：$sys/{pid}/{device-name}/image/update

​	payload: 符合要求的json格式数据(可参照Image服务需求说明文档)

#### 3.3.2 获取镜像

​	topic：$sys/{pid}/{device-name}/image/get

​	payload: 目前必须为空

#### 3.3.3 获取delta消息

- 在image/update时可能会触发delta消息(详见Image服务需求说明文档)
- 应用层API修改了镜像时可能会触发delta消息(详见Image服务需求说明文档)

#### 3.3.4 Image相关的错误码

错误码及错误信息定义如下表所示：

| 序号 | 错误码 | 错误说明                          | 备注                                     |
| ---- | ------ | --------------------------------- | ---------------------------------------- |
| 1    | 0x96   | message rate too high             | 更新设备镜像频率过快                     |
| 2    | 0xA0   | illegal json                      | 非法json字符串                           |
| 3    | 0xA1   | json out of bound                 | json数据过长                             |
| 4    | 0xA2   | json depth out of bounds          | json数据嵌套层级太深                     |
| 5    | 0xA3   | state key not found               | state字段不存在                          |
| 6    | 0xA4   | desired or reported key not found | desired或reported字段不存在              |
| 7    | 0xA5   | invalid parameters                | 非法参数                                 |
| 8    | 0xA6   | device image existed              | 镜像已存在                               |
| 9    | 0xA7   | device image not exists           | 镜像不存在                               |
| 10   | 0x62   | illegal data                      | 非法数据(如image/get时带有非空的payload) |
| 11   | 0x64   | internal error                    | 内部错误                                 |

注：子设备相关业务处理见subdev-design文档

## 4 topic订阅 

- 只有订阅了对应的topic才能收到平台的回复
- 设备只能订阅跟自身相关的topic。
- granted Qos最大为0
