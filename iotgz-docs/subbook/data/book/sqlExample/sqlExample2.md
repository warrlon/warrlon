### 示例2 - 按天统计

场景：统计每天的流入数据条数，每进来一条数据，就输出一个结果。
当数据源中未含有时间相关的字段，但是又想要根据系统时间，如：按天统计时。建议在数据源中增加时间相关的字段。若无法添加，可以使用如下方式。  

输入节点的结构：

| 字段名| 字段类型|
| :----:| :----:  |
| uid  	| VARCHAR    |
| name 	| VARCHAR   |

输出节点的结构：

| 字段名| 字段类型|是否主键|说明|
| :----:| :----:  |:----: |:----:|
| t_day  	| VARCHAR    |是  |数据被处理的机器时间（天） |
| count_num 	| Long   |否  |统计数量|

本示例展示当source中不含时间字段时，如何按天统计  
sql:

```sql
-- 使用内置函数 LOCALTIMESTAMP 获取本地日期  yyyy-MM-dd HH:mm:ss 格式
-- 使用内置函数LOCALTIME 获取本地时间 HH:mm:ss 格式
-- 使用 CAST 函数转为 VARCHAR
-- 使用 SUBSTRING 截取字符串为 yyyy-MM-dd 格式
-- 使用CONCAT拼接字符串，用于结果展示
-- 使用YEAR(),MONTH(),DATOFMONTH(),HOUR(),MINUTE()等函数获取当前时间的值
-- 计算并插入结果表
INSERT INTO sink 
select 
CONCAT(
-- 获取本地时间 - 年份
	 CAST(YEAR(LOCALTIMESTAMP) AS VARCHAR),
	 '-',
-- 获取本地时间 - 月份
	 CAST(MONTH(LOCALTIMESTAMP) AS VARCHAR),
	 '-', 
-- 获取本地时间 - 本月的哪一天
	 CAST(DAYOFMONTH(LOCALTIMESTAMP) AS VARCHAR) 
	) ,
COUNT(uid) as count_num 
from source 
group by 
SUBSTRING(CAST(LOCALTIMESTAMP AS VARCHAR) FROM 1 FOR 10);
```
需要注意的是：
1.	在sink的元数据中，t_day要设置为主键，这样在结果集中，才会按照天数为key，将结果区分开
2.	group by语句后面，跟的是 SUBSTRING函数转化的时间。必须这样写，才可在数据源中不含时间字段，也可以做到根据任务所在的机器的时间来按时间维度统计。
3.	t_day所代表的值，不可用group by中SUBSTRING函数转化的时间来代替，必须如上述所写来使用，否则t_day所代表的值会固定不变。下面有更多的示例。

下面展示关于时间的常用内置函数的示例，基本就是灵活使用 `SUBSTRING`/`CONCAT`/`CAST`/`YEAR`/`MONTH`等函数来达到想要的结果：  

```sql
-- 精确到天 yyyy-MM-dd 本地时间
INSERT INTO sink 
select 
CONCAT(
-- 获取本地时间 - 年份
	 CAST(YEAR(LOCALTIMESTAMP) AS VARCHAR),
	 '-',
-- 获取本地时间 - 月份
	 CAST(MONTH(LOCALTIMESTAMP) AS VARCHAR),
	 '-',
-- 获取本地时间 - 本月的哪一天
	 CAST(DAYOFMONTH(LOCALTIMESTAMP) AS VARCHAR) 
	) ,
COUNT(uid) as count_num 
from source 
group by 
-- 注意这里是 1~10
SUBSTRING(CAST(LOCALTIMESTAMP AS VARCHAR) FROM 1 FOR 10);
```

```sql
-- 精确到分钟 yyyy-MM-dd HH:mm 本地时间 使用函数构造冒号与空格
INSERT INTO sink 
select 
CONCAT(
-- 获取本地时间 - 年份
	 CAST(YEAR(LOCALTIMESTAMP) AS VARCHAR),
	 '-',
-- 获取本地时间 - 月份
	 CAST(MONTH(LOCALTIMESTAMP) AS VARCHAR),
	 '-',
  -- 获取本地时间 - 本月的哪一天
	 CAST(DAYOFMONTH(LOCALTIMESTAMP) AS VARCHAR),
-- 这是一个空格
'  ',
-- 获取本地时间 - 小时
      CAST(HOUR(LOCALTIME) AS VARCHAR),
      ':',
-- 获取本地时间 - 分钟
      CAST(MINUTE(LOCALTIME) AS VARCHAR) 
	),
COUNT(uid) as count_num 
from source 
group by 
-- 注意，这里是 1~16
SUBSTRING(CAST(LOCALTIMESTAMP AS VARCHAR) FROM 1 FOR 16);
```

上述示例均为本地时区的时间。若想使用UTC时区。可使用`CURRENT_TIME`代替`LOCALTIME`，使用`CURRENT_TIMESTAMP`代替`LOCALTIMESTAMP`。  
