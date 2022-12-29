# 分组编辑

#### 接口名称

> UpdateGroup

#### 请求方法

> POST

#### 请求参数

| 参数名称   | 类型   | 是否必选 | 描述     |
| :--------- | :----- | :------- | :------- |
| project_id | string | 是       | 项目ID   |
| group_id   | string | 是       | 分组ID   |
| tag        | object | 否       | 标签信息 |
| desc       | string | 否       | 分组描述 |

#### 返回数据

| 参数名称      | 类型    | 描述                       |
| :------------ | :------ | :------------------------- |
| code          | string  | 调用失败时，返回的错误码   |
| msg           | string  | 调用失败时，返回的错误信息 |
| requestId     | string  | 调用API时生成的请求标识    |
| success       | boolean | 接口是否调用成功           |
| data          | -       | 调用成功时，返回的业务数据 |
| data.group_id | string  | 分组ID                     |

#### 示例

##### 请求示例

```
POST /application?action=UpdateGroup&version=1
Content-type: application/json

{
    "project_id": "Ua3Dbm",
    "group_id": "3UfAWD",
    "tag": {"key11":"dkmclg"},	#标签的键值对
    "desc": "描述"
}
```

##### 响应示例

```
{
    "data": {
    	"group_id": "diVGB3"
    },
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
```

