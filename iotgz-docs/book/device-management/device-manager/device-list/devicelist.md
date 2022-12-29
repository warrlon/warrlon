# **设备管理**  

# **设备列表**  

用户点击选择【设备管理】，进入设备管理页面，该页面默认展示全部产品的【设备列表】信息，支持产品范围切换查看。页面具体包括设备总数、在线设备数和激活设备数统计信息，以及设备列表中设备名称、所属产品、设备状态、IMEI、IMSI、节点类型、设备来源、添加时间、最新在线时间等信息。

![device-list](/images/device-management/device-list/device-list.png)

该页面支持以下功能：

- 支持用户自定义列表展示字段
- 支持通过设备状态、设备来源、设备名称和IMEI进行搜索功能
- 支持设备编辑功能
- 支持设备添加功能
- 支持设备单一删除功能
- 支持设备批量删除功能
- 支持设备导出功能
- 支持设备详情查看功能

以查看详情、添加设备为例，进行重点描述。

#### **1、查看详情**  

用户通过导航栏进入【设备管理】页面，默认展示设备列表内容，通过点击【详情】按钮，可进入具体设备详情介绍页面。

![device-info](/images/device-management/device-list/device-info.png)

该页面支持以下功能：

- 支持设备信息编辑  
- 支持设备密钥更新功能  
- 支持实时和历史属性数据查询  
- 支持事件记录信息查询  
- 支持服务记录信息查询  
- 支持操作记录信息查询  
- 支持子设备管理信息查询  
- 支持文件管理信息查询  

**（1)操作记录**

用户进入设备详情界面，切换点击【操作记录】按钮，系统默认设备最近一小时所有操作记录列表。

![device-operation-record](/images/device-management/device-list/device-operation-record.png)

该子页面支持以下功能：
  
- 支持用户通过时间按钮（最近1小时、最近24小时、最近7天、任意时间）进行搜索查询功能  
- 支持用户查看操作记录详情功能  

**（2)设备属性**

用户进入设备详情界面，系统默认展示该设备不同属性的功能名称、数据类型、标识符、读写类型等。  

![device-info](/images/device-management/device-list/device-info.png)

该子页面支持以下功能：

- 支持用户开启【实时刷新】按钮实现实时数据的更新展示  
- 支持用户点击【历史数据】按钮，通过时间按钮（最近1小时、最近24小时、最近7天、任意时间）进行数据查询  

**（3)事件记录**

用户进入设备详情界面，切换点击【事件记录】按钮，系统默认设备最近一小时所有事件记录列表。

![device-event-record](/images/device-management/device-list/device-event-record.png)

该子页面支持以下功能：

- 支持用户通过事件类型（信息、告警、故障）、时间按钮（最近1小时、最近24小时、最近7天、任意时间）、标识符进行事件记录搜索查询  
- 支持用户查看服务记录详情功能  

**（4)服务记录**

用户进入设备详情界面，切换点击【服务记录】按钮，系统默认设备最近一小时所有服务记录列表。

![device-list/device-service-record](/images/device-management/device-list/device-service-record.png)

该子页面支持以下功能：

- 支持用户通过时间按钮（最近1小时、最近24小时、最近7天、任意时间）、标识符进行搜索查询功能  
- 支持用户查看服务记录详情功能

**（5)子设备管理**

仅网关设备有【子设备管理】功能， 用户切换至该页面时，默认展示搞网关设备下子设备列表，包括设备名称、所属产品、节点类型、设备状态、最近在线时间。

![device-list/getway-sub-dev](/images/device-management/device-list/getway-sub-dev.png)

该子页面支持以下功能：
 
- 支持用户基于设备名称进行搜索功能  
- 支持用户查看设备详情功能  
- 支持用户解绑子设备功能  
- 支持用户关联子设备功能  
- 支持同步拓扑关系至网关  

其中，【关联子设备功能】同【解绑】功能联动，当该子设备下的设备已关联时，在最新的设备列表中不予显示；反之，当该设备未关联或已解绑时，用户可重新关联。

<div align=center><img src ="/images/device-management/device-list/relation-sub-dev.png"/></div>

**（6)文件管理**

用户进入设备详情界面，切换点击【文件管理】按钮，系统默认展示该设备所有文件。

![dev-file](/images/device-management/device-list/dev-file.png)

该子页面支持以下功能：  

- 支持用户用户自定义上传文件，可点击【上传文件】按钮，支持.jpg .jpeg .png .bmp .gif .webp .tiff .txt .exe .jar .zip .rar；格式文件上传  
- 支持用户查看详情功能  
- 支持用户删除文件功能  

#### **2、添加设备**  

用户通过导航栏进入【设备管理】界面，点击【添加设备】按钮。

<div align=center><img src ="/images/device-management/device-list/device-add1.png"/></div>

<div align=center><img src ="/images/device-management/device-list/device-add2.png"/></div>

该页面支持以下功能：

- 支持用户通过设备名称、所属产品、设备描述和设备信息添加单个产品  
- 支持用户通过模板批量上传多个设备  











