Cancel Caching Command
---
Request mode: ** PUT**

URL: http://api.heclouds.com/nbiot/offline/cancel/uuid

    Uuid: Cache command ID


#### URL parameter
Parameter Name | Format | Whether Must | Explain
:- | :- | :- | :- 
IMEI | string | is the identity code of | nbiot device

#### Return parameters
Parameter name | format | description
:- | :- | :- 
Error no | int | Calls the error code, which is 0 to indicate that the call was successful
Error | string | Error description, which indicates that the call succeeded for "succ"

##### Description
```
只有当命令处于wait状态才能取消
```

#### Examples of requests

```text
PUT http://api.heclouds.com/nbiot/offline/cancel/10018?imei=86582003*** HTTP/1.1
api-key: WhI*************v1c=
Host: api.heclouds.com

```

#### Return an example
```json
{
    "errno": 0,
    "error": "succ"
}
```