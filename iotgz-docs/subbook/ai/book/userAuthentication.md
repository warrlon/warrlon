# 用户鉴权

Login Token的有效期为24小时，请您调用时注意在程序中定期请求新的token。

## API调用方式

<table>
<tr>
	<th width="20%">请求方式</th>
	<th>POST</th>
</tr>
<tr>
	<td>url</td>
	<td>http://ai.heclouds.com:9090/v1/user/oneNetLogin</td>
</tr>
<tr>
	<td>header</td>
	<td>Content-Type: application/json</td>
</tr>
<tr>
	<td>request-body</td>
    <td>{<br/>
&nbsp;&nbsp;"account":"String",	//用户账号<br/>
&nbsp;&nbsp;"password": "String"  //使用加密工具（请参照对应编程语言示例中所采用的加密工具）加密后的密文<br/>
}</td>
</tr>
<tr>
    <td>成功返回结果</td>
    <td> {<br/>
        &nbsp;&nbsp; "stateCode":"0x0000",	//结果状态码，16进制。"0x0000":成功;<br/>
        &nbsp;&nbsp;  "message": "success", <br/>
        &nbsp;&nbsp; "data":{ <br/>
		 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; "userId":"String",//用户id<br/>
		 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; "loginToken":"String"//登录token<br/>
   &nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;}<br/>
   }
  </td>
</tr> 
</table>

## 请求示例

[Java](#Java) 	
[Python](#Python) 	
[C++](#C++)	
[C#](#C#)	
[Node](#Node)		

<span id="Java">
Java示例如下：

```java
import java.util.HashMap;
import java.util.Map;

import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import com.mobile.analysis.HttpUtil;
import com.mobile.analysis.SimpleEncode;

/**
 * 用户鉴权
 */
public class OneNETLoginToken {

    private static Gson gson = new GsonBuilder().setPrettyPrinting().create();
    public static void main(String[] agrs){
        //获取loginToken：
        loginToken();

    }

    /**
     * 使用前请先下载工具包
     * http://open.iot.10086.cn/ai/code/Util-0.0.1.jar
     */
    public static String loginToken() {
        //服务地址
        String path = "http://ai.heclouds.com:9090/v1/user/oneNetLogin";
        //注册邮箱/登录密码
        String account = "############";
        String pwd = "############";
        try {
            //调用
            Map<String, Object> params = new HashMap<>();
            params.put("account",account);
            params.put("password", SimpleEncode.encrypt(pwd));
            String result = HttpUtil.post(path, null,params);
            System.out.println("result:" + result);
            Map map = gson.fromJson(result, Map.class);
            Object data = map.get("data");
            return  gson.fromJson(gson.toJson(data), Map.class).get("loginToken").toString();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return "";
    }

}
```
<span id="Python">
Python示例如下：

```python
import requests
import json
import base64
import random

class SimpleEncode():
    keyStr = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890abcdefghijklmnopqrstuvwxyz~!@#$%^&*()_+-={}[]:;<,>.?/|"
    keyLength = len(keyStr)
    encryptionA = 17
    encryptionB = 8
    decodeA = 0
    preCountMax = 15
    postCount = 5
    randomChar = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnop"
    randomCharLength = len(randomChar)
    #base64字符
    ALPHABET = "ABCDEFGHIJKLMN0123456789OPQRSTUVWXYZ+/abcdefghijklmnopqrstuvwxyz"
    STANDARD = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"  # 标准的字符串索引

    #找到密钥
    for i in range(1,keyLength):
            if (encryptionA * i) % keyLength == 1:
                decodeA = i

    def base64Encode(self,sourceStr):
        encode = ""
        for ch in base64.b64encode(sourceStr.encode()).decode():
            if ch == '=':
                encode += '='
            else:
                for i in range(64):
                    if ch == self.STANDARD[i]:
                        encode += self.ALPHABET[i]
        return encode

    def encrpyt(self,sourceStr):
        srcLength = len(sourceStr)
        #先加入干扰字符的数量
        addCharCount = random.randint(1,self.preCountMax) if srcLength < self.preCountMax else 0
        #随机字符
        sb = str(addCharCount)+"|"
        for i in range(addCharCount):
            sb += self.randomChar[random.randint(0,self.randomCharLength-1)]

        sb += sourceStr
        #尾部固定增加x个字符
        for i in range(self.postCount):
            sb += self.randomChar[random.randint(0,self.randomCharLength-1)]

        #base64 加密
        base64Str = self.base64Encode(sb)

        destStr = ''
        for i in range(len(base64Str)):
            #找到字符所在位置
            position = self.keyStr.find(base64Str[i])

            #对字符进行转换
            y = (self.encryptionA * position + self.encryptionB) % self.keyLength

            #找到替换后的字符

            destStr += self.keyStr[y]

        return destStr

if __name__ == '__main__':
    url = 'http://ai.heclouds.com:9090/v1/user/oneNetLogin'
    headers = {
        'Content-Type': 'application/json',
    }
    account = ''  # 用户名
    password = ''  # 用户密码
    simpleencode = SimpleEncode()
    data = {'account': account, 'password': simpleencode.encrpyt(password)}
    print(data)
    req = requests.post(url, data=json.dumps(data), headers=headers)
    print(req.text)
```

<span id="C++">
C++示例如下：

```c++
/*注意：完整工程地址，请从这里下载：http://open.iot.10086.cn/ai/code/cpp/OneNETAiApi.zip*/
#include<iostream>
#include"APIData.hpp"
using namespace std;
/*
*使用完整工程时，请复制此页的main函数，填入到工程main.cpp文件中
*其它api请求用法示例  请参考官网帮助文档（c++版）
*官网帮助文档地址：https://open.iot.10086.cn/ai/helpCenter.html#/helpHome?categoryType=2
*/
int main(int argc, char* argv[])
{
	//api请求地址
	const string url = "http://ai.heclouds.com:9090";
	//初始化一个对象，并传入参数url（api请求地址）
	OneNETAiApiRequest aiApiRequest(url);
	//用户名
	string account = "【替换成自已的用户名】";
	//密码
	string password = "【替换成自已的用户密码】";
	//存储返回结果
	string result;
	//存储token鉴权数据
	string token;
	do
	{
		if (argc < 3) {
			cout << "param error!  run like this: " << endl << "./OneNETAiApi" << endl;
			break;
		}
		//登陆获取token
		if (!loginToken(result, &aiApiRequest, account, password)) {
			cout << "login failed,result is: " << result << endl;
			break;
		}
		IFEMPTYBRREAK(result.empty());
		token = result;
		cout << "login success,token is: " << token << endl;
	} while (false);
	return 0;
}
```

<span id="C#">
C#示例如下：

```c#
using System;
using System.IO;
using LitJson;
using RestSharp;
using System.Text;
using System.Security.Cryptography;

namespace ConsoleApplication1
{
    class Program
    {

        //用户鉴权功能
        //注意：需要引用外部LitJson和RestSharp库

        static void Main(string[] args)
        {
            var client = new RestClient("http://ai.heclouds.com:9090/v1/user/oneNetLogin");
            var request = new RestRequest(Method.POST);
            request.AddHeader("cache-control", "no-cache");
            request.AddHeader("content-type", "application/json");

            //将用户名和加密后的密码作为request-body
            JsonData jd = new JsonData();
            jd["account"] = "用户名";//此处填入用户名
            jd["password"] = SimpleEncode.encrypt("密码");//此处填入密码
            request.AddParameter("application/json", jd.ToJson(), ParameterType.RequestBody);
            IRestResponse response = client.Execute(request);
            Console.WriteLine(response.Content);
            Console.ReadKey();
        }

    }



    public class SimpleEncode
    {

        // base64字符
        private static char[] ALPHABET = "ABCDEFGHIJKLMN0123456789OPQRSTUVWXYZ+/abcdefghijklmnopqrstuvwxyz".ToCharArray();
        private const String keyStr = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890abcdefghijklmnopqrstuvwxyz~!@#$%^&*()_+-={}[]:;<,>.?/|";
        private static int keyLength = keyStr.Length;
        private static int[] toInt = new int[128];

        private static int encryptionA = 17;
        private static int encryptionB = 8;
        private static int preCountMax = 15;
        private static int postCount = 5;

        private const String randomChar = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnop";
        private static int randomCharLength = randomChar.Length;


        /**
         *  加密方法
         * @param s
         * @return
         * @throws UnsupportedEncodingException
         */
        public static String encrypt(String s)
        {
            int srcLength = s.Length;
            System.Random random = new System.Random();
            // 先加入干扰字符
            // 加入数量
            int addCharCount = 0;
            if (srcLength < preCountMax)
            {
                addCharCount = random.Next(preCountMax) + 1;
            }

            // 随机字符
            StringBuilder sb = new StringBuilder(addCharCount + "|");
            for (int i = 0; i < addCharCount; i++)
            {
                sb.Append(randomChar[random.Next(randomCharLength)]);
            }
            sb.Append(s);
            // 尾部固定增加x个字符
            for (int i = 0; i < postCount; i++)
            {
                sb.Append(randomChar[random.Next(randomCharLength)]);
            }

            // base64加密
            String base64Str = base64Encode(sb.ToString());
            char[] srcArray = base64Str.ToCharArray();
            //char[] srcArray = sb.toString().toCharArray();
            char[] destArray = new char[srcArray.Length];
            for (int i = 0; i < srcArray.Length; i++)
            {
                char srcChar = srcArray[i];

                // 找到字符所在位置
                int position = keyStr.IndexOf(srcChar);

                // 对字符进行转换
                int y = (encryptionA * position + encryptionB) % keyLength;

                // 找到替换后的字符
                char replaceChar = keyStr[y];

                destArray[i] = replaceChar;
            }

            return new String(destArray);
        }

        /**
        * 先将原字符串使用utf-8编码，转为字节数组，再将字节数组进行Base64编码
        * @param sourceStr
        * @return
        * @throws UnsupportedEncodingException
        */
        private static String base64Encode(String sourceStr)
        {
            byte[] bs = Encoding.UTF8.GetBytes(sourceStr);
            return base64Encode(bs);
        }

        /**
         * Translates the specified byte array into Base64 string.
         *
         * @param buf the byte array (not null)
         * @return the translated Base64 string (not null)
         */
        private static String base64Encode(byte[] buf)
        {
            int size = buf.Length;
            char[] ar = new char[((size + 2) / 3) * 4];
            int a = 0;
            int i = 0;
            while (i < size)
            {
                byte b0 = buf[i++];
                byte b1 = (byte)((i < size) ? buf[i++] : 0);
                byte b2 = (byte)((i < size) ? buf[i++] : 0);

                int mask = 0x3F;
                ar[a++] = ALPHABET[(b0 >> 2) & mask];
                ar[a++] = ALPHABET[((b0 << 4) | ((b1 & 0xFF) >> 4)) & mask];
                ar[a++] = ALPHABET[((b1 << 2) | ((b2 & 0xFF) >> 6)) & mask];
                ar[a++] = ALPHABET[b2 & mask];
            }
            switch (size % 3)
            {
                case 1: ar[--a] = '=='; break;
                case 2: ar[--a] = '='; break;
            }
            return new String(ar);
        }

    }

}
```

<span id="Node">
Node示例如下：

```node
/*
*desc:用户鉴权
*version：1.0
*time：2018-07-24
*/
const http = require('http');//引入http模块,用于使用HTTP服务器与客户端
let userInfo = {
    "account":'12345678@qq.com',//用户账号
    "password":'pw1212'//用户密码
};
userInfo['password'] = new SimpleEncode().encode(userInfo['password']);//对密码进行处理
//请求配置信息
const options = {
    host: 'ai.heclouds.com',//IP地址
    port: 9090,//端口号
    path: '/v1/user/oneNetLogin',//请求路径
    method: 'POST',//请求类型
    headers:{//请求头信息
        'Content-Type': 'application/json'
    }
};
//建立请求
const httpreq = http.request(options, (httpres) => {
    let size = 0;//计数请求响应结果的大小
    let chunks = [];//保存请求响应结果
    httpres.on('data', function (chunk) {
        let tempBuffer = Buffer.from(chunk);
        chunks.push(tempBuffer);
        size += tempBuffer.length;
    });
    httpres.on('end', function () {
        console.log('状态码：'+httpres.statusCode);
        let bufferData = Buffer.concat(chunks,size);
        let result = JSON.parse(bufferData.toString());
        console.log('响应长度：'+size);
        console.log('响应结果：');
        console.log(result);
    });
}).on('error', (e) => {
    console.log(e.stack);
});
httpreq.write(JSON.stringify(userInfo));// 写入数据到请求主体
httpreq.end();//结束发送请求

function SimpleEncode(){
  const keyStr = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890abcdefghijklmnopqrstuvwxyz~!@#$%^&*()_+-={}[]:;<,>.?/|";
  const keyLength = keyStr.length;
  const keyArray = keyStr.split('');
  const encryptionA = 17;
  const encryptionB = 8;
  let decodeA = '';
  const preCountMax = 15;
  const postCount = 5;

  const randomChar = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnop";
  const randomCharLength = randomChar.length;

  // base64字符
  let ALPHABETStr = "ABCDEFGHIJKLMN0123456789OPQRSTUVWXYZ+/abcdefghijklmnopqrstuvwxyz";
  const ALPHABET = ALPHABETStr.split('');
  let toInt = new Array(128);

  // 找到解密钥
  for(let i=1; i<=keyLength; i++) {
    if( (encryptionA * i) % keyLength == 1) {
      decodeA = i;
    }
  }

  for(let i=0; i< ALPHABET.length; i++){
    toInt[ALPHABET[i]]= i;
  }

  this.encode = function (s) {
    let srcLength = s.length;
    // 先加入干扰字符
    // 加入数量
    let addCharCount = 0;
    if(srcLength < preCountMax) {
      addCharCount = Math.floor(Math.random()*preCountMax)+1;
    }

    // 随机字符
    let stringBuilder = addCharCount+"|";

    for(let i=0; i<addCharCount; i++) {
      stringBuilder += randomChar.charAt(Math.floor(Math.random()*randomCharLength));
    }
    stringBuilder += s;
    // 尾部固定增加x个字符
    for(let i=0; i<postCount; i++) {
      stringBuilder += randomChar.charAt(Math.floor(Math.random()*randomCharLength));
    }

    // base64加密
    //let base64Str = Buffer.from(stringBuilder).toString('base64');
    let base64Str = Base64_encode(stringBuilder);
    let srcArray = base64Str.split('');
    let destArray = new Array(srcArray.length);
    for(let i=0; i<srcArray.length; i++) {
      let srcChar = srcArray[i];
      // 找到字符所在位置
      let position = keyStr.indexOf(srcChar);
      // 对字符进行转换
      let y = (encryptionA * position + encryptionB) % keyLength;
      // 找到替换后的字符
      let replaceChar = keyStr.charAt(y);
      destArray[i] = replaceChar;
    }

    return destArray.join().replace(/,/g,'');
  }

  function Base64_encode (input) {
    let _keyStr = ALPHABETStr;
    let output = "";
    let chr1, chr2, chr3, enc1, enc2, enc3, enc4;
    let i = 0;
    input = _utf8_encode(input);
    while (i < input.length) {
      chr1 = input.charCodeAt(i++);
      chr2 = input.charCodeAt(i++);
      chr3 = input.charCodeAt(i++);
      enc1 = chr1 >> 2;
      enc2 = ((chr1 & 3) << 4) | (chr2 >> 4);
      enc3 = ((chr2 & 15) << 2) | (chr3 >> 6);
      enc4 = chr3 & 63;
      if (isNaN(chr2)) {
        enc3 = enc4 = 64;
      } else if (isNaN(chr3)) {
        enc4 = 64;
      }
      output = output +
        _keyStr.charAt(enc1) + _keyStr.charAt(enc2) +
        _keyStr.charAt(enc3) + _keyStr.charAt(enc4);
    }
    return output
  }
  /**
   * 将字符串编码为 UTF-8
   */
  function _utf8_encode(string) {
    string = string.replace(/\r\n/g,"\n");
    let utftext = "";
    for (let n = 0; n < string.length; n++) {
      let c = string.charCodeAt(n);
      if (c < 128) {
        utftext += String.fromCharCode(c);
      } else if((c > 127) && (c < 2048)) {
        utftext += String.fromCharCode((c >> 6) | 192);
        utftext += String.fromCharCode((c & 63) | 128);
      } else {
        utftext += String.fromCharCode((c >> 12) | 224);
        utftext += String.fromCharCode(((c >> 6) & 63) | 128);
        utftext += String.fromCharCode((c & 63) | 128);
      }
    }
    return utftext;
  }
}
```

