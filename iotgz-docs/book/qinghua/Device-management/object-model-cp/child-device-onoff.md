# 子设备上下线

**1. 子设备上线**

子设备上线之前，需和网关绑定拓扑关系；
子设备上线时，物联平台会根据拓扑关系进行子设备验证，以确定子设备是否有使用网关通道的权利。
````
若用户不关心子设备的在线状态，该流程为可选流程，子设备在线状态会显示为未知
````

>- 请求topic: $sys/{pid}/{device-name}/thing/sub/login

因子设备通过网关通道与物联平台建立通信，以上topic为网关设备的topic，topic中的变量{pid}和{device-name}需替换为网关设备对应信息。

OneJSON数据格式:

````json
{
  "id": "123",
  "version": "1.0",
  "params": {
    "productID": "product1",
    "deviceName": "device1"
  }
}
````

表：请求参数描述

<table>
<tr style="background-color:#363636; color:#F0FFF0;"><td width="15%">参数</td><td>类型</td><td width="70%">说明</td></tr>
<tr><td>id</td><td>String</td><td>消息id号，用户自定义，String类型的数字，长度限制不超过13位</td></tr>
<tr><td>version</td><td>String</td><td>物模型版本号，可选字段，不填默认为1.0</td></tr>
<tr><td>params</td><td>Object</td><td>请求入参，包含的具体参数见下表params</td></tr>
<tr><td>deviceName</td><td>String</td><td>子设备的设备名称</td></tr>
<tr><td>productID</td><td> String</td><td>子设备所属产品的productID</td></tr>
</table>

>- 响应topic:$sys/{pid}/{device-name}/thing/sub/login/reply

因子设备通过网关通道与物联平台建立通信，以上topic为网关设备的topic，topic中的变量{pid}和{device-name}需替换为网关设备对应信息。

OneJSON数据格式:

````json
{
    "id":"123",
    "code":200,
    "msg":"xxxx"
}
````

<table>
<tr style="background-color:#363636; color:#F0FFF0;"><td width="15%">参数</td><td>类型</td><td width="70%">说明</td></tr>
<tr><td>id</td><td>String</td><td>消息id号，用户自定义，String类型的数字，长度限制不超过13位</td></tr>
<tr><td>code</td><td>Integer</td><td>返回结果，200代表成功</td></tr>
<tr><td>msg</td><td>String</td><td>结果信息，可选项</td></tr>
</table>

**2. 子设备下线**

````
若用户不关心子设备的在线状态，该流程为可选流程，子设备在线状态会显示为未知  
````

>- 请求topic:$sys/{pid}/{device-name}/thing/sub/logout

因子设备通过网关通道与平台建立通信，以上topic为网关设备的topic，topic中的变量{pid}和{device-name}需替换为网关设备对应信息。

OneJSON数据格式:

````json
{
  "id": "123",
  "version": "1.0",
  "params": {
    "productID": "product1",
    "deviceName": "device1"
  }
}
````

表：请求参数描述

<table>
<tr style="background-color:#363636; color:#F0FFF0;"><td width="15%">参数</td><td>类型</td><td width="70%">说明</td></tr>
<tr><td>id</td><td>String</td><td>消息id号，用户自定义，String类型的数字，长度限制不超过13位</td></tr>
<tr><td>version</td><td>String</td><td>物模型版本号，可选字段，不填默认为1.0</td></tr>
<tr><td>params</td><td>Object</td><td>请求入参，包含的具体参数见下表params</td></tr>
<tr><td>deviceName</td><td>String</td><td>子设备的设备名称</td></tr>
<tr><td>productID</td><td> String</td><td>子设备所属产品的productID</td></tr>
</table>

>- 响应topic:$sys/{pid}/{device-name}/thing/sub/logout/reply
    
因子设备通过网关通道与物联平台建立通信，以上topic为网关设备的topic，topic中的变量{pid}和{device-name}需替换为网关设备对应信息。

OneJSON数据格式:

````json
{
    "id":"123",
    "code":200,
    "msg":"xxxx"
}
````

表:响应参数描述

<table>
<tr style="background-color:#363636; color:#F0FFF0;"><td width="15%">参数</td><td>类型</td><td width="70%">说明</td></tr>
<tr><td>id</td><td>String</td><td>消息id号，用户自定义，String类型的数字，长度限制不超过13位</td></tr>
<tr><td>code</td><td>Integer</td><td>返回结果，200代表成功</td></tr>
<tr><td>msg</td><td>String</td><td>结果信息，可选项</td></tr>
</table>