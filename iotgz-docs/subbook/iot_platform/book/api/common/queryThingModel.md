# 物模型查询

#### 接口名称

> QueryThingModel

#### 请求方法

> GET

#### 请求参数

| 参数名称   | 类型   | 是否必选 | 描述   |
| :--------- | :----- | :------- | :----- |
| product_id | string | 是       | 产品id |

#### 返回数据

| 参数名称          | 类型    | 描述                       |
| :---------------- | :------ | :------------------------- |
| code              | string  | 调用失败时，返回的错误码   |
| msg               | string  | 调用失败时，返回的错误信息 |
| requestId         | string  | 调用API时生成的请求标识    |
| success           | boolean | 接口是否调用成功           |
| data | object | 物模型 |
| data.properties | array | 数组对象 属性功能点 |
| p.functionMode | string | 功能点类型，定值'property' |
| p.identifier | string | 属性唯一标识符（产品下唯一） |
| p.name | string | 属性名称 |
| p.desc | string | 属性描述 |
| p.accessMode | string | "属性读写类型：只读（r）或读写（rw） |
| p.functionType | string | 是否是标准功能点，自定义（u）/系统（s） |
| p.dataType | object | 属性功能点数据 |
| p.dataType.type | string | 属性类型: int32（32位整数）、int64（64位整数）、float（单精度浮点）、double（双精度浮点型）、string（字符串）、date（String类型UTC秒）、bool（true或false）、enum（int类型）、bitMap（位图）、date（int64类型UTC时间戳毫秒）、struct（结构体类型）、array（数组） |
| p.dataType.specs | object | 属性功能点数据 |
| data.events | array | 数组对象 事件功能点 |
| e.functionMode | string | 功能点类型，定值'event' |
| e.identifier | string | 事件唯一标识符 |
| e.name | string | 事件名称 |
| e.desc | string | 事件描述 |
| e.type | string | 事件类型（info、alert、error） |
| e.fuctionType | string| 是否是标准功能点，自定义（u）/标准（s） |
| e.outputData | array | 参数 |
| e.outputData.identifier | string | 参数唯一标识符 |
| e.outputData.name | string | 参数名称 |
| e.outputData.dataType | object | 参数数据 |
| e.outputData.dataType.type | string | 属性类型: int32（32位整数）、int64（64位整数）、float（单精度浮点）、double（双精度浮点型）、string（字符串）、date（String类型UTC秒）、bool（true或false）、enum（int类型）、bitMap（位图）、date（int64类型UTC时间戳毫秒）、struct（结构体类型）、array（数组） |
| e.outputData.dataType.specs | object | 功能点数据 |
| services | array | 数组对象 服务功能点 |
| s.functionMode | string | 功能点类型，定值'service' |
| s.identifier | string | 服务唯一标识符（产品下唯一） |
| s.name | string | 服务名称 |
| s.desc | string | 服务描述 |
| s.callType | string | 调用方式,同步(s)/异步(a) |
| s.fuctionType | string | 功能点类型，自定义（u）/系统（s） |
| s.input | array | 输入参数 |
| s.input.identifier | string | 参数唯一标识符 |
| s.input.name | string | 参数名称 |
| s.input.dataType | object | 参数数据 |
| s.input.dataType.type | string | 属性类型: int32（32位整数）、int64（64位整数）、float（单精度浮点）、double（双精度浮点型）、string（字符串）、bool（true或false）、enum（int类型）、bitMap（位图）、date（int64类型UTC时间戳毫秒）、struct（结构体类型）、array（数组） |
| s.input.dataType.specs | object | 参数功能点数据 |
| s.output | array | 输出参数 |
| s.output.identifier | string | 参数唯一标识符 |
| s.output.name | string | 参数名称 |
| s.output.dataType | object | 参数数据 |
| s.output.dataType.type | string | 属性类型: int32（32位整数）、int64（64位整数）、float（单精度浮点）、double（双精度浮点型）、string（字符串）、bool（true或false）、enum（int类型）、bitMap（位图）、date（int64类型UTC时间戳毫秒）、struct（结构体类型）、array（数组） |
| s.output.dataType.specs | object | 参数功能点数据 |


#### 示例

##### 请求示例

```
GET /common?action=QueryThingModel&version=1&product_id=lsibd9
```



##### 响应示例

```
{
    "data": { 
        "properties": [
            {
                "name": "模式",
                "identifier": "model",
                "functionType": "u",
                "functionMode": "property",
                "desc": "",
                "accessMode": "rw",
                "dataType": {
                    "type": "enum",
                    "specs": {
                        "1": "模式1",
                        "2": "模式2"
                    }
                }
            }
        ],
        "events": [
            {
                "name": "test",
                "identifier": "test",
                "functionType": "u",
                "functionMode": "event",
                "desc": null,
                "eventType": "info",
                "outputData": [
                    {
                        "dataType": {
                            "type": "bool",
                            "specs": {
                                "false": "关",
                                "true": "开"
                            }
                        },
                        "name": "开关",
                        "identifier": "switch"
                    }
                ]
            }
        ]
    } 
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
```
