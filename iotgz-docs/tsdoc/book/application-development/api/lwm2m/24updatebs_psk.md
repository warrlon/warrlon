Update bs_psk
---

Request mode: ** PUT**

URL: http://api.heclouds.com/nbiot/device/psk?imei=865820034287669




#### URL request parameters
Parameter Name | Format | Whether Must | Explain
:- | :- | :- | :- 
IMEI | string | is the request parameter in the | URL with the value of the device's IMEI number


#### HTTP body request parameters
Parameter Name | Format | Whether Must | Explain
:- | :- | :- | :- 
Key | string | is | Modify the PSK of the connection boot machine, 8-16 bytes in length, composed of letters or numbers

#### Return parameters

Parameter name | format | description
:- | :- | :- 
Error no | int | Calls the error code, which is 0 to indicate that the call was successful
Error | string | Error description, which indicates that the call succeeded for "succ"


#### Examples of requests

```text
POST http://api.heclouds.com/devices HTTP/1.1
api-key: WhI*************v1c=
Content-Type: application/json
Host: api.heclouds.com

```

#### Examples of HTTP request parameters

```json
{
    "key":"dafdfdsafd" 
}
```

#### Return an example

```json
{
    "errno": 0,
    "error": "succ"
}
```