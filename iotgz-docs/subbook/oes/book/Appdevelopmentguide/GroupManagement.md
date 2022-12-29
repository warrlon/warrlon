# 分组管理

### 模糊分页查询分组列表
```
GET  /api/v1/label
```
**Query:**

| Name           | Description              | Required | Type   | marks                           |
| -------------- | ------------------------ | -------- | ------ | ------------------------------- |
| currentPage  | 页码          | Yes      | int     |                         |
| pageSize     | 每页条数        | Yes      | int     | 范围：1\-50                |
| product      | 产品ID        | Yes       | int  |  |
| name         | 名称        | No       | string  | （默认不传:全部）。长度：0\-128     |

**Responses:**

```
{
    "success": true,
    "code": 0,
    "msg": "",
    "data": {
              "contents":[
                             {
                               "created": 0,
                               "description": "string",
                               "deviceCount": 0,
                               "enableDeviceCount": 0,
                               "id": 0,
                               "name": "string",
                               "onlineDeviceCount": 0,
                               "productId": 0
                             }
                           ],
                           "currentPage": 0,
                           "pageSize": 0,
                           "totalCount": 0,
                           "totalPage": 0
    }

```
------
### 添加分组
```
POST  /api/v1/label
```

**Body:**

| Name          | Description | Required | Type       | marks                                                 |
|---------------|-------------|----------|------------|-------------------------------------------------------|
| productId  | 产品ID        | Yes       | int |                                                       |
| name          | 分组名称        | Yes       | string        |                                             |
| description  | 描述        | No       | string     | 长度：0-128                                             |

**Responses:**

```
{
    "data": {
        "id": 174,
        "productId": 101702,
        "name": "t1ttt3tt",
        "created": 1578474716405,
        "description": ""
    },
    "success": true,
    "code": 0,
    "msg": null
}
```
------
### 编辑分组
```
PUT  /api/v1/label
```

**Body:**

| Name          | Description | Required | Type       | marks                                                 |
|---------------|-------------|----------|------------|-------------------------------------------------------|
| id  | 分组ID        | Yes       | int |                                                       |
| name          | 分组名称        | No       | string        |                                             |
| description  | 描述        | No       | string     | 长度：0-128                                             |

**Responses:**

```
{
    "success": true,
    "code": 0,
    "msg": "",
    "data": null
}

```
------
### 删除分组
```
DELETE  /api/v1/label
```

**Body:**

| Name          | Description | Required | Type       | marks                                                 |
|---------------|-------------|----------|------------|-------------------------------------------------------|
| ids  | 分组ID数组        | Yes       | []int |                                                       |


**Responses:**

```
{
    "success": true,
    "code": 0,
    "msg": "",
    "data": null
}

```
------
### 查看分组详情
```
GET  /api/v1/label/id/{id}
```

**Path:**

| Name           | Description              | Required | Type   | marks                           |
| -------------- | ------------------------ | -------- | ------ | ------------------------------- |
| id            | 分组ID | Yes      | int |       |

**Responses:**

```
{
    "success": true,
    "code": 0,
    "msg": "",
    "data": {
              "created": 0,
              "description": "string",
              "deviceCount": 0,
              "enableDeviceCount": 0,
              "id": 0,
              "name": "string",
              "onlineDeviceCount": 0,
              "productId": 0
            }
}

```
------

### 添加批量设备到分组
```
PUT  /api/v1/label/add/devices
```

**Body:**

| Name          | Description | Required | Type       | marks                                                 |
|---------------|-------------|----------|------------|-------------------------------------------------------|
| deviceIds  | 设备ID数组      | Yes       | []int |                                                       |
| labelId  | 分组ID      | Yes       | int |                                                       |

**Responses:**

```
{
    "success": true,
    "code": 0,
    "msg": "",
    "data": null
}

```
------
### 批量将多个设备移除分组
```
PUT  /api/v1/label/remove/devices
```


**Body:**

| Name          | Description | Required | Type       | marks                                                 |
|---------------|-------------|----------|------------|-------------------------------------------------------|
| deviceIds  | 设备ID数组      | Yes       | []int |                                                       |
| labelId  | 分组ID      | Yes       | int |                                                       |

**Responses:**

```
{
    "success": true,
    "code": 0,
    "msg": "",
    "data": null
}

```
------
### 分页查询分组里/外的设备列表
```
GET  /api/v1/label/group/{relation}/page
```
**Query:**

| Name           | Description              | Required | Type   | marks                           |
| -------------- | ------------------------ | -------- | ------ | ------------------------------- |
| protocol |    产品协议          | No      | int    |  |
| currentPage  | 页码          | Yes      | int     |                         |
| pageSize     | 每页条数        | Yes      | int     | 范围：1\-50                |
| label         | 分组ID      | Yes    | string  | （默认不传:全部）。长度：0\-128     |
| deviceId | 设备ID | No | int |  |
| name      | 设备名称        | No       | string  | （默认不传:全部）。长度：0\-128  |
| adminState | 启用状态：0-全部,1-禁用,2-启用 | No | int | 启用状态 |
| operatingState | 在线状态：0-全部,1-离线,2-在线 | No | int | 在线状态 |

**Path:**

| Name           | Description              | Required | Type   | marks                           |
| -------------- | ------------------------ | -------- | ------ | ------------------------------- |
| relation            | 两种参数：IN/NIN | Yes      | string |       |

**Responses:**

```
{
    "success": true,
    "code": 0,
    "msg": "",
    "data":{
             "content": [
               {
                 "adminState": 0,
                 "apiKey": "string",
                 "connectGatewayId": "string",
                 "created": 0,
                 "description": "string",
                 "encrypt": true,
                 "id": 0,
                 "labels": [
                   "string"
                 ],
                 "lastConnected": 0,
                 "lastReported": 0,
                 "location": "string",
                 "modified": 0,
                 "name": "string",
                 "operatingState": 0,
                 "parentId": 0,
                 "productId": 0,
                 "protocolType": 0,
                 "userId": "string"
               }
             ],
             "currentPage": 0,
             "pageSize": 0,
             "totalCount": 0,
             "totalPage": 0
           }
}
```

