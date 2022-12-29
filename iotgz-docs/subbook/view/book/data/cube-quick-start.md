# 数据集快速入门

数据可视化 View 可以允许您通过数据集连接到您的数据库，然后基于数据库创建数据模型应用到可视化组件中进行展示，以下是具体的使用方式。

## 创建数据库连接

在“数据管理”中找到“数据模型”，选择“数据库连接”选项卡，点击“创建数据库连接”按钮，如下图所示：

![选择创建数据库连接](/images/view/cube/choose_create_jdbc_connection.png)

在弹出的选项卡中填入相关的数据，如下图所示：

![创建数据库连接](/images/view/cube/create_jdbc_connection.png)

当数据填写完成后，可以点击“测试连接”测试填写的用户信息是否能正常连接到数据库，确认无误后可以点击“创建”保存所填写的数据。

需要填写的数据含义参考下表：

| 字段名 | 字段含义 |
| :---- | :---- |
| 类型 | 选择当前数据库使用的版本 |
| 数据库连接名 | 用户自己定义的在数据库连接列表当中展示的名称 |
| 数据库连接地址 | 数据库地址，可以是域名或IP地址 |
| 端口号 | 数据库端口号 |
| 数据库名 | 需要连接的实例的数据库 |
| 用户名 | 连接数据库使用的用户账号 |
| 密码 | 连接数据库使用的账号对应的密码 |

> 需要注意的是，数据可视化 View 只需要账号拥有查询权限，另外如果数据库在内网当中无法通过外网进行访问，我们建议通过建立中间代理服务器的方式将服务器特定的端口代理到公网上，同时要注意服务器访问权限的配置以保证数据库的安全。

创建完成后，我们可以选择列表当中的“预览”功能，预览所创建的数据库连接的数据表与表中的数据，如下图所示：

![预览数据库连接](/images/view/cube/review_jdbc_connection.png)

在“预览”选项卡当中，左侧是数据库表列表，右侧则是表中数据表格，如下图所示：

![预览数据库连接选项卡](/images/view/cube/review_jdbc_connection_card.png)

## 创建数据集

创建数据集我们可以选择“数据模型”中的选项卡“数据集”，再点击“创建数据集”按钮打开创建的选项卡，如下图所示：

![选择创建数据集](/images/view/cube/choose_create_cube.png)

在打开的选项卡当中填写“数据集名称”，再选择所创建的数据库连接即可，如下图：

![创建数据集](/images/view/cube/create_cube.png)

## 编辑数据集模型

我们可以在创建完数据集的列表当中选择“编辑”进入到“数据集编辑器”中进行创建我们的数据集模型，如下图：

![数据集编辑器首页](/images/view/cube/cube_editor_index.png)

我们可以把 cv_student_lesson 表拖入到编辑器中当中，编辑器自动将表中的字段进行了归类（编辑器会自动将文字类的属性归为维度，数字类的属性归为度量），如下图：

![拖入表](/images/view/cube/drop_table.png)

再将学生的基本信息拖入到编辑器当中，并将选课表当中学生的ID与学生表当中的ID进行左连接，如下图：

![创建表连接](/images/view/cube/create_table_relation.png)

创建好后模型如下：

![模型关系](/images/view/cube/table_relation_details.png)

点击“预览数据”可以看到创建的模型返回的数据，如下图：

![预览数据集数据](/images/view/cube/review_cube_data.png)

点击选项卡当中的SQL语句，可以预览到整个模型编译生成后的SQL，如下图：

![预览SQL](/images/view/cube/review_sql.png)

按照这种方式，我们继续将课程信息以及老师的信息添加到模型当中，结果如下图：

![完整的数据集模型](/images/view/cube/completed_cube_model.png)

选择“预览数据”得到的数据集查询结果如下：

![预览完整数据集模型数据](/images/view/cube/review_completed_cube_data.png)

### 添加数据筛选器

假设我们只需要看选了“课时超过100”的课程，则选择数据筛选器，如下图：

![悬着数据过滤器](/images/view/cube/choose_data_filter.png)

选择添加按钮，如下图：

![添加按钮](/images/view/cube/choose_create_data_filter.png)

选择对应的字段，然后选择生效条件为“匹配所有条件”，然后再选择条件为“大于等于”并填入数值，如下图：

![添加条件](/images/view/cube/create_data_filter.png)

创建好后数据集查询结果当中则只会包含匹配规则的数据，预览数据的结果如下：

![预览过滤器结果](/images/view/cube/review_data_filter_result_data.png)

## 维度与度量

维度与度量用来定义可视化组件如何使用数据集当中返回得数据，具体解释如下。

### 维度

维度指的是我们如何去对数据做一个分组，比如我们有一堆销售的数据，如可以按照地区把这一整块数据重新做一个分组，分组当中的所有数据都拥有相同的地区名称。在语义上，“统计每个销售地区的销量总和”，那么维度就是销售地区；“统计每个学校的教师数量”其中维度就是学校。

![维度分组](/images/view/cube/group_by_dimension.png)

### 度量

度量指的是按照维度处理完成的数据后，如何来统计剩下的数据，一般来讲统计的方式有：求和、求平均等方式，在上面的维度例子中，地区已经被设为维度后，还有产品、销量与成本可以作为度量来使用，如下图：

![根据度量计算](/images/view/cube/compute_by_measure.png)

在语义上，“统计每个销售地区的销量总和”，那么就应该设置销量为`求和`；“统计每个学校的教师数量”，那么度量就应该设置教师唯一标识为`计数`。