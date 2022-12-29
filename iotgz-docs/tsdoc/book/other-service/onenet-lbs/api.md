# Interface Service Capability Description

Users can upload data points to $OneNET_LBS, a data stream, in a specified format. After receiving the data points, the platform can convert the data points information into corresponding latitude and longitude information, which can be saved in the platform to facilitate users to call the interface to query latitude and longitude information.

## Data point upload

** Data stream name $OneNET_LBS**

** Single Base Station Location**

| Does the field name | data type | field | have to be filled in|
| --------| -----|----|----|
| Getting Base Station Information Time | date | bstime | Select Fill|
| Mobile Network Number | int | MNC | Selected, currently only 0 supported|
| Mobile Country Number | int | MCC | Selected, China default 460|
| Area code | int | lac | must be filled in|
| base station code | int | CID | must be filled in|
| 网络制式|int|networkType|选填 <br/>0 GSM<br/>1 GSM Compact<br/>2 UTRAN <br/>3 GSM w/EGPRS <br/>4 UTRAN w/HSDPA <br/>5 UTRAN w/HSUPA <br/>6 UTRAN w/HSDPA and HSUPA <br/>7 E-UTRAN<br/>8 EC-GSM-IoT <br/>9 E-UTRAN <br/>10 E-UTRA connected to a 5G CN <br/>11 NR connected to a 5G CN <br/>12 NR connected to an EPS core <br/>13 NG-RAN <br/>14 E-UT RA-NR dual connectivity|


** Data Stream Name $OneNET_LBS** < br/>** Multi-Base Station Location**

| Does the field name | data type | field | have to be filled in|
| --------| -----|----|----|
| Getting Base Station Information Time | date | bstime | Select Fill|
| Mobile Network Number | int | MNC | Selected, currently only 0 supported|
| Mobile Country Number | int | MCC | Selected, China default 460|
| Area code | int | lac | must be filled in|
| base station code | int | CID | must be filled in|
| 网络制式|int|networkType|必填 <br/>0 GSM<br/>1 GSM Compact<br/>2 UTRAN <br/>3 GSM w/EGPRS <br/>4 UTRAN w/HSDPA <br/>5 UTRAN w/HSUPA <br/>6 UTRAN w/HSDPA and HSUPA <br/>7 E-UTRAN<br/>8 EC-GSM-IoT <br/>9 E-UTRAN <br/>10 E-UTRA connected to a 5G CN <br/>11 NR connected to a 5G CN <br/>12 NR connected to an EPS core <br/>13 NG-RAN <br/>14 E-UT RA-NR dual connectivity|
| Signal Intensity | int | SS | Selected Fill|
| Current Base Station Broadcast Signal Strength | int | SignalLength | Selected Fill|
| Mobile Station Distance to Determine Timing Advance to Base Station | int | TA | Selected Fill|
| Base Station Information Number | int | flag | Selection / Mandatory <br/> Base Station Information is 10-ary Flag written 10, default is not filled in 10-ary, base station information is 16-ary, flag must fill in 16|

-------------
Note: When flag is 10, all reported data are 10-digit. When flag is 16, all reported data are 16-digit. According to JSON, hexadecimal numbers are transmitted as strings.

** Single Base Station Location Data Reporting Format**
```json
{
    "$OneNET_LBS": {
        "cid": 30183,
        "lac": 13112,
        "mcc": 460,
        "mnc": 0,
        "networktype": 5,
        "ss": -12,
        "ta": 1
    }
}
```


** Multi-Base Station Location Data Reporting Format**
```json
{
    "$OneNET_LBS": [{
        "cid": 21089,
        "lac": 6334,
        "mcc": 460,
        "mnc": 0,
        "networktype": 5,
        "ss": -12,
        "ta": 1
    }, {
        "cid": 40673,
        "lac": 6334,
        "mcc": 460,
        "mnc": 0,
        "networktype": 5,
        "ss": -11,
        "ta": 1
    }]
}
```


## API Description

| Category | Function | Details|
|------|--------------|----------------------------------------------|
| API | Nearest Location Query | Latitude and longitude of the last location result can be returned|
|| History Track Query | Implementing Track Query in Time Interval Based on Input Time Interval Range|

## API interface





