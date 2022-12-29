# 机卡关系查询API

请求方法：**GET**

URL：http://api.heclouds.com/dmc/ccmp/devicecard

#### url参数
参数名称 | 格式 | 是否必须 | 说明
:- | :- | :- | :- 
deviceid|string|是|设备ID

#### http头部
参数名称 | 格式 | 是否必须 | 说明
:- | :- | :- | :- 
api-key | string | 是 | 必须为masterkey

#### 返回参数
参数名称|格式|说明
:- | :- | :- 
errno|int|调用错误码，为0表示调用成功
error|string|错误描述，为"succ"表示调用成功
data|json|机卡映射关系及物联卡查询权限


#### data描述表
参数名称|格式|说明
:- | :- | :- 
deviceid|string|设备ID
iccid|string|设备绑定的物联卡iccid号
status|string|是否有该物联卡业务数据的查询权限


#### 请求示例
```text
GET http://api.heclouds.com/dmc/ccmp/devicecard?deviceid=35282992,35271941 HTTP/1.1
api-key: WhI3***************v1c=
Host: api.heclouds.com
```


#### 返回示例
```json
{
"errno": 0,
"error":"succ",
"data":[ 
{
    "deviceid":"35282992",  //设备id
    "iccid":"898602B2201720000126" //物联卡iccid号
    "status":"无权限" //是否有查询卡业务数据的权限
}
]
}
```