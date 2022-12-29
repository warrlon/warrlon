# **接入安全认证**

# **设备安全认证**

#### **1. 鉴权参数**

设备鉴权参数（鉴权三元组）如下：

<table>
<tr style="background-color:#363636; color:#F0FFF0;"><td width="30%">参数</td><td>描述</td></tr>
<tr><td>ProductId</td><td>产品ID，平台生成唯一ID</td></tr>
<tr><td>DeviceName</td><td>设备名称</td></tr>
<tr><td>Token</td><td>鉴权token</td></tr> 
</table>

#### **2. Token算法**  

Token由多个参数构成，如下表：

<table style="text-align: left">
<tr style="background-color:#363636; color:#F0FFF0;"><td>名称</td><td width="10%">类型</td><td width="10%">是否必须</td><td width="40%">参数说明</td><td>参数示例</td></tr>
<tr><td>version</td><td>string</td><td>是</td><td>参数组版本号，日期格式，目前仅支持"2018-10-31"</td><td>2018-10-31</td></tr>
<tr><td>res</td><td>string</td><td>是</td><td>访问资源 resource格式为：products/{产品id}/devices/{设备名字}</td><td>products/dafdfadfafdaf/devices/che1</td></tr>
<tr><td>et</td><td>int</td><td>是</td><td>访问过期时间 expirationTime，单位秒，unix时间当一次访问参数中的et时间小于当前时间时，平台会认为访问参数过期从而拒绝该访问</td><td>1537255523表示：北京时间 2018-09-18 15:25:23</td></tr>
<tr><td>method</td><td>string</td><td>是</td><td>签名方法 signatureMethod支持hmacmd5、hmacsha1、hmacsha256</td><td>sha1（代表使用hmacsha1算法）</td></tr>
<tr><td>sign</td><td>string</td><td>是</td><td>签名结果字符串signature</td><td>rBYeJXTp2q4V3C2aj4DBzjaydcw%3D</td></tr>

</table>

- sign算法  
  
参数sign的生成算法为：

    sign = base64(hmac_<method>(base64decode(key), utf-8(StringForSignature)))  

其中Key为平台为资源分配的访问密钥(产品级、设备级均可)，其作为签名算法参数之一参与签名计算，为保证访问安全，请妥善保管；Key参与计算前应先进行base64decode操作，用于计算签名的字符串 StringForSignature的组成顺序按照参数名称进行字符串排序，以'\n'作为参数分隔，当前版本中按照如下顺序进行排序：et、method、res、version

StringForSignature组成示例如下：  

    StringForSignature = et + '\n' + method + '\n' + res+ '\n' + version

注意：每个参数均为key=value格式组成，但是仅参数中的value参与计算签名的字符串 StringForSignature的组成，若token参数如下：

    et = 1537255523  
    method = sha1
    res = products/dafdfadfafdaf/devices/che1
    version = 2018-10-31

则用于计算签名的字符串StringForSignature为（按照et、method、res、version的顺序）

    StringForSignature = "1537255523" + "\n" + "sha1"+ "\n" + "products/123123"+ "\n" + "2018-10-31"

计算出sign后，将每个参数均采用key=value的形式表示，并用'&'作为分隔符，示例如下：

    version=2018-10-31&res=products/dafdfadfafdaf/devices/che1&et=1537255523&method=sha1&sign=ZjA1NzZlMmMxYzIOTg3MjBzNjYTI2MjA4Yw=

- 参数编码

Token中key=value的形式的value部分需要经过URL编码，需要进行编码的特殊符号如下：

<table>
<tr style="background-color:#363636; color:#F0FFF0;"><td>序号</td><td>特殊序号</td><td> URL编码</td></tr>
<tr><td>1</td><td>+ </td><td>%2B</td></tr>
<tr><td>2</td><td>空格</td><td>%20</td></tr>
<tr><td>3</td><td>/</td><td>%2F</td></tr>
<tr><td>4</td><td>?</td><td>%3F</td></tr>
<tr><td>5</td><td>% </td><td>%25</td></tr>
<tr><td>6</td><td>#</td><td>%23</td></tr>
<tr><td>7</td><td>&</td><td>%26</td></tr>
<tr><td>8</td><td>=</td><td>%3D</td></tr>
</table>

编码后，上例中实际传输Token为：

    version=2018-10-31&res=products%2F123123%2Fdevices%2Fche1&et=1537255523&method=sha1&sign=ZjA1NzZlMmMxYzIOTg3MjBzNjYTI2MjA4Yw%3D

#### **3. Token生成工具**  

为便于开发者开发，平台提供Token生成工具([点击下载](https://open.iot.10086.cn/doc/iot_platform/images/tools/token.exe))

##### 打开生成工具**token.exe**

![token1](/images/device-management/standard-security/token1.png)

##### 填写对应参数，点击**generate**  

![token2](/images/device-management/standard-security/token2.png)

##### 生成Token如下： 

![token3](/images/device-management/standard-security/token3.png)
