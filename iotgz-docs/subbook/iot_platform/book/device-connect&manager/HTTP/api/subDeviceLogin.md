# 子设备上线接口

#### 接口名称

> subDeviceLogin

#### 请求方法

> POST

#### 请求参数

| 参数名称   | 类型   | 是否必选 | 描述   |
| :--------- | :----- | :------- | :----- |
| topic | string | 是       | $sys/{pid}/{device-name}/thing/sub/login |
| protocol | string | 是       | 协议名称，包含MQTT,OTHER|

#### 返回数据

| 参数名称          | 类型    | 描述                       |
| :---------------- | :------ | :------------------------- |
| errno              | int  | 调用失败时，返回的错误码序号   |
| error               | string  | 调用失败时，返回的错误码 |

#### 示例

##### 请求示例

```
POST /proxy/device/thing/login?topic=$sys/9701D5Lc56/device2/thing/sub/login&protocol=mqtt
{
  "id": "123",
  "version": "1.0",
  "params": {
    "productID": "k5NIV817Ww", 
    "deviceName": "childDevice1"
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
