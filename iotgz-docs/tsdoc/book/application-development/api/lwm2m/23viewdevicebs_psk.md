View bs_psk of the device
---

Request mode: ** GET**

URL: http://api.heclouds.com/nbiot/device/psk?imei=865820034287669&did=86582



#### URL request parameters
Parameter name | format | description
:- | :- | :- 
Request parameter in IMEI | string | URL with the value of device IMEI number
Did | long | URL request parameter with device ID value

#### Description
```text
1、请求参数中imei和did仅且只能选择其一
2、兼容历史NB设备，查看历史设备的PSK后端默认生成存库并返回
```



#### Return parameters

Parameter name | format | description
:- | :- | :- 
Error no | int | Calls the error code, which is 0 to indicate that the call was successful
Error | string | Error description, which indicates that the call succeeded for "succ"
Data | JSON | Interface call success returns device-related information, as shown in the data description table

##### data description table

Parameter name | format | description
:- | :- | :- 
The PSK | string | device connects to the PSK of the bootstrap and returns the field when the NB protocol opens DTLS encryption. In other cases, there is no such field.


#### Return an example

```json
{
"errno": 0,
"error":"succ",
"data":
{
"psk":"23ddafd3444"
    }
}
```