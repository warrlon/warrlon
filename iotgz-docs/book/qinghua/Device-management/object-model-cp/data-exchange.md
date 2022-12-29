# 子设备数据交互

**1. 子设备数据上传**

子设备数据上传采用批量上送数据通道，具体参考[设备属性/事件](/book/qinghua/Device-management/object-model-cp/device-attribute.md)的【批量数据上报】或【历史数据上报】。

**2. 子设备属性获取**

支持应用通过网关获取子设备属性，目前仅支持一次获取单个子设备多个属性，每次获取属性个数不超过50个，超时时间为5s。

>- 请求topic:$sys/{pid}/{device-name}/thing/sub/property/get

OneJSON数据格式:

````json
{
    "id":"123",
    "version":"1.0",
    "params":{
        "deviceName":"device1",
        "productID":"product1",
        "params":[
            "temperature",
            "humidity"
        ]
    }
}
````

表：请求参数说明

<table>
<tr style="background-color:#363636; color:#F0FFF0;"><td width="15%">参数</td><td>类型</td><td width="70%">说明</td></tr>
<tr><td>id</td><td>String</td><td>消息id号，用户自定义，String类型的数字，长度限制不超过13位</td></tr>
<tr><td>version</td><td>String</td><td>物模型版本号，可选字段，不填默认为1.0</td></tr>
<tr><td>params（外层）</td><td>JsonObject</td><td>获取属性最新值的相关信息</td></tr>
<tr><td>deviceName</td><td>String</td><td>子设备的设备名称</td></tr>
<tr><td>productID</td><td> String</td><td>子设备所属产品的productID</td></tr>
<tr><td>params（内层）</td><td>array</td><td>请求属性标识符列表</td></tr>
</table>

>- 响应topic:$sys/{pid}/{device-name}/thing/sub/property/get_reply

OneJSON数据格式:

````json
{
    "id":"123",
    "code":200,
    "msg":"xxx",
    "data":{
        "temperature":39.5,
        "humidity":20
    }
}
````

表：响应参数描述

<table>
<tr style="background-color:#363636; color:#F0FFF0;"><td width="15%">参数</td><td>类型</td><td width="70%">说明</td></tr>
<tr><td>id</td><td>String</td><td>消息id号，用户自定义，String类型的数字，长度限制不超过13位</td></tr>
<tr><td>code</td><td>Integer</td><td>结果状态码，用户自定义</td></tr>
<tr><td>msg</td><td>String</td><td> 错误信息</td></tr>
<tr><td>data</td><td>JsonObject</td><td>获取属性最新值列表</td></tr>
</table>

**3. 子设备属性设置**

支持应用通过网关设置子设备属性，目前仅支持一次设置单个子设备多个属性，每次设置属性个数不超过50个，超时时间为5s。

>- 请求topic:$sys/{pid}/{device-name}/thing/sub/property/set

OneJSON数据格式:

````json
{
    "id":"123",
    "version":"1.0",
    "params":{
        "deviceName":"device1",
        "productID":"product1",
        "params":{
            "temperature":"30.5",
            "humidity":"20.5"
        }
    }
}
````

表：请求参数说明

<table>
<tr style="background-color:#363636; color:#F0FFF0;"><td width="15%">参数</td><td>类型</td><td width="70%">说明</td></tr>
<tr><td>id</td><td>String</td><td>消息id号，用户自定义，String类型的数字，长度限制不超过13位</td></tr>
<tr><td>version</td><td>String</td><td>物模型版本号，可选字段，不填默认为1.0</td></tr>
<tr><td>params（外层）</td><td>JsonObject</td><td>设置属性值的相关信息</td></tr>
<tr><td>deviceName</td><td>String</td><td>子设备的设备名称</td></tr>
<tr><td>productID</td><td> String</td><td>子设备所属产品的productID</td></tr>
<tr><td>params（内层）</td><td>array</td><td>设置属性的值列表</td></tr>
</table>

>- 响应topic:$sys/{pid}/{device-name}/thing/sub/property/set_reply

OneJSON数据格式:

````json
{
    "id":"123",
    "code":200,
    "msg":"xxxx"
}
````

表：响应参数描述

<table>
<tr style="background-color:#363636; color:#F0FFF0;"><td width="15%">参数</td><td>类型</td><td width="70%">说明</td></tr>
<tr><td>id</td><td>String</td><td>消息id号，用户自定义，String类型的数字，长度限制不超过13位</td></tr>
<tr><td>code</td><td>Integer</td><td>结果状态码，用户自定义</td></tr>
<tr><td>msg</td><td>String</td><td>错误信息</td></tr>
</table>

**4. 子设备服务调用**

网关可代替子设备获取平台下发的服务调用，并返回设备执行结果。

>- 请求topic:$sys/{pid}/{device-name}/thing/sub/service/invoke

OneJSON数据格式:

````json
{
    "id":"123",
    "version":"1.0",
    "params":{
        "deviceName":"device1",
        "productID":"product1",
        "identifier":"xxxx",
        "input":{
            "Power1":"on",
            "WF1":"2"
        }
    }
}
````

表：请求参数说明

<table>
<tr style="background-color:#363636; color:#F0FFF0;"><td width="15%">参数</td><td>类型</td><td width="70%">说明</td></tr>
<tr><td>id</td><td>String</td><td>消息id号，用户自定义，String类型的数字，长度限制不超过13位</td></tr>
<tr><td>version</td><td>String</td><td>物模型版本号，可选字段，不填默认为1.0</td></tr>
<tr><td>params</td><td>Object</td><td>请求入参，详情见表params</td></tr>
<tr><td>deviceName</td><td>String</td><td>子设备的设备名称</td></tr>
<tr><td>productID</td><td> String</td><td>子设备所属产品的productID</td></tr>
<tr><td>identifier</td><td>String</td><td>服务标识符</td></tr>
<tr><td>input</td><td>Object</td><td>服务的请求参数，参数类型具体见物模型对应的“服务”定义</td></tr>
</table>

>- 响应topic:$sys/{pid}/{device-name}/thing/sub/service/invoke_reply

OneJSON数据格式:

````json
{
    "id":"123",
    "code":200,
    "msg":"xxxx",
    "data":{
        "deviceName":"device1",
        "productID":"product1",
        "identifier":"xxxx",
        "output":{
            "result1":"on",
            "result2":"2"
        }
    }
}
````

````
消息体中，参数productID和deviceName的值是子设备的对应信息。
````

表:响应参数描述

<table>
<tr style="background-color:#363636; color:#F0FFF0;"><td width="15%">参数</td><td>类型</td><td width="70%">说明</td></tr>
<tr><td>id</td><td>String</td><td>消息id号，用户自定义，String类型的数字，长度限制不超过13位</td></tr>
<tr><td>code</td><td>Integer</td><td>结果状态码，用户自定义</td></tr>
<tr><td>msg</td><td> String</td><td>错误信息</td></tr>
<tr><td>data</td><td>JsonObject</td><td>请求成功是，返回的服务调用结果，具体见表.data</td></tr>
<tr><td>deviceName</td><td>String</td><td>子设备的设备名称</td></tr>
<tr><td>productID</td><td> String</td><td>子设备所属产品的productID</td></tr>
<tr><td>identifier</td><td>String</td><td>服务标识符</td></tr>
<tr><td>output</td><td>Object</td><td>服务的响应参数，参数类型具体见物模型对应的“服务”定义</td></tr>
</table>
