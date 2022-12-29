# 规则引擎

在左侧边导航栏中选择【应用开发】，点击选择【规则引擎】。页面默认展示【规则管理】内容，可切换查看【数据统计】相关信息。

![规则引擎](/images\qinghua\device-management\brms.png)

该页面支持以下功能：

- 支持用户基于【规则管理】内容进行相关操作
- 支持用户基于【数据统计】内容进行相关操作

### 规则管理

用户点击选择【规则引擎】，默认展示【规则管理】列表信息。列表具体包括规则名称、创建方式、创建时间、启用状态信息。

<div align=center><img src ="/images\qinghua\device-management\brms-rule-management.png"/></div>

该页面支持以下功能： 

- 支持启用/禁用规则功能 
- 支持编辑规则功能
- 支持删除规则功能
- 支持直接添加规则功能
- 支持可视化添加规则，并进行可视化编辑功能

#### 直接添加消息规则

用户进入【规则管理】页面，点击【直接添加消息规则】按钮，可通过填写规则名称、选择消息源、确定产品、设备范围、查询字段、匹配条件、消息目的地等完成消息规则的直接添加，点击【新增】即可在前端实现展示。

<div align=center><img src ="/images\qinghua\device-management\push-rule-add.png"/></div>

#### 可视化添加规则

用户进入【规则管理】页面，首先点击【可视化添加规则】按钮，填写规则名称、相关规则描述，实现可视化规则添加功能。

<div align=center><img src ="/images\qinghua\device-management\visualization-rule-add.png"/></div>

接下来，点击该条规则的【可视化编辑】按钮，选中【共用节点按钮】，如【条件过滤】拖动至可编辑页面，即可实现规则可视化编辑。支持用户通过【SQL监测】按钮进行测试。

<div align=center><img src ="/images\qinghua\device-management\component-orchestration.png"/></div>

### 数据统计

在左侧边导航栏中选择【应用开发】，点击选择【规则引擎】，可切换展示【数据统计】折线图信息。

<div align=center><img src ="/images\qinghua\device-management\brms-data-statistics.png"/></div>

该页面支持以下功能：

- 支持用户查看7天、15天、30天规则触发统计折线图功能
