# 机卡关系删除API

请求方法：**DELETE**

URL：http://api.heclouds.com/dmc/ccmp/devicecard

#### http头部
参数名称 | 格式 | 是否必须 | 说明
:- | :- | :- | :- 
api-key | string | 是 | 必须为masterkey

#### HTTP请求参数
参数名称 | 格式 | 是否必须 | 说明
:- | :- | :- | :- 
data|json|是|机卡关系数据

#### data描述表
参数名称 | 格式 | 是否必须 | 说明
:- | :- | :- | :- 
deviceid|string|是|设备ID

#### 返回参数
参数名称|格式|说明
:- | :- | :- 
errno|int|调用错误码，为0表示调用成功
error|string|错误描述，为"succ"表示调用成功
data|json|批量机卡关系删除的结果详情

#### data描述表
参数名称|格式|说明
:- | :- | :- 
succ|int|该次请求中机卡关系删除成功总数
fail|int|该次请求中机卡关系删除失败总数
total|int|该次请求中机卡关系删除的总数

#### 请求头部示例

```text
DELETE http://api.heclouds.com/dmc/ccmp/devicecard HTTP/1.1
api-key: WhI3***************v1c=
Host: api.heclouds.com
```

#### 请求参数示例
```json
{
    "data":["35282992","35271941"]
}
```


#### 返回示例
```json
{
"errno": 0,
"error":"succ",
"data":
    {
        "succ": 10,
        "fail": 0,
        "total": 10
    }
}
```