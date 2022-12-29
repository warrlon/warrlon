# Machine Card Relation Delete API

Request method: ** DELETE**

URL：http://api.heclouds.com/dmc/ccmp/devicecard

#### HTTP head
Parameter Name | Format | Whether Must | Explain
:- | :- | :- | :- 
Api-key | string | is | must be master key

#### HTTP request parameters
Parameter Name | Format | Whether Must | Explain
:- | :- | :- | :- 
Data | JSON | is | machine card relational data

#### data description table
Parameter Name | Format | Whether Must | Explain
:- | :- | :- | :- 
Deviceid | string | is | device ID

#### Return parameters
Parameter name | format | description
:- | :- | :- 
Error code is called for errno | int | and 0 indicates successful invocation.
Error | string | Error description, for "succ" to indicate successful invocation
Data | JSON | Batch Card Relation Deletion Result Details

#### data description table
Parameter name | format | description
:- | :- | :- 
Succ | int | The total number of successful deletions of machine card relationships in this request
Fail | int | Total number of machine card relationship deletion failures in this request
Total | int | The total number of deletions of machine card relationships in this request

#### Request Header Example

```text
DELETE http://api.heclouds.com/dmc/ccmp/devicecard HTTP/1.1
api-key: WhI3***************v1c=
Host: api.heclouds.com
```

#### Examples of request parameters
```json
{
    "data":["35282992","35271941"]
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