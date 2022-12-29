# 语音通知

## 语音通知状态呼叫通知

请求方式：**POST**

请求地址: 语音通知API中指定的notify_url。若如无此字段，则以OneNET平台配置为准。

#### HTTP头部

|参数名称|是否必填|参数值|
|:-|:-|:-|
|Authorization|是|[查看鉴权参数计算方法](/book/api/auth.md)|
|Content-Type|是|application/json;charset=utf-8|


#### 请求body

<table>
<tr><th width="18%">参数名称</th><th width="15%">类型</th><th width="15%">长度</th><th width="15%">是否必填</th><th>说明</th></tr>
<tr><td>user_id</td><td>Long</td><td>32</td><td>是</td><td>OneNET用户Id</td></tr>
<tr><td>call_id</td><td>String</td><td>64</td><td>是</td><td>呼叫标识</td></tr>
<tr><td>caller</td><td>String</td><td>64</td><td>是</td><td>主叫号码（MSISDN）<br>举例8618625150488</td></tr>
<tr><td>callee</td><td>String</td><td>64</td><td>是</td><td>被叫号码（MSISDN）<br>举例8618625150488</td></tr>
<tr><td>status</td><td>String</td><td>16</td><td>是</td><td>呼叫状态<br>CallingCallee：正在呼叫被叫<br>Connected：通话中<br>Disconnected：已经结束<br>CollectResult：放音收号结果事件
</td></tr>
<tr><td>reason</td><td>String</td><td>16</td><td>否</td><td>status为Disconnected时必填<br>当status为Disconnected时，表示断开原因<br>HangUp：正常挂机，包括通话后被删除<br>CalleeBusy：被叫忙<br>CalleeNoAnswer：被叫无应答<br>CalleeFailure：被叫其它原因失败<br>Other：其它原因失败<br>CalleeEmpty：被叫空号<br>CalleeUnregistere：被叫关机<br>CalleeReject：被叫拒接<br>CalleenotReach：被叫不可及</td></tr>
<tr><td>operation_result</td><td>String</td><td>64</td><td>否</td><td>当status= CollectResult时，该参数用于表示在放音收号场景中，向开发者提供收号结果</td></tr>
<tr><td>call_duration</td><td>String</td><td>-</td><td>否</td><td>本次通话时长，单位秒<br>status为Disconnected时必填</td></tr>
</table>

#### 请求示例
    POST /callback/statusback
    Content-Type: application/json;charset=utf-8
    Accept: application/json
    Authorization:version=2020-05-29&res=userid%2F37739&et=1605860214&method=md5&sign=TqjQo8%2FlSMuM6jN5uLYvPw%3D%3D

    {
      "user_id":1234,
      "call_id": "CS123",
      "caller":"8613912345672",
      "callee":"8613912345673",
      "status":"Disconnected",
      "reason":"HangUp"
    }



#### 响应消息

<table>
<tr><th width="15%">参数名称</th><th width="15%">类型</th><th width="15%">长度</th><th width="15%">是否必填</th><th>说明</th></tr>
<tr><td>request_id</td><td>String</td><td>32</td><td>是</td><td>请求Id<br>http请求唯一识别码</td></tr>
<tr><td>code_no</td><td>String</td><td>6</td><td>是</td><td>返回编码</td></tr>
<tr><td>code</td><td>String</td><td>512</td><td>是</td><td>返回码</td></tr>
<tr><td>message</td><td>String</td><td>512</td><td>是</td><td>返回描述信息</td></tr>
</table>



#### 响应消息示例
    HTTP/1.1 200 OK
    Content-Type: application/json; charset=UTF-8
    Connection: close
    Content-Length: 0
    {
    "request_id": "85fcaba7045247c88b87380149ea0941",
    "code_no": "000000",
    "code": "OneNET_common_success",
    "message": "调用成功"
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