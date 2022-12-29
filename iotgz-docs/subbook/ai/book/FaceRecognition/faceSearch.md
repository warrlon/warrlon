# 人脸搜索

## 功能介绍

接口能力：在指定人脸数据库中，将一张人脸和 N 张人脸进行比对，查找出相同人脸；即1:N 人脸搜索；

图片格式：现支持PNG、JPG、JPEG、BMP,不支持GIF图片；

图片大小：上传图片大小不超过2M；目标像素不能小于80*80，图片为正面无遮挡的单人脸照片最佳；

业务应用：可应用于安防监控，刷脸门禁、刷脸签到等基于人脸识别的应用场景。

**注意：人脸库的创建和管理请到“控制台->数据管理->人脸库管理”中操作。**

## API调用方式
<table>
<tr>
	<th width="20%">请求方式</th>
	<th>POST</th>
</tr>
<tr>
	<td>url</td>
	<td>http://ai.heclouds.com:9090/v1/aiApi/picture/FACE_RECO_LIB</td>
</tr>
<tr>
	<td>http-header</td>
	<td>	Login-Token: xxxxxxxxxxxxxxxxx(用户鉴权接口返回结果loginToken )<br/>
Content-Type:application/json</td>
</tr>
<tr>
	<td>request-body</td>
    <td>{<br/>
	&nbsp;&nbsp;&nbsp;&nbsp;"param":"人脸库ID,0.x",  //人脸库ID（在OneNET AI平台的“控制台”中创建“人脸库”后该人脸库的ID），0.x-相似度阈值（英文逗号分隔，不传默认为0.6）<br/>
	&nbsp;&nbsp;&nbsp;&nbsp;"picture":["String"]  //一张图片的base64图片编码<br/>
}</td>
</tr>
<tr>
    <td>成功返回结果</td>
    <td> {<br/>
	&nbsp;&nbsp; &nbsp;&nbsp;"stateCode":"0x0000",	//结果状态码，16进制。"0x0000":成功;"0x240B":调用次数超过最大限制;"0x240C":调用频率过快;<br/>
	&nbsp;&nbsp;&nbsp;&nbsp;"message":"success",	//返回信息<br/>
	&nbsp;&nbsp;&nbsp;&nbsp;"data":"String"    //图片存储地址,置信度,用户名称<br/>
}<br/>
例如:<br/>
  "http://123.123.12.123:8080/ai/os/AiOneToNFace/1234567890987654321,1,张三"    // 图片存储地址,置信度,用户名称<br/>
  "no match pic";    //没有查找到匹配的图片<br/>
注意：<br/>
http错误码返回"401"时表示"未经授权"，造成的原因有：未使用或使用的token不正确；使用的token已经超时失效。 </td>
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
/// 人脸搜索
curl -X POST \
  http://ai.heclouds.com:9090/v1/aiApi/picture/FACE_RECO_LIB \
  -H 'Cache-Control: no-cache' \
  -H 'Content-Type: application/json' \
  -H 'Login-Token: 请自行替换Login-Token' \
  -d '{
  "param":"123456789098765432,0.7"
  "picture": ["请替换图片(base64编码的图片数据)"]
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
 * 人脸搜索
 */
public class FaceLibReco {

    public static void main(String[] agrs){
        //人脸搜索
        faceLibReco(LoginToken.loginToken());
    }
    /**
     * 下载工具包
     * http://open.iot.10086.cn/ai/code/java.zip
     */
    public static void faceLibReco(String loginToken ) {
        String path = "http://ai.heclouds.com:9090/v1/aiApi/picture/FACE_RECO_LIB";

        //方式一：网络图片
        String imgURL = "https://ss3.bdstatic.com/70cFv8Sh_Q1YnxGkpoWK1HF6hhy/it/u=364607011,3159450266&fm=27&gp=0.jpg";
        String pic1 = Base64Img.GetImageStrFromUrl(imgURL);
        //方式二：本地读数图片
        //String pic1 = Base64Img.GetImageStrFromPath("【本地图片文件】");
        String[] value = {pic1};
        //图片信息
        Map<String, Object> params = new HashMap<>();
        params.put("param", "578631713182187520,0.7"); //人脸库ID（在OneNET AI平台的“控制台”中创建“人脸库”后该人脸库的ID），0.x-相似度阈值（英文逗号分隔，不传默认为0.6）
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

url = 'http://ai.heclouds.com:9090/v1/aiApi/picture/FACE_RECO_LIB'
headers ={
    'Content-Type':'application/json',
    'Login-Token':'xxxxxxxxxxxxxxxxx(用户鉴权接口返回结果loginToken)'
    }

faceLibId = '123456789098765432,0.7'
file = open('用户上传图片位置','rb')
str = base64.b64encode(file.read()).decode()
file.close()
data = {'param':faceLibId,'picture':[str]}
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
	//图片路径
	string picPath;
	//图片库id
	string picID;
	//算法相似度阈值
	string threshold;
	do
	{
#if defined (WIN32)
		//待匹配的图片
		picPath = "testData/1.jpeg";
		//传入库id，请替换成自己的图片库id
		picID = "648883658718969856";
		//传入相似度阈值
		threshold = "0.6";
#elif defined(__linux__)
		if (argc < 4) {
			cout << "param error!  run like this: " << endl << "./OneNETAiApi testData/1.jpeg  648883658718969856 0.7" << endl;
			break;
		}
		picPath = argv[1];
		picID = argv[2];
		threshold = argv[3];
#endif
		//登陆获取token
		if (!loginToken(result, &aiApiRequest, account, password)) {
			cout << "login failed,result is: " << result << endl;
			break;
		}
		IFEMPTYBRREAK(result.empty());
		token = result;
		cout << "login success,token is: " << token << endl;
		//执行1:N人脸搜索api请求
		if (!oneToNFaceSearch(result, &aiApiRequest, token, picPath, picID+","+threshold)) {
			cout << "faceSearch failed,result is: " << result << endl;
			break;
		}
		cout << "\n faceSearch result :" << result << endl;
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

        //人脸搜索功能
        //注意：需要引用外部LitJson和RestSharp库

        static void Main(string[] args)
        {
            var token = "";//请用户通过用户鉴权接口获取token
            string paramStr = "123456789098765432,0.7"; //人脸库ID（在OneNET AI平台的“控制台”中创建“人脸库”后该人脸库的ID），0.x-相似度阈值（英文逗号分隔，不传默认为0.6）
            string sFilePath = "D:\\OneNETdiskDownload\\test.jpg"; //图片文件路径
            var client = new RestClient("http://ai.heclouds.com:9090/v1/aiApi/picture/FACE_RECO_LIB");
            var request = new RestRequest(Method.POST);
            request.AddHeader("Login-Token", token);
            request.AddHeader("cache-control", "no-cache");
            request.AddHeader("content-type", "application/json");


            Byte[] bt = File.ReadAllBytes(sFilePath);
            string sPicture = Convert.ToBase64String(bt);
            JsonData jd = new JsonData();
            jd["param"] = paramStr;
            jd["picture"] = new JsonData();
            jd["picture"].Add(sPicture);
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
*desc:人脸搜索
*version：1.0
*time：2019-05-17
*/
const http = require('http');//引入http模块,用于使用HTTP服务器与客户端
const fs = require('fs');//引入fs模块，用于与文件系统进行交互
const mineType = require('mime-types');//需要安装模块“mime-types”，安装方法：npm install mime-types
let paramStr = '123456789098765432,0.7';//人脸库ID（在OneNET AI平台的“控制台”中创建“人脸库”后该人脸库的ID），0.x-相似度阈值（英文逗号分隔，不传默认为0.6）
let filePath = 'D:/mydownload/renlian3.jpg';//用户用于人脸搜索的图片路径
let data = fs.readFileSync(filePath);//读取文件
data = Buffer.from(data).toString('base64');//转换为“base64”格式
let base64Data = 'data:' + mineType.lookup(filePath) + ';base64,' + data;//补充完整图片信息
console.log(base64Data);
const loginToken = 'KEFxABCxKUVzO0F1*Ua2OER4O0R0*EABCEFxfFRxKUVzO0F1*Ua2OER4O0R0*EJAU2LLS1W*Um_KQUF2K0F4KlV6K0FA*Ea1KEBAKUV0KUiyKlK0KU1yQUR0OERyKlB3QUF3KUR3';//用户鉴权接口返回结果loginToken,此处仅作为示例
//请求配置信息
const options = {
    host: 'ai.heclouds.com',//IP地址
    port: 9090,//端口号
    path: '/v1/aiApi/picture/FACE_RECO_LIB',//请求路径
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
  "param":paramStr,
  "picture":[base64Data]
};
httpreq.write(JSON.stringify(requestBody));// 写入数据到请求主体
httpreq.end();//结束发送请求
```

