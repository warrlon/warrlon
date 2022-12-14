# Security Authentication
## Overview of Authentication Ways
OneNET supports both common and secure authentication methods. Compare the following tables:

<table>
<tr><th width="20%"> </th><th width="40%">普通</th><th>安全（推荐）</th></tr>
<tr><td>核心密钥</td><td>apiKey</td><td>accessKey</td></tr>
<tr><td>核心密钥更新</td><td>不支持</td><td>支持（即将到来）</td></tr>
<tr><td>鉴权参数</td><td>apiKey</td><td>由多个参数组构成的token</td></tr>
<tr><td>传输内容</td><td>apiKey（直接传输密钥）</td><td>token，不含密钥</td></tr>
<tr><td>访问时间控制</td><td>不支持</td><td>支持</td></tr>
<tr><td>自定义权限</td><td>不支持</td><td>支持（即将到来）</td></tr>
<tr><td>设备资源占用</td><td>较低</td><td>较高</td></tr>
<tr><td>安全性</td><td>较低</td><td>较高</td></tr>
</table>

This chapter focuses on ** security authentication ** methods

## Security Authentication

### Security assurance mechanism

Security authentication mechanism guarantees access security mainly through the following ways:
- Avoid the direct transmission in the core key network, so as to avoid the leakage of the core key in the transmission.
- Identity authentication is performed by token containing signatures generated by ** non-reversible algorithm **. Even if token is stolen, attackers cannot retrieve the core key by token.
- The authentication parameter token has the ** expiration time ** attribute of ** user-defined **, which can reduce the risk of being attacked/counterfeited from the time dimension.

### Common security solutions
1. Visitors (for ** applications ** or ** devices **) first obtain temporary access token through access managers. Access managers can customize the token's access validity (i.e. expiration time) according to their needs. Visitors can access OneNET only after obtaining the token.

    ![](/images/MQTTS/token安全方案1.png)

2. The access manager authorizes the key directly to the visitor (e.g., burning the key directly for the device), and the visitor generates token through the key for access.

    ![](/images/MQTTS/token安全方案2-1.png)

### Scope of application
The scope of security authentication is API authentication, message queue MQ connection authentication and MQTTS device access authentication.

### token composition and algorithm
Token consists of several parameters, as shown in the following table:

<table>
<tr><th width="10%">名称</th><th width="10%">类型</th><th width="10%">是否必须</th><th width="45%">参数说明</th><th>参数示例</th></tr>
<tr><td>version</td><td>string</td><td>是</td><td>参数组版本号，日期格式，目前仅支持"2018-10-31"</td><td>2018-10-31</td></tr>
<tr><td>res</td><td>string</td><td>是</td><td>访问资源 resource <br>格式为：父资源类/父资源ID/子资源类/子资源ID<br>见res使用场景说明</td><td>products/123123<br>products/123123/devices/78329710<br>mqs/osndf09nand9f21390</td></tr>
<tr><td>et</td><td>int</td><td>是</td><td>访问过期时间 expirationTime，unix时间<br>当一次访问参数中的et时间小于当前时间时，平台会认为访问参数过期从而拒绝该访问</td><td>1537255523<br>表示：北京时间 2018-09-18 15:25:23</td></tr>
<tr><td>method</td><td>string</td><td>是</td><td>签名方法 signatureMethod <br>支持md5、sha1、sha256</td><td>sha256</td></tr>
<tr><td>sign</td><td>string</td><td>是</td><td>签名结果字符串 signature</td><td> </td></tr>
</table>



Special description of token parameters:
#### Re Use Scenario Description

The usage scenarios are as follows:

<table>
<tr><th width="15%">场景</th><th width="35%">res参数格式</th><th>示例</th><th width="20%">说明</th></tr>
<tr><td>API访问</td><td>products/{pid}</td><td>products/123123</td><td> </td></tr>
<tr><td>消息队列MQ连接</td><td>mqs/{MQ_ID}</td><td>mqs/osndf09nand9f21390</td><td>消息队列MQ作为独立资源访问</td></tr>
<tr><td>MQTTS设备连接</td><td>products/{pid}/devices/{device_name}</td><td>products/123123/devices/mydev</td><td>需使用设备级密钥</td></tr>
</table>

#### sign signature algorithm

The generating algorithm of parameter sign is as follows:

    sign = base64(hmac_<method>(base64decode(accessKey), utf-8(StringForSignature))) 

Among them:

- AccessKey is the unique access key allocated by OneNET for independent resources (e.g. products). It participates in signature computation as one of the parameters of signature algorithm. To ensure access security, please keep it properly.
- Base64 decode operation should be performed before accessKey participates in the calculation.
- String ForSignature used to calculate signatures is sorted by ** parameter name ** and separated by'/ n'. The current version is sorted in the following order: et, method, res, version.

An example of the composition of String ForSignature is as follows:

    StringForSignature = et + '\n' + method + '\n' + res+ '\n' + version


Note: Each parameter is in key = value format, but only the value in the parameter participates in the calculation of the composition of the signature string String ForSignature, if the token parameter is as follows

    et = 1537255523
    method = sha1
    res = products/123123
    version = 2018-10-31

The string String ForSignature used to calculate signatures is (in the order of et, method, res, version)

    StringForSignature = "1537255523" + "\n" + "sha1"+ "\n" + "products/123123"+ "\n" + "2018-10-31"

After calculating sign, each parameter is expressed in the form of key = value, and'&'is used as a separator. The example is as follows:

    version=2018-10-31&res=products/123123&et=1537255523&method=sha1&sign=ZjA1NzZlMmMxYzIOTg3MjBzNjYTI2MjA4Yw=

#### Parametric coding

The value part in the form of key = value in token needs to be encoded by ** URL **, and the special symbols that need to be encoded are as follows:

| serial number | symbol | encoding|
|:-:|:-:|:-:|
|1|+|%2B |
| 2 | Space |% 20|
|3| / |%2F|
|4|?| %3F |
|5|%| %25 |
|6|#| %23 |
|7|&| %26 |
|8|=| %3D|

After encoding, the actual transmission token in the above example is:

    version=2018-10-31&res=products%2F123123&et=1537255523&method=sha1&sign=ZjA1NzZlMmMxYzIOTg3MjBzNjYTI2MjA4Yw%3D

#### token generates examples
Python code example













```python
import base64
import hmac
import time
from urllib.parse import quote

def token(id,access_key):

    version = '2018-10-31'

    res = 'mqs/%s' % id  # 通过MQ_ID访问MQ
    # res = 'products/%s' % id  # 通过产品ID访问产品API

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
    id = 'A1EB10110CFA9E06D6209E40C4A6D7976'
    access_key = 'KuF3NT/jUBJ62LNBB/A8XZA9CqS3Cu79B/ABmfA1UCw='

    print(token(id,access_key))
```


Java code example










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
        String resourceName = "mqs/A1EB10110CFA9E06D6209E40C4A6D7976";
        String expirationTime = System.currentTimeMillis() / 1000 + 100 * 24 * 60 * 60 + "";
        String signatureMethod = SignatureMethod.SHA1.name().toLowerCase();
        String accessKey = "KuF3NT/jUBJ62LNBB/A8XZA9CqS3Cu79B/ABmfA1UCw=";
        String token = assembleToken(version, resourceName, expirationTime, signatureMethod, accessKey);
        System.out.println("Authorization:" + token);
    }
}
```