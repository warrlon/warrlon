# 快速接入套件开放API

行业开发平台支持在线调试API。

#### [&#9755; API调试入口 &#9754;](https://open.iot.10086.cn/hewu/open-website/docs/rest#doc)

#### &#128366; 调试必读：

&#10004; 所有请求Header

<h4><font color=#CD8162>Content-Type: application/json</font></h4>

&#10004; 统一前缀

<h4><font color=#CD8162>{domain}/hewu/open-api/{version}/{apiUrl}</font></h4>
 
其中domain为<font color=#CD8162>https://open.iot.10086.cn</font>，version代表当前版本号<font color=#CD8162>v1</font>，apiUrl代表<font color=#CD8162>URL地址</font>。

&#10004; 关于鉴权

若无特殊说明，均使用鉴权方式。header携带服务端交换的token, header中key为project-token,文档中"鉴权"说明均是相应key对应的token。

> 示例：调用2.1创建群组Key接口时，需要在请求中设置key为project-token，value为masterKey换取的token的header。

&#10004; 关于响应

所有响应中包含code/msg 字段说明。

<font color=#CD8162>{code:200, msg:'OK'}</font>表示请求成功。<font color=#CD8162>data</font>字段为具体数据，当code不为200时，msg为相应错误原因。

&#10004;关于分页

tag <font color=#CD8162>pagenation</font> 表示该接口可传分页参数，query参数可携带<font color=#CD8162>{offset: 0, limit: 10}</font>。

其中limit为<font color=#CD8162>每页显示条数</font>，offset为<font color=#CD8162>跳过的数据条数</font>。

默认值：limit为10,offset为0，响应中data.count表示<font color=#CD8162>数据总条数</font>。

&#10004;关于key

<font color=#CD8162>群组Key</font>代表一个群组的key，<font color=#CD8162>masterKey</font>代表项目唯一的key</font>。

&#10004; 关于加密

接口中所有传输的key(群组Key/masterKey)可选择<font color=#CD8162>加密</font>和<font color=#CD8162>非加密</font>模式，<font color=#CD8162>默认加密</font>(使用API列表下方的加解密方法)，如果非加密，请传query参数unencrypted为true。

#### API列表

<table>
<tr><th width="20%">类别</th><th>API名称</th></tr>
<tr><td>设备生产商</td><td>指生产各类单品设备的厂商，不太关注整体应用/项目，主要以单品硬件设备销售获取利润。</td></tr>

- 1 鉴权类API
  - 1.1 [换取token](#11)
- 2 Key相关API
  - 2.1 [创建群组Key](#21)
  - 2.2 [重置群组Key](#22)
  - 2.3 [获取项目所有群组Key](#23)
  - 2.4 [删除群组Key](#24)
- 3 设备相关API
  - 3.1 [群组Key添加设备](#31)
  - 3.2 [群组Key移除设备](#32)
  - 3.3 [设备列表](#33)
  - 3.4 [命令下发](#34)
  - 3.5 [命令下发日志查询](#35)
  - 3.6 [修改设备](#36)
  - 3.7 [设备详情](#37)
  - 3.8 [设备分享](#38)
  - 3.9 [取消分享](#39)
- 4 项目相关API
  - 4.1 [获取项目下授权产品](#41)
  - 4.2 [项目创建设备配网](#42)
  - 4.3 [项目设备配网结果查询](#43)
- 5 工具类相关API
  - 5.1 [获取省市区三级联动详情](#51)
  - 5.2 [获取第三方数据](#52)
- 6 联动管理相关API
  - 6.1 [创建联动](#61)
  - 6.2 [修改联动](#62)
  - 6.3 [联动详情](#63)
  - 6.4 [联动列表](#64)
  - 6.5 [联动执行日志查询](#55)
- 附件
  - 附件一 [加/解密算法](#a1)
  - 附件二 [错误码对应表](#a2)
  - 附件三 [第三方数据说明](#a3)

## 1. 鉴权类API

### 1.1 <span id="11">换取token</span>
- URL地址: `/sys/auth`
- HTTP方法: GET
- 描述: 根据项目的 masterKey/群组Key 换取对应的token,可使用该token进行鉴权
- 鉴权: false
- 请求参数：

| 字段 | 位置 | 必传 | 类型 | 描述 | 备注 |
| - | - | - | - | - | - |
| refresh | query | false | enum | 刷新当前key对应token(会删除key交换的其他token) | 默认false,可选值 [true, false] |
| project-id | header | true | string | 项目ID | - |
| confirm-code | header | true | string | 加密后的key | 加密算法详见附件一 |
| unencrypted | query | false | string | 是否key不加密 | enum ['true','false'] |

- 响应内容:

| 字段 | 类型 | 描述 |
| - | - | - |
| token | string | 当前key对应token |

- 请求响应示例：

```javascript
// request
url: "/hewu/open-api/v1/sys/auth?refresh=true&unencrypted=true"
header: {
  "project-id": "123456",
  "confirm-code": "123xcwex23dsc3243ffds"
}
// response
{
  code: 200,
  msg: "OK",
  data: {
    token: "5bc7fecbfecb51004743350f"
  }
}
```

## 2. Key相关API

### 2.1 <span id="21">创建群组Key</span>
- URL地址: `/keys/create`
- HTTP方法: POST
- 鉴权: masterKey
- 描述: 创建 群组Key,**创建后只可重置，不可删除**
- 请求参数：

| 字段 | 位置 | 必传 | 类型 | 描述 | 备注 |
| - | - | - | - | - | - |
| count | body | true | number | 创建群组Key个数 | 0 < count < 10 |
| unencrypted | query | false | string | 是否key不加密 | enum ['true','false'] |

- 响应内容:

| 字段 | 类型 | 描述 | 备注 |
| - | - | - | - |
| keys | array | 当前key数组 | - |

- 请求响应示例：

```javascript
// request
url: "/hewu/open-api/v1/keys/create?unencrypted=true"
body: {
  count: 2
}
// response
{
  code: 200,
  msg: "OK",
  data: {
    keys: ["5bc7fecbfecb51004743350f", "5bc7fecbfecb51004743350f"]
  }
}
```

### 2.2 <span id="22">重置群组Key</span>
- URL地址: `/keys/reset`
- HTTP方法: PUT
- 鉴权: masterKey/群组Key自身
- 描述: 重置key后，旧key和对应token都失效
- 请求参数：

| 字段 | 位置 | 必传 | 类型 | 描述 | 备注 |
| - | - | - | - | - | - |
| confirm-code | header | true | string | key value值 | - |
| unencrypted | query | false | string | 是否key不加密 | enum ['true','false'] |

- 响应内容:

| 字段 | 类型 | 描述 | 备注 |
| - | - | - | - |
| key | string | 重置后的key | - |

- 请求响应示例：

```javascript
// request
url: "/hewu/open-api/v1/keys/reset?unencrypted=true"
header: {
  "confirm-code": "123xcwex23dsc3243ffds"
}
// response
{
  code: 200,
  msg: "OK",
  data: {
    key: "5bc7fecbfecb51004743350f"
  }
}
```

### 2.3 <span id="23">获取项目所有群组Key</span>
- URL地址: `/keys`
- HTTP方法: GET
- 鉴权: masterKey
- 描述: 
- 请求参数：

| 字段 | 位置 | 必传 | 类型 | 描述 | 备注 |
| - | - | - | - | - | - |
| project_id | query | true | string | 项目ID | - |
| unencrypted | query | false | string | 是否key不加密 | enum ['true','false'] |

- 响应内容:

| 字段 | 类型 | 描述 | 备注 |
| - | - | - | - |
| keys | array | 当前key数组 | - |

- 请求响应示例：

```javascript
// request
url: "/hewu/open-api/v1/keys?project_id=123456&unencrypted=true"
// response
{
  code: 200,
  msg: "OK",
  data: {
    keys: ["5bc7fecbfecb51004743350f", "5bc7fecbfecb51004743350f"]
  }
}
```
### 2.4 <span id="24">删除群组Key</span>
- URL地址: `/keys/value`
- HTTP方法: DELETE
- 鉴权: masterKey
- 描述: 删除了群组Key后，所有 分享/绑定 的设备，都会移除关系
- 请求参数：

| 字段 | 位置 | 必传 | 类型 | 描述 | 备注 |
| - | - | - | - | - | - |
| key-value | header | true | string | 群组Key | 原始的群组Key值|
| unencrypted | query | false | string | 是否key不加密 | enum ['true','false'] |

- 响应内容:
| 字段 | 类型 | 描述 | 备注 |
| - | - | - | - |
| slaver_key | string | 原始的群组Key值 | |

- 请求响应示例：

```javascript
// request
url: "/hewu/open-api/v1/keys/value?unencrypted=true"
header: {
  "key-value": "5d0c937df03e1055e82693ca"
}
// response
{
  code: 200,
  msg: "OK",
  data: {
  "slaver_key" :"5d0c937df03e1055e82693ca"
  }
}
```

## 3. 设备相关API

### 3.1 <span id="31">群组Key添加设备</span>
- URL地址: `/devices/add`
- HTTP方法: POST
- 鉴权: masterKey
- 描述: 
- 请求参数：

| 字段 | 位置 | 必传 | 类型 | 描述 | 备注 |
| - | - | - | - | - | - |
| slaver_key | body | true | string | slaver_key的值 | - |
| bind_type | query | false | string | 绑定方式 设备id/设备唯一标示，默认设备id | enum [dev_id, dev_key] |
| devices | body | true | array | 设备数组 | device对象数组 |
| device.id | body | false | string | 设备24位objectId | bind_type为dev_id时必传 |
| device.dev_key | body | false | string | 设备唯一标识 | bind_type为dev_key时必传 |
| device.pid | body | false | string | 产品OneNET id | bind_type为dev_key时必传 |
| device.name | body | false | string | 设备名称 | - |
| unencrypted | query | false | string | 是否key不加密 | enum ['true','false'] |

- 响应内容:

| 字段 | 类型 | 描述 | 备注 |
| - | - | - | - |
| results | array | 添加结果对象数组 | 后续用reslut.xx表示每个对象属性 |
| reslut.id | string | 设备id | 24位objectId，bind_type=dev_id时返回 |
| reslut.name | string | 设备名称 | 设备名称为空时默认为产品名称 |
| reslut.msg | string | 添加失败原因 | - |
| reslut.pid | string | 产品id | bind_type=dev_key时返回 |
| reslut.dev_key | string | 设备标识 | bind_type=dev_key时返回 |
| reslut.success | boolean | 是否添加成功 | - |

- 请求响应示例：

```javascript
// request
url: "/hewu/open-api/v1/devices/add?unencrypted=true"
body: {
  slaver_key: "5bc7fecbfecb51004743350e",
  devices: [
    {
      id: "5bc7fecbfecb51004743350f",
      name: "测试设备"
    }, {
      id: "5bc7fecbfecb51004743350m",
      name: "测试设备2"
    }
  ]
}
// response
{
  code: 200,
  msg: "OK",
  data: {
    results: [
      {
        "id": "5d1ad03193295aae5fbaa928",
        "name": "测试设备",
        success: true
      },
      {
        "id": "5d1ad03193295aae5fbaa929",
        "msg": "不属于当前项目",
        success: false
      },
      {
        "id": "5d1b0cf393295aae5fbcd405",
        "msg": "重复添加",
        success: false
      }
    ]
  }
}
```

### 3.2 <span id="32">群组Key移除设备</span>
- URL地址: `/devices/remove`
- HTTP方法: DELETE
- 鉴权: masterKey
- 描述: 
- 请求参数：

| 字段 | 位置 | 必传 | 类型 | 描述 | 备注 |
| - | - | - | - | - | - |
| slaver_key | query | true | string | slaver_key的值 | - |
| device_ids | query | true | string | 所有移除设备的id | 以逗号分割 |
| unencrypted | query | false | string | 是否key不加密 | enum ['true','false'] |

- 响应内容:

| 字段 | 类型 | 描述 | 备注 |
| - | - | - | - |
| results | array | 操作结果对象数组 | 后续用result.xx表示对象属性 |
| result.id | string | 设备id | 24位objectId |
| result.success | boolean | 是否成功 | - |
| result.msg | string | 移除失败原因 | - |
| result.code | integer | 失败code | 仅移除失败时有，具体与msg对应关系详见附录二 |

- 请求响应示例：

```javascript
// request
url: "/hewu/open-api/v1/devices/remove?slaver_key=5bc7fecbfecb51004743350e&device_ids=5bc7fecbfecb51004743350m,5bc7fecbfecb51004743350f&unencrypted=true"
// response
{
  code: 200,
  msg: "OK",
  data: {
    "results": [
        {
          "id": "5d1ad03193295aae5fbaa928",
          "msg": "OK",
          success: true
        },
        {
          "id": "5d1ad03193295aae5fbaa929",
          "msg": "当前key下无此设备",
          success: false
        }
      ]
  }
}
```

### 3.3 <span id="33">设备列表</span>
- URL地址: `/devices`
- HTTP方法: GET
- Tag: pagenation
- 鉴权: masterKey/群组Key
- 描述: 获取当前key下的设备列表(包括分享设备)，masterKey查询该产品接入所有设备
- 请求参数：

| 字段 | 位置 | 必传 | 类型 | 描述 | 备注 |
| - | - | - | - | - | - |
| product_id | query | true | string | 产品OneNET id | 支持查询多个产品的设备，以逗号分隔 |

- 响应内容:

| 字段 | 类型 | 描述 | 备注 |
| - | - | - | - |
| count | number | 设备总数量 | - |
| devices | array | 设备数组 | item为device对象 |
| device._id | string | 设备id | - |
| device.sn | string | 设备sn | - |
| device.name | string | 设备名称 | - |
| device.online | boolean | 设备是否在线 | - |
| device.product_id | string | 设备所属产品OneNET id | - |
| device.slaver_key | string | 设备所属群组Key | key已加密 |

- 请求响应示例：

```javascript
// request
url: "/hewu/open-api/v1/devices?product_id=123456,111111&offset=0&limit=20"
// response
{
  code: 200,
  msg: "OK",
  data: {
    count: 24,
    devices: [
      {
        _id: "5bc7fecbfecb51004743350a",
        sn: "sdfe234",
        name: "冰箱",
        online: true,
        product_id: "32654",
        slaver_key:"5bc7fecbfecb51004743350m"
      }
    ]
  }
}
```

### 3.4 <span id="34">命令下发</span>
- URL地址: `/devices/send-order`
- HTTP方法: POST
- 鉴权: masterKey/群组Key
- 描述: 同一产品可批量下发(命令<50)，masterKey可给所有设备发送命令，群组Key只可给 拥有/被分享 设备发送命令
- 请求参数：

| 字段 | 位置 | 必传 | 类型 | 描述 | 备注 |
| -----|---- | ---- |---- |---- |---- |
| pid | body | true | string | OneNET产品id | - |
| sync | body | false | boolean | 是否同步下发 | 默认false,异步下发 |
| orders | body | true | array | 具体命令 | order对象 |
| order.product_type | body | false | string | 产品类型 | enum:["infrared","common"]，分别代表红外设备、普通设备，不传默认为common |
| order.sn | body | true | string | 设备sn | - |
| order.function_index | body | true | number | 功能点index | - |
| order.function_type | body | true | string | 功能点类型 | enum: ['BOOLEAN', 'INTEGER', 'FLOAT', 'ENUM', 'STRING'] |
| order.value | body | true | string | 具体命令 | - |
| order.offline | body | false | boolean | 是否为离线命令 | 仅针对NB设备命令下发，默认为false |
| order.expired_time | body | false | number | 离线命令过期时间,时间戳 | 仅针对NB设备命令下发，需要大于当前时间，默认值为当前时间+6000ms |

- 响应内容:

| 字段 | 类型 | 描述 | 备注 |
| -----|---- | ---- |---- |
| success | array | 下发命令成功的设备列表 | s代表其中一个设备 |
| s.sn | string | 设备sn | - |
| s.function_type | string | 功能点类型 | - |
| s.function_index | number | 功能点index | - |
| s.value | any | 具体命令 | - |
| s.msg | string | 下发结果 | 同步下发才有 |
| s.success | any | 下发是否成功 | 同步下发才有 |
| s.task_id | string | 命令id | MQ推送中有这条命令下发结果回传,也可通过接口查询命令下发结果 |
| fail | array | 下发命令失败的设备列表 | f代表其中一个设备 |
| f.sn | string | 设备sn | - |
| f.function_type | string | 功能点类型 | - |
| f.function_index | number | 功能点index | - |
| f.value | any | 具体命令 | - |
| f.msg | string | 下发结果 | 同步下发才有 |
| f.success | any | 下发是否成功 | 同步下发才有 |
| f.task_id | string | 命令id | MQ推送中有这条命令下发结果回传,也可通过接口查询命令下发结果 |

- 请求响应示例：

```javascript
// request
url: "/hewu/open-api/v1/devices/send_order"
body: {
  pid: "1234",
  orders: [
    {
      sn: "hw-1123",
      function_index: 1,
      value: "true",
      function_type:"BOOLEAN"
    },
   {
      product_type: "infrared",
      sn: "hw-1124",
      function_index: 3,
      value: "13",
      function_type:"INTEGER"
    }
  ],
  sync: true
}
// response
{
  code: 200,
  msg: "OK",
  data: {
    "success": [
      {
        sn: "hw-1123",
        function_index: 1,
        value: "true",
        function_type:"BOOLEAN",
        task_id: "oxwBXSKK2f",
        msg: "OK",
        success: true
      }
    ],
    "fail": [
      {
        sn: "hw-1124",
        function_index: 3,
        value: "13",
        function_type:"INTEGER",
        task_id: "QcVFUVO5cQ",
        msg: "device not found",
        success: false
      }
    ]
  }
}
```

### 3.5 <span id="35">命令下发日志查询</span>
- URL地址: `/devices/order-feedbacks`
- HTTP方法: GET
- 鉴权: masterKey/群组Key
- 描述: 根据下发命令的task_id，查询命令下发结果
- 请求参数：

| 字段 | 位置 | 必传 | 类型 | 描述 | 备注 |
| - | - | - | - | - | - |
| task_ids | query | true | string | 下发命令后response里的task_id | 逗号分割task_id |

- 响应内容:

| 字段 | 类型 | 描述 | 备注 |
| - | - | - | - |
| feedbacks | array | 具体命令 | feedback对象 |
| feedback.msg | string | 下发失败原因 | - |
| feedback.success | boolean | 下发结果 | - |
| feedback.uuid | string | 命令id | MQ推送中有这条命令下发结果回传,也可通过接口查询命令下发结果 |

- 请求响应示例：

```javascript
// request
url: "/hewu/open-api/v1/devices/order_feedbacks?task_ids=aYvg6s3HTf,fYvg6s3HTf"
// response
{
  code: 200,
  msg: "OK",
  data: {
    feedbacks: [
      {
        uuid: "fYvg6s3HTf",
        success: true,
        msg: "OK"
      },
      {
        uuid: "aYvg6s3HTf",
        success: false,
        msg: "device offline"
      }
    ]
  }
}
```
### 3.6 <span id="36">修改设备</span>
- URL地址: `/devices/:id`
- HTTP方法: PATCH
- 鉴权: masterKey/群组Key
- 描述: 修改设备
- 请求参数：

| 字段 | 位置 | 必传 | 类型 | 描述 | 备注 |
| - | - | - | - | - | - |
| id | path | true | string | 设备 _id | - |
| name | body | true | string | 设备名称 | - |

- 响应内容:

| 字段 | 类型 | 描述 | 备注 |
| - | - | - | - |
| _id | string | 设备id | - |
| sn | string | 设备sn | - |
| name | string | 设备名称 | - |
| online | boolean | 设备是否在线 | - |
| product_id | string | 设备所属产品OneNET id | - |
| slaver_key | string | 设备所属群组Key | key已加密 |

- 请求响应示例：

```javascript
// request
url: "/hewu/open-api/v1/devices/5bc7fecbfecb51004743350e"
body: {
  name: "测试设备"
}
// response
{
  code: 200,
  msg: "OK",
  data: {
    _id: "5bc7fecbfecb51004743350a",
    sn: "sdfe234",
    online: true,
    name: "测试设备",
    product_id: "32654",
    slaver_key: "5bc7fecbfecb51004743350m"
  }
}
```

### 3.7 <span id="37">设备详情</span>
- URL地址: `/devices/:id`
- HTTP方法: GET
- 鉴权: masterKey/群组Key
- 描述: 获取设备详情
- 请求参数：

| 字段 | 位置 | 必传 | 类型 | 描述 | 备注 |
| - | - | - | - | - | - |
| id | path | true | string | 设备 _id | - |
| unencrypted | query | false | string | 是否key不加密 | enum ['true','false'] |

- 响应内容:

| 字段 | 类型 | 描述 | 备注 |
| - | - | - | - |
| _id | string | 设备id | - |
| sn | string | 设备sn | - |
| name | string | 设备名称 | - |
| online | boolean | 设备是否在线 | - |
| device_status | enum | 设备状态['nonactivated', 'bind', 'unbind']['未激活', '已绑定', '未绑定'] | - |
| product_id | string | 设备所属产品OneNET id | - |
| slaver_key | string | 设备绑定的群组Key Value | key已加密 |


- 请求响应示例：

```javascript
// request
url: "/hewu/open-api/v1/devices/5bc7fecbfecb51004743350e?unencrypted=true"
// response
{
  code: 200,
  msg: "OK",
  data: {
    _id: "5bc7fecbfecb51004743350a",
    sn: "sdfe234",
    online: true,
    name: "测试设备",
    product_id: "32654",
    device_status: 'bind',
    slaver_key: "5bc7fecbfecb51004743350m"
  }
}
```

### 3.8 <span id="38">分享key</span>
- URL地址: `/devices/:id/key-share`
- HTTP方法: POST
- 鉴权: masterKey/群组Key，如果鉴权是masterkey可以分享给任一群组Key,如果是slaverykey需要判断当前设备关联的key是否有再分享的权利
- 描述: 将设备控制权限分享给群组Key
- 请求参数：

| 字段 | 位置 | 必传 | 类型 | 描述 | 备注 |
| - | - | - | - | - | - |
| id | path | true | string | 设备 _id | - |
| key_value | body | true | string | 被分享的加密后的keyValue | - |
| can_share | body | false | string | 能否再分享，true时该key能够继续分享给其它key,只有鉴权是master或key绑定该设备的关系类型为OWNER能设置 | - |
| unencrypted | query | false | string | 是否key不加密 | enum ['true','false'] |

- 响应内容:

| 字段 | 类型 | 描述 | 备注 |
| - | - | - | - |
| _id | string | 设备关系id | - |
| type | string | 设备关系的类型 | - |
| key_value | string | 设备关系的加密后的key的value | - |
| d_id | string | 设备id | - |
| can_share | boolean | 能否再分享 | - |


- 请求响应示例：

```javascript
// request
url: "/hewu/open-api/v1/devices/5bc7fecbfecb51004743350e/key-share?unencrypted=true"
// response
{
  code: 200,
  msg: "OK",
  data: {
    _id: "5bc7fecbfecb51004743350a",
    type: "USER",
    can_share: true,
    d_id: "5bc7fecbfecb51004743350s",
    key_value: "5bc7fecbfecb51004743350m"
  }
}
```

### 3.9 <span id="39">取消分享key</span>
- URL地址: `/devices/:id/key-unshare`
- HTTP方法: POST
- 鉴权: masterKey/群组Key，如果鉴权是masterkey可以取消分享任意类型的项目Key与设备绑定关系,如果是slaverykey只能取消分享'USER'类型的项目Key与设备绑定关系
- 描述: 取消分享给群组Key的设备控制权限
- 请求参数：

| 字段 | 位置 | 必传 | 类型 | 描述 | 备注 |
| - | - | - | - | - | - |
| id | path | true | string | 设备 _id | - |
| key_value | body | true | string | 被取消分享的加密后的keyValue | - |
| unencrypted | query | false | string | 是否key不加密 | enum ['true','false'] |

- 响应内容: 状态码返回204

- 请求响应示例：

```javascript
// request
url: "/hewu/open-api/v1/devices/5bc7fecbfecb51004743350e/key-unshare?unencrypted=true"
// response
{
  code: 204
}
```

## 4. 项目相关API
### 4.1 <span id="41">获取项目下授权产品</span>
- URL地址: `/projects/:id/products`
- HTTP方法: GET
- 鉴权: masterKey/salverKey
- 描述: 获取项目下已授权产品
- 请求参数：

| 字段 | 位置 | 必传 | 类型 | 描述 | 备注 |
| - | - | - | - | - | - |
| id | path | true | string | 项目ID | - |
| product_id | query | false | string | 只查询该产品 | 产品id或者产品OneNET id |
| embed | query | false | string | 此处仅支持['functions'] |  |

- 响应内容:

| 字段 | 类型 | 描述 | 备注 |
| - | - | - | - |
| products | array | 已被授权产品数组 | itmes为product对象 |
| product._id | string | 产品id | - |
| product.id | string | 产品OneNET id | - |
| product.name | string | 产品名称 | - |
| product.qrcode_type | string | 二维码类型 | ['ONEPRO', 'EACHDEVICE']-['一产品一码','一物一码'] |
| product.connection | string | 产品联网方式 | - |
| embed | object | 可选响应字段 | - |
| embed.functions | array | 产品的功能点数组 | item为function对象 |
| embed.function._id | string | 功能点id | - |
| embed.function.type | string | 功能点类型 | - |
| embed.function.name | string | 功能点名称 | - |
| embed.function.index | string | 功能点index | - |
| embed.function.product_id | string | 功能点对应产品_id | - |
| embed.function.up | boolean | 可上报 | - |
| embed.function.down | boolean | 可下发 | - |
| embed.function.number | object | 数值型功能点范围和单位 | 仅整型和浮点型功能点返回该字段 |
| embed.function.number.max | integer | 最大值 | - |
| embed.function.number.min | integer | 最小值 | - |
| embed.function.number.step | integer | 间隔 | - |
| embed.function.number.unit | string | 单位 | - |
| embed.function.enum | object |枚举型功能点范围和单位 |仅枚举型功能点返回该字段|
| embed.function.enum.items | array | 具体值|-|
| embed.function.enum.visble | array |可见值 |-|
| embed.function.exception | object | 故障型功能点范围和单位 | 仅故障型功能点返回该字段  |
| embed.function.exception.items | array | 具体值 | -  |
- 请求响应示例：

```javascript
// request
url: "/hewu/open-api/v1/projects/123456/products?embed=functions"
// response
{
  code: 200,
  msg: "OK",
  data: {
    products: [
      {
        _id: "5bc7fecbfecb51004743350a",
        id: "1234",
        name: "灯控",
        connection: "WIFI",
        qrcode_type: "EACHDEVICE"
      }
    ],
    embed: {
      functions: [
        {
          _id: "5bc7fecbfecb51004743350b",
          product_id: "5bc7fecbfecb51004743350a",
          type: "INTEGER",
          name: "开关",
          index: 2,
          up: true,
          down: true,
          number: {
            max: 6500,
            min: 2700,
            step: 100,
            unit: "k"
          },
        }
      ]
    }
  }
}
```

### 4.2 <span id="42">项目创建设备配网</span>
- URL地址: `/project/:id/activate-device`
- HTTP方法: POST
- 鉴权: 群组Key
- 描述: 项目创建设备配网,配网完成后自动和鉴权的群组Key绑定
- 请求参数：

| 字段 | 位置 | 必传 | 类型 | 描述 | 备注 |
| - | - | - | - | - | - |
| id | path | true | string | 项目ID | - |
| valid_time | body | false | number | 配网信息有效时间 | 单位秒，默认180秒,0<valid_time<600秒 |
| type | body | false | string | 枚举值['DEBUG','PRODUCTION'],默认PRODUCTION | - |
| product_id | body | false | string | 产品OneNET id| - |
| device_sn | body | false | string | **设备模组**唯一标识(wifi:sn,蜂窝网:imei) | - |
| chip | body | false | string | NB测试设备唯一标示| - |
| imsi | body | false | string | 用户唯一标识，NB设备必填 | - |

- 响应内容:

| 字段 | 类型 | 描述 | 备注 |
| - | - | - | - |
| id | string | 配网id | - |
| binding_token | string | 配网token | - |
- 请求响应示例：

```javascript
// request
url: "/hewu/open-api/v1/projects/123456/activate-device"
body: {
  id: "ACEDSS",
  type: "PRODUCTION",
  product_id: "4631",
  device_sn: "23cvw3revc"
}
// response
{
  code: 200,
  msg: "OK",
  data: {
    "id": "dsf23fsd",
    "binding_token": "sdv34fsdf24"
  }
}
```

### 4.3 <span id="43">项目设备配网结果查询</span>
- URL地址: `/project/:id/activate-device-feedback`
- HTTP方法: GET
- 鉴权: masterKey/salverKey
- 描述: 项目设备配网结果查询
- 请求参数：

| 字段 | 位置 | 必传 | 类型 | 描述 | 备注 |
| - | - | - | - | - | - |
| id | path | true | string | 项目ID | - |
| connection_id | query | true | string | 4.2创建配网接口返回id | - |

- 响应内容:

| 字段 | 类型 | 描述 | 备注 |
| - | - | - | - |
| success | array | 成功列表 | - |
| success.name | string | 设备名称 |
| success._id | string | 设备id |
| failed | array | 失败列表 | - |
| failed.product_id | string | 产品id | - |
| failed.device_sn | string | 上报的设备sn | - |
| failed.msg | string | 失败原因 | - |
- 请求响应示例：

```javascript
// request
url: "/hewu/open-api/v1/projects/123456/activate-device-feedback?connection_id=dsf23fsd"
// response
{
  code: 200,
  msg: "OK",
  data: {
    "success": [
      { _id: '5bc7fecbfecb51004743350e', name: '灯控' },
      { _id: '5bc7fecbfecb51004743350e', name: '灯控' }
    ],
    "failed": [
      { product_id: '5bc7fecbfecb51004743350e', device_sn: '1234', msg: '错误原因' }
    ]
  }
}
```

## 5. 工具类相关API
### 5.1 <span id="51">获取省市区三级联动详情</span>
- URL地址: `/city`
- HTTP方法: GET
- 鉴权: masterKey/salverKey
- 描述: 获取所有省市区三级联动详情
- 请求参数：

| 字段 | 位置 | 必传 | 类型 | 描述 | 备注 |
| - | - | - | - | - | - |

- 响应内容:

| 字段 | 类型 | 描述 | 备注 |
| - | - | - | - |
| name | string | 省份名称 | - |
| ad_code | string | 省份adcode | - |
| cities | array | 省份下属市 | - |
| cities.name | string | 省份下属市名称 | - |
| cities.ad_code | string | 省份下属市adcode | - |
| city.countries | array | 下属市下属区县 | - |
| cities.countries.name | string | 下属市下属区名称 | - |
| cities.countries.ad_code | string | 下属市下属区adcode | - |

- 请求响应示例：

```javascript
// request
url: "/hewu/open-api/v1/city"

// response
{
  code: 200,
  msg: "OK",
  data: [
    {
      "name": "北京",
      "ad_code": "110000",
      "cities": [
          {
            "name": "北京",
            "ad_code": "110100",
            "countries": [
                {
                    "name": "海淀",
                    "ad_code": "110108"
                },
                {
                    "name": "朝阳",
                    "ad_code": "110105"
                },
                {
                    "name": "顺义",
                    "ad_code": "110113"
                },
                {
                    "name": "怀柔",
                    "ad_code": "110116"
                },
                {
                    "name": "通州",
                    "ad_code": "110112"
                },
                {
                    "name": "昌平",
                    "ad_code": "110114"
                },
                {
                    "name": "延庆",
                    "ad_code": "110119"
                },
                {
                    "name": "丰台",
                    "ad_code": "110106"
                },
                {
                    "name": "石景山",
                    "ad_code": "110107"
                },
                {
                    "name": "大兴",
                    "ad_code": "110115"
                },
                {
                    "name": "房山",
                    "ad_code": "110111"
                },
                {
                    "name": "密云",
                    "ad_code": "110118"
                },
                {
                    "name": "门头沟",
                    "ad_code": "110109"
                },
                {
                    "name": "平谷",
                    "ad_code": "110117"
                },
                {
                    "name": "东城",
                    "ad_code": "110101"
                },
                {
                    "name": "西城",
                    "ad_code": "110102"
                }
            ]
          }
      ]
    },
    {
      "name": "上海",
      "ad_code": "310000",
      "cities": [
          {
            "name": "上海",
            "ad_code": "310100",
            "countries": [
                {
                    "name": "闵行",
                    "ad_code": "310112"
                },
                {
                    "name": "宝山",
                    "ad_code": "310113"
                },
                {
                    "name": "黄浦",
                    "ad_code": "310101"
                },
                {
                    "name": "嘉定",
                    "ad_code": "310114"
                },
                {
                    "name": "浦东新区",
                    "ad_code": "310115"
                },
                {
                    "name": "金山",
                    "ad_code": "310116"
                },
                {
                    "name": "青浦",
                    "ad_code": "310118"
                },
                {
                    "name": "松江",
                    "ad_code": "310117"
                },
                {
                    "name": "奉贤",
                    "ad_code": "310120"
                },
                {
                    "name": "崇明",
                    "ad_code": "310151"
                },
                {
                    "name": "徐汇",
                    "ad_code": "310104"
                },
                {
                    "name": "长宁",
                    "ad_code": "310105"
                },
                {
                    "name": "静安",
                    "ad_code": "310106"
                },
                {
                    "name": "普陀",
                    "ad_code": "310107"
                },
                {
                    "name": "虹口",
                    "ad_code": "310109"
                },
                {
                    "name": "杨浦",
                    "ad_code": "310110"
                }
            ]
          }
      ]
    }
  ]
}
```

### 5.2 <span id="52">获取第三方数据</span>
- URL地址: `/city/:adcode/ext-data`
- HTTP方法: GET
- 鉴权: masterKey/salverKey
- 描述: 获取adcode对应的第三方数据
- 请求参数：

| 字段 | 位置 | 必传 | 类型 | 描述 | 备注 |
| - | - | - | - | - | - |
| adcode | path | true | string | adcode | - |

- 响应内容:

| 字段 | 类型 | 描述 | 备注 |
| - | - | - | - |
| ad_code | string | 城市ad_code | - |
| air_quality | string | 空气质量 | - |
| pm25 | string | pm25质量 | - |
| rainfall | number | 降雨量 | - |
| wind_speed | number | 风速 | - |
| wind_direction | string | 风向 | - |
| weather | string | 天气 | - |
| humidity | string | 湿度 | - |
| temperature | number | 温度 | - |
- 请求响应示例：

```javascript
// request
url: "/hewu/open-api/v1/city/110100/ext-data"
// response
{
  code: 200,
  msg: "OK",
  data: {
    ad_code: "110100",
    air_quality: "EXCELLENT",
    pm25: "EXCELLENT",
    rainfall: 0.0,
    wind_speed: 11,
    wind_direction: "西北风",
    weather: "CLOUDY",
    humidity: "MOIST",
    temperature: 27
  }
}
```
## 6. 联动管理相关API
### 6.1 <span id="61">创建联动</span>
- URL地址: `/rules`
- HTTP方法: POST
- 鉴权: masterKey/salverKey
- 描述: 创建联动
- 请求参数：

| 字段 | 位置 | 必传 | 类型 | 描述 | 备注 |
| - | - | - | - | - | - |
| name | body | true | string | 联动名称 |支持中文、英文字母、数字、下划线和短划线，长度限制1-20|
| description | body | false | string | 联动描述 | - |
| start | body | false | boolean | 是否开启联动 | 默认开启 |
| conditions | body | true | array | 触发条件对象数组，至少传递一个条件 | 后续用 c.xxx 描述对象属性 |
| c.type | body | true | enum | 条件类型 ['TIME', 'EXTERNAL', 'DEVICE'],(设备触发,定时器触发,第三方数据触发) | - |
| c.standard_value | body | true | any | 被比较的值 | - |
| c.operator | body | true | enum | 比较操作 ['EQ', 'LT', 'GT', 'LTE', 'GTE'],(等于,小于,大于,小于等于,大于等于) |
| c.device | body | false | object | 设备触发条件必传(type=device) | 后续用 c.device.xxx 表示对象属性 |
| c.device.product_id | body | true | string | OneNET产品id | - |
| c.device.function_type | body | true | string | 功能点类型 | - |
| c.device.device_sn | body | true | string | 设备唯一标识 | - |
| c.device.function_index | body | true | integer | 功能点索引 | - |
| c.ext | body | false | object | 第三方数据触发条件必传(type=ext) | 后续用 c.ext.xxx 表示对象属性，详见附件三说明 |
| c.ext.type | body | true | enum | 第三方数据类型 enum['WEATHER','TEMPERATURE','HUMIDITY','PM25','AIRQUALITY'](天气,温度,湿度,PM2.5,空气质量) | 详细描述请见附件三 |
| c.ext.ad_code | body | true | string | 地区编码 | 可从工具类接口获取 |
| c.timer | body | false | object | 定时器触发必传(type=timer) | 后续用 c.timer.xxx 表示对象属性 |
| c.timer.time | body | true | string | 执行时间点，精确到分 | eg: "12:45" |
| c.timer.repeat_day | body | false | array | 每周内重复的天数 | enum:['MON', 'TUE', 'WED', 'THU', 'FRI', 'SAT', 'SUN']|
| actions | body | true | array | 执行动作对象数组 | 后续用 a.xxx 描述对象属性 |
| a.type | body | true | enum | 执行动作类型,['DEVICE', 'CALLBACK'],(给设备下发命令,执行回调) | - |
| a.device | body | false | object | 下发命令动作必传(type=cmd) | 后续用 a.device.xxx 表示对象属性 |
| a.device.product_id | body | true | string | OneNET产品id | - |
| a.device.function_type | body | true | enum | 功能点类型['BOOLEAN','INTEGER','FLOAT','ENUM','STRING','BUFFER'] | - |
| a.device.function_index | body | true | integer | 功能点索引 | - |
| a.device.device_sn | body | true | string | 设备唯一标识 | - |
| a.device.cmd_value | body | true | string | 下发命令值 | - |
| a.callback | body | false | object | 执行回调动作必传(type=callback) | 后续用 a.callback.xxx 表示对象属性 |
| a.callback.url | body | true | string | 回调地址 | - |
| emit_condition | body | false | enum  | ['ANY','ALL'],(满足一个条件触发,满足所有条件触发) | 默认为ALL |
| limit | body | false | object | 全局触发限制条件 | 后续使用 l.xxx 表示对象属性 |
| l.range | body | true | array |  时间点范围，精确到分 eg: ['12:21', '16:34'] | 默认全天 |
| l.repeat_day | body | true | array | 每周内重复天数 | 默认当天,enum:['MON', 'TUE', 'WED', 'THU', 'FRI', 'SAT', 'SUN'] |

- 响应内容:

| 字段 | 类型 | 描述 |
| - | - | - |
| _id | string | 联动id |

- 请求响应示例：

```javascript
// request
url: "/hewu/open-api/v1/rules"
body: {
	 "name": "设备联动规则1",
     "description": "设备联动规则1",
     "start": true,
     "conditions": [{
     	"type":"DEVICE",
     	"device":{
     		"product_id" : "12345",
            "device_sn" : "12345-1",
            "function_index" : 1,
            "function_type" : "BOOLEAN"
     	},
     	"standard_value":"3",
     	"operator":"EQ"
     }],
     "actions": [
     	{
     		"type":"DEVICE",
     		"device":{
	     		"product_id" : "12345",
            	"device_sn" : "12345-11",
	            "function_index" : 1,
	            "function_type" : "BOOLEAN",
	            "cmd_value" : "true"
     		}
     	}
     ],
     "emit_condition":"ANY"
}
// response
{
  code: 200,
  msg: "OK",
  data: {
    _id: '5bc7fecbfecb51004743350s'
  }
}
```

### 6.2 <span id="62">修改联动</span>
- URL地址: `/rules/:id`
- HTTP方法: PUT
- 鉴权: masterKey/salverKey
- 描述: 创建联动
- 请求参数：

| 字段 | 位置 | 必传 | 类型 | 描述 | 备注 |
| - | - | - | - | - | - |
| id | path | true | string | 创建联动返回的_id |-|
| name | body | false | string | 联动名称 |支持中文、英文字母、数字、下划线和短划线，长度限制1-20|
| description | body | false | string | 联动描述 | - |
| start | body | false | boolean | 是否开启联动 | 默认开启 |
| conditions | body | false | array | 触发条件对象数组 | 后续用 c.xxx 描述对象属性 |
| c.type | body | true | enum | 条件类型 ['TIME', 'EXTERNAL', 'DEVICE'],(设备触发,定时器触发,第三方数据触发) | - |
| c.standard_value | body | true | any | 被比较的值 | - |
| c.operator | body | true | enum | 比较操作 ['EQ', 'LT', 'GT', 'LTE', 'GTE'],(等于,小于,大于,小于等于,大于等于) |
| c.device | body | false | object | 设备触发条件必传(type=device) | 后续用 c.device.xxx 表示对象属性 |
| c.device.product_id | body | true | string | OneNET产品id | - |
| c.device.function_type | body | true | string | 功能点类型 | - |
| c.device.device_sn | body | true | string | 设备唯一标识 | - |
| c.device.function_index | body | true | integer | 功能点索引 | - |
| c.ext | body | false | object | 第三方数据触发条件必传(type=ext) | 后续用 c.ext.xxx 表示对象属性，详见附件三说明 |
| c.ext.type | body | true | enum | 第三方数据类型 enum['WEATHER','TEMPERATURE','HUMIDITY','PM25','AIRQUALITY'](天气,温度,湿度,PM2.5,空气质量) | 详细描述请见附件三 |
| c.ext.ad_code | body | true | string | 地区编码 | 可从工具类接口获取 |
| c.timer | body | false | object | 定时器触发必传(type=timer) | 后续用 c.timer.xxx 表示对象属性 |
| c.timer.time | body | true | string | 执行时间点，精确到分 | eg: "12:45" |
| c.timer.repeat_day | body | false | array | 每周内重复的天数 | enum:['MON', 'TUE', 'WED', 'THU', 'FRI', 'SAT', 'SUN']|
| actions | body | false | array | 执行动作对象数组 | 后续用 a.xxx 描述对象属性 |
| a.type | body | true | enum | 执行动作类型,['DEVICE', 'CALLBACK'],(给设备下发命令,执行回调) | - |
| a.device | body | false | object | 下发命令动作必传(type=cmd) | 后续用 a.device.xxx 表示对象属性 |
| a.device.product_id | body | true | string | OneNET产品id | - |
| a.device.function_type | body | true | enum | 功能点类型['BOOLEAN','INTEGER','FLOAT','ENUM','STRING','BUFFER'] | - |
| a.device.function_index | body | true | integer | 功能点索引 | - |
| a.device.device_sn | body | true | string | 设备唯一标识 | - |
| a.device.cmd_value | body | true | string | 下发命令值 | - |
| a.callback | body | false | object | 执行回调动作必传(type=callback) | 后续用 a.callback.xxx 表示对象属性 |
| a.callback.url | body | true | string | 回调地址 | - |
| emit_condition | body | false | enum  | ['ANY','ALL'],(满足一个条件触发,满足所有条件触发) | 默认为ALL |
| limit | body | false | object | 全局触发限制条件 | 后续使用 l.xxx 表示对象属性 |
| l.range | body | true | array |  时间点范围，精确到分 eg: ['12:21', '16:34'] | 默认全天 |
| l.repeat_day | body | true | array | 每周内重复天数 | 默认当天,enum:['MON', 'TUE', 'WED', 'THU', 'FRI', 'SAT', 'SUN'] |
- 响应内容:

| 字段 | 类型 | 描述 |
| - | - | - |
| _id | string | 联动id |
- 请求响应示例：

```javascript
// request
url: "/hewu/open-api/v1/rules/5bc7fecbfecb51004743350s"
body: {
	   "name": "设备联动规则1",
     "description": "设备联动规则1",
     "start": false,
     "conditions": [{
     	"type":"DEVICE",
     	"device":{
     		"product_id" : "12345",
            "device_sn" : "12345-1",
            "function_index" : 1,
            "function_type" : "BOOLEAN"
     	},
     	"standard_value":"3",
     	"operator":"EQ"
     }],
     "actions": [
     	{
     		"type":"DEVICE",
     		"device":{
	     		"product_id" : "12345",
            "device_sn" : "12345-11",
            "function_index" : 1,
            "function_type" : "BOOLEAN",
            "cmd_value" : "true"
     		}
     	}
     ],
     "emit_condition":"ANY"
}
// response
{
  code: 200,
  msg: "OK",
  data: {
    _id: '5bc7fecbfecb51004743350s'
  }
}
```
### 6.3 <span id="63">联动详情</span>
- URL地址: `/rules/:id`
- HTTP方法: GET
- 鉴权: masterKey/salverKey
- 描述: 联动详情
- 请求参数：

| 字段 | 位置 | 必传 | 类型 | 描述 | 备注 |
| - | - | - | - | - | - |
| id | path | true | string | 创建联动返回_id | - |
- 响应内容:

| 字段 | 类型 | 描述 | 备注|
| - | - | - | - | - | - |
| name | string | 联动名称
| description |  string | 联动描述 |
| start |  boolean | 是否开启联动 | 
| conditions |  array | 触发条件对象数组，至少传递一个条件 | 后续用 c.xxx 描述对象属性 |
| c.type | enum | 条件类型 ['TIME', 'EXTERNAL', 'DEVICE'],(设备触发,定时器触发,第三方数据触发) | - |
| c.standard_value | string | 被比较的值 | - |
| c.operator | enum | 比较操作 ['EQ', 'LT', 'GT', 'LTE', 'GTE'],(等于,小于,大于,小于等于,大于等于) |
| c.device  | object | 设备触发条件 | 后续用 c.device.xxx 表示对象属性 |
| c.device.product_id  | string | OneNET产品id | - |
| c.device.function_type  | string | 功能点类型 | - |
| c.device.device_sn  | string | 设备唯一标识 | - |
| c.device.function_index  | integer | 功能点索引 | - |
| c.ext  | object | 第三方数据触发条件 | 后续用 c.ext.xxx 表示对象属性，详见附件三说明 |
| c.ext.type | enum | 第三方数据类型 enum['WEATHER','TEMPERATURE','HUMIDITY','PM25','AIRQUALITY'](天气,温度,湿度,PM2.5,空气质量) | 详细描述请见附件三 |
| c.ext.ad_code  | string | 地区编码 | 可从工具类接口获取 |
| c.timer  | object | 定时器触发 | 后续用 c.timer.xxx 表示对象属性 |
| c.timer.time  | string | 执行时间点，精确到分 | eg: "12:45" |
| c.timer.repeat_day  | array | 每周内重复的天数 | enum:['MON', 'TUE', 'WED', 'THU', 'FRI', 'SAT', 'SUN']|
| actions  | array | 执行动作对象数组 | 后续用 a.xxx 描述对象属性 |
| a.type  | enum | 执行动作类型,['DEVICE', 'CALLBACK'],(给设备下发命令,执行回调) | - |
| a.device  | object | 下发命令动作 | 后续用 a.device.xxx 表示对象属性 |
| a.device.product_id  | string | OneNET产品id | - |
| a.device.function_type  | enum | 功能点类型['BOOLEAN','INTEGER','FLOAT','ENUM','STRING','BUFFER'] | - |
| a.device.function_index  | integer | 功能点索引 | - |
| a.device.device_sn | string | 设备唯一标识 | - |
| a.device.cmd_value  | string | 下发命令值 | - |
| a.callback  | object | 执行回调动作 | 后续用 a.callback.xxx 表示对象属性 |
| a.callback.url  | string | 回调地址 | - |
| emit_condition  | enum  | ['ANY','ALL'],(满足一个条件触发,满足所有条件触发) | 默认为ALL |
| limit  | object | 全局触发限制条件 | 后续使用 l.xxx 表示对象属性 |
| l.range  | array |  时间点范围，精确到分 eg: ['12:21', '16:34'] | 默认全天 |
| l.repeat_day | array | 每周内重复天数 | 默认当天,enum:['MON', 'TUE', 'WED', 'THU', 'FRI', 'SAT', 'SUN'] |
- 请求响应示例：

```javascript
// request
url: "/hewu/open-api/v1/rules/5bc7fecbfecb51004743350s"
// response
{
  code: 200,
  msg: "OK",
  data: {
    "_id":"5bc7fecbfecb51004743350s",
     "name": "设备联动规则1",
     "description": "设备联动规则1",
     "start": false,
     "conditions": [{
     	"type":"DEVICE",
     	"device":{
        "product_id" : "12345",
        "device_sn" : "12345-1",
        "function_index" : 1,
        "function_type" : "BOOLEAN"
     	},
     	"standard_value":"3",
     	"operator":"EQ"
     }],
     "actions": [
     	{
     		"type":"DEVICE",
         "device":{
          "product_id" : "12345",
          "device_sn" : "12345-11",
          "function_index" : 1,
          "function_type" : "BOOLEAN",
          "cmd_value" : "true"
        }
     	}
     ],
     "emit_condition":"ANY"
  } 
}
```
### 6.4 <span id="64">联动列表</span>
- URL地址: `/rules`
- HTTP方法: GET
- Tag: pagenation
- 鉴权: masterKey/salverKey
- 描述: 联动列表
- 请求参数：

| 字段 | 位置 | 必传 | 类型 | 描述 | 备注 |
| - | - | - | - | - | - |
| name | query | false | string | 联动名称 | 筛选条件 |
- 响应内容:

| 字段 | 类型 | 描述 |
| - | - | - |
| count | number | 总数量 |
| rules | array | 联动列表，具体联动详情及字段见6.3|
- 请求响应示例：

```javascript
// request
url: "/hewu/open-api/v1/rules?name=喷水&offset=10&limit=10"
// response
{
  code: 200,
  msg: "OK",
  data: {
    count: 11,
    rules: [{
    "_id":"5bc7fecbfecb51004743350s",
     "name": "设备联动规则1",
     "description": "设备联动规则1",
     "start": false,
     "conditions": [{
     	"type":"DEVICE",
     	"device":{
        "product_id" : "12345",
        "device_sn" : "12345-1",
        "function_index" : 1,
        "function_type" : "BOOLEAN"
     	},
     	"standard_value":"3",
     	"operator":"EQ"
     }],
     "actions": [
     	{
     		"type":"DEVICE",
         "device":{
          "product_id" : "12345",
          "device_sn" : "12345-11",
          "function_index" : 1,
          "function_type" : "BOOLEAN",
          "cmd_value" : "true"
        }
     	}
     ],
     "emit_condition":"ANY"
    } ]
  }
}
```
### 6.5 <span id="65">联动执行日志查询</span>
- URL地址: `/rules/:id/logs`
- HTTP方法: GET
- Tag: pagenation
- 鉴权: masterKey/salverKey
- 描述: 联动执行日志查询
- 请求参数：

| 字段 | 位置 | 必传 | 类型 | 描述 | 备注 |
| - | - | - | - | - | - |
| id | path | true | string | 创建联动返回的_id | - |
- 响应内容:

| 字段 | 类型 | 描述 |
| - | - | - |
| count | number | 日志总数 |
| logs | array | 日志对象数组，后续用l.xxx表示每个属性 |
| l.created_at | IOSDate | 创建时间 |
| l.status | enum | 执行状态 ['SUCCESS','FAIL','PARTSUCCESS'],(成功,失败,部分成功) |
| l.actions | array | 执行动作对象数组，后续用l.actions.xx表示每个属性 |
| l.actions.type | enum | 动作类型['DEVICE','CALLBACK'] |
| l.actions.success | boolean | 是否成功 |
| l.actions.msg | string | 失败原因,scuccess=false 时返回 |
| l.actions.url | string | 回调地址 DEVICE类型独有 |
| l.actions.pid | string | OneNET产品id DEVICE类型独有 |
| l.actions.fn_index | string | 功能点索引 DEVICE类型独有 |
| l.actions.device_sn | string | 设备唯一标识 DEVICE类型独有 |
| l.actions.value | string | 下发命令值 DEVICE类型独有 |
- 请求响应示例：

```javascript
// request
url: "/hewu/open-api/v1/rules/5bc7fecbfecb51004743350s/logs?from=1565863812858&to=1565863822858&limit=10&offset=190"
// response
{
  code: 200,
  msg: "OK",
  data: {
    count: 191,
    logs: [{
      status: 'SUCCESS',
      created_at: "2019-08-08T16:46:51.309Z",
      actions: [{
        type: 'DEVICE',
        pid: '12345',
        fn_index: 1,
        device_sn: 'sn-12345',
        value: 'true'
        success: false,
        msg: 'device offline',
      }, {
        type: 'CALLBACK',
        url: 'http://wwww.baidu.com/api/test'
        success: true
      }]
    }]
  }
}
```

## 附件一 <span id="a1">加/解密算法</span>
java参考资料: https://blog.csdn.net/linminqin/article/details/19972751

**每次加密应当实时计算，解密后会对时间戳校验，超过两分钟被认为非法Key**
```javascript
// 加密算法：明文key + 5位随机码 + 13位时间戳的 => 通过 aes-128-ecb 加密 => 转为16进制
// 1. 创建Cipher实例密钥为项目的access_key，加密算法为aes256
// 2. 使用Cipher实例加密明文(输入utf8，输出hex)，明文结构为 key + 5位随机码 + Unix时间戳
// 3. Cipher实例输出16进制密文
// Nodejs 代码 msg: key明文, accessKey: 项目access_key
function encode (msg, accessKey) {
  const random = Math.random().toString().slice(3, 8)
  const cipher = crypto.createCipher('aes-128-ecb', accessKey)
  let encodeMsg = cipher.update(`${msg}${random}${new Date().getTime()}`, 'utf8', 'hex')
  encodeMsg += cipher.final('hex')

  return encodeMsg
}
// 解密算法：密文key => 通过 aes-128-ecb 解密 =>  项目key + 5位随机码 + 13位时间戳
// 1. 创建Decipher实例密钥为项目access_key，解密算法为aes256
// 2. 使用Decipher实例解密密文(输入hex，输出utf8),明文结构为 key + 5位随机码 + Unix时间戳
// 3. Decipher实例输出utf8编码明文key
// Nodejs 代码 msg: key密文, accessKey: 项目access_key
function decode (msg, accessKey) {
  const decipher = crypto.createDecipher('aes-128-ecb', accessKey)
  let decrypted = decipher.update(msg, 'hex', 'utf8')
  decrypted += decipher.final('utf8')

  const key = decrypted.substring(0, decrypted.length - 18)

  const requestTime = decrypted.substring(decrypted.length - 13)

  return key
}
```
## 附件二 <span id="a2">错误码对应表</span>
+ 统一错误码

| 错误码 | 说明 |
| ---- | ---- |
| 10002 | 请求参数错误，httpStatus等于400 |
| 10003 | 内部错误，httpStatus等于500 |
| 12001 | Restful接口操作资源时，该资源依赖的其他资源不存在，详见错误msg |
| 40003 | confirm-code 已失效，需重新加密计算 |
| 40004 | confirm-code 解密计算失败，确认密文是否有效 |
| 40005 | 越权错误，详见msg |
| 50001 | IEMI校验错误 |
| 50002 | 当前key下无此设备或者设备不存在 |

## 附件三 <span id="a3">第三方数据说明</span>
- 设置第三方数据条件时 除了 number 类型可选所有比较动作,其余都只能'EQ'
- 设置第三方数据条件时 所有 enum 类型stander_value字段为中文枚举值

| 字段 | 含义 | 数据类型 | 备注 |
| - | - | - | - |
| WEATHER | 天气 | enum | 晴天/阴天/雨天/雪天/霾天/雾天 |
| TEMPERATURE | 温度 | number | 单位 摄氏度 |
| HUMIDITY | 湿度 | enum | 干燥（低于40%）/舒适（40%- 60%）/潮湿（高于60%） |
| PM25 | PM2.5 | enum | 优（0~35μg/m³）/良（35~75μg/m³）/污染（75μg/m³以上） |
| AIRQUALITY | 空气质量 | enum | 优/良/轻度污染/中度污染/重度污染/严重污染 |
