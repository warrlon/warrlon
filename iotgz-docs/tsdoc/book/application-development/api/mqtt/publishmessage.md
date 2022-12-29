# Publish news
Request mode: ** POST**

URL: http://api.heclouds.com/mqtt

#### URL parameters
Parameter Name | Format | Whether Must | Explain
:- | :- | :- | :- 
Topic | string | is | to publish a message to a specified topic, which only supports publishing a message with QoS = 0

#### HTTP content
    Ordinary binary data, strings, json, etc. (** Maximum support 64k**)

#### Return parameters
Parameter name | format | description
:- | :- | :- 
Error no | int | Calls the error code, which is 0 to indicate that the call was successful
Error | string | Error description, which indicates that the call succeeded for "succ"

#### Request Header Example
```text
POST http://api.heclouds.com/mqtt?topic=topic/test/01 HTTP/1.1
```

#### Examples of request parameters
```text
{"payload":"testmsg"}
```

#### Return an example
```json
{
    "errno":0,
    "error":"succ"
}
```