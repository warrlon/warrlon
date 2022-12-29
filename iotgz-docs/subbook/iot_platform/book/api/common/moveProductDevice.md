# 设备转移

#### 接口名称

> MoveProductDevice

#### 请求方法

> Post

#### 请求参数

| 参数名称   | 类型   | 是否必选 | 描述   |
| :--------- | :----- | :------- | :----- |
| product_id | string | 是       | 产品ID |
| target_user_tel | string | 是       | 接收人电话 |
| device_name | array | 是       | 被转移设备的名称数组，如["name_1", "name_2"] |

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
POST /common?action=MoveProductDevice&version=1
{
    "product_id": "IOoSyVbY8q",
    "device_name": ["SB00009"],
    "target_user_tel": "17830021227"
}
```


##### 响应示例

```
{
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true,
    "data": {
      "move_id": "1317465"
    }
}
```

