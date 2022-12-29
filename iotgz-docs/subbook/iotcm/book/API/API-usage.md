[API鉴权](#2)
* [1 普通鉴权](#3)
* [2 安全鉴权](#4)

<h1 id="1">API使用</h1>

平台提供开放的API接口，用户可以通过HTTP/HTTPS调用，进行设备管理，数据查询，设备命令交互等操作，在API的基础上，根据自己的个性化需求搭建上层应用

<h2 id="2">API鉴权</h2>

为提高API访问安全性，OneNET API的鉴权参数作为**header**参数存在。

OneNET支持普通以及安全两种鉴权认证方式，对比如下表：

<table>
<tr><th width="20%"> </th><th width="40%">普通</th><th>安全（推荐）</th></tr>
<tr><td>核心密钥</td><td>apiKey</td><td>accessKey</td></tr>
<tr><td>header参数名</td><td>"api-key"</td><td>"Authorization"</td></tr>
<tr><td>header参数值</td><td>apiKey（直接传输密钥）</td><td>由参数组构成的token，不含密钥</td></tr>
<tr><td>访问时间控制</td><td>不支持</td><td>支持（由参数组中参数控制访问时效）</td></tr>
<tr><td>自定义权限</td><td>不支持</td><td>支持（即将到来）</td></tr>
<tr><td>核心密钥更新</td><td>不支持</td><td>支持（即将到来）</td></tr>
<tr><td>HTTPS</td><td>支持</td><td>支持</td></tr>
<tr><td>安全性</td><td>较低</td><td>较高</td></tr>
</table>

<h3 id="3"><table><tr><td bgcolor=#F2F2F2>1 普通鉴权</table></tr></td></h3>

普通鉴权方式通过apiKey作为鉴权密钥，apiKey分为两个访问层级：产品级（Master）与设备级
<table>
<tr><th width="15%"> </th><th width="40%">产品级</th><th>设备级</th></tr>
<tr><td>数量</td><td>产品下唯一</td><td>产品下可以有多个</td></tr>
<tr><td>权限范围</td><td>产品下所有资源的操作，包括：<br>设备、数据流、数据点、触发器、文件、命令以及设备apiKey</td><td>部分设备的全量操作，包括<br>设备详情，设备数据流，设备数据点</td></tr>
<tr><td>自定义权限</td><td>不支持</td><td>支持设备级<br>需要用户进行apiKey与设备的关联操作，一旦关联则具备该设备的最大权限</td></tr>
</table>

#### 调用示例
**（以“查询设备详情API”为例）**

```
GET /devices/3532392 
api-key: WhI3aidfa82SUBD34h123hv1c=

```

<h3 id="4"><table><tr><td bgcolor=#F2F2F2>2 安全鉴权</table></tr></td></h3> 

安全鉴权方式以accessKey为核心密钥，用户需要使用核心密钥通过签名算法计算签名，与其他参数共同组成token，然后将token作为请求Header参数进行鉴权

安全鉴权方式通过避免核心密钥在网络上直接传输，增加认证参数时效控制，增加密钥权限粒度控制（即将到来）等方式提高鉴权安全性，最大限度保证访问安全

下面主要介绍鉴权参数算法，计算Authorization，用于接口调用时的鉴权
Authorization由多个参数构成，如下表：


<table>
<tr><th width="10%">名称</th><th width="10%">类型</th><th width="10%">是否必须</th><th width="45%">参数说明</th><th>参数示例</th></tr>
<tr><td>version</td><td>string</td><td>是</td><td>参数组版本号，日期格式，目前仅支持"2018-10-31"</td><td>2018-10-31</td></tr>
<tr><td>res</td><td>string</td><td>是</td><td>访问资源 resource <br>格式为：父资源类/父资源ID/子资源类/子资源ID<br>见res使用场景说明</td><td>products/123123<br>products/123123/devices/78329710<br>mqs/osndf09nand9f21390</td></tr>
<tr><td>et</td><td>int</td><td>是</td><td>访问过期时间 expirationTime，unix时间<br>当一次访问参数中的et时间小于当前时间时，平台会认为访问参数过期从而拒绝该访问</td><td>1537255523<br>表示：北京时间 2018-09-18 15:25:23</td></tr>
<tr><td>method</td><td>string</td><td>是</td><td>签名方法 signatureMethod <br>支持md5、sha1、sha256</td><td>sha256</td></tr>
<tr><td>sign</td><td>string</td><td>是</td><td>签名结果字符串 signature</td><td> </td></tr>
</table>


#### 调用示例
**（以“查询设备详情API”为例）**

```
GET /devices/3532392 
Authorization: version=2018-10-31&res=products%2F123123&et=1537255523&method=sha1&sign=ZjA1NzZlMmMxYzIOTg3MjBzNjYTI2MjA4Yw%3D

```


关于token参数的特别说明：
### res使用场景说明

使用场景如下表：

<table>
<tr><th width="15%">场景</th><th width="35%">res参数格式</th><th>示例</th><th width="20%">说明</th></tr>
<tr><td>API访问</td><td>products/{pid}</td><td>products/123123</td><td> </td></tr>
<tr><td>设备连接</td><td>products/{pid}/devices/{device_name}</td><td>products/123123/devices/mydev</td><td>需使用设备级密钥</td></tr>
</table>

### sign签名算法

参数sign的生成算法为：

    sign = base64(hmac_<method>(base64decode(accessKey), utf-8(StringForSignature))) 

其中：

- accessKey为OneNET为独立资源（例如，产品）分配的唯一访问密钥，其作为签名算法参数之一参与签名计算，为保证访问安全，请妥善保管
- accessKey参与计算前应先进行base64decode操作
- 用于计算签名的字符串 StringForSignature的组成顺序按照**参数名称进行字符串排序**，以'/n'作为参数分隔，当前版本中按照如下顺序进行排序：et、method、res、version

StringForSignature组成示例如下：

    StringForSignature = et + '\n' + method + '\n' + res+ '\n' + version


注意：每个参数均为key=value格式组成，但是仅参数中的value参与计算签名的字符串 StringForSignature的组成，若token参数如下

    et = 1537255523
    method = sha1
    res = products/123123
    version = 2018-10-31

则用于计算签名的字符串StringForSignature为（按照et、method、res、version的顺序）
    
    StringForSignature = "1537255523" + "\n" + "sha1"+ "\n" + "products/123123"+ "\n" + "2018-10-31"

计算出sign后，将每个参数均采用key=value的形式表示，并用'&'作为分隔符，示例如下：

    version=2018-10-31&res=products/123123&et=1537255523&method=sha1&sign=ZjA1NzZlMmMxYzIOTg3MjBzNjYTI2MjA4Yw=

### 参数编码

token中key=value的形式的value部分需要经过**URL编码**，需要进行编码的特殊符号如下：

|序号|符号|编码|
|:-:|:-:|:-:|
|1|+|%2B |
|2|空格| %20 |
|3| / |%2F|
|4|?| %3F |
|5|%| %25 |
|6|#| %23 |
|7|&| %26 |
|8|=| %3D|

编码后，上例中实际传输token为：

    version=2018-10-31&res=products%2F123123&et=1537255523&method=sha1&sign=ZjA1NzZlMmMxYzIOTg3MjBzNjYTI2MjA4Yw%3D


# token生成示例 - python

基于 python 生成 token 代码示例如下：


```python
import base64
import hmac
import time
from urllib.parse import quote

def token(id,access_key):

    version = '2018-10-31'

    res = 'products/%s' % id  # 通过产品ID访问产品API

    # 用户自定义token过期时间
    et = str(int(time.time()) + 3600)

    # 签名方法，支持md5、sha1、sha256
    method = 'sha1'

    # 对access_key进行decode
    key = base64.b64decode(access_key)

    # 计算sign
    org = et + '\n' + method + '\n' + res + '\n' + version
    sign_b = hmac.new(key=key, msg=org.encode(), digestmod=method)
    sign = base64.b64encode(sign_b.digest()).decode()

    # value 部分进行url编码，method/res/version值较为简单无需编码
    sign = quote(sign, safe='')
    res = quote(res, safe='')

    # token参数拼接
    token = 'version=%s&res=%s&et=%s&method=%s&sign=%s' % (version, res, et, method, sign)

    return token


if __name__ == '__main__':
    id = '123123'
    access_key = 'KuF3NT/jUBJ62LNBB/A8XZA9CqS3Cu79B/ABmfA1UCw='
    
    print(token(id,access_key))
```


# token生成示例 - java

基于 java 生成 token 代码示例如下：

```java
import javax.crypto.Mac;
import javax.crypto.spec.SecretKeySpec;
import java.io.UnsupportedEncodingException;
import java.net.URLEncoder;
import java.security.InvalidKeyException;
import java.security.NoSuchAlgorithmException;
import java.util.Base64;


public class Token {

    public static String assembleToken(String version, String resourceName, String expirationTime, String signatureMethod, String accessKey)
            throws UnsupportedEncodingException, NoSuchAlgorithmException, InvalidKeyException {
        StringBuilder sb = new StringBuilder();
        String res = URLEncoder.encode(resourceName, "UTF-8");
        String sig = URLEncoder.encode(generatorSignature(version, resourceName, expirationTime
                , accessKey, signatureMethod), "UTF-8");
        sb.append("version=")
                .append(version)
                .append("&res=")
                .append(res)
                .append("&et=")
                .append(expirationTime)
                .append("&method=")
                .append(signatureMethod)
                .append("&sign=")
                .append(sig);
        return sb.toString();
    }

    public static String generatorSignature(String version, String resourceName, String expirationTime, String accessKey, String signatureMethod) 
		    throws NoSuchAlgorithmException, InvalidKeyException {
        String encryptText = expirationTime + "\n" + signatureMethod + "\n" + resourceName + "\n" + version;
        String signature;
        byte[] bytes = HmacEncrypt(encryptText, accessKey, signatureMethod);
        signature = Base64.getEncoder().encodeToString(bytes);
        return signature;
    }

    public static byte[] HmacEncrypt(String data, String key, String signatureMethod)
            throws NoSuchAlgorithmException, InvalidKeyException {
        //根据给定的字节数组构造一个密钥,第二参数指定一个密钥算法的名称
        SecretKeySpec signinKey = null;
        signinKey = new SecretKeySpec(Base64.getDecoder().decode(key),
                "Hmac" + signatureMethod.toUpperCase());

        //生成一个指定 Mac 算法 的 Mac 对象
        Mac mac = null;
        mac = Mac.getInstance("Hmac" + signatureMethod.toUpperCase());

        //用给定密钥初始化 Mac 对象
        mac.init(signinKey);

        //完成 Mac 操作
        return mac.doFinal(data.getBytes());
    }

    public enum SignatureMethod {
        SHA1, MD5, SHA256;
    }

    public static void main(String[] args) throws UnsupportedEncodingException, NoSuchAlgorithmException, InvalidKeyException {
        String version = "2018-10-31";
        String resourceName = "products/123123";
        String expirationTime = System.currentTimeMillis() / 1000 + 100 * 24 * 60 * 60 + "";
        String signatureMethod = SignatureMethod.SHA1.name().toLowerCase();
        String accessKey = "KuF3NT/jUBJ62LNBB/A8XZA9CqS3Cu79B/ABmfA1UCw=";
        String token = assembleToken(version, resourceName, expirationTime, signatureMethod, accessKey);
        System.out.println("Authorization:" + token);
    }
}
```
