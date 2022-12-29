# API列表

行业开发平台支持在线调试API。

[![1](/images/API调试入口.png)](https://open.iot.10086.cn/industry/open-website/docs/rest#doc)


#### &#128366; 调试必读：

&#10004; 所有请求Header

<h4><font color=#CD8162>&nbsp;&nbsp;&nbsp;Content-Type: application/json</font></h4>

&#10004; 统一前缀

<h4><font color=#CD8162>&nbsp;&nbsp;&nbsp;{domain}/industry/open-api/{version}/{apiUrl}</font></h4>
 
&nbsp;&nbsp;&nbsp;其中domain为<font color=#CD8162>https://open.iot.10086.cn</font>，version代表当前版本号<font color=#CD8162>v1</font>，apiUrl代表<font color=#CD8162>URL地址</font>。

&#10004; 关于鉴权

&nbsp;&nbsp;&nbsp;若无特殊说明，均使用鉴权方式。header携带服务端交换的token, header中key为project-token,文档中"鉴权"说明均是相应key对应的token。

> 示例：调用2.1创建群组Key接口时，需要在请求中设置key为project-token，value为masterKey换取的token的header。

&#10004; 关于响应

&nbsp;&nbsp;&nbsp;所有响应中包含code/msg 字段说明。

<font color=#CD8162>&nbsp;&nbsp;&nbsp;{code:200, msg:'OK'}</font>表示请求成功。<font color=#CD8162>data</font>字段为具体数据，当code不为200时，msg为相应错误原因。

&#10004;关于分页

&nbsp;&nbsp;&nbsp;tag <font color=#CD8162>pagenation</font> 表示该接口可传分页参数，query参数可携带<font color=#CD8162>{offset: 0, limit: 10}</font>。

&nbsp;&nbsp;&nbsp;其中limit为<font color=#CD8162>每页显示条数</font>，offset为<font color=#CD8162>跳过的数据条数</font>。默认值：limit为10,offset为0，响应中data.count表示<font color=#CD8162>数据总条数</font>。

&#10004;关于key

<font color=#CD8162>&nbsp;&nbsp;&nbsp;群组Key</font>代表一个群组的key，<font color=#CD8162>masterKey</font>代表项目唯一的key</font>。

&#10004; 关于加密

&nbsp;&nbsp;&nbsp;接口中所有传输的key(群组Key/masterKey)可选择<font color=#CD8162>加密</font>和<font color=#CD8162>非加密</font>模式，<font color=#CD8162>默认加密</font>(使用API列表下方的加解密方法)，如果非加密，请传query参数unencrypted为true。

#### API列表

<table>
<tr><th width="20%">类别</th><th width="30%">API名称</th><th width="20%">类别</th><th width="30%">API名称</th></tr>
<tr><td>鉴权类API</td><td>换取token</td><td rowspan="3">项目相关API</td><td>获取项目下授权产品</td></tr>
<tr><td rowspan="4">Key相关API</td><td>创建群组Key</td><td>项目创建设备配网</td></tr>
<tr><td>重置群组Key</td><td>项目设备配网结果查询</td></tr>
<tr><td>获取项目所有群组Key</td><td rowspan="2">工具类相关API</td><td>获取省市区三级联动详情</td></tr>
<tr><td>删除群组Key</td><td>获取第三方数据</td>
<tr><td rowspan="9">设备相关API</td><td>群组Key添加设备</td><td rowspan="5">联动管理相关API</td><td>创建联动</td></tr>
<tr><td>群组Key移除设备</td><td>修改联动</td></tr>
<tr><td>设备列表</td><td>联动详情</td></tr>
<tr><td>命令下发</td><td>联动列表</td></tr>
<tr><td>命令下发日志查询</td><td>联动执行日志查询</td></tr>
<tr><td>修改设备</td><td>-</td><td>-</td></tr>
<tr><td>设备详情</td><td>-</td><td>-</td></tr>
<tr><td>设备分享</td><td>-</td><td>-</td></tr>
<tr><td>取消分享</td><td>-</td><td>-</td></tr>
</table>

#### <span id="a1"> &#9863; 加/解密算法</span>

java参考资料: https://blog.csdn.net/linminqin/article/details/19972751

> 注意：每次加密应当实时计算，解密后会对时间戳校验，超过两分钟被认为非法Key

```javascript
// 加密算法：明文key + 5位随机码 + 13位时间戳的 => 通过 aes-128-ecb 加密 => 转为16进制
// 1. 创建Cipher实例密钥为项目的access_key，加密算法为aes256
// 2. 使用Cipher实例加密明文(输入utf8，输出hex)，明文结构为 key + 5位随机码 + Unix时间戳
// 3. Cipher实例输出16进制密文
// Nodejs 代码 msg: key明文, accessKey: 项目access_key
function encode (msg, accessKey) {
  const random = Math.random().toString().slice(3, 8)
  const cipher = crypto.createCipher('aes-128-ecb', accessKey)
  let encodeMsg = cipher.update(`${msg}${random}${new Date().getTime()}`, 'utf8', 'hex')
  encodeMsg += cipher.final('hex')

  return encodeMsg
}
// 解密算法：密文key => 通过 aes-128-ecb 解密 =>  项目key + 5位随机码 + 13位时间戳
// 1. 创建Decipher实例密钥为项目access_key，解密算法为aes256
// 2. 使用Decipher实例解密密文(输入hex，输出utf8),明文结构为 key + 5位随机码 + Unix时间戳
// 3. Decipher实例输出utf8编码明文key
// Nodejs 代码 msg: key密文, accessKey: 项目access_key
function decode (msg, accessKey) {
  const decipher = crypto.createDecipher('aes-128-ecb', accessKey)
  let decrypted = decipher.update(msg, 'hex', 'utf8')
  decrypted += decipher.final('utf8')

  const key = decrypted.substring(0, decrypted.length - 18)

  const requestTime = decrypted.substring(decrypted.length - 13)

  return key
}
```
#### <span id="a2">&#9863; 错误码对应表</span>

统一错误码列表如下：

| 错误码 | 说明 |
| ---- | ---- |
| 10002 | 请求参数错误，httpStatus等于400 |
| 10003 | 内部错误，httpStatus等于500 |
| 12001 | RESTful接口操作资源时，该资源依赖的其他资源不存在，详见错误msg |
| 40003 | confirm-code 已失效，需重新加密计算 |
| 40004 | confirm-code 解密计算失败，确认密文是否有效 |
| 40005 | 越权错误，详见msg |
| 50001 | IMEI校验错误 |
| 50002 | 当前key下无此设备或者设备不存在 |

#### <span id="a3"> &#9863; 第三方数据说明</span>

- 设置第三方数据条件时，除了<font color=#CD8162>number</font>类型可选所有比较动作,其余都只能'EQ'。
- 设置第三方数据条件时，所有<font color=#CD8162>enum</font>类型stander_value字段为中文枚举值。

| 字段 | 含义 | 数据类型 | 备注 |
| - | - | - | - |
| WEATHER | 天气 | enum | 晴天/阴天/雨天/雪天/霾天/雾天 |
| TEMPERATURE | 温度 | number | 单位 摄氏度 |
| HUMIDITY | 湿度 | enum | 干燥（低于40%）/舒适（40%- 60%）/潮湿（高于60%） |
| PM25 | PM2.5 | enum | 优（0~35μg/m³）/良（35~75μg/m³）/污染（75μg/m³以上） |
| AIRQUALITY | 空气质量 | enum | 优/良/轻度污染/中度污染/重度污染/严重污染 |

<div>
    <a href="/book/project_integrator/key_use.md">
        <span> &#171; 上一篇：项目集成商_Key管理</span>
    </a>
</div>
<div>
    <a href="/book/download/download_list.md">
        <span> &#187; 下一篇：下载专区</span>
    </a>
</div>