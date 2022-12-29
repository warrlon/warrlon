# UnionPay Business Data Query API

Request method: ** GET**

URL：http://api.heclouds.com/dmc/ccmp/deviceinfo

#### URL parameter
Parameter Name | Format | Whether Must | Explain
:- | :- | :- | :- 
Deviceid | string | is | device ID, with multiple deviceids divided by ""

#### HTTP head
Parameter Name | Format | Whether Must | Explain
:- | :- | :- | :- 
Api-key | string | is | must be master key

#### Return parameters
Parameter name | format | description
:- | :- | :- 
Error code is called for errno | int | and 0 indicates successful invocation.
Error | string | Error description, for "succ" to indicate successful invocation
Data | JSON | UnionPay Business Data Details

#### data description table
Parameter name | format | description
:- | :- | :- 
Cardnfos | JSON | Card Business Data Details

#### cardinfo description table
Parameter name | format | description
:- | :- | :- 
Deviceid | string | device ID
Cardstatus | string | UnionCard status; 00-normal, 01-unidirectional downtime, 02-downtime, 03-pre-sale number, 04-sale number, 05-transfer, 06-dormancy, 07-to-be-stimulated, 99-number does not exist
Entertime | string | Internet access time
IMSI | string | IUCA IMSI number
Iccid | string | IUCA iccid number
MSISDN | string | IUCA MSISDN number
Left | string | Set Surplus Flow (KB)
Gprstotal | string | total package flow (unit: KB)
GPRS usedflow | string | packages have been used traffic (unit: KB)
Bilingstatus | string | UnionPay's current life cycle; 00: official, 01: test, 02: silence, 03: other
Gprs_status | string | on-line status of Union of Things; 00-offline, 01-on-line
Prodinfos | JSON | UnionPay Package Information

#### prodinfos description table
Parameter name | format | description
:- | :- | :- 
Prodid | string | set ID
Prodname | string | package name
Prodinstefftime | string | package expiration time

#### Examples of requests
```text
GET http://api.heclouds.com/dmc/ccmp/deviceinfo?deviceid=35282992_35271941 HTTP/1.1
api-key: WhI3***************v1c=
Host: api.heclouds.com
```

#### Return an example
```json
{
"errno": 0,
"error":"succ",
"data":
    [
        "cardinfos":
        [
            {
                "deviceid":"YYYYYYYY", 
                "cardstatus": "00", 
                "entertime": "20160607123030", 
                "imsi": "xxxxxx", 
                "iccid":"xxxx",
                "msisdn":"xxx",
                "left":"20",
                "gprstotal":"100", 
                "gprsusedflow":"80" 
                "billingstatus":"xxx" 
                "gprs_status":"xxx" 
                "prodinfos": 
                [
                    {
                        "prodid": "I00010700001",
                        "prodname": "null",
                        "prodinstefftime":"xxx"
                    },
                    ...
                ]
            },
            ...
        ]
    ]
}
```