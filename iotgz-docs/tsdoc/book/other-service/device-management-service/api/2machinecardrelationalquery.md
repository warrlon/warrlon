# Machine Card Relational Query API

Request method: ** GET**

URL：http://api.heclouds.com/dmc/ccmp/devicecard

#### URL parameter
Parameter Name | Format | Whether Must | Explain
:- | :- | :- | :- 
Deviceid | string | is | device ID

#### HTTP head
Parameter Name | Format | Whether Must | Explain
:- | :- | :- | :- 
Api-key | string | is | must be master key

#### Return parameters
Parameter name | format | description
:- | :- | :- 
Error code is called for errno | int | and 0 indicates successful invocation.
Error | string | Error description, for "succ" to indicate successful invocation
Data | JSON | Machine Card Mapping Relation and Material Union Card Query Authority


#### data description table
Parameter name | format | description
:- | :- | :- 
Deviceid | string | device ID
Iccid | string | device-bound IUCA iccid number
Status | string | Does it have the right to query the business data of UnionPay?


#### Examples of requests
```text
GET http://api.heclouds.com/dmc/ccmp/devicecard?deviceid=35282992,35271941 HTTP/1.1
api-key: WhI3***************v1c=
Host: api.heclouds.com
```


#### Return an example
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