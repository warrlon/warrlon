# 场景联动管理
### 新建规则

功能描述：提供新建规则的功能，入参为规则具体内容，返回新增结果。

```
POST  /api/v1/rules
```

**Body:**

| Name        | Type     | Description                                  | Required                                   |
| ----------- | -------- | -------------------------------------------- | ------------------------------------------ |
| name        | string   | 规则名                                       | Yes                                        |
| conditions  | []struct | 触发器结构体数组                             | No (conditions和timeTrigger中至少必填一个) |
| timeTrigger | string   | 时间触发器 支持cron表达式（0 0 3,18 * * ? ） | No  (trigger和timeTrigger中至少必填一个)   |
| actions     | []struct | 执行设备信息结构体数组                       | Yes                                        |
| ruleType    | int      | 规则类型，0-边缘端                           | Yes                                        |

Body   conditions结构体：

| Name      | Type           | Description                                                  | Required |
| --------- | -------------- | ------------------------------------------------------------ | -------- |
| productId | int            | 触发产品ID                                                   | Yes      |
| didList   | int[]          | 触发设备ID数组                                               | Yes      |
| parameter | string         | 触发设备属性名（定义功能时添加的属性名）                     | Yes      |
| operation | string         | 触发设备判定符号（目前支持：> ; >= ; == ; < ; <= ; !=）(注：string，bool，byte只支持  == 与 !=  ) | Yes      |
| operand   | 功能属性值类型 | 阈值（bool值写成true或者false，int写成数字）                 | Yes      |

Body   actions结构体：

| Name       | Type     | Description                                | Required |
| ---------- | -------- | ------------------------------------------ | -------- |
| productId  | int      | 执行产品ID                                 | Yes      |
| deviceId   | int      | 执行设备ID                                 | Yes      |
| identifier | string   | 需执行的属性名（具有写权限的属性）         | Yes      |
| value      | 任意类型 | 值（bool值写成true或者false，int写成数字） | Yes      |

body example:

```
{
        "name": "rule01",
        "timeTrigger": "",
        "conditions": [
            {
               
                "parameter":"temperature",
                "operand": "2",
                "operation": "!=",
                "productId": 100492,
                "didList": [
                    10011699,10001086
                ]
            }
        ],
        "filters": [],
        "actions": [
            {
                "identifier": "voltage",
                "deviceId": 10001086,
                "productId": 100492,
                "value": "6"
            }
        ],
        "ruleType": 0
    }
```

**Responses:**

```
{
    "data": "8ae491be7096bd2301709a46d7170009",
    "success": true,
    "code": 0,
    "msg": null
}
```



---



### 获取详细规则信息

功能描述：提供根据id查询规则详情的功能，返回规则详情。

```
GET  /api/v1/rules/{ruleId}
```

**Path:**

| Name   | Description | Required | Type   |
| ------ | ----------- | -------- | ------ |
| ruleId | 规则的id    | Yes      | string |

**Responses:**

```
{
  "success": true,
  "code": 0,
  "msg": "",
  "data": {
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
}
```



---



### 更新规则

功能描述：更新规则的功能，入参为规则具体内容。

```
PUT  /api/v1/rules/{ruleId}
```

**Path:**

| Name   | Description | Required | Type   |
| ------ | ----------- | -------- | ------ |
| ruleId | 规则的id    | Yes      | string |

**Body:**

| Name        | Type     | Description                                  | Required                                   |
| ----------- | -------- | -------------------------------------------- | ------------------------------------------ |
| name        | string   | 规则名                                       | No                                         |
| conditions  | []struct | 触发器结构体数组                             | No (conditions和timeTrigger中至少必填一个) |
| timeTrigger | string   | 时间触发器 支持cron表达式（0 0 3,18 * * ? ） | No  (trigger和timeTrigger中至少必填一个)   |
| actions     | []struct | 执行设备信息结构体数组                       | No                                         |

Body   conditions结构体：

| Name      | Type           | Description                                                  | Required |
| --------- | -------------- | ------------------------------------------------------------ | -------- |
| productId | int            | 触发产品ID                                                   | Yes      |
| didList   | int[]          | 触发设备ID                                                   | Yes      |
| parameter | string         | 触发设备属性名（定义功能时添加的属性名）                     | Yes      |
| operation | string         | 触发设备判定符号（目前支持：> ; >= ; == ; < ; <= ; !=）(注：string，bool，byte只支持  == 与 !=  ) | Yes      |
| operand   | 功能属性值类型 | 阈值（bool值写成true或者false，int写成数字）                 | Yes      |

Body   actions结构体：

| Name       | Type     | Description                                | Required |
| ---------- | -------- | ------------------------------------------ | -------- |
| productId  | int      | 执行产品ID                                 | Yes      |
| deviceId   | int      | 执行设备ID                                 | Yes      |
| identifier | string   | 需执行的属性名（具有写权限的属性）         | Yes      |
| value      | 任意类型 | 值（bool值写成true或者false，int写成数字） | Yes      |

body example:

```
{
        "name": "myrule02",
        "conditions": [
            {
               
                "parameter":"tttt",
                "operand": "2",
                "operation": "!=",
                "productId": 100492,
                "didList": [
                    10011699
                ]
            }
        ],
        "actions": [
            {
                "identifier": "tttt",
                "deviceId": 10001086,
                "productId": 100492,
                "value": "6"
            }
        ]
    }
```

**Responses:**

```
{
    "data": null,
    "success": true,
    "code": 0,
    "msg": null
}
```

------



### 通过id删除规则

功能描述：提供根据id删除规则的功能，返回删除结果。

```
DELETE  /api/v1/rules/{ruleId}
```

**Path:**

| Name           | Description              | Required | Type   | marks                           |
| -------------- | ------------------------ | -------- | ------ | ------------------------------- |
| ruleId    | 规则的id | Yes      | string |       |

**Responses:**

```
{
  "success": true,
  "code": 0,
  "msg": "",
  "data": "true"
}
```



***
### 分页查询规则

功能描述：提供对规则的分页查询功能，返回规则列表。

```
GET  /api/v1/rules
```

**Query:**

| Name           | Description              | Required | Type   | marks                           |
| -------------- | ------------------------ | -------- | ------ | ------------------------------- |
| pageSize       | 分页大小                 | Yes      | int    | 1~50 |
| currentPage    | 页码                     | Yes      | int    | 正整数 |
| name           | 规则名                   | No      | string |                                 |
| type | 规则类型，0-边缘端 | No | int | |



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
