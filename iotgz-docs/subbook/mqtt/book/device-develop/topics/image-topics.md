# 设备镜像 topic 簇

MQTT物联网套件支持用户通过设备镜像实现设备状态、配置信息的同步，如下图所示，详情见[设备镜像](/book/manual/image/introduce.md)

![](/images/devce-image/usage.jpg)

设备镜像 topic 簇 topic 列表如下：

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


## 设备镜像属性更新

设备可以通过向系统topic：$sys/{pid}/{device-name}/image/update 发布消息更新，payload示例：

```json
{
    "state": {
        "desired": {			
            "color": "green"
        },
        "reported": {	
            "color": "red"
        }
    }
}
```
其中，参数说明如下：
<table>
<tr><th width="10%">参数</th><th width="10%">类型</th><th>是否必填</th><th width="60%">说明</th></tr>
<tr><td>state</td><td>object</td><td>是</td><td>-</td></tr>
<tr><td>desired</td><td>object</td><td>-</td><td>用于更新设备状态/配置信息期望状态，与reported至少存在一项</td></tr>
<tr><td>reported</td><td>object</td><td>-</td><td>用于更新设备状态/配置信息当前状态，与desired至少存在一项</td></tr>
</table>

- 设备镜像更新**支持 QoS1**，若 publish QoS=1，则平台回复 publish ack
- 若镜像更新成功，平台通过系统topic：$sys/{pid}/{device-name}/image/update/accepted 下发成功消息
- 若镜像更新失败，平台通过系统topic：$sys/{pid}/{device-name}/image/update/rejected 下发更新失败消息，见错误码表
- 设备进行更新成功后，若reported 内容与desired内容产生了差异，则触发delta消息，设备可以通过订阅 系统topic：$sys/{pid}/{device-name}/image/update/delta 获取该差异消息

## 设备获取属性差异

当应用/设备更新reported 或者 desired属性后，平台会计算属性差异 delta，若delta存在，平台会发送该差异消息至系统topic：$sys/{pid}/{device-name}/image/update/delta，设备可以通过订阅该topic获取属性差异消息，消息示例如下：

```json
{
    "state": {
        "color": "green"
    },
    "metadata": {
        "color": {
            "timestamp": 1469574492
        }
    },
    "version":2,
    "timestamp":1469574492
}
```


## 设备镜像属性查询

设备可以通过向系统topic：$sys/{pid}/{device-name}/image/get 发布**空消息**查询当前镜像最新数据

- 设备镜像查询**支持 QoS1**，若 publish QoS=1，则平台回复 publish ack
- 若镜像查询成功，平台通过系统topic：$sys/{pid}/{device-name}/image/get/accepted 下发镜像最新数据
- 若镜像更新失败，平台通过系统topic：$sys/{pid}/{device-name}/image/get/rejected 下发更新失败消息，见错误码表


## 错误码

|错误码 err_code |错误消息 err_msg |说明|
|:-|:-|:-|
| 128 | unspecified error     | 未明确的错误 |
| 160 | illegal json | 非法json |
| 161 | json out of bound | json数据过长 |
| 162 | json depth out of bound | json嵌套层级过多 |
| 163 | state key not found | state字段不存在 |
| 164 | desired or reported key not found | 未包含"desired" 与 "reported"字段 |
| 165 | invalid parameters   | 存在非法参数 |
| 166 | device image existed | 设备镜像已存在 |
| 167 | device image not exists | 设备镜像不存在 |


## 更多帮助

[了解使用设备镜像进行设备状态同步的最佳实例](/book/example/image.md)