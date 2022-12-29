# 物模型更新（增删改）

<table>
<tr><th>方法</th><td colspan="4">POST</th></tr>
<tr><td>路径URI</td><td colspan="4">/common?action=UpdateThingModel&version=1</td></tr>
<tr><td>请求头</td><td colspan="4">Content-Type : application/json	</td></tr>

<tr><td>URL参数</td><td colspan="4">无</td></tr>

<tr><td rowspan="44">请求体参数</td><td>product_id</td><td>string</td><td>必填</td><td>产品ID</td></tr>
<tr><td>properties</td><td>array</td><td>必填</td><td>数组对象 属性功能点</td></tr>
<tr><td>p.functionMode</td><td>string</td><td>必填</td><td>功能点类型，定值'property'</td></tr>
<tr><td>p.identifier</td><td>string</td><td>必填</td><td>属性唯一标识符（产品下唯一）</td></tr>
<tr><td>p.name</td><td>string</td><td>必填</td><td>属性名称</td></tr>
<tr><td>p.desc</td><td>string</td><td>可选</td><td>属性描述</td></tr>
<tr><td>p.accessMode</td><td>string</td><td>必填</td><td>"属性读写类型：只读（r）或读写（rw）</td></tr>
<tr><td>p.fuctionType</td><td>string</td><td>必填</td><td>是否是标准功能点，自定义（u）/ 系统（s）- 更新只支持自定义功能点</td></tr>
<tr><td>p.type</td><td>object</td><td>必填</td><td>属性功能点数据</td></tr>
<tr><td>p.dataType</td><td>object</td><td>必填</td><td>属性功能点数据</td></tr>
<tr><td>p.dataType.typee</td><td>string</td><td>必填</td><td>属性类型: int32（32位整数）、int64（64位整数）、float（单精度浮点）、double（双精度浮点型）、string（字符串）、bool（true或false）、enum（int类型）、bitMap（位图）、date（int64类型UTC时间戳毫秒）、struct（结构体类型）、array（数组）</td></tr>
<tr><td>p.dataType.specs</td><td>object</td><td>必填</td><td>属性功能点数据</td></tr>
<tr><td>events</td><td>array</td><td>必填</td><td>数组对象 事件功能点</td></tr>
<tr><td>e.functionMode</td><td>string</td><td>必填</td><td>功能点类型，定值'event'</td></tr>
<tr><td>e.identifier</td><td>string</td><td>必填</td><td>事件唯一标识符</td></tr>
<tr><td>e.name</td><td>string</td><td>必填</td><td>事件名称</td></tr>
<tr><td>e.desc</td><td>string</td><td>可选</td><td>事件描述</td></tr>
<tr><td>e.eventType</td><td>string</td><td>必填</td><td>事件类型（info、alert、error）</td></tr>
<tr><td>e.functionType</td><td>string</td><td>必填</td><td>是否是标准功能点，自定义（u）/标准（s）</td></tr>
<tr><td>e.outputData</td><td>array</td><td>必填</td><td>参数</td></tr>
<tr><td>e.outputData.identifier</td><td>string</td><td>必填</td><td>参数唯一标识符</td></tr>
<tr><td>e.outputData.name</td><td>string</td><td>必填</td><td>参数名称</td></tr>
<tr><td>e.outputData.dataType</td><td>object</td><td>必填</td><td>参数数据</td></tr>
<tr><td>e.outputData.dataType.type</td><td>string</td><td>必填</td><td>属性类型: int32（32位整数）、int64（64位整数）、float（单精度浮点）、double（双精度浮点型）、string（字符串）、bool（true或false）、enum（int类型）、bitMap（位图）、date（int64类型UTC时间戳毫秒）、struct（结构体类型）、array（数组）</td></tr>
<tr><td>e.outputData.dataType.specs</td><td>object</td><td>必填</td><td>功能点数据</td></tr>
<tr><td>services</td><td>array</td><td>必填</td><td>数组对象 服务功能点</td></tr>
<tr><td>s.functionMode</td><td>string</td><td>必填</td><td>功能点类型，定值'service'</td></tr>
<tr><td>s.identifier</td><td>string</td><td>必填</td><td>服务唯一标识符（产品下唯一）</td></tr>
<tr><td>s.name</td><td>string</td><td>必填</td><td>服务名称</td></tr>
<tr><td>s.desc</td><td>string</td><td>可选</td><td>服务描述</td></tr>
<tr><td>s.callType</td><td>string</td><td>必填</td><td>调用方式,同步(s)/异步(a)</td></tr>
<tr><td>s.fuctionType</td><td>string</td><td>必填</td><td>功能点类型，自定义（u）/系统（s）</td></tr>
<tr><td>s.input</td><td>array</td><td>可选</td><td>输入参数</td></tr>
<tr><td>s.input.identifier</td><td>string</td><td>必填</td><td>参数唯一标识符</td></tr>
<tr><td>s.input.name</td><td>string</td><td>必填</td><td>参数名称</td></tr>
<tr><td>s.input.dataType</td><td>object</td><td>可选</td><td>参数数据</td></tr>
<tr><td>s.input.dataType.type</td><td>string</td><td>必填</td><td>属性类型: int32（32位整数）、int64（64位整数）、float（单精度浮点）、double（双精度浮点型）、string（字符串）、bool（true或false）、enum（int类型）、bitMap（位图）、date（int64类型UTC时间戳毫秒）、struct（结构体类型）、array（数组）</td></tr>
<tr><td>s.input.dataType.specs</td><td>object</td><td>必填</td><td>参数功能点数据</td></tr>
<tr><td>s.output</td><td>array</td><td>必填</td><td>输出参数</td></tr>
<tr><td>s.output.identifier</td><td>string</td><td>必填</td><td>参数唯一标识符</td></tr>
<tr><td>s.output.name</td><td>string</td><td>必填</td><td>参数名称</td></tr>
<tr><td>s.output.dataType</td><td>object</td><td>可选</td><td>参数数据</td></tr>
<tr><td>s.output.dataType.type</td><td>string</td><td>必填</td><td>属性类型: int32（32位整数）、int64（64位整数）、float（单精度浮点）、double（双精度浮点型）、string（字符串）、bool（true或false）、enum（int类型）、bitMap（位图）、date（int64类型UTC时间戳毫秒）、struct（结构体类型）、array（数组）</td></tr>
<tr><td>s.output.dataType.specs</td><td>object</td><td>必填</td><td>参数功能点数据</td></tr>
</tr><td rowspan="5">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>调用成功时，返回的业务数据</td></tr>

<tr><th>请求示例</th><td colspan="4">
{<br>
   "product_id":"10132", <br>
   "properties": [<br>
    {<br>
            "identifier": "RoomTemp", //必填 标识符<br>
            "name": "房间温度", //必填 功能名称<br>
            "accessMode": "r", //必填 读写属性（r可读，rw读写）<br>
            "functionMode":"property", // 必填 功能类型（property属性，event事件）<br>
            "functionType": "u", //必填 功能点（u代表自定义功能点/s代表系统功能点）<br>
            "dataType": {<br>
                "type": "float", //必填 数据类型<br>
                "specs": {<br>
                    "min": "-20.5", //必填 最小值<br>
                    "max": "50.5", //必填 最大值<br>
                    "unit": "摄氏度/°C", //选填 单位 支持自法定义（长度不超过15）<br>
                    "step": "0.5" //选填 步长<br>
                }<br>
            },<br>
            "desc": "xxxxx" //选填 描述 长度不超过255<br>
        },<br>
        {<br>
            "identifier": "name",<br>
            "name": "名字",<br>
            "accessMode": "rw",<br>
            "functionMode":"property",<br>
            "functionType": "u",<br>
            "dataType": {<br>
                "type": "string",<br>
                "specs": {<br>
                    "length": "234" //必填 字符串长度（不超过255） <br>
                }<br>
            }<br>
        },<br>
        {<br>
            "identifier": "person",<br>
            "name": "人类",<br>
            "accessMode": "rw",<br>
            "functionMode":"property",<br>
            "functionType": "u",<br>
            "dataType": {<br>
                "type": "struct",<br>
                "specs": [{<br>
                        "identifier": "name",<br>
                        "name": "名字",<br>
                        "dataType": {<br>
                            "type": "string",<br>
                            "specs": {<br>
                                "length": "200"<br>
                            }<br>
                        }<br>
                    },<br>
                    {<br>
                        "identifier": "sex",<br>
                        "name": "性别",<br>
                        "dataType": {<br>
                            "type": "bool",<br>
                            "specs": {<br>
                                "true": "男",<br>
                                //必填 true代表的含义（长度不超过20）<br>
                                "false": "女" //必填 false代表的含义（长度不超过20）<br>
                            }<br>
                            }<br>
                        }<br>
                    }<br>
                ]<br>
            }<br>
        },<br>
        {<br>
            "identifier": "createTime",<br>
            "name": "创建时间",<br>
            "functionMode":"property",<br>
            "accessMode": "rw",<br>
            "desc": "设备创建时间",<br>
            "functionType": "u",<br>
            "dataType": {<br>
                "type": "dat",<br>
                "specs": {}<br>
            }<br>
        },<br>
        {<br>
            "identifier": "switch",<br>
            "name": "开关",<br>
            "functionMode":"property",<br>
            "accessMode": "rw",<br>
            "functionType": "u",<br>
            "dataType": {<br>
                "type": "bool",<br>
                "specs": {<br>
                    "true": "关",<br>
                    "false": "开"<br>
                }<br>
            }<br>
        },<br>
        {<br>
            "identifier": "deviceType",<br>
            "name": "设备类型",<br>
            "functionMode":"property",<br>
            "accessMode": "rw",<br>
            "functionType": "u",<br>
            "dataType": {<br>
                "type": "enum",<br>
                "specs": {<br>
                    "1": "真实设备",<br>
                    //必填 参数描述（长度不超过20）<br>
                    "2": "虚拟设备",<br>
                    "3": "云设备"<br>
                }<br>
            }<br>
        },<br>
    {<br>
      "name": "时间测试",<br>
      "identifier": "time_test",<br>
      "functionMode": "property",<br>
      "accessMode": "rw",<br>
      "dataType": {<br>
        "type": "date",<br>
        "specs": {}<br>
      },<br>
      "functionType": "u"<br>
    },<br>
    {<br>
      "name": "数组测试",<br>
      "identifier": "array",<br>
      "functionMode": "property",<br>
      "accessMode": "rw",<br>
      "dataType": {<br>
        "type": "array",<br>
        "specs": {<br>
          "length": "2",<br>
          "type": "int32",<br>
          "specs": {<br>
            "min": "1",<br>
            "max": "6",<br>
            "step": "1",<br>
            "unit": "微西每厘米 / uS/cm"<br>
          }<br>
        }<br>
      },<br>
      "functionType": "u"<br>
    },<br>
        {<br>
            "identifier": "bitMapTest",<br>
            "name": "位图测试",<br>
            "accessMode": "rw",<br>
            "functionMode":"property",<br>
            "functionType": "u",<br>
            "dataType": {<br>
                "type": "bitMap",<br>
                "specs": {<br>
                    "length": 3,<br>
                    //必填 （长度不能超过32）<br>
                    "define": [{<br>
                            "bit": 0,<br>
                            //选填 定义每一位0,1的含义（长度不超过50）<br> 
                            "0": "xxxx",<br>
                            "1": "xxxx"<br>
                        },<br>
                        {<br>
                            "bit": 1,<br>
                            //选填 定义每一位0,1的含义（长度不超过50）<br> 
                            "0": "xxxx",<br>
                            "1": "xxxx"<br>
                        }, ,<br>
                        {<br>
                            "bit": 2,<br>
                            //选填<br>
                            "0": "xxxx"<br>,
                            "1": "xxxx"<br>
                        }<br>
                    ]<br>
                }<br>
            }<br>
        },<br>
        {<br>
            "identifier": "GeoLocation",<br>
            "name": "地理位置",<br>
            "accessMode": "r",<br>
            "functionMode":"property",<br>
            "functionType": "s",<br>
            "dataType": {<br>
                "type": "struct",<br>
                "specs": [{<br>
                        "identifier": "Longitude",<br>
                        "name": "经度",<br>
                        "dataType": {<br>
                            "type": "double",<br>
                            "specs": {<br>
                                "min": "-180",<br>
                                "max": "180",<br>
                                "unit": "度/°",<br>
                                "step": "0.01"<br>
                            }<br>
                        }<br>
                    },<br>
                    {<br>
                        "identifier": "Latitude",<br>
                        "name": "纬度",<br>
                        "dataType": {<br>
                            "type": "double",<br>
                            "specs": {<br>
                                "min": "-90",<br>
                                "max": "90",<br>
                                "unit": "度/°",<br>
                                "step": "0.01"<br>
                            }<br>
                        }<br>
                    },<br>
                    {<br>
                        "identifier": "Altitude",<br>
                        "name": "海拔",<br>
                        "dataType": {<br>
                            "type": "double",<br>
                            "specs": {<br>
                                "min": "0",<br>
                                "max": "9999",<br>
                                "unit": "米/m",<br>
                                "step": "0.01"<br>
                            }<br>
                        }<br>
                    },<br>
                    {<br>
                        "identifier": "CoordinateSystem",<br>
                        "name": "坐标系统",<br>
                        "dataType": {<br>
                            "type": "enum",<br>
                            "specs": {<br>
                                "1": "WGS_84",<br>
                                "2": "GCJ_02"<br>
                            }<br>
                        }<br>
                    }<br>
                ]<br>
            }<br>
        },<br>
        {<br>
            "identifier": "$arrayTest",<br>
            "name": "nihao",<br>
            "accessMode": "rw",<br>
            "functionMode":"property",<br>
            "functionType": "s",<br>
            "dataType": {<br>
                "type": "array",<br>
                "specs": {<br>
                    "size": "10",<br>
                    "item": {<br>
                        "type": "struct",<br>
                        "specs": [{<br>
                                "identifier": "temp",<br>
                                "name": "温度",<br>
                                "dataType": {<br>
                                    "type": "int32",<br>
                                    "specs": {<br>
                                        "min": "10",<br>
                                        "max": "20",<br>
                                        "step": "1"<br>
                                    }<br>
                                }<br>
                            },<br>
                            {<br>
                                "identifier": "hum",<br>
                                "name": "湿度",<br>
                                "dataType": {<br>
                                    "type": "float",<br>
                                    "specs": {<br>
                                        "min": "10.1",<br>
                                        "max": "20.1",<br>
                                        "step": "0.1"<br>
                                    }<br>
                                }<br>
                            }<br>
                        ]<br>
                    }<br>
                }<br>
            }<br>
        }<br>
    ],<br>
    "events": [{<br>
            "identifier": "post",<br>
            "name": "post",<br>
            "eventType": "info",<br>
            "functionMode":"event",<br>
            "functionType": "s",<br>
            "desc": "属性上报",<br>
            "outputData": [{<br>
                    "identifier": "RoomTemp",<br>
                    "name": "房间温度",<br>
                    "dataType": {<br>
                        "type": "float",<br>
                        "specs": {<br>
                            "min": "-20.5",<br>
                            "max": "50.5",<br>
                            "unit": "摄氏度/°C",<br>
                            "step": "0.5"<br>
                        }<br>
                    }<br>
                },<br>
                {<br>
                    "identifier": "name",<br>
                    "name": "名字",<br>
                    "dataType": {<br>
                        "type": "string",<br>
                        "specs": {<br>
                            "length": "240"<br>
                        }<br>
                    }<br>
                },<br>
                {<br>
                    "identifier": "person",<br>
                    "name": "人类",<br>
                    "dataType": {<br>
                        "type": "struct",<br>
                        "specs": [{<br>
                                "identifier": "name",<br>
                                "name": "名字",<br>
                                "dataType": {<br>
                                    "type": "string",<br>
                                    "specs": {<br>
                                        "length": "240"<br>
                                    }<br>
                                }<br>
                            },<br>
                            {<br>
                                "identifier": "sex",<br>
                                "name": "性别",<br>
                                "dataType": {<br>
                                    "type": "bool",<br>
                                    "specs": {<br>
                                        "0": "男",<br>
                                        "1": "女"<br>
                                    }<br>
                                }<br>
                            }<br>
                        ]<br>
                    }<br>
                },<br>
                {<br>
                    "identifier": "createTime",<br>
                    "name": "创建时间",<br>
                    "dataType": {<br>
                        "type": "date",<br>
                        "specs": {}<br>
                    }<br>
                },<br>
                {<br>
                    "identifier": "switch",<br>
                    "name": "开关",<br>
                    "dataType": {<br>
                        "type": "bool",<br>
                        "specs": {<br>
                            "0": "关",<br>
                            "1": "开"<br>
                        }<br>
                    }<br>
                },<br>
                {<br>
                    "identifier": "deviceType",<br>
                    "name": "设备类型",<br>
                    "dataType": {<br>
                        "type": "enum",<br>
                        "specs": {<br>
                            "1": "真实设备",<br>
                            "2": "虚拟设备",<br>
                            "3": "云设备"<br>
                        }<br>
                    }<br>
                },<br>
                {<br>
                    "identifier": "GeoLocation",<br>
                    "name": "地理位置",<br>
                    "dataType": {<br>
                        "type": "struct",<br>
                        "specs": [{<br>
                                "identifier": "Longitude",<br>
                                "name": "经度",<br>
                                "dataType": {<br>
                                    "type": "double",<br>
                                    "specs": {<br>
                                        "min": "-180",<br>
                                        "max": "180",<br>
                                        "unit": "度/°"，<br>
                                        "step": "0.01"<br>
                                    }<br>
                                }<br>
                            },<br>
                            {<br>
                                "identifier": "Latitude",<br>
                                "name": "纬度",<br>
                                "dataType": {<br>
                                    "type": "double",<br>
                                    "specs": {<br>
                                        "min": "-90",<br>
                                        "max": "90",<br>
                                        "unit": "度/°"，<br>
                                        "step": "0.01"<br>
                                    }<br>
                                }<br>
                            },<br>
                            {<br>
                                "identifier": "Altitude",<br>
                                "name": "海拔",<br>
                                "dataType": {<br>
                                    "type": "double",<br>
                                    "specs": {<br>
                                        "min": "0",<br>
                                        "max": "9999",<br>
                                        "unit": "米/m"，<br>
                                        "step": "0.01"<br>
                                    }<br>
                                }<br>
                            },<br>
                            {<br>
                                "identifier": "CoordinateSystem",<br>
                                "name": "坐标系统",<br>
                                "dataType": {<br>
                                    "type": "enum",<br>
                                    "specs": {<br>
                                        "1": "WGS_84",<br>
                                        "2": "GCJ_02"<br>
                                    }<br>
                                }<br>
                            }<br>
                        ]<br>
                    }<br>
                }<br>
            ]<br>
        },<br>
        {<br>
            "identifier": "tempWarming",<br>
            "name": "温度告警事件",<br>
            "type": "info",<br>
            "functionMode":"event",<br>
            "functionType": "u",<br>
            "outputData": [{<br>
                    "identifier": "TaskId",<br>
                    "name": "任务ID",<br>
                    "dataType": {<br>
                        "type": "string",<br>
                        "specs": {<br>
                            "length": "64"<br>
                        }<br>
                    }<br>
                },<br>
                {<br>
                    "identifier": "Process",<br>
                    "name": "部署进度",<br>
                    "dataType": {<br>
                        "type": "int64",<br>
                        "specs": {<br>
                            "min": "0",<br>
                            "max": "100",<br>
                            "unit": "无/",<br>
                            "step": "1"<br>
                        }<br>
                    }<br>
                },<br>
                {<br>
                    "identifier": "Code",<br>
                    "name": "返回码",<br>
                    "dataType": {<br>
                        "type": "enum",<br>
                        "specs": {<br>
                            "0": "成功",<br>
                            "1": "算法平台不支持",<br>
                            "2": "下载模型失败",<br>
                            "3": "MD5校验失败",<br>
                            "4": "解压失败"<br>
                        }<br>
                    }<br>
                },<br>
                {<br>
                    "identifier": "Message",<br>
                    "name": "返回信息",<br>
                    "dataType": {<br>
                        "type": "string",<br>
                        "specs": {<br>
                            "length": "256"<br>
                        }<br>
                    }<br>
                }<br>
            ]<br>
        }<br>
    ],<br>
    "services": [<br>
        {<br>
            "callType": "a", <br>
            "desc": null,<br> 
            "functionMode": "service",<br> 
            "functionType": "u",<br> 
            "identifier": "test",<br> 
            "input": [<br>
                {<br>
                    "dataType": {<br>
                        "specs": {<br>
                            "max": "1111",<br> 
                            "min": "1", <br>
                            "step": "1"<br>
                        }, <br>
                        "type": "int32"<br>
                    }, <br>
                    "identifier": "name",<br> 
                    "name": "name"<br>
                }<br>
            ],<br> 
            "name": "test", <br>
            "output": [<br>
                {<br>
                    "dataType": {<br>
                        "specs": {<br>
                            "max": "111",<br> 
                            "min": "1",<br> 
                            "step": "1"<br>
                        }, <br>
                        "type": "int32"<br>
                    }, <br>
                    "identifier": "result",<br> 
                    "name": "result"<br>
                }<br>
            ]<br>
        }<br>
    ]<br>
}<br>
</th></tr>
<tr><th>响应示例</th><td colspan="4">
{<br>
    "requestId": "a25087f46df04b69b29e90ef0acfd115", <br>
    "success": true<br>
}<br>
</th></tr>
</table>