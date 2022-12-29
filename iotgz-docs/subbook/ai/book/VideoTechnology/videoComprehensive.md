# 视频分析

## 功能介绍

接口能力:基于视频流的AI能力，对视频进行多维度分析，目前已支持视频图像内容评审、车牌识别、火灾检测、人体检测；

业务应用：基于视频流的图像内容评审、车牌识别、火灾检测、人体检测。

## API调用方式
<table>
<tr>
	<th width="20%">请求方式</th>
	<th>POST</th>
</tr>
<tr>
	<td>url</td>
	<td>http://ai.heclouds.com:9090/v1/aiApi/video/comprehensive/check</td>
</tr>
<tr>
	<td>http-header</td>
	<td>Login-Token: xxxxxxxxxxxxxxxxx(用户鉴权接口返回结果loginToken )<br/>
Content-Type: application/json</td>
</tr>
<tr>
	<td>request-body</td>
    <td>{<br/>
	&nbsp;&nbsp;&nbsp;&nbsp;"checkTarget":"String",   //检测目标:<br/>
		&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;IDENTIFY_PORN——图像内容测评<br/>
		&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;NUMBER_PLATE_RECOGNITION——车牌识别<br/>
		&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;FIRE_DETECTION——火灾检测<br/>
		&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;BODY_RECO——人体检测<br/>
	&nbsp;&nbsp;&nbsp;&nbsp;"sourceUrl":"String"    //指定检测视频地址，如果需要手动推流（使用返回结果中的“pushUrl”进行推流），则此参数为空或不传<br/>
					&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;//推流工具可以使用OBS或者FFmpeg或其它推流工具<br/>
}  </td>
</tr>
<tr>
    <td>成功返回结果</td>
    <td>{<br/>
	&nbsp;&nbsp;&nbsp;&nbsp;"stateCode": "0x0000",	//结果状态码，16进制。"0x0000":成功;<br/>
	&nbsp;&nbsp;&nbsp;&nbsp;"message": "success",<br/>
	&nbsp;&nbsp;&nbsp;&nbsp;"data": {<br/>
		&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"pushUrl":"String",    //推流地址，通过此url推送视频流到服务器<br/>
		&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"taskId":"String"  //根据此id调用结果查询接口对结果进行查询<br/>
	&nbsp;&nbsp;&nbsp;&nbsp;}<br/>
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
// 视频分析
curl --request POST \
  --url http://ai.heclouds.com:9090/v1/aiApi/video/comprehensive/check \
  --header 'cache-control: no-cache' \
  --header 'content-type: application/json' \
  --header 'login-token: 【Login-Token】' \
  --data '{\n	"checkTarget":"NUMBER_PLATE_RECOGNITION",\n	"sourceUrl":"【可访问的视频地址】"\n}'
```
<span id="Java">
Java示例如下：

```java
package ocm.mobile.test;

import java.util.HashMap;
import java.util.Map;

import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import com.mobile.analysis.HttpUtil;

public class VideoCheck {
	public static void main(String[] agrs){
        //视频分析检测
		videoCheck();
    }

    /**
     * 下载工具包
     * http://open.iot.10086.cn/ai/code/java.zip
     */
    private static void videoCheck() {
        String path = "http://ai.heclouds.com:9090/v1/aiApi/video/comprehensive/check";
        String loginToken = "【获取loginToken】";

        Map<String, Object> params = new HashMap<>();
        // IDENTIFY_PORN 图像内容评测
        // NUMBER_PLATE_RECOGNITION 车牌识别
        // FIRE_DETECTION 火灾检测
        // BODY_RECO 人体检测
        params.put("checkTarget", "NUMBER_PLATE_RECOGNITION");
        // 指定检测视频地址，如果需要手动推流，则此参数为空或不传
        params.put("sourceUrl", "【可访问视频的地址】");
        try {
            //调用
            String result = HttpUtil.post(path, loginToken, params);
            System.out.println("result:" + result);

            Gson gson = new GsonBuilder().create();
            Map map = gson.fromJson(result, Map.class);
            String data = map.get("data") == null ? "" : map.get("data").toString();
            // data中包含pushUrl和taskId
            System.out.println("data====:"+data);
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

url = 'http://ai.heclouds.com:9090/v1/aiApi/video/comprehensive/check'
headers ={
    'Content-Type':'application/json',
    'Login-Token': '【获取loginToken】'
    }
data = {
    'checkTarget':'NUMBER_PLATE_RECOGNITION',
    'sourceUrl':'【可访问视频的地址】'
}
req = requests.post(url,headers=headers,data=json.dumps(data))

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
	//算法类型
	string algotype;
	//http视频地址，置空则由用户自己推流
	string sourceUrl;
	//查询id
	string searchID;
	//推流地址
	string pushStreamURl;
	do
	{
#if defined (WIN32)
		algotype = getAlgoType(porn);
		//可以传入http视频的址，也可以置空
		sourceUrl = "";
#elif defined(__linux__)
		if (argc < 3) {
			cout << "param error!  run like this: " << endl << "./OneNETAiApi 1 \"\" " << endl;
			cout << "1:porn detect " << endl;
			cout << "2:car plate detect" << endl;
			cout << "3:fire detect" << endl;
			cout << "4:person detect" << endl;
			break;
		}
		algotype = getAlgoType(std::stoi(argv[1]));
		sourceUrl = argv[2];
#endif
		//登陆获取token
		if (!loginToken(result, &aiApiRequest, account, password)) {
			cout << "login failed,result is: " << result << endl;
			break;
		}
		IFEMPTYBRREAK(result.empty());
		token = result;
		cout << "login success,token is: " << token << endl;

		//执行视频分析 api请求
		if (!videoCheckFunc(result, &aiApiRequest, token, algotype, sourceUrl)) {
			cout << "videoCheck failed,result is: " << result << endl;
			break;
		}
		IFEMPTYBRREAK(result.empty());

		//从result中解析查询id和推流地址
		apiData<videoCheckData> videoCheckData;
		TRYBRREAK(videoCheckData.FromString(result));
		searchID = videoCheckData.data.taskId;
		pushStreamURl = videoCheckData.data.pushUrl;
		cout << "searchID:" << searchID << endl;
		//获取到该地址后，请向该地址推流，以便后续查询到结果
		cout << "pushStreamURL:" << pushStreamURl << endl;
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

        //视频分析功能
        //注意：需要引用外部LitJson和RestSharp库,

        static void Main(string[] args)
        {
            var token = "";//请用户通过用户鉴权接口获取token
            var client = new RestClient("http://ai.heclouds.com:9090/v1/aiApi/video/comprehensive/check");
            var request = new RestRequest(Method.POST);
            request.AddHeader("Login-Token", token);
            request.AddHeader("cache-control", "no-cache");
            request.AddHeader("content-type", "application/json");

            JsonData jd = new JsonData();
            jd["checkTarget"] = "IDENTIFY_PORN";//检测目标:IDENTIFY_PORN——图像内容测评;NUMBER_PLATE_RECOGNITION——车牌识别;FIRE_DETECTION——火灾检测;BODY_RECO——人体检测
            jd["sourceUrl"] = "https://ip:port/other_files/smart_city.mp4";//指定检测视频地址，如果需要手动推流，则此参数为空或不传
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
*desc:视频分析
*version：1.0
*time：2019-11-18
*/
const http = require('http');//引入http模块,用于使用HTTP服务器与客户端
let checkTarget = 'IDENTIFY_PORN';//检测目标:IDENTIFY_PORN——图像内容测评;NUMBER_PLATE_RECOGNITION——车牌识别;FIRE_DETECTION——火灾检测;BODY_RECO——人体检测
let sourceUrl = 'https://ip:port/other_files/smart_city.mp4';//指定检测视频地址，如果需要手动推流，则此参数为空或不传
const loginToken = 'KEFxABCxKUVzO0F1*Ua2OER4O0R0*EABCEFxfUBxKUVzO0F1*Ua2OER4O0R0*EJAU2LLS1W*Um_KQUF2K0F4KlV6K0FA*Ea1KEBAKUV0KUiyKlK0KU1yQUR0OERyKlB3QUF3KUR3';//用户鉴权接口返回结果loginToken,此处仅作为示例
//请求配置信息
const options = {
    host: 'ai.heclouds.com',//IP地址
    port: 9090,//端口号
    path: '/v1/aiApi/video/comprehensive/check',//请求路径
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
    "checkTarget":checkTarget,
    "sourceUrl":sourceUrl
};
httpreq.write(JSON.stringify(requestBody));// 写入数据到请求主体
httpreq.end();//结束发送请求
```

## 视频分析结果查询
<table>
<tr>
	<th width="20%">请求方式</th>
	<th>GET</th>
</tr>
<tr>
	<td>url</td>
<td>http://ai.heclouds.com:9090/v1/aiApi/arithmetic/VIDEO_CHECK/results/{resultId}/current</td>
</tr>
<tr>
	<td>http-header</td>
	<td>Login-Token: xxxxxxxxxxxxxxxxx(用户鉴权接口返回结果loginToken )<br/>
Content-Type:application/json</td>
</tr>
<tr>
	<td>request-body</td>
    <td> </td>
</tr>
<tr>
	<td>path-variable</td>
    <td>resultId    //上一步骤中返回的查询id </td>
</tr>
<tr>
    <td>成功返回结果</td>
    <td>{<br/>
	&nbsp;&nbsp;&nbsp;&nbsp;"stateCode": "0x0000",	//结果状态码，16进制。"0x0000":成功;<br/>
	&nbsp;&nbsp;&nbsp;&nbsp;"message": "success",<br/>
	&nbsp;&nbsp;&nbsp;&nbsp;"data": {<br/>
		&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"result": [<br/>
			&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"ResultData":"xxxx",    //base64 或存储地址<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"ResultValue": "string",    //结构详见上一步配置的“检测目标”所对应的技术文档中API返回结果参数“data”的说明<br/>
			&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}<br/>
		&nbsp;&nbsp;&nbsp;&nbsp;],<br/>
		&nbsp;&nbsp;&nbsp;&nbsp;"status":"processing"   //检测状态：处理中-processing，处理完-finish<br/>
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
// 视频分析结果查询
curl --request GET \
  --url http://ai.heclouds.com:9090/v1/aiApi/arithmetic/VIDEO_CHECK/results/【resultId】/current" \
  --header 'cache-control: no-cache' \
  --header 'login-token: 【Login-Token】'
```
<span id="Java1">
Java示例如下：

```java
package ocm.mobile.test;

import com.mobile.analysis.HttpUtil;

public class VideoCheckResult {
	public static void main(String[] agrs){
		 //视频分析检测：先进行视频上传，获取返回的结果id
        String resultId = "【videoCheck()】";
        //视频分析检测结果查询
		videoCheckResult(resultId);
    }

    /**
     * 下载工具包
     * http://open.iot.10086.cn/ai/code/java.zip
     */
    private static void videoCheckResult(String resultId) {
        String path = "http://ai.heclouds.com:9090/v1/aiApi/arithmetic/VIDEO_CHECK/results/"+resultId+"/current";
        String loginToken = "【获取loginToken】";

        try {
            Thread.sleep(1000*2);
            String result = HttpUtil.get(path, loginToken);
            System.out.println("result:" + result);
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

#先进行视频分析，获取返回的结果id
#视频检测结果查询
resultId = "获取的taskId"
url = 'http://ai.heclouds.com:9090/v1/aiApi/arithmetic/VIDEO_CHECK/results/' +resultId+"/current"
headers ={
    'Content-Type':'application/json',
    'Login-Token': '【获取loginToken】',
    }
req = requests.get(url,headers=headers)

print(req.text)
```
<span id="C++1">
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
	//算法类型
	string algotype;
	//http视频地址，置空则由用户自己推流
	string sourceUrl;
	//查询id
	string searchID;
	//推流地址
	string pushStreamURl;
	//算法查询结束状态
	string finishStatus;
	do
	{
#if defined (WIN32)
		algotype = getAlgoType(porn);
		//可以传入http视频的址，亦可置空
		sourceUrl = "";
#elif defined(__linux__)
		if (argc < 3) {
			cout << "param error!  run like this: " << endl << "./OneNETAiApi 1 \"\" " << endl;
			cout << "1:porn detect " << endl;
			cout << "2:car plate detect" << endl;
			cout << "3:fire detect" << endl;
			cout << "4:person detect" << endl;
			break;
		}
		algotype = getAlgoType(std::stoi(argv[1]));
		sourceUrl = argv[2];
#endif
		//登陆获取token
		if (!loginToken(result, &aiApiRequest, account, password)) {
			cout << "login failed,result is: " << result << endl;
			break;
		}
		IFEMPTYBRREAK(result.empty());
		token = result;
		cout << "login success,token is: " << token << endl;

		//执行视频分析 api请求
		if (!videoCheckFunc(result, &aiApiRequest, token, algotype, sourceUrl)) {
			cout << "videoCheck failed,result is: " << result << endl;
			break;
		}
		IFEMPTYBRREAK(result.empty());

		//从result中解析查询id和推流地址
		apiData<videoCheckData> videoCheckData;
		TRYBRREAK(videoCheckData.FromString(result));
		searchID = videoCheckData.data.taskId;
		pushStreamURl = videoCheckData.data.pushUrl;
		//获取到该地址后，请向该地址推流，进行算法计算
		cout << "pushStreamURL:" << pushStreamURl << endl;

		apiData<videoCheckSearchData> videoCheckSearchData;
		//查询直到返回finish状态
		while (finishStatus.compare("finish"))
		{
			this_thread::sleep_for(chrono::milliseconds(1500));
			//执行视频分析查询 api请求
			if (!videoCheckSearchFunc(result, &aiApiRequest, token, searchID)) {
				cout << "videoCheckSearch failed,result is: " << result << endl;
				continue;
			}
			try
			{
				videoCheckSearchData.FromString(result);
				finishStatus = videoCheckSearchData.data.status;
			}
			catch (...)
			{}
      cout << "result: " << result << endl;
		}
	} while (false);
	return 0;
}
```
<span id="C#1">
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

        //视频分析结果查询功能
        //注意：需要引用外部LitJson和RestSharp库,

        static void Main(string[] args)
        {
            var token = "";//请用户通过用户鉴权接口获取token
            var client = new RestClient("http://ai.heclouds.com:9090/v1/aiApi/arithmetic/VIDEO_CHECK/results/123_b101033b6a484621963323ad508f627d/current");//123_b101033b6a484621963323ad508f627d为视频分析成功时返回的查询id“taskId”
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
*desc:视频分析结果查询
*version：1.0
*time：2019-11-18
*/
const http = require('http');//引入http模块,用于使用HTTP服务器与客户端
const loginToken = 'KEFxfUBxABCzO0F1*Ua2OER4O0R0*EJABCFxfUBxKUVzO0F1*Ua2OER4O0R0*EJAU2LLS1W*Um_KQUF2K0F4KlV6K0FA*Ea1KEBAKUV0KUiyKlK0KU1yQUR0OERyKlB3QUF3KUR3';//用户鉴权接口返回结果中的“loginToken”,此处仅为示例
const resultId = '010u0015271496544774321_1741d8278a604c39a34ab73cfeeb9d0f';//用视频分析接口返回结果中的查询id“taskId”,此处仅为示例
//请求配置信息
const options = {
    host: 'ai.heclouds.com',//IP地址
    port: 9090,//端口号
    path: '/v1/aiApi/arithmetic/VIDEO_CHECK/results/'+resultId+'/current',//请求路径
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