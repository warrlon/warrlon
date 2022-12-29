# Log query
## I. Page Function

Step 1. Register / log on to OneNET platform[https://open.iot.10086.cn](https://open.iot.10086.cn)

Step 2. Click on the device management module and enter the MDP management module.
![dmp home page](/images/OTA/dmp.png)

On the left navigation bar of step, select OTA upgrade and click FOTA upgrade.
![log](/images/LogQuery/log0.png) 

Step 4. Select and set search conditions, enter device ID, and click Search.

![log1](/images/LogQuery/log1.png)

> Search Conditions Description <br>
Date Selection: The default choice is the latest hour, the maximum selection range is one month, and the platform only stores logs for nearly three months; <br>
Log level: Log level is divided into INFO, ERRO, WARN; < br >
Device ID: Accurate search through device ID is now mandatory; <br>


Detailed log descriptions are as follows

## NB-IoT suite log description

### 1 NBBS (NB Access Machine Boot)
#### 1.1 bootstrap start
Key words | key information | meaning of examples
:- | :- | :- |
Required bootstrap | imei: 86xxxxxxxxxxxx, imsi: 2222 | Request bootstrap, imei: 86xxxxxxxxxx, imsi: 2222

#### 1.2 bootstrap delete
Key words | key information | meaning of examples
:- | :- | :- 
Bootstrap delete | CHANGED | Delete / Response CHANGED
Bootstrap delete error | | Delete / error

#### 1.3 bootstrap discover
Key words | key information | meaning of examples
:- | :- | :- 
Bootstrap discover | CONTENT | Discover / Response CONTENT
Bootstrap discover error | | Discover / error

#### 1.4 bootstrap write /0/1
Key words | key information | meaning of examples
:- | :- | :- 
Bootstrap write server address |/0/1 (information 1), CHANGED (information 2) | bootstrap write/0/1 response CHANGED
Bootstrap write security instance XXX error | / 0/1 | bootstrap write / 0/1 error

#### 1.5 bootstrap write /0/1
Key words | key information | meaning of examples
:- | :- | :- 
Bootstrap write server address |/0/1 (information 1), CHANGED (information 2) | bootstrap write/0/1 response CHANGED
Bootstrap write security instance XXX error | / 0/1 | bootstrap write / 0/1 error

#### 1.6 bootstrap finish
Key words | key information | meaning of examples
:- | :- | :- 
Bootstrap finished | CHANGED | bootstrap finish response CHANGED
Bootstrap finish error | | bootstrap finish error

### 2 Registration and reporting data
#### 2.1 register
Key words | key information | meaning of examples
:- | :- | :- 
New registered client | imei: 86xxxxxxxxxxx, imsi: 2222, 300 | Successful connection platform, imei: 86xxxxxxxxxxx, imsi: 2222, lifetime: 300 seconds

#### 2.1 observe
Key words | key information | meaning of examples
:- | :- | :- 
Autoobserve |/3/0, CONTENT | Platform Subscription / 3/0 Response to CONTENT
Autoobserve error |/3/0 | Platform subscription / 3/0 timeout, no further requests

#### 2.3 read /3/0 or read /4/0
Key words | key information | meaning of examples
:- | :- | :- 
Autoread |/3/0, CONTENT | Platform Read / 3/0 Response to CONTENT
Auto read error |/3/0 | Platform read / 3/0 timeout, no further requests

#### 2.4 update
Key words | key information | meaning of examples
:- | :- | :- 
Update success | imei: 86xxxxxxxxxxxx, 300 | update success, imei: 86xxxxxxxxxx, lifetime: 300 seconds

#### 2.5 deregister
Key words | key information | meaning of examples
:- | :- | :- 
Deregister success | imei: 86xxxxxxxxxx | logout successful, device offline, imei: 86xxxxxxxxx

#### 2.6 notify
Key words | key information | meaning of examples
:- | :- | :- 
Notify success |/3/0 | device notify, imei: 86xxxxxxxxxx, resource path: / 3/0

### 3 Downlink business
#### 3.1 read
Key words | key information | meaning of examples
:- | :- | :- 
Read client |/3/0, 12345 | Submit Read Request, Resource Path: / 3/0, Sequence Number: 12345
Read return | CONTENT, / 3/0, 12345 | Receives the Read response CONTENT, resource path: / 3/0, serial number: 12345
Read error | | Read response timeout / error, resource path: / 3/0, serial number: 12345

#### 3.2 write
Key words | key information | meaning of examples
:- | :- | :- 
Write client |/3/0, 12345 | to issue a Write request, resource path: / 3/0, serial number: 12345
Write return | CHANGED, / 3/0, 12345 | Receives Write response CHANGED, resource path: / 3/0, serial number: 12345
Write error | TIMEOUT / RESP_ERROR, / 3/0, 12345 | Write response timeout / error, resource path: / 3/0, serial number: 12345

#### 3.3 execute
Key words | key information | meaning of examples
:- | :- | :- 
Execute client |/3/0, 12345 | Submit Execute request, resource path: / 3/0, serial number: 12345
Excute return | CHANGED, / 3/0, 12345 | Receives Execute response CHANGED, resource path: / 3/0, serial number: 12345
Excute error | TIMEOUT/RESP_ERROR, / 3/0, 12345 | Execute response timeout/error, resource path: / 3/0, serial number: 12345

#### 3.4 write attribute
Key words | key information | meaning of examples
:- | :- | :- 
WriteAttribute client |/3/0, 12345 | Next WriteAttribute request, resource path: /3/0, serial number: 12345
WriteAttribute return | CHANGED, / 3/0, 12345 | Receives WriteAttribute response CHANGED, resource path: / 3/0, serial number: 12345
WriteAttribute error | TIMEOUT/RESP_ERROR, / 3/0, 12345 | WriteAttribute response timeout/error, resource path: / 3/0, serial number: 12345

#### 3.5 write package
Key words | key information | meaning of examples
:- | :- | :- 
Write Package Client | 12345 | Download Write Firmware Package Request, Serial Number: 12345
Write Package return | CHANGED, 12345 | Receive Write Firmware Package Response CHANGED, serial number: 12345
Write Package error | TIMEOUT/RESP_ERROR, 12345 | Write firmware package response timeout/error, serial number: 12345

#### 3.6 observe
Key words | key information | meaning of examples
:- | :- | :- 
Observation client |/3/0, 12345 | Issue Observer requests, resource path: / 3/0, serial number: 12345
Observe return | CHANGED, / 3/0, 12345 | Receive Observer response CONTENT, resource path: / 3/0, serial number: 12345
Observation error | TIMEOUT/RESP_ERROR, / 3/0, 12345 | Observer response timeout/error, resource path: / 3/0, serial number: 12345

#### 3.7 cancel observe
Key words | key information | meaning of examples
:- | :- | :- 
Cancel observe client |/3/0, 12345 | Next cancel Observer request, resource path: / 3/0, serial number: 12345
Cancel observe return | CHANGED, / 3/0, 12345 | Receive cancel Observer response CONTENT, resource path: / 3/0, serial number: 12345
Cancel observe error | TIMEOUT / RESP_ERROR, / 3/0, 12345 | Cancel Observer response timeout / error, resource path: / 3/0, serial number: 12345

### 4 equipment timeout and offline
Key words | key information | meaning of examples
:- | :- | :- 
Offline | imei: 86xxxxxxxxxx | lifetime expiration, device offline, imei: 86xxxxxxxxxx