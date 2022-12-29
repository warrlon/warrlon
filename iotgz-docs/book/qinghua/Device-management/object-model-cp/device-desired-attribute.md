# 设备期望属性值

**1. 属性期望值流程**

在物联平台设置属性期望值后，平台更新属性期望值，若设备在线，将实时异步更新设备属性状态；若设备离线，期望值属性值将缓存在平台，待设备上线后，设备可主动获取属性期望值，设备业务处理后，并选择是否上报属性最新状态。

![属性期望值流程](/images\qinghua\device-management\desired-attribute-process.png)

**2. 属性期望值获取**

>- 请求topic: $sys/{pid}/{device-name}/thing/property/desired/get

OneJSON数据格式：

````json
{
    "id" : "123",
    "version":"1.0",
    "params" : [
        "power",
        "temperature"
    ]
}
````

表：请求参数描述

<table>
<tr style="background-color:#363636; color:#F0FFF0;"><td width="15%">参数</td><td>类型</td><td widtd="70%">描述</td></tr>
<tr><td>id</td><td>String</td><td>消息id号，用户自定义，String类型的数字，长度限制不超过13位</td></tr>
<tr><td>version</td><td>String</td><td>物模型版本号，可选字段，不填默认为1.0</td></tr>
<tr><td>params</td><td>JsonObject</td><td>获取属性期望的标识符列表</td></tr>
</table>

>- 响应topic:$sys/{pid}/{device-name}/thing/property/desired/get/reply

OneJSON数据格式：

````json
{
    "id":"123",
    "code":200,
    "msg":"xxxx"
    "data":{
        "power": {
            "value": "on",
            "version": 2
        }
    }
}
````

表：响应参数描述

<table>
<tr style="background-color:#363636; color:#F0FFF0;"><td width="15%">参数</td><td>类型</td><td widtd="70%">描述</td></tr>
<tr><td>id</td><td>String</td><td>消息id号，用户自定义，String类型的数字，长度限制不超过13位</td></tr>
<tr><td>code</td><td>Integer</td><td>结果状态码</td></tr>
<tr><td>msg</td><td>String</td><td>错误消息</td></tr>
<tr><td>data</td><td>Object</td><td>1.返回的期望值信息。若未在云端设置过该属性的期望值，或期望值属性被清空，返回对象中不包含该属性的标识符。key：属性标识符value：期望值version：当前期望属性值的版本。首次设置属性期望值后，版本为1。以后每次设置，版本号自增；清空期望值再设置期望值，版本号重新从1开始2.如果状态未成功，msg为携带的错误信息</td></tr>
</table>

**3. 属性期望值清除**

>- 请求topic:$sys/{pid}/{device-name}/thing/property/desired/delete

OneJSON数据格式：

````json
{
    "id": "123",
    "version": "1.0",
    "params": {
        "power": {
            "version": 1
        },
        "temperature": { }
    }  
}
````

表：请求参数描述

<table>
<tr style="background-color:#363636; color:#F0FFF0;"><td width="15%">参数</td><td>类型</td><td widtd="70%">描述</td></tr>
<tr><td>id</td><td>String</td><td>消息id号，用户自定义，String类型的数字，长度限制不超过13位</td></tr>
<tr><td>version</td><td>String</td><td>物模型版本号，可选字段，不填默认为1.0</td></tr>
<tr><td>params</td><td>JsonObject</td><td>要清除期望的属性信息列表。key：标识符version：要删除期望属性的版本号。如果指定为1，标识平台最新版本是1时执行清除。如果指定版本为1，但平台最新版本是大于1，则忽略这个清除请求。若请求中，未指定要清除的期望值版本version，则不验证版本号，直接清除期望值</td></tr>
</table>

>- 响应topic:$sys/{pid}/{device-name}/thing/property/desired/delete/reply

OneJSON数据格式：

````json
{
    "id":"123",
    "code":200,
    "msg":"xxxx"
}
````

表：响应参数描述

<table>
<tr style="background-color:#363636; color:#F0FFF0;"><td width="15%">参数</td><td>类型</td><td widtd="70%">描述</td></tr>
<tr><td>id</td><td>String</td><td>消息id号，用户自定义，String类型的数字，长度限制不超过13位</td></tr>
<tr><td>code</td><td>Integer</td><td>结果状态码</td></tr>
<tr><td>msg</td><td>String</td><td>错误消息</td></tr>
</table>