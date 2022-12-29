# 子设备上下线

[1. 子设备上线](#1-子设备上线)

[2. 子设备下线](#2-子设备下线)

---

### 1. 子设备上线

子设备上线之前，需和网关绑定拓扑关系；
子设备上线时，平台会根据拓扑关系进行子设备验证，以确定子设备是否有使用网关通道的权利；

    若用户不关心子设备的在线状态，该流程为可选流程，子设备在线状态会显示为未知

- 请求topic: $sys/{pid}/{device-name}/thing/sub/login


    因子设备通过网关通道与物联网平台建立通信，以上topic为网关设备的topic。topic中的变量{pid}和{device-name}需替换为网关设备对应信息。

OneJSON数据格式:

```json
{
  "id": "123",
  "version": "1.0",
  "params": {
    "productID": "product1",
    "deviceName": "device1"
  }
}
```

表：请求参数描述

| 参数       | 类型   | 说明                                                         |
| :--------- | :----- | :----------------------------------------------------------- |
| id         | String | 消息id号，用户自定义，String类型的数字，长度限制不超过13位。 |
| version    | String | 物模型版本号，可选字段，不填默认为1.0                        |
| params     | Object | 请求入参，包含的具体参数见下表params。                       |
| deviceName | String | 子设备的设备名称。                                           |
| productID  | String | 子设备所属产品的productID。                                  |

- 响应topic:$sys/{pid}/{device-name}/thing/sub/login/reply


    因子设备通过网关通道与物联网平台建立通信，以上topic为网关设备的topic。topic中的变量{pid}和{device-name}需替换为网关设备对应信息。

OneJSON数据格式:

```json
{
    "id":"123",
    "code":200,
    "msg":"xxxx"
}
```

| 参数 | 类型    | 说明                                                         |
| :--- | :------ | :----------------------------------------------------------- |
| id   | String  | 消息id号，用户自定义，String类型的数字，长度限制不超过13位。 |
| code | Integer | 返回结果，200代表成功。                                      |
| msg  | String  | 结果信息，可选项。                                           |

### 2. 子设备下线

    若用户不关心子设备的在线状态，该流程为可选流程，子设备在线状态会显示为未知

- 请求topic:$sys/{pid}/{device-name}/thing/sub/logout


    因子设备通过网关通道与物联网平台建立通信，以上topic为网关设备的topic。topic中的变量{pid}和{device-name}需替换为网关设备对应信息。

OneJSON数据格式:

```json
{
  "id": "123",
  "version": "1.0",
  "params": {
    "productID": "product1",
    "deviceName": "device1"
  }
}
```

表：请求参数描述

| 参数       | 类型   | 说明                                                         |
| :--------- | :----- | :----------------------------------------------------------- |
| id         | String | 消息id号，用户自定义，String类型的数字，长度限制不超过13位。 |
| version    | String | 物模型版本号，可选字段，不填默认为1.0                        |
| params     | Object | 请求入参，包含的具体参数见下表params。                       |
| deviceName | String | 子设备的设备名称。                                           |
| productID  | String | 子设备所属产品的productID。                                  |

- 响应topic:$sys/{pid}/{device-name}/thing/sub/logout/reply


    因子设备通过网关通道与物联网平台建立通信，以上topic为网关设备的topic。topic中的变量{pid}和{device-name}需替换为网关设备对应信息。

OneJSON数据格式:

```json
{
    "id":"123",
    "code":200,
    "msg":"xxxx"
}
```

表:响应参数描述

| 参数 | 类型    | 说明                                                         |
| :--- | :------ | :----------------------------------------------------------- |
| id   | String  | 消息id号，用户自定义，String类型的数字，长度限制不超过13位。 |
| code | Integer | 返回结果，200代表成功。                                      |
| msg  | String  | 结果信息，可选项。                                           |
