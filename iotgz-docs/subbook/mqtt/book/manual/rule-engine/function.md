# 内置函数

**SELECT**语句中支持使用内置函数获取设备相关常量数据（函数名区分大小写）

内置函数返回内容均为**字符串常量**，支持相关插入操作，用法说明如下：

<table>
<tr><th width="15%">函数名</th><th width="25%">说明</th><th>用法示例</th><th>备注</th></tr>
<tr><td>imei()</td><td>获取NB设备imei号</td><td>SELECT *,imei() as imei</td><td>仅NB设备支持，对于其他协议设备，函数返回为空字符串""</td></tr>
<tr><td>bin_data()</td><td>获取设备消息中的二进制数据</td><td>SELECT *,bin_data() as bin_data</td><td>仅对设备上传的二进制数据点生效，提取数据点中的二进制数据，并转为16进制字符串格式，示例：0x0102被转为"0102"<br>对于非二进制的数据点，函数返回空字符串""<br>注：二进制数据点大小限制为80k</td></tr>
<tr><td>deviceName()</td><td>获取设备名称</td><td>SELECT *,deviceName() as name</td><td>获取产生该消息的设备名称</td></tr>
</table>

内置函数使用示例如下：
<table>
<tr><th width="10%">原JSON</th><th width="30%">SQL语句</th><th>结果示例</th><th>说明</th></tr>
<tr><td>{"a":1}</td><td>SELECT *,imei() as b</td><td>{"a":1,"b":"4A7B3123F202"}</td><td>NB设备</td></tr>
<tr><td>{"a":1}</td><td>SELECT *,imei() as b</td><td>{"a":1,"b":""}</td><td>非NB设备时为空</td></tr>
<tr><td>{"a":1}</td><td>SELECT *,bin_data() as b</td><td>{"a":1,"b":"010203"}</td><td>二进制数据点</td></tr>
<tr><td>{"a":1}</td><td>SELECT *,bin_data() as b</td><td>{"a":1,"b":""}</td><td>非二进制数据点时为空</td></tr>
<tr><td>{"a":1}</td><td>SELECT *,deviceName() as b</td><td>{"a":1,"b":"mydevice"}</td><td>-</td></tr>
</table>
