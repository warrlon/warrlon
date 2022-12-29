# 查询订阅topic的设备
请求方式：**GET**

URL: http://api.heclouds.com/mqtt/topic_device

#### URL参数
参数名称 | 格式 | 是否必须 | 说明
:- | :- | :- | :- 
topic | string | 是 | 发布消息到指定的topic，只支持发布qos=0的消息
page | int | 是 | 指定页码
per_page | int | 是 | 指定每页输出设备个数，默认30，最多1000


#### 返回参数
参数名称 | 格式 | 说明
:- | :- | :- 
errno | int | 调用错误码，为0表示调用成功
error | string | 错误描述，为"succ"表示调用成功
data | json | 接口调用成功之后返回的设备相关信息，见data描述表

##### data描述表
参数名称 | 格式 | 说明
:- | :- | :- 
total_count | int | 查询结果中设备的数量
page | int | 当前页
per_page | int | 每页设备数量
devices | array-int | 设备ID数组


#### 请求头部示例
```text
GET http://api.heclouds.com//mqtt/topic_device?topic=topic/test/01&page=1&per_page=100 HTTP/1.1
```

#### 返回示例
```json
{
	"errno": 0,
	"data": {
		"per_page": 100,
		"devices": [39587277,39587272],
		"total_count": 2,
		"page": 1
	},
	"error": "succ"
}
```