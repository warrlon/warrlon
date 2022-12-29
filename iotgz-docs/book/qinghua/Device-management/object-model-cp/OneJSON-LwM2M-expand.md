# OneJSON LwM2M拓展

**1. 设备上行数据**

OneJSON数据格式:

````json
{
  "id": "123",
  "version": "1.0",
  "params": {
    "Power": {
      "value": "on",
      "time": 1524448722123
    },
    "WF": {
      "value": 23.6,
      "time": 1524448722123
    }
  },
  "method":"thing.{功能类型}.{方法}"
}
````

表：请求参数描述

<table>
<tr style="background-color:#363636; color:#F0FFF0;"><td width="15%">参数</td><td>类型</td><td width="70%">描述</td></tr>
<tr><td>id</td><td>String</td><td>消息id号，用户自定义，String类型的数字，长度限制不超过13位</td></tr>
<tr><td>version</td><td>String</td><td>物模型版本号，可选字段，不填默认为1.0</td></tr>
<tr><td>params</td><td>JsonObject</td><td>请求参数，标准json格式，内容同基础的OneJSON格式</td></tr>
<tr><td>method</td><td>String</td><td>上行数据业务类型，目前仅支持以下四种方法：thing.property.post、thing.event.post、thing.pack.post、thing.history.post</td></tr>
</table>

**2. 异步服务响应数据**

OneJSON数据格式:

````json
{
    "id":"123",
    "code":200,
    "msg":"xxxx",
    "data":{
        "result1":"on",
        "result2":"2"
    },
    "method":"thing.{功能类型}.{identifier}.reply"
}
````

表:响应参数描述

<table>
<tr style="background-color:#363636; color:#F0FFF0;"><td width="15%">参数</td><td>类型</td><td width="70%">描述</td></tr>
<tr><td>id</td><td>String</td><td>消息id号，用户自定义，String类型的数字，长度限制不超过13位</td></tr>
<tr><td>code</td><td>Integer</td><td>结果状态码</td></tr>
<tr><td>msg</td><td>String</td><td>错误信息</td></tr>
<tr><td>data</td><td>Object</td><td>请求参数，标准json格式，内容同基础的OneJSON格式</td></tr>
<tr><td>method</td><td>String</td><td>下行数据响应业务类型，目前仅支持服务异步响应：
thing.service.{identifier}.reply</td></tr>
</table>

**3. 设备下行数据**

OneJSON数据格式:

````json
{
  "id": "123",
  "version": "1.0",
  "params": {},
  "method":"thing.{功能类型}.{方法/服务标识符}"
}
````

表：请求参数描述

<table>
<tr style="background-color:#363636; color:#F0FFF0;"><td width="15%">参数</td><td>类型</td><td width="70%">描述</td></tr>
<tr><td>id</td><td>String</td><td>消息id号，用户自定义，String类型的数字，长度限制不超过13位</td></tr>
<tr><td>version</td><td>String</td><td>物模型版本号，可选字段，不填默认为1.0</td></tr>
<tr><td>params</td><td>JsonObject</td><td>请求参数，标准json格式，内容同基础的OneJSON格式</td></tr>
<tr><td>method</td><td>String</td><td>上行数据业务类型，目前仅支持以下3种方法：
thing.property.set、
thing.property.get、
thing.service.{identifier}</td></tr>
</table>