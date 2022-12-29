# 物联卡业务数据查询API

请求方法：**GET**

URL：http://api.heclouds.com/dmc/ccmp/deviceinfo

#### url参数
参数名称 | 格式 | 是否必须 | 说明
:- | :- | :- | :- 
deviceid|string|是|设备ID，多个deviceid以"_"分割

#### http头部
参数名称 | 格式 | 是否必须 | 说明
:- | :- | :- | :- 
api-key | string | 是 | 必须为masterkey

#### 返回参数
参数名称|格式|说明
:- | :- | :- 
errno|int|调用错误码，为0表示调用成功
error|string|错误描述，为"succ"表示调用成功
data|json|物联卡业务数据详情

#### data描述表
参数名称|格式|说明
:- | :- | :- 
cardinfos|json|卡业务数据详情

#### cardinfo描述表
参数名称|格式|说明
:- | :- | :- 
deviceid|string|设备id
cardstatus|string|物联卡状态；00-正常,01-单向停机,02-停机,03-预销号,04-销号,05-过户,06-休眠,07-待激,99-号码不存在
entertime|string|物联卡入网时间
imsi|string|物联卡imsi号
iccid|string|物联卡iccid号
msisdn|string|物联卡msisdn号
left|string|套餐剩余流量（单位：KB）
gprstotal|string|套餐总流量（单位：KB）
gprsusedflow|string|套餐已使用流量（单位：KB）
billingstatus|string|物联卡当前生命周期；00:正式期,01:测试期,02:沉默期,03:其他
gprs_status|string|物联卡在线状态；00-离线,01-在线
prodinfos|json|物联卡套餐信息

#### prodinfos描述表
参数名称|格式|说明
:- | :- | :- 
prodid|string|套餐id
prodname|string|套餐名称
prodinstefftime|string|套餐失效时间

#### 请求示例
```text
GET http://api.heclouds.com/dmc/ccmp/deviceinfo?deviceid=35282992_35271941 HTTP/1.1
api-key: WhI3***************v1c=
Host: api.heclouds.com
```

#### 返回示例
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