# 鉴权认证

用户和OneNET平台交互时，在HTTP请求的鉴权头中，应该携带以下五个字段：

<table>
<tr><th width="10%">参数名称</th><th width="10%">类型</th><th width="10%">是否必填</th><th width="45%">说明</th><th>示例</th></tr>
<tr><td>version</td><td>string</td><td>是</td><td>参数组版本号，目前指定为v1</td><td>v1</td></tr>
<tr><td>res</td><td>string</td><td>是</td><td>访问资源 resource，格式为onenet_voice/{appid} appid由OneNET平台生成
</td><td>onenet_voice/fd977e9f94e44f239f18f6f919282569</td></tr>
<tr><td>et</td><td>string</td><td>是</td><td>访问过期时间 expirationTime，unix时间<br>当一次访问参数中的et时间小于当前时间时，平台会认为访问参数过期从而拒绝该访问</td><td>1537255523<br>表示：北京时间 2018-09-18 15:25:23</td></tr>
<tr><td>method</td><td>string</td><td>是</td><td>签名方法 signatureMethod <br>支持md5、sha1、sha256</td><td>sha256</td></tr>
<tr><td>sign</td><td>string</td><td>是</td><td>签名结果字符串 signature<br>详细规则见sign签名算法</td><td>uMJm8NxLshHNkW9qqQF1Gg%3D%3D </td></tr>
</table>

#### sign签名算法

参数sign的生成算法为：

    sign = base64(hmac_<method>(base64decode(accessKey), utf-8(StringForSignature))) 

其中：

- accessKey为OneNET为语音通话用户分配的唯一访问密钥，其作为签名算法参数之一参与签名计算，为保证访问安全，请妥善保管
- accessKey参与计算前应先进行base64decode操作
- 用于计算签名的字符串 StringForSignature的组成顺序按照**参数名称进行字符串排序**，以'/n'作为参数分隔，当前版本中按照如下顺序进行排序：et、method、res、version

StringForSignature组成示例如下：

    StringForSignature = et + '\n' + method + '\n' + res+ '\n' + version


注意：每个参数均为key=value格式组成，但是仅参数中的value参与计算签名的字符串 StringForSignature的组成，若token参数如下

    et = 1537255523
    method = sha1
    res = onenet_voice/123123
    version = v1

则用于计算签名的字符串StringForSignature为（按照et、method、res、version的顺序）
    
    StringForSignature = "1537255523" + "\n" + "sha1"+ "\n" + "onenet_voice/123123"+ "\n" + "v1"

计算出sign后，将每个参数均采用key=value的形式表示，并用'&'作为分隔符，示例如下：

    version=v1&res=onenet_voice/123123&et=1537255523&method=sha1&sign=ZjA1NzZlMmMxYzIOTg3MjBzNjYTI2MjA4Yw=

#### 参数编码

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

    version=v1&res=onenet_voice%2F123123&et=1537255523&method=sha1&sign=ZjA1NzZlMmMxYzIOTg3MjBzNjYTI2MjA4Yw%3D

#### token生成示例
python代码示例
```python
import base64
import hmac
import time
from urllib.parse import quote

def token(id,access_key):

    version = 'v1'

    res = onenet_voice/%s' % id

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


Java代码示例
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
        String sig = URLEncoder.encode(generatorSignature(version, resourceName, expirationTime, accessKey, signatureMethod), "UTF-8");
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
        String version = "v1";
        String resourceName = "onenet_voice/A1EB10110CFA9E06D6209E40C4A6D7976";
        String expirationTime = System.currentTimeMillis() / 1000 + 100 * 24 * 60 * 60 + "";
        String signatureMethod = SignatureMethod.SHA1.name().toLowerCase();
        String accessKey = "KuF3NT/jUBJ62LNBB/A8XZA9CqS3Cu79B/ABmfA1UCw=";
        String token = assembleToken(version, resourceName, expirationTime, signatureMethod, accessKey);
        System.out.println("Authorization:" + token);
    }
}
```

