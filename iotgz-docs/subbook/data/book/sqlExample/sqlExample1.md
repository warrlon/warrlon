### 示例1 - window函数的使用

场景：每隔5秒，统计近5分钟内流入的数据条数，可以使用窗口window函数来实现。

输入节点的结构：

| 字段名| 字段类型|
| :----:| :----:  |
| uid  	| VARCHAR    |
| log_ts	| Long |
输入节点配置时间标尺：  

 | 时间标尺来源| 时间标尺名称|
 | :----:| :----:  |
 | log_ts  	| r_time  |
 输出节点的结构：
 
 | 字段名| 字段类型|
 | :----:| :----:  |
 | nums   	| Long  |
 | endTime 	| TIMESTAMP |
 sql：
 ```sql
-- 创建中间表,将uid字段与时间标尺字段r_time筛选出来
CREATE VIEW temp as 
select 
uid,
r_time 
from source;

-- 使用window函数进行统计，获取统计总数nums与统计窗口的结束时间endTime
CREATE VIEW temp2 as 
select 
CAST(COUNT(uid) AS BIGINT) as nums,
HOP_END(r_time,INTERVAL '5' SECOND,INTERVAL '5' MINUTE) as endTime 
from temp 
GROUP BY HOP(r_time,INTERVAL '5' SECOND,INTERVAL '5' MINUTE);

-- 插入结果表
INSERT INTO sink select nums,endTime from temp2;
```


