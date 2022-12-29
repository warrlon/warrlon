# 设备文件删除接口

#### 接口名称

> DeleteDeviceFile

#### 请求方法

> Post

#### 请求参数

| 参数名称   | 类型   | 是否必选 | 描述   |
| :--------- | :----- | :------- | :----- |
| id | string | 是       | 文件ID |

#### 返回数据

| 参数名称          | 类型    | 描述                       |
| :---------------- | :------ | :------------------------- |
| code              | string  | 调用失败时，返回的错误码   |
| msg               | string  | 调用失败时，返回的错误信息 |
| requestId         | string  | 调用API时生成的请求标识   |
| success           | boolean | 接口是否调用成功  |
| data              | -       | 调用成功时，返回的业务数据 |

#### 示例

##### 请求示例

```
POST /application?action=DeleteDeviceFile&version=1
{
  id：43bb54ac673f48c88300fa6e6d3c9481
}
```


##### 响应示例

```
{
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
```
