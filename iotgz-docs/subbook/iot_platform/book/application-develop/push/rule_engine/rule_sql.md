# SQL语句说明

<a href="#1">1. SELECT说明</a>

<a href="#2">2. WHERE说明</a>

---

系统基础消息数据格式为JSON，可将其映射为虚拟数据表，数据表中的key对应表的列，value对应列值，规则引擎通过SQL语句对数据进行处理，如图所示：

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/application/规则引擎_SQL.png">
</center>

##### 示例：

```
{
    "projectId": "990909090",     
    "productId": "00001",                   
    "deviceName": "iot-0001",     
    "messageType": "notify",
    "notifyType":"property",
    "data": {                         
        "id":  "12345"，                  
        "params": {
            "Power": {
                "value": "on",
                "time": 1524448722123
            },
            "WF": {
                "value": 23.6,
                "time": 1524448722123
            ｝
        ｝
    } 
}
```
SQL 示例:

```
SELECT productId, deviceName, data FROM /deviceDatapoint/ds WHERE notifyType = 'property'

```

该SQL语句表示:

```
筛选设备物模型数据中的属性功能点数据, 提取productId、deviceName和data三个属性字段。
```

经过该SQL处理的消息输出如下消息

```
{
    "productId": "00001",                   
    "deviceName": "iot-0001",     
    "data": {                         
        "id":  "12345"，                  
        "params": {
            "Power": {
                "value": "on",
                "time": 1524448722123
            },
            "WF": {
                "value": 23.6,
                "time": 1524448722123
            ｝
        ｝
    } 
}
```

<h3 id="1">1. SELECT说明</h3>

* 默认为 *，即不做任何提取与重组操作
* 支持 as，可对提取出的属性进行重命名，示例如下：
```
SELECT body as temperature
```
* 支持使用 json path 获取嵌套 json 中的属性值，示例如下：
```
SELECT appProperty.deviceId as did
```
* 支持通过逗号(,) 进行多个属性的提取与重命名，示例如下：
```
SELECT appProperty.deviceId as did, appProperty.dataTimestamp as t
```
* 不支持子SQL查询
* SELECT语句中的最多支持10个查询字段

<h3 id="2">2. WHERE说明</h3>

WHERE语句用于定义规则触发条件

* 支持使用 json path 获取嵌套 json 中的属性值，同SELECT，示例如下：
```
SELECT * WHERE body.temperature > 10
```
* 支持对数值类型进行大于、小于、等于判断，示例如下：
```
SELECT * WHERE body.temperature = 10
```
* 支持对字符类型进行匹配判断，示例如下：
```
SELECT * WHERE body.humidity = '47%'
```
* 支持多个表达式的 "与" "或"条件运算，示例如下：
```
SELECT * WHERE body.temperature > 10 AND body.temperature < 30
```
表达式支持详情见下表

| 操作符 | 说明 | 举例 |
|:- | :- | :- |
|=|相等|	temperature=20|
|!=|	不等于|	temperature!=20|
|AND|	逻辑与|	temperature=20 AND country='CN'|
|OR|	逻辑或|	temperature=20 OR country='CN'|
|( )|	括号中表达式优先计算|	temperature=20 AND (country='CN' OR online = true)|
|+	|算术加法|	4+5|
|-|	算术减法	|5-4|
|/	|算术除法	|10/5|
|*|	算术乘法	|2*5|
|%|	取余|	20%7|
|<|	小于|	5<6|
|<=|	小于等于	|5<=6|
|>|	大于	|5>4|
|>=|	大于等于|	5>=4|