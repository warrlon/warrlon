Creating equipment
---

Request mode: ** POST**

URL: http://api.heclouds.com/devices

#### HTTP body request parameters
Parameter Name | Format | Whether Must | Explain
:- | :- | :- | :- 
Title | string | is | device name
Desc | string | no | device description
Tags | array-string | no | device tag, string array
Protocol | string | is | Access Protocol, here it can only be LwM2M
Location | JSON | no | device location ("latitude", "accuracy", "height")
Private | bool | no | device privacy (default true)
Auh_info | JSON | is | NBIOT device: {"imei code": "imsi code"}, the rules of IMEI and IMSI are explained.
Auh | string | no | Auth_Code, consisting of numbers or letters, no more than 16 bits
Obsv | bool | no | subscribe to device resources (default is true)
Other | JSON | no | other information (JSON format, customizable)
Chip | int | No | The relationship between the test device and the chip type (value 1-6) is described in detail.
PSK used for PSK | string | no | DTLS encryption, 8-16 bytes in length, composed of letters or numbers

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
PSK | string | Returns this field when the NB protocol turns on DTLS encryption, otherwise it does not exist.

#### Description

Classification | IMEI | IMSI | chip | Remarks
:- | :- | :- | :- | :- 
Official equipment | 15 digits | no more than 15 digits, not empty | no | Official equipment does not need chip value
Test equipment | 4 digits | no more than 15 digits, not empty | Value 1-6 | Test equipment must fill in the chip value

##### Chip Value Correspondence Table

Chip value | 1 | 2 | 3 | 4 | 5 | 6
:- | :- | :- | :- | :- | :- | :-
Chip Name | MTK | Huawei 120 | Huawei 150 | Qualcomm | ZTE Micro | RDA

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
    "title": "mydevice",
    "desc": "some description",
    "tags": ["china", "mobile"],
    "protocol": "LwM2M",
    "location": {"lon": 106, "lat": 29, "ele": 370},
    "private": true,
    "auth_info": {"xxxxxxxxxxxx": "xxxxxxxxxxx"},
    "auth":"1233311",
    "obsv": true,
    "other": {"version": "1.0.0", "manu": "china mobile"},
    "chip":1,
    "psk":"dafdfdsafd" 
}
```

#### Return an example

```json
{
    "errno": 0,
    "data": {
        "device_id": "23444",
        "psk":"23ddafd3444"
    },
    "error": "succ"
}
```