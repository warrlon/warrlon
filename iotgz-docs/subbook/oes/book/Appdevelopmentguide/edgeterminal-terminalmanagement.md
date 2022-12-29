# 边缘终端管理

## 注册边缘终端

功能描述：新建一个边缘终端，返回新建边缘终端的id、apiKey，用于该设备的信息鉴权。

```
POST  /api/v1/devices
```

**Query:**

| Name           | Description              | Required | Type   | marks                           |
| -------------- | ------------------------ | -------- | ------ | ------------------------------- |
| productId      | 产品ID                   | Yes      | int    |                                 |

**Body:**

| Name        | Type   | Description | Required |
| ----------- | ------ | ----------- | -------- |
| name        | string | 设备名称    | Yes      |
| description | string | 设备描述    | No       |

**Responses:**

```
{
  "success": true,
  "code": 0,
  "msg": "",
  "data": {
    "apiKey": "NGNlYTkxMDk1MDdjYWNkOGUyZjI=",
    "id": 41
  }
}
```



------







## 获取边缘终端详情

功能描述：查询指定边缘终端，返回该设备的详细信息。

```
GET  /api/v1/devices/{deviceId}
```

**Responses:**

```
{
  "success": true,
  "code": 0,
  "msg": "",
  "data": {
    "id": "116",
    "apiKey": "ZTcyOTMxMWVmNWI1YzMwMDM5NDY=",
    "productId": "33",
    "name": "api_device_mu01",
    "description": "api_device_mu01",
    "adminState": 0,
    "operatingState": 1,
    "labels": [],
    "lastConnected": 0,
    "lastReported": 0,
    "userId": "aa0a5029-e4a7-4216-a713-f7451fcc1e33",
    "created": 156637312502341,
    "modified": 115663731250143,
    "protocolType": 1,
    "connectGatewayId": "123484657",
    "location": "ws3edsw",
    "encrypt": false
  }
}
```



------





## 更新设备的基本属性

功能描述：更新指定边缘终端的基本属性。

```
PUT  /api/v1/devices/{deviceId}
```

**Body:**

| Name        | Type   | Description  | Required |
| ----------- | ------ | ------------ | -------- |
| name        | string | 设备名称     | No     |
| description | string | 设备描述信息 | No       |

**Responses:**

```
{
  "success": true,
  "code": 0,
  "msg": ""
}
```

------



## 删除边缘终端

功能描述：删除指定边缘终端。

```
DELETE  /api/v1/devices/{deviceId}
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



## 按条件分页查询边缘终端

功能描述：分页查询指定产品下的边缘终端，返回具体分页信息和边缘终端列表。

```
GET  /api/v1/devices/multi
```

**Query:**

| Name        | Description        | Required | Type   |
| ----------- | ------------------ | -------- | ------ |
| productId   | 产品ID             | Yes      | int    |
| pageSize    | 分页大小           | Yes      | int    |
| currentPage | 页码               | Yes      | int    |
| name        | 设备名称，模糊查询 | No       | string |

**Responses:**

```
{
  "success": true,
  "code": 0,
  "msg": "",
  "data": {
    "content": [
      {
        "id": "116",
        "apiKey": "ZTcyOTMxMWVmNWI1YzMwMDM5NDY=",
        "productId": "33",
        "name": "api_device_mu01",
        "description": "api_device_mu01",
        "adminState": 1,
        "operatingState": 0,
        "labels": [],
        "lastConnected": 0,
        "lastReported": 0,
        "userId": "aa0a5029-e4a7-4216-a713-f7451fcc1e33",
        "created": 12337312502341,
        "modified": 154637312502341,
        "protocolType": 2,
        "connectGatewayId": "123434322",
        "location": "ws2qw2",
        "encrypt": false
      },
      ...
    ],
    "currentPage": 1,
    "pageSize": 5,
    "totalCount": 4,
    "totalPage": 1
  }
}
```



------





## 批量创建边缘终端

功能描述：提供批量创建边缘终端的能力，返回设备信息列表，每项信息包含id和apiKey， 用于对应新建设备的信息鉴权。

注：设备创建数量上限为2000。

```
POST  /api/v1/devices/multi
```

**Query:**

| Name      | Description | Required | Type |
| --------- | ----------- | -------- | ---- |
| productId | 产品ID      | Yes      | int  |

**Body:**

| Name        | Type   | Description | Required |
| ----------- | ------ | ----------- | -------- |
| list        | struct[] | 设备列表    | YES      |

**list的子对象结构体:**

| Name        | Type   | Description | Required |
| ----------- | ------ | ----------- | -------- |
| name        | string | 设备名称    | YES      |
| description | string | 设备描述    | No       |

body example:

```
{"list":[
{
    "name":"api_device_M02",
    "description":"test device"
},
{
    "name":"api_device_M03",
    "description":"test device"
} 
]}

```

**Responses:**

```
{
  "success": true,
  "code": 0,
  "msg": "",
  "data": [
     {"id":114,
      "apiKey":"NWVkM2Q2YjgwNzllMmU3ZTdiYWM="},
     {"id":115,
      "apiKey":"NmViYWFmYzY2Y2MwODc5YzcxYjU="
      }]
 }

```

---



## 批量删除边缘终端

功能描述：提供批量删除边缘终端的能力，返回删除边缘终端的数量。

```
DELETE  /api/v1/devices
```

**Body：**

| Name      | Type     | Description | Required |
| --------- | -------- | ----------- | -------- |
| deviceIds | []int | 设备ID数组  | YES      |

body example：

```
{
	"deviceIds": [114, 115] 
}

```

**Responses:**

```
{
    "success": true,
    "code": 0,
    "msg": "",
    "data": 2
}
```



------



## 批量启用边缘终端

功能描述：提供批量启用指定产品下设备的能力。

```
PUT  /api/v1/devices/unlock
```

**Body：**

| Name      | Type     | Description | Required |
| --------- | -------- | ----------- | -------- |
| deviceIds | []int | 设备ID数组  | YES      |

body example：

```
{
"deviceIds": [118, 119] 
}

```

**Responses:**

```
{
  "success": true,
  "code": 0,
  "msg": "",
  "data": "2"
}
```

------

## 批量禁用边缘终端

功能描述：提供批量启用指定产品下设备的能力。

```
PUT  /api/v1/devices/lock
```

**Body：**

| Name      | Type     | Description | Required |
| --------- | -------- | ----------- | -------- |
| deviceIds | []int | 设备ID数组  | YES      |

body example：

```
{
"deviceIds": [118, 119] 
}

```

**Responses:**

```
{
  "success": true,
  "code": 0,
  "msg": "",
  "data": "2"
}
```

------

## 查询边缘终端的功能列表

功能描述：根据产品ID、设备ID，查询设备的功能列表。

```
GET  /api/v1/devices/{id}/properties
```
**Path:**

| Name | Description | Required | Type   | marks |
| ---- | ----------- | -------- | ------ | ----- |
| id   | 设备id      | Yes      | string |       |

**Query:**

| Name           | Description              | Required | Type   | marks                           |
| -------------- | ------------------------ | -------- | ------ | ------------------------------- |
| productId      | 产品Id                   | Yes      | int    |                                 |

**Responses:**

```
{
  "success": true,
  "code": 0,
  "msg": "",
  "data": [{
      "id": 236,
      "name": "cmd_dd_345",
      "identifier": "p_api_65",
      "accessMode": 2,
      "type": 2,
      "unit": "tw3",
      "minimum": 10,
      "maximum": 20,
      "minString": null,
      "maxString": null,
      "productId": 103455,
      "userId": "a34edf626c8ec42ceb4c597a3ce7f0b",
      "nodeName": null
  }]
}
```
