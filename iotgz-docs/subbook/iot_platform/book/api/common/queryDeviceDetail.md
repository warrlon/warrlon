# 设备详情

#### 接口名称

> QueryDeviceDetail

#### 请求方法

> GET

#### 请求参数
|参数名称 | 类型 | 是否必选  | 描述 |
|:- | :- | :- | :- |
|product_id | string | 是 | 产品ID |
|device_name | string | 是 | 设备名称 |

#### 返回数据
|参数名称 | 类型 | 描述 |
|:- | :- | :- |
| code | string | 调用失败时，返回的错误码 |
| msg  | string | 调用失败时，返回的错误信息 |
| requestId | string | 调用API时生成的请求标识  |
| success | boolean | 接口是否调用成功 |
| data | - | 调用成功返回业务数据 |
| data.device_name | string | 设备名称 |
| data.product_id | string | 产品ID |
| data.product_name | string | 产品名称 |
| data.desc | string | 设备描述 |
| data.status | int | 设备状态 1-未激活 2-在线 3-离线 |
| data.node_type | int | 节点类型 1-直连设备 |
| data.protocol | int | 协议类型 1-泛协议 2-MQTT 3-CoAP 4-LwM2M |
| data.imei | string | NB设备imei，15个数字组成的电子串号 |
| data.imsi | string | NB设备imsi，不超过15个的数字 |
| data.auth_code | string | NB设备鉴权码 |
| data.ip | string | 设备连接ip |
| data.create_time | string | 创建时间 |
| data.last_time | string | 最后一次在线时间 |
| data.active_time | string | 激活时间 |
| data.sec_key | string | 设备密钥 |
| data.lat | string | 纬度 |
| data.lon | string | 经度 |
| data.province | string | 省 |
| data.city | string | 市 |
| data.district | string | 区、县 |
| data.street | string | 街道、路 |
| data.street_num | string | 号牌 |
| data.address | string | 详细地址 |

#### 示例

##### 请求示例

```
GET /common?action=QueryDeviceDetail&version=1&product_id=lsibd9
&device_name=no001

```

##### 响应示例

```
{
    "data": {
        "device_name": "no001",
        "product_id": "9MaNe52pNO",
        "product_name": "空气净化器",
        "active_time": "2020-06-19T08:11:27.801Z",
        "created_time": "2020-06-19T06:09:22.550Z",
        "desc": "设备1",    
        "ip": "192.168.200.139",
        "last_time": "2020-06-19T09:48:15.027Z",
        "node_type": 1,    
        "protocol": 2,
        "imei": "366322456556584",
        "imsi": "366322456556584",
        "auth_code": "authcode",        
        "sec_key": "UQd3K9lXR/EbLXeJc50lJfvvkTVdu5uFgbfz48/fI5k=",
        "status": 3,
        "lat": "39.916392",
        "lon": "116.375972",
        "province": "北京市",
        "city": "北京市",
        "district": "西城区",
        "street": "皮库胡同",
        "street_num": "4号楼",
        "address": "",
    },
    "requestId": "a25087f46df04b69b29e90ef0acfd115", 
    "success": true
}
```