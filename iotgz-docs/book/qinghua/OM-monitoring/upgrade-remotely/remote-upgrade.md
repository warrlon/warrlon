# 远程升级

在左侧边导航栏中选择【运维监控】，点击选择【远程升级】，系统默认显示【升级包管理】信息，可切换查看【升级任务通知】、【版本分布】、【转入设备批次】信息。

![远程升级](/images\qinghua\device-management\remote-upgrade.png)

该页面主要功能如下：

- 支持用户基于【升级包管理】功能进行相关操作
- 支持用户基于【升级任务通知】功能进行相关操作
- 支持用户基于【版本分布】功能进行相关操作
- 支持用户基于【转入设备批次】功能进行相关操作

### 升级包管理

系统默认显示【升级包管理】列表信息，具体包括升级包名称、升级包类型、目标版本号、待升级版本、所属产品、状态、添加时间、启用状态信息。

<div align=center><img src ="/images\qinghua\device-management\upgrade-package-management.png"/></div>

该页面支持以下功能：

- 支持基于升级包名称、所属产品搜索功能
- 支持添加升级包功能
- 支持升级包验证升级功能
- 支持升级包批量升级功能
- 支持升级包详情查看功能
- 支持升级包删除功能

#### 添加升级包

用户点击【添加升级包】按钮，通过升级包类型、升级包名称、确定所属产品、升级模块、目标版本、升级包描述、上传升级包进行添加，返回结果在前端进行展示。

<div align=center><img src ="/images\qinghua\device-management\upgrade-package-add.png"/></div>

#### 验证升级

用户点击【验证升级】按钮，选择待升级版本号、通知方式、设备，点击【开始验证】按钮进行验证，也可以点击【跳过验证】按钮跳过验证步骤，跳过验证之后可直接进行批量升级，但将不能再进行验证升级。

<div align=center><img src ="/images\qinghua\device-management\upgrade-verify.png"/></div>

#### 批量升级

用户点击【批量升级】按钮，选择待升级版本号、升级策略、升级范围、升级时间、升级失败重试策略、设备升级超时时间等，确认批量升级内容。

<div align=center><img src ="/images\qinghua\device-management\bulk-upgrades.png"/></div>

#### 详情查看

用户点击【详情】按钮，跳转至升级包详情页面。支持系统查看【批次列表】和【设备列表】相关详情，支持用户进行验证升级、批量升级、取消升级、查看所在批次等操作。

<div align=center><img src ="/images\qinghua\device-management\view-upgrade-details.png"/></div>

### 升级任务通知

用户点击查看【升级任务通知】相关信息，包括升级任务通知配置和关联升级列表信息，列表具体包括升级包名称、升级包类型、目标版本号、所属产品、升级模块、状态信息。

<div align=center><img src ="/images\qinghua\device-management\task-notification-upgrade.png"/></div>

该页面支持以下功能：

- 支持用户添加升级任务通知功能
- 支持用户根据升级包名称、所属产品查询关联升级列表信息功能
- 支持用户进行关联升级功能
- 支持用户根据升级包名称查询关联通知记录信息功能

#### 添加升级任务通知

用户点击【添加升级任务通知】按钮，通过UL、token进行添加，返回结果在前端进行展示。

<div align=center><img src ="/images\qinghua\device-management\upgrade-task-add.png"/></div>

#### 关联升级

用户在关联升级页面，点击【关联升级】按钮，通过选择所属产品、升级包相关内容实现关联升级，内容返回前端进行展示。

<div align=center><img src ="/images\qinghua\device-management\association-upgrade.png"/></div>

#### 通知记录

用户点击切换展示【通知记录】列表信息，具体包括升级包名称、批次ID、最新执行推送时间、推送状态、信息类型。

<div align=center><img src ="/images\qinghua\device-management\notification-logs.png"/></div>

### 版本分布

用户点击查看【版本分布】相关信息，点击产品名称可查看该产品的版本占比和设备列表信息。

<div align=center><img src ="/images\qinghua\device-management\version-distribution.png"/></div>

该页面支持以下功能：

- 支持用户查看版本占比信息
- 支持用户查看设备列表信息

### 版本占比

在左侧边导航栏中选择【运维监控】，点击选择【远程升级】，切换查看【版本分布】信息。系统默认展示某产品下【版本占比】列表信息，包括版本号、升级模块、设备数、占比信息，可切换产品查看相应内容。

<div align=center><img src ="/images\qinghua\device-management\version-ratio.png"/></div>

#### 设备列表

用户切换【设备列表】按钮，可查看设备名称、模组固件版本号、MCU软件版本号、版本更新时间、版本升级总数、版本失败总次数。用户选择某产品，可查看该产品下任意设备详情，支持通过设备名称进行搜索功能，支持用户查看升级日志详情功能。

<div align=center><img src ="/images\qinghua\device-management\ac-device-list.png"/></div>

### 转入设备批次

用户进入【远程升级】页面，点击切换至【转入设备批次】信息，系统默认展示转入设备批次列表详情，具体包括批次ID、产品ID、产品名称、起始版本、目标版本、创建时间、状态信息。

<div align=center><img src ="/images\qinghua\device-management\device-batch-transfer.png"/></div>

该页面支持以下功能：

- 支持根据状态、产品名称、产品ID进行搜索功能
- 支持批次详情查看功能

其中，【查看详情】具体操作如下：用户点击【查看详情】按钮，可切换至详情页面。支持用户查看【待升级】、【升级中】、【升级成功】、【升级失败】不同状态列表信息。支持用户同意、拒绝相关转入设备。

<div align=center><img src ="/images\qinghua\device-management\ac-detail-view.png"/></div>
