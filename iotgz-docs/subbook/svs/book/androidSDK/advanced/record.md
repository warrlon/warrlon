# 录音配置项

|参数名|取值|说明|默认值|
|-|-|-|-|
| K_RECORDER_MODE | external/internal | 录音机模式：<br>external（使用外置录音机，需主动调用拾音接口） | internal |
| | |internal（使用内置录音机AudioRecord，DDS自动录音） |
| K_AEC_MODE | external | AEC模式:<br>external（DDS会认为宿主设备已经完成了AEC回声消除，选择默认模组也可以支持唤醒打断） | N/A |
| K_AUDIO_SOURCE | AudioSource的取值 | 内置录音机数据源类型 | AudioSource.DEFAULT |
| K_IS_REVERSE_AUDIO_CHANNEL | true/false | 是否反转内置录音机通道 | false |
| K_AUDIO_BUFFER_SIZE | 数值型字符串 | 内置录音机读buffer的大小 | 通道数<br>* 16/8 * 16000 * 100/1000 B |
 