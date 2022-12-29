# SQL语句说明
    这是规则引擎2.0 SQL语法详解

##### 数据示例
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
                }
            }
        }  
    }

##### SQL示例
    SELECT productId, deviceName as dn, data FROM /deviceDatapoint/ds WHERE notifyType == "property" AND data.params.Power.value == "on"

##### 该SQL语句表示:
    筛选设备物模型数据中的属性功能点数据, 提取productId、deviceName和data三个属性字段。并将deviceName字段重命名为dn。

##### 经过该SQL处理的消息输出如下消息
    {
        "productId": "00001",                   
        "dn": "iot-0001",     
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
                }
            }
        }
    } 

### 1. SELECT说明

· 默认为 *，即不做任何提取与重组操作

· 支持 as，可对提取出的属性进行重命名，示例如下：

    SELECT body as temperature

· 支持使用 json path 获取嵌套 json 中的属性值，示例如下：

    SELECT appProperty.deviceId as did

· 支持通过逗号(,) 进行多个属性的提取与重命名，示例如下：

    SELECT appProperty.deviceId as did, appProperty.dataTimestamp as t

· 支持通过函数进行查询字段的组合和处理

    SELECT @concat("One", "NET"), @b64decode(b64str)

· 不支持子SQL查询

### 2. WHERE说明

WHERE语句用于定义规则触发条件

·支持使用 json path 获取嵌套 json 中的属性值，同SELECT，示例如下：

    SELECT * WHERE body.temperature > 10

·支持对数值类型进行大于、小于、等于判断，示例如下：

    SELECT * WHERE body.temperature == 10

·支持对字符类型进行like模糊匹配判断，示例如下：

    SELECT * WHERE body.humidity like "47%"

·支持多个表达式的 "与" "或"条件运算，示例如下：

    SELECT * WHERE body.temperature > 10 AND body.temperature < 30

·支持判定条件之间的一级嵌套，示例如下

    SELECT * WHERE (body.temperature < 10 OR body.temperature>=30) AND body.humidity like "47%"

· 支持通过函数进行条件筛选

    SELECT * WHERE @upper("OneNET") == "ONENET" AND @startswith("OneNET", "One")

### WHERE条件筛选语法示例 

```
示例1、((1+(4/2))>=3) and (x<>"abc"||g>=3) and x like "%d!"

示例2、@abs(3-5)>1 && @mod(1-(-1+1),7)==1 && @concat("nihao", "ma") == "nihaoma"

示例3、@crypto("lujiayu","MD5")=="cf0cc2c4cc5a5fe04720bd7ac97b3f39"

示例4、@exists(x) == true && y == NULL
````

#### 表达式和函数支持详情见下表:

| 操作符 | 描述   |       举例      |
| ------ | ------ | --------------- |
|   ==   | 相等   | color == "red"  |
|   <>   | 不等   | color <> "blue" |
|   !=   | 不等   | color != "blue" |
|   &&   | 逻辑与 | color == "red" && siren == "on" |
|   AND   | 逻辑与 | color == "red" AND siren == "on" |
|   &#124;&#124;  | 逻辑或 | color == "red" &#124;&#124; siren == "on" |
|   OR   | 逻辑或 | color == "red" OR siren == "on" |
|   +    | 算术加 | 4 + 5 | 
|   -    | 算术减 | 5 - 4 | 
|   *    | 算术乘 | 5 * 4 | 
|   /    | 算术除 | 5 / 4 | 
|   ^    | 幂次   | 5 ^ 2 | 
|   <    | 小于   | 4 < 5 | 
|   <=   | 小于等于 | 4 <= 5 | 
|   >    | 大于   | 5 > 4 | 
|   >=   | 大于等于 | 5 >= 4 |
|  "str" | 定义字符串，仅支持以一对双引号""括起来的字符串 | "OneNET" |
|   like | 匹配字符串，支持%通配符 | str like "%hello" |
|   ( )  | 括号提升表达式优先级, 支持对判定符的括号和对四则运算的括号  |  (a+b)/c == 1 && (d > 2 &#124;&#124; e < 3) |
|   IN   | IN枚举查询语法，	支持 数字、字符串，不支持子查询。 | x IN("OneNET", "CMIot", "CMCC") |
| JSON属性表达式 | 从消息Payload以JSON表达式提取属性 | state.desired.color[0].d |
| @abs(x) | 绝对值函数 | @abs(-1) = 1 |
| @asin(x) | 反正弦函数 | @asin(x) |
| @b64decode(x) | base64解码 | @b64decode(b64_str) |
| @b64encode(x) | base64编码 | @b64encode(x) |
| @ceil(x) | 浮点数向上取整 | @ceil(1+2.5) = 4 |
| @concat(x, y) | 对两个字符串进行连接 | @concat("iot.", "10086") = "iot.10086" |
| @cos(x) | 余弦函数 | @cos(x) |
| @crypto(x, y) | 对x进行y指定的算法摘要计算，y支持的取值为MD5/SHA1/SHA256/SHA384/SHA512 | @crypto("hello", "MD5") |
| @endswith(x, y) | 判断x字符串是否以y字符串结尾。返回true/false | @endswith("OneNET", "NET") = true |
| @exists(x) | 判断消息payload中是否有对应属性存在 | @exists(x) = true |
| @floor(x) | 浮点数向下取整 | @floor(1+2.5) = 3 |
| @len(x) | 返回字符串长度 | @len("OneNET") = 6 |
| @ln(x) | 自然对数函数,求常数e为底x的对数 | @ln(1) = 0 |
| @log(x) | 对数函数，求10为底x的对数 | @log(10) = 1 |
| @lower(x) | 将字符串中的大写字母转为小写字母 | @lower("HELLO") = "hello" |
| @mod(x,y) | 取余函数,取得x除以y的余数 | @mod(10,7) = 3 |
| @nanvl(x, default) | 带默认值的取值函数，若x存在则返回x的值，否则返回default的值 | @nanvl(x, "x not exists!") |
| @newuuid() | 生成一个全局唯一的uuid，生成的uuid符合UUID4规则 | @newuuid() == "6ec12098-89bd-4eaf-8f5e-2ea181907d8c" |
| @nowtime(\[format]) | 获取当前时间，format支持"yyyy-MM-dd hh:mm:ss"，若不传format参数，则返回当前秒级时间戳 | @nowtime("yyyy-MM") = "2021-07" |
| @rand(\[x]) | 获取随机浮点数，x为随机数最大取值,若不传则默认取0-1之间的随机数 | @rand(10)，返回0-10之间的随机浮点数 |  
| @round(x, y) | 对浮点数x做指定精度的四舍五入截取，y取值为大于等于0的整数 | @round(1.549, 2) = 1.55 ; @round(1.549, 1) = 1.5 ; @round(1.549, 0) = 2 |
| @startswith(x, y) | 判断x字符串是否以y字符串为起始。返回true/false | @startswith("OneNET", "One") = true |
| @substring(str, start, end) | 根据传入的start/end下标数字，截取字符串str | @substring("hello world", 0, 5) = "hello" |
| @sin(x) | 正弦函数 | @sin(x) |
| @trim(x\[, y]) | 返回字符串 x 的一部分，并将 y 中包含的所有前导和尾部字符删除, 若不传y，则删除x前后的空白字符 | @trim("!*+OneNET*+!", "!+") = "*+OneNET*" | 
| @upper(x) | 将字符串中的小写字母转为大写字母 | @upper("hello")，返回结果"HELLO" |
