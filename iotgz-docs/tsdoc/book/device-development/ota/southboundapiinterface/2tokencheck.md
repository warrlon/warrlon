# Pull Upgrade File - token Check

Request mode: ** GET**

URL: http://ota.heclouds.com/ota/download/$token/check

#### HTTP head
Parameter Name | Format | Whether Must | Explain
:- | :- | :- | :- 
Content-Type | string | is | must be application/json
Authorization | string | is | security authentication information


#### HTTP request parameters
Parameter Name | Format | Whether Must | Explain
:- | :- | :- | :- 
Dev_id | string | is | device ID

#### Return parameters
Parameter name | format | description
:- | :- | :- 
Error no | int | Calls the error code, which is 0 to indicate that the call was successful
Error | string | Error description, which indicates that the call succeeded for "succ"


#### Error Code Description
Error code | description
:- | :-
 0 | Effective
 7 | OneNET internal error
12 | token expires, equipment upgrade process ends, default expires in two days
15 | Not the latest token, multiple calls to check for upgrade tasks, using token errors
18 | Error token, SDK logic error, end of equipment upgrade process
19 | Upgrade task is suspended, SDK controls the next check time and does not consume retries
20 | Upgrade Task Ended, Equipment Upgrade Process Ended
21 | Invalid operation, SDK logic error
22 | Upgrade task cancelled without reporting upgrade failure
23 | token and dev_id are inconsistent

#### Examples of HTTP request parameters

```json
{
    "dev_id": 6523

}
```

#### Return an example


```json
{
    "errno": 0,
    "error": "succ"

}
```