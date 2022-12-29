# 用户设备文件数量查询

#### 接口名称

> GetDeviceFileCount

#### 请求方法

> Get

#### 请求参数

| 参数名称   | 类型   | 是否必选 | 描述   |
| :--------- | :----- | :------- | :----- |
| device_name | string | 是       | 设备名称 |
| product_id  | string | 是       | 产品ID |

#### 返回数据

| 参数名称          | 类型    | 描述                       |
| :--------------------- | :------ | :------------------------- |
| code                   | string  | 调用失败时，返回的错误码   |
| msg                    | string  | 调用失败时，返回的错误信息 |
| requestId              | string  | 调用API时生成的请求标识   |
| success                | boolean | 接口是否调用成功  |
| data                   | -       | 调用成功时，返回的业务数据 |
| data.upperLimit        | number  | 设备允许的最大文件数量 |
| data.filesTotal        | number  | 设备已存在的文件数量 |

#### 示例

##### 请求示例

```
GET /application?action=GetDeviceFileCount&version=1&device_name=ap-test-008&product_id=Bs1f6s5bhKP7rmfO
```


##### 响应示例

```
{
    "data": { 
        "upperLimit": 1000,
        "filesTotal": 1
    } 
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
```