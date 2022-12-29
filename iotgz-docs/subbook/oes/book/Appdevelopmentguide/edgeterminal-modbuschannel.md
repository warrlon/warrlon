# Modbus通道管理

##  创建Modbus通道

功能描述：新建一个通道，返回新建通道id。

```
POST  /api/v1/gateway/channels
```

**Query:**

| Name           | Description              | Required | Type   | marks                           |
| -------------- | ------------------------ | -------- | ------ | ------------------------------- |
| gatewayId      | 网关设备ID               | Yes      | int    |                                 |

**Body:**

| Name       | Type   | Description                                                  | Required |
| ---------- | ------ | ------------------------------------------------------------ | -------- |
| name       | string | 通道名称                                                     | Yes      |
| model      | string | 通道模式（0 : RTU/ 1 : TCP）,目前只支持RTU模式               | Yes      |
| serialPort | string | 串口号                                                       | Yes      |
| baudRate   | int    | 波特率（300/600/1200/1440/2400/4800/9600/19200/38400 /43000/56000/57600/115200/230400）默认为1200 | Yes      |
| dataBits   | int    | 数据位（5/6/7/8）默认为8                                     | Yes      |
| checkBits  | int    | 数据位（无校验：0；奇校验：1；偶校验：2）默认为无校验        | Yes      |
| stopBits   | int    | 停止位(1/2)默认为2                                           | Yes      |



**Responses:**

```
{
  "success": true,
  "code": 0,
  "msg": "",
  "data": {
    "id": 14,
    "gatewayid": 10000144,
    "name": "api_channel_01",
    "model": 0,
    "serialPort": "/devredfffffffff",
    "baudRate": 300,
    "dataBits": 5,
    "checkBits": 0,
    "stopBits": 1,
    "ip": "",
    "port": 0,
    "created": 1566439063,
    "modified": 0
  }
}
```



------



##  修改Modbus通道

功能描述：修改指定通道。

```
PUT  /api/v1/gateway/channels/{id}
```

**Body:**

| Name       | Type   | Description                                                  | Required |
| :--------- | :----- | :----------------------------------------------------------- | :------- |
| name       | string | 通道名称                                                     | No       |
| serialPort | string | 串口号                                                       | No       |
| baudRate   | string | 波特率（300/600/1200/1440/2400/4800/9600/19200/38400 /43000/56000/57600/115200/230400）默认为1200 | No       |
| dataBits   | int    | 数据位（5/6/7/8）默认为8                                     | No       |
| checkBits  | int    | 数据位（无校验：0；奇校验：1；偶校验：2）默认为无校验        | No       |
| stopBits   | int    | 停止位(1/2)默认为2                                           | No       |



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



## 查询Modbus通道详情

功能描述：根据id查询指定通道，返回该通道的具体信息。

```
GET  /api/v1/gateway/channels/{id}
```



**Responses:**

```
{
  "success": true,
  "code": 0,
  "msg": "",
  "data": {
    "id": 14,
    "gatewayid": 10000144,
    "name": "api_channel_01",
    "model": 0,
    "serialPort": "/devredfffffffff",
    "baudRate": 300,
    "dataBits": 5,
    "checkBits": 0,
    "stopBits": 1,
    "ip": "",
    "port": 0,
    "created": 1566439063,
    "modified": 0
  }
}
```



------





##  查询边缘节点下的所有通道

功能描述：查询指定边缘节点下的所有通道，返回该通道信息列表。

```
GET  /api/v1/gateway/channels
```

**Query:**

| Name           | Description              | Required | Type   | marks                           |
| :------------- | :----------------------- | :------- | :----- | :------------------------------ |
| gatewayId      | 网关设备ID               | Yes      | int    |                                 |



**Responses:**

```
{
  "success": true,
  "code": 0,
  "msg": "",
  "data": [
    {
      "id": 14,
      "gatewayid": 10000144,
      "name": "api_channel_01",
      "model": 0,
      "serialPort": "/dev",
      "baudRate": 300,
      "dataBits": 5,
      "checkBits": 0,
      "stopBits": 2,
      "ip": "",
      "port": 0,
      "created": 1566439063,
      "modified": 1566440081
    }
  ]
}
```



------





## 删除Modbus通道

功能描述：删除指定通道。

```
DELETE  /api/v1/gateway/channels/{id}
```


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


##  根据设备ID查询Modbus通道列表

功能描述：查询指定设备下的所有通道，返回该通道信息列表。

```
GET  /api/v1/device/4/channel/device/{deviceId}
```

**Query:**

| Name           | Description              | Required | Type   | marks                           |
| :------------- | :----------------------- | :------- | :----- | :------------------------------ |
| deviceId       | 设备ID                   | Yes      | int    |                                 |


**Responses:**

```
{
  "success": true,
  "code": 0,
  "msg": "",
  "data": [
    {
      "id": 14,
      "gatewayid": 10000144,
      "name": "api_channel_01",
      "model": 0,
      "serialPort": "/dev",
      "baudRate": 300,
      "dataBits": 5,
      "checkBits": 0,
      "stopBits": 2,
      "ip": "",
      "port": 0,
      "created": 1566439063,
      "modified": 1566440081
    }
  ]
}
```
## 创建Modbus设备的边缘节点通道配置

功能描述：为Modbus设备创建一个网关通道配置，根据此配置可以实现该设备数据的上传和下发。

注意：此接口多次调用会覆盖旧的Modbus设备网关通道配置。

```
POST  /api/v1/devices/modbus/channel-config/gateway
```

**body**

| Name          | Type | Description                   | Required |
| ------------- | ---- | ----------------------------- | -------- |
| id            | int  | Modbus设备ID                  | Yes      |
| channelId     | int  | 网关通道配置Id                |     Yes     |
| modbusAddress | int  | 从站号                        | No     |
| collectTime   | int  | 设备数据采集间隔  , 不小于10S | Yes      |



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





## 获取Modbus设备的边缘节点通道配置

功能描述：获取Modbus设备的网关通道配置。

```
GET  /api/v1/devices/modbus/channel-config
```

**Query:**

| Name | Description  | Required | Type | marks |
| ---- | ------------ | -------- | ---- | ----- |
| id   | Modbus设备ID | Yes      | int  |       |

**Responses:**

```
{
  "success": true,
  "code": 0,
  "msg": "",
  "data": {
    "id": 10000196,
    "channelId": 16,
    "modbusAddress": 1,
    "collectTime": 10
  }
}
```