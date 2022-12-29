# 场景联动规则详情

#### 接口名称

> QuerySceneRuleDetail

#### 请求方法

> GET

#### 请求参数
|参数名称 | 类型 | 是否必选  | 描述 |
|:- | :- | :- | :- |
|project_id | string | 是 | 项目ID |
|scene_id | string | 是 | 场景联动规则ID | 

#### 返回数据
|参数名称 | 类型 | 描述 |
|:- | :- | :- |
|code | string | 调用失败时，返回的错误码 |
|msg  | string | 调用失败时，返回的错误信息 |
|requestId | string | 调用API时生成的请求标识  |
|success | boolean | 接口是否调用成功 |
|data | - | 调用成功时，返回的业务数据 |
|data.name | string | 项目ID |
|data.conditions | array | 触发方式集合 |
|data.actions | array | 执行动作集合 |
|data.emit_condition | string | 执行条件，all-全部触发, any-任意触发 |
|data.created_at | string | 创建时间 |
|data.updated_at | string | 更新时间 |

##### data.conditions字段结构
```
[
    {
        "ctype": string, # 触发方式 lifeCycle - 设备生命周期触发
        "device_name": string, # 设备名称
        "product_id": string, # 产品ID
        "value": string, # 功能点值
        "operator": string, # 比较运算符 eq-等于
    },
    {
        "ctype": string, # 触发方式 notify - 设备数据上报触发
        "device_name": string, # 设备名称
        "product_id": string, # 产品ID
        "identifier": string, # 属性功能点标识
        "type": string, # 功能点数据类型
        "value": string, # 功能点值
        "operator": string, # 比较运算符 eq-等于 lt-小于 gt-大于 lte-小于等于 gte-大于等于
    },
    {
        "ctype": string, # 触发方式 extension - 第三方数据触发
        "value": string,  # 第三方数据比较值
        "operator": string, # 比较运算符 eq-等于 lt-小于 gt-大于 lte-小于等于 gte-大于等于
        "ext": {  
            "ad_code": string,  # 城市编码
            "type": string # 第三方数据类型  weather-天气  temperature-温度 humidity-湿度 pm25-pm2.5  airquality-空气质量
        }
    },
    {
        "ctype": string, # 触发方式 timer - 定时条件触发
        "timer": {
            "repeat_day": array, # 重复周期 支持[mon 、tue、wed、thu、fri、sat、sun]
            "time": string, # 定时触发时间
            "cron": string  # cron时间格式
        }
    }
]
```

##### data.actions 字段结构为

```
[
    // 执行动作 - 设备执行
    {
        "device_name": string, # 设备名称
        "product_id": string, # 产品ID
        "identifier": string, #  属性功能点标识
        "type": string, # 功能点数据类型
        "value": string, # 功能点值
    },
    // 执行动作 - API调用
    {
        "callback": {
            "url": string  # API调用地址
        }
    }
]
```

#### 示例

##### 请求示例

```
GET /application?action=QuerySceneRuleDetail&version=1&project_id=ocgzVU&
scene_id=5ec48dce640d1b02043a6a59

```

##### 响应示例

```
{
    "data": {
        "name":"联动测试",
        "conditions":[
            {   
                "ctype":"notify",
                "device_name":"datou1",
                "product_id":"30769",
                "identifier":"1",
                "type":"bool",
                "value":"true",
                "operator":"eq"
            },
            {
                "ctype": "extension", 
                "value": "BAD",   
                "operator": "gt",
                "ext": {
                    "ad_code": "101041200",   
                    "type": "airquality"
                }
            },
            {
                "ctype": "timer",     
                "timer": {
                    "repeat_day": [ 
                        "wed" 
                    ],
                    "time": "01:02:07",
                    "cron": "07 02 01 ? * WED *"
                }
            }
        ],
        "actions":[
            {
                "device_name":"datou1",
                "product_id":"30769",
                "identifier":"1",
                "type":"bool",
                "value":"true"
        }],
        "emit_condition":"all",
        "created_at": "2020-05-20T01:37:45.187Z",
        "updated_at": "2020-05-20T01:45:35.149Z"
    },
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
```