# 数据推送

<a href="#1">1. 实例创建</a> 

<a href="#2">2. 实例验证</a> 

<a href="#3">3. 消息推送</a> 

<a href="#4">4. 重推策略</a> 

<a href="#5">5. 最佳实践</a> 

---

HTTP推送用于实现平台与应用服务器之间的单向数据通信。平台作为客户端，通过HTTP/HTTPS请求方式，将项目下应用及设备数据推送给应用服务器。HTTP推送服务使用流程包括实例创建、实例验证、规则配置、消息推送4个步骤。

<h3 id="1">1. 实例创建</h3>

展开菜单栏中的「应用开发」，点击「消息推送」，进入推送实例列表页面。列表展示已创建的实例信息，每个实例对应一个HTTP的推送配置。点击「添加实例」，填写实例名称、推送地址等信息，完成实例新增，如图1所示。目前每个用户最多创建10个实例。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/application/数据推送_添加编辑HTTP推送实例.png">
    <br>
    图 1 添加HTTP推送实例
    <br>
</center>

##### 参数说明：

<table>
<tr><th width="20%">参数</th><th>说明</th></tr>
<tr><td>推送地址</td><td>应用服务器处理请求的URL地址，需要同时支持GET和POST两种方式。平台通过GET请求对应用服务地址有效性进行验证，通过POST请求将数据推送至应用服务器。</td></tr>
<tr><td>Token</td><td>应用服务器通过授权Token对平台身份进行校验，保证数据传输安全。</td></tr>
<tr><td>消息加密方式</td><td>支持明文模式和安全模式，安全模式采用AES加密算法，由系统生成16位长度的加密密钥。</td></tr>
</table>

实例创建成功，列表显示实例名称、消息加密方式、创建时间和验证状态等信息，如图2所示。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/application/数据推送_HTTP实例列表.png">
    <br>
    图 2 HTTP推送实例列表
    <br>
</center>

其中实例状态代表当前实例的验证状态，包括待验证、验证成功、验证失败三种。
- 待验证：创建成功的实例状态默认为待验证，用户未对实例进行过验证操作。
- 验证成功：当前实例已通过平台验证，可以正常使用。
- 验证失败：当前实例进行过验证操作，但验证失败，失败的原因包括：1）网络请求错误，应用服务器地址访问异常。2）url参数验证失败，应用服务器返回验证响应数据格式错误或平台请求未通过应用服务器校验。

<h3 id="2">2. 实例验证</h3>

实例创建成功后，下一步进行实例验证。实例列表页面，选择某一实例，点击「验证」，如图3所示。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/application/数据推送_验证HTTP推送实例.png">
    <br>
    图 3 验证HTTP推送实例
    <br>
</center>

点击验证时，平台服务器会向配置的服务器地址发送HTTP GET请求，进行地址有效性验证，请求形式示例如下：

```
http://url?msg=xxx&nonce=xxx&signature=xxx

```

携带参数信息包括：

<table>
<tr><th width="20%">参数</th><th>说明</th></tr>
<tr><td>msg</td><td>推送的消息内容。实例验证阶段，为平台生成的随机字符串；接收消息阶段，为平台推送的设备或业务消息数据</td></tr>
<tr><td>nonce</td><td>平台生成的随机字符串</td></tr>
<tr><td>signature</td><td>加密签名，signature结合了创建实例填写的token参数和请求中的msg、nonce参数。</td></tr>
</table>

应用服务器收到请求后，需要通过signature参数字段对请求进行校验。若确认此次GET请求来自OneNET平台，需在响应中原样返回msg参数，实例验证才能通过，否则验证失败，实例配置不生效。signature参数校验方法如下：

    (1) 将实例配置时填写的token参数及校验请求中携带的nonce、msg参数拼接得到字符串A，即A = token + nonce + msg
    (2) 将字符串A进行md5加密得到字符串B
    (3) 将字符串B进行Base64转换，并通过URL Decode计算后得到参数C，将参数C与signature进行对比，相等则表示校验成功，标识请求来于OneNET平台

如果用户不想验证，可选择跳过该过程，直接返回msg参数。实例验证通过后，下一步进行消息源（需要推送的数据）的配置。

<h3 id="3">3. 消息推送</h3>

消息源以单个项目进行配置，使用前需完成项目创建。推送实例列表页面点击「配置消息推送规则」按钮，弹出消息规则配置指引页面，如图3所示。选择某一具体项目，进入该项目「规则引擎」管理页面，配置推送的数据源及过滤规则。选择消息目的地为HTTP推送，页面展示当前已验证的推送实例列表，选择某一实例保存后，推送即可生效，该项目下设备及业务数据将会通过HTTP方式推送至应用服务器，详细操作见[规则引擎使用说明](/book/application-develop/push/rule_engine/rule_introduce.md)。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/application/HTTP数据推送_配置消息推送规则.png">
    <br>
    图 4 配置消息推送规则
    <br>
</center>

目前平台支持设备生命周期、设备物模型、场景联动触发日志等数据推送。推送数据以JSON形式置于HTTP请求中的body部分，推送消息格式如下：

```json
{
      "msg":  "xxxxxxxx", # 消息内容，JSON字符串
      "nonce": "abcdefgh", # 随机字符串
      "signature": "message signature", # 加密签名
      "time":  1591340648197,  # 消息推送时间
      "id":  "3799902"  # 消息id
}
```

<table>
<tr><th width="20%">字段</th><th>类型</th><th>字段说明</th></tr>
<tr><td>msg</td><td>string</td><td>规则引擎过滤后的数据内容，包括设备生命周期、设备物模型、场景联动触发日志，基础消息格式见规则引擎介绍</td></tr>
<tr><td>nonce</td><td>string</td><td>用于计算签名字符的随机串</td></tr>
<tr><td>signature</td><td>string</td><td>加密签名，用以校验推送客户端身份合法性，校验方法见实例验证</td></tr>
<tr><td>time</td><td>long</td><td>推送时间戳（毫秒）</td></tr>
<tr><td>id</td><td>string</td><td>消息ID</td></tr>
</table>

配置推送实例时，如果选择消息推送方式为安全模式，则平台会对消息msg进行加密处理（加密方式采用AES的CBC模式，数据填充采用PKCS7），应用服务器收到数据时，需通过生成密钥进行解密操作（详情见最佳实践示例）。

<h3 id="4">4. 重推策略</h3>

应用服务器收到平台每一次推送请求后，需要在有限时间内返回响应（目前是5秒），且HTTP响应状态码应设置为200，否则平台会认为请求发送失败，进行消息重推。重推采用指数退避策略，每条消息最多重推16次。如果某条消息一直失败，那么会在接下来的2小时45分4秒重推16次，之后不再重试。重推策略如下所示：

<table>
<tr><th>第几次重试</th><th>与上次间隔时间</th><th>第几次重试</th><th>与上次间隔时间</th></tr>
<tr><td>1</td><td>5秒</td><td>9</td><td>6分钟</td></tr>
<tr><td>2</td><td>10秒</td><td>10</td><td>7分钟</td></tr>
<tr><td>3</td><td>30秒</td><td>11</td><td>8分钟</td></tr>
<tr><td>4</td><td>1分钟</td><td>12</td><td>9分钟</td></tr>
<tr><td>5</td><td>2分钟</td><td>13</td><td>10分钟</td></tr>
<tr><td>6</td><td>3分钟</td><td>14</td><td>20分钟</td></tr>
<tr><td>7</td><td>4分钟</td><td>15</td><td>30分钟</td></tr>
<tr><td>8</td><td>5分钟</td><td>16</td><td>1小时</td></tr>
</table>

<h3 id="5">5. 最佳实践</font></h3>

##### JAVA代码示例

```java
/**
 * 功能描述 消息摘要计算
 *
 * @param msg   平台推送消息
 * @param token 配置页面填写的token
 * @param nonce 平台生成的随机字符串
 * @return
 * @throws Exception
 */
public static String signature(String msg, String token, String nonce) throws Exception {
    byte[] msgByte = msg.getBytes();
    byte[] tokenByte = token.getBytes();
    int tokenLen = tokenByte.length;
    int msgLen = msgByte.length;
    byte[] signature = new byte[tokenLen + 8 + msgLen];
    System.arraycopy(tokenByte, 0, signature, 0, tokenLen);
    System.arraycopy(nonce.getBytes(), 0, signature, tokenLen, 8);
    System.arraycopy(msgByte, 0, signature, tokenLen + 8, msgLen);
    MessageDigest mdInst = MessageDigest.getInstance("MD5");
    mdInst.update(signature);
    byte[] digest = mdInst.digest();
    return Base64.getEncoder().encodeToString(digest);
}
```

```java
/**
 * 功能描述 推送消息解密
 *
 * @param encryptMsg 加密消息体对象
 * @param key        配置页面生成的AES秘钥
 * @return
 * @throws NoSuchPaddingException
 * @throws NoSuchAlgorithmException
 * @throws InvalidAlgorithmParameterException
 * @throws InvalidKeyException
 * @throws BadPaddingException
 * @throws IllegalBlockSizeException
 */
public static String decrypt(String encryptMsg, byte[] key) throws NoSuchPaddingException, NoSuchAlgorithmException, InvalidAlgorithmParameterException, InvalidKeyException, BadPaddingException, IllegalBlockSizeException {
    byte[] encMsg = Base64.getDecoder().decode(encryptMsg);
    SecretKey secretKey = new SecretKeySpec(key, "AES");
    //算法/模式/补码方式
    //CBC模式 向量必须是16个字节
    Cipher cipher = Cipher.getInstance("AES/CBC/PKCS7Padding");
    cipher.init(Cipher.DECRYPT_MODE, secretKey, new IvParameterSpec(key));
    byte[] msg = cipher.doFinal(encMsg);
    return new String(msg);
}
```