# 设备影子

### 获取设备影子详情
```
GET  /api/v1/shadow
```
**Query:**

| Name           | Description              | Required | Type   | marks                           |
| -------------- | ------------------------ | -------- | ------ | ------------------------------- |
| deviceId       | 设备ID                   | Yes       | int |  |


**Responses:**

```
{
    "success": true,
    "code": 0,
    "msg": "",
    "data": { "deviceId": 10000086,
              "createTime": 20191227141301,
              "connectionState": 0,
              "properties": [
                              { "timestamp": 20191227141301,
                                "version": 1,
                                "state": {"desired": "1",
                                          "reported": "0",
                                          }
                                "metadata": {"desired": "1",
                                             "reported": "0",
                                            }
                              }                            
                            ]
    }

```
------


### 更新设备影子信息
```
PUT  /api/v1/shadow
```
**Query:**

| Name           | Description              | Required | Type   | marks                           |
| -------------- | ------------------------ | -------- | ------ | ------------------------------- |
| deviceId       | 设备ID                   | Yes       | int |  |

**Body**

|     Name     |  Type  ------------|                         Description                          | Required |
| :----------: | :----------------: | :----------------------------------------------------------: | :------: |
|   properties | ShadowPropertyRes[]|                            设备影子信息                            |   Yes    |

**ShadowPropertyRes:**

| Name        | Description | Required | Type                         | marks                 |
|-------------|-------------|----------|------------------------------|-----------------------|
| timestamp   | 更新时间     | No       | long                         | |
| version     | 版本号       | No       | long                         |                    |
| state       | 状态信息     | No       | ShadowPropertyStateRes[]     |                       |
| metadata    | 元数据信息   | No       | ShadowPropertyMetadataRes[]  |                       |

**ShadowPropertyStateRes:**

| Name        | Description  | Required | Type                         | marks                 |
|-------------|--------------|----------|------------------------------|-----------------------|
| desired     | 设备的预期状态 | No       | long                         | |
| reported    | 设备的报告状态 | No       | long                         |                    |

**ShadowPropertyMetadataRes:**

| Name        | Description  | Required | Type                         | marks                 |
|-------------|--------------|----------|------------------------------|-----------------------|
| desired     | 设备的预期状态 | No       | long                         | |
| reported    | 设备的报告状态 | No       | long                         |                    |

body example：

```
{
  "properties":{
		"timestamp":12314566987,
		"version":3,
		"state":{
		    "desired":{},
		    "reported":{
                "color": "RED"
				}
			}
	}
}
```

**Responses:**

```
{
    "success": true,
    "code": 0,
    "msg": "",
    "data": { "deviceId": 10000086,
              "createTime": 20191227141301,
              "connectionState": 0,
              "properties": [
                              { "timestamp": 20191227141301,
                                "version": 1,
                                "state": {"desired": "1",
                                          "reported": "0",
                                          }
                                "metadata": {"desired": "1",
                                             "reported": "0",
                                            }
                              }                            
                            ]
    }

```
