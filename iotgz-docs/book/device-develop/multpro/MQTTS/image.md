# 设备镜像

设备镜像是OneNET为每一个设备分配的用于存储设备最新状态/配置信息的json文档

## 应用场景
设备镜像可以应用于以下场景：

- 存储设备静态属性，例如：设备的安装位置
- 存储设备当前状态信息，例如：设备当前网络连接模式、运行状态
- 同步设备与应用之间的长时间任务的执行状态，例如：设备上报固件升级过程中的各个状态与升级结果通知
- 应用层查询设备的配置/状态信息
- 在弱网/低功耗状态下，应用层期望设备达到的某个长期的配置/状态，设备镜像可以托管该通信过程，在设备上线后完成该配置/状态的期望值通信


设备镜像json文档包含如下信息：
- 系统属性

    系统为设备定义的属性，例如，设备ID、创建时间、在线状态等，对设备不可见，对应用层为**只读**

- 标记（tags）

    用于标记设备类别，例如，部署区域、应用项目，对设备不可见，对应用层为**可读写**

- 期望属性（desired）

    用于应用层表达设备所期望达到的某个状态/配置，对应用层与设备均为**可读写**

- 报告属性（reported）

    用于设备上报当前的状态/配置信息，与期望属性结合使用，当设备报告属性与期望属性存在差异，平台可以发送该差异给设备，可实现同步设备配置/状态，对应用层与设备均为**可读写**

- 属性差异（delta）

    用于表达报告属性与期望属性之间的差异值，每次镜像json更新后，均会触发差异计算，若存在差异值，平台可以发送该差异消息给设备，该差异对于应用层与设备均为**只读**

## 常见使用方式

在实际应用场景中可以参考如下使用方式：
- 设备订阅delta消息并上报属性至reported
- 应用层在需求设备进行状态/配置信息变更时，更新desired属性
- 设备在线且设备订阅了delta消息时，平台下发delta消息至设备
- 设备接收delta消息并作出状态/配置调整，上报新的属性至reported，当reported与desired一致时，delta属性消失
- 设备与应用可定期查询全量属性
- 应用可通过标签标记设备类别

![](/images/devce-image/usage.jpg)

## 设备镜像json

设备镜像json示例如下：
```json
{
    "deviceId": "638612",
    "createTime": 1469564492,
    "connectionState": "online",

    "tags": {
        "building": "43",
        "floor": "1"
    },

    "properties": {
        "state": {
            "desired": {
                "lights": {
                    "color": "RED"
                },
                "engine": "ON"
            },
            "reported": {
                "lights": {
                    "color": "GREEN"
                },
                "engine": "ON"
            },
            "delta": {
                "lights": {
                    "color": "RED"
                }
            }
        },
        "metadata": {
            "desired": {
                "lights": {
                    "color": {
                        "timestamp": 1469564492
                    }
                },
                "engine": {
                    "timestamp": 1469564492
                }
            },
            "reported": {
                "lights": {
                    "color": {
                        "timestamp": 1469564492
                    }
                },
                "engine": {
                    "timestamp": 1469564492
                }
            }
        },
        "version": 10,
        "timestamp": 1469564492
    }
}
```

json中，系统属性字段说明如下：
<table>
<tr><th width="20%">key</th><th width="20%">value类型</th><th width="60%">说明</th></tr>
<tr><td>deviceId</td><td>string</td><td>设备ID</td></tr>
<tr><td>createTime</td><td>int</td><td>设备创建时间，unix时间戳，单位为秒</td></tr>
<tr><td>connectionState</td><td>string</td><td>设备连接状态：online / offline</td></tr>
<tr><td>tags</td><td>object</td><td>设备标签，key-value格式，不支持json嵌套</td></tr>
<tr><td>properties</td><td>object</td><td>包含state、metadata、version、timestamp等属性<br>state：包含设备报告属性、期望属性、属性差异<br>metadata：state中个属性的最近时间记录<br>version：版本记录，每次更新累加1<br>timestamp：properties最近更新时间记录</td></tr>
</table>


## 使用限制
设备镜像json对象具有以下使用限制：
- json整体大小不得超过4k
- properties中key的使用限制：长度1-30，由英文字母、数字、下划线组成
- properties中 reported 与 desired 属性json对象的最大嵌套深度为4层，例如以下对象是有效的：

```json
{
    "state": {
        "reported": {
            "one": {
                "two": {
                    "three": {
                        "four": {
                            "key": "value"
                        }
                    }
                }
            }
        }
    }
}
```

## 更多帮助

[了解设备开发指南，见设备镜像topic簇的使用手册](/book/device-develop/multpro/MQTTS/topics/image-topics.md)
