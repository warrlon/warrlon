# 获取拓扑关系接口

#### 接口名称

> getTopo

#### 请求方法

> POST

#### 请求参数

| 参数名称   | 类型   | 是否必选 | 描述   |
| :--------- | :----- | :------- | :----- |
| topic | string | 是       | $sys/{pid}/{device-name}/thing/sub/topo/get |
| protocol | string | 是       | 协议名称，包含MQTT,OTHER|

#### 返回数据

| 参数名称          | 类型    | 描述                       |
| :---------------- | :------ | :------------------------- |
| errno              | int  | 调用失败时，返回的错误码序号   |
| error               | string  | 调用失败时，返回的错误码 |
| data              | -       | 调用成功时，返回的业务数据 |

#### 示例

##### 请求示例

```
POST /proxy/device/thing/topo/get?topic=$sys/9701D5Lc56/test2/thing/sub/topo/get&protocol=other
{
    "id":"123",
    "version":"1.0"
}
```


##### 响应示例

```
{
    "errno": 0,
    "data": [
        {
            "productID": "k5NIV817Ww",
            "deviceName": "ChildDevice2"
        },
        {
            "productID": "k5NIV817Ww",
            "deviceName": "childDevice1"
        }
    ],
    "error": "succ"
}
```
