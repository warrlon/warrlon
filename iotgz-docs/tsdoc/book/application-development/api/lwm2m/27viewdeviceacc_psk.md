View device acc_psk
---

Request mode: ** GET**

URL: http://api.heclouds.com/nbiot/device/accpsk?imei=865820034287669


#### URL request parameters
Parameter Name | Format | Whether Must | Explain
:- | :- | :- | :- 
IMEI | string | is the request parameter in the | URL with the value of the device's IMEI number

#### Return parameters

Parameter name | format | description
:- | :- | :- 
Error no | int | Calls the error code, which is 0 to indicate that the call was successful
Error | string | Error description, which indicates that the call succeeded for "succ"
Data | JSON | Interface call success returns device-related information, as shown in the data description table

##### data description table

Parameter name | format | description
:- | :- | :- 
Device_id | string | Platform assigns unique ID
The PSK | string | device connects to the PSK of the access machine and returns the field when the NB protocol opens DTLS encryption. In other cases, there is no such field.


#### Examples of requests

```text
POST http://api.heclouds.com/devices HTTP/1.1
api-key: WhI*************v1c=
Content-Type: application/json
Host: api.heclouds.com

```

#### Return an example

```json
{
    "errno": 0,
    "error": "succ",
    "data": {
        "psk":"23ddafd3444"
    }
}
```