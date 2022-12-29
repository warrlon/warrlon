# 设备安全认证

<a href="#1">1. 鉴权参数</a>

<a href="#2">2. Token算法</a>

<a href="#3">3. Token生成工具</a>

---

<h3 id="1">1. 鉴权参数</font></h3>

设备鉴权参数（鉴权三元组）如下：

| 参数       | 描述       |
| ---------- | ---------- |
| ProductId   | 产品ID，平台生成唯一ID |
| DeviceName | 设备名称   |
| Token   | 鉴权token  |

<h3 id="2">2. Token算法</font></h3>

Token由多个参数构成，如下表：

| 名称    | 类型   | 是否必须 | 参数说明                                                                                                          | 参数示例                                     |
| ------- | ------ | -------- | ----------------------------------------------------------------------------------------------------------------- | -------------------------------------------- |
| version | string | 是       | 参数组版本号，日期格式，目前仅支持"2018-10-31"                                                                    | 2018-10-31                                   |
| res     | string | 是       | 访问资源 resource格式为：products/{产品id}/devices/{设备名字}                                                     | products/dafdfadfafdaf/devices/che1          |
| et      | int    | 是       | 访问过期时间 expirationTime，单位秒，unix时间当一次访问参数中的et时间小于当前时间时，平台会认为访问参数过期从而拒绝该访问 | 1537255523表示：北京时间 2018-09-18 15:25:23 |
| method  | string | 是       | 签名方法 signatureMethod支持hmacmd5、hmacsha1、hmacsha256                                                         | sha1（代表使用hmacsha1算法）                 |
| sign    | string | 是       | 签名结果字符串signature                                                    | rBYeJXTp2q4V3C2aj4DBzjaydcw%3D           |


- sign算法

参数sign的生成算法为：

```text
sign = base64(hmac_<method>(base64decode(key), utf-8(StringForSignature)))
```

其中：
Key为OneNET为资源分配的访问密钥(产品级、设备级均可)，其作为签名算法参数之一参与签名计算，为保证访问安全，请妥善保管
Key参与计算前应先进行base64decode操作
用于计算签名的字符串 StringForSignature的组成顺序按照参数名称进行字符串排序，以'\n'作为参数分隔，当前版本中按照如下顺序进行排序：et、method、res、version
StringForSignature组成示例如下：

```text
StringForSignature = et + '\n' + method + '\n' + res+ '\n' + version
```

注意：每个参数均为key=value格式组成，但是仅参数中的value参与计算签名的字符串 StringForSignature的组成，若token参数如下

```text
et = 1537255523
method = sha1
res = products/dafdfadfafdaf/devices/che1
version = 2018-10-31
```

则用于计算签名的字符串StringForSignature为（按照et、method、res、version的顺序）

```text
StringForSignature = "1537255523" + "\n" + "sha1"+ "\n" + "products/123123"+ "\n" + "2018-10-31"
```

计算出sign后，将每个参数均采用key=value的形式表示，并用'&'作为分隔符，示例如下：

```text
version=2018-10-31&res=products/dafdfadfafdaf/devices/che1&et=1537255523&method=sha1&sign=ZjA1NzZlMmMxYzIOTg3MjBzNjYTI2MjA4Yw=
```

- 参数编码

Token中key=value的形式的value部分需要经过URL编码，需要进行编码的特殊符号如下：

| 序号   |  特殊符号    |  URL编码 |
| --- | ---- | --- |
| 1   | +    | %2B |
| 2   | 空格 | %20 |
| 3   | /    | %2F |
| 4   | ?    | %3F |
| 5   | %    | %25 |
| 6   | #    | %23 |
| 7   | &    | %26 |
| 8   | =    | %3D |

编码后，上例中实际传输Token为：

```text
version=2018-10-31&res=products%2F123123%2Fdevices%2Fche1&et=1537255523&method=sha1&sign=ZjA1NzZlMmMxYzIOTg3MjBzNjYTI2MjA4Yw%3D
```

<h3 id="3">3. Token生成工具</font></h3>

为便于开发者开发，平台提供Token生成工具（[点击下载](/images/tools/token.exe)）

- 打开生成工具 **token.exe**

<center>
    <img width="75%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/MQTTS/token/open.png">
    <br>
    <br>
</center>

- 填写对应参数，点击**generate**

<center>
    <img width="75%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/MQTTS/token/generate.png">
    <br>
    <br>
</center>

- 生成Token如下：

<center>
    <img width="75%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/MQTTS/token/end.png">
    <br>
    <br>
</center>