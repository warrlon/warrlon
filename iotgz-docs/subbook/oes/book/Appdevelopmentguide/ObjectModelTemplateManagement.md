# 物模型模板管理

## 创建物模型模板

功能描述：创建物模型模板。

```
POST  /api/v1/objtemplate
```

**Body:**

| Name         | Type   | Description                                      | Required |
| ------------ | ------ | ------------------------------------------------ | -------- |
| name         | string | 模板名称                                         | Yes      |
| protocolType | int    | 物模型协议 （1 : MQTT;  4 : MODBUS; 5 : OPC UA） | Yes      |
| description  | string | 描述信息                                         | No       |

**Responses:**

```
{
  "success": true,
  "code": 0,
  "msg": "",
  "data": {
    "content": "",
    "id": 109,
    "userId": "bb5f2d0f4fad4d2ab1897d3fdca7c5c3",
    "created": 1577331855217,
    "modified": 1577331855217,
    "name": "test1111",
    "description": "string",
    "protocolType": 1,
    "platform": 2
  }
}
```

## 分页查询物模型模板

功能描述：分页查询物模型模板。

```
GET  /api/v1/objtemplate/page
```

**Query:**

| Name        | Type   | Description        | Required |
| ----------- | ------ | ------------------ | -------- |
| name        | string | 模板名称，模糊查询 | No       |
| currentPage | int    | 当前页码           | Yes      |
| pageSize    | int    | 分页大小           | Yes      |

**Responses:**

content即为功能列表

```
{
  "data": {
    "currentPage": 1,
    "pageSize": 5,
    "totalCount": 1,
    "totalPage": 1,
    "content": [
      {
        "name": "test1111",
        "protocolType": 1,
        "description": "string",
        "content": "[{\"accessMode\":2,\"identifier\":\"ttttt\",\"maxString\":\"\",\"minString\":\"\",\"name\":\"test\",\"nodeName\":\"ttttt\",\"productId\":108,\"type\":2,\"unit\":\"\"}]",
        "created": 1577331855217,
        "id": 109,
        "modified": 1577331855217,
        "platform": 2,
        "userId": "bb5f2d0f4fad4d2ab1897d3fdca7c5c3"
      }
    ]
  },
  "success": true,
  "code": 0,
  "msg": null
}
```

## 查询单个物模型模板详情

功能描述：查询单个物模型模板详情。

```
GET  /api/v1/objtemplate/id/{id}
```

**Responses:**

content即为功能列表

```
{
  "data": {
    "name": "opcua11111",
    "protocolType": 5,
    "description": "",
    "content": "[{\"accessMode\":2,\"identifier\":\"ttttt\",\"maxString\":\"\",\"minString\":\"\",\"name\":\"test\",\"nodeName\":\"ttttt\",\"productId\":108,\"type\":2,\"unit\":\"\"}]",
    "created": 1577329097139,
    "id": 108,
    "modified": 1577329629622,
    "platform": 2,
    "userId": "bb5f2d0f4fad4d2ab1897d3fdca7c5c3"
  },
  "success": true,
  "code": 0,
  "msg": null
}
```
## 更改物模型模板

功能描述：更改物模型模板的基础信息。

```
PUT  /api/v1/objtemplate
```

**Body:**

| Name        | Type   | Description | Required |
| ----------- | ------ | ----------- | -------- |
| id          | int    | 模板id      | Yes      |
| name        | string | 模板新名字  | No       |
| description | string | 模板新描述  | No       |



**Responses:**

```
{
  "success": true,
  "code": 0,
  "msg": "",
  "data": null
}
```
## 删除物模型模板

功能描述：删除物模型模板。

```
Delete  /api/v1/objtemplate/id/{id}
```
**Responses:**

```
{
  "success": true,
  "code": 0,
  "msg": "",
  "data": null
}
```
## 为物模型模板设置产品功能列表

功能描述：给物模型模板设置功能列表，会覆盖当前的功能列表。

```
PUT  /api/v1/objtemplate/property
```

**Body:**

| Name               | Type     | Description           | Required                                     |
| ------------------ | -------- | --------------------- | -------------------------------------------- |
| id                 | int      | 模板id                | Yes                                          |
| propertyList       | struct[] | 功能列表(MQTT/OPC UA) | No(propertyList和modbusPropertyList必传其一) |
| modbusPropertyList | struct[] | MODBUS功能列表        | No(propertyList和modbusPropertyList必传其一) |

**propertyList的子对象结构体:**

| Name       | Type   | Required               | Description                                                  |
| ---------- | ------ | ---------------------- | ------------------------------------------------------------ |
| name       | string | Yes                    | 功能名称                                                     |
| identifier | string | Yes                    | 属性名称(该产品下唯一)                                       |
| accessMode | int    | Yes                    | 属性读写类型，只读(1：R)，读写(2：RW)                        |
| type       | int    | Yes                    | 数据类型，支持以下几种：bytes/string/boolean/date/int32/int64/float32/float64。具体值参考后面 “属性type类型码表”。 |
| unit       | string | No                    | 属性单位                                                     |
| minString | string | No，type为数值类型必填 | 参数最小值(数值类型特有)                            |
| maxString | string | No，type为数值类型必填 | 参数最大值(数值类型特有)                              |
| nodeName    | String | No | 节点名称                                     |
**modbusPropertyList的子对象结构体:**

| Name            | Type   | Required               | Description                                                  |
| --------------- | ------ | ---------------------- | ------------------------------------------------------------ |
| name            | string | Yes                    | 功能名称                                                     |
| identifier      | string | Yes                    | 属性名称(该产品下唯一)                                       |
| unit            | string | No                     | 属性单位                                                     |
| readFlag        | string | Yes                    | 读命令码，16进制值，支持值选项： 线圈状态 "0x01"; 离散输入变量 "0x02"; 保持寄存器 "0x03"; 输入寄存器 "0x04" |
| writeFlag       | string | No                     | 写命令码，16进制值，支持值选项：线圈状态 "0x05" ,"0x0F"； 保持寄存器 "0x06" ,"0x10" |
| type            | int    | Yes                    | 数据类型，支持类型：int16/uint16/int32/uint32/int64/uint64/float32/float64/string/bool,<br>当读命令码为"0x01"(线圈状态)，"0x02"（离散输入变量）时该参数值只能为bool。数据类型值请参考表下类型码表。 |
| swapByte        | int    | No                     | 是否交换高低字节(不变：0；变：1)，把寄存器内16位数据的前后8个bits互换。默认为0。该字段仅对type为数值类型有效。其他类型将设置为1。 |
| swapOrder       | int    | No                     | 是否交换顺序(不变：0；变：1)，把原始数据32位数据的bits互换。默认为1。该字段仅对type为数值类型有效。其他类型将设置为0。 |
| scalingfactor   | double | Yes                    | 缩放因子，此字段只有type为数值类型有效，默认为1.0。有效值不能为0。 |
| reportMethod    | int    | No                     | 上报方式，目前只支持按时上报，值 1 : time,  默认为该值       |
| registerAddress | string | Yes                    | 寄存器起始地址,16进制值，范围0x0000~0xffff                   |
| registerNumber  | int    | type为string类型时必填 | 寄存器个数，用于确定string类型的数据占用长度。只有type为string时该数据有效。 |
| originDataType  | int    | Yes                    | 原始数据类型，数据类型值请参考表下类型码表。                 |

属性type类型码表

| bytes     | string     | boolean    | date       | int8        | int16       | int32 | int64 |
| --------- | ---------- | ---------- | ---------- | ----------- | ----------- | ----- | ----- |
| 1         | 2          | 3          | 4          | 5           | 6           | 7     | 8     |
| **uint8** | **uint16** | **uint32** | **uint64** | **float32** | **float64** |       |       |
| 9         | 10         | 11         | 12         | 13          | 14          |       |       |

下表格为参数readFlag，writeFlag与accessMode之间的关系图。

| 操作类型                                  | readFlag                                       | writeFlag                          | accessMode                                        |
| -------------------------------------------------- | --------------------------------- | -------------------------------------------- | -------------------------------------------- |
| 1.线圈状态,只读 | 0x01 | 无 | 1 |
| 2.线圈状态,读写 | 0x01 | 0x05           | 2 |
| 3.线圈状态,读写 | 0x01 | 0x0F | 2   |
| 4.离散量输入,只读 | 0x02 | 无 | 1 |
| 5.保持寄存器,只读 | 0x03 | 无 | 1 |
| 6.保持寄存器,读写 | 0x03  | 0x06    | 2   |
| 7.保持寄存器,读写 | 0x03 | 0x10  | 2   |
| 8.输入寄存器,只读 | 0x04 | 无 | 1 |

**Responses:**

```
{
  "success": true,
  "code": 0,
  "msg": "",
  "data": {
    "content": "",
    "id": 109,
    "userId": "bb5f2d0f4fad4d2ab1897d3fdca7c5c3",
    "created": 1577331855217,
    "modified": 1577331855217,
    "name": "test1111",
    "description": "string",
    "protocolType": 1,
    "platform": 2
  }
}
```
## 使用模板创建非Modbus产品功能

功能描述：使用模板创建产品功能。

```
POST  /api/v1/objtemplate/property/withtemplate
```

**Body:**

| Name        | Type   | Description | Required |
| ----------- | ------ | ----------- | -------- |
| productId   | int    | 产品ID      | No       |
| templateId  | int    | 物模版ID    | No       |


**Responses:**

```
{
  "success": true,
  "code": 0,
  "msg": "",
  "data": null
}
```


## 使用模板创建Modbus产品功能

功能描述：使用模板创建Modbus产品功能。

```
POST  /api/v1/objtemplate/modbusproperty/withtemplate
```

**Body:**

| Name        | Type   | Description | Required |
| ----------- | ------ | ----------- | -------- |
| productId   | int    | 产品ID      | No       |
| templateId  | int    | 物模版ID    | No       |


**Responses:**

```
{
  "success": true,
  "code": 0,
  "msg": "",
  "data": null
}
```
