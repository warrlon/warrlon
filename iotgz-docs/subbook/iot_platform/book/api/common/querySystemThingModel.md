# 物模型系统功能点列表 - 【平台内置功能点】

#### 接口名称

> QuerySystemThingModel

#### 请求方法

> GET

#### 请求参数

| 参数名称   | 类型   | 是否必选 | 描述   |
| :--------- | :----- | :------- | :----- |
| - | - | -       | - |

#### 返回数据

| 参数名称          | 类型    | 描述                       |
| :---------------- | :------ | :------------------------- |
| code              | string  | 调用失败时，返回的错误码   |
| msg               | string  | 调用失败时，返回的错误信息 |
| requestId         | string  | 调用API时生成的请求标识    |
| success           | boolean | 接口是否调用成功           |
| data | object | 系统标准物模型 |
| data.properties | array | 数组对象 属性功能点列表，如下的p表示properties数组的单个对象标识 |
| p.functionMode | string | 功能点类型，定值'property' |
| p.identifier | string | 属性唯一标识符（产品下唯一） |
| p.name | string | 属性名称 |
| p.desc | string | 属性描述 |
| p.accessMode | string | 属性读写类型：只读（r）或读写（rw） |
| p.fuctionType | string | 是否是标准功能点，自定义（u）/系统（s） |
| p.dataType | object | 属性功能点数据 |
| p.dataType.type | string | 属性功能点数据类型: int32（32位整数）、int64（64位整数）、float（单精度浮点）、double（双精度浮点型）、string（字符串）、date（String类型UTC秒）、bool（true或false）、enum（int类型）、bitMap（位图）、struct（结构体类型，可包含前面9种类型） |
| p.dataType.specs | object | 属性功能点数据，详见下面实例 |
| data.events | array | 数组对象 事件功能点列表，如下的e表示events数组的单个对象标识 |
| e.functionMode | string | 功能点类型，定值'event' |
| e.identifier | string | 事件唯一标识符 |
| e.name | string | 事件名称 |
| e.desc | string | 事件描述 |
| e.type | string | 事件类型（info、alert、error） |
| e.fuctionType | string| 是否是标准功能点，自定义（u）/系统（s） |
| e.outputData | array | 参数数组 |
| e.outputData.identifier | string | 参数唯一标识符 |
| e.outputData.name | string | 参数名称 |
| e.outputData.dataType | object | 参数数据 |
| e.outputData.dataType.type | string | 参数数据类型: int32（32位整数）、int64（64位整数）、float（单精度浮点）、double（双精度浮点型）、string（字符串）、date（String类型UTC秒）、bool（true或false）、enum（int类型）、bitMap（位图）、struct（结构体类型，可包含前面9种类型） |
| e.outputData.dataType.specs | object | 功能点具体数据，详见下面实例 |

#### 示例

##### 请求示例

```
GET /common?action=QuerySystemThingModel&version=1
```

##### 响应示例

```
{
    "data": { 
        "properties": [
            {
                "name": "基站定位",
                "identifier": "$OneNET_LBS",
                "functionType": "s",
                "functionMode": "property",
                "desc": null,
                "accessMode": "r",
                "dataType": {
                    "type": "array",
                    "specs": {
                        "size": "3",
                        "items": {
                            "type": "struct",
                            "specs": [
                                {
                                    "identifier": "mnc",
                                    "name": "移动网号",
                                    "dataType": {
                                        "type": "int32",
                                        "specs": {
                                            "min": "-2147483648",
                                            "max": "2147483647"
                                        }
                                    }
                                },
                                {
                                    "identifier": "mcc",
                                    "name": "移动国家号码",
                                    "dataType": {
                                        "type": "int32",
                                        "specs": {
                                            "min": "-2147483648",
                                            "max": "2147483647"
                                        }
                                    }
                                },
                                {
                                    "identifier": "lac",
                                    "name": "地区区域码",
                                    "dataType": {
                                        "type": "int32",
                                        "specs": {
                                            "min": "-2147483648",
                                            "max": "2147483647"
                                        }
                                    }
                                },
                                {
                                    "identifier": "cid",
                                    "name": "基站码",
                                    "dataType": {
                                        "type": "int32",
                                        "specs": {
                                            "min": "-2147483648",
                                            "max": "2147483647"
                                        }
                                    }
                                },
                                {
                                    "identifier": "networkType",
                                    "name": "网络制式",
                                    "dataType": {
                                        "type": "int32",
                                        "specs": {
                                            "min": "-2147483648",
                                            "max": "2147483647"
                                        }
                                    }
                                },
                                {
                                    "identifier": "ss",
                                    "name": "信号强度",
                                    "dataType": {
                                        "type": "int32",
                                        "specs": {
                                            "min": "-2147483648",
                                            "max": "2147483647"
                                        }
                                    }
                                },
                                {
                                    "identifier": "signalLength",
                                    "name": "当前基站广播信号强度",
                                    "dataType": {
                                        "type": "int32",
                                        "specs": {
                                            "min": "-2147483648",
                                            "max": "2147483647"
                                        }
                                    }
                                },
                                {
                                    "identifier": "ta",
                                    "name": "移动台距以确定其发往基站的定时超前量",
                                    "dataType": {
                                        "type": "int32",
                                        "specs": {
                                            "min": "-2147483648",
                                            "max": "2147483647"
                                        }
                                    }
                                },
                                {
                                    "identifier": "flag",
                                    "name": "基站信息数字进制",
                                    "dataType": {
                                        "type": "int32",
                                        "specs": {
                                            "min": "-2147483648",
                                            "max": "2147483647"
                                        }
                                    }
                                }
                            ]
                        }
                    }
                }
            },
            {
                "name": "WiFi定位",
                "identifier": "$OneNET_LBS_WIFI",
                "functionType": "s",
                "functionMode": "property",
                "desc": null,
                "accessMode": "r",
                "dataType": {
                    "type": "struct",
                    "specs": [
                        {
                            "identifier": "imsi",
                            "name": "移动用户识别码",
                            "dataType": {
                                "type": "string",
                                "specs": {
                                    "length": "255"
                                }
                            }
                        },
                        {
                            "identifier": "serverip",
                            "name": "设备接入基站时对应的网关ip",
                            "dataType": {
                                "type": "string",
                                "specs": {
                                    "length": "255"
                                }
                            }
                        },
                        {
                            "identifier": "macs",
                            "name": "可以接收到的热点mac信息",
                            "dataType": {
                                "type": "string",
                                "specs": {
                                    "length": "255"
                                }
                            }
                        },
                        {
                            "identifier": "mmac",
                            "name": "已连热点mac信息",
                            "dataType": {
                                "type": "string",
                                "specs": {
                                    "length": "255"
                                }
                            }
                        },
                        {
                            "identifier": "smac",
                            "name": "手机mac码",
                            "dataType": {
                                "type": "string",
                                "specs": {
                                    "length": "255"
                                }
                            }
                        },
                        {
                            "identifier": "idfa",
                            "name": "IOS手机的idfa",
                            "dataType": {
                                "type": "string",
                                "specs": {
                                    "length": "255"
                                }
                            }
                        }
                    ]
                }
            }
        ],
        "events": null
    } 
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
```