Delete triggers
---
Request mode: ** DELETE**

URL: http://api.heclouds.com/triggers/trigger_id

    Trigger_id: trigger ID


#### Return parameters
Parameter name | format | description
:- | :- | :- 
Error no | int | Calls the error code, which is 0 to indicate that the call was successful
Error | string | Error description, which indicates that the call succeeded for "succ"

#### Examples of requests

```text
DELETE http://api.heclouds.com/triggers/12***1 HTTP/1.1
api-key: WhI*************v1c=
Content-Type: application/json
Host: api.heclouds.com

```

#### Return an example
```json
{
    "errno": 0,
    "error": "succ"
}
```