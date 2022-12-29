# 边缘节点（即网关）管理

**边缘节点：指产品的节点类型为“网关”的产品设备**

## 注册网关设备

功能描述：新建一个网关设备，返回新建设备的id, apiKey, 用于该设备的信息鉴权。

```
POST  /api/v1/devices/gateway
```

**Query:**

| Name           | Description              | Required | Type   | marks                           |
| -------------- | ------------------------ | -------- | ------ | ------------------------------- |
| productId      | 产品ID                   | Yes      | int    |                                 |

**Body:**

| Name           | Type   | Description                                                  | Required |
| -------------- | ------ | ------------------------------------------------------------ | -------- |
| name           | string | 设备名称                                                     | Yes      |
| description    | string | 设备描述                                                     | No       |
| logEnable      | int    | 是否启用日志 （0:启用 / 1:不启用）                           | No       |
| logDay         | int    | 日志保存时长天数， 目前支持值 ： 1, 7 , 30, 分别表示一天，一周，一月。 | No       |
| logLevel       | string | 日志级别（error / warning / info）                           | No       |
| cpuType        | int    | cpu类型，（0-ARM,1-ARM64,2-AMD64）                           | Yes      |
| systemType     | int    | 系统类型（0-Linux）                                          | Yes      |
| dataSavePeriod | int    | 数据存储周期                                                 | No       |



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





## 更新网关设备的网关特征属性。

功能描述：指定一个网关设备，对该设备的网关特征的部分属性进行更新。

```
PUT  /api/v1/devices/gateway/{deviceId}
```

**Body:**

| Name           | Type | Description                                                  | Required |
| -------------- | ---- | ------------------------------------------------------------ | -------- |
| logEnable      | int  | 是否启用日志 （1:启用 / 0:不启用）                           | No       |
| logDay         | int  | 日志保存时长天数， 目前支持值 ： 1, 7 , 30, 分别表示一天，一周，一月。 | No       |
| logLevel       | int  | 日志级别（日志等级：0-错误，1-警告，2-信息）                 | No       |
| dataSavePeriod | int  | 数据存储周期                                                 | No       |

**Responses:**

```
{
  "success": true,
  "code": 0,
  "msg": "",
  "data": 1
}
```

------





## 查看网关设备的网关特征属性。

功能描述：查看网关设备的网关特征属性。

```
GET  /api/v1/devices/gateway/{deviceId}
```

**Responses:**

```
{
  "success": true,
  "code": 0,
  "msg": "",
  "data": {
    "id": 10000005,
    "logDay": 7,
    "logEnable": 1,
    "logLevel": "info",
    "cpuType":1,
    "systemType":0,
    "systemInfo":"String",
    "version":"网关版本",
    "dockerVersion":"容器版本",
    "hostName":"主机名",
    "netCard":"网卡",
    "ip":"1.1.1.1",
    "dataSavePeriod":5
  }
}
```

------



## 添加网关设备关联

功能描述：网关设备绑定一个或多个设备。

```
POST  /api/v1/devices/gateway/associations
```

**Query:**

| Name           | Description              | Required | Type   | marks                                     |
| -------------- | ------------------------ | -------- | ------ | ----------------------------------------- |
| gatewayId      | 网关设备ID               | Yes      | string |                                           |
| productId      | 产品ID                   | Yes      | int    |                                           |
| deviceIds      | 关联设备ID列表           | Yes      | string | 以逗号隔开                                |



**Responses:**

```
{
  "success": true,
  "code": 0,
  "msg": "",
  "data": [
    {
      "deviceId": 10000201,
      "parentId": 10000144,
      "productId": 100150,
      "masterKey": "ZjBiNDY0MTk4NzYwYmM2NThkNWI="
    },
    {
      "deviceId": 10000196,
      "parentId": 10000144,
      "productId": 100150,
      "masterKey": "ZjBiNDY0MTk4NzYwYmM2NThkNWI="
    }
  ]
}
```

------





## 删除网关设备关联

功能描述：删除某个网关设备下的设备关联信息。

```
DELETE  /api/v1/devices/gateway/associations
```

**Query:**

| Name           | Description              | Required | Type   | marks                           |
| -------------- | ------------------------ | -------- | ------ | ------------------------------- |
| gatewayId      | 网关设备ID               | Yes      | string |                                 |
| deviceIds      | 关联设备ID列表           | Yes      | string | 以逗号隔开                      |

**Responses:**

```
{
    "success": true,
    "code": 0,
    "msg": ""
    "data": 1
}
```

------

## 查询网关配置信息

功能描述：查询某个网关设备下的设备配置信息。

```
GET  /api/v1/devices/gateway/information/{gatewayId}
```

**Path:**

| Name           | Description              | Required | Type   |
| -------------- | ------------------------ | -------- | ------ |
| gatewayId      | 网关设备ID               | Yes      | string |

**Responses:**

```
{
    "success": true,
    "code": 0,
    "msg": ""
    "data": 
        {
        "rulesCount": 12,
        "exportCount": 11,
        "deviceCount": 1,
        "channelCount": 10
        }
}
```

------


## 查询网关下所有关联的边缘终端

功能描述：查询网关下所有关联边缘终端的信息。

```
GET  /api/v1/devices/gateway/multi/{gatewayId}/{protocolType}
```

**Path:**

| Name           | Description              | Required | Type   |
| -------------- | ------------------------ | -------- | ------ |
| gatewayId      | 网关设备ID               | Yes      | string |
| protocolType   | 物模型协议 （1 : MQTT;  4 : MODBUS; 5 : OPC UA）| Yes      | int |

**Responses:**

```
{
    "success": true,
    "code": 0,
    "msg": ""
    "data": [
                {
                  "deviceId": 10000201,
                  "parentId": 10000144,
                  "productId": 100150,
                  "masterKey": "ZjBiNDY0MTk4NzYwYmM2NThkNWI="
                },
                {
                  "deviceId": 10000196,
                  "parentId": 10000144,
                  "productId": 100150,
                  "masterKey": "ZjBiNDY0MTk4NzYwYmM2NThkNWI="
                }
              ]
}
```
## 获取边缘节点的基本属性

功能描述：查询指定边缘节点的基本属性。

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





## 更新边缘节点的基本属性

功能描述：更新边缘节点的基本属性。

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



## 删除边缘节点

功能描述：删除指定边缘节点。

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



## 分页查询边缘节点的基本属性

功能描述：分页查询指定产品下的边缘节点，返回具体分页信息和节点列表。

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

## 批量删除边缘节点

功能描述：提供批量删除设备的能力，返回删除设备的数量。

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



## 批量启用边缘节点

功能描述：提供批量启用指定产品下边缘节点的能力。

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

## 批量禁用边缘节点

功能描述：提供批量启用指定产品下边缘节点的能力。

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


## 分页查询边缘节点已关联的边缘终端

功能描述：查询边缘节点已关联的边缘终端。

```
GET  /api/v1/devices/subdevice/IN/page
```

**Query:**

| Name           | Description                                                | Required | Type   | marks                           |
| -------------- | ---------------------------------------------------------- | -------- | ------ | ------------------------------- |
| currentPage    | 当前页码                                                   | Yes      | int    | 从1开始                         |
| pageSize       | 分页大小                                                   | Yes      | int    | 从1开始                         |
| deviceId       | 设备                                                       | No    | int    | 网关或DTU设备的id               |
| protocol       | 子设备协议，1: mqtt, 4: modbus, 5: opc ua | Yes      | int    | 1~5                             |
| name           | 子设备名，模糊查询                                         | No       | string | 子设备名，模糊查询              |
| product        | 产品id                                          | No       | int | 产品id             |
| adminState     | 启用状态：0-全部,1-禁用,2-启用                                          | No       | int |启用状态             |
| operatingState | 在线状态：0-全部,1-离线,2-在线                                          | No       | int |在线状态             |
| parentId | 边缘节点id                                    | Yes       | int |边缘节点id             |

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
        "id": 10000247,
        "name": "strdddd",
        "userId": null,
        "productId": 100048,
        "created": 1568801094160,
        "modified": 1568801094160,
        "description": "string",
        "adminState": 1,
        "operatingState": 0,
        "labels": null,
        "lastConnected": 0,
        "lastReported": 0,
        "location": null,
        "apiKey": "YTE1NTBhZDlkOGI2ZTliNmE4ZjY=",
        "protocolType": 4,
        "connectGatewayId": "0",
        "encrypt": false
      }
    ]
  },
  "success": true,
  "code": 0,
  "msg": null
}
```

------


## 分页查询边缘节点未关联的边缘终端

功能描述：查询边缘节点未关联的边缘终端。

```
GET  /api/v1/devices/subdevice/NIN/page
```

**Query:**

| Name           | Description                                                | Required | Type   | marks                           |
| -------------- | ---------------------------------------------------------- | -------- | ------ | ------------------------------- |
| currentPage    | 当前页码                                                   | Yes      | int    | 从1开始                         |
| pageSize       | 分页大小                                                   | Yes      | int    | 从1开始                         |
| deviceId       | 设备                                                       | No    | int    | 网关或DTU设备的id               |
| protocol       | 子设备协议，1: mqtt, 4: modbus, 5: opc ua | No    | int    | 1~5                             |
| name           | 子设备名，模糊查询                                         | No       | string | 子设备名，模糊查询              |
| product        | 产品id                                          | Yes    | int | 产品id             |
| adminState     | 启用状态：0-全部,1-禁用,2-启用                                          | No       | int |启用状态             |
| operatingState | 在线状态：0-全部,1-离线,2-在线                                          | No       | int |在线状态             |
| parentId | 边缘节点id                                    | Yes       | int |边缘节点id             |

**Responses:**

```
{
  "data": {
    "currentPage": 1,
    "pageSize": 5,
    "totalCount": 13,
    "totalPage": 3,
    "content": [
      {
        "id": 10000246,
        "name": "bqqr",
        "userId": null,
        "productId": 100048,
        "created": 1568799603921,
        "modified": 1568799603921,
        "description": "string22",
        "adminState": 1,
        "operatingState": 0,
        "labels": null,
        "lastConnected": 0,
        "lastReported": 0,
        "location": null,
        "apiKey": "OTE0NDcyYmYwZjkxZTk1NTNmN2E=",
        "protocolType": 4,
        "connectGatewayId": "0",
        "encrypt": false
      },
      {
        "id": 10000244,
        "name": "b67rr",
        "userId": null,
        "productId": 100048,
        "created": 1568798437978,
        "modified": 1568798437978,
        "description": "string22",
        "adminState": 1,
        "operatingState": 0,
        "labels": null,
        "lastConnected": 0,
        "lastReported": 0,
        "location": null,
        "apiKey": "OWFhMTAxOGRjMGU1YjBmNzc2NGY=",
        "protocolType": 4,
        "connectGatewayId": "0",
        "encrypt": false
      },
      {
        "id": 10000243,
        "name": "13eqqd",
        "userId": null,
        "productId": 100048,
        "created": 1568797352371,
        "modified": 1568797352371,
        "description": "string22",
        "adminState": 1,
        "operatingState": 0,
        "labels": null,
        "lastConnected": 0,
        "lastReported": 0,
        "location": null,
        "apiKey": "ODlhMjgyOTJkMWZmZjA3OWE4MzE=",
        "protocolType": 4,
        "connectGatewayId": "0",
        "encrypt": false
      },
      {
        "id": 10000237,
        "name": "13242986666222",
        "userId": null,
        "productId": 100048,
        "created": 1568796141212,
        "modified": 1568796141212,
        "description": "string22",
        "adminState": 1,
        "operatingState": 0,
        "labels": null,
        "lastConnected": 0,
        "lastReported": 0,
        "location": null,
        "apiKey": "YzVkYTE2ZTBjMGQ1NmRlY2I2NmM=",
        "protocolType": 4,
        "connectGatewayId": "0",
        "encrypt": false
      }
    ]
  },
  "success": true,
  "code": 0,
  "msg": null
}
```
## 查询边缘节点的功能列表

功能描述：根据产品ID、边缘节点ID，查询边缘节点的功能列表。

```
GET  /api/v1/devices/{id}/properties
```
**Path:**

| Name | Description | Required | Type   | marks |
| ---- | ----------- | -------- | ------ | ----- |
| id   | 边缘节点id  | Yes      | string |       |

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
