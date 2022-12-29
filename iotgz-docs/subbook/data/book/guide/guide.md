## 使用注意
#### 数据有效期
分析任务的计算结果会保存一天。超过一天后会被清除。结合第6与第7条注意事项说明，分析任务的计算结果最多存储5000条，且最久保存一天。

#### 任务下线后，修改任务
任务在下线时会进行存档，将该任务的状态信息进行保存。重启时，会读取存档，从下线时刻的状态开始运行任务。  
这样设计可以保证同一个任务在重启时，不会丢失暂停期间的数据。  
但是，如果在任务下线后，进行某些编辑任务操作，如：修改元数据，大幅度修改sql，会导致重新上线任务时，读取的状态与修改后的任务不匹配，导致上线失败，提示：  
`SQL实时任务的SQL脚本有语法错误||internal error`  
>建议：如果想大幅度修改任务，可以重新新建一个任务，而不是在旧任务上进行编辑。

#### insert into 语句
任务要正常启动，必须使用 insert into 语句，将计算结果输出到sink表。  
以如下sink表结构为例:  

| 字段名| 字段类型| 含义 |
| :----:| :----:  |:----:|
| name	| String  | 姓名 |
| age	| Integer | 年龄 |

任务中的 insert into 语句如下：  
`Insert into sink select what_ever_field_name, what_ever_field_age from temp;`  
这里，只要select后面的字段类型的顺序与sink定义的字段类型顺序相同，即可保证temp表中的计算结果可以顺利流入sink表。

#### 使用group by操作符
目前仅开放了计算结果存入key-value数据库的结果集。  
通常，我们会使用group by操作符进行聚合操作，如：统计每天的总数等场景。  
当使用聚合等操作符时，任务会在内存中保存中间计算结果。以统计每天的数据条数为例：  
假设今天为 2018-08-08 ，当数据流入时，每流入一条数据，key=2018-08-08 的结果就会加1，也可以通过接口实时看到该更新的数据。  
而任务会在内存中保存 key=2018-08-08 的统计值，以便下一条数据流入时，可以快速计算出结果并存入结果集。  
因此，目前需要谨慎的选择group by的key值，以免因为任务保存过多的状态，导致任务异常下线。  
可以在遇到此情况时（在正确选择key的情况下，需要很久才会出现该问题），新建一个一样的任务来继续执行计算（而不是重启旧任务）。  
后续，我们会开放一个时间配置，超过配置时间的状态会被清除。

#### 元数据结果集主键的设置
目前仅开放了计算结果存入key-value数据库的结果集。根据key-value数据库的特性，需要配置一个key来存储对应的结果。  
元数据配置了主键字段，sql语句中未使用group by或未按照该主键聚合，计算结果仍然会按照元数据配置的主键对结果进行区分。  
元数据未配置主键字段，sql中使用group by按照某字段进行聚合操作，计算结果仅会显示最新的计算结果，无法按照group by的聚合字段进行结果查询。  
如果配置了主键，且在sql中使用 group by 语句将配置的主键作为聚合字段，计算结果会显示所有主键的最新结果，可以方便的按照主键查询及区分不同主键的当前计算结果。  
>建议：在元数据中配置的主键字段需要在sql中使用group by对这些字段进行聚合操作。或者当想要在sql中进行group by操作时，需要确保元数据中这些字段配置为了主键。

#### 结果集类型元数据中 record_ts 字段
在添加结果集类型元数据时，会发现系统会自带 record_ts 字段。该字段为系统自动添加到计算结果中的。  
代表计算结果存入key-value数据库的时间（毫秒值）。  
当通过接口获取计算结果时，可以通过该字段判断某计算结果最后的计算时间。

#### 结果数量限制
目前每个结果集限制为：最多存储5000条计算结果  
因此，使用 group by 语句进行聚合分析操作，根据key来进行聚合，可以保存5000个key的计算结果。  
当超过5000时，最旧的key会被删除。

#### 字段不匹配导致任务异常下线
API数据接入时，用户上传的数据结构（list数组里的JSONObject）需要与关联的数据源类型元数据的格式一致，否则，任务启动后，读取数据会因格式不匹配而报错，导致任务异常下线。  
此时，建议新建一个任务。因为根据本页面第2点的说明，重启任务会从上次下线处重启，重启后仍然会从错误数据处开始读取，造成异常下线。  
可以在修复发送数据的问题后，新建一个任务并启动。

#### 配置输入节点的元数据时，字段名提示重名
当配置输入节点的元数据时，会发现某些字段后，提示重名。鼠标悬浮，可以看到提示与关键字重名的字段名。  
此时，建议回到元数据模块，修改该重名的字段名。  
若无法修改，可以在sql书写时，使用反引号（英文模式下，ESC键下面的按键）将重名的字段名包裹起来。  
如： `extend` 为与关键字重名字段，sql示例如下： 
````sql
create view temp as select `extend` as myExtend from sourceTable;
````

#### 在sql中，使用CAST函数进行类型转化
元数据中的字段类型 `LONG` 在sql中统一视作 `BIGINT`   
元数据中的字段类型 `STRING`/`VARCHAR`  在sql中统一视作 `VARCHAR`  
如下：

***a.将某数字转为`LONG` 或 `BIGINT` 类型,结果字段重命名为 nums：***  
`CAST('123' AS BIGINT) as nums`  
注意上面的大写，以及 数字常量使用单引号包裹。想转为LONG类型或者BIGINT类型，在CAST函数中，使用 BIGINT。这样在sql的表中，就人为增加了一个叫做 nums ，内容为常量 123 ，类型为 LONG 或 BIGINT 的字段

***b.将某字段转为`LONG` 或 `BIGINT` 类型,结果字段重命名为 nums：***   
`CAST(field AS BIGINT) as nums`   
注意上面的大写。想转为LONG类型或者BIGINT类型，在CAST函数中，使用 BIGINT 。

***c.将某字符常量转为 STRING 或 VARCHAR 类型，结果字段重命名为 name:***  
`CAST('test' AS VARCHAR) as name`  
注意上面的大写，以及 字符常量使用单引号包裹。想转为STRING 或 VARCHAR类型，在CAST函数中，使用 VARCHAR。这样在sql的表中，就人为增加了一个叫做 name ，内容为常量 test ，类型为 STRING 或 VARCHAR 的字段

***d.将某字段转为 `STRING` 或 `VARCHAR` 类型，结果重字段命名为 name:***  
`CAST(field AS VARCHAR) as name`  
注意上面的大写，以及 字符常量使用单引号包裹。想转为STRING 或 VARCHAR类型，在CAST函数中，使用 VARCHAR

#### 在sql中，字段与字符串常量进行比对
在sql中，使用 where 进行筛选时，若需要与字符常量进行比对，字符常量要使用***单引号包裹***，如：  
```sql
create view temp as select name, age, class from sourceTable where class='grade_1';
create view temp2 as select name, age , addr from sourceTable where addr='中国';
```

#### sql注释
在sql中，可以在***行首***，使用 `--` 做注释，类似于mysql客户端的单行注释

#### 多表关联操作
在任务配置中，可以配置多个输入节点。Sql中支持多表关联操作。与上面的使用注意4中类似。多表关联操作会在内存中缓存相关数据。若数据太多，会导致任务异常下线。  
可以在遇到此情况时（在正确选择key的情况下，需要很久才会出现该问题），新建一个一样的任务来继续执行计算（而不是重启旧任务）。  
后续，我们会开放一个时间配置，超过配置时间的状态会被清除。

#### 任务上线失败
大部分提示，都是简单易读的错误提示。可以根据提示更改sql。下面是常见的错误提示含义:

***a.若提示中最后一两行含有：This exception indicates that the query uses an unsupported SQL feature.***   
则表示，sql中使用了尚未支持的sql语法。尽管为了降低学习成本，sql与数据库的sql类似。但在实时分析领域，使用sql处理的是无限的，不断流入的数据，与数据库有限的数据集操作有所区别。因此某些数据库sql特性可能不支持。  

***b.若提示：SQL实时任务的SQL脚本有语法错误||internal error***  
一般表示任务无法从存档处重启。原因如上面讨论的，可能是修改了sql或者元数据等任务相关内容，导致该任务从上次存档处重启时，无法将存档与自身匹配而无法上线。此时建议新建一个任务进行上线。  

***c.若提示：Invalid SQL statement:  xxx |Encountered "yyyy" at line 1, column 120.
Was expecting one of: zzz***  
则代表sql语句“xxx”在”yyyy”处有语法错误，期待的字符是“zzz”。  

***d.若提示：Invalid SQL statement: XXX|Conversion to relational algebra failed to preserve datatypes:
validated type:  
RecordType(xxx) NOT NULL  
converted type:  
RecordType(xxx) NOT NULL  
rel:  
LogicalProject(xxx)  
  LogicalTableScan(table=[[xxx]])***  
建议修改下元数据中的字段名称，或在sql中使用as关键字对字段进行重命名。 
 
***e.其他问题***  
请仔细检查是否有select了不存在的字段（如修改元数据字段名后，未修改sql）等错误。

#### 系统内置字段
在输入数据时，`collectId`字段为系统内置字段（不区分大小写），在配置数据源类型元数据的数据结构字段时，无法配置该字段。`record_ts`字段也是系统内置字段，在配置结果集类型元数据时，无法配置该字段。  

#### 结果集中的时间戳字段
当计算结果包括`TIMESTAMP`等时间相关的数据类型时，需要特别注意。在使用窗口函数，如：HOP_END获取的时间戳是***UTC时区***。  
当发现时间字段结果是UTC时区时，可以选择在获取到结果集数据后，在自己的程序中进行转化。  
如果想在sql中转化，可以考虑先使用内置的时间函数如TIMESTAMPADD，将时间增加8小时，转化为北京时间，如： `TIMESTAMPADD(HOUR, 8, youTimeField)`，其中 youTimeField 是你的时间类型的字段，可以是DATE/TIMESTAMP等。  

#### 数据源中含有时间相关字段
当数据源中，时间字段存储的是`LONG`类型的毫秒值，但是想要转为`TIMESTAMP`类型的值时，可以配置时间标尺来实现。  
当数据源中，时间字段存储的是字符串类型的时间戳，如：`2019-10-10 11:38:39 `或`2019-10-10 11:38:39.152 `，可以使用内置函数，如 `CAST(fieldname AS TIMESTAMP)` 将字符串类型的时间戳转为`TIMESTAMP`格式。详情可以查看[SQL示例](../sqlExample/sqlExample.md)中提供的内置函数链接。  








