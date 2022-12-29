# 用户文件存储空间查询

#### 接口名称

> GetDeviceFileSpace

#### 请求方法

> Get

#### 请求参数

| 参数名称   | 类型   | 是否必选 | 描述   |
| :--------- | :----- | :------- | :----- |

#### 返回数据

| 参数名称          | 类型    | 描述                       |
| :--------------------- | :------ | :------------------------- |
| code                   | string  | 调用失败时，返回的错误码   |
| msg                    | string  | 调用失败时，返回的错误信息 |
| requestId              | string  | 调用API时生成的请求标识   |
| success                | boolean | 接口是否调用成功  |
| data                   | -       | 调用成功时，返回的业务数据 |
| data.useSize           | number  | 用户已使用的空间 |
| data.hasSize           | number  | 用户剩余空间 |
| data.totalSize         | number  | 用户分配的总空间 |

#### 示例

##### 请求示例

```
GET /application?action=GetDeviceFileSpace&version=1
```


##### 响应示例

```
{
    "data": { 
        "useSize": 138683,
        "hasSize": 1073603141,
        "totalSize": 1073741824
    } 
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
```
