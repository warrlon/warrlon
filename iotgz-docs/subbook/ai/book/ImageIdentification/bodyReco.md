# 人体检测

## 功能介绍

接口能力: 检测并定位图片中无遮挡的人体，返回人体位置和置信度，可实现多人体检测；

图片格式：现支持PNG、JPG、JPEG、BMP,不支持GIF图片；

图片大小：图片中识别的人体不被遮挡，人体区域高度120像素以上，宽度80像素以上；上传图片大小不超过2M；

业务应用：智慧零售人流量统计、人体跟踪、安防监控。

## API调用方式
<table>
<tr>
	<th width="20%">请求方式</th>
	<th>POST</th>
</tr>
<tr>
	<td>url</td>
	<td>http://ai.heclouds.com:9090/v1/aiApi/picture/BODY_RECO</td>
</tr>
<tr>
	<td>http-header</td>
	<td>Login-Token: xxxxxxxxxxxxxxxxx(用户鉴权接口返回结果loginToken )<br/>
Content-Type:application/json</td>
</tr>
<tr>
	<td>request-body</td>
    <td>{<br/>
	&nbsp;&nbsp;&nbsp;&nbsp;"picture":["String"]  //一张图片的base64图片编码<br/>
}</td>
</tr>
<tr>
    <td>成功返回结果</td>
    <td>{<br/>
	&nbsp;&nbsp;&nbsp;&nbsp;"stateCode":"0x0000",	//结果状态码，16进制。"0x0000":成功;"0x240B":调用次数超过最大限制;"0x240C":调用频率过快;<br/>
	&nbsp;&nbsp;&nbsp;&nbsp;"message":"success",	//返回信息<br/>
	&nbsp;&nbsp;&nbsp;&nbsp;"data":"String"    //人体的位置，置信度（多个人体目标以“;”分隔）<br/>
}<br/>
例如:<br/>
  "150,26,464,998,0.998191"    //  人体在图片中矩形框的位置为“150,26,464,998”，置信度为“0.998191”；多个人体目标以“;”分隔。<br/>
注意：<br/>
http错误码返回"401"时表示"未经授权"，造成的原因有：未使用或使用的token不正确；使用的token已经超时失效。</td>
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
// 人体检测
curl -X POST \
  http://ai.heclouds.com:9090/v1/aiApi/picture/BODY_RECO \
  -H 'Cache-Control: no-cache' \
  -H 'Content-Type: application/json' \
  -H 'Login-Token: 请自行替换Login-Token' \
  -d '{
 "picture": ["请替换图片(base64编码的图片数据)"]
}
'
```
<span id="Java">
Java示例如下：

```java
package ocm.mobile.test;

import java.util.HashMap;
import java.util.Map;

import com.mobile.analysis.Base64Img;
import com.mobile.analysis.HttpUtil;

public class BodyCheck {
	public static void main(String[] agrs){
        //人体检测
		bodyCheck();
    }

    /**
     * 下载工具包
     * http://open.iot.10086.cn/ai/code/java.zip
     */
    private static void bodyCheck() {
        String path = "http://ai.heclouds.com:9090/v1/aiApi/picture/BODY_RECO";
        String loginToken = "【获取loginToken】";

        //图片信息
        Map<String, Object> params = new HashMap<>();
//        //方式一
//        String imgURL = "https://ss1.bdstatic.com/70cFuXSh_Q1YnxGkpoWK1HF6hhy/it/u=3469321769,440317554&fm=27&gp=0.jpg";
//        String pic1 = Base64Img.GetImageStrFromUrl(imgURL);
        //方式二
        String pic1 = Base64Img.GetImageStrFromPath("本地文件地址");
        String[] value = {pic1};
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

url = 'http://ai.heclouds.com:9090/v1/aiApi/picture/BODY_RECO'
headers ={
    'Content-Type':'application/json',
    'Login-Token':'xxxxxxxxxxxxxxxxx(用户鉴权接口返回结果loginToken)'
    }

file = open('用户上传图片位置','rb')
str = base64.b64encode(file.read()).decode()
file.close()
data = {'picture':[str]}
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
	do
	{
		//给图片路径赋值
#if defined (WIN32)
		picPath = "testData/1.jpeg";
#elif defined(__linux__)
		if (argc < 2) {
			cout << "param error!  run like this: " << endl << "./OneNETAiApi testData/1.jpeg" << endl;
			break;
		}
		picPath = argv[1];
#endif
		//登陆获取token
		if (!loginToken(result, &aiApiRequest, account, password)) {
			cout << "login failed,result is: " << result << endl;
			break;
		}
		IFEMPTYBRREAK(result.empty());
		token = result;
		cout << "login success,token is: " << token << endl;
		//执行人体检测api请求
		if (!personDetect(result, &aiApiRequest, token, picPath)) {
			cout << "person detect failed,result is: " << result << endl;
			break;
		}
		cout << "\n person detect result :" << result << endl;
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

        //人体检测功能
        //注意：需要引用外部LitJson和RestSharp库

        static void Main(string[] args)
        {
            var token = "";//请用户通过用户鉴权接口获取token
            string sFilePath = "D:\\BaiduNetdiskDownload\\test.png"; //图片文件路径
            var client = new RestClient("http://ai.heclouds.com:9090/v1/aiApi/picture/BODY_RECO");
            var request = new RestRequest(Method.POST);
            request.AddHeader("Login-Token", token);
            request.AddHeader("cache-control", "no-cache");
            request.AddHeader("content-type", "application/json");


            Byte[] bt = File.ReadAllBytes(sFilePath);
            string sPicture = Convert.ToBase64String(bt);
            JsonData jd = new JsonData();
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
*desc:人体检测
*version：1.0
*time：2019-11-05
*/
const http = require('http');//引入http模块,用于使用HTTP服务器与客户端
const fs = require('fs');//引入fs模块，用于与文件系统进行交互
const mineType = require('mime-types');//需要安装模块“mime-types”，安装方法：npm install mime-types
let filePath = 'D:/mydownload/aaa.jpg';//图片路径
let data = fs.readFileSync(filePath);//读取文件
data = Buffer.from(data).toString('base64');//转换为“base64”格式
let base64Data = 'data:' + mineType.lookup(filePath) + ';base64,' + data;//补充完整图片信息
console.log(base64Data);
const loginToken = 'KEFxABCxKUVzO0F1*Ua2OER4O0R0*EABCEFxfUBxKUVzO0F1*Ua2OER4O0R0*EJAU2LLS1W*Um_KQUF2K0F4KlV6K0FA*Ea1KEBAKUV0KUiyKlK0KU1yQUR0OERyKlB3QUF3KUR3';//用户鉴权接口返回结果loginToken,此处仅作为示例
//请求配置信息
const options = {
    host: 'ai.heclouds.com',//IP地址
    port: 9090,//端口号
    path: '/v1/aiApi/picture/BODY_RECO',//请求路径
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
    "picture":[base64Data]
};
httpreq.write(JSON.stringify(requestBody));// 写入数据到请求主体
httpreq.end();//结束发送请求
```

