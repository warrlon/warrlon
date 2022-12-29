# 场景联动规则编辑

#### 接口名称

> UpdateSceneRule

#### 请求方法:

> POST

#### 请求参数
|参数名称 | 类型 | 是否必选  | 描述 |
|:- | :- | :-  | :- |
|project_id | string | 是  | 项目ID |
|scene_id | string | 是  | 场景联动规则ID |
|name | string | 是  | 场景联动规则名称 | 
|conditions | array | 是  | 触发条件集合，接口只支持设备生命周期、设备数据上报两种触发方式，<br/>定时触发、第三方数据触发可通过页面设置 |
|actions | array  | 是   | 执行动作集合 |
|emit_condition | string | 是  | 触发方式，all - 满足全部条件触发, any - 任意条件触发|  

##### conditions字段结构
```
[
    {
        "ctype": string, # 触发方式 支持lifeCycle-设备生命周期、 notify-设备数据上报
        "device_name": string, # 设备名称
        "product_id": string, # 产品ID
        "identifier": string, # 属性功能点标识
        "type": string, # 功能点数据类型 支持int32、int64、float、double、string、bool
        "value": string, # 功能点值 触发方式为lifecycle时，value值为online或者offline
        "operator": string, # 比较运算符 支持eq-等于、lt-小于、gt-大于、lte-小于等于、gte-大于等于
    }
    // 注：当ctype为lifeCycle时，只需填product_id、device_name、value和operator字段
]
```

##### actions字段结构为

```
[
    {
        "device_name": string, # 设备名称
        "product_id": string, # 产品ID
        "identifier": string, #  属性功能点标识
        "type": string, # 功能点数据类型
        "value": string, # 功能点值
    }
]
```

#### 返回数据
|参数名称 | 类型  | 描述 |
|:- | :- | :- |
| code | string  | 调用失败时，返回的错误码 |
| msg  | string | 调用失败时，返回的错误信息 |
| requestId | string  | 调用API时生成的请求标识  |
| success | boolean  | 接口是否调用成功 |
| data | - | 调用成功时，返回的业务数据 |
| data.id | string | 场景ID |

#### 示例

##### 请求示例

```
POST /application?action=UpdateSceneRule&version=1
Content-type: application/json

{
    "project_id":"ocgzVU",
    "scene_id":"5ee2031009f703003737cd5b", 
    "name":"联动测试",
    "conditions":[ // 触发条件集合
        {   
            "ctype":"notify", 
            "device_name":"no001",
            "product_id":"30769",
            "identifier":"1", 
            "type":"bool",
            "value":"true",
            "operator":"eq" 
    }],
    "actions":[  // 执行动作集合
        {
            "device_name":"no001",
            "product_id":"30769",
            "identifier":"1",
            "type":"bool",
            "value":"true"
    }],
   "emit_condition":"all"
}
```

##### 响应示例

```
{
    "data": {
        "id": "5ee2031009f703003737cd5b"
    },
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
```
