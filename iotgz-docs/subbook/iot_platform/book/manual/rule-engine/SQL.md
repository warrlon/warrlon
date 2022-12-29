# SQL语句

[本页目录]()

[示例](#1)

[SQL SELECT语句](#2)

[SQL WHERE语句](#3)

OneNET将系统的基础消息格式设计为json格式，其数据可以映射为虚拟的表，数据中的Key对应表的列，Value对应列值，规则引擎支持SQL语句对该数据进行处理，如下图所示：

![](/images/LwM2M/SQL.jpg)


<h2 id="1">示例</h2>

消息源选择为设备数据点消息，基础消息格式示例如下：
```json
{
    "sysProperty": {
        "messageType": "deviceDatapoint",
        "productId": "90273"
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

SQL示例：
```sql
SELECT appProperty.deviceId as did, body as weather FROM /deviceDatapoint/ds WHERE body.temperature > 10
```
该SQL语句表示：
    
> 筛选设备上传数据点的消息，当body的value大于10的时候，提取 appProperty.deviceId 属性，并重命名为 did；提取body属性，重命名为temperature ，消息重组后进行转发

经过该SQL处理的消息输出如下消息

```json
{
    "did": "90273",
    "weather": {
        "temperature": 30,
        "humidity": "47%"
    }
}
```

<h2 id="2">SELECT </h2>

- 默认为 *，即不做任何提取与重组操作
- 支持 as，可对提取出的属性进行重命名，示例如下：
```sql
SELECT body as temperature
```
- 支持使用 json path 获取嵌套 json 中的属性值，示例如下：
```sql
SELECT appProperty.deviceId as did
```
- 支持通过逗号(,) 进行多个属性的提取与重命名，示例如下：
```sql
SELECT appProperty.deviceId as did, appProperty.dataTimestamp as t
```
- 不支持子SQL查询
- SELECT语句中的最多支持10个查询字段

<h2 id="3">WHERE</h2>

WHERE语句用于定义规则触发条件

- 支持使用 json path 获取嵌套 json 中的属性值，同SELECT，示例如下：
```sql
SELECT * WHERE body.temperature > 10
```
- 支持对数值类型进行大于、小于、等于判断，示例如下：
```sql
SELECT * WHERE body.temperature = 10
```
- 支持对字符类型进行匹配判断，示例如下：
```sql
SELECT * WHERE body.humidity = '47%'
```
- 支持多个表达式的 "与" "或"条件运算，示例如下：
```sql
SELECT * WHERE body.temperature > 10 AND body.temperature < 30
```
表达式支持详情见下表

#### 条件表达式支持列表

<table>
<tr><th width="20%">操作符</th><th width="30%">说明</th><th>举例</th></tr>
<tr><td>=</td><td>相等</td><td>temperature=20</td></tr>
<tr><td>!=</td><td>不等于</td><td>temperature!=20</td></tr>
<tr><td>AND</td><td>逻辑与</td><td>temperature=20 AND country='CN'</td></tr>
<tr><td>OR</td><td>逻辑或</td><td>temperature=20 OR country='CN'</td></tr>
<tr><td>( )</td><td>括号中表达式优先计算</td><td>temperature=20 AND (country='CN' OR online = true)</td></tr>
<tr><td>+</td><td>算术加法</td><td>4+5</td></tr>
<tr><td>-</td><td>算术减法</td><td>5-4</td></tr>
<tr><td>/</td><td>算术除法</td><td>10/5</td></tr>
<tr><td>*</td><td>算术乘法</td><td>2*5</td></tr>
<tr><td>%</td><td>取余</td><td>20%7</td></tr>
<tr><td>&lt;</td><td>小于</td><td>5&lt;6</td></tr>
<tr><td>&lt;=</td><td>小于等于</td><td>5&lt;=6</td></tr>
<tr><td>&gt;</td><td>大于</td><td>5&gt;4</td></tr>
<tr><td>&gt;=</td><td>大于等于</td><td>5&gt;=4</td></tr>
</table>
