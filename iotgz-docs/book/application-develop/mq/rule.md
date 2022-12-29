# 规则配置

OneNET支持用户自定义基于数据流的数据转发规则
- 转发全部数据流
- 基于数据流模板选择数据流
- 使用正则表达式针对数据流名称自定义匹配规则

## 正则表达式使用

OneNET支持用户在对数据流名称进行筛选时，使用正则表达式自定义数据流名称的筛选匹配规则

### 示例1：选择所有数据流

参考筛选表达式为:

    .*

### 示例2：精确筛选一个数据流

表达式语法：
    
    数据流名称

或者 

    ^数据流名称$  

**例**：若需要从 aaa, bbb, ccc 这几个数据流中，只选择ccc这个数据流，参考筛选表达式为:

    ccc

或者
  
    ^ccc$


### 示例3：精确筛选多个数据流

表达式语法：

    数据流名称1|数据流名称2|数据流名称3

或者

    ^数据流名称1$|^数据流名称2$|^数据流名称3$

若需要从 aaa, bbb, ccc 这几个数据流中，只选择aaa,ccc这个数据流，参考筛选表达式为：

    aaa|ccc

或者

    ^aaa$|^ccc$

### 示例4：模糊筛选数据流

(1) 若需要从 abc, bcd, cde 这几个数据流中，只选择包含bc的数据流(abc, bcd)，参考筛选表达式为:

    .*bc.*

(2) 若需要从 test0, test1, test2, test3, abctest0 这几个数据流中，只选择 test0 test1 test2 ，参考筛选表达式为:

    ^test[0-2]


### 示例5： 多重筛选数据流

若需要从 test0, test01, humi2, humi3, abctest0 这几个数据流中，只选择 test0 test01 humi2，参考筛选表达式为:

    ^test0.*|humi2


## 更多帮助

- [查看控制台使用入门手册](/book/easy-manual/MQ.md)
- [查看更多服务功能介绍](/book/application-develop/mq/introduce.md)
- [了解客户端开发帮助，详情请见开发手册](/book/application-develop/mq/develop-manual.md)
- [查看demo工程使用说明](/book/application-develop/mq/demo-project.md)
- [查看服务使用最佳实例](/book/application-develop/mq/example.md)
- [公测版服务资源使用限制](/book/application-develop/mq/limit.md)