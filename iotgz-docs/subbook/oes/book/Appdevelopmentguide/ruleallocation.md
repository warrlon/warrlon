# 场景联动管理

### 解除分配的规则
功能描述：提供解除已分配的规则的功能

```
POST  /api/v1/rules/gateway/deallocate
```

**Body:**

| Name           | Type     | Description                                  | Required                                                    |
| -------------- | -------- | -------------------------------------------- | ---------|
| ruleId         | string   | 规则名                                        | Yes      |
| productId      | string   | 产品ID                                        | Yes      |
| gatewayId      | string   | 网关ID                                        | Yes      |

body example:

```
{
	"ruleId":"5d65056cf953620006dbefc2",
	"productId":"1000056",
	"gatewayId":"1000056"
} 
```

**Responses:**

```
{
  "success": true,
  "code": 0,
  "msg": "",
  "data": 
}
```



---



### 批量分配规则到网关

功能描述：批量分配规则到网关的功能。

```
POST  /api/v1/rules/gateway/allocate/multi
```

**Body:**

| Name           | Type     | Description                                  | Required  |
| -------------- | -------- | -------------------------------------------- | --------- |
| ruleIdList     | []string | 规则名列表                                    | Yes       |
| productId      | int      | 产品ID                                        | Yes      |
| gatewayId      | int      | 网关ID                                        | Yes      |
| allocatedTime  | long     | 分配时间                                      | No        |


body example:

```
{
	"ruleIdList":[],
	"productId":10112,
	"gatewayId":"10000082",
	"allocatedTime":"20191227110701"
} 
```

**Responses:**

```
{
  "success": true,
  "code": 0,
  "msg": ""
}
```

------



### 分页查询已分配规则

功能描述：分页查询已分配规则的功能.

```
POST  /api/v1/rules/gateway/allocated
```
**Query:**

| Name           | Description              | Required | Type   | marks                           |
| -------------- | ------------------------ | -------- | ------ | ------------------------------- |
| accessKeyId    | 用户访问服务所用的密钥ID | Yes      | string | 系统生成，在生成用户时获取      |
| signature      | 签名结果串               | Yes      | string | 不校验，备用字段                |
| signatureNonce | 签名随机数               | Yes      | int    | 1小时内，同一用户需使用不同数字 |

**Body:**

| Name           | Type     | Description                                  | Required  |
| -------------- | -------- | -------------------------------------------- | --------- |
| currentPage    | int      | 当前页码                                      | Yes       |
| pageSize       | int      | 页码大小                                      | Yes      |
| filter         | struct   | 筛选条件                                      | Yes      |

body filter:

| Name      | Type   | Description    | Required |
| --------- | ------ | -------------- | -------- |
| name      | string | 规则引擎的名称 | No       |
| gatewayId | int    | 网关ID         | Yes      |

body example:

```
{
	"currentPage":1,
	"pageSize":100,
	"filter": {
            "name":"test",
        	"gatewayId": 10000080
     }
} 
```

**Responses:**

```
{
  "success": true,
  "code": 0,
  "msg": "",
  "data": {
    "currentPage": 1,
    "pageSize": 10,
    "totalCount": 1,
    "totalPage": 1,
    "content": [
      {
        "id": "5d650b4cf953620006dbefc4",
        "name": "rule_api_001",
        "ruleType":1,
        "conditions": [
          {
            "deviceId": 10000237,
            "deviceName": "test_dev_001",
            "productId": 100140,
            "productName": "test_mqtt_dev_001",
            "protocolType": 1,
            "check": {
              "parameter": "int32",
              "operation": "==",
              "operand": 2023,
              "type": 9
            }
          }
        ],
        "timeTrigger": "",
        "filters": [
          {
            "type": 1,
            "deviceFilter": {
              "deviceId": 10000237,
              "deviceName": "test_dev_001",
              "productId": 100140,
              "productName": "test_mqtt_dev_001",
              "protocolType": 1,
              "check": {
                "parameter": "string",
                "operation": "==",
                "operand": "20",
                "type": 3
              }
            }
          }
        ],
        "actions": [
          {
            "deviceId": 10000237,
            "deviceName": "test_dev_001",
            "productId": 100140,
            "productName": "test_mqtt_dev_001",
            "protocolType": 1,
            "identifier": "string",
            "value": "20",
            "type": 3
          }
        ],
        "phone": [],
        "exportClientId": null,
        "exportClientName": "",
        "mailServerId": "5d65056cf953620006dbefc2",
        "mailServerName": "test_mail",
        "mailPatternId": "5d6505d7f953620006dbefc3",
        "mailPatternName": "test_pattern",
        "status": "DISABLED",
        "created": 1566903116318,
        "modified": 1566903116318,
        "userId": "a881f626c8ec42ceb4c597a3ce7f0bbe"
      }
    ]
  }
}
```

------



### 分页查询未分配规则

功能描述：分页查询未分配规则的功能.

```
POST  /api/v1/rules/gateway/unallocated
```
**Query:**

| Name           | Description              | Required | Type   | marks                           |
| -------------- | ------------------------ | -------- | ------ | ------------------------------- |
| accessKeyId    | 用户访问服务所用的密钥ID | Yes      | string | 系统生成，在生成用户时获取      |
| signature      | 签名结果串               | Yes      | string | 不校验，备用字段                |
| signatureNonce | 签名随机数               | Yes      | int    | 1小时内，同一用户需使用不同数字 |

**Body:**

| Name           | Type     | Description                                  | Required  |
| -------------- | -------- | -------------------------------------------- | --------- |
| currentPage    | int      | 当前页码                                      | Yes       |
| pageSize       | int      | 页码大小                                      | Yes      |
| filter         | struct   | 筛选条件                                      | Yes      |

body filter:

| Name      | Type   | Description    | Required |
| --------- | ------ | -------------- | -------- |
| name      | string | 规则引擎的名字 | No       |
| gatewayId | int    | 网关ID         | Yes      |

body example:

```
{
	"currentPage":1,
	"pageSize":100,
	"filter": {
            "name":"test",
        	"gatewayId": 10000080
     }
} 
```

**Responses:**

```
{
  "success": true,
  "code": 0,
  "msg": "",
  "data": {
    "currentPage": 1,
    "pageSize": 10,
    "totalCount": 1,
    "totalPage": 1,
    "content": [
      {
        "id": "5d650b4cf953620006dbefc4",
        "name": "rule_api_001",
        "ruleType":1,
        "conditions": [
          {
            "deviceId": 10000237,
            "deviceName": "test_dev_001",
            "productId": 100140,
            "productName": "test_mqtt_dev_001",
            "protocolType": 1,
            "check": {
              "parameter": "int32",
              "operation": "==",
              "operand": 2023,
              "type": 9
            }
          }
        ],
        "timeTrigger": "",
        "filters": [
          {
            "type": 1,
            "deviceFilter": {
              "deviceId": 10000237,
              "deviceName": "test_dev_001",
              "productId": 100140,
              "productName": "test_mqtt_dev_001",
              "protocolType": 1,
              "check": {
                "parameter": "string",
                "operation": "==",
                "operand": "20",
                "type": 3
              }
            }
          }
        ],
        "actions": [
          {
            "deviceId": 10000237,
            "deviceName": "test_dev_001",
            "productId": 100140,
            "productName": "test_mqtt_dev_001",
            "protocolType": 1,
            "identifier": "string",
            "value": "20",
            "type": 3
          }
        ],
        "phone": [],
        "exportClientId": null,
        "exportClientName": "",
        "mailServerId": "5d65056cf953620006dbefc2",
        "mailServerName": "test_mail",
        "mailPatternId": "5d6505d7f953620006dbefc3",
        "mailPatternName": "test_pattern",
        "status": "DISABLED",
        "created": 1566903116318,
        "modified": 1566903116318,
        "userId": "a881f626c8ec42ceb4c597a3ce7f0bbe"
      }
    ]
  }
}
```
