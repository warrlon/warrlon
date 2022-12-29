# 命令管理

功能意义：命令下发会指定某台设备，并对此设备的指定属性进行同步或异步读写。
### MQTT设备下发命令读取/写入功能点属性信息

功能描述：提供对MQTT设备的读，写命令的下发功能，返回命令执行的结果。

注：需要设备在线。

```
POST  /api/v1/commands/mqtt
```

**Body**

|     Name     |  Type  |                         Description                          | Required |
| :----------: | :----: | :----------------------------------------------------------: | :------: |
|   deviceId   |  int   |                            设备ID                            |   Yes    |
| functionType | string |           命令类型，可选值propertyGet\|propertySet           |   Yes    |
|  identifier  | string |                            属性名                            |   Yes    |
|    identifierValue     | object | 属性值，functionType值为propertySet时必需，值类型：String/Integer/Long/Float/Double/Boolean/Date/Bytes |    No    |

body example

```
{
	"deviceId": 674,
	"functionType": "propertySet",
	"identifier": "tempratrue",
	"value": 30
}
```

**Response:**

```
{
  "success": true,
  "code": 0,
  "msg": "succeed"
}
```

### Modbus-Gateway设备下发命令读取/写入功能点属性信息

功能描述：提供对modbus设备的读，写命令的下发功能，通过网关设备进行数据的上传和下发，返回命令执行的结果。

注：需要设备绑定到网关设备，并且网关设备在线。

```
POST  /api/v1/commands/modbus
```

**Body**

|     Name     |  Type  |                         Description                          | Required |
| :----------: | :----: | :----------------------------------------------------------: | :------: |
|   deviceId   |  int   |                            设备ID                            |   Yes    |
| functionType | string |           命令类型，可选值propertyGet\|propertySet           |   Yes    |
|  identifier  | string |                            属性名                            |   Yes    |
|    identifierValue     | object | 属性值，functionType值为propertySet时必需，值类型：String/Integer/Long/Float/Double/Boolean/Date/Bytes |    No    |

body example

```
{
	"deviceId": 674,
	"functionType": "propertySet",
	"identifier": "tempratrue",
	"value": 30
}
```

**Response:**

```
{
    "success": true,
    "code": 0,
    "msg": "",
    "data": {
        "created": 1552120367158,
        "deviceId": 44,
        "eventId": "1d90124d-1963-41e7-a1f5-4426f5225c98",
        "name": "zhengxing",
        "productId": 16,
        "protocol": "MQTT-STANDARD",
        "value": 123
    }
}
```

### OPC UA设备下发命令读取/写入功能点属性信息

功能描述：提供对OPC UA设备的读，写命令的下发功能，通过网关设备进行数据的上传和下发，返回命令执行的结果。

注：需要设备绑定到网关设备，并且网关设备在线。

```
POST  /api/v1/commands/opcua
```

**Body**

|     Name     |  Type  |                         Description                          | Required |
| :----------: | :----: | :----------------------------------------------------------: | :------: |
|   deviceId   |  int   |                            设备ID                            |   Yes    |
| functionType | string |           命令类型，可选值propertyGet\|propertySet           |   Yes    |
|  identifier  | string |                            属性名                            |   Yes    |
|    identifierValue     | object | 属性值，functionType值为propertySet时必需，值类型：String/Integer/Long/Float/Double/Boolean/Date/Bytes |    No    |

body example

```
{
	"deviceId": 674,
	"functionType": "propertySet",
	"identifier": "tempratrue",
	"value": 30
}
```

**Response:**

```
{
    "success": true,
    "code": 0,
    "msg": "",
    "data": {
        "created": 1552120367158,
        "deviceId": 44,
        "eventId": "1d90124d-1963-41e7-a1f5-4426f5225c98",
        "name": "zhengxing",
        "productId": 16,
        "protocol": "opcua",
        "value": 123
    }
}
```
