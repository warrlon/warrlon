# 删除子设备接口

#### 接口名称

> deleteSubDevice

#### 请求方法

> POST

#### 请求参数

| 参数名称   | 类型   | 是否必选 | 描述   |
| :--------- | :----- | :------- | :----- |
| topic | string | 是       | $sys/{pid}/{device-name}/thing/sub/topo/delete |
| protocol | string | 是       | 协议名称，包含MQTT,OTHER|

#### 返回数据

| 参数名称          | 类型    | 描述                       |
| :---------------- | :------ | :------------------------- |
| errno              | int  | 调用失败时，返回的错误码序号   |
| error               | string  | 调用失败时，返回的错误码 |

#### 示例

##### 请求示例

```
POST /proxy/device/thing/topo/delete?topic=$sys/9701D5Lc56/device2/thing/sub/topo/delete&protocol=mqtt
{
    "id":"123",
    "version":"1.0",
    "params":{
        "deviceName":"childDevice1",
        "productID":"MdKy5u6o5e",
        "sasToken":"xxxxxxxxxxxxxxxxx"
    }
}
```


##### 响应示例

```
{
    "errno": 0,
    "error": "succ"
}
```
