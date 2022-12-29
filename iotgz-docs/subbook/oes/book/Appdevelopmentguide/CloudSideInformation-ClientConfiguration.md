# 客户端配置

## 新增消息路由

功能描述：新建一个消息路由，返回该路由的id。

```
POST  /api/v1/routers
```

**Body:**

| Name        | Type     | Description                                             | Required |
| ----------- | -------- | ------------------------------------------------------- | -------- |
| name        | string   | 客户端名称                                               | Yes      |
| env | int   | 任务类型边缘端或者云端（1:cloud / 2:edge）                            | Yes |
| type | int  | 客户端类型 (1:STANDARD/ 2:RULEENGINE/ 3:DATAANALYZE) | Yes |
| addressType | int | 转发方式（1:REST / 2:MQTT / 3:KAFKA / 4:MYSQL / 5:云平台，当env为边缘端时可选）| Yes |
| addressConfigId | int | 目的地配置id, 当转发方式为云平台时不填，其他转发方式必填，参考 **目的地配置** | No |
| format | int | 数据格式（目前支持 1:JSON / 2:XML/ 3:SERIALIZED / 4:CSV） | Yes |
| encryption  | struct   | 加密规则结构体，详情见下方sheet（当addressType为4:MYSQL时，不填）                         | No       |
| compression | int   | 数据压缩方式，（1：NONE / 2:GZIP / 3:ZIP）, NONE表示不压缩。 | Yes     |
| filter | struct | 过滤器结构体，只支持type为STANDARD的类型。 | No, type为STANDARD时必须。 |


Body   filter结构体:

| Name      | Type   | Description                           | Required   |
| --------- | ------ | ------------------------------------- | ---------- |
| devIdentifiers   | []struct | 过滤规则结构体 | Yes        |

Body   devIdentifiers结构体（数组结构）:

| Name                       | Type     | Description                        | Required                         |
| -------------------------- | -------- | ---------------------------------- | -------------------------------- |
| pid               | string | 产品ID的字符串                       | Yes                               |
| deviceId          | string | 设备ID字符串                         | No（无该字段，则默认为全部设备）  |
| valueDescriptorIdentifiers | []string | 需过滤的属性（必须首先设置设备ID） | No（设备ID填写时必填，且限制为5个） |

Body encryption结构体：

| Name                | Type   | Description               | Required |
| ------------------- | ------ | ------------------------- | -------- |
| encryptionAlgorithm | int | 加密方式(1:NONE / 2:AES), 目前只支持AES, NONE表示不加密。 | Yes       |
| encryptionKey       | string | AES加密Key                | Yes，AES加密时必须 |
| initializingVector  | string | 初始化向量                | No       |

body example：

```
{
    "name":"test_router_01",
    "env":1,
    "type":1,
    "addressType":1,
    "addressConfigId":10112,
    "format":1,
    "encryption":{
    	"encryptionAlgorithm":2,
    	"encryptionKey":"123456",
    	"initializingVector":"23"
    },
   "compression":1,
   "filter": {
		"devIdentifiers": [{
			"pid": "100140",
			"deviceId":"10000237",
			"valueDescriptorIdentifiers": ["string", "int64"]
		}]
	}

}
```

**Responses:**

```
{
  "success": true,
  "code": 0,
  "msg": "",
  "data": 10108
}
```

***



## 获取消息路由

功能描述：查询消息路由， 返回该消路由的详细信息。

```
GET  /api/v1/routers/{id}
```

**Responses:**

```
{
  "success": true,
  "code": 0,
  "msg": "",
  "data": {
    "id": 10108,
    "name": "test_router_01",
    "env": 1,
    "platform": 1,
    "type": 1,
    "format": 1,
    "compression": 1,
    "addressType": 1,
    "addressConfigId": 10112,
    "encryption": {
      "encryptionAlgorithm": 2,
      "encryptionKey": "123456",
      "initializingVector": "23"
    },
    "filter": {
      "devIdentifiers": [
        {
          "deviceId": "10000237",
          "pid": "100140",
          "valueDescriptorIdentifiers": [
            "string",
            "int64"
          ]
        }
      ]
    },
     "status": 1
    "created": 1566789708827,
    "modified": 1566801455047
  }
}
```

***



## 修改消息路由

功能描述：修改指定的消息路由。

```
PUT  /api/v1/routers/{id}
```

**Body:**

| Name        | Type     | Description                                             | Required |
| ----------- | -------- | ------------------------------------------------------- | -------- |
| name        | string   | 客户端名称                                              | No     |
| type | int | 客户端类型 (1:STANDARD/ 2:RULEENGINE/ 3:DATAANALYZE) | No |
| addressConfigId | int | 目的地配置id, 参考 **目的地配置** | No |
| format | string | 数据格式（目前支持 1:JSON / 2:XML/ 3:SERIALIZED / 4:CSV） | No |
| encryption  | struct   | 加密规则结构体，详情见下方sheet                         | No       |
| compression | int   | 数据压缩方式，（1：NONE / 2:GZIP / 3:ZIP）, NONE表示不压缩。 | No    |
| filter | struct | 过滤器结构体，只支持type为STANDARD的类型。 | No |

Body   filter结构体:

| Name      | Type   | Description                           | Required   |
| --------- | ------ | ------------------------------------- | ---------- |
| devIdentifiers   | []struct | 过滤规则结构体 | Yes        |

Body   devIdentifiers结构体（数组结构）:

| Name                       | Type     | Description                        | Required                         |
| -------------------------- | -------- | ---------------------------------- | -------------------------------- |
| pid               | string | 产品ID的字符串                       | Yes                               |
| deviceId          | string | 设备ID字符串                         | No（无该字段，则默认为全部设备）  |
| valueDescriptorIdentifiers | []string | 需过滤的属性（必须首先设置设备ID） | No（设备ID填写时必填，且限制为5个） |

Body encryption结构体：

| Name                | Type   | Description               | Required |
| ------------------- | ------ | ------------------------- | -------- |
| encryptionAlgorithm | int | 加密方式(1:NONE / 2:AES), 目前只支持AES, NONE表示不加密。 | Yes       |
| encryptionKey       | string | AES加密Key                | Yes，AES加密时必须 |
| initializingVector  | string | 初始化向量                | No       |

body example：

```
{
    "name":"test_router_01u",
    "type":1,
    "format":1,
    "encryption":{
    	"encryptionAlgorithm":2,
    	"encryptionKey":"123456",
    	"initializingVector":"23"
    },
   "compression":1,
   "filter": {
		"devIdentifiers": [{
			"pid": "100140",
			"deviceId":"10000237",
			"valueDescriptorIdentifiers": ["string", "int64"]
		}]
	}

}}
```




**Responses:**

```
{
  "success": true,
  "code": 0,
  "msg": "",
  "data": 10108
}
```



---



## 删除消息路由

功能描述：删除指定的客户端。

```
DELETE  /api/v1/routers/{id}
```

**Responses:**

```
{
  "success": true,
  "code": 0,
  "msg": "",
  "data": null
}
```



***

## 分页查询消息路由

功能描述：根据名称模糊查询消息路由，指定当前分页和分页大小，返回 客户端列表和数量。

```
GET  /api/v1/routers
```

**Query:**

| Name           | Description              | Required | Type   | marks                                   |
| -------------- | ------------------------ | -------- | ------ | --------------------------------------- |
| type           | 客户端类型               | No       | int    | 1:STANDARD/ 2:RULEENGINE/ 3:DATAANALYZE |
| pageSize       | 分页大小                 | Yes      | int    |                                         |
| currentPage    | 页码                     | Yes      | int    |                                         |
| name           | 客户端名字 非必填        | No       | string |                                         |
| address        | 目的地配置名称           | No       | String |                                         |

**Responses:**

```
{
    "data": {
        "currentPage": 1,
        "pageSize": 5,
        "totalCount": 1,
        "totalPage": 1,
        "content": [
            {
                "id": 10454,
                "addressConfigId": 13599,
                "addressConfigName": "mysql1",
                "addressType": 4,
                "compression": 1,
                "created": 1581572914394,
                "encryption": {
                    "encryptionAlgorithm": 1,
                    "encryptionKey": null,
                    "initializingVector": null
                },
                "env": 1,
                "filter": {
                    "devIdentifiers": null
                },
                "format": 1,
                "modified": 1581572914394,
                "name": "luyou4",
                "type": 3,
                "userId": "38869",
                "status": 1,
                "platform": 1,
                "ownerName": null
            }
        ]
    },
    "success": true,
    "code": 0,
    "msg": null
}
```
***



##  启用云端的消息路由

功能描述：启用指定的云端的消息路由，消息路由启用后才能实现数据转发。

```
PUT  /api/v1/routers/{id}/enable
```

**Responses:**

```
{
  "success": true,
  "code": 0,
  "msg": "",
  "data": 10108
}
```



## 禁用云端的消息路由

功能描述：禁用指定的云端的消息路由。

```
PUT  /api/v1/routers/{id}/disable
```
**Path:**

| Name           | Description | Required | Type   |
| :------------- | :---------- | :------- | :----- |
| id | 客户端ID    | Yes      | int |

**Responses:**

```
{
  "success": true,
  "code": 0,
  "msg": "",
  "data": 10108
}
```
##  批量启用云端的消息路由

功能描述：批量启用指定的云端的消息路由，消息路由启用后才能实现数据转发。

```
PUT  /api/v1/routers/enable
```
**Body:**
| Name | Type  | Description      | Required |
| ---- | ----- | ---------------- | -------- |
| list | int[] | 消息路由的id数组 | Yes      |

**Request Body Example:**
```
{
  "list": [1001,1002]
}
```
**Responses:**

```
{
  "success": true,
  "code": 0,
  "msg": "成功",
  "data": null
}
```



## 批量禁用云端的消息路由

功能描述：批量禁用指定的云端的消息路由。

```
PUT  /api/v1/routers/disable
```
**Body:**
| Name | Type  | Description      | Required |
| ---- | ----- | ---------------- | -------- |
| list | int[] | 消息路由的id数组 | Yes      |

**Request Body Example:**
```
{
  "list": [1001,1002]
}
```

**Responses:**

```
{
  "success": true,
  "code": 0,
  "msg": "成功",
  "data": null
}
```
