View data points
---
Request mode: ** GET**

URL: http://api.heclouds.com/devices/device_id/datapoints

    Device_id: The device ID needs to be replaced


#### URL parameter
Parameter Name | Format | Whether Must | Explain
:- | :- | :- | :- 
Datastream_id | string | no | data stream, separated by commas between multiple data streams
Start | string | no | start time of extracting data points, format: 2015-01-10T08:00:35
End | string | no | End time of extracting data points, format: 2015-01-10T08:00:35
Limit | int | No | Limit the maximum number of data points returned by this request, with a value of > 0, <= 6000
Cursor | string | no | specifies that the request continues to extract data from the cursor location

#### Return parameters
Parameter name | format | description
:- | :- | :- 
Error no | int | Calls the error code, which is 0 to indicate that the call was successful
Error | string | Error description, which indicates that the call succeeded for "succ"
Data | JSON | Data Point Information Returned After Successful Interface Call, See Data Description Table

##### data description table
Parameter name | format | description
:- | :- | :- 
Cursor | string | location of the next data point
Datastreams | array - JSON | JSON array of device data flow information, see datastreams description table
Number of data streams returned by count | int |

##### datastreams description table
Parameter name | format | description
:- | :- | :- 
ID | string | data stream name
JSON array of data points | array-json | data points, see datapoints description table
Statistic | JSON | JSON for data flow statistics, see Statistic Description Table

##### datapoints description table
Parameter name | format | description
:- | :- | :- 
At | string | time
value | String (or array) | Values of data points

##### Statistic Description Table
Parameter name | format | description
:- | :- | :- 
At | string | A maximum point of time returned when maximizing
Value | string | data point value

##### Description
```
不携带任何参数，直接调用。则返回本设备所存在的所有数据流中最新的数据。 如果这个设备有三个数据流，则返回这三个数据流中每个数据流中最后一条数据。
不携带数据流id参数，携带limit参数时，会返回该设备每个数据流最多limit条数据。
其中datastream_id等于obj_id_obj_inst_id_ res_id，如obj_id:3200，obj_inst_id:0，res_id:5501，那么这个datastream_id就为3200_0_5501。
要查看某一条数据流在某个时间范围内的数据，可以在增加start和end参数。注意如果start参数存在，end参数不存在，表示取start后的所有数据；如果start不存在，end存在，设备云会忽略end参数。start和end之间的时间间隔最大为1年，超过一年会忽略。
如果指定了start参数，则可能返回的数据点的数目会很多，此时默认会返回最多100个数据点。可以使用limit参数，设定返回多少个数据点，最大为6000个数据点。当实际的数据点数目多于limit限定的数目时，返回的json串中会有一个cursor字段，下一次请求的命令行中可以携带此cursor字段表示接着遍历本数据流。此cursor字段标识上次取出数据点后下一个数据点的位置。
```

#### Example 1 of Request

```text
GET http://api.heclouds.com/devices/564280/datapoints? datastream_id=3200_0_5501&start=2015-11-30T17:12:33&end=2015-12-01T17:22:33&limit=5&cursor=25971_564280_1448961024981 HTTP/1.1
api-key: WhI*************v1c=
Host: api.heclouds.com

```

#### Return an example
```json
{
    "errno":0,
    "data":{
        "cursor":"25971_564280_1448961152173",
        "count":5,
        "datastreams":[
            {
                "datapoints":[
                    {
                        "at":"2015-12-01 17:10:24.981",
                        "value":"35"
                    },
                    {
                        "at":"2015-12-01 17:10:53.406",
                        "value":"38"
                    },
                    ...
                ],
                "id":"3200_0_5501"
            },
            ...
        ]
    },
    "error":"succ"}
```