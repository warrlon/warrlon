# 设备文件上传接口

#### 接口名称

> CreateDeviceFile

#### 请求方法

> Post

#### 请求参数

| 参数名称   | 类型   | 是否必选 | 描述   |
| :--------- | :----- | :------- | :----- |
| device_name | string | 是       | 设备名称 ,参数需构造在同一个 form-data 中|
| product_id | string | 是       | 产品ID  ,参数需构造在同一个 form-data 中|
| file | file | 是       | 上传的图片文件(目前支持JPG、PNG、BMP、GIF) |

#### 返回数据

| 参数名称          | 类型    | 描述                       |
| :---------------- | :------ | :------------------------- |
| code              | string  | 调用失败时，返回的错误码   |
| msg               | string  | 调用失败时，返回的错误信息 |
| requestId         | string  | 调用API时生成的请求标识   |
| success           | boolean | 接口是否调用成功  |
| data              | -       | 调用成功时，返回的业务数据 |
| data.fid          | string  | 文件上传成功后返回的文件ID |

#### 示例

##### 请求示例

```
POST /application?action=CreateDeviceFile&version=1
Content-type: multipart/form-data
{
  "device_name": "device_name",
  "product_id": "qwdfbht",
  "md5": "f55c2e86ab864b64a6d939fbe3a7d65f",
  "size": 12546,
  "filename": "filename",
  "file": file
}
```


##### 响应示例

```
{
    "data": { 
        "fid": "434fa51a170942c8a291be1e4b229582"
    } 
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
```
