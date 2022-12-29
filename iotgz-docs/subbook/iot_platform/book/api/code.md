# 错误码

本文档列举API调用失败时，返回的错误码。出现缺少请求参数、不合法的请求参数等错误时，请参见具体API描述进行修改。

#### 资源权限相关错误码

| 错误码 | 描述 |
|:- | :- |
|authPermissionDeny | 鉴权失败 |
|resourePermissionDeny | 无资源访问权限 |
|parameterRequired | 缺少请求参数 |
|parameterMissing | 缺少请求参数 |
|invalidParameter | 不合法的请求参数 |

#### 项目相关错误码

| 错误码 | 描述 |
|:- | :- |
|projectCatNotFound | 项目行业标签不存在 |
|projectNotFound | 项目不存在 |
|projectCreateFailed | 项目创建失败 |
|projectUpdateFailed | 项目更新失败 |
|projectGetFailed | 项目详情获取失败 |
|projectHasDevice | 项目存在关联设备 |
|projectStatisticsFailed| 项目统计信息获取失败 |

#### 产品相关错误码

| 错误码 | 描述 |
|:- | :- |
|productNotFound | 产品不存在 |
|productHasNoDevice | 产品未创建设备 |

#### 设备相关错误码

| 错误码 | 描述 |
|:- | :- |
|deviceNotFound | 设备不存在 |
|setPropertyFailed | 设备属性设置失败 |
|setDesiredPeropertyFailed | 设备属性期望设置失败 |
|queryDesiredProperyFailed | 设备属性期望查询失败 |
|getTmProperties | 设备属性获取失败 |
|callTmService | 设备服务调用失败 |
|deleteDesiredPeropertyFailed | 设备属性期望删除失败 | 
|queryCurrentData | 设备最新数据查询失败 |
|queryPropertyHistoryData | 设备属性历史数据查询失败 |
|queryEventHistoryData | 设备事件历史数据查询失败 |
|queryOperationLog | 设备操作记录查询失败 | 

#### 场景联动相关错误码

| 错误码 | 描述 |
|:- | :- |
|sceneNotFound | 场景联动规则不存在 |
|sceneCreateFailed | 场景联动规则创建失败 |
|sceneUpdateFailed | 场景联动规则更新失败 |
|sceneDelGetFailed | 场景联动规则删除失败 |
|sceneUpdateStatusFailed | 场景联动规则状态切换失败 |