# 麦克风阵列配置项

|参数名|取值|说明|默认值|
|-|-|-|-|
| K_MIC_TYPE | partner/dialog | 0、1、2、3、4、5、6、7	<br>设置硬件采集模组的类型<br>0：原始单麦（1路音频）<br>1：单麦回消（1路音频+1路参考音）<br>2：线性四麦（4路音频）<br>3：环形六麦（6路音频）<br>4：车载双麦（2路音频）<br>5：家居双麦（2路音频）<br>6：环形四麦（4路音频）<br>7：新车载双麦（2路音频）-- 替换原有车载双麦方案<br>默认使用DUI控制台上产品的对应配置项。若客户端通过SDK配置此项后，则以客户端配置为准。 | 线上的采集模组配置 
| K_MIC_ARRAY_AEC_CFG | 麦克风阵列aec资源的磁盘绝对路径，比如/data/aec.bin | 麦克风阵列aec资源的磁盘绝对路径<br>1. 麦克风阵列的AEC默认做在ROM里。若需SDK做AEC，请配置此项。<br>2.需要开发者确保在这个路径下这个资源存在。<br>3.需要开发者在外部实现录音机（参考K_RECORDER_MODE）。<br> | 无 
| K_MIC_ARRAY_BEAMFORMING_CFG | 麦克风阵列beamforming资源的磁盘绝对路径，比如/data/beamforming.bin | 克风阵列beamforming资源的磁盘绝对路径<br>1.需要开发者确保在这个路径下这个资源存在。<br>2.默认的双麦/四麦/六麦内置资源为35mm/35mm/72mm。 | 内置资源 
| K_WAKEUP_BIN | 麦克风阵列wakeup配置资源的磁盘绝对路径，比如/data/wakeup_cfg.bin | 麦克风阵列wakeup配置资源的磁盘绝对路径<br>需要开发者确保在这个路径下这个资源存在 | 内置资源 