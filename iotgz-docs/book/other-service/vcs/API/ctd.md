# 点击拨号

## 点击拨号

请求方式：**POST**

请求地址: https://voice.heclouds.com:8002/v1/onenet/dial/notify

#### HTTP头部


|参数名称|是否必填|参数值|
|:-|:-|:-|
|Authorization|是|[详见鉴权认证](/book/other-service/vcs/API/authentication.md)|
|Content-Type|是|application/json;charset=utf-8|

#### 请求body

<table>
<tr><th width="15%">参数名称</th><th width="12%">类型</th><th width="12%">长度</th><th width="12%">是否必填</th><th>说明</th></tr>
<tr><td>appid</td><td>String</td><td>32</td><td>是</td><td>应用标识<br>由OneNET平台生成</td></tr>
<tr><td>sponsor</td><td>String</td><td>64</td><td>是</td><td>发起呼叫的号码（业务号码）<br>主叫用户的来显号码，由OneNET平台提供<br>号码格式：<br>手机号码格式：MSISDN。示例：8613500000003<br>固话格式：区号+固话。区号0755，固话号码28000003，填写为075528000003</td></tr>
<tr><td>caller</td><td>String</td><td>64</td><td>是</td><td>主叫号码<br>号码格式使用MSISDN，举例8618625150488</td></tr>
<tr><td>callee</td><td>String</td><td>64</td><td>是</td><td>被叫号码<br>号码格式使用MSISDN，举例8618625150488</td></tr>
<tr><td>display</td><td>String</td><td>64</td><td>否</td><td>被叫用户的号显号码<br>如果未携带此参数，被叫用户的来显号码为sponsor<br>如果携带此参数，值只可以与caller（display与caller相同时，caller需要加白名单）或sponsor相同，如果携带为其他号码则无法呼叫，响应报错<br>号码格式：<br>手机号码格式：MSISDN。示例：8613500000003<br>固话格式：区号+固话。区号0755，固话号码28000003，填写为075528000003</td></tr>
<tr><td>notify_url</td><td>String</td><td>512</td><td>否</td><td>用户指定的通知地址（请求方式为POST）<br>如无此字段，则根据OneNET平台配置为准</td></tr>
</table>



#### 请求示例
    POST /v1/ OneNET/dial/notify  HTTP/1.1   
    Content-Type: application/json;charset=utf-8
    Accept: application/json
    Authorization:version=v1&res=onenet_voice%2F3143eba93adb4f35bde98aa31e4e5bbd&et=1568267186&method=sha1&sign=VeSeq%2B6zZKllEvCv2pa1Vdx0DUk%3D
    {
      "appid":"3143eba93adb4f35bde98aa31e4e5bbd",
	  "callee":"8613696486500",
      "caller":"8618223159111",
	  "display":"02066240222",
	  "sponsor":"02066240222",
	  "notify_url":"http:183.230.40.149:80/callback/statusback"
    }


#### 响应消息

<table>
<tr><th width="15%">参数名称</th><th width="12%">类型</th><th width="12%">长度</th><th width="12%">是否必填</th><th>说明</th></tr>
<tr><td>request_id</td><td>String</td><td>32</td><td>是</td><td>请求Id<br>http请求唯一识别码</td></tr>
<tr><td>code_no</td><td>String</td><td>6</td><td>是</td><td>返回编码</td></tr>
<tr><td>code</td><td>String</td><td>512</td><td>是</td><td>返回码</td></tr>
<tr><td>message</td><td>String</td><td>512</td><td>是</td><td>返回描述信息</td></tr>
<tr><td>data</td><td>Data</td><td>-</td><td>是</td><td>呼叫结果信息<br>Data详细参数说明如下所示</td></tr>
</table>

##### Data参数说明

<table>
<tr><th width="15%">参数名称</th><th width="12%">类型</th><th width="12%">长度</th><th width="12%">是否必填</th><th>说明</th></tr>
<tr><td>call_id</td><td>String</td><td>64</td><td>是</td><td>呼叫标识</td></tr>
</table>


#### 响应消息示例
    HTTP/1.1 200 OK
    Content-Type: application/json; charset=UTF-8
    Connection: close
    {
    "request_id": "85fcaba7045247c88b87380149ea0941",
    "code_no": "000000",
    "code": "OneNET_common_success",
    "message": "调用成功",
    "data": {
             "call_id": "150104227912386807"
            }
    }


#### 响应码汇总
目前的响应码汇总如下，根据实际情况可能有所调整。
<table>
<tr><th width="25%">code_no</th><th width="40%">code</th><th>message</th></tr>
<tr><td>000000</td><td>onenet_common_success</td><td>成功</td></tr>
<tr><td>000111</td><td>onenet_common_systemException</td><td>系统异常，请稍后重试</td></tr>
<tr><td>000001</td><td>onenet_common_systemBusy</td><td>系统繁忙，请稍后重试</td></tr>
<tr><td>000002</td><td>onenet_common_authException</td><td>系统认证失败</td></tr>
<tr><td>000004</td><td>onenet_common_invalidParams</td><td>非法的参数</td></tr>
<tr><td>000005</td><td>onenet_common_invalidReqParams</td><td>非法的请求参数</td></tr>
<tr><td>000006</td><td>onenet_common_paramNullException</td><td>必输参数不能为空</td></tr>
<tr><td>000012</td><td>onenet_common_JsonException</td><td>非法JSON的数据</td></tr>
<tr><td>000014</td><td>onenet_common_authorizationIsNull</td><td>鉴权参数为空</td></tr>
<tr><td>000015</td><td>onenet_common_authorizationFailed</td><td>鉴权失败</td></tr>
<tr><td>001001</td><td>onenet_iaepVoice_callIdNotExist</td><td>呼叫标识不存在</td></tr>
<tr><td>001005</td><td>onenet_iaepVoice_NumberFormatRrror</td><td>号码格式错误</td></tr>
<tr><td>001008</td><td>onenet_iaepVoice_BusinessNumberMismatch</td><td>业务号码不匹配</td></tr>
<tr><td>001009</td><td>onenet_iaepVoice_NotOpenTheBusiness</td><td>用户没有开通该业务</td></tr>
<tr><td>001010</td><td>onenet_iaepVoice_TheBusinessIsClosed</td><td>用户该项业务已关闭</td></tr>
</table>