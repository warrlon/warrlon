# 账户下文件列表查询

#### 接口名称

> GetDeviceFilesList

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
| data.meta.total        | number  | 文件数量 |
| data.meta.limit        | number  | 每次请求的数据长度 |
| data.meta.offset       | number  | 偏移量 |
| data.list.id           | string  | 文件上传记录ID |
| data.list.fid          | string  | 文件ID |
| data.list.name         | string  | 文件名称 |
| data.list.file_size    | number  | 文件大小 |
| data.list.created_time | string  | 文件创建时间 |
| data.list.device_name  | string  | 文件所属设备名称 |
| data.list.product_id   | string  | 文件所属设备的产品ID |

#### 示例

##### 请求示例

```
GET /application?action=GetDeviceFilesList&version=1
```


##### 响应示例

```
{
    "data": { 
        "meta": {
            "limit": 10,
            "offset": 0,
            "total": 1
        },
        "list": [
            {
                "id": "574f7eab98eb7b5222911a",
                "fid": "98cfa6be79574f7eab98eb7b5222911a",
                "name": "28fpf.png",
                "file_size": 138683,
                "created_time": "2020-12-16T09:30:18.419Z",
                "device_name": "ap-test-008",
                "product_id": "Bs1f6s5bhKP7rmfO"
            }
        ]
    } 
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
```