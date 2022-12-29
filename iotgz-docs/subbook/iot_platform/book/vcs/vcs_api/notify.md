# 语音通知

## 语音通知

请求方式：POST

请求地址：https(http)://openapi.heclouds.com/vcs?action=voiceNotify&version=2

#### HTTP头部

|参数名称|是否必填|参数值|
|:-|:-|:-|
|Authorization|是|[查看鉴权参数计算方法](/book/api/auth.md)|
|Content-Type|是|application/json;charset=utf-8|

#### 请求body

<table>
<tr><th width="20%">参数名称</th><th width="17%">类型</th><th width="14%">长度</th><th width="14%">是否必填</th><th>说明</th></tr>
<tr><td>participant_address</td><td>String</td><td>20</td><td>是</td><td>外呼被叫号码MSISDN<br>举例8618625150488</td></tr>
<tr><td>display</td><td>String</td><td>64</td><td>是</td><td>业务号码（用户在开发者中心进行资质申请，审核通过后平台分配业务号码）</td></tr>
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


#### 返回数据

<table>
<tr><th width="20%">参数名称</th><th width="20%">类型</th><th>描述</th></tr>
<tr><td>code</td><td>String</td><td>调用失败时，返回的错误码</td></tr>
<tr><td>msg</td><td>String</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td>requestId</td><td>String</td><td>调用API时生成的请求标识</td></tr>
<tr><td>success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td>data</td><td>-</td><td>调用成功时，返回的业务数据</td></tr>
<tr><td>data.call_id</td><td>string</td><td>呼叫标识</td></tr>
</table>


#### 请求示例

    POST /vcs?action=voiceNotify&version=2
    Content-type: application/json
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
      "display": "02066240200",
      "notify_url": "http:10.10.3.71:80/thirdParty/callback/statusback",
      "participant_address": "8618102383000"
    }

#### 响应示例

成功

    {
        "requestId": "a25087f46df04b69b29e90ef0acfd115", 
        "success": true,
        "data": {
            "call_id": "150104227912386807"
        }
    }

失败

    {
        "code": "iot.vcs.notApplyTestAccount",
        "msg": "request ip not equals test account ip",
        "requestId": "0d9a3bab49ee458984743d5ee59eafab",
        "success": false
    }

