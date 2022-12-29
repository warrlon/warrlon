# Examples of OTA-API usage

Instructions for the Use of General OTA Device Side of OneNET Platform
Universal remote upgrade functions include module upgrade and MCU application upgrade. Upgraded devices interact with OneNET platform through HTTP RESTful standard format to complete the upgrade. <br/>
There are three types of RESTful APIs for southward devices: detection tasks, pull files, and report status. The pull files include two APIs: checking TOKEN and getting files. <br>
Here's an overview of API usage and the process of testing firmware pull-out with postman simulator.
This document is suitable for equipment-side operators who use OneNET platform to operate with OTA functions.


### 1 Authentication parameter

The Python is used here to calculate token. You can change the product ID and access key. Refer to the Section of Security Authentication (/ book/easy-manual/auth.md). The Python code is shown in Figure 1.

![SDK note](/images/OTA/ota-api/ota-api1.png)

![SDK note](/images/OTA/ota-api/ota-api2.png)

The calculated token:
```
version=2018-10-31&res=products%2F245528&et=7559008892&method=sha1&sign=TPllhakDDnUV90epLnOqpj6aWqI%3D
```
### 2 Detection Task
Refer to the OTA-SDK documentation for instructions and responses to the detection task API:
The headers parameter Authorization: value is the token calculated above.

> The two parameters manuf = 102 & model = 10201 refer to the table below. Dev_id=527776559 is modified to the device ID that needs to be upgraded. Other parameters remain unchanged.

| Chip Platform | Chip Model | Manufacturer Number | Chip Number|
|:-|:-|:-|:-|
| Lexin | ESP32 | 101 | 10101|
|nordic |nrf52832|  102 |10201|
| Zhaoyi | GD32 | 103 | 10301|
| Other | Other | 100 | 10001|

```
http://ota.heclouds.com/ota/south/check?dev_id=527776559&manuf=102&model=10201&type=2&version=V1&cdn=false
```

![SDK note](/images/OTA/ota-api/ota-api3.png)

![SDK note](/images/OTA/ota-api/ota-api4.png)


```json
{
    "errno": 0,
    "error": "succ",
    "data": {
        "target": "V1",
        "token": "ota_iF0hnXrq2CxLrP8vZ39l",
        "size": 22,
        "md5": "ad2f4e4ea2a27eace7e4913139f8f01a",
        "signal": 10,
        "power": 50,
        "retry": 0,
        "interval": 0,
        "type": 1
    }
}
```
### 3 Check TOKEN
Check TOKEN instructions and response information refer to OTA-SDK instructions:
The headers parameter Authorization: value is the token calculated above.
> dev_id=527776559 is modified to the device ID that needs to be upgraded. Ota_iF0hnXrq2CxLrP8vZ39l is the token obtained by the authentication parameter step, other parameters remain unchanged.

```
http://ota.heclouds.com/ota/south/download/ota_iF0hnXrq2CxLrP8vZ39l/check?dev_id=527776559
```
![SDK note](/images/OTA/ota-api/ota-api5.png)

### 4 Draw Documents
Refer to OTA-SDK documentation for instructions and responses to pull files:
```
http://ota.heclouds.com/ota/south/download/ota_iF0hnXrq2CxLrP8vZ39l
```
Ta_iF0hnXrq2CxLrP8vZ39l is the token obtained by the authentication parameter step, and other parameters remain unchanged.
You can pull the entire file:

![SDK note](/images/OTA/ota-api/ota-api6.png)

You can also pull out some files.

![SDK note](/images/OTA/ota-api/ota-api7.png)

Header Range field explanation: Range: bytes={start} - {end}, currently only supports the following modes
> 1. Range: bytes={start}-, get the {start}+1 byte to the last data <br>.
    For example: Range: bytes = 0 -, get all the data
    Range: bytes = 2 -, get the third data to the last one < br >
    Note: If {start}>= the total length of the file, the default is {start}= 0 < br>.
    2. Range: bytes={start} - {end} to get the {start}+1 byte to {end}+1 byte
    For example: Range: bytes = 0-99, get the first 100 bytes < br >
    Note: If {end}>= the total length of the file len, the default end = len-1 < br >
    If {start}> {end}, start is set to 0 < br >
    3. Range: bytes = - {end} to get the last end byte data < br >
    For example: Range: bytes = - 100, get the last 100 bytes of data < br >
    Note: If {end}> the total length of the file len, the default end = len is <br>.

Piecewise status code
> status code returned by fragmentation: 206 < br >
  The status code returned without fragmentation: 200

### 5 Reporting status
Refer to OTA-SDK documentation for status usage instructions and response information:
The headers parameter Authorization: value is the token calculated above.
The body content is

```
{
    "result": 201

}
```

result:

> 101: Upgrade Pack Downloaded Successfully <br>
 102: Download failed, space insufficient < br >
 103: Download failed, memory overflow < br >
 104: Download failed, download request timeout < br >
 105: Download failure, power shortage < br >
 106: Download failure, bad signal < br >
 107: Download failed, unknown exception < br >
 201: Upgrade success < br >
 202: Upgrade failure, power shortage < br >
 203: Upgrade failed, memory overflow < br >
 204: Upgrade failed, version inconsistency < br >
 205: Upgrade Failure, MD5 Check Failure < br >
206: Upgrade failed, unknown exception < br >

error:

> 0: Report status was successful < br >
1: Report status failed, token authentication failed < br >
2: Failure to report status and error of status code < br >
20:Failure to report status, upgrade task completed <br>
21:Invalid operation <br>
22:Failure to report status, upgrade task cancelled <br>
24: Request content result error < br >

Explain
> dev_id=527776559 is modified to the device ID that needs to be upgraded. Ota_iF0hnXrq2CxLrP8vZ39l is the token obtained by the authentication parameter step, other parameters remain unchanged.

```
http://ota.heclouds.com/ota/south/report?dev_id=527776559&token=ota_iF0hnXrq2CxLrP8vZ39l
```

![SDK note](/images/OTA/ota-api/ota-api8.png)

![SDK note](/images/OTA/ota-api/ota-api9.png)


After reporting the successful status of the upgrade, the platform will display the status of the task to be completed.