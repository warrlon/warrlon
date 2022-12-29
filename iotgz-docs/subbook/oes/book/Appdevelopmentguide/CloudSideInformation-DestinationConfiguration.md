# 目的地址配置

## 测试目的地址配置

功能描述：创建目的地配置前，测试目的地配置是否能连接到客户端

```
POST  /api/v1/address-configs/connection/testing
```

**Body:**

**公共参数：**

| Name        | Type     | Description                                             | Required |
| ----------- | -------- | ------------------------------------------------------- | -------- |
| type | int | 转发方式（1:REST / 2:MQTT / 3:KAFKA / 4:MYSQL) | Yes      |
| env | int | 1：云端；2：边缘端 | Yes |

**输入type相关差异参数**


- REST 特有参数

| Name  | Type   | Description            | Required |
| ----- | ------ | ---------------------- | -------- |
| path  |string | 访问路径，REST仅有属性 | Yes      |
| host   | string   | 转发主机地址， IP或者域名 | Yes      |
| port | int | 端口， 1~65535 | Yes |

- MQTT时特有参数

| Name     | Type   | Description       | Required |
| -------- | ------ | ----------------- | -------- |
| clientId | string | 客户端ID          | Yes      |
| username | string | 用户名            | Yes      |
| password | string | 密码              | Yes      |
| topic    | string | MQTT指定推送topic | Yes      |
| host   | string   | 转发主机地址， IP或者域名 | Yes      |
| port | int | 端口， 1~65535 | Yes |

- KAFKA 时特有参数

| Name  | Type   | Description         | Required |
| ----- | ------ | ------------------- | -------- |
| topic | string | KAFKA指定推送topic  | Yes      |
| addr  | string | KAFKA地址，支持集群 | Yes      |

- MYSQL时特有参数

| Name     | Type   | Description | Required |
| -------- | ------ | ----------- | -------- |
| username | string | 用户名      | Yes      |
| password | string | 密码        | Yes      |
| database | string | 数据库      | Yes      |
| table    | string | 表名        | Yes      |
| host   | string   | 转发主机地址， IP或者域名 | Yes      |
| port | int | 端口， 1~65535 | Yes |



body example（REST）：

```
{
    "type":1,
    "env":1,
    "host":"10.12.6.24",
    "port":31694,
    "path":"/api/v1/product"
}
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

---


## 新增目的地址配置

功能描述：新建目的地配置，返回该配置的id。

```
POST  /api/v1/address-configs  
```

**Body:**

**公共参数：**

| Name        | Type     | Description                                             | Required |
| ----------- | -------- | ------------------------------------------------------- | -------- |
| name        | string   | 目的地址名称                                         | Yes      |
| type | int | 转发方式（1:REST / 2:MQTT / 3:KAFKA / 4:MYSQL) | Yes      |
| env | int | 1：云端；2：边缘端 | Yes |

**输入type相关差异参数**


- REST 特有参数

| Name  | Type   | Description            | Required |
| ----- | ------ | ---------------------- | -------- |
| path  |string | 访问路径，REST仅有属性 | Yes      |
| host   | string   | 转发主机地址， IP或者域名 | Yes      |
| port | int | 端口， 1~65535 | Yes |

- MQTT时特有参数

| Name     | Type   | Description       | Required |
| -------- | ------ | ----------------- | -------- |
| clientId | string | 客户端ID          | Yes      |
| username | string | 用户名            | Yes      |
| password | string | 密码              | Yes      |
| topic    | string | MQTT指定推送topic | Yes      |
| host   | string   | 转发主机地址， IP或者域名 | Yes      |
| port | int | 端口， 1~65535 | Yes |

- KAFKA 时特有参数

| Name  | Type   | Description         | Required |
| ----- | ------ | ------------------- | -------- |
| topic | string | KAFKA指定推送topic  | Yes      |
| addr  | string | KAFKA地址，支持集群 | Yes      |

- MYSQL时特有参数

| Name     | Type   | Description | Required |
| -------- | ------ | ----------- | -------- |
| username | string | 用户名      | Yes      |
| password | string | 密码        | Yes      |
| database | string | 数据库      | Yes      |
| table    | string | 表名        | Yes      |
| host   | string   | 转发主机地址， IP或者域名 | Yes      |
| port | int | 端口， 1~65535 | Yes |



body example（MQTT）：

```
{
	"name":"test_addrconfig_rest05",
	"type":2,
    "addr":"",
    "env": 1,
	"host":"www.baidu.com",
	"port":23,
	"clientId":"10001",
	"username":"eminem",
	"password":"123456",
	"topic":"GoodDay"
}
```

**Responses:**

```
{
  "success": true,
  "code": 0,
  "msg": "",
  "data": 10121
}
```

---

## 获取目的地址配置

功能描述：获取一个目的地配置信息。

```
GET  /api/v1/address-configs/{id} 
```

**Responses:**

```
{
  "success": true,
  "code": 0,
  "msg": "",
  "data": {
    "id": 10121,
    "addr":"",
    "env": 1,
    "platform": 1,
    "name": "test_addrconfig_mqtt",
    "type": 2,
    "host": "www.baidu.com",
    "port": 23,
    "clientid": "10001",
    "username": "eminem",
    "password": "123456",
    "database": "",
    "table": "",
    "topic": "GoodDay",
    "path": "",
    "created": 1566553594817,
    "modified": 1566553594817
  }
}
```



---



## 修改目的地址配置

功能描述：修改指定的目的地配置。

```
PUT  /api/v1/address-configs/{id}
```

**Body:**

**公共参数：**

| Name | Type   | Description                                    | Required |
| ---- | ------ | ---------------------------------------------- | -------- |
| name | string | 目的地址名称                                   | No       |
| type | int    | 转发方式（1:REST / 2:MQTT / 3:KAFKA / 4:MYSQL) | No       |

**输入type相关差异参数**

- REST 特有参数

| Name | Type   | Description            | Required |
| ---- | ------ | ---------------------- | -------- |
| path | string | 访问路径，REST仅有属性 | No       |
| host | string | 转发主机地址， IP或者域名                      | No       |
| port | int    | 端口， 1~65535                                 | No      |

- MQTT时特有参数

| Name     | Type   | Description       | Required |
| -------- | ------ | ----------------- | -------- |
| clientid | string | 客户端ID          | No       |
| username | string | 用户名            | No       |
| password | string | 密码              | No       |
| topic    | string | MQTT指定推送topic | No       |
| host | string | 转发主机地址， IP或者域名                      | No       |
| port | int    | 端口， 1~65535                                 | No      |

- KAFKA 时特有参数

| Name  | Type   | Description         | Required |
| ----- | ------ | ------------------- | -------- |
| topic | string | KAFKA指定推送topic  | No       |
| addr  | string | KAFKA地址，支持集群 | No       |

- MYSQL时特有参数

| Name     | Type   | Description | Required |
| -------- | ------ | ----------- | -------- |
| username | string | 用户名      | No       |
| password | string | 密码        | No       |
| database | string | 数据库      | No       |
| table    | string | 表名        | No       |
| host | string | 转发主机地址， IP或者域名                      | No       |
| port | int    | 端口， 1~65535                                 | No      |



**Responses:**

```
{
  "success": true,
  "code": 0,
  "msg": "",
  "data": 10121
}
```



---





## 删除目的地址配置

功能描述：删除一个指定的目的地配置。

```
DELETE  /api/v1/address-configs/{id} 
```

**Responses:**

```
{
  "success": true,
  "code": 0,
  "msg": "",
  "data": "true"
}
```



---







## 分页查询目的地址配置

功能描述：分页查询目的地配置信息，返回结果包括目的地址配置列表和总数量。

```
GET  /api/v1/address-configs
```
**Query:**

| Name           | Description              | Required | Type   | marks                           |
| -------------- | ------------------------ | -------- | ------ | ------------------------------- |
| type           | 转发方式                 | Yes      | int    | 值参考新增目的地配置（0：所有）  |
| pageSize       | 分页大小                 | Yes      | int    |                                 |
| currentPage    | 页码                     | Yes      | int    |                                 |
| name    | 名称模糊查询字段                     | No      | string    |                                 |
| env    |  目的地类型：1-云端，2-边缘端，0-全部；默认全部| No      | int    |                                 |

**Responses:**

```
{
    "data": {
        "currentPage": 1,
        "pageSize": 5,
        "totalCount": 2,
        "totalPage": 1,
        "content": [
            {
                "env": 1,
                "addr": null,
                "clientId": null,
                "database": "",
                "host": "36.155.102.137",
                "password": null,
                "path": "/path",
                "port": 9005,
                "topic": null,
                "type": 1,
                "username": null,
                "table": "",
                "id": "13593",
                "created": 1581563325751,
                "modified": 1581563325751,
                "userId": "38869",
                "name": "rest1",
                "platform": 1,
                "ownerName": null
            },
            {
                "env": 1,
                "addr": null,
                "clientId": null,
                "database": "",
                "host": "36.155.102.137",
                "password": null,
                "path": "/path",
                "port": 9005,
                "topic": null,
                "type": 1,
                "username": null,
                "table": "",
                "id": "13591",
                "created": 1581563275566,
                "modified": 1581563275566,
                "userId": "38869",
                "name": "rest",
                "platform": 1,
                "ownerName": null
            }
        ]
    },
    "success": true,
    "code": 0,
    "msg": null
}
```



------



## 批量删除目的地址配置

功能描述：删除一个指定的目的地配置。

```
DELETE  /api/v1/address-configs
```

**Body:**

| Name | Type  | Description      | Required |
| ---- | ----- | ---------------- | -------- |
| ids  | []int | 目的地配置id数组 | Yes      |
**Request example:**

```
[53333,277777]
```
**Responses:**

```
{
  "success": true,
  "code": 0,
  "msg": "",
  "data": "true"
}
```
