# 点击拨号

## 点击拨号

请求方式：POST

接口地址：https(http)://openapi.heclouds.com/vcs?action=dialNotify&version=2

#### HTTP头部

|参数名称|是否必填|参数值|
|:-|:-|:-|
|Authorization|是|[查看鉴权参数计算方法](/book/api/auth.md)|
|Content-Type|是|application/json;charset=utf-8|

#### 请求body

<table>
<tr><th width="15%">参数名称</th><th width="12%">类型</th><th width="12%">长度</th><th width="12%">是否必填</th><th>说明</th></tr>
<tr><td>sponsor</td><td>String</td><td>64</td><td>是</td><td>发起呼叫的号码（业务号码）<br>主叫用户的来显号码，由OneNET平台提供<br>号码格式：<br>手机号码格式：MSISDN。示例：8613500000003<br>固话格式：区号+固话。区号0755，固话号码28000003，填写为075528000003</td></tr>
<tr><td>caller</td><td>String</td><td>64</td><td>是</td><td>主叫号码<br>号码格式使用MSISDN，举例8618625150488</td></tr>
<tr><td>callee</td><td>String</td><td>64</td><td>是</td><td>被叫号码<br>号码格式使用MSISDN，举例8618625150488</td></tr>
<tr><td>display</td><td>String</td><td>64</td><td>否</td><td>被叫用户的号显号码<br>如果未携带此参数，被叫用户的来显号码为sponsor<br>如果携带此参数，值只可以与caller（display与caller相同时，caller需要加白名单）或sponsor相同，如果携带为其他号码则无法呼叫，响应报错<br>号码格式：<br>手机号码格式：MSISDN。示例：8613500000003<br>固话格式：区号+固话。区号0755，固话号码28000003，填写为075528000003</td></tr>
<tr><td>notify_url</td><td>String</td><td>512</td><td>否</td><td>用户指定的通知地址（请求方式为POST）<br>如无此字段，不进行回调</td></tr>
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

    POST /vcs?action=dialNotify&version=2
    Content-type: application/json
    {
      "callee":"8613696486500",
      "caller":"8618223159111",
      "display":"02066240222",
      "sponsor":"02066240222",
      "notify_url":"http:183.230.40.149:80/callback/statusback"
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

