# 分组设备移除

#### 接口名称

> RemoveGroupDevice

#### 请求方法

> POST

#### 请求参数

| 参数名称   | 类型   | 是否必选 | 描述               |
| :--------- | :----- | :------- | :----------------- |
| project_id | string | 是       | 项目ID             |
| group_id         | string | 是       | 分组ID             |
| product_id | string | 是       | 产品ID             |
| devices    | arrary | 是       | 需要移除的设备集合 |

#### 返回数据

| 参数名称        | 类型    | 描述                       |
| :-------------- | :------ | :------------------------- |
| code            | string  | 调用失败时，返回的错误码   |
| msg             | string  | 调用失败时，返回的错误信息 |
| requestId       | string  | 调用API时生成的请求标识    |
| success         | boolean | 接口是否调用成功           |
| data            | -       | 调用成功时，返回的业务数据 |
| data.error_data | array   | 移除失败的错误信息集合     |

##### data.err_data 字段结构为

```
[
    {
        "device_name": string, # 移除失败的设备集合
        "cause": string, # 移除失败原因
    }
]
```

#### 示例

##### 请求示例

```
POST /application?action=RemoveGroupDevice&version=1
Content-type: application/json

{
    "project_id": "3C6Djy",
    "group_id": "Z1Pdei",
    "product_id": "XVlg5CCSSj",
    "devices": ["dev1", "dev2"]
}
```

##### 响应示例

```
{
    "data": {
        "group_id": "qf6nAD",
        "devices": ["dev1", "dev2"]
    },
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
```
