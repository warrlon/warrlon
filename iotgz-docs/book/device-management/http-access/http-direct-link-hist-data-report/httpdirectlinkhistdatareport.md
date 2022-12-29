# **直连设备-历史数据上报**  

# **历史数据上报接口**  

#### **接口名称**

> **historyDataNotify**

#### **请求方法**  

> **POST**

#### **请求参数**  

<table style="text-align: left">
    <tr style="background-color:#363636; color:#F0FFF0;">
        <td width="18%">参数名称</td>
        <td width="18%">类型</td>
        <td width="18%">是否必选</td>
        <td>描述</td>
    </tr>
    <tr>
        <td>topic</td>
        <td>string</td>
        <td>是</td>
        <td>$sys/{pid}/{device-name}/thing/history/post</td>
    </tr>
    <tr>
        <td>protocol</td>
        <td>string</td>
        <td>是</td>
        <td>协议名称，包含MQTT,COAP,OTHER,HTTP</td>
    </tr>
</table>

#### **返回数据**  

<table style="text-align: left">
    <tr style="background-color:#363636; color:#F0FFF0;">
        <td width="20%">参数名称</td>
        <td width="20%">类型</td>
        <td>描述</td>
    </tr>
    <tr>
        <td>code</td>
        <td>string</td>
        <td>调用失败时，返回的错误码</td>
    </tr>
    <tr>
        <td>msg</td>
        <td>string</td>
        <td>调用失败时，返回的错误信息</td>
    </tr>
    <tr>
        <td>requestId</td>
        <td>string</td>
        <td>调用API时生成的请求标识</td>
    </tr>
    <tr>
        <td>success</td>
        <td>boolean</td>
        <td>接口是否调用成功</td>
    </tr>
    <tr>
        <td>data</td>
        <td>-</td>
        <td>调用成功时，返回的业务数据</td>
    </tr>
</table>

#### **示例**
  
**请求示例**  

````json
POST /device/thing/history/post?topic=$sys/W6O8v7Ce7d/device1/thing/history/post&protocol=http
{
    "id":"123",
    "version":"1.0",
    "params":[{
           "properties":{
                "status":[{
                    "value":1,
                    "time":1619332210357
                }],
                "gear":[{
                    "value":1,
                    "time":1619332210357
                }]
            },
            "events":{
                "RolloverEvent":[{
                    "value":{
                        "RolloverAccP":31,
                        "RolloverAccE":32
                     },
                    "time":1619332210357
                }]
            }
    }]
}
````

**响应示例**  

````json
{
    "errno": 0,
    "error": "succ"
}
````