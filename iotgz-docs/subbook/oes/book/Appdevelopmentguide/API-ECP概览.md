# ECP概览

## 查询数据转发最近的聚合数据

功能描述：查询数据转发最近的聚合数据。
```
GET  /api/v1/routers/data/last
```
**Query:**

| Name           | Type          | Description              | Required |
| -------------- | ------------------------ | -------- | ------ |
| interval | int | 时间间隔（1:小时; 2:天) | Yes      |
| count    | int                  | 最近记录的数量              | Yes     |
**Response data：**

| Name           | Type          | Description              |
| -------------- | ------------------------ | -------- |
| time | long | 数据产生时间 |
| count    | int                  | 转发总数量 |
| countSuccess | int | 转发成功数量 |
| countFailed | int | 转发失败数量 |
| timeCostAverage | float | 数据平均转发时长(毫秒) |

**Response example:**

```
{
    "data": [
        {
            "count": 0,
            "time": 1582848000,
            "countSuccess": 0,
            "countFailed": 0,
            "timeCostAverage": 0.0
        },
        {
            "count": 0,
            "time": 1583193600,
            "countSuccess": 0,
            "countFailed": 0,
            "timeCostAverage": 0.0
        }
    ],
    "success": true,
    "code": 0,
    "msg": null
}
```
## 查询消息路由实例总数

功能描述：查询消息路由实例总数。
```
GET  /api/v1/routers/count
```
**Query:**

| Name           | Type          | Description              | Required |
| -------------- | ------------------------ | -------- | ------ |
| platform | int | 平台类型 | Yes      |

**Response example:**

```
{
    "data": 10,
    "success": true,
    "code": 0,
    "msg": null
}
```

## 数据上传数量统计

功能描述：数据上传数量统计。
```
GET  /api/v1/data/overview/count/event
```

**Query:**

| Name           | Type          | Description              | Required |
| -------------- | ------------------------ | -------- | ------ |
| uploadDuration | int | 时间区间（1表示24小时，7表示7天，30表示30天) | Yes      |

**Response data：**

| Name           | Type          | Description              |
| -------------- | ------------------------ | -------- |
| userId | string | 用户ID |
| onlineNodeCount    | int                  | 节点在线数 |
| offlineNodeCount | int | 节点离线数 |
| onlineDeviceCount | int | 设备在线数 |
| offlineDeviceCount | float | 设备离线数 |
| count | long | event数量 |
| userId | time | 时间 |

**Response example:**

```
{
    "data": [
        {
            "count": 0,
            "offlineDeviceCount": 0,
            "offlineNodeCount": 0,
            "onlineDeviceCount": 0,
            "onlineNodeCount": 0,
            "time": "2020-03-05T08:06:15.609Z",
            "userId": "string"

        },
        {
            "count": 0,
            "offlineDeviceCount": 0,
            "offlineNodeCount": 0,
            "onlineDeviceCount": 0,
            "onlineNodeCount": 0,
            "time": "2020-03-06T08:06:15.609Z",
            "userId": "string1"

        }
    ],
    "success": true,
    "code": 0,
    "msg": null
}
```