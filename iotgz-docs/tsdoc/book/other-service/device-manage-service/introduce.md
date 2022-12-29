# Service introduction
OneNET equipment management service is aimed at the needs of Internet of Things application equipment management. It provides the integrated management capability of machine card, equipment profile statistics, equipment information enhancement management, remote upgrade, fault tracking and other functions. It is used for terminal-Internet of Things card fault detection, machine card relationship management, terminal status query, communication service usage query and other scenarios.
## Product Entry
After login to the developer center, switch to device management through the top title.

![Device Management Home Page](/images/dj/设备管理首页.png)

## Equipment Overview Statistics

- Equipment statistics
   - Total number of equipment: total number of equipment under users
   - Online Number: Current Online Number
   - On-line rate: proportion of equipment on-line
   - Number of new equipment added today: Number of new equipment added that day
- API statistics
   - API Calls Today: Number of API Calls Today
   - Success rate: API call success rate, that is, the proportion of access success (returning 200 as success)
- Push statistics
   - Number of push messages: Number of push messages today
   - Success Rate: Proportion of Successful Push Items
- Command statistics
   - Order issued today: the number of orders issued today
   - Success Rate: Proportion of Responded Equipment and Equipment



## Equipment Information Management

Device List page, users can quickly switch to other product management and view device information


Details page can view device information, historical data, historical commands, online records (different protocol labels may be different)


DMP based on OneNET basic equipment information expansion equipment information management, including: basic information, status information, location information, card information, version information

| Information | Collection Method | Fixed Data Stream Name | Description|
|:-|:-|:-|:-|:-|
| Basic Information | Providing API Interface | No | Adding Information to Current Device Information by Page or Interface|
| Status Information | Platform Record | None | None|
| Location information | Fixed data stream name and field | $OneNET_LBS | reporting via interface or message|
| Card Information | Fixed Data Stream Name and Fields | $OneNET_cardinfo | Reporting via Pages, Interfaces, or Messages|
| Version Information | Fixed Data Stream Name and Fields | $OneNET_versioninfo | Reporting via Interface or Message|

    Note: Data streams starting with $OneNET are system data streams


- Basic Information Module

| English | Chinese | Description | Source | Format Requirements|
|:-|:-|:-|:-|:-|:-|
| ID | device ID | device ID platform unique | platform generation | long string|
| Title | device name | user-defined | user-filled | String limit 64 words|
| APIkey | APIkey | device key | platform generation | String|
| auth_info | Authentication Information | User-defined Authentication Information | User Fill in | Object, 64-bit|
| IMEI | IMEI | International Standard | User Fill-in/Device Reporting | String, International Standard 15|
| desc | Description | Device Description Information | User Fill in | String, 512 words|
| Protocol | Protocol Type | Protocol Type on Platform | User Fill in | string|
| Manufacturer_Id | Manufacturer | Manufacturer name, user-defined, globally unique | User fill in | String, 32 words|
| Model | Model | Model name, user-defined | User fill in | String, 32 words|
| create_time | create time | time of new device | auto-generate | datetime|
| Activated state | Activated state | is divided into activated, inactive, and inactive if there is no online record | server record | boolean|
| First_active time | activation time | first connection time | server record | datetime|
| Location | Location | Address Description | User Fill in | Object|
| Other | Other | Other Custom Information | User Fill in | Object|

- Status information

| English | Chinese | Description | Source | Format Requirements|
|:-|:-|:-|:-|:-|:-|
| online | device status | online, offline | server record | boolean|
| Last_connection_date | Last connection time | Last connection server time | Server record | Datetime|

- Location information ($OneNET_LBS)

| English | Chinese | Description | Source | Format Requirements|
|:-|:-|:-|:-|:-|:-|
| CID | base station coding | base station coding | device reporting / API interface | int, up to 32 bits|
| La | Area Coding | Area Coding | Device Reporting / API Interface | int, up to 32 bits|
| MNC | Mobile Network Number | Mobile Network Number, Select Fill | Device Reporting / API Interface | int|
| MCC | Mobile Country Number | Select Fill | Device Reporting / API Interface | int|
| networktype | networking | networking | device reporting / API interface | int|
| SS | Signal Intensity | Signal Intensity | Device Reporting / API Interface | int|
| SignalLength | Signal Strength of Current Base Station Broadcasting | Signal Strength of Current Base Station Broadcasting | Device Reporting/API Interface | int|
| TA | Mobile Station Distance | To Determine Timing Advance to Base Station | Device Reporting / API Interface | int|

- UnionPay Card Information ($OneNET_cardinfo)

| English | Chinese | Description | Source | Format Requirements|
|:-|:-|:-|:-|:-|:-|
| IMSI | IMSI | International Standards | Device Reporting | int, up to 15 digits|
| MSISDN | UnionPay Number | 13 digits | Device Report | Int, up to 13 digits|
| iccid | ICCID | International Standards | Equipment Reporting | int, up to 20 digits|


- Version information ($OneNET_versioninfo)

| English | Chinese | Description | Source | Format Requirements|
|:-|:-|:-|:-|:-|:-|
| fw_version | firmware version | firmware version number | device report | String, length limit 32 bits|
| hw_version | Hardware version | Hardware version number | Device report | String, length limit 32 bits|
| sw_version | software version | software version number | device report | String, length limit 32 bits|

Report the sample JSON data point section

```json
{
    "$OneNET_cardinfo": {
        "imsi": "1331231231231231", 
        "iccid": "12312312312434324234324324324"
    }
}
```

- Information Storage

The storage time is as follows

| Information | Storage Mode | Description|
|:-|:-|:-|
| Basic Information | Storing Latest Values | No|
| State Information | Store the Latest Value | No|
| LBS | Store values for nearly a period of time | One year|
| Card Information | Storing Latest Values | No|
| Version Information | Storing Latest Values | No|

    The rest of the statistics are due yesterday.



## Introduction to the Integrated Function of Machine Card

OneNET provides the integrated management capability of machine cards (mobile Internet of Things cards) for terminal-Internet of Things card troubleshooting, machine card relationship management, terminal status query, communication service usage query and other scenarios.

### Instructions for Use
To use the integrated function of machine card, we need to bind Onelink's EC account to determine whether it has the right to query the corresponding card number.
### EC Account Binding
When you create a new bound user, you need to jump to Onelink for login verification
### The Way of Building Machine Card Relations
| Mode | Instructions for Use|
|:-|:-|
| New Machine Card Relations on Pages | New Single Relations on Pages or Batch Import Machine Card Relations on Pages|
| API Interface New Machine Card Relations | New Machine Card Relations Through Interfaces, see the next chapter|
| Data Point Reporting | Establishing Machine Card Relations by Specifying Data Flow Reporting Standard Data Points to the System|
    Note: The data stream of the system card is $OneNET_cardinfo. The JSON of the reported data point contains one or more keywords of imsi, MSISDN and iccid.