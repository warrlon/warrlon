# 基础消息格式

规则引擎对不同的消息源定义了不同的固定基础消息格式，作为规则SQL的处理依据

## 设备数据点消息

设备数据点消息数据格式如下：

<table>
<tr><th width="15%">参数</th><th width="15%">属性</th><th width="15%">类型</th><th width="40%">说明</th><th>示例</th></tr>
<tr>
    <td rowspan="2"> sysProperty
    <td>messageType</td><td>string</td><td>消息类型：固定为deviceDatapoint</td><td> </td>
</tr>
<tr>    
    <td>productId</td><td>string</td><td>产品ID</td><td>90273</td>
</tr>
<tr>
    <td rowspan="3"> appProperty
    <td>deviceId</td><td>string</td><td>设备ID</td><td>102839</td>
</tr>
<tr>
    <td>dataTimestamp</td><td>int</td><td>设备数据点生产时间戳，单位毫秒，设备上传时可自定义携带</td><td>15980987429000</td>
</tr>
<tr>    
    <td>datastream</td><td>string</td><td>数据流名称</td><td>weather</td>
</tr>

<tr>
    <td rowspan="1"> body
    <td> </td><td>object/string/...</td><td>详细的数据点消息内容</td><td>见如下示例</td>
</tr>
</table>



数据json示例1，json数据
```json
{
    "sysProperty": {
        "messageType": "deviceDatapoint",
        "productId": "90273",
    },
    "appProperty":{
        "deviceId": "102839",
        "dataTimestamp": 15980987429000,
        "datastream":"weather"
    },
    "body":{
        "temperature": 30,
        "humidity": "47%"
    }
}
```
数据json示例2，数值型数据
```json
{
    "sysProperty": {
        "messageType": "deviceDatapoint",
        "productId": "90273",
    },
    "appProperty":{
        "deviceId": "102839",
        "dataTimestamp": 15980987429000,
        "datastream":"temperature"
    },
    "body": 10
}
```

数据json示例3，字符串型数据
```json
{
    "sysProperty": {
        "messageType": "deviceDatapoint",
        "productId": "90273",
    },
    "appProperty":{
        "deviceId": "102839",
        "dataTimestamp": 15980987429000,
        "datastream":"weather"
    },
    "body":"sunny with wind"
}
```

数据json示例4，二进制数据

>  **说明**：
> - 数据格式为二进制数据时，body中数据为二进制数据的索引号 *index*，示例如下，用户可以通过该索引号通过API获取该数据

```json
{
    "sysProperty": {
        "messageType": "deviceDatapoint",
        "productId": "90273",
    },
    "appProperty":{
        "deviceId": "102839",
        "dataTimestamp": 15980987429000,
        "datastream":"weather"
    },
    "body":{
        "index": "3491506_1475204886914_bin"
    }
}
```


## 设备生命周期事件消息

设备生命周期事件消息数据格式如下：

<table>
<tr><th width="15%">参数</th><th width="15%">属性</th><th width="15%">类型</th><th width="40%">说明</th><th>示例</th></tr>
<tr>
    <td rowspan="2"> sysProperty
    <td>messageType</td><td>string</td><td>消息类型：固定为deviceLifeCycle</td><td> </td>
</tr>
<tr>    
    <td>productId</td><td>string</td><td>产品ID</td><td>90273</td>
</tr>
<tr>
    <td rowspan="2"> appProperty
    <td>deviceId</td><td>string</td><td>设备ID</td><td>102839</td>
</tr>
<tr>
    <td>dataTimestamp</td><td>int</td><td>设备消息生产时间戳，单位毫秒</td><td>15980987429000</td>
</tr>
<tr>
    <td rowspan="1"> body
    <td> </td><td>object</td><td>创建、删除、上线、离线
created/deleted/online/offline</td><td></td>
</tr>
</table>

数据json示例
```json
{
    "sysProperty": {
        "messageType": "deviceLifeCycle",
        "productId": "90273",
    },
    "appProperty":{
        "deviceId": "102839",
        "dataTimestamp": 15980987429000,
    },
    "body":{
        "event": "online"
    }
}
```

