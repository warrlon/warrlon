# **接入管理** 

# **系统接入**  

在左侧边导航栏中选择【接入管理】，点击选择【系统接入】，进入数据集成管理页面，该页面默认展示应用管理列表信息。列表具体包括应用名称、应用描述、创建时间信息。

![app-list](/images/device-management/system-access/app-list.png)

该页面支持以下功能：

- 支持用户创建应用
- 支持用户查看工作流
- 支持用户编辑应用
- 支持用户导出配置
- 支持用户进行日志查询功能
- 支持用户删除应用功能

#### **1、创建应用**  

用户点击【创建应用】按钮，可弹出如下页面。可通过手动创建和导入配置两种形式进行应用创建，创建内容可在前端列表中展示。支持用户编辑工作流、编辑应用、查询日志等相关操作。

<div align=center><img src ="/images/device-management/system-access/app-add1.png"/></div>

<div align=center><img src ="/images/device-management/system-access/app-add2.png"/></div>

#### **2、创建工作流**  

![app-list](/images/device-management/system-access/app-list.png)

用户在应用列表中点击【工作流】按钮，可进入如下界面。用户点击【创建工作流】按钮，通过手动创建、导入配置、从模板创建三种形式创建工作流。创建在前端以列表形式进行展示，主要包括工作流名称、工作流描述、创建时间、任务状态。

![workflow-list](/images/device-management/system-access/workflow-list.png)

支持用户编辑工作流流程、编辑工作流名称、支持导出配置以及删除工作流操作。接下来，对编辑工作流流程进行详细阐述：用户点击已有工作流列表中【编辑工作流】按钮，进入如下界面，点击【添加起始控件】按钮，可选择内置控件和第三方控件。值得注意的是，不同控件需要填写的参数不一样，且每个控件的填写顺序也有要求，系统通过可选/不可选显示控件是否可选。

![workflow-form](/images/device-management/system-access/workflow-form.png)

以定时器控件为例，用户点击添加按钮，通过修改定时器控件名称、选择定时器类型、执行周期间隔、循环时间确定控件要素。用户可将鼠标移至【定时器】控件下继续添加控件，添加完工作流后，点击【运行】就可以运行该工作流，运行过程中，用户可点击【停止】按钮暂停工作流。返回前端，可查看到该工作流状态由“已停止”变为“已启动”。

![workflow-edit](/images/device-management/system-access/workflow-edit.png)
