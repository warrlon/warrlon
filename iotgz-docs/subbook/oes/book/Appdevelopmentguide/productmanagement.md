# 产品管理

## 创建边缘节点产品

功能描述：提供边缘节点（即网关）产品对象新建，返回产品的id和masterKey，用于产品信息鉴权。

```
POST  /api/v1/products/mqtt
```

**Body:**

| Name         | Type   | Description                                                  | Required                                      |
| ------------ | ------ | ------------------------------------------------------------ | --------------------------------------------- |
| name         | string | 产品名称                                                      | Yes                                           |
| description  | string | 产品描述信息                                                  | No                                            |

**Responses:**

```
{
  "success": true,
  "code": 0,
  "msg": "",
  "data": {
    "id": 100109,
    "masterKey": "NTFjYzRiNDNmNGUzZmNhMDYyODQ="
  }
}
```

-----

## 创建边缘终端产品

功能描述：提供产品对象新建，返回产品的id和masterKey，用于产品信息鉴权。

```
POST  /api/v1/products
```

**Body:**

| Name         | Type   | Description                                     | Required |
| ------------ | ------ | ----------------------------------------------- | -------- |
| name         | string | 产品名称                                        | Yes      |
| protocolType | int    | 产品协议 （1 : MQTT;  4 : MODBUS; 5 : OPC UA）  | Yes      |
| nodeType     | int    | 节点类型  (1 : 设备)                            | Yes      |
| model        | int    | 产品模式 （1：物模型）                          | Yes      |
| dataFormat   | int    | 数据类型 （1：标准数据类型 ；3  :  modbus rtu） | Yes      |
| description  | string | 产品描述信息                                    | No       |
| manufacturer | string | 制造商（备用扩展字段）                          | No       |
| category     | int    | 产品分类描述（备用扩展字段）                    | No       |
| netType      | int    | 产品网络连接分类（备用扩展字段）                | No       |

下表格为参数protocolType与model，dataFormat, nodeType之间的关系图。

| protocolType                                       | nodeType                          | model                                        | dataFormat                                                   |
| -------------------------------------------------- | --------------------------------- | -------------------------------------------- | ------------------------------------------------------------ |
| MQTT | 设备 | 物模型 | 标准数据格式 |
| MODBUS                                             | 设备                              | 物模型                                | modbus rtu                                                   |
| OPC UA                                             | 设备                              | 物模型                                | 无 |

**Responses:**

```
{
  "success": true,
  "code": 0,
  "msg": "",
  "data": {
    "id": 100109,
    "masterKey": "NTFjYzRiNDNmNGUzZmNhMDYyODQ="
  }
}
```

-----


## 根据产品ID查询产品信息

功能描述：根据产品的id查询产品，返回产品详细信息。

```
GET  /api/v1/products/{productId}
```

**Responses:**

```
{
  "success": true,
  "code": 0,
  "msg": "",
  "data": {
    "Id": 100109,
    "masterKey": "NTFjYzRiNDNmNGUzZmNhMDYyODQ=",
    "name": "prod_api_dtu",
    "protocolType": 3,
    "model": 0,
    "dataFormat": 3,
    "netType": 0,
    "nodeType": 3,
    "description": "prod_dtu",
    "manufacturer": "",
    "category": 0,
    "userId": "11e57f7f-6b0b-42cf-b629-678c61a58004",
    "created": 1565603715244,
    "modified": 1565603715244,
    "deviceCount": null,
    "platform":1
  }
}
```



-----



## 查询产品列表信息

功能描述：用于产品分页查询，指定当前分页和分页大小。返回具体分页信息和产品查询列表。

```
GET  /api/v1/products
```

**Query:**

| Name           | Description              | Required | Type   | marks                           |
| -------------- | ------------------------ | -------- | ------ | ------------------------------- |
| pageSize       | 分页大小                  | Yes      | int    |                                 |
| currentPage    | 页码                     | Yes      | int    |                                 |
| name           | 产品名，模糊查询          | No       | string |                                 |

**Responses:**

```
{
  "success": true,
  "code": 0,
  "msg": "",
  "data": {
    "totalCount": 4,
    "pageSize": 5,
    "currentPage": 1,
    "totalPage": 1,
    "content": [
      {
        "Id": 100109,
        "masterKey": "NTFjYzRiNDNmNGUzZmNhMDYyODQ=",
        "name": "prod_api_dtu",
        "protocolType": 3,
        "model": 0,
        "dataFormat": 3,
        "netType": 0,
        "nodeType": 3,
        "description": "prod_dtu",
        "manufacturer": "",
        "category": 0,
        "userId": "11e57f7f-6b0b-42cf-b629-678c61a58004",
        "created": 1565603715244,
        "modified": 1565603715244,
        "deviceCount": null
      },
      ...
    ]
  }
}
```



-----



## 更改产品

功能描述：根据产品id和将要更改的产品属性对产品进行更改。

```
PUT  /api/v1/products/{productId}
```

**Body:**

| Name        | Type   | Description | Required |
| ----------- | ------ | ----------- | -------- |
| name        | string | 产品名字    | No       |
| description | string | 产品描述    | No       |

**Responses:**

```
{
  "success": true,
  "code": 0,
  "msg": "",
  "data": null
}
```

## 删除产品

功能描述：根据产品id删除指定产品。

```
DELETE  /api/v1/products/{productId}
```

注：删除产品时会将产品下的设备和脚本同时删除，慎用！！！

**Responses:**

```
{
  "success": true,
  "code": 0,
  "msg": "",
  "data": null
}
```
