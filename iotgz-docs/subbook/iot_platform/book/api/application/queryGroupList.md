# 分组列表

#### 接口名称

> QueryGroupList

#### 请求方法

> GET

#### 请求参数

| 参数名称   | 类型   | 是否必选 | 描述                                             |
| :--------- | :----- | :------- | :----------------------------------------------- |
| project_id | string | 是       | 项目ID                                           |
| name       | string | 否       | 分组名称                                         |
| key        | string | 否       | 标签key（key、value需成对出现，否则没有效果）    |
| value      | string | 否       | 标签value（key、value 需成对出现，否则没有效果） |
| offset     | string | 否       | 请求记录起始位置，默认 0                         |
| limit      | string | 否       | 每次请求记录数，默认10                           |

#### 返回数据

| 参数名称  | 类型    | 描述                       |
| :-------- | :------ | :------------------------- |
| code      | string  | 调用失败时，返回的错误码   |
| msg       | string  | 调用失败时，返回的错误信息 |
| requestId | string  | 调用API时生成的请求标识    |
| success   | boolean | 接口是否调用成功           |
| data      | -       | 调用成功时，返回的业务数据 |
| data.list | array   | 分组信息集合               |
| data.meta | object  | 分页信息                   |

##### data.list 字段结构为

```
[
    { 
        "project_id": "3C6Djy", // 项目id
        "name": "xq_group1", // 分组名称
        "group_id": "qf6nAD", // 分组id
        "key":"ZDM0MzA4MTA3MjQ4NzdlYzZjOGJlYzU1YmUwZTNhMmY=", //分组key
        "tag": {
            "xq": "123"  //标签信息
        }, 
        "created_time": "2020-08-13T01:49:17.694Z", //创建时间
        "device_count": 2 //设备数
    }
]
```

##### data.meta 字段结构为

```
{
    "limit": int, # 每次请求记录数
    "offset": int, # 请求记录起始位置
    "total": int, # 记录总数
}
```

#### 示例

##### 请求示例

```
GET /application?action=QueryGroupList&version=1&project_id=3C6Djy
```

##### 响应示例

```
{
    "data": {
        "list": [
            {
                "project_id": "3C6Djy",
                "name": "xq_group1",
                "group_id": "qf6nAD",
                "key": "ZDM0MzA4MTA3MjQ4NzdlYzZjOGJlYzU1YmUwZTNhMmY=",
                "tag": {
                    "xq": "123"
                },
                "created_time":"2020-08-13T01:49:17694,
                "device_count": 2
            }
        ],
        "meta": {
            "limit": 10,
            "offset": 0,
            "total": 1
        }
    },
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
```
