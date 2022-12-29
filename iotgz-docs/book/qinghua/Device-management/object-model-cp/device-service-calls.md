# 设备服务调用

**1. 设备服务调用**

物联平台支持同步调用和异步调用，同步调用超时时间5s，异步调用无超时时间。

下行(OneJSON）

>- 请求topic: $sys/{pid}/{device-name}/thing/service/{identifier}/invoke

OneJSON数据格式:

````json
{
    "id":"123",
    "version":"1.0",
    "params":{
        "Power1":"on",
        "WF1":"2"
    }
}
````

表：请求参数描述
 
<table>
<tr style="background-color:#363636; color:#F0FFF0;"><td width="15%">参数</td><td>类型</td><td widtd="70%">描述</td></tr>
<tr><td>ididentifier</td><td>String</td><td>功能点唯一标识符（产品下唯一）</td></tr>
<tr><td>id</td><td>String</td><td>消息id号，用户自定义，String类型的数字，长度限制不超过13位</td></tr>
<tr><td>version</td><td>String</td><td>结果状态码,物模型版本号，可选字段，不填默认为1.0</td></tr>
<tr><td>params</td><td>Object</td><td>服务的请求参数，参数类型具体见物模型对应的“服务”定义（输入参数部分）<br>
{<br>
"Power1":"on",<br>
"WF1":"2"<br>
}</td></tr><br>
</table>

>- 响应topic: $sys/{pid}/{device-name}/thing/service/{identifier}/invoke_reply

OneJSON数据格式:

````json
{
    "id":"123",
    "code":200,
    "msg":"xxxx",
    "data":{
        "result1":"on",
        "result2":"2"
    }
}
````

表：响应参数描述
 
<table>
<tr style="background-color:#363636; color:#F0FFF0;"><td width="15%">参数</td><td>类型</td><td widtd="70%">描述</td></tr>
<tr><td>id</td><td>String</td><td>消息id号，用户自定义，String类型的数字，长度限制不超过13位</td></tr>
<tr><td>code</td><td>Integer</td><td>结果状态码</td></tr>
<tr><td>msg</td><td>String</td><td>错误消息</td></tr>
<tr><td>data</td><td>Object</td><td>服务的响应参数，参数类型具体见物模型对应的“服务”定义（输出参数部分）<br>
{<br>
"result1":"on",<br>
"result2":"2"<br>
}</td></tr><br>
</table>

>- 说明:  
同步调用，返回以上结果；  
异步调用，平台收到服务调用请求后立即返回以上结果给应用，但是不包含data字段；平台收到设备响应后，按以上结果（含data字段）将数据通过规则引擎推送或数据存储，用户HTTP推送、Kafka推送等服务获取设备服务执行结果，也可通过「设备详情」-「服务记录」查看相关执行结果，亦可通过api查询获取执行结果。