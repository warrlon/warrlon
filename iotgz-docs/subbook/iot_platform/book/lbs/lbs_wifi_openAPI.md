# WIFI定位API文档

[本页目录]()
* [WIFI定位-设备最新位置查询](#1)
* [WIFI定位-设备历史轨迹查询](#2)
---

<h2 id="1">1. WIFI定位-设备最新位置查询</h2>

#### 接口名称
> latestWifiLocation

#### 请求方法 

> GET

#### URL

http://openapi.heclouds.com/lbs_wifi

#### HTTP头部

key : authorization

value : [查看鉴权参数计算方法](/book/api/auth.md)

#### URL参数
|参数名称 | 类型 | 是否必选  | 描述 |
|:- | :- | :- | :- |
|action | string | 是  | 接口名称<br>该值为latestWifiLocation |
|version | string | 是  | 版本信息<br>该值为1 |
|product_id | string | 是  | 产品ID |
|device_name | string | 是  | 设备名称 | 


#### 返回数据
|参数名称 | 类型  | 描述 |
|:- | :-  | :- |
| code | string | 调用失败时，返回的错误码,为0表示调用成功 |
| msg  | string | 调用失败时，返回的错误信息,为"success"表示调用成功 |
| data | - | 调用成功时，返回的业务数据 |
| data. at | string | 时间 |
| data.lon | string | 经度 |
| data.lat | string | 纬度 |


#### 示例

##### 请求示例

GET http:/openapi.heclouds.com/lbs_wifi?action=latestWifiLocation&version=1&product_id=lqIY8PNO38a2Ce4o&device_name=linglong-Test

Content-type: application/json

##### 响应示例

```json
{
"code": "0",
"msg":"success",
"data": {
         "at": "2020-06-13 15:15:22.012",  //时间
         "lon": 106.48881,   //经度
         "lat": 29.62518   //纬度
      }
}


```
<h2 id="2">2. WIFI定位-设备历史轨迹查询</h2>

#### 接口名称
> getWifiTrail

#### 请求方法 

> GET

#### URL

http://openapi.heclouds.com/lbs

#### HTTP头部

key : authorization

value : [查看鉴权参数计算方法](/book/api/auth.md)

#### URL参数
|参数名称 | 类型 | 是否必选  | 描述 |
|:- | :- | :- | :- |
|action | string | 是  | 接口名称<br>该值为getWifiTrail |
|version | string | 是  | 版本信息<br>该值为1 |
|product_id | string | 是  | 产品ID |
|device_name | string | 是  | 设备名称 | 
|start | string | 否 | 查询轨迹的开始时间, 默认起始时间为本周一零点，精确到毫秒级别 | 
| end | string | 否 | 查询轨迹的结束时间，默认结束时间为当前时间，精确到毫秒级别 | 
| page  | int | 否 | 指定页码 |
| per_page | int | 否 | 指定每页输出个数,默认10 |
| maxLon | string | 否 | 最大经度 |
| minLon | string | 否 | 最小经度 |
| maxLat | string | 否 | 最大纬度 |
| minLat | string | 否 | 最小纬度 |
| sort | string | 否 | 排序规则<br>DESC或ASC，默认为ASC（升序） |

> 备注：最大、最小经纬度如果不传，查询所有轨迹。如果四个参数都传入，则查询范围内轨迹。


#### 返回数据
|参数名称 | 类型  | 描述 |
|:- | :-  | :- |
| code | string | 调用失败时，返回的错误码,为0表示调用成功 |
| msg  | string | 调用失败时，返回的错误信息,为"success"表示调用成功 |
| data | - | 调用成功时，返回的业务数据 |
| data.page | int | 指定页码 |
| data.perPage | int | 每页输出个数 |
| data.total_count | int | 位置记录总数 |
| data.items | array | 设备的位置记录数据 |

#### items数据结构

|参数名称 | 类型  | 描述 |
|:- | :-  | :- |
| at | string | 时间 |
| lon | string | 经度 |
| lat | string | 纬度 |


#### 示例

##### 请求示例

GET http://openapi.heclouds.com/lbs_wifi?action=getWifiTrail&version=1&product_id=lqIY8PNO38a2Ce4o&device_name=linglong-Test

Content-type: application/json

##### 响应示例

```json
{
"code": "0",
"msg":"success",
"data": {
        "page": 1,
        "perPage": 10,
        "total_count": 3,
        "items": [
            {
                "at": "2020-06-13 15:15:22.012",  //时间
                "lon": 106.48881, //经度
                "lat": 29.62518  //纬度
            },
            {
                "at": "2020-06-13 18:22:58.234",  //时间
                "lon": 106.48886999999999, //经度
                "lat": 29.62514  //纬度
            },
            {
                "at": "2020-06-13 18:25:19.210",  //时间
                "lon": 106.48885,  //经度
                "lat": 29.62516  //纬度
            }       
]
}

```