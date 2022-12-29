# Modbus物模型

## 新增Modbus功能

功能描述：指定产品，为该产品添加modbus属性功能，用于读写产品属性值。返回功能的id。

```
POST  /api/v1/products/{productId}/properties/modbus
```

**Body:**

| Name            | Type   | Description                                                  | Required               |
| --------------- | ------ | ------------------------------------------------------------ | ---------------------- |
| name            | string | 功能名称                                                     | Yes                    |
| identifier      | string | 属性名称(该产品下唯一)                                       | Yes                    |
| unit            | string | 属性单位                                                     | No                     |
| readFlag        | string | 读命令码，16进制值，支持值选项： 线圈状态 "0x01"; 离散输入变量 "0x02"; 保持寄存器 "0x03"; 输入寄存器 "0x04" | Yes                    |
| writeFlag       | string | 写命令码，16进制值，支持值选项：线圈状态 "0x05" ,"0x0F"； 保持寄存器 "0x06" ,"0x10" | No                     |
| type            | int    | 数据类型，支持类型：int16/uint16/int32/uint32/int64/uint64/float32/float64/string/bool,<br>当读命令码为"0x01"(线圈状态)，"0x02"（离散输入变量）时该参数值只能为bool。数据类型值请参考表下类型码表。 | Yes                    |
| swapByte        | int    | 是否交换高低字节(不变：1；变：2)，把寄存器内16位数据的前后8个bits互换。默认为0。该字段仅对type为数值类型有效。其他类型将设置为1。 | No                     |
| swapOrder       | int    | 是否交换顺序(不变：1；变：2)，把原始数据32位数据的bits互换。默认为1。该字段仅对type为数值类型有效。其他类型将设置为0。 | No                     |
| scalingfactor   | double | 缩放因子，此字段只有type为数值类型有效，默认为1.0。有效值不能为0。 | Yes                    |
| reportMethod    | int    | 上报方式，目前只支持按时上报，值 1 : time,  默认为该值       | No                     |
| registerAddress | string | 寄存器起始地址,16进制值，范围0x0000~0xffff                   | Yes                    |
| registerNumber  | int    | 寄存器个数，用于确定string类型的数据占用长度。只有type为string时该数据有效。 | type为string类型时必填 |
| originDataType  | int    | 原始数据类型，数据类型值请参考表下类型码表。                 |                        |

属性type类型码表

| bytes     | string     | boolean    | date       | int8        | int16       | int32 | int64 |
| --------- | ---------- | ---------- | ---------- | ----------- | ----------- | ----- | ----- |
| 1         | 2          | 3          | 4          | 5           | 6           | 7     | 8     |
| **uint8** | **uint16** | **uint32** | **uint64** | **float32** | **float64** |       |       |
| 9         | 10         | 11         | 12         | 13          | 14          |       |       |

body example:

```
{
    "name":"prop_api_modbus_01",
    "identifier":"prop_api_modbus_01",
    "readFlag":"0x04",
    "writeFlag":"0x05",
	"type":13,
	"unit": "C",
	"reportMethod":1,
	"RegisterAddress":"0x0",
	"swapByte":1,
	"swapOrder" :1,
	"scalingFactor":2.0,
	"registerNumber":2
}
```

**Response:**

```
{
  "success": true,
  "code": 0,
  "msg": "",
  "data": {
    "id": 55,
    "name": "prop_api_modbus_01",
    "identifier": "prop_api_modbus_01",
    "unit": "C",
    "readFlag": "0x04",
    "writeFlag": "0x05",
    "type": 13,
    "swapByte": 1,
    "swapOrder": 1,
    "Scalingfactor": 2.0,
    "reportMethod": 1,
    "registerAddress": "0x0",
    "registerNumber": 0,
    "productId": 100150,
    "userId": "a881f626c8ec42ceb4c597a3ce7f0bbe"
  }
}
```


## 删除Modbus功能

功能描述：指定产品，删除该产品下某个modbus功能。

```
DELETE  /api/v1/products/{productId}/properties/modbus/{id}
```

**Response:**

```
{
    "success": true,
    "code": 0,
    "msg": ""
}
```

## 更新Modbus功能

功能描述：指定产品，修改指定的modbus属性功能。

```
PUT  /api/v1/products/{productId}/properties/modbus/{id}
```

**Body:**

| Name            | Type   | Description                                                  | Required |
| --------------- | ------ | ------------------------------------------------------------ | -------- |
| name            | string | 功能名称                                                     | No       |
| unit            | string | 属性单位                                                     | No       |
| readFlag        | string | 读命令码，16进制值，支持值选项： 线圈状态 "0x01"; 离散输入变量 "0x02"; 保持寄存器 "0x03"; 输入寄存器 "0x04"。 | No       |
| writeFlag       | string | 写命令码，16进制值，支持值选项：线圈状态 "0x05" ,"0x0F"； 保持寄存器 "0x06" ,"0x10" | No       |
| type            | type   | 数据类型，支持类型：int16/uint16/int32/uint32/int64/uint64/float32/float64/string/bool。当读命令码为"0x01"(线圈状态)，"0x02"（离散输入变量）时该参数传入值只能为bool，不传入将默认为bool。数据类型值请参考 **2.2.1**类型码表。 | No       |
| swapByte        | int    | 是否交换高低字节(不变：1；变：2)，把寄存器内16位数据的前后8个bits互换。该字段仅对type为数值类型有效。 | No       |
| swapOrder       | int    | 是否交换顺序(不变：1；变：2)，把原始数据32位数据的bits互换。该字段仅对type为数值类型有效。 | No       |
| scalingfactor   | double | 缩放因子。此字段只有type为数值类型有效。有效值不能为0。      | No       |
| reportMethod    | int    | 上报方式，目前只支持按时上报，值 1 : time,  默认为该值       | No       |
| registerAddress | string | 寄存器起始地址,16进制值，范围0x0000~0xffff                   | No       |
| registerNumber  | int    | 寄存器个数，用于确定string类型的数据占用长度。只有type为string时该数据有效。 | No       |
| originDataType  | int    | 原始数据类型，数据类型值请参考表下类型码表。                 |          |

body example:

```
{
    "name":"prop_api_modbus_01u",
	"unit": "C",
	"reportMethod":"time",
	"RegisterAddress":"0x0",
	"swapByte":0,
	"swapOrder" :0,
	"registerNumber":2
}
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

## 根据功能ID查询Modbus功能

功能描述：指定产品，获取该产品下某个modbus功能信息。

```
GET  /api/v1/products/{productId}/properties/modbus/{id}
```

**Response:**

```
{
    "success": true,
    "code": 0,
    "msg": "",
    "data": {
        "id": 78,
        "name": "cmd_123",
        "identifier": "prop_2345",
        "accessMode": 1,
        "type": 2,
        "unit": "23we",
        "minimum": 10,
        "maximum": 20,
        "minString": null,
        "maxString": null,
        "productId": 1008764,
        "userId": "w3eec42ceb4c597a3ce7f0b",
        "nodeName": null,
        "readFlag": "",
        "writeFlag": "",
        "Scalingfactor": 2.0,
        "swapByte": 0,
        "swapOrder": 0,
        "reportMethod": "time",
        "registerAddress": "0x0",
        "registerNumber": 2
    }
}
```
## 根据Modbus产品ID查询所有功能

功能描述：指定产品，获取该产品下所有modbus功能信息。

```
GET  /api/v1/products/{productId}/properties/modbus
```

**Response:**

```
{
    "success": true,
    "code": 0,
    "msg": "",
    "data": [
        {
                    "id": 18,
                    "name": "sd_123",
                    "identifier": "ws_2345",
                    "accessMode": 1,
                    "type": 2,
                    "unit": "2wsss",
                    "minimum": 10,
                    "maximum": 20,
                    "minString": null,
                    "maxString": null,
                    "productId": 10023,
                    "userId": "eec42ceb4c597a3ce7f0b",
                    "nodeName": null,
                    "readFlag": "",
                    "writeFlag": "",
                    "Scalingfactor": 2.0,
                    "swapByte": 0,
                    "swapOrder": 0,
                    "reportMethod": "time",
                    "registerAddress": "0x0",
                    "registerNumber": 2
        },
        {
                    "id": 28,
                    "name": "cww_123",
                    "identifier": "pww_2345",
                    "accessMode": 1,
                    "type": 2,
                    "unit": "22w3e",
                    "minimum": 10,
                    "maximum": 20,
                    "minString": null,
                    "maxString": null,
                    "productId": 1008764,
                    "userId": "qws3w3c42ceb4c597a3ce7f0b",
                    "nodeName": null,
                    "readFlag": "",
                    "writeFlag": "",
                    "Scalingfactor": 3.0,
                    "swapByte": 0,
                    "swapOrder": 0,
                    "reportMethod": "time",
                    "registerAddress": "0x0",
                    "registerNumber": 2
        }
    ]
}
```
