# 场景联动触发日志

<table>
<tr><th>方法</th><td colspan="4">GET</th></tr>
<tr><td>路径URI</td><td colspan="4">/application?action=QuerySceneLog&version=1&project_id=ocgzVU&scene_id=5ec48dce640d1b02043a6a59</td></tr>
<tr><td>请求头</td><td colspan="4"></td></tr>

<tr><td rowspan="6">URL请求参数</td><td>project_id</td><td>string</td><td>必填</td><td>项目ID</td></td>
<tr><td>scene_id</td><td>string</td><td>必填</td><td>场景联动规则ID</td></tr>
<tr><td>start_time</td><td>string</td><td>可选</td><td>查询起始时间，例如2020-07-10T05:59:02.833Z</td></tr>
<tr><td>end_time</td><td>string</td><td>可选</td><td>查询起始时间</td></tr>
<tr><td>offset</td><td>string</td><td>可选</td><td>请求起始位置，默认0</td></tr>
<tr><td>limit</td><td>string</td><td>可选</td><td>每次请求记录数，默认10, 范围[1, 100]</td></tr>
<tr><td>请求体参数</td><td colspan="4">无</td></tr>

<tr><td rowspan="10">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>调用成功返回业务数据</td></tr>
<tr><td colspan="2">data.list</td><td>array</td><td>场景联动触发日志集合</td></tr>
<tr><td colspan="2">data.meta</td><td>object</td><td>分页信息</td></tr>
<tr><td colspan="2">data.meta.limit</td><td>int</td><td>每次请求记录数</td></tr>
<tr><td colspan="2">data.meta.offset</td><td>int</td><td>请求记录起始位置</td></tr>
<tr><td colspan="2">data.meta.count</td><td>int</td><td>记录总数</td></tr>

<tr><th>字段结构描述</th><td colspan="4">
data.list字段结构：<br>
[<br>
    {<br>
        "conditions": [ # 触发条件<br>
            {<br>
                "ctype": string, # 触发方式 lifeCycle - 设备生命周期触发<br>
                "device_name": string, # 设备名称<br>
                "product_id": string, # 产品ID<br>
                "value": string, # 功能点值<br>
                "operator": string, # 比较运算符 eq-等于<br>
            },  <br>
            {<br>
                "ctype": string , # 触发方式 notify - 设备数据上报<br>
                "device_name": string, # 设备名称<br>
                "product_id": string, # 产品ID<br>
                "identifier": string, # 功能点标识<br>
                "type": string, # 功能点数据类型<br>
                "value": string, # 预设值<br>
                "operator": string, # 比较运算符 <br>
            },<br>
            {<br>
                "ctype": string, # 触发方式 extension - 第三方数据触发<br>
                "value": string,  # 第三方数据比较值<br>
                "operator": string, # 比较运算符 eq-等于 lt-小于 gt-大于 lte-小于等于 gte-大于等于<br>
                "ext": { <br> 
                    "ad_code": string,  # 城市编码<br>
                    "type": string # 第三方数据类型  weather-天气 temperature-温度 humidity-湿度 pm25-pm2.5  airquality-空气质量<br>
                }<br>
            },<br>
            {<br>
                "ctype": string, # 触发方式 timer - 定时条件触发<br>
                "timer": {<br>
                    "repeat_day": array, # 重复周期 支持[mon、tue、wed、thu、fri、sat、sun]<br>
                }<br>
                "time": string, # 定时触发时间<br>
                "cron": string  # cron时间格式<br>
             }<br>
        ],<br>
        "actions": [ # 执行动作<br>
            // 执行动作 - 设备执行<br>
            {<br>
                "device_name": string, # 设备名称<br>
                "product_id": string, # 产品ID<br>
                "identifier": string, # 功能点标识<br>
                "type": string, # 功能点数据类型<br>
                "value": string, # 预设值<br>
                "success": boolean, # 执行结果<br>
                "message": string, # 执行错误码<br>
            },<br>
            // 执行动作 - API调用<br>
            {<br>
                "callback": {<br>
                    "url": string # API调用地址<br>
                }，<br>
                "success": boolean, # 执行结果<br>
                "message": string, # 执行错误码<br>
            }, <br>   
        ],<br>
        "scene_id": string, # 联动规则ID<br>
        "status": string, # 执行结果<br>
        "created_at": string, # 触发时间<br>
    }<br>
]        "value": string, # 功能点值<br>
    },<br>
    // 执行动作 - API调用<br>
    {<br>
        "callback": {<br>
            "url": string  # API调用地址<br>
        }<br>
    }<br>
]<br>
</th></tr>

<tr><th>请求示例</th><td colspan="4">GET /application?action=QuerySceneLogversion=1&project_id=ocgzVU&scene_id=5ec48dce640d1b02043a6a59</th></tr>
<tr><th>响应示例</th><td colspan="4">
{<br>
    "data": {<br>
        "list": [<br>
            {<br>
                "conditions": [<br>
                    {<br>
                        "ctype": "notify",<br>
                        "device_name": "30769-datou1",<br>
                        "product_id": "30769",<br>
                        "identifier": "1",<br>
                        "type": "bool",<br>
                        "value": "true",<br>
                        "operator": "eq"<br>
                    },<br>
                    {<br>
                        "ctype": "extension", <br> 
                        "value": "BAD",<br>       
                        "operator": "gt",<br>
                        "ext": {<br>
                            "ad_code": "101041200",<br>
                            "type": "airquality"<br> 
                        }<br>
                    },<br>
                    {<br>
                        "ctype": "timer",<br>
                        "timer": {<br>
                            "repeat_day": [<br>
                                "wed"<br>
                            ],<br>
                            "time": "01:02:07",<br>
                            "cron": "07 02 01 ? * WED *"<br>
                        }<br>
                    }<br>
                ],<br>
                "actions": [<br>
                    {<br>
                        "device_name": "30769-datou1",<br>
                        "product_id": "30769",<br>
                        "identifier": "1",<br>
                        "type": "bool",<br>
                        "value": "true",<br>
                        "success": true,<br>
                        "message": "命令下发成功"<br>
                    }<br>
                ],<br>
                "scene_id": "5ec48dce640d1b02043a6a59",<br>
                "status": "allsuccess ",<br>
                "created_at": "2020-05-21T01:27:18.974Z",<br>
                "updated_at": "2020-05-21T01:27:18.974Z"<br>
            }<br>
        ],<br>
        "meta": {<br>
            "count": 1,<br>
            "limit": 10,<br>
            "offset": 0<br>
        },<br>
    },<br>
    "requestId": "a25087f46df04b69b29e90ef0acfd115", <br>
    "success": true<br>
}<br>
</th></tr>
</table>