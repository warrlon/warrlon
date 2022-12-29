# 签名机制
签名时，您需在用户管理控制台页面查看您当前账号的 AccessKeyId 和 AccessKeySecret，然后进行加密。其中，AccessKeyId 用于标识访问者身份；AccessKeySecret 是用于加密签名字符串和服务器端验证签名字符串的密钥，必须严格保密。

请按照下面的方法对请求进行签名：

## 构造规范化的请求字符串（Canonicalized Query String）

### 排序参数

按参数名的字典顺序，对请求参数进行排序，包括 公共请求参数（不包括 **Signature** 参数）和接口的自定义参数。
    

```
说明 当使用 GET 方法提交请求时，这些参数就是请求 URL 中的参数部分，即 URL 中 ?之后由 &连接的部分。
```

### 使用等号=连接请求参数名和参数值

### 使用与号&连接请求参数。参数排序与步骤"排序参数" 的排序一致

### 在上一步处理之后的字符串后追加请求Body（JSON格式）参数内容

### 对上一步处理之后的字符串进行 URL 编码

使用UTF-8字符集按照 RFC3986 规则编码整个字符串。编码规则如下：

- 字符 A~Z、a~z、0~9 以及字符-、_、.、~不编码。
- 其它字符编码成%XY的格式，其中XY是字符对应 ASCII 码的 16 进制表示。比如英文的双引号"对应的编码为%22。
- 扩展的UTF-8字符，编码成%XY%ZA…的格式。
- 英文空格要编码成%20，而不是加号+。
- 该编码方式与application/x-www-form-urlencoded MIME格式编码算法相似，但又有所不同。

如果您使用的是Java标准库中的java.net.URLEncoder，可以先用标准库中 URLEncoder.encode()编码，随后将编码后的字符中加号+替换为%20、星号*替换为%2A、%7E替换为波浪号~，即可得到上述规则描述的编码字符串。

```java
private static final String ENCODING = "UTF-8";
private static String percentEncode(String value) throws UnsupportedEncodingException {
	return value != null ? URLEncoder.encode(value, ENCODING).replace("+", "%20").replace("*", "%2A").replace("%7E", "~") : null;
}
```

完成后，即获得规范化请求字符串（CanonicalizedQueryString）。

## 构造签名字符串

   加上请求方法构造完整的签名字符串。可参考如下规则：

```java
StringToSign=
HTTPMethod + "&" + //HTTPMethod：发送请求的 HTTP 方法，例如 GET。
percentEncode("/") + "&" + //percentEncode("/")：字符（/）UTF-8 编码得到的值，即 %2F。
CanonicalizedQueryString//您的规范化请求字符串。
```

## 计算 HMAC 值

   按照 RFC2104 的定义，使用步骤"构造签名字符串"得到的字符串StringToSign计算签名 HMAC 值。示例使用的是Java Base64编码方法。

```java
signature = Base64( HMAC-SHA1( AccessSecret, UTF-8-Encoding-Of(StringToSign) ) )
```

```
 说明 计算签名时，使用的 Key 就是您的 AccessKeySecret 。使用的哈希算法是 SHA1。
```

## 计算签名值

按照 Base64 编码规则把步骤"计算HMAC值"中的 HMAC 值编码成字符串，即得到签名值（Signature）。

## 添加签名

将得到的签名值作为 signature 参数，按照 RFC3986 的规则进行 URL 编码后，再添加到请求参数中，即完成对请求签名的过程。

