# 分组详情

#### 接口名称

> QueryGroupDetail

#### 请求方法

> GET

#### 请求参数

| 参数名称   | 类型   | 是否必选 | 描述   |
| :--------- | :----- | :------- | :----- |
| project_id | string | 是       | 项目ID |
| group_id         | string | 是       | 分组ID |

#### 返回数据

| 参数名称          | 类型    | 描述                       |
| :---------------- | :------ | :------------------------- |
| code              | string  | 调用失败时，返回的错误码   |
| msg               | string  | 调用失败时，返回的错误信息 |
| requestId         | string  | 调用API时生成的请求标识    |
| success           | boolean | 接口是否调用成功           |
| data              | -       | 调用成功时，返回的业务数据 |
| data.active_time  | string  | 激活时间                   |
| data.online_count | string  | 上线次数                   |
| data.project_id   | string  | 分组所属的项目ID           |
| data.name         | string  | 分组名称                   |
| data.group_id           | string  | 分组ID                     |
| data.key          | string  | 分组key                    |
| data.tag          | object  | 分组标签                   |
| data.desc         | string  | 分组描述                   |
| data.device_count | string  | 设备数量                   |
| data.create_time  | string  | 创建时间                   |

#### 示例

##### 请求示例

```
GET /application?action=QueryGroupDetail&version=1
```


##### 响应示例

```
{
    "data": { 
        "activate_count": 0,
        "online_count": 0,
        "project_id": "3C6Djy",
        "name": "xq_group1",
        "group_id": "qf6nAD",
        "key": "ZDM0MzA4MTA3MjQ4NzdlYzZjOGJlYzU1YmUwZTNhMmY=",
        "tag": {
            "xq": "123"
        },
        "desc": "123",
        "created_time": "2020-08-13T01:49:17.694Z",
        "device_count": 2
    } 
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
```
