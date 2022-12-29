# 开发者接入

## 云边消息数据转发

启用路由实例后，系统将会向其目的地端点转发路由实例符合过滤器要求的数据。转发的最终数据为云边消息EVENT标准格式，且加密、压缩之后的数据。

## EVENT数据格式

### 数据存储格式：

- JSON
- XML
- SERIALIZED(暂时等同JSON格式）
- CSV

event JSON格式

```
{
	"id": 1,
	"eventId": "f86797d2-9366-4b26-aa02-28a4a703bf10",
	"deviceId": "10000166",
	"productId": "100036",
	"protocol": 1,
	"data":{
        "temprature" : 30
	}
	"created": 1569664351174,
}
```

data对象为键值对对象，键为属性标志，值为属性数据值。例如"data":{"temprature" : 30}表示温度为30度。

event XML格式:

```
<NewEvent>
	<ID></ID>
	<EventId>f86797d2-9366-4b26-aa02-28a4a703bf10</EventId>
	<DeviceId>10000166</DeviceId>
	<ProductId>100036</ProductId>
	<Protocol>1</Protocol>
	<Data>
        <temperature>
            30
        </temperature>
	</Data>
	<Created>1569664351174</Created>
</NewEvent>
```

&lt;Data&gt;&lt;/Data&gt;节点中包含属性数据。子节点为属性标志，节点值为数据值。例如 &lt;temprature&gt;30&lt;/temprature&gt;表示温度为30度。

event CSV格式:

```
ID,EventId,DeviceId,ProductId,Protocol,Data,Created
-----------------------------------------------------------
1,f86797d2-9366-4b26-aa02-28a4a703bf10,10000166,100036,1,cpu.used,0.015,1569664351174
```

Data对应的数据为“cpu.used，0.015”表示cpu.used属性值为0.015。

### MySQL转发 EVENT 数据结构

MySQL形式数据转发与REST,MQTT,KAFKA其他类型不一致，数据结构以表形式存于数据库表中。结构如下：

| 名称        | 数据类型     | 描述                                |
| ----------- | ------------ | ----------------------------------- |
| id          | INT(11)      | 记录ID                              |
| event_id    | VARCHAR(60)  | 数据原始ID                          |
| product_id  | VARCHAR(60)  | 产品ID                              |
| device_id   | VARCHAR(60)  | 设备ID                              |
| protocol    | INT(11)      | 数据产品协议                        |
| data_string | VARCHAR(128) | 设备属性数据，值为属性标志-值键值对 |
| created     | BIGINT(20)   | 数据产生时间                        |

其中data_string为属性键值对json格式，例如{ "temperature" : 30}

## 加密数据

加密方式暂时只支持AES-128加密,设置AES加密参数后，系统会对event数据进行相应参数加密后转发。

注：加密后的event数据会进行一次base64加密后再进行转发。开发者如需要对数据解密，首先需要将得到的数据依次进行base64解密和AES解密。

## 压缩数据

压缩数据方式暂只支持gzip和zip加密，选择相应压缩方式后，系统将对数据（加密后的数据）进行压缩后再进行转发。
