# 数据集绑定可视化组件

该文档介绍如何在可视化组件应用创建好的数据集模型，在这之前，我们设计了两张张数据表，需要统计其中每一个销售区域的销售总和，具体结构如下：

```sql
create table `st_area` (
    id int primary key auto_increment comment '销售区域标识符',
    name varchar(255) comment '销售区域名称'
);

create table `st_order` (
    id int primary key auto_increment comment '订单标识符',
    area_id int comment '销售区域标识符',
    amount int comment '订单销售金额',
    cost int comment '订单销售成本'
);
```

并在两表之间通过`销售区域标识符`建立了左链接关联关系并调整了相关的维度与度量，如下图：

![建立完成后的数据模型](/images/view/cube/completed_cube.png)

预览的数据如下图：

![预览数据](/images/view/cube/preview_cube_data.png)

**因为我们需要根据每个销售区域来统计销售总额**，所以这里维度我们取`销售区域标识符`或`销售区域名称`都可以，而在度量中需要把`订单销售金额`的聚合修改为`求和`如下图：

![初始化维度度量](/images/view/cube/init_demension_measure.png)

![初始化度量](/images/view/cube/init_measure.png)

然后打开大屏应用，拖入`折线图`，在`折线图`当中选择`数据`，并选择`数据绑定方式`为`数据模型`，然后选择刚刚创建的数据集，如下图

![选择数据集](/images/view/cube/component_choose_cube.png)

然后将`销售区域标识符`或`销售区域名称`拖入到`x轴(x)`中，将`订单销售金额`拖入到`序列1值 (y1)`中,如下图：

![拖入维度度量](/images/view/cube/choose_demension_measure.png)

折线图就可以展示出预期数据。

