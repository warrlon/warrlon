# Aircard Relation Binding API

Request method: ** POST**

URL：http://api.heclouds.com/dmc/ccmp/devicecard

#### HTTP head
Parameter Name | Format | Whether Must | Explain
:- | :- | :- | :- 
Api-key | string | is | must be master key


#### HTTP body parameter
Parameter Name | Format | Whether Must | Explain
:- | :- | :- | :- 
Data | JSON | is | machine card relational data


#### data description table
Parameter Name | Format | Whether Must | Explain
:- | :- | :- | :- 
Deviceid | string | is | device ID
Iccid | string | is | IUCA iccid number

#### Return parameters
Parameter name | format | description
:- | :- | :- 
Error code is called for errno | int | and 0 indicates successful invocation.
Error | string | Error description, for "succ" to indicate successful invocation
Data | JSON | Batch Card Relation Binding Result Details

#### data description table
Parameter name | format | description
:- | :- | :- 
Succ | int | The total number of successful machine card bindings in this request
Fail | int | Total number of machine card binding failures in this request
Total | int | The total number of machine card bindings in this request
#### Request Header Example
```text
POST http://api.heclouds.com/dmc/ccmp/devicecard HTTP/1.1
api-key: WhI3***************v1c=
Host: api.heclouds.com
```
#### Examples of request parameters
```json
{
    "data":
    [
        {
        "deviceid":"35282992",           //设备id
        "iccid"："898602B2201720000126"  //物联卡iccid号
        },
        {
        "deviceid":"35271941",
        "iccid":"898602B0011489800002"
        },
        ...
   ]
}
```
#### Return an example
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