# 视频浓缩

## 功能介绍

接口能力:对监控视频进行自定义活动目标提取、轨迹聚类分析、视频智能浓缩，将同一空间不同时刻的多目标活动“聚集”重排在较短的时序区间进行展现，过滤冗余无用内容但不丢失原视频语义信息；

业务应用：安防监控、海量视频录像浓缩录入、事后分析检索及核查；

场景限制：针对定点监控场景，目前自定义检测目标支持人和小汽车，暂不支持其他活动目标提取；

输入要求：

​               视频格式：avi、mp4；

​               文件大小：1M≤X≤100M；

​               视频时长：视频长度不超过1分钟。

## API调用方式
<table>
<tr>
	<th width="20%">请求方式</th>
	<th>POST</th>
</tr>
<tr>
	<td>url</td>
	<td>http://ai.heclouds.com:9090/zuul/v1/aiApi/video/concentration</td>
</tr>
<tr>
	<td>http-header</td>
	<td>Login-Token: xxxxxxxxxxxxxxxxx(用户鉴权接口返回结果loginToken )<br/>
Content-Type: multipart/form-data</td>
</tr>
<tr>
	<td>request-body</td>
    <td>file  //视频文件<br/>
url   //视频源网络地址<br/>
file与url指定一个即可，当两者同时存在时，url优先有效</td>
</tr>
<tr>
    <td>成功返回结果</td>
    <td>{<br/>
	&nbsp;&nbsp;&nbsp;&nbsp;"stateCode":"0x0000",	//结果状态码，16进制。"0x0000":成功;"0x240B":调用次数超过最大限制;"0x240C":调用频率过快;<br/>
	&nbsp;&nbsp;&nbsp;&nbsp;"message":"success",	//返回信息<br/>
	&nbsp;&nbsp;&nbsp;&nbsp;"data":"String"    //查询id<br/>
}<br/>
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
// 视频浓缩，文件上传
curl -X POST \
  http://ai.heclouds.com:9090/zuul/v1/aiApi/video/concentration \
  -H 'Cache-Control: no-cache' \
  -H 'Login-Token: 请自行替换Login-Token' \
  -H 'content-type: multipart/form-data; boundary=----WebKitFormBoundary7MA4YWxkTrZu0gW' \
  -F 'file=@C:\Users\Administrator\Pictures\剪辑视频\atrium.mp4'
```
<span id="Java">
Java示例如下：

```java
import java.util.Map;
import java.util.concurrent.TimeUnit;

import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import com.squareup.okhttp.MediaType;
import com.squareup.okhttp.OkHttpClient;
import com.squareup.okhttp.Request;
import com.squareup.okhttp.RequestBody;
import com.squareup.okhttp.Response;

/**
 * 视频浓缩
 */
public class MotionDetection {

    public static void main(String[] agrs){
        //视频浓缩
        String resultId = motionDetection();
    }


    /**
     * 下载工具包
     * http://open.iot.10086.cn/ai/code/java.zip
     */
    private static String  motionDetection() {
        //服务地址
        String path = "http://ai.heclouds.com:9090/zuul/v1/aiApi/video/concentration";
        //视频地址、http地址二选一：优先级：videoHttpPath>videoPath
        String videoPath = "D:\\DOCUMENT\\numerical-analysis-system\\doc\\视频浓缩\\atrium.mp4";
        String videoHttpPath = "http://172.19.12.138:7000/v1/AUTH_test/yzx/demoVideo/video-1?temp_url_sig=4fb1bf6ad4897174b95d78e8c7fdb1674a11e166&temp_url_expires=1532079013";
        try {
            String loginToken = "【获取loginToken】";

            OkHttpClient client = new OkHttpClient();
            client.setConnectTimeout(20L, TimeUnit.MINUTES);
            client.setReadTimeout(20L, TimeUnit.MINUTES);
            MediaType mediaType = MediaType.parse("multipart/form-data; boundary=----WebKitFormBoundary7MA4YWxkTrZu0gW");
            StringBuilder sb =  new StringBuilder("------WebKitFormBoundary7MA4YWxkTrZu0gW\r\n");
            sb.append("Content-Disposition: form-data; name=\"file\";filename=")
                    .append(videoPath)
                    .append("\r\n")
                    .append("Content-Type: video/mp4")
                    .append("\r\n\r\n\r\n------WebKitFormBoundary7MA4YWxkTrZu0gW")
                    .append("\r\n")
                    .append("Content-Disposition: form-data; name=\"url\"")
                    .append("\r\n\r\n")
                    .append(videoHttpPath)
                    .append("\r\n")
                    .append("------WebKitFormBoundary7MA4YWxkTrZu0gW--");

            //构造请求信息
            RequestBody body = RequestBody.create(mediaType, sb.toString());
            Request request = new Request.Builder()
                    .url(path)
                    .post(body)
                    .addHeader("content-type", "multipart/form-data; boundary=----WebKitFormBoundary7MA4YWxkTrZu0gW")
                    .addHeader("login-token", loginToken)
                    .addHeader("cache-control", "no-cache")
                    .build();
            Response response = client.newCall(request).execute();

            String result = response.body().string();
            System.out.println(result);
            Gson gson = new GsonBuilder().create();
            Map map = gson.fromJson(result, Map.class);
            String resultId = map.get("data") == null ? "" : map.get("data").toString();
            System.out.println("resultId====:"+resultId);
            return resultId;
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

url = 'http://ai.heclouds.com:9090/zuul/v1/aiApi/video/concentration'
headers ={
    "Cache-Control":"no-cache",
    'Login-Token': '用户Token'
    }

file = open('上传视频位置','rb')
files = {'file':file}
req = requests.post(url,files=files,headers=headers)

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
	//视频路径
	string videoPath;
	//查询id
	string searchID;
	do
	{
		//给视频路径赋值
#if defined (WIN32)
		videoPath = "testData/traffic.mp4";
#elif defined(__linux__)
		if (argc < 2) {
			cout << "param error!  run like this: " << endl << "./OneNETAiApi testData/traffic.mp4" << endl;
			break;
		}
		videoPath = argv[1];
#endif
		//登陆获取token
		if (!loginToken(result, &aiApiRequest, account, password)) {
			cout << "login failed,result is: " << result << endl;
			break;
		}
		IFEMPTYBRREAK(result.empty());
		token = result;
		cout << "login success,token is: " << token << endl;
		cout << "\n uploading the video,please wait for a while..." << endl;
		//执行视频浓缩 api请求
		if (!videoConTraFunc(result, &aiApiRequest, token, videoPath)) {
			cout << "videoConTra failed,result is: " << result << endl;
			break;
		}
		IFEMPTYBRREAK(result.empty());
		searchID = result;
		cout << "\n videoConTra success,searchID is: " << searchID << endl;

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

        //视频浓缩功能
        //注意：需要引用外部LitJson和RestSharp库,

        static void Main(string[] args)
        {
            var token = "";//请用户通过用户鉴权接口获取token
            var client = new RestClient("http://ai.heclouds.com:9090/zuul/v1/aiApi/video/concentration");
            var request = new RestRequest(Method.POST);
            request.AddHeader("Login-Token", token);
            request.AddHeader("Cache-Control", "no-cache");
            request.AddHeader("Content-Type", "multipart/form-data; boundary=----WebKitFormBoundary7MA4YWxkTrZu0gW");
            request.AddFile("file", "D:\\OneNETdiskDownload\\atrium.mp4");
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
*desc:视频浓缩
*version：1.0
*time：2019-11-20
*/
const http = require('http');//引入http模块,用于使用HTTP服务器与客户端
const fs = require('fs');//引入fs模块，用于与文件系统进行交互
const path = require('path');//引入path模块，用于处理文件路径
let file = 'D:/mydownload/movie.mp4';//视频路径，file与url指定一个即可，当两者同时存在时，url优先有效
let url = '';//url必须声明，不使用url时其值可以为：“null”或“false”或“''”
//url = 'http://ip:port/demoVideo/video-2?temp_url_expires=1531324505';//视频源网络地址file与url指定一个即可，当两者同时存在时，url优先有效
const loginToken = 'KEFxfUBxKUVzF100*Ua2OER4O0R0*EJABCFxfUBxKUVzO0F1*Ua2OER4O0R0*EJAU2LLS1W*Um_DCEF2K0F4*UF4OEFA*Ea1KEBAKUV0KUi4*EF1KU1yQUizKUB1KlB2KE1yK0m2*R==';//用户鉴权接口返回结果中的“loginToken”,此处仅为示例
//请求配置信息
const options = {
    host: 'ai.heclouds.com',//IP地址
    port: 9090,//端口号
    path: '/zuul/v1/aiApi/video/concentration',//请求路径
    method: 'POST',//请求类型
    headers:{
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
//模拟form-data发送数据
var boundaryKey = Math.random().toString(16);
var endData = '\r\n----' + boundaryKey + '--';
if(typeof url!=undefined&&url) {
    var content = "\r\n----" + boundaryKey + "\r\n"
        +"Content-Disposition: form-data; "
        +"name=\"url\"\r\n\r\n"+url;
    var contentBinary = Buffer.from(content, 'utf-8');//当编码为ascii时，中文会乱码。
    var contentLength = 0;
    contentLength += contentBinary.length;
    httpreq.setHeader('Content-Type', 'multipart/form-data; boundary=--' + boundaryKey);
    httpreq.setHeader('Content-Length', contentLength + Buffer.byteLength(endData));
    httpreq.write(contentBinary);//发送数据
    httpreq.end(endData);
}else if(typeof file!=undefined&&file){
    var content = "\r\n----" + boundaryKey + "\r\n"
        +"Content-Type: application/octet-stream\r\n"
        +"Content-Disposition: form-data; "
        +"name=\"file\"; "
        +"filename=\"" + path.basename(file) + "\"\r\n"
        + "Content-Transfer-Encoding: binary\r\n\r\n";
    var contentBinary = Buffer.from(content, 'utf-8');//当编码为ascii时，中文会乱码。
    var contentLength = 0;
    var stat = fs.statSync(file);
    contentLength += contentBinary.length;
    contentLength += stat.size;
    httpreq.setHeader('Content-Type', 'multipart/form-data; boundary=--' + boundaryKey);
    httpreq.setHeader('Content-Length', contentLength + Buffer.byteLength(endData));
    httpreq.write(contentBinary);//发送数据
    var fileStream = fs.createReadStream(file, {bufferSize : 4 * 1024});
    fileStream.pipe(httpreq, {end: false});//发送数据
    fileStream.on('end', function() {
        httpreq.end(endData);
    });
}
```

## 视频浓缩结果查询
<table>
<tr>
	<th width="20%">请求方式</th>
	<th>GET</th>
</tr>
<tr>
	<td>url</td>
	<td>	http://ai.heclouds.com:9090/v1/aiApi/arithmetic/VIDEO_CONCENTRATION/results/{resultId}/current</td>
</tr>
<tr>
	<td>http-header</td>
	<td>Login-Token: xxxxxxxxxxxxxxxxx(用户鉴权接口返回结果loginToken )<br/>
Content-Type:application/json</td>
</tr>
<tr>
	<td>request-body</td>
    <td></td>
</tr>
<tr>
	<td>path-variable</td>
    <td>resultId    //上一步骤中返回的查询id</td>
</tr>
<tr>
    <td>成功返回结果</td>
    <td>{<br/>
	&nbsp;&nbsp;&nbsp;&nbsp;"stateCode": "0x0000",	//结果状态码，16进制。"0x0000":成功;<br/>
	&nbsp;&nbsp;&nbsp;&nbsp;"message": "success",<br/>
	&nbsp;&nbsp;&nbsp;&nbsp;"data": {<br/>
		&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"result": ["url"],   //视频地址<br/>
		&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"status":"processing"   //检测状态：处理中-processing，处理完-finish<br/>
	&nbsp;&nbsp;&nbsp;&nbsp;}<br/>
}<br/>
注意：<br/>
http错误码返回"401"时表示"未经授权"，造成的原因有：未使用或使用的token不正确；使用的token已经超时失效。
</td>
</tr> 
</table>

## 请求示例
[bash](#bash1)	 	
[Java](#Java1)	 		
[Python](#Python1)	 		
[C++](#C++1)			
[C#](#C#1)		
[Node](#Node1)	

<span id="bash1">
bash示例如下：

```bash
// 视频浓缩，结果查询
curl -X GET \
  http://ai.heclouds.com:9090/v1/aiApi/arithmetic/VIDEO_CONCENTRATION/results/{请替换为查询id}/current \
  -H 'Cache-Control: no-cache' \
  -H 'Login-Token: 请自行替换Login-Token'
```
<span id="Java1">
Java示例如下：

```java
import com.mobile.analysis.HttpUtil;

/**
 * 视频浓缩结果查询
 */
public class MotionDetectionQuery {

    public static void main(String[] agrs){
        //视频浓缩：先进行视频浓缩视频上传，获取返回的结果id
        String resultId = "【motionDetection()】";
        //结果查询
        motionDetectionResult(resultId);

    }

    /**
     * 下载工具包
     * http://open.iot.10086.cn/ai/code/java.zip
     */
    private static void motionDetectionResult(String resultId) {
        //服务地址
        String path = "http://ai.heclouds.com:9090/v1/aiApi/arithmetic/VIDEO_CONCENTRATION/results/"+resultId+"/current";
        String loginToken = "【获取loginToken】";
        try {
            //调用
            Thread.sleep(1000*2);
            String result = HttpUtil.get(path, loginToken);
            System.out.println("result:" + result);
            //当finish 为视频浓缩完成
            if(result.contains("\"status\":\"processing\"")){
                    motionDetectionResult(resultId);
            }

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

}
```
<span id="Python1">
Python示例如下：

```python
import requests

id = '010u0015313842143597418_1f069c1eeabd4276a61913f6ac47afe9'  # 查询id
mode = 'current'

url = 'http://ai.heclouds.com:9090/v1/aiApi/arithmetic/VIDEO_CONCENTRATION/results/{}/{}'.format(id,mode)
headers = {
    'Login-Token': '用户Token'
}


req = requests.get(url,headers=headers)
print(req.text)
```
<span id="C++1">
C++示例如下：

```C++
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
	//视频路径
	string videoPath;
	//查询id
	string searchID;
	//算法查询结束状态
	string finishStatus = "";
	do
	{
		//给视频路径赋值
#if defined (WIN32)
		videoPath = "testData/traffic.mp4";
#elif defined(__linux__)
		if (argc < 2) {
			cout << "param error!  run like this: " << endl << "./OneNETAiApi testData/traffic.mp4" << endl;
			break;
		}
		videoPath = argv[1];
#endif
		//登陆获取token
		if (!loginToken(result, &aiApiRequest, account, password)) {
			cout << "login failed,result is: " << result << endl;
			break;
		}
		IFEMPTYBRREAK(result.empty());
		token = result;
		cout << "login success,token is: " << token << endl;
		cout << "\n uploading the video,please wait for a while..." << endl;
		//执行视频浓缩 api请求
		if (!videoConTraFunc(result, &aiApiRequest, token, videoPath)) {
			cout << "videoConTra failed,result is: " << result << endl;
			break;
		}
		IFEMPTYBRREAK(result.empty());
		searchID = result;
		//从json中解析结果数据的对象
		apiData<videoConTraSearchData> SearchData;
		//查询直到返回finish状态
		while (finishStatus.compare("finish"))
		{
			this_thread::sleep_for(chrono::milliseconds(1500));
			//执行视频浓缩查询 api请求
			if (!videoConTraSearchFunc(result, &aiApiRequest, token, searchID)) {
				cout << "videoConTraSearch failed,result is: " << result << endl;
				continue;
			}
			//拼接 存储到本地照片的名字
			try
			{
				SearchData.FromString(result);
				finishStatus = SearchData.data.status;

			}
			catch (...)
			{

			}
			cout << "\n videoConTraSearch result: " << result << endl;
		}
	} while (false);
	return 0;
}
```
<span id="C#1">
C#示例如下：

```C#
using System;
using System.IO;
using LitJson;
using RestSharp;

namespace ConsoleApplication1
{
    class Program
    {

        //视频浓缩结果查询功能
        //注意：需要引用外部LitJson和RestSharp库,

        static void Main(string[] args)
        {
            var token = "";//请用户通过用户鉴权接口获取token
            var client = new RestClient("http://ai.heclouds.com:9090/v1/aiApi/arithmetic/VIDEO_CONCENTRATION/results/123_b101033b6a484621963323ad508f627d/current");//123_b101033b6a484621963323ad508f627d为视频浓缩成功时返回的查询id
            var request = new RestRequest(Method.GET);
            request.AddHeader("Login-Token", token);
            request.AddHeader("Cache-Control", "no-cache");
            request.AddHeader("Content-Type", "application/json");
            IRestResponse response = client.Execute(request);
            Console.WriteLine(response.Content);
            Console.ReadKey();
        }

    }
}
```
<span id="Node1">
Node示例如下：

```node
/*
*desc:视频浓缩结果查询
*version：1.0
*time：2019-11-20
*/
const http = require('http');//引入http模块,用于使用HTTP服务器与客户端
const loginToken = 'KEFxfUBxABCzO0F1*Ua2OER4O0R0*EJABCFxfUBxKUVzO0F1*Ua2OER4O0R0*EJAU2LLS1W*Um_KQUF2K0F4KlV6K0FA*Ea1KEBAKUV0KUiyKlK0KU1yQUR0OERyKlB3QUF3KUR3';//用户鉴权接口返回结果中的“loginToken”,此处仅为示例
const resultId = '010u0015271496544774321_1741d8278a604c39a34ab73cfeeb9d0f';//用视频浓缩接口返回结果中的查询id,此处仅为示例
//请求配置信息
const options = {
    host: 'ai.heclouds.com',//IP地址
    port: 9090,//端口号
    path: '/v1/aiApi/arithmetic/VIDEO_CONCENTRATION/results/'+resultId+'/current',//请求路径
    method: 'GET',//请求类型
    headers:{
        'Content-Type':'application/json',
        'Login-Token': loginToken
    }
};
console.log(options.path);
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
httpreq.end();
```

## Postman工具使用

Postman工具下载地址：https://www.getpostman.com/apps

工具使用方法如下：

第一步：

![](/image/postman1.png)

第二步：

![](/image/postman2.png)

第三步：

![](/image/postman3.png)

第四步：

![](/image/postman4.png)