# 消息源格式

<a href="#1">1. 设备生命周期</a>

<a href="#2">2. 设备物模型数据</a>

<a href="#3">3. 场景联动触发日志</a>

<a href="#4">4. 设备位置数据</a>

---
<h3 id="1">1. 设备生命周期数据</h3>

| 参数名称 | 类型 | 说明 |
|:- | :- | :- | :- |
| projectId  | string | 项目ID |
| productId   | string | 产品ID |
| deviceName  | string  | 设备名称 |
| messageType  | string | 消息类型，生命周期固定为 lifeCycle |
| timestamp  | int | 消息时间戳 |
| data | object | 设备生命周期数据，包括 status 属性，online -上线  offline - 离线 |

```
{
    "projectId": "990909090",     
    "productId": "00001",                    
    "deviceName": "iot-0001",      
    "messageType": "lifeCycle", 
    "data":  {
        "status": "online",
        "time": 1524448722123
    }
}
```

<h3 id="2">2. 设备物模型数据</h3>

| 参数名称 | 类型 | 说明 |
|:- | :- | :- |
| projectId  | string | 项目ID |
| productId   | string | 产品ID |
| deviceName  | string  | 设备名称 |
| messageType  | string | 消息类型，物模型上报固定为 notify |
| notifyType | string| 功能点类型，property-属性，event-事件 |
| imei | string | 设备imei号，仅LwM2M协议有此字段 |
| data | object | 物模型数据 |

属性功能点上报数据:

```json
{
    "projectId": "990909090",     
    "productId": "00001",                   
    "deviceName": "iot-0001",     
    "messageType": "notify",
    "notifyType":"property",
    "imei":"509830501643080",//设备imei号，仅LwM2M协议有此字段
    "data": {                         
        "id":  "12345"，                  
        "params": {
            //物模型数据推送格式
            "Power": {
                "value": "on",
                "time": 1524448722123
            },
            "WF": {
                "value": 23.6,
                "time": 1524448722123
            ｝，
            //LwM2M通信协议的IPSO数据协议推送格式
            "3_0_20":{//数据流id，对象_实例_属性
                "time":1612768757420,
                "value":4,
                "bin_data":"A0AA0A0A0A0A0A0" //选填
            }
        ｝
    } 
}
```

事件功能点上报数据:

```
{
    "projectId":  "990909090",    
    "productId":  "00001",                        
    "deviceName":  "iot-0001",    
    "messageType": "notify",
    "notifyType":"event",
    "data": {
        "id": "123",
        "version": "1.0",
        "params": {
            "identifier1":{
                "value": {
                    "Power": "on",
                    "WF": "2"
                },
                "time": 1524448722123
            },
            "identifier2": {
                "value": {
                    "Power": "on",
                    "WF": "2"
                },
                "time": 1524448722123
            }
        }
    }
}
```

服务调用响应数据:

```
{
	"projectId": "990909090 ",
	"productId": "00001 ",
	"deviceName": "iot-0001",
	"messageType": "reply",
	"callType": "async",
	"request": {
		"id": "123",
		"version": "1.0",
		"params": {
			"identifier": "service1",
			"input": {
				"Power1": "on",
				"WF1": "2"
			}
		}
	},
	"response": {
		"id": "123",
		"code": 200,
		"msg": "xxxx",
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
|:- | :- | :- | :- |
| projectId  | string | 项目ID |
| messageType  | string | 消息类型，场景联动日志固定为 sceneLog |
| data | object | 场景联动触发日志，condition 触发条件 action 执行动作 |

```
{
    "projectId": "990909090", 
    "messageType": "sceneLog",
    "sceneName”： "规则1",
    "data": {
        "conditions": [
            { type: "notify", productId: '10000', deviceName: 'abcd123',identifier: 12343, value: 21 },
            { type: "lifeCycle", productId: '10000', deviceName: 'abcd123',value: 'online' } , // 条件类型(设备生命周期), 触发值
            { type: 'extension', category: 'temprature', adCode: '10000', value: 35 } , 条件类型（第三方数据源）
            { type: 'timer', value: "2020-05-14 12:32:20" } // 条件类型(定时), 触发值
        ],
        "actions": [
            { type: 'order', productId: '10001', deviceName: 'abc123', identifier: 12312, value: 21, sccuess: true, message:'成功' } , //命令下发
            { type: 'callback', url: 'https://www.baidu.com', sccuess: true, message:'成功' } // url 调用
        ],
        time: 1592467938974
    }
}
```

<h3 id="4">4. 设备位置数据</h3>

| 参数名称 | 类型 | 说明 |
|:- | :- | :- | :- |
| projectId  | string | 项目ID |
| productId   | string | 产品ID |
| deviceName  | string  | 设备名称 |
| messageType  | string | 消息类别 |
| type  | int | 定位类型，1.基站定位；2.WIFI定位|
| timestamp | int | 上报时间 |
| data | object | 经纬度数据 |

```
{
    “projectId“: "990909090",
    “productId”: "00001",
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
