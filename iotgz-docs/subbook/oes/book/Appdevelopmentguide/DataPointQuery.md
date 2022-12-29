# 数据点查询

### 查询设备的多个属性值的最新值

功能描述：查询指定设备的多个属性值的最新值。

```
GET  /api/v1/data/properties/recent/value
```

**Query:**

| Name           | Description              | Required | Type   | marks                           |
| -------------- | ------------------------ | -------- | ------ | ------------------------------- |
| deviceId       | 设备ID                   | Yes      | int   |                                 |
| propertyNames  | 属性名列表                | Yes      |string[]|                                 |

**Response:**

```
{
    "success": true,
    "code": 0,
    "msg": "",
    "data":[
             {
              "eventId": "991466b0-6d03-4508-88d6-2dc86e7fc618",
              "deviceId": "22",
              "productId": "17",
              "protocol": "MQTT-STANDARD",
              "name": "test",
              "value": 60,
              "created": 1552040792038
             }
          ]
    }
}
```

-----

### 查询资源最新数据点

功能描述：提供查询设备相关资源最新数据点。

```
GET  /api/v1/devices/data/device/{deviceId}/limit/{limit}
```

**Query:**

| Name           | Description              | Required | Type   | marks                           |
| -------------- | ------------------------ | -------- | ------ | ------------------------------- |
| resourceName   | 资源名称                 | Yes      | string    |                                 |


**Responses:**

```
{
    "success": true,
    "code": 0,
    "msg": "",
    "data":[
             {
              "eventId": "991466b0-6d03-4508-88d6-2dc86e7fc618",
              "deviceId": "22",
              "productId": "17",
              "protocol": "MQTT-STANDARD",
              "name": "test",
              "value": 60,
              "created": 1552040792038
             }
          ]
    }
}
```

------


### 分页查询资源某时间段数据点

功能描述：提供分页查询资源某时间段数据点。

```
GET  /api/v1/devices/data/device/{deviceId}
```

**Query:**

| Name           | Description              | Required | Type   | marks                           |
| -------------- | ------------------------ | -------- | ------ | ------------------------------- |
| deviceId       | 设备ID                  | Yes      | string |                                 |
| resourceName   | 资源名称                 | No      | string |                                 |
| start          | 查询开始时间             | No      | long   |                                 |
| end            | 查询结束时间             | No      | long   |                                 |
| currentPage    | 当前页码                 | Yes      | int   |                                 |
| pageSize       | 页码大小                 | Yes      | int   |                                 |

**Responses:**

```
{
    "success": true,
    "code": 0,
    "msg": "",
    "data":"content":
            [
             {
              "eventId": "991466b0-6d03-4508-88d6-2dc86e7fc618",
              "deviceId": "22",
              "productId": "17",
              "protocol": "MQTT-STANDARD",
              "name": "test",
              "value": 60,
              "created": 1552040792038
             }
          ],
        "currentPage":1,
        "pageSize":1,
        "totalCount":1,
        "totalPage":1,
    }
}
```
