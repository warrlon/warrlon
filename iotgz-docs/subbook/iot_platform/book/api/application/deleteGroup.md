# 移除分组

#### 接口名称

> DeleteGroup

#### 请求方法

> POST

#### 请求参数

| 参数名称   | 类型   | 是否必选 | 描述   |
| :--------- | :----- | :------- | :----- |
| project_id | string | 是       | 项目ID |
| group_id   | string | 是       | 分组ID |

#### 返回数据

| 参数名称  | 类型    | 描述                       |
| :-------- | :------ | :------------------------- |
| code      | string  | 调用失败时，返回的错误码   |
| msg       | string  | 调用失败时，返回的错误信息 |
| requestId | string  | 调用API时生成的请求标识    |
| success   | boolean | 接口是否调用成功           |
| data      | -       | 调用成功时，返回的业务数据 |

##### 请求示例

```
POST /application?action=DeleteGroup&version=1
Content-type: application/json

{
    "project_id": "Ua3Dbm",
    "group_id": "3UfAWD"
}
```

##### 响应示例

```
{
    "data": null,
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
```
