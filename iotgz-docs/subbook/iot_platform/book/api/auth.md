# API鉴权

平台需要对API调用方进行资源权限校验，使用API时，需要在请求Header中携带统一的安全鉴权信息。

#### 安全鉴权机制

安全鉴权authorization由多个参数构成，每个参数均采用key = value的形式表示，并用&作为分隔符：

```
authorization: version=2020-05-29&res=userid%2F38055&et=1623982416&method=sha1&sign=S04GcvafYIjtAMHJthkGPevbNwE%3D
```

##### 参数说明

| 序&nbsp;号 | 参数 | 类型 | 说明  | 示例 |
|:- | :- | :- | :- | :- |
|1 | version | string | 签名算法版本 | 目前仅支持 2020-05-29 |
|2 | res | string | 访问资源信息 | 支持主用户和项目群组两种方式： <br/> 1）主用户访问res为：userid/{userid}, userid为平台用户id，参数在个人「账号信息」中查看 <br/> 2）项目群组访问res为：projectid/{projectid}/groupid/{groupid}，projectid为项目id，groupid为分组id，参数在「应用开发」-「项目管理」中查看 |
|3 | et | string | 访问过期时间 | 10位时间戳，1537255523 表示：北京时间 2018-09-18 15:25:23 |
|4 | method | string | 签名方法  | 目前支持md5、sha1、sha256 |
|5 | sign | string | 签名结果字符串&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;| version、res、et、method参数计算生成 |

其中sign的生成算法为:

```
sign = base64(hmac_<method>(base64decode(accessKey), utf-8(StringForSignature))) 
```

* accessKey为平台分配的访问密钥（用户访问权限页面查看），如果访问资源以主用户形式访问, 使用主用户的accessKey，如果访问资源以项目群组方式访问，使用群组的accessKey，且只能对群组内设备进行操作。
* accessKey参与计算前应先进行base64decode操作
* 用于计算签名的字符串 StringForSignature按照et、method、resource、version的顺序，以"\n"作为分隔符进行排列，如下所示：

```
StringForSignature = et + "\n" + method + "\n" + res + "\n" + version
```

##### 参数编码

authorization中key=value的形式的value部分需要经过URL编码，需要进行编码的特殊符号如下：

|序号 | 符号 | 编码 |
|:- | :- | :- |
|1 | + | %2B |
|2 | 空格 | %20 |
|3 | / | %2F |
|4 | ? | %3F |
|5 | % | %25 |
|6 | # | %23 |
|7 | & | %26 |
|8 | = | %3D |

##### authorization生成示例

###### nodejs代码示例

```
'use strict';

const crypto = require('crypto');

/**
 * authorization生成函数
 *
 * @param {String} method        - hash method
 * @param {String} res           - resource
 * @param {String} accessKey     - access key
 * @param {Number} et            - effective time
 * @return {String} - authorization
 */
function generateAuthorization(method, res, accessKey, et) {
  const version = '2020-05-29';
  const et = Math.ceil((Date.now() + et) / 1000); // token有效时间
  const base64Key = Buffer.from(accessKey, 'base64'); // accessKey base64编码
  const StringForSignature = et + '\n' + method + '\n' + res + '\n' + version;
  const sign = encodeURIComponent(crypto.createHmac(method, base64Key).update(StringForSignature).digest('base64'));
  const encodeRes = encodeURIComponent(res);

  return `version=${version}&res=${encodeRes}&et=${et}&method=${method}&sign=${sign}`;
}

const method = 'sha1';
const accessKey = 'mjgvkTCYTBF6DguxMmm+aV9EkDp2CYfL5jzRTph5Th6KhU8gqZz/cBivPTA7tfY5';
const res = 'userid/130037';
const et = 365 * 24 * 3600 * 1000; // 有效时间 - 365天
const authorization = generateAuthorization(method, res, accessKey, et);

```

###### python代码示例

```python
    import base64
    import hmac
    import time
    from urllib.parse import quote
    
    def token(user_id,access_key):
    
        version = '2020-05-29'
    
        res = 'userid/%s' % user_id
    
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
        user_id = '37715'
        access_key = 'mjgvkTCYTBF6DguxMmm+aV9EkDp2CYfL5jzRTph5Th6KhU8gqZz/cBivPTA7tfY5'
    
        print(token(user_id,access_key))
```

###### Java代码示例

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
            String version = "2020-05-29";
            String resourceName = "userid/12321";
            String expirationTime = System.currentTimeMillis() / 1000 + 100 * 24 * 60 * 60 + "";
            String signatureMethod = SignatureMethod.SHA1.name().toLowerCase();
            String accessKey = "KuF3NT/jUBJ62LNBB/A8XZA9CqS3Cu79B/ABmfA1UCw=";
            String token = assembleToken(version, resourceName, expirationTime, signatureMethod, accessKey);
            System.out.println("Authorization:" + token);
        }
    }
```

###### go代码示例

```go
func  (s *SignService) GenerateSign(params_map map[string]string, access_key string) (string, error){
	signature_str := params_map["et"] + "\n" + params_map["method"] + "\n" + params_map["res"] + "\n" + params_map["version"]
	hmac_str := ""
	switch strings.ToLower(params_map["method"]) {
		case "sha1":
	     	hmac_str = tools.HmacSha1(signature_str, tools.Base64Decode(access_key))
		case "sha256":
			hmac_str = tools.HmacSha256(signature_str, tools.Base64Decode(access_key))
		case "md5":
			hmac_str = tools.HmacMd5(signature_str, tools.Base64Decode(access_key))
		default:
			return "",errors.New("签名参数错误！")
	}

	sign :=tools.Base64Encode(hmac_str)
	return sign,nil
}

func Base64Encode(message string) string {
	return base64.StdEncoding.EncodeToString([]byte(message))
}

func Base64Decode(message string) string {
	decode_str, err := base64.StdEncoding.DecodeString(message)
	if err != nil {
		return ""
	}
	return string(decode_str)
}

func HmacSha256(data string, secret string) string {
	h := hmac.New(sha256.New, []byte(secret))
	h.Write([]byte(data))
	return string(h.Sum(nil))
	//return hex.EncodeToString(h.Sum(nil))
}

func HmacMd5(data string, secret string) string {
	h := hmac.New(md5.New, []byte(secret))
	h.Write([]byte(data))
	return string(h.Sum(nil))
	//return hex.EncodeToString(h.Sum(nil))
}

func HmacSha1(data string, secret string) string {
	h := hmac.New(sha1.New, []byte(secret))
	h.Write([]byte(data))
	return string(h.Sum(nil))
	//return hex.EncodeToString(h.Sum(nil)) //不需以十六进制字符串输出
}
```

###### php代码示例

```php
class SafetyAuth
{
    private  $_version = '2020-05-29';//版本
    private  $_method = 'sha1';//加密方法，还可以用md5、sha256
    private  $_access_key;//访问密钥
    private  $_res ;//资源参数
    private  $_et;//到期时间戳
    private  $_expiration;//有效期，有效时间

    public function __construct($access_key, $expiration,$res){
        $this->_expiration = $expiration;
        $this->_access_key = $access_key;
        $this->_res = $res;
    }
   //生成sign
    private function _makeSign() {

        date_default_timezone_set('PRC');
        $this->_et =time() + $this->_expiration;
        $string_for_signature = $this->_et . "\n" . $this->_method . "\n" . $this->_res  . "\n" . $this->_version;
        $b64_decode_acckey = base64_decode($this->_access_key);
        $hmac_key = hash_hmac($this->_method, $this->_strToUtf8($string_for_signature), $b64_decode_acckey, true);
        $sign = base64_encode($hmac_key);
        return $sign;

    }

    private  function _strToUtf8($str){
        $encode = mb_detect_encoding($str, array("ASCII",'UTF-8',"GB2312","GBK",'BIG5'));
        if($encode == 'UTF-8'){
            return $str;
        }else{
            return mb_convert_encoding($str, 'UTF-8', $encode);
        }
    }
//生成token
    public  function makeToken() {
        $sign = $this->_makeSign();
        $token = sprintf("version=2020-05-29&res=%s&et=%s&method=sha1&sign=%s", urlencode($this->_res), $this->_et, urlencode($sign));
        return $token;
    }

}
```