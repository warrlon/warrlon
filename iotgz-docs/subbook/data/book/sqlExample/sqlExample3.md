 ### 示例3 - 模式匹配处理复杂事件
 根据流入的数据，查找“微笑曲线”。并输出微笑曲线的(开始)最高点时间，(中间)最低点时间，(结束)最高点时间，(开始)最高点数值，(中间)最低点数值，(结束)最高点数值。  
 以下示例展示的是一个日志分析场景。假设有一个日志流，含有四个字段，uid,status,count_num与log_date。其中假设该日志为清洗后的日志，status字段为字符串常量”online”，log_date代表日志产生的毫秒值。该日志代表某用户在(log_date – 1Hour) ~ log_date 这一个小时内，某特定动作（如访问网站）的统计次数。以下任务的目标是统计某用户执行某个特定动作（如访问网站）的频率从高峰到低谷再到走出低谷的时间及对应频率。  
 
 输入节点的结构
 
 | 字段名| 字段类型|说明|
 | :----:| :----:  |:----:|
 | uid  	| VARCHAR    |用户id |
 | status  	| VARCHAR   | 状态|
 | count_num  	| LONG   | 统计次数|
 | log_date  	| LONG   | 日志产生的时间戳（毫秒值）|
 
 输入节点的时间标尺配置
 
  | 时间标尺来源| 时间标尺名称|
  | :----:| :----:  |
  |  log_date  	| w_time    |
  
  输出节点的结构
  
   | 字段名| 字段类型|说明|
   | :----:| :----:  |:----:|
   | uid  	| VARCHAR    |用户id |
   | start_t  	| TIMESTAMP   | 匹配到的模式的开始时间戳|
   | bottom_t  	| TIMESTAMP   | 匹配到的模式的波谷时间戳|
   | end_t  	| TIMESTAMP   | 匹配到的模式的结束时间戳|
   | start_count  	| LONG   | 匹配到的模式的开始时刻统计值|
   | bottom_count  	| LONG   | 匹配到的模式的波谷时刻统计值|
   | end_count  	| LONG   |匹配到的模式的结束时刻统计值|
   
 sql:
 
 ```sql
create view temp AS
select *
FROM source
MATCH_RECOGNIZE (
    PARTITION BY uid
    ORDER BY w_time
    MEASURES
        START_ROW.w_time AS start_t,
        LAST(PRICE_DOWN.w_time) AS bottom_t,
        LAST(PRICE_UP.w_time) AS end_t,
         START_ROW.count_num AS start_count,
        LAST(PRICE_DOWN.count_num) AS bottom_count,
        LAST(PRICE_UP.count_num) AS end_count
    ONE ROW PER MATCH
    AFTER MATCH SKIP TO LAST PRICE_UP
    PATTERN (START_ROW PRICE_DOWN+ PRICE_UP)
    DEFINE
        PRICE_DOWN AS
            (LAST(PRICE_DOWN.count_num, 1) IS NULL AND PRICE_DOWN.count_num < START_ROW.count_num) OR
                PRICE_DOWN.count_num < LAST(PRICE_DOWN.count_num, 1),
        PRICE_UP AS
            PRICE_UP.count_num > LAST(PRICE_DOWN.count_num, 1)
    ) MR;

-- 插入结果表
INSERT INTO sink select * from temp;
```

上述任务，可以使用如下数据进行输入：

| uid| status|count_num|log_date|
| :----:| :----:  |:----:|:----:|
|***"12"***|***"online"***|***8***|***1533686400000***|
|"12"|"online"|6|1533690000000|
|"12"|"online"|4|1533693600000|
|***"12"***|***"online"***|***2***|***1533697200000***|
|***"12"***|***"online"***|***5***|***1533700800000***|
|"12"|"online"|6|1533704400000|

表中 ***加粗斜体*** 的数据会被匹配到，输出的计算结果为：

```json
{
  "uid": "12",
  "end_t": "2018-08-08 04:00:00.0",// 窗口函数生成的TIMESTAMP是UTC时区的，可以自己转化
  "record_ts": "1570603718360",//系统自动生成
  "end_count": "5",
  "bottom_count": "2",
  "start_t": "2018-08-08 00:00:00.0",
  "start_count": "8",
  "bottom_t": "2018-08-08 03:00:00.0"
}
```
该示例中，匹配模式计算出的符合要求的数据，均为仅匹配微笑曲线上升趋势的第一个点（而不是最后一个高点），即表格中倒数第二个数据（而不是最后一个数据），并且仅当最后一个数据也发送后，程序才会判定出结果。更多模式匹配资料，可以参考[这里](https://ci.apache.org/projects/flink/flink-docs-release-1.7/dev/table/streaming/match_recognize.html)。

