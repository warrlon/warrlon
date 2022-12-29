# **直连设备-设备事件上报**  

# **设备事件上报接口**  

#### **接口名称**

> **deviceEventNotify**

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
        <td>$sys/{pid}/{device-name}/thing/event/post</td>
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
        <td>errno</td>
        <td>int</td>
        <td>调用失败时，返回的错误码序号</td>
    </tr>
    <tr>
        <td>error</td>
        <td>string</td>
        <td>调用失败时，返回的错误码</td>
    </tr>
</table>

#### **示例** 
 
**请求示例**  

````json
POST /device/thing/event/post?topic=$sys/W6O8v7Ce7d/device1/thing/event/post&protocol=http
{
    "id":"123",
    "version":"1.0",
    "params":{
        "RolloverEvent":{
            "time":1619161479300,
            "value":{
                "RolloverAccP":99,
                "RolloverAccE":99
             }
        }
    }
}
````

**响应示例**  

````json
{
    "errno": 0,
    "error": "succ"
}
````