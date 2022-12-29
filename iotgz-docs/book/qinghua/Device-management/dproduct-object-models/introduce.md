# 开发产品物模型

# 什么是物模型

**1. 定义**

物模型是对设备的数字化抽象描述，描述该型号设备是什么，能做什么，能对外提供哪些服务。
物模型将物理空间中的实体设备数字化，在云端构建该实体的数据模型，即将物理空间的实体在云端进行格式化表示。

![物模型定位](/images\qinghua\device-management\object-model-definition.png)

如上图所示，物模型属于应用协议之上的语法语义层。在物联平台中，物模型完成对终端产品形态，产品功能的结构化定义，包括终端设备业务数据的格式和传输规则。

物模型功能模块在物联平台中的位置如图所示：

![物模型功能](/images\qinghua\device-management\object-model-function.png)

物模型在业务逻辑属于物联平台的设备管理模块，用于实现不同设备能够以统一的物模型标准对接应用平台，不同应用之间能够以统一物模型标准进行数据互通。

**2. 设备抽象模型**

物模型基础功能分为三类：属性、服务、事件，功能点数量不超过100个。

<table>
<tr style="background-color:#363636; color:#F0FFF0;"><td>功能类型</td><td width="80%">说明</td></tr>
<tr><td>属性</td><td>用于描述设备的动态特征，包括运行时的状态，应用可发起对属性的读取和设置请求</td></tr>
<tr><td>服务</td><td>用于描述终端设备可被外部调用的能力，可设置输入参数和输出参数。服务可实现复杂的业务逻辑，例如执行某项特定的任务；支持同步或异步返回结果</td></tr>
<tr><td>事件</td><td>设备运行时可以被触发的上行消息，如设备运行的记录信息，设备异常时发出的告警、故障信息等；可包含多个输出参数</td></tr> 
</table>

功能类别分为三类：系统、标准、自定义，可为属性、服务、事件三者任意组合。

<table>
<tr style="background-color:#363636; color:#F0FFF0;"><td>功能类型</td><td width="80%">说明</td></tr>
<tr><td>系统功能点</td><td>此类功能点多数与平台提供的服务有关，如定位服务、设备认证服务等</td></tr>
<tr><td>标准功能点</td><td>此类功能点多数与产品行业类别相关，为标准行业产品抽象出的一套标准的功能点</td></tr>
<tr><td>自定义功能点</td><td>此类功能点为用户自定义，产品非标准设备，用户按设备实际情况添加设备功能点，自由度较大</td></tr>
</table>

**3. 数据类型支持**

<table>
<tr style="background-color:#363636; color:#F0FFF0;"><td>类型</td><td>标识符</td><td width="50%">说明</td></tr>
<tr><td>整数型</td><td>int32、int64</td><td>整数、长整数</td></tr>
<tr><td>浮点型</td><td>float、double</td><td>单精度浮点、双精度浮点</td></tr>
<tr><td>时间类型</td><td>date</td><td>长整数的扩展类型，整数类型int64的UTC时间戳（毫秒）</td></tr>
<tr><td>布尔型</td><td>bool</td><td>true或false</td></tr>
<tr><td>字符型</td><td> string</td><td> 字符串，文本类型</td></tr>
<tr><td>枚举型</td><td>enum</td><td>枚举类型，枚举值为整数</td></tr>
<tr><td>位图型</td><td>bitMap</td><td>位图，多用于多个故障信号同时上送，非传统意义的图片数据</td></tr>
<tr><td>数组类型</td><td>array</td><td>数组类型，元素类型支持：int32、int64、float、double、string、date、struct</td></tr>
<tr><td>结构图</td><td> struct</td><td> 结构图类型，仅支持一层嵌套，成员类型不支持数组</td></tr>
</table>

**特别说明：**

<table>
<tr style="background-color:#363636; color:#F0FFF0;"><td>类型</td><td>比特数</td><td>有效数字</td><td width="40%">数值范围</td></tr>
<tr><td>float</td><td>32</td><td>6-7</td><td>-3.4*10^(-38)～3.4*10^(38)</td></tr>
<tr><td>double</td><td>64</td><td>15-16</td><td>-1.7*10^(-308)～1.7*10^(308)</td></tr>
</table>

**4. 物模型描述文件说明**

<table>
<tr style="background-color:#363636; color:#F0FFF0;"><td width="20%">名称</td><td width="80%">描述</td></tr>
<tr><td>properties</td><td>属性点集合</td>
<tr><td>events</td><td>事件点集合</td>
<tr><td>services</td><td>服务点集合</td>
<tr><td>identifier</td><td>功能点标识符/参数标识符，以"$"开始为系统功能点，功能点标识符产品下唯一</td>
<tr><td>name</td><td>功能点名字，用户自定义</td>
<tr><td>functionType</td><td>功能类型，用户自定义(u)/系统功能点(s)/标准功能点(st)</td>
<tr><td>accessMode</td><td>读写类型，只读(r)/读写(rw)</td>
<tr><td>dataType</td><td>数据描述集合</td>
<tr><td>type</td><td>数据类型</td>
<tr><td>eventType</td><td>事件类型：信息（info）、告警（alert)、故障(error)</td>
<tr><td>specs</td><td>数据类型描述的时候存在</td>
<tr><td>desc</td><td>用户自定义描述</td>
<tr><td>inputData</td><td>输入参数集合</td>
<tr><td>outputData</td><td>输出参数集合</td>
</table>