# 人脸对比

## 功能介绍

接口能力：比对两张图片中人脸的相似度，并返回相似度分值；只用于单人脸对比；

图片格式：现支持PNG、JPG、JPEG、BMP,不支持GIF图片；

图片大小：图片中主体人脸部分像素不小于80*80；上传图片大小不超过2M；

业务应用：用于比对多张图片中的人脸相似度并返回两两比对的得分，可用于判断两张脸是否是同一人的可能性大小；如智能手机或电脑的登录验证、人证合一验证、会场签到等。

## API调用方式
<table>
<tr>
	<th width="20%">请求方式</th>
	<th>POST</th>
</tr>
<tr>
	<td>url</td>
	<td>http://ai.heclouds.com:9090/v1/aiApi/picture/FACE_COMPARE</td>
</tr>
<tr>
	<td>http-header</td>
	<td>Login-Token: xxxxxxxxxxxxxxxxx(用户鉴权接口返回结果loginToken )<br/>
Content-Type:application/json</td>
</tr>
<tr>
	<td>request-body</td>
    <td>{<br/>
	&nbsp;&nbsp;&nbsp;&nbsp;"picture":["String","String" ]  //两张图片的base64图片编码<br/>
}</td>
</tr>
<tr>
    <td>成功返回结果</td>
    <td> {<br/>
	 &nbsp;&nbsp;  &nbsp;&nbsp; "stateCode":"0x0000",	//结果状态码，16进制。"0x0000":成功;"0x240B":调用次数超过最大限制;"0x240C":调用频率过快;<br/>
	 &nbsp;&nbsp;  &nbsp;&nbsp; "message":"success",	//返回信息<br/>
	 &nbsp;&nbsp;  &nbsp;&nbsp; "data":"String"    //评分，人脸在图片中的位置<br/>
}<br/>
例如:<br/>
  "0.74738,176,207,277,277,123,299,398,398"   //评分，两张人脸分别在图片中的矩形框坐标位置和大小<br/>
  "NoFace";    //图片中没有脸<br/>
  "MoreThanOneFace";   //图片中有多张脸<br/>
  "ImageError";   //图片错误<br/>
  "0.74738 "表示相似度<br/>
 从第二个数字开始，每4个数字为一组，两组数字分别表示两张图中人脸的矩形框的位置信息，例如"176,207,277,277"是指在以图片左上角为原点的坐标系中，人脸所在的矩形框的位置信息，其中"176"表示X坐标：176px，"207"表示Y坐标：-207px，"277"表示矩形宽：277px，"277"表示矩形高：277px。<br/>
注意：<br/>
http错误码返回"401"时表示"未经授权"，造成的原因有：未使用或使用的token不正确；使用的token已经超时失效。
  </td>
</tr> 
</table>


## 请求示例
[bash](#bash) 	
[Java](#Java) 	
[Python](#Python)	 	
[C++](#C++)	
[C#](#C#)	
[Node](#Node)	

<span id="bash">
bash示例如下：

```bash
// 人脸对比
curl -X POST \
  http://ai.heclouds.com:9090/v1/aiApi/picture/FACE_COMPARE \
  -H 'Cache-Control: no-cache' \
  -H 'Content-Type: application/json' \
  -H 'Login-Token: 请自行替换Login-Token' \
  -d '{
 "picture": ["请替换图片(base64编码的图片数据)",
 "请替换图片(base64编码的图片数据)"]
}
'
```
<span id="Java">
Java示例如下：

```java
import java.util.HashMap;
import java.util.Map;

import com.mobile.analysis.Base64Img;
import com.mobile.analysis.HttpUtil;

/**
 * 人脸对比
 */
public class FaceCheck {

    public static void main(String[] agrs){
        //人脸对比
        faceCheck();
    }

    /**
     * 下载工具包
     * http://open.iot.10086.cn/ai/code/java.zip
     */
    private static void faceCheck() {
        String path = "http://ai.heclouds.com:9090/v1/aiApi/picture/FACE_COMPARE";
        String loginToken = "【获取loginToken】";

        //图片信息
        Map<String, Object> params = new HashMap<>();
        //方式一
        String imgURL1 = "https://ss1.bdstatic.com/70cFvXSh_Q1YnxGkpoWK1HF6hhy/it/u=1252736001,1291115764&fm=27&gp=0.jpg";
        String imgURL2 = "https://ss2.bdstatic.com/70cFvnSh_Q1YnxGkpoWK1HF6hhy/it/u=3563872185,2131706691&fm=27&gp=0.jpg";
        String pic1 = Base64Img.GetImageStrFromUrl(imgURL1);
        String pic2 = Base64Img.GetImageStrFromUrl(imgURL2);
        //方式二
        //String pic1 = Base64Img.GetImageStrFromPath("【本地图片文件】");
        //String pic2 = Base64Img.GetImageStrFromPath("【本地图片文件】");

        String[] value = {pic1,pic2};
        params.put("picture", value);
        try {
            //调用
            String result = HttpUtil.post(path, loginToken, params);
            System.out.println("result:" + result);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
```
<span id="Python">
Python示例如下：

```python
import requests
import json
import base64

url = 'http://ai.heclouds.com:9090/v1/aiApi/picture/FACE_COMPARE'
headers ={
    'Content-Type':'application/json',
    'Login-Token':'xxxxxxxxxxxxxxxxx(用户鉴权接口返回结果loginToken)'
    }
file1 = open('用户上传图片1','rb')
file2 = open('用户上传图片2','rb')
str1 = base64.b64encode(file1.read()).decode()
str2 = base64.b64encode(file2.read()).decode()
file1.close()
file2.close()
data = {'picture':[str1,str2]}
req = requests.post(url,data=json.dumps(data),headers=headers)
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
	//图片路径1
	string pic1Path;
	//图片路径2
	string pic2Path;
	do
	{
//给图片路径赋值
#if defined (WIN32)
		pic1Path = "testData/1.jpeg";
		pic2Path = "testData/2.jpeg";
#elif defined(__linux__)
		if (argc < 3) {
			cout << "param error!  run like this: " << endl << "./OneNETAiApi testData/1.jpeg testData/2.jpeg " << endl;
			break;
		}
		pic1Path = argv[1];
		pic2Path = argv[2];
#endif
 		//登陆获取token
		if (!loginToken(result, &aiApiRequest, account, password)) {
			cout << "login failed,result is: " << result << endl;
			break;
		}
		IFEMPTYBRREAK(result.empty());
		token = result;
		cout << "login success,token is: " << token << endl;
		//执行人脸对比api请求
		if (!faceCompare(result, &aiApiRequest, token, pic1Path, pic2Path)) {
			cout << "faceCompare failed,result is: " << result << endl;
			break;
		}
		cout << "\n faceCompare result :" << result << endl;
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

namespace ConsoleApplication1
{
    class Program
    {

        //人脸对比功能
        //注意：需要引用外部LitJson和RestSharp库

        static void Main(string[] args)
        {
            var token = "";//请用户通过用户鉴权接口获取token
            string sFilePath1 = "D:\\OneNETdiskDownload\\test1.jpg"; //人脸1图片文件路径
            string sFilePath2 = "D:\\OneNETdiskDownload\\test1.jpg"; //人脸2图片文件路径
            var client = new RestClient("http://ai.heclouds.com:9090/v1/aiApi/picture/FACE_COMPARE");
            var request = new RestRequest(Method.POST);
            request.AddHeader("Login-Token", token);
            request.AddHeader("cache-control", "no-cache");
            request.AddHeader("content-type", "application/json");

            Byte[] bt1 = File.ReadAllBytes(sFilePath1);
            string sPicture1 = Convert.ToBase64String(bt1);
            Byte[] bt2 = File.ReadAllBytes(sFilePath2);
            string sPicture2 = Convert.ToBase64String(bt2);
            JsonData jd = new JsonData();
            jd["picture"] = new JsonData();
            jd["picture"].Add(sPicture1);
            jd["picture"].Add(sPicture2);
            request.AddParameter("application/json", jd.ToJson(), ParameterType.RequestBody);

            IRestResponse response = client.Execute(request);
            Console.WriteLine(response.Content);
            Console.ReadKey();
        }

    }
}
```
<span id="Node">
Node示例如下：

```node
/*
*desc:人脸对比
*version：1.0
*time：2018-07-24
*/
const http = require('http');//引入http模块,用于使用HTTP服务器与客户端
const fs = require('fs');//引入fs模块，用于与文件系统进行交互
const mineType = require('mime-types');//需要安装模块“mime-types”，安装方法：npm install mime-types
let fileAPath = 'D:/mydownload/aaa.jpg';//图片A路径
let fileBPath = 'D:/mydownload/bbb.jpg';//图片B路径
let dataA = fs.readFileSync(fileAPath);//读取文件
let dataB = fs.readFileSync(fileBPath);//读取文件
dataA = Buffer.from(dataA).toString('base64');//转换为“base64”格式
dataB = Buffer.from(dataB).toString('base64');//转换为“base64”格式
let base64DataA = 'data:' + mineType.lookup(fileAPath) + ';base64,' + dataA;//补充完整图片信息
let base64DataB = 'data:' + mineType.lookup(fileBPath) + ';base64,' + dataB;//补充完整图片信息
console.log(base64DataA);
console.log(base64DataB);
const loginToken = 'KEFxABCxKUVzO0F1*Ua2OER4O0R0*EABCEFxfUBxKUVzO0F1*Ua2OER4O0R0*EJAU2LLS1W*Um_KQUF2K0F4KlV6K0FA*Ea1KEBAKUV0KUiyKlK0KU1yQUR0OERyKlB3QUF3KUR3';//用户鉴权接口返回结果loginToken,此处仅作为示例
//请求配置信息
const options = {
    host: 'ai.heclouds.com',//IP地址
    port: 9090,//端口号
    path: '/v1/aiApi/picture/FACE_COMPARE',//请求路径
    method: 'POST',//请求类型
    headers:{//请求头信息
        'Content-Type': 'application/json',
        'Login-Token': loginToken
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
let requestBody = {
    "picture":[base64DataA,base64DataB]
};
httpreq.write(JSON.stringify(requestBody));// 写入数据到请求主体
httpreq.end();//结束发送请求
```

