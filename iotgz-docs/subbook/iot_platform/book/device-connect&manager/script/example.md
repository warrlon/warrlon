# 最佳实践

本节以M5310A模组，LwM2M接入协议为例，演示数据解析功能的使用流程。

#### 创建产品

按照平台[创建产品](/book/device-connect&manager/product-create.md)操作步骤，创建一个名称为后视镜、节点类型为直连设备、接入协议为LwM2M、数据协议为透传/自定义的产品，如图所示。

<center>
    <img width="80%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/script/脚本示例创建产品.png">
</center>

#### 开发产品物模型

产品物模型管理页面，添加一个标识符为humi的浮点型功能点、标识符为temp的整数型功能点。

<center>
    <img width="80%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/script/脚本示例创建功能点.png">
</center>

#### 设备数据上报测试

##### 单个功能点上报测试

产品数据解析功能页面，按照如下示例完成上行解析函数的编写。

```javascript
/**
  * 示例数据：
  * 设备属性上报
  * 传入参数：
  * 0x01010007  命令类型[1字节]+消息id[1字节]+数据值[2字节]
  * 输出格式：
  * {"method":"thing.property.post", "version":"1.0", "id":"1", "params":{"temp": { "value": 2.0 } }}
  */
var COMMAND_POST = 0x01 // 属性上报
var THING_PROP_POST_METHOD = 'thing.property.post'
 
function rawDataToJson (rawData) {
  var uint8Array = new Uint8Array(rawData.length)
  for (var i = 0; i < rawData.length; i++) {
    uint8Array[i] = rawData[i] & 0xff
  }
  var dataView = new DataView(uint8Array.buffer, 0)
  var jsonMap = { 'version': '1.0' }

  var fHead = uint8Array[0] // 读取第一个字节为command命令
  if (fHead === COMMAND_POST) {
    jsonMap['method'] = THING_PROP_POST_METHOD
    jsonMap['id'] = '' + dataView.getInt8(1)
    var value = dataView.getInt16(2)
    jsonMap['params'] = {
      'temp': {
        'value': value
      }
    }
  } 
  return jsonMap
}

function jsonToRawData (json) {}

```

使用平台在线脚本调试工具，完成脚本上行函数调试并发布脚本。（模拟输入类型选择设备上行数据，输入数据为0x01010008）

```
数据值：0x01010008
- 01代表属性上报报文，01为消息id，0008为功能点temp的上报值
- 命令类型[1字节]+消息id[1字节]+数据值[2字节]
```

<center>
    <img width="90%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/script/脚本示例单功能调试.png">
</center>

设备使用5310模组上报数据，如下为模组AT指令（他模组指令登录可参考模组手册和咨询模组技术人员）。

```
AT  //模组返回ok，mcu和模组通信成功
AT+CSQ   //查询信号，一般12-31，数值越大越好。一般为20左右
AT+CEREG?  //网络附着情况，返回0,1为附着到网络
AT+MIPLCREATEEX="183.230.102.118:5683",0  //创建实体
AT+MIPLADDOBJ=0,20,2,"11",0,1  //订阅对象
AT+MIPLDISCOVERRSP=0,20,1,1,"0" //订阅资源
AT+MIPLOPEN=0,86400,30//登录
AT+MIPLNOTIFY=0,0,20,0,0,6,4,"01010008",0,0,18 //上报数据
- 01代表属性上报报文，01为消息id，0008为功能点temp的上报值
```

##### 多个功能点上报测试

产品数据解析功能页面，按照如下示例修改上行解析函数，增加多个功能点的解析处理。

```javascript

var COMMAND_POST = 0x01 // 属性上报
var COMMAND_EVENT = 0x02 // 事件上报
var COMMAND_PACK = 0x03 // 批量上报
var COMMAND_HISTORY = 0x04 // 历史上报
var COMMAND_POST_REPLY = 0x00 // 上报数据返回结果

var COMMAND_SET = 0x05 // 属性设置设备返回结果
var COMMAND_SET_REPLY = 0x15 // 属性设置设备返回结果
var COMMAND_GET = 0x06 // 属性获取
var COMMAND_GET_REPLY = 0x16 // 属性获取返回

var THING_PROP_POST_METHOD = 'thing.property.post'
var THING_EVENT_POST_METHOD = 'thing.event.post'
var THING_PACK_POST_METHOD = 'thing.pack.post'
var THING_HISOTORY_METHOD = 'thing.history.post'
var THING_POST_REPLY_METHOD = 'thing.post.reply'
var THING_PROP_SET_METHOD = 'thing.property.set'
var THING_PROP_SET_REPLY_METHOD = 'thing.property.set.reply'
var THING_PROP_GET_METHOD = 'thing.property.get'
var THING_PROP_GET_REPLY_METHOD = 'thing.property.get.reply'

/**
  * 示例数据：
  * 设备属性上报
  * 传入参数：
  * 0x01010007  命令类型[1字节]+消息id[1字节]+数据值[2字节]
  * 输出格式：
  * {"method":"thing.property.post", "version":"1.0", "id":"1", "params":{"temp": { "value": 2.0 } }}
  */
function rawDataToJson (rawData) {
  var uint8Array = new Uint8Array(rawData.length)
  for (var i = 0; i < rawData.length; i++) {
    uint8Array[i] = rawData[i] & 0xff
  }
  var dataView = new DataView(uint8Array.buffer, 0)
  var jsonMap = { 'version': '1.0' }

  var fHead = uint8Array[0] // 读取第一个字节为command命令

  if (fHead === COMMAND_POST) {
    jsonMap['method'] = THING_PROP_POST_METHOD
    jsonMap['id'] = '' + dataView.getInt8(1)
    var value = dataView.getInt16(2)
    jsonMap['params'] = {
       'temp': {
          'value': value
       }
    }
  } else if(fHead == COMMAND_PACK) {
    jsonMap['method'] = THING_PACK_POST_METHOD
    jsonMap['id'] = '' + dataView.getInt8(1)
    var value = dataView.getInt16(2)
    jsonMap['params'] = [{
      'properties': {
        'humi': [{
          'value': value/10,
          'time': Date.now()
        }],
          "temp":[{
              "value":dataView.getInt16(4),
              'time': Date.now()
          }]
      
      }
    }]
  } else if(fHead == COMMAND_HISTORY) {
    jsonMap['method'] = THING_HISOTORY_METHOD
    jsonMap['id'] = '' + dataView.getInt8(1)
    var value = dataView.getInt16(2)
    //value = value、
    jsonMap['params'] = [{
      'properties': {
        'power': [{
          'value': value,
          'time': Date.now()
        }]
      }
    }]
  } else if (fHead === COMMAND_SET_REPLY) {
    jsonMap['method'] = THING_PROP_SET_REPLY_METHOD
    jsonMap['id'] = '' + dataView.getInt8(1)
    jsonMap['code'] =  dataView.getUint8(2)
    jsonMap['msg'] = jsonMap['code'] ? 'success' : 'failed'
    jsonMap['data'] = {
      'temp': dataView.getInt16(2) 
    }

  } else if (fHead === COMMAND_GET_REPLY) {
    jsonMap['method'] = THING_PROP_GET_REPLY_METHOD
    jsonMap['id'] = '' + dataView.getInt8(1)
    jsonMap['code'] = '' + dataView.getUint8(2)
    jsonMap['msg'] = jsonMap['code'] ? 'success' : 'failed'
    jsonMap['data'] = { 
      'power': dataView.getUint16(3) 
    }
  }
  return jsonMap
}
function jsonToRawData (json) {}

```

使用平台在线脚本调试工具，完成脚本上行函数调试并发布脚本（模拟输入类型选择设备上行数据，输入数据为0x030100080009。

```
数据值：0x030100080009
- 01代表属性上报报文，01为消息id，0008为功能点humi的上报值，0009为功能点temp的上报值
```

<center>
    <img width="90%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/script/脚本示例多功能调试.png">
</center>


```
模组上行指令改为：
AT+MIPLNOTIFY=0,0,20,0,0,6,4,"030100080009",0,0,18
- 01代表属性上报报文，01为消息id，0008为功能点humi的上报值，0009为功能点temp的上报值
```

#### 平台命令下发测试

产品数据解析功能页面，按照如下示例完成下行转换函数的编写。

```javascript

var COMMAND_POST = 0x01 // 属性上报
var COMMAND_EVENT = 0x02 // 事件上报
var COMMAND_PACK = 0x03 // 批量上报
var COMMAND_HISTORY = 0x04 // 历史上报
var COMMAND_POST_REPLY = 0x00 // 上报数据返回结果

var COMMAND_SET = 0x05 // 属性设置设备返回结果
var COMMAND_SET_REPLY = 0x15 // 属性设置设备返回结果
var COMMAND_GET = 0x06 // 属性获取
var COMMAND_GET_REPLY = 0x16 // 属性获取返回
var COMMAND_SERVICE =0x07 //服务下发
var COMMAND_SERVICE_REPLY =0x17 //服务回复

var THING_PROP_POST_METHOD = 'thing.property.post'
var THING_EVENT_POST_METHOD = 'thing.event.post'
var THING_PACK_POST_METHOD = 'thing.pack.post'
var THING_HISOTORY_METHOD = 'thing.history.post'
var THING_POST_REPLY_METHOD = 'thing.post.reply'
var THING_PROP_SET_METHOD = 'thing.property.set'
var THING_PROP_SET_REPLY_METHOD = 'thing.property.set.reply'
var THING_PROP_GET_METHOD = 'thing.property.get'
var THING_PROP_GET_REPLY_METHOD = 'thing.property.get.reply'

/**
  * 
  * 示例数据：
  * 属性设置返回结果：
  * 传入参数：
  * 0x1502010008 命令类型[1字节]+消息id[1字节]+执行结果[1字节]+数据值[2字节]
  * 输出结果：
  * {"id":"2", "code":"200", "msg": "success", "data":{ "power": 8 }}
  *
  */
function rawDataToJson (rawData) {
  var uint8Array = new Uint8Array(rawData.length)
  for (var i = 0; i < rawData.length; i++) {
    uint8Array[i] = rawData[i] & 0xff
  }
  var dataView = new DataView(uint8Array.buffer, 0)
  var jsonMap = { 'version': '1.0' }

  var fHead = uint8Array[0] // 读取第一个字节为command命令
  
  (fHead === COMMAND_SET_REPLY) {
    jsonMap['method'] = THING_PROP_SET_REPLY_METHOD
    jsonMap['id'] = '' + dataView.getInt8(1)
    jsonMap['code'] =  dataView.getUint8(2)
    jsonMap['msg'] = jsonMap['code'] ? 'success' : 'failed'
    jsonMap['data'] = {
      'temp': dataView.getInt16(2) 
    }

  } else if (fHead === COMMAND_GET_REPLY) {
    jsonMap['method'] = THING_PROP_GET_REPLY_METHOD
    jsonMap['id'] = '' + dataView.getInt8(1)
    jsonMap['code'] = '' + dataView.getUint8(2)
    jsonMap['msg'] = jsonMap['code'] ? 'success' : 'failed'
    jsonMap['data'] = { 
      'power': dataView.getUint16(3) 
    }
  } else if(fHead === COMMAND_SERVICE_REPLY) {
    // 命令类型[1] + 消息ID[1] + 执行结果[1字节] + 服务类型[1字节] + 参数1[1字节]
    jsonMap['id'] = '' + dataView.getInt8(1)
    jsonMap['code'] = 200
    var serviceName = 'cmd'
    jsonMap['method'] = 'thing.service.' + serviceName + '.reply'
    jsonMap['data'] = { 
      'fan1': '1234'  // 回复的参数
    }
  } 
  return jsonMap
}

/**
  * 示例数据
  * 下发属性设置指令： 
  * 传入参数：
  * {"method":"thing.property.set", "version": "1.0", "id": 2, "params":{ "power": 8 }}
  * 输出结果：
  * 0x05020008  命令类型[1字节]+消息id[1字节]+数据值[2字节]
  *
  */
function jsonToRawData (json) {
  var method = json['method']
  var id = json['id']
  var payloadArray = []
  
  if (method === THING_PROP_SET_METHOD) // 属性设置。
  {
    var params = json['params']
    var temp = params['temp']
    var humi = params['humi']
   
    payloadArray = payloadArray.concat(buffer_uint8(COMMAND_SET)) // command字段。
    payloadArray = payloadArray.concat(buffer_uint8(parseInt(id))) // 消息id
    payloadArray = payloadArray.concat(buffer_int16(parseInt(temp))) // 消息值
    
    payloadArray = payloadArray.concat(buffer_uint8(COMMAND_SET)) // command字段。
    payloadArray = payloadArray.concat(buffer_uint8(parseInt(id))) // 消息id
    payloadArray = payloadArray.concat(buffer_int16(parseInt(humi))) // 消息值
  
  } else if (method === THING_PROP_GET_METHOD) {
    
    var params = json['params']
    payloadArray = payloadArray.concat(buffer_uint8(COMMAND_GET)) // command字段。
    payloadArray = payloadArray.concat(buffer_uint8(parseInt(id)))
    payloadArray = payloadArray.concat(buffer_uint8(params.length))
  
  } else if (method === THING_POST_REPLY_METHOD) {
    var code = json['code']
    var value = code === 200 ? 1 : 0

    payloadArray = payloadArray.concat(buffer_uint8(COMMAND_POST_REPLY)) // 命令码
    payloadArray = payloadArray.concat(buffer_uint8(parseInt(id))) // 消息id
    payloadArray = payloadArray.concat(buffer_uint8(value)) // 消息值
 
  } else if(method.startsWith('thing.service')){
    // 命令类型[1] + 消息ID[1] + 服务类型[1字节] + 服务参数1[2字节] + 服务参数2[2字节]

    var params = json['params']
    var serviceName = 1
    var cmd1 = params['cmd1']

    payloadArray = payloadArray.concat(buffer_uint8(COMMAND_SERVICE)) // command字段。
    payloadArray = payloadArray.concat(buffer_uint8(parseInt(id))) // 消息id
    payloadArray = payloadArray.concat(buffer_uint8(parseInt(serviceName))) // 消息类型
    payloadArray = payloadArray.concat(buffer_int16(parseInt(cmd1))) // 消息类型
  }
  return payloadArray
}

//将8位无符号整形转换为byte数组
function buffer_uint8(value) {
  var uint8Array = new Uint8Array(1);
  var dataView = new DataView(uint8Array.buffer);
  dataView.setUint8(0, value);
  return [].slice.call(uint8Array);
}

//将16位无符号整形转换为byte数组
function buffer_int16 (value) {
  var uint8Array = new Uint8Array(2)
  var dv = new DataView(uint8Array.buffer, 0)
  dv.setInt16(0, value)
  return [].slice.call(uint8Array)
}
```

##### 属性设置测试

「运维监控」下选择设备调试功能，调试页面选择产品下某一设备，使用应用模拟器模拟平台属性设置命令下发。

<center>
    <img width="90%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/script/脚本示例单功能点属性设置.png">
</center>

```

设备侧收到： 
+MIPLWRITE:0,35605,20,1,0,2,16,050D0000050D0016,0
- 05代表下行设置报文，0D为消息id，000b为temp参数设置值，05代表下行设置报文，0D为消息id，
0016为humi参数设置值

设备侧回复：
AT+MIPLWRITERSP=0,35605,2
- 其中35605要和下行报文的msg id一致
```

##### 服务调用测试

功能测试前，在产品物模型下添加服务功能点，标识符cmd，调用方式同步。

<center>
    <img width="90%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/script/脚本示例服务功能点.png">
</center>

「运维监控」下选择设备调试功能，调试页面选择产品下某一设备，使用应用模拟器模拟平台服务命令下发。

<center>
    <img width="90%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/script/脚本示例服务调用测试.png">
</center>

```

设备侧收到： 
+MIPLWRITE:0,27233,20,1,0,2,10,073C01000C,0
- 07代表服务调用报文，3C为消息id，01代表服务参数类型（整型、浮点型等），000C为服务参数cmd1的设置值

设备侧回复：
AT+MIPLWRITERSP=0,27233,2
AT+MIPLNOTIFY=0,0,20,1,0,6,4,"173C",0,0
- 17代表下行服务报文, 3C为消息id
```

<center>
    <img width="90%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/script/脚本示例服务调用响应.png">
</center>