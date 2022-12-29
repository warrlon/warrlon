# 物模型查询

<table>
<tr><th>方法</th><td colspan="4">GET</th></tr>
<tr><td>路径URI</td><td colspan="4">/common?action=QueryThingModel&version=1&product_id=lsibd9</td></tr>
<tr><td>请求头</td><td colspan="4"></td></tr>

<tr><td rowspan="1">URL请求参数</td><td>product_id</td><td>string</td><td>必填</td><td>产品id </td></tr>

<tr><td>请求体参数</td><td colspan="4">无</td></tr>

<tr><td rowspan="47">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>调用成功时，返回的业务数据</td></tr>
<tr><td colspan="2">data.properties</td><td>array</td><td>数组对象 属性功能点</td></tr>
<tr><td colspan="2">p.functionMode</td><td>string</td><td>功能点类型，定值'property'</td></tr>
<tr><td colspan="2">p.identifier</td><td>string</td><td>属性唯一标识符（产品下唯一）</td></tr>
<tr><td colspan="2">p.name</td><td>string</td><td>属性名称</td></tr>
<tr><td colspan="2">p.desc</td><td>string</td><td>属性描述</td></tr>
<tr><td colspan="2">p.accessMode</td><td>string</td><td>"属性读写类型：只读（r）或读写（rw）</td></tr>
<tr><td colspan="2">p.fuctionType</td><td>string</td><td>是否是标准功能点，自定义（u）/系统（s）</td></tr>
<tr><td colspan="2">p.dataType</td><td>object</td><td>属性功能点数据</td></tr>
<tr><td colspan="2">p.dataType.type</td><td>string</td><td>属性类型: int32（32位整数）、int64（64位整数）、float（单精度浮点）、double（双精度浮点型）、string（字符串）、date（String类型UTC秒）、bool（true或false）、enum（int类型）、bitMap（位图）、date（int64类型UTC时间戳毫秒）、struct（结构体类型）、array（数组）</td></tr>
<tr><td colspan="2">p.dataType.specs</td><td>object</td><td>属性功能点数据</td></tr>
<tr><td colspan="2">data.events</td><td>array</td><td>数组对象 事件功能点列表</td></tr>
<tr><td colspan="2">e.functionMode</td><td>string</td><td>功能点类型，定值'event'</td></tr>
<tr><td colspan="2">e.identifier</td><td>string</td><td>事件唯一标识符</td></tr>
<tr><td colspan="2">e.name</td><td>string</td><td>事件名称</td></tr>
<tr><td colspan="2">e.desc</td><td>string</td><td>事件描述</td></tr>
<tr><td colspan="2">e.type</td><td>string</td><td>事件类型（info、alert、error）</td></tr>
<tr><td colspan="2">e.fuctionType</td><td>string</td><td>是否是标准功能点，自定义（u）/系统（s）</td></tr>
<tr><td colspan="2">e.outputData</td><td>array</td><td>参数</td></tr>
<tr><td colspan="2">e.outputData.identifier</td><td>string</td><td>参数唯一标识符</td></tr>
<tr><td colspan="2">e.outputData.name</td><td>string</td><td>参数名称</td></tr>
<tr><td colspan="2">e.outputData.dataType</td><td>object</td><td>参数数据</td></tr>
<tr><td colspan="2">e.outputData.dataType.type</td><td>string</td><td>属性类型: int32（32位整数）、int64（64位整数）、float（单精度浮点）、double（双精度浮点型）、string（字符串）、bool（true或false）、enum（int类型）、bitMap（位图）、date（int64类型UTC时间戳毫秒）、struct（结构体类型）、array（数组）</td></tr>
<tr><td colspan="2">e.outputData.dataType.specs</td><td>object</td><td>功能点数据</td></tr>
<tr><td colspan="2">services</td><td>array</td><td>数组对象 服务功能点</td></tr>
<tr><td colspan="2">s.functionMode</td><td>string</td><td>功能点类型，定值'service'</td></tr>
<tr><td colspan="2">s.identifier</td><td>string</td><td>服务唯一标识符（产品下唯一）</td></tr>
<tr><td colspan="2">s.name</td><td>string</td><td>服务名称</td></tr>
<tr><td colspan="2">s.desc</td><td>string</td><td>服务描述</td></tr>
<tr><td colspan="2">s.callType</td><td>string</td><td>调用方式,同步(s)/异步(a)</td></tr>
<tr><td colspan="2">s.fuctionType</td><td>string</td><td>功能点类型，自定义（u）/系统（s）</td></tr>
<tr><td colspan="2">s.input</td><td>array</td><td>输入参数</td></tr>
<tr><td colspan="2">s.input.identifier</td><td>string</td><td>参数唯一标识符</td></tr>
<tr><td colspan="2">s.input.name</td><td>string</td><td>参数名称</td></tr>
<tr><td colspan="2">s.input.dataType</td><td>object</td><td>参数数据</td></tr>
<tr><td colspan="2">s.input.dataType.type</td><td>string</td><td>属性类型: int32（32位整数）、int64（64位整数）、float（单精度浮点）、double（双精度浮点型）、string（字符串）、bool（true或false）、enum（int类型）、bitMap（位图）、date（int64类型UTC时间戳毫秒）、struct（结构体类型）、array（数组）</td></tr>
<tr><td colspan="2">s.input.dataType.specs</td><td>object</td><td>参数功能点数据</td></tr>
<tr><td colspan="2">s.output</td><td>string</td><td>输出参数</td></tr>
<tr><td colspan="2">s.output.identifier</td><td>string</td><td>参数唯一标识符</td></tr>
<tr><td colspan="2">s.output.name</td><td>string</td><td>参数名称</td></tr>
<tr><td colspan="2">s.output.dataType</td><td>object</td><td>参数数据</td></tr>
<tr><td colspan="2">s.output.dataType.type</td><td>string</td><td>属性类型: int32（32位整数）、int64（64位整数）、float（单精度浮点）、double（双精度浮点型）、string（字符串）、bool（true或false）、enum（int类型）、bitMap（位图）、date（int64类型UTC时间戳毫秒）、struct（结构体类型）、array（数组）</td></tr>
<tr><td colspan="2">s.output.dataType.specs</td><td>object</td><td>参数功能点数据</td></tr>

<tr><th>请求示例</th><td colspan="4">GET /common?action=QueryThingModel&version=1&product_id=lsibd9</th></tr>
<tr><th>响应示例</th><td colspan="4">
{<br>
    "data": { <br>
        "properties": [<br>
            {<br>
                "name": "模式",<br>
                "identifier": "model",<br>
                "functionType": "u",<br>
                "functionMode": "property",<br>
                "desc": "",<br>
                "accessMode": "rw",<br>
                "dataType": {<br>
                    "type": "enum",<br>
                    "specs": {<br>
                        "1": "模式1",<br>
                        "2": "模式2"<br>
                    }<br>
                }<br>
            }<br>
        ],<br>
        "events": [<br>
            {<br>
                "name": "test",<br>
                "identifier": "test",<br>
                "functionType": "u",<br>
                "functionMode": "event",<br>
                "desc": null,<br>
                "eventType": "info",<br>
                "outputData": [<br>
                    {<br>
                        "dataType": {<br>
                            "type": "bool",<br>
                            "specs": {<br>
                                "false": "关",<br>
                                "true": "开"<br>
                            }<br>
                        },<br>
                        "name": "开关",<br>
                        "identifier": "switch"<br>
                    }<br>
                ]<br>
            }<br>
        ]<br>
    }<br>
    "requestId": "a25087f46df04b69b29e90ef0acfd115",<br> 
    "success": true<br>
}<br>
</th></tr>
</table>
