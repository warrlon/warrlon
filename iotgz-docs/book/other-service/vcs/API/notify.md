# 语音通知

## 语音通知

请求方式：**POST**

请求地址: https://voice.heclouds.com:8002/v1/onenet/voice/notify

#### HTTP头部

|参数名称|是否必填|参数值|
|:-|:-|:-|
|Authorization|是|[详见鉴权认证](/book/other-service/vcs/API/authentication.md)|
|Content-Type|是|application/json;charset=utf-8|


#### 请求body

<table>
<tr><th width="20%">参数名称</th><th width="17%">类型</th><th width="14%">长度</th><th width="14%">是否必填</th><th>说明</th></tr>
<tr><td>appid</td><td>String</td><td>32</td><td>是</td><td>应用标识<br>由OneNET平台生成</td></tr>
<tr><td>participant_address</td><td>String</td><td>20</td><td>是</td><td>外呼被叫号码MSISDN<br>举例8618625150488</td></tr>
<tr><td>display</td><td>String</td><td>64</td><td>是</td><td>号显号码（业务号码）<br>由OneNET平台提供</td></tr>
<tr><td>actions</td><td>CallActionType[]</td><td>-</td><td>是</td><td>呼叫操作指示，参考CallActionType定义<br>仅支持Play和PlayAndCollect</td></tr>
<tr><td>notify_url</td><td>String</td><td>512</td><td>否</td><td>用户指定的通知地址（请求方式为POST）<br>如无此字段，则根据OneNET平台配置为准</td></tr>
</table>

##### 呼叫操作类型CallActionType参数说明

<table>
<tr><th width="20%">参数名称</th><th width="17%">类型</th><th width="14%">长度</th><th width="14%">是否必填</th><th>说明</th></tr>
<tr><td>operation</td><td>String</td><td>32</td><td>是</td><td>操作类型<br>Play：放音<br>PlayAndCollect：放音及收号</td></tr>
<tr><td>tts_template</td><td>String</td><td>20</td><td>是</td><td>tts模板编号<br>用户向OneNET提交的通知模板，需审核通过后才能使用</td></tr>
<tr><td>param_value</td><td>String</td><td>-</td><td>是</td><td>模板中需要填充的参数<br>参数内容为UTF-8编码，JSON Object的格式为{"var1":"aa","var2":"aa"}，其中var1，var2为模板变量名称，var的个数可变</td></tr>
<tr><td>collect_length</td><td>String</td><td>32</td><td>否</td><td>收号长度<br>当operation=PlayAndCollect时有效，如果replayAfterCollection=false或未配置，系统会将用户输入的号码通过呼叫状态通知API发送给第三方；如果replayAfterCollection=true，则不会将收号结果上报给第三方<br>取值范围<br>1~32：收号，取值表示收号位长，最大支持32位</td></tr>
<tr><td>replay_after_collection</td><td>String</td><td>-</td><td>否</td><td>重新播放标识<br>当operation=PlayAndCollect时有效，此字段用于设置是否在收号后重新播放指定的放音<br>true：播放<br>false：不播放<br>默认值：false</td></tr>
<tr><td>collect_content_trigger_replaying</td><td>String</td><td>32</td><td>否</td><td>当replayAfterCollection=true时此参数有效<br>此字段用于设置触发重新放音的收号内容，只有实际收号内容与该参数值一致时，才重新放音<br>例如：该参数设置为1，当用户根据收号语音提示按1，两者一致，则重复放音<br>默认值为1</td></tr>
<tr><td>relay_time</td><td>String</td><td>32</td><td>否</td><td>重复放音次数<br>当操作类型为Play时，此字段有效<br>默认为1次</td></tr>
</table>


#### 请求示例
    Content-Type: application/json;charset=utf-8
    Accept: application/json
    Authorization:version=v1&res=onenet_voice%2Ffd977e9f94e44f239f18f6f919282569&et=1568341874&method=md5&sign=uMJm8NxLshHNkW9qqQF1Gg%3D%3D
    {
      "actions": [
        {
          "tts_template": "89",
          "param_value": {"param1": "张三"},
          "collect_length": "1",
	      "replay_after_collection": "true",
	      "collect_content_trigger_replaying": "1",
	      "operation": "PlayAndCollect"
       }
      ],
      "appid": "fd977e9f94e44f239f18f6f919282569",
      "display": "02066240200",
      "notify_url": "http:10.10.3.71:80/thirdParty/callback/statusback",
      "participant_address": "8618102383000"
    }


#### 响应消息

<table>
<tr><th width="15%">参数名称</th><th width="15%">类型</th><th width="15%">长度</th><th width="15%">是否必填</th><th>说明</th></tr>
<tr><td>request_id</td><td>String</td><td>32</td><td>是</td><td>请求Id<br>http请求唯一识别码</td></tr>
<tr><td>code_no</td><td>String</td><td>6</td><td>是</td><td>返回编码</td></tr>
<tr><td>code</td><td>String</td><td>512</td><td>是</td><td>返回码</td></tr>
<tr><td>message</td><td>String</td><td>512</td><td>是</td><td>返回描述信息</td></tr>
<tr><td>data</td><td>Data</td><td>-</td><td>是</td><td>呼叫结果信息<br>Data详细参数说明如下所示</td></tr>
</table>

##### Data参数说明

<table>
<tr><th width="15%">参数名称</th><th width="15%">类型</th><th width="15%">长度</th><th width="15%">是否必填</th><th>说明</th></tr>
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


