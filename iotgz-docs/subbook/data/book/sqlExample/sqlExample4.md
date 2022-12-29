### 示例4 - 输出节点使用“插入更新及删除”配置
当数据分析任务有如下类似需求：统计借书次数不大于10次的用户信息。这时大致有两种处理方式：  
- 实时程序仅计算借书总次数，不关心真正的业务逻辑（不大于10次），输出全部计算结果，由下游的应用根据结果进行筛选。
- 实时程序可以处理业务逻辑，当计算某用户的借书次数超过10次时，将该用户的结果在结果集中删除。  

而输出节点的“插入更新及删除”便可以完成这样的任务。  
因为实时程序需要接受源源不断的数据流入，它无法向离线程序一样预先知道所有的数据，因此无法提前筛选借书次数不大于10次的用户。又由于实时程序追求数据计算的实时性，数据进入后，在极短的时间内就需要计算出目前为止借书次数的统计。因此在该需求中使用该配置，实时任务的表现可能如下：  
- a.数据流入一段时间后，计算出目前结果：小明借书次数9次，小红借书次数3次
- b.流入一条小红借书的数据，计算出目前结果：小明借书次数9次，小红借书次数4次
- c.流入一条小明借书的数据，计算出目前结果：小明借书次数10次，小红借书次数4次
- d. 流入一条小明借书的数据，计算出目前结果：小红借书次数4次

可以看到，在执行到步骤d时，因为任务发现小明借书次数为11次超过了10次，会在结果集中删除小明的计算结果。当有类似需求是，可以参考如下示例：

输入节点的结构

 | 字段名| 字段类型|说明|
 | :----:| :----:  |:----:|
 | uid  	| VARCHAR    |用户id |
 | name  	| VARCHAR   | 用户姓名|
 | book_name  	| LONG   | 书名|
 | borrow_time  	| TIMESTAMP   | 借书时间|

输出节点的结构

| 字段名| 字段类型|说明|
 | :----:| :----:  |:----:|
 | uid  	| VARCHAR    |用户id |
 | borrow_count  	| LONG   | 借书次数|
 
 sql：
 ```sql
-- 创建中间表，筛选字段
create view temp as select uid, book_name from sourceTable;
-- 插入结果集，按照用户id进行聚合统计并使用having筛选
insert into sinkTable select uid, COUNT(uid) as borrow_count from temp group by uid  having COUNT(uid) <= 10;
```
--- 

本文档选取了几个常见的统计场景，并分别给出输入节点,输出节点以及sql的配置与书写。  
下面给出目前支持且常用的sql操作：

#### 创建中间表
`CREATE VIEW TableName AS SELECT field FROM OtherTable`

#### select
```sql
SELECT * FROM Orders
SELECT a, c AS d FROM Orders
```

#### Where 
`SELECT * FROM Orders WHERE b = 'red'`

#### GroupBy 聚合
```sql
SELECT a, SUM(b) as d
 FROM Orders
 GROUP BY a
```

#### GroupBy 窗口聚合
```sql
SELECT user, SUM(amount)
FROM Orders
GROUP BY TUMBLE(rowtime, INTERVAL '1' DAY), user
```

#### Distinct
`SELECT DISTINCT users FROM Orders`

#### Having
```sql
SELECT SUM(amount)
FROM Orders
GROUP BY users
```

#### Order By
```sql
SELECT *
FROM Orders
ORDER BY orderTime
```

#### Insert Into
```sql
INSERT INTO OutputTable
SELECT users, tag
FROM Orders
```

#### Group Windows 窗口操作，需配置source的时间标尺后再使用
`TUMBLE(time_attr, interval)`：窗口长度为interval，步长也为interval。即：两个窗口无重叠  
`TUMBLE_START(time_attr, interval)`：窗口的开始时间，TIMESTAMP类型  
`TUMBLE_END(time_attr, interval)`：窗口结束时间，TIMESTAMP类型  
`HOP(time_attr, interval_1, interval_2)`：长度为interval_2，步长为interval_1的滑动窗口。即：两个窗口的重叠长度为interval_1。可以参考第一个sql示例  
`HOP_START(time_attr, interval, interval)`：窗口的开始时间，TIMESTAMP类型  
`HOP_END(time_attr, interval, interval)`：窗口结束时间，TIMESTAMP类型  

---

以下SQL语法是多表关联操作的语法。注意，目前多表关联仅支持等值关联操作。仅一个特殊的关联操作语法可以在等值关联操作的基础上，对时间标尺字段进行区间判断操作。  


#### INNER JOIN
```sql
SELECT *
FROM Orders INNER JOIN Product ON Orders.productId = Product.id
12. LEFT JOIN
SELECT *
FROM Orders LEFT JOIN Product ON Orders.productId = Product.id
```

#### 使用时间标尺字段进行区间关联
```sql
SELECT *
FROM Orders o, Shipments s
WHERE o.id = s.orderId AND
      o.ordertime BETWEEN s.shiptime - INTERVAL '4' HOUR AND s.shiptime
```
这个sql示例表示，订单表order与货运表shipments的关系。该sql表示，订单生成后，四个小时内被装运的那些订单与货运信息会被筛选出来。  
注意：必须有一个等值关联，区间关联必须是时间标尺字段。时间标尺字段的区间关联也可以这么写：  
- ltime = rtime
- ltime >= rtime AND ltime < rtime + INTERVAL '10' MINUTE
- ltime BETWEEN rtime - INTERVAL '10' SECOND AND rtime + INTERVAL '5' SECOND

关于更多的sql内置函数如数值判断函数，逻辑判断函数，字符串常用函数，类型转化函数，时间函数，逻辑运算函数，条件判断函数，聚合函数，时间间隔单位等，可以参考[这里](https://ci.apache.org/projects/flink/flink-docs-release-1.7/dev/table/functions.html)。


