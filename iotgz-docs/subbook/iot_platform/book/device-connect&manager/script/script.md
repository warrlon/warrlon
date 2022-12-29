# 脚本开发

<a href="#1">1. 脚本编辑</a>

<a href="#2">2. 脚本调试及发布</a>

<a href="#3">3. 物模型上行输出格式定义</a>

<a href="#4">4. 物模型下行输入格式定义</a>

<a href="#5">5. 脚本示例</a>

---

<h3 id="1">1. 脚本编辑</h3>

透传/自定义产品详情页面，选择数据解析标签，页面展示脚本编辑框，用户在编辑框内完成数据解析脚本开发，如图所示。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/script/数据解析脚本编辑.png">
</center>
<br/>

数据解析脚本支持以JavaScript语言开发，脚本需要实现如下两个函数方式：

* rawDataToJson：上行解析函数，按照产品物模型定义，将设备上报二进制数据转换为标准物模型Json数据格式，主要实现设备数据上报和命令回复响应两类数据解析。函数输出的物模型数据必须符合平台规范，具体格式要求见：<a href="#3">物模型上行输出格式定义</a>。

```java
/**
  * 上行解析函数，将设备上报的自定义二进制数据解析为平台物模型数据
  * 可实现两类数据的解析：设备上报数据及设备命令响应数据
  * @params rawData byte[]数组 设备上报的二进制字节数组
  * @return jsonObj json对象 解析后的物模型json数据，格式见文档说明
  */
function rawDataToJson(rawData）{
    var jsonObj = {};
    return jsonObj;
} 
```

* jsonToRawData: 下行解析函数，将平台下发给设备的标准物模型数据转换为设备侧自定义二进制数据，主要实现平台命令下发和设备数据上报响应两类数据转换。平台物模型数据作为函数入参，具体格式要求见：<a href="#4">物模型下行输入格式定义</a>。

```java

/**
 * 下行转换函数，将平台下行的物模型JSON数据编码为设备自定义二进制数据
 * 可实现两类数据的转换：平台命令下发及设备上报响应
 * @params jsonObj json对象 平台构造的物模型josn数据，格式见文档说明
 * @return rawData byte[]数组 转换后的二进制数据
 */
function jsonToRawData(jsonObj）{
    var rawData = [];
    return rawData;
}
```

**脚本开发说明**：

    (1)JavaScript语言开发，语法规则需遵循ECMAScript5.1规范。
    (2)JavaScript脚本大小不能超过256K限制。
    (3)脚本必须实现平台定义的两个函数方法，否则无法正常保存。
    (4)上行解析函数输入参数和下行转换函数的输出参数均为字节数组，数组元素为整型，取值范围为[0,255]。
    (5)脚本开发前，请确保已完成产品物模型功能点定义，且解析的物模型数据在平台有对应功能点。

<h3 id="2">2. 脚本调试及发布</h3>

脚本编辑完成后进行在线脚本调试，调试页面选择模拟输入类型，输入模拟数据，点击调试按钮，测试脚本功能，如图所示。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/script/数据解析脚本调试.png">
</center>
<br/>

脚本调试模拟输入包括以下两种：

<table>
<tr><th>模拟输入类型</th><th>输入说明</th><th width="35%">示例</th></tr>
<tr><td>设备上行数据</td><td>模拟设备上报自定义二进制数据</td><td>输入以0x开头的十六进制字符串，例如：0xffff </td></tr>
<tr><td>设备下行数据</td><td>模拟平台下发物模型Json数据</td><td>输入json字符串，例如：{,"id":"16","version":"1.0","params":{"fileName":"12","size":12,"fileID":"12"},"method":"thing.service.$SyncGetFile.invoke"}</td></tr>
</table>

<br/>

数据解析脚本经过调试即可进行发布操作，发布后，切换线上脚本标签，即可看到系统正在运行的数据解析脚本，如图所示。如需修改运行的解析脚本，切换至脚本草稿重新编辑发布。

<center>
    <img width="95%" style="box-shadow: 5px 5px 10px rgba(0,0,0,0.4);" 
    src="/images/iot_platform/script/数据解析脚本发布.png">
</center>
<br/>

**调试及发布说明**

    (1)脚本只有调试通过后（即脚本运行正常，无异常报错），才能进行发布操作。
    (2)页面「开启脚本对比」功能，提供草稿箱脚本与线上运行脚本文件对比功能。
    (3)页面「导入线上脚本」功能，可将线上运行脚本直接加载至当前脚本编辑框中，加载时会覆盖脚本草稿里已有文件内容。


<h3 id="3">3. 物模型上行输出格式定义</h3>

物模型上行输出类型包括：属性上报、事件上报、属性设置响应、属性获取响应、服务调用响应。

```java

// 属性上报
{ 
    "id": "1001",
    "version": "1.0",
    "params": {
        "power": {
            "value"："30.5"，
            "time": 1524448722123
        } 
    },
    "method": "thing.property.post"
}

// 事件上报
{ 
    "id": "1001",
    "version": "1.0",
    "params": {
        "identifier": {
            "value"：{
                "power": "on",
                "switch": "on"
            } 
        }  
    }
    "method": "thing.event.post"
}

// 批量数据上报
{ 
    "id": "1001",
    "version": "1001",
    "params": [{
        "properties": {
            "power": {
                "value"："30.5"，
                "time": 1524448722123
            } 
        },
        "event"：{
            "alarmEvent1": {
                "value": {
                    "Power":"on",
                    "WF":"2"
                },
                "time":1524448722000
            },
        }
    }],
    "method": "thing.pack.post"
}

// 历史数据上报
{ 
    "id": "1001",
    "version": "1001",
    "params": [{
        "properties": {
            "power": [{
                "value"："30.5"，
                "time": 1524448722123
            },{
                "value"："30.5"，
                "time": 1524448722170
            }] 
        },
        "event"：{
            "alarmEvent1": [{
                "value": {
                    "Power": "on",
                    "WF": "2"
                },
                "time":1524448722000
            },{
                "value": {
                    "Power": "on",
                    "WF": "10"
                },
                "time":1524448722111
            }]
        }
    }],
    "method": "thing.history.post"
}

// 属性设置响应
{ 
    "id": "1001",
    "code": 200,
    "msg":"success"，
    "method": "thing.property.set.reply"
}

// 属性获取响应
{ 
    "id": "1001",
    "code": 200,
    "msg": "success",
    "data": {
      "power": "on"
    }
    "method": "thing.property.get.reply"
}

// 服务调用响应
{ 
    "id": "1000",
    "code": 200,
    "msg": "success",
    "data": {
        "temperature" : "30.5"
    },
    "method": "thing.service.{identifier}.reply"  // identifier为服务标识
}
```

<h3 id="4">4. 物模型下行输出格式定义</h3>

物模型下行输出类型包括：属性设置、属性获取、服务调用及设备上报响应。

```java

// 属性设置
{ 
    "id": "1001",
    "version": "1.0",
    "params": {
        "power": "27"
    },
    "method": "thing.property.set"
}

// 属性获取
{ 
    "id": "1001",
    "version": "1.0",
    "params": ["power","switch"],
    "method": "thing.property.get"
}

// 服务调用
{ 
    "id": "1001",
    "version": "1.0",  
    "params": {
        "power": "28", 
        "switch": "on"
    },
    "method": "thing.service.{identifier}.invoke" // identifier为服务标识
}

// 设备上报响应
{ 
    "id": "1001",
    "code": 200, // 200为成果
    "msg": "success",
    "method": "thing.post.reply"
}
```

<h3 id="5">5. 脚本示例</h3>

本文以产品「温度传感器」为例，展示数据解析脚本的编写示例。在产品下创建物模型功能：1）属性功能点，功能名称（电源开关），标识符（power），数据类型（int32），数据解析脚本如下所示。

```java

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
  * 1.设备上报属性
  * 传入参数：
  * 0x01010007  命令类型[1字节]+消息id[1字节]+数据值[2字节] - 功能点power
  * 输出结果：
  * {"method":"thing.property.post", "version":"1.0", "id":"1", "params":{"power": { "value": 7 } }}
  *
  * 2.属性设置的返回结果：
  * 传入参数：
  * 0x1502010008 命令类型[1字节]+消息id[1字节]+执行结果[1字节]+数据值[2字节] - 功能点power
输出结果：
  * {"id":"2", "code":200, "msg": "success", "data":{ "power": 8 }}
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
       'power': {
          'value': value
       }
    }
  } else if(fHead == COMMAND_PACK) {
    jsonMap['method'] = THING_PACK_POST_METHOD
    jsonMap['id'] = '' + dataView.getInt8(1)
    var value = dataView.getInt16(2)
    jsonMap['params'] = [{
      'properties': {
        'power': [{
          'value': value,
          'time': Date.now()
        }]
      }
    }]
  } else if(fHead == COMMAND_HISTORY) {
    jsonMap['method'] = THING_HISOTORY_METHOD
    jsonMap['id'] = '' + dataView.getInt8(1)
    var value = dataView.getInt16(2)
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
    jsonMap['code'] = dataView.getUint8(2) ? 200 : 500
    jsonMap['msg'] = jsonMap['code'] ? 'success' : 'failed'
    jsonMap['data'] = {
      'power': dataView.getInt16(3) 
    }
  } else if (fHead === COMMAND_GET_REPLY) {
    jsonMap['method'] = THING_PROP_GET_REPLY_METHOD
    jsonMap['id'] = '' + dataView.getInt8(1)
    jsonMap['code'] = dataView.getUint8(2) ? 200 : 500
    jsonMap['msg'] = jsonMap['code'] ? 'success' : 'failed'
    jsonMap['data'] = { 
      'power': dataView.getUint16(3) 
    }
  }
  return jsonMap
}


/**
  * 示例数据
  * 1. 下发属性设置指令： 
  * 传入参数：
  * {"method":"thing.property.set", "version": "1.0", "id": 2, "params":{ "power": 8 }}
  * 输出结果：
  * 0x05020008  命令类型[1字节]+消息id[1字节]+数据值[2字节]
  *
  * 2. 设备上报响应返回
  * 传入参数：
  * {"method":"thing.post.reply", "id":"1", "code":200}
  * 输出结果：
  * 0x000101 命令类型[1字节]+消息id[1字节]+执行结果[1字节]
*/
function jsonToRawData (json) {
  var method = json['method']
  var id = json['id']
  var payloadArray = []

  if (method === THING_PROP_SET_METHOD) // 属性设置。
  {
    var params = json['params']
    var power = params['power']

    payloadArray = payloadArray.concat(buffer_uint8(COMMAND_SET)) // command字段。
    payloadArray = payloadArray.concat(buffer_uint8(parseInt(id))) // 消息id
    payloadArray = payloadArray.concat(buffer_int16(parseInt(power))) // 消息值
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