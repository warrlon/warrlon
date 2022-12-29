# **代理设备-子设备上线**  

# **子设备上线接口**  

#### **接口名称**

> **subDeviceLogin**

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
        <td>$sys/{pid}/{device-name}/thing/sub/login</td>
    </tr>
    <tr>
        <td>protocol</td>
        <td>string</td>
        <td>是</td>
        <td>协议名称，包含MQTT,OTHER</td>
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
POST /proxy/device/thing/login?topic=$sys/9701D5Lc56/device2/thing/sub/login&protocol=mqtt
{
  "id": "123",
  "version": "1.0",
  "params": {
    "productID": "k5NIV817Ww", 
    "deviceName": "childDevice1"
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