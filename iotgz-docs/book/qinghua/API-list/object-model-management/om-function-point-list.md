# 物模型管理

# 物模型系统功能点列表

<table>
<tr><th>方法</th><td colspan="4">GET</th></tr>
<tr><td>路径URI</td><td colspan="4">/common?action=QuerySystemThingModel&version=1</td></tr>
<tr><td>请求头</td><td colspan="4"></td></tr>

<tr><td>URL参数</td><td colspan="4">无</td></tr>
<tr><td>请求体参数</td><td colspan="4">无</td></tr>

<tr><td rowspan="27">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>系统标准物模型</td></tr>
<tr><td colspan="2">data.properties</td><td>array</td><td>数组对象 属性功能点列表，如下的p表示properties数组的单个对象标识</td></tr>
<tr><td colspan="2">p.functionMode</td><td>string</td><td>功能点类型，定值'property'</td></tr>
<tr><td colspan="2">p.identifier</td><td>string</td><td>属性唯一标识符（产品下唯一）</td></tr>
<tr><td colspan="2">p.name</td><td>string</td><td>属性名称</td></tr>
<tr><td colspan="2">p.desc</td><td>string</td><td>属性描述</td></tr>
<tr><td colspan="2">p.fuctionType</td><td>string</td><td>是否是标准功能点，自定义（u）/系统（s）</td></tr>
<tr><td colspan="2">p.dataType</td><td>object</td><td>属性功能点数据</td></tr>
<tr><td colspan="2">p.dataType.type</td><td>string</td><td>属性功能点数据类型: int32（32位整数）、int64（64位整数）、float（单精度浮点）、double（双精度浮点型）、string（字符串）、date（String类型UTC秒）、bool（true或false）、enum（int类型）、bitMap（位图）、struct（结构体类型，可包含前面9种类型）</td></tr>
<tr><td colspan="2">p.dataType.specs</td><td>object</td><td>属性功能点数据，详见下面实例</td></tr>
<tr><td colspan="2">data.events</td><td>array</td><td>数组对象 事件功能点列表，如下的e表示events数组的单个对象标识</td></tr>
<tr><td colspan="2">e.functionMode</td><td>string</td><td>功能点类型，定值'event'</td></tr>
<tr><td colspan="2">e.identifier</td><td>string</td><td>事件唯一标识符</td></tr>
<tr><td colspan="2">e.name</td><td>string</td><td>事件名称</td></tr>
<tr><td colspan="2">e.desc</td><td>string</td><td>事件描述</td></tr>
<tr><td colspan="2">e.type</td><td>string</td><td>事件类型（info、alert、error）</td></tr>
<tr><td colspan="2">e.fuctionType</td><td>string</td><td>是否是标准功能点，自定义（u）/系统（s）</td></tr>
<tr><td colspan="2">e.outputData</td><td>array</td><td>参数数组</td></tr>
<tr><td colspan="2">e.outputData.identifier</td><td>string</td><td>参数唯一标识符</td></tr>
<tr><td colspan="2">e.outputData.name</td><td>string</td><td>参数名称</td></tr>
<tr><td colspan="2">e.outputData.dataType</td><td>object</td><td>参数数据</td></tr>
<tr><td colspan="2">e.outputData.dataType.type</td><td>string</td><td>参数数据类型: int32（32位整数）、int64（64位整数）、float（单精度浮点）、double（双精度浮点型）、string（字符串）、date（String类型UTC秒）、bool（true或false）、enum（int类型）、bitMap（位图）、struct（结构体类型，可包含前面9种类型）</td></tr>
<tr><td colspan="2">e.outputData.dataType.specs</td><td>object</td><td>功能点具体数据，详见下面实例</td></tr>

<tr><th>请求示例</th><td colspan="4">GET /common?action=QuerySystemThingModel&version=1</th></tr>
<tr><th>响应示例</th><td colspan="4">
{<br>
     "data": {<br> 
        "properties": [<br>
            {<br>
                "name": "基站定位",<br>
                "functionType": "s",<br>
                "functionMode": "property",<br>
                "desc": null,<br>
                "accessMode": "r",<br>
                "dataType": {<br>
                    "type": "array",<br>
                    "specs": {<br>
                        "size": "3",<br>
                        "items": {<br>
                            "type": "struct",<br>
                            "specs": [<br>
                                {<br>
                                    "identifier": "mnc",<br>
                                    "name": "移动网号",<br>
                                    "dataType": {<br>
                                        "type": "int32",<br>
                                        "specs": {<br>
                                            "min": "-2147483648",<br>
                                            "max": "2147483647"<br>
                                        }<br>
                                    }<br>
                                },<br>
                                {<br>
                                    "identifier": "mcc",<br>
                                    "name": "移动国家号码",<br>
                                    "dataType": {<br>
                                        "type": "int32",<br>
                                        "specs": {<br>
                                            "min": "-2147483648",<br>
                                            "max": "2147483647"<br>
                                        }<br>
                                    }<br>
                                },<br>
                                {<br>
                                    "identifier": "lac",<br>
                                    "name": "地区区域码",<br>
                                    "dataType": {<br>
                                        "type": "int32",<br>
                                        "specs": {<br>
                                            "min": "-2147483648",<br>
                                            "max": "2147483647"<br>
                                        }<br>
                                    }<br>
                                },<br>
                                {<br>
                                    "identifier": "cid",<br>
                                    "name": "基站码",<br>
                                    "dataType": {<br>
                                        "type": "int32",<br>
                                        "specs": {<br>
                                            "min": "-2147483648",<br>
                                            "max": "2147483647"<br>
                                        }<br>
                                    }<br>
                                },<br>
                                {<br>
                                    "identifier": "networkType",<br>
                                    "name": "网络制式",<br>
                                    "dataType": {<br>
                                        "type": "int32",<br>
                                        "specs": {<br>
                                            "min": "-2147483648",<br>
                                            "max": "2147483647"<br>
                                        }<br>
                                    }<br>
                                },<br>
                                {<br>
                                    "identifier": "ss",<br>
                                    "name": "信号强度",<br>
                                    "dataType": {<br>
                                        "type": "int32",<br>
                                        "specs": {<br>
                                            "min": "-2147483648",<br>
                                            "max": "2147483647"<br>
                                        }<br>
                                    }<br>
                                },<br>
                                {<br>
                                    "identifier": "signalLength",<br>
                                    "name": "当前基站广播信号强度",<br>
                                    "dataType": {<br>
                                        "type": "int32",<br>
                                        "specs": {<br>
                                            "min": "-2147483648",<br>
                                            "max": "2147483647"<br>
                                        }<br>
                                    }<br>
                                },<br>
                                {<br>
                                    "identifier": "ta",<br>
                                    "name": "移动台距以确定其发往基站的定时超前量",<br>
                                    "dataType": {<br>
                                        "type": "int32",<br>
                                        "specs": {<br>
                                            "min": "-2147483648",<br>
                                            "max": "2147483647"<br>
                                        }<br>
                                    }<br>
                                },<br>
                                {<br>
                                    "identifier": "flag",<br>
                                    "name": "基站信息数字进制",<br>
                                    "dataType": {<br>
                                        "type": "int32",<br>
                                        "specs": {<br>
                                            "min": "-2147483648",<br>
                                            "max": "2147483647"<br>
                                        }<br>
                                    }<br>
                                }<br>
                            ]<br>
                        }<br>
                    }<br>
                }<br>
            },<br>
            {<br>
                "name": "WiFi定位",<br>
                "functionType": "s",<br>
                "functionMode": "property",<br>
                "desc": null,<br>
                "accessMode": "r",<br>
                "dataType": {<br>
                    "type": "struct",<br>
                    "specs": [<br>
                        {<br>
                            "identifier": "imsi",<br>
                            "name": "移动用户识别码",<br>
                            "dataType": {<br>
                                "type": "string",<br>
                                "specs": {<br>
                                    "length": "255"<br>
                                }<br>
                            }<br>
                        },<br>
                        {<br>
                            "identifier": "serverip",<br>
                            "name": "设备接入基站时对应的网关ip",<br>
                            "dataType": {<br>
                                "type": "string",<br>
                                "specs": {<br>
                                    "length": "255"<br>
                                }<br>
                            }<br>
                        },<br>
                        {<br>
                            "identifier": "macs",<br>
                            "name": "可以接收到的热点mac信息",<br>
                            "dataType": {<br>
                                "type": "string",<br>
                                "specs": {<br>
                                    "length": "255"<br>
                                }<br>
                            }<br>
                        },<br>
                        {<br>
                            "identifier": "mmac",<br>
                            "name": "已连热点mac信息",<br>
                            "dataType": {<br>
                                "type": "string",<br>
                                "specs": {<br>
                                    "length": "255"<br>
                                }<br>
                            }<br>
                        },<br>
                        {<br>
                            "identifier": "smac",<br>
                            "name": "手机mac码",<br>
                            "dataType": {<br>
                                "type": "string",<br>
                                "specs": {<br>
                                    "length": "255"<br>
                                }<br>
                            }<br>
                        },<br>
                        {<br>
                            "identifier": "idfa",<br>
                            "name": "IOS手机的idfa",<br>
                            "dataType": {<br>
                                "type": "string",<br>
                                "specs": {<br>
                                    "length": "255"<br>
                                }<br>
                            }<br>
                        }<br>
                    ]<br>
                }<br>
            }<br>
        ],<br>
        "events": null<br>
    } <br>
    "requestId": "a25087f46df04b69b29e90ef0acfd115", <br>
    "success": true<br>
}<br>
</th></tr>
</table>