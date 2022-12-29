# Device Mirror Topic Cluster


The list of top clusters for device mirroring is as follows:

<table>
<tr><th width="45%">系统topic</th><th>用途</th><th width="8%">QoS</th><th width="10%">可订阅</th><th width="10%">可发布</th></tr>
<tr><td>$sys/{pid}/{device-name}/image/update</td><td>设备更新镜像中属性</td><td>0/1</td><td> </td><td>√</td></tr>
<tr><td>$sys/{pid}/{device-name}/image/update/accepted</td><td>系统通知"设备镜像更新成功"</td><td>0</td><td>√</td><td></td></tr>
<tr><td>$sys/{pid}/{device-name}/image/update/rejected</td><td>系统通知"设备镜像更新失败"</td><td>0</td><td>√</td><td></td></tr>
<tr><td>$sys/{pid}/{device-name}/image/update/delta</td><td>系统通知"属性中上报值与期望值存在差异"</td><td>0</td><td>√</td><td></td></tr>
<tr><td>$sys/{pid}/{device-name}/image/get</td><td>设备镜像信息查询</td><td>0/1</td><td> </td><td>√</td></tr>
<tr><td>$sys/{pid}/{device-name}/image/get/accepted</td><td>系统通知"设备镜像查询成功"</td><td>0</td><td>√</td><td></td></tr>
<tr><td>$sys/{pid}/{device-name}/image/get/rejected</td><td>系统通知"设备镜像查询失败"</td><td>0</td><td>√</td><td></td></tr>
</table>


### Device Mirror Property Update

Devices can be updated by posting messages to system topic: $sys/{pid}/{device-name}/image/update, payload example:

```json
{
    "state": {
        "desired": {            
            "color": "red"
        },
        "reported": {   
            "color": "red"
        }
    }
}
```
Among them, the parameters are as follows:
<table>
<tr><th width="10%">参数</th><th width="10%">类型</th><th>是否必填</th><th width="60%">说明</th></tr>
<tr><td>state</td><td>object</td><td>是</td><td>-</td></tr>
<tr><td>desired</td><td>object</td><td>-</td><td>用于更新设备状态/配置信息期望状态，与reported至少存在一项</td></tr>
<tr><td>reported</td><td>object</td><td>-</td><td>用于更新设备状态/配置信息当前状态，与desired至少存在一项</td></tr>
</table>


Device Mirror Update**Support for QoS1**If publish QoS = 1, the platform replies to publish ACK

## Error code

|Error code err_code |Error message err_msg |Explain|
|:-|:-|:-|
| 128 | unspecified error     | Uncertain errors |
| 160 | illegal json | Illegal JSON |
| 161 | json out of bound | JSON data is too long |
| 162 | json depth out of bound | Too many levels of JSON nesting |
| 163 | state key not found | State field does not exist |
| 164 | desired or reported key not found | To include "desired" and "reported" fields |
| 165 | invalid parameters   | There are illegal parameters |
| 166 | device image existed | Device Mirror Existing |
| 167 | device image not exists | Device Mirror does not exist |