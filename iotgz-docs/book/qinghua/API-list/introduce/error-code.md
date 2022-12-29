# 错误码

本文档列举API调用失败时，返回的错误码。出现缺少请求参数、不合法的请求参数等错误时，请参见具体API描述进行修改。

#### **资源权限相关错误码**

<table>
<tr style="background-color:#363636; color:#F0FFF0;"><td width="25%">错误码</td><td width="75%">描述</td></tr>
<tr><td>authPermissionDeny</td><td>鉴权失败</td></tr>
<tr><td>resourePermissionDeny</td><td>无资源访问权限</td></tr>
<tr><td>parameterRequired</td><td>缺少请求参数</td></tr>
<tr><td>parameterMissing</td><td>缺少请求参数</td></tr>
<tr><td>invalidParameter</td><td>不合法的请求参数</td></tr>
</table>

#### **项目相关错误码**

<table>
<tr style="background-color:#363636; color:#F0FFF0;"><td width="25%">错误码</td><td width="75%">描述</td></tr>
<tr><td>projectCatNotFound</td><td>项目行业标签不存在</td></tr>
<tr><td>projectNotFound</td><td>项目不存在</td></tr>
<tr><td>projectCreateFailed</td><td>项目创建失败</td></tr>
<tr><td>projectUpdateFailed</td><td>项目更新失败</td></tr>
<tr><td>projectGetFailed</td><td>项目详情获取失败</td></tr>
<tr><td>projectHasDevice</td><td>项目存在关联设备</td></tr>
<tr><td>projectStatisticsFailed</td><td>项目统计信息获取失败</td></tr>
</table>

#### **产品相关错误码**

<table>
<tr style="background-color:#363636; color:#F0FFF0;"><td width="25%">错误码</td><td width="75%">描述</td></tr>
<tr><td>productNotFound</td><td>产品不存在</td></tr>
<tr><td>productHasNoDevice</td><td>产品未创建设备</td></tr>
</table>

#### **设备相关错误码**

<table>
<tr style="background-color:#363636; color:#F0FFF0;"><td width="25%">错误码</td><td width="75%">描述</td></tr>
<tr><td>deviceNotFound</td><td>设备不存在</td></tr>
<tr><td>setPropertyFailed</td><td>设备属性设置失败</td></tr>
<tr><td>setDesiredPeropertyFailed</td><td>设备属性期望设置失败</td></tr>
<tr><td>queryDesiredProperyFailed</td><td>设备属性期望查询失败</td></tr>
<tr><td>getTmProperties</td><td>设备属性获取失败</td></tr>
<tr><td>callTmService</td><td>设备服务调用失败</td></tr>
<tr><td>deleteDesiredPeropertyFailed</td><td>设备属性期望删除失败</td></tr>
<tr><td>queryCurrentData</td><td>设备最新数据查询失败</td></tr>
<tr><td>queryPropertyHistoryData</td><td>设备属性历史数据查询失败</td></tr>
<tr><td>queryEventHistoryData</td><td>设备事件历史数据查询失败</td></tr>
<tr><td>queryOperationLog</td><td>设备操作记录查询失败</td></tr>
</table>