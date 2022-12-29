# Query data flow details
Request mode: ** GET**

URL: http://api.heclouds.com/devices/device_id/datastreams/datastream_id

    Device_id: The device ID needs to be replaced
    Datastream_id: You need to replace it with the data stream ID

#### Return parameters
Parameter name | format | description
:- | :- | :- 
Error no | int | Calls the error code, which is 0 to indicate that the call was successful
Error | string | Error description, which indicates that the call succeeded for "succ"
Data | JSON | Interface call success returns device-related information, as shown in the data description table

##### data description table
Parameter name | format | description
:- | :- | :- 
ID | string | data stream ID
Create_time | string | data stream creation time
Update_at | string | latest data upload time
Curr_value | string/int/json... | Latest data points
CMD | string | issue commands periodically
Interval | int | sampling period
Formula | string | register calculation formula


#### Examples of requests
```text
GET http://api.heclouds.com/devices/20474930/datastreams/temperature HTTP/1.1
```

#### Return an example
```json
{
    "errno": 0,
    "data": {
        "create_time": "2017-04-17 14:03:10",
        "update_at": "2017-04-17 14:05:42",
        "formula": "A0+A1",
        "interval": 10,
        "id": "no2",
        "cmd": "010300000002c40b",
        "current_value": {
            "0": "555",
            "1": "0"
        }
    },
    "error": "succ"
}
```