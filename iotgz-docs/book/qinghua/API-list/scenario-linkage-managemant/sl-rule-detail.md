# 场景联动规则详情

<table>
<tr><th>方法</th><td colspan="4">GET</th></tr>
<tr><td>路径URI</td><td colspan="4">/application?action=QuerySceneRuleDetail&version=1&project_id=ocgzVU&scene_id=5ec48dce640d1b02043a6a59</td></tr>
<tr><td>请求头</td><td colspan="4"></td></tr>
<tr><td rowspan="2">URL请求参数</td><td>project_id</td><td>string</td><td>必填</td><td>项目ID</td></td>
<tr><td>scene_id</td><td>string</td><td>必填</td><td>场景联动规则ID</td></tr>
<tr><td>请求体参数</td><td colspan="4">无</td></tr>

<tr><td rowspan="11">响应参数</td><td colspan="2">code</td><td>string</td><td>调用失败时，返回的错误码</td></tr>
<tr><td colspan="2">msg</td><td>string</td><td>调用失败时，返回的错误信息</td></tr>
<tr><td colspan="2">requestId</td><td>string</td><td>调用API时生成的请求标识</td></tr>
<tr><td colspan="2">success</td><td>boolean</td><td>接口是否调用成功</td></tr>
<tr><td colspan="2">data</td><td>-</td><td>调用成功返回业务数据</td></tr>
<tr><td colspan="2">data.name</td><td>string</td><td>项目名称</td></tr>
<tr><td colspan="2">data.conditions</td><td>array</td><td>触发方式集合</td></tr>
<tr><td colspan="2">data.actions</td><td>array</td><td>执行动作集合</td></tr>
<tr><td colspan="2">data.emit_condition</td><td>string</td><td>执行条件，all-全部触发, any-任意触发</td></tr>
<tr><td colspan="2">data.created_at</td><td>string</td><td>创建时间</td></tr>
<tr><td colspan="2">data.updated_at</td><td>string</td><td>更新时间</td></tr>

<tr><th>字段结构描述</th><td colspan="4">
data.conditions字段结构：<br>
[<br>
    {<br>
        "ctype": string, # 触发方式 lifeCycle - 设备生命周期触发<br>
        "device_name": string, # 设备名称<br>
        "product_id": string, # 产品ID<br>
        "value": string, # 功能点值<br>
        "operator": string, # 比较运算符 eq-等于<br>
    },<br>
    {<br>
        "ctype": string, # 触发方式 notify - 设备数据上报触发<br>
        "device_name": string, # 设备名称<br>
        "product_id": string, # 产品ID<br>
        "identifier": string, # 属性功能点标识<br>
        "type": string, # 功能点数据类型<br>
        "value": string, # 功能点值<br>
        "operator": string, # 比较运算符 eq-等于 lt-小于 gt-大于 lte-小于等于 gte-大于等于<br>
    },<br>
    {<br>
        "ctype": string, # 触发方式 extension - 第三方数据触发<br>
        "value": string,  # 第三方数据比较值<br>
        "operator": string, # 比较运算符 eq-等于 lt-小于 gt-大于 lte-小于等于 gte-大于等于<br>
        "ext": {  <br>
            "ad_code": string,  # 城市编码<br>
            "type": string # 第三方数据类型  weather-天气  temperature-温度 humidity-湿度 pm25-pm2.5  airquality-空气质量<br>
        }<br>
    },<br>
    {<br>
        "ctype": string, # 触发方式 timer - 定时条件触发<br>
        "timer": {<br>
            "repeat_day": array, # 重复周期 支持[mon 、tue、wed、thu、fri、sat、sun]<br>
            "time": string, # 定时触发时间<br>
            "cron": string  # cron时间格式<br>
        }<br>
    }<br>
]<br>
data.actions 字段结构为：<br>
[<br>
    // 执行动作 - 设备执行<br>
    {<br>
        "device_name": string, # 设备名称<br>
        "product_id": string, # 产品ID<br>
        "identifier": string, #  属性功能点标识<br>
        "type": string, # 功能点数据类型<br>
        "value": string, # 功能点值<br>
    },<br>
    // 执行动作 - API调用<br>
    {<br>
        "callback": {<br>
            "url": string  # API调用地址<br>
        }<br>
    }<br>
]<br>
</th></tr>

<tr><th>请求示例</th><td colspan="4">GET /application?action=QuerySceneRuleDetail&version=1&project_id=ocgzVU&scene_id=5ec48dce640d1b02043a6a59</th></tr>
<tr><th>响应示例</th><td colspan="4">
{<br>
    "data": {<br>
        "name":"联动测试",<br>
        "conditions":[<br>
            {<br>   
                "ctype":"notify",<br>
                "device_name":"datou1",<br>
                "product_id":"30769",<br>
                "identifier":"1",<br>
                "type":"bool",<br>
                "value":"true",<br>
                "operator":"eq"<br>
            },<br>
            {<br>
                "ctype": "extension", <br>
                "value": "BAD", <br>  
                "operator": "gt",<br>
                "ext": {<br>
                    "ad_code": "101041200", <br>  
                    "type": "airquality"<br>
                }<br>
            },<br>
            {<br>
                "ctype": "timer",<br>     
                "timer": {<br>
                    "repeat_day": [ <br>
                        "wed" <br>
                    ],<br>
                    "time": "01:02:07",<br>
                    "cron": "07 02 01 ? * WED *"<br>
                }<br>
            }<br>
        ],<br>
        "actions":[<br>
            {<br>
                "device_name":"datou1",<br>
                "product_id":"30769",<br>
                "identifier":"1",<br>
                "type":"bool",<br>
                "value":"true"<br>
        }],<br>
        "emit_condition":"all",<br>
        "created_at": "2020-05-20T01:37:45.187Z",<br>
        "updated_at": "2020-05-20T01:45:35.149Z"<br>
    },<br>
    "requestId": "a25087f46df04b69b29e90ef0acfd115",<br> 
    "success": true<br>
}<br>
</th></tr>
</table>
