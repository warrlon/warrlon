# 路由实例分配

## 分页查询当前已分配至网关的边缘类型消息路由客户端

功能描述：分页查询当前已分配至网关的边缘类型消息路由客户端。

```
GET  /api/v1/routers/registration/gateway/association
```

**Query:**

| Name           | Description              | Required | Type   | marks                           |
| -------------- | ------------------------ | -------- | ------ | ------------------------------- |
| currentPage    | 当前页码                | Yes      | string | 系统生成，在生成用户时获取      |
| pageSize       | 页码大小                | Yes      | string | 不校验，备用字段                |
| name           | 名称                    | Yes      | int    |                              |
| deviceId       | 设备ID                  | Yes      | int    |                              |


**Responses:**

```
{
  "success": true,
  "code": 0,
  "msg": "",
  "data": {
    "content": [
      {
        "id": 10109,
        "name": "test_router_02",
        "env": 1,
        "type": 1,
        "format": 1,
        "compression": 1,
        "addressType": 1,
        "addressConfigId": 10112,
        "addressConfigName": "address111",
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
        "created": 1566791296359,
        "modified": 1566791296359
      } 
     ],
    "currentPage": 5
    "pageSize": 5
    "totalCount": 5
    "totalPage": 5
  }
```

---


## 分配消息路由客户端至某边缘网关

功能描述：分配消息路由客户端至指定的网关。

```
POST  /api/v1/routers/registration/gateway/association
```

**Body:**

| Name           | Type  | Description      | Required |
| -------------- | ----- | ---------------- | -------- |
| devId          | string| 设备ID           | Yes      |
| exportClientId | []int | 目的地配置id数组  | Yes      |

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


## 移除某个已分配的消息路由客户端

功能描述：移除某个已分配的消息路由客户端。

```
DELETE  /api/v1/routers/registration/gateway/association/{id}
```

**Query:**

| Name           | Description              | Required | Type   | marks                           |
| -------------- | ------------------------ | -------- | ------ | ------------------------------- |
| exportClientId | 客户端ID                | Yes      | string | 系统生成，在生成用户时获取      |
| devId          | 设备ID                  | Yes      | string | 不校验，备用字段                |

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


## 分页查询未分配的消息路由客户端信息

功能描述：分页查询未分配的消息路由客户端信息。

```
GET  /api/v1/routers/registration/gateway/unassignedclient
```

**Query:**

| Name           | Description              | Required | Type   | marks                           |
| -------------- | ------------------------ | -------- | ------ | ------------------------------- |
| currentPage    | 当前页码                | Yes      | string | 页码      |
| pageSize       | 页码大小                | Yes      | string | 分页大小   |
| name           | 名称                    | No      | int    | 客户端名称 |
| deviceId       | 设备ID                  | Yes      | int    | 设备id |


**Responses:**

```
{
  "success": true,
  "code": 0,
  "msg": "",
  "data": {
    "content": [
      {
        "id": 10109,
        "name": "test_router_02",
        "env": 1,
        "type": 1,
        "format": 1,
        "compression": 1,
        "addressType": 1,
        "addressConfigId": 10112,
        "addressConfigName": "address111",
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
        "created": 1566791296359,
        "modified": 1566791296359
      } 
     ],
    "currentPage": 5
    "pageSize": 5
    "totalCount": 5
    "totalPage": 5
  }
```
