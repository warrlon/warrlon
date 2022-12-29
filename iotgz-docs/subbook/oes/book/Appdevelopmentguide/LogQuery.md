# 日志查询

### 模糊分页查询指定设备的日志信息
```
GET  /api/v1/monitor/logs
```
**Query:**

| Name           | Description              | Required | Type   | marks                           |
| -------------- | ------------------------ | -------- | ------ | ------------------------------- |
| pageNum        | 页码                     | Yes      | int     | 范围：1\-100 |
| pageSize       | 每页条数                 | Yes      | int     | 范围：1\-100             |
| deviceId       | 设备ID                   | Yes       | string  |  |
| modules        | 日志模块                 | No       | []string  |      |
| level          | 日志级别                 | No       | string  |  |
| startTime      | 查询起始时间        | No       | Date  |      |
| finishTime     | 查询终止时间        | No       | Date  |  |

**Responses:**

```
{
    "success": true,
    "code": 0,
    "msg": "",
    "data": {
              "content":[
                             {
                               "id": 2312312343214,
                               "time": "2019/12/27 12:38:01",
                               "expireTime": "2019/12/27 12:38:01",
                               "module": 'monitor',
                               "level": "info",
                               "deviceId": "1000089",
                               "msg": "xxxxdsafadsfadfads",
                             }
                           ],
                           "currentPage": 0,
                           "pageSize": 0,
                           "totalCount": 0,
                           "totalPage": 0
    }

```
------



### 查询设备下可供查询日志模块
```
GET  /api/v1/monitor/logs/{devId}/modules
```
**Path:**

| Name           | Description              | Required | Type   | marks                           |
| -------------- | ------------------------ | -------- | ------ | ------------------------------- |
| devId       | 设备ID                   | Yes       | string  |  |

**Responses:**

```
{
    "success": true,
    "code": 0,
    "msg": "",
    "data": {"modules":
                [
                  "monitor"
                ]
    }

```
------


### 查询部署日志
```
GET  /api/v1/monitor/configlog/page
```
**Query:**

| Name           | Description              | Required | Type   | marks                           |
| -------------- | ------------------------ | -------- | ------ | ------------------------------- |
| currentPage    | 页码                     | Yes      | int     |                         |
| pageSize       | 每页条数                 | Yes      | int     | 范围：1\-50                |
| deviceId       | 设备ID                   | Yes       | string  |  |
| start          | 查询起始时间             | Yes       | long  |      |
| end            | 查询终止时间             | Yes       | long  |  |

**Responses:**

```
{
    "success": true,
    "code": 0,
    "msg": "",
    "data": {
              "content":[
                             {
                               "deviceId": 2312312343214,
                               "time": "20191227123801",
                               "result": "true",
                               "msg": 'dfadafdfadfa'
                             }
                           ],
                           "currentPage": 0,
                           "pageSize": 0,
                           "totalCount": 0,
                           "totalPage": 0
    }

```
