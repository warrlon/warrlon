# API列表

## 使用说明

API接口请求参数包括公共参数和自定义业务参数两部分。公共请求参数是调用每个API时都需要携带的请求参数, 包括服务命名空间、接口名称、版本信息。自定义业务参数由各接口定义，根据调用方法不同，需要将参数携带至请求路径或者请求体中。API接口公共参数调用如下所示：
https(http)://xxxx.com/{namespace}?action=xxxx&version=1
**参数说明**
<table>
<tr><th width="15%">序号</th><th>参数</th><th>类型</th><th>是否必选</th><th width="40%">描述</th></tr>
<tr><td>1</td><td>namespace</td><td>string</td><td>是</td><td>API接口类别, 目前支持两类:
application 应用开发类
common 设备管理类</td></tr>
<tr><td>2</td><td>action</td><td>string</td><td>是</td><td>API接口名称</td></tr>
<tr><td>3</td><td>version</td><td>string</td><td>是</td><td>API版本号, 目前所有API接口版本均为1</td></tr>
</table>

**公共响应说明**
**成功响应：**
>{
    "requestId": "8906582E6722409AA6C40E7863B733A5",
    "success": true,
    "data": {
        status: 1
    }
}

**失败响应：**
>{
    "requestId": "8906582E6722409AA6C40E7863B733A5",
    "code":  "iot.application.deviceNotFound",
    "msg": "device does not exist",
    "success": false
}

**参数说明**

<table>
<tr><th width="20%">序号</th><th>参数</th><th>类型</th><th width="40%">描述</th></tr>
<tr><td>1</td><td>requestId</td><td>string</td><td>请求ID，调用API时由平台生成唯一请求标识</td></tr>
<tr><td>2</td><td>code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td>3</td><td>msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td>4</td><td>success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td>5</td><td>data</td><td>object</td><td>调用成功时，返回的业务数据（接口无业务数据返回，值为null）</td></tr>
</table>

### 安全鉴权

平台需要对API调用方进行资源权限校验，使用API时，需要在请求Header中携带统一的安全鉴权信息。
**安全鉴权机制**
安全鉴权authorization由多个参数构成，每个参数均采用key = value的形式表示，并用&作为分隔符：
>authorization: version=2020-05-29&res=userid%2F38055&et=1623982416&method=sha1&sign=S04GcvafYIjtAMHJthkGPevbNwE%3D

**参数说明**
<table>
<tr><th width="15%">序号</th><th>参数</th><th>类型</th><th>说明</th><th width="40%">描述</th></tr>
<tr><td>1</td><td>version</td><td>string</td><td>签名算法版本</td><td>目前仅支持 2020-05-29</td></tr>
<tr><td>2</td><td>res</td><td>string</td><td>访问资源信息</td><td>支持主用户和项目群组两种方式：
1）主用户访问res为：userid/{userid}, userid为平台用户id，参数在个人「账号信息」中查看
2）项目群组访问res为：projectid/{projectid}/groupid/{groupid}，projectid为项目id，groupid为分组id，参数在「应用开发」-「项目管理」中查看</td></tr>
<tr><td>3</td><td>et</td><td>string</td><td>访问过期时间</td><td>10位时间戳，1537255523 表示：北京时间 2018-09-18 15:25:23</td></tr>
<tr><td>4</td><td>method</td><td>string</td><td>签名方法</td><td>目前支持md5、sha1、sha256</td></tr>
<tr><td>5</td><td>sign</td><td>string</td><td>签名结果字符串 </td><td>version、res、et、method参数计算生成</td></tr>
</table>

其中sign的生成算法为
>sign = base64(hmac_<method>(base64decode(accessKey), utf-8(StringForSignature)))

- accessKey为平台分配的访问密钥（用户访问权限页面查看），如果访问资源以主用户形式访问, 使用主用户的accessKey，如果访问资源以项目群组方式访问，使用群组的accessKey，且只能对群组内设备进行操作。
- accessKey参与计算前应先进行base64decode操作
- 用于计算签名的字符串 StringForSignature按照et、method、resource、version的顺序，以"\n"作为分隔符进行排列，如下所示：
StringForSignature = et + "\n" + method + "\n" + res + "\n" + version

**参数编码**
authorization中key=value的形式的value部分需要经过URL编码，需要进行编码的特殊符号如下：
<table>
<tr><th width="30%">序号</th><th>符号</th><th width="40%">编码</th></tr>
<tr><td>1</td><td>+</td><td>%2B</td></tr>
<tr><td>2</td><td>空格</td><td>%20</td></tr>
<tr><td>3</td><td>/</td><td>%2F</td></tr>
<tr><td>4</td><td>?</td><td>%3F</td></tr>
<tr><td>5</td><td>%</td><td>%25</td></tr>
<tr><td>6</td><td>#</td><td>%23</td></tr>
<tr><td>7</td><td>&</td><td>%26</td></tr>
<tr><td>8</td><td>=</td><td>%3D</td></tr>
</table>

**authorization生成示例**
nodejs代码示例
>'use strict';
const crypto = require('crypto');
/**
 *authorization生成函数
 >*
 *@param {String} method        - hash method
 *@param {String} res           - resource
 *@param {String} accessKey     - access key
 *@param {Number} et            - effective time
 *@return {String} - authorization
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

python代码示例
>import base64
    import hmac
    import time
    from urllib.parse import quote
>
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

Java代码示例
>import javax.crypto.Mac;
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

go代码示例
>func  (s *SignService) GenerateSign(params_map map[string]string, access_key string) (string, error){
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
>}

>func Base64Encode(message string) string {
    return base64.StdEncoding.EncodeToString([]byte(message))
}

>func Base64Decode(message string) string {
    decode_str, err := base64.StdEncoding.DecodeString(message)
    if err != nil {
        return ""
    }
    return string(decode_str)
}

>func HmacSha256(data string, secret string) string {
    h := hmac.New(sha256.New, []byte(secret))
    h.Write([]byte(data))
    return string(h.Sum(nil))
    //return hex.EncodeToString(h.Sum(nil))
}

>func HmacMd5(data string, secret string) string {
    h := hmac.New(md5.New, []byte(secret))
    h.Write([]byte(data))
    return string(h.Sum(nil))
    //return hex.EncodeToString(h.Sum(nil))
}

>func HmacSha1(data string, secret string) string {
    h := hmac.New(sha1.New, []byte(secret))
    h.Write([]byte(data))
    return string(h.Sum(nil))
    //return hex.EncodeToString(h.Sum(nil)) //不需以十六进制字符串输出
}

php代码示例
>class SafetyAuth
{
    private  $_version = '2020-05-29';//版本
    private  $_method = 'sha1';//加密方法，还可以用md5、sha256
    private  $_access_key;//访问密钥
    private  $_res ;//资源参数
    private  $_et;//到期时间戳
    private  $_expiration;//有效期，有效时间

    public function __construct($access_key, $expiration,$res){
        $this->_expiration = $expiration;
        $this->_access_key = $access_key;
        $this->_res = $res;
    }
   >//生成sign
    private function _makeSign() {

        date_default_timezone_set('PRC');
        $this->_et =time() + $this->_expiration;
        $string_for_signature = $this->_et . "\n" . $this->_method . "\n" . $this->_res  . "\n" . $this->_version;
        $b64_decode_acckey = base64_decode($this->_access_key);
        $hmac_key = hash_hmac($this->_method, $this->_strToUtf8($string_for_signature), $b64_decode_acckey, true);
        $sign = base64_encode($hmac_key);
        return $sign;

    }

    private  function _strToUtf8($str){
        $encode = mb_detect_encoding($str, array("ASCII",'UTF-8',"GB2312","GBK",'BIG5'));
        if($encode == 'UTF-8'){
            return $str;
        }else{
            return mb_convert_encoding($str, 'UTF-8', $encode);
        }
    }
>//生成token
    public  function makeToken() {
        $sign = $this->_makeSign();
        $token = sprintf("version=2020-05-29&res=%s&et=%s&method=sha1&sign=%s", urlencode($this->_res), $this->_et, urlencode($sign));
        return $token;
    }

>}

### 错误码

本文档列举API调用失败时，返回的错误码。出现缺少请求参数、不合法的请求参数等错误时，请参见具体API描述进行修改。

**资源权限相关错误码**
<table>
<tr><th width="30%">错误码</th><th width="%">描述</th></tr>
<tr><td>authPermissionDeny</td><td>鉴权失败</td></tr>
<tr><td>resourePermissionDeny</td><td>无资源访问权限</td></tr>
<tr><td>parameterRequired</td><td>缺少请求参数</td></tr>
<tr><td>parameterMissing</td><td>缺少请求参数</td></tr>
<tr><td>invalidParameter</td><td>不合法的请求参数</td></tr>
</table>

**项目相关错误码**
<table>
<tr><th width="30%">错误码</th><th width="%">描述</th></tr>
<tr><td>projectCatNotFound</td><td>项目行业标签不存在</td></tr>
<tr><td>projectNotFound</td><td>项目不存在</td></tr>
<tr><td>projectCreateFailed</td><td>项目创建失败</td></tr>
<tr><td>projectUpdateFailed</td><td>项目更新失败</td></tr>
<tr><td>projectGetFailed</td><td>项目详情获取失败</td></tr>
<tr><td>projectHasDevice</td><td>项目存在关联设备</td></tr>
<tr><td>projectStatisticsFailed</td><td>项目统计信息获取失败</td></tr>
</table>

**产品相关错误码**
<table>
<tr><th width="30%">错误码</th><th width="%">描述</th></tr>
<tr><td>productNotFound</td><td>产品不存在</td></tr>
<tr><td>productHasNoDevice</td><td>产品未创建设备</td></tr>
</table>

**设备相关错误码**
<table>
<tr><th width="30%">错误码</th><th width="%">描述</th></tr>
<tr><td>deviceNotFound</td><td>设备不存在</td></tr>
<tr><td>setPropertyFailed</td><td>设备属性设置失败</td></tr>
<tr><td>setDesiredPeropertyFailed</td><td>设备属性期望设置失败</td></tr>
<tr><td>queryDesiredProperyFailed</td><td>设备属性期望查询失败</td></tr>
<tr><td>getTmProperties</td><td>设备属性获取失败</td></tr>
<tr><td>callTmService</td><td>设备服务调用失败</td></tr>
<tr><td>deleteDesiredPeropertyFailed</td><td>设备属性期望删除失败</td></tr>
<tr><td>queryCurrentData</td><td>设备最新数据查询失败</td></tr>
<tr><td>queryPropertyHistoryData</td><td>设备属性历史数据查询失败</td></tr>
<tr><td>queryEventHistoryData</td><td>设备事件历史数据查询失败</td></tr>
<tr><td>queryOperationLog</td><td>设备操作记录查询失败</td></tr>
</table>

## 项目管理

### 项目概况

<table>
<tr><th>方法</th><td colspan="4">GET</th></tr>
<tr><td>路径URI</td><td colspan="4">/application?action=QueryStatistics&version=1&project_id=ocgzVU</td></tr>
</tr><td>请求头</td><td colspan="4">Content-Type : application/json</td></tr>
<tr><td>URL参数</td><td>project_id</td><td>string</td><td>必填</td><td>项目id </td></td>
</tr><td>请求体</td><td colspan="4">无</td></tr>
</tr><td rowspan="22">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>object</td><td>调用成功时，返回的请求数据</td></tr>
<tr><td colspan="2">data.project</td><td>object</td><td>项目基础信息</td></tr>
<tr><td colspan="2">data.project. project_id</td><td>string</td><td>项目ID</td></tr>
<tr><td colspan="2">data.project. create_time</td><td>string</td><td>项目创建时间</td></tr>
<tr><td colspan="2">data.project. tag</td><td>string</td><td>自定义标签名称集合</td></tr>
<tr><td colspan="2">data.project. name</td><td>string</td><td>项目名称</td></tr>
<tr><td colspan="2">data.project.</td><td>string</td><td>项目描述</td></tr>
<tr><td colspan="2">desc</td><td></td><td></td></tr>
<tr><td colspan="2">data.project. category_name</td><td>string</td><td>行业类别名称</td></tr>
<tr><td colspan="2">data.project. category</td><td>string</td><td>行业类别ID </td></tr>
<tr><td colspan="2">data.product_count</td><td>int</td><td>集成产品总数</td></tr>
<tr><td colspan="2">data.device_count</td><td>int</td><td>集成设备总数</td></tr>
<tr><td colspan="2">data.online_count</td><td>int</td><td>在线设备总数</td></tr>
<tr><td colspan="2">data.activate_count</td><td>int</td><td>激活设备总数</td></tr>
<tr><td colspan="2">data.active_count</td><td>int</td><td>活跃设备总数</td></tr>
<tr><td colspan="2">data.product_aggregate</td><td>array</td><td>设备分布集合，如下的p表示product_aggregate数组的单个对象标识</td></tr>
<tr><td colspan="2">p. name</td><td>string</td><td>产品名称</td></tr>
<tr><td colspan="2">p. count</td><td>int</td><td>项目下产品设备总数</td></tr>
<tr><th>请求示例</th><td colspan="4">GET /application?action=QueryStatistics&version=1&project_id=ocgzVU</th></tr>
<tr><th>响应示例</th><td colspan="4">

{
   "data": {
        "project": {
            "project_id": "ocgzVU",
            "name": "智慧城市",
            "desc": "",
            "category": "A003",
            "category_name": "智慧城市",
            "create_time": "2020-06-19T08:18:01.483Z", 
            "project_id": "ocgzVU",
            "tag": [
                "智慧城市"
            ]
        },
        "product_count": 1,
        "device_count": 2,
        "activate_count": 2,
        "active_count": 2,
        "online_count": 2,
        "product_aggregate": [
            "name": "智能烟感",
            "count": 2
         ]
    },
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}</th></tr>
</table>

### 项目集成产品列表

<table>
<tr><th>方法</th><td colspan="4">GET</th></tr>
<tr><td>路径URI</td><td colspan="4">/application?action=QueryProductList&version=1&project_id=ocgzVU</td></tr>
</tr><td>请求头</td><td colspan="4">Content-Type : application/json</td></tr>
<tr><td rowspan="3">URL参数</td><td>project_id</td><td>string</td><td>必填</td><td>项目id </td></td>
<tr><td>offset</td><td>string</td><td>可选</td><td>请求起始位置，默认0</td></tr>
<tr><td>limit</td><td>string</td><td>可选</td><td>每次请求记录数，默认10</td></tr>
</tr><td>请求体</td><td colspan="4">无</td></tr>
</tr><td rowspan="19">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>调用成功时, 返回业务数据</td></tr>
<tr><td colspan="2">data.list</td><td>array</td><td>产品信息集合，如下的l表示 list 数组的单个对象标识</td></tr>
<tr><td colspan="2">l. product_id</td><td>string</td><td>产品ID</td></tr>
<tr><td colspan="2">l. name</td><td>string</td><td>产品名称</td></tr>
<tr><td colspan="2">l. type</td><td>string</td><td>描述</td></tr>
<tr><td colspan="2">l. desc</td><td>string</td><td>项目名称</td></tr>
<tr><td colspan="2">l. protocol</td><td>int</td><td>协议 1-泛协议 2-MQTT 3-CoAP</td></tr>
<tr><td colspan="2">l. node_type</td><td>int</td><td>节点类型 1-直连设备</td></tr>
<tr><td colspan="2">l. data_type</td><td>int</td><td>数据类型 1-OneJson</td></tr>
<tr><td colspan="2">l. network</td><td>int</td><td>联网模式 1-其他 2-蜂窝 3-wifi 4-以太网</td></tr>
<tr><td colspan="2">l. device_number</td><td>string</td><td>设备总数</td></tr>
<tr><td colspan="2">data.meta</td><td>object</td><td>分页信息</td></tr>
<tr><td colspan="2">data.online_count</td><td>int</td><td>每次请求记录数</td></tr>
<tr><td colspan="2">data.meta.offset</td><td>int</td><td>请求记录起始位置</td></tr>
<tr><td colspan="2">data.meta.total</td><td>int</td><td>记录总数</td></tr>
<tr><th>请求示例</th><td colspan="4">GET /application?action=QueryProductList&version=1&project_id=ocgzVU</th></tr>
<tr><th>响应示例</th><td colspan="4">

{
    "data": {
        "list": [
            {
                "product_id": "9MaNe52pNO",
                "name": "空气净化器",
                "desc":  "智能家居空气净化器",
                "type": 1,
                "protocol":  2, 
                "node_type":  1,
                "data_type":  1,
                "network": 4, 
                "device_number": 2
            }
        ],
        "meta": {
            "limit": 10,
            "offset": 0,
            "total": 1
        }
    },
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true

}</th></tr>
</table>

### 项目集成设备列表

<table>
<tr><th>方法</th><td colspan="4">GET</th></tr>
<tr><td>路径URI</td><td colspan="4">/application?action=QueryDeviceList&version=1&project_id=ocgzVU</td></tr>
</tr><td>请求头</td><td colspan="4">Content-Type : application/json</td></tr>
<tr><td rowspan="7">URL参数</td><td>project_id</td><td>string</td><td>必填</td><td>项目id </td></td>
<tr><td>product_id</td><td>string</td><td>可选</td><td>产品ID</td></tr>
<tr><td>group_id</td><td>string</td><td>可选</td><td>分组ID</td></tr>
<tr><td>device_name</td><td>string</td><td>可选</td><td>设备名称</td></tr>
<tr><td>from</td><td>string</td><td>可选</td><td>设备来源 1-自主创建 2-他人转移</td></tr>
<tr><td>offset</td><td>string</td><td>可选</td><td>请求起始位置，默认0</td></tr>
<tr><td>limit</td><td>string</td><td>可选</td><td>每次请求记录数，默认10, 范围[1, 100]</td></tr>
</tr><td>请求体</td><td colspan="4">无</td></tr>
</tr><td rowspan="18">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>调用成功时, 返回业务数据</td></tr>
<tr><td colspan="2">data.list</td><td>array</td><td>产品信息集合，如下的l表示 list 数组的单个对象标识</td></tr>
<tr><td colspan="2">l. product_id</td><td>string</td><td>产品ID</td></tr>
<tr><td colspan="2">l.product_name</td><td>string</td><td>产品名称</td></tr>
<tr><td colspan="2">l.device_name</td><td>string</td><td>设备名称</td></tr>
<tr><td colspan="2">l.status</td><td>string</td><td>设备状态 1-未激活 2-在线 3-离线</td></tr>
<tr><td colspan="2">l.from</td><td>string</td><td>设备来源 1-自主创建 2-他人转移</td></tr>
<tr><td colspan="2">l. node_type</td><td>int</td><td>节点类型 1-直连设备</td></tr>
<tr><td colspan="2">l.created_time</td><td>string</td><td>创建时间</td></tr>
<tr><td colspan="2">l.last_time</td><td>string</td><td>最后一次在线时间</td></tr>
<tr><td colspan="2">data.meta</td><td>object</td><td>分页信息</td></tr>
<tr><td colspan="2">data.meta. limit</td><td>int</td><td>每次请求记录数</td></tr>
<tr><td colspan="2">data.meta.offset</td><td>int</td><td>请求记录起始位置</td></tr>
<tr><td colspan="2">data.meta.total</td><td>int</td><td>记录总数</td></tr>
<tr><th>请求示例</th><td colspan="4">GET  /application?action=QueryDeviceList&version=1&project_id=ocgzVU</th></tr>
<tr><th>响应示例</th><td colspan="4">

{
    "data": {
        "list": [
             {
                "product_id": "9MaNe52pNO",
                "product_name": "空气净化器",
                "node_type": 1,
                "status": 1,
                "device_name": "no001",
                "from": 1,
                "created_time": "2020-06-19T06:09:42.300Z",
                "last_time": "0001-01-01T00:00:00.000Z"
            },
            {
                "product_id": "9MaNe52pNO",
                "product_name": "空气净化器",
                "node_type": 1,
                "status": 3,
                "device_name": "no002",
                "from": 1,
                "created_time": "2020-06-19T06:09:22.550Z",
                "last_time": "2020-06-19T09:48:15.027Z"
            }
        ],
        "meta": {
            "limit": 10,
            "offset": 0,
            "total": 2
        }
    },
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
</th></tr>
</table>

### 项目移除设备

<table>
<tr><th>方法</th><td colspan="4">POST</th></tr>
<tr><td>路径URI</td><td colspan="4">/application?action=RemoveDevice&version=1</td></tr>
</tr><td>请求头</td><td colspan="4">Content-Type : application/json</td></tr>
</tr><td>URL参数</td><td colspan="4">无</td></tr>
<tr><td rowspan="3">请求体参数</td><td>project_id</td><td>string</td><td>必填</td><td>项目id </td></td>
<tr><td>product_id</td><td>string</td><td>必填</td><td>产品ID</td></tr>
<tr><td>devices</td><td>array</td><td>必填</td><td>移除设备名称集合</td></tr>
</tr><td rowspan="8">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>调用成功时, 返回业务数据</td></tr>
<tr><td colspan="2">data.error_data</td><td>array</td><td>移除失败的错误信息集合，如下的e表示 error_data数组的单个对象标识</td></tr>
<tr><td colspan="2">e. device_name</td><td>string</td><td>移除失败设备名称</td></tr>
<tr><td colspan="2">e. cause</td><td>string</td><td>移除失败原因</td></tr>
<tr><th>请求示例</th><td colspan="4">

{
    "project_id": "ocgzVU",
    "product_id": "9MaNe52pNO", 
    "devices": ["no010"]
}
</th></tr>
<tr><th>响应示例</th><td colspan="4">

{
    "data": {
       "error_data":[
           {"name": "no010", "cause": "设备不存在"}
        ],
    }
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
</th></tr>
</table>

### 项目设备添加


<table>
<tr><th>方法</th><td colspan="4">POST</th></tr>
<tr><td>路径URI</td><td colspan="4">/application?action=AddDevice&version=1</td></tr>
</tr><td>请求头</td><td colspan="4">Content-Type : application/json</td></tr>
</tr><td>URL参数</td><td colspan="4">无</td></tr>
<tr><td rowspan="3">请求体参数</td><td>project_id</td><td>string</td><td>必填</td><td>项目id，创建项目时由平台自动生成</td></td>
<tr><td>product_id</td><td>string</td><td>必填</td><td>产品id，创建产品时由平台自动生成</td></tr>
<tr><td>devices</td><td>array</td><td>必填</td><td>添加设备集合</td></tr>
</tr><td rowspan="8">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>调用成功时, 返回业务数据</td></tr>
<tr><td colspan="2">data.error_data</td><td>array</td><td>添加失败的错误信息集合，如下的e表示 error_data数组的单个对象标识</td></tr>
<tr><td colspan="2">e. device_name</td><td>string</td><td>添加失败设备名称</td></tr>
<tr><td colspan="2">e. cause</td><td>string</td><td>添加失败原因</td></tr>
<tr><th>请求示例</th><td colspan="4">

{
    "project_id": "ocgzVU",
    "product_id": "9MaNe52pNO", 
    "devices": ["no010"]
}
</th></tr>
<tr><th>响应示例</th><td colspan="4">

{
    "data": {
       "error_data":[
           {"name": "no010", "cause": "设备不存在"}
</th></tr>
</table>

## 分组管理

### 分组创建

<table>
<tr><th>方法</th><td colspan="4">POST</th></tr>
<tr><td>路径URI</td><td colspan="4">/application?action=CreateGroup&version=1</td></tr>
</tr><td>请求头</td><td colspan="4">Content-Type : application/json</td></tr>
</tr><td>URL参数</td><td colspan="4">无</td></tr>
<tr><td rowspan="3">请求体参数</td><td>project_id</td><td>string</td><td>必填</td><td>项目id </td></td>
<tr><td>name</td><td>string</td><td>必填</td><td>分组名称</td></tr>
<tr><td>desc</td><td>string</td><td>可选</td><td>分组描述</td></tr>
</tr><td rowspan="6">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>调用成功时, 返回业务数据</td></tr>
<tr><td colspan="2">data.group_id</td><td>string</td><td>分组ID</td></tr>
<tr><th>请求示例</th><td colspan="4">

{
    "project_id": "3C6Djy",
    "name": "黄河大道东",
    "desc": "group 1"
}
</th></tr>
<tr><th>响应示例</th><td colspan="4">

{
    "data": {
        "group_id": "uwYqby"
    },
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
</th></tr>
</table>

### 分组删除

<table>
<tr><th>方法</th><td colspan="4">POST</th></tr>
<tr><td>路径URI</td><td colspan="4">/application?action=DeleteGroup&version=1</td></tr>
</tr><td>请求头</td><td colspan="4">Content-Type : application/json</td></tr>
</tr><td>URL参数</td><td colspan="4">无</td></tr>
<tr><td rowspan="2">请求体参数</td><td>project_id</td><td>string</td><td>必填</td><td>项目id </td></td>
<tr><td>group_id</td><td>string</td><td>必填</td><td>分组ID</td></tr>
</tr><td rowspan="5">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>调用成功时, 返回的业务数据</td></tr>
<tr><th>请求示例</th><td colspan="4">

{
    "project_id": "Ua3Dbm",
    "group_id": "3UfAWD"
}
</th></tr>
<tr><th>响应示例</th><td colspan="4">

{
    "data": null,
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
</th></tr>
</table>

### 分组编辑

<table>
<tr><th>方法</th><td colspan="4">POST</th></tr>
<tr><td>路径URI</td><td colspan="4">/application?action=UpdateGroup&version=1</td></tr>
</tr><td>请求头</td><td colspan="4">Content-Type : application/json</td></tr>
</tr><td>URL参数</td><td colspan="4">无</td></tr>
<tr><td rowspan="4">请求体参数</td><td>project_id</td><td>string</td><td>必填</td><td>项目id </td></td>
<tr><td>group_id</td><td>string</td><td>必填</td><td>分组ID</td></tr>
<tr><td>tag</td><td>object</td><td>可选</td><td>标签信息</td></tr>
<tr><td>desc</td><td>string</td><td>可选</td><td>分组描述</td></tr>
</tr><td rowspan="6">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>调用成功时, 返回业务数据</td></tr>
<tr><td colspan="2">data.group_id</td><td>string</td><td>分组ID</td></tr>
<tr><th>请求示例</th><td colspan="4">

{
    "project_id": "Ua3Dbm",
    "group_id": "3UfAWD",
    "tag": {"key11":"dkmclg"},    #标签的键值对
    "desc": "描述"
}
</th></tr>
<tr><th>响应示例</th><td colspan="4">

{
    "data": {
        "group_id": "diVGB3"
    },
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
</th></tr>
</table>

### 分组列表

<table>
<tr><th>方法</th><td colspan="4">GET</th></tr>
<tr><td>路径URI</td><td colspan="4">/application?action=QueryGroupList&version=1&project_id=3C6Djy</td></tr>
</tr><td>请求头</td><td colspan="4">无</td></tr>
<tr><td rowspan="6">URL参数</td><td>project_id</td><td>string</td><td>必填</td><td>项目id </td></td>
<tr><td>name</td><td>string</td><td>可选</td><td>分组名称</td></tr>
<tr><td>key</td><td>string</td><td>可选</td><td>标签key（key、value需成对出现，否则没有效果）</td></tr>
<tr><td>value</td><td>string</td><td>可选</td><td>标签value（key、value 需成对出现，否则没有效果）</td></tr>
<tr><td>offset</td><td>string</td><td>可选</td><td>请求起始位置，默认0</td></tr>
<tr><td>limit</td><td>string</td><td>可选</td><td>每次请求记录数，默认10, </td></tr>
</tr><td>请求体</td><td colspan="4">无</td></tr>
</tr><td rowspan="17">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>调用成功时, 返回业务数据</td></tr>
<tr><td colspan="2">data.list</td><td>array</td><td>分组信息集合，如下的l表示 list 数组的单个对象标识</td></tr>
<tr><td colspan="2">l.project_id</td><td>string</td><td>项目id</td></tr>
<tr><td colspan="2">l.name</td><td>string</td><td>分组名称</td></tr>
<tr><td colspan="2">l.group_id</td><td>string</td><td>分组id</td></tr>
<tr><td colspan="2">l.key</td><td>string</td><td>分组key</td></tr>
<tr><td colspan="2">l.tag</td><td>object</td><td>标签信息,健值对</td></tr>
<tr><td colspan="2">l.created_time</td><td>string</td><td>创建时间</td></tr>
<tr><td colspan="2">l.device_count</td><td>int</td><td>设备数</td></tr>
<tr><td colspan="2">data.meta</td><td>object</td><td>分页信息</td></tr>
<tr><td colspan="2">data.meta. limit</td><td>int</td><td>每次请求记录数</td></tr>
<tr><td colspan="2">data.meta.offset</td><td>int</td><td>请求记录起始位置</td></tr>
<tr><td colspan="2">data.meta.total</td><td>int</td><td>记录总数</td></tr>
<tr><th>请求示例</th><td colspan="4">GET   /application?action=QueryGroupList&version=1&project_id=3C6Djy</th></tr>
<tr><th>响应示例</th><td colspan="4">

{
    "data": {
        "list": [
            {
                "project_id": "3C6Djy",
                "name": "xq_group1",
                "group_id": "qf6nAD",
                "key": "ZDM0MzA4MTA3MjQ4NzdlYzZjOGJlYzU1YmUwZTNhMmY=",
                "tag": {
                    "xq": "123"
                },
                "created_time":"2020-08-13T01:49:17694,
                "device_count": 2
            }
        ],
        "meta": {
            "limit": 10,
            "offset": 0,
            "total": 1
        }
    },
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
</th></tr>
</table>

### 分组详情

<table>
<tr><th>方法</th><td colspan="4">GET</th></tr>
<tr><td>路径URI</td><td colspan="4">/application?action=QueryGroupDetail&version=1</td></tr>
</tr><td>请求头</td><td colspan="4">无</td></tr>
<tr><td rowspan="2">URL参数</td><td>project_id</td><td>string</td><td>必填</td><td>项目id </td></td>
<tr><td>group_id</td><td>string</td><td>必填</td><td>分组ID</td></tr>
</tr><td>请求体</td><td colspan="4">无</td></tr>
</tr><td rowspan="15">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>调用成功时, 返回业务数据</td></tr>
<tr><td colspan="2">data.active_time</td><td>string</td><td>激活时间</td></tr>
<tr><td colspan="2">data.online_count</td><td>string</td><td>上线次数</td></tr>
<tr><td colspan="2">data.project_id</td><td>string</td><td>分组所属的项目ID</td></tr>
<tr><td colspan="2">data.name</td><td>string</td><td>分组名称</td></tr>
<tr><td colspan="2">data.group_id</td><td>string</td><td>分组ID</td></tr>
<tr><td colspan="2">data.key</td><td>string</td><td>分组key</td></tr>
<tr><td colspan="2">data.tag</td><td>object</td><td>分组标签</td></tr>
<tr><td colspan="2">data.desc</td><td>string</td><td>分组描述</td></tr>
<tr><td colspan="2">data.device_count</td><td>string</td><td>设备数量</td></tr>
<tr><td colspan="2">data.create_time</td><td>string</td><td>创建时间</td></tr>
<tr><th>请求示例</th><td colspan="4">GET  /application?action=QueryGroupDetail&version=1</th></tr>
<tr><th>响应示例</th><td colspan="4">

{
    "data": { 
        "activate_count": 0,
        "online_count": 0,
        "project_id": "3C6Djy",
        "name": "xq_group1",
        "group_id": "qf6nAD",
        "key": "ZDM0MzA4MTA3MjQ4NzdlYzZjOGJlYzU1YmUwZTNhMmY=",
        "tag": {
            "xq": "123"
        },
        "desc": "123",	
        "created_time": "2020-08-13T01:49:17.694Z",
        "device_count": 2
    } 
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
</th></tr>
</table>

### 分组设备添加

<table>
<tr><th>方法</th><td colspan="4">POST</th></tr>
<tr><td>路径URI</td><td colspan="4">/application?action=AddGroupDevice&version=1</td></tr>
</tr><td>请求头</td><td colspan="4">Content-Type : application/json</td></tr>
</tr><td>URL参数</td><td colspan="4">无</td></tr>
<tr><td rowspan="4">请求体参数</td><td>project_id</td><td>string</td><td>必填</td><td>项目id </td></td>
<tr><td>group_id</td><td>string</td><td>必填</td><td>分组ID</td></tr>
<tr><td>product_id</td><td>string</td><td>必填</td><td>产品ID</td></tr>
<tr><td>devices</td><td>array</td><td>必填</td><td>需要添加的设备集合</td></tr>
</tr><td rowspan="8">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>调用成功时, 返回的业务数据</td></tr>
<tr><td colspan="2">data.error_data</td><td>array</td><td>添加失败的错误信息集合，如下的e表示 error_data 数组的单个对象标识</td></tr>
<tr><td colspan="2">e. device_name</td><td>string</td><td>添加失败的设备集合</td></tr>
<tr><td colspan="2">e. cause</td><td>string</td><td>添加失败原因</td></tr>
<tr><th>请求示例</th><td colspan="4">

{
    "project_id": "3C6Djy",
    "group_id": "Z1Pdei",
    "product_id": "XVlg5CCSSj",
    "devices": ["dev1", "dev2"]
}
</th></tr>
<tr><th>响应示例</th><td colspan="4">

{
    "data": {
        "group_id": "qf6nAD",
        "devices": ["dev1", "dev2"]
    },
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
</th></tr>
</table>

### 分组设备移除

<table>
<tr><th>方法</th><td colspan="4">POST</th></tr>
<tr><td>路径URI</td><td colspan="4">/application?action=RemoveGroupDevice&version=1</td></tr>
</tr><td>请求头</td><td colspan="4">Content-Type : application/json</td></tr>
</tr><td>URL参数</td><td colspan="4">无</td></tr>
<tr><td rowspan="4">请求体参数</td><td>project_id</td><td>string</td><td>必填</td><td>项目id </td></td>
<tr><td>group_id</td><td>string</td><td>必填</td><td>分组ID</td></tr>
<tr><td>product_id</td><td>string</td><td>必填</td><td>产品ID</td></tr>
<tr><td>devices</td><td>array</td><td>必填</td><td>需要移除的设备集合</td></tr>
</tr><td rowspan="8">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>调用成功时, 返回的业务数据</td></tr>
<tr><td colspan="2">data.error_data</td><td>array</td><td>移除失败的错误信息集合，如下的e表示 error_data 数组的单个对象标识</td></tr>
<tr><td colspan="2">e. device_name</td><td>string</td><td>移除失败的设备集合</td></tr>
<tr><td colspan="2">e. cause</td><td>string</td><td>移除失败原因</td></tr>
<tr><th>请求示例</th><td colspan="4">

{
    "project_id": "3C6Djy",
    "group_id": "Z1Pdei",
    "product_id": "XVlg5CCSSj",
    "devices": ["dev1", "dev2"]
}
</th></tr>
<tr><th>响应示例</th><td colspan="4">

{
    "data": {
        "group_id": "qf6nAD",
        "devices": ["dev1", "dev2"]
    },
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
</th></tr>
</table>



## 物模型管理
### 物模型系统功能点列表

<table>
<tr><th>方法</th><td colspan="4">GET</th></tr>
<tr><td>路径URI</td><td colspan="4">/common?action=QuerySystemThingModel&version=1</td></tr>
</tr><td>请求头</td><td colspan="4"></td></tr>
<tr><td>URL参数</td><td colspan="4">无</td></tr>
</tr><td>请求体参数</td><td colspan="4">无</td></tr>
</tr><td rowspan="27">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>系统标准物模型</td></tr>
<tr><td colspan="2">data.properties</td><td>array</td><td>数组对象 属性功能点列表，如下的p表示properties数组的单个对象标识</td></tr>
<tr><td colspan="2">p.functionMode</td><td>string</td><td>功能点类型，定值'property'</td></tr>
<tr><td colspan="2">p.identifier</td><td>string</td><td>属性唯一标识符（产品下唯一）</td></tr>
<tr><td colspan="2">p.name</td><td>string</td><td>属性名称</td></tr>
<tr><td colspan="2">p.desc</td><td>string</td><td>属性描述</td></tr>
<tr><td colspan="2">p.fuctionType</td><td>string</td><td>是否是标准功能点，自定义（u）/系统（s）</td></tr>
<tr><td colspan="2">p.dataType</td><td>object</td><td>属性功能点数据</td></tr>
<tr><td colspan="2">p.dataType.type</td><td>string</td><td>属性功能点数据类型: int32（32位整数）、int64（64位整数）、float（单精度浮点）、double（双精度浮点型）、string（字符串）、date（String类型UTC秒）、bool（true或false）、enum（int类型）、bitMap（位图）、struct（结构体类型，可包含前面9种类型）</td></tr>
<tr><td colspan="2">p.dataType.specs</td><td>object</td><td>属性功能点数据，详见下面实例</td></tr>
<tr><td colspan="2">data.events</td><td>array</td><td>数组对象 事件功能点列表，如下的e表示events数组的单个对象标识</td></tr>
<tr><td colspan="2">e.functionMode</td><td>string</td><td>功能点类型，定值'event'</td></tr>
<tr><td colspan="2">e.identifier</td><td>string</td><td>事件唯一标识符</td></tr>
<tr><td colspan="2">e.name</td><td>string</td><td>事件名称</td></tr>
<tr><td colspan="2">e.desc</td><td>string</td><td>事件描述</td></tr>
<tr><td colspan="2">e.type</td><td>string</td><td>事件类型（info、alert、error）</td></tr>
<tr><td colspan="2">e.fuctionType</td><td>string</td><td>是否是标准功能点，自定义（u）/系统（s）</td></tr>
<tr><td colspan="2">e.outputData</td><td>array</td><td>参数数组</td></tr>
<tr><td colspan="2">e.outputData.identifier</td><td>string</td><td>参数唯一标识符</td></tr>
<tr><td colspan="2">e.outputData.name</td><td>string</td><td>参数名称</td></tr>
<tr><td colspan="2">e.outputData.dataType</td><td>object</td><td>参数数据</td></tr>
<tr><td colspan="2">e.outputData.dataType.type</td><td>string</td><td>参数数据类型: int32（32位整数）、int64（64位整数）、float（单精度浮点）、double（双精度浮点型）、string（字符串）、date（String类型UTC秒）、bool（true或false）、enum（int类型）、bitMap（位图）、struct（结构体类型，可包含前面9种类型）</td></tr>
<tr><td colspan="2">e.outputData.dataType.specs</td><td>object</td><td>功能点具体数据，详见下面实例</td></tr>
<tr><th>请求示例</th><td colspan="4">GET /common?action=QuerySystemThingModel&version=1</th></tr>
<tr><th>响应示例</th><td colspan="4">

{
     "data": { 
        "properties": [
            {
                "name": "基站定位",
                "identifier": "$OneNET_LBS",
                "functionType": "s",
                "functionMode": "property",
                "desc": null,
                "accessMode": "r",
                "dataType": {
                    "type": "array",
                    "specs": {
                        "size": "3",
                        "items": {
                            "type": "struct",
                            "specs": [
                                {
                                    "identifier": "mnc",
                                    "name": "移动网号",
                                    "dataType": {
                                        "type": "int32",
                                        "specs": {
                                            "min": "-2147483648",
                                            "max": "2147483647"
                                        }
                                    }
                                },
                                {
                                    "identifier": "mcc",
                                    "name": "移动国家号码",
                                    "dataType": {
                                        "type": "int32",
                                        "specs": {
                                            "min": "-2147483648",
                                            "max": "2147483647"
                                        }
                                    }
                                },
                                {
                                    "identifier": "lac",
                                    "name": "地区区域码",
                                    "dataType": {
                                        "type": "int32",
                                        "specs": {
                                            "min": "-2147483648",
                                            "max": "2147483647"
                                        }
                                    }
                                },
                                {
                                    "identifier": "cid",
                                    "name": "基站码",
                                    "dataType": {
                                        "type": "int32",
                                        "specs": {
                                            "min": "-2147483648",
                                            "max": "2147483647"
                                        }
                                    }
                                },
                                {
                                    "identifier": "networkType",
                                    "name": "网络制式",
                                    "dataType": {
                                        "type": "int32",
                                        "specs": {
                                            "min": "-2147483648",
                                            "max": "2147483647"
                                        }
                                    }
                                },
                                {
                                    "identifier": "ss",
                                    "name": "信号强度",
                                    "dataType": {
                                        "type": "int32",
                                        "specs": {
                                            "min": "-2147483648",
                                            "max": "2147483647"
                                        }
                                    }
                                },
                                {
                                    "identifier": "signalLength",
                                    "name": "当前基站广播信号强度",
                                    "dataType": {
                                        "type": "int32",
                                        "specs": {
                                            "min": "-2147483648",
                                            "max": "2147483647"
                                        }
                                    }
                                },
                                {
                                    "identifier": "ta",
                                    "name": "移动台距以确定其发往基站的定时超前量",
                                    "dataType": {
                                        "type": "int32",
                                        "specs": {
                                            "min": "-2147483648",
                                            "max": "2147483647"
                                        }
                                    }
                                },
                                {
                                    "identifier": "flag",
                                    "name": "基站信息数字进制",
                                    "dataType": {
                                        "type": "int32",
                                        "specs": {
                                            "min": "-2147483648",
                                            "max": "2147483647"
                                        }
                                    }
                                }
                            ]
                        }
                    }
                }
            },
            {
                "name": "WiFi定位",
                "identifier": "$OneNET_LBS_WIFI",
                "functionType": "s",
                "functionMode": "property",
                "desc": null,
                "accessMode": "r",
                "dataType": {
                    "type": "struct",
                    "specs": [
                        {
                            "identifier": "imsi",
                            "name": "移动用户识别码",
                            "dataType": {
                                "type": "string",
                                "specs": {
                                    "length": "255"
                                }
                            }
                        },
                        {
                            "identifier": "serverip",
                            "name": "设备接入基站时对应的网关ip",
                            "dataType": {
                                "type": "string",
                                "specs": {
                                    "length": "255"
                                }
                            }
                        },
                        {
                            "identifier": "macs",
                            "name": "可以接收到的热点mac信息",
                            "dataType": {
                                "type": "string",
                                "specs": {
                                    "length": "255"
                                }
                            }
                        },
                        {
                            "identifier": "mmac",
                            "name": "已连热点mac信息",
                            "dataType": {
                                "type": "string",
                                "specs": {
                                    "length": "255"
                                }
                            }
                        },
                        {
                            "identifier": "smac",
                            "name": "手机mac码",
                            "dataType": {
                                "type": "string",
                                "specs": {
                                    "length": "255"
                                }
                            }
                        },
                        {
                            "identifier": "idfa",
                            "name": "IOS手机的idfa",
                            "dataType": {
                                "type": "string",
                                "specs": {
                                    "length": "255"
                                }
                            }
                        }
                    ]
                }
            }
        ],
        "events": null
    } 
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
</th></tr>
</table>

### 物模型更新（增删改）

<table>
<tr><th>方法</th><td colspan="4">POST</th></tr>
<tr><td>路径URI</td><td colspan="4">/common?action=UpdateThingModel&version=1</td></tr>
</tr><td>请求头</td><td colspan="4">Content-Type : application/json	</td></tr>
<tr><td>URL参数</td><td colspan="4">无</td></tr>
<tr><td rowspan="44">请求体参数</td><td>product_id</td><td>string</td><td>必填</td><td>产品ID</td></tr>
<tr><td>properties</td><td>array</td><td>必填</td><td>数组对象 属性功能点</td></tr>
<tr><td>p.functionMode</td><td>string</td><td>必填</td><td>功能点类型，定值'property'</td></tr>
<tr><td>p.identifier</td><td>string</td><td>必填</td><td>属性唯一标识符（产品下唯一）</td></tr>
<tr><td>p.name</td><td>string</td><td>必填</td><td>属性名称</td></tr>
<tr><td>p.desc</td><td>string</td><td>可选</td><td>属性描述</td></tr>
<tr><td>p.accessMode</td><td>string</td><td>必填</td><td>"属性读写类型：只读（r）或读写（rw）</td></tr>
<tr><td>p.fuctionType</td><td>string</td><td>必填</td><td>是否是标准功能点，自定义（u）/ 系统（s）- 更新只支持自定义功能点</td></tr>
<tr><td>p.type</td><td>object</td><td>必填</td><td>属性功能点数据</td></tr>
<tr><td>p.dataType</td><td>object</td><td>必填</td><td>属性功能点数据</td></tr>
<tr><td>p.dataType.typee</td><td>string</td><td>必填</td><td>属性类型: int32（32位整数）、int64（64位整数）、float（单精度浮点）、double（双精度浮点型）、string（字符串）、bool（true或false）、enum（int类型）、bitMap（位图）、date（int64类型UTC时间戳毫秒）、struct（结构体类型）、array（数组）</td></tr>
<tr><td>p.dataType.specs</td><td>object</td><td>必填</td><td>属性功能点数据</td></tr>
<tr><td>events</td><td>array</td><td>必填</td><td>数组对象 事件功能点</td></tr>
<tr><td>e.functionMode</td><td>string</td><td>必填</td><td>功能点类型，定值'event'</td></tr>
<tr><td>e.identifier</td><td>string</td><td>必填</td><td>事件唯一标识符</td></tr>
<tr><td>e.name</td><td>string</td><td>必填</td><td>事件名称</td></tr>
<tr><td>e.desc</td><td>string</td><td>可选</td><td>事件描述</td></tr>
<tr><td>e.eventType</td><td>string</td><td>必填</td><td>事件类型（info、alert、error）</td></tr>
<tr><td>e.functionType</td><td>string</td><td>必填</td><td>是否是标准功能点，自定义（u）/标准（s）</td></tr>
<tr><td>e.outputData</td><td>array</td><td>必填</td><td>参数</td></tr>
<tr><td>e.outputData.identifier</td><td>string</td><td>必填</td><td>参数唯一标识符</td></tr>
<tr><td>e.outputData.name</td><td>string</td><td>必填</td><td>参数名称</td></tr>
<tr><td>e.outputData.dataType</td><td>object</td><td>必填</td><td>参数数据</td></tr>
<tr><td>e.outputData.dataType.type</td><td>string</td><td>必填</td><td>属性类型: int32（32位整数）、int64（64位整数）、float（单精度浮点）、double（双精度浮点型）、string（字符串）、bool（true或false）、enum（int类型）、bitMap（位图）、date（int64类型UTC时间戳毫秒）、struct（结构体类型）、array（数组）</td></tr>
<tr><td>e.outputData.dataType.specs</td><td>object</td><td>必填</td><td>功能点数据</td></tr>
<tr><td>services</td><td>array</td><td>必填</td><td>数组对象 服务功能点</td></tr>
<tr><td>s.functionMode</td><td>string</td><td>必填</td><td>功能点类型，定值'service'</td></tr>
<tr><td>s.identifier</td><td>string</td><td>必填</td><td>服务唯一标识符（产品下唯一）</td></tr>
<tr><td>s.name</td><td>string</td><td>必填</td><td>服务名称</td></tr>
<tr><td>s.desc</td><td>string</td><td>可选</td><td>服务描述</td></tr>
<tr><td>s.callType</td><td>string</td><td>必填</td><td>调用方式,同步(s)/异步(a)</td></tr>
<tr><td>s.fuctionType</td><td>string</td><td>必填</td><td>功能点类型，自定义（u）/系统（s）</td></tr>
<tr><td>s.input</td><td>array</td><td>可选</td><td>输入参数</td></tr>
<tr><td>s.input.identifier</td><td>string</td><td>必填</td><td>参数唯一标识符</td></tr>
<tr><td>s.input.name</td><td>string</td><td>必填</td><td>参数名称</td></tr>
<tr><td>s.input.dataType</td><td>object</td><td>可选</td><td>参数数据</td></tr>
<tr><td>s.input.dataType.type</td><td>string</td><td>必填</td><td>属性类型: int32（32位整数）、int64（64位整数）、float（单精度浮点）、double（双精度浮点型）、string（字符串）、bool（true或false）、enum（int类型）、bitMap（位图）、date（int64类型UTC时间戳毫秒）、struct（结构体类型）、array（数组）</td></tr>
<tr><td>s.input.dataType.specs</td><td>object</td><td>必填</td><td>参数功能点数据</td></tr>
<tr><td>s.output</td><td>array</td><td>必填</td><td>输出参数</td></tr>
<tr><td>s.output.identifier</td><td>string</td><td>必填</td><td>参数唯一标识符</td></tr>
<tr><td>s.output.name</td><td>string</td><td>必填</td><td>参数名称</td></tr>
<tr><td>s.output.dataType</td><td>object</td><td>可选</td><td>参数数据</td></tr>
<tr><td>s.output.dataType.type</td><td>string</td><td>必填</td><td>属性类型: int32（32位整数）、int64（64位整数）、float（单精度浮点）、double（双精度浮点型）、string（字符串）、bool（true或false）、enum（int类型）、bitMap（位图）、date（int64类型UTC时间戳毫秒）、struct（结构体类型）、array（数组）</td></tr>
<tr><td>s.output.dataType.specs</td><td>object</td><td>必填</td><td>参数功能点数据</td></tr>
</tr><td rowspan="5">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>调用成功时，返回的业务数据</td></tr>

<tr><th>请求示例</th><td colspan="4">

{
   "product_id":"10132", 
   "properties": [
    {
            "identifier": "RoomTemp", //必填 标识符
            "name": "房间温度", //必填 功能名称
            "accessMode": "r", //必填 读写属性（r可读，rw读写）
            "functionMode":"property", // 必填 功能类型（property属性，event事件）
            "functionType": "u", //必填 功能点（u代表自定义功能点/s代表系统功能点）
            "dataType": {
                "type": "float", //必填 数据类型
                "specs": {
                    "min": "-20.5", //必填 最小值
                    "max": "50.5", //必填 最大值
                    "unit": "摄氏度/°C", //选填 单位 支持自法定义（长度不超过15）
                    "step": "0.5" //选填 步长
                }
            },
            "desc": "xxxxx" //选填 描述 长度不超过255
        },
        {
            "identifier": "name",
            "name": "名字",
            "accessMode": "rw",
            "functionMode":"property",
            "functionType": "u",
            "dataType": {
                "type": "string",
                "specs": {
                    "length": "234" //必填 字符串长度（不超过255） 
                }
            }
        },
        {
            "identifier": "person",
            "name": "人类",
            "accessMode": "rw",
            "functionMode":"property",
            "functionType": "u",
            "dataType": {
                "type": "struct",
                "specs": [{
                        "identifier": "name",
                        "name": "名字",
                        "dataType": {
                            "type": "string",
                            "specs": {
                                "length": "200"
                            }
                        }
                    },
                    {
                        "identifier": "sex",
                        "name": "性别",
                        "dataType": {
                            "type": "bool",
                            "specs": {
                                "true": "男",
                                //必填 true代表的含义（长度不超过20）
                                "false": "女" //必填 false代表的含义（长度不超过20）
                            }
                        }
                    }
                ]
            }
        },
        {
            "identifier": "createTime",
            "name": "创建时间",
            "functionMode":"property",
            "accessMode": "rw",
            "desc": "设备创建时间",
            "functionType": "u",
            "dataType": {
                "type": "dat",
                "specs": {}
            }
        },
        {
            "identifier": "switch",
            "name": "开关",
            "functionMode":"property",
            "accessMode": "rw",
            "functionType": "u",
            "dataType": {
                "type": "bool",
                "specs": {
                    "true": "关",
                    "false": "开"
                }
            }
        },
        {
            "identifier": "deviceType",
            "name": "设备类型",
            "functionMode":"property",
            "accessMode": "rw",
            "functionType": "u",
            "dataType": {
                "type": "enum",
                "specs": {
                    "1": "真实设备",
                    //必填 参数描述（长度不超过20）
                    "2": "虚拟设备",
                    "3": "云设备"
                }
            }
        },
    {
      "name": "时间测试",
      "identifier": "time_test",
      "functionMode": "property",
      "accessMode": "rw",
      "dataType": {
        "type": "date",
        "specs": {}
      },
      "functionType": "u"
    },
    {
      "name": "数组测试",
      "identifier": "array",
      "functionMode": "property",
      "accessMode": "rw",
      "dataType": {
        "type": "array",
        "specs": {
          "length": "2",
          "type": "int32",
          "specs": {
            "min": "1",
            "max": "6",
            "step": "1",
            "unit": "微西每厘米 / uS/cm"
          }
        }
      },
      "functionType": "u"
    },
        {
            "identifier": "bitMapTest",
            "name": "位图测试",
            "accessMode": "rw",
            "functionMode":"property",
            "functionType": "u",
            "dataType": {
                "type": "bitMap",
                "specs": {
                    "length": 3,
                    //必填 （长度不能超过32）
                    "define": [{
                            "bit": 0,
                            //选填 定义每一位0,1的含义（长度不超过50） 
                            "0": "xxxx",
                            "1": "xxxx"
                        },
                        {
                            "bit": 1,
                            //选填 定义每一位0,1的含义（长度不超过50） 
                            "0": "xxxx",
                            "1": "xxxx"
                        }, ,
                        {
                            "bit": 2,
                            //选填
                            "0": "xxxx",
                            "1": "xxxx"
                        }
                    ]
                }
            }
        },
        {
            "identifier": "GeoLocation",
            "name": "地理位置",
            "accessMode": "r",
            "functionMode":"property",
            "functionType": "s",
            "dataType": {
                "type": "struct",
                "specs": [{
                        "identifier": "Longitude",
                        "name": "经度",
                        "dataType": {
                            "type": "double",
                            "specs": {
                                "min": "-180",
                                "max": "180",
                                "unit": "度/°",
                                "step": "0.01"
                            }
                        }
                    },
                    {
                        "identifier": "Latitude",
                        "name": "纬度",
                        "dataType": {
                            "type": "double",
                            "specs": {
                                "min": "-90",
                                "max": "90",
                                "unit": "度/°",
                                "step": "0.01"
                            }
                        }
                    },
                    {
                        "identifier": "Altitude",
                        "name": "海拔",
                        "dataType": {
                            "type": "double",
                            "specs": {
                                "min": "0",
                                "max": "9999",
                                "unit": "米/m",
                                "step": "0.01"
                            }
                        }
                    },
                    {
                        "identifier": "CoordinateSystem",
                        "name": "坐标系统",
                        "dataType": {
                            "type": "enum",
                            "specs": {
                                "1": "WGS_84",
                                "2": "GCJ_02"
                            }
                        }
                    }
                ]
            }
        },
        {
            "identifier": "$arrayTest",
            "name": "nihao",
            "accessMode": "rw",
            "functionMode":"property",
            "functionType": "s",
            "dataType": {
                "type": "array",
                "specs": {
                    "size": "10",
                    "item": {
                        "type": "struct",
                        "specs": [{
                                "identifier": "temp",
                                "name": "温度",
                                "dataType": {
                                    "type": "int32",
                                    "specs": {
                                        "min": "10",
                                        "max": "20",
                                        "step": "1"
                                    }
                                }
                            },
                            {
                                "identifier": "hum",
                                "name": "湿度",
                                "dataType": {
                                    "type": "float",
                                    "specs": {
                                        "min": "10.1",
                                        "max": "20.1",
                                        "step": "0.1"
                                    }
                                }
                            }
                        ]
                    }
                }
            }
        }
    ],
    "events": [{
            "identifier": "post",
            "name": "post",
            "eventType": "info",
            "functionMode":"event",
            "functionType": "s",
            "desc": "属性上报",
            "outputData": [{
                    "identifier": "RoomTemp",
                    "name": "房间温度",
                    "dataType": {
                        "type": "float",
                        "specs": {
                            "min": "-20.5",
                            "max": "50.5",
                            "unit": "摄氏度/°C",
                            "step": "0.5"
                        }
                    }
                },
                {
                    "identifier": "name",
                    "name": "名字",
                    "dataType": {
                        "type": "string",
                        "specs": {
                            "length": "240"
                        }
                    }
                },
                {
                    "identifier": "person",
                    "name": "人类",
                    "dataType": {
                        "type": "struct",
                        "specs": [{
                                "identifier": "name",
                                "name": "名字",
                                "dataType": {
                                    "type": "string",
                                    "specs": {
                                        "length": "240"
                                    }
                                }
                            },
                            {
                                "identifier": "sex",
                                "name": "性别",
                                "dataType": {
                                    "type": "bool",
                                    "specs": {
                                        "0": "男",
                                        "1": "女"
                                    }
                                }
                            }
                        ]
                    }
                },
                {
                    "identifier": "createTime",
                    "name": "创建时间",
                    "dataType": {
                        "type": "date",
                        "specs": {}
                    }
                },
                {
                    "identifier": "switch",
                    "name": "开关",
                    "dataType": {
                        "type": "bool",
                        "specs": {
                            "0": "关",
                            "1": "开"
                        }
                    }
                },
                {
                    "identifier": "deviceType",
                    "name": "设备类型",
                    "dataType": {
                        "type": "enum",
                        "specs": {
                            "1": "真实设备",
                            "2": "虚拟设备",
                            "3": "云设备"
                        }
                    }
                },
                {
                    "identifier": "GeoLocation",
                    "name": "地理位置",
                    "dataType": {
                        "type": "struct",
                        "specs": [{
                                "identifier": "Longitude",
                                "name": "经度",
                                "dataType": {
                                    "type": "double",
                                    "specs": {
                                        "min": "-180",
                                        "max": "180",
                                        "unit": "度/°"，
                                        "step": "0.01"
                                    }
                                }
                            },
                            {
                                "identifier": "Latitude",
                                "name": "纬度",
                                "dataType": {
                                    "type": "double",
                                    "specs": {
                                        "min": "-90",
                                        "max": "90",
                                        "unit": "度/°"，
                                        "step": "0.01"
                                    }
                                }
                            },
                            {
                                "identifier": "Altitude",
                                "name": "海拔",
                                "dataType": {
                                    "type": "double",
                                    "specs": {
                                        "min": "0",
                                        "max": "9999",
                                        "unit": "米/m"，
                                        "step": "0.01"
                                    }
                                }
                            },
                            {
                                "identifier": "CoordinateSystem",
                                "name": "坐标系统",
                                "dataType": {
                                    "type": "enum",
                                    "specs": {
                                        "1": "WGS_84",
                                        "2": "GCJ_02"
                                    }
                                }
                            }
                        ]
                    }
                }
            ]
        },
        {
            "identifier": "tempWarming",
            "name": "温度告警事件",
            "type": "info",
            "functionMode":"event",
            "functionType": "u",
            "outputData": [{
                    "identifier": "TaskId",
                    "name": "任务ID",
                    "dataType": {
                        "type": "string",
                        "specs": {
                            "length": "64"
                        }
                    }
                },
                {
                    "identifier": "Process",
                    "name": "部署进度",
                    "dataType": {
                        "type": "int64",
                        "specs": {
                            "min": "0",
                            "max": "100",
                            "unit": "无/",
                            "step": "1"
                        }
                    }
                },
                {
                    "identifier": "Code",
                    "name": "返回码",
                    "dataType": {
                        "type": "enum",
                        "specs": {
                            "0": "成功",
                            "1": "算法平台不支持",
                            "2": "下载模型失败",
                            "3": "MD5校验失败",
                            "4": "解压失败"
                        }
                    }
                },
                {
                    "identifier": "Message",
                    "name": "返回信息",
                    "dataType": {
                        "type": "string",
                        "specs": {
                            "length": "256"
                        }
                    }
                }
            ]
        }
    ],
    "services": [
        {
            "callType": "a", 
            "desc": null, 
            "functionMode": "service", 
            "functionType": "u", 
            "identifier": "test", 
            "input": [
                {
                    "dataType": {
                        "specs": {
                            "max": "1111", 
                            "min": "1", 
                            "step": "1"
                        }, 
                        "type": "int32"
                    }, 
                    "identifier": "name", 
                    "name": "name"
                }
            ], 
            "name": "test", 
            "output": [
                {
                    "dataType": {
                        "specs": {
                            "max": "111", 
                            "min": "1", 
                            "step": "1"
                        }, 
                        "type": "int32"
                    }, 
                    "identifier": "result", 
                    "name": "result"
                }
            ]
        }
    ]
}
</th></tr>
<tr><th>响应示例</th><td colspan="4">

{
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
</th></tr>
</table>

### 物模型查询

<table>
<tr><th>方法</th><td colspan="4">GET</th></tr>
<tr><td>路径URI</td><td colspan="4">/common?action=QueryThingModel&version=1&product_id=lsibd9</td></tr>
</tr><td>请求头</td><td colspan="4"></td></tr>
<tr><td rowspan="1">URL请求参数</td><td>product_id</td><td>string</td><td>必填</td><td>产品id </td></tr>
</tr><td>请求体参数</td><td colspan="4">无</td></tr>
</tr><td rowspan="47">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>调用成功时，返回的业务数据</td></tr>
<tr><td colspan="2">data.properties</td><td>array</td><td>数组对象 属性功能点</td></tr>
<tr><td colspan="2">p.functionMode</td><td>string</td><td>功能点类型，定值'property'</td></tr>
<tr><td colspan="2">p.identifier</td><td>string</td><td>属性唯一标识符（产品下唯一）</td></tr>
<tr><td colspan="2">p.name</td><td>string</td><td>属性名称</td></tr>
<tr><td colspan="2">p.desc</td><td>string</td><td>属性描述</td></tr>
<tr><td colspan="2">p.accessMode</td><td>string</td><td>"属性读写类型：只读（r）或读写（rw）</td></tr>
<tr><td colspan="2">p.fuctionType</td><td>string</td><td>是否是标准功能点，自定义（u）/系统（s）</td></tr>
<tr><td colspan="2">p.dataType</td><td>object</td><td>属性功能点数据</td></tr>
<tr><td colspan="2">p.dataType.type</td><td>string</td><td>属性类型: int32（32位整数）、int64（64位整数）、float（单精度浮点）、double（双精度浮点型）、string（字符串）、date（String类型UTC秒）、bool（true或false）、enum（int类型）、bitMap（位图）、date（int64类型UTC时间戳毫秒）、struct（结构体类型）、array（数组）</td></tr>
<tr><td colspan="2">p.dataType.specs</td><td>object</td><td>属性功能点数据</td></tr>
<tr><td colspan="2">data.events</td><td>array</td><td>数组对象 事件功能点列表</td></tr>
<tr><td colspan="2">e.functionMode</td><td>string</td><td>功能点类型，定值'event'</td></tr>
<tr><td colspan="2">e.identifier</td><td>string</td><td>事件唯一标识符</td></tr>
<tr><td colspan="2">e.name</td><td>string</td><td>事件名称</td></tr>
<tr><td colspan="2">e.desc</td><td>string</td><td>事件描述</td></tr>
<tr><td colspan="2">e.type</td><td>string</td><td>事件类型（info、alert、error）</td></tr>
<tr><td colspan="2">e.fuctionType</td><td>string</td><td>是否是标准功能点，自定义（u）/系统（s）</td></tr>
<tr><td colspan="2">e.outputData</td><td>array</td><td>参数</td></tr>
<tr><td colspan="2">e.outputData.identifier</td><td>string</td><td>参数唯一标识符</td></tr>
<tr><td colspan="2">e.outputData.name</td><td>string</td><td>参数名称</td></tr>
<tr><td colspan="2">e.outputData.dataType</td><td>object</td><td>参数数据</td></tr>
<tr><td colspan="2">e.outputData.dataType.type</td><td>string</td><td>属性类型: int32（32位整数）、int64（64位整数）、float（单精度浮点）、double（双精度浮点型）、string（字符串）、bool（true或false）、enum（int类型）、bitMap（位图）、date（int64类型UTC时间戳毫秒）、struct（结构体类型）、array（数组）</td></tr>
<tr><td colspan="2">e.outputData.dataType.specs</td><td>object</td><td>功能点数据</td></tr>
<tr><td colspan="2">services</td><td>array</td><td>数组对象 服务功能点</td></tr>
<tr><td colspan="2">s.functionMode</td><td>string</td><td>功能点类型，定值'service'</td></tr>
<tr><td colspan="2">s.identifier</td><td>string</td><td>服务唯一标识符（产品下唯一）</td></tr>
<tr><td colspan="2">s.name</td><td>string</td><td>服务名称</td></tr>
<tr><td colspan="2">s.desc</td><td>string</td><td>服务描述</td></tr>
<tr><td colspan="2">s.callType</td><td>string</td><td>调用方式,同步(s)/异步(a)</td></tr>
<tr><td colspan="2">s.fuctionType</td><td>string</td><td>功能点类型，自定义（u）/系统（s）</td></tr>
<tr><td colspan="2">s.input</td><td>array</td><td>输入参数</td></tr>
<tr><td colspan="2">s.input.identifier</td><td>string</td><td>参数唯一标识符</td></tr>
<tr><td colspan="2">s.input.name</td><td>string</td><td>参数名称</td></tr>
<tr><td colspan="2">s.input.dataType</td><td>object</td><td>参数数据</td></tr>
<tr><td colspan="2">s.input.dataType.type</td><td>string</td><td>属性类型: int32（32位整数）、int64（64位整数）、float（单精度浮点）、double（双精度浮点型）、string（字符串）、bool（true或false）、enum（int类型）、bitMap（位图）、date（int64类型UTC时间戳毫秒）、struct（结构体类型）、array（数组）</td></tr>
<tr><td colspan="2">s.input.dataType.specs</td><td>object</td><td>参数功能点数据</td></tr>
<tr><td colspan="2">s.output</td><td>string</td><td>输出参数</td></tr>
<tr><td colspan="2">s.output.identifier</td><td>string</td><td>参数唯一标识符</td></tr>
<tr><td colspan="2">s.output.name</td><td>string</td><td>参数名称</td></tr>
<tr><td colspan="2">s.output.dataType</td><td>object</td><td>参数数据</td></tr>
<tr><td colspan="2">s.output.dataType.type</td><td>string</td><td>属性类型: int32（32位整数）、int64（64位整数）、float（单精度浮点）、double（双精度浮点型）、string（字符串）、bool（true或false）、enum（int类型）、bitMap（位图）、date（int64类型UTC时间戳毫秒）、struct（结构体类型）、array（数组）</td></tr>
<tr><td colspan="2">s.output.dataType.specs</td><td>object</td><td>参数功能点数据</td></tr>

<tr><th>请求示例</th><td colspan="4">GET /common?action=QueryThingModel&version=1&product_id=lsibd9</th></tr>
<tr><th>响应示例</th><td colspan="4">

{
    "data": { 
        "properties": [
            {
                "name": "模式",
                "identifier": "model",
                "functionType": "u",
                "functionMode": "property",
                "desc": "",
                "accessMode": "rw",
                "dataType": {
                    "type": "enum",
                    "specs": {
                        "1": "模式1",
                        "2": "模式2"
                    }
                }
            }
        ],
        "events": [
            {
                "name": "test",
                "identifier": "test",
                "functionType": "u",
                "functionMode": "event",
                "desc": null,
                "eventType": "info",
                "outputData": [
                    {
                        "dataType": {
                            "type": "bool",
                            "specs": {
                                "false": "关",
                                "true": "开"
                            }
                        },
                        "name": "开关",
                        "identifier": "switch"
                    }
                ]
            }
        ]
    } 
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
</th></tr>
</table>


## 文件管理
### 设备文件上传

<table>
<tr><th>方法</th><td colspan="4">POST</th></tr>
<tr><td>路径URI</td><td colspan="4">/application?action=CreateDeviceFile&version=1</td></tr>
</tr><td>请求头</td><td colspan="4">Content-Type : application/json	</td></tr>
<tr><td>URL参数</td><td colspan="4">无</td></tr>
<tr><td rowspan="3">请求体参数</td><td>device_name</td><td>string</td><td>必填</td><td>设备名称 ,参数需构造在同一个 form-data 中</td></tr>
<tr><td>product_id</td><td>string</td><td>必填</td><td>产品ID ,参数需构造在同一个 form-data 中</td></tr>
<tr><td>file</td><td>file</td><td>必填</td><td>上传的图片文件(目前支持JPG、PNG、BMP、GIF)</td></tr>
</tr><td rowspan="6">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>调用成功时，返回的业务数据</td></tr>
<tr><td colspan="2">data.fid</td><td>string</td><td>文件上传成功后返回的文件ID</td></tr>
<tr><th>请求示例</th><td colspan="4">

{
  "device_name": "device_name",
  "product_id": "qwdfbht",
  "md5": "f55c2e86ab864b64a6d939fbe3a7d65f",
  "size": 12546,
  "filename": "filename",
  "file": file
}
</th></tr>
<tr><th>响应示例</th><td colspan="4">

{
    "data": { 
        "fid": "434fa51a170942c8a291be1e4b229582"
    } 
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
</th></tr>
</table>

### 查看下载设备文件接口

<table>
<tr><th>方法</th><td colspan="4">GET</th></tr>
<tr><td>路径URI</td><td colspan="4">/application?action=GetDeviceFile&version=1&id=43bb54ac673f48c88300fa6e6d3c9481</td></tr>
</tr><td>请求头</td><td colspan="4"></td></tr>
<tr><td rowspan="1">URL参数</td><td>id</td><td>string</td><td>必填</td><td>文件id </td></tr>
</tr><td>请求体</td><td colspan="4">无</td></tr>
</tr><td rowspan="1">响应参数</td><td colspan="2">file</td><td>file</td><td>需要下载的文件</td></tr>
<tr><th>请求示例</th><td colspan="4">GET /application?action=GetDeviceFile&version=1&id=43bb54ac673f48c88300fa6e6d3c9481
</th></tr>
<tr><th>响应示例</th><td colspan="4">file
</th></tr>
</table>

### 文件删除接口

<table>
<tr><th>方法</th><td colspan="4">POST</th></tr>
<tr><td>路径URI</td><td colspan="4">/application?action=DeleteDeviceFile&version=1</td></tr>
</tr><td>请求头</td><td colspan="4"></td></tr>
</tr><td>URL参数</td><td colspan="4">无</td></tr>
<tr><td rowspan="1">请求体参数</td><td>id</td><td>string</td><td>必填</td><td>文件id </td></tr>
</tr><td rowspan="5">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>调用成功时，返回的业务数据</td></tr>
<tr><th>请求示例</th><td colspan="4">

{
  id：43bb54ac673f48c88300fa6e6d3c9481
}
</th></tr>
<tr><th>响应示例</th><td colspan="4">

{
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
</th></tr>
</table>

## 用户管理

### 用户下产品数量统计

<table>
<tr><th>方法</th><td colspan="4">GET</th></tr>
<tr><td>路径URI</td><td colspan="4">/common?action=ProductStatistics&version=1</td></tr>
</tr><td>请求头</td><td colspan="4"></td></tr>
</tr><td>URL请求参数</td><td colspan="4">无</td></tr>
</tr><td>请求体参数</td><td colspan="4">无</td></tr>
</tr><td rowspan="21">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>调用成功时，返回的业务数据</td></tr>
<tr><td colspan="2">data.product_aggregate.product_count</td><td>number</td><td>产品数量</td></tr>
<tr><td colspan="2">data.product_aggregate.ind_agg</td><td>array</td><td>数组对象，行业类型统计，如下的ind表示ind_agg数组的单个对象标识</td></tr>
<tr><td colspan="2">ind._id</td><td>string</td><td>行业ID（自动生成）</td></tr>
<tr><td colspan="2">ind.count/td><td>string</td><td>行业类别下产品数量</td></tr>
<tr><td colspan="2">ind.name</td><td>string</td><td>行业名称</td></tr>
<tr><td colspan="2">data.product_aggregate.pt_agg</td><td>array</td><td>数组对象，协议类型统计，如下的pt表示pt_agg数组的单个对象标识</td></tr>
<tr><td colspan="2">pt._id</td><td>string</td><td>协议ID（自动生成）</td></tr>
<tr><td colspan="2">pt.count</td><td>string</td><td>同一协议下产品数量</td></tr>
<tr><td colspan="2">pt.name</td><td>string</td><td>协议名称</td></tr>
<tr><td colspan="2">data.product_aggregate.net_agg</td><td>array</td><td>数组对象，联网类型统计，如下的net表示net_agg数组的单个对象标识</td></tr>
<tr><td colspan="2">net._id</td><td>string</td><td>联网类型ID（自动生成）</td></tr>
<tr><td colspan="2">net.name</td><td>string</td><td>联网类型名称</td></tr>
<tr><td colspan="2">data.product_aggregate.model_agg</td><td>array</td><td>数组对象，物模型类型统计，如下的model表示model_agg数组的单个对象标识</td></tr>
<tr><td colspan="2">model._id</td><td>string</td><td>物模型类型ID（自动生成)</td></tr>
<tr><td colspan="2">model.count</td><td>string</td><td>物模型类型下产品数量</td></tr>
<tr><td colspan="2">model.name</td><td>string</td><td>物模型类型名称</td></tr>
<tr><th>请求示例</th><td colspan="4">GET /common?action=ProductStatistics&version=1</th></tr>
</th></tr>
<tr><th>响应示例</th><td colspan="4">

{
    "data": { 
          "product_aggregate":{
            "ind_agg":[ // 行业类别
                {
                    "_id":"1",
                    "count":7,
                    "name":"智慧城市"
                }
            ],
            "pt_agg":[ // 协议类型
                {
                    "_id":'sub',
                    "count":1,
                    "name":‘网关子设备’
                },
                {
                    "_id":4,
                    "count":2,
                    "name":'LwM2M'
                },
                {
                    "_id":2,
                    "count":4,
                    "name":"MQTT"
                }
            ],
            "net_agg":[ // 联网型类型
                {
                    "_id":"1",
                    "count":0,
                    "name":"其他"
                },
                {
                    "_id":"2",
                    "count":0,
                    "name":"蜂窝"
                },
                {
                    "_id":"3",
                    "count":5,
                    "name":"wifi"
                },
                {
                    "_id":"4",
                    "count":0,
                    "name":"以太网"
                },
                {
                    "_id":"5",
                    "count":1,
                    "name":"NB"
                }
            ],
            "model_agg":[ // 物模型类型
                {
                    "_id":"1",
                    "count":2,
                    "name":"标准"
                },
                {
                    "_id":"2",
                    "count":5,
                    "name":"自定义"
                }
            ]
        },
        "product_count":7 // 总数
}
} 
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
</th></tr>
</table>

### 用户下设备数量统计

<table>
<tr><th>方法</th><td colspan="4">GET</th></tr>
<tr><td>路径URI</td><td colspan="4">/common?action=UserDeviceStatistics&version=1</td></tr>
</tr><td>请求头</td><td colspan="4"></td></tr>
</tr><td>URL请求参数</td><td colspan="4">无</td></tr>
</tr><td>请求体参数</td><td colspan="4">无</td></tr>
</tr><td rowspan="12">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>调用成功时，返回的业务数据</td></tr>
<tr><td colspan="2">data.count</td><td>number</td><td>总设备数量</td></tr>
<tr><td colspan="2">data.statistcs</td><td>array</td><td>数组对象，设备分类统计，如下的s表示statistcs数组的单个对象标识</td></tr>
<tr><td colspan="2">s.uid</td><td>string</td><td>设备所属用户ID</td></tr>
<tr><td colspan="2">s.dev_new<td>number</td><td>每日新增设备数量</td></tr>
<tr><td colspan="2">s.dev_lively</td><td>number</td><td>日活设备数量</td></tr>
<tr><td colspan="2">s.insert_time</td><td>array</td><td>设备统计的具体日期</td></tr>
<tr><td colspan="2">s.dev_actived</td><td>number</td><td>日激活设备数</td></tr>
<tr><th>请求示例</th><td colspan="4">GET /common?action=UserDeviceStatistics&version=1</th></tr>
</th></tr>
<tr><th>响应示例</th><td colspan="4">

{
    "data": { 
         "count":27, // 总设备数
         "statistcs":[
            {
                "uid":5,
                "dev_new":0, // 每日新增设备数
                "dev_lively":1, // 日活备数
                "insert_time":"20211213", //  日期
                "dev_actived":13 // 日激活设备数
            },
            {
                "uid":5,
                "dev_new":0,
                "dev_lively":1,
                "insert_time":"20211214",
                "dev_actived":13
            }
        ]} 
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
</th></tr>
</table>

### 账户下文件列表查询

<table>
<tr><th>方法</th><td colspan="4">GET</th></tr>
<tr><td>路径URI</td><td colspan="4">/application?action=GetDeviceFilesList&version=1</td></tr>
</tr><td>请求头</td><td colspan="4"></td></tr>
</tr><td>URL请求参数</td><td colspan="4">无</td></tr>
</tr><td>请求体参数</td><td colspan="4">无</td></tr>
</tr><td rowspan="15">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>调用成功时，返回的业务数据</td></tr>
<tr><td colspan="2">data.meta.total</td><td>number</td><td>文件数量</td></tr>
<tr><td colspan="2">data.meta.limit</td><td>number</td><td>每次请求的数据长度</td></tr>
<tr><td colspan="2">data.meta.offset</td><td>number</td><td>偏移量</td></tr>
<tr><td colspan="2">data.list.id<td>string</td><td>文件上传记录ID</td></tr>
<tr><td colspan="2">data.list.fid</td><td>string</td><td>文件ID</td></tr>
<tr><td colspan="2">data.list.name</td><td>string</td><td>文件名称</td></tr>
<tr><td colspan="2">data.list.file_size</td><td>number</td><td>文件大小</td></tr>
<tr><td colspan="2">data.list.created_time</td><td>string</td><td>文件创建时间</td></tr>
<tr><td colspan="2">data.list.device_name</td><td>string</td><td>文件所属设备名称</td></tr>
<tr><td colspan="2">data.list.product_id</td><td>string</td><td>文件所属设备的产品ID</td></tr>
<tr><th>请求示例</th><td colspan="4">GET /application?action=GetDeviceFilesList&version=1</th></tr>
</th></tr>
<tr><th>响应示例</th><td colspan="4">

{
    "data": { 
        "meta": {
            "limit": 10,
            "offset": 0,
            "total": 1
        },
        "list": [
            {
                "id": "574f7eab98eb7b5222911a",
                "fid": "98cfa6be79574f7eab98eb7b5222911a",
                "name": "28fpf.png",
                "file_size": 138683,
                "created_time": "2020-12-16T09:30:18.419Z",
                "device_name": "ap-test-008",
                "product_id": "Bs1f6s5bhKP7rmfO"
            }
        ]
    } 
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
</th></tr>
</table>

### 用户文件存储空间查询

<table>
<tr><th>方法</th><td colspan="4">GET</th></tr>
<tr><td>路径URI</td><td colspan="4">/application?action=GetDeviceFileSpace&version=1</td></tr>
</tr><td>请求头</td><td colspan="4"></td></tr>
</tr><td>URL请求参数</td><td colspan="4">无</td></tr>
</tr><td>请求体参数</td><td colspan="4">无</td></tr>
</tr><td rowspan="8">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>调用成功时，返回的业务数据</td></tr>
<tr><td colspan="2">data.useSize</td><td>number</td><td>用户已使用的空间</td></tr>
<tr><td colspan="2">data.hasSize</td><td>number</td><td>用户剩余空间</td></tr>
<tr><td colspan="2">data.totalSize</td><td>number</td><td>用户分配的总空间</td></tr>
<tr><th>请求示例</th><td colspan="4">GET /application?action=GetDeviceFileSpace&version=1</th></tr>
</th></tr>
<tr><th>响应示例</th><td colspan="4">

{
    "data": { 
        "useSize": 138683,
        "hasSize": 1073603141,
        "totalSize": 1073741824
    } 
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
</th></tr>
</table>

### 用户设备文件数量查询

<table>
<tr><th>方法</th><td colspan="4">GET</th></tr>
<tr><td>路径URI</td><td colspan="4">/application?action=GetDeviceFileCount&version=1&device_name=ap-test-008&product_id=Bs1f6s5bhKP7rmfO</td></tr>
</tr><td>请求头</td><td colspan="4"></td></tr>
<tr><td rowspan="2">URL请求参数</td><td>product_id</td><td>string</td><td>必填</td><td>产品id </td></td>
<tr><td>device_name</td><td>string</td><td>必填</td><td>设备名称</td></tr>
</tr><td>请求体参数</td><td colspan="4">无</td></tr>
</tr><td rowspan="7">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>调用成功时，返回的业务数据</td></tr>
<tr><td colspan="2">data.upperLimit</td><td>number</td><td>设备允许的最大文件数量</td></tr>
<tr><td colspan="2">data.filesTotal</td><td>number</td><td>设备已存在的文件数量</td></tr>
<tr><th>请求示例</th><td colspan="4">GET /application?action=GetDeviceFileCount&version=1&device_name=ap-test-008&product_id=Bs1f6s5bhKP7rmfO </th></tr>
</th></tr>
<tr><th>响应示例</th><td colspan="4">

{
    "data": { 
        "upperLimit": 1000,
        "filesTotal": 1
    } 
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
</th></tr>
</table>

## 场景联动管理

### 场景联动规则创建


<table>
<tr><th>方法</th><td colspan="4">POST</th></tr>
<tr><td>路径URI</td><td colspan="4">/application?action=CreateSceneRule&version=1</td></tr>
</tr><td>请求头</td><td colspan="4">Content-Type : application/json</td></tr>
</tr><td>URL参数</td><td colspan="4">无</td></tr>
<tr><td rowspan="17">请求体参数</td><td>project_id</td><td>string</td><td>必填</td><td>项目ID</td></td>
<tr><td>name</td><td>string</td><td>必填</td><td>场景联动名称</td></tr>
<tr><td>conditions</td><td>array</td><td>必填</td><td>触发条件集合，如下的c表示conditions数组的单个对象标识</td></tr>
<tr><td>c. ctype</td><td>string</td><td>必填</td><td>触发方式 支持lifeCycle-设备生命周期、 notify-设备数据上报</td></tr>
<tr><td>c. device_name</td><td>string</td><td>必填</td><td>设备名称</td></tr>
<tr><td>c. product_id</td><td>string</td><td>必填</td><td>产品ID</td></tr>
<tr><td>c. identifier</td><td>string</td><td>必填</td><td>属性功能点标识</td></tr>
<tr><td>c. type</td><td>string</td><td>必填</td><td>功能点数据类型 支持int32、int64、float、double、string、bool</td></tr>
<tr><td>c. value</td><td>string</td><td>必填</td><td>功能点预设值 触发方式为lifecycle时，value值为online或者offline</td></tr>
<tr><td>c. operator</td><td>string</td><td>必填</td><td>比较运算符 支持eq-等于、lt-小于、gt-大于、lte-小于等于、gte-大于等于</td></tr>
<tr><td>actions</td><td>array</td><td>必填</td><td>执行动作集合，接口只支持设备生命周期、设备数据上报两种触发方式，定时触发、第三方数据触发可通过页面设置，如下的a表示actions数组的单个对象标识</td></tr>
<tr><td>a. device_name</td><td>string</td><td>必填</td><td>设备名称</td></tr>
<tr><td>a. product_id</td><td>string</td><td>必填</td><td>产品ID</td></tr>
<tr><td>a. identifier</td><td>string</td><td>必填</td><td>属性功能点标识</td></tr>
<tr><td>a. type</td><td>string</td><td>必填</td><td>功能点数据类型</td></tr>
<tr><td>a. value</td><td>string</td><td>必填</td><td>功能点值</td></tr>
<tr><td>emit_condition</td><td>string</td><td>必填</td><td>触发方式，all - 满足全部条件触发, any - 任意条件触发</td></tr>
</tr><td rowspan="6">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>调用成功返回业务数据</td></tr>
<tr><td colspan="2">data.id</td><td>string</td><td>场景ID</td></tr>
<tr><th>请求示例</th><td colspan="4">

{
    "project_id":"ocgzVU", 
    "name":"联动测试",
    "conditions":[ // 触发方式
        {   
            "ctype":"notify",  
            "device_name":"no001",
            "product_id":"30769", 
            "identifier":"1", 
            "type":"bool", 
            "value":"true",
            "operator":"eq"
    }],
    "actions":[  // 执行动作 
        {
            "device_name":"no001",
            "product_id":"30769",
            "identifier":"1",
            "type":"bool",
            "value":"true"
    }],
   "emit_condition":"all"
}
</th></tr>
<tr><th>响应示例</th><td colspan="4">

{
    "data": {
        "id": "5ee2031009f703003737cd5b"
    },
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
</th></tr>
</table>

### 场景联动规则编辑

<table>
<tr><th>方法</th><td colspan="4">POST</th></tr>
<tr><td>路径URI</td><td colspan="4">/application?action=UpdateSceneRule&version=1</td></tr>
</tr><td>请求头</td><td colspan="4">Content-Type : application/json</td></tr>
</tr><td>URL参数</td><td colspan="4">无</td></tr>
<tr><td rowspan="18">请求体参数</td><td>project_id</td><td>string</td><td>必填</td><td>项目ID</td></td>
<tr><td>scene_id</td><td>string</td><td>必填</td><td>场景联动规则ID</td></tr>
<tr><td>name</td><td>string</td><td>必填</td><td>场景联动名称</td></tr>
<tr><td>conditions</td><td>array</td><td>必填</td><td>触发条件集合，接口只支持设备生命周期、设备数据上报两种触发方式，定时触发、第三方数据触发可通过页面设置，如下的c表示conditions数组的单个对象标识</td></tr>
<tr><td>c. ctype</td><td>string</td><td>必填</td><td>触发方式 支持lifeCycle-设备生命周期、 notify-设备数据上报，注：当ctype为lifeCycle时，只需填product_id、device_name、value和operator字段</td></tr>
<tr><td>c. device_name</td><td>string</td><td>必填</td><td>设备名称</td></tr>
<tr><td>c. product_id</td><td>string</td><td>必填</td><td>产品ID</td></tr>
<tr><td>c. identifier</td><td>string</td><td>必填</td><td>属性功能点标识</td></tr>
<tr><td>c. type</td><td>string</td><td>必填</td><td>功能点数据类型 支持int32、int64、float、double、string、bool</td></tr>
<tr><td>c. value</td><td>string</td><td>必填</td><td>功能点预设值 触发方式为lifecycle时，value值为online或者offline</td></tr>
<tr><td>c. operator</td><td>string</td><td>必填</td><td>比较运算符 支持eq-等于、lt-小于、gt-大于、lte-小于等于、gte-大于等于</td></tr>
<tr><td>actions</td><td>array</td><td>必填</td><td>执行动作集合，接口只支持设备生命周期、设备数据上报两种触发方式，定时触发、第三方数据触发可通过页面设置，如下的a表示actions数组的单个对象标识</td></tr>
<tr><td>a. device_name</td><td>string</td><td>必填</td><td>设备名称</td></tr>
<tr><td>a. product_id</td><td>string</td><td>必填</td><td>产品ID</td></tr>
<tr><td>a. identifier</td><td>string</td><td>必填</td><td>属性功能点标识</td></tr>
<tr><td>a. type</td><td>string</td><td>必填</td><td>功能点数据类型</td></tr>
<tr><td>a. value</td><td>string</td><td>必填</td><td>功能点值</td></tr>
<tr><td>emit_condition</td><td>string</td><td>必填</td><td>触发方式，all - 满足全部条件触发, any - 任意条件触发</td></tr>
</tr><td rowspan="6">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>调用成功返回业务数据</td></tr>
<tr><td colspan="2">data.id</td><td>string</td><td>场景ID</td></tr>
<tr><th>请求示例</th><td colspan="4">

{
    "project_id":"ocgzVU",
    "scene_id":"5ee2031009f703003737cd5b", 
    "name":"联动测试",
    "conditions":[ // 触发条件集合
        {   
            "ctype":"notify", 
            "device_name":"no001",
            "product_id":"30769",
            "identifier":"1", 
            "type":"bool",
            "value":"true",
            "operator":"eq" 
    }],
    "actions":[  // 执行动作集合
        {
            "device_name":"no001",
            "product_id":"30769",
            "identifier":"1",
            "type":"bool",
            "value":"true"
    }],
   "emit_condition":"all"
}
</th></tr>
<tr><th>响应示例</th><td colspan="4">

{
    "data": {
        "id": "5ee2031009f703003737cd5b"
    },
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
</th></tr>
</table>

### 场景联动规则详情

<table>
<tr><th>方法</th><td colspan="4">GET</th></tr>
<tr><td>路径URI</td><td colspan="4">/application?action=QuerySceneRuleDetail&version=1&project_id=ocgzVU&scene_id=5ec48dce640d1b02043a6a59</td></tr>
</tr><td>请求头</td><td colspan="4"></td></tr>
<tr><td rowspan="2">URL请求参数</td><td>project_id</td><td>string</td><td>必填</td><td>项目ID</td></td>
<tr><td>scene_id</td><td>string</td><td>必填</td><td>场景联动规则ID</td></tr>
</tr><td>请求体参数</td><td colspan="4">无</td></tr>
</tr><td rowspan="11">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>调用成功返回业务数据</td></tr>
<tr><td colspan="2">data.name</td><td>string</td><td>项目名称</td></tr>
<tr><td colspan="2">data.conditions</td><td>array</td><td>触发方式集合</td></tr>
<tr><td colspan="2">data.actions</td><td>array</td><td>执行动作集合</td></tr>
<tr><td colspan="2">data.emit_condition</td><td>string</td><td>执行条件，all-全部触发, any-任意触发</td></tr>
<tr><td colspan="2">data.created_at</td><td>string</td><td>创建时间</td></tr>
<tr><td colspan="2">data.updated_at</td><td>string</td><td>更新时间</td></tr>
<tr><th>字段结构描述</th><td colspan="4">

data.conditions字段结构：
[
    {
        "ctype": string, # 触发方式 lifeCycle - 设备生命周期触发
        "device_name": string, # 设备名称
        "product_id": string, # 产品ID
        "value": string, # 功能点值
        "operator": string, # 比较运算符 eq-等于
    },
    {
        "ctype": string, # 触发方式 notify - 设备数据上报触发
        "device_name": string, # 设备名称
        "product_id": string, # 产品ID
        "identifier": string, # 属性功能点标识
        "type": string, # 功能点数据类型
        "value": string, # 功能点值
        "operator": string, # 比较运算符 eq-等于 lt-小于 gt-大于 lte-小于等于 gte-大于等于
    },
    {
        "ctype": string, # 触发方式 extension - 第三方数据触发
        "value": string,  # 第三方数据比较值
        "operator": string, # 比较运算符 eq-等于 lt-小于 gt-大于 lte-小于等于 gte-大于等于
        "ext": {  
            "ad_code": string,  # 城市编码
            "type": string # 第三方数据类型  weather-天气  temperature-温度 humidity-湿度 pm25-pm2.5  airquality-空气质量
        }
    },
    {
        "ctype": string, # 触发方式 timer - 定时条件触发
        "timer": {
            "repeat_day": array, # 重复周期 支持[mon 、tue、wed、thu、fri、sat、sun]
            "time": string, # 定时触发时间
            "cron": string  # cron时间格式
        }
    }
]
data.actions 字段结构为：
[
    // 执行动作 - 设备执行
    {
        "device_name": string, # 设备名称
        "product_id": string, # 产品ID
        "identifier": string, #  属性功能点标识
        "type": string, # 功能点数据类型
        "value": string, # 功能点值
    },
    // 执行动作 - API调用
    {
        "callback": {
            "url": string  # API调用地址
        }
    }
]
</th></tr>
<tr><th>请求示例</th><td colspan="4">GET /application?action=QuerySceneRuleDetail&version=1&project_id=ocgzVU&scene_id=5ec48dce640d1b02043a6a59</th></tr>
<tr><th>响应示例</th><td colspan="4">

{
    "data": {
        "name":"联动测试",
        "conditions":[
            {   
                "ctype":"notify",
                "device_name":"datou1",
                "product_id":"30769",
                "identifier":"1",
                "type":"bool",
                "value":"true",
                "operator":"eq"
            },
            {
                "ctype": "extension", 
                "value": "BAD",   
                "operator": "gt",
                "ext": {
                    "ad_code": "101041200",   
                    "type": "airquality"
                }
            },
            {
                "ctype": "timer",     
                "timer": {
                    "repeat_day": [ 
                        "wed" 
                    ],
                    "time": "01:02:07",
                    "cron": "07 02 01 ? * WED *"
                }
            }
        ],
        "actions":[
            {
                "device_name":"datou1",
                "product_id":"30769",
                "identifier":"1",
                "type":"bool",
                "value":"true"
        }],
        "emit_condition":"all",
        "created_at": "2020-05-20T01:37:45.187Z",
        "updated_at": "2020-05-20T01:45:35.149Z"
    },
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
</th></tr>
</table>

### 场景联动规则列表

<table>
<tr><th>方法</th><td colspan="4">GET</th></tr>
<tr><td>路径URI</td><td colspan="4">/application?action=QuerySceneRules&version=1&project_id=ocgzVU</td></tr>
</tr><td>URI</td><td colspan="4"></td></tr>
</tr><td>请求头</td><td colspan="4"></td></tr>
<tr><td rowspan="3">URL请求参数</td><td>project_id</td><td>string</td><td>必填</td><td>项目ID</td></td>
<tr><td>offset</td><td>string</td><td>可选</td><td>请求起始位置，默认0</td></tr>
<tr><td>limit</td><td>string</td><td>可选</td><td>每次请求记录数，默认10, 范围[1, 100]</td></tr>
</tr><td>请求体参数</td><td colspan="4">无</td></tr>
</tr><td rowspan="15">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>调用成功返回业务数据</td></tr>
<tr><td colspan="2">data.list</td><td>array</td><td>场景联动规则集合，如下的l表示 list 数组的单个对象标识</td></tr>
<tr><td colspan="2">l.name</td><td>string</td><td>规则名称</td></tr>
<tr><td colspan="2">l.scene_id</td><td>string</td><td>规则ID</td></tr>
<tr><td colspan="2">l.start</td><td>string</td><td>规则是否启用</td></tr>
<tr><td colspan="2">l.created_at</td><td>string</td><td>创建时间</td></tr>
<tr><td colspan="2">l.updated_at</td><td>string</td><td>更新时间</td></tr>
<tr><td colspan="2">data.meta</td><td>object</td><td>分页信息</td></tr>
<tr><td colspan="2">data.meta.limit</td><td>string</td><td>每次请求记录数</td></tr>
<tr><td colspan="2">data.meta.offset</td><td>string</td><td>请求记录起始位置</td></tr>
<tr><td colspan="2">data.meta.count</td><td>object</td><td>记录总数</td></tr>
<tr><th>请求示例</th><td colspan="4">GET /application?action=QuerySceneRules&version=1&project_id=ocgzVU</th></tr>
<tr><th>响应示例</th><td colspan="4">

{
    "data": {
        "list": [
          {
            "name": "联动测试",
            "scene_id": "a25087f46df04b69b29e90ef0acfd115",
            "start": true,
            "created_at": "2020-05-20T01:37:45.187Z",
            "updated_at": "2020-05-20T01:45:35.149Z"
          }
        ],
        "meta": {
          "count": 1,
          "limit": 10,
          "offset": 0
        },
    },
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
</th></tr>
</table>

### 场景联动触发日志

<table>
<tr><th>方法</th><td colspan="4">GET</th></tr>
<tr><td>路径URI</td><td colspan="4">/application?action=QuerySceneLog&version=1&project_id=ocgzVU&scene_id=5ec48dce640d1b02043a6a59</td></tr>
</tr><td>请求头</td><td colspan="4"></td></tr>
<tr><td rowspan="6">URL请求参数</td><td>project_id</td><td>string</td><td>必填</td><td>项目ID</td></td>
<tr><td>scene_id</td><td>string</td><td>必填</td><td>场景联动规则ID</td></tr>
<tr><td>start_time</td><td>string</td><td>可选</td><td>查询起始时间，例如2020-07-10T05:59:02.833Z</td></tr>
<tr><td>end_time</td><td>string</td><td>可选</td><td>查询起始时间</td></tr>
<tr><td>offset</td><td>string</td><td>可选</td><td>请求起始位置，默认0</td></tr>
<tr><td>limit</td><td>string</td><td>可选</td><td>每次请求记录数，默认10, 范围[1, 100]</td></tr>
</tr><td>请求体参数</td><td colspan="4">无</td></tr>
</tr><td rowspan="10">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>调用成功返回业务数据</td></tr>
<tr><td colspan="2">data.list</td><td>array</td><td>场景联动触发日志集合</td></tr>
<tr><td colspan="2">data.meta</td><td>object</td><td>分页信息</td></tr>
<tr><td colspan="2">data.meta.limit</td><td>int</td><td>每次请求记录数</td></tr>
<tr><td colspan="2">data.meta.offset</td><td>int</td><td>请求记录起始位置</td></tr>
<tr><td colspan="2">data.meta.count</td><td>int</td><td>记录总数</td></tr>
<tr><th>字段结构描述</th><td colspan="4">

data.list字段结构：
[
    {
        "conditions": [ # 触发条件
            {
                "ctype": string, # 触发方式 lifeCycle - 设备生命周期触发
                "device_name": string, # 设备名称
                "product_id": string, # 产品ID
                "value": string, # 功能点值
                "operator": string, # 比较运算符 eq-等于
            },  
            {
                "ctype": string , # 触发方式 notify - 设备数据上报
                "device_name": string, # 设备名称
                "product_id": string, # 产品ID
                "identifier": string, # 功能点标识
                "type": string, # 功能点数据类型
                "value": string, # 预设值
                "operator": string, # 比较运算符 
            },
            {
                "ctype": string, # 触发方式 extension - 第三方数据触发
                "value": string,  # 第三方数据比较值
                "operator": string, # 比较运算符 eq-等于 lt-小于 gt-大于 lte-小于等于 gte-大于等于
                "ext": {  
                    "ad_code": string,  # 城市编码
                    "type": string # 第三方数据类型  weather-天气 temperature-温度 humidity-湿度 pm25-pm2.5  airquality-空气质量
                }
            },
            {
                "ctype": string, # 触发方式 timer - 定时条件触发
                "timer": {
                    "repeat_day": array, # 重复周期 支持[mon、tue、wed、thu、fri、sat、sun]
                }
                "time": string, # 定时触发时间
                "cron": string  # cron时间格式
             }
        ],
        "actions": [ # 执行动作
            // 执行动作 - 设备执行
            {
                "device_name": string, # 设备名称
                "product_id": string, # 产品ID
                "identifier": string, # 功能点标识
                "type": string, # 功能点数据类型
                "value": string, # 预设值
                "success": boolean, # 执行结果
                "message": string, # 执行错误码
            },
            // 执行动作 - API调用
            {
                "callback": {
                    "url": string # API调用地址
                }，
                "success": boolean, # 执行结果
                "message": string, # 执行错误码
            },    
        ],
        "scene_id": string, # 联动规则ID
        "status": string, # 执行结果
        "created_at": string, # 触发时间
    }
]        "value": string, # 功能点值
    },
    // 执行动作 - API调用
    {
        "callback": {
            "url": string  # API调用地址
        }
    }
]
</th></tr>
<tr><th>请求示例</th><td colspan="4">GET /application?action=QuerySceneLogversion=1&project_id=ocgzVU&scene_id=5ec48dce640d1b02043a6a59</th></tr>
<tr><th>响应示例</th><td colspan="4">

{
    "data": {
        "list": [
            {
                "conditions": [
                    {
                        "ctype": "notify",
                        "device_name": "30769-datou1",
                        "product_id": "30769",
                        "identifier": "1",
                        "type": "bool",
                        "value": "true",
                        "operator": "eq"
                    },
                    {
                        "ctype": "extension",  
                        "value": "BAD",       
                        "operator": "gt",
                        "ext": {
                            "ad_code": "101041200",
                            "type": "airquality" 
                        }
                    },
                    {
                        "ctype": "timer",
                        "timer": {
                            "repeat_day": [
                                "wed"
                            ],
                            "time": "01:02:07",
                            "cron": "07 02 01 ? * WED *"
                        }
                    }
                ],
                "actions": [
                    {
                        "device_name": "30769-datou1",
                        "product_id": "30769",
                        "identifier": "1",
                        "type": "bool",
                        "value": "true",
                        "success": true,
                        "message": "命令下发成功"
                    }
                ],
                "scene_id": "5ec48dce640d1b02043a6a59",
                "status": "allsuccess ",
                "created_at": "2020-05-21T01:27:18.974Z",
                "updated_at": "2020-05-21T01:27:18.974Z"
            }
        ],
        "meta": {
            "count": 1,
            "limit": 10,
            "offset": 0
        },
    },
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
</th></tr>
</table>

## 产品管理

### 产品详情

<table>
<tr><th>方法</th><td colspan="4">GET</th></tr>
<tr><td>路径URI</td><td colspan="4">/common?action=ProductDetail&version=1&product_id=10132</td></tr>
</tr><td>请求头</td><td colspan="4"></td></tr>
<tr><td rowspan="1">URL请求参数</td><td>product_id</td><td>string</td><td>必填</td><td>产品ID</td></td>
</tr><td>请求体参数</td><td colspan="4">无</td></tr>
</tr><td rowspan="18">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>调用成功返回业务数据</td></tr>
<tr><td colspan="2">data.device_number</td><td>number</td><td>设备数量</td></tr>
<tr><td colspan="2">data.product_id</td><td>string</td><td>产品ID</td></tr>
<tr><td colspan="2">data.name</td><td>string</td><td>产品名称</td></tr>
<tr><td colspan="2">data.desc</td><td>string</td><td>产品描述</td></tr>
<tr><td colspan="2">data.network</td><td>string</td><td>联网方式</td></tr>
<tr><td colspan="2">data.category</td><td>string</td><td>产品所属分类ID</td></tr>
<tr><td colspan="2">data.protocol</td><td>number</td><td>协议类型 1-泛协议 2-MQTT 3-CoAP</td></tr>
<tr><td colspan="2">data.scene</td><td>string</td><td>产品所属场景ID</td></tr>
<tr><td colspan="2">data.create_time</td><td>string</td><td>创建时间</td></tr>
<tr><td colspan="2">data.ind_title</td><td>string</td><td>产品行业名称</td></tr>
<tr><td colspan="2">data.prod_ind</td><td>string</td><td>产品行业编码</td></tr>
<tr><td colspan="2">data.uid</td><td>string</td><td>产品用户ID</td></tr>
<tr><td colspan="2">data.sec_key</td><td>string</td><td>产品权限key</td></tr>
<tr><th>请求示例</th><td colspan="4">GET /common?action=ProductDetail&version=1&product_id=10132</th></tr>
<tr><th>响应示例</th><td colspan="4">

{
    "data": {
        "device_number":0,
        "protocol":2,
        "created_time":"2021-12-06T08:28:56.762Z",
        "product_id":"wjrJjSRtsG",
        "network":"1",
        "category":"138",
        "scene":"82",
        "ind_title":"智慧城市",
        "prod_ind":"1",
        "uid":37782,
        "sec_key":"vC3eX2gr8mapsNZ1zYVmtsFRMYaX953GbJiKlcAQTp4=",
        "desc":"",
        "name":"物模型"   
 },
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
</th></tr>
</table>

### 产品列表

<table>
<tr><th>方法</th><td colspan="4">GET</th></tr>
<tr><td>路径URI</td><td colspan="4">/common?action=ProductList&version=1</td></tr>
</tr><td>请求头</td><td colspan="4"></td></tr>
<tr><td rowspan="6">URL请求参数</td><td>name</td><td>string</td><td>可选</td><td>产品名称</td></td>
<tr><td>manufacturer</td><td>string</td><td>可选</td><td>厂商名称</td></tr>
<tr><td>protocol</td><td>string</td><td>可选</td><td>接入协议，可选['1', '2', '3', '4', '5', '6', '7', '8', '9', '0']</td></tr>
<tr><td>industry</td><td>string</td><td>可选</td><td>行业类型编码</td></tr>
<tr><td>offset</td><td>string</td><td>可选</td><td>请求起始位置，默认0</td></tr>
<tr><td>limit</td><td>string</td><td>可选</td><td>每次请求记录数，默认10</td></tr>
</tr><td>请求体参数</td><td colspan="4">无</td></tr>
</tr><td rowspan="26">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>调用成功返回业务数据</td></tr>
<tr><td colspan="2">data.list</td><td>array</td><td>产品信息集合，如下的l表示 list 数组的单个对象标识</td></tr>
<tr><td colspan="2">l. total</td><td>number</td><td>设备数量</td></tr>
<tr><td colspan="2">l. category_name</td><td>string</td><td>分类名称</td></tr>
<tr><td colspan="2">l. scene_name</td><td>string</td><td>场景名称</td></tr>
<tr><td colspan="2">l. desc</td><td>string</td><td>描述</td></tr>
<tr><td colspan="2">l. protocol</td><td>number</td><td>协议 1-泛协议 2-MQTT 3-CoAP</td></tr>
<tr><td colspan="2">l. created_time</td><td>string</td><td>创建时间</td></tr>
<tr><td colspan="2">l. product_id</td><td>string</td><td>产品ID</td></tr>
<tr><td colspan="2">l. network</td><td>string</td><td>联网模式 1-其他 2-蜂窝 3-wifi 4-以太网</td></tr>
<tr><td colspan="2">l. category</td><td>string</td><td>分类ID</td></tr>
<tr><td colspan="2">l. scene</td><td>string</td><td>场景ID</td></tr>
<tr><td colspan="2">l. ind_title</td><td>string</td><td>产品行业名称</td></tr>
<tr><td colspan="2">l. prod_ind</td><td>string</td><td>产品行业编码</td></tr>
<tr><td colspan="2">l. l. uid</td><td>string</td><td>产品用户ID</td></tr>
<tr><td colspan="2">l. sec_key</td><td>string</td><td>产品权限KEY</td></tr>
<tr><td colspan="2">l. name</td><td>string</td><td>产品名称</td></tr>
<tr><td colspan="2">l. manufacturer</td><td>string</td><td>厂商名称</td></tr>
<tr><td colspan="2">data.meta</td><td>object</td><td>分页信息</td></tr>
<tr><td colspan="2">data.meta.limit</td><td>number</td><td>每次请求记录数</td></tr>
<tr><td colspan="2">data.meta.offset</td><td>number</td><td>请求记录起始位置</td></tr>
<tr><td colspan="2">data.meta.total</td><td>number</td><td>条数</td></tr>
<tr><th>请求示例</th><td colspan="4">GET /common?action=ProductList&version=1&product_id=wA10WBynvt</th></tr>
<tr><th>响应示例</th><td colspan="4">

{
    "data": {
         "list":[
            {
                "total":2,
                "category_name":"智能后视镜",
                "scene_name":"公共服务",
                "protocol":4,
                "created_time":"2021-08-31T08:00:12.846Z",
                "product_id":"wA10WBynvt",
                "network":"3",
                "category":"326",
                "scene":"14",
                "ind_title":"智慧城市",
                "prod_ind":"1",
                "uid":5,
                "sec_key":"RJKrcCGT22DYGSQ4KVXslu/Jnh3bezHzvhqCTFMk05Q=",
                "desc":"",
                "name":"qwe123",
                "manufacturer":"S1234567890"
            }
        ],
        "meta":{
            "total":1,
            "limit":10,
            "offset":0
        }
 },
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
</th></tr>
</table>

### 设备列表

<table>
<tr><th>方法</th><td colspan="4">GET</th></tr>
<tr><td>路径URI</td><td colspan="4">/common?action=DeviceList&version=1</td></tr>
</tr><td>请求头</td><td colspan="4"></td></tr>
<tr><td rowspan="5">URL请求参数</td><td>name</td><td>string</td><td>可选</td><td>设备名称</td></td>
<tr><td>product_id</td><td>string</td><td>可选</td><td>产品ID</td></tr>
<tr><td>status</td><td>string</td><td>可选</td><td>设备状态，可选['1'未激活, '2'在线, '3'离线]</td></tr>
<tr><td>offset</td><td>string</td><td>可选</td><td>请求起始位置，默认0</td></tr>
<tr><td>limit</td><td>string</td><td>可选</td><td>每次请求记录数，默认10</td></tr>
</tr><td>请求体参数</td><td colspan="4">无</td></tr>
</tr><td rowspan="21">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>调用成功返回业务数据</td></tr>
<tr><td colspan="2">data.list</td><td>array</td><td>产品信息集合，如下的l表示 list 数组的单个对象标识</td></tr>
<tr><td colspan="2">l. product_id</td><td>string</td><td>产品ID</td></tr>
<tr><td colspan="2">l. name</td><td>string</td><td>设备名称</td></tr>
<tr><td colspan="2">l. node_type</td><td>number</td><td>节点类型1：直连设备，2：网关设备，3：网关子设备</td></tr>
<tr><td colspan="2">l. status</td><td>number</td><td>设备状态1：未激活，2：在线，3：离线 【默认为未激活】</td></tr>
<tr><td colspan="2">l. last_time</td><td>string</td><td>设备最后一次在线时间</td></tr>
<tr><td colspan="2">l. created_time</td><td>string</td><td>创建时间</td></tr>
<tr><td colspan="2">l. from</td><td>string</td><td>设备来源(1:自主创建，2:他人转移)</td></tr>
<tr><td colspan="2">l. lon</td><td>string</td><td>经度</td></tr>
<tr><td colspan="2">l. lat</td><td>string</td><td>纬度</td></tr>
<tr><td colspan="2">l. idid</td><td>string</td><td>设备ID</td></tr>
<tr><td colspan="2">l. product_name</td><td>string</td><td>产品名称</td></tr>
<tr><td colspan="2">data.meta</td><td>object</td><td>分页信息</td></tr>
<tr><td colspan="2">data.meta.limit</td><td>number</td><td>每次请求记录数</td></tr>
<tr><td colspan="2">data.meta.offset</td><td>number</td><td>请求记录起始位置</td></tr>
<tr><td colspan="2">data.meta.total</td><td>number</td><td>条数</td></tr>
<tr><th>请求示例</th><td colspan="4">GET /common?action=DeviceList&version=1</th></tr>
<tr><th>响应示例</th><td colspan="4">

{
    "data": {
          "list":[
            {
                "pid":"7ubgKi1vhm",
                "name":"400A002090011001",
                "ct":"2021-11-30T08:22:53.519Z",
                "node_type":1,
                "status":3,
                "last_time":"2021-12-10T10:19:33.327Z",
                "from":1,
                "lon":"",
                "lat":"",
                "idid":"10015446",
                "product_id":"7ubgKi1vhm",
                "created_time":"2021-11-30T08:22:53.519Z",
                "id":10015446,
                "product_name":"水电费"
            }
        ],        
"meta":{
            "total":1,
            "limit":10,
            "offset":0
        }
 },
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
</th></tr>
</table>

### 产品中的设备数量统计

<table>
<tr><th>方法</th><td colspan="4">GET</th></tr>
<tr><td>路径URI</td><td colspan="4">/common?action=ProductDeviceStatistics&version=1</td></tr>
</tr><td>请求头</td><td colspan="4"></td></tr>
<tr><td rowspan="1">URL请求参数</td><td>product_id</td><td>string</td><td>必填</td><td>产品id </td></td>
</tr><td rowspan="9">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>调用成功返回业务数据</td></tr>
<tr><td colspan="2">data.unactive</td><td>number</td><td>未激活设备数</td></tr>
<tr><td colspan="2">data.online</td><td>number</td><td>在线设备数</td></tr>
<tr><td colspan="2">data.offline</td><td>number</td><td>离线设备数</td></tr>
<tr><td colspan="2">data.total</td><td>number</td><td>总的设备数</td></tr>
<tr><th>请求示例</th><td colspan="4">GET /common?action=ProductDeviceStatistics&version=1&product_id=7ubgKi1vhm</th></tr>
<tr><th>响应示例</th><td colspan="4">

{
    "data": { 
         "unactive":6, // 未激活数
        "online":0, // 在线数
        "offline":8, // 离线数
        "total":14 // 总数
} 
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
</th></tr>
</table>