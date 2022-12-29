# MQTT和OPC UA物模型

非Modbus协议即指：MQTT协议或OPC UA协议。

## 新增非Modbus功能

功能描述：指定产品，为该产品添加属性功能，用于读写产品属性值。返回功能的id。

```
POST  /api/v1/products/{productId}/properties
```

**Body:**

| Name       | Type   | Description                                                  | Required               |
| ---------- | ------ | ------------------------------------------------------------ | ---------------------- |
| name       | string | 功能名称                                                     | Yes                    |
| identifier | string | 属性名称(该产品下唯一)                                       | Yes                    |
| accessMode | int    | 属性读写类型，只读(1：R)，读写(2：RW)                        | Yes                    |
| type       | int    | 数据类型，支持以下几种：bytes/string/boolean/date/int32/int64/float32/float64。具体值参考后面 “属性type类型码表”。 | Yes                    |
| unit       | string | 属性单位                                                     | Yes                    |
| minimum    | number | 参数最小值(数值类型特有)                            | No，type为数值类型必填， |
| maximum    | number | 参数最大值(数值类型特有)                              | No，type为数值类型必填 |
| nodeName    | String | 节点名称                                     | No |


属性type类型码表

| bytes     | string     | boolean    | date       | int8        | int16       | int32 | int64 |
| --------- | ---------- | ---------- | ---------- | ----------- | ----------- | ----- | ----- |
| 1         | 2          | 3          | 4          | 5           | 6           | 7     | 8     |
| **uint8** | **uint16** | **uint32** | **uint64** | **float32** | **float64** |       |       |
| 9         | 10         | 11         | 12         | 13          | 14          |       |       |



body example:

```
{
    "name":"cmd_api_wendu02",
    "identifier":"prop_api_wendu02",
    "accessMode":1,
    "type":7,
    "unit":"t",
    "minimum":10,
    "maximum":20,
    "minString": null,
    "maxString": null,
    "nodeName": null
}
```

**Response:**

```
{
  "success": true,
  "code": 0,
  "msg": "",
  "data": {
    "id": 23,
    "name": "cmd_api_wendu02",
    "identifier": "prop_api_wendu02",
    "accessMode": 1,
    "type": 7,
    "unit": "t",
    "minimum": 10,
    "maximum": 20,
    "minString": null,
    "maxString": null,
    "productId": 100152,
    "userId": "a881f626c8ec42ceb4c597a3ce7f0bbe",
    "nodeName": null,
  }
}
```
## 删除非Modbus功能

功能描述：删除指定产品下的某一功能。

```
DELETE  /api/v1/products/{productId}/properties/{id}
```

**Response:**

```
{
  "success": true,
  "code": 0,
  "msg": "",
  "data": 1
}
```
## 更新非Modbus功能

功能描述：更新指定产品下的某一功能。

```
PUT  /api/v1/products/{productId}/properties/{id}
```

**Body:**

| Name       | Type   | Description                              | Required |
| ---------- | ------ | ---------------------------------------- | -------- |
| name       | string | 功能名称                                 | No       |
| accessMode | int    | 属性读写类型，只读(1：R)，读写(2：RW)    | No       |
| unit       | string | 属性单位                                 | No       |
| minimum    | number | 参数最小值(Integer，Long, Float, Double) | No       |
| maximum    | number | 参数最大值(Integer，Long, Float, Double) | No       |

**Response:**

```
{
  "success": true,
  "code": 0,
  "msg": "",
  "data": 1
}
```
## 根据功能ID查询非Modbus功能

功能描述：根据产品id和该产品下的功能id查询产品功能, 返回产品功能的详细信息。

```
GET  /api/v1/products/{productId}/properties/{id}
```

**Response:**

```
{
  "success": true,
  "code": 0,
  "msg": "",
  "data": {
        "id": 26,
        "name": "cmd_api_345",
        "identifier": "prop_api_65",
        "accessMode": 2,
        "type": 1,
        "unit": "twsde",
        "minimum": 10,
        "maximum": 20,
        "minString": null,
        "maxString": null,
        "productId": 100234,
        "userId": "f626c8ec42ceb4c597a3ce7f0b",
        "nodeName": null,
  }
}
```
## 根据非Modbus产品ID查询所有功能

功能描述：查询指定产品下的功能，返回产品功能列表。

```
GET  /api/v1/products/{productId}/properties
```

**Response:**

```
{
  "success": true,
  "code": 0,
  "msg": "",
  "data": [
    {
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
      "nodeName": null,
    }
  ]
}
```
