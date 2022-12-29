# 主账户操作

## 角色管理

角色管理包含添加角色和角色列表，添加角色是进行具有相同权限的一组用户的定义，角色列表为定义好的角色信息展示。

### 添加角色
进入角色管理，点击**添加角色**进行角色权限设置，即授予某个角色一项或多项操作权限，需要完成角色名称定义，为该角色设置权限与资源。
- 某些权限无对应资源，如车牌识别，只用添加权限即可；
- 某些权限有对应资源，如产品管理、设备查看等，则设置权限时还需要添加至少一个对应的资源，比如授予某个角色产品管理的权限，则需要至少添加一个产品。

![添加角色](/images/purview/添加角色.png)

![角色设置](/images/purview/角色设置.png)


### 角色列表
角色列表中可以查看创建的角色信息，以及每个角色已邀请加入的协作用户数，支持对已创建的角色进行编辑、删除。

![角色列表](/images/purview/角色列表.png)


## 用户管理

用户管理包含邀请用户和用户列表，邀请用户即邀请其他OneNET用户加入已定义好的某个角色，邀请其他用户进行协同操作，用户列表为用户的用户名、角色、别名和邀请状态等基础信息展示。

### 邀请用户
进入用户管理，点击**邀请用户**进行用户邀请，可为该用户设置别名，便于管理。

![邀请用户](/images/purview/邀请用户.png)

![用户设置](/images/purview/邀请用户明细.png)

### 查看链接
完成页面的邀请用户操作后，需要在用户列表中点击**查看邀请链接**，将该链接发送给邀请的用户。

![查看邀请链接](/images/purview/查看链接.png)

![复制邀请链接](/images/purview/复制链接.png)

被邀请用户同意加入角色后，才会生成被其所属角色的共享Accesskey，才能进行被授予权限的相关操作。同时主账号的用户管理列表中该用户的状态更新为正常。

![完成用户邀请](/images/purview/正常状态.png)

## 行为日志
行为日志提供主账号以及所有协作用户的操作日志，所有操作有迹可循，避免出现协作操作多而无法追踪的问题，降低安全风险。

### 查看日志
 
行为日志支持按照用户名、别名、角色名筛选查找操作日志，按照时间筛选的时候，不能跨月查询。

![查看行为日志](/images/purview/查看日志.png)

