# 场景联动触发日志

#### 接口名称

> QuerySceneLog

#### 请求方法

> GET

#### 请求参数
|参数名称 | 类型 | 是否必选  | 描述 |
|:- | :- | :-  | :- |
|project_id | string | 是 | 项目ID |
|scene_id | string | 是 | 场景联动规则ID |
|start_time | string | 否  | 查询起始时间，例如2020-07-10T05:59:02.833Z |
|end_time | string | 否  | 查询起始时间 |
|offset | string | 否  | 请求起始位置，默认0 |
|limit | string | 否 | 每次请求记录数，默认10, 范围[1, 100] |

#### 返回数据
|参数名称 | 类型  | 描述 |
|:- | :- | :- |
| code | string  | 调用失败时，返回的错误码 |
| msg  | string | 调用失败时，返回的错误信息 |
| requestId | string  | 调用API时生成的请求标识  |
| success | boolean | 接口是否调用成功 |
| data | - | 调用成功时，返回的业务数据 |
| data.list | array | 场景联动触发日志集合 |
| data.meta | object | 分页信息 |

##### data.list 字段结构为

```
[
    {
        "conditions": [ # 触发条件
            {
                "ctype": string, # 触发方式 lifeCycle - 设备生命周期触发
                "device_name": string, # 设备名称
                "product_id": string, # 产品ID
                "value": string, # 功能点值
                "operator": string, # 比较运算符 eq-等于
            },  
            {
                "ctype": string , # 触发方式 notify - 设备数据上报
                "device_name": string, # 设备名称
                "product_id": string, # 产品ID
                "identifier": string, # 功能点标识
                "type": string, # 功能点数据类型
                "value": string, # 预设值
                "operator": string, # 比较运算符 
            },
            {
                "ctype": string, # 触发方式 extension - 第三方数据触发
                "value": string,  # 第三方数据比较值
                "operator": string, # 比较运算符 eq-等于 lt-小于 gt-大于 lte-小于等于 gte-大于等于
                "ext": {  
                    "ad_code": string,  # 城市编码
                    "type": string # 第三方数据类型  weather-天气 temperature-温度 humidity-湿度 pm25-pm2.5  airquality-空气质量
                }
            },
            {
                "ctype": string, # 触发方式 timer - 定时条件触发
                "timer": {
                    "repeat_day": array, # 重复周期 支持[mon、tue、wed、thu、fri、sat、sun]
                }
                "time": string, # 定时触发时间
                "cron": string  # cron时间格式
             }
        ],
        "actions": [ # 执行动作
            // 执行动作 - 设备执行
            {
                "device_name": string, # 设备名称
                "product_id": string, # 产品ID
                "identifier": string, # 功能点标识
                "type": string, # 功能点数据类型
                "value": string, # 预设值
                "success": boolean, # 执行结果
                "message": string, # 执行错误码
            },
            // 执行动作 - API调用
            {
                "callback": {
                    "url": string # API调用地址
                }，
		        "success": boolean, # 执行结果
                "message": string, # 执行错误码
            },    
        ],
        "scene_id": string, # 联动规则ID
        "status": string, # 执行结果
        "created_at": string, # 触发时间
    }
]
```

##### data.meta 字段结构为

```
{
    "limit": int, # 每次请求记录数
    "offset": int, # 请求记录起始位置
    "count": int, # 记录总数
}
```

#### 示例

##### 请求示例

```
GET /application?action=QuerySceneLog&version=1&project_id=ocgzVU
&scene_id=5ec48dce640d1b02043a6a59

```

##### 响应示例

```
{
    "data": {
        "list": [
            {
                "conditions": [
                    {
                        "ctype": "notify",
                        "device_name": "30769-datou1",
                        "product_id": "30769",
                        "identifier": "1",
                        "type": "bool",
                        "value": "true",
                        "operator": "eq"
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
                "actions": [
                    {
                        "device_name": "30769-datou1",
                        "product_id": "30769",
                        "identifier": "1",
                        "type": "bool",
                        "value": "true",
                        "success": true,
                        "message": "命令下发成功"
                    }
                ],
                "scene_id": "5ec48dce640d1b02043a6a59",
                "status": "allsuccess ",
                "created_at": "2020-05-21T01:27:18.974Z",
                "updated_at": "2020-05-21T01:27:18.974Z"
            }
        ],
        "meta": {
            "count": 1,
            "limit": 10,
            "offset": 0
        },
    },
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
```