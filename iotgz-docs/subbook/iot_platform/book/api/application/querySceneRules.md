# 场景联动规则列表

#### 接口名称

> QuerySceneRules

#### 请求方法

> GET

#### 请求参数
|参数名称 | 类型 | 是否必选  | 描述 |
|:- | :- | :- | :- |
|project_id | string | 是  | 项目ID |
|offset | string | 否 | 请求起始位置，默认0 |
|limit | string | 否  | 每次请求记录数，默认10, 范围[1, 100] |

#### 返回数据
|参数名称 | 类型 | 描述 |
|:- | :- | :- | :- |
| code | string | 调用失败时，返回的错误码 |
| msg  | string | 调用失败时，返回的错误信息 |
| requestId | string  | 调用API时生成的请求标识  |
| success | boolean | 接口是否调用成功 |
| data | - | 调用成功时，返回的业务数据 |
| data.list | array | 场景联动规则集合 |
| data.meta | object | 分页信息 |

##### data.list 字段结构为

```
[
    {
      "name": string, # 规则名称
      "scene_id": string, # 规则ID
      "start": string , # 规则是否启用
      "created_at": string, # 创建时间
      "updated_at": string, # 更新时间
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
GET /application?action=QuerySceneRules&version=1&project_id=ocgzVU

```

##### 响应示例

```
{
    "data": {
        "list": [
          {
            "name": "联动测试",
            "scene_id": "a25087f46df04b69b29e90ef0acfd115",
            "start": true,
            "created_at": "2020-05-20T01:37:45.187Z",
            "updated_at": "2020-05-20T01:45:35.149Z"
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