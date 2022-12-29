# 消息源格式

<a href="#1">1. 设备生命周期</a>

<a href="#2">2. 设备物模型数据</a>

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<a href="#2.1">2.1 设备物模型数据</a>

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<a href="#2.2">2.2 设备物模型数据</a>

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<a href="#2.3">2.3 设备物模型数据</a>

<a href="#3">3. 场景联动触发日志</a>

<a href="#4">4. 设备位置数据</a>

---
<h3 id="1">1. 设备生命周期数据</h3>

| 参数名称 | 类型 | 说明 |
|:- | :- | :- |
| productId   | string | 产品ID |
| deviceId | int | 设备ID |
| deviceName  | string  | 设备名称 |
| messageType  | string | 消息类型，生命周期固定为 lifeCycle |
| data | object | 设备生命周期数据，包括 status 属性，online -上线  offline - 离线 |

```json
{
    "productId": "C6z4Zk012B",
    "deviceId": 1343759,
    "deviceName": "test01",
    "messageType": "lifeCycle",
    "data": {
        "status": "online",
        "time": 1631521919234
    }
}
```

<h3 id="2">2. 设备物模型数据</h3>

| 参数名称 | 类型 | 说明 |
|:- | :- | :- |
| productId   | string | 产品ID |
| deviceId | int | 设备ID |
| deviceName  | string  | 设备名称 |
| messageType  | string | 消息类型，物模型上报固定为 notify |
| notifyType | string| 功能点类型，property-属性，event-事件 |
| imei | string | 设备imei号，仅LwM2M协议有此字段 |
| data | object | 物模型数据 |

<h5 id="2.1">2.1 属性功能点上报数据</h5>

```json
{
    "productId": "C6z4Zk012B",
    "deviceId": 1343759,
    "deviceName": "test01",
    "messageType": "notify",
    "notifyType": "property",
    "data": {
        "id": "1631522002438",
        "version": "1.0",
        "params": {
            "boolean": {
                "time": 1631522002499,
                "value": true
            },
            "enum": {
                "time": 1631522002527,
                "value": 2
            },
            "float": {
                "time": 1631522002527,
                "value": 1.11
            },
            "int32": {
                "time": 1631522002543,
                "value": 12
            }
        }
    }
}
```

<h5 id="2.2">2.2 事件功能点上报数据</h5>

```json
{
    "productId": "C6z4Zk012B",
    "deviceId": 1343759,
    "deviceName": "test01",
    "messageType": "notify",
    "notifyType": "event",
    "data": {
        "id": "1631522157984",
        "version": "1.0",
        "params": {
            "event1": {
                "eventType": "info",
                "time": 1631522158068,
                "value": {
                    "response": 12
                }
            }
        }
    }
}
```

<h5 id="2.3">2.3 服务调用响应数据</h5>

```json
{
    "productId": "C6z4Zk012B",
    "deviceId": 123456,
    "deviceName": "test01",
    "messageType": "reply",
    "callType": "sync",
    "request": {
        "id": "123",
        "version": "1.0",
        "params": {
            "identifier": "service1",
            "input": {
                "reqeust": 12
            }
        }
    },
	"response": {
		"id": "123",
		"code": 200,
		"msg": "succ",
		"data": {
			"identifier": "service1",
			"output": {
				"result1": "1",
				"result2": "2"
			}
		}
	},
	"sTime": 1524448722123,
	"rTime": 1524448722123
}
```

<h3 id="3">3. 场景联动触发日志</h3>

| 参数名称 | 类型 | 说明 |
| :- | :- | :- |
| messageType  | string | 消息类型，场景联动日志固定为 sceneLog |
| data | object | 场景联动触发日志，conditions-触发条件 actions-执行动作 |

```json
{
  "messageType": "sceneLog",
  "data": {
    "actions": [
      {
        "deviceName": "test01",
        "identifier": "enum",
        "productId": "C6z4Zk012B",
        "success": true,
        "type": "order",
        "value": 1
      }
    ],
    "conditions": [
      {
        "deviceId": 1343759,
        "deviceName": "test01",
        "identifier": "int32",
        "productId": "C6z4Zk012B",
        "type": "notify",
        "value": 3
      }
    ],
    "time": 1631521408309
  }
}
```

<h3 id="4">4. 设备位置数据</h3>

| 参数名称 | 类型 | 说明 |
| :- | :- | :- |
| productId   | string | 产品ID |
| deviceName  | string  | 设备名称 |
| messageType  | string | 消息类别 |
| type  | int | 定位类型，1.基站定位；2.WIFI定位|
| timestamp | int | 上报时间 |
| data | object | 经纬度数据 |

```json
{
    "deviceId": 123456,
    "deviceName": "iot-0001",
    "messageType": "lbsAndWifi",
    "type": 2,
    "timestamp":1524448722123,
    "data": {
        "accuracy": 683,
        "lon": 126.08448,
        "lat": 39.22312
    }
}
```
