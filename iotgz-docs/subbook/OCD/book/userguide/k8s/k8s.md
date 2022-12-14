
<h1>集群管理操作流程</h1>
<h2 id="1">1.功能概述</h2>

OneNET应用托管集群管理功能提供基于原生Kubernetes的容器管理服务，提供高性能的容器化管理能力，能够实现对用户容器化应用的全生命周期管理。服务部署简单，免去运维成本。可根据业务一键增删节点，满足不同场景下的使用需求。

产品优势：

- 一键部署：省去集群搭建的烦恼，用户无需手动运维，全程自动化部署，开箱即用。
- 按需使用：页面一键新增、减少节点数量，根据业务情况使用，降低成本。
- 秒级启动：结合私有镜像仓库，可实现用户容器化应用快速部署。
- 监控全面：内置监控组件，实现对节点、应用的多维度监控，并及时告警。


<h2 id="2">2.集群管理操作步骤</h2>

<h4 id="21"><font color=#2B2B2B face="微软雅黑"> &triangleright; STEP 1 集群管理入口</font></h4> 

点击页面左侧“**物联网应用托管-集群管理**”，进入集群管理页，如图1所示。

![1](/images/OCD/cluster001.png)

<center>图 1 集群管理入口 </center>

<h4 id="22"><font color=#2B2B2B face="微软雅黑"> &triangleright; STEP 2 创建集群管理</font></h4> 

点击页面右侧“**+创建集群**”按钮，如图2和图3所示。填入实例名称，根据需求选择计算节点配置，点击确认即可创建。

![2](/images/OCD/cluster002.png)

<center>图 2 创建集群配置1 </center>


![3](/images/OCD/cluster003.png)

<center>图 3 创建集群配置2 </center>

<h4 id="23"><font color=#2B2B2B face="微软雅黑"> &triangleright; STEP 3 集群开机</font></h4>

集群处于关机状态时，点击表格操作栏中的“**开机**”按钮，确保您的账号处于未欠费状态下，集群便可开机成功。如图4所示。


![4](/images/OCD/cluster004.png)

<center>图 4 集群开机 </center>

<h4 id="24"><font color=#2B2B2B face="微软雅黑"> &triangleright; STEP 4 删除集群</font></h4> 

集群处于运行中或启动失败的状态时，点击表格操作栏中的“**删除**”按钮，二次确认后即可删除集群，如图5所示。

![5](/images/OCD/cluster005.png)

<center>图 5 删除集群 </center>

<h4 id="25"><font color=#2B2B2B face="微软雅黑"> &triangleright; STEP 5 集群详情</font></h4> 

集群处于运行中状态时，点击表格操作栏中的“**查看**”按钮，进入集群详情页，如图6所示。


![6](/images/OCD/cluster006.png)

<center>图 6 集群详情入口 </center>

##### 1. 基本信息

集群详情第一页为集群的基本信息和主节点配置，点击基本信息中的“**修改描述**”，在弹窗内填入相应信息，点击确认即可修改集群描述，如图7和图8所示。

![7](/images/OCD/cluster007.png)

<center>图 7 集群基本信息 </center>

![8](/images/OCD/cluster008.png)

<center>图 8 修改集群描述 </center>

##### 2. 节点管理

集群详情第二页为集群的节点管理页，在列表中展示了集群的主节点（不可操作）和计算节点，如图9所示。

![9](/images/OCD/cluster009.png)

<center>图 9 节点列表 </center>

##### 2.1 新增计算节点

点击右上角的“**+新增计算节点**”按钮，选择配置，点击确认即可新增计算节点，如图10所示。

![10](/images/OCD/cluster010.png)

<center>图 10 新增计算节点 </center>

##### 2.2 删除计算节点

当节点的部署状态为“**已部署**”时，点击表格操作栏中的“**删除**”按钮，二次确认后即可删除该计算节点，如图11所示。

![11](/images/OCD/cluster011.png)

<center>图 11 删除计算节点 </center>

##### 3 命名空间

集群详情第三页为集群的命名空间管理页，如图12所示。

![12](/images/OCD/cluster012.png)

<center>图 12 命名空间列表 </center>

##### 3.1 新增命名空间

点击右上角的“**+新增命名空间**”按钮，填入基本信息，点击确认即可创建，如图13所示。

![13](/images/OCD/cluster013.png)

<center>图 13 新增命名空间 </center>

##### 3.2 编辑命名空间

当命名空间不是“**默认Namespace**”和“**系统Namespace**”时，点击表格操作栏中的“**编辑**”按钮，在弹框内输入描述，点击确认即可修改命名空间的描述，如图14所示。

![14](/images/OCD/cluster014.png)

<center>图 14 编辑命名空间 </center>

##### 3.3 删除命名空间

当命名空间不是“**默认Namespace**”和“**系统Namespace**”时，点击表格操作栏中的“**删除**”按钮，二次确认后即可删除该命名空间，如图15所示。

![15](/images/OCD/cluster015.png)

<center>图 15 删除命名空间 </center>

##### 4 监控

集群详情第四页为集群监控页，如图16所示。

![16](/images/OCD/cluster016.png)

<center>图 16 监控1 </center>


左上角的下拉框为监控的时间和节点筛选，中间二级菜单可切换不同的监控对象，点击图表旁的图例可显示/隐藏该条数据，如图17所示。

![17](/images/OCD/cluster017.png)

<center>图 17 监控2 </center>

##### 5 告警

集群详情第五页为集群告警管理页，左上角第一个下拉框可选择展示“**已激活告警实例**”和“**静默告警实例**”，第二个下拉框可筛选告警类型，如图18所示。

![18](/images/OCD/cluster018.png)

<center>图 18 告警列表 </center>

##### 5.1 告警用户管理

点击右上角的“**告警用户管理**”，弹出告警用户管理页，如图19所示。

![19](/images/OCD/cluster019.png)

<center>图 19 告警用户管理 </center>

##### 5.1.1 新增告警用户

在“**告警用户管理**”页中，点击右上角的“**+新增告警用户**”按钮，填入用户名（本系统中存在的用户）和邮箱，点击确认即可，如图20所示。

![20](/images/OCD/cluster020.png)

<center>图 20 新增告警用户 </center>

##### 5.1.2 编辑告警用户

在“**告警用户管理**”页中，点击表格操作栏中的“**编辑**”按钮，可修改用户的激活状态，如图21所示。

![21](/images/OCD/cluster021.png)

<center>图 21 编辑告警用户 </center>

##### 5.1.3 删除告警用户

在“**告警用户管理**”页中，点击表格操作栏中的“**删除**”按钮，二次确认后可删除该告警用户，如图22所示。

![22](/images/OCD/cluster022.png)

<center>图 22 删除告警用户 </center>

##### 5.2 告警规则管理

点击右上角的“**告警规则管理**”按钮，弹出告警规则管理页，如图23所示。

![23](/images/OCD/cluster023.png)

<center>图 23 告警规则管理 </center>

##### 5.2.1 新增告警规则管理

在“**告警规则管理**”页中，点击右上角的“**+新增告警规则**”按钮，填写告警规则类型、告警条件、延迟告警时间，点击确认即可，如图24所示。

![24](/images/OCD/cluster024.png)

<center>图 24 新增告警规则 </center>

##### 5.2.2 编辑告警规则管理

在“**告警规则管理**”页中，点击表格操作栏中的“**编辑**”按钮，可修改告警规则的告警条件、延迟告警时间，点击确认即可，如图25所示。

![25](/images/OCD/cluster025.png)

<center>图 25 编辑告警规则 </center>

##### 5.2.3 禁用告警规则管理

在“**告警规则管理**”页中，点击表格操作栏中的“**禁用**”按钮，二次确认后可禁用该告警规则，如图26所示。

![26](/images/OCD/cluster026.png)

<center>图 26 禁用告警规则 </center>

##### 5.2.4 删除告警规则管理

在“**告警规则管理**”页中，点击表格操作栏中的“**删除**”按钮，二次确认后可删除该告警规则，如图27所示。

![27](/images/OCD/cluster027.png)

<center>图 27 删除告警规则 </center>

##### 5.3 静默告警

在展示“**已激活告警实例**”时，点击表格操作栏中的“**静默**”按钮，二次确认后，在弹出框中选择静默时间段，点击确定即可静默该告警，此操作存在时延，若表格未更新，请手动刷新查看。如图28和图29所示。

![28](/images/OCD/cluster028.png)

<center>图 28 静默告警 </center>

![29](/images/OCD/cluster029.png)

<center>图 29 静默告警时间选择 </center>


##### 5.4 恢复告警

在展示“**静默告警实例**”时，点击表格操作栏中的“**恢复**”按钮，二次确认后即可恢复该告警，此操作存在时延，若表格未更新，请手动刷新查看。如图30所示。

![30](/images/OCD/cluster030.png)

<center>图 30 恢复默告警 </center>
