# Report Upgrade Status

Request mode: ** POST**

URL: http://ota.heclouds.com/ota/report

#### HTTP head
Parameter Name | Format | Whether Must | Explain
:- | :- | :- | :- 
Authorization | string | is | security authentication information


#### HTTP request parameters
Parameter Name | Format | Whether Must | Explain
:- | :- | :- | :- 
Dev_id | string | is | device ID
Token | string | is | token returned by detecting upgrade tasks

#### HTTP body content
Parameter Name | Format | Whether Must | Explain
:- | :- | :- | :- 
Result | int | is | See result description for details

#### Return parameters
Parameter name | format | description
:- | :- | :- 
Error no | int | Call error code, see error code description for details
Error | string | Error description, which indicates that the call succeeded for "succ"


#### Result description
Result code | description
:- | :-
101 | Upgrade Pack Downloaded Successfully
102 | Download failed, lack of space
103 | Download failed, memory overflow
104 | Download failed, download request timed out
105 | Download failure, power shortage
106 | Download failed, bad signal
107 | Download failed, unknown exception
201 | Successful upgrade
202 | Upgrade failure, power shortage
203 | Upgrade failed, memory overflow
204 | Upgrade failed, version inconsistent
205 | Upgrade failed, MD5 checkout failed
206 | Upgrade failed, unknown exception

#### Error Code Description
Error code | description
:- | :-
0 | Successful reporting of information
1 | Failed to report information, token authentication failed
2 | Failed to report. The status code of the report is unrecognizable
20 | Failed to report information, upgrade task completed
21 | Invalid operation, SDK logic error
22 | Failed to report information, upgrade task cancelled
24 | Request content result error


#### Examples of HTTP request parameters

```json
{
    "result": 101

}
```

#### Return an example


```json
{
    "errno": 0,
    "error": "succ"

}
```